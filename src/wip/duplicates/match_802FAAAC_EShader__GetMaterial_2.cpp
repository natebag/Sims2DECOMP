// 0x802FAAAC (8 bytes)
class EShader {
public:
    int GetMaterial();
};

int EShader::GetMaterial() {
    return (int)((char*)this + 0x10);
}
