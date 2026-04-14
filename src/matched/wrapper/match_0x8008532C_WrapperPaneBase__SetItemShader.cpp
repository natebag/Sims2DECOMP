// 0x8008532C WrapperPaneBase::SetItemShader(ItemType, int, unsigned int) (64B)
struct IconItem {
    void ReleaseShader();
    void SetShader(unsigned int shader);
};

struct WrapperPaneBase {
    IconItem* GetItem(int type, int idx);
    void SetItemShader(int type, int idx, unsigned int shader);
};

void WrapperPaneBase::SetItemShader(int type, int idx, unsigned int shader) {
    IconItem* item = GetItem(type, idx);
    item->ReleaseShader();
    item->SetShader(shader);
}
