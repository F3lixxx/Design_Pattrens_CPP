#include <iostream>
#include "sql_query_builder.h"


int main()
{
	SqlSelectQueryBuilder query_builder;
	query_builder.AddColumn("name").Addcolumn("phone");
	query_builder.AddFrom("student");
	query_builder.AddWhere("id", "42").AddWhere("name", "John");

	static_assert(query_builder.BuildQuery(),
		"Select name, phone FROM students where id = 42 AND name = John;");
	return 0;
}