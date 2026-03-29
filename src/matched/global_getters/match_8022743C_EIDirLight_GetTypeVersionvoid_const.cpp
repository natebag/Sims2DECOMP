// 0x8022743C (12 bytes)
class EIDirLight {
public:
    short GetTypeVersion() const;
};

extern char gEIDirLightData[];

short EIDirLight::GetTypeVersion() const {
    return *(short*)(gEIDirLightData + 0);
}
