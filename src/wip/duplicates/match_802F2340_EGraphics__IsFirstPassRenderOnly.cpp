// 0x802F2340 (8 bytes)
class EGraphics {
public:
    int IsFirstPassRenderOnly();
};

int EGraphics::IsFirstPassRenderOnly() {
    return *(int*)((char*)this + 0x31C);
}
