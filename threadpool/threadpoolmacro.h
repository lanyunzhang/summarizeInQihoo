//File:    threadpoolmacro.h
// Author:  Sky <djsxut@gmail.com>
// Brief:   
//
// History:
// ================================================================
// 2011-04-29 Sky <djsxut@gmail.com> created
//
//
//

#ifndef THREAD_POOL_MACRO_H_
#define THREAD_POOL_MACRO_H_

#define MAX_THREAD_NUM 256    //线程池允许创建的最大线程数
#define MIN_THREAD_NUM 1    //线程池中最小需要创建的线程数

#include <stdio.h>
#include <pthread.h>
#include <stdlib.h>
#include <string.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <unistd.h>
#include <time.h>

#define return_if_null(p) if((p) == NULL)\
{printf("%s:%d Warning: failed.\n",\
        __func__, __LINE__); return;}

#define return_null_if_fail(p) if((p) == NULL)\
{printf("%s:%d Warning: failed.\n",\
        __func__, __LINE__); return NULL;}

#define return_val_if_fail(p, ret) if((p) == NULL)\
{printf("%s:%d Warning: failed.\n", \
        __func__, __LINE__); return (ret);}

#endif //end THREAD_POOL_MACRO_H_

