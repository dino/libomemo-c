#include <glib.h>

GRecMutex global_mutex;

void test_global_mutex_lock(void *user_data)
{
    g_rec_mutex_lock(&global_mutex);
}

void test_global_mutex_unlock(void *user_data)
{
    g_rec_mutex_unlock(&global_mutex);
}

void test_global_mutex_setup()
{
    g_rec_mutex_init(&global_mutex);
}

void test_global_mutex_teardown()
{
    g_rec_mutex_clear(&global_mutex);
}