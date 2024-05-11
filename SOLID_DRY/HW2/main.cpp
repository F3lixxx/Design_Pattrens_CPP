#include <iostream>
#include <fstream>
#include <string>
#include <utility>


class Printable {
public:
    virtual std::string printformat(std::string& str) const = 0;
};

class HTML : public Printable {
public:
    HTML(std::string& data, std::ofstream& file) : data_(data), file_html(file) {}
    std::string printformat(std::string& message) const override {
        if (file_html.is_open()) {
            file_html << data_;
            return "HTML " + data_ + " HTML/";
        }
        return "Failed to open HTML file.";
    }

private:
    std::string data_;
    std::ofstream& file_html;
};


class TEXT : public Printable {
public:
    TEXT(std::string& data, std::ofstream& file) : data_(data), file_text(file) {}
    std::string printformat(std::string& message) const override {
        if (file_text.is_open()) {
            file_text << data_;
            return "TEXT " + data_ + " TEXT/";
        }
        return "Failed to open HTML file.";
    }

private:
    std::string data_;
    std::ofstream& file_text;
};

class JSON : public Printable {
public:
    JSON(std::string& data, std::ofstream& file) : data_(data), file_json(file) {}
    std::string printformat(std::string& message) const override {
        if (file_json.is_open()) {
            file_json << data_;
            return "JSON " + data_ + " JSON/";
        }
        return "Failed to open HTML file.";
    }

private:
    std::string data_;
    std::ofstream& file_json;
};


int main() {
    std::ofstream filename_html("HTML.txt");
    std::ofstream filename_text("TEXT.txt");
    std::ofstream filename_json("JSON.txt");

    std::string str_html;
    std::cout << "HTML: ";
    std::getline(std::cin, str_html);
    HTML fileHtml(str_html, filename_html);
    std::cout << fileHtml.printformat(str_html) << std::endl;

    std::string str_text;
    std::cout << "TEXT: ";
    std::getline(std::cin, str_text);
    TEXT fileText(str_text, filename_text);
    std::cout << fileText.printformat(str_html) << std::endl;
    
    std::string str_json;
    std::cout << "JSON: ";
    std::getline(std::cin, str_json);
    JSON fileJson(str_json, filename_json);
    std::cout << fileJson.printformat(str_json) << std::endl;

    return 0;
}
