# Semaphore test

## sem_t *sem_open(const char *name, int oflag);

Open or Create a semaphore

### Create a semaphore

```c
sem_t *sem = sem_open("/testsem", O_CREAT|O_EXCL);
```

### Open a semaphore

```c
sem_t *sem = sem_open("/testsem", 0);
```

## int sem_getvalue(sem_t *sem, int *sval);

Read a semaphore

```c
int val;
sem_getvalue(sem, &val);
```

## int sem_post(sem_t *sem);

Increase semaphore

```c
sem_post(sem);
```

## int sem_wait(sem_t *sem);

Decrease semaphore

```c
sem_wait(sem);
```

## int sem_close(sem_t *sem);

Close a semaphore

```c
sem_close(sem);
```

## int sem_unlink(const char *name);

Destroy a semaphore

```c
sem_unlink("/testsem");
```

## Including headers

```c
#include <sys/stat.h>
#include <fcntl.h>
#include <semaphore.h>
#include <errno.h>
```

## Linked libraries

pthread
