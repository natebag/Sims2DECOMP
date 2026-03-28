// 0x80111188 (12 bytes)
// ObjSelector::GetShadowBrightness(void)
// lwz r9, 56(r3); lha r3, 158(r9); blr
struct ObjSelectorData {
    char m_pad[158];
    short m_shadowBrightness;
};

class ObjSelector {
public:
    char m_pad[56];
    ObjSelectorData* m_data;
    short GetShadowBrightness();
};

short ObjSelector::GetShadowBrightness() {
    return m_data->m_shadowBrightness;
}
