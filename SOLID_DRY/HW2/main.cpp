#include <iostream>
#include <fstream>
#include <string>
#include <utility>

class Printable {
public:
    virtual std::string printformat() const = 0;
};

class HTML : public Printable {
public:
    HTML(std::string data) : data_(std::move(data)) {}
    std::string printformat() const override {
        file.open("C:\\Programming\\Design_Pattrens_CPP\\SOLID_DRY\\HW2\\HTML.txt");
        if (file.is_open()) {
            file << data_;
            return "html" + data_ + "html/";
        }
        return "Failed to open HTML file.";
    }

private:
    std::string data_;
};

class TEXT : public Printable {
public:
    TEXT(std::string data) : data_(std::move(data)) {}
    std::string printformat() const override {
        file.open("C:\\Programming\\Design_Pattrens_CPP\\SOLID_DRY\\HW2\\TEXT.txt");
        if (file.is_open()) {
            file << data_;
            return "TEXT" + data_ + "TEXT/";
        }
        return "Failed to open TEXT file.";
    }

private:
    std::string data_;
};

class JSON : public Printable {
public:
    JSON(std::string data) : data_(std::move(data)) {}
    std::string printformat() const override {
        file.open("C:\\Programming\\Design_Pattrens_CPP\\SOLID_DRY\\HW2\\JSON.txt");
        if (file.is_open()) {
            file << data_;
            return "JSON" + data_ + "JSON";
        }
        return "Failed to open JSON file.";
    }

private:
    std::string data_;
};

int main() {
    std::ofstream filename;
    std::string str;

    std::cout << "HTML: ";
    std::getline(std::cin, str);
    HTML filehtml(str);
    std::cout << filehtml.printformat(filename) << std::endl;

    std::cout << "TEXT: ";
    std::getline(std::cin, str);
    TEXT text(str);
    std::cout << text.printformat(filename) << std::endl;

    std::cout << "JSON: ";
    std::getline(std::cin, str);
    JSON jsonformat(str);
    std::cout << jsonformat.printformat(filename) << std::endl;

    return 0;
}
