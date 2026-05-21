// 0x8003F9AC EGlobal::SelectWin(ERC*) (80B)

class ERC;

class EGlobal {
public:
    char pad[0xD0];
    int m_208;
    void SelectWin(ERC* erc);
};

void EGlobal::SelectWin(ERC* erc) {
    int p = m_208;
    if (p == 0) return;
    char* obj = (char*)p + 16;
    if (obj == 0) return;
    if (erc == 0) return;
    char* vt = *(char**)(obj + 0x9C);
    short adj = *(short*)(vt + 0x10);
    void* fn = *(void**)(vt + 0x14);
    ((void(*)(void*))fn)(obj + adj);
}
