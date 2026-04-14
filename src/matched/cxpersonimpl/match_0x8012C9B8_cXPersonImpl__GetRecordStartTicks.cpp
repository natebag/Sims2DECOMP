// 0x8012C9B8 cXPersonImpl::GetRecordStartTicks (8B)

struct cXPerson_GetRecordStartTicks {
    char pad[0x440];
    int m_val;
    int GetRecordStartTicks();
};

int cXPerson_GetRecordStartTicks::GetRecordStartTicks() {
    return m_val;
}
