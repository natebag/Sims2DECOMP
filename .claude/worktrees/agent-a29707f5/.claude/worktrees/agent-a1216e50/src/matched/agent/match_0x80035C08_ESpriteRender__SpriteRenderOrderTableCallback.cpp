/* ESpriteRender::SpriteRenderOrderTableCallback(ELevelDrawData &, EOrderTableData *) at 0x80035C08 (72B) */

struct ERC;
struct EOrderTableData;
struct ELevelDrawData;

struct ESpriteRender {
    char pad_00[0x98];
    ERC* m_rc;
    char pad_9c[0x0C];
    int m_fieldA8;
    int m_fieldAC;
    int m_fieldB0;
    int m_fieldB4;

    void DrawDirectly(ERC*);
    void SpriteRenderOrderTableCallback(ELevelDrawData&, EOrderTableData*);
};

struct ELevelDrawData {
    char pad[0x18];
    ESpriteRender* m_sprite;
};

void ESpriteRender::SpriteRenderOrderTableCallback(ELevelDrawData& data, EOrderTableData*) {
    data.m_sprite->DrawDirectly(m_rc);
    m_fieldA8 = 0;
    m_fieldAC = 0;
    m_fieldB4 = 0;
    m_fieldB0 = 0;
}
