// 0x800B63D8 (60B) FamilyImpl::GetName(StringBuffer2 *)

struct BString2 {
    unsigned short* c_str() const;
};

struct StringBuffer2 {
    void copy(unsigned short*);
};

struct FamilyImpl {
    char pad[4];
    BString2 m_name;   // offset 4

    void GetName(StringBuffer2* buf);
};

void FamilyImpl::GetName(StringBuffer2* buf) {
    buf->copy(m_name.c_str());
}
