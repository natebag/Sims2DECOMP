// 0x80014D2C BGExec_FlushResQueue (64b)
// FLAGS: -fno-elide-constructors

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
    int (*fn)(void *) = vt->m_flushFunc;
    short off = vt->m_vbaseOff;
    fn((char *)g_bgExecObj + off);
    g_resQueueFlushed = 1;
}
