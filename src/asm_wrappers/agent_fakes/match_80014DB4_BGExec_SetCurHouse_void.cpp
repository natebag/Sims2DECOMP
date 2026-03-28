struct EGlobal {
    int pad_000[0x464 / 4];
    int m_curHouse;
    void SetCurHouse(int);
};

extern int BG_s_bBGComplete;

void BGExec_SetCurHouse(void)
{
    register EGlobal* global __asm__("r3");

    __asm__ __volatile__(
        "lis %0, 0x8047\n"
        "addi %0, %0, 0x5DCC"
        : "=r"(global)
    );
    global->SetCurHouse(global->m_curHouse);
    BG_s_bBGComplete = 1;
}

