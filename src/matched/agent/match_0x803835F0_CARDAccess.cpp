// 0x803835F0 __CARDAccess (148 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="mfspr 0,8; stw 0,0x4(1); stwu 1,-24(1); stw 31,0x14(1); stw 30,0x10(1); mr 30,4; lbz 0,0x0(4); lwz 31,0x10c(3); cmplwi 0,255; bne 0f; li 3,-4; b 3f; 0:; lis 3,-32688; addi 0,3,-23456; cmplw 31,0; beq 1f; addi 3,30,0; addi 4,31,0; li 5,4; bl _s803835F0_0; cmpwi 3,0; bne 2f; addi 3,30,4; addi 4,31,4; li 5,2; bl _s803835F0_1; cmpwi 3,0; bne 2f; 1:; li 3,0; b 3f; 2:; li 3,-10; 3:; lwz 0,0x1c(1); lwz 31,0x14(1); lwz 30,0x10(1); addi 1,1,24; mtspr 8,0"
extern "C" void _s803835F0_0();
extern "C" void _s803835F0_1();
extern "C" void f_803835F0() {}
