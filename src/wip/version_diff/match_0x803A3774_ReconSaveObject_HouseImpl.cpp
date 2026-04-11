// 0x803A3774 ReconSaveObject_HouseImpl (108b)
extern int RSO_vt_803A3774[];

struct RSHelper_803A3774 {
    int* vtable;
    void* obj;
    int val;
    RSHelper_803A3774(void* o, int v) {
        vtable = RSO_vt_803A3774;
        obj = o;
        val = v;
    }
};

int rsave_func_803A3774(void* buf, RSHelper_803A3774* helper, int p5, void* resFile, int p4);
void rsave_dtor_803A3774(RSHelper_803A3774* self, int mode);

int ReconSaveObject_803A3774(void* obj, void* resFile, int val, short p4, int p5) {
    RSHelper_803A3774 helper(obj, val);
    RSHelper_803A3774* hp = &helper;
    char buf[8];
    int result = rsave_func_803A3774(buf, hp, p5, resFile, (int)p4);
    rsave_dtor_803A3774(hp, 2);
    return result;
}
