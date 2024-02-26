#include "Analysis.h"

void Analysis::getTeachers(const HttpRequestPtr& req, std::function<void (const HttpResponsePtr &)> &&callback)
{
    Json::Value jsonResp(Json::arrayValue);
    HttpStatusCode httpRetCode = HttpStatusCode::k200OK;

    try
    {
        auto dbClient = app().getDbClient();
        auto teacherMapper = drogon::orm::Mapper<Teachers>(dbClient);
        std::vector<Teachers> teachers = teacherMapper.findAll();

        for(auto& teacher: teachers)
        {
            Json::Value json;
            json["id"] = std::to_string(teacher.getValueOfId());
            json["first_name"] = teacher.getValueOfFirstName();
            json["last_name"] = teacher.getValueOfLastName();
            json["school"] = teacher.getValueOfSchool();

            jsonResp.append(json);
        }
    }
    catch(const std::exception& e)
    {
        LOG_ERROR << e.what();
        jsonResp["Error"] = e.what();
    }

    auto resp = HttpResponse::newHttpJsonResponse(jsonResp);
    resp->setStatusCode(httpRetCode);
    callback(resp);
}

void Analysis::getTeacherbyID(const HttpRequestPtr& req, std::function<void (const HttpResponsePtr &)> &&callback)
{
    Json::Value jsonResp;
    std::string id = req->getParameter("id");
    HttpStatusCode httpRetCode = HttpStatusCode::k200OK;

    try
    {
        auto dbClient = app().getDbClient();
        auto teacherMapper = drogon::orm::Mapper<Teachers>(dbClient);
        Teachers teacher = teacherMapper.findOne(
            Criteria(Teachers::Cols::_id, CompareOperator::EQ, id)
        );

        jsonResp["id"] = std::to_string(teacher.getValueOfId());
        jsonResp["first_name"] = teacher.getValueOfFirstName();
        jsonResp["last_name"] = teacher.getValueOfLastName();
        jsonResp["school"] = teacher.getValueOfSchool();
    }
    catch(const std::exception& e)
    {
        LOG_ERROR << e.what();
        jsonResp["Error"] = e.what();
    }
    auto resp = HttpResponse::newHttpJsonResponse(jsonResp);
    resp->setStatusCode(httpRetCode);
    callback(resp);
}

void Analysis::getIDTeacher(const HttpRequestPtr& req, std::function<void (const HttpResponsePtr &)> &&callback)
{
    Json::Value jsonResp;
    std::string first_name = req->getParameter("first_name");
    std::string last_name = req->getParameter("last_name");
    HttpStatusCode httpRetCode = HttpStatusCode::k200OK;

    try
    {
        auto dbClient = app().getDbClient();
        auto teacherMapper = drogon::orm::Mapper<Teachers>(dbClient);
        std::vector<Teachers> teachers = teacherMapper.findBy(
            Criteria(Teachers::Cols::_first_name, CompareOperator::EQ, first_name) &&
            Criteria(Teachers::Cols::_last_name, CompareOperator::EQ, last_name)
        );

        if(teachers.size()==0)
        {
            jsonResp["error"] = "Cannot find teacher with name " + first_name;
        }

        for(auto& teacher: teachers)
        {
            Json::Value json;
            json["id"] = std::to_string(teacher.getValueOfId());
            json["first_name"] = teacher.getValueOfFirstName();
            json["last_name"] = teacher.getValueOfLastName();
            json["school"] = teacher.getValueOfSchool();

            jsonResp.append(json);
        }
    }
    catch(const std::exception& e)
    {
        LOG_ERROR << e.what();
        jsonResp["Error"] = e.what();
    }
    auto resp = HttpResponse::newHttpJsonResponse(jsonResp);
    resp->setStatusCode(httpRetCode);
    callback(resp);
}

void Analysis::addTeacher(const HttpRequestPtr& req, std::function<void (const HttpResponsePtr &)> &&callback)
{
    std::shared_ptr<Json::Value>jsonBody;
    Json::Value jsonResp;
    Teachers obj;
    jsonBody = req->getJsonObject();

    trantor::Date hire_date = getDatefromString(jsonBody->operator[]("hire_date").asString());

    obj.setFirstName(jsonBody->operator[]("first_name").asString());
    obj.setLastName(jsonBody->operator[]("last_name").asString());
    obj.setSalary(jsonBody->operator[]("salary").asString());
    obj.setSchool(jsonBody->operator[]("school").asString());
    obj.setHireDate(hire_date);

    try
    {
        auto dbClient = app().getDbClient();
        auto teacherMapper = drogon::orm::Mapper<Teachers>(dbClient);
        teacherMapper.insert(obj);

        jsonResp["message"] = "Added teacher successfully";
    }
    catch(const std::exception& e)
    {
        LOG_ERROR << e.what();
        jsonResp["Error"] = e.what();
    }
    
    auto resp = HttpResponse::newHttpJsonResponse(jsonResp);
    callback(resp);
}

void Analysis::updateTeacher(const HttpRequestPtr& req, std::function<void (const HttpResponsePtr &)> &&callback)
{
    Json::Value jsonResp;
    std::shared_ptr<Json::Value>jsonBody;
    Teachers obj;
    jsonBody = req->getJsonObject();

    trantor::Date hire_date = getDatefromString(jsonBody->operator[]("hire_date").asString());

    obj.setId(jsonBody->operator[]("id").asInt64());
    obj.setFirstName(jsonBody->operator[]("first_name").asString());
    obj.setLastName(jsonBody->operator[]("last_name").asString());
    obj.setSalary(jsonBody->operator[]("salary").asString());
    obj.setSchool(jsonBody->operator[]("school").asString());
    obj.setHireDate(hire_date);
    
    try
    {
        auto dbClient = app().getDbClient();
        auto teacherMapper = drogon::orm::Mapper<Teachers>(dbClient);
        size_t res = teacherMapper.update(obj);
        if(!res)
        {
            jsonResp["Error"] = "Cannot find teacher with ID " + jsonBody->operator[]("id").asString();
        }else
        {
            jsonResp["message"] = "Update teacher successfully";
        }
    }
    catch(const std::exception& e)
    {
        LOG_ERROR << e.what();
        jsonResp["Error"] = e.what();
    }
    
    auto resp = HttpResponse::newHttpJsonResponse(jsonResp);
    callback(resp);
}

void Analysis::deleteTeacher(const HttpRequestPtr& req, std::function<void (const HttpResponsePtr &)> &&callback)
{
    Json::Value jsonResp;

    try
    {
        std::string id = req->getParameter("id");

        auto dbClient = app().getDbClient();
        auto teacherMapper = drogon::orm::Mapper<Teachers>(dbClient);

        size_t res = teacherMapper.deleteBy(
            Criteria(Teachers::Cols::_id, CompareOperator::EQ, id)
        );

        if(!res)
        {
            jsonResp["Error"] = "Cannot find teacher with ID " + id;
        }else
        {
            jsonResp["message"] = "Delete teacher successfully";
        }
    }
    catch(const std::exception& e)
    {
        LOG_ERROR << e.what();
        jsonResp["Error"] = e.what();
    }

    auto resp = HttpResponse::newHttpJsonResponse(jsonResp);
    callback(resp);
}

trantor::Date Analysis::getDatefromString(const std::string date)
{
    std::stringstream ss(date);
    std::string token;
    std::getline(ss, token, '-'); // Extract year
    int year = std::stoi(token);

    std::getline(ss, token, '-'); // Extract month
    int month = std::stoi(token);

    std::getline(ss, token, '-'); // Extract day
    int day = std::stoi(token);

    return trantor::Date(year, month, day);
}
