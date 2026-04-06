// 0x80321F8C HDDThread::DoSpeedTest (52b)

extern void HDDThread_DoSpeedTest_sub(void*);

struct HDDThread3 {
    char pad[0x5CC];
    int m_speedTestFlag;
};

void HDDThread_DoSpeedTest(HDDThread3* self) {
    HDDThread_DoSpeedTest_sub(self);
    self->m_speedTestFlag = 1;
}
