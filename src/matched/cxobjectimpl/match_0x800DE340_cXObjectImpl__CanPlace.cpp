// cXObjectImpl::CanPlace(FTilePt&, int, cXObject*, int) at 0x800DE340 (132B)

struct FTilePt { int x; int y; };

struct cXObjectImpl;

struct CPVt { char pad[1312]; short m_off; char _p[2]; cXObjectImpl *(*m_fn)(void *); };

struct cXObject {
    char pad[4];
    CPVt *m_vt2;
};

struct PlacementSpec {
    int data[6];
    PlacementSpec(FTilePt&, int, cXObjectImpl *, int);
};

struct cXObjectImpl {
    bool TestAndPlace(PlacementSpec *, bool);
    bool CanPlace(FTilePt &, int, cXObject *, int);
};

bool cXObjectImpl::CanPlace(FTilePt &arg1, int arg2, cXObject *arg3, int arg4) {
    cXObjectImpl *converted;
    if (arg3 != 0) {
        converted = arg3->m_vt2->m_fn((char *)arg3 + arg3->m_vt2->m_off);
    } else {
        converted = 0;
    }
    PlacementSpec spec(arg1, arg2, converted, arg4);
    return TestAndPlace(&spec, false);
}
