// FLAGS: -fno-elide-constructors
// 0x803AD6B0 ReconLoadObject_ReconStreamVector_SlotDescriptor (100b)
extern int RLO_vt_803AD6B0[];
struct RLH_803AD6B0 { int* vtable; void* obj; int val;
    RLH_803AD6B0(void* o, int v) { vtable = RLO_vt_803AD6B0; obj = o; val = v; }
};
int rload_f_803AD6B0(void* buf, RLH_803AD6B0* h, void* resFile, short p4, int* p5);
void rload_d_803AD6B0(RLH_803AD6B0* s, int m);
int ReconLoadObject_803AD6B0(void* obj, void* resFile, int val, short p4, int* p5) {
    RLH_803AD6B0 helper(obj, val); RLH_803AD6B0* hp = &helper;
    char buf[8]; int result = rload_f_803AD6B0(buf, hp, resFile, p4, p5);
    rload_d_803AD6B0(hp, 2); return result;
}
