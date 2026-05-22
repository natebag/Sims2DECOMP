// 0x8033A3B0 ENgcRC::DisplayList(EDL (128 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-16(1); mfspr 0,8; stw 31,0xc(1); stw 0,0x14(1); mr. 31,4; beq 2f; lwz 9,0x60(31); lwz 0,0x3c(3); cmpw 9,0; bgt 2f; lwz 11,0x0(3); lwz 9,0x54(31); lwz 0,0x54(11); add 0,0,9; stw 0,0x54(11); lwz 9,0x30(31); cmpwi 9,0; bne 0f; lwz 0,0x3c(31); cmpwi 0,0; beq 1f; 0:; mr 4,31; bl _s8033A3B0_0; 1:; lis 3,-32691; lwz 4,0x48(31); addi 3,3,21688; bl _s8033A3B0_1; 2:; lwz 0,0x14(1); mtspr 8,0; lwz 31,0xc(1); addi 1,1,16"
extern "C" void _s8033A3B0_0();
extern "C" void _s8033A3B0_1();
extern "C" void f_8033A3B0() {}
