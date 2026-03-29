// 0x80229C5C (12 bytes)
class EIPointAmbLight {
public:
    const char* GetTypeKey() const;
};

extern char gEIPointAmbLightData[];

const char* EIPointAmbLight::GetTypeKey() const {
    return *(const char**)(gEIPointAmbLightData + 0);
}
