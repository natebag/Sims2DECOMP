// 0x8015E7B0 (8 bytes)
class TreeTableEntryQuickData {
public:
    float GetCustomAttenuationValue();
};

float TreeTableEntryQuickData::GetCustomAttenuationValue() {
    return *(float*)((char*)(*(int*)((char*)this + 0x4)) + 0x8);
}
