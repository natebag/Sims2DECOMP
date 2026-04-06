// 0x8039E5D0 ReconSaveObject<cSimulator> (108b)
// FLAGS: -fno-elide-constructors
extern int RSO_vt_8039E5D0[];

struct RSHelper_8039E5D0 {
    int* vtable;
    void* obj;
    int val;
    RSHelper_8039E5D0(void* o, int v) {
        vtable = RSO_vt_8039E5D0;
        obj = o;
        val = v;
    }
};

int rsave_func_8039E5D0(void* buf, RSHelper_8039E5D0* helper, int p5, void* resFile, int p4);
void rsave_dtor_8039E5D0(RSHelper_8039E5D0* self, int mode);

int ReconSaveObject_8039E5D0(void* obj, void* resFile, int val, short p4, int p5) {
    RSHelper_8039E5D0 helper(obj, val);
    RSHelper_8039E5D0* hp = &helper;
    char buf[8];
    int result = rsave_func_8039E5D0(buf, hp, p5, resFile, (int)p4);
    rsave_dtor_8039E5D0(hp, 2);
    return result;
}
