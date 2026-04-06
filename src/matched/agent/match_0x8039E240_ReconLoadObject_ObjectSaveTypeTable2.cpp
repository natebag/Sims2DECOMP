// 0x8039E240 ReconLoadObject_ObjectSaveTypeTable2 (100b)
extern int RLO_vt_8039E240[];
struct RLH_8039E240 { int* vtable; void* obj; int val;
    RLH_8039E240(void* o, int v) { vtable = RLO_vt_8039E240; obj = o; val = v; }
};
int rload_f_8039E240(void* buf, RLH_8039E240* h, void* resFile, short p4, int* p5);
void rload_d_8039E240(RLH_8039E240* s, int m);
int ReconLoadObject_8039E240(void* obj, void* resFile, int val, short p4, int* p5) {
    RLH_8039E240 helper(obj, val); RLH_8039E240* hp = &helper;
    char buf[8]; int result = rload_f_8039E240(buf, hp, resFile, p4, p5);
    rload_d_8039E240(hp, 2); return result;
}
