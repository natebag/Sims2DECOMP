// 0x802FAB74 (8 bytes)
class EShader {
public:
    int GetShaderUpdate();
};

int EShader::GetShaderUpdate() {
    return *(int*)((char*)this + 0xE8);
}
