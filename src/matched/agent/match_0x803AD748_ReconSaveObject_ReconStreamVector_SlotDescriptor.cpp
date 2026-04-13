// FLAGS: -fno-elide-constructors
// 0x803AD748 ReconSaveObject_ReconStreamVector_SlotDescriptor (108b)
extern int RSO_vt_803AD748[];

struct RSHelper_803AD748 {
    int* vtable;
    void* obj;
    int val;
    RSHelper_803AD748(void* o, int v) {
        vtable = RSO_vt_803AD748;
        obj = o;
        val = v;
    }
};

int rsave_func_803AD748(void* buf, RSHelper_803AD748* helper, int p5, void* resFile, int p4);
void rsave_dtor_803AD748(RSHelper_803AD748* self, int mode);

int ReconSaveObject_803AD748(void* obj, void* resFile, int val, short p4, int p5) {
    RSHelper_803AD748 helper(obj, val);
    RSHelper_803AD748* hp = &helper;
    char buf[8];
    int result = rsave_func_803AD748(buf, hp, p5, resFile, (int)p4);
    rsave_dtor_803AD748(hp, 2);
    return result;
}
