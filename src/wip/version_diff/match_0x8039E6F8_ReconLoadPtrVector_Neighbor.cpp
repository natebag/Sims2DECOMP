// 0x8039E6F8 ReconLoadPtrVector_Neighbor (52b)
int rv_target_8039E6F8(RVW_8039E6F8* w, void* resFile, int val, short p4, int* p5);
int ReconVecWrap_8039E6F8(void* vec, void* resFile, int val, short p4, int* p5) {
    RVW_8039E6F8 w; w.vec = vec; w.val = val;
    return rv_target_8039E6F8(&w, resFile, val, p4, p5);
}
