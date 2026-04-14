// 0x8012C9C8 cXPersonImpl::GetRecordTicksElapsed (8B)

struct cXPerson_GetRecordTicksElapsed {
    char pad[0x444];
    int m_val;
    int GetRecordTicksElapsed();
};

int cXPerson_GetRecordTicksElapsed::GetRecordTicksElapsed() {
    return m_val;
}
