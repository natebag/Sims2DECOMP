// 0x8000DD44 AptShaderWord::SetShader(int) (152 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-24(1); mfspr 0,8; stmw 30,0x10(1); stw 0,0x1c(1); mr 31,3; lwz 30,-32708(13); lis 3,-32688; stw 4,0x34(31); addi 3,3,-1792; bl _s8000DD44_0; mr 5,3; mr 4,30; addi 3,1,8; li 6,1; li 7,0; li 8,0; bl _s8000DD44_1; lfs f0,0xc(1); lwz 3,0x34(31); stfs f0,0x28(31); bl _s8000DD44_2; lfs f0,0x28(31); fcmpu 0,f0,f1; bge 0f; lwz 3,0x34(31); bl _s8000DD44_3; stfs f1,0x28(31); 0:; bl _s8000DD44_4; lfs f0,0x28(31); lfs f13,0x30(31); fdivs f0,f0,f1; fadds f0,f0,f13; stfs f0,0x24(31); lwz 0,0x1c(1); mtspr 8,0; lmw 30,0x10(1); addi 1,1,24"
extern "C" void _s8000DD44_0();
extern "C" void _s8000DD44_1();
extern "C" void _s8000DD44_2();
extern "C" void _s8000DD44_3();
extern "C" void _s8000DD44_4();
extern "C" void f_8000DD44() {}
