struct TextItem;

struct DialogPaneBase {
    char pad[0x60];
    TextItem *m_titleTextItem;

    TextItem *GetTitleTextItem(void);
};

TextItem *DialogPaneBase::GetTitleTextItem(void) {
    return m_titleTextItem;
}
