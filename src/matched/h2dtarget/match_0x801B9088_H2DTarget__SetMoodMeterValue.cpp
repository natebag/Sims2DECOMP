/* H2DTarget::SetMoodMeterValue(int, float, bool) at 0x801B9088 (56B) */

struct MODTarget_SMV {
    void SetMeterValue(float val, bool b);
};

struct H2DTarget_SMV {
    char m_pad[136];
    MODTarget_SMV* m_meters[1];
    void SetMoodMeterValue(int idx, float val, bool b);
};

void H2DTarget_SMV::SetMoodMeterValue(int idx, float val, bool b) {
    if (m_meters[idx])
        m_meters[idx]->SetMeterValue(val, b);
}
