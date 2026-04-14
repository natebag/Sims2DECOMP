// 0x8012C980 cXPersonImpl::GetMotives (8B)

struct cXPerson_GetMotives {
    char pad[0xA8];
    char m_arr[1];
    void* GetMotives();
};

void* cXPerson_GetMotives::GetMotives() {
    return &m_arr[0];
}
