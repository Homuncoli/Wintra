#ifndef LOGTRA_LOGGER_H
#define LOGTRA_LOGGER_H

#include <string>
#include <iostream>

namespace Logtra {
	class Logger {
	public:
		static Logger* instance;

		Logger();
		Logger(const std::string& context);
		/*
			Pattern: 

			%m	->	message
			%t	->	time in HH:MM:SS
			%c	->	context
			%l	->	line number
			%f	->	file name
			%bc	->	begin color
			%ec	->	end color; is set automatically at the end of the log
		*/
		Logger(const std::string& context, const std::string& pattern);

		void logSuccess (const std::string& message, const char* file, int line) const;
		void logMessage (const std::string& message, const char* file, int line) const;
		void logWarning (const std::string& message, const char* file, int line) const;
		void logError   (const std::string& message, const char* file, int line) const;
		void logCritical(const std::string& message, const char* file, int line) const;

		void setPattern(const std::string& pattern);
		void setStream(std::ostream* stream);

	private:
		std::string applyPattern(const std::string& message, const char* file, int line, const char* color) const;

		std::string pattern;
		std::string context;
		std::ostream* stream{ &std::cout };
	};
}

#endif // !LOGTRA_LOGGER_H
