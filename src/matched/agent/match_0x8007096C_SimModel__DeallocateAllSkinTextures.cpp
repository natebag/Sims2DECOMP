// 0x8007096C SimModel::DeallocateAllSkinTextures(void) (100B)
// Pattern: 4-iteration loop freeing texture array elements with null check
extern char gSkinTexName[];
extern void FreeTexture(char* name, void* tex, int pad);

struct SimModel {
    char pad[320];
    void* m_textures[4];
    void DeallocateAllSkinTextures();
};

void SimModel::DeallocateAllSkinTextures() {
    void** tex = m_textures;
    unsigned int i = 0;
    do {
        void* t = *tex;
        i++;
        if (t != 0) {
            FreeTexture(gSkinTexName, t, 0);
            *tex = 0;
        }
        tex++;
    } while (i <= 3u);
}
