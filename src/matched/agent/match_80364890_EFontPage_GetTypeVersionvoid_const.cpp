// 0x80364890 (12 bytes)
class EFontPage {
public:
    unsigned short GetTypeVersion() const;
};

extern unsigned short gEFontPageData[];

unsigned short EFontPage::GetTypeVersion() const {
    return gEFontPageData[0];
}
