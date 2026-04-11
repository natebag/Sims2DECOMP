// 0x803A3544 ReconSaveObject_FamilyImpl (108b)
extern int RSO_vt_803A3544[];

struct RSHelper_803A3544 {
    int* vtable;
    void* obj;
    int val;
    RSHelper_803A3544(void* o, int v) {
        vtable = RSO_vt_803A3544;
        obj = o;
        val = v;
    }
};

int rsave_func_803A3544(void* buf, RSHelper_803A3544* helper, int p5, void* resFile, int p4);
void rsave_dtor_803A3544(RSHelper_803A3544* self, int mode);

int ReconSaveObject_803A3544(void* obj, void* resFile, int val, short p4, int p5) {
    RSHelper_803A3544 helper(obj, val);
    RSHelper_803A3544* hp = &helper;
    char buf[8];
    int result = rsave_func_803A3544(buf, hp, p5, resFile, (int)p4);
    rsave_dtor_803A3544(hp, 2);
    return result;
}
