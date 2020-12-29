BIN=BloomFilter
MAIN=src/main.cpp
TESTS=src/tests.cpp
TESTS_BIN=tests

CPP_OPTS=./3rd/xxHash/xxhash.o -ggdb -fsanitize=address -fno-omit-frame-pointer

all: deps compile compile-tests run-tests run

deps:
	gcc ./3rd/xxHash/xxhash.c -c -o ./3rd/xxHash/xxhash.o

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

.PHONY: tests