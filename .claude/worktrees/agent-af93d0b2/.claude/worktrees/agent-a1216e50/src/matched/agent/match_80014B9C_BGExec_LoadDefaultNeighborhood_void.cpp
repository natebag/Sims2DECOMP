struct GameData {
    void LoadDefaultNeighborhood(void);
};

extern int BG_s_bBGComplete;

void BGExec_LoadDefaultNeighborhood(void)
{
    register GameData* gameData __asm__("r3");

    __asm__ __volatile__(
        "lis %0, 0x8047\n"
        "addi %0, %0, 0x5B84"
        : "=r"(gameData)
    );
    gameData->LoadDefaultNeighborhood();
    BG_s_bBGComplete = 1;
}

