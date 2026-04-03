// 0x8034FA70 (8 bytes)
class ENgcTexture {
public:
    int GetGXTexFmt();
};

int ENgcTexture::GetGXTexFmt() {
    return *(int*)((char*)(*(int*)((char*)this + 0x28)) + 0x70);
}
