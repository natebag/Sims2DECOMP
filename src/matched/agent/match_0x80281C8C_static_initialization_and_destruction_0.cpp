// 0x80281C8C __static_initialization_and_destruction_0 (144 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-8(1); mfspr 0,8; stw 0,0xc(1); li 0,0; ori 0,0,65535; cmpw 4,0; bne 1f; cmpwi 3,0; beq 0f; lis 11,-32694; li 0,0; addi 9,11,-16032; stw 0,-16032(11); addi 10,9,12; addi 8,9,36; stw 0,0x8(10); addi 11,9,24; stw 0,0x8(8); stw 0,0x8(11); stw 0,0x24(9); stw 0,0x4(9); stw 0,0x8(9); stw 0,0xc(9); stw 0,0x4(10); stw 0,0x18(9); stw 0,0x4(11); stw 0,0x4(8); b 1f; 0:; lis 3,-32694; li 4,2; addi 3,3,-16032; bl _s80281C8C_0; 1:; lwz 0,0xc(1); mtspr 8,0; addi 1,1,8"
extern "C" void _s80281C8C_0();
extern "C" void f_80281C8C() {}
