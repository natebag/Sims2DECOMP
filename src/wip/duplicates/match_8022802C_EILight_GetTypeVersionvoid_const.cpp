// 0x8022802C (12 bytes)
class EILight {
public:
    short GetTypeVersion() const;
};

extern char gEILightData[];

short EILight::GetTypeVersion() const {
    return *(short*)(gEILightData + 0);
}
