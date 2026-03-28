struct DepthOfFieldSettings {
    int f00, f04, f08, f0C, f10;
};

struct DepthOfField {
    char pad[0x14];
    DepthOfFieldSettings m_target;

    void SetTargetSettings(DepthOfFieldSettings& settings);
};

void DepthOfField::SetTargetSettings(DepthOfFieldSettings& settings) {
    m_target = settings;
}
