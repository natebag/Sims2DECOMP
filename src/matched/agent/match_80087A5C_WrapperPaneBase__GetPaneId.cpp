// 0x80087A5C (8 bytes)
class WrapperPaneBase {
public:
    int m_paneId;

    int GetPaneId(void);
};

int WrapperPaneBase::GetPaneId(void) {
    return m_paneId;
}
