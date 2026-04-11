/* BGExec_FlushResQueue(void) at 0x80014D2C (64B) */

struct BGExecVtable {
    char pad[0x38];
    short m_vbaseOff;
    int (*m_flushFunc)(void *);
};

struct BGExecObj {
    BGExecVtable *m_vtable;
};

extern BGExecObj *g_bgExecObj;
extern int g_resQueueFlushed;

void BGExec_FlushResQueue(void) {
    BGExecVtable *vt = g_bgExecObj->m_vtable;
    short off = vt->m_vbaseOff;
    int (*fn)(void *) = vt->m_flushFunc;
    fn((char *)g_bgExecObj + off);
    g_resQueueFlushed = 1;
}
