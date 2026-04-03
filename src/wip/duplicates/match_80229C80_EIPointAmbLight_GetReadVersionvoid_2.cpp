// 0x80229C80 (12 bytes)
class EIPointAmbLight {
public:
    short GetReadVersion() const;
};

extern char gEIPointAmbLightData[];

short EIPointAmbLight::GetReadVersion() const {
    return *(short*)(gEIPointAmbLightData + 0);
}
