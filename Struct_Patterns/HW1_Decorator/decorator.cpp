	#include <iostream>
	#include <string>
	#include <vector>

	class Text {
	public:
		virtual void render(const std::string& data) const {
			std::cout << data;
		}
	};

	class Decorated_text : public Text {
	public:
		explicit Decorated_text(Text* text) : _text(text) {}
		Text* _text;
	};

	class Paragraph : public Decorated_text {
	public:
		explicit Paragraph(Text* text) : Decorated_text(text) {}
		void render(const std::string& data) const override {
			std::cout << "<p>";
			_text->render(data);
			std::cout << "</p>" << std::endl;
		}
	};

	class Reversed : public Decorated_text {
	public:
		explicit Reversed(Text* text) : Decorated_text(text) {}
		void render(const std::string& data) const override {
			auto reversed_text = data;
			std::reverse(reversed_text.begin(), reversed_text.end());
				_text->render(reversed_text);
				std::cout << std::endl;
		}
	};

	class Link : public Decorated_text {
	public:
		explicit Link(Text* text) : Decorated_text(text) {}
		void render(const std::pair<std::string, std::string>& data) const {
			std::cout << "a href=\"" << data.first << "\">" << data.second << "</a>" << std::endl;
		}
	};

	int main() {
		auto text_par = new Paragraph(new Text());
		text_par->render("Hello World");
		auto text_view = new Reversed(new Text());
		text_view->render("Hello World");

		auto link_text = new Link(new Text());
		link_text->render(std::make_pair("netology.ru", "Hello World"));
		return 0;
	}