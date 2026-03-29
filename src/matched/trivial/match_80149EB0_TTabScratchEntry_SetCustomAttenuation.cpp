// 0x80149EB0 (16 bytes)
// TTabScratchEntry::SetCustomAttenuation(float)
class TTabScratchEntry {
    char pad[264];
    int m_field264;
    float m_field268;
public:
    void SetCustomAttenuation(float val);
};

void TTabScratchEntry::SetCustomAttenuation(float val) {
    m_field264 = 0;
    m_field268 = val;
}
