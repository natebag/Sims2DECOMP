// 0x80234090 ERLevel::SetBounds(EInstance (288 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="lfs f13,0x0(5); addi 9,4,60; lfs f0,0x3c(4); li 10,0; li 0,0; fcmpu 0,f13,f0; bne 0f; lfs f13,0x4(5); lfs f0,0x4(9); fcmpu 0,f13,f0; bne 0f; lfs f13,0x8(5); lfs f0,0x8(9); fcmpu 0,f13,f0; beq 1f; 0:; li 0,1; 1:; cmpwi 0,0; bne 4f; lfs f13,0xc(9); addi 11,5,12; lfs f0,0xc(5); addi 9,9,12; li 0,0; fcmpu 0,f0,f13; bne 2f; lfs f13,0x4(11); lfs f0,0x4(9); fcmpu 0,f13,f0; bne 2f; lfs f13,0x8(11); lfs f0,0x8(9); fcmpu 0,f13,f0; beq 3f; 2:; li 0,1; 3:; cmpwi 0,0; beq 5f; 4:; li 10,1; 5:; cmpwi 10,0; beqlr; lwz 9,0x0(5); addi 11,4,60; lwz 0,0x8(5); addi 7,5,12; lwz 10,0x4(5); addi 8,4,72; stw 9,0x3c(4); stw 0,0x8(11); stw 10,0x4(11); lwz 9,0xc(5); lwz 11,0x4(7); lwz 0,0x8(7); stw 9,0x48(4); stw 0,0x8(8); stw 11,0x4(8); lwz 4,0x38(4); cmpwi 4,0; beqlr; lfs f13,0x0(5); addi 9,4,4; lfs f0,0x4(4); fcmpu 0,f13,f0; cror 3,2,1; bnslr; lfs f13,0x10(4); lfs f0,0xc(5); fcmpu 0,f0,f13; cror 3,2,0; bnslr; lfs f13,0x4(5); lfs f0,0x4(9); fcmpu 0,f13,f0"

struct ERLevel {
    void SetBounds_EInstance();
};

void ERLevel::SetBounds_EInstance() {
}
