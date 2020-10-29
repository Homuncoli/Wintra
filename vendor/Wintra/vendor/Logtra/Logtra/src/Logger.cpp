#include "Logger.h"

#include <regex>
#include <chrono>

#include <ctime>

#define REPLACE_SYMBOL(string, symbol, text) string = std::regex_replace(string, std::regex(symbol), text)

#define MESSAGE_PATTERN_SYMBOL		"%m"
#define TIME_PATTERN_SYMBOL			"%t"
#define CONTEXT_PATTERN_SYMBOL		"%c"
#define LINE_PATTERN_SYMBOL			"%l"
#define FILE_PATTERN_SYMBOL			"%f"
#define COLOR_BEGIN_PATTERN_SYMBOL	"%bc"
#define COLOR_END_PATTERN_SYMBOL	"%ec"

namespace Logtra {
	Logtra::Logger* Logtra::Logger::instance = nullptr;

	// ToDo: Make this good
	std::string getTime() {
		time_t now = time(0);
		tm* ltm = localtime(&now);
		return std::to_string(ltm->tm_hour) + ":" + std::to_string(ltm->tm_min) + ":" + std::to_string(ltm->tm_sec);
	}

	Logger::Logger() : context("Logtra")
	{
		setPattern("%bc[%c][%t][%f,%l]: %m");
	}

	Logger::Logger(const std::string& context) : Logger()
	{
		this->context = context;
	}

	Logger::Logger(const std::string& context, const std::string& pattern) : context(context) {
		setPattern(pattern);
	}

	void Logger::logSuccess(const std::string& message, const char* file, int line) const
	{
		std::string log = applyPattern(message, file, line, "\x1B[32m");
		*stream << log << '\n';
	}

	void Logger::logMessage(const std::string& message, const char* file, int line) const
	{
		std::string log = applyPattern(message, file, line, "\x1B[37m");
		*stream << log << '\n';
	}

	void Logger::logWarning(const std::string& message, const char* file, int line) const
	{
		std::string log = applyPattern(message, file, line, "\x1B[33m");
		*stream << log << '\n';
	}

	void Logger::logError(const std::string& message, const char* file, int line) const
	{
		std::string log = applyPattern(message, file, line, "\x1B[91m");
		*stream << log << '\n';
	}

	void Logger::logCritical(const std::string& message, const char* file, int line) const
	{
		std::string log = applyPattern(message, file, line, "\x1B[31m");
		*stream << log << '\n';
	}

	void Logger::setPattern(const std::string& pattern)
	{
		this->pattern = pattern;
	}

	void Logger::setStream(std::ostream* stream)
	{
		this->stream = stream;
	}

	// ToDo: Make this good
	std::string Logger::applyPattern(const std::string& message, const char* file, int line, const char* color) const
	{
		std::string log = pattern;

		REPLACE_SYMBOL(log, CONTEXT_PATTERN_SYMBOL, context);
		REPLACE_SYMBOL(log, TIME_PATTERN_SYMBOL, getTime());
		REPLACE_SYMBOL(log, MESSAGE_PATTERN_SYMBOL, message);
		REPLACE_SYMBOL(log, LINE_PATTERN_SYMBOL, std::to_string(line));
		REPLACE_SYMBOL(log, FILE_PATTERN_SYMBOL, file);
		REPLACE_SYMBOL(log, COLOR_BEGIN_PATTERN_SYMBOL, color);
		REPLACE_SYMBOL(log, COLOR_END_PATTERN_SYMBOL, "\033[0m");

		return log + "\033[0m";
	}
}