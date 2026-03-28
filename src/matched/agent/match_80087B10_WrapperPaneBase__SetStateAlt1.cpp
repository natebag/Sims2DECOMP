// 0x80087B10 (12 bytes)
class WrapperPaneBase {
public:
    char pad[52];
    int m_state;

    void SetStateAlt1(void);
};

void WrapperPaneBase::SetStateAlt1(void) {
    m_state = 3;
}
