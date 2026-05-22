// 0x8015D8F8 TreeTableEntryQuickData::TreeTableEntryQuickData(TreeTableEntry (308 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-48(1); mfspr 0,8; stmw 27,0x1c(1); stw 0,0x34(1); lis 9,-32698; mr 27,3; li 0,0; addi 9,9,23688; addi 28,27,8; stw 9,0x0(27); stw 4,0x4(27); addi 11,28,8; stw 0,0x8(27); cmpwi 4,0; stw 0,0x4(28); stw 0,0x4(11); stw 0,0x18(27); beq 5f; stw 0,0x10(1); addi 6,1,16; lwz 9,0x8(27); lwz 4,0x4(28); subf 0,9,4; srawi 0,0,2; cmplwi 0,16; ble 3f; addi 29,9,64; lwz 30,0x4(28); mr 31,29; cmpw 29,30; beq 2f; 0:; lwz 11,0x0(31); cmpwi 11,0; beq 1f; lwz 9,0x0(11); lha 3,0x18(9); lwz 0,0x1c(9); add 3,11,3; mtspr 8,0; blrl; 1:; addi 31,31,4; cmpw 31,30; bne 0b; 2:; stw 29,0x4(28); b 4f; 3:; mr 3,28; subfic 5,0,16; bl _s8015D8F8_0; 4:; lwz 11,0x10(1); cmpwi 11,0; beq 5f; lwz 9,0x0(11); lha 3,0x18(9); lwz 0,0x1c(9); add 3,11,3; mtspr 8,0; blrl; 5:; lwz 0,-31588(13); cmpwi 0,0; bne 6f; li 3,12; bl _s8015D8F8_1; addi 4,13,-23880; bl _s8015D8F8_2; lwz 9,0x0(3); stw 3,-31588(13); lha 0,0x10(9); lwz 9,0x14(9); add 3,3,0; mtspr 8,9; blrl; 6:; mr 3,27; lwz 0,0x34(1); mtspr 8,0; lmw 27,0x1c(1); addi 1,1,48"
extern "C" void _s8015D8F8_0();
extern "C" void _s8015D8F8_1();
extern "C" void _s8015D8F8_2();
extern "C" void f_8015D8F8() {}
