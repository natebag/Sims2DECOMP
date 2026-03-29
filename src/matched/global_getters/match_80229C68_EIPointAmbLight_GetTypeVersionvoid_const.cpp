// 0x80229C68 (12 bytes)
class EIPointAmbLight {
public:
    short GetTypeVersion() const;
};

extern char gEIPointAmbLightData[];

short EIPointAmbLight::GetTypeVersion() const {
    return *(short*)(gEIPointAmbLightData + 0);
}
