// 0x8009F018 (32B) BString::find(char *, unsigned int, unsigned int) const
// Thunk to BString::find_str(char *, unsigned int, unsigned int) const

class BString {
public:
    void find(char * a0, unsigned int a1, unsigned int a2) const;
    void find_str(char * a0, unsigned int a1, unsigned int a2) const;
};

void BString::find(char * a0, unsigned int a1, unsigned int a2) const {
    find_str(a0, a1, a2);
}
