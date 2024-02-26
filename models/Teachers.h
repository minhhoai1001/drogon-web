/**
 *
 *  Teachers.h
 *  DO NOT EDIT. This file is generated by drogon_ctl
 *
 */

#pragma once
#include <drogon/orm/Result.h>
#include <drogon/orm/Row.h>
#include <drogon/orm/Field.h>
#include <drogon/orm/SqlBinder.h>
#include <drogon/orm/Mapper.h>
#include <drogon/orm/BaseBuilder.h>
#ifdef __cpp_impl_coroutine
#include <drogon/orm/CoroMapper.h>
#endif
#include <trantor/utils/Date.h>
#include <trantor/utils/Logger.h>
#include <json/json.h>
#include <string>
#include <string_view>
#include <memory>
#include <vector>
#include <tuple>
#include <stdint.h>
#include <iostream>

namespace drogon
{
namespace orm
{
class DbClient;
using DbClientPtr = std::shared_ptr<DbClient>;
}
}
namespace drogon_model
{
namespace analysis
{

class Teachers
{
  public:
    struct Cols
    {
        static const std::string _id;
        static const std::string _first_name;
        static const std::string _last_name;
        static const std::string _school;
        static const std::string _hire_date;
        static const std::string _salary;
    };

    const static int primaryKeyNumber;
    const static std::string tableName;
    const static bool hasPrimaryKey;
    const static std::string primaryKeyName;
    using PrimaryKeyType = int64_t;
    const PrimaryKeyType &getPrimaryKey() const;

    /**
     * @brief constructor
     * @param r One row of records in the SQL query result.
     * @param indexOffset Set the offset to -1 to access all columns by column names,
     * otherwise access all columns by offsets.
     * @note If the SQL is not a style of 'select * from table_name ...' (select all
     * columns by an asterisk), please set the offset to -1.
     */
    explicit Teachers(const drogon::orm::Row &r, const ssize_t indexOffset = 0) noexcept;

    /**
     * @brief constructor
     * @param pJson The json object to construct a new instance.
     */
    explicit Teachers(const Json::Value &pJson) noexcept(false);

    /**
     * @brief constructor
     * @param pJson The json object to construct a new instance.
     * @param pMasqueradingVector The aliases of table columns.
     */
    Teachers(const Json::Value &pJson, const std::vector<std::string> &pMasqueradingVector) noexcept(false);

    Teachers() = default;

    void updateByJson(const Json::Value &pJson) noexcept(false);
    void updateByMasqueradedJson(const Json::Value &pJson,
                                 const std::vector<std::string> &pMasqueradingVector) noexcept(false);
    static bool validateJsonForCreation(const Json::Value &pJson, std::string &err);
    static bool validateMasqueradedJsonForCreation(const Json::Value &,
                                                const std::vector<std::string> &pMasqueradingVector,
                                                    std::string &err);
    static bool validateJsonForUpdate(const Json::Value &pJson, std::string &err);
    static bool validateMasqueradedJsonForUpdate(const Json::Value &,
                                          const std::vector<std::string> &pMasqueradingVector,
                                          std::string &err);
    static bool validJsonOfField(size_t index,
                          const std::string &fieldName,
                          const Json::Value &pJson,
                          std::string &err,
                          bool isForCreation);

    /**  For column id  */
    ///Get the value of the column id, returns the default value if the column is null
    const int64_t &getValueOfId() const noexcept;
    ///Return a shared_ptr object pointing to the column const value, or an empty shared_ptr object if the column is null
    const std::shared_ptr<int64_t> &getId() const noexcept;
    ///Set the value of the column id
    void setId(const int64_t &pId) noexcept;

    /**  For column first_name  */
    ///Get the value of the column first_name, returns the default value if the column is null
    const std::string &getValueOfFirstName() const noexcept;
    ///Return a shared_ptr object pointing to the column const value, or an empty shared_ptr object if the column is null
    const std::shared_ptr<std::string> &getFirstName() const noexcept;
    ///Set the value of the column first_name
    void setFirstName(const std::string &pFirstName) noexcept;
    void setFirstName(std::string &&pFirstName) noexcept;
    void setFirstNameToNull() noexcept;

    /**  For column last_name  */
    ///Get the value of the column last_name, returns the default value if the column is null
    const std::string &getValueOfLastName() const noexcept;
    ///Return a shared_ptr object pointing to the column const value, or an empty shared_ptr object if the column is null
    const std::shared_ptr<std::string> &getLastName() const noexcept;
    ///Set the value of the column last_name
    void setLastName(const std::string &pLastName) noexcept;
    void setLastName(std::string &&pLastName) noexcept;
    void setLastNameToNull() noexcept;

    /**  For column school  */
    ///Get the value of the column school, returns the default value if the column is null
    const std::string &getValueOfSchool() const noexcept;
    ///Return a shared_ptr object pointing to the column const value, or an empty shared_ptr object if the column is null
    const std::shared_ptr<std::string> &getSchool() const noexcept;
    ///Set the value of the column school
    void setSchool(const std::string &pSchool) noexcept;
    void setSchool(std::string &&pSchool) noexcept;
    void setSchoolToNull() noexcept;

    /**  For column hire_date  */
    ///Get the value of the column hire_date, returns the default value if the column is null
    const ::trantor::Date &getValueOfHireDate() const noexcept;
    ///Return a shared_ptr object pointing to the column const value, or an empty shared_ptr object if the column is null
    const std::shared_ptr<::trantor::Date> &getHireDate() const noexcept;
    ///Set the value of the column hire_date
    void setHireDate(const ::trantor::Date &pHireDate) noexcept;
    void setHireDateToNull() noexcept;

    /**  For column salary  */
    ///Get the value of the column salary, returns the default value if the column is null
    const std::string &getValueOfSalary() const noexcept;
    ///Return a shared_ptr object pointing to the column const value, or an empty shared_ptr object if the column is null
    const std::shared_ptr<std::string> &getSalary() const noexcept;
    ///Set the value of the column salary
    void setSalary(const std::string &pSalary) noexcept;
    void setSalary(std::string &&pSalary) noexcept;
    void setSalaryToNull() noexcept;


    static size_t getColumnNumber() noexcept {  return 6;  }
    static const std::string &getColumnName(size_t index) noexcept(false);

    Json::Value toJson() const;
    Json::Value toMasqueradedJson(const std::vector<std::string> &pMasqueradingVector) const;
    /// Relationship interfaces
  private:
    friend drogon::orm::Mapper<Teachers>;
    friend drogon::orm::BaseBuilder<Teachers, true, true>;
    friend drogon::orm::BaseBuilder<Teachers, true, false>;
    friend drogon::orm::BaseBuilder<Teachers, false, true>;
    friend drogon::orm::BaseBuilder<Teachers, false, false>;
#ifdef __cpp_impl_coroutine
    friend drogon::orm::CoroMapper<Teachers>;
#endif
    static const std::vector<std::string> &insertColumns() noexcept;
    void outputArgs(drogon::orm::internal::SqlBinder &binder) const;
    const std::vector<std::string> updateColumns() const;
    void updateArgs(drogon::orm::internal::SqlBinder &binder) const;
    ///For mysql or sqlite3
    void updateId(const uint64_t id);
    std::shared_ptr<int64_t> id_;
    std::shared_ptr<std::string> firstName_;
    std::shared_ptr<std::string> lastName_;
    std::shared_ptr<std::string> school_;
    std::shared_ptr<::trantor::Date> hireDate_;
    std::shared_ptr<std::string> salary_;
    struct MetaData
    {
        const std::string colName_;
        const std::string colType_;
        const std::string colDatabaseType_;
        const ssize_t colLength_;
        const bool isAutoVal_;
        const bool isPrimaryKey_;
        const bool notNull_;
    };
    static const std::vector<MetaData> metaData_;
    bool dirtyFlag_[6]={ false };
  public:
    static const std::string &sqlForFindingByPrimaryKey()
    {
        static const std::string sql="select * from " + tableName + " where id = $1";
        return sql;
    }

    static const std::string &sqlForDeletingByPrimaryKey()
    {
        static const std::string sql="delete from " + tableName + " where id = $1";
        return sql;
    }
    std::string sqlForInserting(bool &needSelection) const
    {
        std::string sql="insert into " + tableName + " (";
        size_t parametersCount = 0;
        needSelection = false;
            sql += "id,";
            ++parametersCount;
        if(dirtyFlag_[1])
        {
            sql += "first_name,";
            ++parametersCount;
        }
        if(dirtyFlag_[2])
        {
            sql += "last_name,";
            ++parametersCount;
        }
        if(dirtyFlag_[3])
        {
            sql += "school,";
            ++parametersCount;
        }
        if(dirtyFlag_[4])
        {
            sql += "hire_date,";
            ++parametersCount;
        }
        if(dirtyFlag_[5])
        {
            sql += "salary,";
            ++parametersCount;
        }
        needSelection=true;
        if(parametersCount > 0)
        {
            sql[sql.length()-1]=')';
            sql += " values (";
        }
        else
            sql += ") values (";

        int placeholder=1;
        char placeholderStr[64];
        size_t n=0;
        sql +="default,";
        if(dirtyFlag_[1])
        {
            n = snprintf(placeholderStr,sizeof(placeholderStr),"$%d,",placeholder++);
            sql.append(placeholderStr, n);
        }
        if(dirtyFlag_[2])
        {
            n = snprintf(placeholderStr,sizeof(placeholderStr),"$%d,",placeholder++);
            sql.append(placeholderStr, n);
        }
        if(dirtyFlag_[3])
        {
            n = snprintf(placeholderStr,sizeof(placeholderStr),"$%d,",placeholder++);
            sql.append(placeholderStr, n);
        }
        if(dirtyFlag_[4])
        {
            n = snprintf(placeholderStr,sizeof(placeholderStr),"$%d,",placeholder++);
            sql.append(placeholderStr, n);
        }
        if(dirtyFlag_[5])
        {
            n = snprintf(placeholderStr,sizeof(placeholderStr),"$%d,",placeholder++);
            sql.append(placeholderStr, n);
        }
        if(parametersCount > 0)
        {
            sql.resize(sql.length() - 1);
        }
        if(needSelection)
        {
            sql.append(") returning *");
        }
        else
        {
            sql.append(1, ')');
        }
        LOG_TRACE << sql;
        return sql;
    }
};
} // namespace analysis
} // namespace drogon_model
