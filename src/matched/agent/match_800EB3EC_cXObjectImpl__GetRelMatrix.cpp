/* cXObjectImpl::GetRelMatrix(void) - 8 bytes */

class cXObjectImpl {
public:
    char pad[0x60];
    void* m_relMatrix;

    void* GetRelMatrix(void);
};

void* cXObjectImpl::GetRelMatrix(void) {
    return m_relMatrix;
}
