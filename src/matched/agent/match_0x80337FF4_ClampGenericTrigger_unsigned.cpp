/* FLAGS: -fno-schedule-insns */
/* 0x80337FF4 ClampGenericTrigger (52 B) */
/* lbz 0,0x0(3); cmplw 0,4; bgt 0f; li 0,0; stb 0,0x0(3); blr; 0:; cmplw 0,5; ble 1f; stb 5,0x0(3); 1:; lbz 0,0x0(3); subf 0,4,0; stb 0,0x0(3) */
extern "C" void ClampGenericTrigger(unsigned char* ptr, unsigned int min_val, unsigned int max_val) {
    unsigned int v = *ptr;
    if (v <= min_val) {
        *ptr = 0;
        return;
    }
    if (v > max_val) {
        *ptr = (unsigned char)max_val;
    }
    v = *ptr;
    *ptr = (unsigned char)(v - min_val);
}
