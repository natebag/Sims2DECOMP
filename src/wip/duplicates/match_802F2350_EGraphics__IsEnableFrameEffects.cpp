// 0x802F2350 (8 bytes)
class EGraphics {
public:
    int IsEnableFrameEffects();
};

int EGraphics::IsEnableFrameEffects() {
    return *(int*)((char*)this + 0x320);
}
