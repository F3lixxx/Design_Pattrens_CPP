#include <iostream>
#include "sql_query_builder.h"


int main()
{
    SqlSelectQueryBuilder builder;

    builder.AddColumn({"column1", "column2", "column3"});

    builder.AddFrom("table_name");

    std::map<std::string, std::string> conditions = {
            {"column1", "value1"},
            {"column2", "value2"}
    };
    builder.AddWhere(conditions);

    std::string query = builder.BuildQuery();
    std::cout << "SQL Query: " << query << std::endl;
	return 0;
}