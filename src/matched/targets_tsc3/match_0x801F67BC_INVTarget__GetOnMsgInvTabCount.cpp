// 0x801F67BC INVTarget::GetOnMsgInvTabCount(char*) (52B)
extern char gInvFormatStr[];
int Sprintf(char* dst, char* fmt, ...);
struct INVTarget { char pad[0xBC]; int m_tabCount; void GetOnMsgInvTabCount(char* buf); };
void INVTarget::GetOnMsgInvTabCount(char* buf) {
    Sprintf(buf, gInvFormatStr, m_tabCount);
}
