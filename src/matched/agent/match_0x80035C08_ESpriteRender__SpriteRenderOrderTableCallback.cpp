// 0x80035C08 ESpriteRender::SpriteRenderOrderTableCallback(ELevelDrawData &, EOrderTableData *) (72B)

class ERC;
class EOrderTableData;
class ELevelDrawData {
public:
    char _pad[24];
    ERC* m_rc;
};

class ESpriteRender {
public:
    char _pad0[152];
    ERC* m_field152;
    char _pad156[168 - 156];
    int m_field168;
    int m_field172;
    int m_field176;
    int m_field180;

    static void DrawDirectly(ERC* rc, ERC* sprite);
    void SpriteRenderOrderTableCallback(ELevelDrawData& dd, EOrderTableData* otd);
};

void ESpriteRender::SpriteRenderOrderTableCallback(ELevelDrawData& dd, EOrderTableData* /*otd*/) {
    DrawDirectly(dd.m_rc, m_field152);
    *(volatile int*)&m_field176 = 0;
    *(volatile int*)&m_field168 = 0;
    *(volatile int*)&m_field172 = 0;
    *(volatile int*)&m_field180 = 0;
}
