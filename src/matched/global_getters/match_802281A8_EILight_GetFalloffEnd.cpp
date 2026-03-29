// 0x802281A8 (12 bytes)
class EILight {
public:
    float GetFalloffEnd();
};

// Force the lis + lfs pattern
extern char gLightData[0xE684];

float EILight::GetFalloffEnd() {
    return *(float*)(gLightData + 0xE684);
}
