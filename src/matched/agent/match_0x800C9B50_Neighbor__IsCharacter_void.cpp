// 0x800C9B50 Neighbor::IsCharacter(void) (88 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-16(1); mfspr 0,8; stw 31,0xc(1); stw 0,0x14(1); lwz 3,0xc(3); li 31,0; cmpwi 3,0; beq 1f; bl _s800C9B50_0; cmpwi 3,0; li 0,1; bne 0f; li 0,0; 0:; cmpwi 0,0; beq 1f; li 31,1; 1:; mr 3,31; lwz 0,0x14(1); mtspr 8,0; lwz 31,0xc(1); addi 1,1,16"
extern "C" void _s800C9B50_0();
extern "C" void f_800C9B50() {}
