// 0x8036481C EFontPage::Destruct (16b)

typedef unsigned int u32;

struct EFontPageVTable;
extern EFontPageVTable g_EFontPageVTable_Destruct;

struct EFontPage {
    u32 vtable;
};

void EFontPage_Destruct(EFontPage* thisPtr) {
    thisPtr->vtable = (u32)&g_EFontPageVTable_Destruct;
}
