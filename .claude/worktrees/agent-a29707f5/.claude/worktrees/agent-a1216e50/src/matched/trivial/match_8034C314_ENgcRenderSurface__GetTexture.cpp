// 0x8034C314 (8 bytes)
class ENgcRenderSurface {
public:
    int GetTexture();
};

int ENgcRenderSurface::GetTexture() {
    return *(int*)((char*)this + 0x28);
}
