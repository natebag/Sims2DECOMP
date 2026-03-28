int TimerGetTicksImpl();

int AptAuxPCEorGL_TimerGetTicks() {
    return TimerGetTicksImpl();
}
