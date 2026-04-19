// 0x8009F480 (32B) BString::find_last_of(char, unsigned int) const
// Thunk to BString::rfind(char, unsigned int) const

class BString {
public:
    void find_last_of(char a0, unsigned int a1) const;
    void rfind(char a0, unsigned int a1) const;
};

void BString::find_last_of(char a0, unsigned int a1) const {
    rfind(a0, a1);
}
