// 0x8022A584 (12 bytes)
class EIPointLight {
public:
    short GetTypeVersion() const;
};

extern char gEIPointLightData[];

short EIPointLight::GetTypeVersion() const {
    return *(short*)(gEIPointLightData + 0);
}
