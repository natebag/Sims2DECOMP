// 0x802D158C __static_initialization_and_destruction_0 (108 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-8(1); mfspr 0,8; stw 0,0xc(1); li 0,0; ori 0,0,65535; cmpw 4,0; bne 0f; cmpwi 3,0; beq 0f; lis 3,-32688; lis 4,-32708; addi 3,3,-13320; lis 5,-32708; lis 6,-32708; lis 8,-32702; addi 4,4,9288; addi 5,5,9340; addi 6,6,9356; addi 8,8,-6920; li 7,0; mr 9,3; bl _s802D158C_0; stw 3,-22780(13); 0:; lwz 0,0xc(1); mtspr 8,0; addi 1,1,8"
extern "C" void _s802D158C_0();
extern "C" void f_802D158C() {}
