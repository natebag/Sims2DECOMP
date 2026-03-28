/* cXObjectImpl::GetID(void) - 8 bytes */

class cXObjectImpl {
public:
    char pad[0x64];
    short m_id;

    short GetID(void);
};

short cXObjectImpl::GetID(void) {
    return m_id;
}
