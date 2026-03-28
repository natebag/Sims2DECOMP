/* 0x80321F14 (12 bytes) - HDDThread::DoCopy(void) */
class HDDThread { char pad[1476]; int m_doCopy; public: void DoCopy(); };
void HDDThread::DoCopy() { m_doCopy = 1; }
