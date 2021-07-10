# Cpp wrapper for spdlog
This project is wrapper around spdlog logging library with some string formatting template functions.

# Prerequisites
Pre-installed [spdlog](https://github.com/gabime/spdlog)

# Usage
Include Logger.h, call function initLogger function with logPath, verbose and logName. Library is fully static, once init is done you can call static function logInfo, logWarning and logError from anywhere.
