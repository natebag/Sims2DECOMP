// 0x8014ADA0 WantFear::Bookmark::GetType(void) (104 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-16(1); mfspr 0,8; stw 31,0xc(1); stw 0,0x14(1); mr 31,3; lwz 3,0x4(31); bl _s8014ADA0_0; lbz 0,0x2(3); cmpwi 0,128; beq 0f; cmpwi 0,1; li 3,1; beq 1f; mr 3,31; bl _s8014ADA0_1; cmpwi 3,0; li 3,4; bne 1f; li 3,0; b 1f; 0:; li 3,128; 1:; lwz 0,0x14(1); mtspr 8,0; lwz 31,0xc(1); addi 1,1,16"
extern "C" void _s8014ADA0_0();
extern "C" void _s8014ADA0_1();
extern "C" void f_8014ADA0() {}
