// FLAGS: -fno-elide-constructors
// 0x803A3710 ReconLoadObject_HouseImpl (100b)
extern int RLO_vt_803A3710[];
struct RLH_803A3710 { int* vtable; void* obj; int val;
    RLH_803A3710(void* o, int v) { vtable = RLO_vt_803A3710; obj = o; val = v; }
};
int rload_f_803A3710(void* buf, RLH_803A3710* h, void* resFile, short p4, int* p5);
void rload_d_803A3710(RLH_803A3710* s, int m);
int ReconLoadObject_803A3710(void* obj, void* resFile, int val, short p4, int* p5) {
    RLH_803A3710 helper(obj, val); RLH_803A3710* hp = &helper;
    char buf[8]; int result = rload_f_803A3710(buf, hp, resFile, p4, p5);
    rload_d_803A3710(hp, 2); return result;
}
