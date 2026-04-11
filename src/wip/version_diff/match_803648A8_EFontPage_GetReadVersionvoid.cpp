// 0x803648A8 (12 bytes)
class EFontPage {
public:
    short GetReadVersion() const;
};

extern char gEFontPageData[];

short EFontPage::GetReadVersion() const {
    return *(short*)(gEFontPageData + 0);
}
