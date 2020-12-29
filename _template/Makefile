BIN=Example
MAIN=src/main.cpp
TESTS=src/tests.cpp
TESTS_BIN=tests

CPP_OPTS=-ggdb -fsanitize=address -fno-omit-frame-pointer

all: deps compile compile-tests run-tests run

deps:
	

compile:
	clang++ $(MAIN) $(CPP_OPTS) -o $(BIN)

tests: \
	compile-tests \
	run-tests

compile-tests:
	clang++ $(TESTS) $(CPP_OPTS) -l gtest_main -l gtest -l pthread -o $(TESTS_BIN)

run:
	./$(BIN)

run-tests:
	./$(TESTS_BIN)

clean:
	rm -f $(TESTS_BIN) $(BIN)

.PHONY: tests