// FLAGS: -fno-elide-constructors
// 0x802EB53C EAnimController::CallbackIntermediateComputeMatrices (52b)
void anim_compute(void*);

void CallbackIntermediateComputeMatrices_test(char* self) {
    anim_compute(self);
    *(int*)(self + 48) = (int)g_sda_matflag;
}
