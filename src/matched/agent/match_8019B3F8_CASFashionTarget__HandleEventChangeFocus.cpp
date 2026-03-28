class CasEventChangeFocus {
public:
    char _pad[0x14];
    int m_focusId;
};

class CASFashionTarget {
public:
    char _pad[0x8C];
    int m_currentFocus;

    void HandleEventChangeFocus(CasEventChangeFocus &event);
};

void CASFashionTarget::HandleEventChangeFocus(CasEventChangeFocus &event) {
    m_currentFocus = event.m_focusId;
}
