// 0x8032084C (8 bytes)
class ERShader {
public:
    int GetCurrentGraphicsState();
};

int ERShader::GetCurrentGraphicsState() {
    return *(unsigned char*)((char*)this + 0x50);
}
