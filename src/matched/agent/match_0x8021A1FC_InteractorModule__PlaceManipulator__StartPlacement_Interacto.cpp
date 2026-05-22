// 0x8021A1FC InteractorModule::PlaceManipulator::StartPlacement(InteractorModule::PlaceManipulator::PlaceManipulatorParams (332 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-32(1); mfspr 0,8; stmw 28,0x10(1); stw 0,0x24(1); mr 30,3; mr. 4,4; beq 5f; lwz 0,0xbc(30); addi 11,30,172; li 10,24; addi 28,30,100; stw 0,0x8(1); 0:; lwz 9,0x0(4); addic. 10,10,-24; stw 9,0x0(11); lwz 9,0x4(4); stw 9,0x4(11); lwz 9,0x8(4); stw 9,0x8(11); lwz 9,0xc(4); stw 9,0xc(11); lwz 9,0x10(4); stw 9,0x10(11); lwz 9,0x14(4); addi 4,4,24; stw 9,0x14(11); addi 11,11,24; bne 0b; lwz 9,0x0(4); mr 3,28; lwz 0,0x8(1); stw 9,0x0(11); lwz 9,0x4(4); stw 9,0x4(11); lwz 9,0x8(4); stw 9,0x8(11); lwz 9,0xc(4); stw 9,0xc(11); stw 0,0xbc(30); lwz 4,0xc0(30); lbz 5,0xc4(30); bl _s8021A1FC_0; cmpwi 3,0; beq 5f; lwz 0,0xc8(30); cmpwi 0,0; beq 3f; lwz 31,0x64(30); cmpwi 31,0; beq 3f; li 29,0; b 2f; 1:; mr 3,28; li 4,0; bl _s8021A1FC_1; addi 29,29,1; 2:; cmplwi 29,3; bgt 3f; lwz 9,0x4(31); li 4,1; lwz 0,0x264(9); lha 3,0x260(9); mtspr 8,0; add 3,31,3; blrl; lha 0,0xcc(30); cmpw 3,0; bne 1b; 3:; lis 9,-32697; lwz 0,0x618c(9); cmpwi 0,0; beq 4f; lwz 4,0x64(30); mr 3,30; bl _s8021A1FC_2; 4:; mr 3,30; li 4,0; bl _s8021A1FC_3; 5:; lwz 0,0x24(1); mtspr 8,0; lmw 28,0x10(1); addi 1,1,32"
extern "C" void _s8021A1FC_0();
extern "C" void _s8021A1FC_1();
extern "C" void _s8021A1FC_2();
extern "C" void _s8021A1FC_3();
extern "C" void f_8021A1FC() {}
