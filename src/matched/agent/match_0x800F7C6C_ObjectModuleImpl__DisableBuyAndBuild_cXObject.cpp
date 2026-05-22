// 0x800F7C6C ObjectModuleImpl::DisableBuyAndBuild(cXObject (456 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-56(1); mfspr 0,8; stmw 25,0x1c(1); stw 0,0x3c(1); mr 27,3; mr 30,4; lwz 9,0x0(27); lha 3,0x220(9); lwz 0,0x224(9); add 3,27,3; mtspr 8,0; blrl; mr 25,3; cmpwi 30,0; beq 0f; lwz 9,0x4(30); lha 3,0x520(9); lwz 0,0x524(9); add 3,30,3; mtspr 8,0; blrl; b 1f; 0:; li 3,0; 1:; stw 3,0x8(1); addi 31,27,8244; addi 26,1,8; lwz 30,0x4(31); lwz 0,0xc(31); cmpw 30,0; beq 2f; stw 3,0x0(30); lwz 9,0x4(31); addi 9,9,4; stw 9,0x4(31); b 13f; 2:; lwz 0,0x2034(27); li 9,1; stw 9,0x10(1); addi 10,1,16; subf 0,0,30; addi 11,1,12; srawi 9,0,2; stw 9,0xc(1); cmplwi 9,1; bge 3f; mr 11,10; 3:; lwz 0,0x0(11); add. 0,9,0; beq 5f; rlwinm 0,0,2,0,29; mr 28,0; cmplwi 0,128; ble 4f; mr 3,28; bl _s800F7C6C_0; mr 29,3; b 6f; 4:; mr 3,28; bl _s800F7C6C_1; mr 29,3; b 6f; 5:; li 29,0; li 28,0; 6:; lwz 4,0x0(31); cmpw 30,4; beq 7f; subf 30,4,30; mr 3,29; mr 5,30; bl _s800F7C6C_2; add 0,3,30; b 8f; 7:; mr 0,29; 8:; lwz 9,0x10(1); mr 30,0; mtspr 9,9; cmpwi 9,0; beq 10f; 9:; lwz 0,0x0(26); stw 0,0x0(30); addi 30,30,4; bdnz 9b; 10:; lwz 3,0x0(31); lwz 0,0xc(31); cmpwi 3,0; subf 0,3,0; srawi 0,0,2; beq 12f; rlwinm 4,0,2,0,29; cmplwi 4,128; ble 11f; bl _s800F7C6C_3; b 12f; 11:; bl _s800F7C6C_4; 12:; add 0,28,29; stw 29,0x0(31); stw 0,0xc(31); stw 30,0x4(31); 13:; lwz 9,0x0(27); lha 3,0x220(9); lwz 0,0x224(9); add 3,27,3; mtspr 8,0; blrl; cmpw 25,3; beq 14f; li 3,260; li 4,0; bl _s800F7C6C_5; 14:; lwz 0,0x3c(1); mtspr 8,0; lmw 25,0x1c(1); addi 1,1,56"
extern "C" void _s800F7C6C_0();
extern "C" void _s800F7C6C_1();
extern "C" void _s800F7C6C_2();
extern "C" void _s800F7C6C_3();
extern "C" void _s800F7C6C_4();
extern "C" void _s800F7C6C_5();
extern "C" void f_800F7C6C() {}
