// 0x8004C150 EParticleObj::~EParticleObj(void) (168 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-24(1); mfspr 0,8; stmw 29,0xc(1); stw 0,0x1c(1); mr 30,3; mr 29,4; lwz 9,0x4(30); b 2f; 0:; lwz 0,0x8(30); lwz 3,0x0(9); cmpwi 0,0; lwz 31,0x4(9); beq 1f; cmpwi 3,0; beq 1f; li 4,3; bl _s8004C150_0; 1:; mr 9,31; 2:; li 31,1; cmpwi 9,0; bne 3f; li 31,0; 3:; cmpwi 31,0; bne 0b; mr 3,30; bl _s8004C150_1; lwz 3,0xc(30); cmpwi 3,0; beq 4f; bl _s8004C150_2; stw 31,0xc(30); 4:; mr 3,30; bl _s8004C150_3; andi. 0,29,1; beq 5f; mr 3,30; bl _s8004C150_4; 5:; lwz 0,0x1c(1); mtspr 8,0; lmw 29,0xc(1); addi 1,1,24"
extern "C" void _s8004C150_0();
extern "C" void _s8004C150_1();
extern "C" void _s8004C150_2();
extern "C" void _s8004C150_3();
extern "C" void _s8004C150_4();
extern "C" void f_8004C150() {}
