// 0x802FA9E8 __static_initialization_and_destruction_0 (100 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-8(1); mfspr 0,8; stw 0,0xc(1); li 0,0; ori 0,0,65535; cmpw 4,0; bne 1f; cmpwi 3,0; beq 0f; addi 9,13,-22720; li 0,0; lis 3,-32693; stw 0,0x0(9); addi 3,3,2264; stw 0,0x4(9); bl _s802FA9E8_0; b 1f; 0:; lis 3,-32693; li 4,2; addi 3,3,2264; bl _s802FA9E8_1; 1:; lwz 0,0xc(1); mtspr 8,0; addi 1,1,8"
extern "C" void _s802FA9E8_0();
extern "C" void _s802FA9E8_1();
extern "C" void f_802FA9E8() {}
