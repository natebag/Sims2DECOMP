// 0x80364878 (12 bytes)
class EFontPage {
public:
    const char* GetTypeName() const;
};

extern char gEFontPageData[];

const char* EFontPage::GetTypeName() const {
    return *(const char**)(gEFontPageData + 0);
}
