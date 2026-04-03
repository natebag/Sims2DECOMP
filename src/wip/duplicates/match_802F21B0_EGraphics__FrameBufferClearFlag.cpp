// 0x802F21B0 (8 bytes)
class EGraphics {
public:
    int FrameBufferClearFlag();
};

int EGraphics::FrameBufferClearFlag() {
    return *(int*)((char*)this + 0xC);
}
