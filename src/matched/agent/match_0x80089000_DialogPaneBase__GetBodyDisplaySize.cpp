struct EVec2 {
    float x, y;
};

struct TextItem {
    char pad[0x2C];
    EVec2 m_displaySize;
};

struct DialogPaneBase {
    char pad2[0x64];
    TextItem *m_bodyTextItem;

    EVec2 *GetBodyDisplaySize(void);
};

EVec2 *DialogPaneBase::GetBodyDisplaySize(void) {
    return &m_bodyTextItem->m_displaySize;
}
