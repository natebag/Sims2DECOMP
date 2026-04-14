// 0x8012C9D0 cXPersonImpl::GetRecordSkill (8B)

struct cXPerson_GetRecordSkill {
    char pad[0x448];
    int m_val;
    int GetRecordSkill();
};

int cXPerson_GetRecordSkill::GetRecordSkill() {
    return m_val;
}
