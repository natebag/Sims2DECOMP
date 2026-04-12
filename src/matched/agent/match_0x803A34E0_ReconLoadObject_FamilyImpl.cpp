// 0x803A34E0 match_0x803A34E0_ReconLoadObject_FamilyImpl (100b)
// FLAGS: -fno-elide-constructors
// 0x803A34E0 ReconLoadObject_FamilyImpl (100b)
extern int RLO_vt_803A34E0[];
struct RLH_803A34E0 { int* vtable; void* obj; int val;
    RLH_803A34E0(void* o, int v) { vtable = RLO_vt_803A34E0; obj = o; val = v; }
};
int rload_f_803A34E0(void* buf, RLH_803A34E0* h, void* resFile, short p4, int* p5);
void rload_d_803A34E0(RLH_803A34E0* s, int m);
int ReconLoadObject_803A34E0(void* obj, void* resFile, int val, short p4, int* p5) {
    RLH_803A34E0 helper(obj, val); RLH_803A34E0* hp = &helper;
    char buf[8]; int result = rload_f_803A34E0(buf, hp, resFile, p4, p5);
    rload_d_803A34E0(hp, 2); return result;
}
