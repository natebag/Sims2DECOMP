// 0x800B1194 cSoundModeManager::Update(void) (392 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-16(1); mfspr 0,8; stmw 30,0x8(1); stw 0,0x14(1); lis 9,-32697; mr 31,3; lwz 0,0x5c0c(9); cmpwi 0,0; beq 8f; lwz 9,-21492(13); cmpwi 9,0; beq 0f; lwz 0,0xc(9); cmpwi 0,0; beq 0f; lwz 0,0x0(31); cmpwi 0,6; bne 8f; 0:; mr 3,31; bl _s800B1194_0; mr 3,31; bl _s800B1194_1; mr 3,31; bl _s800B1194_2; lwz 0,0x0(31); cmpwi 0,5; beq 1f; lwz 0,-26748(13); cmpwi 0,0; beq 2f; 1:; lwz 3,-26564(13); lwz 9,0x0(3); lha 0,0x80(9); lwz 9,0x84(9); add 3,3,0; mtspr 8,9; blrl; cmpwi 3,0; beq 8f; lwz 3,-26564(13); lwz 9,0x0(3); lha 0,0x48(9); lwz 9,0x4c(9); add 3,3,0; mtspr 8,9; blrl; b 8f; 2:; lis 9,-32697; addi 30,9,24012; lwz 11,0x148(30); lbz 0,0x1d(11); cmpwi 0,0; beq 8f; lwz 3,-26564(13); lwz 9,0x0(3); lha 0,0x80(9); lwz 9,0x84(9); add 3,3,0; mtspr 8,9; blrl; cmpwi 3,0; bne 8f; lwz 0,0x0(31); cmpwi 0,2; beq 4f; bgt 3f; cmpwi 0,1; beq 7f; b 8f; 3:; cmpwi 0,4; beq 5f; cmpwi 0,6; beq 6f; b 8f; 4:; mr 3,31; li 4,0; bl _s800B1194_3; b 8f; 5:; mr 3,31; bl _s800B1194_4; b 8f; 6:; mr 3,31; bl _s800B1194_5; b 8f; 7:; lwz 0,-32112(13); cmpwi 0,0; beq 8f; lwz 9,0xc8(30); lwz 0,0x54(9); cmpwi 0,9; bne 8f; mr 3,31; bl _s800B1194_6; 8:; lwz 0,0x14(1); mtspr 8,0; lmw 30,0x8(1); addi 1,1,16"
extern "C" void _s800B1194_0();
extern "C" void _s800B1194_1();
extern "C" void _s800B1194_2();
extern "C" void _s800B1194_3();
extern "C" void _s800B1194_4();
extern "C" void _s800B1194_5();
extern "C" void _s800B1194_6();
extern "C" void f_800B1194() {}
