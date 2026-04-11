// SimsCameraParameters::Validate(void) — 40B @ 0x80016044

class SimsCameraParameters {
public:
    void Validate(void);
private:
    char pad[0x28];
    float field_0x28;
    float field_0x2C;
    char pad2[0x8];
    float field_0x38;
    char pad3[0x78];
    float field_0xB4;
    float field_0xB8;
};

void SimsCameraParameters::Validate(void) {
    if (field_0x2C < field_0x28) {
        field_0x2C = field_0x28;
    }
    field_0xB4 = field_0x38;
    field_0xB8 = field_0x28;
}
