// 0x80321EE0 HDDThread::DoDelete (52b)

extern void HDDThread_DoDelete_sub(void*);

struct HDDThread {
    char pad[0x5C0];
    int m_deleteFlag;
};

void HDDThread_DoDelete(HDDThread* self) {
    HDDThread_DoDelete_sub(self);
    self->m_deleteFlag = 1;
}
