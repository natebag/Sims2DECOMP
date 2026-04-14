// 0x8012C778 cXPersonImpl::GetPersonDataArray (8B)

struct cXPerson_GetPersonDataArray {
    char pad[0x8];
    char m_arr[1];
    void* GetPersonDataArray();
};

void* cXPerson_GetPersonDataArray::GetPersonDataArray() {
    return &m_arr[0];
}
