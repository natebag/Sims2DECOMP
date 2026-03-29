// 0x80364884 (12 bytes)
class EFontPage {
public:
    const char* GetTypeKey() const;
};

extern char gEFontPageData[];

const char* EFontPage::GetTypeKey() const {
    return *(const char**)(gEFontPageData + 0);
}
