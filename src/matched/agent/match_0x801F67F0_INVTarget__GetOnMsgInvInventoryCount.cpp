// 0x801F67F0 INVTarget::GetOnMsgInvInventoryCount(char*) (52B)
extern char gInvFormatStr[];
int Sprintf(char* dst, char* fmt, ...);
struct INVTarget { char pad[0xD4]; int m_invCount; void GetOnMsgInvInventoryCount(char* buf); };
void INVTarget::GetOnMsgInvInventoryCount(char* buf) {
    Sprintf(buf, gInvFormatStr, m_invCount);
}
