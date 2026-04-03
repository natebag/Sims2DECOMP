struct EMaterial { int data[4]; };
class EShader {
public:
    char m_pad[16];
    EMaterial m_material;
    EMaterial *GetMaterial() const;
};
EMaterial *EShader::GetMaterial() const { return (EMaterial *)&m_material; }
