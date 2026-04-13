// FLAGS: -fno-elide-constructors
// 0x803A82B8 ReconSaveObject_ObjectModuleImpl (108b)
extern int RSO_vt_803A82B8[];

struct RSHelper_803A82B8 {
    int* vtable;
    void* obj;
    int val;
    RSHelper_803A82B8(void* o, int v) {
        vtable = RSO_vt_803A82B8;
        obj = o;
        val = v;
    }
};

int rsave_func_803A82B8(void* buf, RSHelper_803A82B8* helper, int p5, void* resFile, int p4);
void rsave_dtor_803A82B8(RSHelper_803A82B8* self, int mode);

int ReconSaveObject_803A82B8(void* obj, void* resFile, int val, short p4, int p5) {
    RSHelper_803A82B8 helper(obj, val);
    RSHelper_803A82B8* hp = &helper;
    char buf[8];
    int result = rsave_func_803A82B8(buf, hp, p5, resFile, (int)p4);
    rsave_dtor_803A82B8(hp, 2);
    return result;
}
