// 0x8022B83C (12 bytes)
class EISpotLight {
public:
    short GetTypeVersion() const;
};

extern char gEISpotLightData[];

short EISpotLight::GetTypeVersion() const {
    return *(short*)(gEISpotLightData + 0);
}
