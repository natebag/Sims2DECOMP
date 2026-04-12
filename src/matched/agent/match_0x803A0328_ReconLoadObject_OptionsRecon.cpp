// 0x803A0328 match_0x803A0328_ReconLoadObject_OptionsRecon (88b)
// FLAGS: -fno-elide-constructors
// 0x803A0328 ReconLoadObject_OptionsRecon (88b)
extern int RLO_vt2_803A0328[];
struct RLH2_803A0328 { int* vtable; void* obj; int val;
    RLH2_803A0328(void* o, int v) { vtable = RLO_vt2_803A0328; obj = o; val = v; }
};
void rload_f2_803A0328(void* buf, RLH2_803A0328* h, void* handleNode, int* p4);
void rload_d2_803A0328(RLH2_803A0328* s, int m);
void ReconLoadObject_803A0328(void* obj, void* handleNode, int val, int* p4) {
    RLH2_803A0328 helper(obj, val); RLH2_803A0328* hp = &helper;
    char buf[8]; rload_f2_803A0328(buf, hp, handleNode, p4);
    rload_d2_803A0328(hp, 2);
}
