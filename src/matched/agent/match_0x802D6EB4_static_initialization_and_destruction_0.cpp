// 0x802D6EB4 __static_initialization_and_destruction_0 (112 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-8(1); mfspr 0,8; stw 0,0xc(1); li 0,0; ori 0,0,65535; cmpw 4,0; bne 1f; cmpwi 3,0; beq 0f; lis 5,-32694; lis 3,-32694; addi 5,5,7559; lis 4,-32702; addi 3,3,7444; addi 4,4,-6684; rlwinm 5,5,0,0,25; li 6,116; li 7,300; bl _s802D6EB4_0; b 1f; 0:; lis 3,-32694; li 4,2; addi 3,3,7444; bl _s802D6EB4_1; 1:; lwz 0,0xc(1); mtspr 8,0; addi 1,1,8"
extern "C" void _s802D6EB4_0();
extern "C" void _s802D6EB4_1();
extern "C" void f_802D6EB4() {}
