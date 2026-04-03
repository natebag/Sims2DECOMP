// 0x8016FB5C (8 bytes)
class CasSimRenderer {
public:
    void SetPositionNum(int p);
};

void CasSimRenderer::SetPositionNum(int p) {
    *(int*)((char*)this + 0x214) = p;
}
