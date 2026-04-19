// 0x800A3B08 (32B) BString2::find_first_of(wchar_t, unsigned int) const
// Thunk to BString2::find(wchar_t, unsigned int) const

class BString2 {
public:
    void find_first_of(wchar_t a0, unsigned int a1) const;
    void find(wchar_t a0, unsigned int a1) const;
};

void BString2::find_first_of(wchar_t a0, unsigned int a1) const {
    find(a0, a1);
}
