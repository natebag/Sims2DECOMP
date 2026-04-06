/* PopReadedBuffer2(void) at 0x803374BC (52B) */

extern char g_q_0x803374BC[64];
extern int recv_0x803374BC(void *, int *, int);

int PopReadedBuffer2(void) {
    int msg;
    recv_0x803374BC(g_q_0x803374BC, &msg, 1);
    return msg;
}
