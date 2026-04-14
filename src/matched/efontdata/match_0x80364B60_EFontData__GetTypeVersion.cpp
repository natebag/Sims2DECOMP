// 0x80364B60 EFontData::GetTypeVersion (12B) const
struct VerBlock_EFontData { unsigned short ver[256]; };
extern VerBlock_EFontData g_EFontData_TypeVersion[3];
struct EFontData_GTV { unsigned short GetTypeVersion() const; };
unsigned short EFontData_GTV::GetTypeVersion() const { return g_EFontData_TypeVersion[0].ver[0]; }
