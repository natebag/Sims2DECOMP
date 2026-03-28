// 0x80365108 (8 bytes)
class ETexture {
public:
    int GetBitsPerPaletteEntry();
};

int ETexture::GetBitsPerPaletteEntry() {
    return *(unsigned char*)((char*)this + 0x1B);
}
