CC=gcc
# makefile created by xern

# put source code into src/
# put exec file into bin/
# put lib file into include/
# put link file into build/

bin/md: src/md.c
	CC src/md.c -o bin/md


.PHONY: clean
clean:
	rm bin/md



