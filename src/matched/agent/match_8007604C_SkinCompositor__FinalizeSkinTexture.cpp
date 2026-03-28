typedef unsigned char u8;

void TextureUtils_CopyTexture32To8(void*, void*);
void TextureUtils_CopyTexture32To32(void*, void*);

void SkinCompositor_FinalizeSkinTexture(u8* pThis) {
    int flag = *(int*)(pThis + 0x04);
    if (flag != 0) {
        u8* pObj = *(u8**)(pThis + 0x18);
        void* tex = *(void**)(pThis + 0x08);
        void* dest = *(void**)(pObj + 0x14);
        TextureUtils_CopyTexture32To8(tex, dest);
    } else {
        u8* pObj = *(u8**)(pThis + 0x18);
        void* tex = *(void**)(pThis + 0x08);
        void* dest = *(void**)(pObj + 0x14);
        TextureUtils_CopyTexture32To32(tex, dest);
    }
}
