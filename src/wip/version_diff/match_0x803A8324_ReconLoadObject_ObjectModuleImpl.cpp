// 0x803A8324 ReconLoadObject_ObjectModuleImpl (100b)
extern int RLO_vt_803A8324[];
struct RLH_803A8324 { int* vtable; void* obj; int val;
    RLH_803A8324(void* o, int v) { vtable = RLO_vt_803A8324; obj = o; val = v; }
};
int rload_f_803A8324(void* buf, RLH_803A8324* h, void* resFile, short p4, int* p5);
void rload_d_803A8324(RLH_803A8324* s, int m);
int ReconLoadObject_803A8324(void* obj, void* resFile, int val, short p4, int* p5) {
    RLH_803A8324 helper(obj, val); RLH_803A8324* hp = &helper;
    char buf[8]; int result = rload_f_803A8324(buf, hp, resFile, p4, p5);
    rload_d_803A8324(hp, 2); return result;
}
