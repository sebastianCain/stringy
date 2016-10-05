strtest: stringfuncs.c
	gcc stringfuncs.c -o strtest;

clean:
	rm *~;

run: strtest
	./strtest
