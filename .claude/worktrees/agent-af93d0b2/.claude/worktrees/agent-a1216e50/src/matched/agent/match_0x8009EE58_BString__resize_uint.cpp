/* 0x8009EE58 (64 bytes) - BString::resize(unsigned int) */

class BString {
public:
    char eos(void);
    void resize(unsigned int n, char c);
    void resize(unsigned int n);
};

void BString::resize(unsigned int n)
{
    resize(n, eos());
}
