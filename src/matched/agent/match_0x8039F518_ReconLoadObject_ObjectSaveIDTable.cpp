// 0x8039F518 match_0x8039F518_ReconLoadObject_ObjectSaveIDTable (100b)
// FLAGS: -fno-elide-constructors
// 0x8039F518 ReconLoadObject_ObjectSaveIDTable (100b)
extern int RLO_vt_8039F518[];
struct RLH_8039F518 { int* vtable; void* obj; int val;
    RLH_8039F518(void* o, int v) { vtable = RLO_vt_8039F518; obj = o; val = v; }
};
int rload_f_8039F518(void* buf, RLH_8039F518* h, void* resFile, short p4, int* p5);
void rload_d_8039F518(RLH_8039F518* s, int m);
int ReconLoadObject_8039F518(void* obj, void* resFile, int val, short p4, int* p5) {
    RLH_8039F518 helper(obj, val); RLH_8039F518* hp = &helper;
    char buf[8]; int result = rload_f_8039F518(buf, hp, resFile, p4, p5);
    rload_d_8039F518(hp, 2); return result;
}
