/* BString2::resize(unsigned int) - 0x800A3514 (64 bytes) */

typedef unsigned short wchar_t_u;

struct BString2 {
    wchar_t_u eos();
    void resize_fill(unsigned int, wchar_t_u);
    void resize(unsigned int newSize);
};

void BString2::resize(unsigned int newSize)
{
    wchar_t_u c = eos();
    resize_fill(newSize, c);
}
