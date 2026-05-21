// 0x800922F4 MUStatesSaveNewGame::Draw(ERC*) (76B) — Tech #47 MI-vcall with state-range check

class ERC;

class MUStatesSaveNewGame {
public:
    char pad0[8];
    void* m_mgr;
    char pad_C[16];
    unsigned int m_state;     // 28
    void Draw(ERC* erc);
};

void MUStatesSaveNewGame::Draw(ERC* erc) {
    unsigned int s = m_state - 9;
    if (s > 2) return;
    void* mgr = m_mgr;
    char* obj = *(char**)((char*)mgr + 152);
    char* vt = *(char**)(obj + 128);
    short adj = *(short*)(vt + 48);
    void* fn = *(void**)(vt + 52);
    ((void(*)(void*, ERC*))fn)(obj + adj, erc);
}
