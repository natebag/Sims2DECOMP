// 0x80386714 DoneCallback (804 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="mfspr 0,8; lis 4,-32688; stw 0,0x4(1); addi 4,4,-24000; addi 0,4,48; stwu 1,-136(1); cmplw 0,3; stw 31,0x84(1); li 31,0; stw 30,0x80(1); stw 29,0x7c(1); addi 29,4,0; stw 28,0x78(1); beq 0f; addi 0,4,320; cmplw 0,3; addi 4,4,272; addi 29,4,0; li 31,1; beq 0f; li 31,2; 0:; lwz 3,0x80(29); addi 0,3,47; rlwinm 3,0,0,0,26; lwz 30,0x20(3); bl _s80386714_0; lwz 0,0x2c(29); addi 28,3,0; addi 6,28,0; xor 0,30,0; rlwinm 4,0,0,0,15; addi 3,31,0; addi 5,1,52; li 7,1; bl _s80386714_1; cmpwi 3,0; bge 1f; mr 3,31; bl _s80386714_2; addi 3,31,0; li 4,-3; bl _s80386714_3; b 9f; 1:; lwz 4,0x14(29); li 3,0; lwz 0,0x2c(29); add 4,28,4; addi 4,4,4; rlwinm 4,4,3,0,28; addi 4,4,1; cmplwi 4,0; ble 5f; cmplwi 4,8; addi 6,4,-8; ble 3f; addi 5,6,7; rlwinm 5,5,29,3,31; cmplwi 6,0; mtspr 9,5; ble 3f; 2:; rlwinm 5,0,7,0,24; rlwinm 6,0,15,0,16; xor 5,0,5; xor 5,6,5; rlwinm 7,0,23,0,8; eqv 5,7,5; rlwinm 6,0,1,0,30; rlwinm 0,5,2,30,30; or 7,6,0; rlwinm 0,7,7,0,24; rlwinm 5,7,15,0,16; xor 0,7,0; rlwinm 6,7,23,0,8; xor 0,5,0; eqv 0,6,0; rlwinm 8,0,2,30,30; rlwimi 8,7,1,0,29; rlwinm 0,8,7,0,24; rlwinm 5,8,15,0,16; xor 0,8,0; rlwinm 6,8,23,0,8; xor 0,5,0; eqv 0,6,0; rlwinm 7,0,2,30,30; rlwimi 7,8,1,0,29; rlwinm 0,7,7,0,24; rlwinm 5,7,15,0,16; xor 0,7,0; rlwinm 6,7,23,0,8; xor 0,5,0; eqv 0,6,0; rlwinm 8,0,2,30,30; rlwimi 8,7,1,0,29; rlwinm 0,8,7,0,24; rlwinm 5,8,15,0,16; xor 0,8,0; rlwinm 6,8,23,0,8; xor 0,5,0; eqv 0,6,0; rlwinm 7,0,2,30,30; rlwimi 7,8,1,0,29; rlwinm 0,7,7,0,24; rlwinm 5,7,15,0,16; xor 0,7,0; rlwinm 6,7,23,0,8; xor 0,5,0; eqv 0,6,0; rlwinm 8,0,2,30,30; rlwimi 8,7,1,0,29; rlwinm 0,8,7,0,24; rlwinm 5,8,15,0,16; xor 0,8,0; rlwinm 6,8,23,0,8; xor 0,5,0; eqv 0,6,0; rlwinm 7,0,2,30,30; rlwimi 7,8,1,0,29; rlwinm 0,7,7,0,24; rlwinm 5,7,15,0,16; xor 0,7,0; rlwinm 6,7,23,0,8; xor 0,5,0; eqv 0,6,0; rlwinm 0,0,2,30,30; rlwimi 0,7,1,0,29; addi 3,3,8; bdnz 2b; 3:; subf 5,3,4; cmplw 3,4; mtspr 9,5; bge 5f; 4:; rlwinm 3,0,7,0,24; rlwinm 4,0,15,0,16; xor 3,0,3; rlwinm 5,0,23,0,8; xor 3,4,3; eqv 3,5,3; rlwinm 4,0,1,0,30; rlwinm 0,3,2,30,30; or 0,4,0; bdnz 4b; 5:; rlwinm 3,0,7,0,24; rlwinm 4,0,15,0,16; xor 3,0,3; rlwinm 5,0,23,0,8; xor 3,4,3; eqv 3,5,3; rlwinm 3,3,1,31,31; or 0,0,3; stw 0,0x2c(29); bl _s80386714_4; lwz 0,0x2c(29); rlwinm 4,30,16,0,15; addi 6,3,0; xor 0,4,0; rlwinm 4,0,0,0,15; addi 3,31,0; addi 5,1,52; li 7,1; bl _s80386714_5; cmpwi 3,0; bge 6f; mr 3,31; bl _s80386714_6; addi 3,31,0; li 4,-3; bl _s80386714_7; b 9f; 6:; addi 3,31,0; addi 4,1,48; bl _s80386714_8; addi 28,3,0; addi 3,31,0; bl _s80386714_9; cmpwi 3,0; bne 7f; mr 3,31; bl _s80386714_10; addi 3,31,0; li 4,-3; bl _s80386714_11; b 9f; 7:; cmpwi 28,0; bne 8f; lbz 0,0x30(1); rlwinm. 0,0,0,25,25; bne 8f; mr 3,31; bl _s80386714_12; li 28,-5; 8:; addi 3,31,0; addi 4,28,0; bl _s80386714_13; 9:; lwz 0,0x8c(1); lwz 31,0x84(1); lwz 30,0x80(1); lwz 29,0x7c(1); lwz 28,0x78(1); addi 1,1,136; mtspr 8,0"
extern "C" void _s80386714_0();
extern "C" void _s80386714_1();
extern "C" void _s80386714_2();
extern "C" void _s80386714_3();
extern "C" void _s80386714_4();
extern "C" void _s80386714_5();
extern "C" void _s80386714_6();
extern "C" void _s80386714_7();
extern "C" void _s80386714_8();
extern "C" void _s80386714_9();
extern "C" void _s80386714_10();
extern "C" void _s80386714_11();
extern "C" void _s80386714_12();
extern "C" void _s80386714_13();
extern "C" void f_80386714() {}
