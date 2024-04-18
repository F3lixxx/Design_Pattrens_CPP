#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <map>

class SqlSelectQueryBuilder {
private:
	std::vector<std::string> columns;
	std::string from;
	std::vector<std::pair<std::string, std::string>> where_conditions;

public:
	SqlSelectQueryBuilder() = default;

	SqlSelectQueryBuilder& AddColumn(const std::vector<std::string>& column) noexcept{
        for(const auto& col : column){
            columns.emplace_back(col);
        }
        return *this;
    }

	SqlSelectQueryBuilder& AddFrom(const std::string& table) {
		from = table;
		return *this;
	}

	SqlSelectQueryBuilder& AddWhere(const std::map<std::string, std::string>& kv) noexcept{
		for(const auto& temp : kv){
            where_conditions.emplace_back(temp.first, temp.second);
        }
		return *this;
	}

	std::string BuildQuery() const {
		std::stringstream query;
		query << "SELECT ";
		
		if (columns.empty()) {
			query << "* ";
		}
		else {
			for (size_t i = 0; i < columns.size(); ++i)
			{
				query << columns[i];
				if (i != columns.size() - 1) {
					query << ' ';
				}
			}
			query << ' ';
		}
		
		query << "FROM " << from << ' ';

		if (!where_conditions.empty()) {
			query << "WHERE ";
			for (size_t i = 0; i < where_conditions.size(); i++)
			{
				query << where_conditions[i].first << '=' << where_conditions[i].second;
				if (i != where_conditions.size() - 1)
				{
					query << " AND ";
				} 
			}
		}
		query << ";";
		return query.str();
	}
};