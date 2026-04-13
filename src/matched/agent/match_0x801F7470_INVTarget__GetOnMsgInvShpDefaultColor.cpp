// 0x801F7470 INVTarget::GetOnMsgInvShpDefaultColor(char*) (52B)
extern char gInvFormatStr[];
int Sprintf(char* dst, char* fmt, ...);
struct INVTarget { void GetOnMsgInvShpDefaultColor(char* buf); };
void INVTarget::GetOnMsgInvShpDefaultColor(char* buf) {
    Sprintf(buf, gInvFormatStr, 0);
}
