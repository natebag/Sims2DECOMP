/* ENgcScheduler::QueueCompletionEvent(EEvent &) at 0x8034D968 (40B) */

struct ENgcRenderer_SQCE {
    void QueueEndFrame(void* event);
};

extern char gENgcRenderer[];

struct ENgcScheduler_SQCE {
    void QueueCompletionEvent(void* event);
};

void ENgcScheduler_SQCE::QueueCompletionEvent(void* event) {
    ((ENgcRenderer_SQCE*)gENgcRenderer)->QueueEndFrame(event);
}
