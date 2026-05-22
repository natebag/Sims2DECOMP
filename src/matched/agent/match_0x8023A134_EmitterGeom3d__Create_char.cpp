// 0x8023A134 EmitterGeom3d::Create(char (196 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-32(1); mfspr 0,8; stmw 28,0x10(1); stw 0,0x24(1); mr 31,3; mr 28,6; lis 30,-32732; addi 7,30,-24752; li 8,0; li 9,0; li 10,0; bl _s8023A134_0; mr 29,3; cmpwi 29,-1; beq 0f; mr 3,31; bl _s8023A134_1; li 0,0; mr 8,3; lis 5,-32732; lis 6,-32732; stw 0,0xc(1); addi 4,30,-24752; stw 0,0x8(1); li 9,0; addi 5,5,-25048; addi 6,6,-24816; li 7,0; li 10,0; mr 3,31; bl _s8023A134_2; mr 3,31; bl _s8023A134_3; mr 30,3; lwz 0,0x16c(28); lwz 4,0x88(30); mr 3,31; stw 0,0x80(30); bl _s8023A134_4; lwz 9,0x88(30); mr 3,29; lwz 0,0x108(9); oris 0,0,32; stw 0,0x108(9); 0:; lwz 0,0x24(1); mtspr 8,0; lmw 28,0x10(1); addi 1,1,32"
extern "C" void _s8023A134_0();
extern "C" void _s8023A134_1();
extern "C" void _s8023A134_2();
extern "C" void _s8023A134_3();
extern "C" void _s8023A134_4();
extern "C" void f_8023A134() {}
