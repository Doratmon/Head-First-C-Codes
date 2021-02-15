# Usage of exec functions

| usage | char |
|---|---|
| param list | l |
| param array/vector | v |
| search according to PATH | p |
| environment variable | e |
| | |

* an example: execle = exec + l + e

* codes after exec() functions will not execute

* parent process uses system call fork() to create a child process, they only differ in **PID**

```c
fork - create a child process

#include <unistd.h>
pid_t fork(void);

RETURN VALUE:
On success, the PID of the child process is returned in the parent, and 0 is returned in the child. 
On failure, -1 is returned in the parent, no child process is created, and errno is set appropriately.

```

