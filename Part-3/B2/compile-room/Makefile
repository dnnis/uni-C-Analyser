make: 
	cp ../flex-part/flex-LA.l .
	cp ../bison-part/bison-SA.y .
	bison -d bison-SA.y
	flex flex-LA.l
	gcc bison-SA.tab.h lex.yy.c -lfl -o uni-c-analyser
clean:
	rm flex-LA.l bison-SA.y lex.yy.c uni-c-analyser bison-SA.tab.c bison-SA.tab.h
