/* cXObjectImpl::SetLevel(int) - 8 bytes */

class cXObjectImpl {
public:
    char pad[0x80];
    int m_level;

    void SetLevel(int level);
};

void cXObjectImpl::SetLevel(int level) {
    m_level = level;
}
