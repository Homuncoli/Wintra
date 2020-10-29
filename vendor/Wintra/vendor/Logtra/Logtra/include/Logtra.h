// Logtra.h : Include file for standard system include files,
// or project specific include files.

#pragma once

#include <iostream>

#include "Logger.h"

// Non critical assert
#define ASSERT (condition, message) if (condition) { std::cerr << message << '\n'; }

// Critical assert
#define CASSERT(condition, message) if (condition) { std::cerr << message << '\n'; std::terminate(); }

// Use this logger for all coming log calls
#define LGA_USE_LOGGER(logger) Logtra::Logger::instance = &logger;

// ToDo: Decide if logging should only be posssible in debug

#ifdef _DEBUG
	// Helper nullptr check for logger
	#define CHECK_IF_LOGGER_IS_PRESENT CASSERT(Logtra::Logger::instance == nullptr, "No Logger is in use")

	#define LGA_LOG(message) CHECK_IF_LOGGER_IS_PRESENT;\
							Logtra::Logger::instance->logMessage(message, __FILE__, __LINE__)

	#define LGA_ERROR(message) CHECK_IF_LOGGER_IS_PRESENT;\
								Logtra::Logger::instance->logError(message, __FILE__, __LINE__)

	#define LGA_SUCCESS(message) CHECK_IF_LOGGER_IS_PRESENT;\
								Logtra::Logger::instance->logSuccess(message, __FILE__, __LINE__)

	#define LGA_WARNING(message) CHECK_IF_LOGGER_IS_PRESENT;\
								Logtra::Logger::instance->logWarning(message, __FILE__, __LINE__)

	#define LGA_CRITICAL(message) CHECK_IF_LOGGER_IS_PRESENT;\
								Logtra::Logger::instance->logCritical(message, __FILE__, __LINE__)
#else
	#define LGA_SUCCESS(message)	Logtra::Logger::instance->logSuccess(message, __FILE__, __LINE__)
	#define LGA_LOG(message)		Logtra::Logger::instance->logMessage(message, __FILE__, __LINE__)
	#define LGA_WARNING(message)	Logtra::Logger::instance->logWarning(message, __FILE__, __LINE__)
	#define LGA_ERROR(message)		Logtra::Logger::instance->logError(message, __FILE__, __LINE__)
	#define LGA_CRITICAL(message)	Logtra::Logger::instance->logCritical(message, __FILE__, __LINE__)
#endif


