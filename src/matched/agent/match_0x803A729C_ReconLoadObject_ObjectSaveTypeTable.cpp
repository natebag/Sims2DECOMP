// 0x803A729C ReconLoadObject_ObjectSaveTypeTable (100b)
extern int RLO_vt_803A729C[];
struct RLH_803A729C { int* vtable; void* obj; int val;
    RLH_803A729C(void* o, int v) { vtable = RLO_vt_803A729C; obj = o; val = v; }
};
int rload_f_803A729C(void* buf, RLH_803A729C* h, void* resFile, short p4, int* p5);
void rload_d_803A729C(RLH_803A729C* s, int m);
int ReconLoadObject_803A729C(void* obj, void* resFile, int val, short p4, int* p5) {
    RLH_803A729C helper(obj, val); RLH_803A729C* hp = &helper;
    char buf[8]; int result = rload_f_803A729C(buf, hp, resFile, p4, p5);
    rload_d_803A729C(hp, 2); return result;
}
