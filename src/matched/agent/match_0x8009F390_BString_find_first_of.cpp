// 0x8009F390 (32B) BString::find_first_of(char, unsigned int) const
// Thunk to BString::find(char, unsigned int) const

class BString {
public:
    void find_first_of(char a0, unsigned int a1) const;
    void find(char a0, unsigned int a1) const;
};

void BString::find_first_of(char a0, unsigned int a1) const {
    find(a0, a1);
}
