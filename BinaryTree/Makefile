BIN=BinaryTree
MAIN=src/main.cpp
TESTS=src/tests.cpp
TESTS_BIN=tests

all: compile compile-tests run-tests run


compile:
	clang++ $(MAIN) -o $(BIN)

tests: \
	compile-tests \
	run-tests

compile-tests:
	clang++ $(TESTS) -ggdb -fsanitize=address -fno-omit-frame-pointer -l gtest_main -l gtest -l pthread -o $(TESTS_BIN)

run:
	./$(BIN)

run-tests:
	./$(TESTS_BIN)

.PHONY: tests