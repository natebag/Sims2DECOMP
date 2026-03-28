struct TextItem {
    char pad[0x2C];
    float m_val;
};

struct DialogPaneBase {
    char pad[0x64];
    TextItem *m_bodyTextItem;

    float GetBodyDisplaySizeX(void);
};

float DialogPaneBase::GetBodyDisplaySizeX(void) {
    return m_bodyTextItem->m_val;
}
