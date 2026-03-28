/* cXObjectImpl::GetLevel(void) const - 8 bytes */

class cXObjectImpl {
public:
    char pad[0x80];
    int m_level;

    int GetLevel(void) const;
};

int cXObjectImpl::GetLevel(void) const {
    return m_level;
}
