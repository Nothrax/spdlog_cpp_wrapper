
#include <Logger.h>

#include <spdlog/spdlog.h>
#include <spdlog/sinks/stdout_sinks.h>
#include <spdlog/sinks/rotating_file_sink.h>

#include <vector>
#include <iostream>


void Logger::initLogger(std::string logPath, bool verbose, std::string logName) {
    try
    {
        std::vector<spdlog::sink_ptr> sinks;

        //console sink
        if(verbose){
            sinks.push_back(std::make_shared<spdlog::sinks::stdout_sink_st>());
        }

        //rotating file sink for error and warn logs
        auto console_sink = std::make_shared<spdlog::sinks::rotating_file_sink_mt>(logPath + logName + "_error_log.txt", 1024*1024*5, 1, false);
        console_sink->set_level(spdlog::level::warn);
        sinks.push_back(console_sink);

        //rotating file sink for all logs
        sinks.push_back(std::make_shared<spdlog::sinks::rotating_file_sink_mt>(logPath + logName + "_info_log.txt", 1024*1024*5, 1, false));

        //create synchronous  loggers
        auto readerLogger = std::make_shared<spdlog::logger>("logger", begin(sinks), end(sinks));

        readerLogger->flush_on(spdlog::level::warn);

        // globally register the loggers so they can be accessed using spdlog::get(logger_name)
        spdlog::register_logger(readerLogger);
    }
    catch (const spdlog::spdlog_ex& ex)
    {
        std::cerr << "Log initialization failed: " << ex.what() << std::endl;
        exit(EXIT_FAILURE);
    }
}

void Logger::logInfo(std::string log) {
    std::shared_ptr<spdlog::logger> logger;
    logger = spdlog::get("logger");
    logger->info(log);
}

void Logger::logWarning(std::string log) {
    std::shared_ptr<spdlog::logger> logger;
    logger = spdlog::get("logger");
    logger->warn(log);
}

void Logger::logError(std::string log) {
    std::shared_ptr<spdlog::logger> logger;
    logger = spdlog::get("logger");
    logger->error(log);
}
