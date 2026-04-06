// FLAGS: -msdata=eabi -G 8
// 0x801496C0 TTabScratchEntry::GetAttenuationValue (48b)
extern float CalculateAttenuationValue(int, int, float);

struct TTabScratchEntry {
    char pad[264];
    int field_108;
    float field_10C;
};

float GetAttenuationValue(TTabScratchEntry* self, int param) {
    return CalculateAttenuationValue(param, self->field_108, self->field_10C);
}
