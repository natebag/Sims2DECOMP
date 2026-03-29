// 0x80226F58 (12 bytes)
class EIAmbLight {
public:
    short GetReadVersion() const;
};

extern char gEIAmbLightData[];

short EIAmbLight::GetReadVersion() const {
    return *(short*)(gEIAmbLightData + 0);
}
