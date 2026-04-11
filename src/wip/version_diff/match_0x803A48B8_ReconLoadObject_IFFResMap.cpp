// 0x803A48B8 ReconLoadObject_IFFResMap (88b)
extern int RLO_vt2_803A48B8[];
struct RLH2_803A48B8 { int* vtable; void* obj; int val;
    RLH2_803A48B8(void* o, int v) { vtable = RLO_vt2_803A48B8; obj = o; val = v; }
};
void rload_f2_803A48B8(void* buf, RLH2_803A48B8* h, void* handleNode, int* p4);
void rload_d2_803A48B8(RLH2_803A48B8* s, int m);
void ReconLoadObject_803A48B8(void* obj, void* handleNode, int val, int* p4) {
    RLH2_803A48B8 helper(obj, val); RLH2_803A48B8* hp = &helper;
    char buf[8]; rload_f2_803A48B8(buf, hp, handleNode, p4);
    rload_d2_803A48B8(hp, 2);
}
