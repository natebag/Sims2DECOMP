// 0x802FAAEC (8 bytes)
class EShader {
public:
    int GetSurfaceProperties();
};

int EShader::GetSurfaceProperties() {
    return *(int*)((char*)this + 0x4);
}
