struct EAHeap;
extern "C" EAHeap* EAHeap_GetMovieHeap(void);
struct ESimsApp {
    EAHeap* GetMovieHeap(void);
};

EAHeap* ESimsApp::GetMovieHeap(void)
{
    register EAHeap* heap __asm__("r3");

    __asm__ __volatile__(
        "lis 9, 0x8047\n"
        "lwz %0, 0x5F1C(9)"
        : "=r"(heap)
    );
    if (heap == 0) {
        heap = EAHeap_GetMovieHeap();
    }
    return heap;
}

