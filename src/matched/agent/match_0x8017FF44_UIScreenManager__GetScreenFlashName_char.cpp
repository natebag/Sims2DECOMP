// 0x8017FF44 UIScreenManager::GetScreenFlashName(char (248 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-32(1); mfspr 0,8; stmw 27,0xc(1); stw 0,0x24(1); mr 30,4; li 27,0; mr 4,5; bl _s8017FF44_0; mr. 29,3; beq 6f; lwz 3,0x10(29); cmpwi 3,0; bne 1f; lwz 4,0x14(29); cmpwi 4,0; beq 0f; mr 3,30; li 27,1; bl _s8017FF44_1; b 6f; 0:; lis 9,-32706; addi 11,9,15204; lwz 0,0x3b64(9); lhz 10,0x4(11); stw 0,0x0(30); sth 10,0x4(30); b 6f; 1:; mr 31,3; li 28,0; b 3f; 2:; cmpwi 28,0; bne 6f; 3:; lwz 3,0x0(31); lis 4,-32706; addi 4,4,15212; bl _s8017FF44_2; cmpwi 3,0; bne 4f; lbz 9,0xf(29); addi 3,30,1; li 27,1; addi 9,9,48; stb 9,0x0(30); lwzu 4,0x4(31); bl _s8017FF44_3; b 5f; 4:; lwz 3,0x0(31); lis 4,-32706; addi 4,4,15224; bl _s8017FF44_4; cmpwi 3,0; bne 5f; li 28,1; 5:; addi 31,31,4; cmpwi 27,0; beq 2b; 6:; mr 3,27; lwz 0,0x24(1); mtspr 8,0; lmw 27,0xc(1); addi 1,1,32"
extern "C" void _s8017FF44_0();
extern "C" void _s8017FF44_1();
extern "C" void _s8017FF44_2();
extern "C" void _s8017FF44_3();
extern "C" void _s8017FF44_4();
extern "C" void f_8017FF44() {}
