// 0x80364878 EFontPage::GetTypeName (12b)

struct EFontPage {
    const char* GetTypeName() const;
};

extern const char g_EFontPageTypeName[];

const char* EFontPage::GetTypeName() const {
    return g_EFontPageTypeName;
}
