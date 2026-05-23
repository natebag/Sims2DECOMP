// 0x8016226C CasMediator::SetCasMode(int) (44B) — free-function → method consolidation
//
// Was `void CasMediator_SetCasMode(CasMediator* self, int mode)` (free function
// with manual self ptr). Promoted to proper member method. Field renamed:
// `casMode` → `m_casMode` per project convention.
//
// Behavior: stores mode into m_casMode at offset 0x2C, then mirrors the value
// to the UI database via UIDBSetInt(g_casModeKey, mode) — keeps in-process
// state and UI database in sync.

extern void UIDBSetInt(const char*, int);
extern char g_casModeKey[];

class CasMediator {
public:
    char pad[44];
    int m_casMode;
    void SetCasMode(int mode);
};

void CasMediator::SetCasMode(int mode) {
    m_casMode = mode;
    UIDBSetInt(g_casModeKey, mode);
}
