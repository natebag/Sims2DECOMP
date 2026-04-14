// 0x800EAF38 cXObjectImpl::GetFolder (12B)

struct Inner_GetFolder {
    char pad[0x50];
    int m_val;
};

struct cXObj_GetFolder {
    char pad[0x8C];
    Inner_GetFolder* m_inner;
    int GetFolder();
};

int cXObj_GetFolder::GetFolder() {
    return m_inner->m_val;
}
