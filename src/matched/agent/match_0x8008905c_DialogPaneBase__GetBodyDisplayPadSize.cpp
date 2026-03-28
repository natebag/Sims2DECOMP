struct EVec2 {
    float x, y;
};

struct TextItem {
    char pad[0x34];
    EVec2 m_displayPadSize;
};

struct DialogPaneBase {
    char pad2[0x64];
    TextItem *m_bodyTextItem;

    EVec2 *GetBodyDisplayPadSize(void);
};

EVec2 *DialogPaneBase::GetBodyDisplayPadSize(void) {
    return &m_bodyTextItem->m_displayPadSize;
}
