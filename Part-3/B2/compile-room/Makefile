make: 
	cp ../flex-part/flex-LA.l .
	cp ../bison-part/bison-SA.y .
	bison -d bison-SA.y
	flex flex-LA.l
	gcc -lm bison-SA.tab.c lex.yy.c -o uni-c-analyser
debug: 
	cp ../flex-part/flex-LA.l .
	cp ../bison-part/bison-SA.y .
	bison --defines --debug bison-SA.y
	flex flex-LA.l
	gcc -lm bison-SA.tab.c lex.yy.c -o uni-c-analyser
clean:
	rm flex-LA.l bison-SA.y lex.yy.c uni-c-analyser bison-SA.tab.c bison-SA.tab.h
