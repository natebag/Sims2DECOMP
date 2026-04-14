/* ObjSelector::GetShadowBrightness(void) - 0x80111188 - 12 bytes */
/* lwz r9, 56(r3); lha r3, 0x9E(r9); blr */

struct ObjFnData {
    char _pad[0x9E];
    short m_shadowBrightness;
};

class ObjSelector {
public:
    char _pad[0x38];
    ObjFnData* m_fnData;

    int GetShadowBrightness(void);
};

int ObjSelector::GetShadowBrightness(void) {
    return m_fnData->m_shadowBrightness;
}
