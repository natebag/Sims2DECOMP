typedef unsigned char u8;

void TextBlock_SetDirty(void*);

void DlgWrapper_SetBodyFontSize(u8* pThis, float size) {
    u8* pInner = *(u8**)(pThis + 0xAC);
    u8* pBlock = *(u8**)(pInner + 0x64);
    u8* pTextBlock = pBlock + 0x20;
    *(float*)(pTextBlock + 0x34) = size;
    TextBlock_SetDirty(pTextBlock);
    int flags = *(int*)(pBlock + 0x04);
    flags |= 0x02;
    *(int*)(pBlock + 0x04) = flags;
}
