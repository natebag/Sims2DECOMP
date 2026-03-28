struct BString2 {
    unsigned int length(void);
    void resize_impl(unsigned int newSize, unsigned int curSize);
    void resize(unsigned int newSize);
};

void BString2::resize(unsigned int newSize) {
    unsigned int cur = length();
    resize_impl(newSize, cur);
}
