struct EGlobal {
    void SetupScratchHeap(void);
};

struct ESimsApp {
    void SetupForMovie(void);
};

void ESimsApp::SetupForMovie(void)
{
    EGlobal* global;

    __asm__ __volatile__(
        "lis %0, 0x8047\n"
        "addi %0, %0, 0x5DCC"
        : "=r"(global)
    );
    global->SetupScratchHeap();
}

