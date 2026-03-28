// 0x80365100 (8 bytes)
class ETexture {
public:
    int GetPaletteFormat();
};

int ETexture::GetPaletteFormat() {
    return *(unsigned char*)((char*)this + 0x19);
}
