// 0x8003E094 GameEffectsManager::RenderCB(ELevelDrawData&, EOrderTableData*) (88B)
// Tech #47 MI-vcall via raw pointer arithmetic

class EOrderTableData;

class ELevelDrawData {
public:
    char pad[0x18];
    char* m_18;
};

class GameEffectsManager {
public:
    char pad[0x98];
    void* m_98;
    char padA0[0xC];
    int m_A8;
    void RenderCB(ELevelDrawData& dd, EOrderTableData* otd);
};

void GameEffectsManager::RenderCB(ELevelDrawData& dd, EOrderTableData* otd) {
    char* d = dd.m_18;
    if (d == 0) return;
    char* vt = *(char**)(d + 0x144);

    short adj = *(short*)(vt + 0x18);
    void (*fn)(void*, void*) = *(void (**)(void*, void*))(vt + 0x1C);
    fn(d + adj, m_98);
    m_A8 = 0;
}
