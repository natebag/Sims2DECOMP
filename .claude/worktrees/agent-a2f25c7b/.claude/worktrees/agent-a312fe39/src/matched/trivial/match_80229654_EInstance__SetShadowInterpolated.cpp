// 0x80229654 (8 bytes)
class EInstance {
public:
    void SetShadowInterpolated(int p);
};

void EInstance::SetShadowInterpolated(int p) {
    *(int*)((char*)this + 0xC) = p;
}
