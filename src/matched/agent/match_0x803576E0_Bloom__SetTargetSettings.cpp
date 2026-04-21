// 0x803576E0 (116B) Bloom::SetTargetSettings(BloomSettings &)
// memcpy of 44-byte BloomSettings (11 words) into this at offset 20.

struct BloomSettings {
    int fields[11];
};

class Bloom {
public:
    char pad[20];
    BloomSettings m_target;
    void SetTargetSettings(BloomSettings& s);
};

void Bloom::SetTargetSettings(BloomSettings& s) {
    m_target = s;
}
