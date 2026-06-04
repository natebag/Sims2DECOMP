// FLAGS: -fno-schedule-insns
// 0x80076000 SkinCompositor::InitSkinTexture(void) (76 B)

extern unsigned short lbl_8046ACF0;
extern unsigned short lbl_80468236;
extern unsigned short lbl_80468234;

struct SkinTextureLayerInner { char pad[0x19]; unsigned char flag; };
struct SkinTextureLayerMid { char pad[0x14]; SkinTextureLayerInner* inner; };
struct SkinCompositor {
    unsigned short m_size;
    int m_hasFlag;
    char pad08[8];
    int m_hiRes;
    char pad14[4];
    SkinTextureLayerMid* m_layer;
    void InitSkinTexture();
};

void SkinCompositor::InitSkinTexture() {
    m_size = lbl_8046ACF0 * (m_hiRes ? lbl_80468236 : lbl_80468234);
    int zero = 0;
    SkinTextureLayerMid* layer = m_layer;
    SkinTextureLayerInner* inner = layer->inner;
    m_hasFlag = zero;
    if (inner->flag != 0) {
        m_hasFlag = 1;
    }
}
