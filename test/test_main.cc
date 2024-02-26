#define DROGON_TEST_MAIN
#include <drogon/drogon_test.h>
#include <drogon/drogon.h>

using namespace drogon;

DROGON_TEST(GetTeacherAPITest)
{
    auto client = HttpClient::newHttpClient("http://localhost:5555");
    auto req = HttpRequest::newHttpRequest();
    req->setPath("/Analysis/get-all-teacher");
    client->sendRequest(req, [TEST_CTX](ReqResult res, const HttpResponsePtr& resp) {
        REQUIRE(res == ReqResult::Ok);
        REQUIRE(resp != nullptr);

        CHECK(resp->getStatusCode() == k200OK);
    });
}

DROGON_TEST(GetTeacherbyIDAPITest)
{
    auto client = HttpClient::newHttpClient("http://localhost:5555");
    auto req = HttpRequest::newHttpRequest();
    req->setPath("/Analysis/get-teacher/?id=1");
    client->sendRequest(req, [TEST_CTX](ReqResult res, const HttpResponsePtr& resp) {
        REQUIRE(res == ReqResult::Ok);
        REQUIRE(resp != nullptr);

        CHECK(resp->getStatusCode() == k200OK);
        const auto& jsonResp = resp->getJsonObject();
        CHECK((*jsonResp)["first_name"].asString() == "Janet");
    });
}

DROGON_TEST(AddTeacherAPITest)
{
    auto client = HttpClient::newHttpClient("http://localhost:5555");
    Json::Value jsonRes;
    jsonRes["first_name"]   = "John";
    jsonRes["last_name"]    = "Doe";
    jsonRes["salary"]       = 50000;
    jsonRes["school"]       = "Example School";
    jsonRes["hire_date"]    = "2024-02-22";

    auto req = HttpRequest::newHttpJsonRequest(jsonRes);
    req->setPath("/Analysis/add-teacher");
    req->setMethod(Post);
    client->sendRequest(req, [TEST_CTX](ReqResult res, const HttpResponsePtr& resp) {
        REQUIRE(res == ReqResult::Ok);
        REQUIRE(resp != nullptr);

        CHECK(resp->getStatusCode() == k200OK);
        const auto& jsonResp = resp->getJsonObject();
        CHECK((*jsonResp)["message"].asString() == "Added teacher successfully");
    });
}

DROGON_TEST(GetIDTeacherAPITest)
{
    auto client = HttpClient::newHttpClient("http://localhost:5555");
    auto req = HttpRequest::newHttpRequest();
    req->setPath("/Analysis/get-id-teacher/?first_name=John&last_name=Doe");
    client->sendRequest(req, [TEST_CTX](ReqResult res, const HttpResponsePtr& resp) {
        REQUIRE(res == ReqResult::Ok);
        REQUIRE(resp != nullptr);

        CHECK(resp->getStatusCode() == k200OK);
    });
}

DROGON_TEST(DeleteTeacherAPITest)
{   
    auto client = HttpClient::newHttpClient("http://localhost:5555");
    auto req = HttpRequest::newHttpRequest();
    req->setPath("/Analysis/get-id-teacher/?first_name=John&last_name=Doe");
    client->sendRequest(req, [TEST_CTX](ReqResult res, const HttpResponsePtr& resp) {
        const auto& jsonResp = resp->getJsonObject();
        Json::Value listObj(Json::arrayValue);
        listObj = *jsonResp;

        for (const auto& obj: listObj)
        {
            auto client = HttpClient::newHttpClient("http://localhost:5555");
            auto req = HttpRequest::newHttpRequest();
            std::string endpoint = "/Analysis/delete-teacher/?id=" + obj["id"].asString();
            req->setPath(endpoint);
            req->setMethod(Delete);
            client->sendRequest(req, [TEST_CTX](ReqResult res, const HttpResponsePtr& resp) {
                REQUIRE(res == ReqResult::Ok);
                REQUIRE(resp != nullptr);

                CHECK(resp->getStatusCode() == k200OK);
                const auto& jsonResp = resp->getJsonObject();
                CHECK((*jsonResp)["message"].asString() == "Delete teacher successfully");
            });
        }
    });
}

int main(int argc, char** argv) 
{
    using namespace drogon;

    std::promise<void> p1;
    std::future<void> f1 = p1.get_future();

    // Start the main loop on another thread
    std::thread thr([&]() {
        // Queues the promise to be fulfilled after starting the loop
        app().getLoop()->queueInLoop([&p1]() { p1.set_value(); });
        app().run();
    });

    // The future is only satisfied after the event loop started
    f1.get();
    int status = test::run(argc, argv);

    // Ask the event loop to shutdown and wait
    app().getLoop()->queueInLoop([]() { app().quit(); });
    thr.join();
    return status;
}
