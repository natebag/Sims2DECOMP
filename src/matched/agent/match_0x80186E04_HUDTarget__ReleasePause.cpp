// 0x80186E04 HUDTarget::ReleasePause(bool) (36B)
struct HUDTarget {
    char pad[2228];
    int m_pauseEnabled;
};

extern void PauseMgr__Release(bool flag);

void HUDTarget__ReleasePause(HUDTarget* self, bool flag) {
    if (self->m_pauseEnabled != 0) {
        PauseMgr__Release(flag);
    }
}
