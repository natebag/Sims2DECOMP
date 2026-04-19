// 0x800A3C0C (32B) BString2::find_last_of(wchar_t, unsigned int) const
// Thunk to BString2::rfind(wchar_t, unsigned int) const

class BString2 {
public:
    void find_last_of(wchar_t a0, unsigned int a1) const;
    void rfind(wchar_t a0, unsigned int a1) const;
};

void BString2::find_last_of(wchar_t a0, unsigned int a1) const {
    rfind(a0, a1);
}
