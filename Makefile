CFLAGS = -g -O0 -Wall -Wextra -Wpedantic -I include -I Resources/

test : test
all : main

clean:
	$(RM) -rf bin/*
	$(RM) -rf build/*

test: bin/edit_distance_test
	cd bin && ./edit_distance_test

main : bin/edit_distance_main
	cd bin && ./edit_distance_main ../txt/dictionary.txt ../txt/correctme.txt 

bin/edit_distance_test : build/edit_distance_test.o build/edit_distance.o build/unity.o
	$(CC) $^ -o $@

bin/edit_distance_main : build/edit_distance_main.o build/edit_distance.o
	$(CC) $^ -o $@

build/edit_distance_test.o: test/edit_distance_test.c Resources/unity.h
	$(CC) $(CFLAGS) -c test/edit_distance_test.c -o build/edit_distance_test.o

build/edit_distance_main.o: src/edit_distance_main.c
	$(CC) $(CFLAGS) -c src/edit_distance_main.c -o build/edit_distance_main.o

build/edit_distance.o: src/edit_distance.c include/edit_distance.h
	$(CC) $(CFLAGS) -c src/edit_distance.c -o build/edit_distance.o
	
build/unity.o : Resources/unity.c Resources/unity.h
	$(CC) $(CFLAGS) -c Resources/unity.c -o build/unity.o
	