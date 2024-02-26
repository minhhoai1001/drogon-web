#pragma once

#include <drogon/HttpController.h>
#include "models/Teachers.h"
#include <trantor/utils/Date.h>

using namespace drogon;
using namespace drogon::orm;
using Teachers = drogon_model::analysis::Teachers;
using Criteria = drogon::orm::Criteria;

class Analysis : public drogon::HttpController<Analysis>
{
  public:
    METHOD_LIST_BEGIN
    // use METHOD_ADD to add your custom processing function here;
    METHOD_ADD(Analysis::getTeachers, "/get-all-teacher", Get);
    METHOD_ADD(Analysis::getTeacherbyID, "/get-teacher/{id}", Get);
    METHOD_ADD(Analysis::getIDTeacher, "/get-id-teacher/{first_name}&{last_name}", Get);
    METHOD_ADD(Analysis::addTeacher, "/add-teacher", Post);
    METHOD_ADD(Analysis::updateTeacher, "/update-teacher", Patch);
    METHOD_ADD(Analysis::deleteTeacher, "/delete-teacher/{id}", Delete);

    METHOD_LIST_END
    
    void getTeachers(const HttpRequestPtr& req, std::function<void (const HttpResponsePtr &)> &&callback);
    void getTeacherbyID(const HttpRequestPtr& req, std::function<void (const HttpResponsePtr &)> &&callback);
    void getIDTeacher(const HttpRequestPtr& req, std::function<void (const HttpResponsePtr &)> &&callback);
    void addTeacher(const HttpRequestPtr& req, std::function<void (const HttpResponsePtr &)> &&callback);
    void updateTeacher(const HttpRequestPtr& req, std::function<void (const HttpResponsePtr &)> &&callback);
    void deleteTeacher(const HttpRequestPtr& req, std::function<void (const HttpResponsePtr &)> &&callback);
  private:
    trantor::Date getDatefromString(const std::string date);
};
