// 0x803AD714 ReconLoadVector_SlotDescriptor (52b)
int rv_target_803AD714(RVW_803AD714* w, void* resFile, int val, short p4, int* p5);
int ReconVecWrap_803AD714(void* vec, void* resFile, int val, short p4, int* p5) {
    RVW_803AD714 w; w.vec = vec; w.val = val;
    return rv_target_803AD714(&w, resFile, val, p4, p5);
}
