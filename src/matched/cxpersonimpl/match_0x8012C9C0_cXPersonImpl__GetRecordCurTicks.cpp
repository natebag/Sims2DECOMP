// 0x8012C9C0 cXPersonImpl::GetRecordCurTicks (8B)

struct cXPerson_GetRecordCurTicks {
    char pad[0x43C];
    int m_val;
    int GetRecordCurTicks();
};

int cXPerson_GetRecordCurTicks::GetRecordCurTicks() {
    return m_val;
}
