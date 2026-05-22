// 0x802276E0 __static_initialization_and_destruction_0 (112 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-8(1); mfspr 0,8; stw 0,0xc(1); li 0,0; ori 0,0,65535; cmpw 4,0; bne 0f; cmpwi 3,0; beq 0f; lis 3,-32688; lis 4,-32734; lis 5,-32734; lis 6,-32734; lis 8,-32704; lis 9,-32688; addi 3,3,-13360; addi 4,4,30544; addi 5,5,30584; addi 6,6,30616; addi 8,8,-6940; addi 9,9,-18528; li 7,0; bl _s802276E0_0; stw 3,-23808(13); 0:; lwz 0,0xc(1); mtspr 8,0; addi 1,1,8"
extern "C" void _s802276E0_0();
extern "C" void f_802276E0() {}
