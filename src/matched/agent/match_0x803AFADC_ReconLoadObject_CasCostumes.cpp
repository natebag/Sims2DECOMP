// FLAGS: -fno-elide-constructors
// 0x803AFADC ReconLoadObject_CasCostumes (88b)
extern int RLO_vt2_803AFADC[];
struct RLH2_803AFADC { int* vtable; void* obj; int val;
    RLH2_803AFADC(void* o, int v) { vtable = RLO_vt2_803AFADC; obj = o; val = v; }
};
void rload_f2_803AFADC(void* buf, RLH2_803AFADC* h, void* handleNode, int* p4);
void rload_d2_803AFADC(RLH2_803AFADC* s, int m);
void ReconLoadObject_803AFADC(void* obj, void* handleNode, int val, int* p4) {
    RLH2_803AFADC helper(obj, val); RLH2_803AFADC* hp = &helper;
    char buf[8]; rload_f2_803AFADC(buf, hp, handleNode, p4);
    rload_d2_803AFADC(hp, 2);
}
