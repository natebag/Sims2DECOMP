// 0x80072EB8 SimModel::LoadAllMorphTargets(void) (372 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-80(1); mfspr 0,8; stmw 26,0x38(1); stw 0,0x54(1); mr 26,3; lwz 9,0x13c(26); lwz 11,0x138(26); lbz 0,0x8c(9); lwz 10,0x4(11); extsb 0,0; mulli 0,0,12; lwz 9,0x1c(10); add 31,9,0; addic. 27,31,8; beq 13f; lwz 9,0x8(31); li 0,0; cmpwi 9,0; beq 0f; lwz 0,-4(9); 0:; cmpwi 0,11; ble 13f; mr 3,26; bl _s80072EB8_0; lwz 9,0x8(31); mr 28,3; li 0,0; cmpwi 9,0; beq 1f; lwz 0,-4(9); 1:; cmpwi 0,14; bne 6f; li 31,0; li 30,0; addi 29,1,8; b 4f; 2:; addi 0,30,-9; cmplwi 0,1; ble 3f; rlwinm 9,30,2,0,29; mr 4,28; lwzx 3,11,9; bl _s80072EB8_1; rlwinm 0,31,2,0,29; addi 9,31,1; stwx 3,29,0; rlwinm 31,9,0,24,31; 3:; addi 30,30,1; 4:; lwz 11,0x0(27); li 0,0; cmpwi 11,0; beq 5f; lwz 0,-4(11); 5:; cmpw 30,0; blt 2b; b 10f; 6:; li 31,0; addi 29,1,8; b 8f; 7:; rlwinm 30,31,2,0,29; mr 4,28; lwzx 3,9,30; addi 31,31,1; bl _s80072EB8_2; stwx 3,29,30; 8:; lwz 9,0x0(27); li 0,0; cmpwi 9,0; beq 9f; lwz 0,-4(9); 9:; cmpw 31,0; blt 7b; 10:; lwz 9,0x6c(26); li 30,0; lwz 31,0x120(9); 11:; rlwinm 0,30,2,0,29; lwzx 4,29,0; cmpwi 4,0; beq 12f; mr 3,31; mr 5,30; bl _s80072EB8_3; mr 4,31; bl _s80072EB8_4; 12:; addi 0,30,1; rlwinm 30,0,0,24,31; cmplwi 30,11; ble 11b; 13:; lwz 0,0x54(1); mtspr 8,0; lmw 26,0x38(1); addi 1,1,80"
extern "C" void _s80072EB8_0();
extern "C" void _s80072EB8_1();
extern "C" void _s80072EB8_2();
extern "C" void _s80072EB8_3();
extern "C" void _s80072EB8_4();
extern "C" void f_80072EB8() {}
