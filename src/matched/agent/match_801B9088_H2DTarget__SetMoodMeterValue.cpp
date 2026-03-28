class MODTarget {
public:
    void SetMeterValue(float val, bool b);
};

class H2DTarget {
public:
    char _pad[0x88];
    MODTarget *m_modTargets[2];

    void SetMoodMeterValue(int playerIndex, float val, bool b);
};

void H2DTarget::SetMoodMeterValue(int playerIndex, float val, bool b) {
    MODTarget *mod = m_modTargets[playerIndex];
    if (mod != 0) {
        mod->SetMeterValue(val, b);
    }
}
