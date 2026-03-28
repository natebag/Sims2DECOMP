/* cXObjectImpl::GetDef(void) - 8 bytes */

class cXObjectImpl {
public:
    char pad[0x88];
    void* m_def;

    void* GetDef(void);
};

void* cXObjectImpl::GetDef(void) {
    return m_def;
}
