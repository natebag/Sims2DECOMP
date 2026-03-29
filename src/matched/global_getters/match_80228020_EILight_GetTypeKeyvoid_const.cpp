// 0x80228020 (12 bytes)
class EILight {
public:
    const char* GetTypeKey() const;
};

extern char gEILightData[];

const char* EILight::GetTypeKey() const {
    return *(const char**)(gEILightData + 0);
}
