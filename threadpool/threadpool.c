// File:    threadpool.c
// Author:  Sky <djsxut@gmail.com>
// Brief:   
//
// History:
// ================================================================
// 2011-04-29 Sky <djsxut@gmail.com> created
//
//
//

#include "threadpool.h"

static void* threadpool_excute_task(void *arg);

//*****************************************************************************************
//threadpool_create 函数初始化线程池对象, 成功返回 ThreadPool_ 结构指针, 失败返回 NULL;
//thread_num 为初始化时默认创建的线程数目.
//*****************************************************************************************
ThreadPool* threadpool_create(int thread_num, int max_task_num) {
	ThreadPool *tmp = NULL;
	pthread_t th;
	int i = 0;

	if (thread_num > MAX_THREAD_NUM || thread_num < 0)
		return NULL;
	if (thread_num < MIN_THREAD_NUM)
		thread_num = MIN_THREAD_NUM;
	return_null_if_fail(tmp = (ThreadPool *)malloc(sizeof(ThreadPool)));
	tmp->threadnum_ = thread_num;
	tmp->thread_[0] = thread_num;
	tmp->task_queue_ = malloc((max_task_num + 1) * sizeof(void*));
	tmp->task_queue_[0] = (void *) 0;
	tmp->task_fun_ = malloc((max_task_num + 1) * sizeof(void*));
	tmp->start = 1;
	tmp->end = 1;
	tmp->max_task_num = max_task_num;
    tmp->complete_task_num = 0;
	if (pthread_mutex_init(&tmp->mutex_, NULL) != 0)
		return NULL;
	if (pthread_cond_init(&tmp->cond_, NULL) != 0)
		return NULL;
	while (thread_num > 0) {
		if (pthread_create(&th, NULL, threadpool_excute_task, (void *) tmp) == 0) {
			tmp->thread_[++i] = th;
			--thread_num;
			continue;
		}
		threadpool_destroy(tmp);
		tmp = NULL;
		break;
	}
	return tmp;
}

//*****************************************************************************************
//增加一个任务到thiz 所指向的线程池对象中, arg 是用户自定义参数;
//成功返回0, 失败返回 -1;
//*****************************************************************************************
int threadpool_add_task(ThreadPool *thiz, threadpool_task_fun_ task_fun, void *arg) {
	int task_num;
	return_val_if_fail(thiz, -1);

	pthread_mutex_lock(&thiz->mutex_);
	task_num = (int) thiz->task_queue_[0];

	//任务过多, 超过了任务队列最大缓存数时, 丢弃任务
	if (task_num > thiz->max_task_num - 2) {
		pthread_mutex_unlock(&thiz->mutex_);
		return -1;
	}

	++task_num;
	thiz->task_queue_[0] = (void *) task_num;
	thiz->task_queue_[thiz->end] = arg;
	thiz->task_fun_[thiz->end] = task_fun;
	if (++thiz->end > thiz->max_task_num) {
		thiz->end = 1;
	}

	pthread_cond_signal(&thiz->cond_);
	pthread_mutex_unlock(&thiz->mutex_);

	return 0;
}

//*****************************************************************************************
//停止thiz 所指向的线程池对象中所有线程;
//成功返回0, 失败返回 -1;
//*****************************************************************************************
int threadpool_stop_all_task(ThreadPool *thiz) {
	pthread_t i;
	return_val_if_fail(thiz, -1);

	for (i = 1; i <= thiz->thread_[0]; ++i) {
		pthread_cancel(thiz->thread_[i]);
		pthread_join(thiz->thread_[i], NULL);
	}
	thiz->thread_[0] = 0;

	return 0;
}

//*****************************************************************************************
//销毁thiz 所指向的线程池对象;
//成功返回0, 失败返回 -1;
//*****************************************************************************************
int threadpool_destroy(ThreadPool *thiz) {
	return_val_if_fail(thiz, -1);
	free(thiz->task_queue_);
	free(thiz->task_fun_);
	threadpool_stop_all_task(thiz);
	pthread_mutex_destroy(&thiz->mutex_);
	pthread_cond_destroy(&thiz->cond_);
	free(thiz);
	thiz = NULL;

	return 0;
}

int getThreadNum(ThreadPool *thiz){
       return thiz->complete_task_num; 
}

//*****************************************************************************************
//执行任务;
//*****************************************************************************************
static void* threadpool_excute_task(void *arg) {
	ThreadPool *thiz = (ThreadPool *) arg;
	return_null_if_fail(thiz);

	while (1) {
		int thread_num = 0;
        int thread_num_c = 0;
		void *tmp_arg = NULL;
		threadpool_task_fun_ task_fun;
		pthread_mutex_lock(&thiz->mutex_);
		if ((thread_num = (int) thiz->task_queue_[0]) > 0) {
			tmp_arg = thiz->task_queue_[thiz->start];
			task_fun = thiz->task_fun_[thiz->start];
			if (++thiz->start > thiz->max_task_num) {
				thiz->start = 1;
			}
			--thread_num;
			thiz->task_queue_[0] = (void *) thread_num;
			thread_num = 1; //执行调度函数
		} else {
			pthread_cond_wait(&thiz->cond_, &thiz->mutex_); //等待线程调度
			pthread_mutex_unlock(&thiz->mutex_);
			continue;
		}
		pthread_mutex_unlock(&thiz->mutex_);
		if (thread_num > 0){
			task_fun(tmp_arg);

            pthread_mutex_lock(&thiz->mutex_);
            thiz->complete_task_num++;
            pthread_mutex_unlock(&thiz->mutex_);
            
        }
	}

	return (void *) 0;
}

