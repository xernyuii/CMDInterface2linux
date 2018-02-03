$(CC)      :=gcc
# makefile created by xern

# put source code into src/
# put exec file into bin/
# put lib file into include/
# put link file into build/
	

bin/md, bin/mkdir, bin/cls: src/md.c src/cls.c
	$(CC) src/md.c -o bin/md
	$(CC) src/md.c -o bin/mkdir
	$(CC) src/cls.c -o bin/cls

.PHONY: clean
clean:
	rm bin/md
	rm bin/mkdir
	rm bin/cls



