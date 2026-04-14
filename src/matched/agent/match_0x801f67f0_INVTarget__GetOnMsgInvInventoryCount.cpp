// 0x801F67F0 INVTarget::GetOnMsgInvInventoryCount(char *) (52B)

extern int Sprintf(char* dest, const char* fmt, ...);

struct INVTarget {
    char pad[0xD4];
    int m_inventoryCount;
    void GetOnMsgInvInventoryCount(char* dest);
};

void INVTarget::GetOnMsgInvInventoryCount(char* dest) {
    Sprintf(dest, "%d", m_inventoryCount);
}
