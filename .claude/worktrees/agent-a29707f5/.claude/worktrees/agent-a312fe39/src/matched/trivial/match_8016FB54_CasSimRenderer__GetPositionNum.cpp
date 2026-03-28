// 0x8016FB54 (8 bytes)
class CasSimRenderer {
public:
    int GetPositionNum();
};

int CasSimRenderer::GetPositionNum() {
    return *(int*)((char*)this + 0x214);
}
