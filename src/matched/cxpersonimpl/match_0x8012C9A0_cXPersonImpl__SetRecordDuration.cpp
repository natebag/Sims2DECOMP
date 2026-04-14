// 0x8012C9A0 cXPersonImpl::SetRecordDuration (8B)

struct cXPerson_SetRecordDuration {
    char pad[0x434];
    int m_val;
    void SetRecordDuration(int v);
};

void cXPerson_SetRecordDuration::SetRecordDuration(int v) {
    m_val = v;
}
