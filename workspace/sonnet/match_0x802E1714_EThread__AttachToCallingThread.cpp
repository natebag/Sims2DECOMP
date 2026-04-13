// 0x802E1714 EThread::AttachToCallingThread (56b)

class EThread {
public:
    int Attach(int);
    int AttachToCallingThread(void);
    static int GetCurrentThreadId(void);
};

int EThread::AttachToCallingThread(void) {
    return Attach(GetCurrentThreadId());
}
