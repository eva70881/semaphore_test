#include <stdio.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <semaphore.h>
#include <unistd.h>
#include <errno.h>

int main(int argc, char** argv)
{
  int val = 1;
  sem_t *sem = sem_open("/testsem", O_CREAT|O_EXCL);

	if(sem != SEM_FAILED)
	{
    printf("create new semaphore.\n");
	}
	else if(errno == EEXIST)
	{
    printf("semaphore exists.\n");
		sem = sem_open("/testsem", 0);
	}
	else
	{
    return -1;
	}

	while(val > 0)
	{
	  sem_getvalue(sem, &val);
	  printf("Get semaphore value = %d\n", val);
		sleep(1);
  }

  printf("semaphore not using, start process\n");
	sem_post(sem);
  sleep(20);
	sem_wait(sem);
	printf("process done\n");

	sem_getvalue(sem, &val);
	sem_close(sem);

	if(val == 0)
	{
    sem_unlink("/testsem");
	}

  return 0;
}
