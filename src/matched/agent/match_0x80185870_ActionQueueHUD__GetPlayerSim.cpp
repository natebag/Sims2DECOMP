// ActionQueueHUD::GetPlayerSim(void) const @ 0x80185870 (108B)

typedef void* (*GPS_VFn)(void*);

struct GPS_VTable {
    void* _pad[194];
    short m_adj;
    short _pad2;
    GPS_VFn m_fn;
};

struct GPS_Obj {
    char _unk[4];
    GPS_VTable* m_vt;
};

struct GPS_Globals {
    char _pad[188];
    GPS_Obj* m_sims[8];
};

extern GPS_Globals _globals;

struct AQH_GPS {
    char _pad[788];
    unsigned int m_playerIdx;
    void* GetPlayerSim() const;
};

void* AQH_GPS::GetPlayerSim() const {
    unsigned int idx = m_playerIdx;
    GPS_Obj* obj = _globals.m_sims[idx];
    if (obj != 0) {
        GPS_VTable* vt = obj->m_vt;
        short adj = vt->m_adj;
        GPS_VFn fn = vt->m_fn;
        void* result = fn((char*)obj + adj);
        if (result == 0) {
            obj = 0;
        }
    }
    return obj;
}
