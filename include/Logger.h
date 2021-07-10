#pragma once

#include <string>
/**
 * Simple wrapper around spdlog library
 */
class Logger {
public:
    /**
     * Initializes spdlog logger
     * @param logPath where log files will be saved
     * @param verbose if true logs will be printed to console
     * @param logName name of log file
     */
    static void initLogger(std::string logPath, bool verbose, std::string logName);

    /**
     * Log info message
     * @param log message to log
     */
    static void logInfo(std::string log);

    /**
     * Log warning message
     * @param log message to log
     */
    static void logWarning(std::string log);

    /**
     * Log error message
     * @param log message to log
     */
    static void logError(std::string log);
};
