// 0x80149EA8 (8 bytes)
class TTabScratchEntry {
public:
    float GetCustomAttenuationValue();
};

float TTabScratchEntry::GetCustomAttenuationValue() {
    return *(float*)((char*)this + 0x10C);
}
