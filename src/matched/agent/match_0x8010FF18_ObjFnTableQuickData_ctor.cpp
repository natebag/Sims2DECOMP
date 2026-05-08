/* ObjFnTableQuickData::ObjFnTableQuickData(void) - 0x8010FF18 - 88 bytes */

extern int __vt__ObjFnTableQuickData[];

struct ObjectDataID {
    unsigned int m_nsId;
    unsigned short m_resId;
    ObjectDataID(unsigned int ns, unsigned short res);
};

struct ObjFnTableQuickData {
    int* m_vtable;
    ObjectDataID m_dataID;
    void* m_fnData;
    void* m_fnDataArray;
    int m_refCount;

    ObjFnTableQuickData();
};

ObjFnTableQuickData::ObjFnTableQuickData()
    : m_vtable(__vt__ObjFnTableQuickData),
      m_dataID((unsigned int)-1, 0)
{
    m_refCount = 0;
    m_fnData = 0;
    m_fnDataArray = 0;
}
