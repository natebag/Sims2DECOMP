// 0x80227430 (12 bytes)
class EIDirLight {
public:
    const char* GetTypeKey() const;
};

extern char gEIDirLightData[];

const char* EIDirLight::GetTypeKey() const {
    return *(const char**)(gEIDirLightData + 0);
}
