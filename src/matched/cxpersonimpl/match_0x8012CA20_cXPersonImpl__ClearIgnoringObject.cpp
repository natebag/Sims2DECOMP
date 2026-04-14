// 0x8012CA20 cXPersonImpl::ClearIgnoringObject (12B)

struct cXPerson_CIO {
    char pad[0x53C];
    void* m_val;
    void ClearIgnoringObject();
};

void cXPerson_CIO::ClearIgnoringObject() {
    m_val = 0;
}
