CXX = g++
CXXFLAGS = -std=c++17 -Wall -Iinclude
LDFLAGS = -lfftw3 -lm -lgtest_main -lgtest -lpthread

SRC = src/main.cpp src/scheduler.cpp src/filter.cpp src/fft.cpp src/logger.cpp
TESTS = tests/test_filter.cpp tests/test_fft.cpp tests/test_logger.cpp \
        src/filter.cpp src/fft.cpp src/scheduler.cpp src/logger.cpp

TARGET = rtos_dsp_scheduler
TEST_TARGET = test_runner

all: $(TARGET)

$(TARGET): $(SRC)
	$(CXX) $(CXXFLAGS) -o $@ $(SRC) $(LDFLAGS)

test: $(TESTS)
	$(CXX) $(CXXFLAGS) -o $(TEST_TARGET) $(TESTS) $(LDFLAGS)
	./$(TEST_TARGET)

clean:
	rm -f $(TARGET) $(TEST_TARGET)
	rm -rf logs *.gcno *.gcda *.gcov