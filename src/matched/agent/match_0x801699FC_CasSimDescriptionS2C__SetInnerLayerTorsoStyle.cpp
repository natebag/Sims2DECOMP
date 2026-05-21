// 0x801699FC CasSimDescriptionS2C::SetInnerLayerTorsoStyle(CasSimPartsS2C&) (68B)

class CasSimPartsS2C;

class CasSimDescriptionS2C {
public:
    char pad0[156];
    int m_innerStyle;
    bool InnerLayerHalfTorsoRequired(CasSimPartsS2C& parts);
    void SetInnerLayerTorsoStyle(CasSimPartsS2C& parts);
};

void CasSimDescriptionS2C::SetInnerLayerTorsoStyle(CasSimPartsS2C& parts) {
    int ret = (int)InnerLayerHalfTorsoRequired(parts);
    if (ret != 0) {
        m_innerStyle = 1;
    } else {
        m_innerStyle = ret;
    }
}
