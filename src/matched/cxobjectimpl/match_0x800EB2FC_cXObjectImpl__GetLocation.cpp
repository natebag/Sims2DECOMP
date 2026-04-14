// 0x800EB2FC cXObjectImpl::GetLocation (8B)

struct cXObj_GetLocation {
    char pad[0x68];
    char m_arr[1];
    void* GetLocation();
};

void* cXObj_GetLocation::GetLocation() {
    return &m_arr[0];
}
