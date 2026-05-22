// 0x8021ACC4 InteractorModule::PlacementObject::CreateNewPlacementObjectFromGuid(unsigned (288 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-24(1); mfspr 0,8; stmw 29,0xc(1); stw 0,0x1c(1); mr 31,3; mr 30,5; lwz 0,0x0(31); li 3,0; cmpwi 0,0; bne 2f; mr 3,4; bl _s8021ACC4_0; stw 3,0x0(31); cmpwi 3,0; beq 1f; mr 4,3; mr 5,30; mr 3,31; bl _s8021ACC4_1; lwz 11,0x0(31); lwz 9,0x4(11); lha 3,0x340(9); lwz 0,0x344(9); add 3,11,3; mtspr 8,0; blrl; mr 4,3; lwz 5,0x0(31); mr 3,31; bl _s8021ACC4_2; lis 9,-32697; lwz 9,0x5bf8(9); cmpwi 9,0; beq 0f; lwz 0,0x90(9); cmpwi 0,2; bne 0f; lwz 0,0x84(9); lis 9,-32697; lwz 29,0x0(31); addi 9,9,24012; rlwinm 0,0,2,0,29; addi 9,9,188; lwz 30,0x4(29); lwzx 11,9,0; lha 0,0x1f8(30); lwz 9,0x4(11); addi 30,30,504; add 29,29,0; lha 3,0x1b0(9); lwz 9,0x1b4(9); add 3,11,3; mtspr 8,9; blrl; lwz 0,0x4(30); mr 5,3; mr 3,29; li 4,0; mtspr 8,0; blrl; 0:; lwz 3,0x0(31); bl _s8021ACC4_3; 1:; lwz 0,0x0(31); li 3,1; cmpwi 0,0; bne 2f; li 3,0; 2:; lwz 0,0x1c(1); mtspr 8,0; lmw 29,0xc(1); addi 1,1,24"
extern "C" void _s8021ACC4_0();
extern "C" void _s8021ACC4_1();
extern "C" void _s8021ACC4_2();
extern "C" void _s8021ACC4_3();
extern "C" void f_8021ACC4() {}
