#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>

struct threadFuncArgs
{
  int id;
  char *name;
};


void *threadFunc(void *arg) {
  struct threadFuncArgs *args = (struct threadFuncArgs*)arg;

  for (int i = 0; i < 10; i ++) {
    printf("Thread (%d, %s) created.\n", args->id, args->name);
    sleep(1);

    /* if (i == 3) {
      printf("Thread is exiting.");
      pthread_exit(NULL);
    } */
  }

  return NULL;
}

int main() {
  pthread_t thread;

  struct threadFuncArgs *args = (struct threadFuncArgs*)malloc(sizeof(struct threadFuncArgs));
  args->id = 100;
  args->name = (char*)"Mr. Thread";

  int failed = pthread_create(
    &thread,
    NULL,
    threadFunc,
    (void *)args);

  if (failed) {
    printf("Could not create thread.\n");
  }

  for (int i = 0; i < 10; i++) {
    printf("Main loop execution #%d.\n", i);
    sleep(1);
  }

  return 0;
}