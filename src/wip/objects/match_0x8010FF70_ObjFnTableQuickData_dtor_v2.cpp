/* ObjFnTableQuickData::~ObjFnTableQuickData(void) - 0x8010FF70 - 92 bytes */

struct Base {
    virtual ~Base() {}
};

struct ObjectDataID {
    unsigned int m_nsId;
    unsigned short m_resId;
};

struct ObjFnTableQuickData : public Base {
    ObjectDataID m_dataID;
    void* m_fnData;
    void* m_fnDataArray;
    int m_refCount;

    ~ObjFnTableQuickData();
};

ObjFnTableQuickData::~ObjFnTableQuickData() {
    ::operator delete(m_fnDataArray);
}
