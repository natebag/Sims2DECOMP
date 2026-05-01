// 0x8001A2B8 ESimsCam::CursorNotActive(void) (112B)

class CursorMgr {
public:
    char pad[0x44];
    int m_state1;
    int m_state2;
};

class CursorMgrMgr {
public:
    CursorMgr* Lookup(int x, int y);
};

class ESimsCam {
public:
    char pad[0x4];
    int m_field_4;
    CursorMgrMgr* GetMgr();
    int CursorNotActive();
};

int ESimsCam::CursorNotActive() {
    CursorMgrMgr* mgr = GetMgr();
    CursorMgr* m = mgr->Lookup(m_field_4, -1);
    if (m == 0) goto ret_zero;
    {
        int x = 0;
        if (m->m_state1 != 0) x = 1;
        else if (m->m_state2 != 0) x = 1;
        if (x) return 1;
    }
ret_zero:
    return 0;
}
