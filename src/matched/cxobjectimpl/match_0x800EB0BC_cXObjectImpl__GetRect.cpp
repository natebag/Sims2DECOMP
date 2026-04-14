// 0x800EB0BC cXObjectImpl::GetRect (8B)

struct cXObj_GetRect {
    char pad[0x70];
    char m_arr[1];
    void* GetRect();
};

void* cXObj_GetRect::GetRect() {
    return &m_arr[0];
}
