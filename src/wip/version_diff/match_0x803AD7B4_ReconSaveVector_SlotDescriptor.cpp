// 0x803AD7B4 ReconSaveVector_SlotDescriptor (52b)
int rv_target_803AD7B4(RVW_803AD7B4* w, void* resFile, int val, short p4, int* p5);
int ReconVecWrap_803AD7B4(void* vec, void* resFile, int val, short p4, int* p5) {
    RVW_803AD7B4 w; w.vec = vec; w.val = val;
    return rv_target_803AD7B4(&w, resFile, val, p4, p5);
}
