// 0x800137C0 AwarenessManager::UpdateAwarenessAngle(unsigned (416 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-16(1); mfspr 0,8; stmw 30,0x8(1); stw 0,0x14(1); mr 31,3; lwz 0,0x1c(31); cmpwi 0,0; beq 8f; lwz 0,0x0(31); andi. 9,0,2048; bne 7f; cmpwi 4,5; li 30,1; beq 3f; lwz 3,0x34(31); lwz 9,0x4(3); lha 0,0x330(9); lwz 9,0x334(9); add 3,3,0; mtspr 8,9; blrl; cmpwi 3,1; beq 3f; lwz 3,0x34(31); lwz 9,0x4(3); lha 0,0x350(9); lwz 9,0x354(9); add 3,3,0; mtspr 8,9; blrl; cmpwi 3,1; beq 3f; lwz 3,0x34(31); lwz 9,0x4(3); lha 0,0xf0(9); lwz 9,0xf4(9); add 3,3,0; mtspr 8,9; blrl; cmpwi 3,0; beq 0f; lwz 9,0x4(31); lwz 0,0x10(9); cmpwi 0,1; bne 3f; 0:; lwz 11,0x8(31); lwz 9,0x8(11); cmpwi 9,0; blt 1f; mulli 9,9,176; lwz 0,0x44(11); add 9,0,9; b 2f; 1:; li 9,0; 2:; cmpwi 9,0; beq 3f; lwz 0,0x8(9); andi. 9,0,512; beq 4f; 3:; li 30,0; 4:; cmpwi 30,0; beq 7f; lwz 0,0x18(31); li 4,1024; li 30,0; cmpwi 0,3; bne 5f; li 4,128; 5:; cmpwi 0,1; ble 6f; lwz 0,0x0(31); andi. 9,0,16; bne 6f; lwz 3,0x8(31); bl _s800137C0_0; cmpwi 3,0; beq 6f; li 30,1; 6:; cmpwi 30,0; bne 7f; lwz 4,0x1c(31); mr 3,31; bl _s800137C0_1; cmpwi 3,0; beq 7f; lwz 0,0x0(31); andi. 9,0,2; bne 9f; ori 0,0,6; stw 0,0x0(31); b 9f; 7:; mr 3,31; bl _s800137C0_2; mr 3,31; bl _s800137C0_3; b 9f; 8:; lis 9,-32707; lfs f0,-8960(9); stfs f0,0x20(31); 9:; lwz 0,0x14(1); mtspr 8,0; lmw 30,0x8(1); addi 1,1,16"
extern "C" void _s800137C0_0();
extern "C" void _s800137C0_1();
extern "C" void _s800137C0_2();
extern "C" void _s800137C0_3();
extern "C" void f_800137C0() {}
