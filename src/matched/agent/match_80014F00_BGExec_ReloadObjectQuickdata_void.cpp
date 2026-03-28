struct EGlobal {
    void FreeScratchHeap(void);
};

extern int BG_s_bBGComplete;

void BGExec_ReloadObjectQuickdata(void)
{
    EGlobal* global;

    __asm__ __volatile__(
        "lis %0, 0x8047\n"
        "addi %0, %0, 0x5DCC"
        : "=r"(global)
    );
    global->FreeScratchHeap();
    BG_s_bBGComplete = 1;
}

