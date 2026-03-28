struct EHouse {
    void Init(void);
};

extern int BG_s_bBGComplete;

void BGExec_CurHouseInit(void)
{
    register EHouse* house __asm__("r3");

    __asm__ __volatile__(
        "lis 9, 0x8047\n"
        "lwz %0, 0x5E94(9)"
        : "=r"(house)
    );
    house->Init();
    BG_s_bBGComplete = 1;
}

