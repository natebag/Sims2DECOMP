// FLAGS: -fno-elide-constructors
// 0x803A5220 ReconLoadObject_NeighborhoodImpl (100b)
extern int RLO_vt_803A5220[];
struct RLH_803A5220 { int* vtable; void* obj; int val;
    RLH_803A5220(void* o, int v) { vtable = RLO_vt_803A5220; obj = o; val = v; }
};
int rload_f_803A5220(void* buf, RLH_803A5220* h, void* resFile, short p4, int* p5);
void rload_d_803A5220(RLH_803A5220* s, int m);
int ReconLoadObject_803A5220(void* obj, void* resFile, int val, short p4, int* p5) {
    RLH_803A5220 helper(obj, val); RLH_803A5220* hp = &helper;
    char buf[8]; int result = rload_f_803A5220(buf, hp, resFile, p4, p5);
    rload_d_803A5220(hp, 2); return result;
}
