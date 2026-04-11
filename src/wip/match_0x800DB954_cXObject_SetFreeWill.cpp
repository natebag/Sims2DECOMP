// 0x800DB954 cXObject::SetFreeWill (76b)
// FLAGS: -fno-elide-constructors

struct cXObject_vtable {
    short adj;
    short pad;
    void* func;
};

struct cXObject {
    cXObject_vtable* vt;
};

// SDA globals at specific offsets
extern cXObject* g_freeWillObj __attribute__((section(".sdata")));
extern short g_freeWillVal __attribute__((section(".sdata")));

extern void SetFreeWill_Impl(void* obj, int cmd, short val);

void cXObject_SetFreeWill(cXObject* this_, int freeWill) {
    g_freeWillVal = freeWill;
    
    cXObject* obj = g_freeWillObj;
    if (obj) {
        cXObject_vtable* vt = obj->vt;
        SetFreeWill_Impl((char*)obj + vt->adj, 30, g_freeWillVal);
    }
}
