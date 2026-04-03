// 0x8001EA74 (8 bytes)
class ESimsCam {
public:
    float GetZoom();
};

float ESimsCam::GetZoom() {
    return *(float*)((char*)this + 0x448);
}
