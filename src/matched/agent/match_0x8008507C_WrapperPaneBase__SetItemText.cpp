// 0x8008507C WrapperPaneBase::SetItemText(ItemType, int, unsigned wchar_t*) (52B)
struct TextItem {};
extern void SetTextHelper(TextItem* item, unsigned short* text);

struct WrapperPaneBase {
    TextItem* GetItem(int type, int idx);
    void SetItemText(int type, int idx, unsigned short* text);
};

void WrapperPaneBase::SetItemText(int type, int idx, unsigned short* text) {
    TextItem* item = GetItem(type, idx);
    SetTextHelper(item, text);
}
