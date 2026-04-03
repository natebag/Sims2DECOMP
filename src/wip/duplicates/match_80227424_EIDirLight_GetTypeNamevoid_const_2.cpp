// 0x80227424 (12 bytes)
class EIDirLight {
public:
    const char* GetTypeName() const;
};

extern char gEIDirLightData[];

const char* EIDirLight::GetTypeName() const {
    return *(const char**)(gEIDirLightData + 0);
}
