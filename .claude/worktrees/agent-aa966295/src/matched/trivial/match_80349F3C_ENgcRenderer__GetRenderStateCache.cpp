// 0x80349F3C (8 bytes)
class ENgcRenderer {
public:
    int GetRenderStateCache();
};

int ENgcRenderer::GetRenderStateCache() {
    return *(int*)((char*)this + 0x4D8);
}
