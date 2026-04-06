// 0x8032EB78 EventIdleThread (28b)
void EventIdleThread(void*) {
    volatile int counter = 0;
    while (1) {
        counter++;
    }
}
