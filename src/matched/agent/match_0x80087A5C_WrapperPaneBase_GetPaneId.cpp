// 0x80087A5C (8B) WrapperPaneBase::GetPaneId(void)
// Getter for field at offset 0x0.

class WrapperPaneBase {
public:
    int m_field_0;
    int GetPaneId(void);
};

int WrapperPaneBase::GetPaneId(void) {
    return m_field_0;
}
