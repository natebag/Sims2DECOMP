// 0x803A8740 ReconLoadObject_ThumbnailLoader (88b)
extern int RLO_vt2_803A8740[];
struct RLH2_803A8740 { int* vtable; void* obj; int val;
    RLH2_803A8740(void* o, int v) { vtable = RLO_vt2_803A8740; obj = o; val = v; }
};
void rload_f2_803A8740(void* buf, RLH2_803A8740* h, void* handleNode, int* p4);
void rload_d2_803A8740(RLH2_803A8740* s, int m);
void ReconLoadObject_803A8740(void* obj, void* handleNode, int val, int* p4) {
    RLH2_803A8740 helper(obj, val); RLH2_803A8740* hp = &helper;
    char buf[8]; rload_f2_803A8740(buf, hp, handleNode, p4);
    rload_d2_803A8740(hp, 2);
}
