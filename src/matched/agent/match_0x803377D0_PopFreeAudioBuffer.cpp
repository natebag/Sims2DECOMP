/* PopFreeAudioBuffer(void) at 0x803377D0 (52B) */
// FLAGS: -fno-elide-constructors

extern char g_q_0x803377D0[64];
extern int recv_0x803377D0(void *, int *, int);

int PopFreeAudioBuffer(void) {
    int msg;
    recv_0x803377D0(g_q_0x803377D0, &msg, 1);
    return msg;
}
