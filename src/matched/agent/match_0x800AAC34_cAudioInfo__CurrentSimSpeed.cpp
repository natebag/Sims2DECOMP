/* cAudioInfo::CurrentSimSpeed(void) at 0x800AAC34 (56B) */

struct AudioVtable {
    char pad[0x48];
    short m_vbaseOff;
    int (*m_getSpeedFunc)(void *);
};

struct AudioObj {
    AudioVtable *m_vtable;
};

extern AudioObj *g_audioInfo;

int cAudioInfo_CurrentSimSpeed(void) {
    AudioVtable *vt = g_audioInfo->m_vtable;
    short off = vt->m_vbaseOff;
    int (*fn)(void *) = vt->m_getSpeedFunc;
    return fn((char *)g_audioInfo + off);
}
