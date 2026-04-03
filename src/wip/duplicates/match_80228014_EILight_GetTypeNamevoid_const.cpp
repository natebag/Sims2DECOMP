// 0x80228014 (12 bytes)
class EILight {
public:
    const char* GetTypeName() const;
};

extern char gEILightData[];

const char* EILight::GetTypeName() const {
    return *(const char**)(gEILightData + 0);
}
