$(CC)      :=gcc
VPATH = src:bashlib:include
# makefile created by xern

# put source code into src/
# put exec file into bin/
# put lib file into include/
# put link file into build/
	
bin/cmd, bin/md, bin/mkdir, bin/cls, bin/dir, bin/del, bin/rm, \
bin/rd, bin/rmdir, bin/ren, bin/rename, bin/tree, bin/echo, bin/type, \
bin/more, bin/comp, bin/copy, bin/find, bin/move, bin/date, bin/ver, \
bin/replace, bin/sort, bin/tasklist, bin/ipconfig: src/md.c src/cls.c \
src/dir.c src/del.c src/rd.c src/ren.c src/tree.c src/echo.c src/type.c \
src/more.c src/comp.c src/copy.c src/find.c src/move.c src/date.c src/ver.c \
src/replace.c src/sort.c src/tasklist.c src/ipconfig.c bashlib/cmd.h bashlib/cmd.c \
bashlib/type_prompt.c bashlib/read_command.c bashlib/builtin_command.c bashlib/parsing.c
	mkdir -p bin
	$(CC) bashlib/cmd.c bashlib/type_prompt.c bashlib/read_command.c \
	bashlib/builtin_command.c bashlib/parsing.c -o bin/cmd
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
	$(CC) src/comp.c -o bin/comp
	$(CC) src/copy.c -o bin/copy
	$(CC) src/find.c -o bin/find
	$(CC) src/move.c -o bin/move
	$(CC) src/date.c -o bin/date
	$(CC) src/ver.c -o bin/ver
	$(CC) src/replace.c -o bin/replace
	$(CC) src/sort.c -o bin/sort
	$(CC) src/tasklist.c -o bin/tasklist
	$(CC) src/ipconfig.c -o bin/ipconfig
		

.PHONY: clean
clean:
	rm -r bin/*
