// 0x80093250 MUStatesDisplay::Draw(ERC*) (68B) — Tech #47 MI-vcall (Update twin, different vtable slot)

class ERC;

class MUStatesDisplay {
public:
    char pad0[8];
    void* m_mgr;
    void Draw(ERC* erc);
};

void MUStatesDisplay::Draw(ERC* erc) {
    void* mgr = m_mgr;
    char* obj = *(char**)((char*)mgr + 152);
    if (obj == 0) return;
    char* vt = *(char**)(obj + 128);
    short adj = *(short*)(vt + 48);
    void* fn = *(void**)(vt + 52);
    ((void(*)(void*, ERC*))fn)(obj + adj, erc);
}
