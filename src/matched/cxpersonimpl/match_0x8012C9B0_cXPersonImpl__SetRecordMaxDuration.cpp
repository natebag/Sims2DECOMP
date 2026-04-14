// 0x8012C9B0 cXPersonImpl::SetRecordMaxDuration (8B)

struct cXPerson_SetRecordMaxDuration {
    char pad[0x438];
    int m_val;
    void SetRecordMaxDuration(int v);
};

void cXPerson_SetRecordMaxDuration::SetRecordMaxDuration(int v) {
    m_val = v;
}
