all:
	flex uni-c-analyser.l
	gcc -o uni-c-analyser lex.yy.c
	./uni-c-analyser input.txt
clean:
	rm uni-c-analyser uni-c-analyser.c
