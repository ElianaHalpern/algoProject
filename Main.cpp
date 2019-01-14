//
// Created by eliana on 1/14/19.
//

#include <sys/types.h>

#include <pthread.h>

#include "Main.h"

pthread_mutex_t mutex;
pthread_mutex_t mutexFile;
int main(int argc, char *argv[]) {
    pthread_mutex_init(&mutex, nullptr);
    pthread_mutex_init(&mutexFile, nullptr);

}
