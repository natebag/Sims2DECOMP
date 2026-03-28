typedef void* OSThread;

OSThread OSGetCurrentThread();

struct EThread {
    static OSThread GetCurrentThreadId();
};

OSThread EThread::GetCurrentThreadId()
{
    return OSGetCurrentThread();
}
