// 0x80349F44 (8 bytes)
class ENgcRenderer {
public:
    int GetNextExternalFrameBuffer();
};

int ENgcRenderer::GetNextExternalFrameBuffer() {
    return *(int*)((char*)this + 0x34C);
}
