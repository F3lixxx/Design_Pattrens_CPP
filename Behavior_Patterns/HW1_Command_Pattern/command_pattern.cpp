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

class fileLog : public LogCommand{
public:
    fileLog(std::ofstream& lifelog) : file(lifelog) {
        if(!file.is_open()){
            std::cout << "Error to open" << std::endl;
        }
    };
    void print(const std::string& message) override{
        file << message << std::endl;
        file.close();
    };

private:
    std::ofstream& file;
};

void print(LogLevel Log,LogCommand& command, const std::string& message) {
	command.print(message);
}

int main() {
    std::string path;
    std::cout << "Enter a path with name of file" << std::endl;
    std::getline(std::cin, path);

    std::ofstream pathFile(path);
    ConsoleLogCommand consoleView;
    fileLog log(pathFile);

    print(DEBUG,log, "Error in file");
	print(DEBUG,consoleView, "Error");
    return 0;
}