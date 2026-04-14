// 0x801F6824 INVTarget::GetOnMsgInvInventoryReady(char*) (52B)
extern char gInvFormatStr[];
int Sprintf(char* dst, char* fmt, ...);
struct INVTarget { void GetOnMsgInvInventoryReady(char* buf); };
void INVTarget::GetOnMsgInvInventoryReady(char* buf) {
    Sprintf(buf, gInvFormatStr, 1);
}
