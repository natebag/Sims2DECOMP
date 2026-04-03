// 0x802F2348 (8 bytes)
class EGraphics {
public:
    void SetEnableFrameEffects(int p);
};

void EGraphics::SetEnableFrameEffects(int p) {
    *(int*)((char*)this + 0x320) = p;
}
