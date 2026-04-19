/* ENgcShader::ChangeMaterial(EMaterial&) at 0x8034DF80 (32B) */
// 0x8034DF80 (32 bytes)
class EMaterial;
class EShader {
public:
    void ChangeMaterial(EMaterial& mat);
};
class ENgcShader : public EShader {
public:
    void ChangeMaterial(EMaterial& mat);
};
void ENgcShader::ChangeMaterial(EMaterial& mat) {
    EShader::ChangeMaterial(mat);
}
