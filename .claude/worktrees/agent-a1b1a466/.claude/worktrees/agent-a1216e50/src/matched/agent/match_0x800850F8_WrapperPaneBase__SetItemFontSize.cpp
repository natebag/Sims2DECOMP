/* 0x800850F8 (80 bytes) - WrapperPaneBase::SetItemFontSize(ItemType, int, float) */

typedef int ItemType;

class TextBlock {
public:
    char _pad_0[0x34];
    float m_fontSize;
    void SetDirty(void);
};

class TextBaseItem {
public:
    char _pad_0[4];
    unsigned int m_flags;
    char _pad_8[0x18];
    TextBlock m_textBlock;
};

class WrapperPaneBase {
public:
    TextBaseItem *GetItem(ItemType type, int index);
    void SetItemFontSize(ItemType type, int index, float size);
};

void WrapperPaneBase::SetItemFontSize(ItemType type, int index, float size)
{
    TextBaseItem *item = GetItem(type, index);
    TextBlock *tb = &item->m_textBlock;
    tb->m_fontSize = size;
    tb->SetDirty();
    item->m_flags |= 0x02;
}
