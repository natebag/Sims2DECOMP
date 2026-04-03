// 0x803650E0 (8 bytes)
class ETexture {
public:
    int GetImageFormat();
};

int ETexture::GetImageFormat() {
    return *(unsigned char*)((char*)this + 0x18);
}
