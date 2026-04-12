// 0x803648A8 (12 bytes)
class EFontPage {
public:
    unsigned short GetReadVersion() const;
};

extern unsigned short gEFontPageData[];

unsigned short EFontPage::GetReadVersion() const {
    return gEFontPageData[1];
}
