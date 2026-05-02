// 0x8008BB08 (96B) ELiveMode::~ELiveMode(void)
// Variant L: SI deleting-dtor — vtable@+8 + non-SDA singleton clear + ~EGameState(0) + MainHeap delete.

extern char vt_ELiveMode[];

struct LiveModePtr {
    char data[16];
};
extern LiveModePtr g_liveModeHandle;

class EAHeap {
public:
    void Free(void* p);
};
EAHeap* MainHeap();

void EGameState_dtor(void* obj, int flag);

struct ELiveMode {
    char pad_0_7[8];
    void* m_vt_at_8;
    void dtor(int flag);
};

void ELiveMode::dtor(int flag) {
    m_vt_at_8 = vt_ELiveMode;
    *(int*)&g_liveModeHandle = 0;
    EGameState_dtor(this, 0);
    if (flag & 1) {
        MainHeap()->Free(this);
    }
}
