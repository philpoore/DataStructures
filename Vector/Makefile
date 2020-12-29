BIN=Vector
MAIN=src/main.cpp
TESTS=src/tests.cpp
TESTS_BIN=tests

all: compile compile-tests tests

compile:
	clang++ $(MAIN) -o $(BIN)

compile-tests:
	clang++ $(TESTS) -l gtest_main -l gtest -l pthread -o $(TESTS_BIN)

tests:
	./$(TESTS_BIN)

.PHONY: tests