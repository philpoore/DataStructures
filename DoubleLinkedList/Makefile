all: compile tests

compile:
	clang++ src/main.cpp -o DoubleLinkedList

tests:
	clang++ src/tests.cpp -l gtest_main -l gtest -l pthread -o tests

.PHONY: tests