// 0x800B67D4 (56B) FamilyImpl::SetName(StringBuffer2 *)

struct BString2 {
    void assign(unsigned short*);
};

struct StringBuffer2 {
    unsigned short* c_str() const;
};

struct FamilyImpl {
    char pad[4];
    BString2 m_name;

    void SetName(StringBuffer2* buf);
};

void FamilyImpl::SetName(StringBuffer2* buf) {
    m_name.assign(buf->c_str());
}
