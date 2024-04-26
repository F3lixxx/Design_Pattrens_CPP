#include <iostream>
#include <map>
#include <string>
#include <vector>

class VeryHeavyDB {
public:
	std::string GetData(const std::string& key) const noexcept {
		return "value";
	}

	std::string decrease_access(const std::string& key) noexcept {
		usage_count[key]--;
	}

protected:
	std::map<std::string, int> usage_count;
};

class OneShotDB : public VeryHeavyDB {
public:
	explicit OneShotDB(VeryHeavyDB* real_object, size_t shots = 1) : real_obj(real_object), view(shots) {}
	std::string GetData(const std::string& key) noexcept  {
		if (view == 0 || usage_count[key] >= static_cast<int>(view)) {
			return "error";
		}
		else {
			usage_count[key]++;
			return real_obj->GetData(key);
		}
	}

private:
	VeryHeavyDB* real_obj;
	size_t view;
};

int main() {
	auto real_db = VeryHeavyDB();
	auto limit_db = OneShotDB(std::addressof(real_db), 5);
	std::cout << limit_db.GetData("key") << std::endl;
	std::cout << limit_db.GetData("key") << std::endl;
	std::cout << limit_db.GetData("key") << std::endl;
	std::cout << limit_db.GetData("key") << std::endl;
	std::cout << limit_db.GetData("key") << std::endl;
	std::cout << limit_db.GetData("key") << std::endl;
	std::cout << limit_db.GetData("key") << std::endl;
	std::cout << limit_db.GetData("key") << std::endl;
	std::cout << limit_db.GetData("key") << std::endl;
	std::cout << limit_db.GetData("key") << std::endl;
	std::cout << limit_db.GetData("key") << std::endl;
	std::cout << limit_db.GetData("key") << std::endl;
	std::cout << limit_db.GetData("key") << std::endl;

	return 0;
}
