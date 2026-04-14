struct Inner { char pad[16]; int m_val; };
struct EGlobal { char pad[0xD0]; Inner* m_win; void* GetWin(); };
void* EGlobal::GetWin() {
    if (!m_win) return 0;
    return &m_win->m_val;
}
