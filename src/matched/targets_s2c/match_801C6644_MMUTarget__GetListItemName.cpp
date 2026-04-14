/* MMUTarget::GetListItemName(char *) at 0x801C6644 (72B) */

struct MMUTarget {
    char pad_000[0x8C];
    int m_field8C;

    char* GetListItemName(char* buf);
    char* GetNGHListItemName(char* buf);
    char* GetLotListItemName(char* buf);
};

char* MMUTarget::GetListItemName(char* buf) {
    int mode = m_field8C;
    if (mode == 1) {
        return GetNGHListItemName(buf);
    } else if (mode == 2) {
        return GetLotListItemName(buf);
    }
    return 0;
}
