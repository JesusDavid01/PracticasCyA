CC := g++
CFLAGS := -Wall -o

programa: 
	$(CC) $(CFLAGS)  main_p04_regular_expressions main_p04_regular_expressions.cc file.cc

clean:
	ls | grep -v .txt | grep -v .h | grep -v .cc | grep -v Makefile || xargs rm
