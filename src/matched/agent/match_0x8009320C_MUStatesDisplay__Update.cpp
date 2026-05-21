// 0x8009320C MUStatesDisplay::Update(float) (68B) — Tech #47 MI-vcall

class MUStatesDisplay {
public:
    char pad0[8];
    void* m_mgr;
    void Update(float dt);
};

void MUStatesDisplay::Update(float dt) {
    void* mgr = m_mgr;
    char* obj = *(char**)((char*)mgr + 152);
    if (obj == 0) return;
    char* vt = *(char**)(obj + 128);
    short adj = *(short*)(vt + 40);
    void* fn = *(void**)(vt + 44);
    ((void(*)(void*, float))fn)(obj + adj, dt);
}
