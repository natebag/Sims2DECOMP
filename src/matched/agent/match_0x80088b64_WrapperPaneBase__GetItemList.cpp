struct WrapperPaneBase {
    char pad[0x08];
    int m_itemListStart;

    void *GetItemList(void);
};

void *WrapperPaneBase::GetItemList(void) {
    return &m_itemListStart;
}
