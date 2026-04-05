/* PopFreeReadBuffer(void) at 0x80337458 (52B) */
// FLAGS: -fno-elide-constructors

extern char g_q_0x80337458[64];
extern int recv_0x80337458(void *, int *, int);

int PopFreeReadBuffer(void) {
    int msg;
    recv_0x80337458(g_q_0x80337458, &msg, 1);
    return msg;
}
