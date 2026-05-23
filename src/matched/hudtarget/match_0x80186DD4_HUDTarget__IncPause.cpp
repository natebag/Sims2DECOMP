// 0x80186DD4 HUDTarget::IncPause(bool) (48B)
struct HUDTarget {
    char pad[2228];
    int m_pauseEnabled;
};

extern void PauseMgr__Inc(bool flag);

void HUDTarget__IncPause(HUDTarget* self, bool flag) {
    if (self->m_pauseEnabled != 0) {
        PauseMgr__Inc(flag);
    }
}
