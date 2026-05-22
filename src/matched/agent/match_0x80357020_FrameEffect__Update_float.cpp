// 0x80357020 FrameEffect::Update(float, (148 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-16(1); mfspr 0,8; stmw 30,0x8(1); stw 0,0x14(1); mr 31,3; mr 30,4; lfs f0,0x8(31); fadds f0,f0,f1; stfs f0,0x8(31); bl _s80357020_0; cmpwi 3,0; beq 0f; lwz 9,0x10(31); lfs f1,0x8(31); lha 3,0x10(9); lwz 0,0x14(9); add 3,31,3; mtspr 8,0; blrl; 0:; mr 3,31; bl _s80357020_1; cmpwi 3,0; beq 1f; lwz 9,0x10(31); mr 4,30; lha 3,0x18(9); lwz 0,0x1c(9); add 3,31,3; mtspr 8,0; blrl; 1:; mr 3,31; bl _s80357020_2; lwz 0,0x14(1); mtspr 8,0; lmw 30,0x8(1); addi 1,1,16"
extern "C" void _s80357020_0();
extern "C" void _s80357020_1();
extern "C" void _s80357020_2();
extern "C" void f_80357020() {}
