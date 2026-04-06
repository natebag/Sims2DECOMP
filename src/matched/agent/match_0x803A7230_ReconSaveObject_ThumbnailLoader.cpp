// 0x803A7230 ReconSaveObject_ThumbnailLoader (108b)
extern int RSO_vt_803A7230[];

struct RSHelper_803A7230 {
    int* vtable;
    void* obj;
    int val;
    RSHelper_803A7230(void* o, int v) {
        vtable = RSO_vt_803A7230;
        obj = o;
        val = v;
    }
};

int rsave_func_803A7230(void* buf, RSHelper_803A7230* helper, int p5, void* resFile, int p4);
void rsave_dtor_803A7230(RSHelper_803A7230* self, int mode);

int ReconSaveObject_803A7230(void* obj, void* resFile, int val, short p4, int p5) {
    RSHelper_803A7230 helper(obj, val);
    RSHelper_803A7230* hp = &helper;
    char buf[8];
    int result = rsave_func_803A7230(buf, hp, p5, resFile, (int)p4);
    rsave_dtor_803A7230(hp, 2);
    return result;
}
