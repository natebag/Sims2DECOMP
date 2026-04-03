// 0x80226F40 (12 bytes)
class EIAmbLight {
public:
    short GetTypeVersion() const;
};

extern char gEIAmbLightData[];

short EIAmbLight::GetTypeVersion() const {
    return *(short*)(gEIAmbLightData + 0);
}
