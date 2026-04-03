// 0x8036AD88 (8 bytes)
class REffectsEmitter {
public:
    int GetTexture();
};

int REffectsEmitter::GetTexture() {
    return *(int*)((char*)this + 0x1C);
}
