// 0x803642C4 EFontData::Read(EStream (284 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-16(1); mfspr 0,8; stmw 30,0x8(1); stw 0,0x14(1); mr 31,3; mr 30,4; bl _s803642C4_0; lis 9,-32688; lhz 0,-10422(9); cmpwi 0,0; bne 0f; mr 3,30; addi 4,31,4; bl _s803642C4_1; mr 30,3; addi 4,31,16; lwz 9,0x18(30); li 5,4; lwz 0,0x34(9); lha 3,0x30(9); mtspr 8,0; add 3,30,3; blrl; lwz 9,0x18(30); addi 4,31,20; li 5,4; lwz 0,0x34(9); lha 3,0x30(9); mtspr 8,0; add 3,30,3; blrl; lwz 9,0x18(30); addi 4,31,32; li 5,4; lwz 0,0x34(9); lha 3,0x30(9); mtspr 8,0; add 3,30,3; blrl; lwz 9,0x18(30); addi 4,31,24; li 5,4; lwz 0,0x34(9); lha 3,0x30(9); mtspr 8,0; add 3,30,3; blrl; lwz 9,0x18(30); addi 4,31,28; li 5,4; lwz 0,0x34(9); lha 3,0x30(9); mtspr 8,0; add 3,30,3; blrl; lwz 9,0x18(30); addi 4,31,36; li 5,4; lha 3,0x30(9); lwz 0,0x34(9); add 3,30,3; mtspr 8,0; blrl; mr 3,30; addi 4,31,40; bl _s803642C4_2; 0:; lwz 0,0x14(1); mtspr 8,0; lmw 30,0x8(1); addi 1,1,16"
extern "C" void _s803642C4_0();
extern "C" void _s803642C4_1();
extern "C" void _s803642C4_2();
extern "C" void f_803642C4() {}
