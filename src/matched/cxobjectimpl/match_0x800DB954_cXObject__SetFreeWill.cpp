// 0x800DB954 (76 bytes)
// cXObject::SetFreeWill(bool)

struct cSimulator;

extern void* cXObjectImpl__sFreeWill;
extern cSimulator* Globs__pSimulator;

class cXObject {
public:
    void SetFreeWill(bool);
};

void cXObject::SetFreeWill(bool) {
    cXObjectImpl__sFreeWill = this;
    cSimulator* sim = Globs__pSimulator;
    if (sim) {
        void** vtbl = *(void***)sim;
        short adj = *(short*)((char*)vtbl + 0x38);
        void* fn = *(void**)((char*)vtbl + 0x3C);
        short val = *(short*)((char*)&cXObjectImpl__sFreeWill + 2);
        ((void (*)(void*, int, short))fn)((char*)sim + adj, 30, val);
    }
}
