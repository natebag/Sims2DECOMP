// 0x80364890 (12 bytes)
class EFontPage {
public:
    short GetTypeVersion() const;
};

extern char gEFontPageData[];

short EFontPage::GetTypeVersion() const {
    return *(short*)(gEFontPageData + 0);
}
