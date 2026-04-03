// 0x80349FD4 (8 bytes)
class ENgcRenderer {
public:
    int GetFrameEffectsScratchMemory();
};

int ENgcRenderer::GetFrameEffectsScratchMemory() {
    return *(int*)((char*)this + 0x464C);
}
