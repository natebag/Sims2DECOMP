/* 0x800850B0 (72 bytes) - WrapperPaneBase::SetItemFont(ItemType, int, ERFont *) */

typedef int ItemType;

class TextBlock {
public:
    char _pad_0[0x30];
    void *m_font;
    void SetDirty(void);
};

class ERFont;

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
    void SetItemFont(ItemType type, int index, ERFont *font);
};

void WrapperPaneBase::SetItemFont(ItemType type, int index, ERFont *font)
{
    TextBaseItem *item = GetItem(type, index);
    TextBlock *tb = &item->m_textBlock;
    tb->m_font = font;
    tb->SetDirty();
    item->m_flags |= 0x02;
}
