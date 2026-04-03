// 0x8022B854 (12 bytes)
class EISpotLight {
public:
    short GetReadVersion() const;
};

extern char gEISpotLightData[];

short EISpotLight::GetReadVersion() const {
    return *(short*)(gEISpotLightData + 0);
}
