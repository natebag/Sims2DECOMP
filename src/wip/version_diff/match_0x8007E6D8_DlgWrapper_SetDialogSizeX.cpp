// 0x8007E6D8 DlgWrapper::SetDialogSizeX (64b)
// FLAGS: -fno-schedule-insns

struct TextBlock {
    char pad[0x0C];
    int m_sizeX_bits;
    int m_sizeY_bits;
    void SetDirty();
};

struct TextBlockContainer {
    char pad[0x20];
    TextBlock m_textBlock;
};

struct InnerObj {
    char pad[0x64];
    TextBlockContainer* m_container;
};

struct DlgWrapper {
    char pad[0xAC];
    InnerObj* m_inner;
    char pad2[0x14];
    float m_sizeX;
    float m_sizeY;
    void SetDialogSizeX(float size);
};

void DlgWrapper::SetDialogSizeX(float size) {
    m_sizeX = size;
    TextBlockContainer* container = m_inner->m_container;
    container->m_textBlock.m_sizeY_bits = *(int*)&m_sizeY;
    container->m_textBlock.m_sizeX_bits = *(int*)&m_sizeX;
    container->m_textBlock.SetDirty();
}
