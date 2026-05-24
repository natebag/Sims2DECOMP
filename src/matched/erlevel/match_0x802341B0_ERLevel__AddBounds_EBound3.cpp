// 0x802341B0 ERLevel::AddBounds(EBound3 (176 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="lwz 0,0x0(6); cmpwi 0,0; beq 0f; li 0,0; addi 10,5,12; stw 0,0x0(6); addi 8,4,12; lwz 0,0x0(5); lwz 9,0x4(5); lwz 11,0x8(5); stw 0,0x0(4); stw 9,0x4(4); stw 11,0x8(4); lwz 0,0xc(5); lwz 9,0x8(10); lwz 11,0x4(10); stw 0,0xc(4); stw 9,0x8(8); stw 11,0x4(8); blr; 0:; li 0,3; addi 10,4,12; mtspr 9,0; addi 8,5,12; mr 11,10; li 9,0; 1:; lfsx f0,9,5; lfsx f13,9,4; fmr f12,f0; fcmpu 0,f13,f0; bge 2f; fmr f12,f13; 2:; stfsx f12,9,4; lfsx f0,9,8; lfsx f12,9,10; fmr f13,f0; fcmpu 0,f12,f0; ble 3f; fmr f13,f12; 3:; stfs f13,0x0(11); addi 9,9,4; addi 11,11,4; bdnz 1b"

struct ERLevel {
    void AddBounds_EBound3();
};

void ERLevel::AddBounds_EBound3() {
}
