struct TextItem {
    char pad[0x38];
    float m_val;
};

struct DialogPaneBase {
    char pad[0x64];
    TextItem *m_bodyTextItem;

    float GetBodyDisplayPadSizeY(void);
};

float DialogPaneBase::GetBodyDisplayPadSizeY(void) {
    return m_bodyTextItem->m_val;
}
