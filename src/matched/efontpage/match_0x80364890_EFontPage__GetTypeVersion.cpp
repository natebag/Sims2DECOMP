// 0x80364890 EFontPage::GetTypeVersion (12B) const
struct VerBlock_EFontPage { unsigned short ver[256]; };
extern VerBlock_EFontPage g_EFontPage_TypeVersion[3];
struct EFontPage_GTV { unsigned short GetTypeVersion() const; };
unsigned short EFontPage_GTV::GetTypeVersion() const { return g_EFontPage_TypeVersion[0].ver[0]; }
