// 0x80035364 (8 bytes) — stfs f1, 0x3F0(r3); blr

class ESim {
public:
    char _pad[0x3F0];
    float m_skillmeterValue;

    void SetSkillmeterValue(float val);
};

void ESim::SetSkillmeterValue(float val) {
    m_skillmeterValue = val;
}
