/* EGlobal::LoadPreGlobalRequirements(void) at 0x8003ECA8 (76B) */

extern int *g_cheatsPtr;

void *__builtin_new(unsigned int size);

inline void *operator new(unsigned int, void *p) { return p; }

struct EGlobal;

struct ECheats {
    ECheats(void);
    void Init(EGlobal *global);
};

struct EGlobal {
    char pad_114[0x114];
    ECheats *m_cheats;
    char pad_168[0x168 - 0x118];
    int m_cheatsData;
    void LoadPreGlobalRequirements(void);
};

void EGlobal::LoadPreGlobalRequirements(void) {
    g_cheatsPtr = &m_cheatsData;
    void *p = __builtin_new(268);
    ECheats *cheats = new(p) ECheats;
    m_cheats = cheats;
    cheats->Init(this);
}
