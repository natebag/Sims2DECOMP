// FLAGS: -fno-elide-constructors
// 0x8039E72C ReconSaveObject_ReconStreamPtrVector_Neighbor (108b)
extern int RSO_vt_8039E72C[];

struct RSHelper_8039E72C {
    int* vtable;
    void* obj;
    int val;
    RSHelper_8039E72C(void* o, int v) {
        vtable = RSO_vt_8039E72C;
        obj = o;
        val = v;
    }
};

int rsave_func_8039E72C(void* buf, RSHelper_8039E72C* helper, int p5, void* resFile, int p4);
void rsave_dtor_8039E72C(RSHelper_8039E72C* self, int mode);

int ReconSaveObject_8039E72C(void* obj, void* resFile, int val, short p4, int p5) {
    RSHelper_8039E72C helper(obj, val);
    RSHelper_8039E72C* hp = &helper;
    char buf[8];
    int result = rsave_func_8039E72C(buf, hp, p5, resFile, (int)p4);
    rsave_dtor_8039E72C(hp, 2);
    return result;
}
