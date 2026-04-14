// 0x800EAA68 cXObjectImpl::GetMiscFlag (24B)

struct cXObj_GMF {
    char pad[0x84];
    int m_flags;
    int GetMiscFlag(int flag);
};

int cXObj_GMF::GetMiscFlag(int flag) {
    int result = 1;
    if ((m_flags & flag) == 0) result = 0;
    return result;
}
