// 0x80172C20 (8 bytes)
class CasSimRendererDynamic {
public:
    void LockSimRotation(int p);
};

void CasSimRendererDynamic::LockSimRotation(int p) {
    *(int*)((char*)this + 0x21C) = p;
}
