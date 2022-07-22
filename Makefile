PROJECT_NAME = compression_algorithm.out

SRC = main.c\
src/compression_algorithm.c

TEST_SRC = test/test_main.c\
src/compression_algorithm.c\
unity/unity.c

INC = -Iunity\
-Iinc

.PHONY:test clean run

$(PROJECT_NAME): $(SRC)
	gcc $(SRC) $(INC) -o $(PROJECT_NAME)

run:$(PROJECT_NAME)
	./${PROJECT_NAME}

test:$(TEST_SRC)
	gcc $(TEST_SRC) $(INC) -o test_$(PROJECT_NAME)
	./test_${PROJECT_NAME}

coverage:${PROJECT_NAME}
	gcc -fprofile-arcs -ftest-coverage $(TEST_SRC) $(INC) -o $(PROJECT_NAME)
	./${PROJECT_NAME}
	gcov -a compression_algorithm.c

codesize:${PROJECT_NAME}
	size ./${PROJECT_NAME}

clean:
	rm -rf *.out *.gcov *.gcda *.gcno
