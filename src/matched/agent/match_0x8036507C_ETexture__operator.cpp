// 0x8036507C ETexture::operator (48 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-8(1); mfspr 0,8; stw 0,0xc(1); mr 4,3; li 5,8; lis 3,-32692; addi 3,3,-7364; bl _s8036507C_0; lwz 0,0xc(1); mtspr 8,0; addi 1,1,8"
extern "C" void _s8036507C_0();
extern "C" void f_8036507C() {}
