// 0x803649F8 EFontSize::GetTypeVersion (12B) const
struct VerBlock_EFontSize { unsigned short ver[256]; };
extern VerBlock_EFontSize g_EFontSize_TypeVersion[3];
struct EFontSize_GTV { unsigned short GetTypeVersion() const; };
unsigned short EFontSize_GTV::GetTypeVersion() const { return g_EFontSize_TypeVersion[0].ver[0]; }
