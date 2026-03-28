typedef unsigned char u8;

void TextBlock_SetDirty(void*);
void WrapperPaneBase_UpdateAptButtonWidth(u8*, int);

void DlgWrapper_SetAcceptFontSize(u8* pThis, float size) {
    u8* pInner = *(u8**)(pThis + 0xAC);
    u8* pBlock = *(u8**)(pInner + 0x40);
    u8* pTextBlock = pBlock + 0x20;
    *(float*)(pTextBlock + 0x34) = size;
    TextBlock_SetDirty(pTextBlock);
    int flags = *(int*)(pBlock + 0x04);
    flags |= 0x02;
    *(int*)(pBlock + 0x04) = flags;
    WrapperPaneBase_UpdateAptButtonWidth(pInner, 0);
}
