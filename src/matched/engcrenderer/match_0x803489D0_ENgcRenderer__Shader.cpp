// 0x803489D0 ENgcRenderer::Shader (40b)

struct EDLEntry {
    int pad;
    void* data;
};

extern void ShaderImpl(void*, void*, int);

void ENgcRenderer_Shader(void* self, EDLEntry* entry) {
    void* data = entry->data;
    ShaderImpl(self, data, -1);
}
