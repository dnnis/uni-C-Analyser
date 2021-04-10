all:
	flex -o uni-c-analyser.c uni-c-analyser.l
	gcc -o uni-c-analyser uni-c-analyser.c
	./uni-c-analyser input.txt
clean:
	rm uni-c-analyser uni-c-analyser.c
