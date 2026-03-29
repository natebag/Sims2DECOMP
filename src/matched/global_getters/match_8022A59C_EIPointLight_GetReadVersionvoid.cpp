// 0x8022A59C (12 bytes)
class EIPointLight {
public:
    short GetReadVersion() const;
};

extern char gEIPointLightData[];

short EIPointLight::GetReadVersion() const {
    return *(short*)(gEIPointLightData + 0);
}
