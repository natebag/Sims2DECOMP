// 0x80169AF8 CasSimDescriptionS2C::SetMidLayerTorsoStyle(Sim::MidLayerTorsoStyleS2C, CasSimPartsS2C&) (64B)

class CasSimPartsS2C;
class Sim;

class CasSimDescriptionS2C {
public:
    char pad0[168];
    int m_style;
    bool MidLayerHalfTorsoRequired(CasSimPartsS2C& parts);
    void SwitchMidLayerTorso(bool flag);
    void SetMidLayerTorsoStyle(int style, CasSimPartsS2C& parts);
};

void CasSimDescriptionS2C::SetMidLayerTorsoStyle(int style, CasSimPartsS2C& parts) {
    m_style = style;
    bool req = MidLayerHalfTorsoRequired(parts);
    SwitchMidLayerTorso(req);
}
