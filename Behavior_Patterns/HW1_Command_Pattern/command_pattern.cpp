#include <iostream>
#include <fstream>
#include <filesystem>
#include <windows.h>

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
	FileLog(std::string name, LogLevel error) : filename(name), levelToString(error) {}

	void print(const std::string& message) {
		filename << message;
		filename.close();
	}

private:
	std::ofstream filename;

    std::string levelToString(LogLevel level)
    {
        switch (level) {
        case DEBUG:
            return "DEBUG";
        case INFO:
            return "INFO";
        case WARNING:
            return "WARNING";
        case CRITICAL:
            return "CRITICAL";
        default:
            return "UNKNOWN";
        }
    }
};

void print(LogCommand& command, const std::string& message) {
	command.print(message);
}

int main() {
	std::string _path;
	ConsoleLogCommand consoleView;
	FileLog logFile("Log.txt", Debug);

	print(logFile, "File Log");
	print(consoleView, "Error");
    return 0;
}