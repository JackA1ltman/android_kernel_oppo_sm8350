/* SPDX-License-Identifier: GPL-2.0 */
#ifndef __BPF_COMPAT_54_H
#define __BPF_COMPAT_54_H

#include <linux/capability.h>

static inline bool bpf_capable(void)
{
	return capable(CAP_SYS_ADMIN);
}

#ifndef perfmon_capable
#define perfmon_capable() capable(CAP_SYS_ADMIN)
#endif

#ifndef U32_MIN
#define U32_MIN		((u32)0)
#endif

#ifndef S32_MIN
#define S32_MIN		((s32)(-2147483647-1))
#endif

#ifndef S32_MAX
#define S32_MAX		((s32)2147483647)
#endif

#ifndef AUDIT_BPF
#define AUDIT_BPF	1334
#endif

#ifndef BTF_FUNC_GLOBAL
#define BTF_FUNC_GLOBAL	2
#endif

#include <linux/gfp.h>
#include <linux/vmalloc.h>
static inline void *vmalloc_user_node_flags(unsigned long size, int node,
					    gfp_t flags)
{
	return __vmalloc_node_flags_caller(size, node,
			flags | __GFP_ZERO, __builtin_return_address(0));
}

#endif /* __BPF_COMPAT_54_H */
