// FLAGS: -fno-elide-constructors
// 0x803B0884 ReconLoadObject_CasGenetics (88b)
extern int RLO_vt2_803B0884[];
struct RLH2_803B0884 { int* vtable; void* obj; int val;
    RLH2_803B0884(void* o, int v) { vtable = RLO_vt2_803B0884; obj = o; val = v; }
};
void rload_f2_803B0884(void* buf, RLH2_803B0884* h, void* handleNode, int* p4);
void rload_d2_803B0884(RLH2_803B0884* s, int m);
void ReconLoadObject_803B0884(void* obj, void* handleNode, int val, int* p4) {
    RLH2_803B0884 helper(obj, val); RLH2_803B0884* hp = &helper;
    char buf[8]; rload_f2_803B0884(buf, hp, handleNode, p4);
    rload_d2_803B0884(hp, 2);
}
