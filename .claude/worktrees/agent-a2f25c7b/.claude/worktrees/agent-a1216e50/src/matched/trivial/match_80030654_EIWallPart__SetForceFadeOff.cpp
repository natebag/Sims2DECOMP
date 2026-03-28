// 0x80030654 (8 bytes)
class EIWallPart {
public:
    void SetForceFadeOff(int p);
};

void EIWallPart::SetForceFadeOff(int p) {
    *(int*)((char*)this + 0x3B0) = p;
}
