// 0x801F7F1C INVTarget::GetOnMsgInvHelpMode(char*) (140B)

extern char g_invHelpTable[4];  // SDA @ -28700

struct Item;

struct INVTarget {
    char pad[132];
    int m_f132;         // offset 132
    char pad2[80];
    Item* m_items[0];    // starts at offset 216

    void GetOnMsgInvHelpMode(char* buf);
};

extern char g_invHelpFmt[32];

extern "C" int InvItemIsMode2(Item* it);    // 0x8004a0f8
extern "C" int InvItemIsFlag1(Item* it);    // 0x8004a138
extern "C" int InvSprintf(char* buf, const char* fmt, ...);  // 0x802de888

void INVTarget::GetOnMsgInvHelpMode(char* buf) {
    int idx = ((int*)g_invHelpTable)[m_f132];
    Item* it = m_items[idx];
    int mode = 1;
    if (it != 0) {
        if (InvItemIsMode2(it) == 2) {
            if (InvItemIsFlag1(it) == 1) {
                mode = 0;
            }
        }
    }
    InvSprintf(buf, g_invHelpFmt, mode);
}
