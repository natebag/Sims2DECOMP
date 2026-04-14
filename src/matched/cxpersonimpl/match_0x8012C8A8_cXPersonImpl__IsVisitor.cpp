// 0x8012C8A8 cXPersonImpl::IsVisitor (24B)

struct cXPerson_IsVisitor {
    char pad[0x48];
    short m_val;
    int IsVisitor();
};

int cXPerson_IsVisitor::IsVisitor() {
    short v = m_val;
    int result = 1;
    if (v == 0) result = 0;
    return result;
}
