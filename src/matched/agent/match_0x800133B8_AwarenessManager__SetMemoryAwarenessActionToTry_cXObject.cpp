// 0x800133B8 AwarenessManager::SetMemoryAwarenessActionToTry(cXObject (320 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-24(1); mfspr 0,8; stw 31,0x14(1); stw 0,0x1c(1); mr 31,3; li 0,0; stw 0,0x8(1); addi 5,31,20; addi 6,1,8; bl _s800133B8_0; lwz 9,0x8(1); cmpwi 9,1; ble 11f; lwz 0,0x14(31); cmpwi 0,-1; beq 11f; cmpwi 9,5; bgt 0f; cmpwi 9,4; bge 3f; cmpwi 9,2; blt 1f; b 2f; 0:; cmpwi 9,7; ble 5f; 1:; li 0,0; b 10f; 2:; li 0,1; b 10f; 3:; lwz 3,0x4(31); bl _s800133B8_1; cmpwi 3,0; bne 4f; lwz 3,0x4(31); bl _s800133B8_2; cmpwi 3,0; beq 9f; 4:; li 0,1; b 10f; 5:; lwz 3,0x4(31); bl _s800133B8_3; cmpwi 3,0; bne 6f; lwz 3,0x4(31); bl _s800133B8_4; cmpwi 3,0; beq 7f; 6:; li 0,1; b 10f; 7:; lwz 9,0x4(31); lwz 0,0x10(9); cmpwi 0,1; beq 8f; lwz 3,0x34(31); lwz 9,0x4(3); lha 0,0x168(9); lwz 9,0x16c(9); add 3,3,0; mtspr 8,9; blrl; cmpwi 3,0; beq 8f; lwz 3,0x34(31); lwz 9,0x4(3); lha 0,0x168(9); lwz 9,0x16c(9); add 3,3,0; mtspr 8,9; blrl; cmpwi 3,3; bne 9f; 8:; li 0,3; b 10f; 9:; li 0,2; 10:; stw 0,0x18(31); 11:; lwz 0,0x1c(1); mtspr 8,0; lwz 31,0x14(1); addi 1,1,24"
extern "C" void _s800133B8_0();
extern "C" void _s800133B8_1();
extern "C" void _s800133B8_2();
extern "C" void _s800133B8_3();
extern "C" void _s800133B8_4();
extern "C" void f_800133B8() {}
