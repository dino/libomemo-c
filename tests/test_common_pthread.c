#include <pthread.h>

pthread_mutex_t global_mutex;
pthread_mutexattr_t global_mutex_attr;

void test_global_mutex_lock(void *user_data)
{
    pthread_mutex_lock(&global_mutex);
}

void test_global_mutex_unlock(void *user_data)
{
    pthread_mutex_unlock(&global_mutex);
}

void test_global_mutex_setup()
{
    pthread_mutexattr_init(&global_mutex_attr);
    pthread_mutexattr_settype(&global_mutex_attr, PTHREAD_MUTEX_RECURSIVE);
    pthread_mutex_init(&global_mutex, &global_mutex_attr);
}

void test_global_mutex_teardown()
{
    pthread_mutex_destroy(&global_mutex);
    pthread_mutexattr_destroy(&global_mutex_attr);
}