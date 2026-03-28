struct WrapperPaneBase {
    int m_paneId;

    int GetPaneId(void);
};

int WrapperPaneBase::GetPaneId(void) {
    return m_paneId;
}
