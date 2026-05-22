// 0x80074B30 SimRenderer::Render(ERC (196 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-32(1); mfspr 0,8; stmw 27,0xc(1); stw 0,0x24(1); mr 30,3; mr 29,4; mr 28,6; mr 27,7; mr 31,8; mr. 11,5; beq 0f; lwz 9,0xf0(11); mr 4,30; li 5,0; lha 3,0x10(9); lwz 0,0x14(9); add 3,11,3; mtspr 8,0; blrl; 0:; mr 4,31; mr 3,29; bl _s80074B30_0; lwz 9,0x70(30); mr 4,28; mr 5,27; lha 3,0xd8(9); lwz 0,0xdc(9); add 3,30,3; mtspr 8,0; blrl; lis 9,-32707; addi 31,9,22320; addi 28,31,100; 1:; lwz 0,0x0(31); addi 31,31,4; rlwinm 0,0,2,0,29; lwzx 3,29,0; cmpwi 3,0; beq 2f; mr 4,30; li 5,0; bl _s80074B30_1; 2:; cmplw 31,28; ble 1b; lwz 0,0x24(1); mtspr 8,0; lmw 27,0xc(1); addi 1,1,32"
extern "C" void _s80074B30_0();
extern "C" void _s80074B30_1();
extern "C" void f_80074B30() {}
