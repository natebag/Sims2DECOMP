// 0x803A71C4 match_0x803A71C4_ReconSaveObject_UserDataSaveLoad (108b)
// FLAGS: -fno-elide-constructors
// 0x803A71C4 ReconSaveObject_UserDataSaveLoad (108b)
extern int RSO_vt_803A71C4[];

struct RSHelper_803A71C4 {
    int* vtable;
    void* obj;
    int val;
    RSHelper_803A71C4(void* o, int v) {
        vtable = RSO_vt_803A71C4;
        obj = o;
        val = v;
    }
};

int rsave_func_803A71C4(void* buf, RSHelper_803A71C4* helper, int p5, void* resFile, int p4);
void rsave_dtor_803A71C4(RSHelper_803A71C4* self, int mode);

int ReconSaveObject_803A71C4(void* obj, void* resFile, int val, short p4, int p5) {
    RSHelper_803A71C4 helper(obj, val);
    RSHelper_803A71C4* hp = &helper;
    char buf[8];
    int result = rsave_func_803A71C4(buf, hp, p5, resFile, (int)p4);
    rsave_dtor_803A71C4(hp, 2);
    return result;
}
