// 0x8013398C ReconBuffer::ReconMark(void) (268 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-16(1); mfspr 0,8; stw 31,0xc(1); stw 0,0x14(1); mr 31,3; lwz 0,0x18(31); cmpwi 0,0; beq 0f; bl _s8013398C_0; 0:; lwz 0,0xc(31); cmpwi 0,2; beq 3f; cmpwi 0,1; bne 2f; lwz 11,0x2c(31); cmpwi 11,0; beq 1f; lwz 9,0x0(31); lbz 0,0x8(31); add 3,9,11; stbx 0,9,11; addi 11,3,1; lbz 0,0x9(31); stb 0,0x1(3); lbz 9,0xa(31); stbu 9,0x1(11); lbz 0,0xb(31); stb 0,0x1(11); lwz 9,0x10(31); cmpwi 9,0; beq 1f; bl _s8013398C_1; 1:; lwz 9,0x8(31); li 0,0; lwz 11,0x0(31); stw 9,0x2c(31); stbx 0,11,9; add 11,11,9; stbu 0,0x1(11); stbu 0,0x1(11); addi 11,11,1; stb 0,0x0(11); b 3f; 2:; lwz 9,0x8(31); addi 3,31,44; lwz 11,0x0(31); lwz 0,0x10(31); lbzx 10,11,9; add 11,11,9; cmpwi 0,0; stb 10,0x2c(31); lbzu 0,0x1(11); stb 0,0x2d(31); lbzu 9,0x1(11); stb 9,0x2e(31); lbz 0,0x1(11); stb 0,0x2f(31); beq 3f; bl _s8013398C_2; 3:; lwz 9,0x8(31); addi 9,9,4; stw 9,0x8(31); lwz 0,0x14(1); mtspr 8,0; lwz 31,0xc(1); addi 1,1,16"
extern "C" void _s8013398C_0();
extern "C" void _s8013398C_1();
extern "C" void _s8013398C_2();
extern "C" void f_8013398C() {}
