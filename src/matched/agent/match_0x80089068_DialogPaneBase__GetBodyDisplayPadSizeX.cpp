struct TextItem {
    char pad[0x34];
    float m_val;
};

struct DialogPaneBase {
    char pad[0x64];
    TextItem *m_bodyTextItem;

    float GetBodyDisplayPadSizeX(void);
};

float DialogPaneBase::GetBodyDisplayPadSizeX(void) {
    return m_bodyTextItem->m_val;
}
