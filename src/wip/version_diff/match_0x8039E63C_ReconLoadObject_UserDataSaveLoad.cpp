// 0x8039E63C ReconLoadObject_UserDataSaveLoad (88b)
extern int RLO_vt2_8039E63C[];
struct RLH2_8039E63C { int* vtable; void* obj; int val;
    RLH2_8039E63C(void* o, int v) { vtable = RLO_vt2_8039E63C; obj = o; val = v; }
};
void rload_f2_8039E63C(void* buf, RLH2_8039E63C* h, void* handleNode, int* p4);
void rload_d2_8039E63C(RLH2_8039E63C* s, int m);
void ReconLoadObject_8039E63C(void* obj, void* handleNode, int val, int* p4) {
    RLH2_8039E63C helper(obj, val); RLH2_8039E63C* hp = &helper;
    char buf[8]; rload_f2_8039E63C(buf, hp, handleNode, p4);
    rload_d2_8039E63C(hp, 2);
}
