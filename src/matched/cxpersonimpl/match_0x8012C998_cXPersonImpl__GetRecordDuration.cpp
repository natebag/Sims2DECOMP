// 0x8012C998 cXPersonImpl::GetRecordDuration (8B)

struct cXPerson_GetRecordDuration {
    char pad[0x434];
    int m_val;
    int GetRecordDuration();
};

int cXPerson_GetRecordDuration::GetRecordDuration() {
    return m_val;
}
