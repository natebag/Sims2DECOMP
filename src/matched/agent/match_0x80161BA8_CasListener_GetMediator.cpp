// 0x80161BA8 (8B) CasListener::GetMediator(void) const
// Getter for field at offset 0x0.

class CasListener {
public:
    int m_field_0;
    int GetMediator(void) const;
};

int CasListener::GetMediator(void) const {
    return m_field_0;
}
