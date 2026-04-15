// 0x80169A40 CasSimDescriptionS2C::SwitchInnerLayerTorso(bool) (28B)

struct CasSimDescriptionS2C {
    char pad[156];
    int m_innerLayerTorso;
    void SwitchInnerLayerTorso(bool b);
};

void CasSimDescriptionS2C::SwitchInnerLayerTorso(bool b) {
    if (b) {
        m_innerLayerTorso = 1;
    } else {
        m_innerLayerTorso = 0;
    }
}
