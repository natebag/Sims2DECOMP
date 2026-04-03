// 0x802F21B8 (8 bytes)
class EGraphics {
public:
    int FrameBufferClearRequestFlag();
};

int EGraphics::FrameBufferClearRequestFlag() {
    return *(int*)((char*)this + 0x10);
}
