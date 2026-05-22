// 0x80355B34 Effects::FastParticleEmitter::Render(ERC (104 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-80(1); mfspr 0,8; stmw 30,0x48(1); stw 0,0x54(1); mr 31,3; mr 30,4; lwz 9,0x18c(31); lwz 0,0x4c(9); andi. 9,0,24; beq 0f; addi 3,1,8; bl _s80355B34_0; addi 3,31,80; addi 4,1,8; mr 5,3; bl _s80355B34_1; mr 3,31; bl _s80355B34_2; 0:; mr 3,31; mr 4,30; bl _s80355B34_3; lwz 0,0x54(1); mtspr 8,0; lmw 30,0x48(1); addi 1,1,80"
extern "C" void _s80355B34_0();
extern "C" void _s80355B34_1();
extern "C" void _s80355B34_2();
extern "C" void _s80355B34_3();
extern "C" void f_80355B34() {}
