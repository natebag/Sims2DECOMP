/* ENgcScheduler::QueueSetupFrameBuffer(int) at 0x8034D918 (40B) */

struct ENgcRenderer_QSBF {
    void QueueBeginFrame(int arg);
};

extern char gENgcRenderer[];

struct ENgcScheduler_QSBF {
    void QueueSetupFrameBuffer(int arg);
};

void ENgcScheduler_QSBF::QueueSetupFrameBuffer(int arg) {
    ((ENgcRenderer_QSBF*)gENgcRenderer)->QueueBeginFrame(arg);
}
