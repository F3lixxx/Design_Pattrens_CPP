#include <iostream>
#include <map>
#include <string>
#include <vector>

class VeryHeavyDB {
public:
	std::string GetData(const std::string& key) const noexcept {
		return "Very Big Data string: " + key;
	}
};

class CacheProxyDB : VeryHeavyDB {
public:
	explicit CacheProxyDB(VeryHeavyDB* real_object) : real_db_(real_object) {}
	std::string GetData(const std::string& key) noexcept {
		if (cache_.find(key) == cache_.end()) {
			std::cout << "Get from real object\n";
			cache_[key] = real_db_->GetData(key);
		}
		else {
			std::cout << "Get from cache\n";
		}
		return cache_.at(key);
	}
private:
	std::map<std::string, std::string> cache_;
	VeryHeavyDB* real_db_;
};

class OneShotDB :VeryHeavyDB {
public:
	explicit OneShotDB(VeryHeavyDB* real_object, size_t shots = 1) : real_obj(real_object), view(shots) {}
	int limit_db(const size_t& shooter) noexcept override{
		if (shooter == view) {
			std::cout << "error\n";
			view[shooter] = real_obj->GetData(shooter);
		}
		else {
			std::cout << "value\n";
			return 1;
		}
	}
private:
	VeryHeavyDB* real_obj;
	std::vector<size_t> view;
};

int main() {

	return 0;
}
