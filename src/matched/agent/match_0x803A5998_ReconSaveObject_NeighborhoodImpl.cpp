// FLAGS: -fno-elide-constructors
// 0x803A5998 ReconSaveObject_NeighborhoodImpl (108b)
extern int RSO_vt_803A5998[];

struct RSHelper_803A5998 {
    int* vtable;
    void* obj;
    int val;
    RSHelper_803A5998(void* o, int v) {
        vtable = RSO_vt_803A5998;
        obj = o;
        val = v;
    }
};

int rsave_func_803A5998(void* buf, RSHelper_803A5998* helper, int p5, void* resFile, int p4);
void rsave_dtor_803A5998(RSHelper_803A5998* self, int mode);

int ReconSaveObject_803A5998(void* obj, void* resFile, int val, short p4, int p5) {
    RSHelper_803A5998 helper(obj, val);
    RSHelper_803A5998* hp = &helper;
    char buf[8];
    int result = rsave_func_803A5998(buf, hp, p5, resFile, (int)p4);
    rsave_dtor_803A5998(hp, 2);
    return result;
}
