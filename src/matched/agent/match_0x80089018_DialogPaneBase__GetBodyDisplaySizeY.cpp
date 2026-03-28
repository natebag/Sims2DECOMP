struct TextItem {
    char pad[0x30];
    float m_val;
};

struct DialogPaneBase {
    char pad[0x64];
    TextItem *m_bodyTextItem;

    float GetBodyDisplaySizeY(void);
};

float DialogPaneBase::GetBodyDisplaySizeY(void) {
    return m_bodyTextItem->m_val;
}
