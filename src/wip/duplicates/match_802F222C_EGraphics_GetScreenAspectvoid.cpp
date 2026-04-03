// 0x802F222C (12 bytes)
class EGraphics {
public:
    float GetScreenAspect();
};

extern char gEGraphicsData[];

float EGraphics::GetScreenAspect() {
    return *(float*)(gEGraphicsData + 0);
}
