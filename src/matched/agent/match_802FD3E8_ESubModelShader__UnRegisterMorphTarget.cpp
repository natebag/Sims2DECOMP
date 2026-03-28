class ESubModelShader {
public:
    char m_pad[56];
    int m_morphTargets[4];
    void UnRegisterMorphTarget(int index);
};
void ESubModelShader::UnRegisterMorphTarget(int index) {
    m_morphTargets[index] = 0;
}
