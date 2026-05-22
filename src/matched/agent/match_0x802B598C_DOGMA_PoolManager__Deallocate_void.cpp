// 0x802B598C DOGMA_PoolManager::Deallocate(void (196 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-24(1); mfspr 0,8; stmw 29,0xc(1); stw 0,0x1c(1); mr 31,3; mr 29,5; mr 30,4; mr 4,29; bl _s802B598C_0; lwz 9,0x18(31); mr 5,3; lwz 0,0xc(31); addi 9,9,-1; stw 9,0x18(31); cmplw 5,0; ble 3f; lwz 9,-8(30); addi 29,29,8; addi 3,30,-8; cmpwi 9,0; beq 0f; lwz 0,0x4(3); stw 0,0x4(9); 0:; lwz 9,0x4(3); cmpwi 9,0; beq 1f; lwz 0,-8(30); stw 0,0x0(9); 1:; lwz 0,0x14(31); cmpw 0,3; bne 2f; lwz 0,-8(30); stw 0,0x14(31); 2:; lis 9,-32694; mr 4,29; lwz 0,-16280(9); mtspr 8,0; blrl; li 3,0; b 4f; 3:; mr 3,31; mr 4,30; bl _s802B598C_1; li 3,1; 4:; lwz 0,0x1c(1); mtspr 8,0; lmw 29,0xc(1); addi 1,1,24"
extern "C" void _s802B598C_0();
extern "C" void _s802B598C_1();
extern "C" void f_802B598C() {}
