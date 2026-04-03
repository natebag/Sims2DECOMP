// 0x8016FB6C (8 bytes)
class CasSimRenderer {
public:
    int GetSimModel();
};

int CasSimRenderer::GetSimModel() {
    return (int)((char*)this + 0x8);
}
