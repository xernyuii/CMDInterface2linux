## CMDInterface2linux
---
### INSTALL
    cd in repo dir
    make
    ./bin/cmd

---
## USAGE
### COMP
比较两个文件的内容

    comp filename1 filename2 

+	filename1	指定要比较的第一个文件的路径
+	filename2	指定要比较的第一个文件的路径

### COPY
将文件复制到另一个位置

    copy source destination

+	source	指定要复制的文件
+ 	destination	为新文件指定的路径

### FIND
在文件中搜索字符串

    find string filename

+	find 指定要搜索的字符串
+ 	filename 指定被搜索的文件 

### MOVE
移动文件并重命名文件

    move source destination

+	source	指定要移动的文件
+ 	destination	移动后文件的路径

### DATE
显示当前系统时间

    date

### VER
显示当前操作系统和发行版本信息

    ver

### REPLACE
替换文件

    replace filename path

+	filename	指定替换的源文件
+ 	path	指定被替换文件的目录

### SORT
对文件内容进行排序

    sort filename

+	filename	指定被排序的文件路径

### TASKLIST
显示当前运行的进程列表

    tasklist

### IPCONFIG
显示当前的各网卡的IP信息

    ipconfig

### CLS
清除屏幕

    cls

### DEL
删除文件或目录

    del path[...]

+	name 	指定要删除的文件或目录的路径 

### DIR
显示目录中的文件和子目录列表

    dir [path]

+	path	指定要查看的路径，若没有此参数，则列出当前目录


### ECHO
显示信息

    echo message

+	message	指定要现实的信息

### MD
创建目录

    md path

+	path	创建的目录的路径

### MORE
逐屏显示输出

### RD
删除目录

    RD path[...]

+	path	需要删除的目录路径

### REN
重命名文件

    ren filename1 filename2

+	filename1	需要重命名的文件的路径
+	filename2 重命名后的路径

### TREE
以树形显示文件夹结构

    tree

### TYPE
显示文本文件的内容

    type filename

+	filename	需要显示的文件路径