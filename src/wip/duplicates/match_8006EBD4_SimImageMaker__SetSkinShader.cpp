// 0x8006EBD4 (8 bytes)
class SimImageMaker {
public:
    void SetSkinShader(int p);
};

void SimImageMaker::SetSkinShader(int p) {
    *(int*)((char*)this + 0x8C) = p;
}
