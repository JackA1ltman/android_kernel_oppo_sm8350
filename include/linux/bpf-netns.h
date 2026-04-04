/* SPDX-License-Identifier: GPL-2.0 */
/*
 * BPF netns stub for 5.4 backport.
 * Full netns BPF support requires extensive networking changes.
 */
#ifndef _BPF_NETNS_H
#define _BPF_NETNS_H

#include <linux/bpf.h>

enum netns_bpf_attach_type {
NETNS_BPF_INVALID = -1,
NETNS_BPF_FLOW_DISSECTOR = 0,
NETNS_BPF_SK_LOOKUP,
MAX_NETNS_BPF_ATTACH_TYPE
};

static inline int netns_bpf_prog_query(const union bpf_attr *attr,
union bpf_attr __user *uattr)
{
return -EOPNOTSUPP;
}

static inline int netns_bpf_prog_attach(const union bpf_attr *attr,
 struct bpf_prog *prog)
{
return -EOPNOTSUPP;
}

static inline int netns_bpf_prog_detach(const union bpf_attr *attr,
 enum bpf_prog_type ptype)
{
return -EOPNOTSUPP;
}

static inline int netns_bpf_link_create(const union bpf_attr *attr,
 struct bpf_prog *prog)
{
return -EOPNOTSUPP;
}

#endif /* _BPF_NETNS_H */
