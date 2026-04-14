// 0x8012C9A8 cXPersonImpl::GetRecordMaxDuration (8B)

struct cXPerson_GetRecordMaxDuration {
    char pad[0x438];
    int m_val;
    int GetRecordMaxDuration();
};

int cXPerson_GetRecordMaxDuration::GetRecordMaxDuration() {
    return m_val;
}
