struct TextItem;

struct DialogPaneBase {
    char pad[0x64];
    TextItem *m_bodyTextItem;

    TextItem *GetBodyTextItem(void);
};

TextItem *DialogPaneBase::GetBodyTextItem(void) {
    return m_bodyTextItem;
}
