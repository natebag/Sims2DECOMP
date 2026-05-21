// 0x80093124 MUStatesLoadConfig::Draw(ERC*) (76B) — bounds check + Tech #47 MI-vcall

class ERC;

class MUStatesLoadConfig {
public:
    char pad0[8];
    void* m_mgr;
    char pad12[16];
    int m_state;
    void Draw(ERC* erc);
};

void MUStatesLoadConfig::Draw(ERC* erc) {
    int s = m_state - 1;
    if ((unsigned int)s > 1) return;
    void* mgr = m_mgr;
    char* obj = *(char**)((char*)mgr + 152);
    char* vt = *(char**)(obj + 128);
    short adj = *(short*)(vt + 48);
    void* fn = *(void**)(vt + 52);
    ((void(*)(void*, ERC*))fn)(obj + adj, erc);
}
