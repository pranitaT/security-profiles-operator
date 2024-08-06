#ifndef __VMLINUX_H__
#define __VMLINUX_H__

#ifndef BPF_NO_PRESERVE_ACCESS_INDEX
#pragma clang attribute push (__attribute__((preserve_access_index)), apply_to = record)
#endif

typedef char *__gnuc_va_list;

typedef __gnuc_va_list va_list;

typedef signed char __s8;

typedef unsigned char __u8;

typedef short int __s16;

typedef short unsigned int __u16;

typedef int __s32;

typedef unsigned int __u32;

typedef long long int __s64;

typedef long long unsigned int __u64;

typedef __s8 s8;

typedef __u8 u8;

typedef __s16 s16;

typedef __u16 u16;

typedef __s32 s32;

typedef __u32 u32;

typedef __s64 s64;

typedef __u64 u64;

typedef struct {
	__u32 u[4];
} __vector128;

typedef __vector128 vector128;

enum {
	false = 0,
	true = 1,
};

typedef long int __kernel_long_t;

typedef long unsigned int __kernel_ulong_t;

typedef int __kernel_pid_t;

typedef unsigned int __kernel_uid32_t;

typedef unsigned int __kernel_gid32_t;

typedef __kernel_ulong_t __kernel_size_t;

typedef __kernel_long_t __kernel_ssize_t;

typedef long long int __kernel_loff_t;

typedef __kernel_long_t __kernel_time_t;

typedef __kernel_long_t __kernel_clock_t;

typedef int __kernel_timer_t;

typedef int __kernel_clockid_t;

typedef __u16 __be16;

typedef __u32 __be32;

typedef __u64 __be64;

typedef unsigned int __poll_t;

typedef u32 __kernel_dev_t;

typedef __kernel_dev_t dev_t;

typedef short unsigned int umode_t;

typedef __kernel_pid_t pid_t;

typedef __kernel_clockid_t clockid_t;

typedef _Bool bool;

typedef __kernel_uid32_t uid_t;

typedef __kernel_gid32_t gid_t;

typedef __kernel_loff_t loff_t;

typedef __kernel_size_t size_t;

typedef __kernel_ssize_t ssize_t;

typedef long unsigned int ulong;

typedef s32 int32_t;

typedef u32 uint32_t;

typedef u64 uint64_t;

typedef u64 sector_t;

typedef u64 blkcnt_t;

typedef u64 dma_addr_t;

typedef unsigned int gfp_t;

typedef unsigned int fmode_t;

typedef u64 phys_addr_t;

typedef phys_addr_t resource_size_t;

typedef long unsigned int irq_hw_number_t;

typedef struct {
	int counter;
} atomic_t;

typedef struct {
	long int counter;
} atomic64_t;

struct list_head {
	struct list_head *next;
	struct list_head *prev;
};

struct hlist_node;

struct hlist_head {
	struct hlist_node *first;
};

struct hlist_node {
	struct hlist_node *next;
	struct hlist_node **pprev;
};

struct callback_head {
	struct callback_head *next;
	void (*func)(struct callback_head *);
};

struct cpu_spec;

typedef void (*cpu_setup_t)(long unsigned int, struct cpu_spec *);

enum powerpc_pmc_type {
	PPC_PMC_DEFAULT = 0,
	PPC_PMC_IBM = 1,
	PPC_PMC_PA6T = 2,
	PPC_PMC_G4 = 3,
};

typedef void (*cpu_restore_t)();

enum powerpc_oprofile_type {
	PPC_OPROFILE_INVALID = 0,
	PPC_OPROFILE_RS64 = 1,
	PPC_OPROFILE_POWER4 = 2,
	PPC_OPROFILE_G4 = 3,
	PPC_OPROFILE_FSL_EMB = 4,
	PPC_OPROFILE_CELL = 5,
	PPC_OPROFILE_PA6T = 6,
};

struct pt_regs;

struct cpu_spec {
	unsigned int pvr_mask;
	unsigned int pvr_value;
	char *cpu_name;
	long unsigned int cpu_features;
	unsigned int cpu_user_features;
	unsigned int cpu_user_features2;
	unsigned int mmu_features;
	unsigned int icache_bsize;
	unsigned int dcache_bsize;
	void (*cpu_down_flush)();
	unsigned int num_pmcs;
	enum powerpc_pmc_type pmc_type;
	cpu_setup_t cpu_setup;
	cpu_restore_t cpu_restore;
	char *oprofile_cpu_type;
	enum powerpc_oprofile_type oprofile_type;
	long unsigned int oprofile_mmcra_sihv;
	long unsigned int oprofile_mmcra_sipr;
	long unsigned int oprofile_mmcra_clear;
	char *platform;
	int (*machine_check)(struct pt_regs *);
	long int (*machine_check_early)(struct pt_regs *);
};

struct user_pt_regs {
	long unsigned int gpr[32];
	long unsigned int nip;
	long unsigned int msr;
	long unsigned int orig_gpr3;
	long unsigned int ctr;
	long unsigned int link;
	long unsigned int xer;
	long unsigned int ccr;
	long unsigned int softe;
	long unsigned int trap;
	long unsigned int dar;
	long unsigned int dsisr;
	long unsigned int result;
};

struct pt_regs {
	union {
		struct user_pt_regs user_regs;
		struct {
			long unsigned int gpr[32];
			long unsigned int nip;
			long unsigned int msr;
			long unsigned int orig_gpr3;
			long unsigned int ctr;
			long unsigned int link;
			long unsigned int xer;
			long unsigned int ccr;
			long unsigned int softe;
			long unsigned int trap;
			long unsigned int dar;
			long unsigned int dsisr;
			long unsigned int result;
		};
	};
	long unsigned int ppr;
	long unsigned int __pad;
};

typedef int (*initcall_t)();

typedef initcall_t initcall_entry_t;

struct lock_class_key {};

struct dentry;

struct super_block;

struct module;

struct fs_context;

struct fs_parameter_spec;

struct file_system_type {
	const char *name;
	int fs_flags;
	struct dentry * (*mount)(struct file_system_type *, int, const char *, void *);
	void (*kill_sb)(struct super_block *);
	struct module *owner;
	struct file_system_type *next;
	struct hlist_head fs_supers;
	struct lock_class_key s_lock_key;
	struct lock_class_key s_umount_key;
	struct lock_class_key s_vfs_rename_key;
	struct lock_class_key s_writers_key[3];
	struct lock_class_key i_lock_key;
	struct lock_class_key i_mutex_key;
	struct lock_class_key i_mutex_dir_key;
	union {
		int (*init_fs_context)(struct fs_context *);
		struct {
			long unsigned int rh_reserved1;
		} rh_kabi_hidden_2319;
		union {		};
	};
	union {
		const struct fs_parameter_spec *parameters;
		struct {
			long unsigned int rh_reserved2;
		} rh_kabi_hidden_2320;
		union {		};
	};
	long unsigned int rh_reserved3;
	long unsigned int rh_reserved4;
};

struct ppc_cache_info {
	u32 size;
	u32 line_size;
	u32 block_size;
	u32 log_block_size;
	u32 blocks_per_page;
	u32 sets;
	u32 assoc;
};

struct ppc64_caches {
	struct ppc_cache_info l1d;
	struct ppc_cache_info l1i;
	struct ppc_cache_info l2;
	struct ppc_cache_info l3;
};

typedef struct {
	volatile unsigned int slock;
} arch_spinlock_t;

typedef struct {
	volatile int lock;
} arch_rwlock_t;

struct raw_spinlock {
	arch_spinlock_t raw_lock;
};

typedef struct raw_spinlock raw_spinlock_t;

struct spinlock {
	union {
		struct raw_spinlock rlock;
	};
};

typedef struct spinlock spinlock_t;

typedef struct {
	arch_rwlock_t raw_lock;
} rwlock_t;

struct ratelimit_state {
	raw_spinlock_t lock;
	int interval;
	int burst;
	int printed;
	int missed;
	long unsigned int begin;
	long unsigned int flags;
};

typedef u64 jump_label_t;

struct jump_entry {
	jump_label_t code;
	jump_label_t target;
	jump_label_t key;
};

struct static_key_mod;

struct static_key {
	atomic_t enabled;
	union {
		long unsigned int type;
		struct jump_entry *entries;
		struct static_key_mod *next;
	};
};

struct static_key_true {
	struct static_key key;
};

struct static_key_false {
	struct static_key key;
};

typedef void *fl_owner_t;

struct file;

struct kiocb;

struct iov_iter;

struct dir_context;

struct poll_table_struct;

struct vm_area_struct;

struct inode;

struct file_lock;

struct page;

struct pipe_inode_info;

struct seq_file;

struct file_operations {
	struct module *owner;
	loff_t (*llseek)(struct file *, loff_t, int);
	ssize_t (*read)(struct file *, char *, size_t, loff_t *);
	ssize_t (*write)(struct file *, const char *, size_t, loff_t *);
	ssize_t (*read_iter)(struct kiocb *, struct iov_iter *);
	ssize_t (*write_iter)(struct kiocb *, struct iov_iter *);
	int (*iopoll)(struct kiocb *, bool);
	int (*iterate)(struct file *, struct dir_context *);
	int (*iterate_shared)(struct file *, struct dir_context *);
	__poll_t (*poll)(struct file *, struct poll_table_struct *);
	long int (*unlocked_ioctl)(struct file *, unsigned int, long unsigned int);
	long int (*compat_ioctl)(struct file *, unsigned int, long unsigned int);
	int (*mmap)(struct file *, struct vm_area_struct *);
	long unsigned int mmap_supported_flags;
	int (*open)(struct inode *, struct file *);
	int (*flush)(struct file *, fl_owner_t);
	int (*release)(struct inode *, struct file *);
	int (*fsync)(struct file *, loff_t, loff_t, int);
	int (*fasync)(int, struct file *, int);
	int (*lock)(struct file *, int, struct file_lock *);
	ssize_t (*sendpage)(struct file *, struct page *, int, size_t, loff_t *, int);
	long unsigned int (*get_unmapped_area)(struct file *, long unsigned int, long unsigned int, long unsigned int, long unsigned int);
	int (*check_flags)(int);
	int (*flock)(struct file *, int, struct file_lock *);
	ssize_t (*splice_write)(struct pipe_inode_info *, struct file *, loff_t *, size_t, unsigned int);
	ssize_t (*splice_read)(struct file *, loff_t *, struct pipe_inode_info *, size_t, unsigned int);
	int (*setlease)(struct file *, long int, struct file_lock **, void **);
	long int (*fallocate)(struct file *, int, loff_t, loff_t);
	void (*show_fdinfo)(struct seq_file *, struct file *);
	ssize_t (*copy_file_range)(struct file *, loff_t, struct file *, loff_t, size_t, unsigned int);
	loff_t (*remap_file_range)(struct file *, loff_t, struct file *, loff_t, loff_t, unsigned int);
	int (*fadvise)(struct file *, loff_t, loff_t, int);
	long unsigned int rh_reserved1;
	long unsigned int rh_reserved2;
	long unsigned int rh_reserved3;
	long unsigned int rh_reserved4;
};

struct notifier_block;

struct atomic_notifier_head {
	spinlock_t lock;
	struct notifier_block *head;
};

enum system_states {
	SYSTEM_BOOTING = 0,
	SYSTEM_SCHEDULING = 1,
	SYSTEM_FREEING_INITMEM = 2,
	SYSTEM_RUNNING = 3,
	SYSTEM_HALT = 4,
	SYSTEM_POWER_OFF = 5,
	SYSTEM_RESTART = 6,
	SYSTEM_SUSPEND = 7,
};

struct taint_flag {
	char c_true;
	char c_false;
	bool module;
};

typedef __s64 time64_t;

struct timespec {
	__kernel_time_t tv_sec;
	long int tv_nsec;
};

struct timezone {
	int tz_minuteswest;
	int tz_dsttime;
};

struct timespec64 {
	time64_t tv_sec;
	long int tv_nsec;
};

enum timespec_type {
	TT_NONE = 0,
	TT_NATIVE = 1,
	TT_COMPAT = 2,
};

struct compat_timespec;

struct pollfd;

struct restart_block {
	long int (*fn)(struct restart_block *);
	union {
		struct {
			u32 *uaddr;
			u32 val;
			u32 flags;
			u32 bitset;
			u64 time;
			u32 *uaddr2;
		} futex;
		struct {
			clockid_t clockid;
			enum timespec_type type;
			union {
				struct timespec *rmtp;
				struct compat_timespec *compat_rmtp;
			};
			u64 expires;
		} nanosleep;
		struct {
			struct pollfd *ufds;
			int nfds;
			int has_timeout;
			long unsigned int tv_sec;
			long unsigned int tv_nsec;
		} poll;
	};
};

struct mmu_psize_def {
	unsigned int shift;
	int penc[16];
	unsigned int tlbiel;
	long unsigned int avpnm;
	union {
		long unsigned int sllp;
		long unsigned int ap;
	};
};

typedef struct {
	__be64 pte;
} pte_t;

typedef struct {
	__be64 pmd;
} pmd_t;

typedef struct {
	__be64 pud;
} pud_t;

typedef struct {
	__be64 pgd;
} pgd_t;

typedef struct {
	long unsigned int pgprot;
} pgprot_t;

typedef struct {
	pte_t pte;
	long unsigned int hidx;
} real_pte_t;

typedef pte_t *pgtable_t;

struct address_space;

struct kmem_cache;

struct mm_struct;

struct dev_pagemap;

struct mem_cgroup;

struct page {
	long unsigned int flags;
	union {
		struct {
			struct list_head lru;
			struct address_space *mapping;
			long unsigned int index;
			long unsigned int private;
		};
		struct {
			dma_addr_t dma_addr;
		};
		struct {
			union {
				struct list_head slab_list;
				struct {
					struct page *next;
					int pages;
					int pobjects;
				};
			};
			struct kmem_cache *slab_cache;
			void *freelist;
			union {
				void *s_mem;
				long unsigned int counters;
				struct {
					unsigned int inuse: 16;
					unsigned int objects: 15;
					unsigned int frozen: 1;
				};
			};
		};
		struct {
			long unsigned int compound_head;
			unsigned char compound_dtor;
			unsigned char compound_order;
			atomic_t compound_mapcount;
			unsigned int mapcount_seqcount;
			unsigned int compound_nr;
		};
		struct {
			long unsigned int _compound_pad_1;
			union {
				atomic_t hpage_pinned_refcount;
				struct {
					long unsigned int _compound_pad_2;
				} rh_kabi_hidden_161;
				union {				};
			};
			struct list_head deferred_list;
		};
		struct {
			long unsigned int _pt_pad_1;
			pgtable_t pmd_huge_pte;
			long unsigned int _pt_pad_2;
			union {
				union {
					struct mm_struct *pt_mm;
					atomic_t pt_frag_refcount;
				};
				struct {
					struct mm_struct *pt_mm;
				} rh_kabi_hidden_173;
				union {				};
			};
			spinlock_t ptl;
		};
		struct {
			struct dev_pagemap *pgmap;
			union {
				void *zone_device_data;
				struct {
					long unsigned int hmm_data;
				} rh_kabi_hidden_184;
				union {				};
			};
			long unsigned int _zd_pad_1;
		};
		struct callback_head callback_head;
	};
	union {
		atomic_t _mapcount;
		unsigned int page_type;
		unsigned int active;
		int units;
	};
	atomic_t _refcount;
	union {
		long unsigned int memcg_data;
		struct {
			struct mem_cgroup *mem_cgroup;
		} rh_kabi_hidden_216;
		union {		};
	};
};

struct mmu_hash_ops {
	void (*hpte_invalidate)(long unsigned int, long unsigned int, int, int, int, int);
	long int (*hpte_updatepp)(long unsigned int, long unsigned int, long unsigned int, int, int, int, long unsigned int);
	void (*hpte_updateboltedpp)(long unsigned int, long unsigned int, int, int);
	long int (*hpte_insert)(long unsigned int, long unsigned int, long unsigned int, long unsigned int, long unsigned int, int, int, int);
	long int (*hpte_remove)(long unsigned int);
	int (*hpte_removebolted)(long unsigned int, int, int);
	void (*flush_hash_range)(long unsigned int, int);
	void (*hugepage_invalidate)(long unsigned int, long unsigned int, unsigned char *, int, int, int);
	int (*resize_hpt)(long unsigned int);
	void (*hpte_clear_all)();
};

struct hash_pte {
	__be64 v;
	__be64 r;
};

struct slb_entry {
	u64 esid;
	u64 vsid;
};

struct subpage_prot_table {
	long unsigned int maxaddr;
	unsigned int **protptrs[512];
	unsigned int *low_prot[4];
};

struct prtb_entry {
	__be64 prtb0;
	__be64 prtb1;
};

struct patb_entry {
	__be64 patb0;
	__be64 patb1;
};

typedef long unsigned int mm_context_id_t;

struct slice_mask {
	u64 low_slices;
	long unsigned int high_slices[64];
};

struct npu_context;

typedef struct {
	union {
		mm_context_id_t id;
		mm_context_id_t extended_id[8];
	};
	u16 user_psize;
	atomic_t active_cpus;
	atomic_t copros;
	struct npu_context *npu_context;
	unsigned char low_slices_psize[8];
	unsigned char high_slices_psize[2048];
	long unsigned int slb_addr_limit;
	struct slice_mask mask_64k;
	struct slice_mask mask_4k;
	struct slice_mask mask_16m;
	struct slice_mask mask_16g;
	long unsigned int vdso_base;
	struct subpage_prot_table spt;
	void *pte_frag;
	void *pmd_frag;
	struct list_head iommu_group_mem_list;
	u32 pkey_allocation_map;
	s16 execute_only_pkey;
} mm_context_t;

struct arch_hw_breakpoint {
	long unsigned int address;
	u16 type;
	u16 len;
	u16 hw_len;
	u8 flags;
};

struct pmu;

typedef struct {
	long unsigned int seg;
} mm_segment_t;

struct thread_fp_state {
	u64 fpr[64];
	u64 fpscr;
	long: 64;
};

struct thread_vr_state {
	vector128 vr[32];
	vector128 vscr;
};

struct debug_reg {};

struct perf_event;

struct thread_struct {
	long unsigned int ksp;
	long unsigned int ksp_vsid;
	struct pt_regs *regs;
	mm_segment_t addr_limit;
	struct debug_reg debug;
	struct thread_fp_state fp_state;
	struct thread_fp_state *fp_save_area;
	int fpexc_mode;
	unsigned int align_ctl;
	struct perf_event *ptrace_bps[2];
	struct perf_event *last_hit_ubp[2];
	struct arch_hw_breakpoint hw_brk[2];
	long unsigned int trap_nr;
	u8 load_fp;
	u8 load_vec;
	long: 48;
	struct thread_vr_state vr_state;
	struct thread_vr_state *vr_save_area;
	long unsigned int vrsave;
	int used_vr;
	int used_vsr;
	u8 load_tm;
	u64 tm_tfhar;
	u64 tm_texasr;
	u64 tm_tfiar;
	struct pt_regs ckpt_regs;
	long unsigned int tm_tar;
	long unsigned int tm_ppr;
	long unsigned int tm_dscr;
	struct thread_fp_state ckfp_state;
	struct thread_vr_state ckvr_state;
	long unsigned int ckvrsave;
	long unsigned int amr;
	long unsigned int iamr;
	long unsigned int uamor;
	long unsigned int dscr;
	long unsigned int fscr;
	int dscr_inherit;
	long unsigned int rh_reserved_ppr;
	long unsigned int tidr;
	long unsigned int tar;
	long unsigned int ebbrr;
	long unsigned int ebbhr;
	long unsigned int bescr;
	long unsigned int siar;
	long unsigned int sdar;
	long unsigned int sier;
	long unsigned int mmcr2;
	unsigned int mmcr0;
	unsigned int used_ebb;
	unsigned int rh_reserved_used_vas;
	long unsigned int mmcr3;
	long unsigned int sier2;
	long unsigned int sier3;
};

struct cpu_accounting_data {
	long unsigned int utime;
	long unsigned int stime;
	long unsigned int gtime;
	long unsigned int hardirq_time;
	long unsigned int softirq_time;
	long unsigned int steal_time;
	long unsigned int idle_time;
	long unsigned int starttime;
	long unsigned int starttime_user;
};

struct task_struct;

struct thread_info {
	struct task_struct *task;
	int cpu;
	int preempt_count;
	long unsigned int local_flags;
	long unsigned int *livepatch_sp;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long unsigned int flags;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
};

struct refcount_struct {
	atomic_t refs;
};

typedef struct refcount_struct refcount_t;

struct llist_node {
	struct llist_node *next;
};

struct load_weight {
	long unsigned int weight;
	u32 inv_weight;
};

struct rb_node {
	long unsigned int __rb_parent_color;
	struct rb_node *rb_right;
	struct rb_node *rb_left;
};

struct sched_statistics {
	u64 wait_start;
	u64 wait_max;
	u64 wait_count;
	u64 wait_sum;
	u64 iowait_count;
	u64 iowait_sum;
	u64 sleep_start;
	u64 sleep_max;
	s64 sum_sleep_runtime;
	u64 block_start;
	u64 block_max;
	u64 exec_max;
	u64 slice_max;
	u64 nr_migrations_cold;
	u64 nr_failed_migrations_affine;
	u64 nr_failed_migrations_running;
	u64 nr_failed_migrations_hot;
	u64 nr_forced_migrations;
	u64 nr_wakeups;
	u64 nr_wakeups_sync;
	u64 nr_wakeups_migrate;
	u64 nr_wakeups_local;
	u64 nr_wakeups_remote;
	u64 nr_wakeups_affine;
	u64 nr_wakeups_affine_attempts;
	u64 nr_wakeups_passive;
	u64 nr_wakeups_idle;
};

struct util_est {
	unsigned int enqueued;
	unsigned int ewma;
};

struct sched_avg {
	u64 last_update_time;
	u64 load_sum;
	u64 runnable_sum;
	u32 util_sum;
	u32 period_contrib;
	long unsigned int load_avg;
	long unsigned int runnable_avg;
	long unsigned int util_avg;
	struct util_est util_est;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
};

struct cfs_rq;

struct sched_entity {
	struct load_weight load;
	long unsigned int runnable_weight;
	struct rb_node run_node;
	struct list_head group_node;
	unsigned int on_rq;
	u64 exec_start;
	u64 sum_exec_runtime;
	u64 vruntime;
	u64 prev_sum_exec_runtime;
	u64 nr_migrations;
	struct sched_statistics statistics;
	int depth;
	struct sched_entity *parent;
	struct cfs_rq *cfs_rq;
	struct cfs_rq *my_q;
	long: 64;
	long: 64;
	long: 64;
	struct sched_avg avg;
	long unsigned int rh_reserved1;
	long unsigned int rh_reserved2;
	long unsigned int rh_reserved3;
	long unsigned int rh_reserved4;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
};

struct rt_rq;

struct sched_rt_entity {
	struct list_head run_list;
	long unsigned int timeout;
	long unsigned int watchdog_stamp;
	unsigned int time_slice;
	short unsigned int on_rq;
	short unsigned int on_list;
	struct sched_rt_entity *back;
	struct sched_rt_entity *parent;
	struct rt_rq *rt_rq;
	struct rt_rq *my_q;
};

typedef s64 ktime_t;

struct timerqueue_node {
	struct rb_node node;
	ktime_t expires;
};

enum hrtimer_restart {
	HRTIMER_NORESTART = 0,
	HRTIMER_RESTART = 1,
};

struct hrtimer_clock_base;

struct hrtimer_rh;

struct hrtimer {
	struct timerqueue_node node;
	ktime_t _softexpires;
	enum hrtimer_restart (*function)(struct hrtimer *);
	struct hrtimer_clock_base *base;
	u8 state;
	u8 is_rel;
	u8 is_soft;
	u8 is_hard;
	size_t hrtimer_size_rh;
	struct hrtimer_rh *_rh;
};

struct sched_dl_entity {
	struct rb_node rb_node;
	u64 dl_runtime;
	u64 dl_deadline;
	u64 dl_period;
	u64 dl_bw;
	u64 dl_density;
	s64 runtime;
	u64 deadline;
	unsigned int flags;
	unsigned int dl_throttled: 1;
	unsigned int rh_reserved_dl_boosted: 1;
	unsigned int dl_yielded: 1;
	unsigned int dl_non_contending: 1;
	unsigned int dl_overrun: 1;
	struct hrtimer dl_timer;
	struct hrtimer inactive_timer;
};

struct cpumask {
	long unsigned int bits[32];
};

typedef struct cpumask cpumask_t;

struct sched_info {
	long unsigned int pcount;
	long long unsigned int run_delay;
	long long unsigned int last_arrival;
	long long unsigned int last_queued;
};

struct plist_node {
	int prio;
	struct list_head prio_list;
	struct list_head node_list;
};

struct vmacache {
	u64 seqnum;
	struct vm_area_struct *vmas[4];
};

struct task_rss_stat {
	int events;
	int count[4];
};

struct prev_cputime {
	u64 utime;
	u64 stime;
	raw_spinlock_t lock;
};

struct seqcount {
	unsigned int sequence;
};

typedef struct seqcount seqcount_t;

enum vtime_state {
	VTIME_INACTIVE = 0,
	VTIME_IDLE = 1,
	VTIME_SYS = 2,
	VTIME_USER = 3,
	VTIME_GUEST = 4,
};

struct vtime {
	seqcount_t seqcount;
	long long unsigned int starttime;
	enum vtime_state state;
	unsigned int cpu;
	u64 utime;
	u64 stime;
	u64 gtime;
};

struct __call_single_node {
	union {
		unsigned int u_flags;
		atomic_t a_flags;
	};
	struct llist_node llist;
};

struct task_cputime {
	u64 utime;
	u64 stime;
	long long unsigned int sum_exec_runtime;
};

typedef atomic64_t atomic_long_t;

struct optimistic_spin_queue {
	atomic_t tail;
};

struct mutex {
	atomic_long_t owner;
	union {
		raw_spinlock_t wait_lock;
		struct {
			spinlock_t wait_lock;
		} rh_kabi_hidden_66;
		union {		};
	};
	struct optimistic_spin_queue osq;
	struct list_head wait_list;
};

struct sem_undo_list;

struct sysv_sem {
	struct sem_undo_list *undo_list;
};

struct sysv_shm {
	struct list_head shm_clist;
};

typedef struct {
	long unsigned int sig[1];
} sigset_t;

struct sigpending {
	struct list_head list;
	sigset_t signal;
};

typedef struct {
	uid_t val;
} kuid_t;

struct seccomp_filter;

struct seccomp {
	int mode;
	struct seccomp_filter *filter;
};

struct wake_q_node {
	struct wake_q_node *next;
};

struct rb_root {
	struct rb_node *rb_node;
};

struct rb_root_cached {
	struct rb_root rb_root;
	struct rb_node *rb_leftmost;
};

struct task_io_accounting {
	u64 rchar;
	u64 wchar;
	u64 syscr;
	u64 syscw;
	u64 read_bytes;
	u64 write_bytes;
	u64 cancelled_write_bytes;
};

typedef struct {
	long unsigned int bits[4];
} nodemask_t;

struct seqcount_spinlock {
	seqcount_t seqcount;
};

typedef struct seqcount_spinlock seqcount_spinlock_t;

struct tlbflush_unmap_batch {};

struct page_frag {
	struct page *page;
	__u32 offset;
	__u32 size;
};

struct kmap_ctrl {};

struct sched_class;

struct task_group;

struct pid;

struct task_struct_rh;

struct completion;

struct cred;

struct nameidata;

struct fs_struct;

struct files_struct;

struct nsproxy;

struct signal_struct;

struct sighand_struct;

struct audit_context;

struct rt_mutex_waiter;

struct bio_list;

struct blk_plug;

struct reclaim_state;

struct backing_dev_info;

struct io_context;

struct kernel_siginfo;

typedef struct kernel_siginfo kernel_siginfo_t;

struct siginfo;

typedef struct siginfo siginfo_t;

struct css_set;

struct robust_list_head;

struct compat_robust_list_head;

struct futex_pi_state;

struct perf_event_context;

struct mempolicy;

struct numa_group;

struct rseq;

struct task_delay_info;

struct ftrace_ret_stack;

struct request_queue;

struct uprobe_task;

struct task_struct {
	union {
		struct {
			unsigned int __state;
		};
		struct {
			volatile long int state;
		} rh_kabi_hidden_739;
		union {		};
	};
	void *stack;
	union {
		refcount_t usage;
		struct {
			atomic_t usage;
		} rh_kabi_hidden_748;
		union {		};
	};
	unsigned int flags;
	unsigned int ptrace;
	struct llist_node rh_reserved_wake_entry;
	int on_cpu;
	unsigned int wakee_flips;
	long unsigned int wakee_flip_decay_ts;
	struct task_struct *last_wakee;
	int recent_used_cpu;
	int wake_cpu;
	int on_rq;
	int prio;
	int static_prio;
	int normal_prio;
	unsigned int rt_priority;
	const struct sched_class *sched_class;
	long: 64;
	long: 64;
	long: 64;
	struct sched_entity se;
	struct sched_rt_entity rt;
	struct task_group *sched_task_group;
	struct sched_dl_entity dl;
	struct hlist_head preempt_notifiers;
	unsigned int btrace_seq;
	unsigned int policy;
	int nr_cpus_allowed;
	short unsigned int migration_disabled;
	short unsigned int migration_flags;
	cpumask_t cpus_mask;
	struct sched_info sched_info;
	struct list_head tasks;
	struct plist_node pushable_tasks;
	struct rb_node pushable_dl_tasks;
	struct mm_struct *mm;
	struct mm_struct *active_mm;
	struct vmacache vmacache;
	struct task_rss_stat rss_stat;
	int exit_state;
	int exit_code;
	int exit_signal;
	int pdeath_signal;
	long unsigned int jobctl;
	unsigned int personality;
	unsigned int sched_reset_on_fork: 1;
	unsigned int sched_contributes_to_load: 1;
	unsigned int sched_migrated: 1;
	unsigned int rh_reserved_sched_remote_wakeup: 1;
	unsigned int sched_psi_wake_requeue: 1;
	int: 27;
	unsigned int in_execve: 1;
	unsigned int in_iowait: 1;
	unsigned int restore_sigmask: 1;
	unsigned int in_user_fault: 1;
	unsigned int rh_reserved_memcg_kmem_skip_account: 1;
	unsigned int no_cgroup_migration: 1;
	unsigned int use_memdelay: 1;
	unsigned int frozen: 1;
	unsigned int sched_remote_wakeup: 1;
	unsigned int in_memstall: 1;
	unsigned int in_page_owner: 1;
	unsigned int in_thrashing: 1;
	long unsigned int atomic_flags;
	struct restart_block restart_block;
	pid_t pid;
	pid_t tgid;
	struct task_struct *real_parent;
	struct task_struct *parent;
	struct list_head children;
	struct list_head sibling;
	struct task_struct *group_leader;
	struct list_head ptraced;
	struct list_head ptrace_entry;
	struct mem_cgroup *active_memcg;
	union {
		long unsigned int stack_canary;
		struct {
			long unsigned int rh_reserved2;
		} rh_kabi_hidden_982;
		union {		};
	};
	struct pid *thread_pid;
	union {
		const cpumask_t *cpus_ptr;
		struct {
			long unsigned int rh_reserved3;
		} rh_kabi_hidden_987;
		union {		};
	};
	struct task_struct_rh *task_struct_rh;
	struct pid *rh_pgid;
	struct sched_dl_entity *pi_se;
	union {
		void *migration_pending;
		struct {
			long unsigned int rh_reserved6;
		} rh_kabi_hidden_1001;
		union {		};
	};
	struct pid *rh_sid;
	struct list_head thread_group;
	struct list_head thread_node;
	struct completion *vfork_done;
	int *set_child_tid;
	int *clear_child_tid;
	u64 utime;
	u64 stime;
	u64 gtime;
	struct prev_cputime prev_cputime;
	struct vtime vtime;
	atomic_t tick_dep_mask;
	long unsigned int nvcsw;
	long unsigned int nivcsw;
	u64 start_time;
	u64 real_start_time;
	long unsigned int min_flt;
	long unsigned int maj_flt;
	union {
		struct {
			struct __call_single_node wake_entry;
		};
		struct {
			struct task_cputime cputime_expires;
		} rh_kabi_hidden_1045;
		union {		};
	};
	union {
		struct {
			struct mutex futex_exit_mutex;
			unsigned int futex_state;
		};
		struct {
			struct list_head cpu_timers[3];
		} rh_kabi_hidden_1049;
		union {		};
	};
	const struct cred *ptracer_cred;
	const struct cred *real_cred;
	const struct cred *cred;
	char comm[16];
	struct nameidata *nameidata;
	struct sysv_sem sysvsem;
	struct sysv_shm sysvshm;
	long unsigned int last_switch_count;
	struct fs_struct *fs;
	struct files_struct *files;
	struct nsproxy *nsproxy;
	struct signal_struct *signal;
	struct sighand_struct *sighand;
	sigset_t blocked;
	sigset_t real_blocked;
	sigset_t saved_sigmask;
	struct sigpending pending;
	long unsigned int sas_ss_sp;
	size_t sas_ss_size;
	unsigned int sas_ss_flags;
	struct callback_head *task_works;
	struct audit_context *audit_context;
	kuid_t loginuid;
	unsigned int sessionid;
	struct seccomp seccomp;
	u32 rh_reserved_parent_exec_id;
	u32 rh_reserved_self_exec_id;
	spinlock_t alloc_lock;
	raw_spinlock_t pi_lock;
	struct wake_q_node wake_q;
	struct rb_root_cached pi_waiters;
	struct task_struct *pi_top_task;
	struct rt_mutex_waiter *pi_blocked_on;
	void *journal_info;
	struct bio_list *bio_list;
	struct blk_plug *plug;
	struct reclaim_state *reclaim_state;
	struct backing_dev_info *backing_dev_info;
	struct io_context *io_context;
	long unsigned int ptrace_message;
	union {
		kernel_siginfo_t *last_siginfo;
		struct {
			siginfo_t *last_siginfo;
		} rh_kabi_hidden_1185;
		union {		};
	};
	struct task_io_accounting ioac;
	u64 acct_rss_mem1;
	u64 acct_vm_mem1;
	u64 acct_timexpd;
	nodemask_t mems_allowed;
	union {
		seqcount_spinlock_t mems_allowed_seq;
		struct {
			seqcount_t mems_allowed_seq;
		} rh_kabi_hidden_1201;
		union {		};
	};
	int cpuset_mem_spread_rotor;
	int cpuset_slab_spread_rotor;
	unsigned int psi_flags;
	struct css_set *cgroups;
	struct list_head cg_list;
	struct robust_list_head *robust_list;
	struct compat_robust_list_head *compat_robust_list;
	struct list_head pi_state_list;
	struct futex_pi_state *pi_state_cache;
	struct perf_event_context *perf_event_ctxp[2];
	struct mutex perf_event_mutex;
	struct list_head perf_event_list;
	struct mempolicy *mempolicy;
	short int il_prev;
	short int pref_node_fork;
	int numa_scan_seq;
	unsigned int numa_scan_period;
	unsigned int numa_scan_period_max;
	int numa_preferred_nid;
	long unsigned int numa_migrate_retry;
	u64 node_stamp;
	u64 last_task_numa_placement;
	u64 last_sum_exec_runtime;
	struct callback_head numa_work;
	struct list_head numa_entry;
	struct numa_group *numa_group;
	long unsigned int *numa_faults;
	long unsigned int total_numa_faults;
	long unsigned int numa_faults_locality[3];
	long unsigned int numa_pages_migrated;
	struct rseq *rseq;
	u32 rseq_len;
	u32 rseq_sig;
	long unsigned int rseq_event_mask;
	struct tlbflush_unmap_batch tlb_ubc;
	union {
		union {
			refcount_t rcu_users;
			struct callback_head rcu;
		};
		struct {
			struct callback_head rcu;
		} rh_kabi_hidden_1308;
		union {		};
	};
	struct pipe_inode_info *splice_pipe;
	struct page_frag task_frag;
	struct task_delay_info *delays;
	int nr_dirtied;
	int nr_dirtied_pause;
	long unsigned int dirty_paused_when;
	u64 timer_slack_ns;
	u64 default_timer_slack_ns;
	int curr_ret_stack;
	struct ftrace_ret_stack *ret_stack;
	long long unsigned int ftrace_timestamp;
	atomic_t trace_overrun;
	atomic_t tracing_graph_pause;
	long unsigned int trace;
	long unsigned int trace_recursion;
	struct mem_cgroup *memcg_in_oom;
	gfp_t memcg_oom_gfp_mask;
	int memcg_oom_order;
	unsigned int memcg_nr_pages_over_high;
	struct request_queue *throttle_queue;
	struct uprobe_task *utask;
	struct kmap_ctrl kmap_ctrl;
	int pagefault_disabled;
	struct task_struct *oom_reaper_list;
	int patch_state;
	void *security;
	union {
		struct hlist_node pid_links[4];
		struct {
			long unsigned int rh_reserved1;
			long unsigned int rh_reserved2;
			long unsigned int rh_reserved3;
			long unsigned int rh_reserved4;
			long unsigned int rh_reserved5;
			long unsigned int rh_reserved6;
			long unsigned int rh_reserved7;
			long unsigned int rh_reserved8;
		} rh_kabi_hidden_1450;
		union {		};
	};
	long: 64;
	struct thread_struct thread;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
};

struct lppaca {
	__be32 desc;
	__be16 size;
	u8 reserved1[3];
	u8 __old_status;
	u8 reserved3[14];
	volatile __be32 dyn_hw_node_id;
	volatile __be32 dyn_hw_proc_id;
	u8 reserved4[56];
	volatile u8 vphn_assoc_counts[8];
	u8 reserved5[32];
	u8 reserved6[48];
	u8 cede_latency_hint;
	u8 ebb_regs_in_use;
	u8 reserved7[6];
	u8 dtl_enable_mask;
	u8 donate_dedicated_cpu;
	u8 fpregs_in_use;
	u8 pmcregs_in_use;
	u8 reserved8[28];
	__be64 wait_state_cycles;
	u8 reserved9[28];
	__be16 slb_count;
	u8 idle;
	u8 vmxregs_in_use;
	volatile __be32 yield_count;
	volatile __be32 dispersion_count;
	volatile __be64 cmo_faults;
	volatile __be64 cmo_fault_time;
	u8 reserved10[104];
	__be32 page_ins;
	u8 reserved11[148];
	volatile __be64 dtl_idx;
	u8 reserved12[96];
};

struct slb_shadow {
	__be32 persistent;
	__be32 buffer_length;
	__be64 reserved;
	struct {
		__be64 esid;
		__be64 vsid;
	} save_area[3];
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
};

struct kvmppc_vcore;

struct kvm_split_mode {
	long unsigned int rpr;
	long unsigned int pmmar;
	long unsigned int ldbar;
	u8 subcore_size;
	u8 do_nap;
	u8 napped[8];
	struct kvmppc_vcore *vc[4];
};

struct kvm_vcpu;

struct kvmppc_host_state {
	ulong host_r1;
	ulong host_r2;
	ulong host_msr;
	ulong vmhandler;
	ulong scratch0;
	ulong scratch1;
	ulong scratch2;
	u8 in_guest;
	u8 restore_hid5;
	u8 napping;
	u8 hwthread_req;
	u8 hwthread_state;
	u8 host_ipi;
	u8 ptid;
	u8 fake_suspend;
	struct kvm_vcpu *kvm_vcpu;
	struct kvmppc_vcore *kvm_vcore;
	void *xics_phys;
	void *xive_tima_phys;
	void *xive_tima_virt;
	u32 saved_xirr;
	u64 dabr;
	u64 host_mmcr[10];
	u32 host_pmc[8];
	u64 host_purr;
	u64 host_spurr;
	u64 host_dscr;
	u64 dec_expires;
	struct kvm_split_mode *kvm_split_mode;
	u64 cfar;
	u64 ppr;
	u64 host_fscr;
};

struct sibling_subcore_state {
	long unsigned int flags;
	u8 in_guest[4];
};

struct pnv_idle_states_t {
	char name[16];
	u32 latency_ns;
	u32 residency_ns;
	u64 psscr_val;
	u64 psscr_mask;
	u32 flags;
	bool valid;
};

enum MCE_Version {
	MCE_V1 = 1,
};

enum MCE_Severity {
	MCE_SEV_NO_ERROR = 0,
	MCE_SEV_WARNING = 1,
	MCE_SEV_SEVERE = 2,
	MCE_SEV_FATAL = 3,
};

enum MCE_Disposition {
	MCE_DISPOSITION_RECOVERED = 0,
	MCE_DISPOSITION_NOT_RECOVERED = 1,
};

enum MCE_Initiator {
	MCE_INITIATOR_UNKNOWN = 0,
	MCE_INITIATOR_CPU = 1,
	MCE_INITIATOR_PCI = 2,
	MCE_INITIATOR_ISA = 3,
	MCE_INITIATOR_MEMORY = 4,
	MCE_INITIATOR_POWERMGM = 5,
};

enum MCE_ErrorType {
	MCE_ERROR_TYPE_UNKNOWN = 0,
	MCE_ERROR_TYPE_UE = 1,
	MCE_ERROR_TYPE_SLB = 2,
	MCE_ERROR_TYPE_ERAT = 3,
	MCE_ERROR_TYPE_TLB = 4,
	MCE_ERROR_TYPE_USER = 5,
	MCE_ERROR_TYPE_RA = 6,
	MCE_ERROR_TYPE_LINK = 7,
	MCE_ERROR_TYPE_DCACHE = 8,
	MCE_ERROR_TYPE_ICACHE = 9,
};

enum MCE_ErrorClass {
	MCE_ECLASS_UNKNOWN = 0,
	MCE_ECLASS_HARDWARE = 1,
	MCE_ECLASS_HARD_INDETERMINATE = 2,
	MCE_ECLASS_SOFTWARE = 3,
	MCE_ECLASS_SOFT_INDETERMINATE = 4,
};

enum MCE_UeErrorType {
	MCE_UE_ERROR_INDETERMINATE = 0,
	MCE_UE_ERROR_IFETCH = 1,
	MCE_UE_ERROR_PAGE_TABLE_WALK_IFETCH = 2,
	MCE_UE_ERROR_LOAD_STORE = 3,
	MCE_UE_ERROR_PAGE_TABLE_WALK_LOAD_STORE = 4,
};

enum MCE_SlbErrorType {
	MCE_SLB_ERROR_INDETERMINATE = 0,
	MCE_SLB_ERROR_PARITY = 1,
	MCE_SLB_ERROR_MULTIHIT = 2,
};

enum MCE_EratErrorType {
	MCE_ERAT_ERROR_INDETERMINATE = 0,
	MCE_ERAT_ERROR_PARITY = 1,
	MCE_ERAT_ERROR_MULTIHIT = 2,
};

enum MCE_TlbErrorType {
	MCE_TLB_ERROR_INDETERMINATE = 0,
	MCE_TLB_ERROR_PARITY = 1,
	MCE_TLB_ERROR_MULTIHIT = 2,
};

enum MCE_UserErrorType {
	MCE_USER_ERROR_INDETERMINATE = 0,
	MCE_USER_ERROR_TLBIE = 1,
	MCE_USER_ERROR_SCV = 2,
};

enum MCE_RaErrorType {
	MCE_RA_ERROR_INDETERMINATE = 0,
	MCE_RA_ERROR_IFETCH = 1,
	MCE_RA_ERROR_IFETCH_FOREIGN = 2,
	MCE_RA_ERROR_PAGE_TABLE_WALK_IFETCH = 3,
	MCE_RA_ERROR_PAGE_TABLE_WALK_IFETCH_FOREIGN = 4,
	MCE_RA_ERROR_LOAD = 5,
	MCE_RA_ERROR_STORE = 6,
	MCE_RA_ERROR_PAGE_TABLE_WALK_LOAD_STORE = 7,
	MCE_RA_ERROR_PAGE_TABLE_WALK_LOAD_STORE_FOREIGN = 8,
	MCE_RA_ERROR_LOAD_STORE_FOREIGN = 9,
};

enum MCE_LinkErrorType {
	MCE_LINK_ERROR_INDETERMINATE = 0,
	MCE_LINK_ERROR_IFETCH_TIMEOUT = 1,
	MCE_LINK_ERROR_PAGE_TABLE_WALK_IFETCH_TIMEOUT = 2,
	MCE_LINK_ERROR_LOAD_TIMEOUT = 3,
	MCE_LINK_ERROR_STORE_TIMEOUT = 4,
	MCE_LINK_ERROR_PAGE_TABLE_WALK_LOAD_STORE_TIMEOUT = 5,
};

struct machine_check_event {
	enum MCE_Version version: 8;
	u8 in_use;
	enum MCE_Severity severity: 8;
	enum MCE_Initiator initiator: 8;
	enum MCE_ErrorType error_type: 8;
	enum MCE_ErrorClass error_class: 8;
	enum MCE_Disposition disposition: 8;
	bool sync_error;
	u16 cpu;
	u64 gpr3;
	u64 srr0;
	u64 srr1;
	union {
		struct {
			enum MCE_UeErrorType ue_error_type: 8;
			u8 effective_address_provided;
			u8 physical_address_provided;
			u8 ignore_event;
			u8 reserved_1[4];
			u64 effective_address;
			u64 physical_address;
			u8 reserved_2[8];
		} ue_error;
		struct {
			enum MCE_SlbErrorType slb_error_type: 8;
			u8 effective_address_provided;
			u8 reserved_1[6];
			u64 effective_address;
			u8 reserved_2[16];
		} slb_error;
		struct {
			enum MCE_EratErrorType erat_error_type: 8;
			u8 effective_address_provided;
			u8 reserved_1[6];
			u64 effective_address;
			u8 reserved_2[16];
		} erat_error;
		struct {
			enum MCE_TlbErrorType tlb_error_type: 8;
			u8 effective_address_provided;
			u8 reserved_1[6];
			u64 effective_address;
			u8 reserved_2[16];
		} tlb_error;
		struct {
			enum MCE_UserErrorType user_error_type: 8;
			u8 effective_address_provided;
			u8 reserved_1[6];
			u64 effective_address;
			u8 reserved_2[16];
		} user_error;
		struct {
			enum MCE_RaErrorType ra_error_type: 8;
			u8 effective_address_provided;
			u8 reserved_1[6];
			u64 effective_address;
			u8 reserved_2[16];
		} ra_error;
		struct {
			enum MCE_LinkErrorType link_error_type: 8;
			u8 effective_address_provided;
			u8 reserved_1[6];
			u64 effective_address;
			u8 reserved_2[16];
		} link_error;
	} u;
};

struct mce_info {
	int mce_nest_count;
	struct machine_check_event mce_event[10];
	int mce_queue_count;
	struct machine_check_event mce_event_queue[10];
	int mce_ue_count;
	struct machine_check_event mce_ue_event_queue[10];
};

struct mmiowb_state {
	u16 nesting_count;
	u16 mmiowb_pending;
};

struct dtl_entry;

struct paca_struct {
	struct lppaca *lppaca_ptr;
	u16 paca_index;
	u16 lock_token;
	u64 kernel_toc;
	u64 kernelbase;
	u64 kernel_msr;
	void *emergency_sp;
	u64 data_offset;
	s16 hw_cpu_id;
	u8 cpu_start;
	u8 kexec_state;
	struct slb_shadow *slb_shadow_ptr;
	struct dtl_entry *dispatch_log;
	struct dtl_entry *dispatch_log_end;
	u64 dscr_default;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	u64 exgen[11];
	u64 exslb[11];
	u16 vmalloc_sllp;
	u16 slb_cache_ptr;
	u32 slb_cache[8];
	mm_context_id_t mm_ctx_id;
	unsigned char mm_ctx_low_slices_psize[8];
	unsigned char mm_ctx_high_slices_psize[2048];
	long unsigned int mm_ctx_slb_addr_limit;
	struct task_struct *__current;
	u64 kstack;
	u64 stab_rr;
	u64 saved_r1;
	u64 saved_msr;
	u16 trap_save;
	u8 irq_soft_mask;
	u8 irq_happened;
	u8 irq_work_pending;
	u8 pmcregs_in_use;
	u64 sprg_vdso;
	u64 tm_scratch;
	long unsigned int idle_state;
	union {
		struct {
			u8 thread_idle_state;
			u8 subcore_sibling_mask;
		};
		struct {
			u64 requested_psscr;
			atomic_t dont_stop;
		};
	};
	u64 exnmi[11];
	u64 exmc[11];
	void *nmi_emergency_sp;
	void *mc_emergency_sp;
	u16 in_nmi;
	u16 in_mce;
	u8 hmi_event_available;
	u8 hmi_p9_special_emu;
	u32 hmi_irqs;
	u8 ftrace_enabled;
	struct cpu_accounting_data accounting;
	u64 dtl_ridx;
	struct dtl_entry *dtl_curr;
	struct kvmppc_host_state kvm_hstate;
	struct sibling_subcore_state *sibling_subcore_state;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	u64 exrfi[11];
	void *rfi_flush_fallback_area;
	u64 l1d_flush_size;
	u8 *mce_data_buf;
	struct slb_entry *mce_faulty_slbs;
	u16 slb_save_cache_ptr;
	struct mmiowb_state mmiowb_state;
	long unsigned int canary;
	struct mce_info *mce_info;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
};

typedef struct cpumask cpumask_var_t[1];

enum irqreturn {
	IRQ_NONE = 0,
	IRQ_HANDLED = 1,
	IRQ_WAKE_THREAD = 2,
};

typedef enum irqreturn irqreturn_t;

struct smp_ops_t {
	void (*message_pass)(int, int);
	void (*cause_ipi)(int);
	int (*cause_nmi_ipi)(int);
	void (*probe)();
	int (*kick_cpu)(int);
	int (*prepare_cpu)(int);
	void (*setup_cpu)(int);
	void (*bringup_done)();
	void (*take_timebase)();
	void (*give_timebase)();
	int (*cpu_disable)();
	void (*cpu_die)(unsigned int);
	int (*cpu_bootable)(unsigned int);
};

typedef struct {
	atomic_long_t raw_lock;
} qrwlock_t;

typedef struct {
	__u8 b[16];
} guid_t;

typedef struct {
	__u8 b[16];
} uuid_t;

typedef long unsigned int kernel_ulong_t;

struct pci_device_id {
	__u32 vendor;
	__u32 device;
	__u32 subvendor;
	__u32 subdevice;
	__u32 class;
	__u32 class_mask;
	kernel_ulong_t driver_data;
};

struct acpi_device_id {
	__u8 id[9];
	kernel_ulong_t driver_data;
	__u32 cls;
	__u32 cls_msk;
};

struct of_device_id {
	char name[32];
	char type[32];
	char compatible[128];
	const void *data;
};

struct resource {
	resource_size_t start;
	resource_size_t end;
	const char *name;
	long unsigned int flags;
	long unsigned int desc;
	struct resource *parent;
	struct resource *sibling;
	struct resource *child;
	long unsigned int rh_reserved1;
	long unsigned int rh_reserved2;
	long unsigned int rh_reserved3;
	long unsigned int rh_reserved4;
};

enum pcpu_fc {
	PCPU_FC_AUTO = 0,
	PCPU_FC_EMBED = 1,
	PCPU_FC_PAGE = 2,
	PCPU_FC_NR = 3,
};

struct wait_queue_head {
	spinlock_t lock;
	struct list_head head;
};

typedef struct wait_queue_head wait_queue_head_t;

struct seqcount_raw_spinlock {
	seqcount_t seqcount;
};

typedef struct seqcount_raw_spinlock seqcount_raw_spinlock_t;

typedef struct {
	union {
		seqcount_spinlock_t seqcount;
		struct {
			struct seqcount seqcount;
		} rh_kabi_hidden_808;
		union {		};
	};
	spinlock_t lock;
} seqlock_t;

struct userfaultfd_ctx;

struct vm_userfaultfd_ctx {
	struct userfaultfd_ctx *ctx;
};

struct anon_vma;

struct vm_operations_struct;

struct vm_area_struct {
	long unsigned int vm_start;
	long unsigned int vm_end;
	struct vm_area_struct *vm_next;
	struct vm_area_struct *vm_prev;
	struct rb_node vm_rb;
	long unsigned int rb_subtree_gap;
	struct mm_struct *vm_mm;
	pgprot_t vm_page_prot;
	long unsigned int vm_flags;
	struct {
		struct rb_node rb;
		long unsigned int rb_subtree_last;
	} shared;
	struct list_head anon_vma_chain;
	struct anon_vma *anon_vma;
	const struct vm_operations_struct *vm_ops;
	long unsigned int vm_pgoff;
	struct file *vm_file;
	void *vm_private_data;
	atomic_long_t swap_readahead_info;
	struct mempolicy *vm_policy;
	struct vm_userfaultfd_ctx vm_userfaultfd_ctx;
	long unsigned int rh_reserved1;
	long unsigned int rh_reserved2;
	long unsigned int rh_reserved3;
	long unsigned int rh_reserved4;
};

struct mm_rss_stat {
	atomic_long_t count[4];
};

struct rw_semaphore {
	atomic_long_t count;
	struct list_head wait_list;
	raw_spinlock_t wait_lock;
	struct optimistic_spin_queue osq;
	union {
		atomic_long_t owner;
		struct {
			struct task_struct *owner;
		} rh_kabi_hidden_53;
		union {		};
	};
};

struct swait_queue_head {
	raw_spinlock_t lock;
	struct list_head task_list;
};

struct completion {
	unsigned int done;
	union {
		struct swait_queue_head wait;
		struct {
			wait_queue_head_t wait;
		} rh_kabi_hidden_28;
		union {		};
	};
};

struct mmu_notifier_mm;

struct xol_area;

struct uprobes_state {
	struct xol_area *xol_area;
};

struct work_struct;

typedef void (*work_func_t)(struct work_struct *);

struct work_struct {
	atomic_long_t data;
	struct list_head entry;
	work_func_t func;
	union {
		void *bdi_wb_backptr;
		struct {
			long unsigned int rh_reserved1;
		} rh_kabi_hidden_111;
		union {		};
	};
	long unsigned int rh_reserved2;
	long unsigned int rh_reserved3;
	long unsigned int rh_reserved4;
};

struct linux_binfmt;

struct core_state;

struct kioctx_table;

struct user_namespace;

struct mmu_notifier_subscriptions;

struct mm_struct_rh;

struct mm_struct {
	struct {
		struct vm_area_struct *mmap;
		struct rb_root mm_rb;
		u64 vmacache_seqnum;
		long unsigned int (*get_unmapped_area)(struct file *, long unsigned int, long unsigned int, long unsigned int, long unsigned int);
		long unsigned int mmap_base;
		long unsigned int mmap_legacy_base;
		long unsigned int task_size;
		long unsigned int highest_vm_end;
		pgd_t *pgd;
		atomic_t mm_users;
		atomic_t mm_count;
		atomic_long_t pgtables_bytes;
		int map_count;
		spinlock_t page_table_lock;
		union {
			union {
				struct rw_semaphore mmap_sem;
				struct rw_semaphore mmap_lock;
			};
			struct {
				struct rw_semaphore mmap_sem;
			} rh_kabi_hidden_453;
			union {			};
		};
		struct list_head mmlist;
		long unsigned int hiwater_rss;
		long unsigned int hiwater_vm;
		long unsigned int total_vm;
		long unsigned int locked_vm;
		atomic64_t pinned_vm;
		long unsigned int data_vm;
		long unsigned int exec_vm;
		long unsigned int stack_vm;
		long unsigned int def_flags;
		spinlock_t arg_lock;
		long unsigned int start_code;
		long unsigned int end_code;
		long unsigned int start_data;
		long unsigned int end_data;
		long unsigned int start_brk;
		long unsigned int brk;
		long unsigned int start_stack;
		long unsigned int arg_start;
		long unsigned int arg_end;
		long unsigned int env_start;
		long unsigned int env_end;
		long unsigned int rh_reserved_saved_auxv[70];
		struct mm_rss_stat rss_stat;
		struct linux_binfmt *binfmt;
		mm_context_t context;
		long unsigned int flags;
		struct core_state *core_state;
		atomic_t membarrier_state;
		spinlock_t ioctx_lock;
		struct kioctx_table *ioctx_table;
		struct task_struct *owner;
		struct user_namespace *user_ns;
		struct file *exe_file;
		union {
			struct mmu_notifier_subscriptions *notifier_subscriptions;
			struct {
				struct mmu_notifier_mm *mmu_notifier_mm;
			} rh_kabi_hidden_536;
			union {			};
		};
		long unsigned int numa_next_scan;
		long unsigned int numa_scan_offset;
		int numa_scan_seq;
		atomic_t tlb_flush_pending;
		struct uprobes_state uprobes_state;
		atomic_long_t hugetlb_usage;
		struct work_struct async_put_work;
	};
	long unsigned int rh_reserved1;
	long unsigned int rh_reserved2;
	union {
		seqcount_t write_protect_seq;
		struct {
			long unsigned int rh_reserved3;
		} rh_kabi_hidden_588;
		union {		};
	};
	union {
		struct mm_struct_rh *mm_rh;
		struct {
			long unsigned int rh_reserved4;
		} rh_kabi_hidden_589;
		union {		};
	};
	long unsigned int rh_reserved5;
	long unsigned int rh_reserved6;
	long unsigned int rh_reserved7;
	union {
		atomic_t vas_windows;
		struct {
			long unsigned int rh_reserved8;
		} rh_kabi_hidden_604;
		union {		};
	};
	long unsigned int cpu_bitmap[0];
};

struct timer_list {
	struct hlist_node entry;
	long unsigned int expires;
	void (*function)(struct timer_list *);
	u32 flags;
	long unsigned int rh_reserved1;
	long unsigned int rh_reserved2;
	long unsigned int rh_reserved3;
	long unsigned int rh_reserved4;
};

typedef int (*notifier_fn_t)(struct notifier_block *, long unsigned int, void *);

struct notifier_block {
	notifier_fn_t notifier_call;
	struct notifier_block *next;
	int priority;
};

struct blocking_notifier_head {
	struct rw_semaphore rwsem;
	struct notifier_block *head;
};

struct arch_uprobe_task {
	long unsigned int saved_trap_nr;
};

enum uprobe_task_state {
	UTASK_RUNNING = 0,
	UTASK_SSTEP = 1,
	UTASK_SSTEP_ACK = 2,
	UTASK_SSTEP_TRAPPED = 3,
};

struct uprobe;

struct return_instance;

struct uprobe_task {
	enum uprobe_task_state state;
	union {
		struct {
			struct arch_uprobe_task autask;
			long unsigned int vaddr;
		};
		struct {
			struct callback_head dup_xol_work;
			long unsigned int dup_xol_addr;
		};
	};
	struct uprobe *active_uprobe;
	long unsigned int xol_vaddr;
	struct return_instance *return_instances;
	unsigned int depth;
};

struct return_instance {
	struct uprobe *uprobe;
	long unsigned int func;
	long unsigned int stack;
	long unsigned int orig_ret_vaddr;
	bool chained;
	struct return_instance *next;
};

struct xarray_rh {};

struct xarray {
	spinlock_t xa_lock;
	gfp_t xa_flags;
	void *xa_head;
	size_t xarray_size_rh;
	struct xarray_rh _rh;
};

typedef u32 errseq_t;

struct address_space_operations;

struct address_space {
	struct inode *host;
	struct xarray i_pages;
	atomic_t i_mmap_writable;
	struct rb_root_cached i_mmap;
	struct rw_semaphore i_mmap_rwsem;
	long unsigned int nrpages;
	long unsigned int nrexceptional;
	long unsigned int writeback_index;
	const struct address_space_operations *a_ops;
	long unsigned int flags;
	spinlock_t private_lock;
	gfp_t gfp_mask;
	struct list_head private_list;
	void *private_data;
	errseq_t wb_err;
	long unsigned int rh_reserved1;
	long unsigned int rh_reserved2;
	long unsigned int rh_reserved3;
	long unsigned int rh_reserved4;
};

typedef int (*dev_page_fault_t)(struct vm_area_struct *, long unsigned int, const struct page *, unsigned int, pmd_t *);

typedef void (*dev_page_free_t)(struct page *, void *);

struct vmem_altmap {
	const long unsigned int base_pfn;
	const long unsigned int reserve;
	long unsigned int free;
	long unsigned int align;
	long unsigned int alloc;
	const long unsigned int end_pfn;
};

enum memory_type {
	MEMORY_DEVICE_PRIVATE = 1,
	MEMORY_DEVICE_PUBLIC = 2,
	MEMORY_DEVICE_FS_DAX = 3,
	MEMORY_DEVICE_PCI_P2PDMA = 4,
	MEMORY_DEVICE_GENERIC = 5,
};

struct percpu_ref;

typedef void percpu_ref_func_t(struct percpu_ref *);

struct percpu_ref {
	atomic_long_t count;
	long unsigned int percpu_count_ptr;
	percpu_ref_func_t *release;
	percpu_ref_func_t *confirm_switch;
	bool force_atomic: 1;
	bool allow_reinit: 1;
	struct callback_head rcu;
};

struct range {
	u64 start;
	u64 end;
};

struct device;

struct dev_pagemap_ops;

struct dev_pagemap {
	dev_page_fault_t rh_reserved_page_fault;
	dev_page_free_t rh_reserved_page_free;
	struct vmem_altmap altmap;
	bool rh_reserved_altmap_valid;
	struct resource rh_reserved_res;
	struct percpu_ref *ref;
	struct device *rh_reserved_dev;
	void *rh_reserved_data;
	enum memory_type type;
	u64 rh_reserved_pci_p2pdma_bus_offset;
	const struct dev_pagemap_ops *ops;
	unsigned int flags;
	struct percpu_ref internal_ref;
	struct completion done;
	void *owner;
	int nr_range;
	long unsigned int vmemmap_shift;
	union {
		struct range range;
		struct range ranges[0];
	};
};

struct vfsmount;

struct path {
	struct vfsmount *mnt;
	struct dentry *dentry;
};

enum rw_hint {
	WRITE_LIFE_NOT_SET = 0,
	WRITE_LIFE_NONE = 1,
	WRITE_LIFE_SHORT = 2,
	WRITE_LIFE_MEDIUM = 3,
	WRITE_LIFE_LONG = 4,
	WRITE_LIFE_EXTREME = 5,
};

enum pid_type {
	PIDTYPE_PID = 0,
	PIDTYPE_PGID = 1,
	PIDTYPE_SID = 2,
	PIDTYPE_TGID = 3,
	PIDTYPE_MAX = 4,
};

struct fown_struct {
	rwlock_t lock;
	struct pid *pid;
	enum pid_type pid_type;
	kuid_t uid;
	kuid_t euid;
	int signum;
};

struct file_ra_state {
	long unsigned int start;
	unsigned int size;
	unsigned int async_size;
	unsigned int ra_pages;
	unsigned int mmap_miss;
	loff_t prev_pos;
};

struct file {
	union {
		struct llist_node fu_llist;
		struct callback_head fu_rcuhead;
	} f_u;
	struct path f_path;
	struct inode *f_inode;
	const struct file_operations *f_op;
	spinlock_t f_lock;
	enum rw_hint f_write_hint;
	atomic_long_t f_count;
	unsigned int f_flags;
	fmode_t f_mode;
	struct mutex f_pos_lock;
	loff_t f_pos;
	struct fown_struct f_owner;
	const struct cred *f_cred;
	struct file_ra_state f_ra;
	u64 f_version;
	void *f_security;
	void *private_data;
	struct list_head f_ep_links;
	struct list_head f_tfile_llink;
	struct address_space *f_mapping;
	errseq_t f_wb_err;
};

typedef unsigned int vm_fault_t;

enum page_entry_size {
	PE_SIZE_PTE = 0,
	PE_SIZE_PMD = 1,
	PE_SIZE_PUD = 2,
};

struct vm_fault;

struct vm_operations_struct {
	void (*open)(struct vm_area_struct *);
	void (*close)(struct vm_area_struct *);
	int (*split)(struct vm_area_struct *, long unsigned int);
	int (*mremap)(struct vm_area_struct *);
	vm_fault_t (*fault)(struct vm_fault *);
	vm_fault_t (*huge_fault)(struct vm_fault *, enum page_entry_size);
	void (*map_pages)(struct vm_fault *, long unsigned int, long unsigned int);
	long unsigned int (*pagesize)(struct vm_area_struct *);
	vm_fault_t (*page_mkwrite)(struct vm_fault *);
	vm_fault_t (*pfn_mkwrite)(struct vm_fault *);
	int (*access)(struct vm_area_struct *, long unsigned int, void *, int, int);
	const char * (*name)(struct vm_area_struct *);
	int (*set_policy)(struct vm_area_struct *, struct mempolicy *);
	struct mempolicy * (*get_policy)(struct vm_area_struct *, long unsigned int);
	struct page * (*find_special_page)(struct vm_area_struct *, long unsigned int);
	union {
		int (*mprotect)(struct vm_area_struct *, long unsigned int, long unsigned int, long unsigned int);
		struct {
			long unsigned int rh_reserved1;
		} rh_kabi_hidden_573;
		union {		};
	};
	long unsigned int rh_reserved2;
	long unsigned int rh_reserved3;
	long unsigned int rh_reserved4;
};

struct core_thread {
	struct task_struct *task;
	struct core_thread *next;
};

struct core_state {
	atomic_t nr_threads;
	struct core_thread dumper;
	struct completion startup;
};

struct mm_struct_rh {
	long unsigned int saved_auxv[70];
};

struct vm_fault {
	struct vm_area_struct *vma;
	unsigned int flags;
	gfp_t gfp_mask;
	long unsigned int pgoff;
	long unsigned int address;
	pmd_t *pmd;
	pud_t *pud;
	pte_t orig_pte;
	struct page *cow_page;
	struct mem_cgroup *rh_reserved_memcg;
	struct page *page;
	pte_t *pte;
	spinlock_t *ptl;
	pgtable_t prealloc_pte;
};

struct free_area {
	struct list_head free_list[6];
	long unsigned int nr_free;
};

struct zone_padding {
	char x[0];
};

enum numa_stat_item {
	NUMA_HIT = 0,
	NUMA_MISS = 1,
	NUMA_FOREIGN = 2,
	NUMA_INTERLEAVE_HIT = 3,
	NUMA_LOCAL = 4,
	NUMA_OTHER = 5,
	NR_VM_NUMA_STAT_ITEMS = 6,
};

enum zone_stat_item {
	NR_FREE_PAGES = 0,
	NR_ZONE_LRU_BASE = 1,
	NR_ZONE_INACTIVE_ANON = 1,
	NR_ZONE_ACTIVE_ANON = 2,
	NR_ZONE_INACTIVE_FILE = 3,
	NR_ZONE_ACTIVE_FILE = 4,
	NR_ZONE_UNEVICTABLE = 5,
	NR_ZONE_WRITE_PENDING = 6,
	NR_MLOCK = 7,
	NR_BOUNCE = 8,
	NR_ZSPAGES = 9,
	NR_FREE_CMA_PAGES = 10,
	NR_VM_ZONE_STAT_ITEMS = 11,
};

enum node_stat_item {
	NR_LRU_BASE = 0,
	NR_INACTIVE_ANON = 0,
	NR_ACTIVE_ANON = 1,
	NR_INACTIVE_FILE = 2,
	NR_ACTIVE_FILE = 3,
	NR_UNEVICTABLE = 4,
	NR_SLAB_RECLAIMABLE_B = 5,
	NR_SLAB_UNRECLAIMABLE_B = 6,
	NR_ISOLATED_ANON = 7,
	NR_ISOLATED_FILE = 8,
	WORKINGSET_NODES = 9,
	WORKINGSET_REFAULT_BASE = 10,
	WORKINGSET_REFAULT_ANON = 10,
	WORKINGSET_REFAULT_FILE = 11,
	WORKINGSET_ACTIVATE_BASE = 12,
	WORKINGSET_ACTIVATE_ANON = 12,
	WORKINGSET_ACTIVATE_FILE = 13,
	WORKINGSET_RESTORE_BASE = 14,
	WORKINGSET_RESTORE_ANON = 14,
	WORKINGSET_RESTORE_FILE = 15,
	WORKINGSET_NODERECLAIM = 16,
	NR_ANON_MAPPED = 17,
	NR_FILE_MAPPED = 18,
	NR_FILE_PAGES = 19,
	NR_FILE_DIRTY = 20,
	NR_WRITEBACK = 21,
	NR_WRITEBACK_TEMP = 22,
	NR_SHMEM = 23,
	NR_SHMEM_THPS = 24,
	NR_SHMEM_PMDMAPPED = 25,
	NR_FILE_THPS = 26,
	NR_FILE_PMDMAPPED = 27,
	NR_ANON_THPS = 28,
	NR_VMSCAN_WRITE = 29,
	NR_VMSCAN_IMMEDIATE = 30,
	NR_DIRTIED = 31,
	NR_WRITTEN = 32,
	NR_THROTTLED_WRITTEN = 33,
	NR_KERNEL_MISC_RECLAIMABLE = 34,
	NR_FOLL_PIN_ACQUIRED = 35,
	NR_FOLL_PIN_RELEASED = 36,
	NR_KERNEL_STACK_KB = 37,
	NR_PAGETABLE = 38,
	NR_SWAPCACHE = 39,
	NR_VM_NODE_STAT_ITEMS = 40,
};

struct zone_reclaim_stat {
	long unsigned int recent_rotated[2];
	long unsigned int recent_scanned[2];
};

struct pglist_data;

struct lruvec {
	struct list_head lists[5];
	union {
		struct {
			long unsigned int anon_cost;
			long unsigned int file_cost;
			long unsigned int refaults[2];
		};
		struct {
			struct zone_reclaim_stat reclaim_stat;
		} rh_kabi_hidden_339;
		union {		};
	};
	atomic_long_t nonresident_age;
	union {
		long unsigned int flags;
		struct {
			long unsigned int refaults;
		} rh_kabi_hidden_346;
		union {		};
	};
	struct pglist_data *pgdat;
	spinlock_t lru_lock;
};

struct per_cpu_pageset;

struct zone {
	long unsigned int _watermark[3];
	long unsigned int nr_reserved_highatomic;
	long int lowmem_reserve[5];
	int node;
	struct pglist_data *zone_pgdat;
	struct per_cpu_pageset *pageset;
	long unsigned int zone_start_pfn;
	union {
		atomic_long_t managed_pages;
		struct {
			long unsigned int managed_pages;
		} rh_kabi_hidden_576;
		union {		};
	};
	long unsigned int spanned_pages;
	long unsigned int present_pages;
	const char *name;
	long unsigned int nr_isolate_pageblock;
	seqlock_t span_seqlock;
	int initialized;
	long unsigned int watermark_boost;
	int pageset_high;
	int pageset_batch;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	struct zone_padding _pad1_;
	struct free_area free_area[9];
	long unsigned int flags;
	spinlock_t lock;
	long: 32;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	struct zone_padding _pad2_;
	long unsigned int percpu_drift_mark;
	long unsigned int compact_cached_free_pfn;
	long unsigned int compact_cached_migrate_pfn[2];
	unsigned int compact_considered;
	unsigned int compact_defer_shift;
	int compact_order_failed;
	bool compact_blockskip_flush;
	bool contiguous;
	long: 16;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	struct zone_padding _pad3_;
	union {
		long unsigned int compact_init_migrate_pfn;
		struct {
			long unsigned int rh_reserved1;
		} rh_kabi_hidden_666;
		union {		};
	};
	union {
		long unsigned int compact_init_free_pfn;
		struct {
			long unsigned int rh_reserved2;
		} rh_kabi_hidden_667;
		union {		};
	};
	atomic_long_t vm_stat[11];
	atomic_long_t vm_numa_stat[6];
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
};

struct zoneref {
	struct zone *zone;
	int zone_idx;
};

struct zonelist {
	struct zoneref _zonerefs[1281];
};

enum zone_type {
	ZONE_DMA = 0,
	ZONE_DMA32 = 1,
	ZONE_NORMAL = 2,
	ZONE_MOVABLE = 3,
	ZONE_DEVICE = 4,
	__MAX_NR_ZONES = 5,
};

struct deferred_split {
	spinlock_t split_queue_lock;
	struct list_head split_queue;
	long unsigned int split_queue_len;
};

struct per_cpu_nodestat;

struct pglist_data {
	struct zone node_zones[5];
	struct zonelist node_zonelists[2];
	int nr_zones;
	spinlock_t node_size_lock;
	long unsigned int node_start_pfn;
	long unsigned int node_present_pages;
	long unsigned int node_spanned_pages;
	int node_id;
	wait_queue_head_t kswapd_wait;
	wait_queue_head_t pfmemalloc_wait;
	struct task_struct *kswapd;
	int kswapd_order;
	enum zone_type kswapd_highest_zoneidx;
	int kswapd_failures;
	int kcompactd_max_order;
	enum zone_type kcompactd_highest_zoneidx;
	wait_queue_head_t kcompactd_wait;
	struct task_struct *kcompactd;
	spinlock_t rh_reserved_numabalancing_migrate_lock;
	long unsigned int rh_reserved_numabalancing_migrate_next_window;
	long unsigned int rh_reserved_numabalancing_migrate_nr_pages;
	long unsigned int totalreserve_pages;
	long unsigned int min_unmapped_pages;
	long unsigned int min_slab_pages;
	long: 64;
	long: 64;
	long: 64;
	struct zone_padding _pad1_;
	spinlock_t rh_reserved_lru_lock;
	struct deferred_split deferred_split_queue;
	struct lruvec __lruvec;
	long unsigned int flags;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	struct zone_padding _pad2_;
	union {
		atomic_t nr_writeback_throttled;
		struct {
			long unsigned int rh_reserved1;
		} rh_kabi_hidden_920;
		union {		};
	};
	union {
		long unsigned int nr_reclaim_start;
		struct {
			long unsigned int rh_reserved2;
		} rh_kabi_hidden_921;
		union {		};
	};
	wait_queue_head_t reclaim_wait[4];
	struct per_cpu_nodestat *per_cpu_nodestats;
	atomic_long_t vm_stat[40];
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
};

typedef unsigned int isolate_mode_t;

struct per_cpu_pages {
	int count;
	int high;
	int batch;
	struct list_head lists[3];
};

struct per_cpu_pageset {
	struct per_cpu_pages pcp;
	s8 expire;
	u16 vm_numa_stat_diff[6];
	s8 stat_threshold;
	s8 vm_stat_diff[11];
};

struct per_cpu_nodestat {
	s8 stat_threshold;
	s8 vm_node_stat_diff[40];
};

typedef struct pglist_data pg_data_t;

struct mem_section_usage {
	struct callback_head rcu;
	long unsigned int subsection_map[1];
	long unsigned int pageblock_flags[0];
};

struct page_ext;

struct mem_section {
	long unsigned int section_mem_map;
	union {
		struct mem_section_usage *usage;
		struct {
			long unsigned int *pageblock_flags;
		} rh_kabi_hidden_1380;
		union {		};
	};
	struct page_ext *page_ext;
	long unsigned int pad;
};

struct page_ext {
	long unsigned int flags;
};

struct xa_node {
	unsigned char shift;
	unsigned char offset;
	unsigned char count;
	unsigned char nr_values;
	struct xa_node *parent;
	struct xarray *array;
	union {
		struct list_head private_list;
		struct callback_head callback_head;
	};
	void *slots[64];
	union {
		long unsigned int tags[3];
		long unsigned int marks[3];
	};
};

typedef struct {} local_lock_t;

struct radix_tree_preload {
	local_lock_t lock;
	unsigned int nr;
	struct xa_node *nodes;
};

struct idr {
	struct xarray idr_rt;
	unsigned int idr_base;
	unsigned int idr_next;
};

typedef struct {
	gid_t val;
} kgid_t;

struct kernfs_root;

struct kernfs_elem_dir {
	long unsigned int subdirs;
	struct rb_root children;
	struct kernfs_root *root;
	long unsigned int rev;
};

struct kernfs_node;

struct kernfs_syscall_ops;

struct kernfs_root {
	struct kernfs_node *kn;
	unsigned int flags;
	struct idr ino_idr;
	u32 id_highbits;
	u32 last_id_lowbits;
	struct kernfs_syscall_ops *syscall_ops;
	struct list_head supers;
	wait_queue_head_t deactivate_waitq;
	struct rw_semaphore kernfs_rwsem;
	struct rw_semaphore kernfs_iattr_rwsem;
	struct rw_semaphore kernfs_supers_rwsem;
};

struct kernfs_elem_symlink {
	struct kernfs_node *target_kn;
};

struct kernfs_ops;

struct kernfs_open_node;

struct kernfs_elem_attr {
	const struct kernfs_ops *ops;
	struct kernfs_open_node *open;
	loff_t size;
	struct kernfs_node *notify_next;
};

union kernfs_node_id {
	struct {
		u32 ino;
		u32 generation;
	};
	u64 id;
};

struct kernfs_iattrs;

struct kernfs_node {
	atomic_t count;
	atomic_t active;
	struct kernfs_node *parent;
	const char *name;
	struct rb_node rb;
	const void *ns;
	unsigned int hash;
	union {
		struct kernfs_elem_dir dir;
		struct kernfs_elem_symlink symlink;
		struct kernfs_elem_attr attr;
	};
	void *priv;
	union {
		u64 id;
		struct {
			union kernfs_node_id id;
		} rh_kabi_hidden_173;
		union {		};
	};
	short unsigned int flags;
	umode_t mode;
	struct kernfs_iattrs *iattr;
};

struct kernfs_open_file;

struct kernfs_ops {
	int (*open)(struct kernfs_open_file *);
	void (*release)(struct kernfs_open_file *);
	int (*seq_show)(struct seq_file *, void *);
	void * (*seq_start)(struct seq_file *, loff_t *);
	void * (*seq_next)(struct seq_file *, void *, loff_t *);
	void (*seq_stop)(struct seq_file *, void *);
	ssize_t (*read)(struct kernfs_open_file *, char *, size_t, loff_t);
	size_t atomic_write_len;
	bool prealloc;
	ssize_t (*write)(struct kernfs_open_file *, char *, size_t, loff_t);
	int (*mmap)(struct kernfs_open_file *, struct vm_area_struct *);
	union {
		__poll_t (*poll)(struct kernfs_open_file *, struct poll_table_struct *);
		struct {
			long unsigned int rh_reserved1;
		} rh_kabi_hidden_299;
		union {		};
	};
	long unsigned int rh_reserved2;
};

struct kernfs_syscall_ops {
	int (*rh_reserved_remount_fs)(struct kernfs_root *, int *, char *);
	int (*show_options)(struct seq_file *, struct kernfs_root *);
	int (*mkdir)(struct kernfs_node *, const char *, umode_t);
	int (*rmdir)(struct kernfs_node *);
	int (*rename)(struct kernfs_node *, struct kernfs_node *, const char *);
	int (*show_path)(struct seq_file *, struct kernfs_node *, struct kernfs_root *);
	long unsigned int rh_reserved1;
	long unsigned int rh_reserved2;
	long unsigned int rh_reserved3;
	long unsigned int rh_reserved4;
};

struct seq_operations;

struct seq_file {
	char *buf;
	size_t size;
	size_t from;
	size_t count;
	size_t pad_until;
	loff_t index;
	loff_t read_pos;
	u64 version;
	struct mutex lock;
	const struct seq_operations *op;
	int poll_event;
	const struct file *file;
	void *private;
};

struct kernfs_open_file {
	struct kernfs_node *kn;
	struct file *file;
	struct seq_file *seq_file;
	void *priv;
	struct mutex mutex;
	struct mutex prealloc_mutex;
	int event;
	struct list_head list;
	char *prealloc_buf;
	size_t atomic_write_len;
	bool mmapped: 1;
	bool released: 1;
	const struct vm_operations_struct *vm_ops;
};

enum kobj_ns_type {
	KOBJ_NS_TYPE_NONE = 0,
	KOBJ_NS_TYPE_NET = 1,
	KOBJ_NS_TYPES = 2,
};

struct sock;

struct kobj_ns_type_operations {
	enum kobj_ns_type type;
	bool (*current_may_mount)();
	void * (*grab_current_ns)();
	const void * (*netlink_ns)(struct sock *);
	const void * (*initial_ns)();
	void (*drop_ns)(void *);
};

struct kstat {
	u32 result_mask;
	umode_t mode;
	unsigned int nlink;
	uint32_t blksize;
	u64 attributes;
	u64 attributes_mask;
	u64 ino;
	dev_t dev;
	dev_t rdev;
	kuid_t uid;
	kgid_t gid;
	loff_t size;
	struct timespec64 atime;
	struct timespec64 mtime;
	struct timespec64 ctime;
	struct timespec64 btime;
	u64 blocks;
};

struct attribute {
	const char *name;
	umode_t mode;
};

struct kobject;

struct bin_attribute;

struct attribute_group {
	const char *name;
	umode_t (*is_visible)(struct kobject *, struct attribute *, int);
	umode_t (*is_bin_visible)(struct kobject *, struct bin_attribute *, int);
	struct attribute **attrs;
	struct bin_attribute **bin_attrs;
};

struct kref {
	refcount_t refcount;
};

struct kset;

struct kobj_type;

struct kobject {
	const char *name;
	struct list_head entry;
	struct kobject *parent;
	struct kset *kset;
	const struct kobj_type *ktype;
	struct kernfs_node *sd;
	struct kref kref;
	unsigned int state_initialized: 1;
	unsigned int state_in_sysfs: 1;
	unsigned int state_add_uevent_sent: 1;
	unsigned int state_remove_uevent_sent: 1;
	unsigned int uevent_suppress: 1;
	long unsigned int rh_reserved1;
	long unsigned int rh_reserved2;
	long unsigned int rh_reserved3;
	long unsigned int rh_reserved4;
};

struct bin_attribute {
	struct attribute attr;
	size_t size;
	void *private;
	ssize_t (*read)(struct file *, struct kobject *, struct bin_attribute *, char *, loff_t, size_t);
	ssize_t (*write)(struct file *, struct kobject *, struct bin_attribute *, char *, loff_t, size_t);
	int (*mmap)(struct file *, struct kobject *, struct bin_attribute *, struct vm_area_struct *);
};

struct sysfs_ops {
	ssize_t (*show)(struct kobject *, struct attribute *, char *);
	ssize_t (*store)(struct kobject *, struct attribute *, const char *, size_t);
};

struct kset_uevent_ops;

struct kset {
	struct list_head list;
	spinlock_t list_lock;
	struct kobject kobj;
	const struct kset_uevent_ops *uevent_ops;
	long unsigned int rh_reserved1;
	long unsigned int rh_reserved2;
	long unsigned int rh_reserved3;
	long unsigned int rh_reserved4;
};

struct kobj_type {
	void (*release)(struct kobject *);
	const struct sysfs_ops *sysfs_ops;
	struct attribute **default_attrs;
	const struct kobj_ns_type_operations * (*child_ns_type)(const struct kobject *);
	const void * (*namespace)(const struct kobject *);
	union {
		const struct attribute_group **default_groups;
		struct {
			long unsigned int rh_reserved1;
		} rh_kabi_hidden_133;
		union {		};
	};
	union {
		void (*get_ownership)(const struct kobject *, kuid_t *, kgid_t *);
		struct {
			long unsigned int rh_reserved2;
		} rh_kabi_hidden_134;
		union {		};
	};
	long unsigned int rh_reserved3;
	long unsigned int rh_reserved4;
};

struct kobj_uevent_env {
	char *argv[3];
	char *envp[32];
	int envp_idx;
	char buf[2048];
	int buflen;
};

struct kset_uevent_ops {
	int (* const filter)(struct kset *, const struct kobject *);
	const char * (* const name)(struct kset *, const struct kobject *);
	int (* const uevent)(struct kset *, struct kobject *, struct kobj_uevent_env *);
};

struct kobj_attribute {
	struct attribute attr;
	ssize_t (*show)(struct kobject *, struct kobj_attribute *, char *);
	ssize_t (*store)(struct kobject *, struct kobj_attribute *, const char *, size_t);
};

struct pid_namespace;

struct upid {
	int nr;
	struct pid_namespace *ns;
};

struct pid {
	atomic_t count;
	unsigned int level;
	struct hlist_head tasks[4];
	struct callback_head rcu;
	struct upid numbers[1];
};

struct timerqueue_head {
	union {
		struct rb_root_cached rb_root;
		struct {
			struct rb_root head;
			struct timerqueue_node *next;
		} rh_kabi_hidden_17;
		union {		};
	};
};

struct hrtimer_rh {};

struct hrtimer_cpu_base;

struct hrtimer_clock_base {
	struct hrtimer_cpu_base *cpu_base;
	unsigned int index;
	clockid_t clockid;
	union {
		seqcount_raw_spinlock_t seq;
		struct {
			seqcount_t seq;
		} rh_kabi_hidden_180;
		union {		};
	};
	struct hrtimer *running;
	struct timerqueue_head active;
	ktime_t (*get_time)();
	ktime_t offset;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
};

struct hrtimer_cpu_base {
	raw_spinlock_t lock;
	unsigned int cpu;
	unsigned int active_bases;
	unsigned int clock_was_set_seq;
	unsigned int hres_active: 1;
	unsigned int in_hrtirq: 1;
	unsigned int hang_detected: 1;
	unsigned int softirq_activated: 1;
	unsigned int nr_events;
	short unsigned int nr_retries;
	short unsigned int nr_hangs;
	unsigned int max_hang_time;
	ktime_t expires_next;
	struct hrtimer *next_timer;
	ktime_t softirq_expires_next;
	struct hrtimer *softirq_next_timer;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	struct hrtimer_clock_base clock_base[8];
};

struct tick_device;

struct rlimit {
	__kernel_ulong_t rlim_cur;
	__kernel_ulong_t rlim_max;
};

typedef void __signalfn_t(int);

typedef __signalfn_t *__sighandler_t;

typedef void __restorefn_t();

typedef __restorefn_t *__sigrestore_t;

union sigval {
	int sival_int;
	void *sival_ptr;
};

typedef union sigval sigval_t;

union __sifields {
	struct {
		__kernel_pid_t _pid;
		__kernel_uid32_t _uid;
	} _kill;
	struct {
		__kernel_timer_t _tid;
		int _overrun;
		sigval_t _sigval;
		int _sys_private;
	} _timer;
	struct {
		__kernel_pid_t _pid;
		__kernel_uid32_t _uid;
		sigval_t _sigval;
	} _rt;
	struct {
		__kernel_pid_t _pid;
		__kernel_uid32_t _uid;
		int _status;
		__kernel_clock_t _utime;
		__kernel_clock_t _stime;
	} _sigchld;
	struct {
		void *_addr;
		union {
			short int _addr_lsb;
			struct {
				char _dummy_bnd[8];
				void *_lower;
				void *_upper;
			} _addr_bnd;
			struct {
				char _dummy_pkey[8];
				__u32 _pkey;
			} _addr_pkey;
		};
	} _sigfault;
	struct {
		long int _band;
		int _fd;
	} _sigpoll;
	struct {
		void *_call_addr;
		int _syscall;
		unsigned int _arch;
	} _sigsys;
};

struct siginfo {
	union {
		struct {
			int si_signo;
			int si_errno;
			int si_code;
			union __sifields _sifields;
		};
		int _si_pad[32];
	};
};

struct kernel_siginfo {
	struct {
		int si_signo;
		int si_errno;
		int si_code;
		union __sifields _sifields;
	};
};

struct key;

struct user_struct {
	union {
		refcount_t __count;
		struct {
			atomic_t __count;
		} rh_kabi_hidden_18;
		union {		};
	};
	atomic_t processes;
	atomic_t sigpending;
	atomic_t fanotify_listeners;
	atomic_long_t epoll_watches;
	long unsigned int mq_bytes;
	long unsigned int locked_shm;
	long unsigned int unix_inflight;
	atomic_long_t pipe_bufs;
	struct key *uid_keyring;
	struct key *session_keyring;
	struct hlist_node uidhash_node;
	kuid_t uid;
	atomic_long_t locked_vm;
	struct ratelimit_state ratelimit;
	long unsigned int rh_reserved1;
	long unsigned int rh_reserved2;
};

struct sigaction {
	__sighandler_t sa_handler;
	long unsigned int sa_flags;
	__sigrestore_t sa_restorer;
	sigset_t sa_mask;
};

struct k_sigaction {
	struct sigaction sa;
};

struct posix_cputimer_base {
	u64 nextevt;
	struct timerqueue_head tqhead;
};

struct posix_cputimers {
	struct posix_cputimer_base bases[3];
	unsigned int timers_active;
	unsigned int expiry_active;
};

struct cpu_itimer {
	u64 expires;
	u64 incr;
};

struct task_cputime_atomic {
	atomic64_t utime;
	atomic64_t stime;
	atomic64_t sum_exec_runtime;
};

struct thread_group_cputimer {
	struct task_cputime_atomic cputime_atomic;
	bool rh_reserved_running;
	bool rh_reserved_checking_timer;
};

struct pacct_struct {
	int ac_flag;
	long int ac_exitcode;
	long unsigned int ac_mem;
	u64 ac_utime;
	u64 ac_stime;
	long unsigned int ac_minflt;
	long unsigned int ac_majflt;
};

struct tty_struct;

struct autogroup;

struct taskstats;

struct tty_audit_buf;

struct signal_struct {
	union {
		refcount_t sigcnt;
		struct {
			atomic_t sigcnt;
		} rh_kabi_hidden_86;
		union {		};
	};
	atomic_t live;
	int nr_threads;
	struct list_head thread_head;
	wait_queue_head_t wait_chldexit;
	struct task_struct *curr_target;
	struct sigpending shared_pending;
	int group_exit_code;
	int notify_count;
	struct task_struct *group_exit_task;
	int group_stop_count;
	unsigned int flags;
	unsigned int is_child_subreaper: 1;
	unsigned int has_child_subreaper: 1;
	int posix_timer_id;
	struct list_head posix_timers;
	struct hrtimer real_timer;
	ktime_t it_real_incr;
	struct cpu_itimer it[2];
	struct thread_group_cputimer cputimer;
	struct task_cputime rh_reserved_cputime_expires;
	struct list_head rh_reserved_cpu_timers[3];
	struct pid *rh_reserved_leader_pid;
	atomic_t tick_dep_mask;
	struct pid *tty_old_pgrp;
	int leader;
	struct tty_struct *tty;
	struct autogroup *autogroup;
	seqlock_t stats_lock;
	u64 utime;
	u64 stime;
	u64 cutime;
	u64 cstime;
	u64 gtime;
	u64 cgtime;
	struct prev_cputime prev_cputime;
	long unsigned int nvcsw;
	long unsigned int nivcsw;
	long unsigned int cnvcsw;
	long unsigned int cnivcsw;
	long unsigned int min_flt;
	long unsigned int maj_flt;
	long unsigned int cmin_flt;
	long unsigned int cmaj_flt;
	long unsigned int inblock;
	long unsigned int oublock;
	long unsigned int cinblock;
	long unsigned int coublock;
	long unsigned int maxrss;
	long unsigned int cmaxrss;
	struct task_io_accounting ioac;
	long long unsigned int sum_sched_runtime;
	struct rlimit rlim[16];
	struct pacct_struct pacct;
	struct taskstats *stats;
	unsigned int audit_tty;
	struct tty_audit_buf *tty_audit_buf;
	bool oom_flag_origin;
	short int oom_score_adj;
	short int oom_score_adj_min;
	struct mm_struct *oom_mm;
	struct mutex cred_guard_mutex;
	struct pid *pids[4];
	union {
		struct hlist_head multiprocess;
		struct {
			long unsigned int rh_reserved1;
		} rh_kabi_hidden_243;
		union {		};
	};
	long unsigned int rh_reserved2;
	long unsigned int rh_reserved3;
	long unsigned int rh_reserved4;
	struct posix_cputimers posix_cputimers;
	struct rw_semaphore exec_update_lock;
};

struct rseq {
	__u32 cpu_id_start;
	__u32 cpu_id;
	union {
		__u64 ptr64;
		__u64 ptr;
	} rseq_cs;
	__u32 flags;
	long: 32;
	long: 64;
};

struct root_domain;

union rcu_special {
	struct {
		u8 blocked;
		u8 need_qs;
		u8 exp_hint;
		u8 need_mb;
	} b;
	u32 s;
};

struct capture_control;

struct kunit;

struct task_struct_rh {
	struct posix_cputimers posix_cputimers;
	unsigned int rh_reserved_vtime_cpu;
	u64 parent_exec_id;
	u64 self_exec_id;
	struct capture_control *capture_control;
	struct task_struct *task_struct;
	int trc_reader_nesting;
	int trc_ipi_to_cpu;
	union rcu_special trc_reader_special;
	bool trc_reader_checked;
	struct list_head trc_holdout_list;
	struct kunit *kunit_test;
	struct timer_list oom_reaper_timer;
};

struct rq;

struct rq_flags;

struct sched_class {
	const struct sched_class *next;
	void (*enqueue_task)(struct rq *, struct task_struct *, int);
	void (*dequeue_task)(struct rq *, struct task_struct *, int);
	void (*yield_task)(struct rq *);
	union {
		bool (*yield_to_task)(struct rq *, struct task_struct *);
		struct {
			bool (*yield_to_task)(struct rq *, struct task_struct *, bool);
		} rh_kabi_hidden_1851;
		union {		};
	};
	void (*check_preempt_curr)(struct rq *, struct task_struct *, int);
	union {
		struct task_struct * (*pick_next_task)(struct rq *);
		struct {
			struct task_struct * (*pick_next_task)(struct rq *, struct task_struct *, struct rq_flags *);
		} rh_kabi_hidden_1858;
		union {		};
	};
	void (*put_prev_task)(struct rq *, struct task_struct *);
	union {
		int (*select_task_rq)(struct task_struct *, int, int);
		struct {
			int (*select_task_rq)(struct task_struct *, int, int, int);
		} rh_kabi_hidden_1863;
		union {		};
	};
	union {
		void (*migrate_task_rq)(struct task_struct *, int);
		struct {
			void (*migrate_task_rq)(struct task_struct *);
		} rh_kabi_hidden_1865;
		union {		};
	};
	void (*task_woken)(struct rq *, struct task_struct *);
	union {
		void (*set_cpus_allowed)(struct task_struct *, const struct cpumask *, u32);
		struct {
			void (*set_cpus_allowed)(struct task_struct *, const struct cpumask *);
		} rh_kabi_hidden_1871;
		union {		};
	};
	void (*rq_online)(struct rq *);
	void (*rq_offline)(struct rq *);
	union {
		void (*set_next_task)(struct rq *, struct task_struct *, bool);
		struct {
			void (*set_curr_task)(struct rq *);
		} rh_kabi_hidden_1878;
		union {		};
	};
	void (*task_tick)(struct rq *, struct task_struct *, int);
	void (*task_fork)(struct task_struct *);
	void (*task_dead)(struct task_struct *);
	void (*switched_from)(struct rq *, struct task_struct *);
	void (*switched_to)(struct rq *, struct task_struct *);
	void (*prio_changed)(struct rq *, struct task_struct *, int);
	unsigned int (*get_rr_interval)(struct rq *, struct task_struct *);
	void (*update_curr)(struct rq *);
	void (*task_change_group)(struct task_struct *, int);
	union {
		int (*balance)(struct rq *, struct task_struct *, struct rq_flags *);
		struct {
			long unsigned int rh_reserved1;
		} rh_kabi_hidden_1905;
		union {		};
	};
	union {
		struct rq * (*find_lock_rq)(struct task_struct *, struct rq *);
		struct {
			long unsigned int rh_reserved2;
		} rh_kabi_hidden_1906;
		union {		};
	};
};

struct kernel_cap_struct {
	__u32 cap[2];
};

typedef struct kernel_cap_struct kernel_cap_t;

struct group_info;

struct cred {
	atomic_t usage;
	kuid_t uid;
	kgid_t gid;
	kuid_t suid;
	kgid_t sgid;
	kuid_t euid;
	kgid_t egid;
	kuid_t fsuid;
	kgid_t fsgid;
	unsigned int securebits;
	kernel_cap_t cap_inheritable;
	kernel_cap_t cap_permitted;
	kernel_cap_t cap_effective;
	kernel_cap_t cap_bset;
	kernel_cap_t cap_ambient;
	unsigned char jit_keyring;
	struct key *session_keyring;
	struct key *process_keyring;
	struct key *thread_keyring;
	struct key *request_key_auth;
	void *security;
	struct user_struct *user;
	struct user_namespace *user_ns;
	struct group_info *group_info;
	struct callback_head rcu;
};

struct sighand_struct {
	union {
		refcount_t count;
		struct {
			atomic_t count;
		} rh_kabi_hidden_22;
		union {		};
	};
	struct k_sigaction action[64];
	spinlock_t siglock;
	wait_queue_head_t signalfd_wqh;
};

struct io_cq;

struct io_context {
	atomic_long_t refcount;
	atomic_t active_ref;
	atomic_t nr_tasks;
	spinlock_t lock;
	short unsigned int ioprio;
	int nr_batch_requests;
	long unsigned int last_waited;
	struct xarray icq_tree;
	struct io_cq *icq_hint;
	struct hlist_head icq_list;
	struct work_struct release_work;
};

union thread_union {
	struct task_struct task;
	struct thread_info thread_info;
	long unsigned int stack[2048];
};

struct klist_node {
	void *n_klist;
	struct list_head n_node;
	struct kref n_ref;
};

struct pm_message {
	int event;
};

typedef struct pm_message pm_message_t;

struct dev_pm_ops {
	int (*prepare)(struct device *);
	void (*complete)(struct device *);
	int (*suspend)(struct device *);
	int (*resume)(struct device *);
	int (*freeze)(struct device *);
	int (*thaw)(struct device *);
	int (*poweroff)(struct device *);
	int (*restore)(struct device *);
	int (*suspend_late)(struct device *);
	int (*resume_early)(struct device *);
	int (*freeze_late)(struct device *);
	int (*thaw_early)(struct device *);
	int (*poweroff_late)(struct device *);
	int (*restore_early)(struct device *);
	int (*suspend_noirq)(struct device *);
	int (*resume_noirq)(struct device *);
	int (*freeze_noirq)(struct device *);
	int (*thaw_noirq)(struct device *);
	int (*poweroff_noirq)(struct device *);
	int (*restore_noirq)(struct device *);
	int (*runtime_suspend)(struct device *);
	int (*runtime_resume)(struct device *);
	int (*runtime_idle)(struct device *);
};

enum dl_dev_state {
	DL_DEV_NO_DRIVER = 0,
	DL_DEV_PROBING = 1,
	DL_DEV_DRIVER_BOUND = 2,
	DL_DEV_UNBINDING = 3,
};

struct dev_links_info {
	struct list_head suppliers;
	struct list_head consumers;
	enum dl_dev_state status;
};

enum rpm_request {
	RPM_REQ_NONE = 0,
	RPM_REQ_IDLE = 1,
	RPM_REQ_SUSPEND = 2,
	RPM_REQ_AUTOSUSPEND = 3,
	RPM_REQ_RESUME = 4,
};

enum rpm_status {
	RPM_ACTIVE = 0,
	RPM_RESUMING = 1,
	RPM_SUSPENDED = 2,
	RPM_SUSPENDING = 3,
};

struct wakeup_source;

struct wake_irq;

struct pm_subsys_data;

struct dev_pm_qos;

struct dev_pm_info {
	pm_message_t power_state;
	unsigned int can_wakeup: 1;
	unsigned int async_suspend: 1;
	bool in_dpm_list: 1;
	bool is_prepared: 1;
	bool is_suspended: 1;
	bool is_noirq_suspended: 1;
	bool is_late_suspended: 1;
	bool early_init: 1;
	bool direct_complete: 1;
	bool no_pm: 1;
	u32 driver_flags;
	spinlock_t lock;
	struct list_head entry;
	struct completion completion;
	struct wakeup_source *wakeup;
	bool wakeup_path: 1;
	bool syscore: 1;
	bool no_pm_callbacks: 1;
	unsigned int must_resume: 1;
	unsigned int may_skip_resume: 1;
	struct timer_list suspend_timer;
	long unsigned int timer_expires;
	struct work_struct work;
	wait_queue_head_t wait_queue;
	struct wake_irq *wakeirq;
	atomic_t usage_count;
	atomic_t child_count;
	unsigned int disable_depth: 3;
	unsigned int idle_notification: 1;
	unsigned int request_pending: 1;
	unsigned int deferred_resume: 1;
	unsigned int runtime_auto: 1;
	bool ignore_children: 1;
	unsigned int no_callbacks: 1;
	unsigned int irq_safe: 1;
	unsigned int use_autosuspend: 1;
	unsigned int timer_autosuspends: 1;
	unsigned int memalloc_noio: 1;
	unsigned int links_count;
	enum rpm_request request;
	enum rpm_status runtime_status;
	int runtime_error;
	int autosuspend_delay;
	long unsigned int last_busy;
	long unsigned int active_jiffies;
	long unsigned int suspended_jiffies;
	long unsigned int accounting_timestamp;
	struct pm_subsys_data *subsys_data;
	void (*set_latency_tolerance)(struct device *, s32);
	struct dev_pm_qos *qos;
};

struct dma_coherent_mem;

struct iommu_table;

struct pci_dn;

struct eeh_dev;

struct cxl_context;

struct dev_archdata {
	dma_addr_t dma_offset;
	struct iommu_table *iommu_table_base;
	void *rh_reserved_iommu_domain;
	dma_addr_t rh_reserved_max_direct_dma_addr;
	struct pci_dn *pci_data;
	struct eeh_dev *edev;
	struct cxl_context *cxl_ctx;
};

enum device_removable {
	DEVICE_REMOVABLE_NOT_SUPPORTED = 0,
	DEVICE_REMOVABLE_UNKNOWN = 1,
	DEVICE_FIXED = 2,
	DEVICE_REMOVABLE = 3,
};

struct device_private;

struct device_type;

struct bus_type;

struct device_driver;

struct dev_pm_domain;

struct dma_map_ops;

struct bus_dma_region;

struct device_dma_parameters;

struct device_node;

struct fwnode_handle;

struct class;

struct iommu_group;

struct iommu_fwspec;

struct dev_iommu;

struct io_tlb_mem;

struct device_physical_location;

struct device_extended_rh;

struct device {
	struct device *parent;
	struct device_private *p;
	struct kobject kobj;
	const char *init_name;
	const struct device_type *type;
	struct mutex mutex;
	struct bus_type *bus;
	struct device_driver *driver;
	void *platform_data;
	void *driver_data;
	struct dev_links_info links;
	struct dev_pm_info power;
	struct dev_pm_domain *pm_domain;
	struct list_head msi_list;
	int numa_node;
	const struct dma_map_ops *dma_ops;
	u64 *dma_mask;
	u64 coherent_dma_mask;
	u64 bus_dma_limit;
	union {
		const struct bus_dma_region *dma_range_map;
		struct {
			long unsigned int dma_pfn_offset;
		} rh_kabi_hidden_1356;
		union {		};
	};
	struct device_dma_parameters *dma_parms;
	struct list_head dma_pools;
	struct dma_coherent_mem *dma_mem;
	struct dev_archdata archdata;
	struct device_node *of_node;
	struct fwnode_handle *fwnode;
	dev_t devt;
	u32 id;
	spinlock_t devres_lock;
	struct list_head devres_head;
	struct klist_node knode_class;
	struct class *class;
	const struct attribute_group **groups;
	void (*release)(struct device *);
	struct iommu_group *iommu_group;
	struct iommu_fwspec *rh_reserved_iommu_fwspec;
	bool offline_disabled: 1;
	bool offline: 1;
	bool of_node_reused: 1;
	bool state_synced: 1;
	bool can_match: 1;
	bool dma_ops_bypass: 1;
	union {
		struct dev_iommu *iommu;
		struct {
			long unsigned int rh_reserved1;
		} rh_kabi_hidden_1404;
		union {		};
	};
	union {
		struct io_tlb_mem *dma_io_tlb_mem;
		struct {
			long unsigned int rh_reserved2;
		} rh_kabi_hidden_1406;
		union {		};
	};
	union {
		struct device_physical_location *physical_location;
		struct {
			long unsigned int rh_reserved3;
		} rh_kabi_hidden_1412;
		union {		};
	};
	long unsigned int rh_reserved4;
	long unsigned int rh_reserved5;
	union {
		struct list_head links_defer_sync;
		struct {
			long unsigned int rh_reserved6;
			long unsigned int rh_reserved7;
		} rh_kabi_hidden_1415;
		union {		};
	};
	union {
		enum device_removable removable;
		struct {
			long unsigned int rh_reserved8;
		} rh_kabi_hidden_1417;
		union {		};
	};
	union {
		raw_spinlock_t msi_lock;
		struct {
			long unsigned int rh_reserved9;
		} rh_kabi_hidden_1418;
		union {		};
	};
	long unsigned int rh_reserved10;
	long unsigned int rh_reserved11;
	long unsigned int rh_reserved12;
	long unsigned int rh_reserved13;
	long unsigned int rh_reserved14;
	long unsigned int rh_reserved15;
	long unsigned int rh_reserved16;
	size_t device_extended_size_rh;
	struct device_extended_rh *_rh;
};

struct pm_domain_data;

struct pm_subsys_data {
	spinlock_t lock;
	unsigned int refcount;
	struct pm_domain_data *domain_data;
};

struct wakeup_source {
	const char *name;
	struct list_head entry;
	spinlock_t lock;
	struct wake_irq *wakeirq;
	struct timer_list timer;
	long unsigned int timer_expires;
	ktime_t total_time;
	ktime_t max_time;
	ktime_t last_time;
	ktime_t start_prevent_time;
	ktime_t prevent_sleep_time;
	long unsigned int event_count;
	long unsigned int active_count;
	long unsigned int relax_count;
	long unsigned int expire_count;
	long unsigned int wakeup_count;
	bool active: 1;
	bool autosleep_enabled: 1;
	int id;
	struct device *dev;
};

struct dev_pm_domain {
	struct dev_pm_ops ops;
	void (*detach)(struct device *, bool);
	int (*activate)(struct device *);
	void (*sync)(struct device *);
	void (*dismiss)(struct device *);
};

struct iommu_pool {
	long unsigned int start;
	long unsigned int end;
	long unsigned int hint;
	spinlock_t lock;
	long: 32;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
};

struct iommu_table_ops;

struct iommu_table {
	long unsigned int it_busno;
	long unsigned int it_size;
	long unsigned int it_indirect_levels;
	long unsigned int it_level_size;
	long unsigned int it_allocated_size;
	long unsigned int it_offset;
	long unsigned int it_base;
	long unsigned int it_index;
	long unsigned int it_type;
	long unsigned int it_blocksize;
	long unsigned int poolsize;
	long unsigned int nr_pools;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	struct iommu_pool large_pool;
	struct iommu_pool pools[4];
	long unsigned int *it_map;
	long unsigned int it_page_shift;
	struct list_head it_group_list;
	__be64 *it_userspace;
	struct iommu_table_ops *it_ops;
	struct kref it_kref;
	int it_nid;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
};

struct pci_controller;

struct iommu_table_group;

struct pci_dn {
	int flags;
	int busno;
	int devfn;
	int vendor_id;
	int device_id;
	int class_code;
	struct pci_dn *parent;
	struct pci_controller *phb;
	struct iommu_table_group *table_group;
	int pci_ext_config_space;
	struct eeh_dev *edev;
	unsigned int pe_number;
	int rh_reserved_vf_index;
	u16 vfs_expanded;
	u16 num_vfs;
	unsigned int *pe_num_map;
	bool m64_single_mode;
	int (*m64_map)[6];
	int last_allow_rc;
	int mps;
	struct list_head child_list;
	struct list_head list;
	struct resource holes[6];
};

struct eeh_pe;

struct pci_dev;

struct pci_bus;

struct eeh_dev {
	int mode;
	int rh_reserved_class_code;
	int pe_config_addr;
	u32 config_space[16];
	int pcix_cap;
	int pcie_cap;
	int aer_cap;
	int af_cap;
	struct eeh_pe *pe;
	struct list_head entry;
	struct list_head rmv_entry;
	struct pci_dn *pdn;
	struct pci_dev *pdev;
	bool in_error;
	struct pci_dev *physfn;
	union {
		struct pci_controller *controller;
		struct {
			struct pci_bus *bus;
		} rh_kabi_hidden_164;
		union {		};
	};
	int bdfn;
	int vf_index;
};

struct iommu_ops;

struct subsys_private;

struct bus_type {
	const char *name;
	const char *dev_name;
	struct device *dev_root;
	const struct attribute_group **bus_groups;
	const struct attribute_group **dev_groups;
	const struct attribute_group **drv_groups;
	int (*match)(struct device *, struct device_driver *);
	int (*uevent)(struct device *, struct kobj_uevent_env *);
	int (*probe)(struct device *);
	int (*remove)(struct device *);
	void (*shutdown)(struct device *);
	int (*online)(struct device *);
	int (*offline)(struct device *);
	int (*suspend)(struct device *, pm_message_t);
	int (*resume)(struct device *);
	int (*num_vf)(struct device *);
	int (*dma_configure)(struct device *);
	const struct dev_pm_ops *pm;
	const struct iommu_ops *iommu_ops;
	struct subsys_private *p;
	struct lock_class_key rh_reserved_lock_key;
	bool need_parent_lock;
	void (*sync_state)(struct device *);
	void (*dma_cleanup)(struct device *);
};

enum probe_type {
	PROBE_DEFAULT_STRATEGY = 0,
	PROBE_PREFER_ASYNCHRONOUS = 1,
	PROBE_FORCE_SYNCHRONOUS = 2,
};

struct driver_private;

struct device_driver_rh;

struct device_driver {
	const char *name;
	struct bus_type *bus;
	struct module *owner;
	const char *mod_name;
	bool suppress_bind_attrs;
	enum probe_type probe_type;
	const struct of_device_id *of_match_table;
	const struct acpi_device_id *acpi_match_table;
	int (*probe)(struct device *);
	int (*remove)(struct device *);
	void (*shutdown)(struct device *);
	int (*suspend)(struct device *, pm_message_t);
	int (*resume)(struct device *);
	const struct attribute_group **groups;
	const struct dev_pm_ops *pm;
	void (*coredump)(struct device *);
	struct driver_private *p;
	union {
		const struct attribute_group **dev_groups;
		struct {
			long unsigned int rh_reserved1;
		} rh_kabi_hidden_408;
		union {		};
	};
	union {
		void (*sync_state)(struct device *);
		struct {
			long unsigned int rh_reserved2;
		} rh_kabi_hidden_409;
		union {		};
	};
	long unsigned int rh_reserved3;
	long unsigned int rh_reserved4;
	size_t device_driver_size_rh;
	struct device_driver_rh *_rh;
};

enum iommu_cap {
	IOMMU_CAP_CACHE_COHERENCY = 0,
	IOMMU_CAP_INTR_REMAP = 1,
	IOMMU_CAP_NOEXEC = 2,
	IOMMU_CAP_PRE_BOOT_PROTECTION = 3,
};

enum iommu_dev_features {
	IOMMU_DEV_FEAT_AUX = 0,
	IOMMU_DEV_FEAT_SVA = 1,
	IOMMU_DEV_FEAT_IOPF = 2,
};

struct iommu_domain;

struct iommu_iotlb_gather;

struct of_phandle_args;

struct iommu_sva;

struct iommu_fault_event;

struct iommu_page_response;

struct iommu_device;

struct iommu_ops {
	bool (*capable)(enum iommu_cap);
	struct iommu_domain * (*domain_alloc)(unsigned int);
	void (*domain_free)(struct iommu_domain *);
	int (*attach_dev)(struct iommu_domain *, struct device *);
	void (*detach_dev)(struct iommu_domain *, struct device *);
	int (*map)(struct iommu_domain *, long unsigned int, phys_addr_t, size_t, int, gfp_t);
	size_t (*unmap)(struct iommu_domain *, long unsigned int, size_t, struct iommu_iotlb_gather *);
	void (*flush_iotlb_all)(struct iommu_domain *);
	void (*iotlb_sync_map)(struct iommu_domain *, long unsigned int, size_t);
	void (*iotlb_sync)(struct iommu_domain *, struct iommu_iotlb_gather *);
	phys_addr_t (*iova_to_phys)(struct iommu_domain *, dma_addr_t);
	struct iommu_group * (*device_group)(struct device *);
	void (*get_resv_regions)(struct device *, struct list_head *);
	void (*put_resv_regions)(struct device *, struct list_head *);
	int (*of_xlate)(struct device *, struct of_phandle_args *);
	bool (*is_attach_deferred)(struct iommu_domain *, struct device *);
	bool (*dev_has_feat)(struct device *, enum iommu_dev_features);
	bool (*dev_feat_enabled)(struct device *, enum iommu_dev_features);
	int (*dev_enable_feat)(struct device *, enum iommu_dev_features);
	int (*dev_disable_feat)(struct device *, enum iommu_dev_features);
	int (*aux_attach_dev)(struct iommu_domain *, struct device *);
	void (*aux_detach_dev)(struct iommu_domain *, struct device *);
	int (*aux_get_pasid)(struct iommu_domain *, struct device *);
	struct iommu_sva * (*sva_bind)(struct device *, struct mm_struct *);
	void (*sva_unbind)(struct iommu_sva *);
	u32 (*sva_get_pasid)(struct iommu_sva *);
	int (*page_response)(struct device *, struct iommu_fault_event *, struct iommu_page_response *);
	int (*def_domain_type)(struct device *);
	struct iommu_device * (*probe_device)(struct device *);
	void (*release_device)(struct device *);
	void (*probe_finalize)(struct device *);
	int (*enable_nesting)(struct iommu_domain *);
	int (*set_pgtable_quirks)(struct iommu_domain *, long unsigned int);
	int (*map_pages)(struct iommu_domain *, long unsigned int, phys_addr_t, size_t, size_t, int, gfp_t, size_t *);
	size_t (*unmap_pages)(struct iommu_domain *, long unsigned int, size_t, size_t, struct iommu_iotlb_gather *);
	long unsigned int pgsize_bitmap;
	struct module *owner;
};

struct device_driver_rh {};

struct class_rh {};

struct class {
	const char *name;
	struct module *owner;
	const struct attribute_group **class_groups;
	const struct attribute_group **dev_groups;
	struct kobject *dev_kobj;
	int (*dev_uevent)(const struct device *, struct kobj_uevent_env *);
	char * (*devnode)(const struct device *, umode_t *);
	void (*class_release)(struct class *);
	void (*dev_release)(struct device *);
	int (*shutdown_pre)(struct device *);
	const struct kobj_ns_type_operations *ns_type;
	const void * (*namespace)(const struct device *);
	const struct dev_pm_ops *pm;
	struct subsys_private *p;
	union {
		void (*get_ownership)(const struct device *, kuid_t *, kgid_t *);
		struct {
			long unsigned int rh_reserved1;
		} rh_kabi_hidden_619;
		union {		};
	};
	long unsigned int rh_reserved2;
	long unsigned int rh_reserved3;
	long unsigned int rh_reserved4;
	size_t class_size_rh;
	struct class_rh *_rh;
};

struct device_type {
	const char *name;
	const struct attribute_group **groups;
	int (*uevent)(struct device *, struct kobj_uevent_env *);
	char * (*devnode)(const struct device *, umode_t *, kuid_t *, kgid_t *);
	void (*release)(struct device *);
	const struct dev_pm_ops *pm;
};

struct device_dma_parameters {
	unsigned int max_segment_size;
	long unsigned int segment_boundary_mask;
	unsigned int min_align_mask;
};

struct fwnode_operations;

struct fwnode_handle {
	struct fwnode_handle *secondary;
	const struct fwnode_operations *ops;
	struct device *dev;
	struct list_head suppliers;
	struct list_head consumers;
	u8 flags;
};

struct device_extended_rh {};

enum device_physical_location_panel {
	DEVICE_PANEL_TOP = 0,
	DEVICE_PANEL_BOTTOM = 1,
	DEVICE_PANEL_LEFT = 2,
	DEVICE_PANEL_RIGHT = 3,
	DEVICE_PANEL_FRONT = 4,
	DEVICE_PANEL_BACK = 5,
	DEVICE_PANEL_UNKNOWN = 6,
};

enum device_physical_location_vertical_position {
	DEVICE_VERT_POS_UPPER = 0,
	DEVICE_VERT_POS_CENTER = 1,
	DEVICE_VERT_POS_LOWER = 2,
};

enum device_physical_location_horizontal_position {
	DEVICE_HORI_POS_LEFT = 0,
	DEVICE_HORI_POS_CENTER = 1,
	DEVICE_HORI_POS_RIGHT = 2,
};

struct device_physical_location {
	enum device_physical_location_panel panel;
	enum device_physical_location_vertical_position vertical_position;
	enum device_physical_location_horizontal_position horizontal_position;
	bool dock;
	bool lid;
};

struct bus_dma_region {
	phys_addr_t cpu_start;
	dma_addr_t dma_start;
	u64 size;
	u64 offset;
};

enum dma_data_direction {
	DMA_BIDIRECTIONAL = 0,
	DMA_TO_DEVICE = 1,
	DMA_FROM_DEVICE = 2,
	DMA_NONE = 3,
};

struct dma_map_ops_extended_rh {};

struct sg_table;

struct scatterlist;

struct dma_map_ops {
	void * (*alloc)(struct device *, size_t, dma_addr_t *, gfp_t, long unsigned int);
	void (*free)(struct device *, size_t, void *, dma_addr_t, long unsigned int);
	int (*mmap)(struct device *, struct vm_area_struct *, void *, dma_addr_t, size_t, long unsigned int);
	int (*get_sgtable)(struct device *, struct sg_table *, void *, dma_addr_t, size_t, long unsigned int);
	dma_addr_t (*map_page)(struct device *, struct page *, long unsigned int, size_t, enum dma_data_direction, long unsigned int);
	void (*unmap_page)(struct device *, dma_addr_t, size_t, enum dma_data_direction, long unsigned int);
	int (*map_sg)(struct device *, struct scatterlist *, int, enum dma_data_direction, long unsigned int);
	void (*unmap_sg)(struct device *, struct scatterlist *, int, enum dma_data_direction, long unsigned int);
	dma_addr_t (*map_resource)(struct device *, phys_addr_t, size_t, enum dma_data_direction, long unsigned int);
	void (*unmap_resource)(struct device *, dma_addr_t, size_t, enum dma_data_direction, long unsigned int);
	union {
		size_t (*max_mapping_size)(struct device *);
		struct {
			long unsigned int rh_reserved1;
		} rh_kabi_hidden_53;
		union {		};
	};
	union {
		long unsigned int (*get_merge_boundary)(struct device *);
		struct {
			long unsigned int rh_reserved2;
		} rh_kabi_hidden_54;
		union {		};
	};
	union {
		struct page * (*alloc_pages)(struct device *, size_t, dma_addr_t *, enum dma_data_direction, gfp_t);
		struct {
			long unsigned int rh_reserved3;
		} rh_kabi_hidden_57;
		union {		};
	};
	union {
		void (*free_pages)(struct device *, size_t, struct page *, dma_addr_t, enum dma_data_direction);
		struct {
			long unsigned int rh_reserved4;
		} rh_kabi_hidden_60;
		union {		};
	};
	union {
		struct sg_table * (*alloc_noncontiguous)(struct device *, size_t, enum dma_data_direction, gfp_t, long unsigned int);
		struct {
			long unsigned int rh_reserved5;
		} rh_kabi_hidden_63;
		union {		};
	};
	union {
		void (*free_noncontiguous)(struct device *, size_t, struct sg_table *, enum dma_data_direction);
		struct {
			long unsigned int rh_reserved6;
		} rh_kabi_hidden_65;
		union {		};
	};
	void (*sync_single_for_cpu)(struct device *, dma_addr_t, size_t, enum dma_data_direction);
	void (*sync_single_for_device)(struct device *, dma_addr_t, size_t, enum dma_data_direction);
	void (*sync_sg_for_cpu)(struct device *, struct scatterlist *, int, enum dma_data_direction);
	void (*sync_sg_for_device)(struct device *, struct scatterlist *, int, enum dma_data_direction);
	void (*cache_sync)(struct device *, void *, size_t, enum dma_data_direction);
	int (*dma_supported)(struct device *, u64);
	u64 (*get_required_mask)(struct device *);
	size_t dma_map_ops_extended_size_rh;
	struct dma_map_ops_extended_rh _rh;
};

typedef u32 phandle;

struct property;

struct device_node {
	const char *name;
	const char *type;
	phandle phandle;
	const char *full_name;
	struct fwnode_handle fwnode;
	struct property *properties;
	struct property *deadprops;
	struct device_node *parent;
	struct device_node *child;
	struct device_node *sibling;
	struct kobject kobj;
	long unsigned int _flags;
	void *data;
};

enum ctx_state {
	CONTEXT_DISABLED = 4294967295,
	CONTEXT_KERNEL = 0,
	CONTEXT_USER = 1,
	CONTEXT_GUEST = 2,
};

struct context_tracking {
	bool active;
	int recursion;
	enum ctx_state state;
};

struct irq_desc;

typedef void (*irq_flow_handler_t)(struct irq_desc *);

struct msi_desc;

struct irq_common_data {
	unsigned int state_use_accessors;
	unsigned int node;
	void *handler_data;
	struct msi_desc *msi_desc;
	cpumask_var_t affinity;
};

struct irq_chip;

struct irq_domain;

struct irq_data {
	u32 mask;
	unsigned int irq;
	long unsigned int hwirq;
	struct irq_common_data *common;
	struct irq_chip *chip;
	struct irq_domain *domain;
	void *chip_data;
};

struct irqaction;

struct irq_affinity_notify;

struct proc_dir_entry;

struct irq_desc {
	struct irq_common_data irq_common_data;
	struct irq_data irq_data;
	unsigned int *kstat_irqs;
	irq_flow_handler_t handle_irq;
	struct irqaction *action;
	unsigned int status_use_accessors;
	unsigned int core_internal_state__do_not_mess_with_it;
	unsigned int depth;
	unsigned int wake_depth;
	unsigned int irq_count;
	unsigned int tot_count;
	long unsigned int last_unhandled;
	unsigned int irqs_unhandled;
	atomic_t threads_handled;
	int threads_handled_last;
	raw_spinlock_t lock;
	struct cpumask *percpu_enabled;
	const struct cpumask *percpu_affinity;
	const struct cpumask *affinity_hint;
	struct irq_affinity_notify *affinity_notify;
	long unsigned int threads_oneshot;
	atomic_t threads_active;
	wait_queue_head_t wait_for_threads;
	unsigned int nr_actions;
	unsigned int no_suspend_depth;
	unsigned int cond_suspend_depth;
	unsigned int force_resume_depth;
	struct proc_dir_entry *dir;
	struct callback_head rcu;
	struct kobject kobj;
	struct mutex request_mutex;
	int parent_irq;
	struct module *owner;
	const char *name;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
};

typedef int pci_power_t;

typedef unsigned int pci_channel_state_t;

typedef short unsigned int pci_dev_flags_t;

struct pci_p2pdma;

struct pci_vpd {
	struct mutex lock;
	unsigned int len;
	u8 cap;
};

struct pci_dev_extended_rh {};

struct pci_slot;

struct aer_stats;

struct pci_driver;

struct pcie_link_state;

struct pci_sriov;

struct rcec_ea;

struct pci_dev {
	struct list_head bus_list;
	struct pci_bus *bus;
	struct pci_bus *subordinate;
	void *sysdata;
	struct proc_dir_entry *procent;
	struct pci_slot *slot;
	unsigned int devfn;
	short unsigned int vendor;
	short unsigned int device;
	short unsigned int subsystem_vendor;
	short unsigned int subsystem_device;
	unsigned int class;
	u8 revision;
	u8 hdr_type;
	u16 aer_cap;
	struct aer_stats *aer_stats;
	u8 pcie_cap;
	u8 msi_cap;
	u8 msix_cap;
	u8 pcie_mpss: 3;
	u8 rom_base_reg;
	u8 pin;
	u16 pcie_flags_reg;
	long unsigned int *dma_alias_mask;
	struct pci_driver *driver;
	u64 dma_mask;
	struct device_dma_parameters dma_parms;
	pci_power_t current_state;
	unsigned int imm_ready: 1;
	u8 pm_cap;
	unsigned int pme_support: 5;
	unsigned int pme_poll: 1;
	unsigned int d1_support: 1;
	unsigned int d2_support: 1;
	unsigned int no_d1d2: 1;
	unsigned int no_d3cold: 1;
	unsigned int bridge_d3: 1;
	unsigned int d3cold_allowed: 1;
	unsigned int mmio_always_on: 1;
	unsigned int wakeup_prepared: 1;
	unsigned int runtime_d3cold: 1;
	unsigned int ignore_hotplug: 1;
	unsigned int hotplug_user_indicators: 1;
	unsigned int clear_retrain_link: 1;
	unsigned int skip_bus_pm: 1;
	unsigned int external_facing: 1;
	unsigned int d3_delay;
	unsigned int d3cold_delay;
	struct pcie_link_state *link_state;
	unsigned int ltr_path: 1;
	unsigned int eetlp_prefix_path: 1;
	pci_channel_state_t error_state;
	struct device dev;
	int cfg_size;
	unsigned int irq;
	struct resource resource[17];
	bool match_driver;
	unsigned int transparent: 1;
	unsigned int multifunction: 1;
	unsigned int is_busmaster: 1;
	unsigned int no_msi: 1;
	unsigned int no_64bit_msi: 1;
	unsigned int block_cfg_access: 1;
	unsigned int broken_parity_status: 1;
	unsigned int irq_reroute_variant: 2;
	unsigned int msi_enabled: 1;
	unsigned int msix_enabled: 1;
	unsigned int ari_enabled: 1;
	unsigned int ats_enabled: 1;
	unsigned int pasid_enabled: 1;
	unsigned int pri_enabled: 1;
	unsigned int is_managed: 1;
	unsigned int needs_freset: 1;
	unsigned int state_saved: 1;
	unsigned int is_physfn: 1;
	unsigned int is_virtfn: 1;
	unsigned int rh_reserved_reset_fn: 1;
	unsigned int is_hotplug_bridge: 1;
	unsigned int shpc_managed: 1;
	unsigned int is_thunderbolt: 1;
	unsigned int rh_reserved___aer_firmware_first_valid: 1;
	unsigned int rh_reserved___aer_firmware_first: 1;
	unsigned int broken_intx_masking: 1;
	unsigned int io_window_1k: 1;
	unsigned int irq_managed: 1;
	unsigned int has_secondary_link: 1;
	unsigned int non_compliant_bars: 1;
	unsigned int is_probed: 1;
	unsigned int link_active_reporting: 1;
	unsigned int untrusted: 1;
	unsigned int no_vf_scan: 1;
	unsigned int io_window: 1;
	unsigned int pref_window: 1;
	unsigned int pref_64_window: 1;
	unsigned int pasid_required: 1;
	unsigned int dpc_rp_extensions: 1;
	unsigned int no_command_memory: 1;
	unsigned int rom_bar_overlap: 1;
	pci_dev_flags_t dev_flags;
	atomic_t enable_cnt;
	u32 saved_config_space[16];
	struct hlist_head saved_cap_space;
	struct bin_attribute *rh_reserved_rom_attr;
	int rom_attr_enabled;
	struct bin_attribute *res_attr[17];
	struct bin_attribute *res_attr_wc[17];
	const struct attribute_group **msi_irq_groups;
	struct pci_vpd *rh_reserved_vpd;
	union {
		struct pci_sriov *sriov;
		struct pci_dev *physfn;
	};
	u16 ats_cap;
	u8 ats_stu;
	atomic_t rh_reserved_ats_ref_cnt;
	u32 pri_reqs_alloc;
	u16 pasid_features;
	struct pci_p2pdma *p2pdma;
	phys_addr_t rom;
	size_t romlen;
	char *driver_override;
	long unsigned int priv_flags;
	union {
		u16 pri_cap;
		struct {
			long unsigned int rh_reserved1;
		} rh_kabi_hidden_537;
		union {		};
	};
	union {
		u16 pasid_cap;
		struct {
			long unsigned int rh_reserved2;
		} rh_kabi_hidden_540;
		union {		};
	};
	union {
		u16 dpc_cap;
		struct {
			long unsigned int rh_reserved3;
		} rh_kabi_hidden_543;
		union {		};
	};
	union {
		u8 dpc_rp_log_size;
		struct {
			long unsigned int rh_reserved4;
		} rh_kabi_hidden_544;
		union {		};
	};
	union {
		u16 acs_cap;
		struct {
			long unsigned int rh_reserved5;
		} rh_kabi_hidden_546;
		union {		};
	};
	union {
		u16 l1ss;
		struct {
			long unsigned int rh_reserved6;
		} rh_kabi_hidden_548;
		union {		};
	};
	union {
		struct rcec_ea *rcec_ea;
		struct {
			long unsigned int rh_reserved7;
		} rh_kabi_hidden_551;
		union {		};
	};
	union {
		struct pci_dev *rcec;
		struct {
			long unsigned int rh_reserved8;
		} rh_kabi_hidden_552;
		union {		};
	};
	union {
		struct pci_vpd vpd;
		struct {
			long unsigned int rh_reserved9;
			long unsigned int rh_reserved10;
			long unsigned int rh_reserved11;
			long unsigned int rh_reserved12;
			long unsigned int rh_reserved13;
		} rh_kabi_hidden_554;
		union {		};
	};
	union {
		u32 devcap;
		struct {
			long unsigned int rh_reserved14;
		} rh_kabi_hidden_555;
		union {		};
	};
	union {
		u8 reset_methods[7];
		struct {
			long unsigned int rh_reserved15;
		} rh_kabi_hidden_557;
		union {		};
	};
	size_t pci_dev_extended_size_rh;
	struct pci_dev_extended_rh _rh;
};

struct clock_event_device;

struct eeh_pe {
	int type;
	int state;
	int rh_reserved_config_addr;
	int addr;
	struct pci_controller *phb;
	struct pci_bus *bus;
	int check_count;
	int freeze_count;
	time64_t tstamp;
	int false_positives;
	atomic_t pass_dev_cnt;
	struct eeh_pe *parent;
	void *data;
	struct list_head child_list;
	struct list_head edevs;
	struct list_head child;
	long unsigned int stack_trace[64];
	int trace_entries;
};

struct pci_controller_ops {
	void (*dma_dev_setup)(struct pci_dev *);
	void (*dma_bus_setup)(struct pci_bus *);
	int (*probe_mode)(struct pci_bus *);
	bool (*enable_device_hook)(struct pci_dev *);
	void (*disable_device)(struct pci_dev *);
	void (*release_device)(struct pci_dev *);
	resource_size_t (*window_alignment)(struct pci_bus *, long unsigned int);
	void (*setup_bridge)(struct pci_bus *, long unsigned int);
	void (*reset_secondary_bus)(struct pci_dev *);
	int (*setup_msi_irqs)(struct pci_dev *, int, int);
	void (*teardown_msi_irqs)(struct pci_dev *);
	int (*rh_reserved_dma_set_mask)(struct pci_dev *, u64);
	union {
		bool (*iommu_bypass_supported)(struct pci_dev *, u64);
		struct {
			u64 (*dma_get_required_mask)(struct pci_dev *);
		} rh_kabi_hidden_51;
		union {		};
	};
	void (*shutdown)(struct pci_controller *);
};

struct pci_ops;

struct npu;

struct pci_controller {
	struct pci_bus *bus;
	char is_dynamic;
	int node;
	struct device_node *dn;
	struct list_head list_node;
	struct device *parent;
	int first_busno;
	int last_busno;
	int self_busno;
	struct resource busn;
	void *io_base_virt;
	void *io_base_alloc;
	resource_size_t io_base_phys;
	resource_size_t pci_io_size;
	resource_size_t isa_mem_phys;
	resource_size_t isa_mem_size;
	struct pci_controller_ops controller_ops;
	struct pci_ops *ops;
	unsigned int *cfg_addr;
	void *cfg_data;
	u32 indirect_type;
	struct resource io_resource;
	struct resource mem_resources[3];
	resource_size_t mem_offset[3];
	int global_number;
	resource_size_t dma_window_base_cur;
	resource_size_t dma_window_size;
	long unsigned int buid;
	struct pci_dn *pci_data;
	void *private_data;
	struct npu *npu;
};

typedef short unsigned int pci_bus_flags_t;

struct msi_controller;

struct pci_bus {
	struct list_head node;
	struct pci_bus *parent;
	struct list_head children;
	struct list_head devices;
	struct pci_dev *self;
	struct list_head slots;
	struct resource *resource[4];
	struct list_head resources;
	struct resource busn_res;
	struct pci_ops *ops;
	struct msi_controller *msi;
	void *sysdata;
	struct proc_dir_entry *procdir;
	unsigned char number;
	unsigned char primary;
	unsigned char max_bus_speed;
	unsigned char cur_bus_speed;
	char name[48];
	short unsigned int bridge_ctl;
	pci_bus_flags_t bus_flags;
	struct device *bridge;
	struct device dev;
	struct bin_attribute *legacy_io;
	struct bin_attribute *legacy_mem;
	unsigned int is_added: 1;
	long unsigned int rh_reserved1;
	long unsigned int rh_reserved2;
	long unsigned int rh_reserved3;
	long unsigned int rh_reserved4;
	long unsigned int rh_reserved5;
	long unsigned int rh_reserved6;
	long unsigned int rh_reserved7;
};

struct eeh_ops {
	char *name;
	int * (*rh_reserved_init)();
	struct eeh_dev * (*probe)(struct pci_dev *);
	int (*set_option)(struct eeh_pe *, int);
	int (*rh_reserved_get_pe_addr)(struct eeh_pe *);
	int (*get_state)(struct eeh_pe *, int *);
	int (*reset)(struct eeh_pe *, int);
	int (*rh_reserved_wait_state)(struct eeh_pe *, int);
	int (*get_log)(struct eeh_pe *, int, char *, long unsigned int);
	int (*configure_bridge)(struct eeh_pe *);
	int (*err_inject)(struct eeh_pe *, int, int, long unsigned int, long unsigned int);
	union {
		int (*read_config)(struct eeh_dev *, int, int, u32 *);
		struct {
			int (*read_config)(struct pci_dn *, int, int, u32 *);
		} rh_kabi_hidden_244;
		union {		};
	};
	union {
		int (*write_config)(struct eeh_dev *, int, int, u32);
		struct {
			int (*write_config)(struct pci_dn *, int, int, u32);
		} rh_kabi_hidden_246;
		union {		};
	};
	int (*next_error)(struct eeh_pe **);
	union {
		int (*restore_config)(struct eeh_dev *);
		struct {
			int (*restore_config)(struct pci_dn *);
		} rh_kabi_hidden_249;
		union {		};
	};
	union {
		int (*notify_resume)(struct eeh_dev *);
		struct {
			int (*notify_resume)(struct pci_dn *);
		} rh_kabi_hidden_251;
		union {		};
	};
};

struct ppc_pci_io {
	u8 (*readb)(volatile const void *);
	u16 (*readw)(volatile const void *);
	u32 (*readl)(volatile const void *);
	u16 (*readw_be)(volatile const void *);
	u32 (*readl_be)(volatile const void *);
	void (*writeb)(u8, volatile void *);
	void (*writew)(u16, volatile void *);
	void (*writel)(u32, volatile void *);
	void (*writew_be)(u16, volatile void *);
	void (*writel_be)(u32, volatile void *);
	u64 (*readq)(volatile const void *);
	u64 (*readq_be)(volatile const void *);
	void (*writeq)(u64, volatile void *);
	void (*writeq_be)(u64, volatile void *);
	u8 (*inb)(long unsigned int);
	u16 (*inw)(long unsigned int);
	u32 (*inl)(long unsigned int);
	void (*outb)(u8, long unsigned int);
	void (*outw)(u16, long unsigned int);
	void (*outl)(u32, long unsigned int);
	void (*readsb)(volatile const void *, void *, long unsigned int);
	void (*readsw)(volatile const void *, void *, long unsigned int);
	void (*readsl)(volatile const void *, void *, long unsigned int);
	void (*writesb)(volatile void *, const void *, long unsigned int);
	void (*writesw)(volatile void *, const void *, long unsigned int);
	void (*writesl)(volatile void *, const void *, long unsigned int);
	void (*insb)(long unsigned int, void *, long unsigned int);
	void (*insw)(long unsigned int, void *, long unsigned int);
	void (*insl)(long unsigned int, void *, long unsigned int);
	void (*outsb)(long unsigned int, const void *, long unsigned int);
	void (*outsw)(long unsigned int, const void *, long unsigned int);
	void (*outsl)(long unsigned int, const void *, long unsigned int);
	void (*memset_io)(volatile void *, int, long unsigned int);
	void (*memcpy_fromio)(void *, volatile const void *, long unsigned int);
	void (*memcpy_toio)(volatile void *, const void *, long unsigned int);
};

enum dev_dma_attr {
	DEV_DMA_NOT_SUPPORTED = 0,
	DEV_DMA_NON_COHERENT = 1,
	DEV_DMA_COHERENT = 2,
};

struct fwnode_reference_args;

struct fwnode_endpoint;

struct fwnode_operations {
	struct fwnode_handle * (*get)(struct fwnode_handle *);
	void (*put)(struct fwnode_handle *);
	bool (*device_is_available)(const struct fwnode_handle *);
	const void * (*device_get_match_data)(const struct fwnode_handle *, const struct device *);
	bool (*property_present)(const struct fwnode_handle *, const char *);
	int (*property_read_int_array)(const struct fwnode_handle *, const char *, unsigned int, void *, size_t);
	int (*property_read_string_array)(const struct fwnode_handle *, const char *, const char **, size_t);
	struct fwnode_handle * (*get_parent)(const struct fwnode_handle *);
	struct fwnode_handle * (*get_next_child_node)(const struct fwnode_handle *, struct fwnode_handle *);
	struct fwnode_handle * (*get_named_child_node)(const struct fwnode_handle *, const char *);
	int (*get_reference_args)(const struct fwnode_handle *, const char *, const char *, unsigned int, unsigned int, struct fwnode_reference_args *);
	struct fwnode_handle * (*graph_get_next_endpoint)(const struct fwnode_handle *, struct fwnode_handle *);
	struct fwnode_handle * (*graph_get_remote_endpoint)(const struct fwnode_handle *);
	struct fwnode_handle * (*graph_get_port_parent)(struct fwnode_handle *);
	int (*graph_parse_endpoint)(const struct fwnode_handle *, struct fwnode_endpoint *);
	int (*add_links)(struct fwnode_handle *, struct device *);
	const char * (*get_name)(const struct fwnode_handle *);
	const char * (*get_name_prefix)(const struct fwnode_handle *);
	bool (*device_dma_supported)(const struct fwnode_handle *);
	enum dev_dma_attr (*device_get_dma_attr)(const struct fwnode_handle *);
	void * (*iomap)(struct fwnode_handle *, int);
	int (*irq_get)(const struct fwnode_handle *, unsigned int);
};

struct fwnode_endpoint {
	unsigned int port;
	unsigned int id;
	const struct fwnode_handle *local_fwnode;
};

struct fwnode_reference_args {
	struct fwnode_handle *fwnode;
	unsigned int nargs;
	unsigned int args[8];
};

typedef u32 ihandle;

struct property {
	char *name;
	int length;
	void *value;
	struct property *next;
	long unsigned int _flags;
	struct bin_attribute attr;
};

struct irq_fwspec {
	struct fwnode_handle *fwnode;
	int param_count;
	u32 param[16];
};

enum irq_domain_bus_token {
	DOMAIN_BUS_ANY = 0,
	DOMAIN_BUS_WIRED = 1,
	DOMAIN_BUS_PCI_MSI = 2,
	DOMAIN_BUS_PLATFORM_MSI = 3,
	DOMAIN_BUS_NEXUS = 4,
	DOMAIN_BUS_IPI = 5,
	DOMAIN_BUS_FSL_MC_MSI = 6,
	DOMAIN_BUS_TI_SCI_INTA_MSI = 7,
	DOMAIN_BUS_WAKEUP = 8,
	DOMAIN_BUS_VMD_MSI = 9,
};

struct irq_domain_ops {
	int (*match)(struct irq_domain *, struct device_node *, enum irq_domain_bus_token);
	int (*select)(struct irq_domain *, struct irq_fwspec *, enum irq_domain_bus_token);
	int (*map)(struct irq_domain *, unsigned int, irq_hw_number_t);
	void (*unmap)(struct irq_domain *, unsigned int);
	int (*xlate)(struct irq_domain *, struct device_node *, const u32 *, unsigned int, long unsigned int *, unsigned int *);
};

struct irq_domain_chip_generic;

struct irq_domain {
	struct list_head link;
	const char *name;
	const struct irq_domain_ops *ops;
	void *host_data;
	unsigned int flags;
	unsigned int mapcount;
	struct fwnode_handle *fwnode;
	enum irq_domain_bus_token bus_token;
	struct irq_domain_chip_generic *gc;
	long unsigned int rh_reserved1;
	long unsigned int rh_reserved2;
	long unsigned int rh_reserved3;
	long unsigned int rh_reserved4;
	irq_hw_number_t hwirq_max;
	unsigned int revmap_direct_max_irq;
	unsigned int revmap_size;
	struct xarray revmap_tree;
	struct mutex revmap_tree_mutex;
	unsigned int linear_revmap[0];
};

enum irq_gc_flags {
	IRQ_GC_INIT_MASK_CACHE = 1,
	IRQ_GC_INIT_NESTED_LOCK = 2,
	IRQ_GC_MASK_CACHE_PER_TYPE = 4,
	IRQ_GC_NO_MASK = 8,
	IRQ_GC_BE_IO = 16,
};

struct irq_chip_generic;

struct irq_domain_chip_generic {
	unsigned int irqs_per_chip;
	unsigned int num_chips;
	unsigned int irq_flags_to_clear;
	unsigned int irq_flags_to_set;
	enum irq_gc_flags gc_flags;
	struct irq_chip_generic *gc[0];
};

enum irqchip_irq_state {
	IRQCHIP_STATE_PENDING = 0,
	IRQCHIP_STATE_ACTIVE = 1,
	IRQCHIP_STATE_MASKED = 2,
	IRQCHIP_STATE_LINE_LEVEL = 3,
};

struct msi_msg;

struct irq_chip {
	struct device *parent_device;
	const char *name;
	unsigned int (*irq_startup)(struct irq_data *);
	void (*irq_shutdown)(struct irq_data *);
	void (*irq_enable)(struct irq_data *);
	void (*irq_disable)(struct irq_data *);
	void (*irq_ack)(struct irq_data *);
	void (*irq_mask)(struct irq_data *);
	void (*irq_mask_ack)(struct irq_data *);
	void (*irq_unmask)(struct irq_data *);
	void (*irq_eoi)(struct irq_data *);
	int (*irq_set_affinity)(struct irq_data *, const struct cpumask *, bool);
	int (*irq_retrigger)(struct irq_data *);
	int (*irq_set_type)(struct irq_data *, unsigned int);
	int (*irq_set_wake)(struct irq_data *, unsigned int);
	void (*irq_bus_lock)(struct irq_data *);
	void (*irq_bus_sync_unlock)(struct irq_data *);
	void (*irq_cpu_online)(struct irq_data *);
	void (*irq_cpu_offline)(struct irq_data *);
	void (*irq_suspend)(struct irq_data *);
	void (*irq_resume)(struct irq_data *);
	void (*irq_pm_shutdown)(struct irq_data *);
	void (*irq_calc_mask)(struct irq_data *);
	void (*irq_print_chip)(struct irq_data *, struct seq_file *);
	int (*irq_request_resources)(struct irq_data *);
	void (*irq_release_resources)(struct irq_data *);
	void (*irq_compose_msi_msg)(struct irq_data *, struct msi_msg *);
	void (*irq_write_msi_msg)(struct irq_data *, struct msi_msg *);
	int (*irq_get_irqchip_state)(struct irq_data *, enum irqchip_irq_state, bool *);
	int (*irq_set_irqchip_state)(struct irq_data *, enum irqchip_irq_state, bool);
	int (*irq_set_vcpu_affinity)(struct irq_data *, void *);
	void (*ipi_send_single)(struct irq_data *, unsigned int);
	void (*ipi_send_mask)(struct irq_data *, const struct cpumask *);
	long unsigned int flags;
};

typedef irqreturn_t (*irq_handler_t)(int, void *);

struct irqaction {
	irq_handler_t handler;
	void *dev_id;
	void *percpu_dev_id;
	struct irqaction *next;
	irq_handler_t thread_fn;
	struct task_struct *thread;
	struct irqaction *secondary;
	unsigned int irq;
	unsigned int flags;
	long unsigned int thread_flags;
	long unsigned int thread_mask;
	const char *name;
	struct proc_dir_entry *dir;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
};

struct irq_affinity_notify {
	unsigned int irq;
	struct kref kref;
	struct work_struct work;
	void (*notify)(struct irq_affinity_notify *, const cpumask_t *);
	void (*release)(struct kref *);
};

struct irq_chip_regs {
	long unsigned int enable;
	long unsigned int disable;
	long unsigned int mask;
	long unsigned int ack;
	long unsigned int eoi;
	long unsigned int type;
	long unsigned int polarity;
};

struct irq_chip_type {
	struct irq_chip chip;
	struct irq_chip_regs regs;
	irq_flow_handler_t handler;
	u32 type;
	u32 mask_cache_priv;
	u32 *mask_cache;
};

struct irq_chip_generic {
	raw_spinlock_t lock;
	void *reg_base;
	u32 (*reg_readl)(void *);
	void (*reg_writel)(u32, void *);
	void (*suspend)(struct irq_chip_generic *);
	void (*resume)(struct irq_chip_generic *);
	unsigned int irq_base;
	unsigned int irq_cnt;
	u32 mask_cache;
	u32 type_cache;
	u32 polarity_cache;
	u32 wake_enabled;
	u32 wake_active;
	unsigned int num_ct;
	void *private;
	long unsigned int installed;
	long unsigned int unused;
	struct irq_domain *domain;
	struct list_head list;
	struct irq_chip_type chip_types[0];
};

typedef struct {
	unsigned int __softirq_pending;
	unsigned int timer_irqs_event;
	unsigned int broadcast_irqs_event;
	unsigned int timer_irqs_others;
	unsigned int pmu_irqs;
	unsigned int mce_exceptions;
	unsigned int spurious_irqs;
	unsigned int sreset_irqs;
	unsigned int soft_nmi_irqs;
	unsigned int doorbell_irqs;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
} irq_cpustat_t;

typedef __u64 Elf64_Addr;

typedef __u64 Elf64_Xword;

typedef __s64 Elf64_Sxword;

typedef struct {
	Elf64_Sxword d_tag;
	union {
		Elf64_Xword d_val;
		Elf64_Addr d_ptr;
	} d_un;
} Elf64_Dyn;

struct ppc64_tlb_batch {
	int active;
	long unsigned int index;
	struct mm_struct *mm;
	real_pte_t pte[192];
	long unsigned int vpn[192];
	unsigned int psize;
	int ssize;
};

struct hotplug_slot;

struct pci_slot {
	struct pci_bus *bus;
	struct list_head list;
	struct hotplug_slot *hotplug;
	unsigned char number;
	struct kobject kobj;
};

enum pci_channel_state {
	pci_channel_io_normal = 1,
	pci_channel_io_frozen = 2,
	pci_channel_io_perm_failure = 3,
};

struct pci_dynids {
	spinlock_t lock;
	struct list_head list;
};

struct pci_error_handlers;

struct pci_driver {
	struct list_head node;
	const char *name;
	const struct pci_device_id *id_table;
	int (*probe)(struct pci_dev *, const struct pci_device_id *);
	void (*remove)(struct pci_dev *);
	int (*suspend)(struct pci_dev *, pm_message_t);
	int (*rh_reserved_suspend_late)(struct pci_dev *, pm_message_t);
	int (*rh_reserved_resume_early)(struct pci_dev *);
	int (*resume)(struct pci_dev *);
	void (*shutdown)(struct pci_dev *);
	int (*sriov_configure)(struct pci_dev *, int);
	union {
		int (*sriov_set_msix_vec_count)(struct pci_dev *, int);
		struct {
			long unsigned int rh_reserved1;
		} rh_kabi_hidden_958;
		union {		};
	};
	union {
		u32 (*sriov_get_vf_total_msix)(struct pci_dev *);
		struct {
			long unsigned int rh_reserved2;
		} rh_kabi_hidden_959;
		union {		};
	};
	long unsigned int rh_reserved3;
	long unsigned int rh_reserved4;
	const struct pci_error_handlers *err_handler;
	const struct attribute_group **groups;
	struct device_driver driver;
	struct pci_dynids dynids;
	union {
		const struct attribute_group **dev_groups;
		struct {
			long unsigned int rh_reserved5;
		} rh_kabi_hidden_968;
		union {		};
	};
	long unsigned int rh_reserved6;
	long unsigned int rh_reserved7;
	long unsigned int rh_reserved8;
};

struct pci_host_bridge {
	struct device dev;
	struct pci_bus *bus;
	struct pci_ops *ops;
	void *sysdata;
	int busnr;
	int domain_nr;
	struct list_head windows;
	struct list_head dma_ranges;
	u8 (*swizzle_irq)(struct pci_dev *, u8 *);
	int (*map_irq)(const struct pci_dev *, u8, u8);
	void (*release_fn)(struct pci_host_bridge *);
	void *release_data;
	struct msi_controller *msi;
	unsigned int ignore_reset_delay: 1;
	unsigned int no_ext_tags: 1;
	unsigned int native_aer: 1;
	unsigned int native_pcie_hotplug: 1;
	unsigned int native_shpc_hotplug: 1;
	unsigned int native_pme: 1;
	unsigned int native_ltr: 1;
	unsigned int native_dpc: 1;
	unsigned int preserve_config: 1;
	unsigned int size_windows: 1;
	resource_size_t (*align_resource)(struct pci_dev *, const struct resource *, resource_size_t, resource_size_t, resource_size_t);
	long: 64;
	long: 64;
	long: 64;
	long unsigned int private[0];
};

struct pci_ops {
	int (*add_bus)(struct pci_bus *);
	void (*remove_bus)(struct pci_bus *);
	void * (*map_bus)(struct pci_bus *, unsigned int, int);
	int (*read)(struct pci_bus *, unsigned int, int, int, u32 *);
	int (*write)(struct pci_bus *, unsigned int, int, int, u32);
};

typedef unsigned int pci_ers_result_t;

struct pci_error_handlers {
	pci_ers_result_t (*error_detected)(struct pci_dev *, enum pci_channel_state);
	pci_ers_result_t (*mmio_enabled)(struct pci_dev *);
	pci_ers_result_t (*slot_reset)(struct pci_dev *);
	void (*reset_prepare)(struct pci_dev *);
	void (*reset_done)(struct pci_dev *);
	void (*resume)(struct pci_dev *);
};

enum pcie_bus_config_types {
	PCIE_BUS_TUNE_OFF = 0,
	PCIE_BUS_DEFAULT = 1,
	PCIE_BUS_SAFE = 2,
	PCIE_BUS_PERFORMANCE = 3,
	PCIE_BUS_PEER2PEER = 4,
};

struct shrink_control {
	gfp_t gfp_mask;
	long unsigned int nr_to_scan;
	long unsigned int nr_scanned;
	int nid;
	struct mem_cgroup *memcg;
};

struct shrinker {
	long unsigned int (*count_objects)(struct shrinker *, struct shrink_control *);
	long unsigned int (*scan_objects)(struct shrinker *, struct shrink_control *);
	int seeks;
	int id;
	long int batch;
	long unsigned int flags;
	struct list_head list;
	atomic_long_t *nr_deferred;
};

struct tracepoint_func {
	void *func;
	void *data;
	int prio;
};

struct tracepoint {
	const char *name;
	struct static_key key;
	int (*regfunc)();
	void (*unregfunc)();
	struct tracepoint_func *funcs;
};

struct dev_pagemap_ops {
	void (*page_free)(struct page *);
	void (*kill)(struct dev_pagemap *);
	void (*cleanup)(struct dev_pagemap *);
	vm_fault_t (*migrate_to_ram)(struct vm_fault *);
};

struct hlist_bl_node;

struct hlist_bl_head {
	struct hlist_bl_node *first;
};

struct hlist_bl_node {
	struct hlist_bl_node *next;
	struct hlist_bl_node **pprev;
};

struct lockref {
	union {
		__u64 lock_count;
		struct {
			spinlock_t lock;
			int count;
		};
	};
};

struct qstr {
	union {
		struct {
			u32 hash;
			u32 len;
		};
		u64 hash_len;
	};
	const unsigned char *name;
};

struct dentry_stat_t {
	long int nr_dentry;
	long int nr_unused;
	long int age_limit;
	long int want_pages;
	long int nr_negative;
	long int dummy;
};

struct dentry_operations;

struct dentry {
	unsigned int d_flags;
	seqcount_t d_seq;
	struct hlist_bl_node d_hash;
	struct dentry *d_parent;
	struct qstr d_name;
	struct inode *d_inode;
	unsigned char d_iname[32];
	struct lockref d_lockref;
	const struct dentry_operations *d_op;
	struct super_block *d_sb;
	long unsigned int d_time;
	void *d_fsdata;
	union {
		struct list_head d_lru;
		wait_queue_head_t *d_wait;
	};
	struct list_head d_child;
	struct list_head d_subdirs;
	union {
		struct hlist_node d_alias;
		struct hlist_bl_node d_in_lookup_hash;
		struct callback_head d_rcu;
	} d_u;
};

struct posix_acl;

struct inode_operations;

struct bdi_writeback;

struct file_lock_context;

struct block_device;

struct cdev;

struct fsnotify_mark_connector;

struct inode {
	umode_t i_mode;
	short unsigned int i_opflags;
	kuid_t i_uid;
	kgid_t i_gid;
	unsigned int i_flags;
	struct posix_acl *i_acl;
	struct posix_acl *i_default_acl;
	const struct inode_operations *i_op;
	struct super_block *i_sb;
	struct address_space *i_mapping;
	void *i_security;
	long unsigned int i_ino;
	union {
		const unsigned int i_nlink;
		unsigned int __i_nlink;
	};
	dev_t i_rdev;
	loff_t i_size;
	struct timespec64 i_atime;
	struct timespec64 i_mtime;
	struct timespec64 i_ctime;
	spinlock_t i_lock;
	short unsigned int i_bytes;
	unsigned int i_blkbits;
	enum rw_hint i_write_hint;
	blkcnt_t i_blocks;
	long unsigned int i_state;
	struct rw_semaphore i_rwsem;
	long unsigned int dirtied_when;
	long unsigned int dirtied_time_when;
	struct hlist_node i_hash;
	struct list_head i_io_list;
	struct bdi_writeback *i_wb;
	int i_wb_frn_winner;
	u16 i_wb_frn_avg_time;
	u16 i_wb_frn_history;
	struct list_head i_lru;
	struct list_head i_sb_list;
	struct list_head i_wb_list;
	union {
		struct hlist_head i_dentry;
		struct callback_head i_rcu;
	};
	atomic64_t i_version;
	atomic_t i_count;
	atomic_t i_dio_count;
	atomic_t i_writecount;
	atomic_t i_readcount;
	const struct file_operations *i_fop;
	struct file_lock_context *i_flctx;
	struct address_space i_data;
	struct list_head i_devices;
	union {
		struct pipe_inode_info *i_pipe;
		struct block_device *i_bdev;
		struct cdev *i_cdev;
		char *i_link;
		unsigned int i_dir_seq;
	};
	__u32 i_generation;
	__u32 i_fsnotify_mask;
	struct fsnotify_mark_connector *i_fsnotify_marks;
	void *i_private;
	union {
		atomic64_t i_sequence;
		struct {
			long unsigned int rh_reserved1;
		} rh_kabi_hidden_747;
		union {		};
	};
	long unsigned int rh_reserved2;
};

struct dentry_operations {
	int (*d_revalidate)(struct dentry *, unsigned int);
	int (*d_weak_revalidate)(struct dentry *, unsigned int);
	int (*d_hash)(const struct dentry *, struct qstr *);
	int (*d_compare)(const struct dentry *, unsigned int, const char *, const struct qstr *);
	int (*d_delete)(const struct dentry *);
	int (*d_init)(struct dentry *);
	void (*d_release)(struct dentry *);
	void (*d_prune)(struct dentry *);
	void (*d_iput)(struct dentry *, struct inode *);
	char * (*d_dname)(struct dentry *, char *, int);
	struct vfsmount * (*d_automount)(struct path *);
	int (*d_manage)(const struct path *, bool);
	struct dentry * (*d_real)(struct dentry *, const struct inode *);
	long unsigned int rh_reserved1;
	long unsigned int rh_reserved2;
	long unsigned int rh_reserved3;
	long unsigned int rh_reserved4;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
};

struct mtd_info;

typedef long long int qsize_t;

struct quota_format_type;

struct mem_dqinfo {
	struct quota_format_type *dqi_format;
	int dqi_fmt_id;
	struct list_head dqi_dirty_list;
	long unsigned int dqi_flags;
	unsigned int dqi_bgrace;
	unsigned int dqi_igrace;
	qsize_t dqi_max_spc_limit;
	qsize_t dqi_max_ino_limit;
	void *dqi_priv;
};

struct quota_format_ops;

struct quota_info {
	unsigned int flags;
	struct rw_semaphore dqio_sem;
	struct inode *files[3];
	struct mem_dqinfo info[3];
	const struct quota_format_ops *ops[3];
};

enum rcu_sync_type {
	RCU_SYNC = 0,
	RCU_SCHED_SYNC = 1,
	RCU_BH_SYNC = 2,
};

struct rcu_sync {
	int gp_state;
	int gp_count;
	wait_queue_head_t gp_wait;
	int rh_reserved_cb_state;
	struct callback_head cb_head;
	enum rcu_sync_type rh_reserved_gp_type;
};

struct rcuwait {
	struct task_struct *task;
};

struct percpu_rw_semaphore {
	struct rcu_sync rss;
	unsigned int *read_count;
	union {
		wait_queue_head_t waiters;
		struct {
			struct rw_semaphore rw_sem;
		} rh_kabi_hidden_18;
		union {		};
	};
	struct rcuwait writer;
	union {
		atomic_t block;
		struct {
			int readers_block;
		} rh_kabi_hidden_21;
		union {		};
	};
};

struct sb_writers {
	int frozen;
	wait_queue_head_t wait_unfrozen;
	struct percpu_rw_semaphore rw_sem[3];
};

struct list_lru_node;

struct list_lru {
	struct list_lru_node *node;
	struct list_head list;
	int shrinker_id;
	bool memcg_aware;
};

struct super_operations;

struct dquot_operations;

struct quotactl_ops;

struct export_operations;

struct xattr_handler;

struct workqueue_struct;

struct super_block {
	struct list_head s_list;
	dev_t s_dev;
	unsigned char s_blocksize_bits;
	long unsigned int s_blocksize;
	loff_t s_maxbytes;
	struct file_system_type *s_type;
	const struct super_operations *s_op;
	const struct dquot_operations *dq_op;
	const struct quotactl_ops *s_qcop;
	const struct export_operations *s_export_op;
	long unsigned int s_flags;
	long unsigned int s_iflags;
	long unsigned int s_magic;
	struct dentry *s_root;
	struct rw_semaphore s_umount;
	int s_count;
	atomic_t s_active;
	void *s_security;
	const struct xattr_handler **s_xattr;
	struct hlist_bl_head s_roots;
	struct list_head s_mounts;
	struct block_device *s_bdev;
	struct backing_dev_info *s_bdi;
	struct mtd_info *s_mtd;
	struct hlist_node s_instances;
	unsigned int s_quota_types;
	struct quota_info s_dquot;
	struct sb_writers s_writers;
	char s_id[32];
	uuid_t s_uuid;
	void *s_fs_info;
	unsigned int s_max_links;
	fmode_t s_mode;
	u32 s_time_gran;
	union {
		struct {
			__u32 s_fsnotify_mask;
			struct fsnotify_mark_connector *s_fsnotify_marks;
		};
		struct {
			struct mutex s_vfs_rename_mutex;
		} rh_kabi_hidden_1495;
		union {		};
	};
	const char *s_subtype;
	const struct dentry_operations *s_d_op;
	int cleancache_poolid;
	struct shrinker s_shrink;
	atomic_long_t s_remove_count;
	atomic_long_t s_fsnotify_inode_refs;
	int s_readonly_remount;
	struct workqueue_struct *s_dio_done_wq;
	struct hlist_head s_pins;
	struct user_namespace *s_user_ns;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	struct list_lru s_dentry_lru;
	struct list_lru s_inode_lru;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long int rh_reserve_1;
	long int rh_reserve_2;
	long int rh_reserve_3;
	struct callback_head rcu;
	struct work_struct destroy_work;
	struct mutex s_sync_lock;
	int s_stack_depth;
	long: 32;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	spinlock_t s_inode_list_lock;
	struct list_head s_inodes;
	spinlock_t s_inode_wblist_lock;
	struct list_head s_inodes_wb;
	time64_t s_time_min;
	time64_t s_time_max;
	struct mutex s_vfs_rename_mutex;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
};

struct list_lru_one {
	struct list_head list;
	long int nr_items;
};

struct list_lru_memcg {
	struct callback_head rcu;
	struct list_lru_one *lru[0];
};

struct list_lru_node {
	spinlock_t lock;
	struct list_lru_one lru;
	struct list_lru_memcg *memcg_lrus;
	long int nr_items;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
};

struct fiemap_extent {
	__u64 fe_logical;
	__u64 fe_physical;
	__u64 fe_length;
	__u64 fe_reserved64[2];
	__u32 fe_flags;
	__u32 fe_reserved[3];
};

enum migrate_mode {
	MIGRATE_ASYNC = 0,
	MIGRATE_SYNC_LIGHT = 1,
	MIGRATE_SYNC = 2,
	MIGRATE_SYNC_NO_COPY = 3,
};

struct ctl_table;

typedef int proc_handler(struct ctl_table *, int, void *, size_t *, loff_t *);

struct ctl_table_poll;

struct ctl_table {
	const char *procname;
	void *data;
	int maxlen;
	umode_t mode;
	struct ctl_table *child;
	proc_handler *proc_handler;
	struct ctl_table_poll *poll;
	void *extra1;
	void *extra2;
};

struct ctl_table_poll {
	atomic_t event;
	wait_queue_head_t wait;
};

struct assoc_array_ptr;

struct assoc_array {
	struct assoc_array_ptr *root;
	long unsigned int nr_leaves_on_tree;
};

typedef int32_t key_serial_t;

typedef uint32_t key_perm_t;

struct key_type;

struct keyring_index_key {
	struct key_type *type;
	const char *description;
	size_t desc_len;
};

struct key_construction;

typedef int (*request_key_actor_t)(struct key_construction *, const char *, void *);

struct key_preparsed_payload;

struct key_match_data;

struct key_restriction;

struct key_type {
	const char *name;
	size_t def_datalen;
	int (*vet_description)(const char *);
	int (*preparse)(struct key_preparsed_payload *);
	void (*free_preparse)(struct key_preparsed_payload *);
	int (*instantiate)(struct key *, struct key_preparsed_payload *);
	int (*update)(struct key *, struct key_preparsed_payload *);
	int (*match_preparse)(struct key_match_data *);
	void (*match_free)(struct key_match_data *);
	void (*revoke)(struct key *);
	void (*destroy)(struct key *);
	void (*describe)(const struct key *, struct seq_file *);
	long int (*read)(const struct key *, char *, size_t);
	request_key_actor_t request_key;
	struct key_restriction * (*lookup_restriction)(const char *);
	struct list_head link;
	struct lock_class_key lock_class;
};

union key_payload {
	void *rcu_data0;
	void *data[4];
};

typedef int (*key_restrict_link_func_t)(struct key *, const struct key_type *, const union key_payload *, struct key *);

struct key_user;

struct key {
	refcount_t usage;
	key_serial_t serial;
	union {
		struct list_head graveyard_link;
		struct rb_node serial_node;
	};
	struct rw_semaphore sem;
	struct key_user *user;
	void *security;
	union {
		time64_t expiry;
		time64_t revoked_at;
	};
	time64_t last_used_at;
	kuid_t uid;
	kgid_t gid;
	key_perm_t perm;
	short unsigned int quotalen;
	short unsigned int datalen;
	short int state;
	long unsigned int flags;
	union {
		struct keyring_index_key index_key;
		struct {
			struct key_type *type;
			char *description;
		};
	};
	union {
		union key_payload payload;
		struct {
			struct list_head name_link;
			struct assoc_array keys;
		};
	};
	struct key_restriction *restrict_link;
};

struct key_restriction {
	key_restrict_link_func_t check;
	struct key *key;
	struct key_type *keytype;
};

struct group_info {
	atomic_t usage;
	int ngroups;
	kgid_t gid[0];
};

struct delayed_call {
	void (*fn)(void *);
	void *arg;
};

struct io_cq {
	struct request_queue *q;
	struct io_context *ioc;
	union {
		struct list_head q_node;
		struct kmem_cache *__rcu_icq_cache;
	};
	union {
		struct hlist_node ioc_node;
		struct callback_head __rcu_head;
	};
	unsigned int flags;
};

struct files_stat_struct {
	long unsigned int nr_files;
	long unsigned int nr_free_files;
	long unsigned int max_files;
};

struct inodes_stat_t {
	long int nr_inodes;
	long int nr_unused;
	long int dummy[5];
};

struct kiocb {
	struct file *ki_filp;
	loff_t ki_pos;
	void (*ki_complete)(struct kiocb *, long int, long int);
	void *private;
	int ki_flags;
	u16 ki_hint;
	u16 ki_ioprio;
	unsigned int ki_cookie;
};

struct iattr {
	unsigned int ia_valid;
	umode_t ia_mode;
	kuid_t ia_uid;
	kgid_t ia_gid;
	loff_t ia_size;
	struct timespec64 ia_atime;
	struct timespec64 ia_mtime;
	struct timespec64 ia_ctime;
	struct file *ia_file;
};

struct percpu_counter {
	raw_spinlock_t lock;
	s64 count;
	struct list_head list;
	s32 *counters;
};

typedef __kernel_uid32_t projid_t;

typedef struct {
	projid_t val;
} kprojid_t;

enum quota_type {
	USRQUOTA = 0,
	GRPQUOTA = 1,
	PRJQUOTA = 2,
};

struct kqid {
	union {
		kuid_t uid;
		kgid_t gid;
		kprojid_t projid;
	};
	enum quota_type type;
};

struct mem_dqblk {
	qsize_t dqb_bhardlimit;
	qsize_t dqb_bsoftlimit;
	qsize_t dqb_curspace;
	qsize_t dqb_rsvspace;
	qsize_t dqb_ihardlimit;
	qsize_t dqb_isoftlimit;
	qsize_t dqb_curinodes;
	time64_t dqb_btime;
	time64_t dqb_itime;
};

struct dquot {
	struct hlist_node dq_hash;
	struct list_head dq_inuse;
	struct list_head dq_free;
	struct list_head dq_dirty;
	struct mutex dq_lock;
	spinlock_t dq_dqb_lock;
	atomic_t dq_count;
	struct super_block *dq_sb;
	struct kqid dq_id;
	loff_t dq_off;
	long unsigned int dq_flags;
	struct mem_dqblk dq_dqb;
};

struct quota_format_type {
	int qf_fmt_id;
	const struct quota_format_ops *qf_ops;
	struct module *qf_owner;
	struct quota_format_type *qf_next;
};

struct dqstats {
	int stat[8];
	struct percpu_counter counter[8];
};

struct quota_format_ops {
	int (*check_quota_file)(struct super_block *, int);
	int (*read_file_info)(struct super_block *, int);
	int (*write_file_info)(struct super_block *, int);
	int (*free_file_info)(struct super_block *, int);
	int (*read_dqblk)(struct dquot *);
	int (*commit_dqblk)(struct dquot *);
	int (*release_dqblk)(struct dquot *);
	int (*get_next_id)(struct super_block *, struct kqid *);
	long unsigned int rh_reserved1;
	long unsigned int rh_reserved2;
};

struct dquot_operations {
	int (*write_dquot)(struct dquot *);
	struct dquot * (*alloc_dquot)(struct super_block *, int);
	void (*destroy_dquot)(struct dquot *);
	int (*acquire_dquot)(struct dquot *);
	int (*release_dquot)(struct dquot *);
	int (*mark_dirty)(struct dquot *);
	int (*write_info)(struct super_block *, int);
	qsize_t * (*get_reserved_space)(struct inode *);
	int (*get_projid)(struct inode *, kprojid_t *);
	int (*get_inode_usage)(struct inode *, qsize_t *);
	int (*get_next_id)(struct super_block *, struct kqid *);
	long unsigned int rh_reserved1;
	long unsigned int rh_reserved2;
};

struct qc_dqblk {
	int d_fieldmask;
	u64 d_spc_hardlimit;
	u64 d_spc_softlimit;
	u64 d_ino_hardlimit;
	u64 d_ino_softlimit;
	u64 d_space;
	u64 d_ino_count;
	s64 d_ino_timer;
	s64 d_spc_timer;
	int d_ino_warns;
	int d_spc_warns;
	u64 d_rt_spc_hardlimit;
	u64 d_rt_spc_softlimit;
	u64 d_rt_space;
	s64 d_rt_spc_timer;
	int d_rt_spc_warns;
};

struct qc_type_state {
	unsigned int flags;
	unsigned int spc_timelimit;
	unsigned int ino_timelimit;
	unsigned int rt_spc_timelimit;
	unsigned int spc_warnlimit;
	unsigned int ino_warnlimit;
	unsigned int rt_spc_warnlimit;
	long long unsigned int ino;
	blkcnt_t blocks;
	blkcnt_t nextents;
};

struct qc_state {
	unsigned int s_incoredqs;
	struct qc_type_state s_state[3];
};

struct qc_info {
	int i_fieldmask;
	unsigned int i_flags;
	unsigned int i_spc_timelimit;
	unsigned int i_ino_timelimit;
	unsigned int i_rt_spc_timelimit;
	unsigned int i_spc_warnlimit;
	unsigned int i_ino_warnlimit;
	unsigned int i_rt_spc_warnlimit;
};

struct quotactl_ops {
	int (*quota_on)(struct super_block *, int, int, const struct path *);
	int (*quota_off)(struct super_block *, int);
	int (*quota_enable)(struct super_block *, unsigned int);
	int (*quota_disable)(struct super_block *, unsigned int);
	int (*quota_sync)(struct super_block *, int);
	int (*set_info)(struct super_block *, int, struct qc_info *);
	int (*get_dqblk)(struct super_block *, struct kqid, struct qc_dqblk *);
	int (*get_nextdqblk)(struct super_block *, struct kqid *, struct qc_dqblk *);
	int (*set_dqblk)(struct super_block *, struct kqid, struct qc_dqblk *);
	int (*get_state)(struct super_block *, struct qc_state *);
	int (*rm_xquota)(struct super_block *, unsigned int);
	long unsigned int rh_reserved1;
	long unsigned int rh_reserved2;
	long unsigned int rh_reserved3;
	long unsigned int rh_reserved4;
};

struct writeback_control;

struct swap_info_struct;

struct readahead_control;

struct address_space_operations {
	int (*writepage)(struct page *, struct writeback_control *);
	int (*readpage)(struct file *, struct page *);
	int (*writepages)(struct address_space *, struct writeback_control *);
	int (*set_page_dirty)(struct page *);
	int (*readpages)(struct file *, struct address_space *, struct list_head *, unsigned int);
	int (*write_begin)(struct file *, struct address_space *, loff_t, unsigned int, unsigned int, struct page **, void **);
	int (*write_end)(struct file *, struct address_space *, loff_t, unsigned int, unsigned int, struct page *, void *);
	sector_t (*bmap)(struct address_space *, sector_t);
	void (*invalidatepage)(struct page *, unsigned int, unsigned int);
	int (*releasepage)(struct page *, gfp_t);
	void (*freepage)(struct page *);
	ssize_t (*direct_IO)(struct kiocb *, struct iov_iter *);
	int (*migratepage)(struct address_space *, struct page *, struct page *, enum migrate_mode);
	bool (*isolate_page)(struct page *, isolate_mode_t);
	void (*putback_page)(struct page *);
	int (*launder_page)(struct page *);
	int (*is_partially_uptodate)(struct page *, long unsigned int, long unsigned int);
	void (*is_dirty_writeback)(struct page *, bool *, bool *);
	int (*error_remove_page)(struct address_space *, struct page *);
	int (*swap_activate)(struct swap_info_struct *, struct file *, sector_t *);
	void (*swap_deactivate)(struct file *);
	union {
		void (*readahead)(struct readahead_control *);
		struct {
			long unsigned int rh_reserved1;
		} rh_kabi_hidden_405;
		union {		};
	};
	long unsigned int rh_reserved2;
	long unsigned int rh_reserved3;
	long unsigned int rh_reserved4;
};

struct hd_struct;

struct gendisk;

struct block_device {
	dev_t bd_dev;
	int bd_openers;
	struct inode *bd_inode;
	struct super_block *bd_super;
	struct mutex bd_mutex;
	void *bd_claiming;
	void *bd_holder;
	int bd_holders;
	bool bd_write_holder;
	struct list_head bd_holder_disks;
	struct block_device *bd_contains;
	unsigned int bd_block_size;
	u8 bd_partno;
	struct hd_struct *bd_part;
	unsigned int bd_part_count;
	int bd_invalidated;
	struct gendisk *bd_disk;
	struct request_queue *bd_queue;
	struct backing_dev_info *bd_bdi;
	struct list_head bd_list;
	long unsigned int bd_private;
	int bd_fsfreeze_count;
	struct mutex bd_fsfreeze_mutex;
	union {
		spinlock_t bd_size_lock;
		struct {
			long unsigned int rh_reserved1;
		} rh_kabi_hidden_501;
		union {		};
	};
	long unsigned int rh_reserved2;
	long unsigned int rh_reserved3;
	long unsigned int rh_reserved4;
};

struct fiemap_extent_info;

struct inode_operations {
	struct dentry * (*lookup)(struct inode *, struct dentry *, unsigned int);
	const char * (*get_link)(struct dentry *, struct inode *, struct delayed_call *);
	int (*permission)(struct inode *, int);
	struct posix_acl * (*get_acl)(struct inode *, int);
	int (*readlink)(struct dentry *, char *, int);
	int (*create)(struct inode *, struct dentry *, umode_t, bool);
	int (*link)(struct dentry *, struct inode *, struct dentry *);
	int (*unlink)(struct inode *, struct dentry *);
	int (*symlink)(struct inode *, struct dentry *, const char *);
	int (*mkdir)(struct inode *, struct dentry *, umode_t);
	int (*rmdir)(struct inode *, struct dentry *);
	int (*mknod)(struct inode *, struct dentry *, umode_t, dev_t);
	int (*rename)(struct inode *, struct dentry *, struct inode *, struct dentry *, unsigned int);
	int (*setattr)(struct dentry *, struct iattr *);
	int (*getattr)(const struct path *, struct kstat *, u32, unsigned int);
	ssize_t (*listxattr)(struct dentry *, char *, size_t);
	int (*fiemap)(struct inode *, struct fiemap_extent_info *, u64, u64);
	int (*update_time)(struct inode *, struct timespec64 *, int);
	int (*atomic_open)(struct inode *, struct dentry *, struct file *, unsigned int, umode_t, int *);
	int (*tmpfile)(struct inode *, struct dentry *, umode_t);
	int (*set_acl)(struct inode *, struct posix_acl *, int);
	long unsigned int rh_reserved1;
	long unsigned int rh_reserved2;
	long unsigned int rh_reserved3;
	long unsigned int rh_reserved4;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
};

struct file_lock_context {
	spinlock_t flc_lock;
	struct list_head flc_flock;
	struct list_head flc_posix;
	struct list_head flc_lease;
};

struct file_lock_operations {
	void (*fl_copy_lock)(struct file_lock *, struct file_lock *);
	void (*fl_release_private)(struct file_lock *);
	long unsigned int rh_reserved1;
	long unsigned int rh_reserved2;
};

struct nlm_lockowner;

struct nfs_lock_info {
	u32 state;
	struct nlm_lockowner *owner;
	struct list_head list;
};

struct nfs4_lock_state;

struct nfs4_lock_info {
	struct nfs4_lock_state *owner;
};

struct fasync_struct;

struct lock_manager_operations;

struct file_lock {
	struct file_lock *fl_next;
	struct list_head fl_list;
	struct hlist_node fl_link;
	struct list_head fl_block;
	struct list_head rh_reserved1;
	fl_owner_t fl_owner;
	unsigned int fl_flags;
	unsigned char fl_type;
	unsigned int fl_pid;
	int fl_link_cpu;
	wait_queue_head_t fl_wait;
	struct file *fl_file;
	loff_t fl_start;
	loff_t fl_end;
	struct fasync_struct *fl_fasync;
	long unsigned int fl_break_time;
	long unsigned int fl_downgrade_time;
	const struct file_lock_operations *fl_ops;
	const struct lock_manager_operations *fl_lmops;
	union {
		struct nfs_lock_info nfs_fl;
		struct nfs4_lock_info nfs4_fl;
		struct {
			struct list_head link;
			int state;
		} afs;
	} fl_u;
};

struct lock_manager_operations {
	int (*lm_compare_owner)(struct file_lock *, struct file_lock *);
	long unsigned int (*lm_owner_key)(struct file_lock *);
	fl_owner_t (*lm_get_owner)(fl_owner_t);
	void (*lm_put_owner)(fl_owner_t);
	void (*lm_notify)(struct file_lock *);
	int (*lm_grant)(struct file_lock *, int);
	bool (*lm_break)(struct file_lock *);
	int (*lm_change)(struct file_lock *, int, struct list_head *);
	void (*lm_setup)(struct file_lock *, void **);
	union {
		bool (*lm_breaker_owns_lease)(struct file_lock *);
		struct {
			long unsigned int rh_reserved1;
		} rh_kabi_hidden_1047;
		union {		};
	};
	long unsigned int rh_reserved2;
};

struct fasync_struct {
	rwlock_t fa_lock;
	int magic;
	int fa_fd;
	struct fasync_struct *fa_next;
	struct file *fa_file;
	struct callback_head fa_rcu;
};

struct kstatfs;

struct super_operations {
	struct inode * (*alloc_inode)(struct super_block *);
	void (*destroy_inode)(struct inode *);
	void (*dirty_inode)(struct inode *, int);
	int (*write_inode)(struct inode *, struct writeback_control *);
	int (*drop_inode)(struct inode *);
	void (*evict_inode)(struct inode *);
	void (*put_super)(struct super_block *);
	int (*sync_fs)(struct super_block *, int);
	int (*freeze_super)(struct super_block *);
	int (*freeze_fs)(struct super_block *);
	int (*thaw_super)(struct super_block *);
	int (*unfreeze_fs)(struct super_block *);
	int (*statfs)(struct dentry *, struct kstatfs *);
	int (*remount_fs)(struct super_block *, int *, char *);
	void (*umount_begin)(struct super_block *);
	int (*show_options)(struct seq_file *, struct dentry *);
	int (*show_devname)(struct seq_file *, struct dentry *);
	int (*show_path)(struct seq_file *, struct dentry *);
	int (*show_stats)(struct seq_file *, struct dentry *);
	ssize_t (*quota_read)(struct super_block *, int, char *, size_t, loff_t);
	ssize_t (*quota_write)(struct super_block *, int, const char *, size_t, loff_t);
	struct dquot ** (*get_dquots)(struct inode *);
	int (*bdev_try_to_free_page)(struct super_block *, struct page *, gfp_t);
	long int (*nr_cached_objects)(struct super_block *, struct shrink_control *);
	long int (*free_cached_objects)(struct super_block *, struct shrink_control *);
	long unsigned int rh_reserved1;
	long unsigned int rh_reserved2;
	long unsigned int rh_reserved3;
	long unsigned int rh_reserved4;
};

struct iomap;

struct fid;

struct export_operations {
	int (*encode_fh)(struct inode *, __u32 *, int *, struct inode *);
	struct dentry * (*fh_to_dentry)(struct super_block *, struct fid *, int, int);
	struct dentry * (*fh_to_parent)(struct super_block *, struct fid *, int, int);
	int (*get_name)(struct dentry *, char *, struct dentry *);
	struct dentry * (*get_parent)(struct dentry *);
	int (*commit_metadata)(struct inode *);
	int (*get_uuid)(struct super_block *, u8 *, u32 *, u64 *);
	int (*map_blocks)(struct inode *, loff_t, u64, struct iomap *, bool, u32 *);
	int (*commit_blocks)(struct inode *, struct iomap *, int, struct iattr *);
};

struct xattr_handler {
	const char *name;
	const char *prefix;
	int flags;
	bool (*list)(struct dentry *);
	int (*get)(const struct xattr_handler *, struct dentry *, struct inode *, const char *, void *, size_t);
	int (*set)(const struct xattr_handler *, struct dentry *, struct inode *, const char *, const void *, size_t, int);
};

struct fiemap_extent_info {
	unsigned int fi_flags;
	unsigned int fi_extents_mapped;
	unsigned int fi_extents_max;
	struct fiemap_extent *fi_extents_start;
};

typedef int (*filldir_t)(struct dir_context *, const char *, int, loff_t, u64, unsigned int);

struct dir_context {
	filldir_t actor;
	loff_t pos;
};

struct p_log;

struct fs_parameter;

struct fs_parse_result;

typedef int fs_param_type(struct p_log *, const struct fs_parameter_spec *, struct fs_parameter *, struct fs_parse_result *);

struct fs_parameter_spec {
	const char *name;
	fs_param_type *type;
	u8 opt;
	short unsigned int flags;
	const void *data;
};

typedef void compound_page_dtor(struct page *);

enum vm_event_item {
	PGPGIN = 0,
	PGPGOUT = 1,
	PSWPIN = 2,
	PSWPOUT = 3,
	PGALLOC_DMA = 4,
	PGALLOC_DMA32 = 5,
	PGALLOC_NORMAL = 6,
	PGALLOC_MOVABLE = 7,
	ALLOCSTALL_DMA = 8,
	ALLOCSTALL_DMA32 = 9,
	ALLOCSTALL_NORMAL = 10,
	ALLOCSTALL_MOVABLE = 11,
	PGSCAN_SKIP_DMA = 12,
	PGSCAN_SKIP_DMA32 = 13,
	PGSCAN_SKIP_NORMAL = 14,
	PGSCAN_SKIP_MOVABLE = 15,
	PGFREE = 16,
	PGACTIVATE = 17,
	PGDEACTIVATE = 18,
	PGLAZYFREE = 19,
	PGFAULT = 20,
	PGMAJFAULT = 21,
	PGLAZYFREED = 22,
	PGREFILL = 23,
	PGSTEAL_KSWAPD = 24,
	PGSTEAL_DIRECT = 25,
	PGSCAN_KSWAPD = 26,
	PGSCAN_DIRECT = 27,
	PGSCAN_DIRECT_THROTTLE = 28,
	PGSCAN_ANON = 29,
	PGSCAN_FILE = 30,
	PGSTEAL_ANON = 31,
	PGSTEAL_FILE = 32,
	PGSCAN_ZONE_RECLAIM_FAILED = 33,
	PGINODESTEAL = 34,
	SLABS_SCANNED = 35,
	KSWAPD_INODESTEAL = 36,
	KSWAPD_LOW_WMARK_HIT_QUICKLY = 37,
	KSWAPD_HIGH_WMARK_HIT_QUICKLY = 38,
	PAGEOUTRUN = 39,
	PGROTATED = 40,
	DROP_PAGECACHE = 41,
	DROP_SLAB = 42,
	OOM_KILL = 43,
	NUMA_PTE_UPDATES = 44,
	NUMA_HUGE_PTE_UPDATES = 45,
	NUMA_HINT_FAULTS = 46,
	NUMA_HINT_FAULTS_LOCAL = 47,
	NUMA_PAGE_MIGRATE = 48,
	PGMIGRATE_SUCCESS = 49,
	PGMIGRATE_FAIL = 50,
	COMPACTMIGRATE_SCANNED = 51,
	COMPACTFREE_SCANNED = 52,
	COMPACTISOLATED = 53,
	COMPACTSTALL = 54,
	COMPACTFAIL = 55,
	COMPACTSUCCESS = 56,
	KCOMPACTD_WAKE = 57,
	KCOMPACTD_MIGRATE_SCANNED = 58,
	KCOMPACTD_FREE_SCANNED = 59,
	HTLB_BUDDY_PGALLOC = 60,
	HTLB_BUDDY_PGALLOC_FAIL = 61,
	UNEVICTABLE_PGCULLED = 62,
	UNEVICTABLE_PGSCANNED = 63,
	UNEVICTABLE_PGRESCUED = 64,
	UNEVICTABLE_PGMLOCKED = 65,
	UNEVICTABLE_PGMUNLOCKED = 66,
	UNEVICTABLE_PGCLEARED = 67,
	UNEVICTABLE_PGSTRANDED = 68,
	THP_FAULT_ALLOC = 69,
	THP_FAULT_FALLBACK = 70,
	THP_FAULT_FALLBACK_CHARGE = 71,
	THP_COLLAPSE_ALLOC = 72,
	THP_COLLAPSE_ALLOC_FAILED = 73,
	THP_FILE_ALLOC = 74,
	THP_FILE_FALLBACK = 75,
	THP_FILE_FALLBACK_CHARGE = 76,
	THP_FILE_MAPPED = 77,
	THP_SPLIT_PAGE = 78,
	THP_SPLIT_PAGE_FAILED = 79,
	THP_DEFERRED_SPLIT_PAGE = 80,
	THP_SPLIT_PMD = 81,
	THP_ZERO_PAGE_ALLOC = 82,
	THP_ZERO_PAGE_ALLOC_FAILED = 83,
	THP_SWPOUT = 84,
	THP_SWPOUT_FALLBACK = 85,
	BALLOON_INFLATE = 86,
	BALLOON_DEFLATE = 87,
	BALLOON_MIGRATE = 88,
	SWAP_RA = 89,
	SWAP_RA_HIT = 90,
	NR_VM_EVENT_ITEMS = 91,
};

struct vm_event_state {
	long unsigned int event[91];
};

struct scatterlist {
	long unsigned int page_link;
	unsigned int offset;
	unsigned int length;
	dma_addr_t dma_address;
	unsigned int dma_length;
};

struct sg_table {
	struct scatterlist *sgl;
	unsigned int nents;
	unsigned int orig_nents;
};

struct seq_operations {
	void * (*start)(struct seq_file *, loff_t *);
	void (*stop)(struct seq_file *, void *);
	void * (*next)(struct seq_file *, void *, loff_t *);
	int (*show)(struct seq_file *, void *);
};

struct rtc_time;

struct kimage;

struct machdep_calls {
	char *name;
	void * (*ioremap)(phys_addr_t, long unsigned int, pgprot_t, void *);
	void (*iounmap)(volatile void *);
	void (*iommu_save)();
	void (*iommu_restore)();
	long unsigned int (*memory_block_size)();
	void (*dma_set_mask)(struct device *, u64);
	int (*probe)();
	void (*setup_arch)();
	void (*show_cpuinfo)(struct seq_file *);
	void (*show_percpuinfo)(struct seq_file *, int);
	long unsigned int (*get_proc_freq)(unsigned int);
	void (*init_IRQ)();
	unsigned int (*get_irq)();
	void (*pcibios_fixup)();
	void (*pci_irq_fixup)(struct pci_dev *);
	int (*pcibios_root_bridge_prepare)(struct pci_host_bridge *);
	void (*discover_phbs)();
	int (*pci_setup_phb)(struct pci_controller *);
	void (*restart)(char *);
	void (*halt)();
	void (*panic)(char *);
	void (*cpu_die)();
	long int (*time_init)();
	int (*set_rtc_time)(struct rtc_time *);
	void (*get_rtc_time)(struct rtc_time *);
	time64_t (*get_boot_time)();
	unsigned char (*rtc_read_val)(int);
	void (*rtc_write_val)(int, unsigned char);
	void (*calibrate_decr)();
	void (*progress)(char *, short unsigned int);
	void (*log_error)(char *, unsigned int, int);
	unsigned char (*nvram_read_val)(int);
	void (*nvram_write_val)(int, unsigned char);
	ssize_t (*nvram_write)(char *, size_t, loff_t *);
	ssize_t (*nvram_read)(char *, size_t, loff_t *);
	ssize_t (*nvram_size)();
	void (*nvram_sync)();
	int (*system_reset_exception)(struct pt_regs *);
	int (*machine_check_exception)(struct pt_regs *);
	int (*handle_hmi_exception)(struct pt_regs *);
	int (*hmi_exception_early)(struct pt_regs *);
	long int (*machine_check_early)(struct pt_regs *);
	bool (*mce_check_early_recovery)(struct pt_regs *);
	long int (*feature_call)(unsigned int, ...);
	int (*pci_get_legacy_ide_irq)(struct pci_dev *, int);
	pgprot_t (*phys_mem_access_prot)(struct file *, long unsigned int, long unsigned int, pgprot_t);
	void (*power_save)();
	void (*enable_pmcs)();
	int (*set_dabr)(long unsigned int, long unsigned int);
	int (*set_dawr)(int, long unsigned int, long unsigned int);
	int (*pci_exclude_device)(struct pci_controller *, unsigned char, unsigned char);
	void (*pcibios_fixup_resources)(struct pci_dev *);
	void (*pcibios_fixup_bus)(struct pci_bus *);
	void (*pcibios_fixup_phb)(struct pci_controller *);
	void (*pcibios_bus_add_device)(struct pci_dev *);
	resource_size_t (*pcibios_default_alignment)();
	void (*pcibios_fixup_sriov)(struct pci_dev *);
	resource_size_t (*pcibios_iov_resource_alignment)(struct pci_dev *, int);
	int (*pcibios_sriov_enable)(struct pci_dev *, u16);
	int (*pcibios_sriov_disable)(struct pci_dev *);
	void (*machine_shutdown)();
	void (*kexec_cpu_down)(int, int);
	int (*machine_kexec_prepare)(struct kimage *);
	void (*machine_kexec)(struct kimage *);
	void (*suspend_disable_irqs)();
	void (*suspend_enable_irqs)();
	int (*suspend_disable_cpu)();
	ssize_t (*cpu_probe)(const char *, size_t);
	ssize_t (*cpu_release)(const char *, size_t);
	int (*get_random_seed)(long unsigned int *);
};

struct boot_param_header {
	__be32 magic;
	__be32 totalsize;
	__be32 off_dt_struct;
	__be32 off_dt_strings;
	__be32 off_mem_rsvmap;
	__be32 version;
	__be32 last_comp_version;
	__be32 boot_cpuid_phys;
	__be32 dt_strings_size;
	__be32 dt_struct_size;
};

struct iommu_table_group_ops;

struct iommu_table_group {
	__u32 tce32_start;
	__u32 tce32_size;
	__u64 pgsizes;
	__u32 max_dynamic_windows_supported;
	__u32 max_levels;
	struct iommu_group *group;
	struct iommu_table *tables[2];
	struct iommu_table_group_ops *ops;
};

typedef __be32 rtas_arg_t;

struct rtas_args {
	__be32 token;
	__be32 nargs;
	__be32 nret;
	rtas_arg_t args[16];
	rtas_arg_t *rets;
};

struct rtas_t {
	long unsigned int entry;
	long unsigned int base;
	long unsigned int size;
	arch_spinlock_t lock;
	struct rtas_args args;
	struct device_node *dev;
};

struct iommu_table_ops {
	int (*set)(struct iommu_table *, long int, long int, long unsigned int, enum dma_data_direction, long unsigned int);
	int (*exchange)(struct iommu_table *, long int, long unsigned int *, enum dma_data_direction *);
	int (*exchange_rm)(struct iommu_table *, long int, long unsigned int *, enum dma_data_direction *);
	__be64 * (*useraddrptr)(struct iommu_table *, long int, bool);
	void (*clear)(struct iommu_table *, long int, long int);
	long unsigned int (*get)(struct iommu_table *, long int);
	void (*flush)(struct iommu_table *);
	void (*free)(struct iommu_table *);
	int (*xchg_no_kill)(struct iommu_table *, long int, long unsigned int *, enum dma_data_direction *, bool);
	void (*tce_kill)(struct iommu_table *, long unsigned int, long unsigned int, bool);
};

struct iommu_table_group_ops {
	long unsigned int (*get_table_size)(__u32, __u64, __u32);
	long int (*create_table)(struct iommu_table_group *, int, __u32, __u64, __u32, struct iommu_table **);
	long int (*set_window)(struct iommu_table_group *, int, struct iommu_table *);
	long int (*unset_window)(struct iommu_table_group *, int);
	void (*take_ownership)(struct iommu_table_group *);
	void (*release_ownership)(struct iommu_table_group *);
};

struct in6_addr {
	union {
		__u8 u6_addr8[16];
		__be16 u6_addr16[8];
		__be32 u6_addr32[4];
	} in6_u;
};

struct linux_logo {
	int type;
	unsigned int width;
	unsigned int height;
	unsigned int clutsize;
	const unsigned char *clut;
	const unsigned char *data;
};

typedef u32 prom_arg_t;

struct prom_args {
	__be32 service;
	__be32 nargs;
	__be32 nret;
	__be32 args[10];
};

struct prom_t {
	ihandle root;
	phandle chosen;
	int cpu;
	ihandle stdout;
	ihandle mmumap;
	ihandle memory;
};

struct mem_map_entry {
	__be64 base;
	__be64 size;
};

typedef __be32 cell_t;

struct platform_support {
	bool hash_mmu;
	bool radix_mmu;
	bool radix_gtse;
	bool xive;
};

struct option_vector1 {
	u8 byte1;
	u8 arch_versions;
	u8 arch_versions3;
};

struct option_vector2 {
	u8 byte1;
	__be16 reserved;
	__be32 real_base;
	__be32 real_size;
	__be32 virt_base;
	__be32 virt_size;
	__be32 load_base;
	__be32 min_rma;
	__be32 min_load;
	u8 min_rma_percent;
	u8 max_pft_size;
} __attribute__((packed));

struct option_vector3 {
	u8 byte1;
	u8 byte2;
};

struct option_vector4 {
	u8 byte1;
	u8 min_vp_cap;
};

struct option_vector5 {
	u8 byte1;
	u8 byte2;
	u8 byte3;
	u8 cmo;
	u8 associativity;
	u8 bin_opts;
	u8 micro_checkpoint;
	u8 reserved0;
	__be32 max_cpus;
	__be16 papr_level;
	__be16 reserved1;
	u8 platform_facilities;
	u8 reserved2;
	__be16 reserved3;
	u8 subprocessors;
	u8 byte22;
	u8 intarch;
	u8 mmu;
	u8 hash_ext;
	u8 radix_ext;
} __attribute__((packed));

struct option_vector6 {
	u8 reserved;
	u8 secondary_pteg;
	u8 os_name;
};

struct ibm_arch_vec {
	struct {
		u32 mask;
		u32 val;
	} pvrs[14];
	u8 num_vectors;
	u8 vec1_len;
	struct option_vector1 vec1;
	u8 vec2_len;
	struct option_vector2 vec2;
	u8 vec3_len;
	struct option_vector3 vec3;
	u8 vec4_len;
	struct option_vector4 vec4;
	u8 vec5_len;
	struct option_vector5 vec5;
	u8 vec6_len;
	struct option_vector6 vec6;
} __attribute__((packed));

struct kernel_symbol {
	long unsigned int value;
	const char *name;
};

struct obs_kernel_param {
	const char *str;
	int (*setup_func)(char *);
	int early;
};

struct lockdep_map {};

struct _ddebug {
	const char *modname;
	const char *function;
	const char *filename;
	const char *format;
	unsigned int lineno: 18;
	unsigned int flags: 8;
	union {
		struct static_key_true dd_key_true;
		struct static_key_false dd_key_false;
	} key;
};

enum ftrace_dump_mode {
	DUMP_NONE = 0,
	DUMP_ALL = 1,
	DUMP_ORIG = 2,
};

struct uid_gid_extent {
	u32 first;
	u32 lower_first;
	u32 count;
};

struct uid_gid_map {
	u32 nr_extents;
	union {
		struct uid_gid_extent extent[5];
		struct {
			struct uid_gid_extent *forward;
			struct uid_gid_extent *reverse;
		};
	};
};

struct proc_ns_operations;

struct ns_common {
	atomic_long_t stashed;
	const struct proc_ns_operations *ops;
	unsigned int inum;
	refcount_t count;
};

struct ctl_table_root;

struct ctl_table_set;

struct ctl_dir;

struct ctl_node;

struct ctl_table_header {
	union {
		struct {
			struct ctl_table *ctl_table;
			int used;
			int count;
			int nreg;
		};
		struct callback_head rcu;
	};
	struct completion *unregistering;
	struct ctl_table *ctl_table_arg;
	struct ctl_table_root *root;
	struct ctl_table_set *set;
	struct ctl_dir *parent;
	struct ctl_node *node;
	struct hlist_head inodes;
};

struct ctl_dir {
	struct ctl_table_header header;
	struct rb_root root;
};

struct ctl_table_set {
	int (*is_seen)(struct ctl_table_set *);
	struct ctl_dir dir;
};

struct ucounts;

struct user_namespace {
	struct uid_gid_map uid_map;
	struct uid_gid_map gid_map;
	struct uid_gid_map projid_map;
	atomic_t count;
	struct user_namespace *parent;
	int level;
	kuid_t owner;
	kgid_t group;
	struct ns_common ns;
	long unsigned int flags;
	struct key *persistent_keyring_register;
	struct rw_semaphore persistent_keyring_register_sem;
	struct work_struct work;
	struct ctl_table_set set;
	struct ctl_table_header *sysctls;
	struct ucounts *ucounts;
	int ucount_max[24];
	union {
		bool parent_could_setfcap;
		struct {
			long unsigned int rh_reserved1;
		} rh_kabi_hidden_98;
		union {		};
	};
	long unsigned int rh_reserved2;
	long unsigned int rh_reserved3;
	long unsigned int rh_reserved4;
};

struct bug_entry {
	long unsigned int bug_addr;
	const char *file;
	short unsigned int line;
	short unsigned int flags;
};

struct pollfd {
	int fd;
	short int events;
	short int revents;
};

struct perf_cpu_context;

struct perf_output_handle;

struct pmu___2 {
	struct list_head entry;
	struct module *module;
	struct device *dev;
	const struct attribute_group **attr_groups;
	const struct attribute_group **attr_update;
	const char *name;
	int type;
	int capabilities;
	int *pmu_disable_count;
	struct perf_cpu_context *pmu_cpu_context;
	atomic_t exclusive_cnt;
	int task_ctx_nr;
	int hrtimer_interval_ms;
	unsigned int nr_addr_filters;
	void (*pmu_enable)(struct pmu___2 *);
	void (*pmu_disable)(struct pmu___2 *);
	int (*event_init)(struct perf_event *);
	void (*event_mapped)(struct perf_event *, struct mm_struct *);
	void (*event_unmapped)(struct perf_event *, struct mm_struct *);
	int (*add)(struct perf_event *, int);
	void (*del)(struct perf_event *, int);
	void (*start)(struct perf_event *, int);
	void (*stop)(struct perf_event *, int);
	void (*read)(struct perf_event *);
	void (*start_txn)(struct pmu___2 *, unsigned int);
	int (*commit_txn)(struct pmu___2 *);
	void (*cancel_txn)(struct pmu___2 *);
	int (*event_idx)(struct perf_event *);
	void (*sched_task)(struct perf_event_context *, bool);
	struct kmem_cache *task_ctx_cache;
	void (*swap_task_ctx)(struct perf_event_context *, struct perf_event_context *);
	union {
		void * (*setup_aux)(struct perf_event *, void **, int, bool);
		struct {
			void * (*setup_aux)(int, void **, int, bool);
		} rh_kabi_hidden_485;
		union {		};
	};
	void (*free_aux)(void *);
	long int (*snapshot_aux)(struct perf_event *, struct perf_output_handle *, long unsigned int);
	int (*addr_filters_validate)(struct list_head *);
	void (*addr_filters_sync)(struct perf_event *);
	int (*aux_output_match)(struct perf_event *);
	int (*filter_match)(struct perf_event *);
	int (*check_period)(struct perf_event *, u64);
};

enum perf_event_state {
	PERF_EVENT_STATE_DEAD = 4294967292,
	PERF_EVENT_STATE_EXIT = 4294967293,
	PERF_EVENT_STATE_ERROR = 4294967294,
	PERF_EVENT_STATE_OFF = 4294967295,
	PERF_EVENT_STATE_INACTIVE = 0,
	PERF_EVENT_STATE_ACTIVE = 1,
};

typedef struct {
	long int v;
} local_t;

typedef struct {
	local_t a;
} local64_t;

struct perf_event_attr {
	__u32 type;
	__u32 size;
	__u64 config;
	union {
		__u64 sample_period;
		__u64 sample_freq;
	};
	__u64 sample_type;
	__u64 read_format;
	__u64 disabled: 1;
	__u64 inherit: 1;
	__u64 pinned: 1;
	__u64 exclusive: 1;
	__u64 exclude_user: 1;
	__u64 exclude_kernel: 1;
	__u64 exclude_hv: 1;
	__u64 exclude_idle: 1;
	__u64 mmap: 1;
	__u64 comm: 1;
	__u64 freq: 1;
	__u64 inherit_stat: 1;
	__u64 enable_on_exec: 1;
	__u64 task: 1;
	__u64 watermark: 1;
	__u64 precise_ip: 2;
	__u64 mmap_data: 1;
	__u64 sample_id_all: 1;
	__u64 exclude_host: 1;
	__u64 exclude_guest: 1;
	__u64 exclude_callchain_kernel: 1;
	__u64 exclude_callchain_user: 1;
	__u64 mmap2: 1;
	__u64 comm_exec: 1;
	__u64 use_clockid: 1;
	__u64 context_switch: 1;
	__u64 write_backward: 1;
	__u64 namespaces: 1;
	__u64 ksymbol: 1;
	__u64 bpf_event: 1;
	__u64 aux_output: 1;
	__u64 cgroup: 1;
	__u64 text_poke: 1;
	__u64 build_id: 1;
	__u64 inherit_thread: 1;
	__u64 remove_on_exec: 1;
	__u64 __reserved_1: 27;
	union {
		__u32 wakeup_events;
		__u32 wakeup_watermark;
	};
	__u32 bp_type;
	union {
		__u64 bp_addr;
		__u64 kprobe_func;
		__u64 uprobe_path;
		__u64 config1;
	};
	union {
		__u64 bp_len;
		__u64 kprobe_addr;
		__u64 probe_offset;
		__u64 config2;
	};
	__u64 branch_sample_type;
	__u64 sample_regs_user;
	__u32 sample_stack_user;
	__s32 clockid;
	__u64 sample_regs_intr;
	__u32 aux_watermark;
	__u16 sample_max_stack;
	__u16 __reserved_2;
	__u32 aux_sample_size;
	__u32 __reserved_3;
};

struct hw_perf_event_extra {
	u64 config;
	unsigned int reg;
	int alloc;
	int idx;
};

struct hw_perf_event {
	union {
		struct {
			u64 config;
			u64 last_tag;
			long unsigned int config_base;
			long unsigned int event_base;
			int event_base_rdpmc;
			int idx;
			int last_cpu;
			int flags;
			struct hw_perf_event_extra extra_reg;
			struct hw_perf_event_extra branch_reg;
		};
		struct {
			struct hrtimer hrtimer;
		};
		struct {
			struct list_head tp_list;
		};
		struct {
			u64 pwr_acc;
			u64 ptsc;
		};
		struct {
			struct arch_hw_breakpoint info;
			struct list_head bp_list;
		};
		struct {
			u8 iommu_bank;
			u8 iommu_cntr;
			u16 padding;
			u64 conf;
			u64 conf1;
		};
	};
	struct task_struct *target;
	void *addr_filters;
	long unsigned int addr_filters_gen;
	int state;
	local64_t prev_count;
	u64 sample_period;
	union {
		struct {
			u64 last_period;
			local64_t period_left;
		};
		struct {
			u64 saved_metric;
			u64 saved_slots;
		};
	};
	u64 interrupts_seq;
	u64 interrupts;
	u64 freq_time_stamp;
	u64 freq_count_stamp;
};

struct ring_buffer;

struct irq_work {
	union {
		struct __call_single_node node;
		struct {
			long unsigned int flags;
			struct llist_node llnode;
		} rh_kabi_hidden_20;
		union {		};
	};
	void (*func)(struct irq_work *);
};

struct perf_addr_filters_head {
	struct list_head list;
	raw_spinlock_t lock;
	unsigned int nr_file_filters;
};

struct perf_sample_data;

typedef void (*perf_overflow_handler_t)(struct perf_event *, struct perf_sample_data *, struct pt_regs *);

struct ftrace_ops;

typedef void (*ftrace_func_t)(long unsigned int, long unsigned int, struct ftrace_ops *, struct pt_regs *);

struct ftrace_hash;

struct ftrace_ops_hash {
	struct ftrace_hash *notrace_hash;
	struct ftrace_hash *filter_hash;
	struct mutex regex_lock;
};

struct ftrace_ops {
	ftrace_func_t func;
	struct ftrace_ops *next;
	long unsigned int flags;
	void *private;
	ftrace_func_t saved_func;
	struct ftrace_ops_hash local_hash;
	struct ftrace_ops_hash *func_hash;
	struct ftrace_ops_hash old_hash;
	long unsigned int trampoline;
	long unsigned int trampoline_size;
};

struct perf_buffer;

struct perf_addr_filter_range;

struct bpf_prog;

struct trace_event_call;

struct event_filter;

struct perf_cgroup;

struct perf_event {
	struct list_head event_entry;
	struct list_head sibling_list;
	struct list_head active_list;
	struct rb_node group_node;
	u64 group_index;
	struct list_head migrate_entry;
	struct hlist_node hlist_entry;
	struct list_head active_entry;
	int nr_siblings;
	int event_caps;
	int group_caps;
	unsigned int group_generation;
	struct perf_event *group_leader;
	struct pmu___2 *pmu;
	void *pmu_private;
	enum perf_event_state state;
	unsigned int attach_state;
	local64_t count;
	atomic64_t child_count;
	u64 total_time_enabled;
	u64 total_time_running;
	u64 tstamp;
	u64 shadow_ctx_time;
	struct perf_event_attr attr;
	u16 header_size;
	u16 id_header_size;
	u16 read_size;
	struct hw_perf_event hw;
	struct perf_event_context *ctx;
	atomic_long_t refcount;
	atomic64_t child_total_time_enabled;
	atomic64_t child_total_time_running;
	struct mutex child_mutex;
	struct list_head child_list;
	struct perf_event *parent;
	int oncpu;
	int cpu;
	struct list_head owner_entry;
	struct task_struct *owner;
	struct mutex mmap_mutex;
	atomic_t mmap_count;
	union {
		struct perf_buffer *rb;
		struct {
			struct ring_buffer *rb;
		} rh_kabi_hidden_760;
		union {		};
	};
	struct list_head rb_entry;
	long unsigned int rcu_batches;
	int rcu_pending;
	wait_queue_head_t waitq;
	struct fasync_struct *fasync;
	int pending_wakeup;
	int pending_kill;
	int pending_disable;
	struct irq_work pending;
	atomic_t event_limit;
	struct perf_addr_filters_head addr_filters;
	union {
		struct perf_addr_filter_range *addr_filter_ranges;
		struct {
			long unsigned int *addr_filters_offs;
		} rh_kabi_hidden_780;
		union {		};
	};
	long unsigned int addr_filters_gen;
	struct perf_event *aux_event;
	void (*destroy)(struct perf_event *);
	struct callback_head callback_head;
	struct pid_namespace *ns;
	u64 id;
	u64 (*clock)();
	perf_overflow_handler_t overflow_handler;
	void *overflow_handler_context;
	perf_overflow_handler_t orig_overflow_handler;
	struct bpf_prog *prog;
	struct trace_event_call *tp_event;
	struct event_filter *filter;
	struct ftrace_ops ftrace_ops;
	struct perf_cgroup *cgrp;
	void *security;
	struct list_head sb_list;
};

struct llist_head {
	struct llist_node *first;
};

typedef void (*smp_call_func_t)(void *);

struct __call_single_data {
	union {
		struct __call_single_node node;
		struct {
			unsigned int flags;
			struct llist_node llist;
		};
	};
	smp_call_func_t func;
	void *info;
};

enum node_states {
	N_POSSIBLE = 0,
	N_ONLINE = 1,
	N_NORMAL_MEMORY = 2,
	N_HIGH_MEMORY = 2,
	N_MEMORY = 3,
	N_CPU = 4,
	N_GENERIC_INITIATOR = 5,
	NR_NODE_STATES = 6,
};

struct delayed_work {
	struct work_struct work;
	struct timer_list timer;
	struct workqueue_struct *wq;
	int cpu;
	long unsigned int rh_reserved1;
	long unsigned int rh_reserved2;
	long unsigned int rh_reserved3;
	long unsigned int rh_reserved4;
};

struct rcu_work {
	struct work_struct work;
	struct callback_head rcu;
	struct workqueue_struct *wq;
};

struct rcu_segcblist {
	struct callback_head *head;
	struct callback_head **tails[4];
	long unsigned int gp_seq[4];
	union {
		atomic_long_t len;
		struct {
			long int len;
		} rh_kabi_hidden_202;
		union {		};
	};
	union {
		u8 flags;
		struct {
			long int len_lazy;
		} rh_kabi_hidden_206;
		union {		};
	};
	long int seglen[4];
};

struct srcu_node;

struct srcu_struct;

struct srcu_data {
	long unsigned int srcu_lock_count[2];
	long unsigned int srcu_unlock_count[2];
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	spinlock_t lock;
	struct rcu_segcblist srcu_cblist;
	long unsigned int srcu_gp_seq_needed;
	long unsigned int srcu_gp_seq_needed_exp;
	bool srcu_cblist_invoking;
	union {
		struct {
			struct work_struct work;
			struct timer_list delay_work;
		};
		struct {
			struct delayed_work work;
		} rh_kabi_hidden_50;
		union {		};
	};
	struct callback_head srcu_barrier_head;
	struct srcu_node *mynode;
	long unsigned int grpmask;
	int cpu;
	struct srcu_struct *ssp;
};

struct srcu_node {
	spinlock_t lock;
	long unsigned int srcu_have_cbs[4];
	long unsigned int srcu_data_have_cbs[4];
	long unsigned int srcu_gp_seq_needed_exp;
	struct srcu_node *srcu_parent;
	int grplo;
	int grphi;
};

struct srcu_struct {
	struct srcu_node node[131];
	struct srcu_node *level[4];
	struct mutex srcu_cb_mutex;
	spinlock_t lock;
	struct mutex srcu_gp_mutex;
	unsigned int srcu_idx;
	long unsigned int srcu_gp_seq;
	long unsigned int srcu_gp_seq_needed;
	long unsigned int srcu_gp_seq_needed_exp;
	long unsigned int srcu_last_gp_end;
	struct srcu_data *sda;
	long unsigned int srcu_barrier_seq;
	struct mutex srcu_barrier_mutex;
	struct completion srcu_barrier_completion;
	atomic_t srcu_barrier_cpu_cnt;
	struct delayed_work work;
	struct lockdep_map dep_map;
};

typedef u32 ppc_opcode_t;

struct cgroup;

struct cgroup_subsys;

struct cgroup_subsys_state {
	struct cgroup *cgroup;
	struct cgroup_subsys *ss;
	struct percpu_ref refcnt;
	struct list_head sibling;
	struct list_head children;
	struct list_head rstat_css_node;
	int id;
	unsigned int flags;
	u64 serial_nr;
	atomic_t online_cnt;
	struct work_struct destroy_work;
	struct rcu_work destroy_rwork;
	struct cgroup_subsys_state *parent;
};

struct mem_cgroup_id {
	int id;
	union {
		refcount_t ref;
		struct {
			atomic_t ref;
		} rh_kabi_hidden_87;
		union {		};
	};
};

struct pc_padding {
	char x[0];
};

struct page_counter {
	atomic_long_t usage;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	struct pc_padding _pad1_;
	long unsigned int emin;
	atomic_long_t min_usage;
	atomic_long_t children_min_usage;
	long unsigned int elow;
	atomic_long_t low_usage;
	atomic_long_t children_low_usage;
	long unsigned int watermark;
	long unsigned int failcnt;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	struct pc_padding _pad2_;
	long unsigned int min;
	long unsigned int low;
	long unsigned int high;
	long unsigned int max;
	struct page_counter *parent;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
};

struct vmpressure {
	long unsigned int scanned;
	long unsigned int reclaimed;
	long unsigned int tree_scanned;
	long unsigned int tree_reclaimed;
	struct spinlock sr_lock;
	struct list_head events;
	struct mutex events_lock;
	struct work_struct work;
};

struct cgroup_file {
	struct kernfs_node *kn;
	long unsigned int notified_at;
	struct timer_list notify_timer;
};

struct mem_cgroup_threshold_ary;

struct mem_cgroup_thresholds {
	struct mem_cgroup_threshold_ary *primary;
	struct mem_cgroup_threshold_ary *spare;
};

struct memcg_padding {
	char x[0];
};

enum percpu_stats_state {
	MEMCG_PERCPU_STATS_ACTIVE = 0,
	MEMCG_PERCPU_STATS_DISABLED = 1,
	MEMCG_PERCPU_STATS_FLUSHING = 2,
	MEMCG_PERCPU_STATS_FLUSHED = 3,
	MEMCG_PERCPU_STATS_FREED = 4,
};

enum memcg_kmem_state {
	KMEM_NONE = 0,
	KMEM_ALLOCATED = 1,
	KMEM_ONLINE = 2,
};

struct fprop_global {
	struct percpu_counter events;
	unsigned int period;
	seqcount_t sequence;
};

struct wb_domain {
	spinlock_t lock;
	struct fprop_global completions;
	struct timer_list period_timer;
	long unsigned int period_time;
	long unsigned int dirty_limit_tstamp;
	long unsigned int dirty_limit;
};

struct wb_completion {
	atomic_t cnt;
	wait_queue_head_t *waitq;
};

struct memcg_cgwb_frn {
	u64 bdi_id;
	int memcg_id;
	u64 at;
	struct wb_completion done;
};

struct memcg_vmstats;

struct obj_cgroup;

struct memcg_vmstats_percpu;

struct mem_cgroup_per_node;

struct mem_cgroup {
	struct cgroup_subsys_state css;
	struct mem_cgroup_id id;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	struct page_counter memory;
	struct page_counter tcpmem;
	union {
		struct page_counter swap;
		struct page_counter memsw;
	};
	struct page_counter kmem;
	struct work_struct high_work;
	long unsigned int soft_limit;
	struct vmpressure vmpressure;
	bool oom_group;
	bool oom_lock;
	int under_oom;
	int swappiness;
	int oom_kill_disable;
	struct cgroup_file events_file;
	struct cgroup_file events_local_file;
	struct cgroup_file swap_events_file;
	struct mutex thresholds_lock;
	struct mem_cgroup_thresholds thresholds;
	struct mem_cgroup_thresholds memsw_thresholds;
	struct list_head oom_notify;
	long unsigned int move_charge_at_immigrate;
	spinlock_t move_lock;
	long unsigned int move_lock_flags;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	struct memcg_padding _pad1_;
	struct rcu_work percpu_stats_rwork;
	enum percpu_stats_state percpu_stats_disabled;
	struct memcg_vmstats *vmstats;
	atomic_long_t memory_events[8];
	atomic_long_t memory_events_local[8];
	long unsigned int socket_pressure;
	bool tcpmem_active;
	int tcpmem_pressure;
	int kmemcg_id;
	enum memcg_kmem_state kmem_state;
	struct obj_cgroup *objcg;
	struct list_head objcg_list;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	struct memcg_padding _pad2_;
	atomic_t moving_account;
	struct task_struct *move_lock_task;
	struct memcg_vmstats_percpu *vmstats_percpu;
	struct list_head cgwb_list;
	struct wb_domain cgwb_domain;
	struct memcg_cgwb_frn cgwb_frn[4];
	struct list_head event_list;
	spinlock_t event_list_lock;
	struct deferred_split deferred_split_queue;
	struct mem_cgroup_per_node *nodeinfo[0];
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
};

struct anon_vma {
	struct anon_vma *root;
	struct rw_semaphore rwsem;
	atomic_t refcount;
	unsigned int num_children;
	struct anon_vma *parent;
	struct rb_root_cached rb_root;
	long unsigned int num_active_vmas;
};

struct mempolicy {
	atomic_t refcnt;
	short unsigned int mode;
	short unsigned int flags;
	nodemask_t nodes;
	union {
		nodemask_t cpuset_mems_allowed;
		nodemask_t user_nodemask;
	} w;
};

struct linux_binprm;

struct coredump_params;

struct linux_binfmt {
	struct list_head lh;
	struct module *module;
	int (*load_binary)(struct linux_binprm *);
	int (*load_shlib)(struct file *);
	int (*core_dump)(struct coredump_params *);
	long unsigned int min_coredump;
};

enum lru_list {
	LRU_INACTIVE_ANON = 0,
	LRU_ACTIVE_ANON = 1,
	LRU_INACTIVE_FILE = 2,
	LRU_ACTIVE_FILE = 3,
	LRU_UNEVICTABLE = 4,
	NR_LRU_LISTS = 5,
};

struct ctl_node {
	struct rb_node node;
	struct ctl_table_header *header;
};

struct ctl_table_root {
	struct ctl_table_set default_set;
	struct ctl_table_set * (*lookup)(struct ctl_table_root *);
	void (*set_ownership)(struct ctl_table_header *, struct ctl_table *, kuid_t *, kgid_t *);
	int (*permissions)(struct ctl_table_header *, struct ctl_table *);
};

enum umh_disable_depth {
	UMH_ENABLED = 0,
	UMH_FREEZING = 1,
	UMH_DISABLED = 2,
};

struct fs_pin;

struct pid_namespace {
	struct kref kref;
	struct idr idr;
	struct callback_head rcu;
	unsigned int pid_allocated;
	struct task_struct *child_reaper;
	struct kmem_cache *pid_cachep;
	unsigned int level;
	struct pid_namespace *parent;
	struct vfsmount *proc_mnt;
	struct dentry *proc_self;
	struct dentry *proc_thread_self;
	struct fs_pin *bacct;
	struct user_namespace *user_ns;
	struct ucounts *ucounts;
	struct work_struct proc_work;
	kgid_t pid_gid;
	int hide_pid;
	int reboot;
	struct ns_common ns;
};

typedef void (*kunit_try_catch_func_t)(void *);

struct kunit_try_catch {
	struct kunit *test;
	struct completion *try_completion;
	int try_result;
	kunit_try_catch_func_t try;
	kunit_try_catch_func_t catch;
	void *context;
};

enum kunit_status {
	KUNIT_SUCCESS = 0,
	KUNIT_FAILURE = 1,
	KUNIT_SKIPPED = 2,
};

struct kunit {
	void *priv;
	const char *name;
	char *log;
	struct kunit_try_catch try_catch;
	const void *param_value;
	int param_index;
	spinlock_t lock;
	enum kunit_status status;
	struct list_head resources;
	char status_comment[256];
};

struct uts_namespace;

struct ipc_namespace;

struct mnt_namespace;

struct net;

struct cgroup_namespace;

struct time_namespace;

struct nsproxy {
	atomic_t count;
	struct uts_namespace *uts_ns;
	struct ipc_namespace *ipc_ns;
	struct mnt_namespace *mnt_ns;
	struct pid_namespace *pid_ns_for_children;
	struct net *net_ns;
	struct cgroup_namespace *cgroup_ns;
	struct time_namespace *time_ns;
	struct time_namespace *time_ns_for_children;
};

struct bio;

struct bio_list {
	struct bio *head;
	struct bio *tail;
};

struct blk_plug {
	struct list_head mq_list;
	struct list_head cb_list;
	short unsigned int rq_count;
	bool multiple_queues;
};

struct reclaim_state {
	long unsigned int reclaimed_slab;
};

typedef int congested_fn(void *, int);

struct fprop_local_percpu {
	struct percpu_counter events;
	unsigned int period;
	raw_spinlock_t lock;
};

enum wb_reason {
	WB_REASON_BACKGROUND = 0,
	WB_REASON_VMSCAN = 1,
	WB_REASON_SYNC = 2,
	WB_REASON_PERIODIC = 3,
	WB_REASON_LAPTOP_TIMER = 4,
	WB_REASON_FREE_MORE_MEM = 5,
	WB_REASON_FS_FREE_SPACE = 6,
	WB_REASON_FORKER_THREAD = 7,
	WB_REASON_FOREIGN_FLUSH = 8,
	WB_REASON_MAX = 9,
};

struct bdi_writeback_congested;

struct bdi_writeback_rh;

struct bdi_writeback {
	struct backing_dev_info *bdi;
	long unsigned int state;
	long unsigned int last_old_flush;
	struct list_head b_dirty;
	struct list_head b_io;
	struct list_head b_more_io;
	struct list_head b_dirty_time;
	spinlock_t list_lock;
	atomic_t writeback_inodes;
	struct percpu_counter stat[4];
	union {
		long unsigned int congested;
		struct {
			struct bdi_writeback_congested *congested;
		} rh_kabi_hidden_155;
		union {		};
	};
	long unsigned int bw_time_stamp;
	long unsigned int dirtied_stamp;
	long unsigned int written_stamp;
	long unsigned int write_bandwidth;
	long unsigned int avg_write_bandwidth;
	long unsigned int dirty_ratelimit;
	long unsigned int balanced_dirty_ratelimit;
	struct fprop_local_percpu completions;
	int dirty_exceeded;
	enum wb_reason start_all_reason;
	spinlock_t work_lock;
	struct list_head work_list;
	struct delayed_work dwork;
	long unsigned int dirty_sleep;
	struct list_head bdi_node;
	struct percpu_ref refcnt;
	struct fprop_local_percpu memcg_completions;
	struct cgroup_subsys_state *memcg_css;
	struct cgroup_subsys_state *blkcg_css;
	struct list_head memcg_node;
	struct list_head blkcg_node;
	union {
		struct work_struct release_work;
		struct callback_head rcu;
	};
	union {
		struct {
			size_t bdi_writeback_size_rh;
			struct bdi_writeback_rh *_rh;
		};
		struct {
			long unsigned int rh_reserved1;
			long unsigned int rh_reserved2;
		} rh_kabi_hidden_198;
		union {		};
	};
	union {
		struct list_head offline_node;
		struct {
			long unsigned int rh_reserved3;
			long unsigned int rh_reserved4;
		} rh_kabi_hidden_201;
		union {		};
	};
};

struct backing_dev_info {
	struct list_head bdi_list;
	long unsigned int ra_pages;
	long unsigned int io_pages;
	congested_fn *congested_fn;
	void *congested_data;
	const char *rh_reserved_name;
	struct kref refcnt;
	unsigned int capabilities;
	unsigned int min_ratio;
	unsigned int max_ratio;
	unsigned int max_prop_frac;
	atomic_long_t tot_write_bandwidth;
	struct bdi_writeback wb;
	struct list_head wb_list;
	struct xarray cgwb_tree;
	struct rb_root rh_reserved_cgwb_congested_tree;
	struct mutex cgwb_release_mutex;
	wait_queue_head_t wb_waitq;
	struct device *dev;
	struct device *owner;
	struct timer_list laptop_mode_wb_timer;
	struct dentry *debug_dir;
	struct dentry *debug_stats;
	union {
		struct rw_semaphore *wb_switch_rwsem;
		struct {
			long unsigned int rh_reserved1;
		} rh_kabi_hidden_244;
		union {		};
	};
	union {
		char *dev_name;
		struct {
			long unsigned int rh_reserved2;
		} rh_kabi_hidden_245;
		union {		};
	};
	union {
		u64 id;
		struct {
			long unsigned int rh_reserved3;
		} rh_kabi_hidden_246;
		union {		};
	};
	long unsigned int rh_reserved4;
	struct rb_node rb_node;
};

struct css_set {
	struct cgroup_subsys_state *subsys[13];
	refcount_t refcount;
	struct css_set *dom_cset;
	struct cgroup *dfl_cgrp;
	int nr_tasks;
	struct list_head tasks;
	struct list_head mg_tasks;
	struct list_head task_iters;
	struct list_head e_cset_node[13];
	struct list_head threaded_csets;
	struct list_head threaded_csets_node;
	struct hlist_node hlist;
	struct list_head cgrp_links;
	struct list_head mg_src_preload_node;
	struct list_head mg_node;
	struct cgroup *mg_src_cgrp;
	struct cgroup *mg_dst_cgrp;
	struct css_set *mg_dst_cset;
	bool dead;
	struct callback_head callback_head;
	struct list_head dying_tasks;
	struct list_head mg_dst_preload_node;
};

struct perf_event_groups {
	struct rb_root tree;
	u64 index;
};

struct perf_event_context {
	struct pmu___2 *pmu;
	raw_spinlock_t lock;
	struct mutex mutex;
	struct list_head active_ctx_list;
	struct perf_event_groups pinned_groups;
	struct perf_event_groups flexible_groups;
	struct list_head event_list;
	struct list_head pinned_active;
	struct list_head flexible_active;
	int nr_events;
	int nr_active;
	int nr_user;
	int is_active;
	int nr_stat;
	int nr_freq;
	int rotate_disable;
	int rotate_necessary;
	union {
		refcount_t refcount;
		struct {
			atomic_t refcount;
		} rh_kabi_hidden_864;
		union {		};
	};
	struct task_struct *task;
	u64 time;
	u64 timestamp;
	struct perf_event_context *parent_ctx;
	u64 parent_gen;
	u64 generation;
	int pin_count;
	int nr_cgroups;
	void *task_ctx_data;
	struct callback_head callback_head;
};

struct task_delay_info {
	raw_spinlock_t lock;
	unsigned int flags;
	u64 blkio_start;
	u64 blkio_delay;
	u64 swapin_delay;
	u32 blkio_count;
	u32 swapin_count;
	u64 freepages_start;
	u64 freepages_delay;
	u32 freepages_count;
	u32 thrashing_count;
	u64 thrashing_start;
	u64 thrashing_delay;
};

struct ftrace_ret_stack {
	long unsigned int ret;
	long unsigned int func;
	long long unsigned int calltime;
};

typedef unsigned int blk_qc_t;

typedef blk_qc_t make_request_fn(struct request_queue *, struct bio *);

struct request;

typedef int dma_drain_needed_fn(struct request *);

struct blk_integrity_profile;

struct blk_integrity {
	const struct blk_integrity_profile *profile;
	unsigned char flags;
	unsigned char tuple_size;
	unsigned char interval_exp;
	unsigned char tag_size;
	long unsigned int rh_reserved1;
	long unsigned int rh_reserved2;
};

struct blk_rq_stat {
	u64 mean;
	u64 min;
	u64 max;
	u32 nr_samples;
	u64 batch;
};

enum blk_zoned_model {
	BLK_ZONED_NONE = 0,
	BLK_ZONED_HA = 1,
	BLK_ZONED_HM = 2,
};

struct queue_limits {
	long unsigned int bounce_pfn;
	long unsigned int seg_boundary_mask;
	long unsigned int virt_boundary_mask;
	unsigned int max_hw_sectors;
	unsigned int max_dev_sectors;
	unsigned int chunk_sectors;
	unsigned int max_sectors;
	unsigned int max_segment_size;
	unsigned int physical_block_size;
	unsigned int alignment_offset;
	unsigned int io_min;
	unsigned int io_opt;
	unsigned int max_discard_sectors;
	unsigned int max_hw_discard_sectors;
	unsigned int max_write_same_sectors;
	unsigned int max_write_zeroes_sectors;
	unsigned int discard_granularity;
	unsigned int discard_alignment;
	short unsigned int logical_block_size;
	short unsigned int max_segments;
	short unsigned int max_integrity_segments;
	short unsigned int max_discard_segments;
	unsigned char misaligned;
	unsigned char discard_misaligned;
	unsigned char cluster;
	unsigned char raid_partial_stripes_expensive;
	enum blk_zoned_model zoned;
	union {
		unsigned int max_zone_append_sectors;
		struct {
			long unsigned int rh_reserved1;
		} rh_kabi_hidden_361;
		union {		};
	};
	long unsigned int rh_reserved2;
	long unsigned int rh_reserved3;
	long unsigned int rh_reserved4;
	long unsigned int rh_reserved5;
	long unsigned int rh_reserved6;
	long unsigned int rh_reserved7;
	long unsigned int rh_reserved8;
};

struct bsg_ops;

struct bsg_class_device {
	struct device *class_dev;
	int minor;
	struct request_queue *queue;
	const struct bsg_ops *ops;
	long unsigned int rh_reserved1;
	long unsigned int rh_reserved2;
};

typedef void *mempool_alloc_t(gfp_t, void *);

typedef void mempool_free_t(void *, void *);

struct mempool_s {
	spinlock_t lock;
	int min_nr;
	int curr_nr;
	void **elements;
	void *pool_data;
	mempool_alloc_t *alloc;
	mempool_free_t *free;
	wait_queue_head_t wait;
};

typedef struct mempool_s mempool_t;

struct bio_set {
	struct kmem_cache *bio_slab;
	unsigned int front_pad;
	mempool_t bio_pool;
	mempool_t bvec_pool;
	mempool_t bio_integrity_pool;
	mempool_t bvec_integrity_pool;
	spinlock_t rescue_lock;
	struct bio_list rescue_list;
	struct work_struct rescue_work;
	struct workqueue_struct *rescue_workqueue;
	union {
		unsigned int back_pad;
		struct {
			long unsigned int rh_reserved1;
		} rh_kabi_hidden_703;
		union {		};
	};
	long unsigned int rh_reserved2;
	long unsigned int rh_reserved3;
	long unsigned int rh_reserved4;
};

struct sbitmap_word;

struct sbitmap {
	unsigned int depth;
	unsigned int shift;
	unsigned int map_nr;
	bool round_robin;
	struct sbitmap_word *map;
};

struct sbq_wait_state;

struct sbitmap_queue {
	struct sbitmap sb;
	unsigned int *rh_reserved_alloc_hint;
	unsigned int wake_batch;
	atomic_t wake_index;
	struct sbq_wait_state *ws;
	atomic_t ws_active;
	bool rh_reserved_round_robin;
	unsigned int min_shallow_depth;
};

struct elevator_queue;

struct blk_queue_stats;

struct rq_qos;

struct blk_mq_ops;

struct blk_mq_ctx;

struct blk_mq_hw_ctx;

struct blk_stat_callback;

struct blkcg_gq;

struct blk_trace;

struct blk_flush_queue;

struct throtl_data;

struct blk_mq_tag_set;

struct request_queue {
	struct list_head rh_reserved_queue_head;
	struct request *last_merge;
	struct elevator_queue *elevator;
	struct blk_queue_stats *stats;
	struct rq_qos *rq_qos;
	make_request_fn *make_request_fn;
	dma_drain_needed_fn *dma_drain_needed;
	const struct blk_mq_ops *mq_ops;
	struct blk_mq_ctx *queue_ctx;
	unsigned int rh_reserved_nr_queues;
	unsigned int queue_depth;
	struct blk_mq_hw_ctx **queue_hw_ctx;
	unsigned int nr_hw_queues;
	struct backing_dev_info *backing_dev_info;
	void *queuedata;
	long unsigned int queue_flags;
	atomic_t pm_only;
	int id;
	gfp_t bounce_gfp;
	spinlock_t queue_lock;
	struct kobject kobj;
	struct kobject *mq_kobj;
	struct blk_integrity integrity;
	struct device *dev;
	union {
		enum rpm_status rpm_status;
		struct {
			int rpm_status;
		} rh_kabi_hidden_491;
		union {		};
	};
	unsigned int rh_reserved_nr_pending;
	long unsigned int nr_requests;
	unsigned int dma_drain_size;
	void *dma_drain_buffer;
	unsigned int dma_pad_mask;
	unsigned int dma_alignment;
	unsigned int rq_timeout;
	int poll_nsec;
	struct blk_stat_callback *poll_cb;
	struct blk_rq_stat poll_stat[16];
	struct timer_list timeout;
	struct work_struct timeout_work;
	struct list_head icq_list;
	long unsigned int blkcg_pols[1];
	struct blkcg_gq *root_blkg;
	struct list_head blkg_list;
	struct queue_limits limits;
	unsigned int nr_zones;
	union {
		long unsigned int *conv_zones_bitmap;
		struct {
			long unsigned int *seq_zones_bitmap;
		} rh_kabi_hidden_543;
		union {		};
	};
	long unsigned int *seq_zones_wlock;
	unsigned int sg_timeout;
	unsigned int sg_reserved_size;
	int node;
	struct blk_trace *blk_trace;
	struct mutex blk_trace_mutex;
	struct blk_flush_queue *fq;
	struct list_head requeue_list;
	spinlock_t requeue_lock;
	struct delayed_work requeue_work;
	struct mutex sysfs_lock;
	union {
		int mq_freeze_depth;
		struct {
			atomic_t mq_freeze_depth;
		} rh_kabi_hidden_570;
		union {		};
	};
	struct bsg_class_device bsg_dev;
	struct throtl_data *td;
	struct callback_head callback_head;
	wait_queue_head_t mq_freeze_wq;
	struct percpu_ref q_usage_counter;
	struct list_head rh_reserved_all_q_node;
	struct blk_mq_tag_set *tag_set;
	struct list_head tag_set_list;
	struct bio_set bio_split;
	struct dentry *debugfs_dir;
	struct dentry *sched_debugfs_dir;
	bool mq_sysfs_init_done;
	size_t cmd_size;
	struct work_struct rh_reserved_release_work;
	u64 write_hints[5];
	struct list_head unused_hctx_list;
	spinlock_t unused_hctx_lock;
	struct mutex mq_freeze_lock;
	struct mutex sysfs_dir_lock;
	struct dentry *rqos_debugfs_dir;
	unsigned int required_elevator_features;
	struct mutex debugfs_mutex;
	atomic_t nr_active_requests_shared_sbitmap;
	struct sbitmap_queue sched_bitmap_tags;
	struct sbitmap_queue sched_breserved_tags;
	int quiesce_depth;
};

typedef __u16 Elf64_Half;

typedef __u64 Elf64_Off;

typedef __u32 Elf64_Word;

struct elf64_sym {
	Elf64_Word st_name;
	unsigned char st_info;
	unsigned char st_other;
	Elf64_Half st_shndx;
	Elf64_Addr st_value;
	Elf64_Xword st_size;
};

typedef struct elf64_sym Elf64_Sym;

struct elf64_hdr {
	unsigned char e_ident[16];
	Elf64_Half e_type;
	Elf64_Half e_machine;
	Elf64_Word e_version;
	Elf64_Addr e_entry;
	Elf64_Off e_phoff;
	Elf64_Off e_shoff;
	Elf64_Word e_flags;
	Elf64_Half e_ehsize;
	Elf64_Half e_phentsize;
	Elf64_Half e_phnum;
	Elf64_Half e_shentsize;
	Elf64_Half e_shnum;
	Elf64_Half e_shstrndx;
};

typedef struct elf64_hdr Elf64_Ehdr;

struct elf64_shdr {
	Elf64_Word sh_name;
	Elf64_Word sh_type;
	Elf64_Xword sh_flags;
	Elf64_Addr sh_addr;
	Elf64_Off sh_offset;
	Elf64_Xword sh_size;
	Elf64_Word sh_link;
	Elf64_Word sh_info;
	Elf64_Xword sh_addralign;
	Elf64_Xword sh_entsize;
};

typedef struct elf64_shdr Elf64_Shdr;

typedef void (*poll_queue_proc)(struct file *, wait_queue_head_t *, struct poll_table_struct *);

struct poll_table_struct {
	poll_queue_proc _qproc;
	__poll_t _key;
};

struct kernel_param;

struct kernel_param_ops {
	unsigned int flags;
	int (*set)(const char *, const struct kernel_param *);
	int (*get)(char *, const struct kernel_param *);
	void (*free)(void *);
};

struct kparam_string;

struct kparam_array;

struct kernel_param {
	const char *name;
	struct module *mod;
	const struct kernel_param_ops *ops;
	const u16 perm;
	s8 level;
	u8 flags;
	union {
		void *arg;
		const struct kparam_string *str;
		const struct kparam_array *arr;
	};
};

struct kparam_string {
	unsigned int maxlen;
	char *string;
};

struct kparam_array {
	unsigned int max;
	unsigned int elemsize;
	unsigned int *num;
	const struct kernel_param_ops *ops;
	void *elem;
};

enum module_state {
	MODULE_STATE_LIVE = 0,
	MODULE_STATE_COMING = 1,
	MODULE_STATE_GOING = 2,
	MODULE_STATE_UNFORMED = 3,
};

struct module_param_attrs;

struct module_kobject {
	struct kobject kobj;
	struct module *mod;
	struct kobject *drivers_dir;
	struct module_param_attrs *mp;
	struct completion *kobj_completion;
};

struct latch_tree_node {
	struct rb_node node[2];
};

struct mod_tree_node {
	struct module *mod;
	struct latch_tree_node node;
};

struct module_layout {
	void *base;
	unsigned int size;
	unsigned int text_size;
	unsigned int ro_size;
	unsigned int ro_after_init_size;
	struct mod_tree_node mtn;
};

struct mod_arch_specific {
	unsigned int stubs_section;
	unsigned int toc_section;
	bool toc_fixed;
	long unsigned int start_opd;
	long unsigned int end_opd;
	long unsigned int tramp;
	long unsigned int tramp_regs;
	struct list_head bug_list;
	struct bug_entry *bug_table;
	unsigned int num_bugs;
};

struct mod_kallsyms {
	Elf64_Sym *symtab;
	unsigned int num_symtab;
	char *strtab;
};

struct module_attribute;

struct exception_table_entry;

struct module_sect_attrs;

struct module_notes_attrs;

struct trace_eval_map;

struct klp_modinfo;

struct bpf_raw_event_map;

struct kunit_suite;

struct module {
	enum module_state state;
	struct list_head list;
	char name[56];
	struct module_kobject mkobj;
	struct module_attribute *modinfo_attrs;
	const char *version;
	const char *srcversion;
	const char *rhelversion;
	struct kobject *holders_dir;
	const struct kernel_symbol *syms;
	const s32 *crcs;
	unsigned int num_syms;
	struct mutex param_lock;
	struct kernel_param *kp;
	unsigned int num_kp;
	unsigned int num_gpl_syms;
	const struct kernel_symbol *gpl_syms;
	const s32 *gpl_crcs;
	bool sig_ok;
	bool async_probe_requested;
	const struct kernel_symbol *gpl_future_syms;
	const s32 *gpl_future_crcs;
	unsigned int num_gpl_future_syms;
	unsigned int num_exentries;
	struct exception_table_entry *extable;
	int (*init)();
	struct module_layout core_layout;
	struct module_layout init_layout;
	struct mod_arch_specific arch;
	long unsigned int taints;
	unsigned int num_bugs;
	struct list_head bug_list;
	struct bug_entry *bug_table;
	struct mod_kallsyms *kallsyms;
	struct mod_kallsyms core_kallsyms;
	struct module_sect_attrs *sect_attrs;
	struct module_notes_attrs *notes_attrs;
	char *args;
	void *percpu;
	unsigned int percpu_size;
	unsigned int num_tracepoints;
	struct tracepoint * const *tracepoints_ptrs;
	struct jump_entry *jump_entries;
	unsigned int num_jump_entries;
	unsigned int num_trace_bprintk_fmt;
	const char **trace_bprintk_fmt_start;
	struct trace_event_call **trace_events;
	unsigned int num_trace_events;
	struct trace_eval_map **trace_evals;
	unsigned int num_trace_evals;
	unsigned int num_ftrace_callsites;
	long unsigned int *ftrace_callsites;
	bool klp;
	bool klp_alive;
	struct klp_modinfo *klp_info;
	struct list_head source_list;
	struct list_head target_list;
	void (*exit)();
	atomic_t refcnt;
	union {
		unsigned int num_bpf_raw_events;
		struct {
			long unsigned int rh_reserved1;
		} rh_kabi_hidden_486;
		union {		};
	};
	union {
		struct bpf_raw_event_map *bpf_raw_events;
		struct {
			long unsigned int rh_reserved2;
		} rh_kabi_hidden_487;
		union {		};
	};
	union {
		int num_kunit_suites;
		struct {
			long unsigned int rh_reserved3;
		} rh_kabi_hidden_489;
		union {		};
	};
	union {
		struct kunit_suite **kunit_suites;
		struct {
			long unsigned int rh_reserved4;
		} rh_kabi_hidden_490;
		union {		};
	};
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
};

struct module_attribute {
	struct attribute attr;
	ssize_t (*show)(struct module_attribute *, struct module_kobject *, char *);
	ssize_t (*store)(struct module_attribute *, struct module_kobject *, const char *, size_t);
	void (*setup)(struct module *, const char *);
	int (*test)(struct module *);
	void (*free)(struct module *);
};

struct klp_modinfo {
	Elf64_Ehdr hdr;
	Elf64_Shdr *sechdrs;
	char *secstrings;
	unsigned int symndx;
};

struct bpf_raw_event_map {
	struct tracepoint *tp;
	void *bpf_func;
	u32 num_args;
	u32 writable_size;
	long: 64;
};

struct kunit_case;

struct kunit_suite {
	const char name[256];
	int (*suite_init)(struct kunit_suite *);
	void (*suite_exit)(struct kunit_suite *);
	int (*init)(struct kunit *);
	void (*exit)(struct kunit *);
	struct kunit_case *test_cases;
	char status_comment[256];
	struct dentry *debugfs;
	char *log;
	int suite_init_err;
};

struct exception_table_entry {
	int insn;
	int fixup;
};

struct trace_event_functions;

struct trace_event {
	struct hlist_node node;
	struct list_head list;
	int type;
	struct trace_event_functions *funcs;
};

struct trace_event_class;

struct bpf_prog_array;

struct trace_event_call {
	struct list_head list;
	struct trace_event_class *class;
	union {
		char *name;
		struct tracepoint *tp;
	};
	struct trace_event event;
	char *print_fmt;
	struct event_filter *filter;
	void *mod;
	void *data;
	int flags;
	int perf_refcount;
	struct hlist_head *perf_events;
	struct bpf_prog_array *prog_array;
	int (*perf_perm)(struct trace_event_call *, struct perf_event *);
};

struct trace_eval_map {
	const char *system;
	const char *eval_string;
	long unsigned int eval_value;
};

struct taskstats {
	__u16 version;
	__u32 ac_exitcode;
	__u8 ac_flag;
	__u8 ac_nice;
	__u64 cpu_count;
	__u64 cpu_delay_total;
	__u64 blkio_count;
	__u64 blkio_delay_total;
	__u64 swapin_count;
	__u64 swapin_delay_total;
	__u64 cpu_run_real_total;
	__u64 cpu_run_virtual_total;
	char ac_comm[32];
	__u8 ac_sched;
	__u8 ac_pad[3];
	int: 32;
	__u32 ac_uid;
	__u32 ac_gid;
	__u32 ac_pid;
	__u32 ac_ppid;
	__u32 ac_btime;
	__u64 ac_etime;
	__u64 ac_utime;
	__u64 ac_stime;
	__u64 ac_minflt;
	__u64 ac_majflt;
	__u64 coremem;
	__u64 virtmem;
	__u64 hiwater_rss;
	__u64 hiwater_vm;
	__u64 read_char;
	__u64 write_char;
	__u64 read_syscalls;
	__u64 write_syscalls;
	__u64 read_bytes;
	__u64 write_bytes;
	__u64 cancelled_write_bytes;
	__u64 nvcsw;
	__u64 nivcsw;
	__u64 ac_utimescaled;
	__u64 ac_stimescaled;
	__u64 cpu_scaled_run_real_total;
	__u64 freepages_count;
	__u64 freepages_delay_total;
	__u64 thrashing_count;
	__u64 thrashing_delay_total;
};

struct readahead_control {
	struct file *file;
	struct address_space *mapping;
	long unsigned int _index;
	unsigned int _nr_pages;
	unsigned int _batch_count;
};

enum writeback_sync_modes {
	WB_SYNC_NONE = 0,
	WB_SYNC_ALL = 1,
};

struct writeback_control {
	long int nr_to_write;
	long int pages_skipped;
	loff_t range_start;
	loff_t range_end;
	enum writeback_sync_modes sync_mode;
	unsigned int for_kupdate: 1;
	unsigned int for_background: 1;
	unsigned int tagged_writepages: 1;
	unsigned int for_reclaim: 1;
	unsigned int range_cyclic: 1;
	unsigned int for_sync: 1;
	unsigned int no_cgroup_owner: 1;
	unsigned int punt_to_cgroup: 1;
	struct bdi_writeback *wb;
	struct inode *inode;
	int wb_id;
	int wb_lcand_id;
	int wb_tcand_id;
	size_t wb_bytes;
	size_t wb_lcand_bytes;
	size_t wb_tcand_bytes;
	long unsigned int rh_reserved1;
	long unsigned int rh_reserved2;
};

struct swap_cluster_info {
	spinlock_t lock;
	unsigned int data: 24;
	unsigned int flags: 8;
};

struct swap_cluster_list {
	struct swap_cluster_info head;
	struct swap_cluster_info tail;
};

struct swap_extent {
	struct list_head list;
	long unsigned int start_page;
	long unsigned int nr_pages;
	sector_t start_block;
};

struct percpu_cluster;

struct swap_info_struct {
	long unsigned int flags;
	short int prio;
	struct plist_node list;
	struct plist_node avail_lists[256];
	signed char type;
	unsigned int max;
	unsigned char *swap_map;
	struct swap_cluster_info *cluster_info;
	struct swap_cluster_list free_clusters;
	unsigned int lowest_bit;
	unsigned int highest_bit;
	unsigned int pages;
	unsigned int inuse_pages;
	unsigned int cluster_next;
	unsigned int cluster_nr;
	struct percpu_cluster *percpu_cluster;
	struct swap_extent *curr_swap_extent;
	struct swap_extent first_swap_extent;
	struct block_device *bdev;
	struct file *swap_file;
	unsigned int old_block_size;
	long unsigned int *frontswap_map;
	atomic_t frontswap_pages;
	spinlock_t lock;
	spinlock_t cont_lock;
	struct work_struct discard_work;
	struct swap_cluster_list discard_clusters;
	union {
		unsigned int *cluster_next_cpu;
		struct {
			long unsigned int rh_reserved1;
		} rh_kabi_hidden_280;
		union {		};
	};
	long unsigned int rh_reserved2;
	struct percpu_ref users;
	struct completion comp;
};

struct partition_meta_info;

struct disk_stats;

struct hd_struct {
	sector_t start_sect;
	sector_t nr_sects;
	seqcount_t nr_sects_seq;
	sector_t alignment_offset;
	unsigned int discard_alignment;
	struct device __dev;
	struct kobject *holder_dir;
	int policy;
	int partno;
	struct partition_meta_info *info;
	long unsigned int stamp;
	struct disk_stats *dkstats;
	struct percpu_ref ref;
	struct rcu_work rcu_work;
	long unsigned int rh_reserved1;
	long unsigned int rh_reserved2;
	long unsigned int rh_reserved3;
	long unsigned int rh_reserved4;
};

struct disk_part_tbl;

struct block_device_operations;

struct timer_rand_state;

struct disk_events;

struct badblocks;

struct cdrom_device_info;

struct gendisk {
	int major;
	int first_minor;
	int minors;
	char disk_name[32];
	char * (*rh_reserved_devnode)(struct gendisk *, umode_t *);
	union {
		struct {
			short unsigned int events;
			short unsigned int event_flags;
		};
		struct {
			unsigned int events;
		} rh_kabi_hidden_204;
		union {		};
	};
	unsigned int rh_reserved_async_events;
	struct disk_part_tbl *part_tbl;
	struct hd_struct part0;
	const struct block_device_operations *fops;
	struct request_queue *queue;
	void *private_data;
	int flags;
	struct rw_semaphore lookup_sem;
	struct kobject *slave_dir;
	struct timer_rand_state *random;
	atomic_t sync_io;
	struct disk_events *ev;
	struct kobject integrity_kobj;
	int node_id;
	struct badblocks *bb;
	struct lockdep_map lockdep_map;
	union {
		struct cdrom_device_info *cdi;
		struct {
			long unsigned int rh_reserved1;
		} rh_kabi_hidden_233;
		union {		};
	};
	union {
		long unsigned int state;
		struct {
			long unsigned int rh_reserved2;
		} rh_kabi_hidden_234;
		union {		};
	};
	long unsigned int rh_reserved3;
	long unsigned int rh_reserved4;
};

struct cdev {
	struct kobject kobj;
	struct module *owner;
	const struct file_operations *ops;
	struct list_head list;
	dev_t dev;
	unsigned int count;
};

struct fc_log;

struct p_log {
	const char *prefix;
	struct fc_log *log;
};

enum fs_context_purpose {
	FS_CONTEXT_FOR_MOUNT = 0,
	FS_CONTEXT_FOR_SUBMOUNT = 1,
	FS_CONTEXT_FOR_RECONFIGURE = 2,
};

enum fs_context_phase {
	FS_CONTEXT_CREATE_PARAMS = 0,
	FS_CONTEXT_CREATING = 1,
	FS_CONTEXT_AWAITING_MOUNT = 2,
	FS_CONTEXT_AWAITING_RECONF = 3,
	FS_CONTEXT_RECONF_PARAMS = 4,
	FS_CONTEXT_RECONFIGURING = 5,
	FS_CONTEXT_FAILED = 6,
};

struct fs_context_operations;

struct fs_context {
	const struct fs_context_operations *ops;
	struct mutex uapi_mutex;
	struct file_system_type *fs_type;
	void *fs_private;
	void *sget_key;
	struct dentry *root;
	struct user_namespace *user_ns;
	struct net *net_ns;
	const struct cred *cred;
	struct p_log log;
	const char *source;
	void *security;
	void *s_fs_info;
	unsigned int sb_flags;
	unsigned int sb_flags_mask;
	unsigned int s_iflags;
	unsigned int lsm_flags;
	enum fs_context_purpose purpose: 8;
	enum fs_context_phase phase: 8;
	bool need_free: 1;
	bool global: 1;
	bool oldapi: 1;
};

struct audit_names;

struct filename {
	const char *name;
	const char *uptr;
	int refcnt;
	struct audit_names *aname;
	const char iname[0];
};

typedef u8 blk_status_t;

struct bvec_iter {
	sector_t bi_sector;
	unsigned int bi_size;
	unsigned int bi_idx;
	unsigned int bi_bvec_done;
	unsigned int rh_bi_reserved;
};

typedef void bio_end_io_t(struct bio *);

struct bio_issue {
	u64 value;
};

struct bio_vec {
	struct page *bv_page;
	unsigned int bv_len;
	unsigned int bv_offset;
};

struct bio_integrity_payload;

struct bio {
	struct bio *bi_next;
	struct gendisk *bi_disk;
	unsigned int bi_opf;
	short unsigned int bi_flags;
	short unsigned int bi_ioprio;
	short unsigned int bi_write_hint;
	blk_status_t bi_status;
	u8 bi_partno;
	unsigned int bi_phys_segments;
	unsigned int bi_seg_front_size;
	unsigned int bi_seg_back_size;
	struct bvec_iter bi_iter;
	atomic_t __bi_remaining;
	bio_end_io_t *bi_end_io;
	void *bi_private;
	struct blkcg_gq *bi_blkg;
	struct bio_issue bi_issue;
	union {
		struct bio_integrity_payload *bi_integrity;
	};
	short unsigned int bi_vcnt;
	short unsigned int bi_max_vecs;
	atomic_t __bi_cnt;
	struct bio_vec *bi_io_vec;
	struct bio_set *bi_pool;
	union {
		u64 bi_iocost_cost;
		struct {
			long unsigned int rh_reserved1;
		} rh_kabi_hidden_241;
		union {		};
	};
	long unsigned int rh_reserved2;
	long unsigned int rh_reserved3;
	struct bio_vec bi_inline_vecs[0];
};

struct linux_binprm {
	char buf[256];
	struct vm_area_struct *vma;
	long unsigned int vma_pages;
	struct mm_struct *mm;
	long unsigned int p;
	unsigned int deprecated_called_set_creds: 1;
	unsigned int active_secureexec: 1;
	unsigned int secureexec: 1;
	unsigned int called_exec_mmap: 1;
	unsigned int point_of_no_return: 1;
	unsigned int preserve_creds: 1;
	unsigned int recursion_depth;
	struct file *file;
	struct cred *cred;
	int unsafe;
	unsigned int per_clear;
	int argc;
	int envc;
	const char *filename;
	const char *interp;
	unsigned int interp_flags;
	unsigned int interp_data;
	long unsigned int loader;
	long unsigned int exec;
	struct rlimit rlim_stack;
};

struct coredump_params {
	union {
		const kernel_siginfo_t *siginfo;
		struct {
			const siginfo_t *siginfo;
		} rh_kabi_hidden_94;
		union {		};
	};
	struct pt_regs *regs;
	struct file *file;
	long unsigned int limit;
	long unsigned int mm_flags;
	loff_t written;
	loff_t pos;
	int cpu;
};

struct ring_buffer_event {
	u32 type_len: 5;
	u32 time_delta: 27;
	u32 array[0];
};

struct seq_buf {
	char *buffer;
	size_t size;
	size_t len;
	loff_t readpos;
};

struct trace_seq {
	unsigned char buffer[65536];
	struct seq_buf seq;
	int full;
};

enum clock_event_state {
	CLOCK_EVT_STATE_DETACHED = 0,
	CLOCK_EVT_STATE_SHUTDOWN = 1,
	CLOCK_EVT_STATE_PERIODIC = 2,
	CLOCK_EVT_STATE_ONESHOT = 3,
	CLOCK_EVT_STATE_ONESHOT_STOPPED = 4,
};

struct clock_event_device___2 {
	void (*event_handler)(struct clock_event_device___2 *);
	int (*set_next_event)(long unsigned int, struct clock_event_device___2 *);
	int (*set_next_ktime)(ktime_t, struct clock_event_device___2 *);
	ktime_t next_event;
	u64 max_delta_ns;
	u64 min_delta_ns;
	u32 mult;
	u32 shift;
	enum clock_event_state state_use_accessors;
	unsigned int features;
	long unsigned int retries;
	int (*set_state_periodic)(struct clock_event_device___2 *);
	int (*set_state_oneshot)(struct clock_event_device___2 *);
	int (*set_state_oneshot_stopped)(struct clock_event_device___2 *);
	int (*set_state_shutdown)(struct clock_event_device___2 *);
	int (*tick_resume)(struct clock_event_device___2 *);
	void (*broadcast)(const struct cpumask *);
	void (*suspend)(struct clock_event_device___2 *);
	void (*resume)(struct clock_event_device___2 *);
	long unsigned int min_delta_ticks;
	long unsigned int max_delta_ticks;
	const char *name;
	int rating;
	int irq;
	int bound_on;
	const struct cpumask *cpumask;
	struct list_head list;
	struct module *owner;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
};

enum perf_sw_ids {
	PERF_COUNT_SW_CPU_CLOCK = 0,
	PERF_COUNT_SW_TASK_CLOCK = 1,
	PERF_COUNT_SW_PAGE_FAULTS = 2,
	PERF_COUNT_SW_CONTEXT_SWITCHES = 3,
	PERF_COUNT_SW_CPU_MIGRATIONS = 4,
	PERF_COUNT_SW_PAGE_FAULTS_MIN = 5,
	PERF_COUNT_SW_PAGE_FAULTS_MAJ = 6,
	PERF_COUNT_SW_ALIGNMENT_FAULTS = 7,
	PERF_COUNT_SW_EMULATION_FAULTS = 8,
	PERF_COUNT_SW_DUMMY = 9,
	PERF_COUNT_SW_BPF_OUTPUT = 10,
	PERF_COUNT_SW_CGROUP_SWITCHES = 11,
	PERF_COUNT_SW_MAX = 12,
};

union perf_mem_data_src {
	__u64 val;
	struct {
		__u64 mem_op: 5;
		__u64 mem_lvl: 14;
		__u64 mem_snoop: 5;
		__u64 mem_lock: 2;
		__u64 mem_dtlb: 7;
		__u64 mem_lvl_num: 4;
		__u64 mem_remote: 1;
		__u64 mem_snoopx: 2;
		__u64 mem_blk: 3;
		__u64 mem_hops: 3;
		__u64 mem_rsvd: 18;
	};
};

struct perf_branch_entry {
	__u64 from;
	__u64 to;
	__u64 mispred: 1;
	__u64 predicted: 1;
	__u64 in_tx: 1;
	__u64 abort: 1;
	__u64 cycles: 16;
	__u64 type: 4;
	__u64 spec: 2;
	__u64 reserved: 38;
};

union perf_sample_weight {
	__u64 full;
	struct {
		__u32 var1_dw;
		__u16 var2_w;
		__u16 var3_w;
	};
};

struct perf_guest_info_callbacks {
	unsigned int (*state)();
	long unsigned int (*get_ip)();
	unsigned int (*handle_intel_pt_intr)();
};

struct new_utsname {
	char sysname[65];
	char nodename[65];
	char release[65];
	char version[65];
	char machine[65];
	char domainname[65];
};

struct uts_namespace {
	struct kref kref;
	struct new_utsname name;
	struct user_namespace *user_ns;
	struct ucounts *ucounts;
	struct ns_common ns;
};

struct cgroup_namespace {
	refcount_t rh_reserved_count;
	struct ns_common ns;
	struct user_namespace *user_ns;
	struct ucounts *ucounts;
	struct css_set *root_cset;
};

struct proc_ns_operations {
	const char *name;
	const char *real_ns_name;
	int type;
	struct ns_common * (*get)(struct task_struct *);
	void (*put)(struct ns_common *);
	int (*install)(struct nsproxy *, struct ns_common *);
	struct user_namespace * (*owner)(struct ns_common *);
	struct ns_common * (*get_parent)(struct ns_common *);
};

struct ucounts {
	struct hlist_node node;
	struct user_namespace *ns;
	kuid_t uid;
	int count;
	atomic_t ucount[24];
};

enum ftrace_tracing_type_t {
	FTRACE_TYPE_ENTER = 0,
	FTRACE_TYPE_RETURN = 1,
};

enum ftrace_bug_type {
	FTRACE_BUG_UNKNOWN = 0,
	FTRACE_BUG_INIT = 1,
	FTRACE_BUG_NOP = 2,
	FTRACE_BUG_CALL = 3,
	FTRACE_BUG_UPDATE = 4,
};

struct ftrace_graph_ent {
	long unsigned int func;
	int depth;
} __attribute__((packed));

struct ftrace_graph_ret {
	long unsigned int func;
	long unsigned int overrun;
	long long unsigned int calltime;
	long long unsigned int rettime;
	int depth;
} __attribute__((packed));

typedef void (*trace_func_graph_ret_t)(struct ftrace_graph_ret *);

typedef int (*trace_func_graph_ent_t)(struct ftrace_graph_ent *);

struct node {
	struct device dev;
	struct list_head access_list;
	struct work_struct node_work;
};

enum cpuhp_state {
	CPUHP_INVALID = 4294967295,
	CPUHP_OFFLINE = 0,
	CPUHP_CREATE_THREADS = 1,
	CPUHP_PERF_PREPARE = 2,
	CPUHP_PERF_X86_PREPARE = 3,
	CPUHP_PERF_X86_AMD_UNCORE_PREP = 4,
	CPUHP_PERF_POWER = 5,
	CPUHP_PERF_SUPERH = 6,
	CPUHP_X86_HPET_DEAD = 7,
	CPUHP_X86_APB_DEAD = 8,
	CPUHP_X86_MCE_DEAD = 9,
	CPUHP_VIRT_NET_DEAD = 10,
	CPUHP_SLUB_DEAD = 11,
	CPUHP_MM_WRITEBACK_DEAD = 12,
	CPUHP_MM_VMSTAT_DEAD = 13,
	CPUHP_SOFTIRQ_DEAD = 14,
	CPUHP_NET_MVNETA_DEAD = 15,
	CPUHP_CPUIDLE_DEAD = 16,
	CPUHP_ARM64_FPSIMD_DEAD = 17,
	CPUHP_ARM_OMAP_WAKE_DEAD = 18,
	CPUHP_IRQ_POLL_DEAD = 19,
	CPUHP_BLOCK_SOFTIRQ_DEAD = 20,
	CPUHP_ACPI_CPUDRV_DEAD = 21,
	CPUHP_S390_PFAULT_DEAD = 22,
	CPUHP_BLK_MQ_DEAD = 23,
	CPUHP_FS_BUFF_DEAD = 24,
	CPUHP_PRINTK_DEAD = 25,
	CPUHP_MM_MEMCQ_DEAD = 26,
	CPUHP_PERCPU_CNT_DEAD = 27,
	CPUHP_RADIX_DEAD = 28,
	CPUHP_PAGE_ALLOC_DEAD = 29,
	CPUHP_NET_DEV_DEAD = 30,
	CPUHP_PCI_XGENE_DEAD = 31,
	CPUHP_IOMMU_INTEL_DEAD = 32,
	CPUHP_LUSTRE_CFS_DEAD = 33,
	CPUHP_AP_ARM_CACHE_B15_RAC_DEAD = 34,
	CPUHP_WORKQUEUE_PREP = 35,
	CPUHP_POWER_NUMA_PREPARE = 36,
	CPUHP_HRTIMERS_PREPARE = 37,
	CPUHP_PROFILE_PREPARE = 38,
	CPUHP_X2APIC_PREPARE = 39,
	CPUHP_SMPCFD_PREPARE = 40,
	CPUHP_RELAY_PREPARE = 41,
	CPUHP_SLAB_PREPARE = 42,
	CPUHP_MD_RAID5_PREPARE = 43,
	CPUHP_RCUTREE_PREP = 44,
	CPUHP_CPUIDLE_COUPLED_PREPARE = 45,
	CPUHP_POWERPC_PMAC_PREPARE = 46,
	CPUHP_POWERPC_MMU_CTX_PREPARE = 47,
	CPUHP_XEN_PREPARE = 48,
	CPUHP_XEN_EVTCHN_PREPARE = 49,
	CPUHP_ARM_SHMOBILE_SCU_PREPARE = 50,
	CPUHP_SH_SH3X_PREPARE = 51,
	CPUHP_NET_FLOW_PREPARE = 52,
	CPUHP_TOPOLOGY_PREPARE = 53,
	CPUHP_NET_IUCV_PREPARE = 54,
	CPUHP_ARM_BL_PREPARE = 55,
	CPUHP_TRACE_RB_PREPARE = 56,
	CPUHP_MM_ZS_PREPARE = 57,
	CPUHP_MM_ZSWP_MEM_PREPARE = 58,
	CPUHP_MM_ZSWP_POOL_PREPARE = 59,
	CPUHP_KVM_PPC_BOOK3S_PREPARE = 60,
	CPUHP_ZCOMP_PREPARE = 61,
	CPUHP_TIMERS_PREPARE = 62,
	CPUHP_MIPS_SOC_PREPARE = 63,
	CPUHP_BP_PREPARE_DYN = 64,
	CPUHP_BP_PREPARE_DYN_END = 84,
	CPUHP_BRINGUP_CPU = 85,
	CPUHP_AP_IDLE_DEAD = 86,
	CPUHP_AP_OFFLINE = 87,
	CPUHP_AP_SCHED_STARTING = 88,
	CPUHP_AP_RCUTREE_DYING = 89,
	CPUHP_AP_IRQ_GIC_STARTING = 90,
	CPUHP_AP_IRQ_HIP04_STARTING = 91,
	CPUHP_AP_IRQ_ARMADA_XP_STARTING = 92,
	CPUHP_AP_IRQ_BCM2836_STARTING = 93,
	CPUHP_AP_IRQ_MIPS_GIC_STARTING = 94,
	CPUHP_AP_ARM_MVEBU_COHERENCY = 95,
	CPUHP_AP_PERF_X86_AMD_UNCORE_STARTING = 96,
	CPUHP_AP_PERF_X86_STARTING = 97,
	CPUHP_AP_PERF_X86_AMD_IBS_STARTING = 98,
	CPUHP_AP_PERF_X86_CQM_STARTING = 99,
	CPUHP_AP_PERF_X86_CSTATE_STARTING = 100,
	CPUHP_AP_PERF_XTENSA_STARTING = 101,
	CPUHP_AP_MIPS_OP_LOONGSON3_STARTING = 102,
	CPUHP_AP_ARM_SDEI_STARTING = 103,
	CPUHP_AP_ARM_VFP_STARTING = 104,
	CPUHP_AP_ARM64_DEBUG_MONITORS_STARTING = 105,
	CPUHP_AP_PERF_ARM_HW_BREAKPOINT_STARTING = 106,
	CPUHP_AP_PERF_ARM_ACPI_STARTING = 107,
	CPUHP_AP_PERF_ARM_STARTING = 108,
	CPUHP_AP_ARM_L2X0_STARTING = 109,
	CPUHP_AP_ARM_ARCH_TIMER_STARTING = 110,
	CPUHP_AP_ARM_GLOBAL_TIMER_STARTING = 111,
	CPUHP_AP_JCORE_TIMER_STARTING = 112,
	CPUHP_AP_EXYNOS4_MCT_TIMER_STARTING = 113,
	CPUHP_AP_ARM_TWD_STARTING = 114,
	CPUHP_AP_QCOM_TIMER_STARTING = 115,
	CPUHP_AP_ARMADA_TIMER_STARTING = 116,
	CPUHP_AP_MARCO_TIMER_STARTING = 117,
	CPUHP_AP_MIPS_GIC_TIMER_STARTING = 118,
	CPUHP_AP_ARC_TIMER_STARTING = 119,
	CPUHP_AP_KVM_STARTING = 120,
	CPUHP_AP_KVM_ARM_VGIC_INIT_STARTING = 121,
	CPUHP_AP_KVM_ARM_VGIC_STARTING = 122,
	CPUHP_AP_KVM_ARM_TIMER_STARTING = 123,
	CPUHP_AP_DUMMY_TIMER_STARTING = 124,
	CPUHP_AP_ARM_XEN_STARTING = 125,
	CPUHP_AP_ARM_CORESIGHT_STARTING = 126,
	CPUHP_AP_ARM64_ISNDEP_STARTING = 127,
	CPUHP_AP_SMPCFD_DYING = 128,
	CPUHP_AP_X86_TBOOT_DYING = 129,
	CPUHP_AP_ARM_CACHE_B15_RAC_DYING = 130,
	CPUHP_AP_ONLINE = 131,
	CPUHP_TEARDOWN_CPU = 132,
	CPUHP_AP_ONLINE_IDLE = 133,
	CPUHP_AP_SCHED_WAIT_EMPTY = 134,
	CPUHP_AP_SMPBOOT_THREADS = 135,
	CPUHP_AP_IRQ_AFFINITY_ONLINE = 136,
	CPUHP_AP_PERF_ONLINE = 137,
	CPUHP_AP_PERF_X86_ONLINE = 138,
	CPUHP_AP_PERF_X86_UNCORE_ONLINE = 139,
	CPUHP_AP_PERF_X86_AMD_UNCORE_ONLINE = 140,
	CPUHP_AP_PERF_X86_AMD_POWER_ONLINE = 141,
	CPUHP_AP_PERF_X86_RAPL_ONLINE = 142,
	CPUHP_AP_PERF_X86_CQM_ONLINE = 143,
	CPUHP_AP_PERF_X86_CSTATE_ONLINE = 144,
	CPUHP_AP_PERF_S390_CF_ONLINE = 145,
	CPUHP_AP_PERF_S390_SF_ONLINE = 146,
	CPUHP_AP_PERF_ARM_CCI_ONLINE = 147,
	CPUHP_AP_PERF_ARM_CCN_ONLINE = 148,
	CPUHP_AP_PERF_ARM_HISI_DDRC_ONLINE = 149,
	CPUHP_AP_PERF_ARM_HISI_HHA_ONLINE = 150,
	CPUHP_AP_PERF_ARM_HISI_L3_ONLINE = 151,
	CPUHP_AP_PERF_ARM_L2X0_ONLINE = 152,
	CPUHP_AP_PERF_ARM_QCOM_L2_ONLINE = 153,
	CPUHP_AP_PERF_ARM_QCOM_L3_ONLINE = 154,
	CPUHP_AP_PERF_ARM_APM_XGENE_ONLINE = 155,
	CPUHP_AP_PERF_POWERPC_NEST_IMC_ONLINE = 156,
	CPUHP_AP_PERF_POWERPC_CORE_IMC_ONLINE = 157,
	CPUHP_AP_PERF_POWERPC_THREAD_IMC_ONLINE = 158,
	CPUHP_AP_WORKQUEUE_ONLINE = 159,
	CPUHP_AP_RCUTREE_ONLINE = 160,
	CPUHP_AP_ONLINE_DYN = 161,
	CPUHP_AP_ONLINE_DYN_END = 191,
	CPUHP_AP_X86_HPET_ONLINE = 192,
	CPUHP_AP_X86_KVM_CLK_ONLINE = 193,
	CPUHP_AP_ACTIVE = 194,
	CPUHP_ONLINE = 195,
};

struct perf_regs {
	__u64 abi;
	struct pt_regs *regs;
};

struct kernel_cpustat {
	u64 cpustat[10];
};

struct kernel_stat {
	long unsigned int irqs_sum;
	unsigned int softirqs[10];
};

struct u64_stats_sync {};

struct bpf_insn {
	__u8 code;
	__u8 dst_reg: 4;
	__u8 src_reg: 4;
	__s16 off;
	__s32 imm;
};

struct bpf_cgroup_storage_key {
	__u64 cgroup_inode_id;
	__u32 attach_type;
};

enum bpf_map_type {
	BPF_MAP_TYPE_UNSPEC = 0,
	BPF_MAP_TYPE_HASH = 1,
	BPF_MAP_TYPE_ARRAY = 2,
	BPF_MAP_TYPE_PROG_ARRAY = 3,
	BPF_MAP_TYPE_PERF_EVENT_ARRAY = 4,
	BPF_MAP_TYPE_PERCPU_HASH = 5,
	BPF_MAP_TYPE_PERCPU_ARRAY = 6,
	BPF_MAP_TYPE_STACK_TRACE = 7,
	BPF_MAP_TYPE_CGROUP_ARRAY = 8,
	BPF_MAP_TYPE_LRU_HASH = 9,
	BPF_MAP_TYPE_LRU_PERCPU_HASH = 10,
	BPF_MAP_TYPE_LPM_TRIE = 11,
	BPF_MAP_TYPE_ARRAY_OF_MAPS = 12,
	BPF_MAP_TYPE_HASH_OF_MAPS = 13,
	BPF_MAP_TYPE_DEVMAP = 14,
	BPF_MAP_TYPE_SOCKMAP = 15,
	BPF_MAP_TYPE_CPUMAP = 16,
	BPF_MAP_TYPE_XSKMAP = 17,
	BPF_MAP_TYPE_SOCKHASH = 18,
	BPF_MAP_TYPE_CGROUP_STORAGE = 19,
	BPF_MAP_TYPE_REUSEPORT_SOCKARRAY = 20,
	BPF_MAP_TYPE_PERCPU_CGROUP_STORAGE = 21,
	BPF_MAP_TYPE_QUEUE = 22,
	BPF_MAP_TYPE_STACK = 23,
	BPF_MAP_TYPE_SK_STORAGE = 24,
	BPF_MAP_TYPE_DEVMAP_HASH = 25,
	BPF_MAP_TYPE_STRUCT_OPS = 26,
	BPF_MAP_TYPE_RINGBUF = 27,
	BPF_MAP_TYPE_INODE_STORAGE = 28,
	BPF_MAP_TYPE_TASK_STORAGE = 29,
};

enum bpf_prog_type {
	BPF_PROG_TYPE_UNSPEC = 0,
	BPF_PROG_TYPE_SOCKET_FILTER = 1,
	BPF_PROG_TYPE_KPROBE = 2,
	BPF_PROG_TYPE_SCHED_CLS = 3,
	BPF_PROG_TYPE_SCHED_ACT = 4,
	BPF_PROG_TYPE_TRACEPOINT = 5,
	BPF_PROG_TYPE_XDP = 6,
	BPF_PROG_TYPE_PERF_EVENT = 7,
	BPF_PROG_TYPE_CGROUP_SKB = 8,
	BPF_PROG_TYPE_CGROUP_SOCK = 9,
	BPF_PROG_TYPE_LWT_IN = 10,
	BPF_PROG_TYPE_LWT_OUT = 11,
	BPF_PROG_TYPE_LWT_XMIT = 12,
	BPF_PROG_TYPE_SOCK_OPS = 13,
	BPF_PROG_TYPE_SK_SKB = 14,
	BPF_PROG_TYPE_CGROUP_DEVICE = 15,
	BPF_PROG_TYPE_SK_MSG = 16,
	BPF_PROG_TYPE_RAW_TRACEPOINT = 17,
	BPF_PROG_TYPE_CGROUP_SOCK_ADDR = 18,
	BPF_PROG_TYPE_LWT_SEG6LOCAL = 19,
	BPF_PROG_TYPE_LIRC_MODE2 = 20,
	BPF_PROG_TYPE_SK_REUSEPORT = 21,
	BPF_PROG_TYPE_FLOW_DISSECTOR = 22,
	BPF_PROG_TYPE_CGROUP_SYSCTL = 23,
	BPF_PROG_TYPE_RAW_TRACEPOINT_WRITABLE = 24,
	BPF_PROG_TYPE_CGROUP_SOCKOPT = 25,
	BPF_PROG_TYPE_TRACING = 26,
	BPF_PROG_TYPE_STRUCT_OPS = 27,
	BPF_PROG_TYPE_EXT = 28,
	BPF_PROG_TYPE_LSM = 29,
	BPF_PROG_TYPE_SK_LOOKUP = 30,
	BPF_PROG_TYPE_SYSCALL = 31,
};

enum bpf_attach_type {
	BPF_CGROUP_INET_INGRESS = 0,
	BPF_CGROUP_INET_EGRESS = 1,
	BPF_CGROUP_INET_SOCK_CREATE = 2,
	BPF_CGROUP_SOCK_OPS = 3,
	BPF_SK_SKB_STREAM_PARSER = 4,
	BPF_SK_SKB_STREAM_VERDICT = 5,
	BPF_CGROUP_DEVICE = 6,
	BPF_SK_MSG_VERDICT = 7,
	BPF_CGROUP_INET4_BIND = 8,
	BPF_CGROUP_INET6_BIND = 9,
	BPF_CGROUP_INET4_CONNECT = 10,
	BPF_CGROUP_INET6_CONNECT = 11,
	BPF_CGROUP_INET4_POST_BIND = 12,
	BPF_CGROUP_INET6_POST_BIND = 13,
	BPF_CGROUP_UDP4_SENDMSG = 14,
	BPF_CGROUP_UDP6_SENDMSG = 15,
	BPF_LIRC_MODE2 = 16,
	BPF_FLOW_DISSECTOR = 17,
	BPF_CGROUP_SYSCTL = 18,
	BPF_CGROUP_UDP4_RECVMSG = 19,
	BPF_CGROUP_UDP6_RECVMSG = 20,
	BPF_CGROUP_GETSOCKOPT = 21,
	BPF_CGROUP_SETSOCKOPT = 22,
	BPF_TRACE_RAW_TP = 23,
	BPF_TRACE_FENTRY = 24,
	BPF_TRACE_FEXIT = 25,
	BPF_MODIFY_RETURN = 26,
	BPF_LSM_MAC = 27,
	BPF_TRACE_ITER = 28,
	BPF_CGROUP_INET4_GETPEERNAME = 29,
	BPF_CGROUP_INET6_GETPEERNAME = 30,
	BPF_CGROUP_INET4_GETSOCKNAME = 31,
	BPF_CGROUP_INET6_GETSOCKNAME = 32,
	BPF_XDP_DEVMAP = 33,
	BPF_CGROUP_INET_SOCK_RELEASE = 34,
	BPF_XDP_CPUMAP = 35,
	BPF_SK_LOOKUP = 36,
	BPF_XDP = 37,
	BPF_SK_SKB_VERDICT = 38,
	__MAX_BPF_ATTACH_TYPE = 39,
};

union bpf_attr {
	struct {
		__u32 map_type;
		__u32 key_size;
		__u32 value_size;
		__u32 max_entries;
		__u32 map_flags;
		__u32 inner_map_fd;
		__u32 numa_node;
		char map_name[16];
		__u32 map_ifindex;
		__u32 btf_fd;
		__u32 btf_key_type_id;
		__u32 btf_value_type_id;
		__u32 btf_vmlinux_value_type_id;
	};
	struct {
		__u32 map_fd;
		__u64 key;
		union {
			__u64 value;
			__u64 next_key;
		};
		__u64 flags;
	};
	struct {
		__u64 in_batch;
		__u64 out_batch;
		__u64 keys;
		__u64 values;
		__u32 count;
		__u32 map_fd;
		__u64 elem_flags;
		__u64 flags;
	} batch;
	struct {
		__u32 prog_type;
		__u32 insn_cnt;
		__u64 insns;
		__u64 license;
		__u32 log_level;
		__u32 log_size;
		__u64 log_buf;
		__u32 kern_version;
		__u32 prog_flags;
		char prog_name[16];
		__u32 prog_ifindex;
		__u32 expected_attach_type;
		__u32 prog_btf_fd;
		__u32 func_info_rec_size;
		__u64 func_info;
		__u32 func_info_cnt;
		__u32 line_info_rec_size;
		__u64 line_info;
		__u32 line_info_cnt;
		__u32 attach_btf_id;
		union {
			__u32 attach_prog_fd;
			__u32 attach_btf_obj_fd;
		};
		__u64 fd_array;
	};
	struct {
		__u64 pathname;
		__u32 bpf_fd;
		__u32 file_flags;
	};
	struct {
		__u32 target_fd;
		__u32 attach_bpf_fd;
		__u32 attach_type;
		__u32 attach_flags;
		__u32 replace_bpf_fd;
	};
	struct {
		__u32 prog_fd;
		__u32 retval;
		__u32 data_size_in;
		__u32 data_size_out;
		__u64 data_in;
		__u64 data_out;
		__u32 repeat;
		__u32 duration;
		__u32 ctx_size_in;
		__u32 ctx_size_out;
		__u64 ctx_in;
		__u64 ctx_out;
		__u32 flags;
		__u32 cpu;
	} test;
	struct {
		union {
			__u32 start_id;
			__u32 prog_id;
			__u32 map_id;
			__u32 btf_id;
			__u32 link_id;
		};
		__u32 next_id;
		__u32 open_flags;
	};
	struct {
		__u32 bpf_fd;
		__u32 info_len;
		__u64 info;
	} info;
	struct {
		__u32 target_fd;
		__u32 attach_type;
		__u32 query_flags;
		__u32 attach_flags;
		__u64 prog_ids;
		__u32 prog_cnt;
	} query;
	struct {
		__u64 name;
		__u32 prog_fd;
	} raw_tracepoint;
	struct {
		__u64 btf;
		__u64 btf_log_buf;
		__u32 btf_size;
		__u32 btf_log_size;
		__u32 btf_log_level;
	};
	struct {
		__u32 pid;
		__u32 fd;
		__u32 flags;
		__u32 buf_len;
		__u64 buf;
		__u32 prog_id;
		__u32 fd_type;
		__u64 probe_offset;
		__u64 probe_addr;
	} task_fd_query;
	struct {
		__u32 prog_fd;
		union {
			__u32 target_fd;
			__u32 target_ifindex;
		};
		__u32 attach_type;
		__u32 flags;
		union {
			__u32 target_btf_id;
			struct {
				__u64 iter_info;
				__u32 iter_info_len;
			};
		};
	} link_create;
	struct {
		__u32 link_fd;
		__u32 new_prog_fd;
		__u32 flags;
		__u32 old_prog_fd;
	} link_update;
	struct {
		__u32 link_fd;
	} link_detach;
	struct {
		__u32 type;
	} enable_stats;
	struct {
		__u32 link_fd;
		__u32 flags;
	} iter_create;
	struct {
		__u32 prog_fd;
		__u32 map_fd;
		__u32 flags;
	} prog_bind_map;
};

enum bpf_func_id {
	BPF_FUNC_unspec = 0,
	BPF_FUNC_map_lookup_elem = 1,
	BPF_FUNC_map_update_elem = 2,
	BPF_FUNC_map_delete_elem = 3,
	BPF_FUNC_probe_read = 4,
	BPF_FUNC_ktime_get_ns = 5,
	BPF_FUNC_trace_printk = 6,
	BPF_FUNC_get_prandom_u32 = 7,
	BPF_FUNC_get_smp_processor_id = 8,
	BPF_FUNC_skb_store_bytes = 9,
	BPF_FUNC_l3_csum_replace = 10,
	BPF_FUNC_l4_csum_replace = 11,
	BPF_FUNC_tail_call = 12,
	BPF_FUNC_clone_redirect = 13,
	BPF_FUNC_get_current_pid_tgid = 14,
	BPF_FUNC_get_current_uid_gid = 15,
	BPF_FUNC_get_current_comm = 16,
	BPF_FUNC_get_cgroup_classid = 17,
	BPF_FUNC_skb_vlan_push = 18,
	BPF_FUNC_skb_vlan_pop = 19,
	BPF_FUNC_skb_get_tunnel_key = 20,
	BPF_FUNC_skb_set_tunnel_key = 21,
	BPF_FUNC_perf_event_read = 22,
	BPF_FUNC_redirect = 23,
	BPF_FUNC_get_route_realm = 24,
	BPF_FUNC_perf_event_output = 25,
	BPF_FUNC_skb_load_bytes = 26,
	BPF_FUNC_get_stackid = 27,
	BPF_FUNC_csum_diff = 28,
	BPF_FUNC_skb_get_tunnel_opt = 29,
	BPF_FUNC_skb_set_tunnel_opt = 30,
	BPF_FUNC_skb_change_proto = 31,
	BPF_FUNC_skb_change_type = 32,
	BPF_FUNC_skb_under_cgroup = 33,
	BPF_FUNC_get_hash_recalc = 34,
	BPF_FUNC_get_current_task = 35,
	BPF_FUNC_probe_write_user = 36,
	BPF_FUNC_current_task_under_cgroup = 37,
	BPF_FUNC_skb_change_tail = 38,
	BPF_FUNC_skb_pull_data = 39,
	BPF_FUNC_csum_update = 40,
	BPF_FUNC_set_hash_invalid = 41,
	BPF_FUNC_get_numa_node_id = 42,
	BPF_FUNC_skb_change_head = 43,
	BPF_FUNC_xdp_adjust_head = 44,
	BPF_FUNC_probe_read_str = 45,
	BPF_FUNC_get_socket_cookie = 46,
	BPF_FUNC_get_socket_uid = 47,
	BPF_FUNC_set_hash = 48,
	BPF_FUNC_setsockopt = 49,
	BPF_FUNC_skb_adjust_room = 50,
	BPF_FUNC_redirect_map = 51,
	BPF_FUNC_sk_redirect_map = 52,
	BPF_FUNC_sock_map_update = 53,
	BPF_FUNC_xdp_adjust_meta = 54,
	BPF_FUNC_perf_event_read_value = 55,
	BPF_FUNC_perf_prog_read_value = 56,
	BPF_FUNC_getsockopt = 57,
	BPF_FUNC_override_return = 58,
	BPF_FUNC_sock_ops_cb_flags_set = 59,
	BPF_FUNC_msg_redirect_map = 60,
	BPF_FUNC_msg_apply_bytes = 61,
	BPF_FUNC_msg_cork_bytes = 62,
	BPF_FUNC_msg_pull_data = 63,
	BPF_FUNC_bind = 64,
	BPF_FUNC_xdp_adjust_tail = 65,
	BPF_FUNC_skb_get_xfrm_state = 66,
	BPF_FUNC_get_stack = 67,
	BPF_FUNC_skb_load_bytes_relative = 68,
	BPF_FUNC_fib_lookup = 69,
	BPF_FUNC_sock_hash_update = 70,
	BPF_FUNC_msg_redirect_hash = 71,
	BPF_FUNC_sk_redirect_hash = 72,
	BPF_FUNC_lwt_push_encap = 73,
	BPF_FUNC_lwt_seg6_store_bytes = 74,
	BPF_FUNC_lwt_seg6_adjust_srh = 75,
	BPF_FUNC_lwt_seg6_action = 76,
	BPF_FUNC_rc_repeat = 77,
	BPF_FUNC_rc_keydown = 78,
	BPF_FUNC_skb_cgroup_id = 79,
	BPF_FUNC_get_current_cgroup_id = 80,
	BPF_FUNC_get_local_storage = 81,
	BPF_FUNC_sk_select_reuseport = 82,
	BPF_FUNC_skb_ancestor_cgroup_id = 83,
	BPF_FUNC_sk_lookup_tcp = 84,
	BPF_FUNC_sk_lookup_udp = 85,
	BPF_FUNC_sk_release = 86,
	BPF_FUNC_map_push_elem = 87,
	BPF_FUNC_map_pop_elem = 88,
	BPF_FUNC_map_peek_elem = 89,
	BPF_FUNC_msg_push_data = 90,
	BPF_FUNC_msg_pop_data = 91,
	BPF_FUNC_rc_pointer_rel = 92,
	BPF_FUNC_spin_lock = 93,
	BPF_FUNC_spin_unlock = 94,
	BPF_FUNC_sk_fullsock = 95,
	BPF_FUNC_tcp_sock = 96,
	BPF_FUNC_skb_ecn_set_ce = 97,
	BPF_FUNC_get_listener_sock = 98,
	BPF_FUNC_skc_lookup_tcp = 99,
	BPF_FUNC_tcp_check_syncookie = 100,
	BPF_FUNC_sysctl_get_name = 101,
	BPF_FUNC_sysctl_get_current_value = 102,
	BPF_FUNC_sysctl_get_new_value = 103,
	BPF_FUNC_sysctl_set_new_value = 104,
	BPF_FUNC_strtol = 105,
	BPF_FUNC_strtoul = 106,
	BPF_FUNC_sk_storage_get = 107,
	BPF_FUNC_sk_storage_delete = 108,
	BPF_FUNC_send_signal = 109,
	BPF_FUNC_tcp_gen_syncookie = 110,
	BPF_FUNC_skb_output = 111,
	BPF_FUNC_probe_read_user = 112,
	BPF_FUNC_probe_read_kernel = 113,
	BPF_FUNC_probe_read_user_str = 114,
	BPF_FUNC_probe_read_kernel_str = 115,
	BPF_FUNC_tcp_send_ack = 116,
	BPF_FUNC_send_signal_thread = 117,
	BPF_FUNC_jiffies64 = 118,
	BPF_FUNC_read_branch_records = 119,
	BPF_FUNC_get_ns_current_pid_tgid = 120,
	BPF_FUNC_xdp_output = 121,
	BPF_FUNC_get_netns_cookie = 122,
	BPF_FUNC_get_current_ancestor_cgroup_id = 123,
	BPF_FUNC_sk_assign = 124,
	BPF_FUNC_ktime_get_boot_ns = 125,
	BPF_FUNC_seq_printf = 126,
	BPF_FUNC_seq_write = 127,
	BPF_FUNC_sk_cgroup_id = 128,
	BPF_FUNC_sk_ancestor_cgroup_id = 129,
	BPF_FUNC_ringbuf_output = 130,
	BPF_FUNC_ringbuf_reserve = 131,
	BPF_FUNC_ringbuf_submit = 132,
	BPF_FUNC_ringbuf_discard = 133,
	BPF_FUNC_ringbuf_query = 134,
	BPF_FUNC_csum_level = 135,
	BPF_FUNC_skc_to_tcp6_sock = 136,
	BPF_FUNC_skc_to_tcp_sock = 137,
	BPF_FUNC_skc_to_tcp_timewait_sock = 138,
	BPF_FUNC_skc_to_tcp_request_sock = 139,
	BPF_FUNC_skc_to_udp6_sock = 140,
	BPF_FUNC_get_task_stack = 141,
	BPF_FUNC_load_hdr_opt = 142,
	BPF_FUNC_store_hdr_opt = 143,
	BPF_FUNC_reserve_hdr_opt = 144,
	BPF_FUNC_inode_storage_get = 145,
	BPF_FUNC_inode_storage_delete = 146,
	BPF_FUNC_d_path = 147,
	BPF_FUNC_copy_from_user = 148,
	BPF_FUNC_snprintf_btf = 149,
	BPF_FUNC_seq_printf_btf = 150,
	BPF_FUNC_skb_cgroup_classid = 151,
	BPF_FUNC_redirect_neigh = 152,
	BPF_FUNC_per_cpu_ptr = 153,
	BPF_FUNC_this_cpu_ptr = 154,
	BPF_FUNC_redirect_peer = 155,
	BPF_FUNC_task_storage_get = 156,
	BPF_FUNC_task_storage_delete = 157,
	BPF_FUNC_get_current_task_btf = 158,
	BPF_FUNC_bprm_opts_set = 159,
	BPF_FUNC_ktime_get_coarse_ns = 160,
	BPF_FUNC_ima_inode_hash = 161,
	BPF_FUNC_sock_from_file = 162,
	BPF_FUNC_check_mtu = 163,
	BPF_FUNC_for_each_map_elem = 164,
	BPF_FUNC_snprintf = 165,
	BPF_FUNC_sys_bpf = 166,
	BPF_FUNC_btf_find_by_name_kind = 167,
	BPF_FUNC_sys_close = 168,
	__BPF_FUNC_MAX_ID = 169,
};

struct bpf_func_info {
	__u32 insn_off;
	__u32 type_id;
};

struct bpf_line_info {
	__u32 insn_off;
	__u32 file_name_off;
	__u32 line_off;
	__u32 line_col;
};

struct bpf_iter_aux_info;

typedef int (*bpf_iter_init_seq_priv_t)(void *, struct bpf_iter_aux_info *);

struct bpf_map;

struct bpf_iter_aux_info {
	struct bpf_map *map;
};

typedef void (*bpf_iter_fini_seq_priv_t)(void *);

struct bpf_iter_seq_info {
	const struct seq_operations *seq_ops;
	bpf_iter_init_seq_priv_t init_seq_private;
	bpf_iter_fini_seq_priv_t fini_seq_private;
	u32 seq_priv_size;
};

struct btf;

struct btf_type;

struct bpf_prog_aux;

struct bpf_local_storage_map;

struct bpf_local_storage;

struct bpf_verifier_env;

struct bpf_func_state;

struct bpf_map_ops {
	int (*map_alloc_check)(union bpf_attr *);
	struct bpf_map * (*map_alloc)(union bpf_attr *);
	void (*map_release)(struct bpf_map *, struct file *);
	void (*map_free)(struct bpf_map *);
	int (*map_get_next_key)(struct bpf_map *, void *, void *);
	void (*map_release_uref)(struct bpf_map *);
	void * (*map_lookup_elem_sys_only)(struct bpf_map *, void *);
	int (*map_lookup_batch)(struct bpf_map *, const union bpf_attr *, union bpf_attr *);
	int (*map_lookup_and_delete_elem)(struct bpf_map *, void *, void *, u64);
	int (*map_lookup_and_delete_batch)(struct bpf_map *, const union bpf_attr *, union bpf_attr *);
	int (*map_update_batch)(struct bpf_map *, const union bpf_attr *, union bpf_attr *);
	int (*map_delete_batch)(struct bpf_map *, const union bpf_attr *, union bpf_attr *);
	void * (*map_lookup_elem)(struct bpf_map *, void *);
	int (*map_update_elem)(struct bpf_map *, void *, void *, u64);
	int (*map_delete_elem)(struct bpf_map *, void *);
	int (*map_push_elem)(struct bpf_map *, void *, u64);
	int (*map_pop_elem)(struct bpf_map *, void *);
	int (*map_peek_elem)(struct bpf_map *, void *);
	void * (*map_fd_get_ptr)(struct bpf_map *, struct file *, int);
	void (*map_fd_put_ptr)(void *);
	int (*map_gen_lookup)(struct bpf_map *, struct bpf_insn *);
	u32 (*map_fd_sys_lookup_elem)(void *);
	void (*map_seq_show_elem)(struct bpf_map *, void *, struct seq_file *);
	int (*map_check_btf)(const struct bpf_map *, const struct btf *, const struct btf_type *, const struct btf_type *);
	int (*map_poke_track)(struct bpf_map *, struct bpf_prog_aux *);
	void (*map_poke_untrack)(struct bpf_map *, struct bpf_prog_aux *);
	void (*map_poke_run)(struct bpf_map *, u32, struct bpf_prog *, struct bpf_prog *);
	int (*map_direct_value_addr)(const struct bpf_map *, u64 *, u32);
	int (*map_direct_value_meta)(const struct bpf_map *, u64, u32 *);
	int (*map_mmap)(struct bpf_map *, struct vm_area_struct *);
	__poll_t (*map_poll)(struct bpf_map *, struct file *, struct poll_table_struct *);
	int (*map_local_storage_charge)(struct bpf_local_storage_map *, void *, u32);
	void (*map_local_storage_uncharge)(struct bpf_local_storage_map *, void *, u32);
	struct bpf_local_storage ** (*map_owner_storage_ptr)(void *);
	int (*map_redirect)(struct bpf_map *, u32, u64);
	bool (*map_meta_equal)(const struct bpf_map *, const struct bpf_map *);
	int (*map_set_for_each_callback_args)(struct bpf_verifier_env *, struct bpf_func_state *, struct bpf_func_state *);
	int (*map_for_each_callback)(struct bpf_map *, void *, void *, u64);
	const char * const map_btf_name;
	int *map_btf_id;
	const struct bpf_iter_seq_info *iter_seq_info;
};

struct bpf_map {
	const struct bpf_map_ops *ops;
	struct bpf_map *inner_map_meta;
	void *security;
	enum bpf_map_type map_type;
	u32 key_size;
	u32 value_size;
	u32 max_entries;
	u32 map_flags;
	int spin_lock_off;
	u32 id;
	int numa_node;
	u32 btf_key_type_id;
	u32 btf_value_type_id;
	struct btf *btf;
	struct mem_cgroup *memcg;
	char name[16];
	u32 btf_vmlinux_value_type_id;
	union {
		bool bypass_spec_v1;
		struct {
			bool unpriv_array;
		} rh_kabi_hidden_185;
		union {		};
	};
	bool frozen;
	long: 16;
	long: 64;
	long: 64;
	long: 64;
	atomic64_t refcnt;
	atomic64_t usercnt;
	struct work_struct work;
	struct mutex freeze_mutex;
	u64 writecnt;
	long: 64;
};

struct btf_header {
	__u16 magic;
	__u8 version;
	__u8 flags;
	__u32 hdr_len;
	__u32 type_off;
	__u32 type_len;
	__u32 str_off;
	__u32 str_len;
};

struct btf {
	void *data;
	struct btf_type **types;
	u32 *resolved_ids;
	u32 *resolved_sizes;
	const char *strings;
	void *nohdr_data;
	struct btf_header hdr;
	u32 nr_types;
	u32 types_size;
	u32 data_size;
	refcount_t refcnt;
	u32 id;
	struct callback_head rcu;
	struct btf *base_btf;
	u32 start_id;
	u32 start_str_off;
	char name[56];
	bool kernel_btf;
};

struct btf_type {
	__u32 name_off;
	__u32 info;
	union {
		__u32 size;
		__u32 type;
	};
};

struct bpf_ksym {
	long unsigned int start;
	long unsigned int end;
	char name[128];
	struct list_head lnode;
	struct latch_tree_node tnode;
	bool prog;
};

struct bpf_ctx_arg_aux;

struct bpf_trampoline;

struct bpf_jit_poke_descriptor;

struct bpf_kfunc_desc_tab;

struct bpf_prog_ops;

struct btf_mod_pair;

struct bpf_prog_offload;

struct bpf_func_info_aux;

struct bpf_prog_aux {
	atomic64_t refcnt;
	u32 used_map_cnt;
	u32 used_btf_cnt;
	u32 max_ctx_offset;
	u32 max_pkt_offset;
	u32 max_tp_access;
	u32 stack_depth;
	u32 id;
	u32 func_cnt;
	u32 func_idx;
	u32 attach_btf_id;
	u32 ctx_arg_info_size;
	u32 max_rdonly_access;
	u32 max_rdwr_access;
	const struct bpf_ctx_arg_aux *ctx_arg_info;
	struct mutex dst_mutex;
	struct bpf_prog *dst_prog;
	struct bpf_trampoline *dst_trampoline;
	enum bpf_prog_type saved_dst_prog_type;
	enum bpf_attach_type saved_dst_attach_type;
	struct btf *attach_btf;
	bool verifier_zext;
	bool offload_requested;
	bool attach_btf_trace;
	bool func_proto_unreliable;
	bool sleepable;
	bool tail_call_reachable;
	struct hlist_node tramp_hlist;
	const struct btf_type *attach_func_proto;
	const char *attach_func_name;
	struct bpf_prog **func;
	void *jit_data;
	struct bpf_jit_poke_descriptor *poke_tab;
	struct bpf_kfunc_desc_tab *kfunc_tab;
	u32 size_poke_tab;
	struct bpf_ksym ksym;
	const struct bpf_prog_ops *ops;
	struct bpf_map **used_maps;
	struct mutex used_maps_mutex;
	struct btf_mod_pair *used_btfs;
	struct bpf_prog *prog;
	struct user_struct *user;
	u64 load_time;
	struct bpf_map *cgroup_storage[2];
	char name[16];
	void *security;
	struct bpf_prog_offload *offload;
	struct btf *btf;
	struct bpf_func_info *func_info;
	struct bpf_func_info_aux *func_info_aux;
	struct bpf_line_info *linfo;
	void **jited_linfo;
	u32 func_info_cnt;
	u32 nr_linfo;
	u32 linfo_idx;
	u32 num_exentries;
	struct exception_table_entry *extable;
	union {
		struct work_struct work;
		struct callback_head rcu;
	};
};

struct sock_filter {
	__u16 code;
	__u8 jt;
	__u8 jf;
	__u32 k;
};

struct sock_fprog_kern;

struct bpf_prog_stats;

struct bpf_prog {
	u16 pages;
	u16 jited: 1;
	u16 jit_requested: 1;
	u16 gpl_compatible: 1;
	u16 cb_access: 1;
	u16 dst_needed: 1;
	u16 blinded: 1;
	u16 is_func: 1;
	u16 kprobe_override: 1;
	u16 has_callchain_buf: 1;
	u16 enforce_expected_attach_type: 1;
	u16 call_get_stack: 1;
	enum bpf_prog_type type;
	enum bpf_attach_type expected_attach_type;
	u32 len;
	u32 jited_len;
	u8 tag[8];
	struct bpf_prog_aux *aux;
	struct sock_fprog_kern *orig_prog;
	struct bpf_prog_stats *stats;
	int *active;
	unsigned int (*bpf_func)(const void *, const struct bpf_insn *);
	union {
		struct sock_filter insns[0];
		struct bpf_insn insnsi[0];
	};
};

enum bpf_arg_type {
	ARG_DONTCARE = 0,
	ARG_CONST_MAP_PTR = 1,
	ARG_PTR_TO_MAP_KEY = 2,
	ARG_PTR_TO_MAP_VALUE = 3,
	ARG_PTR_TO_UNINIT_MAP_VALUE = 4,
	ARG_PTR_TO_MEM = 5,
	ARG_PTR_TO_UNINIT_MEM = 6,
	ARG_CONST_SIZE = 7,
	ARG_CONST_SIZE_OR_ZERO = 8,
	ARG_PTR_TO_CTX = 9,
	ARG_ANYTHING = 10,
	ARG_PTR_TO_SPIN_LOCK = 11,
	ARG_PTR_TO_SOCK_COMMON = 12,
	ARG_PTR_TO_INT = 13,
	ARG_PTR_TO_LONG = 14,
	ARG_PTR_TO_SOCKET = 15,
	ARG_PTR_TO_BTF_ID = 16,
	ARG_PTR_TO_ALLOC_MEM = 17,
	ARG_CONST_ALLOC_SIZE_OR_ZERO = 18,
	ARG_PTR_TO_BTF_ID_SOCK_COMMON = 19,
	ARG_PTR_TO_PERCPU_BTF_ID = 20,
	ARG_PTR_TO_FUNC = 21,
	ARG_PTR_TO_STACK = 22,
	ARG_PTR_TO_CONST_STR = 23,
	__BPF_ARG_TYPE_MAX = 24,
	ARG_PTR_TO_MAP_VALUE_OR_NULL = 259,
	ARG_PTR_TO_MEM_OR_NULL = 261,
	ARG_PTR_TO_CTX_OR_NULL = 265,
	ARG_PTR_TO_SOCKET_OR_NULL = 271,
	ARG_PTR_TO_ALLOC_MEM_OR_NULL = 273,
	ARG_PTR_TO_STACK_OR_NULL = 278,
	__BPF_ARG_TYPE_LIMIT = 1023,
};

enum bpf_return_type {
	RET_INTEGER = 0,
	RET_VOID = 1,
	RET_PTR_TO_MAP_VALUE = 2,
	RET_PTR_TO_SOCKET = 3,
	RET_PTR_TO_TCP_SOCK = 4,
	RET_PTR_TO_SOCK_COMMON = 5,
	RET_PTR_TO_ALLOC_MEM = 6,
	RET_PTR_TO_MEM_OR_BTF_ID = 7,
	RET_PTR_TO_BTF_ID = 8,
	__BPF_RET_TYPE_MAX = 9,
	RET_PTR_TO_MAP_VALUE_OR_NULL = 258,
	RET_PTR_TO_SOCKET_OR_NULL = 259,
	RET_PTR_TO_TCP_SOCK_OR_NULL = 260,
	RET_PTR_TO_SOCK_COMMON_OR_NULL = 261,
	RET_PTR_TO_ALLOC_MEM_OR_NULL = 262,
	RET_PTR_TO_BTF_ID_OR_NULL = 264,
	__BPF_RET_TYPE_LIMIT = 1023,
};

struct bpf_func_proto {
	u64 (*func)(u64, u64, u64, u64, u64);
	bool gpl_only;
	bool pkt_access;
	enum bpf_return_type ret_type;
	union {
		struct {
			enum bpf_arg_type arg1_type;
			enum bpf_arg_type arg2_type;
			enum bpf_arg_type arg3_type;
			enum bpf_arg_type arg4_type;
			enum bpf_arg_type arg5_type;
		};
		enum bpf_arg_type arg_type[5];
	};
	union {
		struct {
			u32 *arg1_btf_id;
			u32 *arg2_btf_id;
			u32 *arg3_btf_id;
			u32 *arg4_btf_id;
			u32 *arg5_btf_id;
		};
		u32 *arg_btf_id[5];
	};
	int *ret_btf_id;
	bool (*allowed)(const struct bpf_prog *);
};

enum bpf_access_type {
	BPF_READ = 1,
	BPF_WRITE = 2,
};

enum bpf_reg_type {
	NOT_INIT = 0,
	SCALAR_VALUE = 1,
	PTR_TO_CTX = 2,
	CONST_PTR_TO_MAP = 3,
	PTR_TO_MAP_VALUE = 4,
	PTR_TO_MAP_KEY = 5,
	PTR_TO_STACK = 6,
	PTR_TO_PACKET_META = 7,
	PTR_TO_PACKET = 8,
	PTR_TO_PACKET_END = 9,
	PTR_TO_FLOW_KEYS = 10,
	PTR_TO_SOCKET = 11,
	PTR_TO_SOCK_COMMON = 12,
	PTR_TO_TCP_SOCK = 13,
	PTR_TO_TP_BUFFER = 14,
	PTR_TO_XDP_SOCK = 15,
	PTR_TO_BTF_ID = 16,
	PTR_TO_MEM = 17,
	PTR_TO_BUF = 18,
	PTR_TO_PERCPU_BTF_ID = 19,
	PTR_TO_FUNC = 20,
	__BPF_REG_TYPE_MAX = 21,
	PTR_TO_MAP_VALUE_OR_NULL = 260,
	PTR_TO_SOCKET_OR_NULL = 267,
	PTR_TO_SOCK_COMMON_OR_NULL = 268,
	PTR_TO_TCP_SOCK_OR_NULL = 269,
	PTR_TO_BTF_ID_OR_NULL = 272,
	__BPF_REG_TYPE_LIMIT = 1023,
};

struct bpf_verifier_log;

struct bpf_insn_access_aux {
	enum bpf_reg_type reg_type;
	union {
		int ctx_field_size;
		struct {
			struct btf *btf;
			u32 btf_id;
		};
	};
	struct bpf_verifier_log *log;
};

struct bpf_prog_ops {
	int (*test_run)(struct bpf_prog *, const union bpf_attr *, union bpf_attr *);
};

struct bpf_verifier_ops {
	const struct bpf_func_proto * (*get_func_proto)(enum bpf_func_id, const struct bpf_prog *);
	bool (*is_valid_access)(int, int, enum bpf_access_type, const struct bpf_prog *, struct bpf_insn_access_aux *);
	int (*gen_prologue)(struct bpf_insn *, bool, const struct bpf_prog *);
	int (*gen_ld_abs)(const struct bpf_insn *, struct bpf_insn *);
	u32 (*convert_ctx_access)(enum bpf_access_type, const struct bpf_insn *, struct bpf_insn *, struct bpf_prog *, u32 *);
	int (*btf_struct_access)(struct bpf_verifier_log *, const struct btf *, const struct btf_type *, int, int, enum bpf_access_type, u32 *);
	bool (*check_kfunc_call)(u32);
};

struct net_device;

struct bpf_offload_dev;

struct bpf_prog_offload {
	struct bpf_prog *prog;
	struct net_device *netdev;
	struct bpf_offload_dev *offdev;
	void *dev_priv;
	struct list_head offloads;
	bool dev_state;
	bool opt_failed;
	void *jited_image;
	u32 jited_len;
};

struct btf_func_model {
	u8 ret_size;
	u8 nr_args;
	u8 arg_size[12];
};

struct bpf_tramp_image {
	void *image;
	struct bpf_ksym ksym;
	struct percpu_ref pcref;
	void *ip_after_call;
	void *ip_epilogue;
	union {
		struct callback_head rcu;
		struct work_struct work;
	};
};

struct bpf_trampoline {
	struct hlist_node hlist;
	struct mutex mutex;
	refcount_t refcnt;
	u64 key;
	struct {
		struct btf_func_model model;
		void *addr;
		bool ftrace_managed;
	} func;
	struct bpf_prog *extension_prog;
	struct hlist_head progs_hlist[3];
	int progs_cnt[3];
	struct bpf_tramp_image *cur_image;
	u64 selector;
	struct module *mod;
};

struct bpf_func_info_aux {
	u16 linkage;
	bool unreliable;
};

struct bpf_jit_poke_descriptor {
	void *tailcall_target;
	void *tailcall_bypass;
	void *bypass_addr;
	void *aux;
	union {
		struct {
			struct bpf_map *map;
			u32 key;
		} tail_call;
	};
	bool tailcall_target_stable;
	u8 adj_off;
	u16 reason;
	u32 insn_idx;
};

struct bpf_ctx_arg_aux {
	u32 offset;
	enum bpf_reg_type reg_type;
	u32 btf_id;
};

struct btf_mod_pair {
	struct btf *btf;
	struct module *module;
};

struct bpf_cgroup_storage;

struct bpf_prog_array_item {
	struct bpf_prog *prog;
	struct bpf_cgroup_storage *cgroup_storage[2];
};

struct bpf_storage_buffer;

struct bpf_cgroup_storage_map;

struct bpf_cgroup_storage {
	union {
		struct bpf_storage_buffer *buf;
		void *percpu_buf;
	};
	struct bpf_cgroup_storage_map *map;
	struct bpf_cgroup_storage_key key;
	struct list_head list_map;
	struct list_head list_cg;
	struct rb_node node;
	struct callback_head rcu;
};

struct bpf_prog_array {
	struct callback_head rcu;
	struct bpf_prog_array_item items[0];
};

struct bpf_cgroup_storage_info {
	struct task_struct *task;
	struct bpf_cgroup_storage *storage[2];
};

struct bpf_storage_buffer {
	struct callback_head rcu;
	char data[0];
};

struct cgroup_base_stat {
	struct task_cputime cputime;
};

struct cgroup_bpf {
	struct bpf_prog_array *effective[64];
	struct list_head progs[64];
	u32 flags[64];
	struct bpf_prog_array *inactive;
	struct percpu_ref refcnt;
	struct work_struct release_work;
	struct list_head storages;
	long unsigned int rh_reserved3;
	long unsigned int rh_reserved4;
	long unsigned int rh_reserved5;
	long unsigned int rh_reserved6;
	long unsigned int rh_reserved7;
	long unsigned int rh_reserved8;
	long unsigned int rh_reserved9;
	long unsigned int rh_reserved10;
	long unsigned int rh_reserved11;
	long unsigned int rh_reserved12;
	long unsigned int rh_reserved13;
	long unsigned int rh_reserved14;
	long unsigned int rh_reserved15;
	long unsigned int rh_reserved16;
};

struct cgroup_freezer_state {
	bool freeze;
	int e_freeze;
	int nr_frozen_descendants;
	int nr_frozen_tasks;
};

struct psi_group_cpu;

struct psi_group {
	struct mutex avgs_lock;
	struct psi_group_cpu *pcpu;
	u64 avg_total[5];
	u64 avg_last_update;
	u64 avg_next_update;
	struct delayed_work avgs_work;
	u64 total[10];
	long unsigned int avg[15];
	struct task_struct *poll_task;
	struct timer_list poll_timer;
	wait_queue_head_t poll_wait;
	atomic_t poll_wakeup;
	struct mutex trigger_lock;
	struct list_head triggers;
	u32 nr_triggers[5];
	u32 poll_states;
	u64 poll_min_period;
	u64 polling_total[5];
	u64 polling_next_update;
	u64 polling_until;
};

struct cgroup_root;

struct cgroup_rstat_cpu;

struct cgroup {
	struct cgroup_subsys_state self;
	long unsigned int flags;
	int rh_reserved_id;
	int level;
	int max_depth;
	int nr_descendants;
	int nr_dying_descendants;
	int max_descendants;
	int nr_populated_csets;
	int nr_populated_domain_children;
	int nr_populated_threaded_children;
	int nr_threaded_children;
	struct kernfs_node *kn;
	struct cgroup_file procs_file;
	struct cgroup_file events_file;
	u16 subtree_control;
	u16 subtree_ss_mask;
	u16 old_subtree_control;
	u16 old_subtree_ss_mask;
	struct cgroup_subsys_state *subsys[13];
	struct cgroup_root *root;
	struct list_head cset_links;
	struct list_head e_csets[13];
	struct cgroup *dom_cgrp;
	struct cgroup_rstat_cpu *rstat_cpu;
	struct list_head rstat_css_list;
	struct cgroup_base_stat last_bstat;
	struct cgroup_base_stat bstat;
	struct prev_cputime prev_cputime;
	struct list_head pidlists;
	struct mutex pidlist_mutex;
	wait_queue_head_t offline_waitq;
	struct work_struct release_agent_work;
	struct cgroup_bpf bpf;
	atomic_t congestion_count;
	struct cgroup *old_dom_cgrp;
	struct cgroup_freezer_state freezer;
	struct psi_group psi;
	struct cgroup *rstat_flush_next;
	u64 ancestor_ids[0];
};

struct psi_group_cpu {
	seqcount_t seq;
	unsigned int tasks[4];
	u32 state_mask;
	u32 times[6];
	u64 state_start;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	u32 times_prev[12];
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
};

struct cgroup_taskset;

struct cftype;

struct cgroup_subsys {
	struct cgroup_subsys_state * (*css_alloc)(struct cgroup_subsys_state *);
	int (*css_online)(struct cgroup_subsys_state *);
	void (*css_offline)(struct cgroup_subsys_state *);
	void (*css_released)(struct cgroup_subsys_state *);
	void (*css_free)(struct cgroup_subsys_state *);
	void (*css_reset)(struct cgroup_subsys_state *);
	void (*css_rstat_flush)(struct cgroup_subsys_state *, int);
	int (*css_extra_stat_show)(struct seq_file *, struct cgroup_subsys_state *);
	int (*can_attach)(struct cgroup_taskset *);
	void (*cancel_attach)(struct cgroup_taskset *);
	void (*attach)(struct cgroup_taskset *);
	void (*post_attach)();
	int (*can_fork)(struct task_struct *);
	void (*cancel_fork)(struct task_struct *);
	void (*fork)(struct task_struct *);
	void (*exit)(struct task_struct *);
	void (*release)(struct task_struct *);
	void (*bind)(struct cgroup_subsys_state *);
	bool early_init: 1;
	bool implicit_on_dfl: 1;
	bool threaded: 1;
	bool rh_reserved_broken_hierarchy: 1;
	bool rh_reserved_warned_broken_hierarchy: 1;
	int id;
	const char *name;
	const char *legacy_name;
	struct cgroup_root *root;
	struct idr css_idr;
	struct list_head cfts;
	struct cftype *dfl_cftypes;
	struct cftype *legacy_cftypes;
	unsigned int depends_on;
};

struct cgroup_rstat_cpu {
	struct u64_stats_sync bsync;
	struct cgroup_base_stat bstat;
	struct cgroup_base_stat last_bstat;
	struct cgroup *updated_children;
	struct cgroup *updated_next;
};

struct cgroup_root {
	struct kernfs_root *kf_root;
	unsigned int subsys_mask;
	int hierarchy_id;
	struct cgroup cgrp;
	u64 cgrp_ancestor_id_storage;
	atomic_t nr_cgrps;
	struct list_head root_list;
	unsigned int flags;
	struct idr rh_reserved_cgroup_idr;
	char release_agent_path[4096];
	char name[64];
};

struct cftype {
	char name[64];
	long unsigned int private;
	size_t max_write_len;
	unsigned int flags;
	unsigned int file_offset;
	struct cgroup_subsys *ss;
	struct list_head node;
	struct kernfs_ops *kf_ops;
	int (*open)(struct kernfs_open_file *);
	void (*release)(struct kernfs_open_file *);
	u64 (*read_u64)(struct cgroup_subsys_state *, struct cftype *);
	s64 (*read_s64)(struct cgroup_subsys_state *, struct cftype *);
	int (*seq_show)(struct seq_file *, void *);
	void * (*seq_start)(struct seq_file *, loff_t *);
	void * (*seq_next)(struct seq_file *, void *, loff_t *);
	void (*seq_stop)(struct seq_file *, void *);
	int (*write_u64)(struct cgroup_subsys_state *, struct cftype *, u64);
	int (*write_s64)(struct cgroup_subsys_state *, struct cftype *, s64);
	ssize_t (*write)(struct kernfs_open_file *, char *, size_t, loff_t);
	__poll_t (*poll)(struct kernfs_open_file *, struct poll_table_struct *);
};

struct static_call_key {
	void *func;
};

struct perf_callchain_entry {
	__u64 nr;
	__u64 ip[0];
};

typedef long unsigned int (*perf_copy_f)(void *, const void *, long unsigned int, long unsigned int);

struct perf_raw_frag {
	union {
		struct perf_raw_frag *next;
		long unsigned int pad;
	};
	perf_copy_f copy;
	void *data;
	u32 size;
} __attribute__((packed));

struct perf_raw_record {
	struct perf_raw_frag frag;
	u32 size;
};

struct perf_branch_stack {
	__u64 nr;
	__u64 hw_idx;
	struct perf_branch_entry entries[0];
};

struct perf_cpu_context {
	struct perf_event_context ctx;
	struct perf_event_context *task_ctx;
	int active_oncpu;
	int exclusive;
	raw_spinlock_t hrtimer_lock;
	struct hrtimer hrtimer;
	ktime_t hrtimer_interval;
	unsigned int hrtimer_active;
	struct perf_cgroup *cgrp;
	struct list_head cgrp_cpuctx_entry;
	struct list_head sched_cb_entry;
	int sched_cb_usage;
	int online;
	int heap_size;
	struct perf_event **heap;
	struct perf_event *heap_default[2];
};

struct perf_output_handle {
	struct perf_event *event;
	union {
		struct perf_buffer *rb;
		struct {
			struct ring_buffer *rb;
		} rh_kabi_hidden_930;
		union {		};
	};
	long unsigned int wakeup;
	long unsigned int size;
	u64 aux_flags;
	union {
		void *addr;
		long unsigned int head;
	};
	int page;
};

struct perf_addr_filter_range {
	long unsigned int start;
	long unsigned int size;
};

struct perf_sample_data {
	u64 sample_flags;
	u64 addr;
	struct perf_raw_record *raw;
	struct perf_branch_stack *br_stack;
	u64 period;
	union {
		union perf_sample_weight weight;
		struct {
			u64 weight;
		} rh_kabi_hidden_1043;
		union {		};
	};
	u64 txn;
	union perf_mem_data_src data_src;
	u64 type;
	u64 ip;
	struct {
		u32 pid;
		u32 tid;
	} tid_entry;
	u64 time;
	u64 id;
	u64 stream_id;
	struct {
		u32 cpu;
		u32 reserved;
	} cpu_entry;
	struct perf_callchain_entry *callchain;
	u64 aux_size;
	struct perf_regs regs_user;
	struct perf_regs regs_intr;
	u64 stack_user_size;
	u64 phys_addr;
	u64 cgroup;
	u64 data_page_size;
	u64 code_page_size;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
};

struct perf_cgroup_info;

struct perf_cgroup {
	struct cgroup_subsys_state css;
	struct perf_cgroup_info *info;
};

struct perf_cgroup_info {
	u64 time;
	u64 timestamp;
};

struct trace_entry {
	short unsigned int type;
	unsigned char flags;
	unsigned char preempt_count;
	int pid;
};

struct trace_array;

struct tracer;

struct array_buffer;

struct trace_buffer;

struct ring_buffer_iter;

struct trace_iterator {
	struct trace_array *tr;
	struct tracer *trace;
	union {
		struct array_buffer *array_buffer;
		struct {
			struct trace_buffer *trace_buffer;
		} rh_kabi_hidden_83;
		union {		};
	};
	void *private;
	int cpu_file;
	struct mutex mutex;
	struct ring_buffer_iter **buffer_iter;
	long unsigned int iter_flags;
	struct trace_seq tmp_seq;
	cpumask_var_t started;
	bool snapshot;
	struct trace_seq seq;
	struct trace_entry *ent;
	long unsigned int lost_events;
	int leftover;
	int ent_size;
	int cpu;
	u64 ts;
	loff_t pos;
	long int idx;
};

enum print_line_t {
	TRACE_TYPE_PARTIAL_LINE = 0,
	TRACE_TYPE_HANDLED = 1,
	TRACE_TYPE_UNHANDLED = 2,
	TRACE_TYPE_NO_CONSUME = 3,
};

typedef enum print_line_t (*trace_print_func)(struct trace_iterator *, int, struct trace_event *);

struct trace_event_functions {
	trace_print_func trace;
	trace_print_func raw;
	trace_print_func hex;
	trace_print_func binary;
};

enum trace_reg {
	TRACE_REG_REGISTER = 0,
	TRACE_REG_UNREGISTER = 1,
	TRACE_REG_PERF_REGISTER = 2,
	TRACE_REG_PERF_UNREGISTER = 3,
	TRACE_REG_PERF_OPEN = 4,
	TRACE_REG_PERF_CLOSE = 5,
	TRACE_REG_PERF_ADD = 6,
	TRACE_REG_PERF_DEL = 7,
};

struct trace_event_class {
	const char *system;
	void *probe;
	void *perf_probe;
	int (*reg)(struct trace_event_call *, enum trace_reg, void *);
	int (*define_fields)(struct trace_event_call *);
	struct list_head * (*get_fields)(struct trace_event_call *);
	struct list_head fields;
	int (*raw_init)(struct trace_event_call *);
};

struct trace_event_file;

struct trace_event_buffer {
	struct trace_buffer *buffer;
	struct ring_buffer_event *event;
	struct trace_event_file *trace_file;
	void *entry;
	long unsigned int flags;
	int pc;
};

struct trace_subsystem_dir;

struct trace_event_file {
	struct list_head list;
	struct trace_event_call *event_call;
	struct event_filter *filter;
	struct dentry *dir;
	struct trace_array *tr;
	struct trace_subsystem_dir *system;
	struct list_head triggers;
	long unsigned int flags;
	atomic_t sm_ref;
	atomic_t tm_ref;
};

enum {
	TRACE_EVENT_FL_FILTERED_BIT = 0,
	TRACE_EVENT_FL_CAP_ANY_BIT = 1,
	TRACE_EVENT_FL_NO_SET_FILTER_BIT = 2,
	TRACE_EVENT_FL_IGNORE_ENABLE_BIT = 3,
	TRACE_EVENT_FL_TRACEPOINT_BIT = 4,
	TRACE_EVENT_FL_KPROBE_BIT = 5,
	TRACE_EVENT_FL_UPROBE_BIT = 6,
};

enum {
	TRACE_EVENT_FL_FILTERED = 1,
	TRACE_EVENT_FL_CAP_ANY = 2,
	TRACE_EVENT_FL_NO_SET_FILTER = 4,
	TRACE_EVENT_FL_IGNORE_ENABLE = 8,
	TRACE_EVENT_FL_TRACEPOINT = 16,
	TRACE_EVENT_FL_KPROBE = 32,
	TRACE_EVENT_FL_UPROBE = 64,
};

enum {
	EVENT_FILE_FL_ENABLED_BIT = 0,
	EVENT_FILE_FL_RECORDED_CMD_BIT = 1,
	EVENT_FILE_FL_RECORDED_TGID_BIT = 2,
	EVENT_FILE_FL_FILTERED_BIT = 3,
	EVENT_FILE_FL_NO_SET_FILTER_BIT = 4,
	EVENT_FILE_FL_SOFT_MODE_BIT = 5,
	EVENT_FILE_FL_SOFT_DISABLED_BIT = 6,
	EVENT_FILE_FL_TRIGGER_MODE_BIT = 7,
	EVENT_FILE_FL_TRIGGER_COND_BIT = 8,
	EVENT_FILE_FL_PID_FILTER_BIT = 9,
	EVENT_FILE_FL_WAS_ENABLED_BIT = 10,
};

enum {
	EVENT_FILE_FL_ENABLED = 1,
	EVENT_FILE_FL_RECORDED_CMD = 2,
	EVENT_FILE_FL_RECORDED_TGID = 4,
	EVENT_FILE_FL_FILTERED = 8,
	EVENT_FILE_FL_NO_SET_FILTER = 16,
	EVENT_FILE_FL_SOFT_MODE = 32,
	EVENT_FILE_FL_SOFT_DISABLED = 64,
	EVENT_FILE_FL_TRIGGER_MODE = 128,
	EVENT_FILE_FL_TRIGGER_COND = 256,
	EVENT_FILE_FL_PID_FILTER = 512,
	EVENT_FILE_FL_WAS_ENABLED = 1024,
};

enum {
	FILTER_OTHER = 0,
	FILTER_STATIC_STRING = 1,
	FILTER_DYN_STRING = 2,
	FILTER_PTR_STRING = 3,
	FILTER_TRACE_FN = 4,
	FILTER_COMM = 5,
	FILTER_CPU = 6,
};

struct rtc_time {
	int tm_sec;
	int tm_min;
	int tm_hour;
	int tm_mday;
	int tm_mon;
	int tm_year;
	int tm_wday;
	int tm_yday;
	int tm_isdst;
};

enum memblock_flags {
	MEMBLOCK_NONE = 0,
	MEMBLOCK_HOTPLUG = 1,
	MEMBLOCK_MIRROR = 2,
	MEMBLOCK_NOMAP = 4,
};

struct memblock_region {
	phys_addr_t base;
	phys_addr_t size;
	enum memblock_flags flags;
	int nid;
};

struct memblock_type {
	long unsigned int cnt;
	long unsigned int max;
	phys_addr_t total_size;
	struct memblock_region *regions;
	char *name;
};

struct memblock {
	bool bottom_up;
	phys_addr_t current_limit;
	struct memblock_type memory;
	struct memblock_type reserved;
};

enum con_scroll {
	SM_UP = 0,
	SM_DOWN = 1,
};

struct vc_data;

struct console_font;

struct consw {
	struct module *owner;
	const char * (*con_startup)();
	void (*con_init)(struct vc_data *, int);
	void (*con_deinit)(struct vc_data *);
	void (*con_clear)(struct vc_data *, int, int, int, int);
	void (*con_putc)(struct vc_data *, int, int, int);
	void (*con_putcs)(struct vc_data *, const short unsigned int *, int, int, int);
	void (*con_cursor)(struct vc_data *, int);
	bool (*con_scroll)(struct vc_data *, unsigned int, unsigned int, enum con_scroll, unsigned int);
	int (*con_switch)(struct vc_data *);
	int (*con_blank)(struct vc_data *, int, int);
	int (*con_font_set)(struct vc_data *, struct console_font *, unsigned int);
	int (*con_font_get)(struct vc_data *, struct console_font *);
	int (*con_font_default)(struct vc_data *, struct console_font *, char *);
	int (*con_font_copy)(struct vc_data *, int);
	int (*con_resize)(struct vc_data *, unsigned int, unsigned int, unsigned int);
	void (*con_set_palette)(struct vc_data *, const unsigned char *);
	void (*con_scrolldelta)(struct vc_data *, int);
	int (*con_set_origin)(struct vc_data *);
	void (*con_save_screen)(struct vc_data *);
	u8 (*con_build_attr)(struct vc_data *, u8, u8, u8, u8, u8, u8);
	void (*con_invert_region)(struct vc_data *, u16 *, int);
	u16 * (*con_screen_pos)(struct vc_data *, int);
	long unsigned int (*con_getxy)(struct vc_data *, long unsigned int, int *, int *);
	void (*con_flush_scrollback)(struct vc_data *);
	int (*con_debug_enter)(struct vc_data *);
	int (*con_debug_leave)(struct vc_data *);
};

struct tty_driver;

struct console {
	char name[16];
	void (*write)(struct console *, const char *, unsigned int);
	int (*read)(struct console *, char *, unsigned int);
	struct tty_driver * (*device)(struct console *, int *);
	void (*unblank)();
	int (*setup)(struct console *, char *);
	int (*exit)(struct console *);
	int (*match)(struct console *, char *, int, char *);
	short int flags;
	short int index;
	int cflag;
	void *data;
	struct console *next;
};

enum wb_stat_item {
	WB_RECLAIMABLE = 0,
	WB_WRITEBACK = 1,
	WB_DIRTIED = 2,
	WB_WRITTEN = 3,
	NR_WB_STAT_ITEMS = 4,
};

struct bdi_writeback_congested {
	long unsigned int state;
	union {
		refcount_t refcnt;
		struct {
			atomic_t refcnt;
		} rh_kabi_hidden_96;
		union {		};
	};
	struct backing_dev_info *__bdi;
	int blkcg_id;
	struct rb_node rb_node;
};

struct bdi_writeback_rh {
	struct delayed_work bw_dwork;
	struct list_head _b_attached;
};

struct bio_integrity_payload {
	struct bio *bip_bio;
	struct bvec_iter bip_iter;
	short unsigned int rh_reserved_bip_slab;
	short unsigned int bip_vcnt;
	short unsigned int bip_max_vcnt;
	short unsigned int bip_flags;
	struct bvec_iter bio_iter;
	struct work_struct bip_work;
	struct bio_vec *bip_vec;
	long unsigned int rh_reserved1;
	long unsigned int rh_reserved2;
	struct bio_vec bip_inline_vecs[0];
};

struct blkg_iostat {
	u64 bytes[3];
	u64 ios[3];
};

struct blkg_iostat_set {
	struct u64_stats_sync sync;
	struct blkg_iostat cur;
	struct blkg_iostat last;
	struct blkcg_gq *blkg;
	struct llist_node lnode;
	int lqueued;
};

struct blkg_rwstat {
	struct percpu_counter cpu_cnt[5];
	atomic64_t aux_cnt[5];
};

struct blkcg;

struct blkg_policy_data;

struct blkcg_gq {
	struct request_queue *q;
	struct list_head q_node;
	struct hlist_node blkcg_node;
	struct blkcg *blkcg;
	struct bdi_writeback_congested *rh_reserved_wb_congested;
	struct blkcg_gq *parent;
	struct percpu_ref refcnt;
	bool online;
	union {
		struct {
			struct blkg_iostat_set *iostat_cpu;
			struct blkg_iostat_set iostat;
		};
		struct {
			struct blkg_rwstat stat_bytes;
		} rh_kabi_hidden_177;
		union {		};
	};
	struct blkg_rwstat rh_reserved_stat_ios;
	struct blkg_policy_data *pd[5];
	struct callback_head callback_head;
	atomic_t use_delay;
	atomic64_t delay_nsec;
	atomic64_t delay_start;
	u64 last_delay;
	int last_use;
	spinlock_t async_bio_lock;
	struct bio_list async_bios;
	struct work_struct async_bio_work;
};

enum stat_group {
	STAT_READ = 0,
	STAT_WRITE = 1,
	STAT_DISCARD = 2,
	NR_STAT_GROUPS = 3,
};

struct disk_stats {
	u64 nsecs[3];
	long unsigned int sectors[3];
	long unsigned int ios[3];
	long unsigned int merges[3];
	long unsigned int io_ticks;
	long unsigned int rh_reserved_time_in_queue;
	local_t in_flight[2];
};

struct partition_meta_info {
	char uuid[37];
	u8 volname[64];
};

struct disk_part_tbl {
	struct callback_head callback_head;
	int len;
	struct hd_struct *last_lookup;
	struct hd_struct *part[0];
};

struct blk_integrity_iter;

typedef blk_status_t integrity_processing_fn(struct blk_integrity_iter *);

struct blk_integrity_profile_ext_ops;

struct blk_integrity_profile {
	integrity_processing_fn *generate_fn;
	integrity_processing_fn *verify_fn;
	const char *name;
	union {
		const struct blk_integrity_profile_ext_ops *ext_ops;
		struct {
			long unsigned int rh_reserved1;
		} rh_kabi_hidden_1643;
		union {		};
	};
	long unsigned int rh_reserved2;
};

struct blk_zone;

typedef int (*report_zones_cb)(struct blk_zone *, unsigned int, void *);

struct hd_geometry;

struct pr_ops;

struct block_device_operations {
	int (*open)(struct block_device *, fmode_t);
	void (*release)(struct gendisk *, fmode_t);
	int (*rw_page)(struct block_device *, sector_t, struct page *, unsigned int);
	int (*ioctl)(struct block_device *, fmode_t, unsigned int, long unsigned int);
	int (*compat_ioctl)(struct block_device *, fmode_t, unsigned int, long unsigned int);
	unsigned int (*check_events)(struct gendisk *, unsigned int);
	int (*media_changed)(struct gendisk *);
	void (*unlock_native_capacity)(struct gendisk *);
	int (*revalidate_disk)(struct gendisk *);
	int (*getgeo)(struct block_device *, struct hd_geometry *);
	void (*swap_slot_free_notify)(struct block_device *, long unsigned int);
	union {
		int (*report_zones)(struct gendisk *, sector_t, unsigned int, report_zones_cb, void *);
		struct {
			int (*report_zones)(struct gendisk *, sector_t, struct blk_zone *, unsigned int *, gfp_t);
		} rh_kabi_hidden_1811;
		union {		};
	};
	struct module *owner;
	const struct pr_ops *pr_ops;
	union {
		char * (*devnode)(struct gendisk *, umode_t *);
		struct {
			long unsigned int rh_reserved1;
		} rh_kabi_hidden_1815;
		union {		};
	};
	union {
		int (*set_read_only)(struct block_device *, bool);
		struct {
			long unsigned int rh_reserved2;
		} rh_kabi_hidden_1816;
		union {		};
	};
	long unsigned int rh_reserved3;
	long unsigned int rh_reserved4;
};

struct sg_io_v4 {
	__s32 guard;
	__u32 protocol;
	__u32 subprotocol;
	__u32 request_len;
	__u64 request;
	__u64 request_tag;
	__u32 request_attr;
	__u32 request_priority;
	__u32 request_extra;
	__u32 max_response_len;
	__u64 response;
	__u32 dout_iovec_count;
	__u32 dout_xfer_len;
	__u32 din_iovec_count;
	__u32 din_xfer_len;
	__u64 dout_xferp;
	__u64 din_xferp;
	__u32 timeout;
	__u32 flags;
	__u64 usr_ptr;
	__u32 spare_in;
	__u32 driver_status;
	__u32 transport_status;
	__u32 device_status;
	__u32 retry_delay;
	__u32 info;
	__u32 duration;
	__u32 response_len;
	__s32 din_resid;
	__s32 dout_resid;
	__u64 generated_tag;
	__u32 spare_out;
	__u32 padding;
};

struct bsg_ops {
	int (*check_proto)(struct sg_io_v4 *);
	int (*fill_hdr)(struct request *, struct sg_io_v4 *, fmode_t);
	int (*complete_rq)(struct request *, struct sg_io_v4 *);
	void (*free_rq)(struct request *);
	long unsigned int rh_reserved1;
	long unsigned int rh_reserved2;
};

typedef __u32 req_flags_t;

typedef void rq_end_io_fn(struct request *, blk_status_t);

enum mq_rq_state {
	MQ_RQ_IDLE = 0,
	MQ_RQ_IN_FLIGHT = 1,
	MQ_RQ_COMPLETE = 2,
};

struct request {
	struct request_queue *q;
	struct blk_mq_ctx *mq_ctx;
	struct blk_mq_hw_ctx *mq_hctx;
	unsigned int cmd_flags;
	req_flags_t rq_flags;
	int internal_tag;
	unsigned int __data_len;
	int tag;
	sector_t __sector;
	struct bio *bio;
	struct bio *biotail;
	struct list_head queuelist;
	union {
		struct hlist_node hash;
		union {
			struct llist_node ipi_list;
			struct {
				struct list_head ipi_list;
			} rh_kabi_hidden_165;
			union {			};
		};
	};
	union {
		struct rb_node rb_node;
		struct bio_vec special_vec;
		void *completion_data;
		int error_count;
	};
	union {
		struct {
			struct io_cq *icq;
			void *priv[2];
		} elv;
		struct {
			unsigned int seq;
			struct list_head list;
			rq_end_io_fn *saved_end_io;
		} flush;
	};
	struct gendisk *rq_disk;
	struct hd_struct *part;
	u64 start_time_ns;
	u64 io_start_time_ns;
	short unsigned int wbt_flags;
	short unsigned int nr_phys_segments;
	short unsigned int nr_integrity_segments;
	short unsigned int write_hint;
	short unsigned int ioprio;
	void *rh_reserved_special;
	unsigned int extra_len;
	enum mq_rq_state state;
	refcount_t ref;
	unsigned int timeout;
	long unsigned int deadline;
	union {
		struct __call_single_data csd;
		u64 fifo_time;
	};
	rq_end_io_fn *end_io;
	void *end_io_data;
	struct request *rh_reserved_next_rq;
};

struct blk_zone {
	__u64 start;
	__u64 len;
	__u64 wp;
	__u8 type;
	__u8 cond;
	__u8 non_seq;
	__u8 reset;
	__u8 resv[4];
	__u64 capacity;
	__u8 reserved[24];
};

struct sbitmap_word {
	long unsigned int depth;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long unsigned int word;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long unsigned int cleared;
	spinlock_t rh_reserved_swap_lock;
	long: 32;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
};

struct sbq_wait_state {
	atomic_t wait_cnt;
	wait_queue_head_t wait;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
};

enum elv_merge {
	ELEVATOR_NO_MERGE = 0,
	ELEVATOR_FRONT_MERGE = 1,
	ELEVATOR_BACK_MERGE = 2,
	ELEVATOR_DISCARD_MERGE = 3,
};

struct elevator_type;

struct blk_mq_alloc_data;

struct elevator_mq_ops {
	int (*init_sched)(struct request_queue *, struct elevator_type *);
	void (*exit_sched)(struct elevator_queue *);
	int (*init_hctx)(struct blk_mq_hw_ctx *, unsigned int);
	void (*exit_hctx)(struct blk_mq_hw_ctx *, unsigned int);
	bool (*allow_merge)(struct request_queue *, struct request *, struct bio *);
	bool (*bio_merge)(struct blk_mq_hw_ctx *, struct bio *);
	int (*request_merge)(struct request_queue *, struct request **, struct bio *);
	void (*request_merged)(struct request_queue *, struct request *, enum elv_merge);
	void (*requests_merged)(struct request_queue *, struct request *, struct request *);
	void (*limit_depth)(unsigned int, struct blk_mq_alloc_data *);
	void (*prepare_request)(struct request *, struct bio *);
	void (*finish_request)(struct request *);
	void (*insert_requests)(struct blk_mq_hw_ctx *, struct list_head *, bool);
	struct request * (*dispatch_request)(struct blk_mq_hw_ctx *);
	bool (*has_work)(struct blk_mq_hw_ctx *);
	void (*completed_request)(struct request *, u64);
	void (*started_request)(struct request *);
	void (*requeue_request)(struct request *);
	struct request * (*former_request)(struct request_queue *, struct request *);
	struct request * (*next_request)(struct request_queue *, struct request *);
	void (*init_icq)(struct io_cq *);
	void (*exit_icq)(struct io_cq *);
	union {
		void (*depth_updated)(struct blk_mq_hw_ctx *);
		struct {
			long unsigned int rh_reserved1;
		} rh_kabi_hidden_54;
		union {		};
	};
	long unsigned int rh_reserved2;
	long unsigned int rh_reserved3;
	long unsigned int rh_reserved4;
	long unsigned int rh_reserved5;
	long unsigned int rh_reserved6;
	long unsigned int rh_reserved7;
	long unsigned int rh_reserved8;
};

struct elv_fs_entry;

struct blk_mq_debugfs_attr;

struct elevator_type {
	struct kmem_cache *icq_cache;
	struct elevator_mq_ops ops;
	size_t icq_size;
	size_t icq_align;
	struct elv_fs_entry *elevator_attrs;
	char elevator_name[16];
	const char *elevator_alias;
	struct module *elevator_owner;
	const struct blk_mq_debugfs_attr *queue_debugfs_attrs;
	const struct blk_mq_debugfs_attr *hctx_debugfs_attrs;
	char icq_cache_name[22];
	struct list_head list;
	union {
		const unsigned int elevator_features;
		struct {
			long unsigned int rh_reserved1;
		} rh_kabi_hidden_98;
		union {		};
	};
	long unsigned int rh_reserved2;
	long unsigned int rh_reserved3;
	long unsigned int rh_reserved4;
};

struct elevator_queue {
	struct elevator_type *type;
	void *elevator_data;
	struct kobject kobj;
	struct mutex sysfs_lock;
	unsigned int registered: 1;
	struct hlist_head hash[64];
};

struct elv_fs_entry {
	struct attribute attr;
	ssize_t (*show)(struct elevator_queue *, char *);
	ssize_t (*store)(struct elevator_queue *, const char *, size_t);
};

struct blk_mq_debugfs_attr {
	const char *name;
	umode_t mode;
	int (*show)(void *, struct seq_file *);
	ssize_t (*write)(void *, const char *, size_t, loff_t *);
	const struct seq_operations *seq_ops;
};

struct blk_mq_queue_data;

typedef blk_status_t queue_rq_fn(struct blk_mq_hw_ctx *, const struct blk_mq_queue_data *);

typedef void commit_rqs_fn(struct blk_mq_hw_ctx *);

typedef int get_budget_fn(struct request_queue *);

typedef void put_budget_fn(struct request_queue *, int);

enum blk_eh_timer_return {
	BLK_EH_DONE = 0,
	BLK_EH_RESET_TIMER = 1,
};

typedef enum blk_eh_timer_return timeout_fn(struct request *, bool);

typedef int poll_fn(struct blk_mq_hw_ctx *);

typedef void complete_fn(struct request *);

typedef int init_hctx_fn(struct blk_mq_hw_ctx *, void *, unsigned int);

typedef void exit_hctx_fn(struct blk_mq_hw_ctx *, unsigned int);

typedef int init_request_fn(struct blk_mq_tag_set *, struct request *, unsigned int, unsigned int);

typedef void exit_request_fn(struct blk_mq_tag_set *, struct request *, unsigned int);

typedef bool busy_fn(struct request_queue *);

typedef int map_queues_fn(struct blk_mq_tag_set *);

typedef void cleanup_rq_fn(struct request *);

struct blk_mq_ops {
	queue_rq_fn *queue_rq;
	commit_rqs_fn *commit_rqs;
	get_budget_fn *get_budget;
	put_budget_fn *put_budget;
	timeout_fn *timeout;
	poll_fn *poll;
	complete_fn *complete;
	init_hctx_fn *init_hctx;
	exit_hctx_fn *exit_hctx;
	init_request_fn *init_request;
	exit_request_fn *exit_request;
	void (*initialize_rq_fn)(struct request *);
	busy_fn *busy;
	map_queues_fn *map_queues;
	void (*show_rq)(struct seq_file *, struct request *);
	union {
		cleanup_rq_fn *cleanup_rq;
		struct {
			long unsigned int rh_reserved1;
		} rh_kabi_hidden_292;
		union {		};
	};
	union {
		void (*set_rq_budget_token)(struct request *, int);
		struct {
			long unsigned int rh_reserved2;
		} rh_kabi_hidden_297;
		union {		};
	};
	union {
		int (*get_rq_budget_token)(struct request *);
		struct {
			long unsigned int rh_reserved3;
		} rh_kabi_hidden_302;
		union {		};
	};
	long unsigned int rh_reserved4;
	long unsigned int rh_reserved5;
	long unsigned int rh_reserved6;
	long unsigned int rh_reserved7;
	long unsigned int rh_reserved8;
};

struct blk_integrity_iter {
	void *prot_buf;
	void *data_buf;
	sector_t seed;
	unsigned int data_size;
	short unsigned int interval;
	const char *disk_name;
};

typedef void integrity_prepare_fn(struct request *);

typedef void integrity_complete_fn(struct request *, unsigned int);

struct blk_integrity_profile_ext_ops {
	integrity_prepare_fn *prepare_fn;
	integrity_complete_fn *complete_fn;
	long unsigned int rh_reserved1;
	long unsigned int rh_reserved2;
	long unsigned int rh_reserved3;
	long unsigned int rh_reserved4;
};

enum pr_type {
	PR_WRITE_EXCLUSIVE = 1,
	PR_EXCLUSIVE_ACCESS = 2,
	PR_WRITE_EXCLUSIVE_REG_ONLY = 3,
	PR_EXCLUSIVE_ACCESS_REG_ONLY = 4,
	PR_WRITE_EXCLUSIVE_ALL_REGS = 5,
	PR_EXCLUSIVE_ACCESS_ALL_REGS = 6,
};

struct pr_ops {
	int (*pr_register)(struct block_device *, u64, u64, u32);
	int (*pr_reserve)(struct block_device *, u64, enum pr_type, u32);
	int (*pr_release)(struct block_device *, u64, enum pr_type);
	int (*pr_preempt)(struct block_device *, u64, u64, enum pr_type, bool);
	int (*pr_clear)(struct block_device *, u64);
};

enum blkg_rwstat_type {
	BLKG_RWSTAT_READ = 0,
	BLKG_RWSTAT_WRITE = 1,
	BLKG_RWSTAT_SYNC = 2,
	BLKG_RWSTAT_ASYNC = 3,
	BLKG_RWSTAT_DISCARD = 4,
	BLKG_RWSTAT_NR = 5,
	BLKG_RWSTAT_TOTAL = 5,
};

enum blkg_iostat_type {
	BLKG_IOSTAT_READ = 0,
	BLKG_IOSTAT_WRITE = 1,
	BLKG_IOSTAT_DISCARD = 2,
	BLKG_IOSTAT_NR = 3,
};

struct blkcg_policy_data;

struct blkcg {
	struct cgroup_subsys_state css;
	spinlock_t lock;
	struct xarray blkg_tree;
	struct blkcg_gq *blkg_hint;
	struct hlist_head blkg_list;
	struct blkcg_policy_data *cpd[5];
	struct list_head all_blkcgs_node;
	struct list_head cgwb_list;
	refcount_t cgwb_refcnt;
	union {
		refcount_t online_pin;
		struct {
			long unsigned int rh_reserved1;
		} rh_kabi_hidden_93;
		union {		};
	};
	union {
		struct llist_head *lhead;
		struct {
			long unsigned int rh_reserved2;
		} rh_kabi_hidden_97;
		union {		};
	};
	long unsigned int rh_reserved3;
	long unsigned int rh_reserved4;
	char fc_app_id[129];
};

struct blkcg_policy_data {
	struct blkcg *blkcg;
	int plid;
};

struct blkg_policy_data {
	struct blkcg_gq *blkg;
	int plid;
};

enum cpu_idle_type {
	CPU_IDLE = 0,
	CPU_NOT_IDLE = 1,
	CPU_NEWLY_IDLE = 2,
	CPU_MAX_IDLE_TYPES = 3,
};

enum reboot_mode {
	REBOOT_COLD = 0,
	REBOOT_WARM = 1,
	REBOOT_HARD = 2,
	REBOOT_SOFT = 3,
	REBOOT_GPIO = 4,
};

enum reboot_type {
	BOOT_TRIPLE = 116,
	BOOT_KBD = 107,
	BOOT_BIOS = 98,
	BOOT_ACPI = 97,
	BOOT_EFI = 101,
	BOOT_CF9_FORCE = 112,
	BOOT_CF9_SAFE = 113,
};

struct screen_info {
	__u8 orig_x;
	__u8 orig_y;
	__u16 ext_mem_k;
	__u16 orig_video_page;
	__u8 orig_video_mode;
	__u8 orig_video_cols;
	__u8 flags;
	__u8 unused2;
	__u16 orig_video_ega_bx;
	__u16 unused3;
	__u8 orig_video_lines;
	__u8 orig_video_isVGA;
	__u16 orig_video_points;
	__u16 lfb_width;
	__u16 lfb_height;
	__u16 lfb_depth;
	__u32 lfb_base;
	__u32 lfb_size;
	__u16 cl_magic;
	__u16 cl_offset;
	__u16 lfb_linelength;
	__u8 red_size;
	__u8 red_pos;
	__u8 green_size;
	__u8 green_pos;
	__u8 blue_size;
	__u8 blue_pos;
	__u8 rsvd_size;
	__u8 rsvd_pos;
	__u16 vesapm_seg;
	__u16 vesapm_off;
	__u16 pages;
	__u16 vesa_attributes;
	__u32 capabilities;
	__u32 ext_lfb_base;
	__u8 _reserved[2];
} __attribute__((packed));

typedef long unsigned int efi_status_t;

typedef u8 efi_bool_t;

typedef u16 efi_char16_t;

typedef u64 efi_physical_addr_t;

typedef void *efi_handle_t;

typedef guid_t efi_guid_t;

typedef struct {
	u64 signature;
	u32 revision;
	u32 headersize;
	u32 crc32;
	u32 reserved;
} efi_table_hdr_t;

typedef struct {
	u32 type;
	u32 pad;
	u64 phys_addr;
	u64 virt_addr;
	u64 num_pages;
	u64 attribute;
} efi_memory_desc_t;

typedef struct {
	efi_guid_t guid;
	u32 headersize;
	u32 flags;
	u32 imagesize;
} efi_capsule_header_t;

typedef struct {
	u16 year;
	u8 month;
	u8 day;
	u8 hour;
	u8 minute;
	u8 second;
	u8 pad1;
	u32 nanosecond;
	s16 timezone;
	u8 daylight;
	u8 pad2;
} efi_time_t;

typedef struct {
	u32 resolution;
	u32 accuracy;
	u8 sets_to_zero;
} efi_time_cap_t;

typedef struct {
	efi_table_hdr_t hdr;
	u32 raise_tpl;
	u32 restore_tpl;
	u32 allocate_pages;
	u32 free_pages;
	u32 get_memory_map;
	u32 allocate_pool;
	u32 free_pool;
	u32 create_event;
	u32 set_timer;
	u32 wait_for_event;
	u32 signal_event;
	u32 close_event;
	u32 check_event;
	u32 install_protocol_interface;
	u32 reinstall_protocol_interface;
	u32 uninstall_protocol_interface;
	u32 handle_protocol;
	u32 __reserved;
	u32 register_protocol_notify;
	u32 locate_handle;
	u32 locate_device_path;
	u32 install_configuration_table;
	u32 load_image;
	u32 start_image;
	u32 exit;
	u32 unload_image;
	u32 exit_boot_services;
	u32 get_next_monotonic_count;
	u32 stall;
	u32 set_watchdog_timer;
	u32 connect_controller;
	u32 disconnect_controller;
	u32 open_protocol;
	u32 close_protocol;
	u32 open_protocol_information;
	u32 protocols_per_handle;
	u32 locate_handle_buffer;
	u32 locate_protocol;
	u32 install_multiple_protocol_interfaces;
	u32 uninstall_multiple_protocol_interfaces;
	u32 calculate_crc32;
	u32 copy_mem;
	u32 set_mem;
	u32 create_event_ex;
} efi_boot_services_32_t;

typedef union {
	struct {
		efi_table_hdr_t hdr;
		void *raise_tpl;
		void *restore_tpl;
		efi_status_t (*allocate_pages)(int, int, long unsigned int, efi_physical_addr_t *);
		efi_status_t (*free_pages)(efi_physical_addr_t, long unsigned int);
		efi_status_t (*get_memory_map)(long unsigned int *, void *, long unsigned int *, long unsigned int *, u32 *);
		efi_status_t (*allocate_pool)(int, long unsigned int, void **);
		efi_status_t (*free_pool)(void *);
		void *create_event;
		void *set_timer;
		void *wait_for_event;
		void *signal_event;
		void *close_event;
		void *check_event;
		void *install_protocol_interface;
		void *reinstall_protocol_interface;
		void *uninstall_protocol_interface;
		efi_status_t (*handle_protocol)(efi_handle_t, efi_guid_t *, void **);
		void *__reserved;
		void *register_protocol_notify;
		efi_status_t (*locate_handle)(int, efi_guid_t *, void *, long unsigned int *, efi_handle_t *);
		void *locate_device_path;
		efi_status_t (*install_configuration_table)(efi_guid_t *, void *);
		void *load_image;
		void *start_image;
		efi_status_t (*exit)(efi_handle_t, efi_status_t, long unsigned int, efi_char16_t *);
		void *unload_image;
		efi_status_t (*exit_boot_services)(efi_handle_t, long unsigned int);
		void *get_next_monotonic_count;
		void *stall;
		void *set_watchdog_timer;
		void *connect_controller;
		void *disconnect_controller;
		void *open_protocol;
		void *close_protocol;
		void *open_protocol_information;
		void *protocols_per_handle;
		void *locate_handle_buffer;
		efi_status_t (*locate_protocol)(efi_guid_t *, void *, void **);
		void *install_multiple_protocol_interfaces;
		void *uninstall_multiple_protocol_interfaces;
		void *calculate_crc32;
		void *copy_mem;
		void *set_mem;
		void *create_event_ex;
	};
	efi_boot_services_32_t mixed_mode;
} efi_boot_services_t;

typedef struct {
	efi_table_hdr_t hdr;
	u32 get_time;
	u32 set_time;
	u32 get_wakeup_time;
	u32 set_wakeup_time;
	u32 set_virtual_address_map;
	u32 convert_pointer;
	u32 get_variable;
	u32 get_next_variable;
	u32 set_variable;
	u32 get_next_high_mono_count;
	u32 reset_system;
	u32 update_capsule;
	u32 query_capsule_caps;
	u32 query_variable_info;
} efi_runtime_services_32_t;

typedef efi_status_t efi_get_time_t(efi_time_t *, efi_time_cap_t *);

typedef efi_status_t efi_set_time_t(efi_time_t *);

typedef efi_status_t efi_get_wakeup_time_t(efi_bool_t *, efi_bool_t *, efi_time_t *);

typedef efi_status_t efi_set_wakeup_time_t(efi_bool_t, efi_time_t *);

typedef efi_status_t efi_get_variable_t(efi_char16_t *, efi_guid_t *, u32 *, long unsigned int *, void *);

typedef efi_status_t efi_get_next_variable_t(long unsigned int *, efi_char16_t *, efi_guid_t *);

typedef efi_status_t efi_set_variable_t(efi_char16_t *, efi_guid_t *, u32, long unsigned int, void *);

typedef efi_status_t efi_get_next_high_mono_count_t(u32 *);

typedef void efi_reset_system_t(int, efi_status_t, long unsigned int, efi_char16_t *);

typedef efi_status_t efi_set_virtual_address_map_t(long unsigned int, long unsigned int, u32, efi_memory_desc_t *);

typedef efi_status_t efi_query_variable_info_t(u32, u64 *, u64 *, u64 *);

typedef efi_status_t efi_update_capsule_t(efi_capsule_header_t **, long unsigned int, long unsigned int);

typedef efi_status_t efi_query_capsule_caps_t(efi_capsule_header_t **, long unsigned int, u64 *, int *);

typedef union {
	struct {
		efi_table_hdr_t hdr;
		efi_get_time_t *get_time;
		efi_set_time_t *set_time;
		efi_get_wakeup_time_t *get_wakeup_time;
		efi_set_wakeup_time_t *set_wakeup_time;
		efi_set_virtual_address_map_t *set_virtual_address_map;
		void *convert_pointer;
		efi_get_variable_t *get_variable;
		efi_get_next_variable_t *get_next_variable;
		efi_set_variable_t *set_variable;
		efi_get_next_high_mono_count_t *get_next_high_mono_count;
		efi_reset_system_t *reset_system;
		efi_update_capsule_t *update_capsule;
		efi_query_capsule_caps_t *query_capsule_caps;
		efi_query_variable_info_t *query_variable_info;
	};
	efi_runtime_services_32_t mixed_mode;
} efi_runtime_services_t;

typedef struct {
	efi_table_hdr_t hdr;
	u32 fw_vendor;
	u32 fw_revision;
	u32 con_in_handle;
	u32 con_in;
	u32 con_out_handle;
	u32 con_out;
	u32 stderr_handle;
	u32 stderr;
	u32 runtime;
	u32 boottime;
	u32 nr_tables;
	u32 tables;
} efi_system_table_32_t;

typedef union {
	struct {
		efi_table_hdr_t hdr;
		long unsigned int fw_vendor;
		u32 fw_revision;
		long unsigned int con_in_handle;
		long unsigned int con_in;
		long unsigned int con_out_handle;
		long unsigned int con_out;
		long unsigned int stderr_handle;
		long unsigned int stderr;
		efi_runtime_services_t *runtime;
		efi_boot_services_t *boottime;
		long unsigned int nr_tables;
		long unsigned int tables;
	};
	efi_system_table_32_t mixed_mode;
} efi_system_table_t;

struct efi_memory_map {
	phys_addr_t phys_map;
	void *map;
	void *map_end;
	int nr_map;
	long unsigned int desc_version;
	long unsigned int desc_size;
	long unsigned int flags;
};

struct efi {
	efi_system_table_t *systab;
	unsigned int runtime_version;
	unsigned int runtime_supported_mask;
	long unsigned int mps;
	long unsigned int acpi;
	long unsigned int acpi20;
	long unsigned int smbios;
	long unsigned int smbios3;
	long unsigned int sal_systab;
	long unsigned int boot_info;
	long unsigned int hcdp;
	long unsigned int uga;
	long unsigned int fw_vendor;
	long unsigned int runtime;
	long unsigned int config_table;
	long unsigned int esrt;
	long unsigned int properties_table;
	long unsigned int mem_attr_table;
	long unsigned int rng_seed;
	long unsigned int tpm_log;
	long unsigned int tpm_final_log;
	long unsigned int mem_reserve;
	long unsigned int mokvar_table;
	efi_get_time_t *get_time;
	efi_set_time_t *set_time;
	efi_get_wakeup_time_t *get_wakeup_time;
	efi_set_wakeup_time_t *set_wakeup_time;
	efi_get_variable_t *get_variable;
	efi_get_next_variable_t *get_next_variable;
	efi_set_variable_t *set_variable;
	efi_set_variable_t *set_variable_nonblocking;
	efi_query_variable_info_t *query_variable_info;
	efi_query_variable_info_t *query_variable_info_nonblocking;
	efi_update_capsule_t *update_capsule;
	efi_query_capsule_caps_t *query_capsule_caps;
	efi_get_next_high_mono_count_t *get_next_high_mono_count;
	efi_reset_system_t *reset_system;
	efi_set_virtual_address_map_t *set_virtual_address_map;
	struct efi_memory_map memmap;
	long unsigned int flags;
};

enum efi_rts_ids {
	EFI_NONE = 0,
	EFI_GET_TIME = 1,
	EFI_SET_TIME = 2,
	EFI_GET_WAKEUP_TIME = 3,
	EFI_SET_WAKEUP_TIME = 4,
	EFI_GET_VARIABLE = 5,
	EFI_GET_NEXT_VARIABLE = 6,
	EFI_SET_VARIABLE = 7,
	EFI_QUERY_VARIABLE_INFO = 8,
	EFI_GET_NEXT_HIGH_MONO_COUNT = 9,
	EFI_RESET_SYSTEM = 10,
	EFI_UPDATE_CAPSULE = 11,
	EFI_QUERY_CAPSULE_CAPS = 12,
};

struct efi_runtime_work {
	void *arg1;
	void *arg2;
	void *arg3;
	void *arg4;
	void *arg5;
	efi_status_t status;
	struct work_struct work;
	enum efi_rts_ids efi_rts_id;
	struct completion efi_rts_comp;
};

enum memcg_memory_event {
	MEMCG_LOW = 0,
	MEMCG_HIGH = 1,
	MEMCG_MAX = 2,
	MEMCG_OOM = 3,
	MEMCG_OOM_KILL = 4,
	MEMCG_SWAP_HIGH = 5,
	MEMCG_SWAP_MAX = 6,
	MEMCG_SWAP_FAIL = 7,
	MEMCG_NR_MEMORY_EVENTS = 8,
};

struct mem_cgroup_reclaim_iter {
	struct mem_cgroup *position;
	unsigned int generation;
};

struct shrinker_info {
	struct callback_head rcu;
	atomic_long_t *nr_deferred;
	long unsigned int *map;
};

struct lruvec_stats_percpu {
	long int state[40];
	long int state_prev[40];
};

struct lruvec_stats {
	long int state[40];
	long int state_pending[40];
};

struct mem_cgroup_per_node {
	struct lruvec lruvec;
	struct lruvec_stats_percpu *lruvec_stats_percpu;
	struct lruvec_stats lruvec_stats;
	long unsigned int lru_zone_size[25];
	struct mem_cgroup_reclaim_iter iter;
	struct shrinker_info *shrinker_info;
	struct rb_node tree_node;
	long unsigned int usage_in_excess;
	bool on_tree;
	short unsigned int nid;
	struct mem_cgroup *memcg;
};

struct eventfd_ctx;

struct mem_cgroup_threshold {
	struct eventfd_ctx *eventfd;
	long unsigned int threshold;
};

struct mem_cgroup_threshold_ary {
	int current_threshold;
	unsigned int size;
	struct mem_cgroup_threshold entries[0];
};

struct obj_cgroup {
	struct percpu_ref refcnt;
	struct mem_cgroup *memcg;
	atomic_t nr_charged_bytes;
	union {
		struct list_head list;
		struct callback_head rcu;
	};
};

typedef ppc_opcode_t kprobe_opcode_t;

struct arch_specific_insn {
	kprobe_opcode_t *insn;
	int boostable;
};

struct kprobe;

struct prev_kprobe {
	struct kprobe *kp;
	long unsigned int status;
	long unsigned int saved_msr;
};

typedef int (*kprobe_pre_handler_t)(struct kprobe *, struct pt_regs *);

typedef void (*kprobe_post_handler_t)(struct kprobe *, struct pt_regs *, long unsigned int);

typedef int (*kprobe_fault_handler_t)(struct kprobe *, struct pt_regs *, int);

struct kprobe {
	struct hlist_node hlist;
	struct list_head list;
	long unsigned int nmissed;
	kprobe_opcode_t *addr;
	const char *symbol_name;
	unsigned int offset;
	kprobe_pre_handler_t pre_handler;
	kprobe_post_handler_t post_handler;
	kprobe_fault_handler_t fault_handler;
	kprobe_opcode_t opcode;
	struct arch_specific_insn ainsn;
	u32 flags;
};

struct kprobe_ctlblk {
	long unsigned int kprobe_status;
	long unsigned int kprobe_saved_msr;
	struct prev_kprobe prev_kprobe;
};

struct kretprobe_blackpoint {
	const char *name;
	void *addr;
};

struct kprobe_insn_cache {
	struct mutex mutex;
	void * (*alloc)();
	void (*free)(void *);
	struct list_head pages;
	size_t insn_size;
	int nr_garbage;
};

enum kgdb_bptype {
	BP_BREAKPOINT = 0,
	BP_HARDWARE_BREAKPOINT = 1,
	BP_WRITE_WATCHPOINT = 2,
	BP_READ_WATCHPOINT = 3,
	BP_ACCESS_WATCHPOINT = 4,
	BP_POKE_BREAKPOINT = 5,
};

struct dbg_reg_def_t {
	char *name;
	int size;
	int offset;
};

struct kgdb_arch {
	unsigned char gdb_bpt_instr[4];
	long unsigned int flags;
	int (*set_breakpoint)(long unsigned int, char *);
	int (*remove_breakpoint)(long unsigned int, char *);
	int (*set_hw_breakpoint)(long unsigned int, int, enum kgdb_bptype);
	int (*remove_hw_breakpoint)(long unsigned int, int, enum kgdb_bptype);
	void (*disable_hw_break)(struct pt_regs *);
	void (*remove_all_hw_break)();
	void (*correct_hw_break)();
	void (*enable_nmi)(bool);
};

struct kgdb_io {
	const char *name;
	int (*read_char)();
	void (*write_char)(u8);
	void (*flush)();
	int (*init)();
	void (*pre_exception)();
	void (*post_exception)();
	int is_console;
};

struct percpu_cluster {
	struct swap_cluster_info index;
	unsigned int next;
};

enum fs_value_type {
	fs_value_is_undefined = 0,
	fs_value_is_flag = 1,
	fs_value_is_string = 2,
	fs_value_is_blob = 3,
	fs_value_is_filename = 4,
	fs_value_is_file = 5,
};

struct fs_parameter {
	const char *key;
	enum fs_value_type type: 8;
	union {
		char *string;
		void *blob;
		struct filename *name;
		struct file *file;
	};
	size_t size;
	int dirfd;
};

struct fc_log {
	refcount_t usage;
	u8 head;
	u8 tail;
	u8 need_free;
	struct module *owner;
	char *buffer[8];
};

struct fs_context_operations {
	void (*free)(struct fs_context *);
	int (*dup)(struct fs_context *, struct fs_context *);
	int (*parse_param)(struct fs_context *, struct fs_parameter *);
	int (*parse_monolithic)(struct fs_context *, void *);
	int (*get_tree)(struct fs_context *);
	int (*reconfigure)(struct fs_context *);
};

struct fs_parse_result {
	bool negated;
	union {
		bool boolean;
		int int_32;
		unsigned int uint_32;
		u64 uint_64;
	};
};

struct trace_event_raw_initcall_level {
	struct trace_entry ent;
	u32 __data_loc_level;
	char __data[0];
};

struct trace_event_raw_initcall_start {
	struct trace_entry ent;
	initcall_t func;
	char __data[0];
};

struct trace_event_raw_initcall_finish {
	struct trace_entry ent;
	initcall_t func;
	int ret;
	char __data[0];
};

struct trace_event_data_offsets_initcall_level {
	u32 level;
};

struct trace_event_data_offsets_initcall_start {};

struct trace_event_data_offsets_initcall_finish {};

typedef void (*btf_trace_initcall_level)(void *, const char *);

typedef void (*btf_trace_initcall_start)(void *, initcall_t);

typedef void (*btf_trace_initcall_finish)(void *, initcall_t, int);

struct kunit_case {
	void (*run_case)(struct kunit *);
	const char *name;
	const void * (*generate_params)(const void *, char *);
	enum kunit_status status;
	char *log;
};

struct blacklist_entry {
	struct list_head next;
	char *buf;
};

struct file_system_type___2;

struct atomic_notifier_head___2;

enum hrtimer_base_type {
	HRTIMER_BASE_MONOTONIC = 0,
	HRTIMER_BASE_REALTIME = 1,
	HRTIMER_BASE_BOOTTIME = 2,
	HRTIMER_BASE_TAI = 3,
	HRTIMER_BASE_MONOTONIC_SOFT = 4,
	HRTIMER_BASE_REALTIME_SOFT = 5,
	HRTIMER_BASE_BOOTTIME_SOFT = 6,
	HRTIMER_BASE_TAI_SOFT = 7,
	HRTIMER_MAX_CLOCK_BASES = 8,
};

enum {
	MM_FILEPAGES = 0,
	MM_ANONPAGES = 1,
	MM_SWAPENTS = 2,
	MM_SHMEMPAGES = 3,
	NR_MM_COUNTERS = 4,
};

enum rseq_cs_flags_bit {
	RSEQ_CS_FLAG_NO_RESTART_ON_PREEMPT_BIT = 0,
	RSEQ_CS_FLAG_NO_RESTART_ON_SIGNAL_BIT = 1,
	RSEQ_CS_FLAG_NO_RESTART_ON_MIGRATE_BIT = 2,
};

enum perf_event_task_context {
	perf_invalid_context = 4294967295,
	perf_hw_context = 0,
	perf_sw_context = 1,
	perf_nr_task_contexts = 2,
};

enum rseq_event_mask_bits {
	RSEQ_EVENT_PREEMPT_BIT = 0,
	RSEQ_EVENT_SIGNAL_BIT = 1,
	RSEQ_EVENT_MIGRATE_BIT = 2,
};

struct rw_semaphore___2;

enum {
	PROC_ROOT_INO = 1,
	PROC_IPC_INIT_INO = 4026531839,
	PROC_UTS_INIT_INO = 4026531838,
	PROC_USER_INIT_INO = 4026531837,
	PROC_PID_INIT_INO = 4026531836,
	PROC_CGROUP_INIT_INO = 4026531835,
	PROC_TIME_INIT_INO = 4026531834,
};

typedef __u16 __le16;

typedef __u32 __wsum;

typedef unsigned int slab_flags_t;

typedef s32 compat_time_t;

struct compat_timespec {
	compat_time_t tv_sec;
	s32 tv_nsec;
};

typedef struct __call_single_data call_single_data_t;

struct raw_notifier_head {
	struct notifier_block *head;
};

struct rhash_head {
	struct rhash_head *next;
};

struct rhashtable;

struct rhashtable_compare_arg {
	struct rhashtable *ht;
	const void *key;
};

typedef u32 (*rht_hashfn_t)(const void *, u32, u32);

typedef u32 (*rht_obj_hashfn_t)(const void *, u32, u32);

typedef int (*rht_obj_cmpfn_t)(struct rhashtable_compare_arg *, const void *);

struct rhashtable_params {
	u16 nelem_hint;
	u16 key_len;
	u16 key_offset;
	u16 head_offset;
	unsigned int max_size;
	u16 min_size;
	bool automatic_shrinking;
	u8 locks_mul;
	u32 rh_reserved_nulls_base;
	rht_hashfn_t hashfn;
	rht_obj_hashfn_t obj_hashfn;
	rht_obj_cmpfn_t obj_cmpfn;
};

struct bucket_table;

struct rhashtable {
	struct bucket_table *tbl;
	unsigned int key_len;
	unsigned int max_elems;
	struct rhashtable_params p;
	bool rhlist;
	struct work_struct run_work;
	struct mutex mutex;
	spinlock_t lock;
	atomic_t nelems;
};

struct fs_struct {
	int users;
	spinlock_t lock;
	seqcount_t seq;
	int umask;
	int in_exec;
	struct path root;
	struct path pwd;
};

typedef u32 compat_uptr_t;

struct compat_robust_list {
	compat_uptr_t next;
};

typedef s32 compat_long_t;

struct compat_robust_list_head {
	struct compat_robust_list list;
	compat_long_t futex_offset;
	compat_uptr_t list_op_pending;
};

struct pipe_buffer;

struct pipe_inode_info {
	struct mutex mutex;
	wait_queue_head_t wait;
	unsigned int nrbufs;
	unsigned int curbuf;
	unsigned int buffers;
	unsigned int readers;
	unsigned int writers;
	unsigned int files;
	unsigned int waiting_writers;
	unsigned int r_counter;
	unsigned int w_counter;
	struct page *tmp_page;
	struct fasync_struct *fasync_readers;
	struct fasync_struct *fasync_writers;
	struct pipe_buffer *bufs;
	struct user_struct *user;
};

struct ida {
	struct xarray xa;
};

typedef __u64 __addrpair;

typedef __u32 __portpair;

typedef struct {
	struct net *net;
} possible_net_t;

struct hlist_nulls_node {
	struct hlist_nulls_node *next;
	struct hlist_nulls_node **pprev;
};

struct proto;

struct inet_timewait_death_row;

struct sock_common {
	union {
		__addrpair skc_addrpair;
		struct {
			__be32 skc_daddr;
			__be32 skc_rcv_saddr;
		};
	};
	union {
		unsigned int skc_hash;
		__u16 skc_u16hashes[2];
	};
	union {
		__portpair skc_portpair;
		struct {
			__be16 skc_dport;
			__u16 skc_num;
		};
	};
	short unsigned int skc_family;
	volatile unsigned char skc_state;
	unsigned char skc_reuse: 4;
	unsigned char skc_reuseport: 1;
	unsigned char skc_ipv6only: 1;
	unsigned char skc_net_refcnt: 1;
	int skc_bound_dev_if;
	union {
		struct hlist_node skc_bind_node;
		struct hlist_node skc_portaddr_node;
	};
	struct proto *skc_prot;
	possible_net_t skc_net;
	struct in6_addr skc_v6_daddr;
	struct in6_addr skc_v6_rcv_saddr;
	atomic64_t skc_cookie;
	union {
		long unsigned int skc_flags;
		struct sock *skc_listener;
		struct inet_timewait_death_row *skc_tw_dr;
	};
	int skc_dontcopy_begin[0];
	union {
		struct hlist_node skc_node;
		struct hlist_nulls_node skc_nulls_node;
	};
	short unsigned int skc_tx_queue_mapping;
	short unsigned int skc_rx_queue_mapping;
	union {
		int skc_incoming_cpu;
		u32 skc_rcv_wnd;
		u32 skc_tw_rcv_nxt;
	};
	refcount_t skc_refcnt;
	int skc_dontcopy_end[0];
	union {
		u32 skc_rxhash;
		u32 skc_window_clamp;
		u32 skc_tw_snd_nxt;
	};
};

typedef struct {
	spinlock_t slock;
	int owned;
	wait_queue_head_t wq;
} socket_lock_t;

struct sk_buff;

struct sk_buff_head {
	struct sk_buff *next;
	struct sk_buff *prev;
	__u32 qlen;
	spinlock_t lock;
};

typedef u64 netdev_features_t;

struct sock_cgroup_data {
	struct cgroup *cgroup;
	u32 classid;
	u16 prioidx;
};

struct sk_filter;

struct socket_wq;

struct xfrm_policy;

struct dst_entry;

struct socket;

struct sock_reuseport;

struct sock {
	struct sock_common __sk_common;
	socket_lock_t sk_lock;
	atomic_t sk_drops;
	int sk_rcvlowat;
	struct sk_buff_head sk_error_queue;
	struct sk_buff_head sk_receive_queue;
	struct {
		atomic_t rmem_alloc;
		int len;
		struct sk_buff *head;
		struct sk_buff *tail;
	} sk_backlog;
	int sk_forward_alloc;
	unsigned int sk_ll_usec;
	unsigned int sk_napi_id;
	int sk_rcvbuf;
	struct sk_filter *sk_filter;
	union {
		struct socket_wq *sk_wq;
		struct socket_wq *sk_wq_raw;
	};
	struct xfrm_policy *sk_policy[2];
	struct dst_entry *sk_rx_dst;
	struct dst_entry *sk_dst_cache;
	atomic_t sk_omem_alloc;
	int sk_sndbuf;
	int sk_wmem_queued;
	refcount_t sk_wmem_alloc;
	long unsigned int sk_tsq_flags;
	union {
		struct sk_buff *sk_send_head;
		struct rb_root tcp_rtx_queue;
	};
	struct sk_buff_head sk_write_queue;
	__s32 sk_peek_off;
	int sk_write_pending;
	__u32 sk_dst_pending_confirm;
	u32 sk_pacing_status;
	long int sk_sndtimeo;
	struct timer_list sk_timer;
	__u32 sk_priority;
	__u32 sk_mark;
	u32 sk_pacing_rate;
	u32 sk_max_pacing_rate;
	struct page_frag sk_frag;
	netdev_features_t sk_route_caps;
	netdev_features_t sk_route_nocaps;
	netdev_features_t sk_route_forced_caps;
	int sk_gso_type;
	unsigned int sk_gso_max_size;
	gfp_t sk_allocation;
	__u32 sk_txhash;
	unsigned int __sk_flags_offset[0];
	unsigned int sk_padding: 1;
	unsigned int sk_kern_sock: 1;
	unsigned int sk_no_check_tx: 1;
	unsigned int sk_no_check_rx: 1;
	unsigned int sk_userlocks: 4;
	unsigned int sk_protocol: 8;
	unsigned int sk_type: 16;
	u16 sk_gso_max_segs;
	u8 sk_pacing_shift;
	long unsigned int sk_lingertime;
	struct proto *sk_prot_creator;
	rwlock_t sk_callback_lock;
	int sk_err;
	int sk_err_soft;
	u32 sk_ack_backlog;
	u32 sk_max_ack_backlog;
	kuid_t sk_uid;
	struct pid *sk_peer_pid;
	const struct cred *sk_peer_cred;
	long int sk_rcvtimeo;
	ktime_t sk_stamp;
	u16 sk_tsflags;
	u8 sk_shutdown;
	u32 sk_tskey;
	atomic_t sk_zckey;
	u8 sk_clockid;
	u8 sk_txtime_deadline_mode: 1;
	u8 sk_txtime_report_errors: 1;
	u8 sk_txtime_unused: 6;
	struct socket *sk_socket;
	void *sk_user_data;
	void *sk_security;
	u64 sk_cgrp_data_hole;
	struct mem_cgroup *sk_memcg;
	void (*sk_state_change)(struct sock *);
	void (*sk_data_ready)(struct sock *);
	void (*sk_write_space)(struct sock *);
	void (*sk_error_report)(struct sock *);
	int (*sk_backlog_rcv)(struct sock *, struct sk_buff *);
	struct sk_buff * (*sk_validate_xmit_skb)(struct sock *, struct net_device *, struct sk_buff *);
	void (*sk_destruct)(struct sock *);
	struct sock_reuseport *sk_reuseport_cb;
	struct callback_head sk_rcu;
	union {
		struct bpf_local_storage *sk_bpf_storage;
		struct {
			long unsigned int rh_reserved1;
		} rh_kabi_hidden_526;
		union {		};
	};
	union {
		struct sk_buff *sk_tx_skb_cache;
		struct {
			long unsigned int rh_reserved2;
		} rh_kabi_hidden_527;
		union {		};
	};
	union {
		struct {
			u8 sk_prefer_busy_poll;
			u16 sk_busy_poll_budget;
		};
		struct {
			long unsigned int rh_reserved3;
		} rh_kabi_hidden_529;
		union {		};
	};
	union {
		spinlock_t sk_peer_lock;
		struct {
			long unsigned int rh_reserved4;
		} rh_kabi_hidden_530;
		union {		};
	};
	union {
		struct sock_cgroup_data sk_cgrp_data;
		struct {
			long unsigned int rh_reserved5;
			long unsigned int rh_reserved6;
		} rh_kabi_hidden_531;
		union {		};
	};
	union {
		int sk_txrehash;
		struct {
			long unsigned int rh_reserved7;
		} rh_kabi_hidden_532;
		union {		};
	};
	long unsigned int rh_reserved8;
	long unsigned int rh_reserved9;
	long unsigned int rh_reserved10;
	long unsigned int rh_reserved11;
	long unsigned int rh_reserved12;
	long unsigned int rh_reserved13;
	long unsigned int rh_reserved14;
	long unsigned int rh_reserved15;
	long unsigned int rh_reserved16;
};

struct iovec {
	void *iov_base;
	__kernel_size_t iov_len;
};

struct kvec {
	void *iov_base;
	size_t iov_len;
};

struct iov_iter {
	union {
		unsigned int type;
		struct {
			int type;
		} rh_kabi_hidden_47;
		union {		};
	};
	size_t iov_offset;
	size_t count;
	union {
		const struct iovec *iov;
		const struct kvec *kvec;
		const struct bio_vec *bvec;
		struct pipe_inode_info *pipe;
	};
	union {
		long unsigned int nr_segs;
		struct {
			int idx;
			int start_idx;
		};
	};
};

typedef short unsigned int __kernel_sa_family_t;

struct __kernel_sockaddr_storage {
	__kernel_sa_family_t ss_family;
	char __data[126];
};

typedef __kernel_sa_family_t sa_family_t;

struct sockaddr {
	sa_family_t sa_family;
	char sa_data[14];
};

struct msghdr {
	void *msg_name;
	int msg_namelen;
	struct iov_iter msg_iter;
	void *msg_control;
	__kernel_size_t msg_controllen;
	unsigned int msg_flags;
	struct kiocb *msg_iocb;
};

typedef struct {
	unsigned int clock_rate;
	unsigned int clock_type;
	short unsigned int loopback;
} sync_serial_settings;

typedef struct {
	unsigned int clock_rate;
	unsigned int clock_type;
	short unsigned int loopback;
	unsigned int slot_map;
} te1_settings;

typedef struct {
	short unsigned int encoding;
	short unsigned int parity;
} raw_hdlc_proto;

typedef struct {
	unsigned int t391;
	unsigned int t392;
	unsigned int n391;
	unsigned int n392;
	unsigned int n393;
	short unsigned int lmi;
	short unsigned int dce;
} fr_proto;

typedef struct {
	unsigned int dlci;
} fr_proto_pvc;

typedef struct {
	unsigned int dlci;
	char master[16];
} fr_proto_pvc_info;

typedef struct {
	unsigned int interval;
	unsigned int timeout;
} cisco_proto;

struct ifmap {
	long unsigned int mem_start;
	long unsigned int mem_end;
	short unsigned int base_addr;
	unsigned char irq;
	unsigned char dma;
	unsigned char port;
};

struct if_settings {
	unsigned int type;
	unsigned int size;
	union {
		raw_hdlc_proto *raw_hdlc;
		cisco_proto *cisco;
		fr_proto *fr;
		fr_proto_pvc *fr_pvc;
		fr_proto_pvc_info *fr_pvc_info;
		sync_serial_settings *sync;
		te1_settings *te1;
	} ifs_ifsu;
};

struct ifreq {
	union {
		char ifrn_name[16];
	} ifr_ifrn;
	union {
		struct sockaddr ifru_addr;
		struct sockaddr ifru_dstaddr;
		struct sockaddr ifru_broadaddr;
		struct sockaddr ifru_netmask;
		struct sockaddr ifru_hwaddr;
		short int ifru_flags;
		int ifru_ivalue;
		int ifru_mtu;
		struct ifmap ifru_map;
		char ifru_slave[16];
		char ifru_newname[16];
		void *ifru_data;
		struct if_settings ifru_settings;
	} ifr_ifru;
};

struct vfsmount {
	struct dentry *mnt_root;
	struct super_block *mnt_sb;
	int mnt_flags;
};

struct ld_semaphore {
	union {
		atomic_long_t count;
		struct {
			long int count;
		} rh_kabi_hidden_129;
		union {		};
	};
	raw_spinlock_t wait_lock;
	unsigned int wait_readers;
	struct list_head read_wait;
	struct list_head write_wait;
};

typedef unsigned int tcflag_t;

typedef unsigned char cc_t;

typedef unsigned int speed_t;

struct ktermios {
	tcflag_t c_iflag;
	tcflag_t c_oflag;
	tcflag_t c_cflag;
	tcflag_t c_lflag;
	cc_t c_cc[19];
	cc_t c_line;
	speed_t c_ispeed;
	speed_t c_ospeed;
};

struct winsize {
	short unsigned int ws_row;
	short unsigned int ws_col;
	short unsigned int ws_xpixel;
	short unsigned int ws_ypixel;
};

struct tty_operations;

struct tty_ldisc;

struct termiox;

struct tty_port;

struct tty_struct {
	int magic;
	struct kref kref;
	struct device *dev;
	struct tty_driver *driver;
	const struct tty_operations *ops;
	int index;
	struct ld_semaphore ldisc_sem;
	struct tty_ldisc *ldisc;
	struct mutex atomic_write_lock;
	struct mutex legacy_mutex;
	struct mutex throttle_mutex;
	struct rw_semaphore termios_rwsem;
	struct mutex winsize_mutex;
	spinlock_t ctrl_lock;
	spinlock_t flow_lock;
	struct ktermios termios;
	struct ktermios termios_locked;
	struct termiox *termiox;
	char name[64];
	struct pid *pgrp;
	struct pid *session;
	long unsigned int flags;
	int count;
	struct winsize winsize;
	long unsigned int stopped: 1;
	long unsigned int flow_stopped: 1;
	int: 30;
	long unsigned int unused: 62;
	int hw_stopped;
	long unsigned int ctrl_status: 8;
	long unsigned int packet: 1;
	int: 23;
	long unsigned int unused_ctrl: 55;
	unsigned int receive_room;
	int flow_change;
	struct tty_struct *link;
	struct fasync_struct *fasync;
	wait_queue_head_t write_wait;
	wait_queue_head_t read_wait;
	struct work_struct hangup_work;
	void *disc_data;
	void *driver_data;
	spinlock_t files_lock;
	struct list_head tty_files;
	int closing;
	unsigned char *write_buf;
	int write_cnt;
	struct work_struct SAK_work;
	struct tty_port *port;
};

typedef struct {
	size_t written;
	size_t count;
	union {
		char *buf;
		void *data;
	} arg;
	int error;
} read_descriptor_t;

struct posix_acl_entry {
	short int e_tag;
	short unsigned int e_perm;
	union {
		kuid_t e_uid;
		kgid_t e_gid;
	};
};

struct posix_acl {
	refcount_t a_refcount;
	struct callback_head a_rcu;
	unsigned int a_count;
	struct posix_acl_entry a_entries[0];
};

struct termiox {
	__u16 x_hflag;
	__u16 x_cflag;
	__u16 x_rflag[5];
	__u16 x_sflag;
};

struct serial_icounter_struct;

struct serial_struct;

struct tty_operations {
	struct tty_struct * (*lookup)(struct tty_driver *, struct file *, int);
	int (*install)(struct tty_driver *, struct tty_struct *);
	void (*remove)(struct tty_driver *, struct tty_struct *);
	int (*open)(struct tty_struct *, struct file *);
	void (*close)(struct tty_struct *, struct file *);
	void (*shutdown)(struct tty_struct *);
	void (*cleanup)(struct tty_struct *);
	int (*write)(struct tty_struct *, const unsigned char *, int);
	int (*put_char)(struct tty_struct *, unsigned char);
	void (*flush_chars)(struct tty_struct *);
	int (*write_room)(struct tty_struct *);
	int (*chars_in_buffer)(struct tty_struct *);
	int (*ioctl)(struct tty_struct *, unsigned int, long unsigned int);
	long int (*compat_ioctl)(struct tty_struct *, unsigned int, long unsigned int);
	void (*set_termios)(struct tty_struct *, struct ktermios *);
	void (*throttle)(struct tty_struct *);
	void (*unthrottle)(struct tty_struct *);
	void (*stop)(struct tty_struct *);
	void (*start)(struct tty_struct *);
	void (*hangup)(struct tty_struct *);
	int (*break_ctl)(struct tty_struct *, int);
	void (*flush_buffer)(struct tty_struct *);
	void (*set_ldisc)(struct tty_struct *);
	void (*wait_until_sent)(struct tty_struct *, int);
	void (*send_xchar)(struct tty_struct *, char);
	int (*tiocmget)(struct tty_struct *);
	int (*tiocmset)(struct tty_struct *, unsigned int, unsigned int);
	int (*resize)(struct tty_struct *, struct winsize *);
	int (*set_termiox)(struct tty_struct *, struct termiox *);
	int (*get_icount)(struct tty_struct *, struct serial_icounter_struct *);
	void (*show_fdinfo)(struct tty_struct *, struct seq_file *);
	int (*poll_init)(struct tty_driver *, int, char *);
	int (*poll_get_char)(struct tty_driver *, int);
	void (*poll_put_char)(struct tty_driver *, int, char);
	int (*proc_show)(struct seq_file *, void *);
	int (*get_serial)(struct tty_struct *, struct serial_struct *);
	int (*set_serial)(struct tty_struct *, struct serial_struct *);
};

struct tty_driver {
	int magic;
	struct kref kref;
	struct cdev **cdevs;
	struct module *owner;
	const char *driver_name;
	const char *name;
	int name_base;
	int major;
	int minor_start;
	unsigned int num;
	short int type;
	short int subtype;
	struct ktermios init_termios;
	long unsigned int flags;
	struct proc_dir_entry *proc_entry;
	struct tty_driver *other;
	struct tty_struct **ttys;
	struct tty_port **ports;
	struct ktermios **termios;
	void *driver_state;
	const struct tty_operations *ops;
	struct list_head tty_drivers;
};

struct tty_buffer {
	union {
		struct tty_buffer *next;
		struct llist_node free;
	};
	int used;
	int size;
	int commit;
	int read;
	int flags;
	long unsigned int data[0];
};

struct tty_bufhead {
	struct tty_buffer *head;
	struct work_struct work;
	struct mutex lock;
	atomic_t priority;
	struct tty_buffer sentinel;
	struct llist_head free;
	atomic_t mem_used;
	int mem_limit;
	struct tty_buffer *tail;
};

struct tty_port_operations;

struct tty_port_client_operations;

struct tty_port {
	struct tty_bufhead buf;
	struct tty_struct *tty;
	struct tty_struct *itty;
	const struct tty_port_operations *ops;
	const struct tty_port_client_operations *client_ops;
	spinlock_t lock;
	int blocked_open;
	int count;
	wait_queue_head_t open_wait;
	wait_queue_head_t delta_msr_wait;
	long unsigned int flags;
	long unsigned int iflags;
	unsigned char console: 1;
	unsigned char low_latency: 1;
	struct mutex mutex;
	struct mutex buf_mutex;
	unsigned char *xmit_buf;
	unsigned int close_delay;
	unsigned int closing_wait;
	int drain_delay;
	struct kref kref;
	void *client_data;
};

struct tty_ldisc_ops {
	int magic;
	char *name;
	int num;
	int flags;
	int (*open)(struct tty_struct *);
	void (*close)(struct tty_struct *);
	void (*flush_buffer)(struct tty_struct *);
	ssize_t (*read)(struct tty_struct *, struct file *, unsigned char *, size_t);
	ssize_t (*write)(struct tty_struct *, struct file *, const unsigned char *, size_t);
	int (*ioctl)(struct tty_struct *, struct file *, unsigned int, long unsigned int);
	long int (*compat_ioctl)(struct tty_struct *, struct file *, unsigned int, long unsigned int);
	void (*set_termios)(struct tty_struct *, struct ktermios *);
	__poll_t (*poll)(struct tty_struct *, struct file *, struct poll_table_struct *);
	int (*hangup)(struct tty_struct *);
	void (*receive_buf)(struct tty_struct *, const unsigned char *, char *, int);
	void (*write_wakeup)(struct tty_struct *);
	void (*dcd_change)(struct tty_struct *, unsigned int);
	int (*receive_buf2)(struct tty_struct *, const unsigned char *, char *, int);
	struct module *owner;
	int refcount;
};

struct tty_ldisc {
	struct tty_ldisc_ops *ops;
	struct tty_struct *tty;
};

struct tty_port_operations {
	int (*carrier_raised)(struct tty_port *);
	void (*dtr_rts)(struct tty_port *, int);
	void (*shutdown)(struct tty_port *);
	int (*activate)(struct tty_port *, struct tty_struct *);
	void (*destruct)(struct tty_port *);
};

struct tty_port_client_operations {
	int (*receive_buf)(struct tty_port *, const unsigned char *, const unsigned char *, size_t);
	void (*write_wakeup)(struct tty_port *);
};

struct prot_inuse;

struct netns_core {
	struct ctl_table_header *sysctl_hdr;
	int sysctl_somaxconn;
	int *sock_inuse;
	struct prot_inuse *prot_inuse;
};

struct tcp_mib;

struct ipstats_mib;

struct linux_mib;

struct udp_mib;

struct icmp_mib;

struct icmpmsg_mib;

struct icmpv6_mib;

struct icmpv6msg_mib;

struct linux_xfrm_mib;

struct netns_mib {
	struct tcp_mib *tcp_statistics;
	struct ipstats_mib *ip_statistics;
	struct linux_mib *net_statistics;
	struct udp_mib *udp_statistics;
	struct udp_mib *udplite_statistics;
	struct icmp_mib *icmp_statistics;
	struct icmpmsg_mib *icmpmsg_statistics;
	struct proc_dir_entry *proc_net_devsnmp6;
	struct udp_mib *udp_stats_in6;
	struct udp_mib *udplite_stats_in6;
	struct ipstats_mib *ipv6_statistics;
	struct icmpv6_mib *icmpv6_statistics;
	struct icmpv6msg_mib *icmpv6msg_statistics;
	struct linux_xfrm_mib *xfrm_statistics;
};

struct netns_packet {
	struct mutex sklist_lock;
	struct hlist_head sklist;
};

struct netns_unix {
	int sysctl_max_dgram_qlen;
	struct ctl_table_header *ctl;
};

struct inet_frags;

struct netns_frags {
	long int high_thresh;
	long int low_thresh;
	int timeout;
	int max_dist;
	struct inet_frags *f;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	struct rhashtable rhashtable;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	atomic_long_t mem;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
};

struct local_ports {
	seqlock_t lock;
	int range[2];
	bool warned;
};

struct inet_hashinfo;

struct inet_timewait_death_row {
	atomic_t tw_count;
	long: 32;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	struct inet_hashinfo *hashinfo;
	int sysctl_max_tw_buckets;
	long: 32;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
};

struct ping_group_range {
	seqlock_t lock;
	kgid_t range[2];
};

struct ipv4_devconf;

struct ip_ra_chain;

struct fib_rules_ops;

struct fib_table;

struct inet_peer_base;

struct xt_table;

struct tcp_congestion_ops;

struct tcp_fastopen_context;

struct fib_notifier_ops;

struct netns_ipv4 {
	struct ctl_table_header *forw_hdr;
	struct ctl_table_header *frags_hdr;
	struct ctl_table_header *ipv4_hdr;
	struct ctl_table_header *route_hdr;
	struct ctl_table_header *xfrm4_hdr;
	struct ipv4_devconf *devconf_all;
	struct ipv4_devconf *devconf_dflt;
	struct ip_ra_chain *ra_chain;
	struct mutex ra_mutex;
	struct fib_rules_ops *rules_ops;
	bool fib_has_custom_rules;
	unsigned int fib_rules_require_fldissect;
	struct fib_table *fib_main;
	struct fib_table *fib_default;
	bool fib_has_custom_local_routes;
	int fib_num_tclassid_users;
	struct hlist_head *fib_table_hash;
	bool fib_offload_disabled;
	struct sock *fibnl;
	struct sock **icmp_sk;
	struct sock *mc_autojoin_sk;
	struct inet_peer_base *peers;
	struct sock **tcp_sk;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	struct netns_frags frags;
	struct xt_table *iptable_filter;
	struct xt_table *iptable_mangle;
	struct xt_table *iptable_raw;
	struct xt_table *arptable_filter;
	struct xt_table *iptable_security;
	struct xt_table *nat_table;
	int sysctl_icmp_echo_ignore_all;
	int sysctl_icmp_echo_ignore_broadcasts;
	int sysctl_icmp_ignore_bogus_error_responses;
	int sysctl_icmp_ratelimit;
	int sysctl_icmp_ratemask;
	int sysctl_icmp_errors_use_inbound_ifaddr;
	struct local_ports ip_local_ports;
	int sysctl_tcp_ecn;
	int sysctl_tcp_ecn_fallback;
	int sysctl_ip_default_ttl;
	int sysctl_ip_no_pmtu_disc;
	int sysctl_ip_fwd_use_pmtu;
	int sysctl_ip_nonlocal_bind;
	int sysctl_ip_dynaddr;
	int sysctl_ip_early_demux;
	int sysctl_tcp_early_demux;
	int sysctl_udp_early_demux;
	int sysctl_fwmark_reflect;
	int sysctl_tcp_fwmark_accept;
	int sysctl_tcp_l3mdev_accept;
	int sysctl_tcp_mtu_probing;
	int sysctl_tcp_base_mss;
	int sysctl_tcp_probe_threshold;
	u32 sysctl_tcp_probe_interval;
	int sysctl_tcp_keepalive_time;
	int sysctl_tcp_keepalive_probes;
	int sysctl_tcp_keepalive_intvl;
	int sysctl_tcp_syn_retries;
	int sysctl_tcp_synack_retries;
	int sysctl_tcp_syncookies;
	int sysctl_tcp_reordering;
	int sysctl_tcp_retries1;
	int sysctl_tcp_retries2;
	int sysctl_tcp_orphan_retries;
	int sysctl_tcp_fin_timeout;
	unsigned int sysctl_tcp_notsent_lowat;
	int sysctl_tcp_tw_reuse;
	int sysctl_tcp_sack;
	int sysctl_tcp_window_scaling;
	int sysctl_tcp_timestamps;
	int sysctl_tcp_early_retrans;
	int sysctl_tcp_recovery;
	int sysctl_tcp_thin_linear_timeouts;
	int sysctl_tcp_slow_start_after_idle;
	int sysctl_tcp_retrans_collapse;
	int sysctl_tcp_stdurg;
	int sysctl_tcp_rfc1337;
	int sysctl_tcp_abort_on_overflow;
	int sysctl_tcp_fack;
	int sysctl_tcp_max_reordering;
	int sysctl_tcp_dsack;
	int sysctl_tcp_app_win;
	int sysctl_tcp_adv_win_scale;
	int sysctl_tcp_frto;
	int sysctl_tcp_nometrics_save;
	int sysctl_tcp_moderate_rcvbuf;
	int sysctl_tcp_tso_win_divisor;
	int sysctl_tcp_workaround_signed_windows;
	int sysctl_tcp_limit_output_bytes;
	int sysctl_tcp_challenge_ack_limit;
	int sysctl_tcp_min_tso_segs;
	int sysctl_tcp_min_rtt_wlen;
	int sysctl_tcp_autocorking;
	int sysctl_tcp_invalid_ratelimit;
	int sysctl_tcp_pacing_ss_ratio;
	int sysctl_tcp_pacing_ca_ratio;
	int sysctl_tcp_wmem[3];
	int sysctl_tcp_rmem[3];
	int sysctl_tcp_comp_sack_nr;
	long unsigned int sysctl_tcp_comp_sack_delay_ns;
	long: 64;
	long: 64;
	struct inet_timewait_death_row tcp_death_row;
	int sysctl_max_syn_backlog;
	int sysctl_tcp_fastopen;
	const struct tcp_congestion_ops *tcp_congestion_control;
	struct tcp_fastopen_context *tcp_fastopen_ctx;
	spinlock_t tcp_fastopen_ctx_lock;
	unsigned int sysctl_tcp_fastopen_blackhole_timeout;
	atomic_t tfo_active_disable_times;
	long unsigned int tfo_active_disable_stamp;
	int sysctl_udp_wmem_min;
	int sysctl_udp_rmem_min;
	int sysctl_udp_l3mdev_accept;
	int sysctl_igmp_max_memberships;
	int sysctl_igmp_max_msf;
	int sysctl_igmp_llm_reports;
	int sysctl_igmp_qrv;
	struct ping_group_range ping_group_range;
	atomic_t dev_addr_genid;
	long unsigned int *sysctl_local_reserved_ports;
	int sysctl_ip_prot_sock;
	struct list_head mr_tables;
	struct fib_rules_ops *mr_rules_ops;
	int sysctl_fib_multipath_use_neigh;
	int sysctl_fib_multipath_hash_policy;
	struct fib_notifier_ops *notifier_ops;
	unsigned int fib_seq;
	struct fib_notifier_ops *ipmr_notifier_ops;
	unsigned int ipmr_seq;
	atomic_t rt_genid;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
};

struct netns_sysctl_ipv6 {
	struct ctl_table_header *hdr;
	struct ctl_table_header *route_hdr;
	struct ctl_table_header *icmp_hdr;
	struct ctl_table_header *frags_hdr;
	struct ctl_table_header *xfrm6_hdr;
	int bindv6only;
	int flush_delay;
	int ip6_rt_max_size;
	int ip6_rt_gc_min_interval;
	int ip6_rt_gc_timeout;
	int ip6_rt_gc_interval;
	int ip6_rt_gc_elasticity;
	int ip6_rt_mtu_expires;
	int ip6_rt_min_advmss;
	int multipath_hash_policy;
	int flowlabel_consistency;
	int auto_flowlabels;
	int icmpv6_time;
	int anycast_src_echo_reply;
	int ip_nonlocal_bind;
	int fwmark_reflect;
	int idgen_retries;
	int idgen_delay;
	int flowlabel_state_ranges;
	int flowlabel_reflect;
	int max_dst_opts_cnt;
	int max_hbh_opts_cnt;
	int max_dst_opts_len;
	int max_hbh_opts_len;
	int seg6_flowlabel;
};

struct neighbour;

struct dst_ops {
	short unsigned int family;
	unsigned int gc_thresh;
	union {
		void (*gc)(struct dst_ops *);
		struct {
			int (*gc)(struct dst_ops *);
		} rh_kabi_hidden_22;
		union {		};
	};
	struct dst_entry * (*check)(struct dst_entry *, __u32);
	unsigned int (*default_advmss)(const struct dst_entry *);
	unsigned int (*mtu)(const struct dst_entry *);
	u32 * (*cow_metrics)(struct dst_entry *, long unsigned int);
	void (*destroy)(struct dst_entry *);
	void (*ifdown)(struct dst_entry *, struct net_device *, int);
	struct dst_entry * (*negative_advice)(struct dst_entry *);
	void (*link_failure)(struct sk_buff *);
	union {
		void (*update_pmtu)(struct dst_entry *, struct sock *, struct sk_buff *, u32, bool);
		struct {
			void (*update_pmtu)(struct dst_entry *, struct sock *, struct sk_buff *, u32);
		} rh_kabi_hidden_36;
		union {		};
	};
	void (*redirect)(struct dst_entry *, struct sock *, struct sk_buff *);
	int (*local_out)(struct net *, struct sock *, struct sk_buff *);
	struct neighbour * (*neigh_lookup)(const struct dst_entry *, struct sk_buff *, const void *);
	void (*confirm_neigh)(const struct dst_entry *, const void *);
	struct kmem_cache *kmem_cachep;
	long unsigned int rh_reserved1;
	long unsigned int rh_reserved2;
	long unsigned int rh_reserved3;
	long unsigned int rh_reserved4;
	long unsigned int rh_reserved5;
	long unsigned int rh_reserved6;
	long unsigned int rh_reserved7;
	long unsigned int rh_reserved8;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	struct percpu_counter pcpuc_entries;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
};

struct ipv6_devconf;

struct fib6_info;

struct rt6_info;

struct rt6_statistics;

struct fib6_table;

struct seg6_pernet_data;

struct netns_ipv6 {
	struct netns_sysctl_ipv6 sysctl;
	struct ipv6_devconf *devconf_all;
	struct ipv6_devconf *devconf_dflt;
	struct inet_peer_base *peers;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	struct netns_frags frags;
	struct xt_table *ip6table_filter;
	struct xt_table *ip6table_mangle;
	struct xt_table *ip6table_raw;
	struct xt_table *ip6table_security;
	struct xt_table *ip6table_nat;
	struct fib6_info *fib6_null_entry;
	struct rt6_info *ip6_null_entry;
	struct rt6_statistics *rt6_stats;
	struct timer_list ip6_fib_timer;
	struct hlist_head *fib_table_hash;
	struct fib6_table *fib6_main_tbl;
	struct list_head fib6_walkers;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	struct dst_ops ip6_dst_ops;
	rwlock_t fib6_walker_lock;
	spinlock_t fib6_gc_lock;
	union {
		atomic_t ip6_rt_gc_expire;
		struct {
			unsigned int ip6_rt_gc_expire;
		} rh_kabi_hidden_74;
		union {		};
	};
	long unsigned int ip6_rt_last_gc;
	unsigned int fib6_rules_require_fldissect;
	bool fib6_has_custom_rules;
	struct rt6_info *ip6_prohibit_entry;
	struct rt6_info *ip6_blk_hole_entry;
	struct fib6_table *fib6_local_tbl;
	struct fib_rules_ops *fib6_rules_ops;
	struct sock **icmp_sk;
	struct sock *ndisc_sk;
	struct sock *tcp_sk;
	struct sock *igmp_sk;
	struct sock *mc_autojoin_sk;
	struct list_head mr6_tables;
	struct fib_rules_ops *mr6_rules_ops;
	atomic_t dev_addr_genid;
	atomic_t fib6_sernum;
	struct seg6_pernet_data *seg6_data;
	struct fib_notifier_ops *notifier_ops;
	struct fib_notifier_ops *ip6mr_notifier_ops;
	unsigned int ipmr_seq;
	struct {
		struct hlist_head head;
		spinlock_t lock;
		u32 seq;
	} ip6addrlbl_table;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
};

struct netns_sysctl_lowpan {
	struct ctl_table_header *frags_hdr;
};

struct netns_ieee802154_lowpan {
	struct netns_sysctl_lowpan sysctl;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	struct netns_frags frags;
};

struct sctp_mib;

struct netns_sctp {
	struct sctp_mib *sctp_statistics;
	struct proc_dir_entry *proc_net_sctp;
	struct ctl_table_header *sysctl_header;
	struct sock *ctl_sock;
	struct list_head local_addr_list;
	struct list_head addr_waitq;
	struct timer_list addr_wq_timer;
	struct list_head auto_asconf_splist;
	spinlock_t addr_wq_lock;
	spinlock_t local_addr_lock;
	unsigned int rto_initial;
	unsigned int rto_min;
	unsigned int rto_max;
	int rto_alpha;
	int rto_beta;
	int max_burst;
	int cookie_preserve_enable;
	char *sctp_hmac_alg;
	unsigned int valid_cookie_life;
	unsigned int sack_timeout;
	unsigned int hb_interval;
	int max_retrans_association;
	int max_retrans_path;
	int max_retrans_init;
	int pf_retrans;
	int pf_enable;
	int sndbuf_policy;
	int rcvbuf_policy;
	int default_auto_asconf;
	int addip_enable;
	int addip_noauth;
	int prsctp_enable;
	int reconf_enable;
	int auth_enable;
	int intl_enable;
	int scope_policy;
	int rwnd_upd_shift;
	long unsigned int max_autoclose;
};

struct nf_queue_handler;

struct nf_logger;

struct nf_hook_entries;

struct netns_nf {
	struct proc_dir_entry *proc_netfilter;
	const struct nf_queue_handler *queue_handler;
	const struct nf_logger *nf_loggers[13];
	struct ctl_table_header *nf_log_dir_header;
	struct nf_hook_entries *hooks_ipv4[5];
	struct nf_hook_entries *hooks_ipv6[5];
	struct nf_hook_entries *hooks_arp[3];
	struct nf_hook_entries *hooks_bridge[5];
	bool defrag_ipv4;
	bool defrag_ipv6;
};

struct ebt_table;

struct netns_xt {
	struct list_head tables[13];
	bool notrack_deprecated_warning;
	bool clusterip_deprecated_warning;
	struct ebt_table *broute_table;
	struct ebt_table *frame_filter;
	struct ebt_table *frame_nat;
};

struct nf_proto_net {
	struct ctl_table_header *ctl_table_header;
	struct ctl_table *ctl_table;
	unsigned int users;
};

struct nf_generic_net {
	struct nf_proto_net pn;
	unsigned int timeout;
};

struct nf_tcp_net {
	struct nf_proto_net pn;
	unsigned int timeouts[14];
	unsigned int tcp_loose;
	unsigned int tcp_be_liberal;
	unsigned int tcp_max_retrans;
};

struct nf_udp_net {
	struct nf_proto_net pn;
	unsigned int timeouts[2];
};

struct nf_icmp_net {
	struct nf_proto_net pn;
	unsigned int timeout;
};

struct nf_dccp_net {
	struct nf_proto_net pn;
	int dccp_loose;
	unsigned int dccp_timeout[10];
};

struct nf_sctp_net {
	struct nf_proto_net pn;
	unsigned int timeouts[10];
};

struct nf_ip_net {
	struct nf_generic_net generic;
	struct nf_tcp_net tcp;
	struct nf_udp_net udp;
	struct nf_icmp_net icmp;
	struct nf_icmp_net icmpv6;
	struct nf_dccp_net dccp;
	struct nf_sctp_net sctp;
};

struct ct_pcpu;

struct ip_conntrack_stat;

struct nf_ct_event_notifier;

struct nf_exp_event_notifier;

struct netns_ct {
	atomic_t count;
	unsigned int expect_count;
	struct delayed_work ecache_dwork;
	bool ecache_dwork_pending;
	struct ctl_table_header *sysctl_header;
	struct ctl_table_header *acct_sysctl_header;
	struct ctl_table_header *tstamp_sysctl_header;
	struct ctl_table_header *event_sysctl_header;
	struct ctl_table_header *helper_sysctl_header;
	unsigned int sysctl_log_invalid;
	int sysctl_events;
	int sysctl_acct;
	int sysctl_auto_assign_helper;
	bool auto_assign_helper_warned;
	int sysctl_tstamp;
	int sysctl_checksum;
	struct ct_pcpu *pcpu_lists;
	struct ip_conntrack_stat *stat;
	struct nf_ct_event_notifier *nf_conntrack_event_cb;
	struct nf_exp_event_notifier *nf_expect_event_cb;
	struct nf_ip_net nf_ct_proto;
	unsigned int labels_used;
};

struct netns_nftables {
	struct list_head tables;
	struct list_head commit_list;
	unsigned int base_seq;
	u8 gencursor;
	u8 validate_state;
};

struct netns_nf_frag {
	struct netns_frags frags;
};

struct xfrm_policy_hash {
	struct hlist_head *table;
	unsigned int hmask;
	u8 dbits4;
	u8 sbits4;
	u8 dbits6;
	u8 sbits6;
};

struct xfrm_policy_hthresh {
	struct work_struct work;
	seqlock_t lock;
	u8 lbits4;
	u8 rbits4;
	u8 lbits6;
	u8 rbits6;
};

struct netns_xfrm {
	struct list_head state_all;
	struct hlist_head *state_bydst;
	struct hlist_head *state_bysrc;
	struct hlist_head *state_byspi;
	unsigned int state_hmask;
	unsigned int state_num;
	struct work_struct state_hash_work;
	struct list_head policy_all;
	struct hlist_head *policy_byidx;
	unsigned int policy_idx_hmask;
	struct hlist_head policy_inexact[3];
	struct xfrm_policy_hash policy_bydst[3];
	unsigned int policy_count[6];
	struct work_struct policy_hash_work;
	struct xfrm_policy_hthresh policy_hthresh;
	struct sock *nlsk;
	struct sock *nlsk_stash;
	u32 sysctl_aevent_etime;
	u32 sysctl_aevent_rseqth;
	int sysctl_larval_drop;
	u32 sysctl_acq_expires;
	struct ctl_table_header *sysctl_hdr;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	struct dst_ops xfrm4_dst_ops;
	struct dst_ops xfrm6_dst_ops;
	spinlock_t xfrm_state_lock;
	spinlock_t xfrm_policy_lock;
	struct mutex xfrm_cfg_mutex;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
};

struct netns_ipvs;

struct mpls_route;

struct netns_mpls {
	int ip_ttl_propagate;
	int default_ttl;
	size_t platform_labels;
	struct mpls_route **platform_label;
	struct ctl_table_header *ctl;
};

struct can_dev_rcv_lists;

struct s_stats;

struct s_pstats;

struct netns_can {
	struct proc_dir_entry *proc_dir;
	struct proc_dir_entry *pde_version;
	struct proc_dir_entry *pde_stats;
	struct proc_dir_entry *pde_reset_stats;
	struct proc_dir_entry *pde_rcvlist_all;
	struct proc_dir_entry *pde_rcvlist_fil;
	struct proc_dir_entry *pde_rcvlist_inv;
	struct proc_dir_entry *pde_rcvlist_sff;
	struct proc_dir_entry *pde_rcvlist_eff;
	struct proc_dir_entry *pde_rcvlist_err;
	struct proc_dir_entry *bcmproc_dir;
	struct can_dev_rcv_lists *can_rx_alldev_list;
	spinlock_t can_rcvlists_lock;
	struct timer_list can_stattimer;
	struct s_stats *can_stats;
	struct s_pstats *can_pstats;
	struct hlist_head cgw_list;
};

typedef struct {
	u64 key[2];
} siphash_key_t;

struct netns_xdp {
	struct mutex lock;
	struct hlist_head list;
};

struct nf_gre_net {
	struct nf_proto_net nf;
	struct list_head keymap_list;
	unsigned int timeouts[2];
};

struct mptcp_mib;

struct netns_mptcp_mib {
	struct mptcp_mib *mptcp_statistics;
};

struct netns_bpf {
	struct bpf_prog_array *run_array[2];
	struct bpf_prog *progs[2];
	struct list_head links[2];
};

struct uevent_sock;

struct net_generic;

struct linux_tls_mib;

struct net {
	refcount_t passive;
	refcount_t count;
	spinlock_t rules_mod_lock;
	atomic64_t rh_reserved_cookie_gen;
	struct list_head list;
	struct list_head exit_list;
	struct llist_node cleanup_list;
	struct user_namespace *user_ns;
	struct ucounts *ucounts;
	spinlock_t nsid_lock;
	struct idr netns_ids;
	struct ns_common ns;
	struct proc_dir_entry *proc_net;
	struct proc_dir_entry *proc_net_stat;
	struct ctl_table_set sysctls;
	struct sock *rtnl;
	struct sock *genl_sock;
	struct uevent_sock *uevent_sock;
	struct list_head dev_base_head;
	struct hlist_head *dev_name_head;
	struct hlist_head *dev_index_head;
	unsigned int dev_base_seq;
	int ifindex;
	unsigned int dev_unreg_count;
	struct list_head rules_ops;
	struct list_head rh_reserved_fib_notifier_ops;
	struct net_device *loopback_dev;
	struct netns_core core;
	struct netns_mib mib;
	struct netns_packet packet;
	struct netns_unix unx;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	struct netns_ipv4 ipv4;
	struct netns_ipv6 ipv6;
	struct netns_ieee802154_lowpan ieee802154_lowpan;
	struct netns_sctp sctp;
	struct netns_nf nf;
	struct netns_xt xt;
	struct netns_ct ct;
	struct netns_nftables nft;
	long: 64;
	long: 64;
	struct netns_nf_frag nf_frag;
	struct ctl_table_header *nf_frag_frags_hdr;
	struct sock *nfnl;
	struct sock *nfnl_stash;
	struct list_head nfct_timeout_list;
	struct net_generic *gen;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	struct netns_xfrm xfrm;
	struct netns_ipvs *ipvs;
	struct netns_mpls mpls;
	struct netns_can can;
	struct sock *diag_nlsk;
	atomic_t fnhe_genid;
	int ipv4_sysctl_ip_fwd_update_priority;
	int ipv4_sysctl_tcp_min_snd_mss;
	void *rh_unused;
	siphash_key_t ipv4_ip_id_key;
	u32 hash_mix;
	union {
		struct netns_xdp xdp;
		long unsigned int rh_kabi_hidden_177[21];
	};
	int sctp_ecn_enable;
	struct list_head xfrm_inexact_bins;
	struct raw_notifier_head netdev_chain;
	struct list_head nft_module_list;
	struct list_head nft_notify_list;
	struct mutex nft_commit_mutex;
	struct nf_gre_net nf_ct_gre;
	struct linux_tls_mib *mib_tls_statistics;
	struct netns_mptcp_mib mptcp_mib;
	atomic64_t net_cookie;
	int sctp_pf_expose;
	int sctp_ps_retrans;
	union {
		struct netns_bpf bpf;
		long unsigned int rh_kabi_hidden_194[128];
	};
	struct sock *sctp_udp4_sock;
	struct sock *sctp_udp6_sock;
	int sctp_udp_port;
	int sctp_encap_port;
	seqcount_spinlock_t xfrm_state_hash_generation;
	unsigned int nf_tcp_net_offload_timeout;
	unsigned int nf_udp_net_offload_timeout;
	seqcount_spinlock_t xfrm_policy_hash_generation;
	unsigned int sctp_probe_interval;
	struct hlist_head *xfrm_state_byseq;
	u32 ipv4_sysctl_fib_multipath_hash_fields;
	u32 ipv6_sysctl_multipath_hash_fields;
	struct cpumask *core_rps_default_mask;
	u64 nft_table_handle;
	int sysctl_txrehash;
	u8 ipv4_sysctl_tcp_shrink_window;
	long: 24;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
};

typedef struct {
	local64_t v;
} u64_stats_t;

struct bpf_offloaded_map;

struct bpf_map_dev_ops {
	int (*map_get_next_key)(struct bpf_offloaded_map *, void *, void *);
	int (*map_lookup_elem)(struct bpf_offloaded_map *, void *, void *);
	int (*map_update_elem)(struct bpf_offloaded_map *, void *, void *, u64);
	int (*map_delete_elem)(struct bpf_offloaded_map *, void *);
};

struct bpf_offloaded_map {
	struct bpf_map map;
	struct net_device *netdev;
	const struct bpf_map_dev_ops *dev_ops;
	void *dev_priv;
	struct list_head offloads;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
};

struct net_device_stats {
	union {
		union {
			long unsigned int rx_packets;
			atomic_long_t __rx_packets;
		};
		struct {
			long unsigned int rx_packets;
		} rh_kabi_hidden_182;
		union {		};
	};
	union {
		union {
			long unsigned int tx_packets;
			atomic_long_t __tx_packets;
		};
		struct {
			long unsigned int tx_packets;
		} rh_kabi_hidden_183;
		union {		};
	};
	union {
		union {
			long unsigned int rx_bytes;
			atomic_long_t __rx_bytes;
		};
		struct {
			long unsigned int rx_bytes;
		} rh_kabi_hidden_184;
		union {		};
	};
	union {
		union {
			long unsigned int tx_bytes;
			atomic_long_t __tx_bytes;
		};
		struct {
			long unsigned int tx_bytes;
		} rh_kabi_hidden_185;
		union {		};
	};
	union {
		union {
			long unsigned int rx_errors;
			atomic_long_t __rx_errors;
		};
		struct {
			long unsigned int rx_errors;
		} rh_kabi_hidden_186;
		union {		};
	};
	union {
		union {
			long unsigned int tx_errors;
			atomic_long_t __tx_errors;
		};
		struct {
			long unsigned int tx_errors;
		} rh_kabi_hidden_187;
		union {		};
	};
	union {
		union {
			long unsigned int rx_dropped;
			atomic_long_t __rx_dropped;
		};
		struct {
			long unsigned int rx_dropped;
		} rh_kabi_hidden_188;
		union {		};
	};
	union {
		union {
			long unsigned int tx_dropped;
			atomic_long_t __tx_dropped;
		};
		struct {
			long unsigned int tx_dropped;
		} rh_kabi_hidden_189;
		union {		};
	};
	union {
		union {
			long unsigned int multicast;
			atomic_long_t __multicast;
		};
		struct {
			long unsigned int multicast;
		} rh_kabi_hidden_190;
		union {		};
	};
	union {
		union {
			long unsigned int collisions;
			atomic_long_t __collisions;
		};
		struct {
			long unsigned int collisions;
		} rh_kabi_hidden_191;
		union {		};
	};
	union {
		union {
			long unsigned int rx_length_errors;
			atomic_long_t __rx_length_errors;
		};
		struct {
			long unsigned int rx_length_errors;
		} rh_kabi_hidden_192;
		union {		};
	};
	union {
		union {
			long unsigned int rx_over_errors;
			atomic_long_t __rx_over_errors;
		};
		struct {
			long unsigned int rx_over_errors;
		} rh_kabi_hidden_193;
		union {		};
	};
	union {
		union {
			long unsigned int rx_crc_errors;
			atomic_long_t __rx_crc_errors;
		};
		struct {
			long unsigned int rx_crc_errors;
		} rh_kabi_hidden_194;
		union {		};
	};
	union {
		union {
			long unsigned int rx_frame_errors;
			atomic_long_t __rx_frame_errors;
		};
		struct {
			long unsigned int rx_frame_errors;
		} rh_kabi_hidden_195;
		union {		};
	};
	union {
		union {
			long unsigned int rx_fifo_errors;
			atomic_long_t __rx_fifo_errors;
		};
		struct {
			long unsigned int rx_fifo_errors;
		} rh_kabi_hidden_196;
		union {		};
	};
	union {
		union {
			long unsigned int rx_missed_errors;
			atomic_long_t __rx_missed_errors;
		};
		struct {
			long unsigned int rx_missed_errors;
		} rh_kabi_hidden_197;
		union {		};
	};
	union {
		union {
			long unsigned int tx_aborted_errors;
			atomic_long_t __tx_aborted_errors;
		};
		struct {
			long unsigned int tx_aborted_errors;
		} rh_kabi_hidden_198;
		union {		};
	};
	union {
		union {
			long unsigned int tx_carrier_errors;
			atomic_long_t __tx_carrier_errors;
		};
		struct {
			long unsigned int tx_carrier_errors;
		} rh_kabi_hidden_199;
		union {		};
	};
	union {
		union {
			long unsigned int tx_fifo_errors;
			atomic_long_t __tx_fifo_errors;
		};
		struct {
			long unsigned int tx_fifo_errors;
		} rh_kabi_hidden_200;
		union {		};
	};
	union {
		union {
			long unsigned int tx_heartbeat_errors;
			atomic_long_t __tx_heartbeat_errors;
		};
		struct {
			long unsigned int tx_heartbeat_errors;
		} rh_kabi_hidden_201;
		union {		};
	};
	union {
		union {
			long unsigned int tx_window_errors;
			atomic_long_t __tx_window_errors;
		};
		struct {
			long unsigned int tx_window_errors;
		} rh_kabi_hidden_202;
		union {		};
	};
	union {
		union {
			long unsigned int rx_compressed;
			atomic_long_t __rx_compressed;
		};
		struct {
			long unsigned int rx_compressed;
		} rh_kabi_hidden_203;
		union {		};
	};
	union {
		union {
			long unsigned int tx_compressed;
			atomic_long_t __tx_compressed;
		};
		struct {
			long unsigned int tx_compressed;
		} rh_kabi_hidden_204;
		union {		};
	};
};

struct switchdev_ops;

struct netdev_hw_addr_list {
	struct list_head list;
	int count;
};

struct tipc_bearer;

struct wireless_dev;

enum rx_handler_result {
	RX_HANDLER_CONSUMED = 0,
	RX_HANDLER_ANOTHER = 1,
	RX_HANDLER_EXACT = 2,
	RX_HANDLER_PASS = 3,
};

typedef enum rx_handler_result rx_handler_result_t;

typedef rx_handler_result_t rx_handler_func_t(struct sk_buff **);

struct pcpu_dstats;

struct pcpu_vstats;

struct garp_port;

struct mrp_port;

struct netdev_tc_txq {
	u16 count;
	u16 offset;
};

struct sfp_bus;

struct mpls_dev;

struct udp_tunnel_nic;

enum netdev_ml_priv_type {
	ML_PRIV_NONE = 0,
	ML_PRIV_CAN = 1,
};

struct netdev_name_node;

struct dev_ifalias;

struct net_device_ops;

struct ethtool_ops;

struct l3mdev_ops;

struct ndisc_ops;

struct xfrmdev_ops;

struct tlsdev_ops;

struct header_ops;

struct vlan_info;

struct in_device;

struct inet6_dev;

struct wpan_dev;

struct netdev_rx_queue;

struct mini_Qdisc;

struct netdev_queue;

struct cpu_rmap;

struct Qdisc;

struct xps_dev_maps;

struct netpoll_info;

struct pcpu_lstats;

struct pcpu_sw_netstats;

struct rtnl_link_ops;

struct dcbnl_rtnl_ops;

struct netprio_map;

struct phy_device;

struct xdp_dev_bulk_queue;

struct udp_tunnel_nic_info;

struct bpf_xdp_entity;

struct net_device_core_stats;

struct net_device_extended_rh;

struct net_device {
	char name[16];
	union {
		struct netdev_name_node *name_node;
		struct {
			struct hlist_node name_hlist;
		} rh_kabi_hidden_1966;
		union {		};
	};
	struct dev_ifalias *ifalias;
	long unsigned int mem_end;
	long unsigned int mem_start;
	long unsigned int base_addr;
	int irq;
	long unsigned int state;
	struct list_head dev_list;
	struct list_head napi_list;
	struct list_head unreg_list;
	struct list_head close_list;
	struct list_head ptype_all;
	struct list_head ptype_specific;
	struct {
		struct list_head upper;
		struct list_head lower;
	} adj_list;
	netdev_features_t features;
	netdev_features_t hw_features;
	netdev_features_t wanted_features;
	netdev_features_t vlan_features;
	netdev_features_t hw_enc_features;
	netdev_features_t mpls_features;
	netdev_features_t gso_partial_features;
	int ifindex;
	int group;
	struct net_device_stats stats;
	atomic_long_t rh_rx_dropped;
	atomic_long_t rh_tx_dropped;
	atomic_long_t rh_rx_nohandler;
	atomic_t carrier_up_count;
	atomic_t carrier_down_count;
	const struct net_device_ops *netdev_ops;
	const struct ethtool_ops *ethtool_ops;
	const struct switchdev_ops *rh_reserved_switchdev_ops;
	const struct l3mdev_ops *l3mdev_ops;
	const struct ndisc_ops *ndisc_ops;
	const struct xfrmdev_ops *xfrmdev_ops;
	const struct tlsdev_ops *tlsdev_ops;
	const struct header_ops *header_ops;
	unsigned int flags;
	unsigned int priv_flags;
	short unsigned int gflags;
	short unsigned int padded;
	unsigned char operstate;
	unsigned char link_mode;
	unsigned char if_port;
	unsigned char dma;
	unsigned int mtu;
	unsigned int min_mtu;
	unsigned int max_mtu;
	short unsigned int type;
	short unsigned int hard_header_len;
	unsigned char min_header_len;
	short unsigned int needed_headroom;
	short unsigned int needed_tailroom;
	unsigned char perm_addr[32];
	unsigned char addr_assign_type;
	unsigned char addr_len;
	short unsigned int neigh_priv_len;
	short unsigned int dev_id;
	short unsigned int dev_port;
	unsigned char upper_level;
	unsigned char lower_level;
	spinlock_t addr_list_lock;
	unsigned char name_assign_type;
	bool uc_promisc;
	struct netdev_hw_addr_list uc;
	struct netdev_hw_addr_list mc;
	struct netdev_hw_addr_list dev_addrs;
	struct kset *queues_kset;
	unsigned int promiscuity;
	unsigned int allmulti;
	struct vlan_info *vlan_info;
	struct tipc_bearer *tipc_ptr;
	struct in_device *ip_ptr;
	struct inet6_dev *ip6_ptr;
	struct wireless_dev *ieee80211_ptr;
	struct wpan_dev *ieee802154_ptr;
	unsigned char *dev_addr;
	struct netdev_rx_queue *_rx;
	unsigned int num_rx_queues;
	unsigned int real_num_rx_queues;
	struct bpf_prog *xdp_prog;
	long unsigned int gro_flush_timeout;
	rx_handler_func_t *rx_handler;
	void *rx_handler_data;
	struct mini_Qdisc *miniq_ingress;
	struct netdev_queue *ingress_queue;
	struct nf_hook_entries *nf_hooks_ingress;
	unsigned char broadcast[32];
	struct cpu_rmap *rx_cpu_rmap;
	struct hlist_node index_hlist;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	struct netdev_queue *_tx;
	unsigned int num_tx_queues;
	unsigned int real_num_tx_queues;
	struct Qdisc *qdisc;
	struct hlist_head qdisc_hash[16];
	unsigned int tx_queue_len;
	spinlock_t tx_global_lock;
	int watchdog_timeo;
	struct xps_dev_maps *xps_cpus_map;
	struct xps_dev_maps *xps_rxqs_map;
	struct mini_Qdisc *miniq_egress;
	struct timer_list watchdog_timer;
	int *pcpu_refcnt;
	struct list_head todo_list;
	struct list_head link_watch_list;
	enum {
		NETREG_UNINITIALIZED = 0,
		NETREG_REGISTERED = 1,
		NETREG_UNREGISTERING = 2,
		NETREG_UNREGISTERED = 3,
		NETREG_RELEASED = 4,
		NETREG_DUMMY = 5,
	} reg_state: 8;
	bool dismantle;
	enum {
		RTNL_LINK_INITIALIZED = 0,
		RTNL_LINK_INITIALIZING = 1,
	} rtnl_link_state: 16;
	bool needs_free_netdev;
	void (*priv_destructor)(struct net_device *);
	struct netpoll_info *npinfo;
	possible_net_t nd_net;
	union {
		void *rh_reserved_ml_priv;
		struct pcpu_lstats *lstats;
		struct pcpu_sw_netstats *tstats;
		struct pcpu_dstats *dstats;
		struct pcpu_vstats *rh_reserved_vstats;
	};
	struct garp_port *garp_port;
	struct mrp_port *mrp_port;
	struct device dev;
	const struct attribute_group *sysfs_groups[4];
	const struct attribute_group *sysfs_rx_queue_group;
	const struct rtnl_link_ops *rtnl_link_ops;
	unsigned int gso_max_size;
	u16 gso_max_segs;
	const struct dcbnl_rtnl_ops *dcbnl_ops;
	s16 num_tc;
	struct netdev_tc_txq tc_to_txq[16];
	u8 prio_tc_map[16];
	u16 tso_max_segs;
	unsigned int tso_max_size;
	struct netprio_map *priomap;
	struct phy_device *phydev;
	struct sfp_bus *sfp_bus;
	struct lock_class_key *qdisc_tx_busylock;
	struct lock_class_key *rh_reserved_qdisc_running_key;
	bool proto_down;
	unsigned int wol_enabled: 1;
	unsigned int threaded: 1;
	union {
		struct mpls_dev *mpls_ptr;
		struct {
			long unsigned int rh_reserved1;
		} rh_kabi_hidden_2269;
		union {		};
	};
	union {
		struct list_head net_notifier_list;
		struct {
			long unsigned int rh_reserved2;
			long unsigned int rh_reserved3;
		} rh_kabi_hidden_2270;
		union {		};
	};
	union {
		struct xdp_dev_bulk_queue *xdp_bulkq;
		struct {
			long unsigned int rh_reserved4;
		} rh_kabi_hidden_2271;
		union {		};
	};
	union {
		const struct udp_tunnel_nic_info *udp_tunnel_nic_info;
		struct {
			long unsigned int rh_reserved5;
		} rh_kabi_hidden_2272;
		union {		};
	};
	union {
		struct udp_tunnel_nic *udp_tunnel_nic;
		struct {
			long unsigned int rh_reserved6;
		} rh_kabi_hidden_2273;
		union {		};
	};
	union {
		struct bpf_xdp_entity *xdp_state;
		struct {
			long unsigned int rh_reserved7;
		} rh_kabi_hidden_2276;
		union {		};
	};
	union {
		struct {
			int napi_defer_hard_irqs;
			enum netdev_ml_priv_type ml_priv_type;
		};
		struct {
			long unsigned int rh_reserved8;
		} rh_kabi_hidden_2279;
		union {		};
	};
	union {
		struct net_device_core_stats *core_stats;
		struct {
			long unsigned int rh_reserved9;
		} rh_kabi_hidden_2280;
		union {		};
	};
	union {
		void *ml_priv;
		struct {
			long unsigned int rh_reserved10;
		} rh_kabi_hidden_2281;
		union {		};
	};
	long unsigned int rh_reserved11;
	long unsigned int rh_reserved12;
	long unsigned int rh_reserved13;
	long unsigned int rh_reserved14;
	long unsigned int rh_reserved15;
	long unsigned int rh_reserved16;
	long unsigned int rh_reserved17;
	long unsigned int rh_reserved18;
	long unsigned int rh_reserved19;
	long unsigned int rh_reserved20;
	long unsigned int rh_reserved21;
	long unsigned int rh_reserved22;
	long unsigned int rh_reserved23;
	long unsigned int rh_reserved24;
	long unsigned int rh_reserved25;
	long unsigned int rh_reserved26;
	long unsigned int rh_reserved27;
	long unsigned int rh_reserved28;
	long unsigned int rh_reserved29;
	long unsigned int rh_reserved30;
	size_t net_device_extended_size_rh;
	struct net_device_extended_rh *_rh;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
};

struct bpf_dispatcher_prog {
	struct bpf_prog *prog;
	refcount_t users;
};

struct bpf_dispatcher {
	struct mutex mutex;
	void *func;
	struct bpf_dispatcher_prog progs[48];
	int num_progs;
	void *image;
	u32 image_off;
	struct bpf_ksym ksym;
};

typedef unsigned int sk_buff_data_t;

struct sec_path;

struct nf_bridge_info;

struct skb_ext;

struct sk_buff {
	union {
		struct {
			struct sk_buff *next;
			struct sk_buff *prev;
			union {
				struct net_device *dev;
				long unsigned int dev_scratch;
			};
		};
		struct rb_node rbnode;
		struct list_head list;
	};
	union {
		struct sock *sk;
		int ip_defrag_offset;
	};
	union {
		ktime_t tstamp;
		u64 skb_mstamp_ns;
	};
	char cb[48];
	union {
		struct {
			long unsigned int _skb_refdst;
			void (*destructor)(struct sk_buff *);
		};
		struct list_head tcp_tsorted_anchor;
		long unsigned int _sk_redir;
	};
	struct sec_path *sp;
	long unsigned int _nfct;
	struct nf_bridge_info *nf_bridge;
	unsigned int len;
	unsigned int data_len;
	__u16 mac_len;
	__u16 hdr_len;
	__u16 queue_mapping;
	__u8 __cloned_offset[0];
	__u8 cloned: 1;
	__u8 nohdr: 1;
	__u8 fclone: 2;
	__u8 peeked: 1;
	__u8 head_frag: 1;
	__u8 rh_reserved_xmit_more: 1;
	__u8 pfmemalloc: 1;
	__u8 active_extensions;
	union {
		struct {
			__u8 __pkt_type_offset[0];
			__u8 pkt_type: 3;
			__u8 ignore_df: 1;
			__u8 nf_trace: 1;
			__u8 ip_summed: 2;
			__u8 ooo_okay: 1;
			__u8 l4_hash: 1;
			__u8 sw_hash: 1;
			__u8 wifi_acked_valid: 1;
			__u8 wifi_acked: 1;
			__u8 no_fcs: 1;
			__u8 encapsulation: 1;
			__u8 encap_hdr_csum: 1;
			__u8 csum_valid: 1;
			__u8 csum_complete_sw: 1;
			__u8 csum_level: 2;
			__u8 csum_not_inet: 1;
			__u8 dst_pending_confirm: 1;
			__u8 ndisc_nodetype: 2;
			__u8 ipvs_property: 1;
			__u8 inner_protocol_type: 1;
			__u8 remcsum_offload: 1;
			__u8 offload_fwd_mark: 1;
			__u8 offload_l3_fwd_mark: 1;
			__u8 tc_skip_classify: 1;
			__u8 tc_at_ingress: 1;
			__u8 redirected: 1;
			__u8 from_ingress: 1;
			__u16 tc_index;
			__u8 decrypted: 1;
			__u8 slow_gro: 1;
			union {
				__wsum csum;
				struct {
					__u16 csum_start;
					__u16 csum_offset;
				};
			};
			__u32 priority;
			int skb_iif;
			__u32 hash;
			__be16 vlan_proto;
			__u16 vlan_tci;
			union {
				unsigned int napi_id;
				unsigned int sender_cpu;
			};
			__u32 secmark;
			union {
				__u32 mark;
				__u32 reserved_tailroom;
			};
			union {
				__be16 inner_protocol;
				__u8 inner_ipproto;
			};
			__u16 inner_transport_header;
			__u16 inner_network_header;
			__u16 inner_mac_header;
			__be16 protocol;
			__u16 transport_header;
			__u16 network_header;
			__u16 mac_header;
			char rh_reserved_start[0];
		};
		struct {
			__u8 __pkt_type_offset[0];
			__u8 pkt_type: 3;
			__u8 ignore_df: 1;
			__u8 nf_trace: 1;
			__u8 ip_summed: 2;
			__u8 ooo_okay: 1;
			__u8 l4_hash: 1;
			__u8 sw_hash: 1;
			__u8 wifi_acked_valid: 1;
			__u8 wifi_acked: 1;
			__u8 no_fcs: 1;
			__u8 encapsulation: 1;
			__u8 encap_hdr_csum: 1;
			__u8 csum_valid: 1;
			__u8 csum_complete_sw: 1;
			__u8 csum_level: 2;
			__u8 csum_not_inet: 1;
			__u8 dst_pending_confirm: 1;
			__u8 ndisc_nodetype: 2;
			__u8 ipvs_property: 1;
			__u8 inner_protocol_type: 1;
			__u8 remcsum_offload: 1;
			__u8 offload_fwd_mark: 1;
			__u8 offload_l3_fwd_mark: 1;
			__u8 tc_skip_classify: 1;
			__u8 tc_at_ingress: 1;
			__u8 redirected: 1;
			__u8 from_ingress: 1;
			__u16 tc_index;
			__u8 decrypted: 1;
			__u8 slow_gro: 1;
			union {
				__wsum csum;
				struct {
					__u16 csum_start;
					__u16 csum_offset;
				};
			};
			__u32 priority;
			int skb_iif;
			__u32 hash;
			__be16 vlan_proto;
			__u16 vlan_tci;
			union {
				unsigned int napi_id;
				unsigned int sender_cpu;
			};
			__u32 secmark;
			union {
				__u32 mark;
				__u32 reserved_tailroom;
			};
			union {
				__be16 inner_protocol;
				__u8 inner_ipproto;
			};
			__u16 inner_transport_header;
			__u16 inner_network_header;
			__u16 inner_mac_header;
			__be16 protocol;
			__u16 transport_header;
			__u16 network_header;
			__u16 mac_header;
			char rh_reserved_start[0];
		} headers;
	};
	char rh_reserved[16];
	char rh_reserved_end[0];
	sk_buff_data_t tail;
	sk_buff_data_t end;
	unsigned char *head;
	unsigned char *data;
	unsigned int truesize;
	refcount_t users;
	struct skb_ext *extensions;
};

typedef int suspend_state_t;

enum suspend_stat_step {
	SUSPEND_FREEZE = 1,
	SUSPEND_PREPARE = 2,
	SUSPEND_SUSPEND = 3,
	SUSPEND_SUSPEND_LATE = 4,
	SUSPEND_SUSPEND_NOIRQ = 5,
	SUSPEND_RESUME_NOIRQ = 6,
	SUSPEND_RESUME_EARLY = 7,
	SUSPEND_RESUME = 8,
};

struct suspend_stats {
	int success;
	int fail;
	int failed_freeze;
	int failed_prepare;
	int failed_suspend;
	int failed_suspend_late;
	int failed_suspend_noirq;
	int failed_resume;
	int failed_resume_early;
	int failed_resume_noirq;
	int last_failed_dev;
	char failed_devs[80];
	int last_failed_errno;
	int errno[2];
	int last_failed_step;
	enum suspend_stat_step failed_steps[2];
};

enum s2idle_states {
	S2IDLE_STATE_NONE = 0,
	S2IDLE_STATE_ENTER = 1,
	S2IDLE_STATE_WAKE = 2,
};

enum {
	Root_NFS = 255,
	Root_CIFS = 254,
	Root_RAM0 = 1048576,
	Root_RAM1 = 1048577,
	Root_FD0 = 2097152,
	Root_HDA1 = 3145729,
	Root_HDA2 = 3145730,
	Root_SDA1 = 8388609,
	Root_SDA2 = 8388610,
	Root_HDC1 = 23068673,
	Root_SR0 = 11534336,
};

struct xdr_buf {
	struct kvec head[1];
	struct kvec tail[1];
	struct bio_vec *bvec;
	struct page **pages;
	unsigned int page_base;
	unsigned int page_len;
	unsigned int flags;
	unsigned int buflen;
	unsigned int len;
};

struct rpc_rqst;

struct xdr_stream {
	__be32 *p;
	struct xdr_buf *buf;
	__be32 *end;
	struct kvec *iov;
	struct kvec scratch;
	struct page **page_ptr;
	unsigned int nwords;
	struct rpc_rqst *rqst;
};

struct rpc_xprt;

struct rpc_task;

struct rpc_cred;

struct rpc_rqst {
	struct rpc_xprt *rq_xprt;
	struct xdr_buf rq_snd_buf;
	struct xdr_buf rq_rcv_buf;
	struct rpc_task *rq_task;
	struct rpc_cred *rq_cred;
	__be32 rq_xid;
	int rq_cong;
	u32 rq_seqno;
	int rq_enc_pages_num;
	struct page **rq_enc_pages;
	void (*rq_release_snd_buf)(struct rpc_rqst *);
	union {
		struct list_head rq_list;
		struct rb_node rq_recv;
	};
	struct list_head rq_xmit;
	struct list_head rq_xmit2;
	void *rq_buffer;
	size_t rq_callsize;
	void *rq_rbuffer;
	size_t rq_rcvsize;
	size_t rq_xmit_bytes_sent;
	size_t rq_reply_bytes_recvd;
	struct xdr_buf rq_private_buf;
	long unsigned int rq_majortimeo;
	long unsigned int rq_minortimeo;
	long unsigned int rq_timeout;
	ktime_t rq_rtt;
	unsigned int rq_retries;
	unsigned int rq_connect_cookie;
	atomic_t rq_pin;
	u32 rq_bytes_sent;
	ktime_t rq_xtime;
	int rq_ntrans;
	struct list_head rq_bc_list;
	long unsigned int rq_bc_pa_state;
	struct list_head rq_bc_pa_list;
};

typedef void (*kxdreproc_t)(struct rpc_rqst *, struct xdr_stream *, const void *);

typedef int (*kxdrdproc_t)(struct rpc_rqst *, struct xdr_stream *, void *);

struct rpc_procinfo;

struct rpc_message {
	const struct rpc_procinfo *rpc_proc;
	void *rpc_argp;
	void *rpc_resp;
	const struct cred *rpc_cred;
};

struct rpc_procinfo {
	u32 p_proc;
	kxdreproc_t p_encode;
	kxdrdproc_t p_decode;
	unsigned int p_arglen;
	unsigned int p_replen;
	unsigned int p_timer;
	u32 p_statidx;
	const char *p_name;
};

struct rpc_wait {
	struct list_head list;
	struct list_head links;
	struct list_head timer_list;
};

struct rpc_wait_queue;

struct rpc_call_ops;

struct rpc_clnt;

struct rpc_task {
	atomic_t tk_count;
	int tk_status;
	struct list_head tk_task;
	void (*tk_callback)(struct rpc_task *);
	void (*tk_action)(struct rpc_task *);
	long unsigned int tk_timeout;
	long unsigned int tk_runstate;
	struct rpc_wait_queue *tk_waitqueue;
	union {
		struct work_struct tk_work;
		struct rpc_wait tk_wait;
	} u;
	int tk_rpc_status;
	struct rpc_message tk_msg;
	void *tk_calldata;
	const struct rpc_call_ops *tk_ops;
	struct rpc_clnt *tk_client;
	struct rpc_xprt *tk_xprt;
	struct rpc_cred *tk_op_cred;
	struct rpc_rqst *tk_rqstp;
	struct workqueue_struct *tk_workqueue;
	ktime_t tk_start;
	pid_t tk_owner;
	short unsigned int tk_flags;
	short unsigned int tk_timeouts;
	short unsigned int tk_pid;
	unsigned char tk_priority: 2;
	unsigned char tk_garb_retry: 2;
	unsigned char tk_cred_retry: 2;
};

struct rpc_timer {
	struct list_head list;
	long unsigned int expires;
	struct delayed_work dwork;
};

struct rpc_wait_queue {
	spinlock_t lock;
	struct list_head tasks[4];
	unsigned char maxpriority;
	unsigned char priority;
	unsigned char nr;
	short unsigned int qlen;
	struct rpc_timer timer_list;
	const char *name;
};

struct rpc_call_ops {
	void (*rpc_call_prepare)(struct rpc_task *, void *);
	void (*rpc_call_done)(struct rpc_task *, void *);
	void (*rpc_count_stats)(struct rpc_task *, void *);
	void (*rpc_release)(void *);
};

struct rpc_iostats;

struct rpc_pipe_dir_head {
	struct list_head pdh_entries;
	struct dentry *pdh_dentry;
};

struct rpc_rtt {
	long unsigned int timeo;
	long unsigned int srtt[5];
	long unsigned int sdrtt[5];
	int ntimeouts[5];
};

struct rpc_timeout {
	long unsigned int to_initval;
	long unsigned int to_maxval;
	long unsigned int to_increment;
	unsigned int to_retries;
	unsigned char to_exponential;
};

struct rpc_sysfs_client;

struct rpc_xprt_switch;

struct rpc_xprt_iter_ops;

struct rpc_xprt_iter {
	struct rpc_xprt_switch *xpi_xpswitch;
	struct rpc_xprt *xpi_cursor;
	const struct rpc_xprt_iter_ops *xpi_ops;
};

struct rpc_auth;

struct rpc_stat;

struct rpc_program;

struct rpc_clnt {
	refcount_t cl_count;
	unsigned int cl_clid;
	struct list_head cl_clients;
	struct list_head cl_tasks;
	atomic_t cl_pid;
	spinlock_t cl_lock;
	struct rpc_xprt *cl_xprt;
	const struct rpc_procinfo *cl_procinfo;
	u32 cl_prog;
	u32 cl_vers;
	u32 cl_maxproc;
	struct rpc_auth *cl_auth;
	struct rpc_stat *cl_stats;
	struct rpc_iostats *cl_metrics;
	unsigned int cl_softrtry: 1;
	unsigned int cl_softerr: 1;
	unsigned int cl_discrtry: 1;
	unsigned int cl_noretranstimeo: 1;
	unsigned int cl_autobind: 1;
	unsigned int cl_chatty: 1;
	struct rpc_rtt *cl_rtt;
	const struct rpc_timeout *cl_timeout;
	atomic_t cl_swapper;
	int cl_nodelen;
	char cl_nodename[65];
	struct rpc_pipe_dir_head cl_pipedir_objects;
	struct rpc_clnt *cl_parent;
	struct rpc_rtt cl_rtt_default;
	struct rpc_timeout cl_timeout_default;
	const struct rpc_program *cl_program;
	const char *cl_principal;
	struct dentry *cl_debugfs;
	struct rpc_sysfs_client *cl_sysfs;
	union {
		struct rpc_xprt_iter cl_xpi;
		struct work_struct cl_work;
	};
	const struct cred *cl_cred;
	unsigned int cl_max_connect;
};

struct svc_xprt;

struct svc_serv;

struct rpc_sysfs_xprt;

struct rpc_xprt_ops;

struct xprt_class;

struct rpc_xprt {
	struct kref kref;
	const struct rpc_xprt_ops *ops;
	unsigned int id;
	const struct rpc_timeout *timeout;
	struct __kernel_sockaddr_storage addr;
	size_t addrlen;
	int prot;
	long unsigned int cong;
	long unsigned int cwnd;
	size_t max_payload;
	struct rpc_wait_queue binding;
	struct rpc_wait_queue sending;
	struct rpc_wait_queue pending;
	struct rpc_wait_queue backlog;
	struct list_head free;
	unsigned int max_reqs;
	unsigned int min_reqs;
	unsigned int num_reqs;
	long unsigned int state;
	unsigned char resvport: 1;
	unsigned char reuseport: 1;
	atomic_t swapper;
	unsigned int bind_index;
	struct list_head xprt_switch;
	long unsigned int bind_timeout;
	long unsigned int reestablish_timeout;
	unsigned int connect_cookie;
	struct work_struct task_cleanup;
	struct timer_list timer;
	long unsigned int last_used;
	long unsigned int idle_timeout;
	long unsigned int connect_timeout;
	long unsigned int max_reconnect_timeout;
	atomic_long_t queuelen;
	spinlock_t transport_lock;
	spinlock_t reserve_lock;
	spinlock_t queue_lock;
	u32 xid;
	struct rpc_task *snd_task;
	struct list_head xmit_queue;
	struct svc_xprt *bc_xprt;
	struct svc_serv *bc_serv;
	unsigned int bc_alloc_max;
	unsigned int bc_alloc_count;
	atomic_t bc_slot_count;
	spinlock_t bc_pa_lock;
	struct list_head bc_pa_list;
	struct rb_root recv_queue;
	struct {
		long unsigned int bind_count;
		long unsigned int connect_count;
		long unsigned int connect_start;
		long unsigned int connect_time;
		long unsigned int sends;
		long unsigned int recvs;
		long unsigned int bad_xids;
		long unsigned int max_slots;
		long long unsigned int req_u;
		long long unsigned int bklog_u;
		long long unsigned int sending_u;
		long long unsigned int pending_u;
	} stat;
	struct net *xprt_net;
	const char *servername;
	const char *address_strings[6];
	struct dentry *debugfs;
	atomic_t inject_disconnect;
	struct callback_head rcu;
	const struct xprt_class *xprt_class;
	struct rpc_sysfs_xprt *xprt_sysfs;
	bool main;
};

struct rpc_credops;

struct rpc_cred {
	struct hlist_node cr_hash;
	struct list_head cr_lru;
	struct callback_head cr_rcu;
	struct rpc_auth *cr_auth;
	const struct rpc_credops *cr_ops;
	long unsigned int cr_expire;
	long unsigned int cr_flags;
	refcount_t cr_count;
	const struct cred *cr_cred;
};

typedef u32 rpc_authflavor_t;

struct ethhdr {
	unsigned char h_dest[6];
	unsigned char h_source[6];
	__be16 h_proto;
};

struct flow_dissector {
	unsigned int used_keys;
	short unsigned int offset[31];
};

struct flowi_tunnel {
	__be64 tun_id;
};

struct flowi_common {
	int flowic_oif;
	int flowic_iif;
	__u32 flowic_mark;
	__u8 flowic_tos;
	__u8 flowic_scope;
	__u8 flowic_proto;
	__u8 flowic_flags;
	__u32 flowic_secid;
	struct flowi_tunnel flowic_tun_key;
	kuid_t flowic_uid;
	union {
		__u32 flowic_multipath_hash;
		struct {
			long unsigned int rh_reserved1;
		} rh_kabi_hidden_45;
		union {		};
	};
	union {
		int flowic_l3mdev;
		struct {
			long unsigned int rh_reserved2;
		} rh_kabi_hidden_46;
		union {		};
	};
};

union flowi_uli {
	struct {
		__be16 dport;
		__be16 sport;
	} ports;
	struct {
		__u8 type;
		__u8 code;
	} icmpt;
	struct {
		__le16 dport;
		__le16 sport;
	} dnports;
	__be32 spi;
	__be32 gre_key;
	struct {
		__u8 type;
	} mht;
};

struct flowi4 {
	struct flowi_common __fl_common;
	__be32 saddr;
	__be32 daddr;
	union flowi_uli uli;
	long unsigned int rh_reserved1;
	long unsigned int rh_reserved2;
};

struct flowi6 {
	struct flowi_common __fl_common;
	struct in6_addr daddr;
	struct in6_addr saddr;
	__be32 flowlabel;
	union flowi_uli uli;
	__u32 mp_hash;
	long unsigned int rh_reserved1;
	long unsigned int rh_reserved2;
};

struct flowidn {
	struct flowi_common __fl_common;
	__le16 daddr;
	__le16 saddr;
	union flowi_uli uli;
};

struct flowi {
	union {
		struct flowi_common __fl_common;
		struct flowi4 ip4;
		struct flowi6 ip6;
		struct flowidn dn;
	} u;
};

struct ipstats_mib {
	u64 mibs[37];
	struct u64_stats_sync syncp;
};

struct icmp_mib {
	long unsigned int mibs[28];
};

struct icmpmsg_mib {
	atomic_long_t mibs[512];
};

struct icmpv6_mib {
	long unsigned int mibs[6];
};

struct icmpv6_mib_device {
	atomic_long_t mibs[6];
};

struct icmpv6msg_mib {
	atomic_long_t mibs[512];
};

struct icmpv6msg_mib_device {
	atomic_long_t mibs[512];
};

struct tcp_mib {
	long unsigned int mibs[16];
};

struct udp_mib {
	long unsigned int mibs[10];
};

struct linux_mib {
	long unsigned int mibs[120];
};

struct linux_xfrm_mib {
	long unsigned int mibs[29];
};

struct linux_tls_mib {
	long unsigned int mibs[11];
};

struct inet_frag_queue;

struct inet_frags {
	unsigned int qsize;
	void (*constructor)(struct inet_frag_queue *, const void *);
	void (*destructor)(struct inet_frag_queue *);
	void (*frag_expire)(struct timer_list *);
	struct kmem_cache *frags_cachep;
	const char *frags_cache_name;
	struct rhashtable_params rhash_params;
};

struct frag_v4_compare_key {
	__be32 saddr;
	__be32 daddr;
	u32 user;
	u32 vif;
	__be16 id;
	u16 protocol;
};

struct frag_v6_compare_key {
	struct in6_addr saddr;
	struct in6_addr daddr;
	u32 user;
	__be32 id;
	u32 iif;
};

struct inet_frag_queue {
	struct rhash_head node;
	union {
		struct frag_v4_compare_key v4;
		struct frag_v6_compare_key v6;
	} key;
	struct timer_list timer;
	spinlock_t lock;
	refcount_t refcnt;
	struct sk_buff *fragments;
	struct rb_root rb_fragments;
	struct sk_buff *fragments_tail;
	struct sk_buff *last_run_head;
	ktime_t stamp;
	int len;
	int meat;
	__u8 flags;
	u16 max_size;
	struct netns_frags *net;
	struct callback_head rcu;
};

struct fib_rule;

struct fib_lookup_arg;

struct fib_rule_hdr;

struct nlattr;

struct netlink_ext_ack;

struct nla_policy;

struct fib_rules_ops {
	int family;
	struct list_head list;
	int rule_size;
	int addr_size;
	int unresolved_rules;
	int nr_goto_rules;
	unsigned int fib_rules_seq;
	int (*action)(struct fib_rule *, struct flowi *, int, struct fib_lookup_arg *);
	bool (*suppress)(struct fib_rule *, struct fib_lookup_arg *);
	int (*match)(struct fib_rule *, struct flowi *, int);
	int (*configure)(struct fib_rule *, struct sk_buff *, struct fib_rule_hdr *, struct nlattr **, struct netlink_ext_ack *);
	int (*delete)(struct fib_rule *);
	int (*compare)(struct fib_rule *, struct fib_rule_hdr *, struct nlattr **);
	int (*fill)(struct fib_rule *, struct sk_buff *, struct fib_rule_hdr *);
	size_t (*nlmsg_payload)(struct fib_rule *);
	void (*flush_cache)(struct fib_rules_ops *);
	int nlgroup;
	const struct nla_policy *policy;
	struct list_head rules_list;
	struct module *owner;
	struct net *fro_net;
	struct callback_head rcu;
};

enum tcp_ca_event {
	CA_EVENT_TX_START = 0,
	CA_EVENT_CWND_RESTART = 1,
	CA_EVENT_COMPLETE_CWR = 2,
	CA_EVENT_LOSS = 3,
	CA_EVENT_ECN_NO_CE = 4,
	CA_EVENT_ECN_IS_CE = 5,
};

struct ack_sample;

struct rate_sample;

union tcp_cc_info;

struct tcp_congestion_ops {
	struct list_head list;
	u32 key;
	u32 flags;
	void (*init)(struct sock *);
	void (*release)(struct sock *);
	u32 (*ssthresh)(struct sock *);
	void (*cong_avoid)(struct sock *, u32, u32);
	void (*set_state)(struct sock *, u8);
	void (*cwnd_event)(struct sock *, enum tcp_ca_event);
	void (*in_ack_event)(struct sock *, u32);
	u32 (*undo_cwnd)(struct sock *);
	void (*pkts_acked)(struct sock *, const struct ack_sample *);
	u32 (*min_tso_segs)(struct sock *);
	u32 (*sndbuf_expand)(struct sock *);
	void (*cong_control)(struct sock *, const struct rate_sample *);
	size_t (*get_info)(struct sock *, u32, int *, union tcp_cc_info *);
	char name[16];
	struct module *owner;
};

struct fib_notifier_ops {
	int family;
	struct list_head list;
	unsigned int (*fib_seq_read)(struct net *);
	union {
		int (*fib_dump)(struct net *, struct notifier_block *, struct netlink_ext_ack *);
		struct {
			int (*fib_dump)(struct net *, struct notifier_block *);
		} rh_kabi_hidden_36;
		union {		};
	};
	struct module *owner;
	struct callback_head rcu;
};

struct xfrm_state;

struct lwtunnel_state;

struct dst_entry {
	struct net_device *dev;
	struct dst_ops *ops;
	long unsigned int _metrics;
	long unsigned int expires;
	struct xfrm_state *xfrm;
	int (*input)(struct sk_buff *);
	int (*output)(struct net *, struct sock *, struct sk_buff *);
	short unsigned int flags;
	short int obsolete;
	short unsigned int header_len;
	short unsigned int trailer_len;
	atomic_t __refcnt;
	int __use;
	long unsigned int lastuse;
	struct lwtunnel_state *lwtstate;
	struct callback_head callback_head;
	short int error;
	short int __pad;
	__u32 tclassid;
	long unsigned int rh_reserved1;
	long unsigned int rh_reserved2;
	long unsigned int rh_reserved3;
	long unsigned int rh_reserved4;
	long unsigned int rh_reserved5;
	long unsigned int rh_reserved6;
	long unsigned int rh_reserved7;
	long unsigned int rh_reserved8;
	long unsigned int rh_reserved9;
	long unsigned int rh_reserved10;
};

struct hh_cache {
	unsigned int hh_len;
	seqlock_t hh_lock;
	long unsigned int hh_data[4];
};

struct neigh_table;

struct neigh_parms;

struct neigh_ops;

struct neighbour {
	struct neighbour *next;
	struct neigh_table *tbl;
	struct neigh_parms *parms;
	long unsigned int confirmed;
	long unsigned int updated;
	rwlock_t lock;
	refcount_t refcnt;
	struct sk_buff_head arp_queue;
	unsigned int arp_queue_len_bytes;
	u8 protocol;
	struct timer_list timer;
	long unsigned int used;
	atomic_t probes;
	__u8 flags;
	__u8 nud_state;
	__u8 type;
	__u8 dead;
	seqlock_t ha_lock;
	unsigned char ha[32];
	struct hh_cache hh;
	int (*output)(struct neighbour *, struct sk_buff *);
	const struct neigh_ops *ops;
	struct callback_head rcu;
	struct net_device *dev;
	union {
		struct list_head gc_list;
		struct {
			long unsigned int rh_reserved1;
			long unsigned int rh_reserved2;
		} rh_kabi_hidden_164;
		union {		};
	};
	u8 primary_key[0];
};

struct ipv6_stable_secret {
	bool initialized;
	struct in6_addr secret;
};

struct ipv6_devconf {
	__s32 forwarding;
	__s32 hop_limit;
	__s32 mtu6;
	__s32 accept_ra;
	__s32 accept_redirects;
	__s32 autoconf;
	__s32 dad_transmits;
	__s32 rtr_solicits;
	__s32 rtr_solicit_interval;
	__s32 rtr_solicit_max_interval;
	__s32 rtr_solicit_delay;
	__s32 force_mld_version;
	__s32 mldv1_unsolicited_report_interval;
	__s32 mldv2_unsolicited_report_interval;
	__s32 use_tempaddr;
	__s32 temp_valid_lft;
	__s32 temp_prefered_lft;
	__s32 regen_max_retry;
	__s32 max_desync_factor;
	__s32 max_addresses;
	__s32 accept_ra_defrtr;
	__s32 accept_ra_min_hop_limit;
	__s32 accept_ra_pinfo;
	__s32 ignore_routes_with_linkdown;
	__s32 accept_ra_rtr_pref;
	__s32 rtr_probe_interval;
	__s32 accept_ra_rt_info_min_plen;
	__s32 accept_ra_rt_info_max_plen;
	__s32 proxy_ndp;
	__s32 accept_source_route;
	__s32 accept_ra_from_local;
	__s32 optimistic_dad;
	__s32 use_optimistic;
	__s32 mc_forwarding;
	__s32 disable_ipv6;
	__s32 drop_unicast_in_l2_multicast;
	__s32 accept_dad;
	__s32 force_tllao;
	__s32 ndisc_notify;
	__s32 suppress_frag_ndisc;
	__s32 accept_ra_mtu;
	__s32 drop_unsolicited_na;
	struct ipv6_stable_secret stable_secret;
	__s32 use_oif_addrs_only;
	__s32 keep_addr_on_down;
	__s32 seg6_enabled;
	__u32 enhanced_dad;
	__u32 addr_gen_mode;
	__s32 disable_policy;
	__s32 ndisc_tclass;
	struct ctl_table_header *sysctl_header;
	long unsigned int rh_reserved1;
	long unsigned int rh_reserved2;
	long unsigned int rh_reserved3;
	long unsigned int rh_reserved4;
	long unsigned int rh_reserved5;
	long unsigned int rh_reserved6;
	long unsigned int rh_reserved7;
	long unsigned int rh_reserved8;
	long unsigned int rh_reserved9;
	long unsigned int rh_reserved10;
	long unsigned int rh_reserved11;
	long unsigned int rh_reserved12;
	long unsigned int rh_reserved13;
	long unsigned int rh_reserved14;
	long unsigned int rh_reserved15;
	long unsigned int rh_reserved16;
};

struct nf_queue_entry;

struct nf_queue_handler {
	int (*outfn)(struct nf_queue_entry *, unsigned int);
	void (*nf_hook_drop)(struct net *);
};

enum nf_log_type {
	NF_LOG_TYPE_LOG = 0,
	NF_LOG_TYPE_ULOG = 1,
	NF_LOG_TYPE_MAX = 2,
};

typedef u8 u_int8_t;

struct nf_loginfo;

typedef void nf_logfn(struct net *, u_int8_t, unsigned int, const struct sk_buff *, const struct net_device *, const struct net_device *, const struct nf_loginfo *, const char *);

struct nf_logger {
	char *name;
	enum nf_log_type type;
	nf_logfn *logfn;
	struct module *me;
};

struct hlist_nulls_head {
	struct hlist_nulls_node *first;
};

struct ip_conntrack_stat {
	unsigned int found;
	unsigned int invalid;
	union {
		unsigned int clash_resolve;
		struct {
			unsigned int ignore;
		} rh_kabi_hidden_12;
		union {		};
	};
	unsigned int insert;
	unsigned int insert_failed;
	unsigned int drop;
	unsigned int early_drop;
	unsigned int error;
	unsigned int expect_new;
	unsigned int expect_create;
	unsigned int expect_delete;
	unsigned int search_restart;
};

struct ct_pcpu {
	spinlock_t lock;
	struct hlist_nulls_head unconfirmed;
	struct hlist_nulls_head dying;
};

typedef enum {
	SS_FREE = 0,
	SS_UNCONNECTED = 1,
	SS_CONNECTING = 2,
	SS_CONNECTED = 3,
	SS_DISCONNECTING = 4,
} socket_state;

struct socket_wq {
	wait_queue_head_t wait;
	struct fasync_struct *fasync_list;
	long unsigned int flags;
	struct callback_head rcu;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
};

struct proto_ops;

struct socket {
	socket_state state;
	short int type;
	long unsigned int flags;
	struct socket_wq *wq;
	struct file *file;
	struct sock *sk;
	const struct proto_ops *ops;
};

typedef int (*sk_read_actor_t)(read_descriptor_t *, struct sk_buff *, unsigned int, size_t);

struct proto_ops_extended_rh {};

struct proto_ops {
	int family;
	struct module *owner;
	int (*release)(struct socket *);
	int (*bind)(struct socket *, struct sockaddr *, int);
	int (*connect)(struct socket *, struct sockaddr *, int, int);
	int (*socketpair)(struct socket *, struct socket *);
	int (*accept)(struct socket *, struct socket *, int, bool);
	int (*getname)(struct socket *, struct sockaddr *, int);
	__poll_t (*poll)(struct file *, struct socket *, struct poll_table_struct *);
	int (*ioctl)(struct socket *, unsigned int, long unsigned int);
	int (*compat_ioctl)(struct socket *, unsigned int, long unsigned int);
	int (*listen)(struct socket *, int);
	int (*shutdown)(struct socket *, int);
	int (*setsockopt)(struct socket *, int, int, char *, unsigned int);
	int (*getsockopt)(struct socket *, int, int, char *, int *);
	int (*compat_setsockopt)(struct socket *, int, int, char *, unsigned int);
	int (*compat_getsockopt)(struct socket *, int, int, char *, int *);
	int (*sendmsg)(struct socket *, struct msghdr *, size_t);
	int (*recvmsg)(struct socket *, struct msghdr *, size_t, int);
	int (*mmap)(struct file *, struct socket *, struct vm_area_struct *);
	ssize_t (*sendpage)(struct socket *, struct page *, int, size_t, int);
	ssize_t (*splice_read)(struct socket *, loff_t *, struct pipe_inode_info *, size_t, unsigned int);
	int (*set_peek_off)(struct sock *, int);
	int (*peek_len)(struct socket *);
	int (*read_sock)(struct sock *, read_descriptor_t *, sk_read_actor_t);
	int (*sendpage_locked)(struct sock *, struct page *, int, size_t, int);
	int (*sendmsg_locked)(struct sock *, struct msghdr *, size_t);
	int (*set_rcvlowat)(struct sock *, int);
	long unsigned int rh_reserved1;
	long unsigned int rh_reserved2;
	long unsigned int rh_reserved3;
	long unsigned int rh_reserved4;
	long unsigned int rh_reserved5;
	long unsigned int rh_reserved6;
	long unsigned int rh_reserved7;
	size_t proto_ops_extended_size_rh;
	struct proto_ops_extended_rh _rh;
};

struct pipe_buf_operations;

struct pipe_buffer {
	struct page *page;
	unsigned int offset;
	unsigned int len;
	const struct pipe_buf_operations *ops;
	unsigned int flags;
	long unsigned int private;
};

struct pipe_buf_operations {
	int can_merge;
	int (*confirm)(struct pipe_inode_info *, struct pipe_buffer *);
	void (*release)(struct pipe_inode_info *, struct pipe_buffer *);
	int (*steal)(struct pipe_inode_info *, struct pipe_buffer *);
	union {
		bool (*get)(struct pipe_inode_info *, struct pipe_buffer *);
		struct {
			void (*get)(struct pipe_inode_info *, struct pipe_buffer *);
		} rh_kabi_hidden_113;
		union {		};
	};
};

struct nf_bridge_info {
	refcount_t use;
	enum {
		BRNF_PROTO_UNCHANGED = 0,
		BRNF_PROTO_8021Q = 1,
		BRNF_PROTO_PPPOE = 2,
	} orig_proto: 8;
	u8 pkt_otherhost: 1;
	u8 in_prerouting: 1;
	u8 bridged_dnat: 1;
	__u16 frag_max_size;
	struct net_device *physindev;
	struct net_device *physoutdev;
	union {
		__be32 ipv4_daddr;
		struct in6_addr ipv6_daddr;
		char neigh_header[8];
	};
};

struct skb_ext {
	refcount_t refcnt;
	u8 offset[2];
	u8 chunks;
	char: 8;
	char data[0];
};

struct skb_checksum_ops {
	__wsum (*update)(const void *, int, __wsum);
	__wsum (*combine)(__wsum, __wsum, int, int);
};

struct pernet_operations {
	struct list_head list;
	int (*init)(struct net *);
	void (*pre_exit)(struct net *);
	void (*exit)(struct net *);
	void (*exit_batch)(struct list_head *);
	unsigned int *id;
	size_t size;
};

struct auth_cred {
	const struct cred *cred;
	const char *principal;
};

struct rpc_cred_cache;

struct rpc_authops;

struct rpc_auth {
	unsigned int au_cslack;
	unsigned int au_rslack;
	unsigned int au_verfsize;
	unsigned int au_ralign;
	long unsigned int au_flags;
	const struct rpc_authops *au_ops;
	rpc_authflavor_t au_flavor;
	refcount_t au_count;
	struct rpc_cred_cache *au_credcache;
};

struct rpc_credops {
	const char *cr_name;
	int (*cr_init)(struct rpc_auth *, struct rpc_cred *);
	void (*crdestroy)(struct rpc_cred *);
	int (*crmatch)(struct auth_cred *, struct rpc_cred *, int);
	int (*crmarshal)(struct rpc_task *, struct xdr_stream *);
	int (*crrefresh)(struct rpc_task *);
	int (*crvalidate)(struct rpc_task *, struct xdr_stream *);
	int (*crwrap_req)(struct rpc_task *, struct xdr_stream *);
	int (*crunwrap_resp)(struct rpc_task *, struct xdr_stream *);
	int (*crkey_timeout)(struct rpc_cred *);
	char * (*crstringify_acceptor)(struct rpc_cred *);
	bool (*crneed_reencode)(struct rpc_task *);
};

struct rpc_auth_create_args;

struct rpcsec_gss_info;

struct rpc_authops {
	struct module *owner;
	rpc_authflavor_t au_flavor;
	char *au_name;
	struct rpc_auth * (*create)(const struct rpc_auth_create_args *, struct rpc_clnt *);
	void (*destroy)(struct rpc_auth *);
	int (*hash_cred)(struct auth_cred *, unsigned int);
	struct rpc_cred * (*lookup_cred)(struct rpc_auth *, struct auth_cred *, int);
	struct rpc_cred * (*crcreate)(struct rpc_auth *, struct auth_cred *, int, gfp_t);
	rpc_authflavor_t (*info2flavor)(struct rpcsec_gss_info *);
	int (*flavor2info)(rpc_authflavor_t, struct rpcsec_gss_info *);
	int (*key_timeout)(struct rpc_auth *, struct rpc_cred *);
};

struct rpc_auth_create_args {
	rpc_authflavor_t pseudoflavor;
	const char *target_name;
};

struct rpcsec_gss_oid {
	unsigned int len;
	u8 data[32];
};

struct rpcsec_gss_info {
	struct rpcsec_gss_oid oid;
	u32 qop;
	u32 service;
};

struct rpc_xprt_ops {
	void (*set_buffer_size)(struct rpc_xprt *, size_t, size_t);
	int (*reserve_xprt)(struct rpc_xprt *, struct rpc_task *);
	void (*release_xprt)(struct rpc_xprt *, struct rpc_task *);
	void (*alloc_slot)(struct rpc_xprt *, struct rpc_task *);
	void (*free_slot)(struct rpc_xprt *, struct rpc_rqst *);
	void (*rpcbind)(struct rpc_task *);
	void (*set_port)(struct rpc_xprt *, short unsigned int);
	void (*connect)(struct rpc_xprt *, struct rpc_task *);
	int (*get_srcaddr)(struct rpc_xprt *, char *, size_t);
	short unsigned int (*get_srcport)(struct rpc_xprt *);
	int (*buf_alloc)(struct rpc_task *);
	void (*buf_free)(struct rpc_task *);
	void (*prepare_request)(struct rpc_rqst *);
	int (*send_request)(struct rpc_rqst *);
	void (*wait_for_reply_request)(struct rpc_task *);
	void (*timer)(struct rpc_xprt *, struct rpc_task *);
	void (*release_request)(struct rpc_task *);
	void (*close)(struct rpc_xprt *);
	void (*destroy)(struct rpc_xprt *);
	void (*set_connect_timeout)(struct rpc_xprt *, long unsigned int, long unsigned int);
	void (*print_stats)(struct rpc_xprt *, struct seq_file *);
	int (*enable_swap)(struct rpc_xprt *);
	void (*disable_swap)(struct rpc_xprt *);
	void (*inject_disconnect)(struct rpc_xprt *);
	int (*bc_setup)(struct rpc_xprt *, unsigned int);
	size_t (*bc_maxpayload)(struct rpc_xprt *);
	unsigned int (*bc_num_slots)(struct rpc_xprt *);
	void (*bc_free_rqst)(struct rpc_rqst *);
	void (*bc_destroy)(struct rpc_xprt *, unsigned int);
};

struct xprt_create;

struct xprt_class {
	struct list_head list;
	int ident;
	struct rpc_xprt * (*setup)(struct xprt_create *);
	struct module *owner;
	char name[32];
	const char *netid[0];
};

struct xprt_create {
	int ident;
	struct net *net;
	struct sockaddr *srcaddr;
	struct sockaddr *dstaddr;
	size_t addrlen;
	const char *servername;
	struct svc_xprt *bc_xprt;
	struct rpc_xprt_switch *bc_xps;
	unsigned int flags;
};

struct rpc_sysfs_xprt_switch;

struct rpc_xprt_switch {
	spinlock_t xps_lock;
	struct kref xps_kref;
	unsigned int xps_id;
	unsigned int xps_nxprts;
	unsigned int xps_nactive;
	unsigned int xps_nunique_destaddr_xprts;
	atomic_long_t xps_queuelen;
	struct list_head xps_xprt_list;
	struct net *xps_net;
	const struct rpc_xprt_iter_ops *xps_iter_ops;
	struct rpc_sysfs_xprt_switch *xps_sysfs;
	struct callback_head xps_rcu;
};

struct rpc_stat {
	const struct rpc_program *program;
	unsigned int netcnt;
	unsigned int netudpcnt;
	unsigned int nettcpcnt;
	unsigned int nettcpconn;
	unsigned int netreconn;
	unsigned int rpccnt;
	unsigned int rpcretrans;
	unsigned int rpcauthrefresh;
	unsigned int rpcgarbage;
};

struct rpc_version;

struct rpc_program {
	const char *name;
	u32 number;
	unsigned int nrvers;
	const struct rpc_version **version;
	struct rpc_stat *stats;
	const char *pipe_dir_name;
};

struct ipv6_params {
	__s32 disable_ipv6;
	__s32 autoconf;
};

struct dql {
	unsigned int num_queued;
	unsigned int adj_limit;
	unsigned int last_obj_cnt;
	long: 32;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	unsigned int limit;
	unsigned int num_completed;
	unsigned int prev_ovlimit;
	unsigned int prev_num_queued;
	unsigned int prev_last_obj_cnt;
	unsigned int lowest_slack;
	long unsigned int slack_start_time;
	unsigned int max_limit;
	unsigned int min_limit;
	unsigned int slack_hold_time;
	long: 32;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
};

struct nlmsghdr {
	__u32 nlmsg_len;
	__u16 nlmsg_type;
	__u16 nlmsg_flags;
	__u32 nlmsg_seq;
	__u32 nlmsg_pid;
};

struct nlattr {
	__u16 nla_len;
	__u16 nla_type;
};

struct netlink_ext_ack {
	const char *_msg;
	const struct nlattr *bad_attr;
	u8 cookie[20];
	u8 cookie_len;
	char _msg_buf[80];
};

struct netlink_callback {
	struct sk_buff *skb;
	const struct nlmsghdr *nlh;
	int (*rh_reserved_start)(struct netlink_callback *);
	int (*dump)(struct sk_buff *, struct netlink_callback *);
	int (*done)(struct netlink_callback *);
	void *data;
	struct module *module;
	u16 family;
	u16 min_dump_alloc_rh_old;
	unsigned int prev_seq;
	unsigned int seq;
	union {
		union {
			u8 ctx[48];
			long int args[6];
		};
		struct {
			long int args[6];
		} rh_kabi_hidden_245;
		union {		};
	};
	struct netlink_ext_ack *extack;
	bool strict_check;
	u16 answer_flags;
	u32 min_dump_alloc;
};

struct ethtool_cmd {
	__u32 cmd;
	__u32 supported;
	__u32 advertising;
	__u16 speed;
	__u8 duplex;
	__u8 port;
	__u8 phy_address;
	__u8 transceiver;
	__u8 autoneg;
	__u8 mdio_support;
	__u32 maxtxpkt;
	__u32 maxrxpkt;
	__u16 speed_hi;
	__u8 eth_tp_mdix;
	__u8 eth_tp_mdix_ctrl;
	__u32 lp_advertising;
	__u32 reserved[2];
};

struct ethtool_drvinfo {
	__u32 cmd;
	char driver[32];
	char version[32];
	char fw_version[32];
	char bus_info[32];
	char erom_version[32];
	char reserved2[12];
	__u32 n_priv_flags;
	__u32 n_stats;
	__u32 testinfo_len;
	__u32 eedump_len;
	__u32 regdump_len;
};

struct ethtool_wolinfo {
	__u32 cmd;
	__u32 supported;
	__u32 wolopts;
	__u8 sopass[6];
};

struct ethtool_tunable {
	__u32 cmd;
	__u32 id;
	__u32 type_id;
	__u32 len;
	void *data[0];
};

struct ethtool_regs {
	__u32 cmd;
	__u32 version;
	__u32 len;
	__u8 data[0];
};

struct ethtool_eeprom {
	__u32 cmd;
	__u32 magic;
	__u32 offset;
	__u32 len;
	__u8 data[0];
};

struct ethtool_eee {
	__u32 cmd;
	__u32 supported;
	__u32 advertised;
	__u32 lp_advertised;
	__u32 eee_active;
	__u32 eee_enabled;
	__u32 tx_lpi_enabled;
	__u32 tx_lpi_timer;
	__u32 reserved[2];
};

struct ethtool_modinfo {
	__u32 cmd;
	__u32 type;
	__u32 eeprom_len;
	__u32 reserved[8];
};

struct ethtool_coalesce {
	__u32 cmd;
	__u32 rx_coalesce_usecs;
	__u32 rx_max_coalesced_frames;
	__u32 rx_coalesce_usecs_irq;
	__u32 rx_max_coalesced_frames_irq;
	__u32 tx_coalesce_usecs;
	__u32 tx_max_coalesced_frames;
	__u32 tx_coalesce_usecs_irq;
	__u32 tx_max_coalesced_frames_irq;
	__u32 stats_block_coalesce_usecs;
	__u32 use_adaptive_rx_coalesce;
	__u32 use_adaptive_tx_coalesce;
	__u32 pkt_rate_low;
	__u32 rx_coalesce_usecs_low;
	__u32 rx_max_coalesced_frames_low;
	__u32 tx_coalesce_usecs_low;
	__u32 tx_max_coalesced_frames_low;
	__u32 pkt_rate_high;
	__u32 rx_coalesce_usecs_high;
	__u32 rx_max_coalesced_frames_high;
	__u32 tx_coalesce_usecs_high;
	__u32 tx_max_coalesced_frames_high;
	__u32 rate_sample_interval;
};

struct ethtool_ringparam {
	__u32 cmd;
	__u32 rx_max_pending;
	__u32 rx_mini_max_pending;
	__u32 rx_jumbo_max_pending;
	__u32 tx_max_pending;
	__u32 rx_pending;
	__u32 rx_mini_pending;
	__u32 rx_jumbo_pending;
	__u32 tx_pending;
};

struct ethtool_channels {
	__u32 cmd;
	__u32 max_rx;
	__u32 max_tx;
	__u32 max_other;
	__u32 max_combined;
	__u32 rx_count;
	__u32 tx_count;
	__u32 other_count;
	__u32 combined_count;
};

struct ethtool_pauseparam {
	__u32 cmd;
	__u32 autoneg;
	__u32 rx_pause;
	__u32 tx_pause;
};

enum ethtool_link_ext_state {
	ETHTOOL_LINK_EXT_STATE_AUTONEG = 0,
	ETHTOOL_LINK_EXT_STATE_LINK_TRAINING_FAILURE = 1,
	ETHTOOL_LINK_EXT_STATE_LINK_LOGICAL_MISMATCH = 2,
	ETHTOOL_LINK_EXT_STATE_BAD_SIGNAL_INTEGRITY = 3,
	ETHTOOL_LINK_EXT_STATE_NO_CABLE = 4,
	ETHTOOL_LINK_EXT_STATE_CABLE_ISSUE = 5,
	ETHTOOL_LINK_EXT_STATE_EEPROM_ISSUE = 6,
	ETHTOOL_LINK_EXT_STATE_CALIBRATION_FAILURE = 7,
	ETHTOOL_LINK_EXT_STATE_POWER_BUDGET_EXCEEDED = 8,
	ETHTOOL_LINK_EXT_STATE_OVERHEAT = 9,
	ETHTOOL_LINK_EXT_STATE_MODULE = 10,
};

enum ethtool_link_ext_substate_autoneg {
	ETHTOOL_LINK_EXT_SUBSTATE_AN_NO_PARTNER_DETECTED = 1,
	ETHTOOL_LINK_EXT_SUBSTATE_AN_ACK_NOT_RECEIVED = 2,
	ETHTOOL_LINK_EXT_SUBSTATE_AN_NEXT_PAGE_EXCHANGE_FAILED = 3,
	ETHTOOL_LINK_EXT_SUBSTATE_AN_NO_PARTNER_DETECTED_FORCE_MODE = 4,
	ETHTOOL_LINK_EXT_SUBSTATE_AN_FEC_MISMATCH_DURING_OVERRIDE = 5,
	ETHTOOL_LINK_EXT_SUBSTATE_AN_NO_HCD = 6,
};

enum ethtool_link_ext_substate_link_training {
	ETHTOOL_LINK_EXT_SUBSTATE_LT_KR_FRAME_LOCK_NOT_ACQUIRED = 1,
	ETHTOOL_LINK_EXT_SUBSTATE_LT_KR_LINK_INHIBIT_TIMEOUT = 2,
	ETHTOOL_LINK_EXT_SUBSTATE_LT_KR_LINK_PARTNER_DID_NOT_SET_RECEIVER_READY = 3,
	ETHTOOL_LINK_EXT_SUBSTATE_LT_REMOTE_FAULT = 4,
};

enum ethtool_link_ext_substate_link_logical_mismatch {
	ETHTOOL_LINK_EXT_SUBSTATE_LLM_PCS_DID_NOT_ACQUIRE_BLOCK_LOCK = 1,
	ETHTOOL_LINK_EXT_SUBSTATE_LLM_PCS_DID_NOT_ACQUIRE_AM_LOCK = 2,
	ETHTOOL_LINK_EXT_SUBSTATE_LLM_PCS_DID_NOT_GET_ALIGN_STATUS = 3,
	ETHTOOL_LINK_EXT_SUBSTATE_LLM_FC_FEC_IS_NOT_LOCKED = 4,
	ETHTOOL_LINK_EXT_SUBSTATE_LLM_RS_FEC_IS_NOT_LOCKED = 5,
};

enum ethtool_link_ext_substate_bad_signal_integrity {
	ETHTOOL_LINK_EXT_SUBSTATE_BSI_LARGE_NUMBER_OF_PHYSICAL_ERRORS = 1,
	ETHTOOL_LINK_EXT_SUBSTATE_BSI_UNSUPPORTED_RATE = 2,
};

enum ethtool_link_ext_substate_cable_issue {
	ETHTOOL_LINK_EXT_SUBSTATE_CI_UNSUPPORTED_CABLE = 1,
	ETHTOOL_LINK_EXT_SUBSTATE_CI_CABLE_TEST_FAILURE = 2,
};

enum ethtool_link_ext_substate_module {
	ETHTOOL_LINK_EXT_SUBSTATE_MODULE_CMIS_NOT_READY = 1,
};

struct ethtool_test {
	__u32 cmd;
	__u32 flags;
	__u32 reserved;
	__u32 len;
	__u64 data[0];
};

struct ethtool_stats {
	__u32 cmd;
	__u32 n_stats;
	__u64 data[0];
};

struct ethtool_tcpip4_spec {
	__be32 ip4src;
	__be32 ip4dst;
	__be16 psrc;
	__be16 pdst;
	__u8 tos;
};

struct ethtool_ah_espip4_spec {
	__be32 ip4src;
	__be32 ip4dst;
	__be32 spi;
	__u8 tos;
};

struct ethtool_usrip4_spec {
	__be32 ip4src;
	__be32 ip4dst;
	__be32 l4_4_bytes;
	__u8 tos;
	__u8 ip_ver;
	__u8 proto;
};

struct ethtool_tcpip6_spec {
	__be32 ip6src[4];
	__be32 ip6dst[4];
	__be16 psrc;
	__be16 pdst;
	__u8 tclass;
};

struct ethtool_ah_espip6_spec {
	__be32 ip6src[4];
	__be32 ip6dst[4];
	__be32 spi;
	__u8 tclass;
};

struct ethtool_usrip6_spec {
	__be32 ip6src[4];
	__be32 ip6dst[4];
	__be32 l4_4_bytes;
	__u8 tclass;
	__u8 l4_proto;
};

union ethtool_flow_union {
	struct ethtool_tcpip4_spec tcp_ip4_spec;
	struct ethtool_tcpip4_spec udp_ip4_spec;
	struct ethtool_tcpip4_spec sctp_ip4_spec;
	struct ethtool_ah_espip4_spec ah_ip4_spec;
	struct ethtool_ah_espip4_spec esp_ip4_spec;
	struct ethtool_usrip4_spec usr_ip4_spec;
	struct ethtool_tcpip6_spec tcp_ip6_spec;
	struct ethtool_tcpip6_spec udp_ip6_spec;
	struct ethtool_tcpip6_spec sctp_ip6_spec;
	struct ethtool_ah_espip6_spec ah_ip6_spec;
	struct ethtool_ah_espip6_spec esp_ip6_spec;
	struct ethtool_usrip6_spec usr_ip6_spec;
	struct ethhdr ether_spec;
	__u8 hdata[52];
};

struct ethtool_flow_ext {
	__u8 padding[2];
	unsigned char h_dest[6];
	__be16 vlan_etype;
	__be16 vlan_tci;
	__be32 data[2];
};

struct ethtool_rx_flow_spec {
	__u32 flow_type;
	union ethtool_flow_union h_u;
	struct ethtool_flow_ext h_ext;
	union ethtool_flow_union m_u;
	struct ethtool_flow_ext m_ext;
	__u64 ring_cookie;
	__u32 location;
};

struct ethtool_rxnfc {
	__u32 cmd;
	__u32 flow_type;
	__u64 data;
	struct ethtool_rx_flow_spec fs;
	union {
		__u32 rule_cnt;
		__u32 rss_context;
	};
	__u32 rule_locs[0];
};

struct ethtool_flash {
	__u32 cmd;
	__u32 region;
	char data[128];
};

struct ethtool_dump {
	__u32 cmd;
	__u32 version;
	__u32 flag;
	__u32 len;
	__u8 data[0];
};

struct ethtool_ts_info {
	__u32 cmd;
	__u32 so_timestamping;
	__s32 phc_index;
	__u32 tx_types;
	__u32 tx_reserved[3];
	__u32 rx_filters;
	__u32 rx_reserved[3];
};

struct ethtool_fecparam {
	__u32 cmd;
	__u32 active_fec;
	__u32 fec;
	__u32 reserved;
};

struct ethtool_link_settings {
	__u32 cmd;
	__u32 speed;
	__u8 duplex;
	__u8 port;
	__u8 phy_address;
	__u8 autoneg;
	__u8 mdio_support;
	__u8 eth_tp_mdix;
	__u8 eth_tp_mdix_ctrl;
	__s8 link_mode_masks_nwords;
	__u8 transceiver;
	__u8 master_slave_cfg;
	__u8 master_slave_state;
	__u8 reserved1[1];
	__u32 reserved[7];
	__u32 link_mode_masks[0];
};

enum ethtool_phys_id_state {
	ETHTOOL_ID_INACTIVE = 0,
	ETHTOOL_ID_ACTIVE = 1,
	ETHTOOL_ID_ON = 2,
	ETHTOOL_ID_OFF = 3,
};

struct kernel_ethtool_ringparam {
	u32 rx_buf_len;
	u8 tcp_data_split;
};

struct ethtool_link_ext_state_info {
	enum ethtool_link_ext_state link_ext_state;
	union {
		enum ethtool_link_ext_substate_autoneg autoneg;
		enum ethtool_link_ext_substate_link_training link_training;
		enum ethtool_link_ext_substate_link_logical_mismatch link_logical_mismatch;
		enum ethtool_link_ext_substate_bad_signal_integrity bad_signal_integrity;
		enum ethtool_link_ext_substate_cable_issue cable_issue;
		enum ethtool_link_ext_substate_module module;
		u32 __link_ext_substate;
	};
};

struct ethtool_link_ksettings {
	struct ethtool_link_settings base;
	struct {
		long unsigned int supported[2];
		long unsigned int advertising[2];
		long unsigned int lp_advertising[2];
	} link_modes;
	union {
		struct {
			u32 lanes;
		};
		long unsigned int rh_kabi_hidden_162[4];
	};
};

struct kernel_ethtool_coalesce {
	u8 use_cqe_mode_tx;
	u8 use_cqe_mode_rx;
};

struct ethtool_eth_mac_stats {
	u64 FramesTransmittedOK;
	u64 SingleCollisionFrames;
	u64 MultipleCollisionFrames;
	u64 FramesReceivedOK;
	u64 FrameCheckSequenceErrors;
	u64 AlignmentErrors;
	u64 OctetsTransmittedOK;
	u64 FramesWithDeferredXmissions;
	u64 LateCollisions;
	u64 FramesAbortedDueToXSColls;
	u64 FramesLostDueToIntMACXmitError;
	u64 CarrierSenseErrors;
	u64 OctetsReceivedOK;
	u64 FramesLostDueToIntMACRcvError;
	u64 MulticastFramesXmittedOK;
	u64 BroadcastFramesXmittedOK;
	u64 FramesWithExcessiveDeferral;
	u64 MulticastFramesReceivedOK;
	u64 BroadcastFramesReceivedOK;
	u64 InRangeLengthErrors;
	u64 OutOfRangeLengthField;
	u64 FrameTooLongErrors;
};

struct ethtool_eth_phy_stats {
	u64 SymbolErrorDuringCarrier;
};

struct ethtool_eth_ctrl_stats {
	u64 MACControlFramesTransmitted;
	u64 MACControlFramesReceived;
	u64 UnsupportedOpcodesReceived;
};

struct ethtool_pause_stats {
	u64 tx_pause_frames;
	u64 rx_pause_frames;
};

struct ethtool_fec_stat {
	u64 total;
	u64 lanes[8];
};

struct ethtool_fec_stats {
	struct ethtool_fec_stat corrected_blocks;
	struct ethtool_fec_stat uncorrectable_blocks;
	struct ethtool_fec_stat corrected_bits;
};

struct ethtool_rmon_hist_range {
	u16 low;
	u16 high;
};

struct ethtool_rmon_stats {
	u64 undersize_pkts;
	u64 oversize_pkts;
	u64 fragments;
	u64 jabbers;
	u64 hist[10];
	u64 hist_tx[10];
};

struct ethtool_module_eeprom {
	u32 offset;
	u32 length;
	u8 page;
	u8 bank;
	u8 i2c_address;
	u8 *data;
};

struct ethtool_ops_extended_rh {};

struct ethtool_link_ksettings_rh80 {
	struct ethtool_link_settings base;
	struct {
		long unsigned int supported[1];
		long unsigned int advertising[1];
		long unsigned int lp_advertising[1];
	} link_modes;
};

struct ethtool_ops {
	int (*get_settings)(struct net_device *, struct ethtool_cmd *);
	int (*set_settings)(struct net_device *, struct ethtool_cmd *);
	void (*get_drvinfo)(struct net_device *, struct ethtool_drvinfo *);
	int (*get_regs_len)(struct net_device *);
	void (*get_regs)(struct net_device *, struct ethtool_regs *, void *);
	void (*get_wol)(struct net_device *, struct ethtool_wolinfo *);
	int (*set_wol)(struct net_device *, struct ethtool_wolinfo *);
	u32 (*get_msglevel)(struct net_device *);
	void (*set_msglevel)(struct net_device *, u32);
	int (*nway_reset)(struct net_device *);
	u32 (*get_link)(struct net_device *);
	int (*get_eeprom_len)(struct net_device *);
	int (*get_eeprom)(struct net_device *, struct ethtool_eeprom *, u8 *);
	int (*set_eeprom)(struct net_device *, struct ethtool_eeprom *, u8 *);
	union {
		int (*get_coalesce)(struct net_device *, struct ethtool_coalesce *, struct kernel_ethtool_coalesce *, struct netlink_ext_ack *);
		struct {
			int (*get_coalesce)(struct net_device *, struct ethtool_coalesce *);
		} rh_kabi_hidden_671;
		union {		};
	};
	union {
		int (*set_coalesce)(struct net_device *, struct ethtool_coalesce *, struct kernel_ethtool_coalesce *, struct netlink_ext_ack *);
		struct {
			int (*set_coalesce)(struct net_device *, struct ethtool_coalesce *);
		} rh_kabi_hidden_677;
		union {		};
	};
	union {
		void (*get_ringparam)(struct net_device *, struct ethtool_ringparam *, struct kernel_ethtool_ringparam *, struct netlink_ext_ack *);
		struct {
			void (*get_ringparam)(struct net_device *, struct ethtool_ringparam *);
		} rh_kabi_hidden_683;
		union {		};
	};
	union {
		int (*set_ringparam)(struct net_device *, struct ethtool_ringparam *, struct kernel_ethtool_ringparam *, struct netlink_ext_ack *);
		struct {
			int (*set_ringparam)(struct net_device *, struct ethtool_ringparam *);
		} rh_kabi_hidden_689;
		union {		};
	};
	void (*get_pauseparam)(struct net_device *, struct ethtool_pauseparam *);
	int (*set_pauseparam)(struct net_device *, struct ethtool_pauseparam *);
	void (*self_test)(struct net_device *, struct ethtool_test *, u64 *);
	void (*get_strings)(struct net_device *, u32, u8 *);
	int (*set_phys_id)(struct net_device *, enum ethtool_phys_id_state);
	void (*get_ethtool_stats)(struct net_device *, struct ethtool_stats *, u64 *);
	int (*begin)(struct net_device *);
	void (*complete)(struct net_device *);
	u32 (*get_priv_flags)(struct net_device *);
	int (*set_priv_flags)(struct net_device *, u32);
	int (*get_sset_count)(struct net_device *, int);
	int (*get_rxnfc)(struct net_device *, struct ethtool_rxnfc *, u32 *);
	int (*set_rxnfc)(struct net_device *, struct ethtool_rxnfc *);
	int (*flash_device)(struct net_device *, struct ethtool_flash *);
	int (*reset)(struct net_device *, u32 *);
	u32 (*get_rxfh_key_size)(struct net_device *);
	u32 (*get_rxfh_indir_size)(struct net_device *);
	int (*get_rxfh)(struct net_device *, u32 *, u8 *, u8 *);
	int (*set_rxfh)(struct net_device *, const u32 *, const u8 *, const u8);
	int (*get_rxfh_context)(struct net_device *, u32 *, u8 *, u8 *, u32);
	int (*set_rxfh_context)(struct net_device *, const u32 *, const u8 *, const u8, u32 *, bool);
	void (*get_channels)(struct net_device *, struct ethtool_channels *);
	int (*set_channels)(struct net_device *, struct ethtool_channels *);
	int (*get_dump_flag)(struct net_device *, struct ethtool_dump *);
	int (*get_dump_data)(struct net_device *, struct ethtool_dump *, void *);
	int (*set_dump)(struct net_device *, struct ethtool_dump *);
	int (*get_ts_info)(struct net_device *, struct ethtool_ts_info *);
	int (*get_module_info)(struct net_device *, struct ethtool_modinfo *);
	int (*get_module_eeprom)(struct net_device *, struct ethtool_eeprom *, u8 *);
	int (*get_eee)(struct net_device *, struct ethtool_eee *);
	int (*set_eee)(struct net_device *, struct ethtool_eee *);
	int (*get_tunable)(struct net_device *, const struct ethtool_tunable *, void *);
	int (*set_tunable)(struct net_device *, const struct ethtool_tunable *, const void *);
	int (*get_per_queue_coalesce)(struct net_device *, u32, struct ethtool_coalesce *);
	int (*set_per_queue_coalesce)(struct net_device *, u32, struct ethtool_coalesce *);
	union {
		int (*get_link_ksettings_rh80)(struct net_device *, struct ethtool_link_ksettings_rh80 *);
		struct {
			int (*get_link_ksettings)(struct net_device *, struct ethtool_link_ksettings *);
		} rh_kabi_hidden_744;
		union {		};
	};
	union {
		int (*set_link_ksettings_rh80)(struct net_device *, const struct ethtool_link_ksettings_rh80 *);
		struct {
			int (*set_link_ksettings)(struct net_device *, const struct ethtool_link_ksettings *);
		} rh_kabi_hidden_748;
		union {		};
	};
	int (*get_fecparam)(struct net_device *, struct ethtool_fecparam *);
	int (*set_fecparam)(struct net_device *, struct ethtool_fecparam *);
	void (*get_ethtool_phy_stats)(struct net_device *, struct ethtool_stats *, u64 *);
	union {
		int (*get_link_ksettings)(struct net_device *, struct ethtool_link_ksettings *);
		struct {
			long unsigned int rh_reserved1;
		} rh_kabi_hidden_757;
		union {		};
	};
	union {
		int (*set_link_ksettings)(struct net_device *, const struct ethtool_link_ksettings *);
		struct {
			long unsigned int rh_reserved2;
		} rh_kabi_hidden_759;
		union {		};
	};
	union {
		struct {
			u32 supported_coalesce_params;
			u32 cap_link_lanes_supported: 1;
		};
		struct {
			long unsigned int rh_reserved3;
		} rh_kabi_hidden_761;
		union {		};
	};
	union {
		int (*get_link_ext_state)(struct net_device *, struct ethtool_link_ext_state_info *);
		struct {
			long unsigned int rh_reserved4;
		} rh_kabi_hidden_763;
		union {		};
	};
	union {
		void (*get_pause_stats)(struct net_device *, struct ethtool_pause_stats *);
		struct {
			long unsigned int rh_reserved5;
		} rh_kabi_hidden_765;
		union {		};
	};
	union {
		int (*get_phy_tunable)(struct net_device *, const struct ethtool_tunable *, void *);
		struct {
			long unsigned int rh_reserved6;
		} rh_kabi_hidden_767;
		union {		};
	};
	union {
		int (*set_phy_tunable)(struct net_device *, const struct ethtool_tunable *, const void *);
		struct {
			long unsigned int rh_reserved7;
		} rh_kabi_hidden_769;
		union {		};
	};
	union {
		int (*get_module_eeprom_by_page)(struct net_device *, const struct ethtool_module_eeprom *, struct netlink_ext_ack *);
		struct {
			long unsigned int rh_reserved8;
		} rh_kabi_hidden_772;
		union {		};
	};
	union {
		void (*get_fec_stats)(struct net_device *, struct ethtool_fec_stats *);
		struct {
			long unsigned int rh_reserved9;
		} rh_kabi_hidden_774;
		union {		};
	};
	union {
		void (*get_eth_phy_stats)(struct net_device *, struct ethtool_eth_phy_stats *);
		struct {
			long unsigned int rh_reserved10;
		} rh_kabi_hidden_776;
		union {		};
	};
	union {
		void (*get_eth_mac_stats)(struct net_device *, struct ethtool_eth_mac_stats *);
		struct {
			long unsigned int rh_reserved11;
		} rh_kabi_hidden_778;
		union {		};
	};
	union {
		void (*get_eth_ctrl_stats)(struct net_device *, struct ethtool_eth_ctrl_stats *);
		struct {
			long unsigned int rh_reserved12;
		} rh_kabi_hidden_780;
		union {		};
	};
	union {
		void (*get_rmon_stats)(struct net_device *, struct ethtool_rmon_stats *, const struct ethtool_rmon_hist_range **);
		struct {
			long unsigned int rh_reserved13;
		} rh_kabi_hidden_783;
		union {		};
	};
	union {
		u32 supported_ring_params;
		struct {
			long unsigned int rh_reserved14;
		} rh_kabi_hidden_784;
		union {		};
	};
	long unsigned int rh_reserved15;
	long unsigned int rh_reserved16;
	long unsigned int rh_reserved17;
	long unsigned int rh_reserved18;
	long unsigned int rh_reserved19;
	long unsigned int rh_reserved20;
	long unsigned int rh_reserved21;
	long unsigned int rh_reserved22;
	long unsigned int rh_reserved23;
	long unsigned int rh_reserved24;
	long unsigned int rh_reserved25;
	long unsigned int rh_reserved26;
	long unsigned int rh_reserved27;
	long unsigned int rh_reserved28;
	long unsigned int rh_reserved29;
	long unsigned int rh_reserved30;
	long unsigned int rh_reserved31;
	size_t ethtool_ops_extended_size_rh;
	struct ethtool_ops_extended_rh _rh;
};

struct ieee_ets {
	__u8 willing;
	__u8 ets_cap;
	__u8 cbs;
	__u8 tc_tx_bw[8];
	__u8 tc_rx_bw[8];
	__u8 tc_tsa[8];
	__u8 prio_tc[8];
	__u8 tc_reco_bw[8];
	__u8 tc_reco_tsa[8];
	__u8 reco_prio_tc[8];
};

struct ieee_maxrate {
	__u64 tc_maxrate[8];
};

struct ieee_qcn {
	__u8 rpg_enable[8];
	__u32 rppp_max_rps[8];
	__u32 rpg_time_reset[8];
	__u32 rpg_byte_reset[8];
	__u32 rpg_threshold[8];
	__u32 rpg_max_rate[8];
	__u32 rpg_ai_rate[8];
	__u32 rpg_hai_rate[8];
	__u32 rpg_gd[8];
	__u32 rpg_min_dec_fac[8];
	__u32 rpg_min_rate[8];
	__u32 cndd_state_machine[8];
};

struct ieee_qcn_stats {
	__u64 rppp_rp_centiseconds[8];
	__u32 rppp_created_rps[8];
};

struct ieee_pfc {
	__u8 pfc_cap;
	__u8 pfc_en;
	__u8 mbc;
	__u16 delay;
	__u64 requests[8];
	__u64 indications[8];
};

struct dcbnl_buffer {
	__u8 prio2buffer[8];
	__u32 buffer_size[8];
	__u32 total_size;
};

struct cee_pg {
	__u8 willing;
	__u8 error;
	__u8 pg_en;
	__u8 tcs_supported;
	__u8 pg_bw[8];
	__u8 prio_pg[8];
};

struct cee_pfc {
	__u8 willing;
	__u8 error;
	__u8 pfc_en;
	__u8 tcs_supported;
};

struct dcb_app {
	__u8 selector;
	__u8 priority;
	__u16 protocol;
};

struct dcb_peer_app_info {
	__u8 willing;
	__u8 error;
};

struct dcbnl_rtnl_ops_extended_rh {};

struct dcbnl_rtnl_ops {
	int (*ieee_getets)(struct net_device *, struct ieee_ets *);
	int (*ieee_setets)(struct net_device *, struct ieee_ets *);
	int (*ieee_getmaxrate)(struct net_device *, struct ieee_maxrate *);
	int (*ieee_setmaxrate)(struct net_device *, struct ieee_maxrate *);
	int (*ieee_getqcn)(struct net_device *, struct ieee_qcn *);
	int (*ieee_setqcn)(struct net_device *, struct ieee_qcn *);
	int (*ieee_getqcnstats)(struct net_device *, struct ieee_qcn_stats *);
	int (*ieee_getpfc)(struct net_device *, struct ieee_pfc *);
	int (*ieee_setpfc)(struct net_device *, struct ieee_pfc *);
	int (*ieee_getapp)(struct net_device *, struct dcb_app *);
	int (*ieee_setapp)(struct net_device *, struct dcb_app *);
	int (*ieee_delapp)(struct net_device *, struct dcb_app *);
	int (*ieee_peer_getets)(struct net_device *, struct ieee_ets *);
	int (*ieee_peer_getpfc)(struct net_device *, struct ieee_pfc *);
	u8 (*getstate)(struct net_device *);
	u8 (*setstate)(struct net_device *, u8);
	void (*getpermhwaddr)(struct net_device *, u8 *);
	void (*setpgtccfgtx)(struct net_device *, int, u8, u8, u8, u8);
	void (*setpgbwgcfgtx)(struct net_device *, int, u8);
	void (*setpgtccfgrx)(struct net_device *, int, u8, u8, u8, u8);
	void (*setpgbwgcfgrx)(struct net_device *, int, u8);
	void (*getpgtccfgtx)(struct net_device *, int, u8 *, u8 *, u8 *, u8 *);
	void (*getpgbwgcfgtx)(struct net_device *, int, u8 *);
	void (*getpgtccfgrx)(struct net_device *, int, u8 *, u8 *, u8 *, u8 *);
	void (*getpgbwgcfgrx)(struct net_device *, int, u8 *);
	void (*setpfccfg)(struct net_device *, int, u8);
	void (*getpfccfg)(struct net_device *, int, u8 *);
	u8 (*setall)(struct net_device *);
	u8 (*getcap)(struct net_device *, int, u8 *);
	int (*getnumtcs)(struct net_device *, int, u8 *);
	int (*setnumtcs)(struct net_device *, int, u8);
	u8 (*getpfcstate)(struct net_device *);
	void (*setpfcstate)(struct net_device *, u8);
	void (*getbcncfg)(struct net_device *, int, u32 *);
	void (*setbcncfg)(struct net_device *, int, u32);
	void (*getbcnrp)(struct net_device *, int, u8 *);
	void (*setbcnrp)(struct net_device *, int, u8);
	int (*setapp)(struct net_device *, u8, u16, u8);
	int (*getapp)(struct net_device *, u8, u16);
	u8 (*getfeatcfg)(struct net_device *, int, u8 *);
	u8 (*setfeatcfg)(struct net_device *, int, u8);
	u8 (*getdcbx)(struct net_device *);
	u8 (*setdcbx)(struct net_device *, u8);
	int (*peer_getappinfo)(struct net_device *, struct dcb_peer_app_info *, u16 *);
	int (*peer_getapptable)(struct net_device *, struct dcb_app *);
	int (*cee_peer_getpg)(struct net_device *, struct cee_pg *);
	int (*cee_peer_getpfc)(struct net_device *, struct cee_pfc *);
	int (*dcbnl_getbuffer)(struct net_device *, struct dcbnl_buffer *);
	int (*dcbnl_setbuffer)(struct net_device *, struct dcbnl_buffer *);
	long unsigned int rh_reserved1;
	long unsigned int rh_reserved2;
	long unsigned int rh_reserved3;
	long unsigned int rh_reserved4;
	long unsigned int rh_reserved5;
	long unsigned int rh_reserved6;
	long unsigned int rh_reserved8;
	long unsigned int rh_reserved9;
	long unsigned int rh_reserved10;
	long unsigned int rh_reserved11;
	long unsigned int rh_reserved12;
	long unsigned int rh_reserved13;
	long unsigned int rh_reserved14;
	long unsigned int rh_reserved15;
	size_t dcbnl_rtnl_ops_extended_size_rh;
	struct dcbnl_rtnl_ops_extended_rh _rh;
};

struct netprio_map {
	struct callback_head rcu;
	u32 priomap_len;
	u32 priomap[0];
};

struct xdp_mem_info {
	u32 type;
	u32 id;
};

struct xdp_rxq_info {
	struct net_device *dev;
	u32 queue_index;
	u32 reg_state;
	struct xdp_mem_info mem;
	union {
		unsigned int napi_id;
		struct {
			long unsigned int rh_reserved1;
		} rh_kabi_hidden_68;
		union {		};
	};
	long unsigned int rh_reserved2;
	long unsigned int rh_reserved3;
	long unsigned int rh_reserved4;
	long unsigned int rh_reserved5;
	long unsigned int rh_reserved6;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
};

struct xdp_frame {
	void *data;
	u16 len;
	u16 headroom;
	u32 metasize: 8;
	u32 frame_sz: 24;
	struct xdp_mem_info mem;
	struct net_device *dev_rx;
};

struct ndmsg {
	__u8 ndm_family;
	__u8 ndm_pad1;
	__u16 ndm_pad2;
	__s32 ndm_ifindex;
	__u16 ndm_state;
	__u8 ndm_flags;
	__u8 ndm_type;
};

struct rtnl_link_stats64 {
	__u64 rx_packets;
	__u64 tx_packets;
	__u64 rx_bytes;
	__u64 tx_bytes;
	__u64 rx_errors;
	__u64 tx_errors;
	__u64 rx_dropped;
	__u64 tx_dropped;
	__u64 multicast;
	__u64 collisions;
	__u64 rx_length_errors;
	__u64 rx_over_errors;
	__u64 rx_crc_errors;
	__u64 rx_frame_errors;
	__u64 rx_fifo_errors;
	__u64 rx_missed_errors;
	__u64 tx_aborted_errors;
	__u64 tx_carrier_errors;
	__u64 tx_fifo_errors;
	__u64 tx_heartbeat_errors;
	__u64 tx_window_errors;
	__u64 rx_compressed;
	__u64 tx_compressed;
	__u64 rx_nohandler;
	char __rh_tail[0];
	__u64 __rh_reserved_1;
	__u64 __rh_reserved_2;
	__u64 __rh_reserved_3;
	__u64 __rh_reserved_4;
};

struct ifla_vf_guid {
	__u32 vf;
	__u64 guid;
};

struct ifla_vf_stats {
	__u64 rx_packets;
	__u64 tx_packets;
	__u64 rx_bytes;
	__u64 tx_bytes;
	__u64 broadcast;
	__u64 multicast;
	__u64 rx_dropped;
	__u64 tx_dropped;
};

struct ifla_vf_info {
	__u32 vf;
	__u8 mac[32];
	__u32 vlan;
	__u32 qos;
	__u32 spoofchk;
	__u32 linkstate;
	__u32 min_tx_rate;
	__u32 max_tx_rate;
	__u32 rss_query_en;
	__u32 trusted;
	__be16 vlan_proto;
};

struct tc_stats {
	__u64 bytes;
	__u32 packets;
	__u32 drops;
	__u32 overlimits;
	__u32 bps;
	__u32 pps;
	__u32 qlen;
	__u32 backlog;
};

struct tc_sizespec {
	unsigned char cell_log;
	unsigned char size_log;
	short int cell_align;
	int overhead;
	unsigned int linklayer;
	unsigned int mpu;
	unsigned int mtu;
	unsigned int tsize;
};

enum netdev_tx {
	__NETDEV_TX_MIN = 2147483648,
	NETDEV_TX_OK = 0,
	NETDEV_TX_BUSY = 16,
};

typedef enum netdev_tx netdev_tx_t;

struct net_device_core_stats {
	long unsigned int rx_dropped;
	long unsigned int tx_dropped;
	long unsigned int rx_nohandler;
	long: 64;
};

struct header_ops {
	int (*create)(struct sk_buff *, struct net_device *, short unsigned int, const void *, const void *, unsigned int);
	int (*parse)(const struct sk_buff *, unsigned char *);
	int (*cache)(const struct neighbour *, struct hh_cache *, __be16);
	void (*cache_update)(struct hh_cache *, const struct net_device *, const unsigned char *);
	bool (*validate)(const char *, unsigned int);
	union {
		__be16 (*parse_protocol)(const struct sk_buff *);
		struct {
			long unsigned int rh_reserved1;
		} rh_kabi_hidden_303;
		union {		};
	};
	long unsigned int rh_reserved2;
	long unsigned int rh_reserved3;
};

struct napi_struct_extended_rh {};

struct napi_struct {
	struct list_head poll_list;
	long unsigned int state;
	int weight;
	unsigned int gro_count;
	int (*poll)(struct napi_struct *, int);
	int poll_owner;
	struct net_device *dev;
	struct sk_buff *rh_reserved_gro_list;
	struct sk_buff *skb;
	struct hrtimer timer;
	struct list_head dev_list;
	struct hlist_node napi_hash_node;
	unsigned int napi_id;
	union {
		struct list_head gro_list;
		struct {
			long unsigned int rh_reserved1;
			long unsigned int rh_reserved2;
		} rh_kabi_hidden_365;
		union {		};
	};
	union {
		int defer_hard_irqs_count;
		struct {
			long unsigned int rh_reserved3;
		} rh_kabi_hidden_366;
		union {		};
	};
	union {
		struct task_struct *thread;
		struct {
			long unsigned int rh_reserved4;
		} rh_kabi_hidden_367;
		union {		};
	};
	long unsigned int rh_reserved5;
	long unsigned int rh_reserved6;
	long unsigned int rh_reserved7;
	size_t napi_struct_extended_size_rh;
	struct napi_struct_extended_rh _rh;
};

struct xsk_buff_pool;

struct netdev_queue {
	struct net_device *dev;
	struct Qdisc *qdisc;
	struct Qdisc *qdisc_sleeping;
	struct kobject kobj;
	int numa_node;
	long unsigned int tx_maxrate;
	long unsigned int trans_timeout;
	struct net_device *sb_dev;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	spinlock_t _xmit_lock;
	int xmit_lock_owner;
	long unsigned int trans_start;
	long unsigned int state;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	struct dql dql;
	union {
		struct xsk_buff_pool *pool;
		struct {
			long unsigned int rh_reserved1;
		} rh_kabi_hidden_641;
		union {		};
	};
	long unsigned int rh_reserved2;
	long unsigned int rh_reserved3;
	long unsigned int rh_reserved4;
	long unsigned int rh_reserved5;
	long unsigned int rh_reserved6;
	long unsigned int rh_reserved7;
	long unsigned int rh_reserved8;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
};

struct qdisc_skb_head {
	struct sk_buff *head;
	struct sk_buff *tail;
	__u32 qlen;
	spinlock_t lock;
};

struct gnet_stats_basic_sync {
	u64_stats_t bytes;
	u64_stats_t packets;
	struct u64_stats_sync syncp;
};

struct gnet_stats_queue {
	__u32 qlen;
	__u32 backlog;
	__u32 drops;
	__u32 requeues;
	__u32 overlimits;
};

struct Qdisc_ops;

struct qdisc_size_table;

struct net_rate_estimator;

struct Qdisc {
	int (*enqueue)(struct sk_buff *, struct Qdisc *, struct sk_buff **);
	struct sk_buff * (*dequeue)(struct Qdisc *);
	unsigned int flags;
	u32 limit;
	const struct Qdisc_ops *ops;
	struct qdisc_size_table *stab;
	struct hlist_node hash;
	u32 handle;
	u32 parent;
	struct netdev_queue *dev_queue;
	struct net_rate_estimator *rate_est;
	struct gnet_stats_basic_sync *cpu_bstats;
	struct gnet_stats_queue *cpu_qstats;
	int pad;
	refcount_t refcnt;
	long: 64;
	long: 64;
	long: 64;
	struct sk_buff_head gso_skb;
	struct qdisc_skb_head q;
	struct gnet_stats_basic_sync bstats;
	struct gnet_stats_queue qstats;
	long unsigned int state;
	long unsigned int state2;
	struct Qdisc *next_sched;
	struct sk_buff_head skb_bad_txq;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	spinlock_t busylock;
	spinlock_t seqlock;
	struct callback_head rcu;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long int privdata[0];
};

struct rps_map {
	unsigned int len;
	struct callback_head rcu;
	u16 cpus[0];
};

struct rps_dev_flow {
	u16 cpu;
	u16 filter;
	unsigned int last_qtail;
};

struct rps_dev_flow_table {
	unsigned int mask;
	struct callback_head rcu;
	struct rps_dev_flow flows[0];
};

struct rps_sock_flow_table {
	u32 mask;
	long: 32;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	u32 ents[0];
};

struct netdev_rx_queue {
	struct rps_map *rps_map;
	struct rps_dev_flow_table *rps_flow_table;
	struct kobject kobj;
	struct net_device *dev;
	long: 64;
	struct xdp_rxq_info xdp_rxq;
	union {
		struct xsk_buff_pool *pool;
		struct {
			long unsigned int rh_reserved1;
		} rh_kabi_hidden_764;
		union {		};
	};
	long unsigned int rh_reserved2;
	long unsigned int rh_reserved3;
	long unsigned int rh_reserved4;
	long unsigned int rh_reserved5;
	long unsigned int rh_reserved6;
	long unsigned int rh_reserved7;
	long unsigned int rh_reserved8;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
};

struct xps_map {
	unsigned int len;
	unsigned int alloc_len;
	struct callback_head rcu;
	u16 queues[0];
};

struct xps_dev_maps {
	struct callback_head rcu;
	struct xps_map *attr_map[0];
};

struct netdev_phys_item_id {
	unsigned char id[32];
	unsigned char id_len;
};

typedef u16 (*select_queue_fallback_t)(struct net_device *, struct sk_buff *, struct net_device *);

enum tc_setup_type {
	TC_QUERY_CAPS = 0,
	TC_SETUP_QDISC_MQPRIO = 1,
	TC_SETUP_CLSU32 = 2,
	TC_SETUP_CLSFLOWER = 3,
	TC_SETUP_CLSMATCHALL = 4,
	TC_SETUP_CLSBPF = 5,
	TC_SETUP_BLOCK = 6,
	TC_SETUP_QDISC_CBS = 7,
	TC_SETUP_QDISC_RED = 8,
	TC_SETUP_QDISC_PRIO = 9,
	TC_SETUP_QDISC_MQ = 10,
	TC_SETUP_QDISC_ETF = 11,
	TC_SETUP_ROOT_QDISC = 12,
	TC_SETUP_QDISC_GRED = 13,
	TC_SETUP_QDISC_TAPRIO = 14,
	TC_SETUP_FT = 15,
	TC_SETUP_QDISC_ETS = 16,
	TC_SETUP_QDISC_TBF = 17,
	TC_SETUP_QDISC_FIFO = 18,
	TC_SETUP_QDISC_HTB = 19,
	TC_SETUP_ACT = 20,
};

enum bpf_netdev_command {
	XDP_SETUP_PROG = 0,
	XDP_SETUP_PROG_HW = 1,
	BPF_OFFLOAD_MAP_ALLOC = 2,
	BPF_OFFLOAD_MAP_FREE = 3,
	XDP_SETUP_XSK_POOL = 4,
};

struct bpf_xdp_link;

struct bpf_xdp_entity {
	struct bpf_prog *prog;
	struct bpf_xdp_link *link;
};

struct netdev_bpf {
	enum bpf_netdev_command command;
	union {
		struct {
			u32 flags;
			struct bpf_prog *prog;
			struct netlink_ext_ack *extack;
		};
		struct {
			struct bpf_offloaded_map *offmap;
		};
		struct {
			struct xsk_buff_pool *pool;
			u16 queue_id;
		} xsk;
	};
};

struct xfrmdev_ops_extended_rh {};

struct xfrmdev_ops {
	int (*xdo_dev_state_add)(struct xfrm_state *);
	void (*xdo_dev_state_delete)(struct xfrm_state *);
	void (*xdo_dev_state_free)(struct xfrm_state *);
	bool (*xdo_dev_offload_ok)(struct sk_buff *, struct xfrm_state *);
	void (*xdo_dev_state_advance_esn)(struct xfrm_state *);
	long unsigned int rh_reserved1;
	long unsigned int rh_reserved2;
	long unsigned int rh_reserved3;
	long unsigned int rh_reserved4;
	long unsigned int rh_reserved5;
	long unsigned int rh_reserved6;
	long unsigned int rh_reserved7;
	size_t xfrmdev_ops_extended_size_rh;
	struct xfrmdev_ops_extended_rh _rh;
};

enum tls_offload_ctx_dir {
	TLS_OFFLOAD_CTX_DIR_RX = 0,
	TLS_OFFLOAD_CTX_DIR_TX = 1,
};

struct tlsdev_ops_extended_rh {};

struct tls_crypto_info;

struct tls_context;

struct tlsdev_ops {
	int (*tls_dev_add)(struct net_device *, struct sock *, enum tls_offload_ctx_dir, struct tls_crypto_info *, u32);
	void (*tls_dev_del)(struct net_device *, struct tls_context *, enum tls_offload_ctx_dir);
	union {
		int (*tls_dev_resync)(struct net_device *, struct sock *, u32, u8 *, enum tls_offload_ctx_dir);
		struct {
			long unsigned int rh_reserved1;
		} rh_kabi_hidden_994;
		union {		};
	};
	long unsigned int rh_reserved2;
	long unsigned int rh_reserved3;
	long unsigned int rh_reserved4;
	long unsigned int rh_reserved5;
	long unsigned int rh_reserved6;
	long unsigned int rh_reserved7;
	size_t tlsdev_ops_extended_size_rh;
	struct tlsdev_ops_extended_rh _rh;
};

struct dev_ifalias {
	struct callback_head rcuhead;
	char ifalias[0];
};

struct net_device_ops_extended_rh {};

struct udp_tunnel_info;

struct devlink_port;

struct net_device_ops {
	int (*ndo_init)(struct net_device *);
	void (*ndo_uninit)(struct net_device *);
	int (*ndo_open)(struct net_device *);
	int (*ndo_stop)(struct net_device *);
	netdev_tx_t (*ndo_start_xmit)(struct sk_buff *, struct net_device *);
	netdev_features_t (*ndo_features_check)(struct sk_buff *, struct net_device *, netdev_features_t);
	u16 (*ndo_select_queue)(struct net_device *, struct sk_buff *, struct net_device *, select_queue_fallback_t);
	void (*ndo_change_rx_flags)(struct net_device *, int);
	void (*ndo_set_rx_mode)(struct net_device *);
	int (*ndo_set_mac_address)(struct net_device *, void *);
	int (*ndo_validate_addr)(struct net_device *);
	int (*ndo_do_ioctl)(struct net_device *, struct ifreq *, int);
	int (*ndo_set_config)(struct net_device *, struct ifmap *);
	int (*ndo_change_mtu)(struct net_device *, int);
	int (*ndo_neigh_setup)(struct net_device *, struct neigh_parms *);
	union {
		void (*ndo_tx_timeout)(struct net_device *, unsigned int);
		struct {
			void (*ndo_tx_timeout)(struct net_device *);
		} rh_kabi_hidden_1377;
		union {		};
	};
	void (*ndo_get_stats64)(struct net_device *, struct rtnl_link_stats64 *);
	bool (*ndo_has_offload_stats)(const struct net_device *, int);
	int (*ndo_get_offload_stats)(int, const struct net_device *, void *);
	struct net_device_stats * (*ndo_get_stats)(struct net_device *);
	int (*ndo_vlan_rx_add_vid)(struct net_device *, __be16, u16);
	int (*ndo_vlan_rx_kill_vid)(struct net_device *, __be16, u16);
	void (*ndo_poll_controller)(struct net_device *);
	int (*ndo_netpoll_setup)(struct net_device *, struct netpoll_info *);
	void (*ndo_netpoll_cleanup)(struct net_device *);
	int (*ndo_set_vf_mac)(struct net_device *, int, u8 *);
	int (*ndo_set_vf_vlan)(struct net_device *, int, u16, u8, __be16);
	int (*ndo_set_vf_rate)(struct net_device *, int, int, int);
	int (*ndo_set_vf_spoofchk)(struct net_device *, int, bool);
	int (*ndo_set_vf_trust)(struct net_device *, int, bool);
	int (*ndo_get_vf_config)(struct net_device *, int, struct ifla_vf_info *);
	int (*ndo_set_vf_link_state)(struct net_device *, int, int);
	int (*ndo_get_vf_stats)(struct net_device *, int, struct ifla_vf_stats *);
	int (*ndo_set_vf_port)(struct net_device *, int, struct nlattr **);
	int (*ndo_get_vf_port)(struct net_device *, int, struct sk_buff *);
	int (*ndo_set_vf_guid)(struct net_device *, int, u64, int);
	int (*ndo_set_vf_rss_query_en)(struct net_device *, int, bool);
	int (*ndo_setup_tc)(struct net_device *, enum tc_setup_type, void *);
	int (*ndo_fcoe_get_wwn)(struct net_device *, u64 *, int);
	int (*ndo_rx_flow_steer)(struct net_device *, const struct sk_buff *, u16, u32);
	int (*ndo_add_slave)(struct net_device *, struct net_device *, struct netlink_ext_ack *);
	int (*ndo_del_slave)(struct net_device *, struct net_device *);
	netdev_features_t (*ndo_fix_features)(struct net_device *, netdev_features_t);
	int (*ndo_set_features)(struct net_device *, netdev_features_t);
	int (*ndo_neigh_construct)(struct net_device *, struct neighbour *);
	void (*ndo_neigh_destroy)(struct net_device *, struct neighbour *);
	union {
		int (*ndo_fdb_add)(struct ndmsg *, struct nlattr **, struct net_device *, const unsigned char *, u16, u16, struct netlink_ext_ack *);
		struct {
			int (*ndo_fdb_add)(struct ndmsg *, struct nlattr **, struct net_device *, const unsigned char *, u16, u16);
		} rh_kabi_hidden_1488;
		union {		};
	};
	int (*ndo_fdb_del)(struct ndmsg *, struct nlattr **, struct net_device *, const unsigned char *, u16);
	int (*ndo_fdb_dump)(struct sk_buff *, struct netlink_callback *, struct net_device *, struct net_device *, int *);
	union {
		int (*ndo_bridge_setlink)(struct net_device *, struct nlmsghdr *, u16, struct netlink_ext_ack *);
		struct {
			int (*ndo_bridge_setlink)(struct net_device *, struct nlmsghdr *, u16);
		} rh_kabi_hidden_1506;
		union {		};
	};
	int (*ndo_bridge_getlink)(struct sk_buff *, u32, u32, struct net_device *, u32, int);
	int (*ndo_bridge_dellink)(struct net_device *, struct nlmsghdr *, u16);
	int (*ndo_change_carrier)(struct net_device *, bool);
	int (*ndo_get_phys_port_id)(struct net_device *, struct netdev_phys_item_id *);
	int (*ndo_get_phys_port_name)(struct net_device *, char *, size_t);
	void (*ndo_udp_tunnel_add)(struct net_device *, struct udp_tunnel_info *);
	void (*ndo_udp_tunnel_del)(struct net_device *, struct udp_tunnel_info *);
	void * (*ndo_dfwd_add_station)(struct net_device *, struct net_device *);
	void (*ndo_dfwd_del_station)(struct net_device *, void *);
	int (*rh_reserved_ndo_get_lock_subclass)(struct net_device *);
	int (*ndo_set_tx_maxrate)(struct net_device *, int, u32);
	int (*ndo_get_iflink)(const struct net_device *);
	int (*ndo_change_proto_down)(struct net_device *, bool);
	int (*ndo_fill_metadata_dst)(struct net_device *, struct sk_buff *);
	void (*ndo_set_rx_headroom)(struct net_device *, int);
	int (*ndo_bpf)(struct net_device *, struct netdev_bpf *);
	int (*ndo_xdp_xmit)(struct net_device *, int, struct xdp_frame **, u32);
	int (*ndo_xsk_wakeup)(struct net_device *, u32, u32);
	union {
		int (*ndo_get_port_parent_id)(struct net_device *, struct netdev_phys_item_id *);
		struct {
			long unsigned int rh_reserved1;
		} rh_kabi_hidden_1550;
		union {		};
	};
	union {
		struct devlink_port * (*ndo_get_devlink_port)(struct net_device *);
		struct {
			long unsigned int rh_reserved2;
		} rh_kabi_hidden_1551;
		union {		};
	};
	union {
		int (*ndo_fdb_get)(struct sk_buff *, struct nlattr **, struct net_device *, const unsigned char *, u16, u32, u32, struct netlink_ext_ack *);
		struct {
			long unsigned int rh_reserved3;
		} rh_kabi_hidden_1557;
		union {		};
	};
	union {
		int (*ndo_get_vf_guid)(struct net_device *, int, struct ifla_vf_guid *, struct ifla_vf_guid *);
		struct {
			long unsigned int rh_reserved4;
		} rh_kabi_hidden_1561;
		union {		};
	};
	union {
		struct net_device * (*ndo_get_xmit_slave)(struct net_device *, struct sk_buff *, bool);
		struct {
			long unsigned int rh_reserved5;
		} rh_kabi_hidden_1564;
		union {		};
	};
	union {
		struct net_device * (*ndo_sk_get_lower_dev)(struct net_device *, struct sock *);
		struct {
			long unsigned int rh_reserved6;
		} rh_kabi_hidden_1566;
		union {		};
	};
	union {
		struct net_device * (*ndo_get_peer_dev)(struct net_device *);
		struct {
			long unsigned int rh_reserved7;
		} rh_kabi_hidden_1567;
		union {		};
	};
	long unsigned int rh_reserved8;
	long unsigned int rh_reserved9;
	long unsigned int rh_reserved10;
	long unsigned int rh_reserved11;
	long unsigned int rh_reserved12;
	long unsigned int rh_reserved13;
	long unsigned int rh_reserved14;
	long unsigned int rh_reserved15;
	long unsigned int rh_reserved16;
	long unsigned int rh_reserved17;
	long unsigned int rh_reserved18;
	long unsigned int rh_reserved19;
	long unsigned int rh_reserved20;
	long unsigned int rh_reserved21;
	long unsigned int rh_reserved22;
	long unsigned int rh_reserved23;
	long unsigned int rh_reserved24;
	long unsigned int rh_reserved25;
	long unsigned int rh_reserved26;
	long unsigned int rh_reserved27;
	long unsigned int rh_reserved28;
	long unsigned int rh_reserved29;
	long unsigned int rh_reserved30;
	long unsigned int rh_reserved31;
	long unsigned int rh_reserved32;
	long unsigned int rh_reserved33;
	long unsigned int rh_reserved34;
	long unsigned int rh_reserved35;
	long unsigned int rh_reserved36;
	long unsigned int rh_reserved37;
	long unsigned int rh_reserved38;
	long unsigned int rh_reserved39;
	long unsigned int rh_reserved40;
	long unsigned int rh_reserved41;
	long unsigned int rh_reserved42;
	long unsigned int rh_reserved43;
	long unsigned int rh_reserved44;
	long unsigned int rh_reserved45;
	long unsigned int rh_reserved46;
	long unsigned int rh_reserved47;
	size_t net_device_ops_extended_size_rh;
	struct net_device_ops_extended_rh _rh;
};

struct neigh_parms {
	possible_net_t net;
	struct net_device *dev;
	struct list_head list;
	int (*neigh_setup)(struct neighbour *);
	void (*rh_reserved_neigh_cleanup)(struct neighbour *);
	struct neigh_table *tbl;
	void *sysctl_table;
	int dead;
	refcount_t refcnt;
	struct callback_head callback_head;
	int reachable_time;
	int data[13];
	long unsigned int data_state[1];
};

struct net_device_extended_rh {};

struct pcpu_lstats {
	u64 packets;
	u64 bytes;
	struct u64_stats_sync syncp;
};

struct pcpu_sw_netstats {
	u64 rx_packets;
	u64 rx_bytes;
	u64 tx_packets;
	u64 tx_bytes;
	struct u64_stats_sync syncp;
};

struct udp_tunnel_nic_table_info {
	unsigned int n_entries;
	unsigned int tunnel_types;
};

struct udp_tunnel_nic_shared;

struct udp_tunnel_nic_info_rh {
	struct udp_tunnel_nic_shared *shared;
};

struct udp_tunnel_nic_info {
	int (*set_port)(struct net_device *, unsigned int, unsigned int, struct udp_tunnel_info *);
	int (*unset_port)(struct net_device *, unsigned int, unsigned int, struct udp_tunnel_info *);
	int (*sync_table)(struct net_device *, unsigned int);
	unsigned int flags;
	struct udp_tunnel_nic_table_info tables[4];
	size_t udp_tunnel_nic_info_size_rh;
	struct udp_tunnel_nic_info_rh _rh;
};

struct l3mdev_ops_extended_rh {};

struct l3mdev_ops {
	u32 (*l3mdev_fib_table)(const struct net_device *);
	struct sk_buff * (*l3mdev_l3_rcv)(struct net_device *, struct sk_buff *, u16);
	struct sk_buff * (*l3mdev_l3_out)(struct net_device *, struct sock *, struct sk_buff *, u16);
	struct dst_entry * (*l3mdev_link_scope_lookup)(const struct net_device *, struct flowi6 *);
	long unsigned int rh_reserved1;
	long unsigned int rh_reserved2;
	long unsigned int rh_reserved3;
	long unsigned int rh_reserved4;
	long unsigned int rh_reserved5;
	long unsigned int rh_reserved6;
	long unsigned int rh_reserved7;
	size_t l3mdev_ops_extended_size_rh;
	struct l3mdev_ops_extended_rh _rh;
};

struct nd_opt_hdr;

struct ndisc_options;

struct prefix_info;

struct ndisc_ops {
	int (*is_useropt)(u8);
	int (*parse_options)(const struct net_device *, struct nd_opt_hdr *, struct ndisc_options *);
	void (*update)(const struct net_device *, struct neighbour *, u32, u8, const struct ndisc_options *);
	int (*opt_addr_space)(const struct net_device *, u8, struct neighbour *, u8 *, u8 **);
	void (*fill_addr_option)(const struct net_device *, struct sk_buff *, u8, const u8 *);
	void (*prefix_rcv_add_addr)(struct net *, struct net_device *, const struct prefix_info *, struct inet6_dev *, struct in6_addr *, int, u32, bool, bool, __u32, u32, bool);
};

struct ipv6_devstat {
	struct proc_dir_entry *proc_dir_entry;
	struct ipstats_mib *ipv6;
	struct icmpv6_mib_device *icmpv6dev;
	struct icmpv6msg_mib_device *icmpv6msgdev;
};

struct ifmcaddr6;

struct ifacaddr6;

struct inet6_dev {
	struct net_device *dev;
	struct list_head addr_list;
	struct ifmcaddr6 *mc_list;
	struct ifmcaddr6 *mc_tomb;
	spinlock_t mc_lock;
	unsigned char mc_qrv;
	unsigned char mc_gq_running;
	unsigned char mc_ifc_count;
	unsigned char mc_dad_count;
	long unsigned int mc_v1_seen;
	long unsigned int mc_qi;
	long unsigned int mc_qri;
	long unsigned int mc_maxdelay;
	struct timer_list mc_gq_timer;
	struct timer_list mc_ifc_timer;
	struct timer_list mc_dad_timer;
	struct ifacaddr6 *ac_list;
	rwlock_t lock;
	refcount_t refcnt;
	__u32 if_flags;
	int dead;
	u32 desync_factor;
	u8 rndid[8];
	struct list_head tempaddr_list;
	struct in6_addr token;
	struct neigh_parms *nd_parms;
	struct ipv6_devconf cnf;
	struct ipv6_devstat stats;
	struct timer_list rs_timer;
	__s32 rs_interval;
	__u8 rs_probes;
	long unsigned int tstamp;
	struct callback_head rcu;
};

struct tcf_proto;

struct tcf_block;

struct mini_Qdisc {
	struct tcf_proto *filter_list;
	struct tcf_block *block;
	struct gnet_stats_basic_sync *cpu_bstats;
	struct gnet_stats_queue *cpu_qstats;
	long unsigned int rcu_state;
};

struct rtnl_link_ops_extended_rh {};

struct rtnl_link_ops {
	struct list_head list;
	const char *kind;
	size_t priv_size;
	void (*setup)(struct net_device *);
	unsigned int maxtype;
	const struct nla_policy *policy;
	int (*validate)(struct nlattr **, struct nlattr **, struct netlink_ext_ack *);
	int (*newlink)(struct net *, struct net_device *, struct nlattr **, struct nlattr **, struct netlink_ext_ack *);
	int (*changelink)(struct net_device *, struct nlattr **, struct nlattr **, struct netlink_ext_ack *);
	void (*dellink)(struct net_device *, struct list_head *);
	size_t (*get_size)(const struct net_device *);
	int (*fill_info)(struct sk_buff *, const struct net_device *);
	size_t (*get_xstats_size)(const struct net_device *);
	int (*fill_xstats)(struct sk_buff *, const struct net_device *);
	unsigned int (*get_num_tx_queues)();
	unsigned int (*get_num_rx_queues)();
	unsigned int slave_maxtype;
	const struct nla_policy *slave_policy;
	int (*slave_changelink)(struct net_device *, struct net_device *, struct nlattr **, struct nlattr **, struct netlink_ext_ack *);
	size_t (*get_slave_size)(const struct net_device *, const struct net_device *);
	int (*fill_slave_info)(struct sk_buff *, const struct net_device *, const struct net_device *);
	struct net * (*get_link_net)(const struct net_device *);
	size_t (*get_linkxstats_size)(const struct net_device *, int);
	int (*fill_linkxstats)(struct sk_buff *, const struct net_device *, int *, int);
	union {
		bool netns_refund;
		struct {
			long unsigned int rh_reserved1;
		} rh_kabi_hidden_123;
		union {		};
	};
	union {
		struct net_device * (*alloc)(struct nlattr **, const char *, unsigned char, unsigned int, unsigned int);
		struct {
			long unsigned int rh_reserved2;
		} rh_kabi_hidden_128;
		union {		};
	};
	long unsigned int rh_reserved3;
	long unsigned int rh_reserved4;
	long unsigned int rh_reserved5;
	long unsigned int rh_reserved6;
	long unsigned int rh_reserved7;
	long unsigned int rh_reserved8;
	long unsigned int rh_reserved9;
	long unsigned int rh_reserved10;
	long unsigned int rh_reserved11;
	long unsigned int rh_reserved12;
	long unsigned int rh_reserved13;
	long unsigned int rh_reserved14;
	long unsigned int rh_reserved15;
	size_t rtnl_link_ops_extended_size_rh;
	struct rtnl_link_ops_extended_rh _rh;
};

struct sd_flow_limit;

struct softnet_data {
	struct list_head poll_list;
	struct sk_buff_head process_queue;
	unsigned int processed;
	unsigned int time_squeeze;
	unsigned int received_rps;
	struct softnet_data *rps_ipi_list;
	struct sd_flow_limit *flow_limit;
	struct Qdisc *output_queue;
	struct Qdisc **output_queue_tailp;
	struct sk_buff *completion_queue;
	struct sk_buff_head xfrm_backlog;
	struct {
		u16 recursion;
		u8 more;
		u8 skip_txqueue;
	} xmit;
	int: 32;
	unsigned int input_queue_head;
	long: 32;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	call_single_data_t csd;
	struct softnet_data *rps_ipi_next;
	unsigned int cpu;
	unsigned int input_queue_tail;
	unsigned int dropped;
	struct sk_buff_head input_pkt_queue;
	struct napi_struct backlog;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
};

enum {
	RTAX_UNSPEC = 0,
	RTAX_LOCK = 1,
	RTAX_MTU = 2,
	RTAX_WINDOW = 3,
	RTAX_RTT = 4,
	RTAX_RTTVAR = 5,
	RTAX_SSTHRESH = 6,
	RTAX_CWND = 7,
	RTAX_ADVMSS = 8,
	RTAX_REORDERING = 9,
	RTAX_HOPLIMIT = 10,
	RTAX_INITCWND = 11,
	RTAX_FEATURES = 12,
	RTAX_RTO_MIN = 13,
	RTAX_INITRWND = 14,
	RTAX_QUICKACK = 15,
	RTAX_CC_ALGO = 16,
	RTAX_FASTOPEN_NO_COOKIE = 17,
	__RTAX_MAX = 18,
};

struct tcmsg {
	unsigned char tcm_family;
	unsigned char tcm__pad1;
	short unsigned int tcm__pad2;
	int tcm_ifindex;
	__u32 tcm_handle;
	__u32 tcm_parent;
	__u32 tcm_info;
};

struct gnet_dump {
	spinlock_t *lock;
	struct sk_buff *skb;
	struct nlattr *tail;
	int compat_tc_stats;
	int compat_xstats;
	int padattr;
	void *xstats;
	int xstats_len;
	struct tc_stats tc_stats;
};

struct netlink_range_validation {
	u64 min;
	u64 max;
};

struct netlink_range_validation_signed {
	s64 min;
	s64 max;
};

struct nla_policy {
	union {
		struct {
			u8 type;
			u8 validation_type;
		};
		struct {
			u16 type;
		} rh_kabi_hidden_339;
		union {		};
	};
	u16 len;
	union {
		const u32 *bitfield32_valid_ptr;
		const u32 mask;
		const char *reject_message;
		const struct nla_policy *nested_policy;
		struct netlink_range_validation *range;
		struct netlink_range_validation_signed *range_signed;
		struct {
			s16 min;
			s16 max;
		};
		int (*validate)(const struct nlattr *, struct netlink_ext_ack *);
		u16 strict_start_type;
	};
};

struct nl_info {
	struct nlmsghdr *nlh;
	struct net *nl_net;
	u32 portid;
	u8 skip_notify: 1;
	u8 skip_notify_kernel: 1;
};

enum flow_action_hw_stats_bit {
	FLOW_ACTION_HW_STATS_IMMEDIATE_BIT = 0,
	FLOW_ACTION_HW_STATS_DELAYED_BIT = 1,
	FLOW_ACTION_HW_STATS_DISABLED_BIT = 2,
	FLOW_ACTION_HW_STATS_NUM_BITS = 3,
};

struct flow_block {
	struct list_head cb_list;
};

typedef int flow_setup_cb_t(enum tc_setup_type, void *, void *);

struct qdisc_size_table {
	struct callback_head rcu;
	struct list_head list;
	struct tc_sizespec szopts;
	int refcnt;
	u16 data[0];
};

struct Qdisc_class_ops;

struct Qdisc_ops {
	struct Qdisc_ops *next;
	const struct Qdisc_class_ops *cl_ops;
	char id[16];
	int priv_size;
	unsigned int static_flags;
	int (*enqueue)(struct sk_buff *, struct Qdisc *, struct sk_buff **);
	struct sk_buff * (*dequeue)(struct Qdisc *);
	struct sk_buff * (*peek)(struct Qdisc *);
	int (*init)(struct Qdisc *, struct nlattr *, struct netlink_ext_ack *);
	void (*reset)(struct Qdisc *);
	void (*destroy)(struct Qdisc *);
	int (*change)(struct Qdisc *, struct nlattr *, struct netlink_ext_ack *);
	void (*attach)(struct Qdisc *);
	int (*change_tx_queue_len)(struct Qdisc *, unsigned int);
	void (*change_real_num_tx)(struct Qdisc *, unsigned int);
	int (*dump)(struct Qdisc *, struct sk_buff *);
	int (*dump_stats)(struct Qdisc *, struct gnet_dump *);
	void (*ingress_block_set)(struct Qdisc *, u32);
	void (*egress_block_set)(struct Qdisc *, u32);
	u32 (*ingress_block_get)(struct Qdisc *);
	u32 (*egress_block_get)(struct Qdisc *);
	struct module *owner;
};

struct qdisc_walker;

struct Qdisc_class_ops {
	unsigned int flags;
	struct netdev_queue * (*select_queue)(struct Qdisc *, struct tcmsg *);
	int (*graft)(struct Qdisc *, long unsigned int, struct Qdisc *, struct Qdisc **, struct netlink_ext_ack *);
	struct Qdisc * (*leaf)(struct Qdisc *, long unsigned int);
	void (*qlen_notify)(struct Qdisc *, long unsigned int);
	long unsigned int (*find)(struct Qdisc *, u32);
	int (*change)(struct Qdisc *, u32, u32, struct nlattr **, long unsigned int *, struct netlink_ext_ack *);
	int (*delete)(struct Qdisc *, long unsigned int, struct netlink_ext_ack *);
	void (*walk)(struct Qdisc *, struct qdisc_walker *);
	struct tcf_block * (*tcf_block)(struct Qdisc *, long unsigned int, struct netlink_ext_ack *);
	long unsigned int (*bind_tcf)(struct Qdisc *, long unsigned int, u32);
	void (*unbind_tcf)(struct Qdisc *, long unsigned int);
	int (*dump)(struct Qdisc *, long unsigned int, struct sk_buff *, struct tcmsg *);
	int (*dump_stats)(struct Qdisc *, long unsigned int, struct gnet_dump *);
};

struct tcf_chain;

struct tcf_block {
	struct mutex lock;
	struct list_head chain_list;
	u32 index;
	u32 classid;
	refcount_t refcnt;
	struct net *net;
	struct Qdisc *q;
	struct rw_semaphore cb_lock;
	struct flow_block flow_block;
	struct list_head owner_list;
	bool keep_dst;
	atomic_t offloadcnt;
	unsigned int nooffloaddevcnt;
	unsigned int lockeddevcnt;
	struct {
		struct tcf_chain *chain;
		struct list_head filter_chain_list;
	} chain0;
	struct callback_head rcu;
	struct hlist_head proto_destroy_ht[128];
	struct mutex proto_destroy_lock;
};

struct tcf_result;

struct tcf_proto_ops;

struct tcf_proto {
	struct tcf_proto *next;
	void *root;
	int (*classify)(struct sk_buff *, const struct tcf_proto *, struct tcf_result *);
	__be16 protocol;
	u32 prio;
	void *data;
	const struct tcf_proto_ops *ops;
	struct tcf_chain *chain;
	spinlock_t lock;
	bool deleting;
	refcount_t refcnt;
	struct callback_head rcu;
	struct hlist_node destroy_ht_node;
};

struct tcf_result {
	union {
		struct {
			long unsigned int class;
			u32 classid;
		};
		const struct tcf_proto *goto_tp;
	};
};

struct tcf_walker;

struct tcf_exts;

struct tcf_proto_ops {
	struct list_head head;
	char kind[16];
	int (*classify)(struct sk_buff *, const struct tcf_proto *, struct tcf_result *);
	int (*init)(struct tcf_proto *);
	void (*destroy)(struct tcf_proto *, bool, struct netlink_ext_ack *);
	void * (*get)(struct tcf_proto *, u32);
	void (*put)(struct tcf_proto *, void *);
	int (*change)(struct net *, struct sk_buff *, struct tcf_proto *, long unsigned int, u32, struct nlattr **, void **, u32, struct netlink_ext_ack *);
	int (*delete)(struct tcf_proto *, void *, bool *, bool, struct netlink_ext_ack *);
	bool (*delete_empty)(struct tcf_proto *);
	void (*walk)(struct tcf_proto *, struct tcf_walker *, bool);
	int (*reoffload)(struct tcf_proto *, bool, flow_setup_cb_t *, void *, struct netlink_ext_ack *);
	void (*hw_add)(struct tcf_proto *, void *);
	void (*hw_del)(struct tcf_proto *, void *);
	void (*bind_class)(void *, u32, long unsigned int, void *, long unsigned int);
	void * (*tmplt_create)(struct net *, struct tcf_chain *, struct nlattr **, struct netlink_ext_ack *);
	void (*tmplt_destroy)(void *);
	struct tcf_exts * (*get_exts)(const struct tcf_proto *, u32);
	int (*dump)(struct net *, struct tcf_proto *, void *, struct sk_buff *, struct tcmsg *, bool);
	int (*terse_dump)(struct net *, struct tcf_proto *, void *, struct sk_buff *, struct tcmsg *, bool);
	int (*tmplt_dump)(struct sk_buff *, struct net *, void *);
	struct module *owner;
	int flags;
};

struct tcf_chain {
	struct mutex filter_chain_lock;
	struct tcf_proto *filter_chain;
	struct list_head list;
	struct tcf_block *block;
	u32 index;
	unsigned int refcnt;
	unsigned int action_refcnt;
	bool explicitly_created;
	bool flushing;
	const struct tcf_proto_ops *tmplt_ops;
	void *tmplt_priv;
	struct callback_head rcu;
};

struct sock_fprog_kern {
	u16 len;
	struct sock_filter *filter;
};

struct bpf_prog_stats {
	u64 cnt;
	u64 nsecs;
	u64 misses;
	struct u64_stats_sync syncp;
	long: 64;
};

struct sk_filter {
	refcount_t refcnt;
	struct callback_head rcu;
	struct bpf_prog *prog;
};

struct bpf_nh_params {
	u32 nh_family;
	union {
		u32 ipv4_nh;
		struct in6_addr ipv6_nh;
	};
};

struct bpf_redirect_info {
	u32 flags;
	u32 tgt_index;
	void *tgt_value;
	struct bpf_map *map;
	u32 map_id;
	enum bpf_map_type map_type;
	u32 kern_flags;
	struct bpf_nh_params nh;
};

enum {
	NEIGH_VAR_MCAST_PROBES = 0,
	NEIGH_VAR_UCAST_PROBES = 1,
	NEIGH_VAR_APP_PROBES = 2,
	NEIGH_VAR_MCAST_REPROBES = 3,
	NEIGH_VAR_RETRANS_TIME = 4,
	NEIGH_VAR_BASE_REACHABLE_TIME = 5,
	NEIGH_VAR_DELAY_PROBE_TIME = 6,
	NEIGH_VAR_GC_STALETIME = 7,
	NEIGH_VAR_QUEUE_LEN_BYTES = 8,
	NEIGH_VAR_PROXY_QLEN = 9,
	NEIGH_VAR_ANYCAST_DELAY = 10,
	NEIGH_VAR_PROXY_DELAY = 11,
	NEIGH_VAR_LOCKTIME = 12,
	NEIGH_VAR_QUEUE_LEN = 13,
	NEIGH_VAR_RETRANS_TIME_MS = 14,
	NEIGH_VAR_BASE_REACHABLE_TIME_MS = 15,
	NEIGH_VAR_GC_INTERVAL = 16,
	NEIGH_VAR_GC_THRESH1 = 17,
	NEIGH_VAR_GC_THRESH2 = 18,
	NEIGH_VAR_GC_THRESH3 = 19,
	NEIGH_VAR_MAX = 20,
};

struct pneigh_entry;

struct neigh_statistics;

struct neigh_hash_table;

struct neigh_table {
	int family;
	unsigned int entry_size;
	unsigned int key_len;
	__be16 protocol;
	__u32 (*hash)(const void *, const struct net_device *, __u32 *);
	bool (*key_eq)(const struct neighbour *, const void *);
	int (*constructor)(struct neighbour *);
	int (*pconstructor)(struct pneigh_entry *);
	void (*pdestructor)(struct pneigh_entry *);
	void (*proxy_redo)(struct sk_buff *);
	char *id;
	struct neigh_parms parms;
	struct list_head parms_list;
	int gc_interval;
	int gc_thresh1;
	int gc_thresh2;
	int gc_thresh3;
	long unsigned int last_flush;
	struct delayed_work gc_work;
	struct timer_list proxy_timer;
	struct sk_buff_head proxy_queue;
	atomic_t entries;
	rwlock_t lock;
	long unsigned int last_rand;
	struct neigh_statistics *stats;
	struct neigh_hash_table *nht;
	struct pneigh_entry **phash_buckets;
	atomic_t gc_entries;
	struct list_head gc_list;
	int (*is_multicast)(const void *);
};

struct neigh_statistics {
	long unsigned int allocs;
	long unsigned int destroys;
	long unsigned int hash_grows;
	long unsigned int res_failed;
	long unsigned int lookups;
	long unsigned int hits;
	long unsigned int rcv_probes_mcast;
	long unsigned int rcv_probes_ucast;
	long unsigned int periodic_gc_runs;
	long unsigned int forced_gc_runs;
	long unsigned int unres_discards;
	long unsigned int table_fulls;
};

struct neigh_ops {
	int family;
	void (*solicit)(struct neighbour *, struct sk_buff *);
	void (*error_report)(struct neighbour *, struct sk_buff *);
	int (*output)(struct neighbour *, struct sk_buff *);
	int (*connected_output)(struct neighbour *, struct sk_buff *);
};

struct pneigh_entry {
	struct pneigh_entry *next;
	possible_net_t net;
	struct net_device *dev;
	u8 flags;
	u8 protocol;
	u8 key[0];
};

struct neigh_hash_table {
	struct neighbour **hash_buckets;
	unsigned int hash_shift;
	__u32 hash_rnd[4];
	struct callback_head rcu;
};

struct dst_metrics {
	u32 metrics[17];
	refcount_t refcnt;
};

enum {
	TCP_ESTABLISHED = 1,
	TCP_SYN_SENT = 2,
	TCP_SYN_RECV = 3,
	TCP_FIN_WAIT1 = 4,
	TCP_FIN_WAIT2 = 5,
	TCP_TIME_WAIT = 6,
	TCP_CLOSE = 7,
	TCP_CLOSE_WAIT = 8,
	TCP_LAST_ACK = 9,
	TCP_LISTEN = 10,
	TCP_CLOSING = 11,
	TCP_NEW_SYN_RECV = 12,
	TCP_BOUND_INACTIVE = 13,
	TCP_MAX_STATES = 14,
};

struct smc_hashinfo {
	rwlock_t lock;
	struct hlist_head ht;
};

struct fib_rule_hdr {
	__u8 family;
	__u8 dst_len;
	__u8 src_len;
	__u8 tos;
	__u8 table;
	__u8 res1;
	__u8 res2;
	__u8 action;
	__u32 flags;
};

struct fib_rule_port_range {
	__u16 start;
	__u16 end;
};

struct fib_kuid_range {
	kuid_t start;
	kuid_t end;
};

struct fib_rule {
	struct list_head list;
	int iifindex;
	int oifindex;
	u32 mark;
	u32 mark_mask;
	u32 flags;
	u32 table;
	u8 action;
	u8 l3mdev;
	u8 proto;
	u8 ip_proto;
	u32 target;
	__be64 tun_id;
	struct fib_rule *ctarget;
	struct net *fr_net;
	refcount_t refcnt;
	u32 pref;
	int suppress_ifgroup;
	int suppress_prefixlen;
	char iifname[16];
	char oifname[16];
	struct fib_kuid_range uid_range;
	struct fib_rule_port_range sport_range;
	struct fib_rule_port_range dport_range;
	struct callback_head rcu;
	long unsigned int rh_reserved1;
	long unsigned int rh_reserved2;
	long unsigned int rh_reserved3;
	long unsigned int rh_reserved4;
	long unsigned int rh_reserved5;
	long unsigned int rh_reserved6;
	long unsigned int rh_reserved7;
	long unsigned int rh_reserved8;
};

struct fib_lookup_arg {
	void *lookup_ptr;
	const void *lookup_data;
	void *result;
	struct fib_rule *rule;
	u32 table;
	int flags;
};

struct request_sock_ops;

struct timewait_sock_ops;

struct udp_table;

struct raw_hashinfo;

struct sk_psock;

struct proto {
	void (*close)(struct sock *, long int);
	int (*pre_connect)(struct sock *, struct sockaddr *, int);
	int (*connect)(struct sock *, struct sockaddr *, int);
	int (*disconnect)(struct sock *, int);
	struct sock * (*accept)(struct sock *, int, int *, bool);
	int (*ioctl)(struct sock *, int, long unsigned int);
	int (*init)(struct sock *);
	void (*destroy)(struct sock *);
	void (*shutdown)(struct sock *, int);
	int (*setsockopt)(struct sock *, int, int, char *, unsigned int);
	int (*getsockopt)(struct sock *, int, int, char *, int *);
	void (*keepalive)(struct sock *, int);
	int (*compat_setsockopt)(struct sock *, int, int, char *, unsigned int);
	int (*compat_getsockopt)(struct sock *, int, int, char *, int *);
	int (*compat_ioctl)(struct sock *, unsigned int, long unsigned int);
	int (*sendmsg)(struct sock *, struct msghdr *, size_t);
	int (*recvmsg)(struct sock *, struct msghdr *, size_t, int, int, int *);
	int (*sendpage)(struct sock *, struct page *, int, size_t, int);
	int (*bind)(struct sock *, struct sockaddr *, int);
	int (*backlog_rcv)(struct sock *, struct sk_buff *);
	void (*release_cb)(struct sock *);
	int (*hash)(struct sock *);
	void (*unhash)(struct sock *);
	void (*rehash)(struct sock *);
	int (*get_port)(struct sock *, short unsigned int);
	unsigned int inuse_idx;
	union {
		bool (*stream_memory_free)(const struct sock *, int);
		struct {
			bool (*stream_memory_free)(const struct sock *);
		} rh_kabi_hidden_1214;
		union {		};
	};
	bool (*stream_memory_read)(const struct sock *);
	void (*enter_memory_pressure)(struct sock *);
	void (*leave_memory_pressure)(struct sock *);
	atomic_long_t *memory_allocated;
	struct percpu_counter *sockets_allocated;
	long unsigned int *memory_pressure;
	long int *sysctl_mem;
	int *sysctl_wmem;
	int *sysctl_rmem;
	u32 sysctl_wmem_offset;
	u32 sysctl_rmem_offset;
	int max_header;
	bool no_autobind;
	struct kmem_cache *slab;
	unsigned int obj_size;
	slab_flags_t slab_flags;
	unsigned int useroffset;
	unsigned int usersize;
	struct percpu_counter *orphan_count;
	struct request_sock_ops *rsk_prot;
	struct timewait_sock_ops *twsk_prot;
	union {
		struct inet_hashinfo *hashinfo;
		struct udp_table *udp_table;
		struct raw_hashinfo *raw_hash;
		struct smc_hashinfo *smc_hash;
	} h;
	struct module *owner;
	char name[32];
	struct list_head node;
	int (*diag_destroy)(struct sock *, int);
	union {
		bool (*bpf_bypass_getsockopt)(int, int);
		struct {
			long unsigned int rh_reserved1;
		} rh_kabi_hidden_1267;
		union {		};
	};
	union {
		int (*psock_update_sk_prot)(struct sock *, struct sk_psock *, bool);
		struct {
			long unsigned int rh_reserved2;
		} rh_kabi_hidden_1270;
		union {		};
	};
	long unsigned int rh_reserved3;
	long unsigned int rh_reserved4;
	long unsigned int rh_reserved5;
	long unsigned int rh_reserved6;
	long unsigned int rh_reserved7;
	long unsigned int rh_reserved8;
	long unsigned int rh_reserved9;
	long unsigned int rh_reserved10;
	long unsigned int rh_reserved11;
	long unsigned int rh_reserved12;
	long unsigned int rh_reserved13;
	long unsigned int rh_reserved14;
	long unsigned int rh_reserved15;
	long unsigned int rh_reserved16;
};

struct request_sock;

struct request_sock_ops {
	int family;
	unsigned int obj_size;
	struct kmem_cache *slab;
	char *slab_name;
	int (*rtx_syn_ack)(const struct sock *, struct request_sock *);
	void (*send_ack)(const struct sock *, struct sk_buff *, struct request_sock *);
	void (*send_reset)(const struct sock *, struct sk_buff *);
	void (*destructor)(struct request_sock *);
	void (*syn_ack_timeout)(const struct request_sock *);
};

struct timewait_sock_ops {
	struct kmem_cache *twsk_slab;
	char *twsk_slab_name;
	unsigned int twsk_obj_size;
	int (*twsk_unique)(struct sock *, struct sock *, void *);
	void (*twsk_destructor)(struct sock *);
};

struct saved_syn;

struct request_sock {
	struct sock_common __req_common;
	struct request_sock *dl_next;
	u16 mss;
	u8 num_retrans;
	u8 syncookie: 1;
	u8 num_timeout: 7;
	u32 ts_recent;
	struct timer_list rsk_timer;
	const struct request_sock_ops *rsk_ops;
	struct sock *sk;
	union {
		struct saved_syn *saved_syn;
		struct {
			u32 *saved_syn;
		} rh_kabi_hidden_77;
		union {		};
	};
	u32 secid;
	u32 peer_secid;
};

struct saved_syn {
	u32 mac_hdrlen;
	u32 network_hdrlen;
	u32 tcp_hdrlen;
	u8 data[0];
};

enum tsq_enum {
	TSQ_THROTTLED = 0,
	TSQ_QUEUED = 1,
	TCP_TSQ_DEFERRED = 2,
	TCP_WRITE_TIMER_DEFERRED = 3,
	TCP_DELACK_TIMER_DEFERRED = 4,
	TCP_MTU_REDUCED_DEFERRED = 5,
};

struct ip6_sf_list {
	struct ip6_sf_list *sf_next;
	struct in6_addr sf_addr;
	long unsigned int sf_count[2];
	unsigned char sf_gsresp;
	unsigned char sf_oldin;
	unsigned char sf_crcount;
};

struct ifmcaddr6 {
	struct in6_addr mca_addr;
	struct inet6_dev *idev;
	struct ifmcaddr6 *next;
	struct ip6_sf_list *mca_sources;
	struct ip6_sf_list *mca_tomb;
	unsigned int mca_sfmode;
	unsigned char mca_crcount;
	long unsigned int mca_sfcount[2];
	struct timer_list mca_timer;
	unsigned int mca_flags;
	int mca_users;
	refcount_t mca_refcnt;
	spinlock_t mca_lock;
	long unsigned int mca_cstamp;
	long unsigned int mca_tstamp;
};

struct ifacaddr6 {
	struct in6_addr aca_addr;
	struct fib6_info *aca_rt;
	struct ifacaddr6 *aca_next;
	int aca_users;
	refcount_t aca_refcnt;
	long unsigned int aca_cstamp;
	long unsigned int aca_tstamp;
};

struct ipv6_stub {
	int (*ipv6_sock_mc_join)(struct sock *, int, const struct in6_addr *);
	int (*ipv6_sock_mc_drop)(struct sock *, int, const struct in6_addr *);
	struct dst_entry * (*ipv6_dst_lookup_flow)(struct net *, const struct sock *, struct flowi6 *, const struct in6_addr *);
	int (*ipv6_route_input)(struct sk_buff *);
	struct fib6_table * (*fib6_get_table)(struct net *, u32);
	struct fib6_info * (*fib6_lookup)(struct net *, int, struct flowi6 *, int);
	struct fib6_info * (*fib6_table_lookup)(struct net *, struct fib6_table *, int, struct flowi6 *, int);
	struct fib6_info * (*fib6_multipath_select)(const struct net *, struct fib6_info *, struct flowi6 *, int, const struct sk_buff *, int);
	u32 (*ip6_mtu_from_fib6)(struct fib6_info *, struct in6_addr *, struct in6_addr *);
	void (*fib6_rt_update)(struct net *, struct fib6_info *, struct nl_info *);
	void (*udpv6_encap_enable)();
	void (*ndisc_send_na)(struct net_device *, const struct in6_addr *, const struct in6_addr *, bool, bool, bool, bool);
	int (*xfrm6_udp_encap_rcv)(struct sock *, struct sk_buff *);
	int (*xfrm6_rcv_encap)(struct sk_buff *, int, __be32, int);
	struct neigh_table *nd_tbl;
	int (*ipv6_fragment)(struct net *, struct sock *, struct sk_buff *, int (*)(struct net *, struct sock *, struct sk_buff *));
};

struct ipv6_bpf_stub {
	int (*inet6_bind)(struct sock *, struct sockaddr *, int, u32);
	struct sock * (*udp6_lib_lookup)(struct net *, const struct in6_addr *, __be16, const struct in6_addr *, __be16, int, int, struct udp_table *, struct sk_buff *);
};

enum {
	__ND_OPT_PREFIX_INFO_END = 0,
	ND_OPT_SOURCE_LL_ADDR = 1,
	ND_OPT_TARGET_LL_ADDR = 2,
	ND_OPT_PREFIX_INFO = 3,
	ND_OPT_REDIRECT_HDR = 4,
	ND_OPT_MTU = 5,
	ND_OPT_NONCE = 14,
	__ND_OPT_ARRAY_MAX = 15,
	ND_OPT_ROUTE_INFO = 24,
	ND_OPT_RDNSS = 25,
	ND_OPT_DNSSL = 31,
	ND_OPT_6CO = 34,
	ND_OPT_CAPTIVE_PORTAL = 37,
	__ND_OPT_MAX = 38,
};

struct nd_opt_hdr {
	__u8 nd_opt_type;
	__u8 nd_opt_len;
};

struct ndisc_options {
	struct nd_opt_hdr *nd_opt_array[15];
	struct nd_opt_hdr *nd_opts_ri;
	struct nd_opt_hdr *nd_opts_ri_end;
	struct nd_opt_hdr *nd_useropts;
	struct nd_opt_hdr *nd_useropts_end;
	struct nd_opt_hdr *nd_802154_opt_array[3];
};

struct prefix_info {
	__u8 type;
	__u8 length;
	__u8 prefix_len;
	__u8 reserved: 6;
	__u8 autoconf: 1;
	__u8 onlink: 1;
	__be32 valid;
	__be32 prefered;
	__be32 reserved2;
	struct in6_addr prefix;
};

struct ip6_ra_chain {
	struct ip6_ra_chain *next;
	struct sock *sk;
	int sel;
	void (*destructor)(struct sock *);
};

struct rpc_xprt_iter_ops {
	void (*xpi_rewind)(struct rpc_xprt_iter *);
	struct rpc_xprt * (*xpi_xprt)(struct rpc_xprt_iter *);
	struct rpc_xprt * (*xpi_next)(struct rpc_xprt_iter *);
};

struct rpc_version {
	u32 number;
	unsigned int nrprocs;
	const struct rpc_procinfo *procs;
	unsigned int *counts;
};

struct nfs_fh {
	short unsigned int size;
	unsigned char data[128];
};

enum nfs3_stable_how {
	NFS_UNSTABLE = 0,
	NFS_DATA_SYNC = 1,
	NFS_FILE_SYNC = 2,
	NFS_INVALID_STABLE_HOW = 4294967295,
};

struct nfs4_label {
	uint32_t lfs;
	uint32_t pi;
	u32 len;
	char *label;
};

typedef struct {
	char data[8];
} nfs4_verifier;

struct nfs4_stateid_struct {
	union {
		char data[16];
		struct {
			__be32 seqid;
			char other[12];
		};
	};
	enum {
		NFS4_INVALID_STATEID_TYPE = 0,
		NFS4_SPECIAL_STATEID_TYPE = 1,
		NFS4_OPEN_STATEID_TYPE = 2,
		NFS4_LOCK_STATEID_TYPE = 3,
		NFS4_DELEGATION_STATEID_TYPE = 4,
		NFS4_LAYOUT_STATEID_TYPE = 5,
		NFS4_PNFS_DS_STATEID_TYPE = 6,
		NFS4_REVOKED_STATEID_TYPE = 7,
	} type;
};

typedef struct nfs4_stateid_struct nfs4_stateid;

enum nfs_opnum4 {
	OP_ACCESS = 3,
	OP_CLOSE = 4,
	OP_COMMIT = 5,
	OP_CREATE = 6,
	OP_DELEGPURGE = 7,
	OP_DELEGRETURN = 8,
	OP_GETATTR = 9,
	OP_GETFH = 10,
	OP_LINK = 11,
	OP_LOCK = 12,
	OP_LOCKT = 13,
	OP_LOCKU = 14,
	OP_LOOKUP = 15,
	OP_LOOKUPP = 16,
	OP_NVERIFY = 17,
	OP_OPEN = 18,
	OP_OPENATTR = 19,
	OP_OPEN_CONFIRM = 20,
	OP_OPEN_DOWNGRADE = 21,
	OP_PUTFH = 22,
	OP_PUTPUBFH = 23,
	OP_PUTROOTFH = 24,
	OP_READ = 25,
	OP_READDIR = 26,
	OP_READLINK = 27,
	OP_REMOVE = 28,
	OP_RENAME = 29,
	OP_RENEW = 30,
	OP_RESTOREFH = 31,
	OP_SAVEFH = 32,
	OP_SECINFO = 33,
	OP_SETATTR = 34,
	OP_SETCLIENTID = 35,
	OP_SETCLIENTID_CONFIRM = 36,
	OP_VERIFY = 37,
	OP_WRITE = 38,
	OP_RELEASE_LOCKOWNER = 39,
	OP_BACKCHANNEL_CTL = 40,
	OP_BIND_CONN_TO_SESSION = 41,
	OP_EXCHANGE_ID = 42,
	OP_CREATE_SESSION = 43,
	OP_DESTROY_SESSION = 44,
	OP_FREE_STATEID = 45,
	OP_GET_DIR_DELEGATION = 46,
	OP_GETDEVICEINFO = 47,
	OP_GETDEVICELIST = 48,
	OP_LAYOUTCOMMIT = 49,
	OP_LAYOUTGET = 50,
	OP_LAYOUTRETURN = 51,
	OP_SECINFO_NO_NAME = 52,
	OP_SEQUENCE = 53,
	OP_SET_SSV = 54,
	OP_TEST_STATEID = 55,
	OP_WANT_DELEGATION = 56,
	OP_DESTROY_CLIENTID = 57,
	OP_RECLAIM_COMPLETE = 58,
	OP_ALLOCATE = 59,
	OP_COPY = 60,
	OP_COPY_NOTIFY = 61,
	OP_DEALLOCATE = 62,
	OP_IO_ADVISE = 63,
	OP_LAYOUTERROR = 64,
	OP_LAYOUTSTATS = 65,
	OP_OFFLOAD_CANCEL = 66,
	OP_OFFLOAD_STATUS = 67,
	OP_READ_PLUS = 68,
	OP_SEEK = 69,
	OP_WRITE_SAME = 70,
	OP_CLONE = 71,
	OP_GETXATTR = 72,
	OP_SETXATTR = 73,
	OP_LISTXATTRS = 74,
	OP_REMOVEXATTR = 75,
	OP_ILLEGAL = 10044,
};

enum nfs4_change_attr_type {
	NFS4_CHANGE_TYPE_IS_MONOTONIC_INCR = 0,
	NFS4_CHANGE_TYPE_IS_VERSION_COUNTER = 1,
	NFS4_CHANGE_TYPE_IS_VERSION_COUNTER_NOPNFS = 2,
	NFS4_CHANGE_TYPE_IS_TIME_METADATA = 3,
	NFS4_CHANGE_TYPE_IS_UNDEFINED = 4,
};

struct nfs4_string {
	unsigned int len;
	char *data;
};

struct nfs_fsid {
	uint64_t major;
	uint64_t minor;
};

struct nfs4_threshold {
	__u32 bm;
	__u32 l_type;
	__u64 rd_sz;
	__u64 wr_sz;
	__u64 rd_io_sz;
	__u64 wr_io_sz;
};

struct nfs_fattr {
	unsigned int valid;
	umode_t mode;
	__u32 nlink;
	kuid_t uid;
	kgid_t gid;
	dev_t rdev;
	__u64 size;
	union {
		struct {
			__u32 blocksize;
			__u32 blocks;
		} nfs2;
		struct {
			__u64 used;
		} nfs3;
	} du;
	struct nfs_fsid fsid;
	__u64 fileid;
	__u64 mounted_on_fileid;
	struct timespec64 atime;
	struct timespec64 mtime;
	struct timespec64 ctime;
	__u64 change_attr;
	__u64 pre_change_attr;
	__u64 pre_size;
	struct timespec64 pre_mtime;
	struct timespec64 pre_ctime;
	long unsigned int time_start;
	long unsigned int gencount;
	struct nfs4_string *owner_name;
	struct nfs4_string *group_name;
	struct nfs4_threshold *mdsthreshold;
	struct nfs4_label *label;
};

struct nfs_fsinfo {
	struct nfs_fattr *fattr;
	__u32 rtmax;
	__u32 rtpref;
	__u32 rtmult;
	__u32 wtmax;
	__u32 wtpref;
	__u32 wtmult;
	__u32 dtpref;
	__u64 maxfilesize;
	struct timespec64 time_delta;
	__u32 lease_time;
	__u32 nlayouttypes;
	__u32 layouttype[8];
	__u32 blksize;
	__u32 clone_blksize;
	enum nfs4_change_attr_type change_attr_type;
	__u32 xattr_support;
};

struct nfs_fsstat {
	struct nfs_fattr *fattr;
	__u64 tbytes;
	__u64 fbytes;
	__u64 abytes;
	__u64 tfiles;
	__u64 ffiles;
	__u64 afiles;
};

struct nfs_pathconf {
	struct nfs_fattr *fattr;
	__u32 max_link;
	__u32 max_namelen;
};

struct nfs4_change_info {
	u32 atomic;
	u64 before;
	u64 after;
};

struct nfs4_slot;

struct nfs4_sequence_args {
	struct nfs4_slot *sa_slot;
	u8 sa_cache_this: 1;
	u8 sa_privileged: 1;
};

struct nfs4_sequence_res {
	struct nfs4_slot *sr_slot;
	long unsigned int sr_timestamp;
	int sr_status;
	u32 sr_status_flags;
	u32 sr_highest_slotid;
	u32 sr_target_highest_slotid;
};

struct nfs_open_context;

struct nfs_lock_context {
	refcount_t count;
	struct list_head list;
	struct nfs_open_context *open_context;
	fl_owner_t lockowner;
	atomic_t io_count;
	struct callback_head callback_head;
};

struct nfs4_state;

struct nfs_open_context {
	struct nfs_lock_context lock_context;
	fl_owner_t flock_owner;
	struct dentry *dentry;
	const struct cred *cred;
	struct rpc_cred *ll_cred;
	struct nfs4_state *state;
	fmode_t mode;
	long unsigned int flags;
	int error;
	struct list_head list;
	struct nfs4_threshold *mdsthreshold;
	struct callback_head callback_head;
};

struct nlm_host;

struct nfs_iostats;

struct nfs_auth_info {
	unsigned int flavor_len;
	rpc_authflavor_t flavors[12];
};

struct nfs_fscache_key;

struct fscache_cookie;

struct pnfs_layoutdriver_type;

struct nfs_client;

struct nfs_server {
	struct nfs_client *nfs_client;
	struct list_head client_link;
	struct list_head master_link;
	struct rpc_clnt *client;
	struct rpc_clnt *client_acl;
	struct nlm_host *nlm_host;
	struct nfs_iostats *io_stats;
	atomic_long_t writeback;
	unsigned int flags;
	unsigned int caps;
	unsigned int rsize;
	unsigned int rpages;
	unsigned int wsize;
	unsigned int wpages;
	unsigned int wtmult;
	unsigned int dtsize;
	short unsigned int port;
	unsigned int bsize;
	unsigned int gxasize;
	unsigned int sxasize;
	unsigned int lxasize;
	unsigned int acregmin;
	unsigned int acregmax;
	unsigned int acdirmin;
	unsigned int acdirmax;
	unsigned int namelen;
	unsigned int options;
	unsigned int clone_blksize;
	enum nfs4_change_attr_type change_attr_type;
	struct nfs_fsid fsid;
	__u64 maxfilesize;
	struct timespec64 time_delta;
	long unsigned int mount_time;
	struct super_block *super;
	dev_t s_dev;
	struct nfs_auth_info auth_info;
	__u64 fattr_valid;
	struct nfs_fscache_key *fscache_key;
	struct fscache_cookie *fscache;
	u32 pnfs_blksize;
	u32 attr_bitmask[3];
	u32 attr_bitmask_nl[3];
	u32 exclcreat_bitmask[3];
	u32 cache_consistency_bitmask[3];
	u32 acl_bitmask;
	u32 fh_expire_type;
	struct pnfs_layoutdriver_type *pnfs_curr_ld;
	struct rpc_wait_queue roc_rpcwaitq;
	void *pnfs_ld_data;
	struct rb_root state_owners;
	struct ida openowner_id;
	struct ida lockowner_id;
	struct list_head state_owners_lru;
	struct list_head layouts;
	struct list_head delegations;
	struct list_head ss_copies;
	long unsigned int delegation_gen;
	long unsigned int mig_gen;
	long unsigned int mig_status;
	void (*destroy)(struct nfs_server *);
	atomic_t active;
	int: 32;
	struct __kernel_sockaddr_storage mountd_address;
	size_t mountd_addrlen;
	u32 mountd_version;
	short unsigned int mountd_port;
	short unsigned int mountd_protocol;
	struct rpc_wait_queue uoc_rpcwaitq;
	unsigned int read_hdrsize;
	const struct cred *cred;
	bool has_sec_mnt_opts;
};

struct nfs_subversion;

struct idmap;

struct nfs4_minor_version_ops;

struct nfs4_slot_table;

struct nfs4_session;

struct nfs_rpc_ops;

struct nfs41_server_owner;

struct nfs41_server_scope;

struct nfs41_impl_id;

struct nfs_client {
	refcount_t cl_count;
	atomic_t cl_mds_count;
	int cl_cons_state;
	long unsigned int cl_res_state;
	long unsigned int cl_flags;
	struct __kernel_sockaddr_storage cl_addr;
	size_t cl_addrlen;
	char *cl_hostname;
	char *cl_acceptor;
	struct list_head cl_share_link;
	struct list_head cl_superblocks;
	struct rpc_clnt *cl_rpcclient;
	const struct nfs_rpc_ops *rpc_ops;
	int cl_proto;
	struct nfs_subversion *cl_nfs_mod;
	u32 cl_minorversion;
	unsigned int cl_nconnect;
	unsigned int cl_max_connect;
	const char *cl_principal;
	struct list_head cl_ds_clients;
	u64 cl_clientid;
	nfs4_verifier cl_confirm;
	long unsigned int cl_state;
	spinlock_t cl_lock;
	long unsigned int cl_lease_time;
	long unsigned int cl_last_renewal;
	struct delayed_work cl_renewd;
	struct rpc_wait_queue cl_rpcwaitq;
	struct idmap *cl_idmap;
	const char *cl_owner_id;
	u32 cl_cb_ident;
	const struct nfs4_minor_version_ops *cl_mvops;
	long unsigned int cl_mig_gen;
	struct nfs4_slot_table *cl_slot_tbl;
	u32 cl_seqid;
	u32 cl_exchange_flags;
	struct nfs4_session *cl_session;
	bool cl_preserve_clid;
	struct nfs41_server_owner *cl_serverowner;
	struct nfs41_server_scope *cl_serverscope;
	struct nfs41_impl_id *cl_implid;
	long unsigned int cl_sp4_flags;
	wait_queue_head_t cl_lock_waitq;
	char cl_ipaddr[48];
	struct fscache_cookie *fscache;
	struct net *cl_net;
	struct list_head pending_cb_stateids;
};

struct pnfs_layout_segment;

struct nfs_write_verifier {
	char data[8];
};

struct nfs_writeverf {
	struct nfs_write_verifier verifier;
	enum nfs3_stable_how committed;
};

struct nfs_pgio_args {
	struct nfs4_sequence_args seq_args;
	struct nfs_fh *fh;
	struct nfs_open_context *context;
	struct nfs_lock_context *lock_context;
	nfs4_stateid stateid;
	__u64 offset;
	__u32 count;
	unsigned int pgbase;
	struct page **pages;
	union {
		unsigned int replen;
		struct {
			const u32 *bitmask;
			u32 bitmask_store[3];
			enum nfs3_stable_how stable;
		};
	};
};

struct nfs_pgio_res {
	struct nfs4_sequence_res seq_res;
	struct nfs_fattr *fattr;
	__u32 count;
	__u32 op_status;
	union {
		struct {
			unsigned int replen;
			int eof;
		};
		struct {
			struct nfs_writeverf *verf;
			const struct nfs_server *server;
		};
	};
};

struct nfs_commitargs {
	struct nfs4_sequence_args seq_args;
	struct nfs_fh *fh;
	__u64 offset;
	__u32 count;
	const u32 *bitmask;
};

struct nfs_commitres {
	struct nfs4_sequence_res seq_res;
	__u32 op_status;
	struct nfs_fattr *fattr;
	struct nfs_writeverf *verf;
	const struct nfs_server *server;
};

struct nfs_removeargs {
	struct nfs4_sequence_args seq_args;
	const struct nfs_fh *fh;
	struct qstr name;
};

struct nfs_removeres {
	struct nfs4_sequence_res seq_res;
	struct nfs_server *server;
	struct nfs_fattr *dir_attr;
	struct nfs4_change_info cinfo;
};

struct nfs_renameargs {
	struct nfs4_sequence_args seq_args;
	const struct nfs_fh *old_dir;
	const struct nfs_fh *new_dir;
	const struct qstr *old_name;
	const struct qstr *new_name;
};

struct nfs_renameres {
	struct nfs4_sequence_res seq_res;
	struct nfs_server *server;
	struct nfs4_change_info old_cinfo;
	struct nfs_fattr *old_fattr;
	struct nfs4_change_info new_cinfo;
	struct nfs_fattr *new_fattr;
};

struct nfs_entry {
	__u64 ino;
	__u64 cookie;
	const char *name;
	unsigned int len;
	int eof;
	struct nfs_fh *fh;
	struct nfs_fattr *fattr;
	unsigned char d_type;
	struct nfs_server *server;
};

struct nfs_readdir_arg {
	struct dentry *dentry;
	const struct cred *cred;
	__be32 *verf;
	u64 cookie;
	struct page **pages;
	unsigned int page_len;
	bool plus;
};

struct nfs_readdir_res {
	__be32 *verf;
};

struct nfstime4 {
	u64 seconds;
	u32 nseconds;
};

struct pnfs_commit_ops;

struct pnfs_ds_commit_info {
	struct list_head commits;
	unsigned int nwritten;
	unsigned int ncommitting;
	const struct pnfs_commit_ops *ops;
};

struct nfs41_server_owner {
	uint64_t minor_id;
	uint32_t major_id_sz;
	char major_id[1024];
};

struct nfs41_server_scope {
	uint32_t server_scope_sz;
	char server_scope[1024];
};

struct nfs41_impl_id {
	char domain[1025];
	char name[1025];
	struct nfstime4 date;
};

struct nfs_page_array {
	struct page **pagevec;
	unsigned int npages;
	struct page *page_array[8];
};

struct nfs_page;

struct nfs_rw_ops;

struct nfs_io_completion;

struct nfs_direct_req;

struct nfs_pgio_completion_ops;

struct nfs_pgio_header {
	struct inode *inode;
	const struct cred *cred;
	struct list_head pages;
	struct nfs_page *req;
	struct nfs_writeverf verf;
	fmode_t rw_mode;
	struct pnfs_layout_segment *lseg;
	loff_t io_start;
	const struct rpc_call_ops *mds_ops;
	void (*release)(struct nfs_pgio_header *);
	const struct nfs_pgio_completion_ops *completion_ops;
	const struct nfs_rw_ops *rw_ops;
	struct nfs_io_completion *io_completion;
	struct nfs_direct_req *dreq;
	int pnfs_error;
	int error;
	unsigned int good_bytes;
	long unsigned int flags;
	struct rpc_task task;
	struct nfs_fattr fattr;
	struct nfs_pgio_args args;
	struct nfs_pgio_res res;
	long unsigned int timestamp;
	int (*pgio_done_cb)(struct rpc_task *, struct nfs_pgio_header *);
	__u64 mds_offset;
	struct nfs_page_array page_array;
	struct nfs_client *ds_clp;
	u32 ds_commit_idx;
	u32 pgio_mirror_idx;
};

struct nfs_pgio_completion_ops {
	void (*error_cleanup)(struct list_head *, int);
	void (*init_hdr)(struct nfs_pgio_header *);
	void (*completion)(struct nfs_pgio_header *);
	void (*reschedule_io)(struct nfs_pgio_header *);
};

struct nfs_mds_commit_info {
	atomic_t rpcs_out;
	atomic_long_t ncommit;
	struct list_head list;
};

struct nfs_commit_data;

struct nfs_commit_info;

struct nfs_commit_completion_ops {
	void (*completion)(struct nfs_commit_data *);
	void (*resched_write)(struct nfs_commit_info *, struct nfs_page *);
};

struct nfs_commit_data {
	struct rpc_task task;
	struct inode *inode;
	const struct cred *cred;
	struct nfs_fattr fattr;
	struct nfs_writeverf verf;
	struct list_head pages;
	struct list_head list;
	struct nfs_direct_req *dreq;
	struct nfs_commitargs args;
	struct nfs_commitres res;
	struct nfs_open_context *context;
	struct pnfs_layout_segment *lseg;
	struct nfs_client *ds_clp;
	int ds_commit_index;
	loff_t lwb;
	const struct rpc_call_ops *mds_ops;
	const struct nfs_commit_completion_ops *completion_ops;
	int (*commit_done_cb)(struct rpc_task *, struct nfs_commit_data *);
	long unsigned int flags;
};

struct nfs_commit_info {
	struct inode *inode;
	struct nfs_mds_commit_info *mds;
	struct pnfs_ds_commit_info *ds;
	struct nfs_direct_req *dreq;
	const struct nfs_commit_completion_ops *completion_ops;
};

struct nfs_unlinkdata {
	struct nfs_removeargs args;
	struct nfs_removeres res;
	struct dentry *dentry;
	wait_queue_head_t wq;
	const struct cred *cred;
	struct nfs_fattr dir_attr;
	long int timeout;
};

struct nfs_renamedata {
	struct nfs_renameargs args;
	struct nfs_renameres res;
	const struct cred *cred;
	struct inode *old_dir;
	struct dentry *old_dentry;
	struct nfs_fattr old_fattr;
	struct inode *new_dir;
	struct dentry *new_dentry;
	struct nfs_fattr new_fattr;
	void (*complete)(struct rpc_task *, struct nfs_renamedata *);
	long int timeout;
	bool cancelled;
};

struct nlmclnt_operations;

struct nfs_client_initdata;

struct nfs_access_entry;

struct nfs_rpc_ops {
	u32 version;
	const struct dentry_operations *dentry_ops;
	const struct inode_operations *dir_inode_ops;
	const struct inode_operations *file_inode_ops;
	const struct file_operations *file_ops;
	const struct nlmclnt_operations *nlmclnt_ops;
	int (*getroot)(struct nfs_server *, struct nfs_fh *, struct nfs_fsinfo *);
	int (*submount)(struct fs_context *, struct nfs_server *);
	int (*try_get_tree)(struct fs_context *);
	int (*getattr)(struct nfs_server *, struct nfs_fh *, struct nfs_fattr *, struct inode *);
	int (*setattr)(struct dentry *, struct nfs_fattr *, struct iattr *);
	int (*lookup)(struct inode *, struct dentry *, struct nfs_fh *, struct nfs_fattr *);
	int (*lookupp)(struct inode *, struct nfs_fh *, struct nfs_fattr *);
	int (*access)(struct inode *, struct nfs_access_entry *, const struct cred *);
	int (*readlink)(struct inode *, struct page *, unsigned int, unsigned int);
	int (*create)(struct inode *, struct dentry *, struct iattr *, int);
	int (*remove)(struct inode *, struct dentry *);
	void (*unlink_setup)(struct rpc_message *, struct dentry *, struct inode *);
	void (*unlink_rpc_prepare)(struct rpc_task *, struct nfs_unlinkdata *);
	int (*unlink_done)(struct rpc_task *, struct inode *);
	void (*rename_setup)(struct rpc_message *, struct dentry *, struct dentry *);
	void (*rename_rpc_prepare)(struct rpc_task *, struct nfs_renamedata *);
	int (*rename_done)(struct rpc_task *, struct inode *, struct inode *);
	int (*link)(struct inode *, struct inode *, const struct qstr *);
	int (*symlink)(struct inode *, struct dentry *, struct page *, unsigned int, struct iattr *);
	int (*mkdir)(struct inode *, struct dentry *, struct iattr *);
	int (*rmdir)(struct inode *, const struct qstr *);
	int (*readdir)(struct nfs_readdir_arg *, struct nfs_readdir_res *);
	int (*mknod)(struct inode *, struct dentry *, struct iattr *, dev_t);
	int (*statfs)(struct nfs_server *, struct nfs_fh *, struct nfs_fsstat *);
	int (*fsinfo)(struct nfs_server *, struct nfs_fh *, struct nfs_fsinfo *);
	int (*pathconf)(struct nfs_server *, struct nfs_fh *, struct nfs_pathconf *);
	int (*set_capabilities)(struct nfs_server *, struct nfs_fh *);
	int (*decode_dirent)(struct xdr_stream *, struct nfs_entry *, bool);
	int (*pgio_rpc_prepare)(struct rpc_task *, struct nfs_pgio_header *);
	void (*read_setup)(struct nfs_pgio_header *, struct rpc_message *);
	int (*read_done)(struct rpc_task *, struct nfs_pgio_header *);
	void (*write_setup)(struct nfs_pgio_header *, struct rpc_message *, struct rpc_clnt **);
	int (*write_done)(struct rpc_task *, struct nfs_pgio_header *);
	void (*commit_setup)(struct nfs_commit_data *, struct rpc_message *, struct rpc_clnt **);
	void (*commit_rpc_prepare)(struct rpc_task *, struct nfs_commit_data *);
	int (*commit_done)(struct rpc_task *, struct nfs_commit_data *);
	int (*lock)(struct file *, int, struct file_lock *);
	int (*lock_check_bounds)(const struct file_lock *);
	void (*clear_acl_cache)(struct inode *);
	void (*close_context)(struct nfs_open_context *, int);
	struct inode * (*open_context)(struct inode *, struct nfs_open_context *, int, struct iattr *, int *);
	int (*have_delegation)(struct inode *, fmode_t);
	struct nfs_client * (*alloc_client)(const struct nfs_client_initdata *);
	struct nfs_client * (*init_client)(struct nfs_client *, const struct nfs_client_initdata *);
	void (*free_client)(struct nfs_client *);
	struct nfs_server * (*create_server)(struct fs_context *);
	struct nfs_server * (*clone_server)(struct nfs_server *, struct nfs_fh *, struct nfs_fattr *, rpc_authflavor_t);
	int (*discover_trunking)(struct nfs_server *, struct nfs_fh *);
};

struct nfs_access_entry {
	struct rb_node rb_node;
	struct list_head lru;
	kuid_t fsuid;
	kgid_t fsgid;
	struct group_info *group_info;
	u64 timestamp;
	__u32 mask;
	struct callback_head callback_head;
};

enum {
	UNAME26 = 131072,
	ADDR_NO_RANDOMIZE = 262144,
	FDPIC_FUNCPTRS = 524288,
	MMAP_PAGE_ZERO = 1048576,
	ADDR_COMPAT_LAYOUT = 2097152,
	READ_IMPLIES_EXEC = 4194304,
	ADDR_LIMIT_32BIT = 8388608,
	SHORT_INODE = 16777216,
	WHOLE_SECONDS = 33554432,
	STICKY_TIMEOUTS = 67108864,
	ADDR_LIMIT_3GB = 134217728,
};

enum perf_hw_cache_id {
	PERF_COUNT_HW_CACHE_L1D = 0,
	PERF_COUNT_HW_CACHE_L1I = 1,
	PERF_COUNT_HW_CACHE_LL = 2,
	PERF_COUNT_HW_CACHE_DTLB = 3,
	PERF_COUNT_HW_CACHE_ITLB = 4,
	PERF_COUNT_HW_CACHE_BPU = 5,
	PERF_COUNT_HW_CACHE_NODE = 6,
	PERF_COUNT_HW_CACHE_MAX = 7,
};

enum perf_hw_cache_op_id {
	PERF_COUNT_HW_CACHE_OP_READ = 0,
	PERF_COUNT_HW_CACHE_OP_WRITE = 1,
	PERF_COUNT_HW_CACHE_OP_PREFETCH = 2,
	PERF_COUNT_HW_CACHE_OP_MAX = 3,
};

enum perf_hw_cache_op_result_id {
	PERF_COUNT_HW_CACHE_RESULT_ACCESS = 0,
	PERF_COUNT_HW_CACHE_RESULT_MISS = 1,
	PERF_COUNT_HW_CACHE_RESULT_MAX = 2,
};

enum perf_branch_sample_type_shift {
	PERF_SAMPLE_BRANCH_USER_SHIFT = 0,
	PERF_SAMPLE_BRANCH_KERNEL_SHIFT = 1,
	PERF_SAMPLE_BRANCH_HV_SHIFT = 2,
	PERF_SAMPLE_BRANCH_ANY_SHIFT = 3,
	PERF_SAMPLE_BRANCH_ANY_CALL_SHIFT = 4,
	PERF_SAMPLE_BRANCH_ANY_RETURN_SHIFT = 5,
	PERF_SAMPLE_BRANCH_IND_CALL_SHIFT = 6,
	PERF_SAMPLE_BRANCH_ABORT_TX_SHIFT = 7,
	PERF_SAMPLE_BRANCH_IN_TX_SHIFT = 8,
	PERF_SAMPLE_BRANCH_NO_TX_SHIFT = 9,
	PERF_SAMPLE_BRANCH_COND_SHIFT = 10,
	PERF_SAMPLE_BRANCH_CALL_STACK_SHIFT = 11,
	PERF_SAMPLE_BRANCH_IND_JUMP_SHIFT = 12,
	PERF_SAMPLE_BRANCH_CALL_SHIFT = 13,
	PERF_SAMPLE_BRANCH_NO_FLAGS_SHIFT = 14,
	PERF_SAMPLE_BRANCH_NO_CYCLES_SHIFT = 15,
	PERF_SAMPLE_BRANCH_TYPE_SAVE_SHIFT = 16,
	PERF_SAMPLE_BRANCH_HW_INDEX_SHIFT = 17,
	PERF_SAMPLE_BRANCH_MAX_SHIFT = 18,
};

enum {
	TSK_TRACE_FL_TRACE_BIT = 0,
	TSK_TRACE_FL_GRAPH_BIT = 1,
};

struct uuidcmp {
	const char *uuid;
	int len;
};

struct subprocess_info {
	struct work_struct work;
	struct completion *complete;
	const char *path;
	char **argv;
	char **envp;
	int wait;
	int retval;
	int (*init)(struct subprocess_info *, struct cred *);
	void (*cleanup)(struct subprocess_info *);
	void *data;
};

struct mdu_array_info_s {
	int major_version;
	int minor_version;
	int patch_version;
	unsigned int ctime;
	int level;
	int size;
	int nr_disks;
	int raid_disks;
	int md_minor;
	int not_persistent;
	unsigned int utime;
	int state;
	int active_disks;
	int working_disks;
	int failed_disks;
	int spare_disks;
	int layout;
	int chunk_size;
};

typedef struct mdu_array_info_s mdu_array_info_t;

struct mdu_disk_info_s {
	int number;
	int major;
	int minor;
	int raid_disk;
	int state;
};

typedef struct mdu_disk_info_s mdu_disk_info_t;

enum kmalloc_cache_type {
	KMALLOC_NORMAL = 0,
	KMALLOC_CGROUP = 1,
	KMALLOC_RECLAIM = 2,
	KMALLOC_DMA = 3,
	NR_KMALLOC_TYPES = 4,
};

struct hash {
	int ino;
	int minor;
	int major;
	umode_t mode;
	struct hash *next;
	char name[4098];
};

struct dir_entry {
	struct list_head list;
	char *name;
	time64_t mtime;
};

enum state {
	Start = 0,
	Collect = 1,
	GotHeader = 2,
	SkipIt = 3,
	GotName = 4,
	CopyFile = 5,
	GotSymlink = 6,
	Reset = 7,
};

typedef int (*decompress_fn)(unsigned char *, long int, long int (*)(void *, long unsigned int), long int (*)(void *, long unsigned int), unsigned char *, long int *, void (*)(char *));

typedef u32 note_buf_t[134];

typedef int kexec_probe_t(const char *, long unsigned int);

typedef void *kexec_load_t(struct kimage *, char *, long unsigned int, char *, long unsigned int, char *, long unsigned int);

typedef int kexec_cleanup_t(void *);

struct kexec_file_ops {
	kexec_probe_t *probe;
	kexec_load_t *load;
	kexec_cleanup_t *cleanup;
};

struct crash_mem;

struct kimage_arch {
	struct crash_mem *exclude_ranges;
	long unsigned int backup_start;
	void *backup_buf;
	long unsigned int elfcorehdr_addr;
	long unsigned int elf_headers_sz;
	void *elf_headers;
	phys_addr_t ima_buffer_addr;
	size_t ima_buffer_size;
};

struct crash_mem_range {
	u64 start;
	u64 end;
};

struct crash_mem {
	unsigned int max_nr_ranges;
	unsigned int nr_ranges;
	struct crash_mem_range ranges[0];
};

typedef long unsigned int kimage_entry_t;

struct kexec_segment {
	union {
		void *buf;
		void *kbuf;
	};
	size_t bufsz;
	long unsigned int mem;
	size_t memsz;
};

struct purgatory_info {
	const Elf64_Ehdr *ehdr;
	Elf64_Shdr *sechdrs;
	void *purgatory_buf;
};

struct kimage {
	kimage_entry_t head;
	kimage_entry_t *entry;
	kimage_entry_t *last_entry;
	long unsigned int start;
	struct page *control_code_page;
	struct page *swap_page;
	void *vmcoreinfo_data_copy;
	long unsigned int nr_segments;
	struct kexec_segment segment[16];
	struct list_head control_pages;
	struct list_head dest_pages;
	struct list_head unusable_pages;
	long unsigned int control_page;
	unsigned int type: 1;
	unsigned int preserve_context: 1;
	unsigned int file_mode: 1;
	struct kimage_arch arch;
	void *kernel_buf;
	long unsigned int kernel_buf_len;
	void *initrd_buf;
	long unsigned int initrd_buf_len;
	char *cmdline_buf;
	long unsigned int cmdline_buf_len;
	const struct kexec_file_ops *fops;
	void *image_loader_data;
	struct purgatory_info purgatory_info;
	void *ima_buffer;
	void *elf_headers;
	long unsigned int elf_headers_sz;
	long unsigned int elf_load_addr;
};

enum ucount_type {
	UCOUNT_USER_NAMESPACES = 0,
	UCOUNT_PID_NAMESPACES = 1,
	UCOUNT_UTS_NAMESPACES = 2,
	UCOUNT_IPC_NAMESPACES = 3,
	UCOUNT_NET_NAMESPACES = 4,
	UCOUNT_MNT_NAMESPACES = 5,
	UCOUNT_CGROUP_NAMESPACES = 6,
	UCOUNT_INOTIFY_INSTANCES = 7,
	UCOUNT_INOTIFY_WATCHES = 8,
	UCOUNT_TIME_NAMESPACES = 9,
	UCOUNT_KABI_RESERVE_2 = 10,
	UCOUNT_KABI_RESERVE_3 = 11,
	UCOUNT_KABI_RESERVE_4 = 12,
	UCOUNT_KABI_RESERVE_5 = 13,
	UCOUNT_KABI_RESERVE_6 = 14,
	UCOUNT_KABI_RESERVE_7 = 15,
	UCOUNT_KABI_RESERVE_8 = 16,
	UCOUNT_KABI_RESERVE_9 = 17,
	UCOUNT_KABI_RESERVE_10 = 18,
	UCOUNT_KABI_RESERVE_11 = 19,
	UCOUNT_KABI_RESERVE_12 = 20,
	UCOUNT_KABI_RESERVE_13 = 21,
	UCOUNT_KABI_RESERVE_14 = 22,
	UCOUNT_KABI_RESERVE_15 = 23,
	UCOUNT_COUNTS = 24,
};

enum flow_dissector_key_id {
	FLOW_DISSECTOR_KEY_CONTROL = 0,
	FLOW_DISSECTOR_KEY_BASIC = 1,
	FLOW_DISSECTOR_KEY_IPV4_ADDRS = 2,
	FLOW_DISSECTOR_KEY_IPV6_ADDRS = 3,
	FLOW_DISSECTOR_KEY_PORTS = 4,
	FLOW_DISSECTOR_KEY_PORTS_RANGE = 5,
	FLOW_DISSECTOR_KEY_ICMP = 6,
	FLOW_DISSECTOR_KEY_ETH_ADDRS = 7,
	FLOW_DISSECTOR_KEY_TIPC = 8,
	FLOW_DISSECTOR_KEY_ARP = 9,
	FLOW_DISSECTOR_KEY_VLAN = 10,
	FLOW_DISSECTOR_KEY_FLOW_LABEL = 11,
	FLOW_DISSECTOR_KEY_GRE_KEYID = 12,
	FLOW_DISSECTOR_KEY_MPLS_ENTROPY = 13,
	FLOW_DISSECTOR_KEY_ENC_KEYID = 14,
	FLOW_DISSECTOR_KEY_ENC_IPV4_ADDRS = 15,
	FLOW_DISSECTOR_KEY_ENC_IPV6_ADDRS = 16,
	FLOW_DISSECTOR_KEY_ENC_CONTROL = 17,
	FLOW_DISSECTOR_KEY_ENC_PORTS = 18,
	FLOW_DISSECTOR_KEY_MPLS = 19,
	FLOW_DISSECTOR_KEY_TCP = 20,
	FLOW_DISSECTOR_KEY_IP = 21,
	FLOW_DISSECTOR_KEY_CVLAN = 22,
	FLOW_DISSECTOR_KEY_ENC_IP = 23,
	FLOW_DISSECTOR_KEY_ENC_OPTS = 24,
	FLOW_DISSECTOR_KEY_META = 25,
	FLOW_DISSECTOR_KEY_CT = 26,
	FLOW_DISSECTOR_KEY_HASH = 27,
	FLOW_DISSECTOR_KEY_NUM_OF_VLANS = 28,
	FLOW_DISSECTOR_KEY_PPPOE = 29,
	FLOW_DISSECTOR_KEY_L2TPV3 = 30,
	FLOW_DISSECTOR_KEY_MAX = 31,
};

enum {
	IPSTATS_MIB_NUM = 0,
	IPSTATS_MIB_INPKTS = 1,
	IPSTATS_MIB_INOCTETS = 2,
	IPSTATS_MIB_INDELIVERS = 3,
	IPSTATS_MIB_OUTFORWDATAGRAMS = 4,
	IPSTATS_MIB_OUTPKTS = 5,
	IPSTATS_MIB_OUTOCTETS = 6,
	IPSTATS_MIB_INHDRERRORS = 7,
	IPSTATS_MIB_INTOOBIGERRORS = 8,
	IPSTATS_MIB_INNOROUTES = 9,
	IPSTATS_MIB_INADDRERRORS = 10,
	IPSTATS_MIB_INUNKNOWNPROTOS = 11,
	IPSTATS_MIB_INTRUNCATEDPKTS = 12,
	IPSTATS_MIB_INDISCARDS = 13,
	IPSTATS_MIB_OUTDISCARDS = 14,
	IPSTATS_MIB_OUTNOROUTES = 15,
	IPSTATS_MIB_REASMTIMEOUT = 16,
	IPSTATS_MIB_REASMREQDS = 17,
	IPSTATS_MIB_REASMOKS = 18,
	IPSTATS_MIB_REASMFAILS = 19,
	IPSTATS_MIB_FRAGOKS = 20,
	IPSTATS_MIB_FRAGFAILS = 21,
	IPSTATS_MIB_FRAGCREATES = 22,
	IPSTATS_MIB_INMCASTPKTS = 23,
	IPSTATS_MIB_OUTMCASTPKTS = 24,
	IPSTATS_MIB_INBCASTPKTS = 25,
	IPSTATS_MIB_OUTBCASTPKTS = 26,
	IPSTATS_MIB_INMCASTOCTETS = 27,
	IPSTATS_MIB_OUTMCASTOCTETS = 28,
	IPSTATS_MIB_INBCASTOCTETS = 29,
	IPSTATS_MIB_OUTBCASTOCTETS = 30,
	IPSTATS_MIB_CSUMERRORS = 31,
	IPSTATS_MIB_NOECTPKTS = 32,
	IPSTATS_MIB_ECT1PKTS = 33,
	IPSTATS_MIB_ECT0PKTS = 34,
	IPSTATS_MIB_CEPKTS = 35,
	IPSTATS_MIB_REASM_OVERLAPS = 36,
	__IPSTATS_MIB_MAX = 37,
};

enum {
	ICMP_MIB_NUM = 0,
	ICMP_MIB_INMSGS = 1,
	ICMP_MIB_INERRORS = 2,
	ICMP_MIB_INDESTUNREACHS = 3,
	ICMP_MIB_INTIMEEXCDS = 4,
	ICMP_MIB_INPARMPROBS = 5,
	ICMP_MIB_INSRCQUENCHS = 6,
	ICMP_MIB_INREDIRECTS = 7,
	ICMP_MIB_INECHOS = 8,
	ICMP_MIB_INECHOREPS = 9,
	ICMP_MIB_INTIMESTAMPS = 10,
	ICMP_MIB_INTIMESTAMPREPS = 11,
	ICMP_MIB_INADDRMASKS = 12,
	ICMP_MIB_INADDRMASKREPS = 13,
	ICMP_MIB_OUTMSGS = 14,
	ICMP_MIB_OUTERRORS = 15,
	ICMP_MIB_OUTDESTUNREACHS = 16,
	ICMP_MIB_OUTTIMEEXCDS = 17,
	ICMP_MIB_OUTPARMPROBS = 18,
	ICMP_MIB_OUTSRCQUENCHS = 19,
	ICMP_MIB_OUTREDIRECTS = 20,
	ICMP_MIB_OUTECHOS = 21,
	ICMP_MIB_OUTECHOREPS = 22,
	ICMP_MIB_OUTTIMESTAMPS = 23,
	ICMP_MIB_OUTTIMESTAMPREPS = 24,
	ICMP_MIB_OUTADDRMASKS = 25,
	ICMP_MIB_OUTADDRMASKREPS = 26,
	ICMP_MIB_CSUMERRORS = 27,
	__ICMP_MIB_MAX = 28,
};

enum {
	ICMP6_MIB_NUM = 0,
	ICMP6_MIB_INMSGS = 1,
	ICMP6_MIB_INERRORS = 2,
	ICMP6_MIB_OUTMSGS = 3,
	ICMP6_MIB_OUTERRORS = 4,
	ICMP6_MIB_CSUMERRORS = 5,
	__ICMP6_MIB_MAX = 6,
};

enum {
	TCP_MIB_NUM = 0,
	TCP_MIB_RTOALGORITHM = 1,
	TCP_MIB_RTOMIN = 2,
	TCP_MIB_RTOMAX = 3,
	TCP_MIB_MAXCONN = 4,
	TCP_MIB_ACTIVEOPENS = 5,
	TCP_MIB_PASSIVEOPENS = 6,
	TCP_MIB_ATTEMPTFAILS = 7,
	TCP_MIB_ESTABRESETS = 8,
	TCP_MIB_CURRESTAB = 9,
	TCP_MIB_INSEGS = 10,
	TCP_MIB_OUTSEGS = 11,
	TCP_MIB_RETRANSSEGS = 12,
	TCP_MIB_INERRS = 13,
	TCP_MIB_OUTRSTS = 14,
	TCP_MIB_CSUMERRORS = 15,
	__TCP_MIB_MAX = 16,
};

enum {
	UDP_MIB_NUM = 0,
	UDP_MIB_INDATAGRAMS = 1,
	UDP_MIB_NOPORTS = 2,
	UDP_MIB_INERRORS = 3,
	UDP_MIB_OUTDATAGRAMS = 4,
	UDP_MIB_RCVBUFERRORS = 5,
	UDP_MIB_SNDBUFERRORS = 6,
	UDP_MIB_CSUMERRORS = 7,
	UDP_MIB_IGNOREDMULTI = 8,
	UDP_MIB_MEMERRORS = 9,
	__UDP_MIB_MAX = 10,
};

enum {
	LINUX_MIB_NUM = 0,
	LINUX_MIB_SYNCOOKIESSENT = 1,
	LINUX_MIB_SYNCOOKIESRECV = 2,
	LINUX_MIB_SYNCOOKIESFAILED = 3,
	LINUX_MIB_EMBRYONICRSTS = 4,
	LINUX_MIB_PRUNECALLED = 5,
	LINUX_MIB_RCVPRUNED = 6,
	LINUX_MIB_OFOPRUNED = 7,
	LINUX_MIB_OUTOFWINDOWICMPS = 8,
	LINUX_MIB_LOCKDROPPEDICMPS = 9,
	LINUX_MIB_ARPFILTER = 10,
	LINUX_MIB_TIMEWAITED = 11,
	LINUX_MIB_TIMEWAITRECYCLED = 12,
	LINUX_MIB_TIMEWAITKILLED = 13,
	LINUX_MIB_PAWSACTIVEREJECTED = 14,
	LINUX_MIB_PAWSESTABREJECTED = 15,
	LINUX_MIB_DELAYEDACKS = 16,
	LINUX_MIB_DELAYEDACKLOCKED = 17,
	LINUX_MIB_DELAYEDACKLOST = 18,
	LINUX_MIB_LISTENOVERFLOWS = 19,
	LINUX_MIB_LISTENDROPS = 20,
	LINUX_MIB_TCPHPHITS = 21,
	LINUX_MIB_TCPPUREACKS = 22,
	LINUX_MIB_TCPHPACKS = 23,
	LINUX_MIB_TCPRENORECOVERY = 24,
	LINUX_MIB_TCPSACKRECOVERY = 25,
	LINUX_MIB_TCPSACKRENEGING = 26,
	LINUX_MIB_TCPSACKREORDER = 27,
	LINUX_MIB_TCPRENOREORDER = 28,
	LINUX_MIB_TCPTSREORDER = 29,
	LINUX_MIB_TCPFULLUNDO = 30,
	LINUX_MIB_TCPPARTIALUNDO = 31,
	LINUX_MIB_TCPDSACKUNDO = 32,
	LINUX_MIB_TCPLOSSUNDO = 33,
	LINUX_MIB_TCPLOSTRETRANSMIT = 34,
	LINUX_MIB_TCPRENOFAILURES = 35,
	LINUX_MIB_TCPSACKFAILURES = 36,
	LINUX_MIB_TCPLOSSFAILURES = 37,
	LINUX_MIB_TCPFASTRETRANS = 38,
	LINUX_MIB_TCPSLOWSTARTRETRANS = 39,
	LINUX_MIB_TCPTIMEOUTS = 40,
	LINUX_MIB_TCPLOSSPROBES = 41,
	LINUX_MIB_TCPLOSSPROBERECOVERY = 42,
	LINUX_MIB_TCPRENORECOVERYFAIL = 43,
	LINUX_MIB_TCPSACKRECOVERYFAIL = 44,
	LINUX_MIB_TCPRCVCOLLAPSED = 45,
	LINUX_MIB_TCPDSACKOLDSENT = 46,
	LINUX_MIB_TCPDSACKOFOSENT = 47,
	LINUX_MIB_TCPDSACKRECV = 48,
	LINUX_MIB_TCPDSACKOFORECV = 49,
	LINUX_MIB_TCPABORTONDATA = 50,
	LINUX_MIB_TCPABORTONCLOSE = 51,
	LINUX_MIB_TCPABORTONMEMORY = 52,
	LINUX_MIB_TCPABORTONTIMEOUT = 53,
	LINUX_MIB_TCPABORTONLINGER = 54,
	LINUX_MIB_TCPABORTFAILED = 55,
	LINUX_MIB_TCPMEMORYPRESSURES = 56,
	LINUX_MIB_TCPMEMORYPRESSURESCHRONO = 57,
	LINUX_MIB_TCPSACKDISCARD = 58,
	LINUX_MIB_TCPDSACKIGNOREDOLD = 59,
	LINUX_MIB_TCPDSACKIGNOREDNOUNDO = 60,
	LINUX_MIB_TCPSPURIOUSRTOS = 61,
	LINUX_MIB_TCPMD5NOTFOUND = 62,
	LINUX_MIB_TCPMD5UNEXPECTED = 63,
	LINUX_MIB_TCPMD5FAILURE = 64,
	LINUX_MIB_SACKSHIFTED = 65,
	LINUX_MIB_SACKMERGED = 66,
	LINUX_MIB_SACKSHIFTFALLBACK = 67,
	LINUX_MIB_TCPBACKLOGDROP = 68,
	LINUX_MIB_PFMEMALLOCDROP = 69,
	LINUX_MIB_TCPMINTTLDROP = 70,
	LINUX_MIB_TCPDEFERACCEPTDROP = 71,
	LINUX_MIB_IPRPFILTER = 72,
	LINUX_MIB_TCPTIMEWAITOVERFLOW = 73,
	LINUX_MIB_TCPREQQFULLDOCOOKIES = 74,
	LINUX_MIB_TCPREQQFULLDROP = 75,
	LINUX_MIB_TCPRETRANSFAIL = 76,
	LINUX_MIB_TCPRCVCOALESCE = 77,
	LINUX_MIB_TCPBACKLOGCOALESCE = 78,
	LINUX_MIB_TCPOFOQUEUE = 79,
	LINUX_MIB_TCPOFODROP = 80,
	LINUX_MIB_TCPOFOMERGE = 81,
	LINUX_MIB_TCPCHALLENGEACK = 82,
	LINUX_MIB_TCPSYNCHALLENGE = 83,
	LINUX_MIB_TCPFASTOPENACTIVE = 84,
	LINUX_MIB_TCPFASTOPENACTIVEFAIL = 85,
	LINUX_MIB_TCPFASTOPENPASSIVE = 86,
	LINUX_MIB_TCPFASTOPENPASSIVEFAIL = 87,
	LINUX_MIB_TCPFASTOPENLISTENOVERFLOW = 88,
	LINUX_MIB_TCPFASTOPENCOOKIEREQD = 89,
	LINUX_MIB_TCPFASTOPENBLACKHOLE = 90,
	LINUX_MIB_TCPSPURIOUS_RTX_HOSTQUEUES = 91,
	LINUX_MIB_BUSYPOLLRXPACKETS = 92,
	LINUX_MIB_TCPAUTOCORKING = 93,
	LINUX_MIB_TCPFROMZEROWINDOWADV = 94,
	LINUX_MIB_TCPTOZEROWINDOWADV = 95,
	LINUX_MIB_TCPWANTZEROWINDOWADV = 96,
	LINUX_MIB_TCPSYNRETRANS = 97,
	LINUX_MIB_TCPORIGDATASENT = 98,
	LINUX_MIB_TCPHYSTARTTRAINDETECT = 99,
	LINUX_MIB_TCPHYSTARTTRAINCWND = 100,
	LINUX_MIB_TCPHYSTARTDELAYDETECT = 101,
	LINUX_MIB_TCPHYSTARTDELAYCWND = 102,
	LINUX_MIB_TCPACKSKIPPEDSYNRECV = 103,
	LINUX_MIB_TCPACKSKIPPEDPAWS = 104,
	LINUX_MIB_TCPACKSKIPPEDSEQ = 105,
	LINUX_MIB_TCPACKSKIPPEDFINWAIT2 = 106,
	LINUX_MIB_TCPACKSKIPPEDTIMEWAIT = 107,
	LINUX_MIB_TCPACKSKIPPEDCHALLENGE = 108,
	LINUX_MIB_TCPWINPROBE = 109,
	LINUX_MIB_TCPKEEPALIVE = 110,
	LINUX_MIB_TCPMTUPFAIL = 111,
	LINUX_MIB_TCPMTUPSUCCESS = 112,
	LINUX_MIB_TCPDELIVERED = 113,
	LINUX_MIB_TCPDELIVEREDCE = 114,
	LINUX_MIB_TCPACKCOMPRESSED = 115,
	LINUX_MIB_TCPZEROWINDOWDROP = 116,
	LINUX_MIB_TCPRCVQDROP = 117,
	LINUX_MIB_TCPWQUEUETOOBIG = 118,
	LINUX_MIB_TCPTIMEOUTREHASH = 119,
	__LINUX_MIB_MAX = 120,
};

enum {
	LINUX_MIB_XFRMNUM = 0,
	LINUX_MIB_XFRMINERROR = 1,
	LINUX_MIB_XFRMINBUFFERERROR = 2,
	LINUX_MIB_XFRMINHDRERROR = 3,
	LINUX_MIB_XFRMINNOSTATES = 4,
	LINUX_MIB_XFRMINSTATEPROTOERROR = 5,
	LINUX_MIB_XFRMINSTATEMODEERROR = 6,
	LINUX_MIB_XFRMINSTATESEQERROR = 7,
	LINUX_MIB_XFRMINSTATEEXPIRED = 8,
	LINUX_MIB_XFRMINSTATEMISMATCH = 9,
	LINUX_MIB_XFRMINSTATEINVALID = 10,
	LINUX_MIB_XFRMINTMPLMISMATCH = 11,
	LINUX_MIB_XFRMINNOPOLS = 12,
	LINUX_MIB_XFRMINPOLBLOCK = 13,
	LINUX_MIB_XFRMINPOLERROR = 14,
	LINUX_MIB_XFRMOUTERROR = 15,
	LINUX_MIB_XFRMOUTBUNDLEGENERROR = 16,
	LINUX_MIB_XFRMOUTBUNDLECHECKERROR = 17,
	LINUX_MIB_XFRMOUTNOSTATES = 18,
	LINUX_MIB_XFRMOUTSTATEPROTOERROR = 19,
	LINUX_MIB_XFRMOUTSTATEMODEERROR = 20,
	LINUX_MIB_XFRMOUTSTATESEQERROR = 21,
	LINUX_MIB_XFRMOUTSTATEEXPIRED = 22,
	LINUX_MIB_XFRMOUTPOLBLOCK = 23,
	LINUX_MIB_XFRMOUTPOLDEAD = 24,
	LINUX_MIB_XFRMOUTPOLERROR = 25,
	LINUX_MIB_XFRMFWDHDRERROR = 26,
	LINUX_MIB_XFRMOUTSTATEINVALID = 27,
	LINUX_MIB_XFRMACQUIREERROR = 28,
	__LINUX_MIB_XFRMMAX = 29,
};

enum {
	LINUX_MIB_TLSNUM = 0,
	LINUX_MIB_TLSCURRTXSW = 1,
	LINUX_MIB_TLSCURRRXSW = 2,
	LINUX_MIB_TLSCURRTXDEVICE = 3,
	LINUX_MIB_TLSCURRRXDEVICE = 4,
	LINUX_MIB_TLSTXSW = 5,
	LINUX_MIB_TLSRXSW = 6,
	LINUX_MIB_TLSTXDEVICE = 7,
	LINUX_MIB_TLSRXDEVICE = 8,
	LINUX_MIB_TLSDECRYPTERROR = 9,
	LINUX_MIB_TLSRXDEVICERESYNC = 10,
	__LINUX_MIB_TLSMAX = 11,
};

enum nf_inet_hooks {
	NF_INET_PRE_ROUTING = 0,
	NF_INET_LOCAL_IN = 1,
	NF_INET_FORWARD = 2,
	NF_INET_LOCAL_OUT = 3,
	NF_INET_POST_ROUTING = 4,
	NF_INET_NUMHOOKS = 5,
};

enum {
	NFPROTO_UNSPEC = 0,
	NFPROTO_INET = 1,
	NFPROTO_IPV4 = 2,
	NFPROTO_ARP = 3,
	NFPROTO_NETDEV = 5,
	NFPROTO_BRIDGE = 7,
	NFPROTO_IPV6 = 10,
	NFPROTO_DECNET = 12,
	NFPROTO_NUMPROTO = 13,
};

enum tcp_conntrack {
	TCP_CONNTRACK_NONE = 0,
	TCP_CONNTRACK_SYN_SENT = 1,
	TCP_CONNTRACK_SYN_RECV = 2,
	TCP_CONNTRACK_ESTABLISHED = 3,
	TCP_CONNTRACK_FIN_WAIT = 4,
	TCP_CONNTRACK_CLOSE_WAIT = 5,
	TCP_CONNTRACK_LAST_ACK = 6,
	TCP_CONNTRACK_TIME_WAIT = 7,
	TCP_CONNTRACK_CLOSE = 8,
	TCP_CONNTRACK_LISTEN = 9,
	TCP_CONNTRACK_MAX = 10,
	TCP_CONNTRACK_IGNORE = 11,
	TCP_CONNTRACK_RETRANS = 12,
	TCP_CONNTRACK_UNACK = 13,
	TCP_CONNTRACK_TIMEOUT_MAX = 14,
};

enum ct_dccp_states {
	CT_DCCP_NONE = 0,
	CT_DCCP_REQUEST = 1,
	CT_DCCP_RESPOND = 2,
	CT_DCCP_PARTOPEN = 3,
	CT_DCCP_OPEN = 4,
	CT_DCCP_CLOSEREQ = 5,
	CT_DCCP_CLOSING = 6,
	CT_DCCP_TIMEWAIT = 7,
	CT_DCCP_IGNORE = 8,
	CT_DCCP_INVALID = 9,
	__CT_DCCP_MAX = 10,
};

enum ip_conntrack_dir {
	IP_CT_DIR_ORIGINAL = 0,
	IP_CT_DIR_REPLY = 1,
	IP_CT_DIR_MAX = 2,
};

enum sctp_conntrack {
	SCTP_CONNTRACK_NONE = 0,
	SCTP_CONNTRACK_CLOSED = 1,
	SCTP_CONNTRACK_COOKIE_WAIT = 2,
	SCTP_CONNTRACK_COOKIE_ECHOED = 3,
	SCTP_CONNTRACK_ESTABLISHED = 4,
	SCTP_CONNTRACK_SHUTDOWN_SENT = 5,
	SCTP_CONNTRACK_SHUTDOWN_RECD = 6,
	SCTP_CONNTRACK_SHUTDOWN_ACK_SENT = 7,
	SCTP_CONNTRACK_HEARTBEAT_SENT = 8,
	SCTP_CONNTRACK_HEARTBEAT_ACKED = 9,
	SCTP_CONNTRACK_MAX = 10,
};

enum udp_conntrack {
	UDP_CT_UNREPLIED = 0,
	UDP_CT_REPLIED = 1,
	UDP_CT_MAX = 2,
};

enum gre_conntrack {
	GRE_CT_UNREPLIED = 0,
	GRE_CT_REPLIED = 1,
	GRE_CT_MAX = 2,
};

enum {
	XFRM_POLICY_IN = 0,
	XFRM_POLICY_OUT = 1,
	XFRM_POLICY_FWD = 2,
	XFRM_POLICY_MASK = 3,
	XFRM_POLICY_MAX = 3,
};

enum netns_bpf_attach_type {
	NETNS_BPF_INVALID = 4294967295,
	NETNS_BPF_FLOW_DISSECTOR = 0,
	NETNS_BPF_SK_LOOKUP = 1,
	MAX_NETNS_BPF_ATTACH_TYPE = 2,
};

enum skb_ext_id {
	TC_SKB_EXT = 0,
	SKB_EXT_MPTCP = 1,
	SKB_EXT_NUM = 2,
};

enum sched_tunable_scaling {
	SCHED_TUNABLESCALING_NONE = 0,
	SCHED_TUNABLESCALING_LOG = 1,
	SCHED_TUNABLESCALING_LINEAR = 2,
	SCHED_TUNABLESCALING_END = 3,
};

enum audit_ntp_type {
	AUDIT_NTP_OFFSET = 0,
	AUDIT_NTP_FREQ = 1,
	AUDIT_NTP_STATUS = 2,
	AUDIT_NTP_TAI = 3,
	AUDIT_NTP_TICK = 4,
	AUDIT_NTP_ADJUST = 5,
	AUDIT_NTP_NVALS = 6,
};

struct op_counter_config {
	long unsigned int enabled;
	long unsigned int event;
	long unsigned int count;
	long unsigned int kernel;
	long unsigned int user;
	long unsigned int unit_mask;
};

struct op_system_config {
	long unsigned int mmcr0;
	long unsigned int mmcr1;
	long unsigned int mmcra;
	long unsigned int enable_kernel;
	long unsigned int enable_user;
};

struct op_powerpc_model {
	int (*reg_setup)(struct op_counter_config *, struct op_system_config *, int);
	int (*cpu_setup)(struct op_counter_config *);
	int (*start)(struct op_counter_config *);
	int (*global_start)(struct op_counter_config *);
	void (*stop)();
	void (*global_stop)();
	int (*sync_start)();
	int (*sync_stop)();
	void (*handle_interrupt)(struct pt_regs *, struct op_counter_config *);
	int num_counters;
};

enum migratetype {
	MIGRATE_UNMOVABLE = 0,
	MIGRATE_MOVABLE = 1,
	MIGRATE_RECLAIMABLE = 2,
	MIGRATE_PCPTYPES = 3,
	MIGRATE_HIGHATOMIC = 3,
	MIGRATE_CMA = 4,
	MIGRATE_ISOLATE = 5,
	MIGRATE_TYPES = 6,
};

enum vmscan_throttle_state {
	VMSCAN_THROTTLE_WRITEBACK = 0,
	VMSCAN_THROTTLE_ISOLATED = 1,
	VMSCAN_THROTTLE_NOPROGRESS = 2,
	VMSCAN_THROTTLE_CONGESTED = 3,
	NR_VMSCAN_THROTTLE = 4,
};

enum zone_watermarks {
	WMARK_MIN = 0,
	WMARK_LOW = 1,
	WMARK_HIGH = 2,
	NR_WMARK = 3,
};

enum {
	ZONELIST_FALLBACK = 0,
	ZONELIST_NOFALLBACK = 1,
	MAX_ZONELISTS = 2,
};

typedef __kernel_long_t __kernel_off_t;

typedef __kernel_off_t off_t;

enum {
	PER_LINUX = 0,
	PER_LINUX_32BIT = 8388608,
	PER_LINUX_FDPIC = 524288,
	PER_SVR4 = 68157441,
	PER_SVR3 = 83886082,
	PER_SCOSVR3 = 117440515,
	PER_OSR5 = 100663299,
	PER_WYSEV386 = 83886084,
	PER_ISCR4 = 67108869,
	PER_BSD = 6,
	PER_SUNOS = 67108870,
	PER_XENIX = 83886087,
	PER_LINUX32 = 8,
	PER_LINUX32_3GB = 134217736,
	PER_IRIX32 = 67108873,
	PER_IRIXN32 = 67108874,
	PER_IRIX64 = 67108875,
	PER_RISCOS = 12,
	PER_SOLARIS = 67108877,
	PER_UW7 = 68157454,
	PER_OSF4 = 15,
	PER_HPUX = 16,
	PER_MASK = 255,
};

struct syscall_metadata {
	const char *name;
	int syscall_nr;
	int nb_args;
	const char **types;
	const char **args;
	struct list_head enter_fields;
	struct trace_event_call *enter_event;
	struct trace_event_call *exit_event;
};

enum {
	FW_FEATURE_PSERIES_POSSIBLE = 3479175167,
	FW_FEATURE_PSERIES_ALWAYS = 0,
	FW_FEATURE_POWERNV_POSSIBLE = 268435456,
	FW_FEATURE_POWERNV_ALWAYS = 0,
	FW_FEATURE_PS3_POSSIBLE = 12582912,
	FW_FEATURE_PS3_ALWAYS = 12582912,
	FW_FEATURE_NATIVE_POSSIBLE = 0,
	FW_FEATURE_NATIVE_ALWAYS = 0,
	FW_FEATURE_POSSIBLE = 3747610623,
	FW_FEATURE_ALWAYS = 0,
};

enum {
	PCI_STD_RESOURCES = 0,
	PCI_STD_RESOURCE_END = 5,
	PCI_ROM_RESOURCE = 6,
	PCI_IOV_RESOURCES = 7,
	PCI_IOV_RESOURCE_END = 12,
	PCI_BRIDGE_RESOURCES = 13,
	PCI_BRIDGE_RESOURCE_END = 16,
	PCI_NUM_RESOURCES = 17,
	DEVICE_COUNT_RESOURCE = 17,
};

typedef unsigned int pcie_reset_state_t;

struct trace_event_raw_ppc64_interrupt_class {
	struct trace_entry ent;
	struct pt_regs *regs;
	char __data[0];
};

struct trace_event_raw_hcall_entry {
	struct trace_entry ent;
	long unsigned int opcode;
	char __data[0];
};

struct trace_event_raw_hcall_exit {
	struct trace_entry ent;
	long unsigned int opcode;
	long int retval;
	char __data[0];
};

struct trace_event_raw_opal_entry {
	struct trace_entry ent;
	long unsigned int opcode;
	char __data[0];
};

struct trace_event_raw_opal_exit {
	struct trace_entry ent;
	long unsigned int opcode;
	long unsigned int retval;
	char __data[0];
};

struct trace_event_raw_hash_fault {
	struct trace_entry ent;
	long unsigned int addr;
	long unsigned int access;
	long unsigned int trap;
	char __data[0];
};

struct trace_event_raw_tlbie {
	struct trace_entry ent;
	long unsigned int lpid;
	long unsigned int local;
	long unsigned int rb;
	long unsigned int rs;
	long unsigned int ric;
	long unsigned int prs;
	long unsigned int r;
	char __data[0];
};

struct trace_event_data_offsets_ppc64_interrupt_class {};

struct trace_event_data_offsets_hcall_entry {};

struct trace_event_data_offsets_hcall_exit {};

struct trace_event_data_offsets_opal_entry {};

struct trace_event_data_offsets_opal_exit {};

struct trace_event_data_offsets_hash_fault {};

struct trace_event_data_offsets_tlbie {};

typedef void (*btf_trace_irq_entry)(void *, struct pt_regs *);

typedef void (*btf_trace_irq_exit)(void *, struct pt_regs *);

typedef void (*btf_trace_timer_interrupt_entry)(void *, struct pt_regs *);

typedef void (*btf_trace_timer_interrupt_exit)(void *, struct pt_regs *);

typedef void (*btf_trace_hcall_entry)(void *, long unsigned int, long unsigned int *);

typedef void (*btf_trace_hcall_exit)(void *, long unsigned int, long int, long unsigned int *);

typedef void (*btf_trace_opal_entry)(void *, long unsigned int, long unsigned int *);

typedef void (*btf_trace_opal_exit)(void *, long unsigned int, long unsigned int);

typedef void (*btf_trace_hash_fault)(void *, long unsigned int, long unsigned int, long unsigned int);

typedef void (*btf_trace_tlbie)(void *, long unsigned int, long unsigned int, long unsigned int, long unsigned int, long unsigned int, long unsigned int, long unsigned int);

struct ppc_inst {
	u32 val;
	u32 suffix;
};

struct ppc_emulated_entry {
	const char *name;
	atomic_t val;
};

struct ppc_emulated {
	struct ppc_emulated_entry altivec;
	struct ppc_emulated_entry dcba;
	struct ppc_emulated_entry dcbz;
	struct ppc_emulated_entry fp_pair;
	struct ppc_emulated_entry isel;
	struct ppc_emulated_entry mcrxr;
	struct ppc_emulated_entry mfpvr;
	struct ppc_emulated_entry multiple;
	struct ppc_emulated_entry popcntb;
	struct ppc_emulated_entry spe;
	struct ppc_emulated_entry string;
	struct ppc_emulated_entry sync;
	struct ppc_emulated_entry unaligned;
	struct ppc_emulated_entry vsx;
	struct ppc_emulated_entry mfdscr;
	struct ppc_emulated_entry mtdscr;
	struct ppc_emulated_entry lq_stq;
	struct ppc_emulated_entry lxvw4x;
	struct ppc_emulated_entry lxvh8x;
	struct ppc_emulated_entry lxvd2x;
	struct ppc_emulated_entry lxvb16x;
};

enum instruction_type {
	COMPUTE = 0,
	LOAD = 1,
	LOAD_MULTI = 2,
	LOAD_FP = 3,
	LOAD_VMX = 4,
	LOAD_VSX = 5,
	STORE = 6,
	STORE_MULTI = 7,
	STORE_FP = 8,
	STORE_VMX = 9,
	STORE_VSX = 10,
	LARX = 11,
	STCX = 12,
	BRANCH = 13,
	MFSPR = 14,
	MTSPR = 15,
	CACHEOP = 16,
	BARRIER = 17,
	SYSCALL = 18,
	MFMSR = 19,
	MTMSR = 20,
	RFI = 21,
	INTERRUPT = 22,
	UNKNOWN = 23,
};

struct instruction_op {
	int type;
	int reg;
	long unsigned int val;
	long unsigned int ea;
	int update_reg;
	int spr;
	u32 ccval;
	u32 xerval;
	u8 element_size;
	u8 vsx_flags;
};

typedef long unsigned int uintptr_t;

struct ksignal {
	struct k_sigaction ka;
	kernel_siginfo_t info;
	int sig;
};

typedef long unsigned int elf_greg_t64;

typedef unsigned int elf_greg_t32;

typedef elf_greg_t32 elf_gregset_t32[48];

typedef double elf_fpreg_t;

typedef elf_fpreg_t elf_fpregset_t[33];

typedef __vector128 elf_vrreg_t;

typedef elf_vrreg_t elf_vrregset_t32[33];

typedef elf_fpreg_t elf_vsrreghalf_t32[32];

typedef u32 compat_size_t;

typedef s32 compat_clock_t;

typedef s32 compat_pid_t;

typedef s32 compat_timer_t;

typedef s32 compat_int_t;

typedef u32 __compat_uid32_t;

typedef u32 compat_sigset_word;

struct compat_sigaltstack {
	compat_uptr_t ss_sp;
	int ss_flags;
	compat_size_t ss_size;
};

typedef struct compat_sigaltstack compat_stack_t;

typedef struct {
	compat_sigset_word sig[2];
} compat_sigset_t;

union compat_sigval {
	compat_int_t sival_int;
	compat_uptr_t sival_ptr;
};

typedef union compat_sigval compat_sigval_t;

struct compat_siginfo {
	int si_signo;
	int si_errno;
	int si_code;
	union {
		int _pad[29];
		struct {
			compat_pid_t _pid;
			__compat_uid32_t _uid;
		} _kill;
		struct {
			compat_timer_t _tid;
			int _overrun;
			compat_sigval_t _sigval;
		} _timer;
		struct {
			compat_pid_t _pid;
			__compat_uid32_t _uid;
			compat_sigval_t _sigval;
		} _rt;
		struct {
			compat_pid_t _pid;
			__compat_uid32_t _uid;
			int _status;
			compat_clock_t _utime;
			compat_clock_t _stime;
		} _sigchld;
		struct {
			compat_uptr_t _addr;
			union {
				short int _addr_lsb;
				struct {
					char _dummy_bnd[4];
					compat_uptr_t _lower;
					compat_uptr_t _upper;
				} _addr_bnd;
				struct {
					char _dummy_pkey[4];
					u32 _pkey;
				} _addr_pkey;
			};
		} _sigfault;
		struct {
			compat_long_t _band;
			int _fd;
		} _sigpoll;
		struct {
			compat_uptr_t _call_addr;
			int _syscall;
			unsigned int _arch;
		} _sigsys;
	} _sifields;
};

typedef struct compat_siginfo compat_siginfo_t;

struct sigcontext32 {
	unsigned int _unused[4];
	int signal;
	compat_uptr_t handler;
	unsigned int oldmask;
	compat_uptr_t regs;
};

struct mcontext32 {
	elf_gregset_t32 mc_gregs;
	elf_fpregset_t mc_fregs;
	unsigned int mc_pad[2];
	elf_vrregset_t32 mc_vregs;
	elf_vsrreghalf_t32 mc_vsregs;
};

struct ucontext32 {
	unsigned int uc_flags;
	unsigned int uc_link;
	compat_stack_t uc_stack;
	int uc_pad[7];
	compat_uptr_t uc_regs;
	compat_sigset_t uc_sigmask;
	int uc_maskext[30];
	int uc_pad2[3];
	struct mcontext32 uc_mcontext;
};

struct sigframe {
	struct sigcontext32 sctx;
	struct mcontext32 mctx;
	struct sigcontext32 sctx_transact;
	struct mcontext32 mctx_transact;
	int abigap[56];
};

struct rt_sigframe {
	compat_siginfo_t info;
	struct ucontext32 uc;
	struct ucontext32 uc_transact;
	int abigap[56];
};

typedef void (*perf_irq_t)(struct pt_regs *);

enum pageflags {
	PG_locked = 0,
	PG_error = 1,
	PG_referenced = 2,
	PG_uptodate = 3,
	PG_dirty = 4,
	PG_lru = 5,
	PG_active = 6,
	PG_waiters = 7,
	PG_slab = 8,
	PG_owner_priv_1 = 9,
	PG_arch_1 = 10,
	PG_reserved = 11,
	PG_private = 12,
	PG_private_2 = 13,
	PG_writeback = 14,
	PG_head = 15,
	PG_mappedtodisk = 16,
	PG_reclaim = 17,
	PG_swapbacked = 18,
	PG_unevictable = 19,
	PG_mlocked = 20,
	PG_hwpoison = 21,
	PG_young = 22,
	PG_idle = 23,
	PG_workingset = 24,
	__NR_PAGEFLAGS = 25,
	PG_checked = 9,
	PG_swapcache = 9,
	PG_fscache = 13,
	PG_pinned = 9,
	PG_savepinned = 4,
	PG_foreign = 9,
	PG_xen_remapped = 9,
	PG_slob_free = 12,
	PG_double_map = 13,
	PG_isolated = 17,
	PG_reported = 3,
};

typedef __u32 Elf32_Addr;

typedef __u16 Elf32_Half;

typedef __u32 Elf32_Off;

typedef __u32 Elf32_Word;

struct elf32_sym {
	Elf32_Word st_name;
	Elf32_Addr st_value;
	Elf32_Word st_size;
	unsigned char st_info;
	unsigned char st_other;
	Elf32_Half st_shndx;
};

typedef struct elf32_sym Elf32_Sym;

struct elf32_hdr {
	unsigned char e_ident[16];
	Elf32_Half e_type;
	Elf32_Half e_machine;
	Elf32_Word e_version;
	Elf32_Addr e_entry;
	Elf32_Off e_phoff;
	Elf32_Off e_shoff;
	Elf32_Word e_flags;
	Elf32_Half e_ehsize;
	Elf32_Half e_phentsize;
	Elf32_Half e_phnum;
	Elf32_Half e_shentsize;
	Elf32_Half e_shnum;
	Elf32_Half e_shstrndx;
};

typedef struct elf32_hdr Elf32_Ehdr;

struct vdso_data {
	__u8 eye_catcher[16];
	struct {
		__u32 major;
		__u32 minor;
	} version;
	__u32 platform;
	__u32 processor;
	__u64 processorCount;
	__u64 physicalMemorySize;
	__u64 tb_orig_stamp;
	__u64 tb_ticks_per_sec;
	__u64 tb_to_xs;
	__u64 stamp_xsec;
	__u64 tb_update_count;
	__u32 tz_minuteswest;
	__u32 tz_dsttime;
	__u32 dcache_size;
	__u32 dcache_line_size;
	__u32 icache_size;
	__u32 icache_line_size;
	__u32 dcache_block_size;
	__u32 icache_block_size;
	__u32 dcache_log_block_size;
	__u32 icache_log_block_size;
	__s32 wtom_clock_sec;
	__s32 wtom_clock_nsec;
	struct timespec stamp_xtime;
	__u32 stamp_sec_fraction;
	__u32 syscall_map_64[14];
	__u32 syscall_map_32[14];
};

struct vdso_patch_def {
	long unsigned int ftr_mask;
	long unsigned int ftr_value;
	const char *gen_name;
	const char *fix_name;
};

struct lib32_elfinfo {
	Elf32_Ehdr *hdr;
	Elf32_Sym *dynsym;
	long unsigned int dynsymsize;
	char *dynstr;
	long unsigned int text;
};

struct lib64_elfinfo {
	Elf64_Ehdr *hdr;
	Elf64_Sym *dynsym;
	long unsigned int dynsymsize;
	char *dynstr;
	long unsigned int text;
};

typedef u8 uint8_t;

enum {
	MMU_FTRS_POSSIBLE = 4290769023,
};

enum die_val {
	DIE_OOPS = 1,
	DIE_IABR_MATCH = 2,
	DIE_DABR_MATCH = 3,
	DIE_BPT = 4,
	DIE_SSTEP = 5,
};

struct regbit {
	long unsigned int bit;
	const char *name;
};

enum idle_boot_override {
	IDLE_NO_OVERRIDE = 0,
	IDLE_POWERSAVE_OFF = 1,
};

enum {
	TASKSTATS_CMD_UNSPEC = 0,
	TASKSTATS_CMD_GET = 1,
	TASKSTATS_CMD_NEW = 2,
	__TASKSTATS_CMD_MAX = 3,
};

enum {
	HI_SOFTIRQ = 0,
	TIMER_SOFTIRQ = 1,
	NET_TX_SOFTIRQ = 2,
	NET_RX_SOFTIRQ = 3,
	BLOCK_SOFTIRQ = 4,
	IRQ_POLL_SOFTIRQ = 5,
	TASKLET_SOFTIRQ = 6,
	SCHED_SOFTIRQ = 7,
	HRTIMER_SOFTIRQ = 8,
	RCU_SOFTIRQ = 9,
	NR_SOFTIRQS = 10,
};

enum cpu_usage_stat {
	CPUTIME_USER = 0,
	CPUTIME_NICE = 1,
	CPUTIME_SYSTEM = 2,
	CPUTIME_SOFTIRQ = 3,
	CPUTIME_IRQ = 4,
	CPUTIME_IDLE = 5,
	CPUTIME_IOWAIT = 6,
	CPUTIME_STEAL = 7,
	CPUTIME_GUEST = 8,
	CPUTIME_GUEST_NICE = 9,
	NR_STATS = 10,
};

enum bpf_type_flag {
	PTR_MAYBE_NULL = 256,
	MEM_RDONLY = 512,
	__BPF_TYPE_LAST_FLAG = 512,
};

enum bpf_cgroup_storage_type {
	BPF_CGROUP_STORAGE_SHARED = 0,
	BPF_CGROUP_STORAGE_PERCPU = 1,
	__BPF_CGROUP_STORAGE_MAX = 2,
};

enum bpf_tramp_prog_type {
	BPF_TRAMP_FENTRY = 0,
	BPF_TRAMP_FEXIT = 1,
	BPF_TRAMP_MODIFY_RETURN = 2,
	BPF_TRAMP_MAX = 3,
	BPF_TRAMP_REPLACE = 4,
};

enum psi_task_count {
	NR_IOWAIT = 0,
	NR_MEMSTALL = 1,
	NR_RUNNING = 2,
	NR_ONCPU = 3,
	NR_PSI_TASK_COUNTS = 4,
};

enum psi_states {
	PSI_IO_SOME = 0,
	PSI_IO_FULL = 1,
	PSI_MEM_SOME = 2,
	PSI_MEM_FULL = 3,
	PSI_CPU_SOME = 4,
	PSI_NONIDLE = 5,
	NR_PSI_STATES = 6,
};

enum psi_aggregators {
	PSI_AVGS = 0,
	PSI_POLL = 1,
	NR_PSI_AGGREGATORS = 2,
};

enum cgroup_subsys_id {
	cpuset_cgrp_id = 0,
	cpu_cgrp_id = 1,
	cpuacct_cgrp_id = 2,
	io_cgrp_id = 3,
	memory_cgrp_id = 4,
	devices_cgrp_id = 5,
	freezer_cgrp_id = 6,
	net_cls_cgrp_id = 7,
	perf_event_cgrp_id = 8,
	net_prio_cgrp_id = 9,
	hugetlb_cgrp_id = 10,
	pids_cgrp_id = 11,
	rdma_cgrp_id = 12,
	CGROUP_SUBSYS_COUNT = 13,
};

struct device_attribute {
	struct attribute attr;
	ssize_t (*show)(struct device *, struct device_attribute *, char *);
	ssize_t (*store)(struct device *, struct device_attribute *, const char *, size_t);
};

struct cpu {
	int node_id;
	int hotpluggable;
	struct device dev;
};

struct cache_index_dir;

struct cache_dir {
	struct kobject *kobj;
	struct cache_index_dir *index;
};

struct cache;

struct cache_index_dir {
	struct kobject kobj;
	struct cache_index_dir *next;
	struct cache *cache;
};

struct cache {
	struct device_node *ofnode;
	struct cpumask shared_cpu_map;
	int type;
	int level;
	int group_id;
	struct list_head list;
	struct cache *next_local;
};

struct cache_type_info {
	const char *name;
	const char *size_prop;
	const char *line_size_props[2];
	const char *nr_sets_prop;
};

enum vdso_clock_mode {
	VDSO_CLOCKMODE_NONE = 0,
	VDSO_CLOCKMODE_MAX = 1,
	VDSO_CLOCKMODE_TIMENS = 2147483647,
};

struct clocksource {
	u64 (*read)(struct clocksource *);
	u64 mask;
	u32 mult;
	u32 shift;
	u64 max_idle_ns;
	u32 maxadj;
	u64 max_cycles;
	const char *name;
	struct list_head list;
	int rating;
	enum vdso_clock_mode vdso_clock_mode;
	long unsigned int flags;
	int (*enable)(struct clocksource *);
	void (*disable)(struct clocksource *);
	void (*suspend)(struct clocksource *);
	void (*resume)(struct clocksource *);
	void (*mark_unstable)(struct clocksource *);
	void (*tick_stable)(struct clocksource *);
	struct module *owner;
};

struct pdev_archdata {
	u64 dma_mask;
	void *priv;
};

struct div_result {
	u64 result_high;
	u64 result_low;
};

struct platform_device_id {
	char name[20];
	kernel_ulong_t driver_data;
};

enum dev_prop_type {
	DEV_PROP_U8 = 0,
	DEV_PROP_U16 = 1,
	DEV_PROP_U32 = 2,
	DEV_PROP_U64 = 3,
	DEV_PROP_STRING = 4,
	DEV_PROP_REF = 5,
};

struct property_entry {
	const char *name;
	size_t length;
	bool is_inline;
	enum dev_prop_type type;
	union {
		const void *pointer;
		union {
			u8 u8_data[8];
			u16 u16_data[4];
			u32 u32_data[2];
			u64 u64_data[1];
			const char *str[1];
		} value;
	};
};

struct rtc_wkalrm {
	unsigned char enabled;
	unsigned char pending;
	struct rtc_time time;
};

struct rtc_class_ops {
	int (*ioctl)(struct device *, unsigned int, long unsigned int);
	int (*read_time)(struct device *, struct rtc_time *);
	int (*set_time)(struct device *, struct rtc_time *);
	int (*read_alarm)(struct device *, struct rtc_wkalrm *);
	int (*set_alarm)(struct device *, struct rtc_wkalrm *);
	int (*proc)(struct device *, struct seq_file *);
	int (*set_mmss64)(struct device *, time64_t);
	int (*set_mmss)(struct device *, long unsigned int);
	int (*read_callback)(struct device *, int);
	int (*alarm_irq_enable)(struct device *, unsigned int);
	int (*read_offset)(struct device *, long int *);
	int (*set_offset)(struct device *, long int);
};

struct nvram_os_partition {
	const char *name;
	int req_size;
	int min_size;
	long int size;
	long int index;
	bool os_partition;
};

struct mfd_cell;

struct platform_device {
	const char *name;
	int id;
	bool id_auto;
	struct device dev;
	u32 num_resources;
	struct resource *resource;
	const struct platform_device_id *id_entry;
	const char *driver_override;
	struct mfd_cell *mfd_cell;
	struct pdev_archdata archdata;
};

struct platform_device_info {
	struct device *parent;
	struct fwnode_handle *fwnode;
	const char *name;
	int id;
	const struct resource *res;
	unsigned int num_res;
	const void *data;
	size_t size_data;
	u64 dma_mask;
	struct property_entry *properties;
};

struct tk_read_base {
	struct clocksource *clock;
	u64 mask;
	u64 cycle_last;
	u32 mult;
	u32 shift;
	u64 xtime_nsec;
	ktime_t base;
	u64 base_real;
};

struct timekeeper {
	struct tk_read_base tkr_mono;
	struct tk_read_base tkr_raw;
	u64 xtime_sec;
	long unsigned int ktime_sec;
	struct timespec64 wall_to_monotonic;
	ktime_t offs_real;
	ktime_t offs_boot;
	ktime_t offs_tai;
	s32 tai_offset;
	unsigned int clock_was_set_seq;
	u8 cs_was_changed_seq;
	ktime_t next_leap_ktime;
	u64 raw_sec;
	struct timespec64 monotonic_to_boot;
	u64 cycle_interval;
	u64 xtime_interval;
	s64 xtime_remainder;
	u64 raw_interval;
	u64 ntp_tick;
	s64 ntp_error;
	u32 ntp_error_shift;
	u32 ntp_err_mult;
	u32 skip_second_overflow;
};

typedef __be32 fdt32_t;

struct fdt_header {
	fdt32_t magic;
	fdt32_t totalsize;
	fdt32_t off_dt_struct;
	fdt32_t off_dt_strings;
	fdt32_t off_mem_rsvmap;
	fdt32_t version;
	fdt32_t last_comp_version;
	fdt32_t boot_cpuid_phys;
	fdt32_t size_dt_strings;
	fdt32_t size_dt_struct;
};

enum {
	OPAL_P7IOC_NUM_PEST_REGS = 128,
	OPAL_PHB3_NUM_PEST_REGS = 256,
	OPAL_PHB4_NUM_PEST_REGS = 512,
};

struct drmem_lmb {
	u64 base_addr;
	u32 drc_index;
	u32 aa_index;
	u32 flags;
};

struct drmem_lmb_info {
	struct drmem_lmb *lmbs;
	int n_lmbs;
	u64 lmb_size;
};

struct ibm_feature {
	long unsigned int cpu_features;
	long unsigned int mmu_features;
	unsigned int cpu_user_ftrs;
	unsigned int cpu_user_ftrs2;
	unsigned char pabyte;
	unsigned char pabit;
	unsigned char invert;
};

struct feature_property {
	const char *name;
	u32 min_value;
	long unsigned int cpu_feature;
	long unsigned int cpu_user_ftr;
};

enum lockdep_ok {
	LOCKDEP_STILL_OK = 0,
	LOCKDEP_NOW_UNRELIABLE = 1,
};

enum bug_trap_type {
	BUG_TRAP_TYPE_NONE = 0,
	BUG_TRAP_TYPE_WARN = 1,
	BUG_TRAP_TYPE_BUG = 2,
};

struct fb_fix_screeninfo {
	char id[16];
	long unsigned int smem_start;
	__u32 smem_len;
	__u32 type;
	__u32 type_aux;
	__u32 visual;
	__u16 xpanstep;
	__u16 ypanstep;
	__u16 ywrapstep;
	__u32 line_length;
	long unsigned int mmio_start;
	__u32 mmio_len;
	__u32 accel;
	__u16 capabilities;
	__u16 reserved[2];
};

struct fb_bitfield {
	__u32 offset;
	__u32 length;
	__u32 msb_right;
};

struct fb_var_screeninfo {
	__u32 xres;
	__u32 yres;
	__u32 xres_virtual;
	__u32 yres_virtual;
	__u32 xoffset;
	__u32 yoffset;
	__u32 bits_per_pixel;
	__u32 grayscale;
	struct fb_bitfield red;
	struct fb_bitfield green;
	struct fb_bitfield blue;
	struct fb_bitfield transp;
	__u32 nonstd;
	__u32 activate;
	__u32 height;
	__u32 width;
	__u32 accel_flags;
	__u32 pixclock;
	__u32 left_margin;
	__u32 right_margin;
	__u32 upper_margin;
	__u32 lower_margin;
	__u32 hsync_len;
	__u32 vsync_len;
	__u32 sync;
	__u32 vmode;
	__u32 rotate;
	__u32 colorspace;
	__u32 reserved[4];
};

struct fb_cmap {
	__u32 start;
	__u32 len;
	__u16 *red;
	__u16 *green;
	__u16 *blue;
	__u16 *transp;
};

struct fb_copyarea {
	__u32 dx;
	__u32 dy;
	__u32 width;
	__u32 height;
	__u32 sx;
	__u32 sy;
};

struct fb_fillrect {
	__u32 dx;
	__u32 dy;
	__u32 width;
	__u32 height;
	__u32 color;
	__u32 rop;
};

struct fb_image {
	__u32 dx;
	__u32 dy;
	__u32 width;
	__u32 height;
	__u32 fg_color;
	__u32 bg_color;
	__u8 depth;
	const char *data;
	struct fb_cmap cmap;
};

struct fbcurpos {
	__u16 x;
	__u16 y;
};

struct fb_cursor {
	__u16 set;
	__u16 enable;
	__u16 rop;
	const char *mask;
	struct fbcurpos hot;
	struct fb_image image;
};

struct fb_chroma {
	__u32 redx;
	__u32 greenx;
	__u32 bluex;
	__u32 whitex;
	__u32 redy;
	__u32 greeny;
	__u32 bluey;
	__u32 whitey;
};

struct fb_videomode;

struct fb_monspecs {
	struct fb_chroma chroma;
	struct fb_videomode *modedb;
	__u8 manufacturer[4];
	__u8 monitor[14];
	__u8 serial_no[14];
	__u8 ascii[14];
	__u32 modedb_len;
	__u32 model;
	__u32 serial;
	__u32 year;
	__u32 week;
	__u32 hfmin;
	__u32 hfmax;
	__u32 dclkmin;
	__u32 dclkmax;
	__u16 input;
	__u16 dpms;
	__u16 signal;
	__u16 vfmin;
	__u16 vfmax;
	__u16 gamma;
	__u16 gtf: 1;
	__u16 misc;
	__u8 version;
	__u8 revision;
	__u8 max_x;
	__u8 max_y;
};

struct fb_videomode {
	const char *name;
	u32 refresh;
	u32 xres;
	u32 yres;
	u32 pixclock;
	u32 left_margin;
	u32 right_margin;
	u32 upper_margin;
	u32 lower_margin;
	u32 hsync_len;
	u32 vsync_len;
	u32 sync;
	u32 vmode;
	u32 flag;
};

struct fb_info;

struct fb_pixmap {
	u8 *addr;
	u32 size;
	u32 offset;
	u32 buf_align;
	u32 scan_align;
	u32 access_align;
	u32 flags;
	u32 blit_x;
	u32 blit_y;
	void (*writeio)(struct fb_info *, void *, void *, unsigned int);
	void (*readio)(struct fb_info *, void *, void *, unsigned int);
};

struct backlight_device;

struct fb_deferred_io_pageref;

struct fb_deferred_io;

struct fb_ops;

struct fb_tile_ops;

struct apertures_struct;

struct fb_info {
	atomic_t count;
	int node;
	int flags;
	int fbcon_rotate_hint;
	struct mutex lock;
	struct mutex mm_lock;
	struct fb_var_screeninfo var;
	struct fb_fix_screeninfo fix;
	struct fb_monspecs monspecs;
	struct fb_pixmap pixmap;
	struct fb_pixmap sprite;
	struct fb_cmap cmap;
	struct list_head modelist;
	struct fb_videomode *mode;
	struct backlight_device *bl_dev;
	struct mutex bl_curve_mutex;
	u8 bl_curve[128];
	struct delayed_work deferred_work;
	long unsigned int npagerefs;
	struct fb_deferred_io_pageref *pagerefs;
	struct fb_deferred_io *fbdefio;
	const struct fb_ops *fbops;
	struct device *device;
	struct device *dev;
	int class_flag;
	struct fb_tile_ops *tileops;
	union {
		char *screen_base;
		char *screen_buffer;
	};
	long unsigned int screen_size;
	void *pseudo_palette;
	u32 state;
	void *fbcon_par;
	void *par;
	struct apertures_struct *apertures;
	bool skip_vt_switch;
};

struct fb_blit_caps {
	u32 x;
	u32 y;
	u32 len;
	u32 flags;
};

struct fb_deferred_io_pageref {
	struct page *page;
	long unsigned int offset;
	struct list_head list;
};

struct fb_deferred_io {
	long unsigned int delay;
	bool sort_pagelist;
	struct mutex lock;
	struct list_head pagelist;
	void (*first_io)(struct fb_info *);
	void (*deferred_io)(struct fb_info *, struct list_head *);
};

struct fb_ops {
	struct module *owner;
	int (*fb_open)(struct fb_info *, int);
	int (*fb_release)(struct fb_info *, int);
	ssize_t (*fb_read)(struct fb_info *, char *, size_t, loff_t *);
	ssize_t (*fb_write)(struct fb_info *, const char *, size_t, loff_t *);
	int (*fb_check_var)(struct fb_var_screeninfo *, struct fb_info *);
	int (*fb_set_par)(struct fb_info *);
	int (*fb_setcolreg)(unsigned int, unsigned int, unsigned int, unsigned int, unsigned int, struct fb_info *);
	int (*fb_setcmap)(struct fb_cmap *, struct fb_info *);
	int (*fb_blank)(int, struct fb_info *);
	int (*fb_pan_display)(struct fb_var_screeninfo *, struct fb_info *);
	void (*fb_fillrect)(struct fb_info *, const struct fb_fillrect *);
	void (*fb_copyarea)(struct fb_info *, const struct fb_copyarea *);
	void (*fb_imageblit)(struct fb_info *, const struct fb_image *);
	int (*fb_cursor)(struct fb_info *, struct fb_cursor *);
	int (*fb_sync)(struct fb_info *);
	int (*fb_ioctl)(struct fb_info *, unsigned int, long unsigned int);
	int (*fb_compat_ioctl)(struct fb_info *, unsigned int, long unsigned int);
	int (*fb_mmap)(struct fb_info *, struct vm_area_struct *);
	void (*fb_get_caps)(struct fb_info *, struct fb_blit_caps *, struct fb_var_screeninfo *);
	void (*fb_destroy)(struct fb_info *);
	int (*fb_debug_enter)(struct fb_info *);
	int (*fb_debug_leave)(struct fb_info *);
};

struct fb_tilemap {
	__u32 width;
	__u32 height;
	__u32 depth;
	__u32 length;
	const __u8 *data;
};

struct fb_tilerect {
	__u32 sx;
	__u32 sy;
	__u32 width;
	__u32 height;
	__u32 index;
	__u32 fg;
	__u32 bg;
	__u32 rop;
};

struct fb_tilearea {
	__u32 sx;
	__u32 sy;
	__u32 dx;
	__u32 dy;
	__u32 width;
	__u32 height;
};

struct fb_tileblit {
	__u32 sx;
	__u32 sy;
	__u32 width;
	__u32 height;
	__u32 fg;
	__u32 bg;
	__u32 length;
	__u32 *indices;
};

struct fb_tilecursor {
	__u32 sx;
	__u32 sy;
	__u32 mode;
	__u32 shape;
	__u32 fg;
	__u32 bg;
};

struct fb_tile_ops {
	void (*fb_settile)(struct fb_info *, struct fb_tilemap *);
	void (*fb_tilecopy)(struct fb_info *, struct fb_tilearea *);
	void (*fb_tilefill)(struct fb_info *, struct fb_tilerect *);
	void (*fb_tileblit)(struct fb_info *, struct fb_tileblit *);
	void (*fb_tilecursor)(struct fb_info *, struct fb_tilecursor *);
	int (*fb_get_tilemax)(struct fb_info *);
};

struct aperture {
	resource_size_t base;
	resource_size_t size;
};

struct apertures_struct {
	unsigned int count;
	struct aperture ranges[0];
};

enum backlight_type {
	BACKLIGHT_RAW = 1,
	BACKLIGHT_PLATFORM = 2,
	BACKLIGHT_FIRMWARE = 3,
	BACKLIGHT_TYPE_MAX = 4,
};

enum backlight_scale {
	BACKLIGHT_SCALE_UNKNOWN = 0,
	BACKLIGHT_SCALE_LINEAR = 1,
	BACKLIGHT_SCALE_NON_LINEAR = 2,
};

struct backlight_properties {
	int brightness;
	int max_brightness;
	int power;
	int fb_blank;
	enum backlight_type type;
	unsigned int state;
	enum backlight_scale scale;
};

struct backlight_ops;

struct backlight_device {
	struct backlight_properties props;
	struct mutex update_lock;
	struct mutex ops_lock;
	const struct backlight_ops *ops;
	struct notifier_block fb_notif;
	struct list_head entry;
	struct device dev;
	bool fb_bl_on[32];
	int use_count;
};

struct dmt_videomode {
	u32 dmt_id;
	u32 std_2byte_code;
	u32 cvt_3byte_code;
	const struct fb_videomode *mode;
};

struct backlight_ops {
	unsigned int options;
	int (*update_status)(struct backlight_device *);
	int (*get_brightness)(struct backlight_device *);
	int (*check_fb)(struct backlight_device *, struct fb_info *);
};

enum con_flush_mode {
	CONSOLE_FLUSH_PENDING = 0,
	CONSOLE_REPLAY_ALL = 1,
};

enum kmsg_dump_reason {
	KMSG_DUMP_UNDEF = 0,
	KMSG_DUMP_PANIC = 1,
	KMSG_DUMP_OOPS = 2,
	KMSG_DUMP_EMERG = 3,
	KMSG_DUMP_RESTART = 4,
	KMSG_DUMP_HALT = 5,
	KMSG_DUMP_POWEROFF = 6,
};

struct serial_struct {
	int type;
	int line;
	unsigned int port;
	int irq;
	int flags;
	int xmit_fifo_size;
	int custom_divisor;
	int baud_base;
	short unsigned int close_delay;
	char io_type;
	char reserved_char[1];
	int hub6;
	short unsigned int closing_wait;
	short unsigned int closing_wait2;
	unsigned char *iomem_base;
	short unsigned int iomem_reg_shift;
	unsigned int port_high;
	long unsigned int iomap_base;
};

struct serial_icounter_struct {
	int cts;
	int dsr;
	int rng;
	int dcd;
	int rx;
	int tx;
	int frame;
	int overrun;
	int parity;
	int brk;
	int buf_overrun;
	int reserved[9];
};

struct serial_rs485 {
	__u32 flags;
	__u32 delay_rts_before_send;
	__u32 delay_rts_after_send;
	__u32 padding[5];
};

struct serial_iso7816 {
	__u32 flags;
	__u32 tg;
	__u32 sc_fi;
	__u32 sc_di;
	__u32 clk;
	__u32 reserved[5];
};

struct circ_buf {
	char *buf;
	int head;
	int tail;
};

struct sysrq_key_op {
	void (* const handler)(int);
	const char * const help_msg;
	const char * const action_msg;
	const int enable_mask;
};

struct uart_port;

struct uart_ops {
	unsigned int (*tx_empty)(struct uart_port *);
	void (*set_mctrl)(struct uart_port *, unsigned int);
	unsigned int (*get_mctrl)(struct uart_port *);
	void (*stop_tx)(struct uart_port *);
	void (*start_tx)(struct uart_port *);
	void (*throttle)(struct uart_port *);
	void (*unthrottle)(struct uart_port *);
	void (*send_xchar)(struct uart_port *, char);
	void (*stop_rx)(struct uart_port *);
	void (*enable_ms)(struct uart_port *);
	void (*break_ctl)(struct uart_port *, int);
	int (*startup)(struct uart_port *);
	void (*shutdown)(struct uart_port *);
	void (*flush_buffer)(struct uart_port *);
	void (*set_termios)(struct uart_port *, struct ktermios *, struct ktermios *);
	void (*set_ldisc)(struct uart_port *, struct ktermios *);
	void (*pm)(struct uart_port *, unsigned int, unsigned int);
	const char * (*type)(struct uart_port *);
	void (*release_port)(struct uart_port *);
	int (*request_port)(struct uart_port *);
	void (*config_port)(struct uart_port *, int);
	int (*verify_port)(struct uart_port *, struct serial_struct *);
	int (*ioctl)(struct uart_port *, unsigned int, long unsigned int);
	int (*poll_init)(struct uart_port *);
	void (*poll_put_char)(struct uart_port *, unsigned char);
	int (*poll_get_char)(struct uart_port *);
};

struct uart_icount {
	__u32 cts;
	__u32 dsr;
	__u32 rng;
	__u32 dcd;
	__u32 rx;
	__u32 tx;
	__u32 frame;
	__u32 overrun;
	__u32 parity;
	__u32 brk;
	__u32 buf_overrun;
};

typedef unsigned int upf_t;

typedef unsigned int upstat_t;

struct uart_state;

struct uart_port {
	spinlock_t lock;
	long unsigned int iobase;
	unsigned char *membase;
	unsigned int (*serial_in)(struct uart_port *, int);
	void (*serial_out)(struct uart_port *, int, int);
	void (*set_termios)(struct uart_port *, struct ktermios *, struct ktermios *);
	void (*set_ldisc)(struct uart_port *, struct ktermios *);
	unsigned int (*get_mctrl)(struct uart_port *);
	void (*set_mctrl)(struct uart_port *, unsigned int);
	unsigned int (*get_divisor)(struct uart_port *, unsigned int, unsigned int *);
	void (*set_divisor)(struct uart_port *, unsigned int, unsigned int, unsigned int);
	int (*startup)(struct uart_port *);
	void (*shutdown)(struct uart_port *);
	void (*throttle)(struct uart_port *);
	void (*unthrottle)(struct uart_port *);
	int (*handle_irq)(struct uart_port *);
	void (*pm)(struct uart_port *, unsigned int, unsigned int);
	void (*handle_break)(struct uart_port *);
	int (*rs485_config)(struct uart_port *, struct serial_rs485 *);
	int (*iso7816_config)(struct uart_port *, struct serial_iso7816 *);
	unsigned int irq;
	long unsigned int irqflags;
	unsigned int uartclk;
	unsigned int fifosize;
	unsigned char x_char;
	unsigned char regshift;
	unsigned char iotype;
	unsigned char quirks;
	unsigned int read_status_mask;
	unsigned int ignore_status_mask;
	struct uart_state *state;
	struct uart_icount icount;
	struct console *cons;
	long unsigned int sysrq;
	unsigned int sysrq_ch;
	upf_t flags;
	upstat_t status;
	int hw_stopped;
	unsigned int mctrl;
	unsigned int timeout;
	unsigned int type;
	const struct uart_ops *ops;
	unsigned int custom_divisor;
	unsigned int line;
	unsigned int minor;
	resource_size_t mapbase;
	resource_size_t mapsize;
	struct device *dev;
	unsigned char hub6;
	unsigned char suspended;
	unsigned char unused[2];
	const char *name;
	struct attribute_group *attr_group;
	const struct attribute_group **tty_groups;
	struct serial_rs485 rs485;
	struct serial_iso7816 iso7816;
	void *private_data;
};

enum uart_pm_state {
	UART_PM_STATE_ON = 0,
	UART_PM_STATE_OFF = 3,
	UART_PM_STATE_UNDEFINED = 4,
};

struct uart_state {
	struct tty_port port;
	enum uart_pm_state pm_state;
	struct circ_buf xmit;
	atomic_t refcount;
	wait_queue_head_t remove_wait;
	struct uart_port *uart_port;
};

struct earlycon_device {
	struct console *con;
	struct uart_port port;
	char options[16];
	unsigned int baud;
};

struct earlycon_id {
	char name[15];
	char name_term;
	char compatible[128];
	int (*setup)(struct earlycon_device *, const char *);
};

struct hstate {
	int next_nid_to_alloc;
	int next_nid_to_free;
	unsigned int order;
	long unsigned int mask;
	long unsigned int max_huge_pages;
	long unsigned int nr_huge_pages;
	long unsigned int free_huge_pages;
	long unsigned int resv_huge_pages;
	long unsigned int surplus_huge_pages;
	long unsigned int nr_overcommit_huge_pages;
	struct list_head hugepage_activelist;
	struct list_head hugepage_freelists[256];
	unsigned int nr_huge_pages_node[256];
	unsigned int free_huge_pages_node[256];
	unsigned int surplus_huge_pages_node[256];
	struct cftype cgroup_files_dfl[7];
	struct cftype cgroup_files_legacy[9];
	char name[32];
};

struct dentry___2;

struct super_block___2;

struct file_system_type___3 {
	const char *name;
	int fs_flags;
	struct dentry___2 * (*mount)(struct file_system_type___3 *, int, const char *, void *);
	void (*kill_sb)(struct super_block___2 *);
	struct module *owner;
	struct file_system_type___3 *next;
	struct hlist_head fs_supers;
	struct lock_class_key s_lock_key;
	struct lock_class_key s_umount_key;
	struct lock_class_key s_vfs_rename_key;
	struct lock_class_key s_writers_key[3];
	struct lock_class_key i_lock_key;
	struct lock_class_key i_mutex_key;
	struct lock_class_key i_mutex_dir_key;
	union {
		int (*init_fs_context)(struct fs_context *);
		struct {
			long unsigned int rh_reserved1;
		} rh_kabi_hidden_2319;
		union {		};
	};
	union {
		const struct fs_parameter_spec *parameters;
		struct {
			long unsigned int rh_reserved2;
		} rh_kabi_hidden_2320;
		union {		};
	};
	long unsigned int rh_reserved3;
	long unsigned int rh_reserved4;
};

struct qspinlock {
	union {
		atomic_t val;
		struct {
			u8 locked;
			u8 pending;
		};
		struct {
			u16 locked_pending;
			u16 tail;
		};
	};
};

typedef struct qspinlock arch_spinlock_t___2;

struct qrwlock {
	union {
		atomic_t cnts;
		struct {
			u8 wlocked;
			u8 __lstate[3];
		};
	};
	arch_spinlock_t___2 wait_lock;
};

typedef struct qrwlock arch_rwlock_t___2;

struct raw_spinlock___2 {
	arch_spinlock_t___2 raw_lock;
};

typedef struct raw_spinlock___2 raw_spinlock_t___2;

struct spinlock___2 {
	union {
		struct raw_spinlock___2 rlock;
	};
};

typedef struct spinlock___2 spinlock_t___2;

typedef struct {
	arch_rwlock_t___2 raw_lock;
} rwlock_t___2;

struct ratelimit_state___2 {
	raw_spinlock_t___2 lock;
	int interval;
	int burst;
	int printed;
	int missed;
	long unsigned int begin;
	long unsigned int flags;
};

struct file___2;

struct kiocb___2;

struct vm_area_struct___2;

struct inode___2;

struct file_lock___2;

struct page___2;

struct file_operations___2 {
	struct module *owner;
	loff_t (*llseek)(struct file___2 *, loff_t, int);
	ssize_t (*read)(struct file___2 *, char *, size_t, loff_t *);
	ssize_t (*write)(struct file___2 *, const char *, size_t, loff_t *);
	ssize_t (*read_iter)(struct kiocb___2 *, struct iov_iter *);
	ssize_t (*write_iter)(struct kiocb___2 *, struct iov_iter *);
	int (*iopoll)(struct kiocb___2 *, bool);
	int (*iterate)(struct file___2 *, struct dir_context *);
	int (*iterate_shared)(struct file___2 *, struct dir_context *);
	__poll_t (*poll)(struct file___2 *, struct poll_table_struct *);
	long int (*unlocked_ioctl)(struct file___2 *, unsigned int, long unsigned int);
	long int (*compat_ioctl)(struct file___2 *, unsigned int, long unsigned int);
	int (*mmap)(struct file___2 *, struct vm_area_struct___2 *);
	long unsigned int mmap_supported_flags;
	int (*open)(struct inode___2 *, struct file___2 *);
	int (*flush)(struct file___2 *, fl_owner_t);
	int (*release)(struct inode___2 *, struct file___2 *);
	int (*fsync)(struct file___2 *, loff_t, loff_t, int);
	int (*fasync)(int, struct file___2 *, int);
	int (*lock)(struct file___2 *, int, struct file_lock___2 *);
	ssize_t (*sendpage)(struct file___2 *, struct page___2 *, int, size_t, loff_t *, int);
	long unsigned int (*get_unmapped_area)(struct file___2 *, long unsigned int, long unsigned int, long unsigned int, long unsigned int);
	int (*check_flags)(int);
	int (*flock)(struct file___2 *, int, struct file_lock___2 *);
	ssize_t (*splice_write)(struct pipe_inode_info *, struct file___2 *, loff_t *, size_t, unsigned int);
	ssize_t (*splice_read)(struct file___2 *, loff_t *, struct pipe_inode_info *, size_t, unsigned int);
	int (*setlease)(struct file___2 *, long int, struct file_lock___2 **, void **);
	long int (*fallocate)(struct file___2 *, int, loff_t, loff_t);
	void (*show_fdinfo)(struct seq_file *, struct file___2 *);
	ssize_t (*copy_file_range)(struct file___2 *, loff_t, struct file___2 *, loff_t, size_t, unsigned int);
	loff_t (*remap_file_range)(struct file___2 *, loff_t, struct file___2 *, loff_t, loff_t, unsigned int);
	int (*fadvise)(struct file___2 *, loff_t, loff_t, int);
	long unsigned int rh_reserved1;
	long unsigned int rh_reserved2;
	long unsigned int rh_reserved3;
	long unsigned int rh_reserved4;
};

struct atomic_notifier_head___3 {
	spinlock_t___2 lock;
	struct notifier_block *head;
};

struct address_space___2;

struct mm_struct___2;

struct dev_pagemap___2;

struct page___2 {
	long unsigned int flags;
	union {
		struct {
			struct list_head lru;
			struct address_space___2 *mapping;
			long unsigned int index;
			long unsigned int private;
		};
		struct {
			dma_addr_t dma_addr;
		};
		struct {
			union {
				struct list_head slab_list;
				struct {
					struct page___2 *next;
					int pages;
					int pobjects;
				};
			};
			struct kmem_cache *slab_cache;
			void *freelist;
			union {
				void *s_mem;
				long unsigned int counters;
				struct {
					unsigned int inuse: 16;
					unsigned int objects: 15;
					unsigned int frozen: 1;
				};
			};
		};
		struct {
			long unsigned int compound_head;
			unsigned char compound_dtor;
			unsigned char compound_order;
			atomic_t compound_mapcount;
			unsigned int mapcount_seqcount;
			unsigned int compound_nr;
		};
		struct {
			long unsigned int _compound_pad_1;
			union {
				atomic_t hpage_pinned_refcount;
				struct {
					long unsigned int _compound_pad_2;
				} rh_kabi_hidden_161;
				union {				};
			};
			struct list_head deferred_list;
		};
		struct {
			long unsigned int _pt_pad_1;
			pgtable_t pmd_huge_pte;
			long unsigned int _pt_pad_2;
			union {
				union {
					struct mm_struct___2 *pt_mm;
					atomic_t pt_frag_refcount;
				};
				struct {
					struct mm_struct___2 *pt_mm;
				} rh_kabi_hidden_173;
				union {				};
			};
			spinlock_t___2 ptl;
		};
		struct {
			struct dev_pagemap___2 *pgmap;
			union {
				void *zone_device_data;
				struct {
					long unsigned int hmm_data;
				} rh_kabi_hidden_184;
				union {				};
			};
			long unsigned int _zd_pad_1;
		};
		struct callback_head callback_head;
	};
	union {
		atomic_t _mapcount;
		unsigned int page_type;
		unsigned int active;
		int units;
	};
	atomic_t _refcount;
	union {
		long unsigned int memcg_data;
		struct {
			struct mem_cgroup *mem_cgroup;
		} rh_kabi_hidden_216;
		union {		};
	};
};

struct task_struct___2;

struct thread_info___2 {
	struct task_struct___2 *task;
	int cpu;
	int preempt_count;
	long unsigned int local_flags;
	long unsigned int *livepatch_sp;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long unsigned int flags;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
};

struct hrtimer_clock_base___2;

struct hrtimer___2 {
	struct timerqueue_node node;
	ktime_t _softexpires;
	enum hrtimer_restart (*function)(struct hrtimer___2 *);
	struct hrtimer_clock_base___2 *base;
	u8 state;
	u8 is_rel;
	u8 is_soft;
	u8 is_hard;
	size_t hrtimer_size_rh;
	struct hrtimer_rh *_rh;
};

struct sched_dl_entity___2 {
	struct rb_node rb_node;
	u64 dl_runtime;
	u64 dl_deadline;
	u64 dl_period;
	u64 dl_bw;
	u64 dl_density;
	s64 runtime;
	u64 deadline;
	unsigned int flags;
	unsigned int dl_throttled: 1;
	unsigned int rh_reserved_dl_boosted: 1;
	unsigned int dl_yielded: 1;
	unsigned int dl_non_contending: 1;
	unsigned int dl_overrun: 1;
	struct hrtimer___2 dl_timer;
	struct hrtimer___2 inactive_timer;
};

struct vmacache___2 {
	u64 seqnum;
	struct vm_area_struct___2 *vmas[4];
};

struct prev_cputime___2 {
	u64 utime;
	u64 stime;
	raw_spinlock_t___2 lock;
};

struct mutex___2 {
	atomic_long_t owner;
	union {
		raw_spinlock_t___2 wait_lock;
		struct {
			spinlock_t___2 wait_lock;
		} rh_kabi_hidden_66;
		union {		};
	};
	struct optimistic_spin_queue osq;
	struct list_head wait_list;
};

struct page_frag___2 {
	struct page___2 *page;
	__u32 offset;
	__u32 size;
};

struct task_struct_rh___2;

struct completion___2;

struct cred___2;

struct signal_struct___2;

struct sighand_struct___2;

struct io_context___2;

struct task_struct___2 {
	union {
		struct {
			unsigned int __state;
		};
		struct {
			volatile long int state;
		} rh_kabi_hidden_739;
		union {		};
	};
	void *stack;
	union {
		refcount_t usage;
		struct {
			atomic_t usage;
		} rh_kabi_hidden_748;
		union {		};
	};
	unsigned int flags;
	unsigned int ptrace;
	struct llist_node rh_reserved_wake_entry;
	int on_cpu;
	unsigned int wakee_flips;
	long unsigned int wakee_flip_decay_ts;
	struct task_struct___2 *last_wakee;
	int recent_used_cpu;
	int wake_cpu;
	int on_rq;
	int prio;
	int static_prio;
	int normal_prio;
	unsigned int rt_priority;
	const struct sched_class *sched_class;
	long: 64;
	long: 64;
	long: 64;
	struct sched_entity se;
	struct sched_rt_entity rt;
	struct task_group *sched_task_group;
	struct sched_dl_entity___2 dl;
	struct hlist_head preempt_notifiers;
	unsigned int btrace_seq;
	unsigned int policy;
	int nr_cpus_allowed;
	short unsigned int migration_disabled;
	short unsigned int migration_flags;
	cpumask_t cpus_mask;
	struct sched_info sched_info;
	struct list_head tasks;
	struct plist_node pushable_tasks;
	struct rb_node pushable_dl_tasks;
	struct mm_struct___2 *mm;
	struct mm_struct___2 *active_mm;
	struct vmacache___2 vmacache;
	struct task_rss_stat rss_stat;
	int exit_state;
	int exit_code;
	int exit_signal;
	int pdeath_signal;
	long unsigned int jobctl;
	unsigned int personality;
	unsigned int sched_reset_on_fork: 1;
	unsigned int sched_contributes_to_load: 1;
	unsigned int sched_migrated: 1;
	unsigned int rh_reserved_sched_remote_wakeup: 1;
	unsigned int sched_psi_wake_requeue: 1;
	int: 27;
	unsigned int in_execve: 1;
	unsigned int in_iowait: 1;
	unsigned int restore_sigmask: 1;
	unsigned int in_user_fault: 1;
	unsigned int rh_reserved_memcg_kmem_skip_account: 1;
	unsigned int no_cgroup_migration: 1;
	unsigned int use_memdelay: 1;
	unsigned int frozen: 1;
	unsigned int sched_remote_wakeup: 1;
	unsigned int in_memstall: 1;
	unsigned int in_page_owner: 1;
	unsigned int in_thrashing: 1;
	long unsigned int atomic_flags;
	struct restart_block restart_block;
	pid_t pid;
	pid_t tgid;
	struct task_struct___2 *real_parent;
	struct task_struct___2 *parent;
	struct list_head children;
	struct list_head sibling;
	struct task_struct___2 *group_leader;
	struct list_head ptraced;
	struct list_head ptrace_entry;
	struct mem_cgroup *active_memcg;
	union {
		long unsigned int stack_canary;
		struct {
			long unsigned int rh_reserved2;
		} rh_kabi_hidden_982;
		union {		};
	};
	struct pid *thread_pid;
	union {
		const cpumask_t *cpus_ptr;
		struct {
			long unsigned int rh_reserved3;
		} rh_kabi_hidden_987;
		union {		};
	};
	struct task_struct_rh___2 *task_struct_rh;
	struct pid *rh_pgid;
	struct sched_dl_entity___2 *pi_se;
	union {
		void *migration_pending;
		struct {
			long unsigned int rh_reserved6;
		} rh_kabi_hidden_1001;
		union {		};
	};
	struct pid *rh_sid;
	struct list_head thread_group;
	struct list_head thread_node;
	struct completion___2 *vfork_done;
	int *set_child_tid;
	int *clear_child_tid;
	u64 utime;
	u64 stime;
	u64 gtime;
	struct prev_cputime___2 prev_cputime;
	struct vtime vtime;
	atomic_t tick_dep_mask;
	long unsigned int nvcsw;
	long unsigned int nivcsw;
	u64 start_time;
	u64 real_start_time;
	long unsigned int min_flt;
	long unsigned int maj_flt;
	union {
		struct {
			struct __call_single_node wake_entry;
		};
		struct {
			struct task_cputime cputime_expires;
		} rh_kabi_hidden_1045;
		union {		};
	};
	union {
		struct {
			struct mutex___2 futex_exit_mutex;
			unsigned int futex_state;
		};
		struct {
			struct list_head cpu_timers[3];
		} rh_kabi_hidden_1049;
		union {		};
	};
	const struct cred___2 *ptracer_cred;
	const struct cred___2 *real_cred;
	const struct cred___2 *cred;
	char comm[16];
	struct nameidata *nameidata;
	struct sysv_sem sysvsem;
	struct sysv_shm sysvshm;
	long unsigned int last_switch_count;
	struct fs_struct *fs;
	struct files_struct *files;
	struct nsproxy *nsproxy;
	struct signal_struct___2 *signal;
	struct sighand_struct___2 *sighand;
	sigset_t blocked;
	sigset_t real_blocked;
	sigset_t saved_sigmask;
	struct sigpending pending;
	long unsigned int sas_ss_sp;
	size_t sas_ss_size;
	unsigned int sas_ss_flags;
	struct callback_head *task_works;
	struct audit_context *audit_context;
	kuid_t loginuid;
	unsigned int sessionid;
	struct seccomp seccomp;
	u32 rh_reserved_parent_exec_id;
	u32 rh_reserved_self_exec_id;
	spinlock_t___2 alloc_lock;
	raw_spinlock_t___2 pi_lock;
	struct wake_q_node wake_q;
	struct rb_root_cached pi_waiters;
	struct task_struct___2 *pi_top_task;
	struct rt_mutex_waiter *pi_blocked_on;
	void *journal_info;
	struct bio_list *bio_list;
	struct blk_plug *plug;
	struct reclaim_state *reclaim_state;
	struct backing_dev_info *backing_dev_info;
	struct io_context___2 *io_context;
	long unsigned int ptrace_message;
	union {
		kernel_siginfo_t *last_siginfo;
		struct {
			siginfo_t *last_siginfo;
		} rh_kabi_hidden_1185;
		union {		};
	};
	struct task_io_accounting ioac;
	u64 acct_rss_mem1;
	u64 acct_vm_mem1;
	u64 acct_timexpd;
	nodemask_t mems_allowed;
	union {
		seqcount_spinlock_t mems_allowed_seq;
		struct {
			seqcount_t mems_allowed_seq;
		} rh_kabi_hidden_1201;
		union {		};
	};
	int cpuset_mem_spread_rotor;
	int cpuset_slab_spread_rotor;
	unsigned int psi_flags;
	struct css_set *cgroups;
	struct list_head cg_list;
	struct robust_list_head *robust_list;
	struct compat_robust_list_head *compat_robust_list;
	struct list_head pi_state_list;
	struct futex_pi_state *pi_state_cache;
	struct perf_event_context *perf_event_ctxp[2];
	struct mutex___2 perf_event_mutex;
	struct list_head perf_event_list;
	struct mempolicy *mempolicy;
	short int il_prev;
	short int pref_node_fork;
	int numa_scan_seq;
	unsigned int numa_scan_period;
	unsigned int numa_scan_period_max;
	int numa_preferred_nid;
	long unsigned int numa_migrate_retry;
	u64 node_stamp;
	u64 last_task_numa_placement;
	u64 last_sum_exec_runtime;
	struct callback_head numa_work;
	struct list_head numa_entry;
	struct numa_group *numa_group;
	long unsigned int *numa_faults;
	long unsigned int total_numa_faults;
	long unsigned int numa_faults_locality[3];
	long unsigned int numa_pages_migrated;
	struct rseq *rseq;
	u32 rseq_len;
	u32 rseq_sig;
	long unsigned int rseq_event_mask;
	struct tlbflush_unmap_batch tlb_ubc;
	union {
		union {
			refcount_t rcu_users;
			struct callback_head rcu;
		};
		struct {
			struct callback_head rcu;
		} rh_kabi_hidden_1308;
		union {		};
	};
	struct pipe_inode_info *splice_pipe;
	struct page_frag___2 task_frag;
	struct task_delay_info *delays;
	int nr_dirtied;
	int nr_dirtied_pause;
	long unsigned int dirty_paused_when;
	u64 timer_slack_ns;
	u64 default_timer_slack_ns;
	int curr_ret_stack;
	struct ftrace_ret_stack *ret_stack;
	long long unsigned int ftrace_timestamp;
	atomic_t trace_overrun;
	atomic_t tracing_graph_pause;
	long unsigned int trace;
	long unsigned int trace_recursion;
	struct mem_cgroup *memcg_in_oom;
	gfp_t memcg_oom_gfp_mask;
	int memcg_oom_order;
	unsigned int memcg_nr_pages_over_high;
	struct request_queue *throttle_queue;
	struct uprobe_task *utask;
	struct kmap_ctrl kmap_ctrl;
	int pagefault_disabled;
	struct task_struct___2 *oom_reaper_list;
	int patch_state;
	void *security;
	union {
		struct hlist_node pid_links[4];
		struct {
			long unsigned int rh_reserved1;
			long unsigned int rh_reserved2;
			long unsigned int rh_reserved3;
			long unsigned int rh_reserved4;
			long unsigned int rh_reserved5;
			long unsigned int rh_reserved6;
			long unsigned int rh_reserved7;
			long unsigned int rh_reserved8;
		} rh_kabi_hidden_1450;
		union {		};
	};
	long: 64;
	struct thread_struct thread;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
};

struct paca_struct___2 {
	struct lppaca *lppaca_ptr;
	u16 paca_index;
	u16 lock_token;
	u64 kernel_toc;
	u64 kernelbase;
	u64 kernel_msr;
	void *emergency_sp;
	u64 data_offset;
	s16 hw_cpu_id;
	u8 cpu_start;
	u8 kexec_state;
	struct slb_shadow *slb_shadow_ptr;
	struct dtl_entry *dispatch_log;
	struct dtl_entry *dispatch_log_end;
	u64 dscr_default;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	u64 exgen[11];
	u64 exslb[11];
	u16 vmalloc_sllp;
	u16 slb_cache_ptr;
	u32 slb_cache[8];
	mm_context_id_t mm_ctx_id;
	unsigned char mm_ctx_low_slices_psize[8];
	unsigned char mm_ctx_high_slices_psize[2048];
	long unsigned int mm_ctx_slb_addr_limit;
	struct task_struct___2 *__current;
	u64 kstack;
	u64 stab_rr;
	u64 saved_r1;
	u64 saved_msr;
	u16 trap_save;
	u8 irq_soft_mask;
	u8 irq_happened;
	u8 irq_work_pending;
	u8 pmcregs_in_use;
	u64 sprg_vdso;
	u64 tm_scratch;
	long unsigned int idle_state;
	union {
		struct {
			u8 thread_idle_state;
			u8 subcore_sibling_mask;
		};
		struct {
			u64 requested_psscr;
			atomic_t dont_stop;
		};
	};
	u64 exnmi[11];
	u64 exmc[11];
	void *nmi_emergency_sp;
	void *mc_emergency_sp;
	u16 in_nmi;
	u16 in_mce;
	u8 hmi_event_available;
	u8 hmi_p9_special_emu;
	u32 hmi_irqs;
	u8 ftrace_enabled;
	struct cpu_accounting_data accounting;
	u64 dtl_ridx;
	struct dtl_entry *dtl_curr;
	struct kvmppc_host_state kvm_hstate;
	struct sibling_subcore_state *sibling_subcore_state;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	u64 exrfi[11];
	void *rfi_flush_fallback_area;
	u64 l1d_flush_size;
	u8 *mce_data_buf;
	struct slb_entry *mce_faulty_slbs;
	u16 slb_save_cache_ptr;
	struct mmiowb_state mmiowb_state;
	long unsigned int canary;
	struct mce_info *mce_info;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
};

struct irq_desc___2;

typedef void (*irq_flow_handler_t___2)(struct irq_desc___2 *);

struct irq_chip___2;

struct irq_domain___2;

struct irq_data___2 {
	u32 mask;
	unsigned int irq;
	long unsigned int hwirq;
	struct irq_common_data *common;
	struct irq_chip___2 *chip;
	struct irq_domain___2 *domain;
	void *chip_data;
};

struct wait_queue_head___2 {
	spinlock_t___2 lock;
	struct list_head head;
};

typedef struct wait_queue_head___2 wait_queue_head_t___2;

struct kset___2;

struct kobj_type___2;

struct kernfs_node___2;

struct kobject___2 {
	const char *name;
	struct list_head entry;
	struct kobject___2 *parent;
	struct kset___2 *kset;
	const struct kobj_type___2 *ktype;
	struct kernfs_node___2 *sd;
	struct kref kref;
	unsigned int state_initialized: 1;
	unsigned int state_in_sysfs: 1;
	unsigned int state_add_uevent_sent: 1;
	unsigned int state_remove_uevent_sent: 1;
	unsigned int uevent_suppress: 1;
	long unsigned int rh_reserved1;
	long unsigned int rh_reserved2;
	long unsigned int rh_reserved3;
	long unsigned int rh_reserved4;
};

struct irq_desc___2 {
	struct irq_common_data irq_common_data;
	struct irq_data___2 irq_data;
	unsigned int *kstat_irqs;
	irq_flow_handler_t___2 handle_irq;
	struct irqaction *action;
	unsigned int status_use_accessors;
	unsigned int core_internal_state__do_not_mess_with_it;
	unsigned int depth;
	unsigned int wake_depth;
	unsigned int irq_count;
	unsigned int tot_count;
	long unsigned int last_unhandled;
	unsigned int irqs_unhandled;
	atomic_t threads_handled;
	int threads_handled_last;
	raw_spinlock_t___2 lock;
	struct cpumask *percpu_enabled;
	const struct cpumask *percpu_affinity;
	const struct cpumask *affinity_hint;
	struct irq_affinity_notify *affinity_notify;
	long unsigned int threads_oneshot;
	atomic_t threads_active;
	wait_queue_head_t___2 wait_for_threads;
	unsigned int nr_actions;
	unsigned int no_suspend_depth;
	unsigned int cond_suspend_depth;
	unsigned int force_resume_depth;
	struct proc_dir_entry *dir;
	struct callback_head rcu;
	struct kobject___2 kobj;
	struct mutex___2 request_mutex;
	int parent_irq;
	struct module *owner;
	const char *name;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
};

typedef struct {
	union {
		seqcount_spinlock_t seqcount;
		struct {
			struct seqcount seqcount;
		} rh_kabi_hidden_808;
		union {		};
	};
	spinlock_t___2 lock;
} seqlock_t___2;

struct vm_operations_struct___2;

struct vm_area_struct___2 {
	long unsigned int vm_start;
	long unsigned int vm_end;
	struct vm_area_struct___2 *vm_next;
	struct vm_area_struct___2 *vm_prev;
	struct rb_node vm_rb;
	long unsigned int rb_subtree_gap;
	struct mm_struct___2 *vm_mm;
	pgprot_t vm_page_prot;
	long unsigned int vm_flags;
	struct {
		struct rb_node rb;
		long unsigned int rb_subtree_last;
	} shared;
	struct list_head anon_vma_chain;
	struct anon_vma *anon_vma;
	const struct vm_operations_struct___2 *vm_ops;
	long unsigned int vm_pgoff;
	struct file___2 *vm_file;
	void *vm_private_data;
	atomic_long_t swap_readahead_info;
	struct mempolicy *vm_policy;
	struct vm_userfaultfd_ctx vm_userfaultfd_ctx;
	long unsigned int rh_reserved1;
	long unsigned int rh_reserved2;
	long unsigned int rh_reserved3;
	long unsigned int rh_reserved4;
};

struct rw_semaphore___3 {
	atomic_long_t count;
	struct list_head wait_list;
	raw_spinlock_t___2 wait_lock;
	struct optimistic_spin_queue osq;
	union {
		atomic_long_t owner;
		struct {
			struct task_struct___2 *owner;
		} rh_kabi_hidden_53;
		union {		};
	};
};

struct swait_queue_head___2 {
	raw_spinlock_t___2 lock;
	struct list_head task_list;
};

struct completion___2 {
	unsigned int done;
	union {
		struct swait_queue_head___2 wait;
		struct {
			wait_queue_head_t___2 wait;
		} rh_kabi_hidden_28;
		union {		};
	};
};

struct core_state___2;

struct mm_struct___2 {
	struct {
		struct vm_area_struct___2 *mmap;
		struct rb_root mm_rb;
		u64 vmacache_seqnum;
		long unsigned int (*get_unmapped_area)(struct file___2 *, long unsigned int, long unsigned int, long unsigned int, long unsigned int);
		long unsigned int mmap_base;
		long unsigned int mmap_legacy_base;
		long unsigned int task_size;
		long unsigned int highest_vm_end;
		pgd_t *pgd;
		atomic_t mm_users;
		atomic_t mm_count;
		atomic_long_t pgtables_bytes;
		int map_count;
		spinlock_t___2 page_table_lock;
		union {
			union {
				struct rw_semaphore___3 mmap_sem;
				struct rw_semaphore___3 mmap_lock;
			};
			struct {
				struct rw_semaphore___3 mmap_sem;
			} rh_kabi_hidden_453;
			union {			};
		};
		struct list_head mmlist;
		long unsigned int hiwater_rss;
		long unsigned int hiwater_vm;
		long unsigned int total_vm;
		long unsigned int locked_vm;
		atomic64_t pinned_vm;
		long unsigned int data_vm;
		long unsigned int exec_vm;
		long unsigned int stack_vm;
		long unsigned int def_flags;
		spinlock_t___2 arg_lock;
		long unsigned int start_code;
		long unsigned int end_code;
		long unsigned int start_data;
		long unsigned int end_data;
		long unsigned int start_brk;
		long unsigned int brk;
		long unsigned int start_stack;
		long unsigned int arg_start;
		long unsigned int arg_end;
		long unsigned int env_start;
		long unsigned int env_end;
		long unsigned int rh_reserved_saved_auxv[70];
		struct mm_rss_stat rss_stat;
		struct linux_binfmt *binfmt;
		mm_context_t context;
		long unsigned int flags;
		struct core_state___2 *core_state;
		atomic_t membarrier_state;
		spinlock_t___2 ioctx_lock;
		struct kioctx_table *ioctx_table;
		struct task_struct___2 *owner;
		struct user_namespace *user_ns;
		struct file___2 *exe_file;
		union {
			struct mmu_notifier_subscriptions *notifier_subscriptions;
			struct {
				struct mmu_notifier_mm *mmu_notifier_mm;
			} rh_kabi_hidden_536;
			union {			};
		};
		long unsigned int numa_next_scan;
		long unsigned int numa_scan_offset;
		int numa_scan_seq;
		atomic_t tlb_flush_pending;
		struct uprobes_state uprobes_state;
		atomic_long_t hugetlb_usage;
		struct work_struct async_put_work;
	};
	long unsigned int rh_reserved1;
	long unsigned int rh_reserved2;
	union {
		seqcount_t write_protect_seq;
		struct {
			long unsigned int rh_reserved3;
		} rh_kabi_hidden_588;
		union {		};
	};
	union {
		struct mm_struct_rh *mm_rh;
		struct {
			long unsigned int rh_reserved4;
		} rh_kabi_hidden_589;
		union {		};
	};
	long unsigned int rh_reserved5;
	long unsigned int rh_reserved6;
	long unsigned int rh_reserved7;
	union {
		atomic_t vas_windows;
		struct {
			long unsigned int rh_reserved8;
		} rh_kabi_hidden_604;
		union {		};
	};
	long unsigned int cpu_bitmap[0];
};

struct blocking_notifier_head___2 {
	struct rw_semaphore___3 rwsem;
	struct notifier_block *head;
};

struct xarray___2 {
	spinlock_t___2 xa_lock;
	gfp_t xa_flags;
	void *xa_head;
	size_t xarray_size_rh;
	struct xarray_rh _rh;
};

struct address_space_operations___2;

struct address_space___2 {
	struct inode___2 *host;
	struct xarray___2 i_pages;
	atomic_t i_mmap_writable;
	struct rb_root_cached i_mmap;
	struct rw_semaphore___3 i_mmap_rwsem;
	long unsigned int nrpages;
	long unsigned int nrexceptional;
	long unsigned int writeback_index;
	const struct address_space_operations___2 *a_ops;
	long unsigned int flags;
	spinlock_t___2 private_lock;
	gfp_t gfp_mask;
	struct list_head private_list;
	void *private_data;
	errseq_t wb_err;
	long unsigned int rh_reserved1;
	long unsigned int rh_reserved2;
	long unsigned int rh_reserved3;
	long unsigned int rh_reserved4;
};

typedef int (*dev_page_fault_t___2)(struct vm_area_struct___2 *, long unsigned int, const struct page___2 *, unsigned int, pmd_t *);

typedef void (*dev_page_free_t___2)(struct page___2 *, void *);

struct device___2;

struct dev_pagemap_ops___2;

struct dev_pagemap___2 {
	dev_page_fault_t___2 rh_reserved_page_fault;
	dev_page_free_t___2 rh_reserved_page_free;
	struct vmem_altmap altmap;
	bool rh_reserved_altmap_valid;
	struct resource rh_reserved_res;
	struct percpu_ref *ref;
	struct device___2 *rh_reserved_dev;
	void *rh_reserved_data;
	enum memory_type type;
	u64 rh_reserved_pci_p2pdma_bus_offset;
	const struct dev_pagemap_ops___2 *ops;
	unsigned int flags;
	struct percpu_ref internal_ref;
	struct completion___2 done;
	void *owner;
	int nr_range;
	long unsigned int vmemmap_shift;
	union {
		struct range range;
		struct range ranges[0];
	};
};

struct path___2 {
	struct vfsmount *mnt;
	struct dentry___2 *dentry;
};

struct fown_struct___2 {
	rwlock_t___2 lock;
	struct pid *pid;
	enum pid_type pid_type;
	kuid_t uid;
	kuid_t euid;
	int signum;
};

struct file___2 {
	union {
		struct llist_node fu_llist;
		struct callback_head fu_rcuhead;
	} f_u;
	struct path___2 f_path;
	struct inode___2 *f_inode;
	const struct file_operations___2 *f_op;
	spinlock_t___2 f_lock;
	enum rw_hint f_write_hint;
	atomic_long_t f_count;
	unsigned int f_flags;
	fmode_t f_mode;
	struct mutex___2 f_pos_lock;
	loff_t f_pos;
	struct fown_struct___2 f_owner;
	const struct cred___2 *f_cred;
	struct file_ra_state f_ra;
	u64 f_version;
	void *f_security;
	void *private_data;
	struct list_head f_ep_links;
	struct list_head f_tfile_llink;
	struct address_space___2 *f_mapping;
	errseq_t f_wb_err;
};

struct vm_fault___2;

struct vm_operations_struct___2 {
	void (*open)(struct vm_area_struct___2 *);
	void (*close)(struct vm_area_struct___2 *);
	int (*split)(struct vm_area_struct___2 *, long unsigned int);
	int (*mremap)(struct vm_area_struct___2 *);
	vm_fault_t (*fault)(struct vm_fault___2 *);
	vm_fault_t (*huge_fault)(struct vm_fault___2 *, enum page_entry_size);
	void (*map_pages)(struct vm_fault___2 *, long unsigned int, long unsigned int);
	long unsigned int (*pagesize)(struct vm_area_struct___2 *);
	vm_fault_t (*page_mkwrite)(struct vm_fault___2 *);
	vm_fault_t (*pfn_mkwrite)(struct vm_fault___2 *);
	int (*access)(struct vm_area_struct___2 *, long unsigned int, void *, int, int);
	const char * (*name)(struct vm_area_struct___2 *);
	int (*set_policy)(struct vm_area_struct___2 *, struct mempolicy *);
	struct mempolicy * (*get_policy)(struct vm_area_struct___2 *, long unsigned int);
	struct page___2 * (*find_special_page)(struct vm_area_struct___2 *, long unsigned int);
	union {
		int (*mprotect)(struct vm_area_struct___2 *, long unsigned int, long unsigned int, long unsigned int);
		struct {
			long unsigned int rh_reserved1;
		} rh_kabi_hidden_573;
		union {		};
	};
	long unsigned int rh_reserved2;
	long unsigned int rh_reserved3;
	long unsigned int rh_reserved4;
};

struct core_thread___2 {
	struct task_struct___2 *task;
	struct core_thread___2 *next;
};

struct core_state___2 {
	atomic_t nr_threads;
	struct core_thread___2 dumper;
	struct completion___2 startup;
};

struct vm_fault___2 {
	struct vm_area_struct___2 *vma;
	unsigned int flags;
	gfp_t gfp_mask;
	long unsigned int pgoff;
	long unsigned int address;
	pmd_t *pmd;
	pud_t *pud;
	pte_t orig_pte;
	struct page___2 *cow_page;
	struct mem_cgroup *rh_reserved_memcg;
	struct page___2 *page;
	pte_t *pte;
	spinlock_t___2 *ptl;
	pgtable_t prealloc_pte;
};

struct pglist_data___2;

struct lruvec___2 {
	struct list_head lists[5];
	union {
		struct {
			long unsigned int anon_cost;
			long unsigned int file_cost;
			long unsigned int refaults[2];
		};
		struct {
			struct zone_reclaim_stat reclaim_stat;
		} rh_kabi_hidden_339;
		union {		};
	};
	atomic_long_t nonresident_age;
	union {
		long unsigned int flags;
		struct {
			long unsigned int refaults;
		} rh_kabi_hidden_346;
		union {		};
	};
	struct pglist_data___2 *pgdat;
	spinlock_t___2 lru_lock;
};

struct zone___2 {
	long unsigned int _watermark[3];
	long unsigned int nr_reserved_highatomic;
	long int lowmem_reserve[5];
	int node;
	struct pglist_data___2 *zone_pgdat;
	struct per_cpu_pageset *pageset;
	long unsigned int zone_start_pfn;
	union {
		atomic_long_t managed_pages;
		struct {
			long unsigned int managed_pages;
		} rh_kabi_hidden_576;
		union {		};
	};
	long unsigned int spanned_pages;
	long unsigned int present_pages;
	const char *name;
	long unsigned int nr_isolate_pageblock;
	seqlock_t___2 span_seqlock;
	int initialized;
	long unsigned int watermark_boost;
	int pageset_high;
	int pageset_batch;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	struct zone_padding _pad1_;
	struct free_area free_area[9];
	long unsigned int flags;
	spinlock_t___2 lock;
	long: 32;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	struct zone_padding _pad2_;
	long unsigned int percpu_drift_mark;
	long unsigned int compact_cached_free_pfn;
	long unsigned int compact_cached_migrate_pfn[2];
	unsigned int compact_considered;
	unsigned int compact_defer_shift;
	int compact_order_failed;
	bool compact_blockskip_flush;
	bool contiguous;
	long: 16;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	struct zone_padding _pad3_;
	union {
		long unsigned int compact_init_migrate_pfn;
		struct {
			long unsigned int rh_reserved1;
		} rh_kabi_hidden_666;
		union {		};
	};
	union {
		long unsigned int compact_init_free_pfn;
		struct {
			long unsigned int rh_reserved2;
		} rh_kabi_hidden_667;
		union {		};
	};
	atomic_long_t vm_stat[11];
	atomic_long_t vm_numa_stat[6];
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
};

struct zoneref___2 {
	struct zone___2 *zone;
	int zone_idx;
};

struct zonelist___2 {
	struct zoneref___2 _zonerefs[1281];
};

struct deferred_split___2 {
	spinlock_t___2 split_queue_lock;
	struct list_head split_queue;
	long unsigned int split_queue_len;
};

struct pglist_data___2 {
	struct zone___2 node_zones[5];
	struct zonelist___2 node_zonelists[2];
	int nr_zones;
	spinlock_t___2 node_size_lock;
	long unsigned int node_start_pfn;
	long unsigned int node_present_pages;
	long unsigned int node_spanned_pages;
	int node_id;
	wait_queue_head_t___2 kswapd_wait;
	wait_queue_head_t___2 pfmemalloc_wait;
	struct task_struct___2 *kswapd;
	int kswapd_order;
	enum zone_type kswapd_highest_zoneidx;
	int kswapd_failures;
	int kcompactd_max_order;
	enum zone_type kcompactd_highest_zoneidx;
	wait_queue_head_t___2 kcompactd_wait;
	struct task_struct___2 *kcompactd;
	spinlock_t___2 rh_reserved_numabalancing_migrate_lock;
	long unsigned int rh_reserved_numabalancing_migrate_next_window;
	long unsigned int rh_reserved_numabalancing_migrate_nr_pages;
	long unsigned int totalreserve_pages;
	long unsigned int min_unmapped_pages;
	long unsigned int min_slab_pages;
	long: 64;
	long: 64;
	long: 64;
	struct zone_padding _pad1_;
	spinlock_t___2 rh_reserved_lru_lock;
	struct deferred_split___2 deferred_split_queue;
	struct lruvec___2 __lruvec;
	long unsigned int flags;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	struct zone_padding _pad2_;
	union {
		atomic_t nr_writeback_throttled;
		struct {
			long unsigned int rh_reserved1;
		} rh_kabi_hidden_920;
		union {		};
	};
	union {
		long unsigned int nr_reclaim_start;
		struct {
			long unsigned int rh_reserved2;
		} rh_kabi_hidden_921;
		union {		};
	};
	wait_queue_head_t___2 reclaim_wait[4];
	struct per_cpu_nodestat *per_cpu_nodestats;
	atomic_long_t vm_stat[40];
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
};

typedef struct pglist_data___2 pg_data_t___2;

struct hrtimer_cpu_base___2;

struct hrtimer_clock_base___2 {
	struct hrtimer_cpu_base___2 *cpu_base;
	unsigned int index;
	clockid_t clockid;
	union {
		seqcount_raw_spinlock_t seq;
		struct {
			seqcount_t seq;
		} rh_kabi_hidden_180;
		union {		};
	};
	struct hrtimer___2 *running;
	struct timerqueue_head active;
	ktime_t (*get_time)();
	ktime_t offset;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
};

struct hrtimer_cpu_base___2 {
	raw_spinlock_t___2 lock;
	unsigned int cpu;
	unsigned int active_bases;
	unsigned int clock_was_set_seq;
	unsigned int hres_active: 1;
	unsigned int in_hrtirq: 1;
	unsigned int hang_detected: 1;
	unsigned int softirq_activated: 1;
	unsigned int nr_events;
	short unsigned int nr_retries;
	short unsigned int nr_hangs;
	unsigned int max_hang_time;
	ktime_t expires_next;
	struct hrtimer___2 *next_timer;
	ktime_t softirq_expires_next;
	struct hrtimer___2 *softirq_next_timer;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	struct hrtimer_clock_base___2 clock_base[8];
};

struct key___2;

struct user_struct___2 {
	union {
		refcount_t __count;
		struct {
			atomic_t __count;
		} rh_kabi_hidden_18;
		union {		};
	};
	atomic_t processes;
	atomic_t sigpending;
	atomic_t fanotify_listeners;
	atomic_long_t epoll_watches;
	long unsigned int mq_bytes;
	long unsigned int locked_shm;
	long unsigned int unix_inflight;
	atomic_long_t pipe_bufs;
	struct key___2 *uid_keyring;
	struct key___2 *session_keyring;
	struct hlist_node uidhash_node;
	kuid_t uid;
	atomic_long_t locked_vm;
	struct ratelimit_state___2 ratelimit;
	long unsigned int rh_reserved1;
	long unsigned int rh_reserved2;
};

struct signal_struct___2 {
	union {
		refcount_t sigcnt;
		struct {
			atomic_t sigcnt;
		} rh_kabi_hidden_86;
		union {		};
	};
	atomic_t live;
	int nr_threads;
	struct list_head thread_head;
	wait_queue_head_t___2 wait_chldexit;
	struct task_struct___2 *curr_target;
	struct sigpending shared_pending;
	int group_exit_code;
	int notify_count;
	struct task_struct___2 *group_exit_task;
	int group_stop_count;
	unsigned int flags;
	unsigned int is_child_subreaper: 1;
	unsigned int has_child_subreaper: 1;
	int posix_timer_id;
	struct list_head posix_timers;
	struct hrtimer___2 real_timer;
	ktime_t it_real_incr;
	struct cpu_itimer it[2];
	struct thread_group_cputimer cputimer;
	struct task_cputime rh_reserved_cputime_expires;
	struct list_head rh_reserved_cpu_timers[3];
	struct pid *rh_reserved_leader_pid;
	atomic_t tick_dep_mask;
	struct pid *tty_old_pgrp;
	int leader;
	struct tty_struct *tty;
	struct autogroup *autogroup;
	seqlock_t___2 stats_lock;
	u64 utime;
	u64 stime;
	u64 cutime;
	u64 cstime;
	u64 gtime;
	u64 cgtime;
	struct prev_cputime___2 prev_cputime;
	long unsigned int nvcsw;
	long unsigned int nivcsw;
	long unsigned int cnvcsw;
	long unsigned int cnivcsw;
	long unsigned int min_flt;
	long unsigned int maj_flt;
	long unsigned int cmin_flt;
	long unsigned int cmaj_flt;
	long unsigned int inblock;
	long unsigned int oublock;
	long unsigned int cinblock;
	long unsigned int coublock;
	long unsigned int maxrss;
	long unsigned int cmaxrss;
	struct task_io_accounting ioac;
	long long unsigned int sum_sched_runtime;
	struct rlimit rlim[16];
	struct pacct_struct pacct;
	struct taskstats *stats;
	unsigned int audit_tty;
	struct tty_audit_buf *tty_audit_buf;
	bool oom_flag_origin;
	short int oom_score_adj;
	short int oom_score_adj_min;
	struct mm_struct___2 *oom_mm;
	struct mutex___2 cred_guard_mutex;
	struct pid *pids[4];
	union {
		struct hlist_head multiprocess;
		struct {
			long unsigned int rh_reserved1;
		} rh_kabi_hidden_243;
		union {		};
	};
	long unsigned int rh_reserved2;
	long unsigned int rh_reserved3;
	long unsigned int rh_reserved4;
	struct posix_cputimers posix_cputimers;
	struct rw_semaphore___3 exec_update_lock;
};

struct task_struct_rh___2 {
	struct posix_cputimers posix_cputimers;
	unsigned int rh_reserved_vtime_cpu;
	u64 parent_exec_id;
	u64 self_exec_id;
	struct capture_control *capture_control;
	struct task_struct___2 *task_struct;
	int trc_reader_nesting;
	int trc_ipi_to_cpu;
	union rcu_special trc_reader_special;
	bool trc_reader_checked;
	struct list_head trc_holdout_list;
	struct kunit *kunit_test;
	struct timer_list oom_reaper_timer;
};

struct cred___2 {
	atomic_t usage;
	kuid_t uid;
	kgid_t gid;
	kuid_t suid;
	kgid_t sgid;
	kuid_t euid;
	kgid_t egid;
	kuid_t fsuid;
	kgid_t fsgid;
	unsigned int securebits;
	kernel_cap_t cap_inheritable;
	kernel_cap_t cap_permitted;
	kernel_cap_t cap_effective;
	kernel_cap_t cap_bset;
	kernel_cap_t cap_ambient;
	unsigned char jit_keyring;
	struct key___2 *session_keyring;
	struct key___2 *process_keyring;
	struct key___2 *thread_keyring;
	struct key___2 *request_key_auth;
	void *security;
	struct user_struct___2 *user;
	struct user_namespace *user_ns;
	struct group_info *group_info;
	struct callback_head rcu;
};

struct sighand_struct___2 {
	union {
		refcount_t count;
		struct {
			atomic_t count;
		} rh_kabi_hidden_22;
		union {		};
	};
	struct k_sigaction action[64];
	spinlock_t___2 siglock;
	wait_queue_head_t___2 signalfd_wqh;
};

struct io_cq___2;

struct io_context___2 {
	atomic_long_t refcount;
	atomic_t active_ref;
	atomic_t nr_tasks;
	spinlock_t___2 lock;
	short unsigned int ioprio;
	int nr_batch_requests;
	long unsigned int last_waited;
	struct xarray___2 icq_tree;
	struct io_cq___2 *icq_hint;
	struct hlist_head icq_list;
	struct work_struct release_work;
};

union thread_union___2 {
	struct task_struct___2 task;
	struct thread_info___2 thread_info;
	long unsigned int stack[2048];
};

struct xa_node___2 {
	unsigned char shift;
	unsigned char offset;
	unsigned char count;
	unsigned char nr_values;
	struct xa_node___2 *parent;
	struct xarray___2 *array;
	union {
		struct list_head private_list;
		struct callback_head callback_head;
	};
	void *slots[64];
	union {
		long unsigned int tags[3];
		long unsigned int marks[3];
	};
};

struct radix_tree_preload___2 {
	local_lock_t lock;
	unsigned int nr;
	struct xa_node___2 *nodes;
};

struct idr___2 {
	struct xarray___2 idr_rt;
	unsigned int idr_base;
	unsigned int idr_next;
};

struct kernfs_root___2;

struct kernfs_elem_dir___2 {
	long unsigned int subdirs;
	struct rb_root children;
	struct kernfs_root___2 *root;
	long unsigned int rev;
};

struct kernfs_syscall_ops___2;

struct kernfs_root___2 {
	struct kernfs_node___2 *kn;
	unsigned int flags;
	struct idr___2 ino_idr;
	u32 id_highbits;
	u32 last_id_lowbits;
	struct kernfs_syscall_ops___2 *syscall_ops;
	struct list_head supers;
	wait_queue_head_t___2 deactivate_waitq;
	struct rw_semaphore___3 kernfs_rwsem;
	struct rw_semaphore___3 kernfs_iattr_rwsem;
	struct rw_semaphore___3 kernfs_supers_rwsem;
};

struct kernfs_elem_symlink___2 {
	struct kernfs_node___2 *target_kn;
};

struct kernfs_ops___2;

struct kernfs_elem_attr___2 {
	const struct kernfs_ops___2 *ops;
	struct kernfs_open_node *open;
	loff_t size;
	struct kernfs_node___2 *notify_next;
};

struct kernfs_node___2 {
	atomic_t count;
	atomic_t active;
	struct kernfs_node___2 *parent;
	const char *name;
	struct rb_node rb;
	const void *ns;
	unsigned int hash;
	union {
		struct kernfs_elem_dir___2 dir;
		struct kernfs_elem_symlink___2 symlink;
		struct kernfs_elem_attr___2 attr;
	};
	void *priv;
	union {
		u64 id;
		struct {
			union kernfs_node_id id;
		} rh_kabi_hidden_173;
		union {		};
	};
	short unsigned int flags;
	umode_t mode;
	struct kernfs_iattrs *iattr;
};

struct kernfs_open_file___2;

struct kernfs_ops___2 {
	int (*open)(struct kernfs_open_file___2 *);
	void (*release)(struct kernfs_open_file___2 *);
	int (*seq_show)(struct seq_file *, void *);
	void * (*seq_start)(struct seq_file *, loff_t *);
	void * (*seq_next)(struct seq_file *, void *, loff_t *);
	void (*seq_stop)(struct seq_file *, void *);
	ssize_t (*read)(struct kernfs_open_file___2 *, char *, size_t, loff_t);
	size_t atomic_write_len;
	bool prealloc;
	ssize_t (*write)(struct kernfs_open_file___2 *, char *, size_t, loff_t);
	int (*mmap)(struct kernfs_open_file___2 *, struct vm_area_struct___2 *);
	union {
		__poll_t (*poll)(struct kernfs_open_file___2 *, struct poll_table_struct *);
		struct {
			long unsigned int rh_reserved1;
		} rh_kabi_hidden_299;
		union {		};
	};
	long unsigned int rh_reserved2;
};

struct kernfs_syscall_ops___2 {
	int (*rh_reserved_remount_fs)(struct kernfs_root___2 *, int *, char *);
	int (*show_options)(struct seq_file *, struct kernfs_root___2 *);
	int (*mkdir)(struct kernfs_node___2 *, const char *, umode_t);
	int (*rmdir)(struct kernfs_node___2 *);
	int (*rename)(struct kernfs_node___2 *, struct kernfs_node___2 *, const char *);
	int (*show_path)(struct seq_file *, struct kernfs_node___2 *, struct kernfs_root___2 *);
	long unsigned int rh_reserved1;
	long unsigned int rh_reserved2;
	long unsigned int rh_reserved3;
	long unsigned int rh_reserved4;
};

struct kernfs_open_file___2 {
	struct kernfs_node___2 *kn;
	struct file___2 *file;
	struct seq_file *seq_file;
	void *priv;
	struct mutex___2 mutex;
	struct mutex___2 prealloc_mutex;
	int event;
	struct list_head list;
	char *prealloc_buf;
	size_t atomic_write_len;
	bool mmapped: 1;
	bool released: 1;
	const struct vm_operations_struct___2 *vm_ops;
};

struct bin_attribute___2;

struct attribute_group___2 {
	const char *name;
	umode_t (*is_visible)(struct kobject___2 *, struct attribute *, int);
	umode_t (*is_bin_visible)(struct kobject___2 *, struct bin_attribute___2 *, int);
	struct attribute **attrs;
	struct bin_attribute___2 **bin_attrs;
};

struct bin_attribute___2 {
	struct attribute attr;
	size_t size;
	void *private;
	ssize_t (*read)(struct file___2 *, struct kobject___2 *, struct bin_attribute___2 *, char *, loff_t, size_t);
	ssize_t (*write)(struct file___2 *, struct kobject___2 *, struct bin_attribute___2 *, char *, loff_t, size_t);
	int (*mmap)(struct file___2 *, struct kobject___2 *, struct bin_attribute___2 *, struct vm_area_struct___2 *);
};

struct sysfs_ops___2 {
	ssize_t (*show)(struct kobject___2 *, struct attribute *, char *);
	ssize_t (*store)(struct kobject___2 *, struct attribute *, const char *, size_t);
};

struct kset_uevent_ops___2;

struct kset___2 {
	struct list_head list;
	spinlock_t___2 list_lock;
	struct kobject___2 kobj;
	const struct kset_uevent_ops___2 *uevent_ops;
	long unsigned int rh_reserved1;
	long unsigned int rh_reserved2;
	long unsigned int rh_reserved3;
	long unsigned int rh_reserved4;
};

struct kobj_type___2 {
	void (*release)(struct kobject___2 *);
	const struct sysfs_ops___2 *sysfs_ops;
	struct attribute **default_attrs;
	const struct kobj_ns_type_operations * (*child_ns_type)(const struct kobject___2 *);
	const void * (*namespace)(const struct kobject___2 *);
	union {
		const struct attribute_group___2 **default_groups;
		struct {
			long unsigned int rh_reserved1;
		} rh_kabi_hidden_133;
		union {		};
	};
	union {
		void (*get_ownership)(const struct kobject___2 *, kuid_t *, kgid_t *);
		struct {
			long unsigned int rh_reserved2;
		} rh_kabi_hidden_134;
		union {		};
	};
	long unsigned int rh_reserved3;
	long unsigned int rh_reserved4;
};

struct kset_uevent_ops___2 {
	int (* const filter)(struct kset___2 *, const struct kobject___2 *);
	const char * (* const name)(struct kset___2 *, const struct kobject___2 *);
	int (* const uevent)(struct kset___2 *, struct kobject___2 *, struct kobj_uevent_env *);
};

struct kobj_attribute___2 {
	struct attribute attr;
	ssize_t (*show)(struct kobject___2 *, struct kobj_attribute___2 *, char *);
	ssize_t (*store)(struct kobject___2 *, struct kobj_attribute___2 *, const char *, size_t);
};

struct dev_pm_ops___2 {
	int (*prepare)(struct device___2 *);
	void (*complete)(struct device___2 *);
	int (*suspend)(struct device___2 *);
	int (*resume)(struct device___2 *);
	int (*freeze)(struct device___2 *);
	int (*thaw)(struct device___2 *);
	int (*poweroff)(struct device___2 *);
	int (*restore)(struct device___2 *);
	int (*suspend_late)(struct device___2 *);
	int (*resume_early)(struct device___2 *);
	int (*freeze_late)(struct device___2 *);
	int (*thaw_early)(struct device___2 *);
	int (*poweroff_late)(struct device___2 *);
	int (*restore_early)(struct device___2 *);
	int (*suspend_noirq)(struct device___2 *);
	int (*resume_noirq)(struct device___2 *);
	int (*freeze_noirq)(struct device___2 *);
	int (*thaw_noirq)(struct device___2 *);
	int (*poweroff_noirq)(struct device___2 *);
	int (*restore_noirq)(struct device___2 *);
	int (*runtime_suspend)(struct device___2 *);
	int (*runtime_resume)(struct device___2 *);
	int (*runtime_idle)(struct device___2 *);
};

struct wakeup_source___2;

struct pm_subsys_data___2;

struct dev_pm_info___2 {
	pm_message_t power_state;
	unsigned int can_wakeup: 1;
	unsigned int async_suspend: 1;
	bool in_dpm_list: 1;
	bool is_prepared: 1;
	bool is_suspended: 1;
	bool is_noirq_suspended: 1;
	bool is_late_suspended: 1;
	bool early_init: 1;
	bool direct_complete: 1;
	bool no_pm: 1;
	u32 driver_flags;
	spinlock_t___2 lock;
	struct list_head entry;
	struct completion___2 completion;
	struct wakeup_source___2 *wakeup;
	bool wakeup_path: 1;
	bool syscore: 1;
	bool no_pm_callbacks: 1;
	unsigned int must_resume: 1;
	unsigned int may_skip_resume: 1;
	struct timer_list suspend_timer;
	long unsigned int timer_expires;
	struct work_struct work;
	wait_queue_head_t___2 wait_queue;
	struct wake_irq *wakeirq;
	atomic_t usage_count;
	atomic_t child_count;
	unsigned int disable_depth: 3;
	unsigned int idle_notification: 1;
	unsigned int request_pending: 1;
	unsigned int deferred_resume: 1;
	unsigned int runtime_auto: 1;
	bool ignore_children: 1;
	unsigned int no_callbacks: 1;
	unsigned int irq_safe: 1;
	unsigned int use_autosuspend: 1;
	unsigned int timer_autosuspends: 1;
	unsigned int memalloc_noio: 1;
	unsigned int links_count;
	enum rpm_request request;
	enum rpm_status runtime_status;
	int runtime_error;
	int autosuspend_delay;
	long unsigned int last_busy;
	long unsigned int active_jiffies;
	long unsigned int suspended_jiffies;
	long unsigned int accounting_timestamp;
	struct pm_subsys_data___2 *subsys_data;
	void (*set_latency_tolerance)(struct device___2 *, s32);
	struct dev_pm_qos *qos;
};

struct device_type___2;

struct bus_type___2;

struct device_driver___2;

struct dev_pm_domain___2;

struct device_node___2;

struct fwnode_handle___2;

struct class___2;

struct device___2 {
	struct device___2 *parent;
	struct device_private *p;
	struct kobject___2 kobj;
	const char *init_name;
	const struct device_type___2 *type;
	struct mutex___2 mutex;
	struct bus_type___2 *bus;
	struct device_driver___2 *driver;
	void *platform_data;
	void *driver_data;
	struct dev_links_info links;
	struct dev_pm_info___2 power;
	struct dev_pm_domain___2 *pm_domain;
	struct list_head msi_list;
	int numa_node;
	const struct dma_map_ops *dma_ops;
	u64 *dma_mask;
	u64 coherent_dma_mask;
	u64 bus_dma_limit;
	union {
		const struct bus_dma_region *dma_range_map;
		struct {
			long unsigned int dma_pfn_offset;
		} rh_kabi_hidden_1356;
		union {		};
	};
	struct device_dma_parameters *dma_parms;
	struct list_head dma_pools;
	struct dma_coherent_mem *dma_mem;
	struct dev_archdata archdata;
	struct device_node___2 *of_node;
	struct fwnode_handle___2 *fwnode;
	dev_t devt;
	u32 id;
	spinlock_t___2 devres_lock;
	struct list_head devres_head;
	struct klist_node knode_class;
	struct class___2 *class;
	const struct attribute_group___2 **groups;
	void (*release)(struct device___2 *);
	struct iommu_group *iommu_group;
	struct iommu_fwspec *rh_reserved_iommu_fwspec;
	bool offline_disabled: 1;
	bool offline: 1;
	bool of_node_reused: 1;
	bool state_synced: 1;
	bool can_match: 1;
	bool dma_ops_bypass: 1;
	union {
		struct dev_iommu *iommu;
		struct {
			long unsigned int rh_reserved1;
		} rh_kabi_hidden_1404;
		union {		};
	};
	union {
		struct io_tlb_mem *dma_io_tlb_mem;
		struct {
			long unsigned int rh_reserved2;
		} rh_kabi_hidden_1406;
		union {		};
	};
	union {
		struct device_physical_location *physical_location;
		struct {
			long unsigned int rh_reserved3;
		} rh_kabi_hidden_1412;
		union {		};
	};
	long unsigned int rh_reserved4;
	long unsigned int rh_reserved5;
	union {
		struct list_head links_defer_sync;
		struct {
			long unsigned int rh_reserved6;
			long unsigned int rh_reserved7;
		} rh_kabi_hidden_1415;
		union {		};
	};
	union {
		enum device_removable removable;
		struct {
			long unsigned int rh_reserved8;
		} rh_kabi_hidden_1417;
		union {		};
	};
	union {
		raw_spinlock_t___2 msi_lock;
		struct {
			long unsigned int rh_reserved9;
		} rh_kabi_hidden_1418;
		union {		};
	};
	long unsigned int rh_reserved10;
	long unsigned int rh_reserved11;
	long unsigned int rh_reserved12;
	long unsigned int rh_reserved13;
	long unsigned int rh_reserved14;
	long unsigned int rh_reserved15;
	long unsigned int rh_reserved16;
	size_t device_extended_size_rh;
	struct device_extended_rh *_rh;
};

struct pm_subsys_data___2 {
	spinlock_t___2 lock;
	unsigned int refcount;
	struct pm_domain_data *domain_data;
};

struct wakeup_source___2 {
	const char *name;
	struct list_head entry;
	spinlock_t___2 lock;
	struct wake_irq *wakeirq;
	struct timer_list timer;
	long unsigned int timer_expires;
	ktime_t total_time;
	ktime_t max_time;
	ktime_t last_time;
	ktime_t start_prevent_time;
	ktime_t prevent_sleep_time;
	long unsigned int event_count;
	long unsigned int active_count;
	long unsigned int relax_count;
	long unsigned int expire_count;
	long unsigned int wakeup_count;
	bool active: 1;
	bool autosleep_enabled: 1;
	int id;
	struct device___2 *dev;
};

struct dev_pm_domain___2 {
	struct dev_pm_ops___2 ops;
	void (*detach)(struct device___2 *, bool);
	int (*activate)(struct device___2 *);
	void (*sync)(struct device___2 *);
	void (*dismiss)(struct device___2 *);
};

struct bus_type___2 {
	const char *name;
	const char *dev_name;
	struct device___2 *dev_root;
	const struct attribute_group___2 **bus_groups;
	const struct attribute_group___2 **dev_groups;
	const struct attribute_group___2 **drv_groups;
	int (*match)(struct device___2 *, struct device_driver___2 *);
	int (*uevent)(struct device___2 *, struct kobj_uevent_env *);
	int (*probe)(struct device___2 *);
	int (*remove)(struct device___2 *);
	void (*shutdown)(struct device___2 *);
	int (*online)(struct device___2 *);
	int (*offline)(struct device___2 *);
	int (*suspend)(struct device___2 *, pm_message_t);
	int (*resume)(struct device___2 *);
	int (*num_vf)(struct device___2 *);
	int (*dma_configure)(struct device___2 *);
	const struct dev_pm_ops___2 *pm;
	const struct iommu_ops *iommu_ops;
	struct subsys_private *p;
	struct lock_class_key rh_reserved_lock_key;
	bool need_parent_lock;
	void (*sync_state)(struct device___2 *);
	void (*dma_cleanup)(struct device___2 *);
};

struct device_driver___2 {
	const char *name;
	struct bus_type___2 *bus;
	struct module *owner;
	const char *mod_name;
	bool suppress_bind_attrs;
	enum probe_type probe_type;
	const struct of_device_id *of_match_table;
	const struct acpi_device_id *acpi_match_table;
	int (*probe)(struct device___2 *);
	int (*remove)(struct device___2 *);
	void (*shutdown)(struct device___2 *);
	int (*suspend)(struct device___2 *, pm_message_t);
	int (*resume)(struct device___2 *);
	const struct attribute_group___2 **groups;
	const struct dev_pm_ops___2 *pm;
	void (*coredump)(struct device___2 *);
	struct driver_private *p;
	union {
		const struct attribute_group___2 **dev_groups;
		struct {
			long unsigned int rh_reserved1;
		} rh_kabi_hidden_408;
		union {		};
	};
	union {
		void (*sync_state)(struct device___2 *);
		struct {
			long unsigned int rh_reserved2;
		} rh_kabi_hidden_409;
		union {		};
	};
	long unsigned int rh_reserved3;
	long unsigned int rh_reserved4;
	size_t device_driver_size_rh;
	struct device_driver_rh *_rh;
};

struct class___2 {
	const char *name;
	struct module *owner;
	const struct attribute_group___2 **class_groups;
	const struct attribute_group___2 **dev_groups;
	struct kobject___2 *dev_kobj;
	int (*dev_uevent)(const struct device___2 *, struct kobj_uevent_env *);
	char * (*devnode)(const struct device___2 *, umode_t *);
	void (*class_release)(struct class___2 *);
	void (*dev_release)(struct device___2 *);
	int (*shutdown_pre)(struct device___2 *);
	const struct kobj_ns_type_operations *ns_type;
	const void * (*namespace)(const struct device___2 *);
	const struct dev_pm_ops___2 *pm;
	struct subsys_private *p;
	union {
		void (*get_ownership)(const struct device___2 *, kuid_t *, kgid_t *);
		struct {
			long unsigned int rh_reserved1;
		} rh_kabi_hidden_619;
		union {		};
	};
	long unsigned int rh_reserved2;
	long unsigned int rh_reserved3;
	long unsigned int rh_reserved4;
	size_t class_size_rh;
	struct class_rh *_rh;
};

struct device_type___2 {
	const char *name;
	const struct attribute_group___2 **groups;
	int (*uevent)(struct device___2 *, struct kobj_uevent_env *);
	char * (*devnode)(const struct device___2 *, umode_t *, kuid_t *, kgid_t *);
	void (*release)(struct device___2 *);
	const struct dev_pm_ops___2 *pm;
};

struct fwnode_operations___2;

struct fwnode_handle___2 {
	struct fwnode_handle___2 *secondary;
	const struct fwnode_operations___2 *ops;
	struct device___2 *dev;
	struct list_head suppliers;
	struct list_head consumers;
	u8 flags;
};

struct property___2;

struct device_node___2 {
	const char *name;
	const char *type;
	phandle phandle;
	const char *full_name;
	struct fwnode_handle___2 fwnode;
	struct property___2 *properties;
	struct property___2 *deadprops;
	struct device_node___2 *parent;
	struct device_node___2 *child;
	struct device_node___2 *sibling;
	struct kobject___2 kobj;
	long unsigned int _flags;
	void *data;
};

struct fwnode_reference_args___2;

struct fwnode_endpoint___2;

struct fwnode_operations___2 {
	struct fwnode_handle___2 * (*get)(struct fwnode_handle___2 *);
	void (*put)(struct fwnode_handle___2 *);
	bool (*device_is_available)(const struct fwnode_handle___2 *);
	const void * (*device_get_match_data)(const struct fwnode_handle___2 *, const struct device___2 *);
	bool (*property_present)(const struct fwnode_handle___2 *, const char *);
	int (*property_read_int_array)(const struct fwnode_handle___2 *, const char *, unsigned int, void *, size_t);
	int (*property_read_string_array)(const struct fwnode_handle___2 *, const char *, const char **, size_t);
	struct fwnode_handle___2 * (*get_parent)(const struct fwnode_handle___2 *);
	struct fwnode_handle___2 * (*get_next_child_node)(const struct fwnode_handle___2 *, struct fwnode_handle___2 *);
	struct fwnode_handle___2 * (*get_named_child_node)(const struct fwnode_handle___2 *, const char *);
	int (*get_reference_args)(const struct fwnode_handle___2 *, const char *, const char *, unsigned int, unsigned int, struct fwnode_reference_args___2 *);
	struct fwnode_handle___2 * (*graph_get_next_endpoint)(const struct fwnode_handle___2 *, struct fwnode_handle___2 *);
	struct fwnode_handle___2 * (*graph_get_remote_endpoint)(const struct fwnode_handle___2 *);
	struct fwnode_handle___2 * (*graph_get_port_parent)(struct fwnode_handle___2 *);
	int (*graph_parse_endpoint)(const struct fwnode_handle___2 *, struct fwnode_endpoint___2 *);
	int (*add_links)(struct fwnode_handle___2 *, struct device___2 *);
	const char * (*get_name)(const struct fwnode_handle___2 *);
	const char * (*get_name_prefix)(const struct fwnode_handle___2 *);
	bool (*device_dma_supported)(const struct fwnode_handle___2 *);
	enum dev_dma_attr (*device_get_dma_attr)(const struct fwnode_handle___2 *);
	void * (*iomap)(struct fwnode_handle___2 *, int);
	int (*irq_get)(const struct fwnode_handle___2 *, unsigned int);
};

struct fwnode_endpoint___2 {
	unsigned int port;
	unsigned int id;
	const struct fwnode_handle___2 *local_fwnode;
};

struct fwnode_reference_args___2 {
	struct fwnode_handle___2 *fwnode;
	unsigned int nargs;
	unsigned int args[8];
};

struct property___2 {
	char *name;
	int length;
	void *value;
	struct property___2 *next;
	long unsigned int _flags;
	struct bin_attribute___2 attr;
};

struct irq_fwspec___2 {
	struct fwnode_handle___2 *fwnode;
	int param_count;
	u32 param[16];
};

struct irq_domain_ops___2 {
	int (*match)(struct irq_domain___2 *, struct device_node___2 *, enum irq_domain_bus_token);
	int (*select)(struct irq_domain___2 *, struct irq_fwspec___2 *, enum irq_domain_bus_token);
	int (*map)(struct irq_domain___2 *, unsigned int, irq_hw_number_t);
	void (*unmap)(struct irq_domain___2 *, unsigned int);
	int (*xlate)(struct irq_domain___2 *, struct device_node___2 *, const u32 *, unsigned int, long unsigned int *, unsigned int *);
};

struct irq_domain_chip_generic___2;

struct irq_domain___2 {
	struct list_head link;
	const char *name;
	const struct irq_domain_ops___2 *ops;
	void *host_data;
	unsigned int flags;
	unsigned int mapcount;
	struct fwnode_handle___2 *fwnode;
	enum irq_domain_bus_token bus_token;
	struct irq_domain_chip_generic___2 *gc;
	long unsigned int rh_reserved1;
	long unsigned int rh_reserved2;
	long unsigned int rh_reserved3;
	long unsigned int rh_reserved4;
	irq_hw_number_t hwirq_max;
	unsigned int revmap_direct_max_irq;
	unsigned int revmap_size;
	struct xarray___2 revmap_tree;
	struct mutex___2 revmap_tree_mutex;
	unsigned int linear_revmap[0];
};

struct irq_chip_generic___2;

struct irq_domain_chip_generic___2 {
	unsigned int irqs_per_chip;
	unsigned int num_chips;
	unsigned int irq_flags_to_clear;
	unsigned int irq_flags_to_set;
	enum irq_gc_flags gc_flags;
	struct irq_chip_generic___2 *gc[0];
};

struct irq_chip___2 {
	struct device___2 *parent_device;
	const char *name;
	unsigned int (*irq_startup)(struct irq_data___2 *);
	void (*irq_shutdown)(struct irq_data___2 *);
	void (*irq_enable)(struct irq_data___2 *);
	void (*irq_disable)(struct irq_data___2 *);
	void (*irq_ack)(struct irq_data___2 *);
	void (*irq_mask)(struct irq_data___2 *);
	void (*irq_mask_ack)(struct irq_data___2 *);
	void (*irq_unmask)(struct irq_data___2 *);
	void (*irq_eoi)(struct irq_data___2 *);
	int (*irq_set_affinity)(struct irq_data___2 *, const struct cpumask *, bool);
	int (*irq_retrigger)(struct irq_data___2 *);
	int (*irq_set_type)(struct irq_data___2 *, unsigned int);
	int (*irq_set_wake)(struct irq_data___2 *, unsigned int);
	void (*irq_bus_lock)(struct irq_data___2 *);
	void (*irq_bus_sync_unlock)(struct irq_data___2 *);
	void (*irq_cpu_online)(struct irq_data___2 *);
	void (*irq_cpu_offline)(struct irq_data___2 *);
	void (*irq_suspend)(struct irq_data___2 *);
	void (*irq_resume)(struct irq_data___2 *);
	void (*irq_pm_shutdown)(struct irq_data___2 *);
	void (*irq_calc_mask)(struct irq_data___2 *);
	void (*irq_print_chip)(struct irq_data___2 *, struct seq_file *);
	int (*irq_request_resources)(struct irq_data___2 *);
	void (*irq_release_resources)(struct irq_data___2 *);
	void (*irq_compose_msi_msg)(struct irq_data___2 *, struct msi_msg *);
	void (*irq_write_msi_msg)(struct irq_data___2 *, struct msi_msg *);
	int (*irq_get_irqchip_state)(struct irq_data___2 *, enum irqchip_irq_state, bool *);
	int (*irq_set_irqchip_state)(struct irq_data___2 *, enum irqchip_irq_state, bool);
	int (*irq_set_vcpu_affinity)(struct irq_data___2 *, void *);
	void (*ipi_send_single)(struct irq_data___2 *, unsigned int);
	void (*ipi_send_mask)(struct irq_data___2 *, const struct cpumask *);
	long unsigned int flags;
};

struct irq_chip_type___2 {
	struct irq_chip___2 chip;
	struct irq_chip_regs regs;
	irq_flow_handler_t___2 handler;
	u32 type;
	u32 mask_cache_priv;
	u32 *mask_cache;
};

struct irq_chip_generic___2 {
	raw_spinlock_t___2 lock;
	void *reg_base;
	u32 (*reg_readl)(void *);
	void (*reg_writel)(u32, void *);
	void (*suspend)(struct irq_chip_generic___2 *);
	void (*resume)(struct irq_chip_generic___2 *);
	unsigned int irq_base;
	unsigned int irq_cnt;
	u32 mask_cache;
	u32 type_cache;
	u32 polarity_cache;
	u32 wake_enabled;
	u32 wake_active;
	unsigned int num_ct;
	void *private;
	long unsigned int installed;
	long unsigned int unused;
	struct irq_domain___2 *domain;
	struct list_head list;
	struct irq_chip_type___2 chip_types[0];
};

struct mcs_spinlock {
	struct mcs_spinlock *next;
	int locked;
	int count;
};

struct qnode {
	struct mcs_spinlock mcs;
	long int reserved[2];
};

struct dev_pagemap_ops___2 {
	void (*page_free)(struct page___2 *);
	void (*kill)(struct dev_pagemap___2 *);
	void (*cleanup)(struct dev_pagemap___2 *);
	vm_fault_t (*migrate_to_ram)(struct vm_fault___2 *);
};

struct ppc64_tlb_batch___2 {
	int active;
	long unsigned int index;
	struct mm_struct___2 *mm;
	real_pte_t pte[192];
	long unsigned int vpn[192];
	unsigned int psize;
	int ssize;
};

struct lockref___2 {
	union {
		__u64 lock_count;
		struct {
			spinlock_t___2 lock;
			int count;
		};
	};
};

struct dentry_operations___2;

struct dentry___2 {
	unsigned int d_flags;
	seqcount_t d_seq;
	struct hlist_bl_node d_hash;
	struct dentry___2 *d_parent;
	struct qstr d_name;
	struct inode___2 *d_inode;
	unsigned char d_iname[32];
	struct lockref___2 d_lockref;
	const struct dentry_operations___2 *d_op;
	struct super_block___2 *d_sb;
	long unsigned int d_time;
	void *d_fsdata;
	union {
		struct list_head d_lru;
		wait_queue_head_t___2 *d_wait;
	};
	struct list_head d_child;
	struct list_head d_subdirs;
	union {
		struct hlist_node d_alias;
		struct hlist_bl_node d_in_lookup_hash;
		struct callback_head d_rcu;
	} d_u;
};

struct inode_operations___2;

struct file_lock_context___2;

struct block_device___2;

struct inode___2 {
	umode_t i_mode;
	short unsigned int i_opflags;
	kuid_t i_uid;
	kgid_t i_gid;
	unsigned int i_flags;
	struct posix_acl *i_acl;
	struct posix_acl *i_default_acl;
	const struct inode_operations___2 *i_op;
	struct super_block___2 *i_sb;
	struct address_space___2 *i_mapping;
	void *i_security;
	long unsigned int i_ino;
	union {
		const unsigned int i_nlink;
		unsigned int __i_nlink;
	};
	dev_t i_rdev;
	loff_t i_size;
	struct timespec64 i_atime;
	struct timespec64 i_mtime;
	struct timespec64 i_ctime;
	spinlock_t___2 i_lock;
	short unsigned int i_bytes;
	unsigned int i_blkbits;
	enum rw_hint i_write_hint;
	blkcnt_t i_blocks;
	long unsigned int i_state;
	struct rw_semaphore___3 i_rwsem;
	long unsigned int dirtied_when;
	long unsigned int dirtied_time_when;
	struct hlist_node i_hash;
	struct list_head i_io_list;
	struct bdi_writeback *i_wb;
	int i_wb_frn_winner;
	u16 i_wb_frn_avg_time;
	u16 i_wb_frn_history;
	struct list_head i_lru;
	struct list_head i_sb_list;
	struct list_head i_wb_list;
	union {
		struct hlist_head i_dentry;
		struct callback_head i_rcu;
	};
	atomic64_t i_version;
	atomic_t i_count;
	atomic_t i_dio_count;
	atomic_t i_writecount;
	atomic_t i_readcount;
	const struct file_operations___2 *i_fop;
	struct file_lock_context___2 *i_flctx;
	struct address_space___2 i_data;
	struct list_head i_devices;
	union {
		struct pipe_inode_info *i_pipe;
		struct block_device___2 *i_bdev;
		struct cdev *i_cdev;
		char *i_link;
		unsigned int i_dir_seq;
	};
	__u32 i_generation;
	__u32 i_fsnotify_mask;
	struct fsnotify_mark_connector *i_fsnotify_marks;
	void *i_private;
	union {
		atomic64_t i_sequence;
		struct {
			long unsigned int rh_reserved1;
		} rh_kabi_hidden_747;
		union {		};
	};
	long unsigned int rh_reserved2;
};

struct dentry_operations___2 {
	int (*d_revalidate)(struct dentry___2 *, unsigned int);
	int (*d_weak_revalidate)(struct dentry___2 *, unsigned int);
	int (*d_hash)(const struct dentry___2 *, struct qstr *);
	int (*d_compare)(const struct dentry___2 *, unsigned int, const char *, const struct qstr *);
	int (*d_delete)(const struct dentry___2 *);
	int (*d_init)(struct dentry___2 *);
	void (*d_release)(struct dentry___2 *);
	void (*d_prune)(struct dentry___2 *);
	void (*d_iput)(struct dentry___2 *, struct inode___2 *);
	char * (*d_dname)(struct dentry___2 *, char *, int);
	struct vfsmount * (*d_automount)(struct path___2 *);
	int (*d_manage)(const struct path___2 *, bool);
	struct dentry___2 * (*d_real)(struct dentry___2 *, const struct inode___2 *);
	long unsigned int rh_reserved1;
	long unsigned int rh_reserved2;
	long unsigned int rh_reserved3;
	long unsigned int rh_reserved4;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
};

struct quota_format_type___2;

struct mem_dqinfo___2 {
	struct quota_format_type___2 *dqi_format;
	int dqi_fmt_id;
	struct list_head dqi_dirty_list;
	long unsigned int dqi_flags;
	unsigned int dqi_bgrace;
	unsigned int dqi_igrace;
	qsize_t dqi_max_spc_limit;
	qsize_t dqi_max_ino_limit;
	void *dqi_priv;
};

struct quota_format_ops___2;

struct quota_info___2 {
	unsigned int flags;
	struct rw_semaphore___3 dqio_sem;
	struct inode___2 *files[3];
	struct mem_dqinfo___2 info[3];
	const struct quota_format_ops___2 *ops[3];
};

struct rcu_sync___2 {
	int gp_state;
	int gp_count;
	wait_queue_head_t___2 gp_wait;
	int rh_reserved_cb_state;
	struct callback_head cb_head;
	enum rcu_sync_type rh_reserved_gp_type;
};

struct rcuwait___2 {
	struct task_struct___2 *task;
};

struct percpu_rw_semaphore___2 {
	struct rcu_sync___2 rss;
	unsigned int *read_count;
	union {
		wait_queue_head_t___2 waiters;
		struct {
			struct rw_semaphore___3 rw_sem;
		} rh_kabi_hidden_18;
		union {		};
	};
	struct rcuwait___2 writer;
	union {
		atomic_t block;
		struct {
			int readers_block;
		} rh_kabi_hidden_21;
		union {		};
	};
};

struct sb_writers___2 {
	int frozen;
	wait_queue_head_t___2 wait_unfrozen;
	struct percpu_rw_semaphore___2 rw_sem[3];
};

struct list_lru_node___2;

struct list_lru___2 {
	struct list_lru_node___2 *node;
	struct list_head list;
	int shrinker_id;
	bool memcg_aware;
};

struct super_operations___2;

struct dquot_operations___2;

struct quotactl_ops___2;

struct super_block___2 {
	struct list_head s_list;
	dev_t s_dev;
	unsigned char s_blocksize_bits;
	long unsigned int s_blocksize;
	loff_t s_maxbytes;
	struct file_system_type___3 *s_type;
	const struct super_operations___2 *s_op;
	const struct dquot_operations___2 *dq_op;
	const struct quotactl_ops___2 *s_qcop;
	const struct export_operations *s_export_op;
	long unsigned int s_flags;
	long unsigned int s_iflags;
	long unsigned int s_magic;
	struct dentry___2 *s_root;
	struct rw_semaphore___3 s_umount;
	int s_count;
	atomic_t s_active;
	void *s_security;
	const struct xattr_handler **s_xattr;
	struct hlist_bl_head s_roots;
	struct list_head s_mounts;
	struct block_device___2 *s_bdev;
	struct backing_dev_info *s_bdi;
	struct mtd_info *s_mtd;
	struct hlist_node s_instances;
	unsigned int s_quota_types;
	struct quota_info___2 s_dquot;
	struct sb_writers___2 s_writers;
	char s_id[32];
	uuid_t s_uuid;
	void *s_fs_info;
	unsigned int s_max_links;
	fmode_t s_mode;
	u32 s_time_gran;
	union {
		struct {
			__u32 s_fsnotify_mask;
			struct fsnotify_mark_connector *s_fsnotify_marks;
		};
		struct {
			struct mutex___2 s_vfs_rename_mutex;
		} rh_kabi_hidden_1495;
		union {		};
	};
	const char *s_subtype;
	const struct dentry_operations___2 *s_d_op;
	int cleancache_poolid;
	struct shrinker s_shrink;
	atomic_long_t s_remove_count;
	atomic_long_t s_fsnotify_inode_refs;
	int s_readonly_remount;
	struct workqueue_struct *s_dio_done_wq;
	struct hlist_head s_pins;
	struct user_namespace *s_user_ns;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	struct list_lru___2 s_dentry_lru;
	struct list_lru___2 s_inode_lru;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long int rh_reserve_1;
	long int rh_reserve_2;
	long int rh_reserve_3;
	struct callback_head rcu;
	struct work_struct destroy_work;
	struct mutex___2 s_sync_lock;
	int s_stack_depth;
	long: 32;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	spinlock_t___2 s_inode_list_lock;
	struct list_head s_inodes;
	spinlock_t___2 s_inode_wblist_lock;
	struct list_head s_inodes_wb;
	time64_t s_time_min;
	time64_t s_time_max;
	struct mutex___2 s_vfs_rename_mutex;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
};

struct list_lru_node___2 {
	spinlock_t___2 lock;
	struct list_lru_one lru;
	struct list_lru_memcg *memcg_lrus;
	long int nr_items;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
};

struct ctl_table___2;

typedef int proc_handler___2(struct ctl_table___2 *, int, void *, size_t *, loff_t *);

struct ctl_table_poll___2;

struct ctl_table___2 {
	const char *procname;
	void *data;
	int maxlen;
	umode_t mode;
	struct ctl_table___2 *child;
	proc_handler___2 *proc_handler;
	struct ctl_table_poll___2 *poll;
	void *extra1;
	void *extra2;
};

struct ctl_table_poll___2 {
	atomic_t event;
	wait_queue_head_t___2 wait;
};

typedef int (*key_restrict_link_func_t___2)(struct key___2 *, const struct key_type *, const union key_payload *, struct key___2 *);

struct key_restriction___2;

struct key___2 {
	refcount_t usage;
	key_serial_t serial;
	union {
		struct list_head graveyard_link;
		struct rb_node serial_node;
	};
	struct rw_semaphore___3 sem;
	struct key_user *user;
	void *security;
	union {
		time64_t expiry;
		time64_t revoked_at;
	};
	time64_t last_used_at;
	kuid_t uid;
	kgid_t gid;
	key_perm_t perm;
	short unsigned int quotalen;
	short unsigned int datalen;
	short int state;
	long unsigned int flags;
	union {
		struct keyring_index_key index_key;
		struct {
			struct key_type *type;
			char *description;
		};
	};
	union {
		union key_payload payload;
		struct {
			struct list_head name_link;
			struct assoc_array keys;
		};
	};
	struct key_restriction___2 *restrict_link;
};

struct key_restriction___2 {
	key_restrict_link_func_t___2 check;
	struct key___2 *key;
	struct key_type *keytype;
};

struct io_cq___2 {
	struct request_queue *q;
	struct io_context___2 *ioc;
	union {
		struct list_head q_node;
		struct kmem_cache *__rcu_icq_cache;
	};
	union {
		struct hlist_node ioc_node;
		struct callback_head __rcu_head;
	};
	unsigned int flags;
};

struct kiocb___2 {
	struct file___2 *ki_filp;
	loff_t ki_pos;
	void (*ki_complete)(struct kiocb___2 *, long int, long int);
	void *private;
	int ki_flags;
	u16 ki_hint;
	u16 ki_ioprio;
	unsigned int ki_cookie;
};

struct iattr___2 {
	unsigned int ia_valid;
	umode_t ia_mode;
	kuid_t ia_uid;
	kgid_t ia_gid;
	loff_t ia_size;
	struct timespec64 ia_atime;
	struct timespec64 ia_mtime;
	struct timespec64 ia_ctime;
	struct file___2 *ia_file;
};

struct percpu_counter___2 {
	raw_spinlock_t___2 lock;
	s64 count;
	struct list_head list;
	s32 *counters;
};

struct dquot___2 {
	struct hlist_node dq_hash;
	struct list_head dq_inuse;
	struct list_head dq_free;
	struct list_head dq_dirty;
	struct mutex___2 dq_lock;
	spinlock_t___2 dq_dqb_lock;
	atomic_t dq_count;
	struct super_block___2 *dq_sb;
	struct kqid dq_id;
	loff_t dq_off;
	long unsigned int dq_flags;
	struct mem_dqblk dq_dqb;
};

struct quota_format_type___2 {
	int qf_fmt_id;
	const struct quota_format_ops___2 *qf_ops;
	struct module *qf_owner;
	struct quota_format_type___2 *qf_next;
};

struct dqstats___2 {
	int stat[8];
	struct percpu_counter___2 counter[8];
};

struct quota_format_ops___2 {
	int (*check_quota_file)(struct super_block___2 *, int);
	int (*read_file_info)(struct super_block___2 *, int);
	int (*write_file_info)(struct super_block___2 *, int);
	int (*free_file_info)(struct super_block___2 *, int);
	int (*read_dqblk)(struct dquot___2 *);
	int (*commit_dqblk)(struct dquot___2 *);
	int (*release_dqblk)(struct dquot___2 *);
	int (*get_next_id)(struct super_block___2 *, struct kqid *);
	long unsigned int rh_reserved1;
	long unsigned int rh_reserved2;
};

struct dquot_operations___2 {
	int (*write_dquot)(struct dquot___2 *);
	struct dquot___2 * (*alloc_dquot)(struct super_block___2 *, int);
	void (*destroy_dquot)(struct dquot___2 *);
	int (*acquire_dquot)(struct dquot___2 *);
	int (*release_dquot)(struct dquot___2 *);
	int (*mark_dirty)(struct dquot___2 *);
	int (*write_info)(struct super_block___2 *, int);
	qsize_t * (*get_reserved_space)(struct inode___2 *);
	int (*get_projid)(struct inode___2 *, kprojid_t *);
	int (*get_inode_usage)(struct inode___2 *, qsize_t *);
	int (*get_next_id)(struct super_block___2 *, struct kqid *);
	long unsigned int rh_reserved1;
	long unsigned int rh_reserved2;
};

struct quotactl_ops___2 {
	int (*quota_on)(struct super_block___2 *, int, int, const struct path___2 *);
	int (*quota_off)(struct super_block___2 *, int);
	int (*quota_enable)(struct super_block___2 *, unsigned int);
	int (*quota_disable)(struct super_block___2 *, unsigned int);
	int (*quota_sync)(struct super_block___2 *, int);
	int (*set_info)(struct super_block___2 *, int, struct qc_info *);
	int (*get_dqblk)(struct super_block___2 *, struct kqid, struct qc_dqblk *);
	int (*get_nextdqblk)(struct super_block___2 *, struct kqid *, struct qc_dqblk *);
	int (*set_dqblk)(struct super_block___2 *, struct kqid, struct qc_dqblk *);
	int (*get_state)(struct super_block___2 *, struct qc_state *);
	int (*rm_xquota)(struct super_block___2 *, unsigned int);
	long unsigned int rh_reserved1;
	long unsigned int rh_reserved2;
	long unsigned int rh_reserved3;
	long unsigned int rh_reserved4;
};

struct address_space_operations___2 {
	int (*writepage)(struct page___2 *, struct writeback_control *);
	int (*readpage)(struct file___2 *, struct page___2 *);
	int (*writepages)(struct address_space___2 *, struct writeback_control *);
	int (*set_page_dirty)(struct page___2 *);
	int (*readpages)(struct file___2 *, struct address_space___2 *, struct list_head *, unsigned int);
	int (*write_begin)(struct file___2 *, struct address_space___2 *, loff_t, unsigned int, unsigned int, struct page___2 **, void **);
	int (*write_end)(struct file___2 *, struct address_space___2 *, loff_t, unsigned int, unsigned int, struct page___2 *, void *);
	sector_t (*bmap)(struct address_space___2 *, sector_t);
	void (*invalidatepage)(struct page___2 *, unsigned int, unsigned int);
	int (*releasepage)(struct page___2 *, gfp_t);
	void (*freepage)(struct page___2 *);
	ssize_t (*direct_IO)(struct kiocb___2 *, struct iov_iter *);
	int (*migratepage)(struct address_space___2 *, struct page___2 *, struct page___2 *, enum migrate_mode);
	bool (*isolate_page)(struct page___2 *, isolate_mode_t);
	void (*putback_page)(struct page___2 *);
	int (*launder_page)(struct page___2 *);
	int (*is_partially_uptodate)(struct page___2 *, long unsigned int, long unsigned int);
	void (*is_dirty_writeback)(struct page___2 *, bool *, bool *);
	int (*error_remove_page)(struct address_space___2 *, struct page___2 *);
	int (*swap_activate)(struct swap_info_struct *, struct file___2 *, sector_t *);
	void (*swap_deactivate)(struct file___2 *);
	union {
		void (*readahead)(struct readahead_control *);
		struct {
			long unsigned int rh_reserved1;
		} rh_kabi_hidden_405;
		union {		};
	};
	long unsigned int rh_reserved2;
	long unsigned int rh_reserved3;
	long unsigned int rh_reserved4;
};

struct block_device___2 {
	dev_t bd_dev;
	int bd_openers;
	struct inode___2 *bd_inode;
	struct super_block___2 *bd_super;
	struct mutex___2 bd_mutex;
	void *bd_claiming;
	void *bd_holder;
	int bd_holders;
	bool bd_write_holder;
	struct list_head bd_holder_disks;
	struct block_device___2 *bd_contains;
	unsigned int bd_block_size;
	u8 bd_partno;
	struct hd_struct *bd_part;
	unsigned int bd_part_count;
	int bd_invalidated;
	struct gendisk *bd_disk;
	struct request_queue *bd_queue;
	struct backing_dev_info *bd_bdi;
	struct list_head bd_list;
	long unsigned int bd_private;
	int bd_fsfreeze_count;
	struct mutex___2 bd_fsfreeze_mutex;
	union {
		spinlock_t___2 bd_size_lock;
		struct {
			long unsigned int rh_reserved1;
		} rh_kabi_hidden_501;
		union {		};
	};
	long unsigned int rh_reserved2;
	long unsigned int rh_reserved3;
	long unsigned int rh_reserved4;
};

struct inode_operations___2 {
	struct dentry___2 * (*lookup)(struct inode___2 *, struct dentry___2 *, unsigned int);
	const char * (*get_link)(struct dentry___2 *, struct inode___2 *, struct delayed_call *);
	int (*permission)(struct inode___2 *, int);
	struct posix_acl * (*get_acl)(struct inode___2 *, int);
	int (*readlink)(struct dentry___2 *, char *, int);
	int (*create)(struct inode___2 *, struct dentry___2 *, umode_t, bool);
	int (*link)(struct dentry___2 *, struct inode___2 *, struct dentry___2 *);
	int (*unlink)(struct inode___2 *, struct dentry___2 *);
	int (*symlink)(struct inode___2 *, struct dentry___2 *, const char *);
	int (*mkdir)(struct inode___2 *, struct dentry___2 *, umode_t);
	int (*rmdir)(struct inode___2 *, struct dentry___2 *);
	int (*mknod)(struct inode___2 *, struct dentry___2 *, umode_t, dev_t);
	int (*rename)(struct inode___2 *, struct dentry___2 *, struct inode___2 *, struct dentry___2 *, unsigned int);
	int (*setattr)(struct dentry___2 *, struct iattr___2 *);
	int (*getattr)(const struct path___2 *, struct kstat *, u32, unsigned int);
	ssize_t (*listxattr)(struct dentry___2 *, char *, size_t);
	int (*fiemap)(struct inode___2 *, struct fiemap_extent_info *, u64, u64);
	int (*update_time)(struct inode___2 *, struct timespec64 *, int);
	int (*atomic_open)(struct inode___2 *, struct dentry___2 *, struct file___2 *, unsigned int, umode_t, int *);
	int (*tmpfile)(struct inode___2 *, struct dentry___2 *, umode_t);
	int (*set_acl)(struct inode___2 *, struct posix_acl *, int);
	long unsigned int rh_reserved1;
	long unsigned int rh_reserved2;
	long unsigned int rh_reserved3;
	long unsigned int rh_reserved4;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
};

struct file_lock_context___2 {
	spinlock_t___2 flc_lock;
	struct list_head flc_flock;
	struct list_head flc_posix;
	struct list_head flc_lease;
};

struct file_lock_operations___2 {
	void (*fl_copy_lock)(struct file_lock___2 *, struct file_lock___2 *);
	void (*fl_release_private)(struct file_lock___2 *);
	long unsigned int rh_reserved1;
	long unsigned int rh_reserved2;
};

struct fasync_struct___2;

struct lock_manager_operations___2;

struct file_lock___2 {
	struct file_lock___2 *fl_next;
	struct list_head fl_list;
	struct hlist_node fl_link;
	struct list_head fl_block;
	struct list_head rh_reserved1;
	fl_owner_t fl_owner;
	unsigned int fl_flags;
	unsigned char fl_type;
	unsigned int fl_pid;
	int fl_link_cpu;
	wait_queue_head_t___2 fl_wait;
	struct file___2 *fl_file;
	loff_t fl_start;
	loff_t fl_end;
	struct fasync_struct___2 *fl_fasync;
	long unsigned int fl_break_time;
	long unsigned int fl_downgrade_time;
	const struct file_lock_operations___2 *fl_ops;
	const struct lock_manager_operations___2 *fl_lmops;
	union {
		struct nfs_lock_info nfs_fl;
		struct nfs4_lock_info nfs4_fl;
		struct {
			struct list_head link;
			int state;
		} afs;
	} fl_u;
};

struct lock_manager_operations___2 {
	int (*lm_compare_owner)(struct file_lock___2 *, struct file_lock___2 *);
	long unsigned int (*lm_owner_key)(struct file_lock___2 *);
	fl_owner_t (*lm_get_owner)(fl_owner_t);
	void (*lm_put_owner)(fl_owner_t);
	void (*lm_notify)(struct file_lock___2 *);
	int (*lm_grant)(struct file_lock___2 *, int);
	bool (*lm_break)(struct file_lock___2 *);
	int (*lm_change)(struct file_lock___2 *, int, struct list_head *);
	void (*lm_setup)(struct file_lock___2 *, void **);
	union {
		bool (*lm_breaker_owns_lease)(struct file_lock___2 *);
		struct {
			long unsigned int rh_reserved1;
		} rh_kabi_hidden_1047;
		union {		};
	};
	long unsigned int rh_reserved2;
};

struct fasync_struct___2 {
	rwlock_t___2 fa_lock;
	int magic;
	int fa_fd;
	struct fasync_struct___2 *fa_next;
	struct file___2 *fa_file;
	struct callback_head fa_rcu;
};

struct super_operations___2 {
	struct inode___2 * (*alloc_inode)(struct super_block___2 *);
	void (*destroy_inode)(struct inode___2 *);
	void (*dirty_inode)(struct inode___2 *, int);
	int (*write_inode)(struct inode___2 *, struct writeback_control *);
	int (*drop_inode)(struct inode___2 *);
	void (*evict_inode)(struct inode___2 *);
	void (*put_super)(struct super_block___2 *);
	int (*sync_fs)(struct super_block___2 *, int);
	int (*freeze_super)(struct super_block___2 *);
	int (*freeze_fs)(struct super_block___2 *);
	int (*thaw_super)(struct super_block___2 *);
	int (*unfreeze_fs)(struct super_block___2 *);
	int (*statfs)(struct dentry___2 *, struct kstatfs *);
	int (*remount_fs)(struct super_block___2 *, int *, char *);
	void (*umount_begin)(struct super_block___2 *);
	int (*show_options)(struct seq_file *, struct dentry___2 *);
	int (*show_devname)(struct seq_file *, struct dentry___2 *);
	int (*show_path)(struct seq_file *, struct dentry___2 *);
	int (*show_stats)(struct seq_file *, struct dentry___2 *);
	ssize_t (*quota_read)(struct super_block___2 *, int, char *, size_t, loff_t);
	ssize_t (*quota_write)(struct super_block___2 *, int, const char *, size_t, loff_t);
	struct dquot___2 ** (*get_dquots)(struct inode___2 *);
	int (*bdev_try_to_free_page)(struct super_block___2 *, struct page___2 *, gfp_t);
	long int (*nr_cached_objects)(struct super_block___2 *, struct shrink_control *);
	long int (*free_cached_objects)(struct super_block___2 *, struct shrink_control *);
	long unsigned int rh_reserved1;
	long unsigned int rh_reserved2;
	long unsigned int rh_reserved3;
	long unsigned int rh_reserved4;
};

typedef void compound_page_dtor___2(struct page___2 *);

enum vcpu_state {
	vcpu_running = 0,
	vcpu_halted = 1,
	vcpu_hashed = 2,
};

struct pv_node {
	struct mcs_spinlock mcs;
	int cpu;
	u8 state;
};

struct pv_hash_entry {
	struct qspinlock *lock;
	struct pv_node *node;
};

struct ppc_debug_info {
	__u32 version;
	__u32 num_instruction_bps;
	__u32 num_data_bps;
	__u32 num_condition_regs;
	__u32 data_bp_alignment;
	__u32 sizeof_condition;
	__u64 features;
};

struct ppc_hw_breakpoint {
	__u32 version;
	__u32 trigger_type;
	__u32 addr_mode;
	__u32 condition_mode;
	__u64 addr;
	__u64 addr2;
	__u64 condition_value;
};

struct membuf {
	void *p;
	size_t left;
};

struct user_regset;

typedef int user_regset_active_fn(struct task_struct *, const struct user_regset *);

typedef int user_regset_get2_fn(struct task_struct *, const struct user_regset *, struct membuf);

typedef int user_regset_set_fn(struct task_struct *, const struct user_regset *, unsigned int, unsigned int, const void *, const void *);

typedef int user_regset_writeback_fn(struct task_struct *, const struct user_regset *, int);

typedef unsigned int user_regset_get_size_fn(struct task_struct *, const struct user_regset *);

struct user_regset {
	user_regset_get2_fn *regset_get;
	user_regset_set_fn *set;
	user_regset_active_fn *active;
	user_regset_writeback_fn *writeback;
	user_regset_get_size_fn *get_size;
	unsigned int n;
	unsigned int size;
	unsigned int align;
	unsigned int bias;
	unsigned int core_note_type;
};

struct user_regset_view {
	const char *name;
	const struct user_regset *regsets;
	unsigned int n;
	u32 e_flags;
	u16 e_machine;
	u8 ei_osabi;
};

struct trace_event_raw_sys_enter {
	struct trace_entry ent;
	long int id;
	long unsigned int args[6];
	char __data[0];
};

struct trace_event_raw_sys_exit {
	struct trace_entry ent;
	long int id;
	long int ret;
	char __data[0];
};

struct trace_event_data_offsets_sys_enter {};

struct trace_event_data_offsets_sys_exit {};

typedef void (*btf_trace_sys_enter)(void *, struct pt_regs *, long int);

typedef void (*btf_trace_sys_exit)(void *, struct pt_regs *, long int);

enum powerpc_regset {
	REGSET_GPR = 0,
	REGSET_FPR = 1,
	REGSET_VMX = 2,
	REGSET_VSX = 3,
	REGSET_TM_CGPR = 4,
	REGSET_TM_CFPR = 5,
	REGSET_TM_CVMX = 6,
	REGSET_TM_CVSX = 7,
	REGSET_TM_SPR = 8,
	REGSET_TM_CTAR = 9,
	REGSET_TM_CPPR = 10,
	REGSET_TM_CDSCR = 11,
	REGSET_PPR = 12,
	REGSET_DSCR = 13,
	REGSET_TAR = 14,
	REGSET_EBB = 15,
	REGSET_PMR = 16,
	REGSET_PKEY = 17,
};

struct kobject___3;

struct kobj_attribute___3;

struct pt_regs_offset {
	const char *name;
	int offset;
};

typedef u32 compat_ulong_t;

enum perf_type_id {
	PERF_TYPE_HARDWARE = 0,
	PERF_TYPE_SOFTWARE = 1,
	PERF_TYPE_TRACEPOINT = 2,
	PERF_TYPE_HW_CACHE = 3,
	PERF_TYPE_RAW = 4,
	PERF_TYPE_BREAKPOINT = 5,
	PERF_TYPE_MAX = 6,
};

enum l1d_flush_type {
	L1D_FLUSH_NONE = 1,
	L1D_FLUSH_FALLBACK = 2,
	L1D_FLUSH_ORI = 4,
	L1D_FLUSH_MTTRIG = 8,
};

struct kexec_file_ops___2;

typedef s32 compat_ssize_t;

typedef struct {
	long unsigned int entry;
	long unsigned int toc;
	long unsigned int env;
} func_descr_t;

struct sigaltstack {
	void *ss_sp;
	int ss_flags;
	size_t ss_size;
};

typedef struct sigaltstack stack_t;

typedef elf_greg_t64 elf_gregset_t64[48];

typedef elf_gregset_t64 elf_gregset_t;

struct sigcontext {
	long unsigned int _unused[4];
	int signal;
	int _pad0;
	long unsigned int handler;
	long unsigned int oldmask;
	struct user_pt_regs *regs;
	elf_gregset_t gp_regs;
	elf_fpregset_t fp_regs;
	elf_vrreg_t *v_regs;
	long int vmx_reserve[101];
};

struct ucontext {
	long unsigned int uc_flags;
	struct ucontext *uc_link;
	stack_t uc_stack;
	sigset_t uc_sigmask;
	sigset_t __unused[15];
	struct sigcontext uc_mcontext;
};

struct rt_sigframe___2 {
	struct ucontext uc;
	struct ucontext uc_transact;
	long unsigned int _unused[2];
	unsigned int tramp[6];
	struct siginfo *pinfo;
	void *puc;
	struct siginfo info;
	char abigap[512];
	long: 64;
};

struct semaphore {
	raw_spinlock_t lock;
	unsigned int count;
	struct list_head wait_list;
};

struct miscdevice {
	int minor;
	const char *name;
	const struct file_operations *fops;
	struct list_head list;
	struct device *parent;
	struct device *this_device;
	const struct attribute_group **groups;
	const char *nodename;
	umode_t mode;
};

struct kmsg_dump_iter {
	u64 cur_seq;
	u64 next_seq;
};

struct kmsg_dumper {
	struct list_head list;
	void (*dump)(struct kmsg_dumper *, enum kmsg_dump_reason);
	enum kmsg_dump_reason max_reason;
	bool registered;
};

enum pstore_type_id {
	PSTORE_TYPE_DMESG = 0,
	PSTORE_TYPE_MCE = 1,
	PSTORE_TYPE_CONSOLE = 2,
	PSTORE_TYPE_FTRACE = 3,
	PSTORE_TYPE_PPC_RTAS = 4,
	PSTORE_TYPE_PPC_OF = 5,
	PSTORE_TYPE_PPC_COMMON = 6,
	PSTORE_TYPE_PMSG = 7,
	PSTORE_TYPE_PPC_OPAL = 8,
	PSTORE_TYPE_UNKNOWN = 255,
};

struct pstore_info;

struct pstore_record {
	struct pstore_info *psi;
	enum pstore_type_id type;
	u64 id;
	struct timespec64 time;
	char *buf;
	ssize_t size;
	ssize_t ecc_notice_size;
	int count;
	enum kmsg_dump_reason reason;
	unsigned int part;
	bool compressed;
};

struct pstore_info {
	struct module *owner;
	char *name;
	struct semaphore buf_lock;
	char *buf;
	size_t bufsize;
	struct mutex read_mutex;
	int flags;
	void *data;
	int (*open)(struct pstore_info *);
	int (*close)(struct pstore_info *);
	ssize_t (*read)(struct pstore_record *);
	int (*write)(struct pstore_record *);
	int (*write_user)(struct pstore_record *, const char *);
	int (*erase)(struct pstore_record *);
};

typedef unsigned char Byte;

typedef long unsigned int uLong;

struct internal_state;

struct z_stream_s {
	const Byte *next_in;
	uLong avail_in;
	uLong total_in;
	Byte *next_out;
	uLong avail_out;
	uLong total_out;
	char *msg;
	struct internal_state *state;
	void *workspace;
	int data_type;
	uLong adler;
	uLong reserved;
};

struct internal_state {
	int dummy;
};

struct err_log_info {
	__be32 error_type;
	__be32 seq_num;
};

struct oops_log_info {
	__be16 version;
	__be16 report_length;
	__be64 timestamp;
} __attribute__((packed));

struct nvram_header {
	unsigned char signature;
	unsigned char checksum;
	short unsigned int length;
	char name[12];
};

struct nvram_partition {
	struct list_head partition;
	struct nvram_header header;
	unsigned int index;
};

enum hrtimer_mode {
	HRTIMER_MODE_ABS = 0,
	HRTIMER_MODE_REL = 1,
	HRTIMER_MODE_PINNED = 2,
	HRTIMER_MODE_SOFT = 4,
	HRTIMER_MODE_HARD = 8,
	HRTIMER_MODE_ABS_PINNED = 2,
	HRTIMER_MODE_REL_PINNED = 3,
	HRTIMER_MODE_ABS_SOFT = 4,
	HRTIMER_MODE_REL_SOFT = 5,
	HRTIMER_MODE_ABS_PINNED_SOFT = 6,
	HRTIMER_MODE_REL_PINNED_SOFT = 7,
	HRTIMER_MODE_ABS_HARD = 8,
	HRTIMER_MODE_REL_HARD = 9,
	HRTIMER_MODE_ABS_PINNED_HARD = 10,
	HRTIMER_MODE_REL_PINNED_HARD = 11,
};

struct die_args {
	struct pt_regs *regs;
	const char *str;
	long int err;
	int trapnr;
	int signr;
};

enum {
	HW_BREAKPOINT_EMPTY = 0,
	HW_BREAKPOINT_R = 1,
	HW_BREAKPOINT_W = 2,
	HW_BREAKPOINT_RW = 3,
	HW_BREAKPOINT_X = 4,
	HW_BREAKPOINT_INVALID = 7,
};

enum bp_type_idx {
	TYPE_INST = 0,
	TYPE_DATA = 1,
	TYPE_MAX = 2,
};

struct breakpoint {
	struct list_head list;
	struct perf_event *bp;
	bool ptrace_bp;
};

struct mce_error_info {
	enum MCE_ErrorType error_type: 8;
	union {
		enum MCE_UeErrorType ue_error_type: 8;
		enum MCE_SlbErrorType slb_error_type: 8;
		enum MCE_EratErrorType erat_error_type: 8;
		enum MCE_TlbErrorType tlb_error_type: 8;
		enum MCE_UserErrorType user_error_type: 8;
		enum MCE_RaErrorType ra_error_type: 8;
		enum MCE_LinkErrorType link_error_type: 8;
	} u;
	enum MCE_Severity severity: 8;
	enum MCE_Initiator initiator: 8;
	enum MCE_ErrorClass error_class: 8;
	bool sync_error;
	bool ignore_event;
};

enum {
	WORK_STRUCT_PENDING_BIT = 0,
	WORK_STRUCT_INACTIVE_BIT = 1,
	WORK_STRUCT_PWQ_BIT = 2,
	WORK_STRUCT_LINKED_BIT = 3,
	WORK_STRUCT_COLOR_SHIFT = 4,
	WORK_STRUCT_COLOR_BITS = 4,
	WORK_STRUCT_PENDING = 1,
	WORK_STRUCT_INACTIVE = 2,
	WORK_STRUCT_PWQ = 4,
	WORK_STRUCT_LINKED = 8,
	WORK_STRUCT_STATIC = 0,
	WORK_NR_COLORS = 15,
	WORK_NO_COLOR = 15,
	WORK_CPU_UNBOUND = 2048,
	WORK_STRUCT_FLAG_BITS = 8,
	WORK_OFFQ_FLAG_BASE = 4,
	__WORK_OFFQ_CANCELING = 4,
	WORK_OFFQ_CANCELING = 16,
	WORK_OFFQ_FLAG_BITS = 1,
	WORK_OFFQ_POOL_SHIFT = 5,
	WORK_OFFQ_LEFT = 59,
	WORK_OFFQ_POOL_BITS = 31,
	WORK_OFFQ_POOL_NONE = 2147483647,
	WORK_STRUCT_FLAG_MASK = 255,
	WORK_STRUCT_WQ_DATA_MASK = 4294967040,
	WORK_STRUCT_NO_POOL = 4294967264,
	WORK_BUSY_PENDING = 1,
	WORK_BUSY_RUNNING = 2,
	WORKER_DESC_LEN = 24,
};

enum {
	DTRIG_UNKNOWN = 0,
	DTRIG_VECTOR_CI = 1,
	DTRIG_SUSPEND_ESCAPE = 2,
};

enum {
	TLB_INVAL_SCOPE_GLOBAL = 0,
	TLB_INVAL_SCOPE_LPID = 1,
};

struct mce_ierror_table {
	long unsigned int srr1_mask;
	long unsigned int srr1_value;
	bool nip_valid;
	unsigned int error_type;
	unsigned int error_subtype;
	unsigned int error_class;
	unsigned int initiator;
	unsigned int severity;
	bool sync_error;
};

struct mce_derror_table {
	long unsigned int dsisr_value;
	bool dar_valid;
	unsigned int error_type;
	unsigned int error_subtype;
	unsigned int error_class;
	unsigned int initiator;
	unsigned int severity;
	bool sync_error;
};

enum stf_barrier_type {
	STF_BARRIER_NONE = 1,
	STF_BARRIER_FALLBACK = 2,
	STF_BARRIER_EIEIO = 4,
	STF_BARRIER_SYNC_ORI = 8,
};

enum branch_cache_flush_type {
	BRANCH_CACHE_FLUSH_NONE = 1,
	BRANCH_CACHE_FLUSH_SW = 2,
	BRANCH_CACHE_FLUSH_HW = 4,
};

typedef u16 uint16_t;

struct rtas_suspend_me_data {
	atomic_t working;
	atomic_t done;
	int token;
	atomic_t error;
	struct completion *complete;
};

struct rtas_error_log {
	uint8_t byte0;
	uint8_t byte1;
	uint8_t byte2;
	uint8_t byte3;
	__be32 extended_log_length;
	unsigned char buffer[1];
};

struct rtas_ext_event_log_v6 {
	uint8_t byte0;
	uint8_t byte1;
	uint8_t byte2;
	uint8_t byte3;
	uint8_t reserved[8];
	__be32 company_id;
	uint8_t vendor_log[1];
};

struct pseries_errorlog {
	__be16 id;
	__be16 length;
	uint8_t version;
	uint8_t subtype;
	__be16 creator_component;
	uint8_t data[0];
};

struct rtas_filter {
	const char *name;
	int token;
	int buf_idx1;
	int size_idx1;
	int buf_idx2;
	int size_idx2;
	int fixed_size;
};

struct indicator_elem {
	__be32 token;
	__be32 maxindex;
};

struct wait_queue_entry;

typedef int (*wait_queue_func_t)(struct wait_queue_entry *, unsigned int, int, void *);

struct wait_queue_entry {
	unsigned int flags;
	void *private;
	wait_queue_func_t func;
	struct list_head entry;
};

typedef struct poll_table_struct poll_table;

typedef void (*exitcall_t)();

struct flash_block {
	char *data;
	long unsigned int length;
};

struct flash_block_list {
	long unsigned int num_blocks;
	struct flash_block_list *next;
	struct flash_block blocks[255];
};

struct rtas_update_flash_t {
	int status;
	struct flash_block_list *flist;
};

struct rtas_manage_flash_t {
	int status;
};

struct rtas_validate_flash_t {
	int status;
	char *buf;
	unsigned int buf_size;
	unsigned int update_results;
};

struct rtas_flash_file {
	const char *filename;
	const char *rtas_call_name;
	int *status;
	const struct file_operations fops;
};

struct individual_sensor {
	unsigned int token;
	unsigned int quant;
};

struct rtas_sensors {
	struct individual_sensor sensor[17];
	unsigned int quant;
};

struct dt_cpu_feature {
	const char *name;
	uint32_t isa;
	uint32_t usable_privilege;
	uint32_t hv_support;
	uint32_t os_support;
	uint32_t hfscr_bit_nr;
	uint32_t fscr_bit_nr;
	uint32_t hwcap_bit_nr;
	long unsigned int node;
	int enabled;
	int disabled;
};

struct dt_cpu_feature_match {
	const char *name;
	int (*enable)(struct dt_cpu_feature *);
	u64 cpu_ftr_bit_mask;
};

enum bus_notifier_event {
	BUS_NOTIFY_ADD_DEVICE = 0,
	BUS_NOTIFY_DEL_DEVICE = 1,
	BUS_NOTIFY_REMOVED_DEVICE = 2,
	BUS_NOTIFY_BIND_DRIVER = 3,
	BUS_NOTIFY_BOUND_DRIVER = 4,
	BUS_NOTIFY_UNBIND_DRIVER = 5,
	BUS_NOTIFY_UNBOUND_DRIVER = 6,
	BUS_NOTIFY_DRIVER_NOT_BOUND = 7,
};

struct iopf_device_param;

struct iommu_fault_param;

struct dev_iommu {
	struct mutex lock;
	struct iommu_fault_param *fault_param;
	struct iopf_device_param *iopf_param;
	struct iommu_fwspec *fwspec;
	struct iommu_device *iommu_dev;
	void *priv;
	u32 pci_32bit_workaround: 1;
};

struct iommu_fwspec {
	const struct iommu_ops *ops;
	struct fwnode_handle *iommu_fwnode;
	u32 flags;
	unsigned int num_ids;
	u32 ids[0];
};

struct of_phandle_args {
	struct device_node *np;
	int args_count;
	uint32_t args[16];
};

enum pcie_reset_state {
	pcie_deassert_reset = 1,
	pcie_warm_reset = 2,
	pcie_hot_reset = 3,
};

struct iommu_fault_unrecoverable {
	__u32 reason;
	__u32 flags;
	__u32 pasid;
	__u32 perm;
	__u64 addr;
	__u64 fetch_addr;
};

struct iommu_fault_page_request {
	__u32 flags;
	__u32 pasid;
	__u32 grpid;
	__u32 perm;
	__u64 addr;
	__u64 private_data[2];
};

struct iommu_fault {
	__u32 type;
	__u32 padding;
	union {
		struct iommu_fault_unrecoverable event;
		struct iommu_fault_page_request prm;
		__u8 padding2[56];
	};
};

struct iommu_page_response {
	__u32 argsz;
	__u32 version;
	__u32 flags;
	__u32 pasid;
	__u32 grpid;
	__u32 code;
};

typedef int (*iommu_fault_handler_t)(struct iommu_domain *, struct device *, long unsigned int, int, void *);

struct iommu_domain_geometry {
	dma_addr_t aperture_start;
	dma_addr_t aperture_end;
	bool force_aperture;
};

struct iommu_dma_cookie;

struct iommu_domain {
	unsigned int type;
	const struct iommu_ops *ops;
	long unsigned int pgsize_bitmap;
	iommu_fault_handler_t handler;
	void *handler_token;
	struct iommu_domain_geometry geometry;
	struct iommu_dma_cookie *iova_cookie;
};

typedef int (*iommu_dev_fault_handler_t)(struct iommu_fault *, void *);

struct iommu_iotlb_gather {
	long unsigned int start;
	long unsigned int end;
	size_t pgsize;
	struct list_head freelist;
	bool queued;
};

struct iommu_sva {
	struct device *dev;
};

struct iommu_fault_event {
	struct iommu_fault fault;
	struct list_head list;
};

struct iommu_device {
	struct list_head list;
	const struct iommu_ops *ops;
	struct fwnode_handle *fwnode;
	struct device *dev;
};

struct iommu_fault_param {
	iommu_dev_fault_handler_t handler;
	void *data;
	struct list_head faults;
	struct mutex lock;
};

struct eeh_stats {
	u64 no_device;
	u64 no_dn;
	u64 no_cfg_addr;
	u64 ignored_check;
	u64 total_mmio_ffs;
	u64 false_positives;
	u64 slot_resets;
};

typedef void (*eeh_edev_traverse_func)(struct eeh_dev *, void *);

typedef void * (*eeh_pe_traverse_func)(struct eeh_pe *, void *);

struct pci_io_addr_range {
	struct rb_node rb_node;
	resource_size_t addr_lo;
	resource_size_t addr_hi;
	struct eeh_dev *edev;
	struct pci_dev *pcidev;
	long unsigned int flags;
};

struct pci_io_addr_cache {
	struct rb_root rb_root;
	spinlock_t piar_lock;
};

enum {
	EEH_NEXT_ERR_NONE = 0,
	EEH_NEXT_ERR_INF = 1,
	EEH_NEXT_ERR_FROZEN_PE = 2,
	EEH_NEXT_ERR_FENCED_PHB = 3,
	EEH_NEXT_ERR_DEAD_PHB = 4,
	EEH_NEXT_ERR_DEAD_IOC = 5,
};

enum {
	IRQD_TRIGGER_MASK = 15,
	IRQD_SETAFFINITY_PENDING = 256,
	IRQD_ACTIVATED = 512,
	IRQD_NO_BALANCING = 1024,
	IRQD_PER_CPU = 2048,
	IRQD_AFFINITY_SET = 4096,
	IRQD_LEVEL = 8192,
	IRQD_WAKEUP_STATE = 16384,
	IRQD_MOVE_PCNTXT = 32768,
	IRQD_IRQ_DISABLED = 65536,
	IRQD_IRQ_MASKED = 131072,
	IRQD_IRQ_INPROGRESS = 262144,
	IRQD_WAKEUP_ARMED = 524288,
	IRQD_FORWARDED_TO_VCPU = 1048576,
	IRQD_AFFINITY_MANAGED = 2097152,
	IRQD_IRQ_STARTED = 4194304,
	IRQD_MANAGED_SHUTDOWN = 8388608,
	IRQD_SINGLE_TARGET = 16777216,
	IRQD_DEFAULT_TRIGGER_SET = 33554432,
	IRQD_CAN_RESERVE = 67108864,
	IRQD_MSI_NOMASK_QUIRK = 134217728,
	IRQD_HANDLE_ENFORCE_IRQCTX = 268435456,
	IRQD_IRQ_ENABLED_ON_SUSPEND = 536870912,
};

struct hotplug_slot_ops;

struct hotplug_slot {
	const struct hotplug_slot_ops *ops;
	struct list_head slot_list;
	struct pci_slot *pci_slot;
	struct module *owner;
	const char *mod_name;
	long unsigned int rh_reserved1;
	long unsigned int rh_reserved2;
	long unsigned int rh_reserved3;
	long unsigned int rh_reserved4;
	long unsigned int rh_reserved5;
	long unsigned int rh_reserved6;
	long unsigned int rh_reserved7;
	long unsigned int rh_reserved8;
};

enum pci_ers_result {
	PCI_ERS_RESULT_NONE = 1,
	PCI_ERS_RESULT_CAN_RECOVER = 2,
	PCI_ERS_RESULT_NEED_RESET = 3,
	PCI_ERS_RESULT_DISCONNECT = 4,
	PCI_ERS_RESULT_RECOVERED = 5,
	PCI_ERS_RESULT_NO_AER_DRIVER = 6,
};

struct hotplug_slot_ops {
	int (*enable_slot)(struct hotplug_slot *);
	int (*disable_slot)(struct hotplug_slot *);
	int (*set_attention_status)(struct hotplug_slot *, u8);
	int (*hardware_test)(struct hotplug_slot *, u32);
	int (*get_power_status)(struct hotplug_slot *, u8 *);
	int (*get_attention_status)(struct hotplug_slot *, u8 *);
	int (*get_latch_status)(struct hotplug_slot *, u8 *);
	int (*get_adapter_status)(struct hotplug_slot *, u8 *);
	union {
		int (*reset_slot)(struct hotplug_slot *, bool);
		struct {
			int (*reset_slot)(struct hotplug_slot *, int);
		} rh_kabi_hidden_48;
		union {		};
	};
	long unsigned int rh_reserved1;
	long unsigned int rh_reserved2;
	long unsigned int rh_reserved3;
	long unsigned int rh_reserved4;
	long unsigned int rh_reserved5;
	long unsigned int rh_reserved6;
	long unsigned int rh_reserved7;
	long unsigned int rh_reserved8;
};

struct eeh_rmv_data {
	struct list_head removed_vf_list;
	int removed_dev_count;
};

typedef enum pci_ers_result (*eeh_report_fn)(struct eeh_dev *, struct pci_dev *, struct pci_driver *);

struct stack_trace {
	unsigned int nr_entries;
	unsigned int max_entries;
	long unsigned int *entries;
	int skip;
	long unsigned int rh_reserved1;
	long unsigned int rh_reserved2;
};

struct eeh_event {
	struct list_head list;
	struct eeh_pe *pe;
};

typedef __kernel_long_t __kernel_suseconds_t;

struct timeval {
	__kernel_time_t tv_sec;
	__kernel_suseconds_t tv_usec;
};

struct elf64_phdr {
	Elf64_Word p_type;
	Elf64_Word p_flags;
	Elf64_Off p_offset;
	Elf64_Addr p_vaddr;
	Elf64_Addr p_paddr;
	Elf64_Xword p_filesz;
	Elf64_Xword p_memsz;
	Elf64_Xword p_align;
};

struct elf_siginfo {
	int si_signo;
	int si_code;
	int si_errno;
};

struct elf_prstatus {
	struct elf_siginfo pr_info;
	short int pr_cursig;
	long unsigned int pr_sigpend;
	long unsigned int pr_sighold;
	pid_t pr_pid;
	pid_t pr_ppid;
	pid_t pr_pgrp;
	pid_t pr_sid;
	struct timeval pr_utime;
	struct timeval pr_stime;
	struct timeval pr_cutime;
	struct timeval pr_cstime;
	elf_gregset_t pr_reg;
	int pr_fpvalid;
};

struct fadump_crash_info_header {
	u64 magic_number;
	u64 elfcorehdr_addr;
	u32 crashing_cpu;
	struct pt_regs regs;
	struct cpumask online_mask;
};

struct fadump_memory_range {
	u64 base;
	u64 size;
};

struct fadump_mrange_info {
	char name[16];
	struct fadump_memory_range *mem_ranges;
	u32 mem_ranges_sz;
	u32 mem_range_cnt;
	u32 max_mem_ranges;
	bool is_static;
};

struct fadump_ops;

struct fw_dump {
	long unsigned int reserve_dump_area_start;
	long unsigned int reserve_dump_area_size;
	long unsigned int reserve_bootvar;
	long unsigned int cpu_state_data_size;
	u64 cpu_state_dest_vaddr;
	u32 cpu_state_data_version;
	u32 cpu_state_entry_size;
	long unsigned int hpte_region_size;
	long unsigned int boot_memory_size;
	u64 boot_mem_dest_addr;
	u64 boot_mem_addr[128];
	u64 boot_mem_sz[128];
	u64 boot_mem_top;
	u64 boot_mem_regs_cnt;
	long unsigned int fadumphdr_addr;
	long unsigned int cpu_notes_buf_vaddr;
	long unsigned int cpu_notes_buf_size;
	u64 max_copy_size;
	u64 kernel_metadata;
	int ibm_configure_kernel_dump;
	long unsigned int fadump_enabled: 1;
	long unsigned int fadump_supported: 1;
	long unsigned int dump_active: 1;
	long unsigned int dump_registered: 1;
	long unsigned int nocma: 1;
	struct fadump_ops *ops;
};

struct fadump_ops {
	u64 (*fadump_init_mem_struct)(struct fw_dump *);
	u64 (*fadump_get_metadata_size)();
	int (*fadump_setup_metadata)(struct fw_dump *);
	u64 (*fadump_get_bootmem_min)();
	int (*fadump_register)(struct fw_dump *);
	int (*fadump_unregister)(struct fw_dump *);
	int (*fadump_invalidate)(struct fw_dump *);
	void (*fadump_cleanup)(struct fw_dump *);
	int (*fadump_process)(struct fw_dump *);
	void (*fadump_region_show)(struct fw_dump *, struct seq_file *);
	void (*fadump_trigger)(struct fadump_crash_info_header *, const char *);
};

struct cma;

struct elf64_rela {
	Elf64_Addr r_offset;
	Elf64_Xword r_info;
	Elf64_Sxword r_addend;
};

typedef struct elf64_rela Elf64_Rela;

struct modversion_info {
	long unsigned int crc;
	char name[56];
};

typedef long unsigned int func_desc_t;

struct ppc64_stub_entry {
	u32 jump[7];
	u32 magic;
	func_desc_t funcdata;
};

struct preempt_notifier;

struct preempt_ops {
	void (*sched_in)(struct preempt_notifier *, int);
	void (*sched_out)(struct preempt_notifier *, struct task_struct *);
};

struct preempt_notifier {
	struct hlist_node link;
	struct preempt_ops *ops;
};

struct kvm;

struct kvmppc_vcore {
	int n_runnable;
	int num_threads;
	int entry_exit_map;
	int napping_threads;
	int first_vcpuid;
	u16 pcpu;
	u16 last_cpu;
	u8 vcore_state;
	u8 in_guest;
	struct kvm_vcpu *runnable_threads[8];
	struct list_head preempt_list;
	spinlock_t lock;
	struct rcuwait wait;
	spinlock_t stoltb_lock;
	u64 stolen_tb;
	u64 preempt_tb;
	struct kvm_vcpu *runner;
	struct kvm *kvm;
	u64 tb_offset;
	u64 tb_offset_applied;
	ulong lpcr;
	u32 arch_compat;
	ulong pcr;
	ulong dpdes;
	ulong vtb;
	ulong conferring_threads;
	unsigned int halt_poll_ns;
	atomic_t online_count;
};

typedef u64 gpa_t;

struct kvm_mmio_fragment {
	gpa_t gpa;
	void *data;
	unsigned int len;
};

struct kvmppc_slb {
	u64 esid;
	u64 vsid;
	u64 orige;
	u64 origv;
	bool valid: 1;
	bool Ks: 1;
	bool Kp: 1;
	bool nx: 1;
	bool large: 1;
	bool tb: 1;
	bool class: 1;
	u8 base_page_size;
};

typedef long unsigned int gva_t;

struct kvmppc_pte;

struct kvmppc_mmu {
	void (*slbmte)(struct kvm_vcpu *, u64, u64);
	u64 (*slbmfee)(struct kvm_vcpu *, u64);
	u64 (*slbmfev)(struct kvm_vcpu *, u64);
	int (*slbfee)(struct kvm_vcpu *, gva_t, ulong *);
	void (*slbie)(struct kvm_vcpu *, u64);
	void (*slbia)(struct kvm_vcpu *);
	void (*mtsrin)(struct kvm_vcpu *, u32, ulong);
	u32 (*mfsrin)(struct kvm_vcpu *, u32);
	int (*xlate)(struct kvm_vcpu *, gva_t, struct kvmppc_pte *, bool, bool);
	void (*tlbie)(struct kvm_vcpu *, ulong, bool);
	int (*esid_to_vsid)(struct kvm_vcpu *, ulong, u64 *);
	u64 (*ea_to_vp)(struct kvm_vcpu *, gva_t, bool);
	bool (*is_dcbz32)(struct kvm_vcpu *);
};

struct openpic;

union xive_tma_w01 {
	struct {
		u8 nsr;
		u8 cppr;
		u8 ipb;
		u8 lsmfb;
		u8 ack;
		u8 inc;
		u8 age;
		u8 pipr;
	};
	__be64 w01;
};

struct kvm_vcpu_arch_shared {
	__u64 scratch1;
	__u64 scratch2;
	__u64 scratch3;
	__u64 critical;
	__u64 sprg0;
	__u64 sprg1;
	__u64 sprg2;
	__u64 sprg3;
	__u64 srr0;
	__u64 srr1;
	__u64 dar;
	__u64 msr;
	__u32 dsisr;
	__u32 int_pending;
	__u32 sr[16];
	__u32 mas0;
	__u32 mas1;
	__u64 mas7_3;
	__u64 mas2;
	__u32 mas4;
	__u32 mas6;
	__u32 esr;
	__u32 pir;
	__u64 sprg4;
	__u64 sprg5;
	__u64 sprg6;
	__u64 sprg7;
};

struct mmio_hpte_cache_entry {
	long unsigned int hpte_v;
	long unsigned int hpte_r;
	long unsigned int rpte;
	long unsigned int pte_index;
	long unsigned int eaddr;
	long unsigned int slb_v;
	long int mmio_update;
	unsigned int slb_base_pshift;
};

struct mmio_hpte_cache {
	struct mmio_hpte_cache_entry entry[4];
	unsigned int index;
};

struct kvmppc_vpa {
	long unsigned int gpa;
	void *pinned_addr;
	void *pinned_end;
	long unsigned int next_gpa;
	long unsigned int len;
	u8 update_pending;
	bool dirty;
};

struct kvmppc_vcpu_book3s;

struct kvmppc_icp;

struct kvmppc_xive_vcpu;

struct kvm_nested_guest;

struct kvm_vcpu_arch {
	ulong host_stack;
	u32 host_pid;
	struct kvmppc_slb slb[64];
	int slb_max;
	int slb_nr;
	struct kvmppc_mmu mmu;
	struct kvmppc_vcpu_book3s *book3s;
	struct pt_regs regs;
	long: 64;
	struct thread_fp_state fp;
	struct thread_vr_state vr;
	u32 qpr[32];
	ulong tar;
	ulong hflags;
	ulong guest_owned_ext;
	ulong purr;
	ulong spurr;
	ulong ic;
	ulong dscr;
	ulong amr;
	ulong uamor;
	ulong iamr;
	u32 ctrl;
	u32 dabrx;
	ulong dabr;
	ulong dawr0;
	ulong dawrx0;
	ulong dawr1;
	ulong dawrx1;
	ulong ciabr;
	ulong cfar;
	ulong ppr;
	u32 pspb;
	ulong fscr;
	ulong shadow_fscr;
	ulong ebbhr;
	ulong ebbrr;
	ulong bescr;
	ulong csigr;
	ulong tacr;
	ulong tcscr;
	ulong acop;
	ulong wort;
	ulong tid;
	ulong psscr;
	ulong hfscr;
	ulong shadow_srr1;
	u32 vrsave;
	u32 mmucr;
	ulong shadow_msr;
	ulong csrr0;
	ulong csrr1;
	ulong dsrr0;
	ulong dsrr1;
	ulong mcsrr0;
	ulong mcsrr1;
	ulong mcsr;
	ulong dec;
	u64 entry_tb;
	u64 entry_vtb;
	u64 entry_ic;
	u32 tcr;
	ulong tsr;
	u32 ivor[64];
	ulong ivpr;
	u32 pvr;
	u32 shadow_pid;
	u32 shadow_pid1;
	u32 pid;
	u32 swap_pid;
	u32 ccr0;
	u32 ccr1;
	u32 dbsr;
	u64 mmcr[4];
	u64 mmcra;
	u64 mmcrs;
	u32 pmc[8];
	u32 spmc[2];
	u64 siar;
	u64 sdar;
	u64 sier[3];
	u64 tfhar;
	u64 texasr;
	u64 tfiar;
	u64 orig_texasr;
	u32 cr_tm;
	u64 xer_tm;
	u64 lr_tm;
	u64 ctr_tm;
	u64 amr_tm;
	u64 ppr_tm;
	u64 dscr_tm;
	u64 tar_tm;
	ulong gpr_tm[32];
	struct thread_fp_state fp_tm;
	struct thread_vr_state vr_tm;
	u32 vrsave_tm;
	ulong fault_dar;
	u32 fault_dsisr;
	long unsigned int intr_msr;
	ulong fault_gpa;
	gpa_t paddr_accessed;
	gva_t vaddr_accessed;
	pgd_t *pgdir;
	u16 io_gpr;
	u8 mmio_host_swabbed;
	u8 mmio_sign_extend;
	u8 mmio_sp64_extend;
	u8 mmio_vsx_copy_nums;
	u8 mmio_vsx_offset;
	u8 mmio_vmx_copy_nums;
	u8 mmio_vmx_offset;
	u8 mmio_copy_type;
	u8 osi_needed;
	u8 osi_enabled;
	u8 papr_enabled;
	u8 watchdog_enabled;
	u8 sane;
	u8 cpu_type;
	u8 hcall_needed;
	u8 epr_flags;
	u8 epr_needed;
	u8 external_oneshot;
	u32 cpr0_cfgaddr;
	struct hrtimer dec_timer;
	u64 dec_jiffies;
	u64 dec_expires;
	long unsigned int pending_exceptions;
	u8 ceded;
	u8 prodded;
	u8 doorbell_request;
	u8 irq_pending;
	u32 last_inst;
	struct rcuwait wait;
	struct rcuwait *waitp;
	struct kvmppc_vcore *vcore;
	int ret;
	int trap;
	int state;
	int ptid;
	int thread_cpu;
	int prev_cpu;
	bool timer_running;
	wait_queue_head_t cpu_run;
	struct machine_check_event mce_evt;
	struct kvm_vcpu_arch_shared *shared;
	long unsigned int magic_page_pa;
	long unsigned int magic_page_ea;
	bool disable_kernel_nx;
	int irq_type;
	int irq_cpu_id;
	struct openpic *mpic;
	struct kvmppc_icp *icp;
	struct kvmppc_xive_vcpu *xive_vcpu;
	__be32 xive_cam_word;
	u8 xive_pushed;
	u8 xive_esc_on;
	union xive_tma_w01 xive_saved_state;
	u64 xive_esc_raddr;
	u64 xive_esc_vaddr;
	struct kvm_vcpu_arch_shared shregs;
	struct mmio_hpte_cache mmio_cache;
	long unsigned int pgfault_addr;
	long int pgfault_index;
	long unsigned int pgfault_hpte[2];
	struct mmio_hpte_cache_entry *pgfault_cache;
	struct task_struct *run_task;
	spinlock_t vpa_update_lock;
	struct kvmppc_vpa vpa;
	struct kvmppc_vpa dtl;
	struct dtl_entry *dtl_ptr;
	long unsigned int dtl_index;
	u64 stolen_logged;
	struct kvmppc_vpa slb_shadow;
	spinlock_t tbacct_lock;
	u64 busy_stolen;
	u64 busy_preempt;
	u32 emul_inst;
	u32 online;
	struct kvm_nested_guest *nested;
	u32 nested_vcpu_id;
	gpa_t nested_io_gpr;
};

struct kvm_vcpu_stat_generic {
	u64 halt_successful_poll;
	u64 halt_attempted_poll;
	u64 halt_poll_invalid;
	u64 halt_wakeup;
	u64 halt_poll_success_ns;
	u64 halt_poll_fail_ns;
	u64 halt_wait_ns;
	u64 halt_poll_success_hist[32];
	u64 halt_poll_fail_hist[32];
	u64 halt_wait_hist[32];
	u64 blocking;
};

struct kvm_vcpu_stat {
	struct kvm_vcpu_stat_generic generic;
	u64 sum_exits;
	u64 mmio_exits;
	u64 signal_exits;
	u64 light_exits;
	u64 itlb_real_miss_exits;
	u64 itlb_virt_miss_exits;
	u64 dtlb_real_miss_exits;
	u64 dtlb_virt_miss_exits;
	u64 syscall_exits;
	u64 isi_exits;
	u64 dsi_exits;
	u64 emulated_inst_exits;
	u64 dec_exits;
	u64 ext_intr_exits;
	u64 halt_successful_wait;
	u64 dbell_exits;
	u64 gdbell_exits;
	u64 ld;
	u64 st;
	u64 pf_storage;
	u64 pf_instruc;
	u64 sp_storage;
	u64 sp_instruc;
	u64 queue_intr;
	u64 ld_slow;
	u64 st_slow;
	u64 pthru_all;
	u64 pthru_host;
	u64 pthru_bad_aff;
};

struct kvm_dirty_gfn;

struct kvm_dirty_ring {
	u32 dirty_index;
	u32 reset_index;
	u32 size;
	u32 soft_limit;
	struct kvm_dirty_gfn *dirty_gfns;
	int index;
};

struct kvm_run;

struct kvm_memory_slot;

struct kvm_vcpu {
	struct kvm *kvm;
	struct preempt_notifier preempt_notifier;
	int cpu;
	int vcpu_id;
	int vcpu_idx;
	int ____srcu_idx;
	int mode;
	u64 requests;
	long unsigned int guest_debug;
	struct mutex mutex;
	struct kvm_run *run;
	struct pid *pid;
	int sigset_active;
	sigset_t sigset;
	unsigned int halt_poll_ns;
	bool valid_wakeup;
	int mmio_needed;
	int mmio_read_completed;
	int mmio_is_write;
	int mmio_cur_fragment;
	int mmio_nr_fragments;
	struct kvm_mmio_fragment mmio_fragments[2];
	bool preempted;
	bool ready;
	struct kvm_vcpu_arch arch;
	struct kvm_vcpu_stat stat;
	char stats_id[48];
	struct kvm_dirty_ring dirty_ring;
	struct kvm_memory_slot *last_used_slot;
	u64 last_used_slot_gen;
	long: 64;
};

struct arch_msi_msg_addr_lo {
	u32 address_lo;
};

typedef struct arch_msi_msg_addr_lo arch_msi_msg_addr_lo_t;

struct arch_msi_msg_addr_hi {
	u32 address_hi;
};

typedef struct arch_msi_msg_addr_hi arch_msi_msg_addr_hi_t;

struct arch_msi_msg_data {
	u32 data;
};

typedef struct arch_msi_msg_data arch_msi_msg_data_t;

struct msi_msg {
	union {
		u32 address_lo;
		arch_msi_msg_addr_lo_t arch_addr_lo;
	};
	union {
		u32 address_hi;
		arch_msi_msg_addr_hi_t arch_addr_hi;
	};
	union {
		u32 data;
		arch_msi_msg_data_t arch_data;
	};
};

struct platform_msi_priv_data;

struct platform_msi_desc {
	struct platform_msi_priv_data *msi_priv_data;
	u16 msi_index;
};

struct fsl_mc_msi_desc {
	u16 msi_index;
};

struct irq_affinity_desc;

struct msi_desc {
	struct list_head list;
	unsigned int irq;
	unsigned int nvec_used;
	struct device *dev;
	struct msi_msg msg;
	struct irq_affinity_desc *affinity;
	void (*write_msi_msg)(struct msi_desc *, void *);
	void *write_msi_msg_data;
	union {
		struct {
			u32 masked;
			struct {
				u8 is_msix: 1;
				u8 multiple: 3;
				u8 multi_cap: 3;
				u8 maskbit: 1;
				u8 is_64: 1;
				u8 is_virtual: 1;
				u16 entry_nr;
				unsigned int default_irq;
			} msi_attrib;
			union {
				u8 mask_pos;
				void *mask_base;
			};
		};
		struct platform_msi_desc platform;
		struct fsl_mc_msi_desc fsl_mc;
	};
};

typedef u64 gfn_t;

struct interval_tree_node {
	struct rb_node rb;
	long unsigned int start;
	long unsigned int last;
	long unsigned int __subtree_last;
};

struct kvm_arch_memory_slot {
	long unsigned int *rmap;
};

struct kvm_memory_slot {
	struct hlist_node id_node[2];
	struct interval_tree_node hva_node[2];
	struct rb_node gfn_node[2];
	gfn_t base_gfn;
	long unsigned int npages;
	long unsigned int *dirty_bitmap;
	struct kvm_arch_memory_slot arch;
	long unsigned int userspace_addr;
	u32 flags;
	short int id;
	u16 as_id;
};

struct kvm_vm_stat_generic {
	u64 remote_tlb_flush;
	u64 remote_tlb_flush_requests;
};

enum mmu_notifier_event {
	MMU_NOTIFY_UNMAP = 0,
	MMU_NOTIFY_CLEAR = 1,
	MMU_NOTIFY_PROTECTION_VMA = 2,
	MMU_NOTIFY_PROTECTION_PAGE = 3,
	MMU_NOTIFY_SOFT_DIRTY = 4,
	MMU_NOTIFY_RELEASE = 5,
	MMU_NOTIFY_MIGRATE = 6,
};

struct mmu_notifier_ops;

struct mmu_notifier_rh;

struct mmu_notifier {
	struct hlist_node hlist;
	const struct mmu_notifier_ops *ops;
	union {
		struct {
			size_t mmu_notifier_size_rh;
			struct mmu_notifier_rh *_rh;
		};
		struct {
			long unsigned int rh_reserved1;
			long unsigned int rh_reserved2;
		} rh_kabi_hidden_328;
		union {		};
	};
};

struct mmu_notifier_range {
	struct vm_area_struct *vma;
	struct mm_struct *mm;
	long unsigned int start;
	long unsigned int end;
	unsigned int flags;
	enum mmu_notifier_event event;
	void *migrate_pgmap_owner;
};

struct mmu_notifier_ops {
	int flags;
	void (*release)(struct mmu_notifier *, struct mm_struct *);
	int (*clear_flush_young)(struct mmu_notifier *, struct mm_struct *, long unsigned int, long unsigned int);
	int (*clear_young)(struct mmu_notifier *, struct mm_struct *, long unsigned int, long unsigned int);
	int (*test_young)(struct mmu_notifier *, struct mm_struct *, long unsigned int);
	void (*change_pte)(struct mmu_notifier *, struct mm_struct *, long unsigned int, pte_t);
	void (*invalidate_range_start)(struct mmu_notifier *, struct mm_struct *, long unsigned int, long unsigned int);
	void (*invalidate_range_end)(struct mmu_notifier *, struct mm_struct *, long unsigned int, long unsigned int);
	void (*invalidate_range)(struct mmu_notifier *, struct mm_struct *, long unsigned int, long unsigned int);
	union {
		struct mmu_notifier * (*alloc_notifier)(struct mm_struct *);
		struct {
			long unsigned int rh_reserved1;
		} rh_kabi_hidden_294;
		union {		};
	};
	union {
		void (*free_notifier)(struct mmu_notifier *);
		struct {
			long unsigned int rh_reserved2;
		} rh_kabi_hidden_295;
		union {		};
	};
	union {
		int (*invalidate_range_start_v2)(struct mmu_notifier *, const struct mmu_notifier_range *);
		struct {
			long unsigned int rh_reserved3;
		} rh_kabi_hidden_299;
		union {		};
	};
	union {
		void (*invalidate_range_end_v2)(struct mmu_notifier *, const struct mmu_notifier_range *);
		struct {
			long unsigned int rh_reserved4;
		} rh_kabi_hidden_303;
		union {		};
	};
};

struct mmu_notifier_rh {
	struct mm_struct *mm;
	struct callback_head rcu;
	unsigned int users;
	unsigned int version;
	struct mmu_notifier *back_ptr;
};

struct irq_affinity_desc {
	struct cpumask mask;
	unsigned int is_managed: 1;
};

struct irq_bypass_consumer;

struct irq_bypass_producer {
	struct list_head node;
	void *token;
	int irq;
	int (*add_consumer)(struct irq_bypass_producer *, struct irq_bypass_consumer *);
	void (*del_consumer)(struct irq_bypass_producer *, struct irq_bypass_consumer *);
	void (*stop)(struct irq_bypass_producer *);
	void (*start)(struct irq_bypass_producer *);
};

struct irq_bypass_consumer {
	struct list_head node;
	void *token;
	int (*add_producer)(struct irq_bypass_consumer *, struct irq_bypass_producer *);
	void (*del_producer)(struct irq_bypass_consumer *, struct irq_bypass_producer *);
	void (*stop)(struct irq_bypass_consumer *);
	void (*start)(struct irq_bypass_consumer *);
};

struct kvm_sregs {
	__u32 pvr;
	union {
		struct {
			__u64 sdr1;
			struct {
				struct {
					__u64 slbe;
					__u64 slbv;
				} slb[64];
			} ppc64;
			struct {
				__u32 sr[16];
				__u64 ibat[8];
				__u64 dbat[8];
			} ppc32;
		} s;
		struct {
			union {
				struct {
					__u32 features;
					__u32 svr;
					__u64 mcar;
					__u32 hid0;
					__u32 pid1;
					__u32 pid2;
				} fsl;
				__u8 pad[256];
			} impl;
			__u32 features;
			__u32 impl_id;
			__u32 update_special;
			__u32 pir;
			__u64 sprg8;
			__u64 sprg9;
			__u64 csrr0;
			__u64 dsrr0;
			__u64 mcsrr0;
			__u32 csrr1;
			__u32 dsrr1;
			__u32 mcsrr1;
			__u32 esr;
			__u64 dear;
			__u64 ivpr;
			__u64 mcivpr;
			__u64 mcsr;
			__u32 tsr;
			__u32 tcr;
			__u32 decar;
			__u32 dec;
			__u64 tb;
			__u32 dbsr;
			__u32 dbcr[3];
			__u32 iac[4];
			__u32 dac[2];
			__u32 dvc[2];
			__u8 num_iac;
			__u8 num_dac;
			__u8 num_dvc;
			__u8 pad;
			__u32 epr;
			__u32 vrsave;
			__u32 epcr;
			__u32 mas0;
			__u32 mas1;
			__u64 mas2;
			__u64 mas7_3;
			__u32 mas4;
			__u32 mas6;
			__u32 ivor_low[16];
			__u32 ivor_high[18];
			__u32 mmucfg;
			__u32 eptcfg;
			__u32 tlbcfg[4];
			__u32 tlbps[4];
			__u32 eplc;
			__u32 epsc;
		} e;
		__u8 pad[1020];
	} u;
};

struct kvm_debug_exit_arch {
	__u64 address;
	__u32 status;
	__u32 reserved;
};

struct kvm_sync_regs {};

struct kvm_ppc_mmuv3_cfg {
	__u64 flags;
	__u64 process_table;
};

struct kvm_ppc_radix_geom {
	__u8 page_shift;
	__u8 level_bits[4];
	__u8 pad[3];
};

struct kvm_ppc_rmmu_info {
	struct kvm_ppc_radix_geom geometries[8];
	__u32 ap_encodings[8];
};

struct kvm_hyperv_exit {
	__u32 type;
	__u32 pad1;
	union {
		struct {
			__u32 msr;
			__u32 pad2;
			__u64 control;
			__u64 evt_page;
			__u64 msg_page;
		} synic;
		struct {
			__u64 input;
			__u64 result;
			__u64 params[2];
		} hcall;
		struct {
			__u32 msr;
			__u32 pad2;
			__u64 control;
			__u64 status;
			__u64 send_page;
			__u64 recv_page;
			__u64 pending_page;
		} syndbg;
	} u;
};

struct kvm_xen_exit {
	__u32 type;
	union {
		struct {
			__u32 longmode;
			__u32 cpl;
			__u64 input;
			__u64 result;
			__u64 params[6];
		} hcall;
	} u;
};

struct kvm_run {
	__u8 request_interrupt_window;
	__u8 immediate_exit;
	__u8 padding1[6];
	__u32 exit_reason;
	__u8 ready_for_interrupt_injection;
	__u8 if_flag;
	__u16 flags;
	__u64 cr8;
	__u64 apic_base;
	union {
		struct {
			__u64 hardware_exit_reason;
		} hw;
		struct {
			__u64 hardware_entry_failure_reason;
			__u32 cpu;
		} fail_entry;
		struct {
			__u32 exception;
			__u32 error_code;
		} ex;
		struct {
			__u8 direction;
			__u8 size;
			__u16 port;
			__u32 count;
			__u64 data_offset;
		} io;
		struct {
			struct kvm_debug_exit_arch arch;
		} debug;
		struct {
			__u64 phys_addr;
			__u8 data[8];
			__u32 len;
			__u8 is_write;
		} mmio;
		struct {
			__u64 nr;
			__u64 args[6];
			__u64 ret;
			__u32 longmode;
			__u32 pad;
		} hypercall;
		struct {
			__u64 rip;
			__u32 is_write;
			__u32 pad;
		} tpr_access;
		struct {
			__u8 icptcode;
			__u16 ipa;
			__u32 ipb;
		} s390_sieic;
		__u64 s390_reset_flags;
		struct {
			__u64 trans_exc_code;
			__u32 pgm_code;
		} s390_ucontrol;
		struct {
			__u32 dcrn;
			__u32 data;
			__u8 is_write;
		} dcr;
		struct {
			__u32 suberror;
			__u32 ndata;
			__u64 data[16];
		} internal;
		struct {
			__u32 suberror;
			__u32 ndata;
			__u64 flags;
			union {
				struct {
					__u8 insn_size;
					__u8 insn_bytes[15];
				};
			};
		} emulation_failure;
		struct {
			__u64 gprs[32];
		} osi;
		struct {
			__u64 nr;
			__u64 ret;
			__u64 args[9];
		} papr_hcall;
		struct {
			__u16 subchannel_id;
			__u16 subchannel_nr;
			__u32 io_int_parm;
			__u32 io_int_word;
			__u32 ipb;
			__u8 dequeued;
		} s390_tsch;
		struct {
			__u32 epr;
		} epr;
		struct {
			__u32 type;
			__u64 flags;
		} system_event;
		struct {
			__u64 addr;
			__u8 ar;
			__u8 reserved;
			__u8 fc;
			__u8 sel1;
			__u16 sel2;
		} s390_stsi;
		struct {
			__u8 vector;
		} eoi;
		struct kvm_hyperv_exit hyperv;
		struct {
			__u64 esr_iss;
			__u64 fault_ipa;
		} arm_nisv;
		struct {
			__u8 error;
			__u8 pad[7];
			__u32 reason;
			__u32 index;
			__u64 data;
		} msr;
		struct kvm_xen_exit xen;
		char padding[256];
	};
	__u64 kvm_valid_regs;
	__u64 kvm_dirty_regs;
	union {
		struct kvm_sync_regs regs;
		char padding[2048];
	} s;
};

struct kvm_dirty_log {
	__u32 slot;
	__u32 padding1;
	union {
		void *dirty_bitmap;
		__u64 padding2;
	};
};

struct kvm_ppc_one_page_size {
	__u32 page_shift;
	__u32 pte_enc;
};

struct kvm_ppc_one_seg_page_size {
	__u32 page_shift;
	__u32 slb_enc;
	struct kvm_ppc_one_page_size enc[8];
};

struct kvm_ppc_smmu_info {
	__u64 flags;
	__u32 slb_size;
	__u16 data_keys;
	__u16 instr_keys;
	struct kvm_ppc_one_seg_page_size sps[8];
};

struct kvm_device_attr {
	__u32 flags;
	__u32 group;
	__u64 attr;
	__u64 addr;
};

struct kvm_dirty_gfn {
	__u32 flags;
	__u32 slot;
	__u64 offset;
};

struct kvm_stats_header {
	__u32 flags;
	__u32 name_size;
	__u32 num_desc;
	__u32 id_offset;
	__u32 desc_offset;
	__u32 data_offset;
};

struct kvm_stats_desc {
	__u32 flags;
	__s16 exponent;
	__u16 size;
	__u32 offset;
	__u32 bucket_size;
	char name[0];
};

struct kvm_vm_stat {
	struct kvm_vm_stat_generic generic;
	u64 num_2M_pages;
	u64 num_1G_pages;
};

struct kvm_memslots {
	u64 generation;
	atomic_long_t last_used_slot;
	struct rb_root_cached hva_tree;
	struct rb_root gfn_tree;
	struct hlist_head id_hash[128];
	int node_idx;
};

struct revmap_entry;

struct kvm_hpt_info {
	long unsigned int virt;
	struct revmap_entry *rev;
	u32 order;
	int cma;
};

struct kvm_resize_hpt;

struct kvmppc_xics;

struct kvmppc_xive;

struct kvmppc_passthru_irqmap;

struct kvmppc_ops;

struct kvm_arch {
	unsigned int lpid;
	unsigned int smt_mode;
	unsigned int emul_smt_mode;
	unsigned int tlb_sets;
	struct kvm_hpt_info hpt;
	atomic64_t mmio_update;
	unsigned int host_lpid;
	long unsigned int host_lpcr;
	long unsigned int sdr1;
	long unsigned int host_sdr1;
	long unsigned int lpcr;
	long unsigned int vrma_slb_v;
	int mmu_ready;
	atomic_t vcpus_running;
	u32 online_vcores;
	atomic_t hpte_mod_interest;
	cpumask_t need_tlb_flush;
	cpumask_t cpu_in_guest;
	u8 radix;
	u8 fwnmi_enabled;
	u8 secure_guest;
	u8 svm_enabled;
	bool threads_indep;
	bool nested_enable;
	bool dawr1_enabled;
	pgd_t *pgtable;
	u64 process_table;
	struct dentry *debugfs_dir;
	struct kvm_resize_hpt *resize_hpt;
	struct list_head spapr_tce_tables;
	struct list_head rtas_tokens;
	struct mutex rtas_token_lock;
	long unsigned int enabled_hcalls[5];
	struct kvmppc_xics *xics;
	struct kvmppc_xics *xics_device;
	struct kvmppc_xive *xive;
	struct {
		struct kvmppc_xive *native;
		struct kvmppc_xive *xics_on_xive;
	} xive_devices;
	struct kvmppc_passthru_irqmap *pimap;
	struct kvmppc_ops *kvm_ops;
	struct mutex uvmem_lock;
	struct list_head uvmem_pfns;
	struct mutex mmu_setup_lock;
	u64 l1_ptcr;
	int max_nested_lpid;
	struct kvm_nested_guest *nested_guests[4096];
	struct kvmppc_vcore *vcores[2048];
};

struct kvm_irq_routing_table;

struct kvm_io_bus;

struct kvm_stat_data;

struct kvm {
	spinlock_t mmu_lock;
	struct mutex slots_lock;
	struct mutex slots_arch_lock;
	struct mm_struct *mm;
	long unsigned int nr_memslot_pages;
	struct kvm_memslots __memslots[2];
	struct kvm_memslots *memslots[1];
	struct xarray vcpu_array;
	spinlock_t mn_invalidate_lock;
	long unsigned int mn_active_invalidate_count;
	struct rcuwait mn_memslots_update_rcuwait;
	spinlock_t gpc_lock;
	struct list_head gpc_list;
	atomic_t online_vcpus;
	int created_vcpus;
	int last_boosted_vcpu;
	struct list_head vm_list;
	struct mutex lock;
	struct kvm_io_bus *buses[4];
	struct {
		spinlock_t lock;
		struct list_head items;
		struct list_head resampler_list;
		struct mutex resampler_lock;
	} irqfds;
	struct list_head ioeventfds;
	struct kvm_vm_stat stat;
	struct kvm_arch arch;
	refcount_t users_count;
	struct mutex irq_lock;
	struct kvm_irq_routing_table *irq_routing;
	struct hlist_head irq_ack_notifier_list;
	struct mmu_notifier mmu_notifier;
	long unsigned int mmu_notifier_seq;
	long int mmu_notifier_count;
	long unsigned int mmu_notifier_range_start;
	long unsigned int mmu_notifier_range_end;
	struct list_head devices;
	u64 manual_dirty_log_protect;
	struct dentry *debugfs_dentry;
	struct kvm_stat_data **debugfs_stat_data;
	struct srcu_struct srcu;
	struct srcu_struct irq_srcu;
	pid_t userspace_pid;
	unsigned int max_halt_poll_ns;
	u32 dirty_ring_size;
	bool vm_bugged;
	bool vm_dead;
	char stats_id[48];
};

struct kvm_device;

struct kvm_device_ops {
	const char *name;
	int (*create)(struct kvm_device *, u32);
	void (*init)(struct kvm_device *);
	void (*destroy)(struct kvm_device *);
	void (*release)(struct kvm_device *);
	int (*set_attr)(struct kvm_device *, struct kvm_device_attr *);
	int (*get_attr)(struct kvm_device *, struct kvm_device_attr *);
	int (*has_attr)(struct kvm_device *, struct kvm_device_attr *);
	long int (*ioctl)(struct kvm_device *, unsigned int, long unsigned int);
	int (*mmap)(struct kvm_device *, struct vm_area_struct *);
};

struct revmap_entry {
	long unsigned int guest_rpte;
	unsigned int forw;
	unsigned int back;
};

struct kvmppc_irq_map {
	u32 r_hwirq;
	u32 v_hwirq;
	struct irq_desc *desc;
};

struct kvmppc_passthru_irqmap {
	int n_mapped;
	struct kvmppc_irq_map mapped[1024];
};

enum kvm_mr_change {
	KVM_MR_CREATE = 0,
	KVM_MR_DELETE = 1,
	KVM_MR_MOVE = 2,
	KVM_MR_FLAGS_ONLY = 3,
};

union kvmppc_one_reg;

struct kvm_gfn_range;

struct kvmppc_ops {
	struct module *owner;
	int (*get_sregs)(struct kvm_vcpu *, struct kvm_sregs *);
	int (*set_sregs)(struct kvm_vcpu *, struct kvm_sregs *);
	int (*get_one_reg)(struct kvm_vcpu *, u64, union kvmppc_one_reg *);
	int (*set_one_reg)(struct kvm_vcpu *, u64, union kvmppc_one_reg *);
	void (*vcpu_load)(struct kvm_vcpu *, int);
	void (*vcpu_put)(struct kvm_vcpu *);
	void (*inject_interrupt)(struct kvm_vcpu *, int, u64);
	void (*set_msr)(struct kvm_vcpu *, u64);
	int (*vcpu_run)(struct kvm_vcpu *);
	int (*vcpu_create)(struct kvm_vcpu *);
	void (*vcpu_free)(struct kvm_vcpu *);
	int (*check_requests)(struct kvm_vcpu *);
	int (*get_dirty_log)(struct kvm *, struct kvm_dirty_log *);
	void (*flush_memslot)(struct kvm *, struct kvm_memory_slot *);
	int (*prepare_memory_region)(struct kvm *, const struct kvm_memory_slot *, struct kvm_memory_slot *, enum kvm_mr_change);
	void (*commit_memory_region)(struct kvm *, struct kvm_memory_slot *, const struct kvm_memory_slot *, enum kvm_mr_change);
	bool (*unmap_gfn_range)(struct kvm *, struct kvm_gfn_range *);
	bool (*age_gfn)(struct kvm *, struct kvm_gfn_range *);
	bool (*test_age_gfn)(struct kvm *, struct kvm_gfn_range *);
	bool (*set_spte_gfn)(struct kvm *, struct kvm_gfn_range *);
	void (*free_memslot)(struct kvm_memory_slot *);
	int (*init_vm)(struct kvm *);
	void (*destroy_vm)(struct kvm *);
	int (*get_smmu_info)(struct kvm *, struct kvm_ppc_smmu_info *);
	int (*emulate_op)(struct kvm_vcpu *, unsigned int, int *);
	int (*emulate_mtspr)(struct kvm_vcpu *, int, ulong);
	int (*emulate_mfspr)(struct kvm_vcpu *, int, ulong *);
	void (*fast_vcpu_kick)(struct kvm_vcpu *);
	long int (*arch_vm_ioctl)(struct file *, unsigned int, long unsigned int);
	int (*hcall_implemented)(long unsigned int);
	int (*irq_bypass_add_producer)(struct irq_bypass_consumer *, struct irq_bypass_producer *);
	void (*irq_bypass_del_producer)(struct irq_bypass_consumer *, struct irq_bypass_producer *);
	int (*configure_mmu)(struct kvm *, struct kvm_ppc_mmuv3_cfg *);
	int (*get_rmmu_info)(struct kvm *, struct kvm_ppc_rmmu_info *);
	int (*set_smt_mode)(struct kvm *, long unsigned int, long unsigned int);
	void (*giveup_ext)(struct kvm_vcpu *, ulong);
	int (*enable_nested)(struct kvm *);
	int (*load_from_eaddr)(struct kvm_vcpu *, ulong *, void *, int);
	int (*store_to_eaddr)(struct kvm_vcpu *, ulong *, void *, int);
	int (*enable_svm)(struct kvm *);
	int (*svm_off)(struct kvm *);
	bool (*hash_v3_possible)();
};

struct kvm_nested_guest {
	struct kvm *l1_host;
	int l1_lpid;
	int shadow_lpid;
	pgd_t *shadow_pgtable;
	u64 l1_gr_to_hr;
	u64 process_table;
	long int refcnt;
	struct mutex tlb_lock;
	struct kvm_nested_guest *next;
	cpumask_t need_tlb_flush;
	cpumask_t cpu_in_guest;
	short int prev_cpu[2048];
	u8 radix;
};

struct kvmppc_pte {
	ulong eaddr;
	u64 vpage;
	ulong raddr;
	bool may_read: 1;
	bool may_write: 1;
	bool may_execute: 1;
	long unsigned int wimg;
	long unsigned int rc;
	u8 page_size;
	u8 page_shift;
};

struct kvmppc_sid_map {
	u64 guest_vsid;
	u64 guest_esid;
	u64 host_vsid;
	bool valid: 1;
};

struct kvmppc_bat {
	u64 raw;
	u32 bepi;
	u32 bepi_mask;
	u32 brpn;
	u8 wimg;
	u8 pp;
	bool vs: 1;
	bool vp: 1;
};

struct kvmppc_vcpu_book3s {
	struct kvmppc_sid_map sid_map[512];
	struct {
		u64 esid;
		u64 vsid;
	} slb_shadow[64];
	u8 slb_shadow_max;
	struct kvmppc_bat ibat[8];
	struct kvmppc_bat dbat[8];
	u64 hid[6];
	u64 gqr[8];
	u64 sdr1;
	u64 hior;
	u64 msr_mask;
	u64 vtb;
	u64 proto_vsid_first;
	u64 proto_vsid_max;
	u64 proto_vsid_next;
	int context_id[1];
	bool hior_explicit;
	struct hlist_head hpte_hash_pte[8192];
	struct hlist_head hpte_hash_pte_long[4096];
	struct hlist_head hpte_hash_vpte[8192];
	struct hlist_head hpte_hash_vpte_long[32];
	struct hlist_head hpte_hash_vpte_64k[2048];
	int hpte_cache_count;
	spinlock_t mmu_lock;
};

struct kvm_io_device;

struct kvm_io_range {
	gpa_t addr;
	int len;
	struct kvm_io_device *dev;
};

struct kvm_io_bus {
	int dev_count;
	int ioeventfd_count;
	struct kvm_io_range range[0];
};

struct kvm_gfn_range {
	struct kvm_memory_slot *slot;
	gfn_t start;
	gfn_t end;
	pte_t pte;
	bool may_block;
};

enum kvm_stat_kind {
	KVM_STAT_VM = 0,
	KVM_STAT_VCPU = 1,
};

struct _kvm_stats_desc;

struct kvm_stat_data {
	struct kvm *kvm;
	const struct _kvm_stats_desc *desc;
	enum kvm_stat_kind kind;
};

struct _kvm_stats_desc {
	struct kvm_stats_desc desc;
	char name[48];
};

struct kvm_device {
	const struct kvm_device_ops *ops;
	struct kvm *kvm;
	void *private;
	struct list_head vm_node;
};

union kvmppc_one_reg {
	u32 wval;
	u64 dval;
	vector128 vval;
	u64 vsxval[2];
	u32 vsx32val[4];
	u16 vsx16val[8];
	u8 vsx8val[16];
	struct {
		u64 addr;
		u64 length;
	} vpaval;
	u64 xive_timaval[2];
};

union kvmppc_rm_state {
	long unsigned int raw;
	struct {
		u32 in_host;
		u32 rm_action;
	};
};

struct kvmppc_host_rm_core {
	union kvmppc_rm_state rm_state;
	void *rm_data;
	char pad[112];
};

struct kvmppc_host_rm_ops {
	struct kvmppc_host_rm_core *rm_core;
	void (*vcpu_kick)(struct kvm_vcpu *);
};

enum jump_label_type {
	JUMP_LABEL_NOP = 0,
	JUMP_LABEL_JMP = 1,
};

struct io_tlb_area;

struct io_tlb_slot;

struct io_tlb_mem {
	phys_addr_t start;
	phys_addr_t end;
	void *vaddr;
	long unsigned int nslabs;
	long unsigned int used;
	struct dentry *debugfs;
	bool late_alloc;
	bool force_bounce;
	bool for_alloc;
	unsigned int nareas;
	unsigned int area_nslabs;
	struct io_tlb_area *areas;
	struct io_tlb_slot *slots;
};

enum kgdb_bpstate {
	BP_UNDEFINED = 0,
	BP_REMOVED = 1,
	BP_SET = 2,
	BP_ACTIVE = 3,
};

struct kgdb_bkpt {
	long unsigned int bpt_addr;
	unsigned char saved_instr[4];
	enum kgdb_bptype type;
	enum kgdb_bpstate state;
};

struct hard_trap_info {
	unsigned int tt;
	unsigned char signo;
};

struct sched_domain_shared {
	atomic_t ref;
	atomic_t nr_busy_cpus;
	int has_idle_cores;
	int nr_idle_scan;
};

struct sched_group;

struct sched_domain {
	struct sched_domain *parent;
	struct sched_domain *child;
	struct sched_group *groups;
	long unsigned int min_interval;
	long unsigned int max_interval;
	unsigned int busy_factor;
	unsigned int imbalance_pct;
	unsigned int cache_nice_tries;
	union {
		unsigned int imb_numa_nr;
		struct {
			unsigned int busy_idx;
		} rh_kabi_hidden_89;
		union {		};
	};
	unsigned int rh_reserved_idle_idx;
	unsigned int rh_reserved_newidle_idx;
	unsigned int rh_reserved_wake_idx;
	unsigned int rh_reserved_forkexec_idx;
	unsigned int rh_reserved_smt_gain;
	int nohz_idle;
	int flags;
	int level;
	long unsigned int last_balance;
	unsigned int balance_interval;
	unsigned int nr_balance_failed;
	u64 max_newidle_lb_cost;
	long unsigned int next_decay_max_lb_cost;
	u64 avg_scan_cost;
	unsigned int lb_count[3];
	unsigned int lb_failed[3];
	unsigned int lb_balanced[3];
	unsigned int lb_imbalance[3];
	unsigned int lb_gained[3];
	unsigned int lb_hot_gained[3];
	unsigned int lb_nobusyg[3];
	unsigned int lb_nobusyq[3];
	unsigned int alb_count;
	unsigned int alb_failed;
	unsigned int alb_pushed;
	unsigned int sbe_count;
	unsigned int sbe_balanced;
	unsigned int sbe_pushed;
	unsigned int sbf_count;
	unsigned int sbf_balanced;
	unsigned int sbf_pushed;
	unsigned int ttwu_wake_remote;
	unsigned int ttwu_move_affine;
	unsigned int ttwu_move_balance;
	char *name;
	union {
		void *private;
		struct callback_head rcu;
	};
	struct sched_domain_shared *shared;
	unsigned int span_weight;
	long unsigned int span[0];
};

typedef const struct cpumask * (*sched_domain_mask_f)(int);

typedef int (*sched_domain_flags_f)();

struct sched_group_capacity;

struct sd_data {
	struct sched_domain **sd;
	struct sched_domain_shared **sds;
	struct sched_group **sg;
	struct sched_group_capacity **sgc;
};

struct sched_domain_topology_level {
	sched_domain_mask_f mask;
	sched_domain_flags_f sd_flags;
	int flags;
	int numa_level;
	struct sd_data data;
	char *name;
};

enum kvm_bus {
	KVM_MMIO_BUS = 0,
	KVM_PIO_BUS = 1,
	KVM_VIRTIO_CCW_NOTIFY_BUS = 2,
	KVM_FAST_MMIO_BUS = 3,
	KVM_NR_BUSES = 4,
};

enum {
	smt_idx = 0,
	cache_idx = 1,
	mc_idx = 2,
	die_idx = 3,
};

struct thread_groups {
	unsigned int property;
	unsigned int nr_groups;
	unsigned int threads_per_group;
	unsigned int thread_list[8];
};

struct thread_groups_list {
	unsigned int nr_properties;
	struct thread_groups property_tgs[2];
};

struct cpu_messages {
	long int messages;
};

struct kretprobe_instance;

typedef int (*kretprobe_handler_t)(struct kretprobe_instance *, struct pt_regs *);

struct kretprobe;

struct kretprobe_instance {
	struct hlist_node hlist;
	struct kretprobe *rp;
	kprobe_opcode_t *ret_addr;
	struct task_struct *task;
	void *fp;
	char data[0];
};

struct kretprobe {
	struct kprobe kp;
	kretprobe_handler_t handler;
	kretprobe_handler_t entry_handler;
	int maxactive;
	int nmissed;
	size_t data_size;
	struct hlist_head free_instances;
	raw_spinlock_t lock;
};

struct arch_optimized_insn {
	kprobe_opcode_t copied_insn[1];
	kprobe_opcode_t *insn;
};

struct optimized_kprobe {
	struct kprobe kp;
	struct list_head list;
	struct arch_optimized_insn optinsn;
};

typedef ppc_opcode_t uprobe_opcode_t;

struct arch_uprobe {
	union {
		struct ppc_inst insn;
		struct ppc_inst ixol;
	};
};

enum rp_check {
	RP_CHECK_CALL = 0,
	RP_CHECK_CHAIN_CALL = 1,
	RP_CHECK_RET = 2,
};

struct plat_serial8250_port {
	long unsigned int iobase;
	void *membase;
	resource_size_t mapbase;
	unsigned int irq;
	long unsigned int irqflags;
	unsigned int uartclk;
	void *private_data;
	unsigned char regshift;
	unsigned char iotype;
	unsigned char hub6;
	upf_t flags;
	unsigned int type;
	unsigned int (*serial_in)(struct uart_port *, int);
	void (*serial_out)(struct uart_port *, int, int);
	void (*set_termios)(struct uart_port *, struct ktermios *, struct ktermios *);
	void (*set_ldisc)(struct uart_port *, struct ktermios *);
	unsigned int (*get_mctrl)(struct uart_port *);
	int (*handle_irq)(struct uart_port *);
	void (*pm)(struct uart_port *, unsigned int, unsigned int);
	void (*handle_break)(struct uart_port *);
};

enum {
	PLAT8250_DEV_LEGACY = 4294967295,
	PLAT8250_DEV_PLATFORM = 0,
	PLAT8250_DEV_PLATFORM1 = 1,
	PLAT8250_DEV_PLATFORM2 = 2,
	PLAT8250_DEV_FOURPORT = 3,
	PLAT8250_DEV_ACCENT = 4,
	PLAT8250_DEV_BOCA = 5,
	PLAT8250_DEV_EXAR_ST16C554 = 6,
	PLAT8250_DEV_HUB6 = 7,
	PLAT8250_DEV_AU1X00 = 8,
	PLAT8250_DEV_SM501 = 9,
};

struct legacy_serial_info {
	struct device_node *np;
	unsigned int speed;
	unsigned int clock;
	int irq_check_parent;
	phys_addr_t taddr;
};

enum {
	PCI_REASSIGN_ALL_RSRC = 1,
	PCI_REASSIGN_ALL_BUS = 2,
	PCI_PROBE_ONLY = 4,
	PCI_CAN_SKIP_ISA_ALIGN = 8,
	PCI_ENABLE_PROC_DOMAINS = 16,
	PCI_COMPAT_DOMAIN_0 = 32,
	PCI_SCAN_ALL_PCIE_DEVS = 64,
};

struct vm_struct {
	struct vm_struct *next;
	void *addr;
	long unsigned int size;
	long unsigned int flags;
	struct page **pages;
	unsigned int nr_pages;
	phys_addr_t phys_addr;
	const void *caller;
};

struct pci_fixup {
	u16 vendor;
	u16 device;
	u32 class;
	unsigned int class_shift;
	void (*hook)(struct pci_dev *);
};

struct pci_address {
	u32 a_hi;
	u32 a_mid;
	u32 a_lo;
};

struct isa_address {
	u32 a_hi;
	u32 a_lo;
};

struct isa_range {
	struct isa_address isa_addr;
	struct pci_address pci_addr;
	unsigned int size;
};

enum {
	IRQ_TYPE_NONE = 0,
	IRQ_TYPE_EDGE_RISING = 1,
	IRQ_TYPE_EDGE_FALLING = 2,
	IRQ_TYPE_EDGE_BOTH = 3,
	IRQ_TYPE_LEVEL_HIGH = 4,
	IRQ_TYPE_LEVEL_LOW = 8,
	IRQ_TYPE_LEVEL_MASK = 12,
	IRQ_TYPE_SENSE_MASK = 15,
	IRQ_TYPE_DEFAULT = 15,
	IRQ_TYPE_PROBE = 16,
	IRQ_LEVEL = 256,
	IRQ_PER_CPU = 512,
	IRQ_NOPROBE = 1024,
	IRQ_NOREQUEST = 2048,
	IRQ_NOAUTOEN = 4096,
	IRQ_NO_BALANCING = 8192,
	IRQ_MOVE_PCNTXT = 16384,
	IRQ_NESTED_THREAD = 32768,
	IRQ_NOTHREAD = 65536,
	IRQ_PER_CPU_DEVID = 131072,
	IRQ_IS_POLLED = 262144,
	IRQ_DISABLE_UNLAZY = 524288,
	IRQ_HIDDEN = 1048576,
};

enum pci_mmap_state {
	pci_mmap_io = 0,
	pci_mmap_mem = 1,
};

struct pci_sriov {
	int pos;
	int nres;
	u32 cap;
	u16 ctrl;
	u16 total_VFs;
	u16 initial_VFs;
	u16 num_VFs;
	u16 offset;
	u16 stride;
	u16 vf_device;
	u32 pgsz;
	u8 link;
	u8 max_VF_buses;
	u16 driver_max_VFs;
	struct pci_dev *dev;
	struct pci_dev *self;
	u32 class;
	u8 hdr_type;
	u16 subsystem_vendor;
	u16 subsystem_device;
	resource_size_t barsz[6];
	bool drivers_autoprobe;
	long unsigned int rh_reserved1;
	long unsigned int rh_reserved2;
	long unsigned int rh_reserved3;
	long unsigned int rh_reserved4;
	long unsigned int rh_reserved5;
	long unsigned int rh_reserved6;
	long unsigned int rh_reserved7;
	long unsigned int rh_reserved8;
};

struct rcec_ea {
	u8 nextbusn;
	u8 lastbusn;
	u32 bitmap;
};

typedef u64 pci_bus_addr_t;

struct pci_bus_region {
	pci_bus_addr_t start;
	pci_bus_addr_t end;
};

struct of_bus;

struct of_pci_range_parser {
	struct device_node *node;
	struct of_bus *bus;
	const __be32 *range;
	const __be32 *end;
	int na;
	int ns;
	int pna;
	bool dma;
};

struct of_pci_range {
	union {
		u64 pci_addr;
		u64 bus_addr;
	};
	u64 cpu_addr;
	u64 size;
	u32 flags;
};

struct pci_intx_virq {
	int virq;
	struct kref kref;
	struct list_head list_node;
};

enum pci_fixup_pass {
	pci_fixup_early = 0,
	pci_fixup_header = 1,
	pci_fixup_final = 2,
	pci_fixup_enable = 3,
	pci_fixup_resume = 4,
	pci_fixup_suspend = 5,
	pci_fixup_resume_early = 6,
	pci_fixup_suspend_late = 7,
};

struct msi_controller {
	struct module *owner;
	struct device *dev;
	struct device_node *of_node;
	struct list_head list;
	int (*setup_irq)(struct msi_controller *, struct pci_dev *, struct msi_desc *);
	int (*setup_irqs)(struct msi_controller *, struct pci_dev *, int, int);
	void (*teardown_irq)(struct msi_controller *, unsigned int);
};

struct vmemmap_backing {
	struct vmemmap_backing *list;
	long unsigned int phys;
	long unsigned int virt_addr;
};

typedef void (*crash_shutdown_t)();

typedef __be64 fdt64_t;

typedef struct elf64_phdr Elf64_Phdr;

struct kexec_buf {
	struct kimage *image;
	void *buffer;
	long unsigned int bufsz;
	long unsigned int mem;
	long unsigned int memsz;
	long unsigned int buf_align;
	long unsigned int buf_min;
	long unsigned int buf_max;
	bool top_down;
};

struct umem_info {
	u64 *buf;
	u32 size;
	u32 max_entries;
	u32 idx;
	unsigned int nr_ranges;
	const struct crash_mem_range *ranges;
};

typedef __u32 __le32;

typedef __u64 __le64;

struct elf_info {
	const char *buffer;
	const struct elf64_hdr *ehdr;
	const struct elf64_phdr *proghdrs;
	struct elf64_shdr *sechdrs;
};

enum auditsc_class_t {
	AUDITSC_NATIVE = 0,
	AUDITSC_COMPAT = 1,
	AUDITSC_OPEN = 2,
	AUDITSC_OPENAT = 3,
	AUDITSC_SOCKETCALL = 4,
	AUDITSC_EXECVE = 5,
	AUDITSC_OPENAT2 = 6,
	AUDITSC_NVALS = 7,
};

struct dyn_arch_ftrace {
	struct module *mod;
};

enum {
	FTRACE_FL_ENABLED = 2147483648,
	FTRACE_FL_REGS = 1073741824,
	FTRACE_FL_REGS_EN = 536870912,
	FTRACE_FL_TRAMP = 268435456,
	FTRACE_FL_TRAMP_EN = 134217728,
	FTRACE_FL_IPMODIFY = 67108864,
	FTRACE_FL_DISABLED = 33554432,
	FTRACE_FL_DIRECT = 16777216,
	FTRACE_FL_DIRECT_EN = 8388608,
};

struct dyn_ftrace {
	long unsigned int ip;
	long unsigned int flags;
	struct dyn_arch_ftrace arch;
};

struct secvar_operations {
	int (*get)(const char *, uint64_t, u8 *, uint64_t *);
	int (*get_next)(const char *, uint64_t *, uint64_t);
	int (*set)(const char *, uint64_t, u8 *, uint64_t);
};

enum kobject_action {
	KOBJ_ADD = 0,
	KOBJ_REMOVE = 1,
	KOBJ_CHANGE = 2,
	KOBJ_MOVE = 3,
	KOBJ_ONLINE = 4,
	KOBJ_OFFLINE = 5,
	KOBJ_BIND = 6,
	KOBJ_UNBIND = 7,
	KOBJ_MAX = 8,
};

enum vm_fault_reason {
	VM_FAULT_OOM = 1,
	VM_FAULT_SIGBUS = 2,
	VM_FAULT_MAJOR = 4,
	VM_FAULT_WRITE = 8,
	VM_FAULT_HWPOISON = 16,
	VM_FAULT_HWPOISON_LARGE = 32,
	VM_FAULT_SIGSEGV = 64,
	VM_FAULT_NOPAGE = 256,
	VM_FAULT_LOCKED = 512,
	VM_FAULT_RETRY = 1024,
	VM_FAULT_FALLBACK = 2048,
	VM_FAULT_DONE_COW = 4096,
	VM_FAULT_NEEDDSYNC = 8192,
	VM_FAULT_COMPLETED = 16384,
	VM_FAULT_HINDEX_MASK = 983040,
};

struct mhp_params {
	struct vmem_altmap *altmap;
	pgprot_t pgprot;
};

typedef struct {
	__be64 pdbe;
} hugepd_t;

struct hugepage_subpool {
	spinlock_t lock;
	long int count;
	long int max_hpages;
	long int used_hpages;
	struct hstate *hstate;
	long int min_hpages;
	long int rsv_hpages;
};

struct hugetlbfs_sb_info {
	long int max_inodes;
	long int free_inodes;
	spinlock_t stat_lock;
	struct hstate *hstate;
	struct hugepage_subpool *spool;
	kuid_t uid;
	kgid_t gid;
	umode_t mode;
};

struct vm_unmapped_area_info {
	long unsigned int flags;
	long unsigned int length;
	long unsigned int low_limit;
	long unsigned int high_limit;
	long unsigned int align_mask;
	long unsigned int align_offset;
};

enum {
	MEMBARRIER_STATE_PRIVATE_EXPEDITED_READY = 1,
	MEMBARRIER_STATE_PRIVATE_EXPEDITED = 2,
	MEMBARRIER_STATE_GLOBAL_EXPEDITED_READY = 4,
	MEMBARRIER_STATE_GLOBAL_EXPEDITED = 8,
	MEMBARRIER_STATE_PRIVATE_EXPEDITED_SYNC_CORE_READY = 16,
	MEMBARRIER_STATE_PRIVATE_EXPEDITED_SYNC_CORE = 32,
};

struct of_drconf_cell_v1 {
	__be64 base_addr;
	__be32 drc_index;
	__be32 reserved;
	__be32 aa_index;
	__be32 flags;
};

struct of_drconf_cell_v2 {
	u32 seq_lmbs;
	u64 base_addr;
	u32 drc_index;
	u32 aa_index;
	u32 flags;
} __attribute__((packed));

typedef long unsigned int pte_basic_t;

struct trace_event_raw_hugepage_invalidate {
	struct trace_entry ent;
	long unsigned int addr;
	long unsigned int pte;
	char __data[0];
};

struct trace_event_raw_hugepage_set_pmd {
	struct trace_entry ent;
	long unsigned int addr;
	long unsigned int pmd;
	char __data[0];
};

struct trace_event_raw_hugepage_update {
	struct trace_entry ent;
	long unsigned int addr;
	long unsigned int pte;
	long unsigned int clr;
	long unsigned int set;
	char __data[0];
};

struct trace_event_raw_hugepage_splitting {
	struct trace_entry ent;
	long unsigned int addr;
	long unsigned int pte;
	char __data[0];
};

struct trace_event_data_offsets_hugepage_invalidate {};

struct trace_event_data_offsets_hugepage_set_pmd {};

struct trace_event_data_offsets_hugepage_update {};

struct trace_event_data_offsets_hugepage_splitting {};

typedef void (*btf_trace_hugepage_invalidate)(void *, long unsigned int, long unsigned int);

typedef void (*btf_trace_hugepage_set_pmd)(void *, long unsigned int, long unsigned int);

typedef void (*btf_trace_hugepage_update)(void *, long unsigned int, long unsigned int, long unsigned int, long unsigned int);

typedef void (*btf_trace_hugepage_splitting)(void *, long unsigned int, long unsigned int);

struct ps3_prealloc {
	const char *name;
	void *address;
	long unsigned int size;
	long unsigned int align;
};

enum slb_index {
	LINEAR_INDEX = 0,
	VMALLOC_INDEX = 1,
	KSTACK_INDEX = 2,
};

typedef unsigned int xa_mark_t;

enum xa_lock_type {
	XA_LOCK_IRQ = 1,
	XA_LOCK_BH = 2,
};

enum pgtable_index {
	PTE_INDEX = 0,
	PMD_INDEX = 1,
	PUD_INDEX = 2,
	PGD_INDEX = 3,
	HTLB_16M_INDEX = 4,
	HTLB_16G_INDEX = 5,
};

struct mmu_table_batch {
	struct callback_head rcu;
	unsigned int nr;
	void *tables[0];
};

struct mmu_gather_batch {
	struct mmu_gather_batch *next;
	unsigned int nr;
	unsigned int max;
	struct page *pages[0];
};

struct mmu_gather {
	struct mm_struct *mm;
	struct mmu_table_batch *batch;
	long unsigned int start;
	long unsigned int end;
	unsigned int fullmm: 1;
	unsigned int need_flush_all: 1;
	unsigned int freed_tables: 1;
	unsigned int cleared_ptes: 1;
	unsigned int cleared_pmds: 1;
	unsigned int cleared_puds: 1;
	unsigned int cleared_p4ds: 1;
	unsigned int vma_exec: 1;
	unsigned int vma_huge: 1;
	unsigned int vma_pfn: 1;
	unsigned int batch_count;
	struct mmu_gather_batch *active;
	struct mmu_gather_batch local;
	struct page *__pages[8];
	unsigned int page_size;
};

enum string_size_units {
	STRING_UNITS_10 = 0,
	STRING_UNITS_2 = 1,
};

struct tlbiel_pid {
	long unsigned int pid;
	long unsigned int ric;
};

struct tlbiel_va {
	long unsigned int pid;
	long unsigned int va;
	long unsigned int psize;
	long unsigned int ric;
};

struct tlbiel_va_range {
	long unsigned int pid;
	long unsigned int start;
	long unsigned int end;
	long unsigned int page_size;
	long unsigned int psize;
	bool also_pwc;
};

struct mm_walk;

struct mm_walk_ops {
	int (*pgd_entry)(pgd_t *, long unsigned int, long unsigned int, struct mm_walk *);
	int (*p4d_entry)(pgd_t *, long unsigned int, long unsigned int, struct mm_walk *);
	int (*pud_entry)(pud_t *, long unsigned int, long unsigned int, struct mm_walk *);
	int (*pmd_entry)(pmd_t *, long unsigned int, long unsigned int, struct mm_walk *);
	int (*pte_entry)(pte_t *, long unsigned int, long unsigned int, struct mm_walk *);
	int (*pte_hole)(long unsigned int, long unsigned int, int, struct mm_walk *);
	int (*hugetlb_entry)(pte_t *, long unsigned int, long unsigned int, long unsigned int, struct mm_walk *);
	int (*test_walk)(long unsigned int, long unsigned int, struct mm_walk *);
	int (*pre_vma)(long unsigned int, long unsigned int, struct mm_walk *);
	void (*post_vma)(struct mm_walk *);
};

enum page_walk_action {
	ACTION_SUBTREE = 0,
	ACTION_CONTINUE = 1,
	ACTION_AGAIN = 2,
};

struct mm_walk {
	const struct mm_walk_ops *ops;
	struct mm_struct *mm;
	struct vm_area_struct *vma;
	enum page_walk_action action;
	bool no_vma;
	void *private;
};

enum migrate_reason {
	MR_COMPACTION = 0,
	MR_MEMORY_FAILURE = 1,
	MR_MEMORY_HOTPLUG = 2,
	MR_SYSCALL = 3,
	MR_MEMPOLICY_MBIND = 4,
	MR_NUMA_MISPLACED = 5,
	MR_CONTIG_RANGE = 6,
	MR_LONGTERM_PIN = 7,
	MR_TYPES = 8,
};

struct mm_iommu_table_group_mem_t {
	struct list_head next;
	struct callback_head rcu;
	long unsigned int used;
	atomic64_t mapped;
	unsigned int pageshift;
	u64 ua;
	u64 entries;
	union {
		struct page **hpages;
		phys_addr_t *hpas;
	};
	u64 dev_hpa;
};

struct assoc_arrays {
	u32 n_arrays;
	u32 array_sz;
	const __be32 *arrays;
};

struct huge_bootmem_page {
	struct list_head list;
	struct hstate *hstate;
};

struct copro_slb {
	u64 esid;
	u64 vsid;
};

enum spu_utilization_state {
	SPU_UTIL_USER = 0,
	SPU_UTIL_SYSTEM = 1,
	SPU_UTIL_IOWAIT = 2,
	SPU_UTIL_IDLE_LOADED = 3,
	SPU_UTIL_MAX = 4,
};

struct cbe_spu_info {
	struct mutex list_mutex;
	struct list_head spus;
	int n_spus;
	int nr_active;
	atomic_t busy_spus;
	atomic_t reserved_spus;
};

struct fixup_entry {
	long unsigned int mask;
	long unsigned int value;
	long int start_off;
	long int end_off;
	long int alt_start_off;
	long int alt_end_off;
};

union vsx_reg {
	u8 b[16];
	u16 h[8];
	u32 w[4];
	long unsigned int d[2];
	float fp[4];
	double dp[2];
	__vector128 v;
};

typedef signed char unative_t[16];

enum {
	IRQ_SET_MASK_OK = 0,
	IRQ_SET_MASK_OK_NOCOPY = 1,
	IRQ_SET_MASK_OK_DONE = 2,
};

enum {
	IRQCHIP_SET_TYPE_MASKED = 1,
	IRQCHIP_EOI_IF_HANDLED = 2,
	IRQCHIP_MASK_ON_SUSPEND = 4,
	IRQCHIP_ONOFFLINE_ENABLED = 8,
	IRQCHIP_SKIP_SET_WAKE = 16,
	IRQCHIP_ONESHOT_SAFE = 32,
	IRQCHIP_EOI_THREADED = 64,
	IRQCHIP_SUPPORTS_LEVEL_MSI = 128,
	IRQCHIP_SUPPORTS_NMI = 256,
	IRQCHIP_ENABLE_WAKEUP_ON_SUSPEND = 512,
	IRQCHIP_GIC = 1024,
};

struct syscore_ops {
	struct list_head node;
	int (*suspend)();
	void (*resume)();
	void (*shutdown)();
};

struct msi_bitmap {
	struct device_node *of_node;
	long unsigned int *bitmap;
	spinlock_t lock;
	unsigned int irq_count;
	bool bitmap_from_slab;
};

enum mpic_reg_type {
	mpic_access_mmio_le = 0,
	mpic_access_mmio_be = 1,
};

struct mpic_reg_bank {
	u32 *base;
};

struct mpic_irq_save {
	u32 vecprio;
	u32 dest;
};

struct mpic {
	struct device_node *node;
	struct irq_domain *irqhost;
	struct irq_chip hc_irq;
	struct irq_chip hc_ipi;
	struct irq_chip hc_tm;
	struct irq_chip hc_err;
	const char *name;
	unsigned int flags;
	unsigned int isu_size;
	unsigned int isu_shift;
	unsigned int isu_mask;
	unsigned int num_sources;
	unsigned int ipi_vecs[4];
	unsigned int timer_vecs[8];
	unsigned int err_int_vecs[32];
	unsigned int spurious_vec;
	enum mpic_reg_type reg_type;
	phys_addr_t paddr;
	struct mpic_reg_bank thiscpuregs;
	struct mpic_reg_bank gregs;
	struct mpic_reg_bank tmregs;
	struct mpic_reg_bank cpuregs[32];
	struct mpic_reg_bank isus[32];
	u32 *err_regs;
	long unsigned int *protected;
	struct msi_bitmap msi_bitmap;
	struct mpic *next;
	struct mpic_irq_save *save_data;
};

struct gpio_chip;

struct gpio_irq_chip {
	struct irq_chip *chip;
	struct irq_domain *domain;
	const struct irq_domain_ops *domain_ops;
	irq_flow_handler_t handler;
	unsigned int default_type;
	struct lock_class_key *lock_key;
	struct lock_class_key *request_key;
	irq_flow_handler_t parent_handler;
	void *parent_handler_data;
	unsigned int num_parents;
	unsigned int *parents;
	unsigned int *map;
	bool threaded;
	int (*init_hw)(struct gpio_chip *);
	void (*init_valid_mask)(struct gpio_chip *, long unsigned int *, unsigned int);
	long unsigned int *valid_mask;
	unsigned int first;
	void (*irq_enable)(struct irq_data *);
	void (*irq_disable)(struct irq_data *);
};

struct gpio_device;

struct gpio_chip {
	const char *label;
	struct gpio_device *gpiodev;
	struct device *parent;
	struct module *owner;
	int (*request)(struct gpio_chip *, unsigned int);
	void (*free)(struct gpio_chip *, unsigned int);
	int (*get_direction)(struct gpio_chip *, unsigned int);
	int (*direction_input)(struct gpio_chip *, unsigned int);
	int (*direction_output)(struct gpio_chip *, unsigned int, int);
	int (*get)(struct gpio_chip *, unsigned int);
	int (*get_multiple)(struct gpio_chip *, long unsigned int *, long unsigned int *);
	void (*set)(struct gpio_chip *, unsigned int, int);
	void (*set_multiple)(struct gpio_chip *, long unsigned int *, long unsigned int *);
	int (*set_config)(struct gpio_chip *, unsigned int, long unsigned int);
	int (*to_irq)(struct gpio_chip *, unsigned int);
	void (*dbg_show)(struct seq_file *, struct gpio_chip *);
	int (*init_valid_mask)(struct gpio_chip *, long unsigned int *, unsigned int);
	int (*add_pin_ranges)(struct gpio_chip *);
	int base;
	u16 ngpio;
	const char * const *names;
	bool can_sleep;
	struct gpio_irq_chip irq;
	long unsigned int *valid_mask;
	struct device_node *of_node;
	unsigned int of_gpio_n_cells;
	int (*of_xlate)(struct gpio_chip *, const struct of_phandle_args *, u32 *);
};

struct of_mm_gpio_chip {
	struct gpio_chip gc;
	void (*save_regs)(struct of_mm_gpio_chip *);
	void *regs;
};

struct u8_gpio_chip {
	struct of_mm_gpio_chip mm_gc;
	spinlock_t lock;
	u8 data;
};

struct debugfs_blob_wrapper {
	void *data;
	long unsigned int size;
};

typedef void *scom_map_t;

struct scom_controller {
	scom_map_t (*map)(struct device_node *, u64, u64);
	void (*unmap)(scom_map_t);
	int (*read)(scom_map_t, u64, u64 *);
	int (*write)(scom_map_t, u64, u64);
};

struct scom_debug_entry {
	struct device_node *dn;
	struct debugfs_blob_wrapper path;
	char name[16];
};

struct icp_ops {
	unsigned int (*get_irq)();
	void (*eoi)(struct irq_data *);
	void (*set_priority)(unsigned char);
	void (*teardown_cpu)();
	void (*flush_ipi)();
	void (*cause_ipi)(int);
	irq_handler_t ipi_action;
};

struct ics {
	struct list_head link;
	int (*map)(struct ics *, unsigned int);
	void (*mask_unknown)(struct ics *, long unsigned int);
	long int (*get_server)(struct ics *, long unsigned int);
	int (*host_match)(struct ics *, struct device_node *);
	char data[0];
};

struct xics_cppr {
	unsigned char stack[3];
	int index;
};

struct icp_ipl {
	union {
		u32 word;
		u8 bytes[4];
	} xirr_poll;
	union {
		u32 word;
		u8 bytes[4];
	} xirr;
	u32 dummy;
	union {
		u32 word;
		u8 bytes[4];
	} qirr;
	u32 link_a;
	u32 link_b;
	u32 link_c;
};

typedef s8 int8_t;

typedef s16 int16_t;

typedef s64 int64_t;

struct xive_irq_data {
	u64 flags;
	u64 eoi_page;
	void *eoi_mmio;
	u64 trig_page;
	void *trig_mmio;
	u32 esb_shift;
	int src_chip;
	u32 hw_irq;
	int target;
	bool saved_p;
	bool stale_p;
};

struct xive_q {
	__be32 *qpage;
	u32 msk;
	u32 idx;
	u32 toggle;
	u64 eoi_phys;
	u32 esc_irq;
	atomic_t count;
	atomic_t pending_count;
	u64 guest_qaddr;
	u32 guest_qshift;
};

struct xive_cpu {
	u32 hw_ipi;
	struct xive_irq_data ipi_data;
	int chip_id;
	struct xive_q queue[8];
	u8 pending_prio;
	u8 cppr;
};

struct xive_ops {
	int (*populate_irq_data)(u32, struct xive_irq_data *);
	int (*configure_irq)(u32, u32, u8, u32);
	int (*get_irq_config)(u32, u32 *, u8 *, u32 *);
	int (*setup_queue)(unsigned int, struct xive_cpu *, u8);
	void (*cleanup_queue)(unsigned int, struct xive_cpu *, u8);
	void (*setup_cpu)(unsigned int, struct xive_cpu *);
	void (*teardown_cpu)(unsigned int, struct xive_cpu *);
	bool (*match)(struct device_node *);
	void (*shutdown)();
	void (*update_pending)(struct xive_cpu *);
	void (*sync_source)(u32);
	u64 (*esb_rw)(u32, u32, u64, bool);
	int (*get_ipi)(unsigned int, struct xive_cpu *);
	void (*put_ipi)(unsigned int, struct xive_cpu *);
	int (*debug_show)(struct seq_file *, void *);
	const char *name;
};

enum {
	OPAL_XIVE_MODE_EMU = 0,
	OPAL_XIVE_MODE_EXPL = 1,
};

enum {
	OPAL_XIVE_IRQ_TRIGGER_PAGE = 1,
	OPAL_XIVE_IRQ_STORE_EOI = 2,
	OPAL_XIVE_IRQ_LSI = 4,
	OPAL_XIVE_IRQ_SHIFT_BUG = 8,
	OPAL_XIVE_IRQ_MASK_VIA_FW = 16,
	OPAL_XIVE_IRQ_EOI_VIA_FW = 32,
};

enum {
	OPAL_XIVE_EQ_ENABLED = 1,
	OPAL_XIVE_EQ_ALWAYS_NOTIFY = 2,
	OPAL_XIVE_EQ_ESCALATE = 4,
};

enum {
	OPAL_XIVE_VP_ENABLED = 1,
	OPAL_XIVE_VP_SINGLE_ESCALATION = 2,
};

enum {
	XIVE_SYNC_EAS = 1,
	XIVE_SYNC_QUEUE = 2,
};

struct xive_irq_bitmap {
	long unsigned int *bitmap;
	unsigned int base;
	unsigned int count;
	spinlock_t lock;
	struct list_head list;
};

struct plist_head {
	struct list_head node_list;
};

enum pm_qos_type {
	PM_QOS_UNITIALIZED = 0,
	PM_QOS_MAX = 1,
	PM_QOS_MIN = 2,
};

struct pm_qos_constraints {
	struct plist_head list;
	s32 target_value;
	s32 default_value;
	s32 no_constraint_value;
	enum pm_qos_type type;
	struct blocking_notifier_head *notifiers;
};

struct freq_constraints {
	struct pm_qos_constraints min_freq;
	struct blocking_notifier_head min_freq_notifiers;
	struct pm_qos_constraints max_freq;
	struct blocking_notifier_head max_freq_notifiers;
};

struct pm_qos_flags {
	struct list_head list;
	s32 effective_flags;
};

struct dev_pm_qos_request;

struct dev_pm_qos {
	struct pm_qos_constraints resume_latency;
	struct pm_qos_constraints latency_tolerance;
	struct freq_constraints freq;
	struct pm_qos_flags flags;
	struct dev_pm_qos_request *resume_latency_req;
	struct dev_pm_qos_request *latency_tolerance_req;
	struct dev_pm_qos_request *flags_req;
};

struct clk;

struct pm_qos_flags_request {
	struct list_head node;
	s32 flags;
};

enum dev_pm_qos_req_type {
	DEV_PM_QOS_RESUME_LATENCY = 1,
	DEV_PM_QOS_LATENCY_TOLERANCE = 2,
	DEV_PM_QOS_MIN_FREQUENCY = 3,
	DEV_PM_QOS_MAX_FREQUENCY = 4,
	DEV_PM_QOS_FLAGS = 5,
};

enum freq_qos_req_type {
	FREQ_QOS_MIN = 1,
	FREQ_QOS_MAX = 2,
};

struct freq_qos_request {
	enum freq_qos_req_type type;
	struct plist_node pnode;
	struct freq_constraints *qos;
};

struct dev_pm_qos_request {
	enum dev_pm_qos_req_type type;
	union {
		struct plist_node pnode;
		struct pm_qos_flags_request flr;
		struct freq_qos_request freq;
	} data;
	struct device *dev;
};

enum cpufreq_table_sorting {
	CPUFREQ_TABLE_UNSORTED = 0,
	CPUFREQ_TABLE_SORTED_ASCENDING = 1,
	CPUFREQ_TABLE_SORTED_DESCENDING = 2,
};

struct cpufreq_cpuinfo {
	unsigned int max_freq;
	unsigned int min_freq;
	unsigned int transition_latency;
};

struct cpufreq_governor;

struct cpufreq_frequency_table;

struct cpufreq_stats;

struct thermal_cooling_device;

struct cpufreq_policy {
	cpumask_var_t cpus;
	cpumask_var_t related_cpus;
	cpumask_var_t real_cpus;
	unsigned int shared_type;
	unsigned int cpu;
	struct clk *clk;
	struct cpufreq_cpuinfo cpuinfo;
	unsigned int min;
	unsigned int max;
	unsigned int cur;
	unsigned int restore_freq;
	unsigned int suspend_freq;
	unsigned int policy;
	unsigned int last_policy;
	struct cpufreq_governor *governor;
	void *governor_data;
	char last_governor[16];
	struct work_struct update;
	struct freq_constraints constraints;
	struct freq_qos_request *min_freq_req;
	struct freq_qos_request *max_freq_req;
	struct cpufreq_frequency_table *freq_table;
	enum cpufreq_table_sorting freq_table_sorted;
	struct list_head policy_list;
	struct kobject kobj;
	struct completion kobj_unregister;
	struct rw_semaphore rwsem;
	bool fast_switch_possible;
	bool fast_switch_enabled;
	bool strict_target;
	unsigned int transition_delay_us;
	bool dvfs_possible_from_any_cpu;
	unsigned int cached_target_freq;
	int cached_resolved_idx;
	bool transition_ongoing;
	spinlock_t transition_lock;
	wait_queue_head_t transition_wait;
	struct task_struct *transition_task;
	struct cpufreq_stats *stats;
	void *driver_data;
	struct thermal_cooling_device *cdev;
	struct notifier_block nb_min;
	struct notifier_block nb_max;
};

struct cpufreq_governor {
	char name[16];
	int (*init)(struct cpufreq_policy *);
	void (*exit)(struct cpufreq_policy *);
	int (*start)(struct cpufreq_policy *);
	void (*stop)(struct cpufreq_policy *);
	void (*limits)(struct cpufreq_policy *);
	ssize_t (*show_setspeed)(struct cpufreq_policy *, char *);
	int (*store_setspeed)(struct cpufreq_policy *, unsigned int);
	struct list_head governor_list;
	struct module *owner;
	u8 flags;
};

struct cpufreq_frequency_table {
	unsigned int flags;
	unsigned int driver_data;
	unsigned int frequency;
};

struct freq_attr {
	struct attribute attr;
	ssize_t (*show)(struct cpufreq_policy *, char *);
	ssize_t (*store)(struct cpufreq_policy *, const char *, size_t);
};

enum OpalThreadStatus {
	OPAL_THREAD_INACTIVE = 0,
	OPAL_THREAD_STARTED = 1,
	OPAL_THREAD_UNAVAILABLE = 2,
};

enum {
	OPAL_REINIT_CPUS_HILE_BE = 1,
	OPAL_REINIT_CPUS_HILE_LE = 2,
	OPAL_REINIT_CPUS_MMU_HASH = 4,
	OPAL_REINIT_CPUS_MMU_RADIX = 8,
	OPAL_REINIT_CPUS_TM_SUSPEND_DISABLED = 16,
};

enum {
	OPAL_REBOOT_NORMAL = 0,
	OPAL_REBOOT_PLATFORM_ERROR = 1,
	OPAL_REBOOT_FULL_IPL = 2,
	OPAL_REBOOT_MPIPL = 3,
};

enum OpalPendingState {
	OPAL_EVENT_OPAL_INTERNAL = 1,
	OPAL_EVENT_NVRAM = 2,
	OPAL_EVENT_RTC = 4,
	OPAL_EVENT_CONSOLE_OUTPUT = 8,
	OPAL_EVENT_CONSOLE_INPUT = 16,
	OPAL_EVENT_ERROR_LOG_AVAIL = 32,
	OPAL_EVENT_ERROR_LOG = 64,
	OPAL_EVENT_EPOW = 128,
	OPAL_EVENT_LED_STATUS = 256,
	OPAL_EVENT_PCI_ERROR = 512,
	OPAL_EVENT_DUMP_AVAIL = 1024,
	OPAL_EVENT_MSG_PENDING = 2048,
};

enum opal_msg_type {
	OPAL_MSG_ASYNC_COMP = 0,
	OPAL_MSG_MEM_ERR = 1,
	OPAL_MSG_EPOW = 2,
	OPAL_MSG_SHUTDOWN = 3,
	OPAL_MSG_HMI_EVT = 4,
	OPAL_MSG_DPO = 5,
	OPAL_MSG_PRD = 6,
	OPAL_MSG_OCC = 7,
	OPAL_MSG_PRD2 = 8,
	OPAL_MSG_TYPE_MAX = 9,
};

struct opal_msg {
	__be32 msg_type;
	__be32 reserved;
	__be64 params[8];
};

enum {
	OPAL_HMI_FLAGS_TB_RESYNC = 1,
	OPAL_HMI_FLAGS_DEC_LOST = 2,
	OPAL_HMI_FLAGS_HDEC_LOST = 4,
	OPAL_HMI_FLAGS_TOD_TB_FAIL = 8,
	OPAL_HMI_FLAGS_NEW_EVENT = 0,
};

struct opal_sg_entry {
	__be64 data;
	__be64 length;
};

struct opal_sg_list {
	__be64 length;
	__be64 next;
	struct opal_sg_entry entry[0];
};

struct opal {
	u64 base;
	u64 entry;
	u64 size;
};

struct mcheck_recoverable_range {
	u64 start_addr;
	u64 end_addr;
	u64 recover_addr;
};

enum opal_async_token_state {
	ASYNC_TOKEN_UNALLOCATED = 0,
	ASYNC_TOKEN_ALLOCATED = 1,
	ASYNC_TOKEN_DISPATCHED = 2,
	ASYNC_TOKEN_ABANDONED = 3,
	ASYNC_TOKEN_COMPLETED = 4,
};

struct opal_async_token {
	enum opal_async_token_state state;
	struct opal_msg response;
};

enum ppc_dbell {
	PPC_DBELL = 0,
	PPC_DBELL_CRIT = 1,
	PPC_G_DBELL = 2,
	PPC_G_DBELL_CRIT = 3,
	PPC_G_DBELL_MC = 4,
	PPC_DBELL_SERVER = 5,
};

struct p7_sprs {
	u64 tscr;
	u64 worc;
	u64 sdr1;
	u64 rpr;
	u64 lpcr;
	u64 hfscr;
	u64 fscr;
	u64 purr;
	u64 spurr;
	u64 dscr;
	u64 wort;
	u64 amr;
	u64 iamr;
	u64 amor;
	u64 uamor;
};

struct p9_sprs {
	u64 ptcr;
	u64 rpr;
	u64 tscr;
	u64 ldbar;
	u64 lpcr;
	u64 hfscr;
	u64 fscr;
	u64 pid;
	u64 purr;
	u64 spurr;
	u64 dscr;
	u64 wort;
	u64 mmcra;
	u32 mmcr0;
	u32 mmcr1;
	u64 mmcr2;
	u64 amr;
	u64 iamr;
	u64 amor;
	u64 uamor;
};

enum OpalLPCAddressType {
	OPAL_LPC_MEM = 0,
	OPAL_LPC_IO = 1,
	OPAL_LPC_FW = 2,
};

struct lpc_debugfs_entry {
	enum OpalLPCAddressType lpc_type;
};

enum {
	IMAGE_INVALID = 0,
	IMAGE_LOADING = 1,
	IMAGE_READY = 2,
};

struct image_data_t {
	int status;
	void *data;
	uint32_t size;
};

struct image_header_t {
	uint16_t magic;
	uint16_t version;
	uint32_t size;
};

struct validate_flash_t {
	int status;
	void *buf;
	uint32_t buf_size;
	uint32_t result;
};

struct manage_flash_t {
	int status;
};

struct update_flash_t {
	int status;
};

struct powernv_rng {
	void *regs;
	void *regs_real;
	long unsigned int mask;
};

struct elog_obj {
	struct kobject kobj;
	struct bin_attribute raw_attr;
	uint64_t id;
	uint64_t type;
	size_t size;
	char *buffer;
};

struct elog_attribute {
	struct attribute attr;
	ssize_t (*show)(struct elog_obj *, struct elog_attribute *, char *);
	ssize_t (*store)(struct elog_obj *, struct elog_attribute *, const char *, size_t);
};

struct dump_obj {
	struct kobject kobj;
	struct bin_attribute dump_attr;
	uint32_t id;
	uint32_t type;
	uint32_t size;
	char *buffer;
};

struct dump_attribute {
	struct attribute attr;
	ssize_t (*show)(struct dump_obj *, struct dump_attribute *, char *);
	ssize_t (*store)(struct dump_obj *, struct dump_attribute *, const char *, size_t);
};

enum OpalSysparamPerm {
	OPAL_SYSPARAM_READ = 1,
	OPAL_SYSPARAM_WRITE = 2,
	OPAL_SYSPARAM_RW = 3,
};

struct param_attr {
	struct list_head list;
	u32 param_id;
	u32 param_size;
	struct kobj_attribute kobj_attr;
};

struct memcons {
	__be64 magic;
	__be64 obuf_phys;
	__be64 ibuf_phys;
	__be32 obuf_size;
	__be32 ibuf_size;
	__be32 out_pos;
	__be32 in_prod;
	__be32 in_cons;
};

enum OpalHMI_Version {
	OpalHMIEvt_V1 = 1,
	OpalHMIEvt_V2 = 2,
};

enum OpalHMI_Severity {
	OpalHMI_SEV_NO_ERROR = 0,
	OpalHMI_SEV_WARNING = 1,
	OpalHMI_SEV_ERROR_SYNC = 2,
	OpalHMI_SEV_FATAL = 3,
};

enum OpalHMI_Disposition {
	OpalHMI_DISPOSITION_RECOVERED = 0,
	OpalHMI_DISPOSITION_NOT_RECOVERED = 1,
};

enum OpalHMI_ErrType {
	OpalHMI_ERROR_MALFUNC_ALERT = 0,
	OpalHMI_ERROR_PROC_RECOV_DONE = 1,
	OpalHMI_ERROR_PROC_RECOV_DONE_AGAIN = 2,
	OpalHMI_ERROR_PROC_RECOV_MASKED = 3,
	OpalHMI_ERROR_TFAC = 4,
	OpalHMI_ERROR_TFMR_PARITY = 5,
	OpalHMI_ERROR_HA_OVERFLOW_WARN = 6,
	OpalHMI_ERROR_XSCOM_FAIL = 7,
	OpalHMI_ERROR_XSCOM_DONE = 8,
	OpalHMI_ERROR_SCOM_FIR = 9,
	OpalHMI_ERROR_DEBUG_TRIG_FIR = 10,
	OpalHMI_ERROR_HYP_RESOURCE = 11,
	OpalHMI_ERROR_CAPP_RECOVERY = 12,
};

enum OpalHMI_XstopType {
	CHECKSTOP_TYPE_UNKNOWN = 0,
	CHECKSTOP_TYPE_CORE = 1,
	CHECKSTOP_TYPE_NX = 2,
};

enum OpalHMI_CoreXstopReason {
	CORE_CHECKSTOP_IFU_REGFILE = 1,
	CORE_CHECKSTOP_IFU_LOGIC = 2,
	CORE_CHECKSTOP_PC_DURING_RECOV = 4,
	CORE_CHECKSTOP_ISU_REGFILE = 8,
	CORE_CHECKSTOP_ISU_LOGIC = 16,
	CORE_CHECKSTOP_FXU_LOGIC = 32,
	CORE_CHECKSTOP_VSU_LOGIC = 64,
	CORE_CHECKSTOP_PC_RECOV_IN_MAINT_MODE = 128,
	CORE_CHECKSTOP_LSU_REGFILE = 256,
	CORE_CHECKSTOP_PC_FWD_PROGRESS = 512,
	CORE_CHECKSTOP_LSU_LOGIC = 1024,
	CORE_CHECKSTOP_PC_LOGIC = 2048,
	CORE_CHECKSTOP_PC_HYP_RESOURCE = 4096,
	CORE_CHECKSTOP_PC_HANG_RECOV_FAILED = 8192,
	CORE_CHECKSTOP_PC_AMBI_HANG_DETECTED = 16384,
	CORE_CHECKSTOP_PC_DEBUG_TRIG_ERR_INJ = 32768,
	CORE_CHECKSTOP_PC_SPRD_HYP_ERR_INJ = 65536,
};

enum OpalHMI_NestAccelXstopReason {
	NX_CHECKSTOP_SHM_INVAL_STATE_ERR = 1,
	NX_CHECKSTOP_DMA_INVAL_STATE_ERR_1 = 2,
	NX_CHECKSTOP_DMA_INVAL_STATE_ERR_2 = 4,
	NX_CHECKSTOP_DMA_CH0_INVAL_STATE_ERR = 8,
	NX_CHECKSTOP_DMA_CH1_INVAL_STATE_ERR = 16,
	NX_CHECKSTOP_DMA_CH2_INVAL_STATE_ERR = 32,
	NX_CHECKSTOP_DMA_CH3_INVAL_STATE_ERR = 64,
	NX_CHECKSTOP_DMA_CH4_INVAL_STATE_ERR = 128,
	NX_CHECKSTOP_DMA_CH5_INVAL_STATE_ERR = 256,
	NX_CHECKSTOP_DMA_CH6_INVAL_STATE_ERR = 512,
	NX_CHECKSTOP_DMA_CH7_INVAL_STATE_ERR = 1024,
	NX_CHECKSTOP_DMA_CRB_UE = 2048,
	NX_CHECKSTOP_DMA_CRB_SUE = 4096,
	NX_CHECKSTOP_PBI_ISN_UE = 8192,
};

struct OpalHMIEvent {
	uint8_t version;
	uint8_t severity;
	uint8_t type;
	uint8_t disposition;
	uint8_t reserved_1[4];
	__be64 hmer;
	__be64 tfmr;
	union {
		struct {
			uint8_t xstop_type;
			uint8_t reserved_1[3];
			__be32 xstop_reason;
			union {
				__be32 pir;
				__be32 chip_id;
			} u;
		} xstop_error;
	} u;
};

struct OpalHmiEvtNode {
	struct list_head list;
	struct OpalHMIEvent hmi_evt;
};

struct xstop_reason {
	uint32_t xstop_reason;
	const char *unit_failed;
	const char *description;
};

enum OpalSysEpow {
	OPAL_SYSEPOW_POWER = 0,
	OPAL_SYSEPOW_TEMP = 1,
	OPAL_SYSEPOW_COOLING = 2,
	OPAL_SYSEPOW_MAX = 3,
};

enum OpalSysPower {
	OPAL_SYSPOWER_UPS = 1,
	OPAL_SYSPOWER_CHNG = 2,
	OPAL_SYSPOWER_FAIL = 4,
	OPAL_SYSPOWER_INCL = 8,
};

struct opal_event_irqchip {
	struct irq_chip irqchip;
	struct irq_domain *domain;
	long unsigned int mask;
};

struct powercap_attr {
	u32 handle;
	struct kobj_attribute attr;
};

struct pcap {
	struct attribute_group pg;
	struct powercap_attr *pattrs;
};

struct psr_attr {
	u32 handle;
	struct kobj_attribute attr;
};

struct sg_attr {
	u32 handle;
	struct kobj_attribute attr;
};

struct sensor_group {
	char name[20];
	struct attribute_group sg;
	struct sg_attr *sgattrs;
};

struct sg_ops_info {
	int opal_no;
	const char *attr_name;
	ssize_t (*store)(struct kobject *, struct kobj_attribute *, const char *, size_t);
};

struct memcons___2;

struct split_state {
	u8 step;
	u8 master;
};

enum opal_mpipl_ops {
	OPAL_MPIPL_ADD_RANGE = 0,
	OPAL_MPIPL_REMOVE_RANGE = 1,
	OPAL_MPIPL_REMOVE_ALL = 2,
	OPAL_MPIPL_FREE_PRESERVED_MEMORY = 3,
};

enum opal_mpipl_tags {
	OPAL_MPIPL_TAG_CPU = 0,
	OPAL_MPIPL_TAG_OPAL = 1,
	OPAL_MPIPL_TAG_KERNEL = 2,
	OPAL_MPIPL_TAG_BOOT_MEM = 3,
};

struct opal_mpipl_region {
	__be64 src;
	__be64 dest;
	__be64 size;
};

struct opal_mpipl_fadump {
	u8 version;
	u8 reserved[7];
	__be32 crashing_pir;
	__be32 cpu_data_version;
	__be32 cpu_data_size;
	__be32 region_cnt;
	struct opal_mpipl_region region[0];
};

struct opal_fadump_mem_struct {
	u8 version;
	u8 reserved[3];
	u16 region_cnt;
	u16 registered_regions;
	u64 fadumphdr_addr;
	struct opal_mpipl_region rgn[128];
};

struct hdat_fadump_thread_hdr {
	__be32 pir;
	u8 core_state;
	u8 reserved[3];
	__be32 offset;
	__be32 ecnt;
	__be32 esize;
	__be32 eactsz;
};

struct hdat_fadump_reg_entry {
	__be32 reg_type;
	__be32 reg_num;
	__be64 reg_val;
};

struct elf64_note {
	Elf64_Word n_namesz;
	Elf64_Word n_descsz;
	Elf64_Word n_type;
};

typedef struct elf64_note Elf64_Nhdr;

struct opalcore_config {
	u32 num_cpus;
	u32 crashing_cpu;
	u64 cpu_state_destination_vaddr;
	u64 cpu_state_data_size;
	u64 cpu_state_entry_size;
	u64 ptload_addr[8];
	u64 ptload_size[8];
	u64 ptload_cnt;
	Elf64_Phdr *ptload_phdr;
	size_t opalcore_size;
	size_t opalcorebuf_sz;
	char *opalcorebuf;
	char auxv_buf[24];
};

struct opalcore {
	struct list_head list;
	u64 paddr;
	size_t size;
	loff_t offset;
};

enum OpalFreezeState {
	OPAL_EEH_STOPPED_NOT_FROZEN = 0,
	OPAL_EEH_STOPPED_MMIO_FREEZE = 1,
	OPAL_EEH_STOPPED_DMA_FREEZE = 2,
	OPAL_EEH_STOPPED_MMIO_DMA_FREEZE = 3,
	OPAL_EEH_STOPPED_RESET = 4,
	OPAL_EEH_STOPPED_TEMP_UNAVAIL = 5,
	OPAL_EEH_STOPPED_PERM_UNAVAIL = 6,
};

enum OpalEehFreezeActionToken {
	OPAL_EEH_ACTION_CLEAR_FREEZE_MMIO = 1,
	OPAL_EEH_ACTION_CLEAR_FREEZE_DMA = 2,
	OPAL_EEH_ACTION_CLEAR_FREEZE_ALL = 3,
	OPAL_EEH_ACTION_SET_FREEZE_MMIO = 1,
	OPAL_EEH_ACTION_SET_FREEZE_DMA = 2,
	OPAL_EEH_ACTION_SET_FREEZE_ALL = 3,
};

enum {
	OPAL_PHB_ERROR_DATA_TYPE_P7IOC = 1,
	OPAL_PHB_ERROR_DATA_TYPE_PHB3 = 2,
	OPAL_PHB_ERROR_DATA_TYPE_PHB4 = 3,
};

struct OpalIoPhbErrorCommon {
	__be32 version;
	__be32 ioType;
	__be32 len;
};

struct OpalIoP7IOCPhbErrorData {
	struct OpalIoPhbErrorCommon common;
	__be32 brdgCtl;
	__be32 portStatusReg;
	__be32 rootCmplxStatus;
	__be32 busAgentStatus;
	__be32 deviceStatus;
	__be32 slotStatus;
	__be32 linkStatus;
	__be32 devCmdStatus;
	__be32 devSecStatus;
	__be32 rootErrorStatus;
	__be32 uncorrErrorStatus;
	__be32 corrErrorStatus;
	__be32 tlpHdr1;
	__be32 tlpHdr2;
	__be32 tlpHdr3;
	__be32 tlpHdr4;
	__be32 sourceId;
	__be32 rsv3;
	__be64 errorClass;
	__be64 correlator;
	__be64 p7iocPlssr;
	__be64 p7iocCsr;
	__be64 lemFir;
	__be64 lemErrorMask;
	__be64 lemWOF;
	__be64 phbErrorStatus;
	__be64 phbFirstErrorStatus;
	__be64 phbErrorLog0;
	__be64 phbErrorLog1;
	__be64 mmioErrorStatus;
	__be64 mmioFirstErrorStatus;
	__be64 mmioErrorLog0;
	__be64 mmioErrorLog1;
	__be64 dma0ErrorStatus;
	__be64 dma0FirstErrorStatus;
	__be64 dma0ErrorLog0;
	__be64 dma0ErrorLog1;
	__be64 dma1ErrorStatus;
	__be64 dma1FirstErrorStatus;
	__be64 dma1ErrorLog0;
	__be64 dma1ErrorLog1;
	__be64 pestA[128];
	__be64 pestB[128];
};

struct OpalIoPhb3ErrorData {
	struct OpalIoPhbErrorCommon common;
	__be32 brdgCtl;
	__be32 portStatusReg;
	__be32 rootCmplxStatus;
	__be32 busAgentStatus;
	__be32 deviceStatus;
	__be32 slotStatus;
	__be32 linkStatus;
	__be32 devCmdStatus;
	__be32 devSecStatus;
	__be32 rootErrorStatus;
	__be32 uncorrErrorStatus;
	__be32 corrErrorStatus;
	__be32 tlpHdr1;
	__be32 tlpHdr2;
	__be32 tlpHdr3;
	__be32 tlpHdr4;
	__be32 sourceId;
	__be32 rsv3;
	__be64 errorClass;
	__be64 correlator;
	__be64 nFir;
	__be64 nFirMask;
	__be64 nFirWOF;
	__be64 phbPlssr;
	__be64 phbCsr;
	__be64 lemFir;
	__be64 lemErrorMask;
	__be64 lemWOF;
	__be64 phbErrorStatus;
	__be64 phbFirstErrorStatus;
	__be64 phbErrorLog0;
	__be64 phbErrorLog1;
	__be64 mmioErrorStatus;
	__be64 mmioFirstErrorStatus;
	__be64 mmioErrorLog0;
	__be64 mmioErrorLog1;
	__be64 dma0ErrorStatus;
	__be64 dma0FirstErrorStatus;
	__be64 dma0ErrorLog0;
	__be64 dma0ErrorLog1;
	__be64 dma1ErrorStatus;
	__be64 dma1FirstErrorStatus;
	__be64 dma1ErrorLog0;
	__be64 dma1ErrorLog1;
	__be64 pestA[256];
	__be64 pestB[256];
};

struct OpalIoPhb4ErrorData {
	struct OpalIoPhbErrorCommon common;
	__be32 brdgCtl;
	__be32 deviceStatus;
	__be32 slotStatus;
	__be32 linkStatus;
	__be32 devCmdStatus;
	__be32 devSecStatus;
	__be32 rootErrorStatus;
	__be32 uncorrErrorStatus;
	__be32 corrErrorStatus;
	__be32 tlpHdr1;
	__be32 tlpHdr2;
	__be32 tlpHdr3;
	__be32 tlpHdr4;
	__be32 sourceId;
	__be64 nFir;
	__be64 nFirMask;
	__be64 nFirWOF;
	__be64 phbPlssr;
	__be64 phbCsr;
	__be64 lemFir;
	__be64 lemErrorMask;
	__be64 lemWOF;
	__be64 phbErrorStatus;
	__be64 phbFirstErrorStatus;
	__be64 phbErrorLog0;
	__be64 phbErrorLog1;
	__be64 phbTxeErrorStatus;
	__be64 phbTxeFirstErrorStatus;
	__be64 phbTxeErrorLog0;
	__be64 phbTxeErrorLog1;
	__be64 phbRxeArbErrorStatus;
	__be64 phbRxeArbFirstErrorStatus;
	__be64 phbRxeArbErrorLog0;
	__be64 phbRxeArbErrorLog1;
	__be64 phbRxeMrgErrorStatus;
	__be64 phbRxeMrgFirstErrorStatus;
	__be64 phbRxeMrgErrorLog0;
	__be64 phbRxeMrgErrorLog1;
	__be64 phbRxeTceErrorStatus;
	__be64 phbRxeTceFirstErrorStatus;
	__be64 phbRxeTceErrorLog0;
	__be64 phbRxeTceErrorLog1;
	__be64 phbPblErrorStatus;
	__be64 phbPblFirstErrorStatus;
	__be64 phbPblErrorLog0;
	__be64 phbPblErrorLog1;
	__be64 phbPcieDlpErrorLog1;
	__be64 phbPcieDlpErrorLog2;
	__be64 phbPcieDlpErrorStatus;
	__be64 phbRegbErrorStatus;
	__be64 phbRegbFirstErrorStatus;
	__be64 phbRegbErrorLog0;
	__be64 phbRegbErrorLog1;
	__be64 pestA[512];
	__be64 pestB[512];
};

enum pnv_phb_type {
	PNV_PHB_IODA1 = 0,
	PNV_PHB_IODA2 = 1,
	PNV_PHB_NPU_NVLINK = 2,
	PNV_PHB_NPU_OCAPI = 3,
};

enum pnv_phb_model {
	PNV_PHB_MODEL_UNKNOWN = 0,
	PNV_PHB_MODEL_P7IOC = 1,
	PNV_PHB_MODEL_PHB3 = 2,
	PNV_PHB_MODEL_NPU = 3,
	PNV_PHB_MODEL_NPU2 = 4,
};

struct pnv_phb;

struct npu_comp;

struct pnv_ioda_pe {
	long unsigned int flags;
	struct pnv_phb *phb;
	int device_count;
	struct pci_dev *parent_dev;
	struct pci_dev *pdev;
	struct pci_bus *pbus;
	unsigned int rid;
	unsigned int pe_number;
	struct iommu_table_group table_group;
	struct npu_comp *npucomp;
	bool tce_bypass_enabled;
	uint64_t tce_bypass_base;
	int mve_number;
	struct pnv_ioda_pe *master;
	struct list_head slaves;
	int p2p_initiator_count;
	struct list_head list;
};

struct cxl_afu;

struct pnv_phb {
	struct pci_controller *hose;
	enum pnv_phb_type type;
	enum pnv_phb_model model;
	u64 hub_id;
	u64 opal_id;
	int flags;
	void *regs;
	u64 regs_phys;
	int initialized;
	spinlock_t lock;
	int has_dbgfs;
	struct dentry *dbgfs;
	unsigned int msi_base;
	unsigned int msi32_support;
	struct msi_bitmap msi_bmp;
	int (*msi_setup)(struct pnv_phb *, struct pci_dev *, unsigned int, unsigned int, unsigned int, struct msi_msg *);
	void (*dma_dev_setup)(struct pnv_phb *, struct pci_dev *);
	void (*fixup_phb)(struct pci_controller *);
	int (*init_m64)(struct pnv_phb *);
	void (*reserve_m64_pe)(struct pci_bus *, long unsigned int *, bool);
	struct pnv_ioda_pe * (*pick_m64_pe)(struct pci_bus *, bool);
	int (*get_pe_state)(struct pnv_phb *, int);
	void (*freeze_pe)(struct pnv_phb *, int);
	int (*unfreeze_pe)(struct pnv_phb *, int, int);
	struct {
		unsigned int total_pe_num;
		unsigned int reserved_pe_idx;
		unsigned int root_pe_idx;
		bool root_pe_populated;
		unsigned int m32_size;
		unsigned int m32_segsize;
		unsigned int m32_pci_base;
		unsigned int m64_bar_idx;
		long unsigned int m64_size;
		long unsigned int m64_segsize;
		long unsigned int m64_base;
		long unsigned int m64_bar_alloc;
		unsigned int io_size;
		unsigned int io_segsize;
		unsigned int io_pci_base;
		struct mutex pe_alloc_mutex;
		long unsigned int *pe_alloc;
		struct pnv_ioda_pe *pe_array;
		unsigned int *m64_segmap;
		unsigned int *m32_segmap;
		unsigned int *io_segmap;
		unsigned int dma32_count;
		unsigned int *dma32_segmap;
		int irq_chip_init;
		struct irq_chip irq_chip;
		struct list_head pe_list;
		struct mutex pe_list_mutex;
		unsigned int pe_rmap[65536];
	} ioda;
	unsigned int diag_data_size;
	u8 *diag_data;
	struct cxl_afu *cxl_afu;
	int p2p_target_count;
};

struct va_format {
	const char *fmt;
	va_list *va;
};

enum OpalMmioWindowType {
	OPAL_M32_WINDOW_TYPE = 1,
	OPAL_M64_WINDOW_TYPE = 2,
	OPAL_IO_WINDOW_TYPE = 3,
};

enum OpalPciBusCompare {
	OpalPciBusAny = 0,
	OpalPciBus3Bits = 2,
	OpalPciBus4Bits = 3,
	OpalPciBus5Bits = 4,
	OpalPciBus6Bits = 5,
	OpalPciBus7Bits = 6,
	OpalPciBusAll = 7,
};

enum OpalDeviceCompare {
	OPAL_IGNORE_RID_DEVICE_NUMBER = 0,
	OPAL_COMPARE_RID_DEVICE_NUMBER = 1,
};

enum OpalFuncCompare {
	OPAL_IGNORE_RID_FUNCTION_NUMBER = 0,
	OPAL_COMPARE_RID_FUNCTION_NUMBER = 1,
};

enum OpalPeAction {
	OPAL_UNMAP_PE = 0,
	OPAL_MAP_PE = 1,
};

enum OpalPeltvAction {
	OPAL_REMOVE_PE_FROM_DOMAIN = 0,
	OPAL_ADD_PE_TO_DOMAIN = 1,
};

enum OpalMveEnableAction {
	OPAL_DISABLE_MVE = 0,
	OPAL_ENABLE_MVE = 1,
};

enum OpalM64Action {
	OPAL_DISABLE_M64 = 0,
	OPAL_ENABLE_M64_SPLIT = 1,
	OPAL_ENABLE_M64_NON_SPLIT = 2,
};

enum OpalPciResetScope {
	OPAL_RESET_PHB_COMPLETE = 1,
	OPAL_RESET_PCI_LINK = 2,
	OPAL_RESET_PHB_ERROR = 3,
	OPAL_RESET_PCI_HOT = 4,
	OPAL_RESET_PCI_FUNDAMENTAL = 5,
	OPAL_RESET_PCI_IODA_TABLE = 6,
};

enum OpalPciResetState {
	OPAL_DEASSERT_RESET = 0,
	OPAL_ASSERT_RESET = 1,
};

enum {
	OPAL_PCI_TCE_KILL_PAGES = 0,
	OPAL_PCI_TCE_KILL_PE = 1,
	OPAL_PCI_TCE_KILL_ALL = 2,
};

struct iommu_table_group_link {
	struct list_head next;
	struct callback_head rcu;
	struct iommu_table_group *table_group;
};

struct npu_context {
	struct mm_struct *mm;
	struct pci_dev *npdev[48];
	struct mmu_notifier mn;
	struct kref kref;
	bool nmmu_flush;
	void (*release_cb)(struct npu_context *, void *);
	void *priv;
};

struct npu_comp {
	struct iommu_table_group table_group;
	int pe_num;
	struct pnv_ioda_pe *pe[16];
};

struct npu {
	int index;
	__be64 *mmio_atsd_regs[8];
	unsigned int mmio_atsd_count;
	long unsigned int mmio_atsd_usage;
	bool nmmu_flush;
	struct npu_comp npucomp;
};

struct mmio_atsd_reg {
	struct npu *npu;
	int reg;
};

struct cxl_irq_ranges {
	irq_hw_number_t offset[4];
	irq_hw_number_t range[4];
};

enum OpalPciStatusToken {
	OPAL_EEH_NO_ERROR = 0,
	OPAL_EEH_IOC_ERROR = 1,
	OPAL_EEH_PHB_ERROR = 2,
	OPAL_EEH_PE_ERROR = 3,
	OPAL_EEH_PE_MMIO_ERROR = 4,
	OPAL_EEH_PE_DMA_ERROR = 5,
};

enum OpalPciErrorSeverity {
	OPAL_EEH_SEV_NO_ERROR = 0,
	OPAL_EEH_SEV_IOC_DEAD = 1,
	OPAL_EEH_SEV_PHB_DEAD = 2,
	OPAL_EEH_SEV_PHB_FENCED = 3,
	OPAL_EEH_SEV_PE_ER = 4,
	OPAL_EEH_SEV_INF = 5,
};

enum OpalErrinjectType {
	OPAL_ERR_INJECT_TYPE_IOA_BUS_ERR = 0,
	OPAL_ERR_INJECT_TYPE_IOA_BUS_ERR64 = 1,
};

enum OpalErrinjectFunc {
	OPAL_ERR_INJECT_FUNC_IOA_LD_MEM_ADDR = 0,
	OPAL_ERR_INJECT_FUNC_IOA_LD_MEM_DATA = 1,
	OPAL_ERR_INJECT_FUNC_IOA_LD_IO_ADDR = 2,
	OPAL_ERR_INJECT_FUNC_IOA_LD_IO_DATA = 3,
	OPAL_ERR_INJECT_FUNC_IOA_LD_CFG_ADDR = 4,
	OPAL_ERR_INJECT_FUNC_IOA_LD_CFG_DATA = 5,
	OPAL_ERR_INJECT_FUNC_IOA_ST_MEM_ADDR = 6,
	OPAL_ERR_INJECT_FUNC_IOA_ST_MEM_DATA = 7,
	OPAL_ERR_INJECT_FUNC_IOA_ST_IO_ADDR = 8,
	OPAL_ERR_INJECT_FUNC_IOA_ST_IO_DATA = 9,
	OPAL_ERR_INJECT_FUNC_IOA_ST_CFG_ADDR = 10,
	OPAL_ERR_INJECT_FUNC_IOA_ST_CFG_DATA = 11,
	OPAL_ERR_INJECT_FUNC_IOA_DMA_RD_ADDR = 12,
	OPAL_ERR_INJECT_FUNC_IOA_DMA_RD_DATA = 13,
	OPAL_ERR_INJECT_FUNC_IOA_DMA_RD_MASTER = 14,
	OPAL_ERR_INJECT_FUNC_IOA_DMA_RD_TARGET = 15,
	OPAL_ERR_INJECT_FUNC_IOA_DMA_WR_ADDR = 16,
	OPAL_ERR_INJECT_FUNC_IOA_DMA_WR_DATA = 17,
	OPAL_ERR_INJECT_FUNC_IOA_DMA_WR_MASTER = 18,
	OPAL_ERR_INJECT_FUNC_IOA_DMA_WR_TARGET = 19,
};

enum OpalPciReinitScope {
	OPAL_REINIT_PCI_DEV = 1000,
};

enum {
	OPAL_P7IOC_DIAG_TYPE_NONE = 0,
	OPAL_P7IOC_DIAG_TYPE_RGC = 1,
	OPAL_P7IOC_DIAG_TYPE_BI = 2,
	OPAL_P7IOC_DIAG_TYPE_CI = 3,
	OPAL_P7IOC_DIAG_TYPE_MISC = 4,
	OPAL_P7IOC_DIAG_TYPE_I2C = 5,
	OPAL_P7IOC_DIAG_TYPE_LAST = 6,
};

struct OpalIoP7IOCRgcErrorData {
	__be64 rgcStatus;
	__be64 rgcLdcp;
};

struct OpalIoP7IOCBiErrorData {
	__be64 biLdcp0;
	__be64 biLdcp1;
	__be64 biLdcp2;
	__be64 biFenceStatus;
	uint8_t biDownbound;
};

struct OpalIoP7IOCCiErrorData {
	__be64 ciPortStatus;
	__be64 ciPortLdcp;
	uint8_t ciPort;
};

struct OpalIoP7IOCErrorData {
	__be16 type;
	__be64 gemXfir;
	__be64 gemRfir;
	__be64 gemRirqfir;
	__be64 gemMask;
	__be64 gemRwof;
	__be64 lemFir;
	__be64 lemErrMask;
	__be64 lemAction0;
	__be64 lemAction1;
	__be64 lemWof;
	union {
		struct OpalIoP7IOCRgcErrorData rgc;
		struct OpalIoP7IOCBiErrorData bi;
		struct OpalIoP7IOCCiErrorData ci;
	};
};

struct opal_scom_map {
	uint32_t chip;
	uint64_t addr;
};

enum OpalMemErr_Version {
	OpalMemErr_V1 = 1,
};

enum OpalMemErrType {
	OPAL_MEM_ERR_TYPE_RESILIENCE = 0,
	OPAL_MEM_ERR_TYPE_DYN_DALLOC = 1,
};

enum OpalMemErr_ResilErrType {
	OPAL_MEM_RESILIENCE_CE = 0,
	OPAL_MEM_RESILIENCE_UE = 1,
	OPAL_MEM_RESILIENCE_UE_SCRUB = 2,
};

enum OpalMemErr_DynErrType {
	OPAL_MEM_DYNAMIC_DEALLOC = 0,
};

struct OpalMemoryErrorData {
	enum OpalMemErr_Version version: 8;
	enum OpalMemErrType type: 8;
	__be16 flags;
	uint8_t reserved_1[4];
	union {
		struct {
			enum OpalMemErr_ResilErrType resil_err_type: 8;
			uint8_t reserved_1[7];
			__be64 physical_address_start;
			__be64 physical_address_end;
		} resilience;
		struct {
			enum OpalMemErr_DynErrType dyn_err_type: 8;
			uint8_t reserved_1[7];
			__be64 physical_address_start;
			__be64 physical_address_end;
		} dyn_dealloc;
	} u;
};

struct OpalMsgNode {
	struct list_head list;
	struct opal_msg msg;
};

struct platform_driver {
	int (*probe)(struct platform_device *);
	int (*remove)(struct platform_device *);
	void (*remove_new)(struct platform_device *);
	void (*shutdown)(struct platform_device *);
	int (*suspend)(struct platform_device *, pm_message_t);
	int (*resume)(struct platform_device *);
	struct device_driver driver;
	const struct platform_device_id *id_table;
	bool prevent_deferred_probe;
};

enum {
	OPAL_IMC_COUNTERS_NEST = 1,
	OPAL_IMC_COUNTERS_CORE = 2,
	OPAL_IMC_COUNTERS_TRACE = 3,
};

struct imc_mem_info {
	u64 *vbase;
	u32 id;
};

struct imc_events {
	u32 value;
	char *name;
	char *unit;
	char *scale;
};

struct imc_pmu {
	struct pmu___2 pmu;
	struct imc_mem_info *mem_info;
	struct imc_events *events;
	const struct attribute_group *attr_groups[4];
	u32 counter_mem_size;
	int domain;
	bool imc_counter_mmaped;
};

enum {
	IMC_TYPE_THREAD = 1,
	IMC_TYPE_TRACE = 2,
	IMC_TYPE_CORE = 4,
	IMC_TYPE_CHIP = 16,
};

enum vas_cop_type {
	VAS_COP_TYPE_FAULT = 0,
	VAS_COP_TYPE_842 = 1,
	VAS_COP_TYPE_842_HIPRI = 2,
	VAS_COP_TYPE_GZIP = 3,
	VAS_COP_TYPE_GZIP_HIPRI = 4,
	VAS_COP_TYPE_FTW = 5,
	VAS_COP_TYPE_MAX = 6,
};

struct vas_user_win_ref {
	struct pid *pid;
	struct pid *tgid;
	struct mm_struct *mm;
	struct mutex mmap_mutex;
	struct vm_area_struct *vma;
};

struct vas_window {
	u32 winid;
	u32 wcreds_max;
	u32 status;
	enum vas_cop_type cop;
	struct vas_user_win_ref task_ref;
	char *dbgname;
	struct dentry *dbgdir;
};

struct pnv_vas_window;

struct vas_instance {
	int vas_id;
	struct ida ida;
	struct list_head node;
	struct platform_device *pdev;
	u64 hvwc_bar_start;
	u64 uwc_bar_start;
	u64 paste_base_addr;
	u64 paste_win_id_shift;
	u64 irq_port;
	int virq;
	int fault_crbs;
	int fault_fifo_size;
	int fifo_in_progress;
	spinlock_t fault_lock;
	void *fault_fifo;
	struct pnv_vas_window *fault_win;
	struct mutex mutex;
	struct pnv_vas_window *rxwin[6];
	struct pnv_vas_window *windows[65536];
	char *dbgname;
	struct dentry *dbgdir;
};

struct pnv_vas_window {
	struct vas_window vas_win;
	struct vas_instance *vinst;
	bool tx_win;
	bool nx_win;
	bool user_win;
	void *hvwc_map;
	void *uwc_map;
	void *paste_kaddr;
	char *paste_addr_name;
	struct pnv_vas_window *rxwin;
	atomic_t num_txwins;
};

struct vas_user_win_ops {
	struct vas_window * (*open_win)(int, u64, enum vas_cop_type);
	u64 (*paste_addr)(struct vas_window *);
	int (*close_win)(struct vas_window *);
};

struct vas_rx_win_attr {
	void *rx_fifo;
	int rx_fifo_size;
	int wcreds_max;
	bool pin_win;
	bool rej_no_credit;
	bool tx_wcred_mode;
	bool rx_wcred_mode;
	bool tx_win_ord_mode;
	bool rx_win_ord_mode;
	bool data_stamp;
	bool nx_win;
	bool fault_win;
	bool user_win;
	bool notify_disable;
	bool intr_disable;
	bool notify_early;
	int lnotify_lpid;
	int lnotify_pid;
	int lnotify_tid;
	u32 pswid;
	int tc_mode;
};

struct vas_tx_win_attr {
	enum vas_cop_type cop;
	int wcreds_max;
	int lpid;
	int pidr;
	int pswid;
	int rsvd_txbuf_count;
	int tc_mode;
	bool user_win;
	bool pin_win;
	bool rej_no_credit;
	bool rsvd_txbuf_enable;
	bool tx_wcred_mode;
	bool rx_wcred_mode;
	bool tx_win_ord_mode;
	bool rx_win_ord_mode;
};

enum vas_notify_scope {
	VAS_SCOPE_LOCAL = 0,
	VAS_SCOPE_GROUP = 1,
	VAS_SCOPE_VECTORED_GROUP = 2,
	VAS_SCOPE_UNUSED = 3,
};

enum vas_dma_type {
	VAS_DMA_TYPE_INJECT = 0,
	VAS_DMA_TYPE_WRITE = 1,
};

enum vas_notify_after_count {
	VAS_NOTIFY_AFTER_256 = 0,
	VAS_NOTIFY_NONE = 1,
	VAS_NOTIFY_AFTER_2 = 2,
};

struct vas_winctx {
	void *rx_fifo;
	int rx_fifo_size;
	int wcreds_max;
	int rsvd_txbuf_count;
	bool user_win;
	bool nx_win;
	bool fault_win;
	bool rsvd_txbuf_enable;
	bool pin_win;
	bool rej_no_credit;
	bool tx_wcred_mode;
	bool rx_wcred_mode;
	bool tx_word_mode;
	bool rx_word_mode;
	bool data_stamp;
	bool xtra_write;
	bool notify_disable;
	bool intr_disable;
	bool fifo_disable;
	bool notify_early;
	bool notify_os_intr_reg;
	int lpid;
	int pidr;
	int lnotify_lpid;
	int lnotify_pid;
	int lnotify_tid;
	u32 pswid;
	int rx_win_id;
	int fault_win_id;
	int tc_mode;
	u64 irq_port;
	enum vas_dma_type dma_type;
	enum vas_notify_scope min_scope;
	enum vas_notify_scope max_scope;
	enum vas_notify_after_count notify_after_count;
};

struct trace_event_raw_vas_rx_win_open {
	struct trace_entry ent;
	struct task_struct *tsk;
	int pid;
	int cop;
	int vasid;
	struct vas_rx_win_attr *rxattr;
	int lnotify_lpid;
	int lnotify_pid;
	int lnotify_tid;
	char __data[0];
};

struct trace_event_raw_vas_tx_win_open {
	struct trace_entry ent;
	struct task_struct *tsk;
	int pid;
	int cop;
	int vasid;
	struct vas_tx_win_attr *txattr;
	int lpid;
	int pidr;
	char __data[0];
};

struct trace_event_raw_vas_paste_crb {
	struct trace_entry ent;
	struct task_struct *tsk;
	struct vas_window *win;
	int pid;
	int vasid;
	int winid;
	long unsigned int paste_kaddr;
	char __data[0];
};

struct trace_event_data_offsets_vas_rx_win_open {};

struct trace_event_data_offsets_vas_tx_win_open {};

struct trace_event_data_offsets_vas_paste_crb {};

typedef void (*btf_trace_vas_rx_win_open)(void *, struct task_struct *, int, int, struct vas_rx_win_attr *);

typedef void (*btf_trace_vas_tx_win_open)(void *, struct task_struct *, int, int, struct vas_tx_win_attr *);

typedef void (*btf_trace_vas_paste_crb)(void *, struct task_struct *, struct pnv_vas_window *);

struct coprocessor_completion_block {
	__be64 value;
	__be64 address;
};

struct coprocessor_status_block {
	u8 flags;
	u8 cs;
	u8 cc;
	u8 ce;
	__be32 count;
	__be64 address;
};

struct data_descriptor_entry {
	__be16 flags;
	u8 count;
	u8 index;
	__be32 length;
	__be64 address;
};

struct nx_fault_stamp {
	__be64 fault_storage_addr;
	__be16 reserved;
	__u8 flags;
	__u8 fault_status;
	__be32 pswid;
};

struct coprocessor_request_block {
	__be32 ccw;
	__be32 flags;
	__be64 csb_addr;
	struct data_descriptor_entry source;
	struct data_descriptor_entry target;
	struct coprocessor_completion_block ccb;
	union {
		struct nx_fault_stamp nx;
		u8 reserved[16];
	} stamp;
	u8 reserved[32];
	struct coprocessor_status_block csb;
};

enum {
	OPAL_XIVE_ANY_CHIP = 4294967295,
};

struct actag_range {
	u16 start;
	u16 count;
};

struct npu_link {
	struct list_head list;
	int domain;
	int bus;
	int dev;
	u16 fn_desired_actags[8];
	struct actag_range fn_actags[8];
	bool assignment_done;
};

struct spa_data {
	u64 phb_opal_id;
	u32 bdfn;
};

struct hvcall_mpp_data {
	long unsigned int entitled_mem;
	long unsigned int mapped_mem;
	short unsigned int group_num;
	short unsigned int pool_num;
	unsigned char mem_weight;
	unsigned char unallocated_mem_weight;
	long unsigned int unallocated_entitlement;
	long unsigned int pool_size;
	long int loan_request;
	long unsigned int backing_mem;
};

struct hvcall_mpp_x_data {
	long unsigned int coalesced_bytes;
	long unsigned int pool_coalesced_bytes;
	long unsigned int pool_purr_cycles;
	long unsigned int pool_spurr_cycles;
	long unsigned int reserved[3];
};

struct dtl_entry {
	u8 dispatch_reason;
	u8 preempt_reason;
	__be16 processor_id;
	__be32 enqueue_to_dispatch_time;
	__be32 ready_to_enqueue_time;
	__be32 waiting_to_ready_time;
	__be64 timebase;
	__be64 fault_addr;
	__be64 srr0;
	__be64 srr1;
};

struct dtl_worker {
	struct delayed_work work;
	int cpu;
};

struct vcpu_dispatch_data {
	int last_disp_cpu;
	int total_disp;
	int same_cpu_disp;
	int same_chip_disp;
	int diff_chip_disp;
	int far_chip_disp;
	int numa_home_disp;
	int numa_remote_disp;
	int numa_far_disp;
};

struct hpt_resize_state {
	long unsigned int shift;
	int commit_rc;
};

struct of_drc_info {
	char *drc_type;
	char *drc_name_prefix;
	u32 drc_index_start;
	u32 drc_name_suffix_start;
	u32 num_sequential_elems;
	u32 sequential_inc;
	u32 drc_power_domain;
	u32 last_drc_index;
};

struct h_cpu_char_result {
	u64 character;
	u64 behaviour;
};

struct of_reconfig_data {
	struct device_node *dn;
	struct property *prop;
	struct property *old_prop;
};

enum rtas_iov_fw_value_map {
	NUM_RES_PROPERTY = 0,
	LOW_INT = 1,
	START_OF_ENTRIES = 2,
	APERTURE_PROPERTY = 2,
	WDW_SIZE_PROPERTY = 4,
	NEXT_ENTRY = 7,
};

enum get_iov_fw_value_index {
	BAR_ADDRS = 1,
	APERTURE_SIZE = 2,
	WDW_SIZE = 3,
};

struct memory_notify {
	long unsigned int start_pfn;
	long unsigned int nr_pages;
	int status_change_nid_normal;
	int status_change_nid;
};

enum {
	DDW_QUERY_PE_DMA_WIN = 0,
	DDW_CREATE_PE_DMA_WIN = 1,
	DDW_REMOVE_PE_DMA_WIN = 2,
	DDW_APPLICABLE_SIZE = 3,
};

enum {
	DDW_EXT_SIZE = 0,
	DDW_EXT_RESET_DMA_WIN = 1,
	DDW_EXT_QUERY_OUT_SIZE = 2,
};

struct dynamic_dma_window_prop {
	__be32 liobn;
	__be64 dma_base;
	__be32 tce_shift;
	__be32 window_shift;
};

struct direct_window {
	struct device_node *device;
	const struct dynamic_dma_window_prop *prop;
	struct list_head list;
};

struct ddw_query_response {
	u32 windows_available;
	u64 largest_available_block;
	u32 page_size;
	u32 migration_capable;
};

struct ddw_create_response {
	u32 liobn;
	u32 addr_hi;
	u32 addr_lo;
};

struct failed_ddw_pdn {
	struct device_node *pdn;
	struct list_head list;
};

struct pci_controller_ops___2;

struct pseries_hp_errorlog {
	u8 resource;
	u8 action;
	u8 id_type;
	u8 reserved;
	union {
		__be32 drc_index;
		__be32 drc_count;
		struct {
			__be32 count;
			__be32 index;
		} ic;
		char drc_name[1];
	} _drc_u;
};

struct pseries_mc_errorlog {
	__be32 fru_id;
	__be32 proc_id;
	u8 error_type;
	u8 sub_err_type;
	u8 reserved_1[6];
	__be64 effective_address;
	__be64 logical_address;
};

struct epow_errorlog {
	unsigned char sensor_value;
	unsigned char event_modifier;
	unsigned char extended_modifier;
	unsigned char reserved;
	unsigned char platform_reason;
};

struct hypertas_fw_feature {
	long unsigned int val;
	char *name;
};

struct vec5_fw_feature {
	long unsigned int val;
	unsigned int feature;
};

enum {
	WQ_UNBOUND = 2,
	WQ_FREEZABLE = 4,
	WQ_MEM_RECLAIM = 8,
	WQ_HIGHPRI = 16,
	WQ_CPU_INTENSIVE = 32,
	WQ_SYSFS = 64,
	WQ_POWER_EFFICIENT = 128,
	__WQ_DRAINING = 65536,
	__WQ_ORDERED = 131072,
	__WQ_LEGACY = 262144,
	__WQ_ORDERED_EXPLICIT = 524288,
	WQ_MAX_ACTIVE = 512,
	WQ_MAX_UNBOUND_PER_CPU = 4,
	WQ_DFL_ACTIVE = 256,
};

struct class_attribute {
	struct attribute attr;
	ssize_t (*show)(struct class *, struct class_attribute *, char *);
	ssize_t (*store)(struct class *, struct class_attribute *, const char *, size_t);
};

struct pseries_hp_work {
	struct work_struct work;
	struct pseries_hp_errorlog *errlog;
};

struct cc_workarea {
	__be32 drc_index;
	__be32 zero;
	__be32 name_offset;
	__be32 prop_length;
	__be32 prop_offset;
};

struct class_attribute_string {
	struct class_attribute attr;
	char *str;
};

enum vas_migrate_action {
	VAS_SUSPEND = 0,
	VAS_RESUME = 1,
};

struct update_props_workarea {
	__be32 phandle;
	__be32 state;
	__be64 reserved;
	__be32 nprops;
} __attribute__((packed));

struct pseries_suspend_info {
	atomic_t counter;
	bool done;
};

enum vasi_aborting_entity {
	ORCHESTRATOR = 1,
	VSP_SOURCE = 2,
	PARTITION_FIRMWARE = 3,
	PLATFORM_FIRMWARE = 4,
	VSP_TARGET = 5,
	MIGRATING_PARTITION = 6,
};

enum pci_bus_speed {
	PCI_SPEED_33MHz = 0,
	PCI_SPEED_66MHz = 1,
	PCI_SPEED_66MHz_PCIX = 2,
	PCI_SPEED_100MHz_PCIX = 3,
	PCI_SPEED_133MHz_PCIX = 4,
	PCI_SPEED_66MHz_PCIX_ECC = 5,
	PCI_SPEED_100MHz_PCIX_ECC = 6,
	PCI_SPEED_133MHz_PCIX_ECC = 7,
	PCI_SPEED_66MHz_PCIX_266 = 9,
	PCI_SPEED_100MHz_PCIX_266 = 10,
	PCI_SPEED_133MHz_PCIX_266 = 11,
	AGP_UNKNOWN = 12,
	AGP_1X = 13,
	AGP_2X = 14,
	AGP_4X = 15,
	AGP_8X = 16,
	PCI_SPEED_66MHz_PCIX_533 = 17,
	PCI_SPEED_100MHz_PCIX_533 = 18,
	PCI_SPEED_133MHz_PCIX_533 = 19,
	PCIE_SPEED_2_5GT = 20,
	PCIE_SPEED_5_0GT = 21,
	PCIE_SPEED_8_0GT = 22,
	PCIE_SPEED_16_0GT = 23,
	PCIE_SPEED_32_0GT = 24,
	PCIE_SPEED_64_0GT = 25,
	PCI_SPEED_UNKNOWN = 255,
};

struct pe_map_bar_entry {
	__be64 bar;
	__be16 rid;
	__be16 pe_num;
	__be32 reserved;
};

struct msi_counts {
	struct device_node *requestor;
	int num_devices;
	int request;
	int quota;
	int spare;
	int over_quota;
};

struct energy_scale_attribute {
	__be64 id;
	__be64 val;
	u8 desc[64];
	u8 value_desc[64];
};

struct h_energy_scale_info_hdr {
	__be64 num_attrs;
	__be64 array_offset;
	u8 data_header_version;
} __attribute__((packed));

struct papr_attr {
	u64 id;
	struct kobj_attribute kobj_attr;
};

struct papr_group {
	struct attribute_group pg;
	struct papr_attr pgattrs[3];
};

struct papr_ops_info {
	const char *attr_name;
	ssize_t (*show)(struct kobject *, struct kobj_attribute *, char *);
};

typedef int mhp_t;

struct memory_block {
	long unsigned int start_section_nr;
	long unsigned int state;
	int online_type;
	int nid;
	struct zone *zone;
	struct device dev;
};

struct module_version_attribute {
	struct module_attribute mattr;
	const char *module_name;
	const char *version;
};

struct dev_ext_attribute {
	struct device_attribute attr;
	void *var;
};

struct balloon_dev_info {
	long unsigned int isolated_pages;
	spinlock_t pages_lock;
	struct list_head pages;
	int (*migratepage)(struct balloon_dev_info *, struct page *, struct page *, enum migrate_mode);
	struct inode *inode;
};

struct dtl {
	struct dtl_entry *buf;
	struct dentry *file;
	int cpu;
	int buf_entries;
	u64 last_idx;
	spinlock_t lock;
};

struct pseries_io_event {
	uint8_t event_type;
	uint8_t rpc_data_len;
	uint8_t scope;
	uint8_t event_subtype;
	uint32_t drc_index;
	uint8_t rpc_data[216];
};

struct hv_get_perf_counter_info_params {
	__be32 counter_request;
	__be32 starting_index;
	__be16 secondary_index;
	__be16 returned_values;
	__be32 detail_rc;
	__be16 cv_element_size;
	__u8 counter_info_version_in;
	__u8 counter_info_version_out;
	__u8 reserved[12];
	__u8 counter_value[0];
};

struct hv_gpci_request_buffer {
	struct hv_get_perf_counter_info_params params;
	uint8_t bytes[4064];
};

struct hvcall_ppp_data {
	u64 entitlement;
	u64 unallocated_entitlement;
	u16 group_num;
	u16 pool_num;
	u8 capped;
	u8 weight;
	u8 unallocated_weight;
	u16 active_procs_in_pool;
	u16 active_system_procs;
	u16 phys_platform_procs;
	u32 max_proc_cap_avail;
	u32 entitled_proc_cap_avail;
};

struct bus_attribute {
	struct attribute attr;
	ssize_t (*show)(struct bus_type *, char *);
	ssize_t (*store)(struct bus_type *, const char *, size_t);
};

struct vio_device_id {
	char type[32];
	char compat[32];
};

struct vio_pfo_op {
	u64 flags;
	s64 in;
	s64 inlen;
	s64 out;
	s64 outlen;
	u64 csbcpb;
	void *done;
	long unsigned int handle;
	unsigned int timeout;
	long int hcall_err;
};

enum vio_dev_family {
	VDEVICE = 0,
	PFO = 1,
};

struct vio_dev {
	const char *name;
	const char *type;
	uint32_t unit_address;
	uint32_t resource_id;
	unsigned int irq;
	struct {
		size_t desired;
		size_t entitled;
		size_t allocated;
		atomic_t allocs_failed;
	} cmo;
	enum vio_dev_family family;
	struct device dev;
};

struct vio_driver {
	const char *name;
	const struct vio_device_id *id_table;
	int (*probe)(struct vio_dev *, const struct vio_device_id *);
	void (*remove)(struct vio_dev *);
	long unsigned int (*get_desired_dma)(struct vio_dev *);
	const struct dev_pm_ops *pm;
	struct device_driver driver;
};

struct vio_cmo_pool {
	size_t size;
	size_t free;
};

struct vio_cmo_dev_entry {
	struct vio_dev *viodev;
	struct list_head list;
};

struct vio_cmo {
	spinlock_t lock;
	struct delayed_work balance_q;
	struct list_head device_list;
	size_t entitled;
	struct vio_cmo_pool reserve;
	struct vio_cmo_pool excess;
	size_t spare;
	size_t min;
	size_t desired;
	size_t curr;
	size_t high;
};

struct rtas_fadump_section {
	__be32 request_flag;
	__be16 source_data_type;
	__be16 error_flags;
	__be64 source_address;
	__be64 source_len;
	__be64 bytes_dumped;
	__be64 destination_address;
};

struct rtas_fadump_section_header {
	__be32 dump_format_version;
	__be16 dump_num_sections;
	__be16 dump_status_flag;
	__be32 offset_first_dump_section;
	__be32 dd_block_size;
	__be64 dd_block_offset;
	__be64 dd_num_blocks;
	__be32 dd_offset_disk_path;
	__be32 max_time_auto;
};

struct rtas_fadump_mem_struct {
	struct rtas_fadump_section_header header;
	struct rtas_fadump_section cpu_state_data;
	struct rtas_fadump_section hpte_region;
	struct rtas_fadump_section rmr_region;
};

struct rtas_fadump_reg_save_area_header {
	__be64 magic_number;
	__be32 version;
	__be32 num_cpu_offset;
};

struct rtas_fadump_reg_entry {
	__be64 reg_id;
	__be64 reg_value;
};

enum cc_attr {
	CC_ATTR_MEM_ENCRYPT = 0,
	CC_ATTR_HOST_MEM_ENCRYPT = 1,
	CC_ATTR_GUEST_MEM_ENCRYPT = 2,
	CC_ATTR_GUEST_STATE_ENCRYPT = 3,
	CC_ATTR_GUEST_UNROLL_STRING_IO = 4,
	CC_ATTR_HOTPLUG_DISABLED = 5,
	CC_ATTR_GUEST_SEV_SNP = 6,
};

struct platform_suspend_ops {
	int (*valid)(suspend_state_t);
	int (*begin)(suspend_state_t);
	int (*prepare)();
	int (*prepare_late)();
	int (*enter)(suspend_state_t);
	void (*wake)();
	void (*finish)();
	bool (*suspend_again)();
	void (*end)();
	void (*recover)();
};

struct hv_vas_all_caps {
	__be64 descriptor;
	__be64 feat_type;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
};

struct vas_all_caps {
	u64 descriptor;
	u64 feat_type;
};

enum vas_cop_feat_type {
	VAS_GZIP_QOS_FEAT_TYPE = 0,
	VAS_GZIP_DEF_FEAT_TYPE = 1,
	VAS_MAX_FEAT_TYPE = 2,
};

struct hv_vas_cop_feat_caps {
	__be64 descriptor;
	u8 win_type;
	u8 user_mode;
	__be16 max_lpar_creds;
	__be16 max_win_creds;
	union {
		__be16 reserved;
		__be16 def_lpar_creds;
	};
	__be16 target_lpar_creds;
	long: 48;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
};

struct vas_cop_feat_caps {
	u64 descriptor;
	u8 win_type;
	u8 user_mode;
	u16 max_lpar_creds;
	u16 max_win_creds;
	union {
		u16 reserved;
		u16 def_lpar_creds;
	};
	atomic_t nr_total_credits;
	atomic_t nr_used_credits;
};

struct vas_caps {
	struct vas_cop_feat_caps caps;
	struct list_head list;
	int nr_open_wins_progress;
	int nr_close_wins;
	int nr_open_windows;
	u8 feat;
};

struct pseries_vas_window {
	struct vas_window vas_win;
	u64 win_addr;
	u8 win_type;
	u32 complete_irq;
	u32 fault_irq;
	u64 domain[6];
	u64 util;
	u32 pid;
	struct list_head win_list;
	u64 flags;
	char *name;
	int fault_virq;
	atomic_t pending_faults;
};

struct vas_caps_entry {
	struct kobject kobj;
	struct vas_cop_feat_caps *caps;
};

struct vas_sysfs_entry {
	struct attribute attr;
	ssize_t (*show)(struct vas_cop_feat_caps *, char *);
	ssize_t (*store)(struct vas_cop_feat_caps *, const char *, size_t);
};

struct vas_tx_win_open_attr {
	__u32 version;
	__s16 vas_id;
	__u16 reserved1;
	__u64 flags;
	__u64 reserved2[6];
};

struct coproc_dev {
	struct cdev cdev;
	struct device *device;
	char *name;
	dev_t devt;
	struct class *class;
	enum vas_cop_type cop_type;
	const struct vas_user_win_ops *vops;
};

struct coproc_instance {
	struct coproc_dev *coproc;
	struct vas_window *txwin;
};

enum {
	DUMP_PREFIX_NONE = 0,
	DUMP_PREFIX_ADDRESS = 1,
	DUMP_PREFIX_OFFSET = 2,
};

struct bpf_binary_header {
	u32 pages;
	int: 32;
	u8 image[0];
};

struct codegen_context {
	unsigned int seen;
	unsigned int idx;
	unsigned int stack_size;
	int b2p[14];
	unsigned int exentry_idx;
	unsigned int alt_exit_addr;
};

struct powerpc64_jit_data {
	struct bpf_binary_header *header;
	u32 *addrs;
	u8 *image;
	u32 proglen;
	struct codegen_context ctx;
};

enum {
	BPF_REG_0 = 0,
	BPF_REG_1 = 1,
	BPF_REG_2 = 2,
	BPF_REG_3 = 3,
	BPF_REG_4 = 4,
	BPF_REG_5 = 5,
	BPF_REG_6 = 6,
	BPF_REG_7 = 7,
	BPF_REG_8 = 8,
	BPF_REG_9 = 9,
	BPF_REG_10 = 10,
	__MAX_BPF_REG = 11,
};

enum tk_offsets {
	TK_OFFS_REAL = 0,
	TK_OFFS_BOOT = 1,
	TK_OFFS_TAI = 2,
	TK_OFFS_MAX = 3,
};

struct spu_context;

struct spu_runqueue;

struct spu_problem;

struct spu_priv2;

struct spu_priv1;

struct spu {
	const char *name;
	long unsigned int local_store_phys;
	u8 *local_store;
	long unsigned int problem_phys;
	struct spu_problem *problem;
	struct spu_priv2 *priv2;
	struct list_head cbe_list;
	struct list_head full_list;
	enum {
		SPU_FREE = 0,
		SPU_USED = 1,
	} alloc_state;
	int number;
	unsigned int irqs[3];
	u32 node;
	long unsigned int flags;
	u64 class_0_pending;
	u64 class_0_dar;
	u64 class_1_dar;
	u64 class_1_dsisr;
	size_t ls_size;
	unsigned int slb_replace;
	struct mm_struct *mm;
	struct spu_context *ctx;
	struct spu_runqueue *rq;
	long long unsigned int timestamp;
	pid_t pid;
	pid_t tgid;
	spinlock_t register_lock;
	void (*wbox_callback)(struct spu *);
	void (*ibox_callback)(struct spu *);
	void (*stop_callback)(struct spu *, int);
	void (*mfc_callback)(struct spu *);
	char irq_c0[8];
	char irq_c1[8];
	char irq_c2[8];
	u64 spe_id;
	void *pdata;
	struct device_node *devnode;
	struct spu_priv1 *priv1;
	u64 shadow_int_mask_RW[3];
	struct device dev;
	int has_mem_affinity;
	struct list_head aff_list;
	struct {
		enum spu_utilization_state util_state;
		long long unsigned int tstamp;
		long long unsigned int times[4];
		long long unsigned int vol_ctx_switch;
		long long unsigned int invol_ctx_switch;
		long long unsigned int min_flt;
		long long unsigned int maj_flt;
		long long unsigned int hash_flt;
		long long unsigned int slb_flt;
		long long unsigned int class2_intr;
		long long unsigned int libassist;
	} stats;
};

union mfc_tag_size_class_cmd {
	struct {
		u16 mfc_size;
		u16 mfc_tag;
		u8 pad;
		u8 mfc_rclassid;
		u16 mfc_cmd;
	} u;
	struct {
		u32 mfc_size_tag32;
		u32 mfc_class_cmd32;
	} by32;
	u64 all64;
};

struct spu_problem {
	u64 spc_mssync_RW;
	u8 pad_0x0008_0x3000[12280];
	u8 pad_0x3000_0x3004[4];
	u32 mfc_lsa_W;
	u64 mfc_ea_W;
	union mfc_tag_size_class_cmd mfc_union_W;
	u8 pad_0x3018_0x3104[236];
	u32 dma_qstatus_R;
	u8 pad_0x3108_0x3204[252];
	u32 dma_querytype_RW;
	u8 pad_0x3208_0x321c[20];
	u32 dma_querymask_RW;
	u8 pad_0x3220_0x322c[12];
	u32 dma_tagstatus_R;
	u8 pad_0x3230_0x4000[3536];
	u8 pad_0x4000_0x4004[4];
	u32 pu_mb_R;
	u8 pad_0x4008_0x400c[4];
	u32 spu_mb_W;
	u8 pad_0x4010_0x4014[4];
	u32 mb_stat_R;
	u8 pad_0x4018_0x401c[4];
	u32 spu_runcntl_RW;
	u8 pad_0x4020_0x4024[4];
	u32 spu_status_R;
	u8 pad_0x4028_0x402c[4];
	u32 spu_spe_R;
	u8 pad_0x4030_0x4034[4];
	u32 spu_npc_RW;
	u8 pad_0x4038_0x14000[65480];
	u8 pad_0x14000_0x1400c[12];
	u32 signal_notify1;
	u8 pad_0x14010_0x1c00c[32764];
	u32 signal_notify2;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
};

struct mfc_cq_sr {
	u64 mfc_cq_data0_RW;
	u64 mfc_cq_data1_RW;
	u64 mfc_cq_data2_RW;
	u64 mfc_cq_data3_RW;
};

struct spu_priv2 {
	u8 pad_0x0000_0x1100[4352];
	u8 pad_0x1100_0x1108[8];
	u64 slb_index_W;
	u64 slb_esid_RW;
	u64 slb_vsid_RW;
	u64 slb_invalidate_entry_W;
	u64 slb_invalidate_all_W;
	u8 pad_0x1130_0x2000[3792];
	struct mfc_cq_sr spuq[16];
	struct mfc_cq_sr puq[8];
	u8 pad_0x2300_0x3000[3328];
	u64 mfc_control_RW;
	u8 pad_0x3008_0x4000[4088];
	u64 puint_mb_R;
	u8 pad_0x4008_0x4040[56];
	u64 spu_privcntl_RW;
	u8 pad_0x4048_0x4058[16];
	u64 spu_lslr_RW;
	u64 spu_chnlcntptr_RW;
	u64 spu_chnlcnt_RW;
	u64 spu_chnldata_RW;
	u64 spu_cfg_RW;
	u8 pad_0x4080_0x5000[3968];
	u64 spu_pm_trace_tag_status_RW;
	u64 spu_tag_status_query_RW;
	u64 spu_cmd_buf1_RW;
	u64 spu_cmd_buf2_RW;
	u64 spu_atomic_status_RW;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
};

struct spu_priv1 {
	u64 mfc_sr1_RW;
	u64 mfc_lpid_RW;
	u64 spu_idr_RW;
	u64 mfc_vr_RO;
	u64 spu_vr_RO;
	u8 pad_0x28_0x100[216];
	u64 int_mask_RW[3];
	u8 pad_0x118_0x140[40];
	u64 int_stat_RW[3];
	u8 pad_0x158_0x180[40];
	u64 int_route_RW;
	u8 pad_0x188_0x200[120];
	u64 mfc_atomic_flush_RW;
	u8 pad_0x208_0x280[120];
	u64 resource_allocation_groupID_RW;
	u64 resource_allocation_enable_RW;
	u8 pad_0x290_0x3c8[312];
	u64 smf_sbi_signal_sel;
	u64 smf_ato_signal_sel;
	u8 pad_0x3d8_0x400[40];
	u64 mfc_sdr_RW;
	u8 pad_0x408_0x500[248];
	u64 tlb_index_hint_RO;
	u64 tlb_index_W;
	u64 tlb_vpn_RW;
	u64 tlb_rpn_RW;
	u8 pad_0x520_0x540[32];
	u64 tlb_invalidate_entry_W;
	u64 tlb_invalidate_all_W;
	u8 pad_0x550_0x580[48];
	u64 smm_hid;
	u8 pad_0x588_0x600[120];
	u64 mfc_accr_RW;
	u8 pad_0x608_0x610[8];
	u64 mfc_dsisr_RW;
	u8 pad_0x618_0x620[8];
	u64 mfc_dar_RW;
	u8 pad_0x628_0x700[216];
	u64 rmt_index_RW;
	u8 pad_0x708_0x710[8];
	u64 rmt_data1_RW;
	u8 pad_0x718_0x800[232];
	u64 mfc_dsir_R;
	u64 mfc_lsacr_RW;
	u64 mfc_lscrr_R;
	u8 pad_0x818_0x820[8];
	u64 mfc_tclass_id_RW;
	u8 pad_0x828_0x900[216];
	u64 mfc_rm_boundary;
	u8 pad_0x908_0x938[48];
	u64 smf_dma_signal_sel;
	u8 pad_0x940_0xa38[248];
	u64 smm_signal_sel;
	u8 pad_0xa40_0xc00[448];
	u64 mfc_cer_R;
	u8 pad_0xc08_0x1000[1016];
	u64 spu_ecc_cntl_RW;
	u64 spu_ecc_stat_RW;
	u64 spu_ecc_addr_RW;
	u64 spu_err_mask_RW;
	u8 pad_0x1020_0x1028[8];
	u64 spu_trig0_sel;
	u64 spu_trig1_sel;
	u64 spu_trig2_sel;
	u64 spu_trig3_sel;
	u64 spu_trace_sel;
	u64 spu_event0_sel;
	u64 spu_event1_sel;
	u64 spu_event2_sel;
	u64 spu_event3_sel;
	u64 spu_trace_cntl;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
};

struct spu_priv1_ops {
	void (*int_mask_and)(struct spu *, int, u64);
	void (*int_mask_or)(struct spu *, int, u64);
	void (*int_mask_set)(struct spu *, int, u64);
	u64 (*int_mask_get)(struct spu *, int);
	void (*int_stat_clear)(struct spu *, int, u64);
	u64 (*int_stat_get)(struct spu *, int);
	void (*cpu_affinity_set)(struct spu *, int);
	u64 (*mfc_dar_get)(struct spu *);
	u64 (*mfc_dsisr_get)(struct spu *);
	void (*mfc_dsisr_set)(struct spu *, u64);
	void (*mfc_sdr_setup)(struct spu *);
	void (*mfc_sr1_set)(struct spu *, u64);
	u64 (*mfc_sr1_get)(struct spu *);
	void (*mfc_tclass_id_set)(struct spu *, u64);
	u64 (*mfc_tclass_id_get)(struct spu *);
	void (*tlb_invalidate)(struct spu *);
	void (*resource_allocation_groupID_set)(struct spu *, u64);
	u64 (*resource_allocation_groupID_get)(struct spu *);
	void (*resource_allocation_enable_set)(struct spu *, u64);
	u64 (*resource_allocation_enable_get)(struct spu *);
};

struct spu_management_ops {
	int (*enumerate_spus)(int (*)(void *));
	int (*create_spu)(struct spu *, void *);
	int (*destroy_spu)(struct spu *);
	void (*enable_spu)(struct spu_context *);
	void (*disable_spu)(struct spu_context *);
	int (*init_affinity)();
};

enum {
	XIVE_DUMP_TM_HYP = 0,
	XIVE_DUMP_TM_POOL = 1,
	XIVE_DUMP_TM_OS = 2,
	XIVE_DUMP_TM_USER = 3,
	XIVE_DUMP_VP = 4,
	XIVE_DUMP_EMU_STATE = 5,
};

struct bpt {
	long unsigned int address;
	struct ppc_inst *instr;
	atomic_t ref_count;
	int enabled;
	long unsigned int pad;
};

typedef int (*instruction_dump_func)(long unsigned int, long unsigned int);

typedef long unsigned int (*callfunc_t)(long unsigned int, long unsigned int, long unsigned int, long unsigned int, long unsigned int, long unsigned int, long unsigned int, long unsigned int);

typedef uint64_t ppc_cpu_t;

struct powerpc_opcode {
	const char *name;
	long unsigned int opcode;
	long unsigned int mask;
	ppc_cpu_t flags;
	ppc_cpu_t deprecated;
	unsigned char operands[8];
};

struct powerpc_operand {
	unsigned int bitm;
	int shift;
	long unsigned int (*insert)(long unsigned int, long int, ppc_cpu_t, const char **);
	long int (*extract)(long unsigned int, ppc_cpu_t, int *);
	long unsigned int flags;
};

struct powerpc_macro {
	const char *name;
	unsigned int operands;
	ppc_cpu_t flags;
	const char *format;
};

struct kvmppc_spapr_tce_iommu_table {
	struct callback_head rcu;
	struct list_head next;
	struct iommu_table *tbl;
	struct kref kref;
};

struct kvmppc_spapr_tce_table {
	struct list_head list;
	struct kvm *kvm;
	u64 liobn;
	struct callback_head rcu;
	u32 page_shift;
	u64 offset;
	u64 size;
	struct list_head iommu_tables;
	struct mutex alloc_lock;
	struct page *pages[0];
};

struct mm_iommu_table_group_mem_t___2;

struct kvmppc_xive_src_block;

struct kvmppc_xive_ops;

struct kvmppc_xive {
	struct kvm *kvm;
	struct kvm_device *dev;
	struct dentry *dentry;
	u32 vp_base;
	struct kvmppc_xive_src_block *src_blocks[1024];
	u32 max_sbid;
	u32 src_count;
	u32 saved_src_count;
	u32 delayed_irqs;
	u8 qmap;
	u32 q_order;
	u32 q_page_order;
	u8 single_escalation;
	u32 nr_servers;
	struct kvmppc_xive_ops *ops;
	struct address_space *mapping;
	struct mutex mapping_lock;
	struct mutex lock;
};

struct kvmppc_ics;

struct kvmppc_xics {
	struct kvm *kvm;
	struct kvm_device *dev;
	struct dentry *dentry;
	u32 max_icsid;
	bool real_mode;
	bool real_mode_dbg;
	u32 err_noics;
	u32 err_noicp;
	struct kvmppc_ics *ics[1024];
};

union kvmppc_icp_state {
	long unsigned int raw;
	struct {
		u8 out_ee: 1;
		u8 need_resend: 1;
		u8 cppr;
		u8 mfrr;
		u8 pending_pri;
		u32 xisr;
	};
};

struct kvmppc_icp {
	struct kvm_vcpu *vcpu;
	long unsigned int server_num;
	union kvmppc_icp_state state;
	long unsigned int resend_map[16];
	u32 rm_action;
	struct kvm_vcpu *rm_kick_target;
	struct kvmppc_icp *rm_resend_icp;
	u32 rm_reject;
	u32 rm_eoied_irq;
	long unsigned int n_rm_kick_vcpu;
	long unsigned int n_rm_check_resend;
	long unsigned int n_rm_notify_eoi;
	long unsigned int n_check_resend;
	long unsigned int n_reject;
	union kvmppc_icp_state rm_dbgstate;
	struct kvm_vcpu *rm_dbgtgt;
};

struct kvmppc_xive_vcpu {
	struct kvmppc_xive *xive;
	struct kvm_vcpu *vcpu;
	bool valid;
	u32 server_num;
	u32 vp_id;
	u32 vp_chip_id;
	u32 vp_cam;
	u32 vp_ipi;
	struct xive_irq_data vp_ipi_data;
	uint8_t cppr;
	uint8_t hw_cppr;
	uint8_t mfrr;
	uint8_t pending;
	struct xive_q queues[8];
	u32 esc_virq[8];
	char *esc_virq_names[8];
	u32 delayed_irq;
	u64 stat_rm_h_xirr;
	u64 stat_rm_h_ipoll;
	u64 stat_rm_h_cppr;
	u64 stat_rm_h_eoi;
	u64 stat_rm_h_ipi;
	u64 stat_vm_h_xirr;
	u64 stat_vm_h_ipoll;
	u64 stat_vm_h_cppr;
	u64 stat_vm_h_eoi;
	u64 stat_vm_h_ipi;
};

struct ics_irq_state {
	u32 number;
	u32 server;
	u32 pq_state;
	u8 priority;
	u8 saved_priority;
	u8 resend;
	u8 masked_pending;
	u8 lsi;
	u8 exists;
	int intr_cpu;
	u32 host_irq;
};

struct kvmppc_ics {
	arch_spinlock_t lock;
	u16 icsid;
	struct ics_irq_state irq_state[1024];
};

struct kvmppc_xive_irq_state {
	bool valid;
	u32 number;
	u32 ipi_number;
	struct xive_irq_data ipi_data;
	u32 pt_number;
	struct xive_irq_data *pt_data;
	u8 guest_priority;
	u8 saved_priority;
	u32 act_server;
	u8 act_priority;
	bool in_eoi;
	bool old_p;
	bool old_q;
	bool lsi;
	bool asserted;
	bool in_queue;
	bool saved_p;
	bool saved_q;
	u8 saved_scan_prio;
	u32 eisn;
};

struct kvmppc_xive_src_block {
	arch_spinlock_t lock;
	u16 id;
	struct kvmppc_xive_irq_state irq_state[1024];
};

struct kvmppc_xive_ops {
	int (*reset_mapped)(struct kvm *, long unsigned int);
};

enum {
	scan_fetch = 0,
	scan_poll = 1,
	scan_eoi = 2,
};

enum perf_callchain_context {
	PERF_CONTEXT_HV = 4294967264,
	PERF_CONTEXT_KERNEL = 4294967168,
	PERF_CONTEXT_USER = 4294966784,
	PERF_CONTEXT_GUEST = 4294965248,
	PERF_CONTEXT_GUEST_KERNEL = 4294965120,
	PERF_CONTEXT_GUEST_USER = 4294964736,
	PERF_CONTEXT_MAX = 4294963201,
};

struct perf_callchain_entry_ctx {
	struct perf_callchain_entry *entry;
	u32 max_stack;
	u32 nr;
	short int contexts;
	bool contexts_maxed;
};

struct signal_frame_64 {
	char dummy[128];
	struct ucontext uc;
	long unsigned int unused[2];
	unsigned int tramp[6];
	struct siginfo *pinfo;
	void *puc;
	struct siginfo info;
	char abigap[288];
};

struct signal_frame_32 {
	char dummy[64];
	struct sigcontext32 sctx;
	struct mcontext32 mctx;
	int abigap[56];
};

struct rt_signal_frame_32 {
	char dummy[80];
	compat_siginfo_t info;
	struct ucontext32 uc;
	int abigap[56];
};

enum perf_sample_regs_abi {
	PERF_SAMPLE_REGS_ABI_NONE = 0,
	PERF_SAMPLE_REGS_ABI_32 = 1,
	PERF_SAMPLE_REGS_ABI_64 = 2,
};

enum perf_event_powerpc_regs {
	PERF_REG_POWERPC_R0 = 0,
	PERF_REG_POWERPC_R1 = 1,
	PERF_REG_POWERPC_R2 = 2,
	PERF_REG_POWERPC_R3 = 3,
	PERF_REG_POWERPC_R4 = 4,
	PERF_REG_POWERPC_R5 = 5,
	PERF_REG_POWERPC_R6 = 6,
	PERF_REG_POWERPC_R7 = 7,
	PERF_REG_POWERPC_R8 = 8,
	PERF_REG_POWERPC_R9 = 9,
	PERF_REG_POWERPC_R10 = 10,
	PERF_REG_POWERPC_R11 = 11,
	PERF_REG_POWERPC_R12 = 12,
	PERF_REG_POWERPC_R13 = 13,
	PERF_REG_POWERPC_R14 = 14,
	PERF_REG_POWERPC_R15 = 15,
	PERF_REG_POWERPC_R16 = 16,
	PERF_REG_POWERPC_R17 = 17,
	PERF_REG_POWERPC_R18 = 18,
	PERF_REG_POWERPC_R19 = 19,
	PERF_REG_POWERPC_R20 = 20,
	PERF_REG_POWERPC_R21 = 21,
	PERF_REG_POWERPC_R22 = 22,
	PERF_REG_POWERPC_R23 = 23,
	PERF_REG_POWERPC_R24 = 24,
	PERF_REG_POWERPC_R25 = 25,
	PERF_REG_POWERPC_R26 = 26,
	PERF_REG_POWERPC_R27 = 27,
	PERF_REG_POWERPC_R28 = 28,
	PERF_REG_POWERPC_R29 = 29,
	PERF_REG_POWERPC_R30 = 30,
	PERF_REG_POWERPC_R31 = 31,
	PERF_REG_POWERPC_NIP = 32,
	PERF_REG_POWERPC_MSR = 33,
	PERF_REG_POWERPC_ORIG_R3 = 34,
	PERF_REG_POWERPC_CTR = 35,
	PERF_REG_POWERPC_LINK = 36,
	PERF_REG_POWERPC_XER = 37,
	PERF_REG_POWERPC_CCR = 38,
	PERF_REG_POWERPC_SOFTE = 39,
	PERF_REG_POWERPC_TRAP = 40,
	PERF_REG_POWERPC_DAR = 41,
	PERF_REG_POWERPC_DSISR = 42,
	PERF_REG_POWERPC_SIER = 43,
	PERF_REG_POWERPC_MMCRA = 44,
	PERF_REG_POWERPC_MMCR0 = 45,
	PERF_REG_POWERPC_MMCR1 = 46,
	PERF_REG_POWERPC_MMCR2 = 47,
	PERF_REG_POWERPC_MMCR3 = 48,
	PERF_REG_POWERPC_SIER2 = 49,
	PERF_REG_POWERPC_SIER3 = 50,
	PERF_REG_POWERPC_PMC1 = 51,
	PERF_REG_POWERPC_PMC2 = 52,
	PERF_REG_POWERPC_PMC3 = 53,
	PERF_REG_POWERPC_PMC4 = 54,
	PERF_REG_POWERPC_PMC5 = 55,
	PERF_REG_POWERPC_PMC6 = 56,
	PERF_REG_POWERPC_SDAR = 57,
	PERF_REG_POWERPC_SIAR = 58,
	PERF_REG_POWERPC_MAX = 45,
	PERF_REG_EXTENDED_MAX = 59,
};

enum perf_event_sample_format {
	PERF_SAMPLE_IP = 1,
	PERF_SAMPLE_TID = 2,
	PERF_SAMPLE_TIME = 4,
	PERF_SAMPLE_ADDR = 8,
	PERF_SAMPLE_READ = 16,
	PERF_SAMPLE_CALLCHAIN = 32,
	PERF_SAMPLE_ID = 64,
	PERF_SAMPLE_CPU = 128,
	PERF_SAMPLE_PERIOD = 256,
	PERF_SAMPLE_STREAM_ID = 512,
	PERF_SAMPLE_RAW = 1024,
	PERF_SAMPLE_BRANCH_STACK = 2048,
	PERF_SAMPLE_REGS_USER = 4096,
	PERF_SAMPLE_STACK_USER = 8192,
	PERF_SAMPLE_WEIGHT = 16384,
	PERF_SAMPLE_DATA_SRC = 32768,
	PERF_SAMPLE_IDENTIFIER = 65536,
	PERF_SAMPLE_TRANSACTION = 131072,
	PERF_SAMPLE_REGS_INTR = 262144,
	PERF_SAMPLE_PHYS_ADDR = 524288,
	PERF_SAMPLE_AUX = 1048576,
	PERF_SAMPLE_CGROUP = 2097152,
	PERF_SAMPLE_DATA_PAGE_SIZE = 4194304,
	PERF_SAMPLE_CODE_PAGE_SIZE = 8388608,
	PERF_SAMPLE_WEIGHT_STRUCT = 16777216,
	PERF_SAMPLE_MAX = 33554432,
	__PERF_SAMPLE_CALLCHAIN_EARLY = 0,
};

struct mmcr_regs {
	long unsigned int mmcr0;
	long unsigned int mmcr1;
	long unsigned int mmcr2;
	long unsigned int mmcra;
	long unsigned int mmcr3;
};

struct power_pmu {
	const char *name;
	int n_counter;
	int max_alternatives;
	long unsigned int add_fields;
	long unsigned int test_adder;
	int (*compute_mmcr)(u64 *, int, unsigned int *, struct mmcr_regs *, struct perf_event **, u32);
	int (*get_constraint)(u64, long unsigned int *, long unsigned int *, u64);
	int (*get_alternatives)(u64, unsigned int, u64 *);
	void (*get_mem_data_src)(union perf_mem_data_src *, u32, struct pt_regs *);
	void (*get_mem_weight)(u64 *, u64);
	long unsigned int group_constraint_mask;
	long unsigned int group_constraint_val;
	u64 (*bhrb_filter_map)(u64);
	void (*config_bhrb)(u64);
	void (*disable_pmc)(unsigned int, struct mmcr_regs *);
	int (*limited_pmc_event)(u64);
	u32 flags;
	const struct attribute_group **attr_groups;
	int n_generic;
	int *generic_events;
	u64 (*cache_events)[42];
	int n_blacklist_ev;
	int *blacklist_ev;
	int bhrb_nr;
	int capabilities;
	int (*check_attr_config)(struct perf_event *);
};

struct perf_pmu_events_attr {
	struct device_attribute attr;
	u64 id;
	const char *event_str;
};

struct cpu_hw_events {
	int n_events;
	int n_percpu;
	int disabled;
	int n_added;
	int n_limited;
	u8 pmcs_enabled;
	struct perf_event *event[8];
	u64 events[8];
	unsigned int flags[8];
	struct mmcr_regs mmcr;
	struct perf_event *limited_counter[2];
	u8 limited_hwidx[2];
	u64 alternatives[64];
	long unsigned int amasks[64];
	long unsigned int avalues[64];
	unsigned int txn_flags;
	int n_txn_start;
	u64 bhrb_filter;
	unsigned int bhrb_users;
	void *bhrb_context;
	struct perf_branch_stack bhrb_stack;
	struct perf_branch_entry bhrb_entries[32];
	u64 ic_init;
	long unsigned int pmcs[8];
};

struct perf_event_header {
	__u32 type;
	__u16 misc;
	__u16 size;
};

enum perf_event_type {
	PERF_RECORD_MMAP = 1,
	PERF_RECORD_LOST = 2,
	PERF_RECORD_COMM = 3,
	PERF_RECORD_EXIT = 4,
	PERF_RECORD_THROTTLE = 5,
	PERF_RECORD_UNTHROTTLE = 6,
	PERF_RECORD_FORK = 7,
	PERF_RECORD_READ = 8,
	PERF_RECORD_SAMPLE = 9,
	PERF_RECORD_MMAP2 = 10,
	PERF_RECORD_AUX = 11,
	PERF_RECORD_ITRACE_START = 12,
	PERF_RECORD_LOST_SAMPLES = 13,
	PERF_RECORD_SWITCH = 14,
	PERF_RECORD_SWITCH_CPU_WIDE = 15,
	PERF_RECORD_NAMESPACES = 16,
	PERF_RECORD_KSYMBOL = 17,
	PERF_RECORD_BPF_EVENT = 18,
	PERF_RECORD_CGROUP = 19,
	PERF_RECORD_TEXT_POKE = 20,
	PERF_RECORD_MAX = 21,
};

struct trace_imc_data {
	u64 tb1;
	u64 ip;
	u64 val;
	u64 cpmc1;
	u64 cpmc2;
	u64 cpmc3;
	u64 cpmc4;
	u64 tb2;
};

struct imc_pmu_ref {
	struct mutex lock;
	unsigned int id;
	int refc;
};

enum hv_perf_domains {
	HV_PERF_DOMAIN_PHYS_CHIP = 1,
	HV_PERF_DOMAIN_PHYS_CORE = 2,
	HV_PERF_DOMAIN_VCPU_HOME_CORE = 3,
	HV_PERF_DOMAIN_VCPU_HOME_CHIP = 4,
	HV_PERF_DOMAIN_VCPU_HOME_NODE = 5,
	HV_PERF_DOMAIN_VCPU_REMOTE_NODE = 6,
	HV_PERF_DOMAIN_MAX = 7,
};

struct hv_24x7_request {
	__u8 performance_domain;
	__u8 reserved[1];
	__be16 data_size;
	__be32 data_offset;
	__be16 starting_lpar_ix;
	__be16 max_num_lpars;
	__be16 starting_ix;
	__be16 max_ix;
	__u8 starting_thread_group_ix;
	__u8 max_num_thread_groups;
	__u8 reserved2[14];
};

struct hv_24x7_request_buffer {
	__u8 interface_version;
	__u8 num_requests;
	__u8 reserved[14];
	struct hv_24x7_request requests[0];
};

struct hv_24x7_result {
	__u8 result_ix;
	__u8 results_complete;
	__be16 num_elements_returned;
	__be16 result_element_data_size;
	__u8 reserved[2];
	char elements[0];
};

struct hv_24x7_data_result_buffer {
	__u8 interface_version;
	__u8 num_results;
	__u8 reserved[1];
	__u8 failing_request_ix;
	__be32 detailed_rc;
	__be64 cec_cfg_instance_id;
	__be64 catalog_version_num;
	__u8 reserved2[8];
	struct hv_24x7_result results[0];
};

struct hv_24x7_catalog_page_0 {
	__be32 magic;
	__be32 length;
	__be64 version;
	__u8 build_time_stamp[16];
	__u8 reserved2[32];
	__be16 schema_data_offs;
	__be16 schema_data_len;
	__be16 schema_entry_count;
	__u8 reserved3[2];
	__be16 event_data_offs;
	__be16 event_data_len;
	__be16 event_entry_count;
	__u8 reserved4[2];
	__be16 group_data_offs;
	__be16 group_data_len;
	__be16 group_entry_count;
	__u8 reserved5[2];
	__be16 formula_data_offs;
	__be16 formula_data_len;
	__be16 formula_entry_count;
	__u8 reserved6[2];
};

struct hv_24x7_event_data {
	__be16 length;
	__u8 reserved1[2];
	__u8 domain;
	__u8 reserved2[1];
	__be16 event_group_record_offs;
	__be16 event_group_record_len;
	__be16 event_counter_offs;
	__be32 flags;
	__be16 primary_group_ix;
	__be16 group_count;
	__be16 event_name_len;
	__u8 remainder[0];
} __attribute__((packed));

struct hv_perf_caps {
	u16 version;
	u16 collect_privileged: 1;
	u16 ga: 1;
	u16 expanded: 1;
	u16 lab: 1;
	u16 unused: 12;
};

struct hv_24x7_hw {
	struct perf_event *events[255];
};

struct event_uniq {
	struct rb_node node;
	const char *name;
	int nl;
	unsigned int ct;
	unsigned int domain;
};

enum {
	PROCESSOR_BUS_TOPOLOGY = 0,
	PROCESSOR_CONFIG = 1,
	AFFINITY_DOMAIN_VIA_VP = 2,
	AFFINITY_DOMAIN_VIA_DOM = 3,
	AFFINITY_DOMAIN_VIA_PAR = 4,
};

enum {
	HV_GPCI_CM_GA = 128,
	HV_GPCI_CM_EXPANDED = 64,
	HV_GPCI_CM_LAB = 32,
};

enum hv_gpci_requests {
	HV_GPCI_dispatch_timebase_by_processor = 16,
	HV_GPCI_entitled_capped_uncapped_donated_idle_timebase_by_partition = 32,
	HV_GPCI_run_instructions_run_cycles_by_partition = 48,
	HV_GPCI_system_performance_capabilities = 64,
	HV_GPCI_processor_bus_utilization_abc_links = 80,
	HV_GPCI_processor_bus_utilization_wxyz_links = 96,
	HV_GPCI_processor_bus_utilization_gx_links = 112,
	HV_GPCI_processor_bus_utilization_mc_links = 128,
	HV_GPCI_processor_core_utilization = 148,
	HV_GPCI_partition_hypervisor_queuing_times = 224,
	HV_GPCI_system_hypervisor_times = 240,
	HV_GPCI_system_tlbie_count_and_time = 244,
	HV_GPCI_partition_instruction_count_and_time = 256,
};

struct hv_gpci_system_performance_capabilities {
	__u8 perf_collect_privileged;
	__u8 capability_mask;
	__u8 reserved[14];
};

struct p {
	struct hv_get_perf_counter_info_params params;
	struct hv_gpci_system_performance_capabilities caps;
};

enum perf_hw_id {
	PERF_COUNT_HW_CPU_CYCLES = 0,
	PERF_COUNT_HW_INSTRUCTIONS = 1,
	PERF_COUNT_HW_CACHE_REFERENCES = 2,
	PERF_COUNT_HW_CACHE_MISSES = 3,
	PERF_COUNT_HW_BRANCH_INSTRUCTIONS = 4,
	PERF_COUNT_HW_BRANCH_MISSES = 5,
	PERF_COUNT_HW_BUS_CYCLES = 6,
	PERF_COUNT_HW_STALLED_CYCLES_FRONTEND = 7,
	PERF_COUNT_HW_STALLED_CYCLES_BACKEND = 8,
	PERF_COUNT_HW_REF_CPU_CYCLES = 9,
	PERF_COUNT_HW_MAX = 10,
};

enum {
	PM_IC_DEMAND_L2_BR_ALL = 18584,
	PM_GCT_UTIL_7_TO_10_SLOTS = 8352,
	PM_PMC2_SAVED = 65570,
	PM_CMPLU_STALL_DFU = 131132,
	PM_VSU0_16FLOP = 41124,
	PM_MRK_LSU_DERAT_MISS = 249946,
	PM_MRK_ST_CMPL = 65588,
	PM_NEST_PAIR3_ADD = 264321,
	PM_L2_ST_DISP = 287104,
	PM_L2_CASTOUT_MOD = 90496,
	PM_ISEG = 8356,
	PM_MRK_INST_TIMEO = 262196,
	PM_L2_RCST_DISP_FAIL_ADDR = 221826,
	PM_LSU1_DC_PREF_STREAM_CONFIRM = 53430,
	PM_IERAT_WR_64K = 16574,
	PM_MRK_DTLB_MISS_16M = 315486,
	PM_IERAT_MISS = 65782,
	PM_MRK_PTEG_FROM_LMEM = 315474,
	PM_FLOP = 65780,
	PM_THRD_PRIO_4_5_CYC = 16564,
	PM_BR_PRED_TA = 16554,
	PM_CMPLU_STALL_FXU = 131092,
	PM_EXT_INT = 131320,
	PM_VSU_FSQRT_FDIV = 43144,
	PM_MRK_LD_MISS_EXPOSED_CYC = 65598,
	PM_LSU1_LDF = 49286,
	PM_IC_WRITE_ALL = 18572,
	PM_LSU0_SRQ_STFWD = 49312,
	PM_PTEG_FROM_RL2L3_MOD = 114770,
	PM_MRK_DATA_FROM_L31_SHR = 118862,
	PM_DATA_FROM_L21_MOD = 245830,
	PM_VSU1_SCAL_DOUBLE_ISSUED = 45194,
	PM_VSU0_8FLOP = 41120,
	PM_POWER_EVENT1 = 65646,
	PM_DISP_CLB_HELD_BAL = 8338,
	PM_VSU1_2FLOP = 41114,
	PM_LWSYNC_HELD = 8346,
	PM_PTEG_FROM_DL2L3_SHR = 245844,
	PM_INST_FROM_L21_MOD = 213062,
	PM_IERAT_XLATE_WR_16MPLUS = 16572,
	PM_IC_REQ_ALL = 18568,
	PM_DSLB_MISS = 53392,
	PM_L3_MISS = 127106,
	PM_LSU0_L1_PREF = 53432,
	PM_VSU_SCALAR_SINGLE_ISSUED = 47236,
	PM_LSU1_DC_PREF_STREAM_CONFIRM_STRIDE = 53438,
	PM_L2_INST = 221312,
	PM_VSU0_FRSP = 41140,
	PM_FLUSH_DISP = 8322,
	PM_PTEG_FROM_L2MISS = 311384,
	PM_VSU1_DQ_ISSUED = 45210,
	PM_CMPLU_STALL_LSU = 131090,
	PM_MRK_DATA_FROM_DMEM = 118858,
	PM_LSU_FLUSH_ULD = 51376,
	PM_PTEG_FROM_LMEM = 311378,
	PM_MRK_DERAT_MISS_16M = 249948,
	PM_THRD_ALL_RUN_CYC = 131084,
	PM_MEM0_PREFETCH_DISP = 131203,
	PM_MRK_STALL_CMPLU_CYC_COUNT = 196671,
	PM_DATA_FROM_DL2L3_MOD = 245836,
	PM_VSU_FRSP = 43188,
	PM_MRK_DATA_FROM_L21_MOD = 249926,
	PM_PMC1_OVERFLOW = 131088,
	PM_VSU0_SINGLE = 41128,
	PM_MRK_PTEG_FROM_L3MISS = 184408,
	PM_MRK_PTEG_FROM_L31_SHR = 184406,
	PM_VSU0_VECTOR_SP_ISSUED = 45200,
	PM_VSU1_FEST = 41146,
	PM_MRK_INST_DISP = 131120,
	PM_VSU0_COMPLEX_ISSUED = 45206,
	PM_LSU1_FLUSH_UST = 49334,
	PM_INST_CMPL = 2,
	PM_FXU_IDLE = 65550,
	PM_LSU0_FLUSH_ULD = 49328,
	PM_MRK_DATA_FROM_DL2L3_MOD = 249932,
	PM_LSU_LMQ_SRQ_EMPTY_ALL_CYC = 196636,
	PM_LSU1_REJECT_LMQ_FULL = 49318,
	PM_INST_PTEG_FROM_L21_MOD = 254038,
	PM_INST_FROM_RL2L3_MOD = 81986,
	PM_SHL_CREATED = 20610,
	PM_L2_ST_HIT = 287106,
	PM_DATA_FROM_DMEM = 114762,
	PM_L3_LD_MISS = 192642,
	PM_FXU1_BUSY_FXU0_IDLE = 262158,
	PM_DISP_CLB_HELD_RES = 8340,
	PM_L2_SN_SX_I_DONE = 222082,
	PM_GRP_CMPL = 196612,
	PM_STCX_CMPL = 49304,
	PM_VSU0_2FLOP = 41112,
	PM_L3_PREF_MISS = 258178,
	PM_LSU_SRQ_SYNC_CYC = 53398,
	PM_LSU_REJECT_ERAT_MISS = 131172,
	PM_L1_ICACHE_MISS = 131324,
	PM_LSU1_FLUSH_SRQ = 49342,
	PM_LD_REF_L1_LSU0 = 49280,
	PM_VSU0_FEST = 41144,
	PM_VSU_VECTOR_SINGLE_ISSUED = 47248,
	PM_FREQ_UP = 262156,
	PM_DATA_FROM_LMEM = 245834,
	PM_LSU1_LDX = 49290,
	PM_PMC3_OVERFLOW = 262160,
	PM_MRK_BR_MPRED = 196662,
	PM_SHL_MATCH = 20614,
	PM_MRK_BR_TAKEN = 65590,
	PM_CMPLU_STALL_BRU = 262222,
	PM_ISLB_MISS = 53394,
	PM_CYC = 30,
	PM_DISP_HELD_THERMAL = 196614,
	PM_INST_PTEG_FROM_RL2L3_SHR = 188500,
	PM_LSU1_SRQ_STFWD = 49314,
	PM_GCT_NOSLOT_BR_MPRED = 262170,
	PM_1PLUS_PPC_CMPL = 65778,
	PM_PTEG_FROM_DMEM = 180306,
	PM_VSU_2FLOP = 43160,
	PM_GCT_FULL_CYC = 16518,
	PM_MRK_DATA_FROM_L3_CYC = 262176,
	PM_LSU_SRQ_S0_ALLOC = 53405,
	PM_MRK_DERAT_MISS_4K = 118876,
	PM_BR_MPRED_TA = 16558,
	PM_INST_PTEG_FROM_L2MISS = 319576,
	PM_DPU_HELD_POWER = 131078,
	PM_RUN_INST_CMPL = 262394,
	PM_MRK_VSU_FIN = 196658,
	PM_LSU_SRQ_S0_VALID = 53404,
	PM_GCT_EMPTY_CYC = 131080,
	PM_IOPS_DISP = 196628,
	PM_RUN_SPURR = 65544,
	PM_PTEG_FROM_L21_MOD = 245846,
	PM_VSU0_1FLOP = 41088,
	PM_SNOOP_TLBIE = 53426,
	PM_DATA_FROM_L3MISS = 180296,
	PM_VSU_SINGLE = 43176,
	PM_DTLB_MISS_16G = 114782,
	PM_CMPLU_STALL_VECTOR = 131100,
	PM_FLUSH = 262392,
	PM_L2_LD_HIT = 221570,
	PM_NEST_PAIR2_AND = 198787,
	PM_VSU1_1FLOP = 41090,
	PM_IC_PREF_REQ = 16522,
	PM_L3_LD_HIT = 192640,
	PM_GCT_NOSLOT_IC_MISS = 131098,
	PM_DISP_HELD = 65542,
	PM_L2_LD = 90240,
	PM_LSU_FLUSH_SRQ = 51388,
	PM_BC_PLUS_8_CONV = 16568,
	PM_MRK_DATA_FROM_L31_MOD_CYC = 262182,
	PM_CMPLU_STALL_VECTOR_LONG = 262218,
	PM_L2_RCST_BUSY_RC_FULL = 156290,
	PM_TB_BIT_TRANS = 196856,
	PM_THERMAL_MAX = 262150,
	PM_LSU1_FLUSH_ULD = 49330,
	PM_LSU1_REJECT_LHS = 49326,
	PM_LSU_LRQ_S0_ALLOC = 53407,
	PM_L3_CO_L31 = 323712,
	PM_POWER_EVENT4 = 262254,
	PM_DATA_FROM_L31_SHR = 114766,
	PM_BR_UNCOND = 16542,
	PM_LSU1_DC_PREF_STREAM_ALLOC = 53418,
	PM_PMC4_REWIND = 65568,
	PM_L2_RCLD_DISP = 90752,
	PM_THRD_PRIO_2_3_CYC = 16562,
	PM_MRK_PTEG_FROM_L2MISS = 315480,
	PM_IC_DEMAND_L2_BHT_REDIRECT = 16536,
	PM_LSU_DERAT_MISS = 131318,
	PM_IC_PREF_CANCEL_L2 = 16532,
	PM_MRK_FIN_STALL_CYC_COUNT = 65597,
	PM_BR_PRED_CCACHE = 16544,
	PM_GCT_UTIL_1_TO_2_SLOTS = 8348,
	PM_MRK_ST_CMPL_INT = 196660,
	PM_LSU_TWO_TABLEWALK_CYC = 53414,
	PM_MRK_DATA_FROM_L3MISS = 184392,
	PM_GCT_NOSLOT_CYC = 65784,
	PM_LSU_SET_MPRED = 49320,
	PM_FLUSH_DISP_TLBIE = 8330,
	PM_VSU1_FCONV = 41138,
	PM_DERAT_MISS_16G = 311388,
	PM_INST_FROM_LMEM = 213066,
	PM_IC_DEMAND_L2_BR_REDIRECT = 16538,
	PM_CMPLU_STALL_SCALAR_LONG = 131096,
	PM_INST_PTEG_FROM_L2 = 122960,
	PM_PTEG_FROM_L2 = 114768,
	PM_MRK_DATA_FROM_L21_SHR_CYC = 131108,
	PM_MRK_DTLB_MISS_4K = 184410,
	PM_VSU0_FPSCR = 45212,
	PM_VSU1_VECT_DOUBLE_ISSUED = 45186,
	PM_MRK_PTEG_FROM_RL2L3_MOD = 118866,
	PM_MEM0_RQ_DISP = 65667,
	PM_L2_LD_MISS = 155776,
	PM_VMX_RESULT_SAT_1 = 45216,
	PM_L1_PREF = 55480,
	PM_MRK_DATA_FROM_LMEM_CYC = 131116,
	PM_GRP_IC_MISS_NONSPEC = 65548,
	PM_PB_NODE_PUMP = 65665,
	PM_SHL_MERGED = 20612,
	PM_NEST_PAIR1_ADD = 133249,
	PM_DATA_FROM_L3 = 114760,
	PM_LSU_FLUSH = 8334,
	PM_LSU_SRQ_SYNC_COUNT = 53399,
	PM_PMC2_OVERFLOW = 196624,
	PM_LSU_LDF = 51332,
	PM_POWER_EVENT3 = 196718,
	PM_DISP_WT = 196616,
	PM_CMPLU_STALL_REJECT = 262166,
	PM_IC_BANK_CONFLICT = 16514,
	PM_BR_MPRED_CR_TA = 18606,
	PM_L2_INST_MISS = 221314,
	PM_CMPLU_STALL_ERAT_MISS = 262168,
	PM_NEST_PAIR2_ADD = 198785,
	PM_MRK_LSU_FLUSH = 53388,
	PM_L2_LDST = 92288,
	PM_INST_FROM_L31_SHR = 81998,
	PM_VSU0_FIN = 41148,
	PM_LARX_LSU = 51348,
	PM_INST_FROM_RMEM = 213058,
	PM_DISP_CLB_HELD_TLBIE = 8342,
	PM_MRK_DATA_FROM_DMEM_CYC = 131118,
	PM_BR_PRED_CR = 16552,
	PM_LSU_REJECT = 65636,
	PM_GCT_UTIL_3_TO_6_SLOTS = 8350,
	PM_CMPLU_STALL_END_GCT_NOSLOT = 65576,
	PM_LSU0_REJECT_LMQ_FULL = 49316,
	PM_VSU_FEST = 43192,
	PM_NEST_PAIR0_AND = 67715,
	PM_PTEG_FROM_L3 = 180304,
	PM_POWER_EVENT2 = 131182,
	PM_IC_PREF_CANCEL_PAGE = 16528,
	PM_VSU0_FSQRT_FDIV = 41096,
	PM_MRK_GRP_CMPL = 262192,
	PM_VSU0_SCAL_DOUBLE_ISSUED = 45192,
	PM_GRP_DISP = 196618,
	PM_LSU0_LDX = 49288,
	PM_DATA_FROM_L2 = 114752,
	PM_MRK_DATA_FROM_RL2L3_MOD = 118850,
	PM_LD_REF_L1 = 51328,
	PM_VSU0_VECT_DOUBLE_ISSUED = 45184,
	PM_VSU1_2FLOP_DOUBLE = 41102,
	PM_THRD_PRIO_6_7_CYC = 16566,
	PM_BC_PLUS_8_RSLV_TAKEN = 16570,
	PM_BR_MPRED_CR = 16556,
	PM_L3_CO_MEM = 323714,
	PM_LD_MISS_L1 = 262384,
	PM_DATA_FROM_RL2L3_MOD = 114754,
	PM_LSU_SRQ_FULL_CYC = 65562,
	PM_TABLEWALK_CYC = 65574,
	PM_MRK_PTEG_FROM_RMEM = 249938,
	PM_LSU_SRQ_STFWD = 51360,
	PM_INST_PTEG_FROM_RMEM = 254034,
	PM_FXU0_FIN = 65540,
	PM_LSU1_L1_SW_PREF = 49310,
	PM_PTEG_FROM_L31_MOD = 114772,
	PM_PMC5_OVERFLOW = 65572,
	PM_LD_REF_L1_LSU1 = 49282,
	PM_INST_PTEG_FROM_L21_SHR = 319574,
	PM_CMPLU_STALL_THRD = 65564,
	PM_DATA_FROM_RMEM = 245826,
	PM_VSU0_SCAL_SINGLE_ISSUED = 45188,
	PM_BR_MPRED_LSTACK = 16550,
	PM_MRK_DATA_FROM_RL2L3_MOD_CYC = 262184,
	PM_LSU0_FLUSH_UST = 49332,
	PM_LSU_NCST = 49296,
	PM_BR_TAKEN = 131076,
	PM_INST_PTEG_FROM_LMEM = 319570,
	PM_GCT_NOSLOT_BR_MPRED_IC_MISS = 262172,
	PM_DTLB_MISS_4K = 180314,
	PM_PMC4_SAVED = 196642,
	PM_VSU1_PERMUTE_ISSUED = 45202,
	PM_SLB_MISS = 55440,
	PM_LSU1_FLUSH_LRQ = 49338,
	PM_DTLB_MISS = 196860,
	PM_VSU1_FRSP = 41142,
	PM_VSU_VECTOR_DOUBLE_ISSUED = 47232,
	PM_L2_CASTOUT_SHR = 90498,
	PM_DATA_FROM_DL2L3_SHR = 245828,
	PM_VSU1_STF = 45198,
	PM_ST_FIN = 131312,
	PM_PTEG_FROM_L21_SHR = 311382,
	PM_L2_LOC_GUESS_WRONG = 156800,
	PM_MRK_STCX_FAIL = 53390,
	PM_LSU0_REJECT_LHS = 49324,
	PM_IC_PREF_CANCEL_HIT = 16530,
	PM_L3_PREF_BUSY = 323712,
	PM_MRK_BRU_FIN = 131130,
	PM_LSU1_NCLD = 49294,
	PM_INST_PTEG_FROM_L31_MOD = 122964,
	PM_LSU_NCLD = 51340,
	PM_LSU_LDX = 51336,
	PM_L2_LOC_GUESS_CORRECT = 91264,
	PM_THRESH_TIMEO = 65592,
	PM_L3_PREF_ST = 53422,
	PM_DISP_CLB_HELD_SYNC = 8344,
	PM_VSU_SIMPLE_ISSUED = 47252,
	PM_VSU1_SINGLE = 41130,
	PM_DATA_TABLEWALK_CYC = 196634,
	PM_L2_RC_ST_DONE = 222080,
	PM_MRK_PTEG_FROM_L21_MOD = 249942,
	PM_LARX_LSU1 = 49302,
	PM_MRK_DATA_FROM_RMEM = 249922,
	PM_DISP_CLB_HELD = 8336,
	PM_DERAT_MISS_4K = 114780,
	PM_L2_RCLD_DISP_FAIL_ADDR = 90754,
	PM_SEG_EXCEPTION = 10404,
	PM_FLUSH_DISP_SB = 8332,
	PM_L2_DC_INV = 156034,
	PM_PTEG_FROM_DL2L3_MOD = 311380,
	PM_DSEG = 8358,
	PM_BR_PRED_LSTACK = 16546,
	PM_VSU0_STF = 45196,
	PM_LSU_FX_FIN = 65638,
	PM_DERAT_MISS_16M = 245852,
	PM_MRK_PTEG_FROM_DL2L3_MOD = 315476,
	PM_GCT_UTIL_11_PLUS_SLOTS = 8354,
	PM_INST_FROM_L3 = 81992,
	PM_MRK_IFU_FIN = 196666,
	PM_ITLB_MISS = 262396,
	PM_VSU_STF = 47244,
	PM_LSU_FLUSH_UST = 51380,
	PM_L2_LDST_MISS = 157824,
	PM_FXU1_FIN = 262148,
	PM_SHL_DEALLOCATED = 20608,
	PM_L2_SN_M_WR_DONE = 287618,
	PM_LSU_REJECT_SET_MPRED = 51368,
	PM_L3_PREF_LD = 53420,
	PM_L2_SN_M_RD_DONE = 287616,
	PM_MRK_DERAT_MISS_16G = 315484,
	PM_VSU_FCONV = 43184,
	PM_ANY_THRD_RUN_CYC = 65786,
	PM_LSU_LMQ_FULL_CYC = 53412,
	PM_MRK_LSU_REJECT_LHS = 53378,
	PM_MRK_LD_MISS_L1_CYC = 262206,
	PM_MRK_DATA_FROM_L2_CYC = 131104,
	PM_INST_IMC_MATCH_DISP = 196630,
	PM_MRK_DATA_FROM_RMEM_CYC = 262188,
	PM_VSU0_SIMPLE_ISSUED = 45204,
	PM_CMPLU_STALL_DIV = 262164,
	PM_MRK_PTEG_FROM_RL2L3_SHR = 184404,
	PM_VSU_FMA_DOUBLE = 43152,
	PM_VSU_4FLOP = 43164,
	PM_VSU1_FIN = 41150,
	PM_NEST_PAIR1_AND = 133251,
	PM_INST_PTEG_FROM_RL2L3_MOD = 122962,
	PM_RUN_CYC = 131316,
	PM_PTEG_FROM_RMEM = 245842,
	PM_LSU_LRQ_S0_VALID = 53406,
	PM_LSU0_LDF = 49284,
	PM_FLUSH_COMPLETION = 196626,
	PM_ST_MISS_L1 = 196848,
	PM_L2_NODE_PUMP = 222336,
	PM_INST_FROM_DL2L3_SHR = 213060,
	PM_MRK_STALL_CMPLU_CYC = 196670,
	PM_VSU1_DENORM = 41134,
	PM_MRK_DATA_FROM_L31_SHR_CYC = 131110,
	PM_NEST_PAIR0_ADD = 67713,
	PM_INST_FROM_L3MISS = 147528,
	PM_EE_OFF_EXT_INT = 8320,
	PM_INST_PTEG_FROM_DMEM = 188498,
	PM_INST_FROM_DL2L3_MOD = 213068,
	PM_PMC6_OVERFLOW = 196644,
	PM_VSU_2FLOP_DOUBLE = 43148,
	PM_TLB_MISS = 131174,
	PM_FXU_BUSY = 131086,
	PM_L2_RCLD_DISP_FAIL_OTHER = 156288,
	PM_LSU_REJECT_LMQ_FULL = 51364,
	PM_IC_RELOAD_SHR = 16534,
	PM_GRP_MRK = 65585,
	PM_MRK_ST_NEST = 131124,
	PM_VSU1_FSQRT_FDIV = 41098,
	PM_LSU0_FLUSH_LRQ = 49336,
	PM_LARX_LSU0 = 49300,
	PM_IBUF_FULL_CYC = 16516,
	PM_MRK_DATA_FROM_DL2L3_SHR_CYC = 131114,
	PM_LSU_DC_PREF_STREAM_ALLOC = 55464,
	PM_GRP_MRK_CYC = 65584,
	PM_MRK_DATA_FROM_RL2L3_SHR_CYC = 131112,
	PM_L2_GLOB_GUESS_CORRECT = 91266,
	PM_LSU_REJECT_LHS = 51372,
	PM_MRK_DATA_FROM_LMEM = 249930,
	PM_INST_PTEG_FROM_L3 = 188496,
	PM_FREQ_DOWN = 196620,
	PM_PB_RETRY_NODE_PUMP = 196737,
	PM_INST_FROM_RL2L3_SHR = 81996,
	PM_MRK_INST_ISSUED = 65586,
	PM_PTEG_FROM_L3MISS = 180312,
	PM_RUN_PURR = 262388,
	PM_MRK_GRP_IC_MISS = 262200,
	PM_MRK_DATA_FROM_L3 = 118856,
	PM_CMPLU_STALL_DCACHE_MISS = 131094,
	PM_PTEG_FROM_RL2L3_SHR = 180308,
	PM_LSU_FLUSH_LRQ = 51384,
	PM_MRK_DERAT_MISS_64K = 184412,
	PM_INST_PTEG_FROM_DL2L3_MOD = 319572,
	PM_L2_ST_MISS = 155778,
	PM_MRK_PTEG_FROM_L21_SHR = 315478,
	PM_LWSYNC = 53396,
	PM_LSU0_DC_PREF_STREAM_CONFIRM_STRIDE = 53436,
	PM_MRK_LSU_FLUSH_LRQ = 53384,
	PM_INST_IMC_MATCH_CMPL = 65776,
	PM_NEST_PAIR3_AND = 264323,
	PM_PB_RETRY_SYS_PUMP = 262273,
	PM_MRK_INST_FIN = 196656,
	PM_MRK_PTEG_FROM_DL2L3_SHR = 249940,
	PM_INST_FROM_L31_MOD = 81988,
	PM_MRK_DTLB_MISS_64K = 249950,
	PM_LSU_FIN = 196710,
	PM_MRK_LSU_REJECT = 262244,
	PM_L2_CO_FAIL_BUSY = 91010,
	PM_MEM0_WQ_DISP = 262275,
	PM_DATA_FROM_L31_MOD = 114756,
	PM_THERMAL_WARN = 65558,
	PM_VSU0_4FLOP = 41116,
	PM_BR_MPRED_CCACHE = 16548,
	PM_CMPLU_STALL_IFU = 262220,
	PM_L1_DEMAND_WRITE = 16524,
	PM_FLUSH_BR_MPRED = 8324,
	PM_MRK_DTLB_MISS_16G = 118878,
	PM_MRK_PTEG_FROM_DMEM = 184402,
	PM_L2_RCST_DISP = 221824,
	PM_CMPLU_STALL = 262154,
	PM_LSU_PARTIAL_CDF = 49322,
	PM_DISP_CLB_HELD_SB = 8360,
	PM_VSU0_FMA_DOUBLE = 41104,
	PM_FXU0_BUSY_FXU1_IDLE = 196622,
	PM_IC_DEMAND_CYC = 65560,
	PM_MRK_DATA_FROM_L21_SHR = 249934,
	PM_MRK_LSU_FLUSH_UST = 53382,
	PM_INST_PTEG_FROM_L3MISS = 188504,
	PM_VSU_DENORM = 43180,
	PM_MRK_LSU_PARTIAL_CDF = 53376,
	PM_INST_FROM_L21_SHR = 213070,
	PM_IC_PREF_WRITE = 16526,
	PM_BR_PRED = 16540,
	PM_INST_FROM_DMEM = 81994,
	PM_IC_PREF_CANCEL_ALL = 18576,
	PM_LSU_DC_PREF_STREAM_CONFIRM = 55476,
	PM_MRK_LSU_FLUSH_SRQ = 53386,
	PM_MRK_FIN_STALL_CYC = 65596,
	PM_L2_RCST_DISP_FAIL_OTHER = 287360,
	PM_VSU1_DD_ISSUED = 45208,
	PM_PTEG_FROM_L31_SHR = 180310,
	PM_DATA_FROM_L21_SHR = 245838,
	PM_LSU0_NCLD = 49292,
	PM_VSU1_4FLOP = 41118,
	PM_VSU1_8FLOP = 41122,
	PM_VSU_8FLOP = 43168,
	PM_LSU_LMQ_SRQ_EMPTY_CYC = 131134,
	PM_DTLB_MISS_64K = 245854,
	PM_THRD_CONC_RUN_INST = 196852,
	PM_MRK_PTEG_FROM_L2 = 118864,
	PM_PB_SYS_PUMP = 131201,
	PM_VSU_FIN = 43196,
	PM_MRK_DATA_FROM_L31_MOD = 118852,
	PM_THRD_PRIO_0_1_CYC = 16560,
	PM_DERAT_MISS_64K = 180316,
	PM_PMC2_REWIND = 196640,
	PM_INST_FROM_L2 = 81984,
	PM_GRP_BR_MPRED_NONSPEC = 65546,
	PM_INST_DISP = 131314,
	PM_MEM0_RD_CANCEL_TOTAL = 196739,
	PM_LSU0_DC_PREF_STREAM_CONFIRM = 53428,
	PM_L1_DCACHE_RELOAD_VALID = 196854,
	PM_VSU_SCALAR_DOUBLE_ISSUED = 47240,
	PM_L3_PREF_HIT = 258176,
	PM_MRK_PTEG_FROM_L31_MOD = 118868,
	PM_CMPLU_STALL_STORE = 131146,
	PM_MRK_FXU_FIN = 131128,
	PM_PMC4_OVERFLOW = 65552,
	PM_MRK_PTEG_FROM_L3 = 184400,
	PM_LSU0_LMQ_LHR_MERGE = 53400,
	PM_BTAC_HIT = 20618,
	PM_L3_RD_BUSY = 323714,
	PM_LSU0_L1_SW_PREF = 49308,
	PM_INST_FROM_L2MISS = 278600,
	PM_LSU0_DC_PREF_STREAM_ALLOC = 53416,
	PM_L2_ST = 90242,
	PM_VSU0_DENORM = 41132,
	PM_MRK_DATA_FROM_DL2L3_SHR = 249924,
	PM_BR_PRED_CR_TA = 18602,
	PM_VSU0_FCONV = 41136,
	PM_MRK_LSU_FLUSH_ULD = 53380,
	PM_BTAC_MISS = 20616,
	PM_MRK_LD_MISS_EXPOSED_CYC_COUNT = 65599,
	PM_MRK_DATA_FROM_L2 = 118848,
	PM_LSU_DCACHE_RELOAD_VALID = 53410,
	PM_VSU_FMA = 43140,
	PM_LSU0_FLUSH_SRQ = 49340,
	PM_LSU1_L1_PREF = 53434,
	PM_IOPS_CMPL = 65556,
	PM_L2_SYS_PUMP = 222338,
	PM_L2_RCLD_BUSY_RC_FULL = 287362,
	PM_LSU_LMQ_S0_ALLOC = 53409,
	PM_FLUSH_DISP_SYNC = 8328,
	PM_MRK_DATA_FROM_DL2L3_MOD_CYC = 262186,
	PM_L2_IC_INV = 156032,
	PM_MRK_DATA_FROM_L21_MOD_CYC = 262180,
	PM_L3_PREF_LDST = 55468,
	PM_LSU_SRQ_EMPTY_CYC = 262152,
	PM_LSU_LMQ_S0_VALID = 53408,
	PM_FLUSH_PARTIAL = 8326,
	PM_VSU1_FMA_DOUBLE = 41106,
	PM_1PLUS_PPC_DISP = 262386,
	PM_DATA_FROM_L2MISS = 131326,
	PM_SUSPENDED = 0,
	PM_VSU0_FMA = 41092,
	PM_CMPLU_STALL_SCALAR = 262162,
	PM_STCX_FAIL = 49306,
	PM_VSU0_FSQRT_FDIV_DOUBLE = 41108,
	PM_DC_PREF_DST = 53424,
	PM_VSU1_SCAL_SINGLE_ISSUED = 45190,
	PM_L3_HIT = 127104,
	PM_L2_GLOB_GUESS_WRONG = 156802,
	PM_MRK_DFU_FIN = 131122,
	PM_INST_FROM_L1 = 16512,
	PM_BRU_FIN = 65640,
	PM_IC_DEMAND_REQ = 16520,
	PM_VSU1_FSQRT_FDIV_DOUBLE = 41110,
	PM_VSU1_FMA = 41094,
	PM_MRK_LD_MISS_L1 = 131126,
	PM_VSU0_2FLOP_DOUBLE = 41100,
	PM_LSU_DC_PREF_STRIDED_STREAM_CONFIRM = 55484,
	PM_INST_PTEG_FROM_L31_SHR = 188502,
	PM_MRK_LSU_REJECT_ERAT_MISS = 196708,
	PM_MRK_DATA_FROM_L2MISS = 315464,
	PM_DATA_FROM_RL2L3_SHR = 114764,
	PM_INST_FROM_PREF = 81990,
	PM_VSU1_SQ = 45214,
	PM_L2_LD_DISP = 221568,
	PM_L2_DISP_ALL = 286848,
	PM_THRD_GRP_CMPL_BOTH_CYC = 65554,
	PM_VSU_FSQRT_FDIV_DOUBLE = 43156,
	PM_BR_MPRED = 262390,
	PM_INST_PTEG_FROM_DL2L3_SHR = 254036,
	PM_VSU_1FLOP = 43136,
	PM_HV_CYC = 131082,
	PM_MRK_LSU_FIN = 262194,
	PM_MRK_DATA_FROM_RL2L3_SHR = 118860,
	PM_DTLB_MISS_16M = 311390,
	PM_LSU1_LMQ_LHR_MERGE = 53402,
	PM_IFU_FIN = 262246,
	PM_1THRD_CON_RUN_INSTR = 196706,
	PM_CMPLU_STALL_COUNT = 262155,
	PM_MEM0_PB_RD_CL = 196739,
	PM_THRD_1_RUN_CYC = 65632,
	PM_THRD_2_CONC_RUN_INSTR = 262242,
	PM_THRD_2_RUN_CYC = 131168,
	PM_THRD_3_CONC_RUN_INST = 65634,
	PM_THRD_3_RUN_CYC = 196704,
	PM_THRD_4_CONC_RUN_INST = 131170,
	PM_THRD_4_RUN_CYC = 262240,
};

enum perf_branch_sample_type {
	PERF_SAMPLE_BRANCH_USER = 1,
	PERF_SAMPLE_BRANCH_KERNEL = 2,
	PERF_SAMPLE_BRANCH_HV = 4,
	PERF_SAMPLE_BRANCH_ANY = 8,
	PERF_SAMPLE_BRANCH_ANY_CALL = 16,
	PERF_SAMPLE_BRANCH_ANY_RETURN = 32,
	PERF_SAMPLE_BRANCH_IND_CALL = 64,
	PERF_SAMPLE_BRANCH_ABORT_TX = 128,
	PERF_SAMPLE_BRANCH_IN_TX = 256,
	PERF_SAMPLE_BRANCH_NO_TX = 512,
	PERF_SAMPLE_BRANCH_COND = 1024,
	PERF_SAMPLE_BRANCH_CALL_STACK = 2048,
	PERF_SAMPLE_BRANCH_IND_JUMP = 4096,
	PERF_SAMPLE_BRANCH_CALL = 8192,
	PERF_SAMPLE_BRANCH_NO_FLAGS = 16384,
	PERF_SAMPLE_BRANCH_NO_CYCLES = 32768,
	PERF_SAMPLE_BRANCH_TYPE_SAVE = 65536,
	PERF_SAMPLE_BRANCH_HW_INDEX = 131072,
	PERF_SAMPLE_BRANCH_MAX = 262144,
};

enum {
	PM_CYC___2 = 30,
	PM_GCT_NOSLOT_CYC___2 = 65784,
	PM_CMPLU_STALL___2 = 262154,
	PM_INST_CMPL___2 = 2,
	PM_BRU_FIN___2 = 65640,
	PM_BR_MPRED_CMPL = 262390,
	PM_LD_REF_L1___2 = 65774,
	PM_LD_MISS_L1___2 = 254036,
	PM_ST_MISS_L1___2 = 196848,
	PM_L1_PREF___2 = 55480,
	PM_INST_FROM_L1___2 = 16512,
	PM_L1_ICACHE_MISS___2 = 131325,
	PM_L1_DEMAND_WRITE___2 = 16524,
	PM_IC_PREF_WRITE___2 = 16526,
	PM_DATA_FROM_L3___2 = 311362,
	PM_DATA_FROM_L3MISS___2 = 196862,
	PM_L2_ST___2 = 94336,
	PM_L2_ST_MISS___2 = 94338,
	PM_L3_PREF_ALL = 319570,
	PM_DTLB_MISS___2 = 196860,
	PM_ITLB_MISS___2 = 262396,
	PM_RUN_INST_CMPL___2 = 327930,
	PM_RUN_INST_CMPL_ALT = 262394,
	PM_RUN_CYC___2 = 393460,
	PM_RUN_CYC_ALT = 131316,
	PM_MRK_ST_CMPL___2 = 65844,
	PM_MRK_ST_CMPL_ALT = 197090,
	PM_BR_MRK_2PATH = 65848,
	PM_BR_MRK_2PATH_ALT = 262456,
	PM_L3_CO_MEPF = 98434,
	PM_L3_CO_MEPF_ALT = 254046,
	PM_MRK_DATA_FROM_L2MISS___2 = 119118,
	PM_MRK_DATA_FROM_L2MISS_ALT = 262632,
	PM_CMPLU_STALL_ALT = 122964,
	PM_BR_2PATH = 131126,
	PM_BR_2PATH_ALT = 262198,
	PM_INST_DISP___2 = 131314,
	PM_INST_DISP_ALT = 196850,
	PM_MRK_FILT_MATCH = 131388,
	PM_MRK_FILT_MATCH_ALT = 196910,
	PM_LD_MISS_L1_ALT = 262384,
	MEM_ACCESS = 17039840,
};

enum {
	PM_CYC___3 = 30,
	PM_ICT_NOSLOT_CYC = 65784,
	PM_CMPLU_STALL___3 = 122964,
	PM_INST_CMPL___3 = 2,
	PM_BR_CMPL = 315486,
	PM_BR_MPRED_CMPL___2 = 262390,
	PM_LD_REF_L1___3 = 65788,
	PM_LD_MISS_L1_FIN = 180302,
	PM_LD_MISS_L1___3 = 254036,
	PM_LD_MISS_L1_ALT___2 = 262384,
	PM_ST_MISS_L1___3 = 196848,
	PM_L1_PREF___3 = 131156,
	PM_INST_FROM_L1___3 = 16512,
	PM_L1_ICACHE_MISS___3 = 131325,
	PM_L1_DEMAND_WRITE___3 = 16524,
	PM_IC_PREF_WRITE___3 = 18572,
	PM_DATA_FROM_L3___3 = 311362,
	PM_DATA_FROM_L3MISS___3 = 196862,
	PM_L2_ST___3 = 92288,
	PM_L2_ST_MISS___3 = 157824,
	PM_L3_PREF_ALL___2 = 319570,
	PM_DTLB_MISS___3 = 196860,
	PM_ITLB_MISS___3 = 262396,
	PM_RUN_INST_CMPL___3 = 327930,
	PM_RUN_INST_CMPL_ALT___2 = 262394,
	PM_RUN_CYC___3 = 393460,
	PM_RUN_CYC_ALT___2 = 131316,
	PM_INST_DISP___3 = 131314,
	PM_INST_DISP_ALT___2 = 196850,
	PM_BR_2PATH___2 = 131126,
	PM_BR_2PATH_ALT___2 = 262198,
	PM_MRK_ST_DONE_L2 = 65844,
	PM_RADIX_PWC_L1_HIT = 127062,
	PM_FLOP_CMPL = 65780,
	PM_MRK_NTF_FIN = 131346,
	PM_RADIX_PWC_L2_HIT = 184356,
	PM_IFETCH_THROTTLE = 213086,
	PM_MRK_L2_TM_ST_ABORT_SISTER = 254300,
	PM_RADIX_PWC_L3_HIT = 258134,
	PM_RUN_CYC_SMT2_MODE = 196716,
	PM_TM_TX_PASS_RUN_INST = 319508,
	PM_DISP_HELD_SYNC_HOLD = 262204,
	PM_DTLB_MISS_16G___2 = 114776,
	PM_DERAT_MISS_2M = 114778,
	PM_DTLB_MISS_2M = 114780,
	PM_MRK_DTLB_MISS_1G = 119132,
	PM_DTLB_MISS_4K___2 = 180310,
	PM_DERAT_MISS_1G = 180314,
	PM_MRK_DERAT_MISS_2M = 184658,
	PM_MRK_DTLB_MISS_4K___2 = 184662,
	PM_MRK_DTLB_MISS_16G___2 = 184670,
	PM_DTLB_MISS_64K___2 = 245846,
	PM_MRK_DERAT_MISS_1G = 250194,
	PM_MRK_DTLB_MISS_64K___2 = 250198,
	PM_DTLB_MISS_16M___2 = 311382,
	PM_DTLB_MISS_1G = 311386,
	PM_MRK_DTLB_MISS_16M___2 = 311646,
	MEM_LOADS = 872677856,
	MEM_STORES = 1006895584,
};

enum {
	PM_CYC_ALT = 65776,
	PM_CYC_INST_CMPL = 65778,
	PM_FLOP_CMPL___2 = 65780,
	PM_L1_ITLB_MISS = 65782,
	PM_NO_INST_AVAIL = 65784,
	PM_LD_CMPL = 65788,
	PM_INST_CMPL_ALT = 65790,
	PM_ST_CMPL = 131312,
	PM_INST_DISP___4 = 131314,
	PM_RUN_CYC___4 = 131316,
	PM_L1_DTLB_RELOAD = 131318,
	PM_BR_TAKEN_CMPL = 131322,
	PM_L1_ICACHE_MISS___4 = 131324,
	PM_L1_RELOAD_FROM_MEM = 131326,
	PM_ST_MISS_L1___4 = 196848,
	PM_INST_DISP_ALT___3 = 196850,
	PM_BR_MISPREDICT = 196854,
	PM_DTLB_MISS___4 = 196860,
	PM_DATA_FROM_L3MISS___4 = 196862,
	PM_LD_MISS_L1___4 = 262384,
	PM_CYC_INST_DISP = 262386,
	PM_BR_MPRED_CMPL___3 = 262390,
	PM_RUN_INST_CMPL___4 = 262394,
	PM_ITLB_MISS___4 = 262396,
	PM_LD_NOT_CACHED = 262398,
	PM_INST_CMPL___4 = 327930,
	PM_CYC___4 = 393460,
};

enum {
	PM_CYC___5 = 393460,
};

enum {
	PM_INST_CMPL___5 = 327930,
};

enum {
	PM_BR_CMPL___2 = 315486,
};

enum {
	PM_BR_MPRED_CMPL___4 = 262390,
};

enum {
	PM_BR_FIN = 192586,
};

enum {
	PM_MPRED_BR_FIN = 254104,
};

enum {
	PM_LD_DEMAND_MISS_L1_FIN = 262384,
};

enum {
	PM_LD_REF_L1___4 = 65788,
};

enum {
	PM_LD_MISS_L1___5 = 254036,
};

enum {
	PM_ST_MISS_L1___5 = 196848,
};

enum {
	PM_LD_PREFETCH_CACHE_LINE_MISS = 65580,
};

enum {
	PM_L1_ICACHE_MISS___5 = 131324,
};

enum {
	PM_INST_FROM_L1___4 = 16512,
};

enum {
	PM_INST_FROM_L1MISS = 114752,
};

enum {
	PM_IC_PREF_REQ___2 = 16544,
};

enum {
	PM_DATA_FROM_L3___4 = 114752,
};

enum {
	PM_DATA_FROM_L3MISS___5 = 196862,
};

enum {
	PM_L2_ST___4 = 286848,
};

enum {
	PM_L2_ST_MISS___4 = 157824,
};

enum {
	PM_L3_PF_MISS_L3 = 90240,
};

enum {
	PM_DTLB_MISS___5 = 196860,
};

enum {
	PM_ITLB_MISS___5 = 262396,
};

enum {
	PM_CYC_ALT___2 = 30,
};

enum {
	PM_INST_CMPL_ALT___2 = 2,
};

enum {
	MEM_LOADS___2 = 872677856,
};

enum {
	MEM_STORES___2 = 1006895584,
};

struct fdtable {
	unsigned int max_fds;
	struct file **fd;
	long unsigned int *close_on_exec;
	long unsigned int *open_fds;
	long unsigned int *full_fds_bits;
	struct callback_head rcu;
};

struct files_struct {
	atomic_t count;
	bool resize_in_progress;
	wait_queue_head_t resize_wait;
	struct fdtable *fdt;
	struct fdtable fdtab;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	spinlock_t file_lock;
	unsigned int next_fd;
	long unsigned int close_on_exec_init[1];
	long unsigned int open_fds_init[1];
	long unsigned int full_fds_bits_init[1];
	struct file *fd_array[64];
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
};

struct robust_list {
	struct robust_list *next;
};

struct robust_list_head {
	struct robust_list list;
	long int futex_offset;
	struct robust_list *list_op_pending;
};

struct multiprocess_signals {
	sigset_t signal;
	struct hlist_node node;
};

typedef int (*proc_visitor)(struct task_struct *, void *);

enum {
	IOPRIO_CLASS_NONE = 0,
	IOPRIO_CLASS_RT = 1,
	IOPRIO_CLASS_BE = 2,
	IOPRIO_CLASS_IDLE = 3,
};

enum {
	FUTEX_STATE_OK = 0,
	FUTEX_STATE_EXITING = 1,
	FUTEX_STATE_DEAD = 2,
};

struct trace_event_raw_task_newtask {
	struct trace_entry ent;
	pid_t pid;
	char comm[16];
	long unsigned int clone_flags;
	short int oom_score_adj;
	char __data[0];
};

struct trace_event_raw_task_rename {
	struct trace_entry ent;
	pid_t pid;
	char oldcomm[16];
	char newcomm[16];
	short int oom_score_adj;
	char __data[0];
};

struct trace_event_data_offsets_task_newtask {};

struct trace_event_data_offsets_task_rename {};

typedef void (*btf_trace_task_newtask)(void *, struct task_struct *, long unsigned int);

typedef void (*btf_trace_task_rename)(void *, struct task_struct *, const char *);

struct vt_mode {
	char mode;
	char waitv;
	short int relsig;
	short int acqsig;
	short int frsig;
};

struct console_font {
	unsigned int width;
	unsigned int height;
	unsigned int charcount;
	unsigned char *data;
};

struct uni_pagedir;

struct uni_screen;

struct vc_data {
	struct tty_port port;
	short unsigned int vc_num;
	unsigned int vc_cols;
	unsigned int vc_rows;
	unsigned int vc_size_row;
	unsigned int vc_scan_lines;
	long unsigned int vc_origin;
	long unsigned int vc_scr_end;
	long unsigned int vc_visible_origin;
	unsigned int vc_top;
	unsigned int vc_bottom;
	const struct consw *vc_sw;
	short unsigned int *vc_screenbuf;
	unsigned int vc_screenbuf_size;
	unsigned char vc_mode;
	unsigned char vc_attr;
	unsigned char vc_def_color;
	unsigned char vc_color;
	unsigned char vc_s_color;
	unsigned char vc_ulcolor;
	unsigned char vc_itcolor;
	unsigned char vc_halfcolor;
	unsigned int vc_cursor_type;
	short unsigned int vc_complement_mask;
	short unsigned int vc_s_complement_mask;
	unsigned int vc_x;
	unsigned int vc_y;
	unsigned int vc_saved_x;
	unsigned int vc_saved_y;
	long unsigned int vc_pos;
	short unsigned int vc_hi_font_mask;
	struct console_font vc_font;
	short unsigned int vc_video_erase_char;
	unsigned int vc_state;
	unsigned int vc_npar;
	unsigned int vc_par[16];
	struct vt_mode vt_mode;
	struct pid *vt_pid;
	int vt_newvt;
	wait_queue_head_t paste_wait;
	unsigned int vc_charset: 1;
	unsigned int vc_s_charset: 1;
	unsigned int vc_disp_ctrl: 1;
	unsigned int vc_toggle_meta: 1;
	unsigned int vc_decscnm: 1;
	unsigned int vc_decom: 1;
	unsigned int vc_decawm: 1;
	unsigned int vc_deccm: 1;
	unsigned int vc_decim: 1;
	unsigned int vc_intensity: 2;
	unsigned int vc_italic: 1;
	unsigned int vc_underline: 1;
	unsigned int vc_blink: 1;
	unsigned int vc_reverse: 1;
	unsigned int vc_s_intensity: 2;
	unsigned int vc_s_italic: 1;
	unsigned int vc_s_underline: 1;
	unsigned int vc_s_blink: 1;
	unsigned int vc_s_reverse: 1;
	unsigned int vc_ques: 1;
	unsigned int vc_need_wrap: 1;
	unsigned int vc_can_do_color: 1;
	unsigned int vc_report_mouse: 2;
	unsigned char vc_utf: 1;
	unsigned char vc_utf_count;
	int vc_utf_char;
	unsigned int vc_tab_stop[8];
	unsigned char vc_palette[48];
	short unsigned int *vc_translate;
	unsigned char vc_G0_charset;
	unsigned char vc_G1_charset;
	unsigned char vc_saved_G0;
	unsigned char vc_saved_G1;
	unsigned int vc_resize_user;
	unsigned int vc_bell_pitch;
	unsigned int vc_bell_duration;
	short unsigned int vc_cur_blink_ms;
	struct vc_data **vc_display_fg;
	struct uni_pagedir *vc_uni_pagedir;
	struct uni_pagedir **vc_uni_pagedir_loc;
	struct uni_screen *vc_uni_screen;
};

struct vc {
	struct vc_data *d;
	struct work_struct SAK_work;
};

struct vt_spawn_console {
	spinlock_t lock;
	struct pid *pid;
	int sig;
};

struct warn_args {
	const char *fmt;
	va_list args;
};

enum hk_flags {
	HK_FLAG_TIMER = 1,
	HK_FLAG_RCU = 2,
	HK_FLAG_MISC = 4,
	HK_FLAG_SCHED = 8,
	HK_FLAG_TICK = 16,
	HK_FLAG_DOMAIN = 32,
	HK_FLAG_WQ = 64,
	HK_FLAG_MANAGED_IRQ = 128,
	HK_FLAG_KTHREAD = 256,
};

enum cpuhp_smt_control {
	CPU_SMT_ENABLED = 0,
	CPU_SMT_DISABLED = 1,
	CPU_SMT_FORCE_DISABLED = 2,
	CPU_SMT_NOT_SUPPORTED = 3,
};

struct smp_hotplug_thread {
	struct task_struct **store;
	struct list_head list;
	int (*thread_should_run)(unsigned int);
	void (*thread_fn)(unsigned int);
	void (*create)(unsigned int);
	void (*setup)(unsigned int);
	void (*cleanup)(unsigned int, bool);
	void (*park)(unsigned int);
	void (*unpark)(unsigned int);
	cpumask_var_t cpumask;
	bool selfparking;
	const char *thread_comm;
};

struct trace_event_raw_cpuhp_enter {
	struct trace_entry ent;
	unsigned int cpu;
	int target;
	int idx;
	void *fun;
	char __data[0];
};

struct trace_event_raw_cpuhp_multi_enter {
	struct trace_entry ent;
	unsigned int cpu;
	int target;
	int idx;
	void *fun;
	char __data[0];
};

struct trace_event_raw_cpuhp_exit {
	struct trace_entry ent;
	unsigned int cpu;
	int state;
	int idx;
	int ret;
	char __data[0];
};

struct trace_event_data_offsets_cpuhp_enter {};

struct trace_event_data_offsets_cpuhp_multi_enter {};

struct trace_event_data_offsets_cpuhp_exit {};

typedef void (*btf_trace_cpuhp_enter)(void *, unsigned int, int, int, int (*)(unsigned int));

typedef void (*btf_trace_cpuhp_multi_enter)(void *, unsigned int, int, int, int (*)(unsigned int, struct hlist_node *), struct hlist_node *);

typedef void (*btf_trace_cpuhp_exit)(void *, unsigned int, int, int, int);

struct cpuhp_cpu_state {
	enum cpuhp_state state;
	enum cpuhp_state target;
	enum cpuhp_state fail;
	struct task_struct *thread;
	bool should_run;
	bool rollback;
	bool single;
	bool bringup;
	bool booted_once;
	int cpu;
	struct hlist_node *node;
	struct hlist_node *last;
	enum cpuhp_state cb_state;
	int result;
	struct completion done_up;
	struct completion done_down;
};

struct cpuhp_step {
	const char *name;
	union {
		int (*single)(unsigned int);
		int (*multi)(unsigned int, struct hlist_node *);
	} startup;
	union {
		int (*single)(unsigned int);
		int (*multi)(unsigned int, struct hlist_node *);
	} teardown;
	struct hlist_head list;
	bool cant_stop;
	bool multi_instance;
};

enum cpu_mitigations {
	CPU_MITIGATIONS_OFF = 0,
	CPU_MITIGATIONS_AUTO = 1,
	CPU_MITIGATIONS_AUTO_NOSMT = 2,
};

typedef struct wait_queue_entry wait_queue_entry_t;

struct rusage {
	struct timeval ru_utime;
	struct timeval ru_stime;
	__kernel_long_t ru_maxrss;
	__kernel_long_t ru_ixrss;
	__kernel_long_t ru_idrss;
	__kernel_long_t ru_isrss;
	__kernel_long_t ru_minflt;
	__kernel_long_t ru_majflt;
	__kernel_long_t ru_nswap;
	__kernel_long_t ru_inblock;
	__kernel_long_t ru_oublock;
	__kernel_long_t ru_msgsnd;
	__kernel_long_t ru_msgrcv;
	__kernel_long_t ru_nsignals;
	__kernel_long_t ru_nvcsw;
	__kernel_long_t ru_nivcsw;
};

struct fd {
	struct file *file;
	unsigned int flags;
};

struct compat_timeval {
	compat_time_t tv_sec;
	s32 tv_usec;
};

typedef u32 compat_uint_t;

struct compat_rusage {
	struct compat_timeval ru_utime;
	struct compat_timeval ru_stime;
	compat_long_t ru_maxrss;
	compat_long_t ru_ixrss;
	compat_long_t ru_idrss;
	compat_long_t ru_isrss;
	compat_long_t ru_minflt;
	compat_long_t ru_majflt;
	compat_long_t ru_nswap;
	compat_long_t ru_inblock;
	compat_long_t ru_oublock;
	compat_long_t ru_msgsnd;
	compat_long_t ru_msgrcv;
	compat_long_t ru_nsignals;
	compat_long_t ru_nvcsw;
	compat_long_t ru_nivcsw;
};

struct waitid_info {
	pid_t pid;
	uid_t uid;
	int status;
	int cause;
};

struct wait_opts {
	enum pid_type wo_type;
	int wo_flags;
	struct pid *wo_pid;
	struct waitid_info *wo_info;
	int wo_stat;
	struct rusage *wo_rusage;
	wait_queue_entry_t child_wait;
	int notask_error;
};

struct softirq_action {
	void (*action)(struct softirq_action *);
};

struct tasklet_struct {
	struct tasklet_struct *next;
	long unsigned int state;
	atomic_t count;
	void (*func)(long unsigned int);
	long unsigned int data;
};

enum {
	TASKLET_STATE_SCHED = 0,
	TASKLET_STATE_RUN = 1,
};

struct trace_print_flags {
	long unsigned int mask;
	const char *name;
};

struct trace_event_raw_irq_handler_entry {
	struct trace_entry ent;
	int irq;
	u32 __data_loc_name;
	char __data[0];
};

struct trace_event_raw_irq_handler_exit {
	struct trace_entry ent;
	int irq;
	int ret;
	char __data[0];
};

struct trace_event_raw_softirq {
	struct trace_entry ent;
	unsigned int vec;
	char __data[0];
};

struct trace_event_data_offsets_irq_handler_entry {
	u32 name;
};

struct trace_event_data_offsets_irq_handler_exit {};

struct trace_event_data_offsets_softirq {};

typedef void (*btf_trace_irq_handler_entry)(void *, int, struct irqaction *);

typedef void (*btf_trace_irq_handler_exit)(void *, int, struct irqaction *, int);

typedef void (*btf_trace_softirq_entry)(void *, unsigned int);

typedef void (*btf_trace_softirq_exit)(void *, unsigned int);

typedef void (*btf_trace_softirq_raise)(void *, unsigned int);

struct tasklet_head {
	struct tasklet_struct *head;
	struct tasklet_struct **tail;
};

enum {
	IORES_DESC_NONE = 0,
	IORES_DESC_CRASH_KERNEL = 1,
	IORES_DESC_ACPI_TABLES = 2,
	IORES_DESC_ACPI_NV_STORAGE = 3,
	IORES_DESC_PERSISTENT_MEMORY = 4,
	IORES_DESC_PERSISTENT_MEMORY_LEGACY = 5,
	IORES_DESC_DEVICE_PRIVATE_MEMORY = 6,
	IORES_DESC_DEVICE_PUBLIC_MEMORY = 7,
	IORES_DESC_RESERVED = 8,
	IORES_DESC_SOFT_RESERVED = 9,
};

enum {
	REGION_INTERSECTS = 0,
	REGION_DISJOINT = 1,
	REGION_MIXED = 2,
};

struct resource_entry {
	struct list_head node;
	struct resource *res;
	resource_size_t offset;
	struct resource __res;
};

struct resource_constraint {
	resource_size_t min;
	resource_size_t max;
	resource_size_t align;
	resource_size_t (*alignf)(void *, const struct resource *, resource_size_t, resource_size_t);
	void *alignf_data;
};

enum {
	MAX_IORES_LEVEL = 5,
};

struct region_devres {
	struct resource *parent;
	resource_size_t start;
	resource_size_t n;
};

enum sysctl_writes_mode {
	SYSCTL_WRITES_LEGACY = 4294967295,
	SYSCTL_WRITES_WARN = 0,
	SYSCTL_WRITES_STRICT = 1,
};

struct do_proc_dointvec_minmax_conv_param {
	int *min;
	int *max;
};

struct do_proc_douintvec_minmax_conv_param {
	unsigned int *min;
	unsigned int *max;
};

struct __sysctl_args {
	int *name;
	int nlen;
	void *oldval;
	size_t *oldlenp;
	void *newval;
	size_t newlen;
	long unsigned int __unused[4];
};

enum {
	CTL_KERN = 1,
	CTL_VM = 2,
	CTL_NET = 3,
	CTL_PROC = 4,
	CTL_FS = 5,
	CTL_DEBUG = 6,
	CTL_DEV = 7,
	CTL_BUS = 8,
	CTL_ABI = 9,
	CTL_CPU = 10,
	CTL_ARLAN = 254,
	CTL_S390DBF = 5677,
	CTL_SUNRPC = 7249,
	CTL_PM = 9899,
	CTL_FRV = 9898,
};

enum {
	KERN_OSTYPE = 1,
	KERN_OSRELEASE = 2,
	KERN_OSREV = 3,
	KERN_VERSION = 4,
	KERN_SECUREMASK = 5,
	KERN_PROF = 6,
	KERN_NODENAME = 7,
	KERN_DOMAINNAME = 8,
	KERN_PANIC = 15,
	KERN_REALROOTDEV = 16,
	KERN_SPARC_REBOOT = 21,
	KERN_CTLALTDEL = 22,
	KERN_PRINTK = 23,
	KERN_NAMETRANS = 24,
	KERN_PPC_HTABRECLAIM = 25,
	KERN_PPC_ZEROPAGED = 26,
	KERN_PPC_POWERSAVE_NAP = 27,
	KERN_MODPROBE = 28,
	KERN_SG_BIG_BUFF = 29,
	KERN_ACCT = 30,
	KERN_PPC_L2CR = 31,
	KERN_RTSIGNR = 32,
	KERN_RTSIGMAX = 33,
	KERN_SHMMAX = 34,
	KERN_MSGMAX = 35,
	KERN_MSGMNB = 36,
	KERN_MSGPOOL = 37,
	KERN_SYSRQ = 38,
	KERN_MAX_THREADS = 39,
	KERN_RANDOM = 40,
	KERN_SHMALL = 41,
	KERN_MSGMNI = 42,
	KERN_SEM = 43,
	KERN_SPARC_STOP_A = 44,
	KERN_SHMMNI = 45,
	KERN_OVERFLOWUID = 46,
	KERN_OVERFLOWGID = 47,
	KERN_SHMPATH = 48,
	KERN_HOTPLUG = 49,
	KERN_IEEE_EMULATION_WARNINGS = 50,
	KERN_S390_USER_DEBUG_LOGGING = 51,
	KERN_CORE_USES_PID = 52,
	KERN_TAINTED = 53,
	KERN_CADPID = 54,
	KERN_PIDMAX = 55,
	KERN_CORE_PATTERN = 56,
	KERN_PANIC_ON_OOPS = 57,
	KERN_HPPA_PWRSW = 58,
	KERN_HPPA_UNALIGNED = 59,
	KERN_PRINTK_RATELIMIT = 60,
	KERN_PRINTK_RATELIMIT_BURST = 61,
	KERN_PTY = 62,
	KERN_NGROUPS_MAX = 63,
	KERN_SPARC_SCONS_PWROFF = 64,
	KERN_HZ_TIMER = 65,
	KERN_UNKNOWN_NMI_PANIC = 66,
	KERN_BOOTLOADER_TYPE = 67,
	KERN_RANDOMIZE = 68,
	KERN_SETUID_DUMPABLE = 69,
	KERN_SPIN_RETRY = 70,
	KERN_ACPI_VIDEO_FLAGS = 71,
	KERN_IA64_UNALIGNED = 72,
	KERN_COMPAT_LOG = 73,
	KERN_MAX_LOCK_DEPTH = 74,
	KERN_NMI_WATCHDOG = 75,
	KERN_PANIC_ON_NMI = 76,
	KERN_PANIC_ON_WARN = 77,
	KERN_PANIC_PRINT = 78,
};

struct xfs_sysctl_val {
	int min;
	int val;
	int max;
};

typedef struct xfs_sysctl_val xfs_sysctl_val_t;

struct xfs_param {
	xfs_sysctl_val_t sgid_inherit;
	xfs_sysctl_val_t symlink_mode;
	xfs_sysctl_val_t panic_mask;
	xfs_sysctl_val_t error_level;
	xfs_sysctl_val_t syncd_timer;
	xfs_sysctl_val_t stats_clear;
	xfs_sysctl_val_t inherit_sync;
	xfs_sysctl_val_t inherit_nodump;
	xfs_sysctl_val_t inherit_noatim;
	xfs_sysctl_val_t xfs_buf_timer;
	xfs_sysctl_val_t xfs_buf_age;
	xfs_sysctl_val_t inherit_nosym;
	xfs_sysctl_val_t rotorstep;
	xfs_sysctl_val_t inherit_nodfrg;
	xfs_sysctl_val_t fstrm_timer;
	xfs_sysctl_val_t blockgc_timer;
};

typedef struct xfs_param xfs_param_t;

struct xfs_globals {
	int log_recovery_delay;
	int mount_delay;
	bool bug_on_assert;
	bool always_cow;
};

enum ethtool_link_mode_bit_indices {
	ETHTOOL_LINK_MODE_10baseT_Half_BIT = 0,
	ETHTOOL_LINK_MODE_10baseT_Full_BIT = 1,
	ETHTOOL_LINK_MODE_100baseT_Half_BIT = 2,
	ETHTOOL_LINK_MODE_100baseT_Full_BIT = 3,
	ETHTOOL_LINK_MODE_1000baseT_Half_BIT = 4,
	ETHTOOL_LINK_MODE_1000baseT_Full_BIT = 5,
	ETHTOOL_LINK_MODE_Autoneg_BIT = 6,
	ETHTOOL_LINK_MODE_TP_BIT = 7,
	ETHTOOL_LINK_MODE_AUI_BIT = 8,
	ETHTOOL_LINK_MODE_MII_BIT = 9,
	ETHTOOL_LINK_MODE_FIBRE_BIT = 10,
	ETHTOOL_LINK_MODE_BNC_BIT = 11,
	ETHTOOL_LINK_MODE_10000baseT_Full_BIT = 12,
	ETHTOOL_LINK_MODE_Pause_BIT = 13,
	ETHTOOL_LINK_MODE_Asym_Pause_BIT = 14,
	ETHTOOL_LINK_MODE_2500baseX_Full_BIT = 15,
	ETHTOOL_LINK_MODE_Backplane_BIT = 16,
	ETHTOOL_LINK_MODE_1000baseKX_Full_BIT = 17,
	ETHTOOL_LINK_MODE_10000baseKX4_Full_BIT = 18,
	ETHTOOL_LINK_MODE_10000baseKR_Full_BIT = 19,
	ETHTOOL_LINK_MODE_10000baseR_FEC_BIT = 20,
	ETHTOOL_LINK_MODE_20000baseMLD2_Full_BIT = 21,
	ETHTOOL_LINK_MODE_20000baseKR2_Full_BIT = 22,
	ETHTOOL_LINK_MODE_40000baseKR4_Full_BIT = 23,
	ETHTOOL_LINK_MODE_40000baseCR4_Full_BIT = 24,
	ETHTOOL_LINK_MODE_40000baseSR4_Full_BIT = 25,
	ETHTOOL_LINK_MODE_40000baseLR4_Full_BIT = 26,
	ETHTOOL_LINK_MODE_56000baseKR4_Full_BIT = 27,
	ETHTOOL_LINK_MODE_56000baseCR4_Full_BIT = 28,
	ETHTOOL_LINK_MODE_56000baseSR4_Full_BIT = 29,
	ETHTOOL_LINK_MODE_56000baseLR4_Full_BIT = 30,
	ETHTOOL_LINK_MODE_25000baseCR_Full_BIT = 31,
	ETHTOOL_LINK_MODE_25000baseKR_Full_BIT = 32,
	ETHTOOL_LINK_MODE_25000baseSR_Full_BIT = 33,
	ETHTOOL_LINK_MODE_50000baseCR2_Full_BIT = 34,
	ETHTOOL_LINK_MODE_50000baseKR2_Full_BIT = 35,
	ETHTOOL_LINK_MODE_100000baseKR4_Full_BIT = 36,
	ETHTOOL_LINK_MODE_100000baseSR4_Full_BIT = 37,
	ETHTOOL_LINK_MODE_100000baseCR4_Full_BIT = 38,
	ETHTOOL_LINK_MODE_100000baseLR4_ER4_Full_BIT = 39,
	ETHTOOL_LINK_MODE_50000baseSR2_Full_BIT = 40,
	ETHTOOL_LINK_MODE_1000baseX_Full_BIT = 41,
	ETHTOOL_LINK_MODE_10000baseCR_Full_BIT = 42,
	ETHTOOL_LINK_MODE_10000baseSR_Full_BIT = 43,
	ETHTOOL_LINK_MODE_10000baseLR_Full_BIT = 44,
	ETHTOOL_LINK_MODE_10000baseLRM_Full_BIT = 45,
	ETHTOOL_LINK_MODE_10000baseER_Full_BIT = 46,
	ETHTOOL_LINK_MODE_2500baseT_Full_BIT = 47,
	ETHTOOL_LINK_MODE_5000baseT_Full_BIT = 48,
	ETHTOOL_LINK_MODE_FEC_NONE_BIT = 49,
	ETHTOOL_LINK_MODE_FEC_RS_BIT = 50,
	ETHTOOL_LINK_MODE_FEC_BASER_BIT = 51,
	ETHTOOL_LINK_MODE_50000baseKR_Full_BIT = 52,
	ETHTOOL_LINK_MODE_50000baseSR_Full_BIT = 53,
	ETHTOOL_LINK_MODE_50000baseCR_Full_BIT = 54,
	ETHTOOL_LINK_MODE_50000baseLR_ER_FR_Full_BIT = 55,
	ETHTOOL_LINK_MODE_50000baseDR_Full_BIT = 56,
	ETHTOOL_LINK_MODE_100000baseKR2_Full_BIT = 57,
	ETHTOOL_LINK_MODE_100000baseSR2_Full_BIT = 58,
	ETHTOOL_LINK_MODE_100000baseCR2_Full_BIT = 59,
	ETHTOOL_LINK_MODE_100000baseLR2_ER2_FR2_Full_BIT = 60,
	ETHTOOL_LINK_MODE_100000baseDR2_Full_BIT = 61,
	ETHTOOL_LINK_MODE_200000baseKR4_Full_BIT = 62,
	ETHTOOL_LINK_MODE_200000baseSR4_Full_BIT = 63,
	ETHTOOL_LINK_MODE_200000baseLR4_ER4_FR4_Full_BIT = 64,
	ETHTOOL_LINK_MODE_200000baseDR4_Full_BIT = 65,
	ETHTOOL_LINK_MODE_200000baseCR4_Full_BIT = 66,
	ETHTOOL_LINK_MODE_100baseT1_Full_BIT = 67,
	ETHTOOL_LINK_MODE_1000baseT1_Full_BIT = 68,
	ETHTOOL_LINK_MODE_400000baseKR8_Full_BIT = 69,
	ETHTOOL_LINK_MODE_400000baseSR8_Full_BIT = 70,
	ETHTOOL_LINK_MODE_400000baseLR8_ER8_FR8_Full_BIT = 71,
	ETHTOOL_LINK_MODE_400000baseDR8_Full_BIT = 72,
	ETHTOOL_LINK_MODE_400000baseCR8_Full_BIT = 73,
	ETHTOOL_LINK_MODE_FEC_LLRS_BIT = 74,
	ETHTOOL_LINK_MODE_100000baseKR_Full_BIT = 75,
	ETHTOOL_LINK_MODE_100000baseSR_Full_BIT = 76,
	ETHTOOL_LINK_MODE_100000baseLR_ER_FR_Full_BIT = 77,
	ETHTOOL_LINK_MODE_100000baseCR_Full_BIT = 78,
	ETHTOOL_LINK_MODE_100000baseDR_Full_BIT = 79,
	ETHTOOL_LINK_MODE_200000baseKR2_Full_BIT = 80,
	ETHTOOL_LINK_MODE_200000baseSR2_Full_BIT = 81,
	ETHTOOL_LINK_MODE_200000baseLR2_ER2_FR2_Full_BIT = 82,
	ETHTOOL_LINK_MODE_200000baseDR2_Full_BIT = 83,
	ETHTOOL_LINK_MODE_200000baseCR2_Full_BIT = 84,
	ETHTOOL_LINK_MODE_400000baseKR4_Full_BIT = 85,
	ETHTOOL_LINK_MODE_400000baseSR4_Full_BIT = 86,
	ETHTOOL_LINK_MODE_400000baseLR4_ER4_FR4_Full_BIT = 87,
	ETHTOOL_LINK_MODE_400000baseDR4_Full_BIT = 88,
	ETHTOOL_LINK_MODE_400000baseCR4_Full_BIT = 89,
	ETHTOOL_LINK_MODE_100baseFX_Half_BIT = 90,
	ETHTOOL_LINK_MODE_100baseFX_Full_BIT = 91,
	__ETHTOOL_LINK_MODE_MASK_NBITS = 92,
	__ETHTOOL_LINK_MODE_LAST_RH80 = 51,
};

enum {
	NAPI_STATE_SCHED = 0,
	NAPI_STATE_MISSED = 1,
	NAPI_STATE_DISABLE = 2,
	NAPI_STATE_NPSVC = 3,
	NAPI_STATE_LISTED = 4,
	NAPI_STATE_NO_BUSY_POLL = 5,
	NAPI_STATE_IN_BUSY_POLL = 6,
	NAPI_STATE_PREFER_BUSY_POLL = 7,
	NAPI_STATE_THREADED = 8,
	NAPI_STATE_SCHED_THREADED = 9,
};

enum {
	NETIF_MSG_DRV_BIT = 0,
	NETIF_MSG_PROBE_BIT = 1,
	NETIF_MSG_LINK_BIT = 2,
	NETIF_MSG_TIMER_BIT = 3,
	NETIF_MSG_IFDOWN_BIT = 4,
	NETIF_MSG_IFUP_BIT = 5,
	NETIF_MSG_RX_ERR_BIT = 6,
	NETIF_MSG_TX_ERR_BIT = 7,
	NETIF_MSG_TX_QUEUED_BIT = 8,
	NETIF_MSG_INTR_BIT = 9,
	NETIF_MSG_TX_DONE_BIT = 10,
	NETIF_MSG_RX_STATUS_BIT = 11,
	NETIF_MSG_PKTDATA_BIT = 12,
	NETIF_MSG_HW_BIT = 13,
	NETIF_MSG_WOL_BIT = 14,
	NETIF_MSG_CLASS_COUNT = 15,
};

struct compat_sysctl_args {
	compat_uptr_t name;
	int nlen;
	compat_uptr_t oldval;
	compat_uptr_t oldlenp;
	compat_uptr_t newval;
	compat_size_t newlen;
	compat_ulong_t __unused[4];
};

struct __user_cap_header_struct {
	__u32 version;
	int pid;
};

typedef struct __user_cap_header_struct *cap_user_header_t;

struct __user_cap_data_struct {
	__u32 effective;
	__u32 permitted;
	__u32 inheritable;
};

typedef struct __user_cap_data_struct *cap_user_data_t;

struct sigqueue {
	struct list_head list;
	int flags;
	kernel_siginfo_t info;
	struct user_struct *user;
};

struct ptrace_peeksiginfo_args {
	__u64 off;
	__u32 flags;
	__s32 nr;
};

struct ptrace_rseq_configuration {
	__u64 rseq_abi_pointer;
	__u32 rseq_abi_size;
	__u32 signature;
	__u32 flags;
	__u32 pad;
};

struct compat_iovec {
	compat_uptr_t iov_base;
	compat_size_t iov_len;
};

typedef int __kernel_mqd_t;

typedef __kernel_mqd_t mqd_t;

typedef long unsigned int old_sigset_t;

enum audit_context_status {
	AUDIT_CTX_UNUSED = 0,
	AUDIT_CTX_SYSCALL = 1,
};

enum audit_state {
	AUDIT_STATE_DISABLED = 0,
	AUDIT_STATE_BUILD = 1,
	AUDIT_STATE_RECORD = 2,
};

struct audit_cap_data {
	kernel_cap_t permitted;
	kernel_cap_t inheritable;
	union {
		unsigned int fE;
		kernel_cap_t effective;
	};
	kernel_cap_t ambient;
	kuid_t rootid;
};

struct audit_names {
	struct list_head list;
	struct filename *name;
	int name_len;
	bool hidden;
	long unsigned int ino;
	dev_t dev;
	umode_t mode;
	kuid_t uid;
	kgid_t gid;
	dev_t rdev;
	u32 osid;
	struct audit_cap_data fcap;
	unsigned int fcap_ver;
	unsigned char type;
	bool should_free;
};

struct mq_attr {
	__kernel_long_t mq_flags;
	__kernel_long_t mq_maxmsg;
	__kernel_long_t mq_msgsize;
	__kernel_long_t mq_curmsgs;
	__kernel_long_t __reserved[4];
};

struct open_how {
	__u64 flags;
	__u64 mode;
	__u64 resolve;
};

struct audit_ntp_val {
	long long int oldval;
	long long int newval;
};

struct audit_ntp_data {
	struct audit_ntp_val vals[6];
};

struct audit_proctitle {
	int len;
	char *value;
};

struct audit_aux_data;

struct audit_tree_refs;

struct audit_context {
	int dummy;
	union {
		enum audit_context_status context;
		struct {
			int in_syscall;
		} rh_kabi_hidden_122;
		union {		};
	};
	enum audit_state state;
	enum audit_state current_state;
	unsigned int serial;
	int major;
	struct timespec64 ctime;
	long unsigned int argv[4];
	long int return_code;
	u64 prio;
	int return_valid;
	struct audit_names preallocated_names[5];
	int name_count;
	struct list_head names_list;
	char *filterkey;
	struct path pwd;
	struct audit_aux_data *aux;
	struct audit_aux_data *aux_pids;
	struct __kernel_sockaddr_storage *sockaddr;
	size_t sockaddr_len;
	pid_t pid;
	pid_t ppid;
	kuid_t uid;
	kuid_t euid;
	kuid_t suid;
	kuid_t fsuid;
	kgid_t gid;
	kgid_t egid;
	kgid_t sgid;
	kgid_t fsgid;
	long unsigned int personality;
	int arch;
	pid_t target_pid;
	kuid_t target_auid;
	kuid_t target_uid;
	unsigned int target_sessionid;
	u32 target_sid;
	char target_comm[16];
	struct audit_tree_refs *trees;
	struct audit_tree_refs *first_trees;
	struct list_head killed_trees;
	int tree_count;
	int type;
	union {
		struct {
			int nargs;
			long int args[6];
		} socketcall;
		struct {
			kuid_t uid;
			kgid_t gid;
			umode_t mode;
			u32 osid;
			int has_perm;
			uid_t perm_uid;
			gid_t perm_gid;
			umode_t perm_mode;
			long unsigned int qbytes;
		} ipc;
		struct {
			mqd_t mqdes;
			struct mq_attr mqstat;
		} mq_getsetattr;
		struct {
			mqd_t mqdes;
			int sigev_signo;
		} mq_notify;
		struct {
			mqd_t mqdes;
			size_t msg_len;
			unsigned int msg_prio;
			struct timespec64 abs_timeout;
		} mq_sendrecv;
		struct {
			int oflag;
			umode_t mode;
			struct mq_attr attr;
		} mq_open;
		struct {
			pid_t pid;
			struct audit_cap_data cap;
		} capset;
		struct {
			int fd;
			int flags;
		} mmap;
		struct open_how openat2;
		struct {
			int argc;
		} execve;
		struct {
			char *name;
		} module;
		struct {
			struct audit_ntp_data ntp_data;
			struct timespec64 tk_injoffset;
		} time;
	};
	int fds[2];
	struct audit_proctitle proctitle;
};

enum siginfo_layout {
	SIL_KILL = 0,
	SIL_TIMER = 1,
	SIL_POLL = 2,
	SIL_FAULT = 3,
	SIL_FAULT_MCEERR = 4,
	SIL_FAULT_BNDERR = 5,
	SIL_FAULT_PKUERR = 6,
	SIL_CHLD = 7,
	SIL_RT = 8,
	SIL_SYS = 9,
};

typedef u32 compat_old_sigset_t;

struct compat_sigaction {
	compat_uptr_t sa_handler;
	compat_ulong_t sa_flags;
	compat_uptr_t sa_restorer;
	compat_sigset_t sa_mask;
};

struct compat_old_sigaction {
	compat_uptr_t sa_handler;
	compat_old_sigset_t sa_mask;
	compat_ulong_t sa_flags;
	compat_uptr_t sa_restorer;
};

enum {
	TRACE_SIGNAL_DELIVERED = 0,
	TRACE_SIGNAL_IGNORED = 1,
	TRACE_SIGNAL_ALREADY_PENDING = 2,
	TRACE_SIGNAL_OVERFLOW_FAIL = 3,
	TRACE_SIGNAL_LOSE_INFO = 4,
};

struct trace_event_raw_signal_generate {
	struct trace_entry ent;
	int sig;
	int errno;
	int code;
	char comm[16];
	pid_t pid;
	int group;
	int result;
	char __data[0];
};

struct trace_event_raw_signal_deliver {
	struct trace_entry ent;
	int sig;
	int errno;
	int code;
	long unsigned int sa_handler;
	long unsigned int sa_flags;
	char __data[0];
};

struct trace_event_data_offsets_signal_generate {};

struct trace_event_data_offsets_signal_deliver {};

typedef void (*btf_trace_signal_generate)(void *, int, struct kernel_siginfo *, struct task_struct *, int, int);

typedef void (*btf_trace_signal_deliver)(void *, int, struct kernel_siginfo *, struct k_sigaction *);

typedef int (*get_char_func)();

typedef __kernel_clock_t clock_t;

struct sysinfo {
	__kernel_long_t uptime;
	__kernel_ulong_t loads[3];
	__kernel_ulong_t totalram;
	__kernel_ulong_t freeram;
	__kernel_ulong_t sharedram;
	__kernel_ulong_t bufferram;
	__kernel_ulong_t totalswap;
	__kernel_ulong_t freeswap;
	__u16 procs;
	__u16 pad;
	__kernel_ulong_t totalhigh;
	__kernel_ulong_t freehigh;
	__u32 mem_unit;
	char _f[0];
};

struct rlimit64 {
	__u64 rlim_cur;
	__u64 rlim_max;
};

struct timens_offsets {
	struct timespec64 monotonic;
	struct timespec64 boottime;
};

struct time_namespace {
	struct kref kref;
	struct user_namespace *user_ns;
	struct ucounts *ucounts;
	struct ns_common ns;
	struct timens_offsets offsets;
	struct page *vvar_page;
	bool frozen_offsets;
};

struct oldold_utsname {
	char sysname[9];
	char nodename[9];
	char release[9];
	char version[9];
	char machine[9];
};

struct old_utsname {
	char sysname[65];
	char nodename[65];
	char release[65];
	char version[65];
	char machine[65];
};

enum uts_proc {
	UTS_PROC_OSTYPE = 0,
	UTS_PROC_OSRELEASE = 1,
	UTS_PROC_VERSION = 2,
	UTS_PROC_HOSTNAME = 3,
	UTS_PROC_DOMAINNAME = 4,
};

struct prctl_mm_map {
	__u64 start_code;
	__u64 end_code;
	__u64 start_data;
	__u64 end_data;
	__u64 start_brk;
	__u64 brk;
	__u64 start_stack;
	__u64 arg_start;
	__u64 arg_end;
	__u64 env_start;
	__u64 env_end;
	__u64 *auxv;
	__u32 auxv_size;
	__u32 exe_fd;
};

struct tms {
	__kernel_clock_t tms_utime;
	__kernel_clock_t tms_stime;
	__kernel_clock_t tms_cutime;
	__kernel_clock_t tms_cstime;
};

struct getcpu_cache {
	long unsigned int blob[16];
};

struct compat_tms {
	compat_clock_t tms_utime;
	compat_clock_t tms_stime;
	compat_clock_t tms_cutime;
	compat_clock_t tms_cstime;
};

struct compat_rlimit {
	compat_ulong_t rlim_cur;
	compat_ulong_t rlim_max;
};

struct compat_sysinfo {
	s32 uptime;
	u32 loads[3];
	u32 totalram;
	u32 freeram;
	u32 sharedram;
	u32 bufferram;
	u32 totalswap;
	u32 freeswap;
	u16 procs;
	u16 pad;
	u32 totalhigh;
	u32 freehigh;
	u32 mem_unit;
	char _f[8];
};

struct wq_flusher;

struct worker;

struct workqueue_attrs;

struct pool_workqueue;

struct wq_device;

struct workqueue_struct {
	struct list_head pwqs;
	struct list_head list;
	struct mutex mutex;
	int work_color;
	int flush_color;
	atomic_t nr_pwqs_to_flush;
	struct wq_flusher *first_flusher;
	struct list_head flusher_queue;
	struct list_head flusher_overflow;
	struct list_head maydays;
	struct worker *rescuer;
	int nr_drainers;
	int saved_max_active;
	struct workqueue_attrs *unbound_attrs;
	struct pool_workqueue *dfl_pwq;
	struct wq_device *wq_dev;
	char name[24];
	struct callback_head rcu;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	unsigned int flags;
	struct pool_workqueue *cpu_pwqs;
	struct pool_workqueue *numa_pwq_tbl[0];
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
};

struct workqueue_attrs {
	int nice;
	cpumask_var_t cpumask;
	bool no_numa;
};

struct execute_work {
	struct work_struct work;
};

struct __una_u32 {
	u32 x;
};

struct worker_pool;

struct worker {
	union {
		struct list_head entry;
		struct hlist_node hentry;
	};
	struct work_struct *current_work;
	work_func_t current_func;
	struct pool_workqueue *current_pwq;
	struct list_head scheduled;
	struct task_struct *task;
	struct worker_pool *pool;
	struct list_head node;
	long unsigned int last_active;
	unsigned int flags;
	int id;
	int sleeping;
	char desc[24];
	struct workqueue_struct *rescue_wq;
	work_func_t last_func;
};

struct pool_workqueue {
	struct worker_pool *pool;
	struct workqueue_struct *wq;
	int work_color;
	int flush_color;
	int refcnt;
	int nr_in_flight[15];
	int nr_active;
	int max_active;
	struct list_head inactive_works;
	struct list_head pwqs_node;
	struct list_head mayday_node;
	struct work_struct unbound_release_work;
	struct callback_head rcu;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
};

struct worker_pool {
	raw_spinlock_t lock;
	int cpu;
	int node;
	int id;
	unsigned int flags;
	long unsigned int watchdog_ts;
	struct list_head worklist;
	int nr_workers;
	int nr_idle;
	struct list_head idle_list;
	struct timer_list idle_timer;
	struct work_struct idle_cull_work;
	struct timer_list mayday_timer;
	struct hlist_head busy_hash[64];
	struct worker *manager;
	struct list_head workers;
	struct list_head dying_workers;
	struct completion *detach_completion;
	struct ida worker_ida;
	struct workqueue_attrs *attrs;
	struct hlist_node hash_node;
	int refcnt;
	int: 32;
	atomic_t nr_running;
	struct callback_head rcu;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
};

enum {
	POOL_MANAGER_ACTIVE = 1,
	POOL_DISASSOCIATED = 4,
	WORKER_DIE = 2,
	WORKER_IDLE = 4,
	WORKER_PREP = 8,
	WORKER_CPU_INTENSIVE = 64,
	WORKER_UNBOUND = 128,
	WORKER_REBOUND = 256,
	WORKER_NOT_RUNNING = 456,
	NR_STD_WORKER_POOLS = 2,
	UNBOUND_POOL_HASH_ORDER = 6,
	BUSY_WORKER_HASH_ORDER = 6,
	MAX_IDLE_WORKERS_RATIO = 4,
	IDLE_WORKER_TIMEOUT = 30000,
	MAYDAY_INITIAL_TIMEOUT = 2,
	MAYDAY_INTERVAL = 10,
	CREATE_COOLDOWN = 100,
	RESCUER_NICE_LEVEL = 4294967276,
	HIGHPRI_NICE_LEVEL = 4294967276,
	WQ_NAME_LEN = 24,
};

struct wq_flusher {
	struct list_head list;
	int flush_color;
	struct completion done;
};

struct wq_device {
	struct workqueue_struct *wq;
	struct device dev;
};

struct trace_event_raw_workqueue_work {
	struct trace_entry ent;
	void *work;
	char __data[0];
};

struct trace_event_raw_workqueue_queue_work {
	struct trace_entry ent;
	void *work;
	void *function;
	void *workqueue;
	unsigned int req_cpu;
	unsigned int cpu;
	char __data[0];
};

struct trace_event_raw_workqueue_execute_start {
	struct trace_entry ent;
	void *work;
	void *function;
	char __data[0];
};

struct trace_event_data_offsets_workqueue_work {};

struct trace_event_data_offsets_workqueue_queue_work {};

struct trace_event_data_offsets_workqueue_execute_start {};

typedef void (*btf_trace_workqueue_queue_work)(void *, unsigned int, struct pool_workqueue *, struct work_struct *);

typedef void (*btf_trace_workqueue_activate_work)(void *, struct work_struct *);

typedef void (*btf_trace_workqueue_execute_start)(void *, struct work_struct *);

typedef void (*btf_trace_workqueue_execute_end)(void *, struct work_struct *);

struct wq_barrier {
	struct work_struct work;
	struct completion done;
	struct task_struct *task;
};

struct cwt_wait {
	wait_queue_entry_t wait;
	struct work_struct *work;
};

struct apply_wqattrs_ctx {
	struct workqueue_struct *wq;
	struct workqueue_attrs *attrs;
	struct list_head list;
	struct pool_workqueue *dfl_pwq;
	struct pool_workqueue *pwq_tbl[0];
};

struct work_for_cpu {
	struct work_struct work;
	long int (*fn)(void *);
	void *arg;
	long int ret;
};

typedef void (*task_work_func_t)(struct callback_head *);

enum task_work_notify_mode {
	TWA_NONE = 0,
	TWA_RESUME = 1,
	TWA_SIGNAL = 2,
};

enum {
	KERNEL_PARAM_OPS_FL_NOARG = 1,
};

enum {
	KERNEL_PARAM_FL_UNSAFE = 1,
	KERNEL_PARAM_FL_HWPARAM = 2,
};

struct param_attribute {
	struct module_attribute mattr;
	const struct kernel_param *param;
};

struct module_param_attrs {
	unsigned int num;
	struct attribute_group grp;
	struct param_attribute attrs[0];
};

struct kmalloced_param {
	struct list_head list;
	char val[0];
};

struct sched_param {
	int sched_priority;
};

enum {
	__PERCPU_REF_ATOMIC = 1,
	__PERCPU_REF_DEAD = 2,
	__PERCPU_REF_ATOMIC_DEAD = 3,
	__PERCPU_REF_FLAG_BITS = 2,
};

struct kthread_work;

typedef void (*kthread_work_func_t)(struct kthread_work *);

struct kthread_worker;

struct kthread_work {
	struct list_head node;
	kthread_work_func_t func;
	struct kthread_worker *worker;
	int canceling;
};

enum {
	KTW_FREEZABLE = 1,
};

struct kthread_worker {
	unsigned int flags;
	raw_spinlock_t lock;
	struct list_head work_list;
	struct list_head delayed_work_list;
	struct task_struct *task;
	struct kthread_work *current_work;
};

struct kthread_delayed_work {
	struct kthread_work work;
	struct timer_list timer;
};

enum {
	CSS_NO_REF = 1,
	CSS_ONLINE = 2,
	CSS_RELEASED = 4,
	CSS_VISIBLE = 8,
	CSS_DYING = 16,
};

struct kthread_create_info {
	int (*threadfn)(void *);
	void *data;
	int node;
	struct task_struct *result;
	struct completion *done;
	struct list_head list;
};

struct kthread {
	long unsigned int flags;
	unsigned int cpu;
	int (*threadfn)(void *);
	void *data;
	mm_segment_t oldfs;
	struct completion parked;
	struct completion exited;
	struct cgroup_subsys_state *blkcg_css;
};

enum KTHREAD_BITS {
	KTHREAD_IS_PER_CPU = 0,
	KTHREAD_SHOULD_STOP = 1,
	KTHREAD_SHOULD_PARK = 2,
};

struct kthread_flush_work {
	struct kthread_work work;
	struct completion done;
};

struct ipc_ids {
	int in_use;
	short unsigned int seq;
	struct rw_semaphore rwsem;
	struct idr ipcs_idr;
	int max_idx;
	int last_idx;
	int next_id;
	struct rhashtable key_ht;
};

struct ipc_namespace {
	refcount_t count;
	struct ipc_ids ids[3];
	int sem_ctls[4];
	int used_sems;
	unsigned int msg_ctlmax;
	unsigned int msg_ctlmnb;
	unsigned int msg_ctlmni;
	atomic_t msg_bytes;
	atomic_t msg_hdrs;
	size_t shm_ctlmax;
	size_t shm_ctlall;
	long unsigned int shm_tot;
	int shm_ctlmni;
	int shm_rmid_forced;
	struct notifier_block ipcns_nb;
	struct vfsmount *mq_mnt;
	unsigned int mq_queues_count;
	unsigned int mq_queues_max;
	unsigned int mq_msg_max;
	unsigned int mq_msgsize_max;
	unsigned int mq_msg_default;
	unsigned int mq_msgsize_default;
	struct user_namespace *user_ns;
	struct ucounts *ucounts;
	struct ns_common ns;
};

struct srcu_notifier_head {
	struct mutex mutex;
	struct srcu_struct srcu;
	struct notifier_block *head;
};

enum what {
	PROC_EVENT_NONE = 0,
	PROC_EVENT_FORK = 1,
	PROC_EVENT_EXEC = 2,
	PROC_EVENT_UID = 4,
	PROC_EVENT_GID = 64,
	PROC_EVENT_SID = 128,
	PROC_EVENT_PTRACE = 256,
	PROC_EVENT_COMM = 512,
	PROC_EVENT_COREDUMP = 1073741824,
	PROC_EVENT_EXIT = 2147483648,
};

typedef u64 async_cookie_t;

typedef void (*async_func_t)(void *, async_cookie_t);

struct async_domain {
	struct list_head pending;
	unsigned int registered: 1;
};

struct async_entry {
	struct list_head domain_list;
	struct list_head global_list;
	struct work_struct work;
	async_cookie_t cookie;
	async_func_t func;
	void *data;
	struct async_domain *domain;
};

struct smpboot_thread_data {
	unsigned int cpu;
	unsigned int status;
	struct smp_hotplug_thread *ht;
};

enum {
	HP_THREAD_NONE = 0,
	HP_THREAD_ACTIVE = 1,
	HP_THREAD_PARKED = 2,
};

struct rh_flag {
	struct list_head list;
	char name[32];
};

struct pin_cookie {};

enum {
	CSD_FLAG_LOCK = 1,
	IRQ_WORK_PENDING = 1,
	IRQ_WORK_BUSY = 2,
	IRQ_WORK_LAZY = 4,
	IRQ_WORK_HARD_IRQ = 8,
	IRQ_WORK_CLAIMED = 3,
	CSD_TYPE_ASYNC = 0,
	CSD_TYPE_SYNC = 16,
	CSD_TYPE_IRQ_WORK = 32,
	CSD_TYPE_TTWU = 48,
	CSD_FLAG_TYPE_MASK = 240,
};

struct dl_bw {
	raw_spinlock_t lock;
	u64 bw;
	u64 total_bw;
};

struct cpudl_item;

struct cpudl {
	raw_spinlock_t lock;
	int size;
	cpumask_var_t free_cpus;
	struct cpudl_item *elements;
};

struct cpupri_vec {
	atomic_t count;
	cpumask_var_t mask;
};

struct cpupri {
	struct cpupri_vec pri_to_cpu[102];
	int *cpu_to_pri;
};

struct perf_domain;

struct root_domain___2 {
	atomic_t refcount;
	atomic_t rto_count;
	struct callback_head rcu;
	cpumask_var_t span;
	cpumask_var_t online;
	int overload;
	cpumask_var_t dlo_mask;
	atomic_t dlo_count;
	struct dl_bw dl_bw;
	struct cpudl cpudl;
	struct irq_work rto_push_work;
	raw_spinlock_t rto_lock;
	int rto_loop;
	int rto_cpu;
	atomic_t rto_loop_next;
	atomic_t rto_loop_start;
	cpumask_var_t rto_mask;
	struct cpupri cpupri;
	long unsigned int max_cpu_capacity;
	union {
		struct perf_domain *pd;
		struct {
			long unsigned int rh_reserved1;
		} rh_kabi_hidden_856;
		union {		};
	};
	union {
		int overutilized;
		struct {
			long unsigned int rh_reserved2;
		} rh_kabi_hidden_859;
		union {		};
	};
	union {
		u64 visit_gen;
		struct {
			long unsigned int rh_reserved3;
		} rh_kabi_hidden_868;
		union {		};
	};
	long unsigned int rh_reserved4;
};

struct cfs_rq {
	struct load_weight load;
	long unsigned int rh_reserved_runnable_weight;
	unsigned int nr_running;
	unsigned int h_nr_running;
	u64 exec_clock;
	u64 min_vruntime;
	struct rb_root_cached tasks_timeline;
	struct sched_entity *curr;
	struct sched_entity *next;
	struct sched_entity *last;
	struct sched_entity *skip;
	unsigned int nr_spread_over;
	unsigned int idle_h_nr_running;
	long: 64;
	long: 64;
	long: 64;
	struct sched_avg avg;
	struct {
		raw_spinlock_t lock;
		int nr;
		long unsigned int load_avg;
		long unsigned int util_avg;
		long unsigned int runnable_avg;
		long: 64;
		long: 64;
		long: 64;
		long: 64;
		long: 64;
		long: 64;
		long: 64;
		long: 64;
		long: 64;
		long: 64;
		long: 64;
		long: 64;
	} removed;
	long unsigned int tg_load_avg_contrib;
	long int propagate;
	long int prop_runnable_sum;
	long unsigned int h_load;
	u64 last_h_load_update;
	struct sched_entity *h_load_next;
	struct rq *rq;
	int on_list;
	struct list_head leaf_cfs_rq_list;
	struct task_group *tg;
	int runtime_enabled;
	int rh_reserved_expires_seq;
	u64 rh_reserved_runtime_expires;
	s64 runtime_remaining;
	u64 throttled_clock;
	u64 throttled_clock_pelt;
	u64 throttled_clock_pelt_time;
	int throttled;
	int throttle_count;
	struct list_head throttled_list;
	long unsigned int rh_reserved1;
	long unsigned int rh_reserved2;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
};

struct rt_prio_array {
	long unsigned int bitmap[2];
	struct list_head queue[100];
};

struct rt_rq {
	struct rt_prio_array active;
	unsigned int rt_nr_running;
	unsigned int rr_nr_running;
	struct {
		int curr;
		int next;
	} highest_prio;
	long unsigned int rt_nr_migratory;
	long unsigned int rt_nr_total;
	int overloaded;
	struct plist_head pushable_tasks;
	int rt_queued;
	int rt_throttled;
	u64 rt_time;
	u64 rt_runtime;
	raw_spinlock_t rt_runtime_lock;
	long unsigned int rt_nr_boosted;
	struct rq *rq;
	struct task_group *tg;
};

struct rt_bandwidth {
	raw_spinlock_t rt_runtime_lock;
	ktime_t rt_period;
	u64 rt_runtime;
	struct hrtimer rt_period_timer;
	unsigned int rt_period_active;
};

struct cfs_bandwidth {
	raw_spinlock_t lock;
	ktime_t period;
	u64 quota;
	u64 runtime;
	s64 hierarchical_quota;
	u64 rh_reserved_runtime_expires;
	int rh_reserved_expires_seq;
	union {
		struct {
			u8 idle;
			u8 period_active;
		};
		struct {
			short int idle;
		} rh_kabi_hidden_393;
		union {		};
	};
	union {
		struct {
			u8 rh_reserved_xx_distribute_running;
			u8 slack_started;
		};
		struct {
			short int period_active;
		} rh_kabi_hidden_396;
		union {		};
	};
	struct hrtimer period_timer;
	struct hrtimer slack_timer;
	struct list_head throttled_cfs_rq;
	int nr_periods;
	int nr_throttled;
	u64 throttled_time;
	bool rh_reserved_distribute_running;
};

struct task_group {
	struct cgroup_subsys_state css;
	struct sched_entity **se;
	struct cfs_rq **cfs_rq;
	long unsigned int shares;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	atomic_long_t load_avg;
	struct sched_rt_entity **rt_se;
	struct rt_rq **rt_rq;
	struct rt_bandwidth rt_bandwidth;
	struct callback_head rcu;
	struct list_head list;
	struct task_group *parent;
	struct list_head siblings;
	struct list_head children;
	struct autogroup *autogroup;
	struct cfs_bandwidth cfs_bandwidth;
	long unsigned int rh_reserved1;
	long unsigned int rh_reserved2;
	long: 64;
	long: 64;
	long: 64;
};

typedef int (*task_call_f)(struct task_struct *, void *);

struct wait_bit_key {
	void *flags;
	int bit_nr;
	long unsigned int timeout;
};

struct wait_bit_queue_entry {
	struct wait_bit_key key;
	struct wait_queue_entry wq_entry;
};

struct autogroup {
	struct kref kref;
	struct task_group *tg;
	struct rw_semaphore lock;
	long unsigned int id;
	int nice;
};

enum {
	CFTYPE_ONLY_ON_ROOT = 1,
	CFTYPE_NOT_ON_ROOT = 2,
	CFTYPE_NS_DELEGATABLE = 4,
	CFTYPE_NO_PREFIX = 8,
	CFTYPE_WORLD_WRITABLE = 16,
	CFTYPE_DEBUG = 32,
	CFTYPE_PRESSURE = 64,
	__CFTYPE_ONLY_ON_DFL = 65536,
	__CFTYPE_NOT_ON_DFL = 131072,
};

struct trace_event_raw_sched_kthread_stop {
	struct trace_entry ent;
	char comm[16];
	pid_t pid;
	char __data[0];
};

struct trace_event_raw_sched_kthread_stop_ret {
	struct trace_entry ent;
	int ret;
	char __data[0];
};

struct trace_event_raw_sched_wakeup_template {
	struct trace_entry ent;
	char comm[16];
	pid_t pid;
	int prio;
	int success;
	int target_cpu;
	char __data[0];
};

struct trace_event_raw_sched_switch {
	struct trace_entry ent;
	char prev_comm[16];
	pid_t prev_pid;
	int prev_prio;
	long int prev_state;
	char next_comm[16];
	pid_t next_pid;
	int next_prio;
	char __data[0];
};

struct trace_event_raw_sched_migrate_task {
	struct trace_entry ent;
	char comm[16];
	pid_t pid;
	int prio;
	int orig_cpu;
	int dest_cpu;
	char __data[0];
};

struct trace_event_raw_sched_process_template {
	struct trace_entry ent;
	char comm[16];
	pid_t pid;
	int prio;
	char __data[0];
};

struct trace_event_raw_sched_process_wait {
	struct trace_entry ent;
	char comm[16];
	pid_t pid;
	int prio;
	char __data[0];
};

struct trace_event_raw_sched_process_fork {
	struct trace_entry ent;
	char parent_comm[16];
	pid_t parent_pid;
	char child_comm[16];
	pid_t child_pid;
	char __data[0];
};

struct trace_event_raw_sched_process_exec {
	struct trace_entry ent;
	u32 __data_loc_filename;
	pid_t pid;
	pid_t old_pid;
	char __data[0];
};

struct trace_event_raw_sched_stat_template {
	struct trace_entry ent;
	char comm[16];
	pid_t pid;
	u64 delay;
	char __data[0];
};

struct trace_event_raw_sched_stat_runtime {
	struct trace_entry ent;
	char comm[16];
	pid_t pid;
	u64 runtime;
	u64 vruntime;
	char __data[0];
};

struct trace_event_raw_sched_pi_setprio {
	struct trace_entry ent;
	char comm[16];
	pid_t pid;
	int oldprio;
	int newprio;
	char __data[0];
};

struct trace_event_raw_sched_process_hang {
	struct trace_entry ent;
	char comm[16];
	pid_t pid;
	char __data[0];
};

struct trace_event_raw_sched_move_numa {
	struct trace_entry ent;
	pid_t pid;
	pid_t tgid;
	pid_t ngid;
	int src_cpu;
	int src_nid;
	int dst_cpu;
	int dst_nid;
	char __data[0];
};

struct trace_event_raw_sched_numa_pair_template {
	struct trace_entry ent;
	pid_t src_pid;
	pid_t src_tgid;
	pid_t src_ngid;
	int src_cpu;
	int src_nid;
	pid_t dst_pid;
	pid_t dst_tgid;
	pid_t dst_ngid;
	int dst_cpu;
	int dst_nid;
	char __data[0];
};

struct trace_event_raw_sched_wake_idle_without_ipi {
	struct trace_entry ent;
	int cpu;
	char __data[0];
};

struct trace_event_data_offsets_sched_kthread_stop {};

struct trace_event_data_offsets_sched_kthread_stop_ret {};

struct trace_event_data_offsets_sched_wakeup_template {};

struct trace_event_data_offsets_sched_switch {};

struct trace_event_data_offsets_sched_migrate_task {};

struct trace_event_data_offsets_sched_process_template {};

struct trace_event_data_offsets_sched_process_wait {};

struct trace_event_data_offsets_sched_process_fork {};

struct trace_event_data_offsets_sched_process_exec {
	u32 filename;
};

struct trace_event_data_offsets_sched_stat_template {};

struct trace_event_data_offsets_sched_stat_runtime {};

struct trace_event_data_offsets_sched_pi_setprio {};

struct trace_event_data_offsets_sched_process_hang {};

struct trace_event_data_offsets_sched_move_numa {};

struct trace_event_data_offsets_sched_numa_pair_template {};

struct trace_event_data_offsets_sched_wake_idle_without_ipi {};

typedef void (*btf_trace_sched_kthread_stop)(void *, struct task_struct *);

typedef void (*btf_trace_sched_kthread_stop_ret)(void *, int);

typedef void (*btf_trace_sched_waking)(void *, struct task_struct *);

typedef void (*btf_trace_sched_wakeup)(void *, struct task_struct *);

typedef void (*btf_trace_sched_wakeup_new)(void *, struct task_struct *);

typedef void (*btf_trace_sched_switch)(void *, bool, struct task_struct *, struct task_struct *);

typedef void (*btf_trace_sched_migrate_task)(void *, struct task_struct *, int);

typedef void (*btf_trace_sched_process_free)(void *, struct task_struct *);

typedef void (*btf_trace_sched_process_exit)(void *, struct task_struct *);

typedef void (*btf_trace_sched_wait_task)(void *, struct task_struct *);

typedef void (*btf_trace_sched_process_wait)(void *, struct pid *);

typedef void (*btf_trace_sched_process_fork)(void *, struct task_struct *, struct task_struct *);

typedef void (*btf_trace_sched_process_exec)(void *, struct task_struct *, pid_t, struct linux_binprm *);

typedef void (*btf_trace_sched_stat_wait)(void *, struct task_struct *, u64);

typedef void (*btf_trace_sched_stat_sleep)(void *, struct task_struct *, u64);

typedef void (*btf_trace_sched_stat_iowait)(void *, struct task_struct *, u64);

typedef void (*btf_trace_sched_stat_blocked)(void *, struct task_struct *, u64);

typedef void (*btf_trace_sched_stat_runtime)(void *, struct task_struct *, u64, u64);

typedef void (*btf_trace_sched_pi_setprio)(void *, struct task_struct *, struct task_struct *);

typedef void (*btf_trace_sched_process_hang)(void *, struct task_struct *);

typedef void (*btf_trace_sched_move_numa)(void *, struct task_struct *, int, int);

typedef void (*btf_trace_sched_stick_numa)(void *, struct task_struct *, int, struct task_struct *, int);

typedef void (*btf_trace_sched_swap_numa)(void *, struct task_struct *, int, struct task_struct *, int);

typedef void (*btf_trace_sched_wake_idle_without_ipi)(void *, int);

typedef void (*btf_trace_pelt_cfs_tp)(void *, struct cfs_rq *);

typedef void (*btf_trace_pelt_rt_tp)(void *, struct rq *);

struct dl_rq {
	struct rb_root_cached root;
	long unsigned int dl_nr_running;
	struct {
		u64 curr;
		u64 next;
	} earliest_dl;
	long unsigned int dl_nr_migratory;
	int overloaded;
	struct rb_root_cached pushable_dl_tasks_root;
	u64 running_bw;
	u64 this_bw;
	u64 extra_bw;
	u64 bw_ratio;
};

typedef int (*cpu_stop_fn_t)(void *);

struct cpu_stop_done;

struct cpu_stop_work {
	struct list_head list;
	cpu_stop_fn_t fn;
	void *arg;
	struct cpu_stop_done *done;
};

struct cpuidle_state;

struct rq {
	raw_spinlock_t lock;
	unsigned int nr_running;
	unsigned int nr_numa_running;
	unsigned int nr_preferred_running;
	long unsigned int rh_reserved_cpu_load[5];
	long unsigned int rh_reserved_last_load_update_tick;
	long unsigned int last_blocked_load_update_tick;
	unsigned int has_blocked_load;
	unsigned int nohz_tick_stopped;
	atomic_t nohz_flags;
	struct load_weight rh_reserved_load;
	union {
		unsigned int ttwu_pending;
		struct {
			long unsigned int nr_load_updates;
		} rh_kabi_hidden_917;
		union {		};
	};
	u64 nr_switches;
	long: 64;
	struct cfs_rq cfs;
	struct rt_rq rt;
	struct dl_rq dl;
	struct list_head leaf_cfs_rq_list;
	struct list_head *tmp_alone_branch;
	long unsigned int nr_uninterruptible;
	struct task_struct *curr;
	struct task_struct *idle;
	struct task_struct *stop;
	long unsigned int next_balance;
	struct mm_struct *prev_mm;
	unsigned int clock_update_flags;
	u64 clock;
	union {
		struct rcuwait hotplug_wait;
		struct {
			u64 clock_task;
		} rh_kabi_hidden_947;
		union {		};
	};
	atomic_t nr_iowait;
	int membarrier_state;
	struct root_domain___2 *rd;
	struct sched_domain *sd;
	long unsigned int cpu_capacity;
	long unsigned int cpu_capacity_orig;
	struct callback_head *balance_callback;
	unsigned char idle_balance;
	unsigned char nohz_idle_balance;
	int active_balance;
	int push_cpu;
	struct cpu_stop_work active_balance_work;
	int cpu;
	int online;
	struct list_head cfs_tasks;
	union {
		long unsigned int wake_stamp;
		struct {
			u64 rt_avg;
		} rh_kabi_hidden_978;
		union {		};
	};
	union {
		u64 wake_avg_idle;
		struct {
			u64 age_stamp;
		} rh_kabi_hidden_979;
		union {		};
	};
	u64 idle_stamp;
	u64 avg_idle;
	u64 max_idle_balance_cost;
	long unsigned int calc_load_update;
	long int calc_load_active;
	int rh_reserved_hrtick_csd_pending;
	long: 32;
	long: 64;
	long: 64;
	long: 64;
	call_single_data_t hrtick_csd;
	struct hrtimer hrtick_timer;
	struct sched_info rq_sched_info;
	long long unsigned int rq_cpu_time;
	unsigned int yld_count;
	unsigned int sched_count;
	unsigned int sched_goidle;
	unsigned int ttwu_count;
	unsigned int ttwu_local;
	struct llist_head rh_reserved_wake_list;
	struct cpuidle_state *idle_state;
	union {
		ktime_t hrtick_time;
		struct {
			long unsigned int rh_reserved1;
		} rh_kabi_hidden_1041;
		union {		};
	};
	union {
		struct {
			unsigned int push_busy;
			unsigned int nr_pinned;
		};
		struct {
			long unsigned int rh_reserved2;
		} rh_kabi_hidden_1046;
		union {		};
	};
	unsigned int numa_migrate_on;
	long: 32;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	struct sched_avg avg_rt;
	struct sched_avg avg_dl;
	long unsigned int misfit_task_load;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
	u64 clock_task;
	u64 clock_pelt;
	long unsigned int lost_idle_time;
	struct cpu_stop_work push_work;
	call_single_data_t nohz_csd;
	long: 64;
	long: 64;
	long: 64;
	long: 64;
};

typedef void (*btf_trace_pelt_dl_tp)(void *, struct rq *);

typedef void (*btf_trace_pelt_irq_tp)(void *, struct rq *);

typedef void (*btf_trace_pelt_se_tp)(void *, struct sched_entity *);

typedef void (*btf_trace_sched_cpu_capacity_tp)(void *, struct rq *);

typedef void (*btf_trace_sched_overutilized_tp)(void *, struct root_domain___2 *, bool);

typedef void (*btf_trace_sched_util_est_cfs_tp)(void *, struct cfs_rq *);

typedef void (*btf_trace_sched_util_est_se_tp)(void *, struct sched_entity *);

typedef void (*btf_trace_sched_update_nr_running_tp)(void *, struct rq *, int);

struct trace_event_raw_ipi_raise {
	struct trace_entry ent;
	u32 __data_loc_target_cpus;
	const char *reason;
	char __data[0];
};

struct trace_event_raw_ipi_send_cpu {
	struct trace_entry ent;
	unsigned int cpu;
	void *callsite;
	void *callback;
	char __data[0];
};

