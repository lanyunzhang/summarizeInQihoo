// File:    threadpool.h
// Author:  Sky <djsxut@gmail.com>
// Brief:   
//
// History:
// ================================================================
// 2011-04-29 Sky <djsxut@gmail.com> created
//
//

#ifndef THREAD_POOL_H_
#define THREAD_POOL_H_

#include "threadpoolmacro.h"

//*****************************************************************************************
//threadpool_task_fun_ 是用户传入的回调函数, 当有新的任务时, 线程将执行该回调函数;
//参数 arg 由用户自定义;
//*****************************************************************************************
typedef void (*threadpool_task_fun_)(void *arg);

struct ThreadPool_ {
    int threadnum_; //总线程数, 不包括管理线程
    pthread_t thread_[MAX_THREAD_NUM + 1]; //空闲线程线程号集合. idlethread_[0] 存储空闲线程总数.
    void    **task_queue_;//任务队列中传入函数的参数, task_queue_[0] 存储任务总数
    threadpool_task_fun_ *task_fun_;//任务队列中传入函数的参数, task_queue_[0] 存储任务总数
    int start;
    int end;
    int max_task_num;
    int complete_task_num;  // 完成任务的线程数量
    pthread_mutex_t mutex_; //线程同步锁
    pthread_cond_t cond_;   //线程同步的条件变量
};

//*****************************************************************************************
//ThreadPool_ 是线程池结构对象, 用户必须先调用 init 函数获得该对象;
//*****************************************************************************************
typedef struct ThreadPool_ ThreadPool;
#ifdef __cplusplus
extern "C" {
#endif
    //*****************************************************************************************
    //threadpool_create 函数初始化线程池对象, 成功返回 ThreadPool_ 结构指针, 失败返回 NULL;
    //thread_num 为初始化时默认创建的线程数目.
    //max_task_num 队列中最大缓存的任务数, 如果任务过多, 超过了这个值, 那么丢弃
    //*****************************************************************************************
    ThreadPool* threadpool_create(int thread_num, int max_task_num);

    //*****************************************************************************************
    //增加一个任务到thiz 所指向的线程池对象中, arg 是用户自定义参数;
    //task_fun 是用户传入的回调函数, 线程执行时将调用该函数.
    //成功返回0, 失败返回 -1;
    //*****************************************************************************************
    int threadpool_add_task(ThreadPool *thiz, threadpool_task_fun_ task_fun, void *arg);

    //*****************************************************************************************
    //停止thiz 所指向的线程池对象中所有线程;
    //成功返回0, 失败返回 -1;
    //*****************************************************************************************
    int threadpool_stop_all_task(ThreadPool *thiz);

    //*****************************************************************************************
    //销毁thiz 所指向的线程池对象;
    //成功返回0, 失败返回 -1;
    //*****************************************************************************************
    int threadpool_destroy(ThreadPool *thiz);

#ifdef __cplusplus
}
#endif
#endif //end THREAD_POOL_H_

