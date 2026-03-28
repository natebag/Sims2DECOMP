/* BString::resize(unsigned int) - 0x8009EE58 (64 bytes) */

struct BString {
    char eos();
    void resize_fill(unsigned int, char);
    void resize(unsigned int newSize);
};

void BString::resize(unsigned int newSize)
{
    char c = eos();
    resize_fill(newSize, c);
}
