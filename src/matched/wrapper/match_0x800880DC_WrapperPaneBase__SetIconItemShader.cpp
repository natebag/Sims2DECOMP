// 0x800880DC WrapperPaneBase::SetIconItemShader(int, unsigned int) (44B)
struct WrapperPaneBase {
    void SetItemShader(int type, int idx, unsigned int shader);
    void SetIconItemShader(int idx, unsigned int shader);
};
void WrapperPaneBase::SetIconItemShader(int idx, unsigned int shader) {
    SetItemShader(3, idx, shader);
}
