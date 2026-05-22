// 0x801D1F54 PCTTarget::cCellInfo::Init(ObjSelector (288 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-24(1); mfspr 0,8; stmw 28,0x8(1); stw 0,0x1c(1); mr 31,3; mr 29,5; mr. 28,4; beq 2f; li 0,1; stw 28,0x14(31); stw 0,0x0(31); mr 3,28; bl _s801D1F54_0; lis 0,-10852; mr 4,3; ori 0,0,31669; stw 4,0x4(31); stw 0,0x8(31); lwz 9,0x0(29); lha 3,0x8(9); lwz 0,0xc(9); add 3,29,3; mtspr 8,0; blrl; mr 30,3; cmpwi 30,-1; beq 0f; lis 9,-32697; lwz 0,0x618c(9); cmpwi 0,0; bne 0f; lwz 9,0x0(29); li 4,5; mr 5,30; lha 3,0x28(9); lwz 0,0x2c(9); add 3,29,3; mtspr 8,0; blrl; xori 3,3,1; cmpwi 3,0; stw 3,0xc(31); bne 1f; lwz 9,0x0(29); mr 5,30; li 4,5; lha 3,0x40(9); lwz 0,0x44(9); add 3,29,3; mtspr 8,0; blrl; stw 3,0x10(31); b 1f; 0:; li 0,0; stw 0,0x10(31); stw 0,0xc(31); 1:; mr 3,28; bl _s801D1F54_1; mr. 3,3; beq 2f; lwz 3,0x1c(3); cmpwi 3,0; beq 2f; stw 3,0x8(31); li 3,1; b 3f; 2:; li 3,0; 3:; lwz 0,0x1c(1); mtspr 8,0; lmw 28,0x8(1); addi 1,1,24"
extern "C" void _s801D1F54_0();
extern "C" void _s801D1F54_1();
extern "C" void f_801D1F54() {}
