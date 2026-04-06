// 0x80321F20 HDDThread::TerminateCopy (52b)

extern void HDDThread_TerminateCopy_sub(void*);

struct HDDThread2 {
    char pad[0x5C4];
    int m_copyFlag;
};

void HDDThread_TerminateCopy(HDDThread2* self) {
    HDDThread_TerminateCopy_sub(self);
    self->m_copyFlag = 0;
}
