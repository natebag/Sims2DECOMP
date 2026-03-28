struct EGlobal {
    void FreeScratchHeap(void);
};

struct ESimsApp {
    void CleanupAfterMovie(void);
};

void ESimsApp::CleanupAfterMovie(void)
{
    EGlobal* global;

    __asm__ __volatile__(
        "lis %0, 0x8047\n"
        "addi %0, %0, 0x5DCC"
        : "=r"(global)
    );
    global->FreeScratchHeap();
}

