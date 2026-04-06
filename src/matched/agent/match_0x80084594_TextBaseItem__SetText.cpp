// 0x80084594 TextBaseItem::SetText (72b)

extern void UpdateTextDisplay(void*);

struct TextBaseItem {
    int pad0;
    int flags;
    char pad1[24];
    unsigned short* textPtr;
};

void TextBaseItem_SetText(TextBaseItem* self, unsigned short* text) {
    if (text != 0) {
        self->textPtr = text;
        UpdateTextDisplay(&self->textPtr);
        self->flags |= 2;
    }
}
