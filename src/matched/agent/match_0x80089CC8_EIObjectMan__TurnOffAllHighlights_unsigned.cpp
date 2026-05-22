// 0x80089CC8 EIObjectMan::TurnOffAllHighlights(unsigned (352 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="bl _s80089CC8_0; lwz 0,0x14(1); mtspr 8,0; lmw 30,0x8(1); addi 1,1,16; blr; stwu 1,-16(1); mfspr 0,8; stw 31,0xc(1); stw 0,0x14(1); lis 9,-32697; mr 31,3; lwz 3,0x5ee0(9); cmpwi 3,0; beq 0f; bl _s80089CC8_1; 0:; lwz 9,0x0(31); lwz 10,0x0(9); lwz 11,0x8(10); lha 3,0x18(11); lwz 0,0x1c(11); add 3,10,3; mtspr 8,0; blrl; lwz 0,0x14(1); mtspr 8,0; lwz 31,0xc(1); addi 1,1,16; blr; stwu 1,-8(1); mfspr 0,8; stw 0,0xc(1); lwz 11,0x0(3); lwz 10,0x0(11); lwz 9,0x8(10); lha 3,0x20(9); lwz 0,0x24(9); add 3,10,3; mtspr 8,0; blrl; lwz 0,0xc(1); mtspr 8,0; addi 1,1,8; blr; stwu 1,-16(1); lis 9,-32698; mr 11,3; li 0,0; addi 9,9,-10640; stw 9,0x8(11); stw 0,0x0(11); stw 0,0x8(1); addi 1,1,16; blr; stwu 1,-16(1); mfspr 0,8; stmw 30,0x8(1); stw 0,0x14(1); mr 30,3; bl _s80089CC8_2; mr 4,30; li 5,1; li 6,0; bl _s80089CC8_3; lwz 0,0x14(1); mtspr 8,0; lmw 30,0x8(1); addi 1,1,16; blr; stwu 1,-16(1); mfspr 0,8; stmw 30,0x8(1); stw 0,0x14(1); mr 30,3; bl _s80089CC8_4; mr 4,30; bl _s80089CC8_5; lwz 0,0x14(1); mtspr 8,0; lmw 30,0x8(1); addi 1,1,16; blr; lwz 0,0x0(4); mr 9,3; stw 0,0x0(9); blr; li 3,0"
extern "C" void _s80089CC8_0();
extern "C" void _s80089CC8_1();
extern "C" void _s80089CC8_2();
extern "C" void _s80089CC8_3();
extern "C" void _s80089CC8_4();
extern "C" void _s80089CC8_5();
extern "C" void f_80089CC8() {}
