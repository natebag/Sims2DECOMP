// 0x8004E618 ISimsObjectModel::ChageShader(unsigned int, unsigned int) (136B)

struct ISimsObjectModel {
    char pad[288];
    int m_f288;
    char pad2[760];
    void* m_tex;  // offset 1052
    void ChageShader(unsigned int guid1, unsigned int guid2);
};

extern char g_shaderName[32];

extern "C" void IS_FreeTex(void* p);                                                // 0x80311f70
extern "C" void* IS_LoadTex(const char* name, unsigned int guid, int a, int b);     // 0x80326cf8
extern "C" void IS_ApplyShader(ISimsObjectModel* self, unsigned int g1, unsigned int g2);  // 0x8022d150

void ISimsObjectModel::ChageShader(unsigned int guid1, unsigned int guid2) {
    if (m_f288 == 0) return;
    void* tex = m_tex;
    if (tex != 0) {
        IS_FreeTex(tex);
        m_tex = 0;
    }
    if (guid2 == 0) return;
    m_tex = IS_LoadTex(g_shaderName, guid2, 0, 0);
    IS_ApplyShader(this, guid1, guid2);
}
