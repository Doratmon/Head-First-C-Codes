### make通过\*.o与\*.c文件的时间戳，来判断哪些文件需要进行编译
### 通过makefile向make描述该如何编译
makefile描述了make需要的依赖项与生成命令
```
truster.o: truster.h truster.c
[TAB]gcc -c truster.c
launch.o: launch.h launch.c truster.h
[TAB]gcc -c launch.c
launch: truster.o launch.o
[TAB]gcc truster.o launch.o -o launch
```
1. 目标文件：truster.o launch.o launch
2. 依赖项: 目标文件后面的文件
3. 生成命令是[TAB]后的内容

**我的一些理解：**
* Windows中多文件编程直接运行按钮就可以运行，是编译器做了make的事情，Linux中更直接的揭示了make是怎么做的
* gcc xx -o yy/-c：xx只写.c文件即可，但是在makefile文件的依赖项中要写全（包含.c和.h)