int OSGetCurrentThread();

int EThread_GetCurrentThreadId() {
    return OSGetCurrentThread();
}
