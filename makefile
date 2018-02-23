$(CC)      :=gcc
# makefile created by xern

# put source code into src/
# put exec file into bin/
# put lib file into include/
# put link file into build/
	

bin/md, bin/mkdir, bin/cls, bin/dir, bin/del, bin/rm, bin/rd, bin/rmdir, bin/ren, bin/rename, bin/tree, bin/echo, bin/type, bin/more: src/md.c src/cls.c src/dir.c src/del.c src/rd.c src/ren.c src/tree.c src/echo.c src/type.c src/more.c
	mkdir -p bin
	$(CC) src/md.c -o bin/md
	$(CC) src/md.c -o bin/mkdir
	$(CC) src/cls.c -o bin/cls
	$(CC) src/dir.c -o bin/dir
	$(CC) src/del.c -o bin/del
	$(CC) src/del.c -o bin/rm
	$(CC) src/rd.c -o bin/rd
	$(CC) src/rd.c -o bin/rmdir
	$(CC) src/ren.c -o bin/ren
	$(CC) src/ren.c -o bin/rename
	$(CC) src/tree.c -o bin/tree
	$(CC) src/echo.c -o bin/echo
	$(CC) src/type.c -o bin/type
	$(CC) src/more.c -o bin/more

test: src/sort.c
	$(CC) src/sort.c -o bin/sort
	

.PHONY: clean
clean:
	rm bin/md
	rm bin/mkdir
	rm bin/cls
	rm bin/dir
	rm bin/del
	rm bin/rm
	rm bin/rd
	rm bin/rmdir
	rm bin/ren
	rm bin/rename
	rm bin/tree
	rm bin/echo
	rm bin/type
	rm bin/more
	rm bin/comp
