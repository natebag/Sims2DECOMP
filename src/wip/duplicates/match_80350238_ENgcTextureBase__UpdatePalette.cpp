// 0x80350238 (8 bytes)
class ENgcTextureBase {
public:
    int UpdatePalette();
};

int ENgcTextureBase::UpdatePalette() {
    return *(int*)((char*)this + 0x90);
}
