$(CC)      :=gcc
# makefile created by xern

# put source code into src/
# put exec file into bin/
# put lib file into include/
# put link file into build/
	

bin/md, bin/mkdir, bin/cls, bin/dir, bin/del, bin/rm, bin/rd, bin/rmdir: src/md.c src/cls.c src/dir.c src/del.c src/rd.c
	mkdir -p bin
	$(CC) src/md.c -o bin/md
	$(CC) src/md.c -o bin/mkdir
	$(CC) src/cls.c -o bin/cls
	$(CC) src/dir.c -o bin/dir
	$(CC) src/del.c -o bin/del
	$(CC) src/del.c -o bin/rm
	$(CC) src/rd.c -o bin/rd
	$(CC) src/rd.c -o bin/rmdir

.PHONY: clean
clean:
	rm bin/md
	rm bin/mkdir
	rm bin/cls
	rm bin/dir
	rm bin/del



