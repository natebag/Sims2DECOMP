// 0x80227454 (12 bytes)
class EIDirLight {
public:
    short GetReadVersion() const;
};

extern char gEIDirLightData[];

short EIDirLight::GetReadVersion() const {
    return *(short*)(gEIDirLightData + 0);
}
