// FLAGS: -fno-elide-constructors -msdata=eabi -G 8
// 0x80084464 TextBaseItem::Startup (84b)
extern char g_sda_textinfo[4];
void textblock_setdirty(void*);

struct FloatBase {
    char pad[0x723c];
    float f;
};

void TextBaseItem_Startup(char* self) {
    char* sub = self + 32;
    *(int*)(sub + 48) = *(int*)g_sda_textinfo;
    textblock_setdirty(sub);
    int flags = *(int*)(sub + 56);
    *(float*)(sub + 72) = ((struct FloatBase*)0x803D0000)->f;
    *(int*)(sub + 56) = (flags & ~1) | 0x38;
}
