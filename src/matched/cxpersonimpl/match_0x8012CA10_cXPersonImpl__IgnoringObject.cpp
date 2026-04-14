// 0x8012CA10 cXPersonImpl::IgnoringObject (8B)

struct cXPerson_IgnoringObject {
    char pad[0x53C];
    int m_val;
    int IgnoringObject();
};

int cXPerson_IgnoringObject::IgnoringObject() {
    return m_val;
}
