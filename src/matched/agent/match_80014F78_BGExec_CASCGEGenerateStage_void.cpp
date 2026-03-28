extern "C" void CASGeneticsTarget_HandleGenerateStageBG(void);

extern int BG_s_bBGComplete;

void BGExec_CASCGEGenerateStage(void)
{
    register int target __asm__("r0");

    __asm__ __volatile__(
        "lis 9, 0x8047\n"
        "lwz %0, 0x5BC0(9)"
        : "=r"(target)
    );
    if (target != 0) {
        CASGeneticsTarget_HandleGenerateStageBG();
    }
    BG_s_bBGComplete = 1;
}

