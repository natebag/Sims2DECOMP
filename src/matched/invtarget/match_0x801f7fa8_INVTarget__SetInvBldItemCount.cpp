// 0x801F7FA8 INVTarget::SetInvBldItemCount(void) (56B)

extern void StaticNumberToWideString(int value, unsigned short* out);
extern void UIDBSetString(char* key, unsigned short* value);

struct INVTarget {
    char pad[0x32E8];
    int m_bldItemCount;
    void SetInvBldItemCount(void);
};

void INVTarget::SetInvBldItemCount(void) {
    unsigned short wideStr[32];
    StaticNumberToWideString(m_bldItemCount, wideStr);
    UIDBSetString("inv_bld_item_count", wideStr);
}
