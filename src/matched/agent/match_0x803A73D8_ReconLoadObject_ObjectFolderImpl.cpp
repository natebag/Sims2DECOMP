// 0x803A73D8 ReconLoadObject_ObjectFolderImpl (100b)
extern int RLO_vt_803A73D8[];
struct RLH_803A73D8 { int* vtable; void* obj; int val;
    RLH_803A73D8(void* o, int v) { vtable = RLO_vt_803A73D8; obj = o; val = v; }
};
int rload_f_803A73D8(void* buf, RLH_803A73D8* h, void* resFile, short p4, int* p5);
void rload_d_803A73D8(RLH_803A73D8* s, int m);
int ReconLoadObject_803A73D8(void* obj, void* resFile, int val, short p4, int* p5) {
    RLH_803A73D8 helper(obj, val); RLH_803A73D8* hp = &helper;
    char buf[8]; int result = rload_f_803A73D8(buf, hp, resFile, p4, p5);
    rload_d_803A73D8(hp, 2); return result;
}
