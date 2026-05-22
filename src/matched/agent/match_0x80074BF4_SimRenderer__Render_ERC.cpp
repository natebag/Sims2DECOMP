// 0x80074BF4 SimRenderer::Render(ERC (180 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-32(1); mfspr 0,8; stmw 26,0x8(1); stw 0,0x24(1); mr 29,3; mr 30,4; mr 27,5; mr 28,7; mr 31,8; mr. 6,6; beq 0f; lwz 9,0xf0(6); mr 4,29; li 5,0; lha 3,0x10(9); lwz 0,0x14(9); add 3,6,3; mtspr 8,0; blrl; 0:; mr 4,31; mr 3,30; bl _s80074BF4_0; lis 9,-32707; addi 31,9,22320; addi 26,31,100; 1:; lwz 0,0x0(31); addi 31,31,4; rlwinm 0,0,2,0,29; lwzx 5,30,0; cmpwi 5,0; beq 2f; lwz 5,0x120(5); cmpwi 5,0; beq 2f; mr 3,27; mr 4,29; mr 6,28; bl _s80074BF4_1; 2:; cmplw 31,26; ble 1b; lwz 0,0x24(1); mtspr 8,0; lmw 26,0x8(1); addi 1,1,32"
extern "C" void _s80074BF4_0();
extern "C" void _s80074BF4_1();
extern "C" void f_80074BF4() {}
