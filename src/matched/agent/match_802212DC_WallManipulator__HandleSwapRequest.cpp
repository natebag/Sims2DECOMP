typedef unsigned int size_t;
void* operator new(size_t);

struct UIAUDIO {
    char pad[0x78];
    UIAUDIO();
    void PlaySound(unsigned int soundID);
};

extern UIAUDIO* g_pUIAUDIO;

void WallManipulator_CommittTransaction(void*, int);

struct WallManipulator {
    char pad_00[0xC4];
    int m_flags;

    void HandleSwapRequest();
};

void WallManipulator::HandleSwapRequest() {
    m_flags = 0;
    if (g_pUIAUDIO == 0) {
        g_pUIAUDIO = new UIAUDIO;
    }
    g_pUIAUDIO->PlaySound(0x0064AC15);
    WallManipulator_CommittTransaction(this, 4);
}
