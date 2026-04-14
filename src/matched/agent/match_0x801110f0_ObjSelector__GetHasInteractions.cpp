// 0x801110F0 ObjSelector::GetHasInteractions (88B)

struct InteractionObjVtbl {
    char pad[0x70];
    short adj;
    void* func;
};

struct InteractionObj {
    InteractionObjVtbl* vtable;
};

struct ObjSelector;
extern "C" InteractionObj* ObjSelector_GetInteractionObj(ObjSelector* self);

struct ObjSelector {
    int GetHasInteractions();
};

int ObjSelector::GetHasInteractions() {
    InteractionObj* obj = ObjSelector_GetInteractionObj(this);
    if (obj == 0) return 0;
    InteractionObjVtbl* vt = obj->vtable;
    short adj = vt->adj;
    void* fn = vt->func;
    typedef int (*InteractionFunc)(void*);
    InteractionFunc f = (InteractionFunc)fn;
    int result = f((char*)obj + adj);
    return result != 0;
}
