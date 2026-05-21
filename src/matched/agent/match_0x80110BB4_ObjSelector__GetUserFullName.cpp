// 0x80110BB4 ObjSelector::GetUserFullName(BString2 &) (108B)

class BString2 {
public:
    BString2& operator=(BString2& other);
    BString2& append(unsigned short* s);
    unsigned short* c_str() const;
};

class ObjSelector {
public:
    char _pad0[136];
    BString2* m_userLastName;

    BString2* GetUserName();
    void GetUserFullName(BString2& result);
};

extern unsigned short g_space_string[];

void ObjSelector::GetUserFullName(BString2& result) {
    result = *GetUserName();
    if (m_userLastName != 0) {
        result.append(g_space_string);
        result.append(m_userLastName->c_str());
    }
}
