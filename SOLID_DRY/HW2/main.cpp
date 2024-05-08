#include <iostream>
#include <fstream>
#include <string>
#include <utility>

class Printable {
public:
	virtual std::string printformat(std::ofstream& file) const = 0;
};

class HTML : public Printable
{
public:
	HTML(std::string data) : data_(std::move(data)) {};
	std::string printformat(std::ofstream& file) const override{
        file.open("C:\\Programming\\Design_Pattrens_CPP\\SOLID_DRY\\HW2\\HTML.txt");
		file << data_;
		return "html" + data_ + "html/";
	}
private:
	std::string data_;
};

class TEXT : public Printable
{
public:
	TEXT(std::string data) : data_(std::move(data)) {};
	std::string printformat(std::ofstream& file) const override {
        file.open("C:\\Programming\\Design_Pattrens_CPP\\SOLID_DRY\\HW2\\TEXT.txt");
		file << data_;
		return "TEXT" + data_ + "TEXT/";
	}
private:
	std::string data_;
};

class JSONPRINT : public Printable
{
public:
	JSONPRINT(std::string data) : data_(std::move(data)) {};
	std::string printformat(std::ofstream& file) const override {
        file.open("C:\\Programming\\Design_Pattrens_CPP\\SOLID_DRY\\HW2\\JSON.txt");
		file << data_;
		return "JSON" + data_ + "JSON";
	}
private:
	std::string data_;
};


int main() {
	std::ofstream filename;
	std::string str;
    std::cout << "HTML: ";
    std::getline(std::cin,str);
    HTML filehtml(str);
    filehtml.printformat(filename);
    std::cout << "TEXT: ";
    std::getline(std::cin,str);
    TEXT text(str);
    text.printformat(filename);
    JSONPRINT jsonformat(str);
    std::cout << "JSON: ";
    std::getline(std::cin,str);
    jsonformat.printformat(filename);

	return 0;
}
