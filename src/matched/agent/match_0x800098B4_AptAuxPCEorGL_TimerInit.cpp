extern int gTimerObject;

void TimerInitImpl(void* timer);

void AptAuxPCEorGL_TimerInit() {
    TimerInitImpl((void*)gTimerObject);
}
