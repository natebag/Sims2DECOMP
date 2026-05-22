// 0x803643E0 EFontData::Load(EFile (388 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-56(1); mfspr 0,8; stmw 23,0x14(1); stw 0,0x3c(1); mr 31,3; mr 30,4; bl _s803643E0_0; lis 9,-32688; lhz 0,-10422(9); cmpwi 0,0; bne 2f; addi 29,31,4; addi 23,31,40; mr 3,29; addi 28,31,16; bl _s803643E0_1; addi 27,31,20; lwz 9,0x28(30); addi 4,1,8; li 5,4; addi 26,31,32; lha 3,0x18(9); addi 25,31,24; lwz 0,0x1c(9); addi 24,31,28; add 3,30,3; addi 31,31,36; mtspr 8,0; blrl; b 1f; 0:; addi 4,1,12; mr 3,30; bl _s803643E0_2; lwz 4,0xc(1); mr 3,29; bl _s803643E0_3; 1:; lwz 9,0x8(1); addi 9,9,-1; cmpwi 9,-1; stw 9,0x8(1); bne 0b; lwz 9,0x28(30); mr 4,28; li 5,4; lwz 0,0x1c(9); lha 3,0x18(9); mtspr 8,0; add 3,30,3; blrl; lwz 9,0x28(30); mr 4,27; li 5,4; lwz 0,0x1c(9); lha 3,0x18(9); mtspr 8,0; add 3,30,3; blrl; lwz 9,0x28(30); mr 4,26; li 5,4; lwz 0,0x1c(9); lha 3,0x18(9); mtspr 8,0; add 3,30,3; blrl; lwz 9,0x28(30); mr 4,25; li 5,4; lwz 0,0x1c(9); lha 3,0x18(9); mtspr 8,0; add 3,30,3; blrl; lwz 9,0x28(30); mr 4,24; li 5,4; lwz 0,0x1c(9); lha 3,0x18(9); mtspr 8,0; add 3,30,3; blrl; lwz 9,0x28(30); mr 4,31; li 5,4; lha 3,0x18(9); lwz 0,0x1c(9); add 3,30,3; mtspr 8,0; blrl; mr 3,30; mr 4,23; bl _s803643E0_4; 2:; lwz 0,0x3c(1); mtspr 8,0; lmw 23,0x14(1); addi 1,1,56"
extern "C" void _s803643E0_0();
extern "C" void _s803643E0_1();
extern "C" void _s803643E0_2();
extern "C" void _s803643E0_3();
extern "C" void _s803643E0_4();
extern "C" void f_803643E0() {}
