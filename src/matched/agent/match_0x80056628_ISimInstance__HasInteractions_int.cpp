// 0x80056628 ISimInstance::HasInteractions(int) (272 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-40(1); mfspr 0,8; stmw 27,0x14(1); stw 0,0x2c(1); mr 29,3; mr 30,4; bl _s80056628_0; mr 31,3; lwz 3,-21496(13); lwz 9,0x0(3); lha 0,0x78(9); lwz 9,0x7c(9); add 3,3,0; mtspr 8,9; blrl; cmpwi 3,0; bne 0f; rlwinm 28,30,2,0,29; addi 27,29,940; lwzx 9,27,28; lwz 0,-26812(13); cmpw 9,0; ble 1f; 0:; rlwinm 0,30,2,0,29; addi 9,29,948; lwzx 31,9,0; b 4f; 1:; addi 3,1,8; bl _s80056628_1; addi 3,1,8; bl _s80056628_2; lwz 9,0x4(31); li 4,34; lha 3,0x260(9); lwz 0,0x264(9); add 3,31,3; mtspr 8,0; blrl; cmpwi 3,0; bne 2f; mr 3,31; mr 5,30; addi 4,1,8; li 6,1; bl _s80056628_3; 2:; addi 3,1,8; li 31,0; bl _s80056628_4; cmpwi 3,0; beq 3f; li 31,1; 3:; addi 9,29,948; stwx 31,9,28; bl _s80056628_5; rlwinm 9,3,0,28,31; lwz 0,-26812(13); addi 9,9,10; addi 3,1,8; add 0,0,9; li 4,2; stwx 0,27,28; bl _s80056628_6; 4:; mr 3,31; lwz 0,0x2c(1); mtspr 8,0; lmw 27,0x14(1); addi 1,1,40"
extern "C" void _s80056628_0();
extern "C" void _s80056628_1();
extern "C" void _s80056628_2();
extern "C" void _s80056628_3();
extern "C" void _s80056628_4();
extern "C" void _s80056628_5();
extern "C" void _s80056628_6();
extern "C" void f_80056628() {}
