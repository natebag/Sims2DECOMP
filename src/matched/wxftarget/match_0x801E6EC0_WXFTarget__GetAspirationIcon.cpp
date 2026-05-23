// 0x801E6EC0 WXFTarget::GetAspirationIcon() (72B)

class EGlobal {
public:
    void* GetSelectedPerson(int id);
};

extern char gEGlobalSingleton_80475DCC[16];

class WXFTarget {
public:
    char pad0[148];
    int m_148_id;
    int GetAspirationIcon();
};

int WXFTarget::GetAspirationIcon() {
    int id = m_148_id;
    void* p = ((EGlobal*)gEGlobalSingleton_80475DCC)->GetSelectedPerson(id);
    char* obj = (char*)p;
    char* vt = *(char**)(obj + 4);
    short adj = *(short*)(vt + 0x138);
    void* fn = *(void**)(vt + 0x13C);
    return ((int(*)(void*, int))fn)(obj + adj, 20);
}
