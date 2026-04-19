// 0x8009F4F8 (32B) BString::find_first_not_of(char *, unsigned int, unsigned int) const
// Thunk to BString::find_first_not_of_str(char *, unsigned int, unsigned int) const

class BString {
public:
    void find_first_not_of(char * a0, unsigned int a1, unsigned int a2) const;
    void find_first_not_of_str(char * a0, unsigned int a1, unsigned int a2) const;
};

void BString::find_first_not_of(char * a0, unsigned int a1, unsigned int a2) const {
    find_first_not_of_str(a0, a1, a2);
}
