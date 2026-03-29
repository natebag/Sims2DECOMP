// 0x802F2210 (12 bytes)
class EGraphics {
public:
    float GetNearZVal();
};

extern char gEGraphicsData[];

float EGraphics::GetNearZVal() {
    return *(float*)(gEGraphicsData + 0);
}
