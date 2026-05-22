// 0x802B3D84 AptValue::isMCInParentChain(void) (244 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-24(1); mfspr 0,8; stmw 29,0xc(1); stw 0,0x1c(1); lwz 9,-26996(13); lis 30,-32694; addi 30,30,-11332; mr 31,3; addi 4,30,376; addi 3,9,12; bl _s802B3D84_0; lwz 9,0x8(3); lha 0,0x20(9); lwz 9,0x24(9); add 3,3,0; mtspr 8,9; blrl; lwz 29,0xc(3); addi 4,30,400; lwz 3,-26996(13); addi 3,3,12; bl _s802B3D84_1; lwz 9,0x8(3); lha 0,0x20(9); lwz 9,0x24(9); add 3,3,0; mtspr 8,9; blrl; lwz 30,0xc(3); cmpw 31,29; bne 1f; 0:; li 3,1; b 4f; 1:; lwz 9,0x8(31); lha 3,0x20(9); lwz 0,0x24(9); add 3,31,3; mtspr 8,0; blrl; 2:; cmpwi 3,0; beq 3f; lwz 11,0x8(3); cmpwi 11,0; beq 3f; cmpw 11,29; beq 0b; cmpw 11,30; beq 3f; lwz 9,0x8(11); lha 3,0x20(9); lwz 0,0x24(9); add 3,11,3; mtspr 8,0; blrl; b 2b; 3:; li 3,0; 4:; lwz 0,0x1c(1); mtspr 8,0; lmw 29,0xc(1); addi 1,1,24"
extern "C" void _s802B3D84_0();
extern "C" void _s802B3D84_1();
extern "C" void f_802B3D84() {}
