// 0x801F6954 INVTarget::GetOnMsgInvShpResourcesReady(char*) (52B)
extern char gInvFormatStr[];
int Sprintf(char* dst, char* fmt, ...);
struct INVTarget { void GetOnMsgInvShpResourcesReady(char* buf); };
void INVTarget::GetOnMsgInvShpResourcesReady(char* buf) {
    Sprintf(buf, gInvFormatStr, 1);
}
