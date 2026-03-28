// 0x8016FB64 (8 bytes)
class CasSimRenderer {
public:
    void SetSimRotation(float p);
};

void CasSimRenderer::SetSimRotation(float p) {
    *(float*)((char*)this + 0x20C) = p;
}
