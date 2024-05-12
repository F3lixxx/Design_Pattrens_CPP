#include <iostream>
#include <fstream>

enum LogLevel { DEBUG, INFO, WARNING, CRITICAL };

class LogCommand {
public:
	virtual ~LogCommand() = default;
	virtual void print(const std::string& message) = 0;
};

class ConsoleLogCommand : public LogCommand {
public:
	 void print(const std::string& message) override {
        std::cout << "Console Log: " << message << std::endl;
    }
};

class FileLog : public LogCommand {
public:

    void print(const std::string& message) override {
        std::string path;
        std::ofstream file( "log.txt");
        file << message << std::endl;
        file.close();
    }
};

void print(LogCommand& command, const std::string& message) {
	command.print(message);
}

int main() {
    std::string path;
    std::cin >> path;
    std::ofstream pathFile;

	ConsoleLogCommand consoleView;
	FileLog logFile;
	print(logFile, "symbols");
	print(consoleView, "Error");
    return 0;
}