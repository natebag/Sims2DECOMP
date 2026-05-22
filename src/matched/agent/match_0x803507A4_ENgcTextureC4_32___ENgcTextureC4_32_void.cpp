// 0x803507A4 ENgcTextureC4_32::~ENgcTextureC4_32(void) (132 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-24(1); mfspr 0,8; stmw 29,0xc(1); stw 0,0x1c(1); mr 31,3; lis 9,-32697; addi 9,9,-11880; lwz 0,0x8(31); stw 9,0x24(31); mr 29,4; andi. 9,0,128; bne 0f; lis 30,-32692; lwz 4,0xcc(31); addi 3,30,-7364; bl _s803507A4_0; lwz 4,0xd0(31); addi 3,30,-7364; bl _s803507A4_1; 0:; mr 3,31; li 4,0; bl _s803507A4_2; andi. 0,29,1; beq 1f; lis 3,-32692; mr 4,31; addi 3,3,-7364; bl _s803507A4_3; 1:; lwz 0,0x1c(1); mtspr 8,0; lmw 29,0xc(1); addi 1,1,24"
extern "C" void _s803507A4_0();
extern "C" void _s803507A4_1();
extern "C" void _s803507A4_2();
extern "C" void _s803507A4_3();
extern "C" void f_803507A4() {}
