// 0x802F2204 (12 bytes)
class EGraphics {
public:
    float GetFarZVal();
};

// Force the lis + lfs pattern by using a base+offset
extern char gGraphicsData[0xF094];

float EGraphics::GetFarZVal() {
    return *(float*)(gGraphicsData + 0xF094);
}
