// 0x80365118 (8 bytes)
class ETexture {
public:
    int GetFlags();
};

int ETexture::GetFlags() {
    return *(int*)((char*)this + 0x8);
}
