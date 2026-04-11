// 0x8039F4B4 ReconLoadObject_ObjectSaveTypeTable3 (100b)
extern int RLO_vt_8039F4B4[];
struct RLH_8039F4B4 { int* vtable; void* obj; int val;
    RLH_8039F4B4(void* o, int v) { vtable = RLO_vt_8039F4B4; obj = o; val = v; }
};
int rload_f_8039F4B4(void* buf, RLH_8039F4B4* h, void* resFile, short p4, int* p5);
void rload_d_8039F4B4(RLH_8039F4B4* s, int m);
int ReconLoadObject_8039F4B4(void* obj, void* resFile, int val, short p4, int* p5) {
    RLH_8039F4B4 helper(obj, val); RLH_8039F4B4* hp = &helper;
    char buf[8]; int result = rload_f_8039F4B4(buf, hp, resFile, p4, p5);
    rload_d_8039F4B4(hp, 2); return result;
}
