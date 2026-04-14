// 0x8012C7E4 cXPersonImpl::GetDestList (8B)

struct cXPerson_GetDestList {
    char pad[0x3F8];
    char m_arr[1];
    void* GetDestList();
};

void* cXPerson_GetDestList::GetDestList() {
    return &m_arr[0];
}
