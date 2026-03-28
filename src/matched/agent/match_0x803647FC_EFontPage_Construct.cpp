struct EFontPage {
    EFontPage(void);
    static void Construct(EFontPage* obj);
};

inline void* operator new(unsigned int, void* ptr) { return ptr; }

void EFontPage::Construct(EFontPage* obj)
{
    new (obj) EFontPage();
}
