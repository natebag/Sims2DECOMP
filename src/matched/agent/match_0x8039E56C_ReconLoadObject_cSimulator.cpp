// FLAGS: -fno-elide-constructors
// 0x8039E56C ReconLoadObject_cSimulator (100b)
extern int RLO_vt_8039E56C[];
struct RLH_8039E56C { int* vtable; void* obj; int val;
    RLH_8039E56C(void* o, int v) { vtable = RLO_vt_8039E56C; obj = o; val = v; }
};
int rload_f_8039E56C(void* buf, RLH_8039E56C* h, void* resFile, short p4, int* p5);
void rload_d_8039E56C(RLH_8039E56C* s, int m);
int ReconLoadObject_8039E56C(void* obj, void* resFile, int val, short p4, int* p5) {
    RLH_8039E56C helper(obj, val); RLH_8039E56C* hp = &helper;
    char buf[8]; int result = rload_f_8039E56C(buf, hp, resFile, p4, p5);
    rload_d_8039E56C(hp, 2); return result;
}
