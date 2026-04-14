/* 0x800A3514 (64 bytes) - BString2::resize(unsigned int) */

typedef short wchar_t_sn;

class BString2 {
public:
    wchar_t_sn eos(void);
    void resize(unsigned int n, wchar_t_sn c);
    void resize(unsigned int n);
};

void BString2::resize(unsigned int n)
{
    resize(n, eos());
}
