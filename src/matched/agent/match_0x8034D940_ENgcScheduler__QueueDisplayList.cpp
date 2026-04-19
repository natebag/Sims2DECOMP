/* ENgcScheduler::QueueDisplayList(EDL *, bool) at 0x8034D940 (40B) */

struct ENgcRenderer_SQDL {
    void QueueDisplayList(void* dl, int flag);
};

extern char gENgcRenderer[];

struct ENgcScheduler_SQDL {
    void QueueDisplayList(void* dl, int flag);
};

void ENgcScheduler_SQDL::QueueDisplayList(void* dl, int flag) {
    ((ENgcRenderer_SQDL*)gENgcRenderer)->QueueDisplayList(dl, flag);
}
