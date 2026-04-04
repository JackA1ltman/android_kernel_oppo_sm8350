/* SPDX-License-Identifier: GPL-2.0+ */
/*
 * Read-Copy Update mechanism for mutual exclusion, adapted for tracing.
 *
 * Stub for kernels without CONFIG_TASKS_TRACE_RCU (5.4 backport).
 * Falls back to regular RCU tasks primitives.
 */

#ifndef __LINUX_RCUPDATE_TRACE_H
#define __LINUX_RCUPDATE_TRACE_H

#include <linux/sched.h>
#include <linux/rcupdate.h>

#ifdef CONFIG_DEBUG_LOCK_ALLOC

extern struct lockdep_map rcu_trace_lock_map;

static inline int rcu_read_lock_trace_held(void)
{
	return lock_is_held(&rcu_trace_lock_map);
}

#else /* #ifdef CONFIG_DEBUG_LOCK_ALLOC */

static inline int rcu_read_lock_trace_held(void)
{
	return 1;
}

#endif /* #else #ifdef CONFIG_DEBUG_LOCK_ALLOC */

/*
 * 5.4 backport: CONFIG_TASKS_TRACE_RCU is not available.
 * Provide stubs that fall back to regular RCU tasks or plain RCU.
 */
static inline void rcu_read_lock_trace(void)
{
	rcu_read_lock();
}

static inline void rcu_read_unlock_trace(void)
{
	rcu_read_unlock();
}

#ifdef CONFIG_TASKS_RCU
#define call_rcu_tasks_trace	call_rcu_tasks
#define synchronize_rcu_tasks_trace	synchronize_rcu_tasks
#define rcu_barrier_tasks_trace	rcu_barrier
#else
#define call_rcu_tasks_trace	call_rcu
#define synchronize_rcu_tasks_trace	synchronize_rcu
#define rcu_barrier_tasks_trace	rcu_barrier
#endif

#endif /* __LINUX_RCUPDATE_TRACE_H */
