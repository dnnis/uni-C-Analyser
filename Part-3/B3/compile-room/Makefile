make:
	cp ../flex-part/flex-LA.l .
	cp ../bison-part/bison-SA.y .
	cp ../input-files/input.txt .
	bison --defines bison-SA.y
	flex flex-LA.l
	gcc -lm bison-SA.tab.c lex.yy.c -o uni-c-analyser
	./uni-c-analyser > output.txt
	cat output.txt
debug:
	cp ../flex-part/flex-LA.l .
	cp ../bison-part/bison-SA.y .
	cp ../input-files/input.txt .
	bison --defines --debug bison-SA.y
	flex flex-LA.l
	gcc -lm bison-SA.tab.c lex.yy.c -o uni-c-analyser
	./uni-c-analyser > output.txt
	 # /--- Report ---/
	cat output.txt
clean:
	rm flex-LA.l bison-SA.y lex.yy.c uni-c-analyser bison-SA.tab.c bison-SA.tab.h
