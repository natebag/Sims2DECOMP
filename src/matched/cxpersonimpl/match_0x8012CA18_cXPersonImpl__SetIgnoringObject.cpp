// 0x8012CA18 cXPersonImpl::SetIgnoringObject (8B)

struct cXPerson_SetIgnoringObject {
    char pad[0x53C];
    int m_val;
    void SetIgnoringObject(int v);
};

void cXPerson_SetIgnoringObject::SetIgnoringObject(int v) {
    m_val = v;
}
