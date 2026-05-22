// 0x80074D48 SimRenderer::RenderGhosted(ERC (152 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-24(1); mfspr 0,8; stmw 28,0x8(1); stw 0,0x1c(1); mr 31,3; mr 28,4; mr 30,5; mr 29,6; mr 4,7; mr 3,28; bl _s80074D48_0; lwz 9,0x70(31); mr 4,30; mr 5,29; lha 3,0xd8(9); lwz 0,0xdc(9); add 3,31,3; mtspr 8,0; blrl; lis 9,-32707; addi 30,9,22320; addi 29,30,100; 0:; lwz 0,0x0(30); addi 30,30,4; rlwinm 0,0,2,0,29; lwzx 3,28,0; cmpwi 3,0; beq 1f; mr 4,31; li 5,0; bl _s80074D48_1; 1:; cmpw 30,29; ble 0b; lwz 0,0x1c(1); mtspr 8,0; lmw 28,0x8(1); addi 1,1,24"
extern "C" void _s80074D48_0();
extern "C" void _s80074D48_1();
extern "C" void f_80074D48() {}
