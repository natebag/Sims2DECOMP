// FLAGS: -fno-elide-constructors
// 0x803A7300 ReconSaveObject_ObjectSaveTypeTable (108b)
extern int RSO_vt_803A7300[];

struct RSHelper_803A7300 {
    int* vtable;
    void* obj;
    int val;
    RSHelper_803A7300(void* o, int v) {
        vtable = RSO_vt_803A7300;
        obj = o;
        val = v;
    }
};

int rsave_func_803A7300(void* buf, RSHelper_803A7300* helper, int p5, void* resFile, int p4);
void rsave_dtor_803A7300(RSHelper_803A7300* self, int mode);

int ReconSaveObject_803A7300(void* obj, void* resFile, int val, short p4, int p5) {
    RSHelper_803A7300 helper(obj, val);
    RSHelper_803A7300* hp = &helper;
    char buf[8];
    int result = rsave_func_803A7300(buf, hp, p5, resFile, (int)p4);
    rsave_dtor_803A7300(hp, 2);
    return result;
}
