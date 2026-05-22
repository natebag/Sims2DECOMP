// 0x8021ADE4 InteractorModule::PlacementObject::GrabExistingObjectInstanceFromId(short) (276 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-24(1); mfspr 0,8; stmw 29,0xc(1); stw 0,0x1c(1); mr 31,3; mr 3,4; bl _s8021ADE4_0; mr. 29,3; beq 1f; lwz 3,0x4(29); bl _s8021ADE4_1; mr. 29,3; beq 1f; lwz 3,0x4(29); lwz 9,0x4(3); lha 0,0x158(9); lwz 9,0x15c(9); add 3,3,0; mtspr 8,9; blrl; cmpwi 3,0; beq 0f; lwz 3,0x4(29); addi 30,31,8; mr 4,30; stw 3,0x0(31); lwz 9,0x4(3); lha 0,0x338(9); lwz 9,0x33c(9); add 3,3,0; mtspr 8,9; blrl; lwz 11,0x0(31); li 4,1; lwz 9,0x4(11); lwz 0,0x264(9); lha 3,0x260(9); mtspr 8,0; add 3,11,3; blrl; sth 3,0x10(31); lwz 11,0x0(31); lwz 9,0x4(11); lha 3,0x390(9); lwz 0,0x394(9); add 3,11,3; mtspr 8,0; blrl; lwz 5,0x4(29); mr 4,30; mr 3,31; bl _s8021ADE4_2; lwz 3,0x0(31); bl _s8021ADE4_3; li 3,1; b 2f; 0:; lwz 3,0x4(29); lwz 9,0x4(3); lha 0,0x158(9); lwz 9,0x15c(9); add 3,3,0; mtspr 8,9; blrl; 1:; li 3,0; 2:; lwz 0,0x1c(1); mtspr 8,0; lmw 29,0xc(1); addi 1,1,24"
extern "C" void _s8021ADE4_0();
extern "C" void _s8021ADE4_1();
extern "C" void _s8021ADE4_2();
extern "C" void _s8021ADE4_3();
extern "C" void f_8021ADE4() {}
