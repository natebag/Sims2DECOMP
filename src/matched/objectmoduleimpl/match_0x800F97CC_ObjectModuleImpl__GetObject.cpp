// 0x800F97CC ObjectModuleImpl::GetObject(unsigned) (84B)
// id in [0x4000, 0x400F] -> m_specialObjects[id-0x4000]; else m_objectMap[id].
// Return obj ? obj->m_handle : 0.
struct GameObj {
    char pad0[4];
    int m_handle;   // 0x4
};

struct ObjectModuleImpl {
    char pad[0x2090];
    GameObj** m_objectMap;          // 0x2090
    char pad2[0x20A0 - 0x2094];     // 0x2094..0x209F
    GameObj* m_specialObjects[16];  // 0x20A0
    int GetObject(unsigned id);
};

int ObjectModuleImpl::GetObject(unsigned id) {
    if ((unsigned)(id - 0x4000) <= 15) {
        GameObj* o = m_specialObjects[id - 0x4000];
        return o ? o->m_handle : 0;
    } else {
        GameObj* o = *(GameObj**)((unsigned)m_objectMap + (id << 2));
        return o ? o->m_handle : 0;
    }
}
