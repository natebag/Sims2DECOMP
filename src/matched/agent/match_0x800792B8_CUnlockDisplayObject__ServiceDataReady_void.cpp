// 0x800792B8 CUnlockDisplayObject::ServiceDataReady(void) (160 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-16(1); mfspr 0,8; stmw 30,0x8(1); stw 0,0x14(1); mr 31,3; li 30,0; lwz 0,0x14(31); cmpwi 0,0; bne 0f; lis 3,-32692; lwz 4,0x2c(31); addi 3,3,-27556; bl _s800792B8_0; stw 3,0x14(31); 0:; lwz 0,0x80(31); cmpwi 0,0; bne 2f; lwz 0,0x20(31); cmpwi 0,0; bne 1f; lis 3,-32693; lwz 4,0x34(31); addi 3,3,11064; bl _s800792B8_1; stw 3,0x20(31); 1:; lwz 0,0x14(31); cmpwi 0,0; beq 4f; lwz 0,0x20(31); b 3f; 2:; lwz 0,0x14(31); 3:; cmpwi 0,0; beq 4f; li 30,1; 4:; mr 3,30; lwz 0,0x14(1); mtspr 8,0; lmw 30,0x8(1); addi 1,1,16"
extern "C" void _s800792B8_0();
extern "C" void _s800792B8_1();
extern "C" void f_800792B8() {}
