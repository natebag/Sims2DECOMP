// 0x8012FDD0 cXPortalImpl::Place(FTilePt&, int, cXObject*, int) (76B)

class FTilePt;
class cXObject;
class ObjectModule;

struct SubA {
    char pad[88];
    ObjectModule* m_module;
};

class cXMTObjectImpl {
public:
    SubA* m_sub;
    void Place(FTilePt& pt, int a, cXObject* obj, int b);
};

class cXPortal {
public:
    static void DirtyAllRoutes(ObjectModule* m);
};

class cXPortalImpl {
public:
    cXMTObjectImpl* m_obj;
    void Place(FTilePt& pt, int a, cXObject* obj, int b);
    void ApplyWallStyle(bool b);
};

void cXPortalImpl::Place(FTilePt& pt, int a, cXObject* obj, int b) {
    m_obj->Place(pt, a, obj, b);
    ApplyWallStyle(true);
    cXPortal::DirtyAllRoutes(m_obj->m_sub->m_module);
}
