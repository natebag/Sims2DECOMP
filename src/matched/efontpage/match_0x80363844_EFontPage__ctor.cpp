// 0x80363844 match_0x80363844_EFontPage__ctor (32b)
// FLAGS: -fno-elide-constructors
// 0x80363844 EFontPage::EFontPage (32b)

typedef unsigned int u32;

struct EFontPageVTable;
extern EFontPageVTable g_EFontPageVTable;

struct EFontPage {
    u32 vtable;
    u32 field_04;
    u32 field_08;

    EFontPage();
};

EFontPage::EFontPage() {
    vtable = (u32)&g_EFontPageVTable;
    field_04 = 0;
    field_08 = 0;
}
