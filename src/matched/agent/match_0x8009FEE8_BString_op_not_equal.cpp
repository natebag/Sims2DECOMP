// 0x8009FEE8 (56B) BString::operator!=(BString &) const

struct BString {
    int compare(BString& other, int start, int len) const;
    bool operator!=(BString& other) const;
};

bool BString::operator!=(BString& other) const {
    if (compare(other, 0, -1) != 0) return 1;
    return 0;
}
