// 0x800EB3EC cXObjectImpl::GetRelMatrix (8B)

struct cXObj_GetRelMatrix {
    char pad[0x60];
    int m_val;
    int GetRelMatrix();
};

int cXObj_GetRelMatrix::GetRelMatrix() {
    return m_val;
}
