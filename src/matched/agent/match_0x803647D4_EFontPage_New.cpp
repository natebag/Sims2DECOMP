typedef unsigned int uint;

struct EFontPage {
    EFontPage(void);
    static EFontPage* New(void);
};

extern "C" void* __builtin_new(uint size);
inline void* operator new(uint, void* ptr) { return ptr; }

EFontPage* EFontPage::New(void)
{
    return new ((EFontPage*)__builtin_new(0x14)) EFontPage;
}
