/* ENgcScheduler::QueueSwapBuffer(int, int) at 0x8034D990 (40B) */

struct ENgcRenderer_SQSB {
    void QueueSwap(int a, int b);
};

extern char gENgcRenderer[];

struct ENgcScheduler_SQSB {
    void QueueSwapBuffer(int a, int b);
};

void ENgcScheduler_SQSB::QueueSwapBuffer(int a, int b) {
    ((ENgcRenderer_SQSB*)gENgcRenderer)->QueueSwap(a, b);
}
