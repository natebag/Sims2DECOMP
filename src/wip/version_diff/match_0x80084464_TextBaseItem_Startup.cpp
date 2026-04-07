// FLAGS: -fno-elide-constructors
// 0x80084464 TextBaseItem::Startup (84b)
extern char g_float_textbase[];
void textblock_setdirty(void*);

void TextBaseItem_Startup(char* self) {
    char* sub = self + 32;
    *(int*)(sub + 48) = (int)g_sda_textinfo;
    textblock_setdirty(sub);
    int flags = *(int*)(sub + 56);
    *(float*)(sub + 72) = *(float*)g_float_textbase;
    *(int*)(sub + 56) = (flags & ~1) | 0x38;
}
