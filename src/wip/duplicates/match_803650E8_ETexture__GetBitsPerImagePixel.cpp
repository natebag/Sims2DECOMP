// 0x803650E8 (8 bytes)
class ETexture {
public:
    int GetBitsPerImagePixel();
};

int ETexture::GetBitsPerImagePixel() {
    return *(unsigned char*)((char*)this + 0x1A);
}
