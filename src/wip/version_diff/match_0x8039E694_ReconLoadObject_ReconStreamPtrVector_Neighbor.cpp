// 0x8039E694 ReconLoadObject_ReconStreamPtrVector_Neighbor (100b)
extern int RLO_vt_8039E694[];
struct RLH_8039E694 { int* vtable; void* obj; int val;
    RLH_8039E694(void* o, int v) { vtable = RLO_vt_8039E694; obj = o; val = v; }
};
int rload_f_8039E694(void* buf, RLH_8039E694* h, void* resFile, short p4, int* p5);
void rload_d_8039E694(RLH_8039E694* s, int m);
int ReconLoadObject_8039E694(void* obj, void* resFile, int val, short p4, int* p5) {
    RLH_8039E694 helper(obj, val); RLH_8039E694* hp = &helper;
    char buf[8]; int result = rload_f_8039E694(buf, hp, resFile, p4, p5);
    rload_d_8039E694(hp, 2); return result;
}
