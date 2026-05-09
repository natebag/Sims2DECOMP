// ISimsObjectModel::UpdateBulb(ObjAnimDef*) at 0x8004DCE4 (56 bytes)
// Updates cached anim id at this+1056; on change, writes (id==1) bool to *this+1120 -> +136.
// `mr. r4, r4` early null-check; classic xori+subfic+adde !x idiom for (newVal == 1).

struct ObjAnimDef {
    char _pad[20];
    int m_id;       // offset 20
};

struct UpdateBulbCache {
    char _pad[20];
    int m_lastId;   // offset 20
};

struct UpdateBulbSink {
    char _pad[136];
    int m_bulb;     // offset 136
};

class ISimsObjectModel {
public:
    char _pad0[1056];
    UpdateBulbCache m_cache;          // offset 1056
    char _pad1[1120 - 1056 - sizeof(UpdateBulbCache)];
    UpdateBulbSink* m_sink;           // offset 1120
    void UpdateBulb(ObjAnimDef* pAnim);
};

void ISimsObjectModel::UpdateBulb(ObjAnimDef* pAnim) {
    if (!pAnim) return;
    UpdateBulbCache* cache = &m_cache;
    int newId = pAnim->m_id;
    if (cache->m_lastId == newId) return;
    cache->m_lastId = newId;
    m_sink->m_bulb = (newId == 1);
}
