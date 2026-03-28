typedef unsigned char u8;

void TextBlock_SetDirty(void*);
void WrapperPaneBase_UpdateAptButtonWidth(u8*, int);

void DlgWrapper_SetAlt1Font(u8* pThis, void* pFont) {
    u8* pInner = *(u8**)(pThis + 0xAC);
    u8* pBlock = *(u8**)(pInner + 0x48);
    u8* pTextBlock = pBlock + 0x20;
    *(void**)(pTextBlock + 0x30) = pFont;
    TextBlock_SetDirty(pTextBlock);
    int flags = *(int*)(pBlock + 0x04);
    flags |= 0x02;
    *(int*)(pBlock + 0x04) = flags;
    WrapperPaneBase_UpdateAptButtonWidth(pInner, 2);
}
