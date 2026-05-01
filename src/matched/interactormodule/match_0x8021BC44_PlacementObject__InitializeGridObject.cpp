// 0x8021BC44 InteractorModule::PlacementObject::InitializeGridObject(cXMTObjectImpl*) (100B)

struct cXMTObjectImpl;

namespace InteractorModule {

struct GridObjVt {
    char pad[0x8];
    short m_off;            // 0x8
    char _p[2];
    void (*m_fn)(void*);    // 0xC
};

struct GridInner {
    char pad[0x4];
    GridObjVt* m_vt;        // 0x4
};

struct cXMTObjImplGO {
    char pad[0x4];
    GridInner* m_inner;     // 0x4
    int m_field_0;          // wait, structure unclear
};

struct GridGlobal {
    void RegisterGrid(int handle);
};

extern GridGlobal* g_gridReg;  // SDA-extern via r13 @ -21432

class PlacementObject {
public:
    int InitializeGridObject(cXMTObjectImpl* obj);
};

int PlacementObject::InitializeGridObject(cXMTObjectImpl* obj) {
    int result;
    if (obj == 0) {
        result = 0;
        goto end;
    }
    {
        GridInner* inner = ((cXMTObjImplGO*)obj)->m_inner;
        GridObjVt* vt = inner->m_vt;
        void (*fn)(void*) = vt->m_fn;
        short off = vt->m_off;
        fn((char*)inner + off);
        GridInner* inner2 = ((cXMTObjImplGO*)obj)->m_inner;
        g_gridReg->RegisterGrid(*(int*)inner2);
        result = 1;
    }
end:
    return result;
}

}
