// 0x80229C50 (12 bytes)
class EIPointAmbLight {
public:
    const char* GetTypeName() const;
};

extern char gEIPointAmbLightData[];

const char* EIPointAmbLight::GetTypeName() const {
    return *(const char**)(gEIPointAmbLightData + 0);
}
