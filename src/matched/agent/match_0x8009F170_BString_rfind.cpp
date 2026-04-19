// 0x8009F170 (32B) BString::rfind(char *, unsigned int, unsigned int) const
// Thunk to BString::rfind_str(char *, unsigned int, unsigned int) const

class BString {
public:
    void rfind(char * a0, unsigned int a1, unsigned int a2) const;
    void rfind_str(char * a0, unsigned int a1, unsigned int a2) const;
};

void BString::rfind(char * a0, unsigned int a1, unsigned int a2) const {
    rfind_str(a0, a1, a2);
}
