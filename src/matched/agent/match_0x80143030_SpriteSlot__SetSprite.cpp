// FLAGS: -fno-schedule-insns
// 0x80143030 SpriteSlot::SetSprite(ObjSelector*) (92B)

class ObjSelector;

class EGlobal {
public:
    void UpdateSpriteRenderer(class SpriteSlot* slot);
};

extern EGlobal* g_global_renderer;  // SDA at -0x53B8

class SpriteSlot {
public:
    char pad[0x18];
    int m_18;
    char pad1C[0xC];
    ObjSelector* m_28;
    int m_2C;
    int m_30;
    int m_34;
    char pad38[4];
    int m_3C;
    int m_40;
    void SetSprite(ObjSelector* sel);
};

void SpriteSlot::SetSprite(ObjSelector* sel) {
    EGlobal* g = g_global_renderer;
    m_28 = sel;
    m_18 = -1;
    m_30 = 0;
    m_34 = 1;
    m_2C = 1;
    g->UpdateSpriteRenderer(this);
    m_40 = -1;
    m_3C = -1;
}
