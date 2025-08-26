#include <gtest/gtest.h>
#include <fstream>
#include <filesystem>
#include "filter.h"

namespace fs = std::filesystem;

TEST(LoggerTest, CreateAndWriteLogFile) {
    
    std::string logDir = "logs";
    std::string logFile = logDir + "/system.log";

    // If log exists, remove it
    if(fs::exists(logFile)) {
        fs::remove(logFile);
    } if(fs::exists(logDir)) {
        fs::remove_all(logDir);
    }

    logTask();
    // Log directory and file should exist
    ASSERT_TRUE(fs::exists(logDir));
    ASSERT_TRUE(fs::exists(logFile));

    // Assert: file should not be empty
    std::ifstream ifs(logFile);
    std::string content((std::istreambuf_iterator<char>(ifs)),
                         std::istreambuf_iterator<char>());
    ASSERT_FALSE(content.empty());

    // Assert: file should contain "[LoggerTask]"
    EXPECT_NE(content.find("[LoggerTask]"), std::string::npos);

}