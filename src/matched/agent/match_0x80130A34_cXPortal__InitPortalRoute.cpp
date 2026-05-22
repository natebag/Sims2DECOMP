// 0x80130A34 cXPortal::InitPortalRoute(ObjectModule*, cXObject*, cXObject*) (148B)
// MI-vcall through *(om+4) vtable: slot 76 (offset 608) then slot 61 (offset 488)
// VEntry 8B: {short thisAdj, short pad, void* fn}; vt[N] at N*8, fn at N*8+4

struct VEntry {
    short thisAdj;
    short pad;
    void* fn;
};

class ObjectModule;
class cXObject;

extern float g_cXPortal_ClearRouteDefault[4];

class cXPortal {
public:
    int FindAvailRouteID();
    void ClearRoute(int route, float f);
    int InitPortalRoute(ObjectModule* om, cXObject* obj1, cXObject* obj2);
};

int cXPortal::InitPortalRoute(ObjectModule* om, cXObject*, cXObject*) {
    VEntry* vt = (VEntry*)*(void**)((char*)om + 4);
    short adj = vt[76].thisAdj;
    typedef int (*Fn1)(void*, int);
    int route = ((Fn1)vt[76].fn)((char*)om + adj, 6);
    if (!route) {
        route = FindAvailRouteID();
        VEntry* vt2 = (VEntry*)*(void**)((char*)om + 4);
        short adj2 = vt2[61].thisAdj;
        typedef void (*Fn2)(void*, int, int);
        ((Fn2)vt2[61].fn)((char*)om + adj2, 6, route);
    }
    ClearRoute(route, g_cXPortal_ClearRouteDefault[0]);
    return 1;
}
