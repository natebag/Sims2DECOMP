// 0x80091764 MUStatesFormat::Draw(ERC*) (72B) — Tech #47 MI-vcall + state==1 check

class ERC;

class MUStatesFormat {
public:
    char pad0[8];
    void* m_mgr;
    char pad_C[20];
    int  m_state;     // 32
    void Draw(ERC* erc);
};

void MUStatesFormat::Draw(ERC* erc) {
    if (m_state != 1) return;
    void* mgr = m_mgr;
    char* obj = *(char**)((char*)mgr + 152);
    char* vt = *(char**)(obj + 128);
    short adj = *(short*)(vt + 48);
    void* fn = *(void**)(vt + 52);
    ((void(*)(void*, ERC*))fn)(obj + adj, erc);
}
