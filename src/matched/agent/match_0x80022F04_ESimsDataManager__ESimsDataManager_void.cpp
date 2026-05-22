// 0x80022F04 ESimsDataManager::ESimsDataManager(void) (108 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-16(1); mfspr 0,8; stmw 30,0x8(1); stw 0,0x14(1); mr 30,3; bl _s80022F04_0; lis 9,-32698; lis 11,-32707; li 0,0; addi 9,9,-20736; addi 11,11,1556; li 10,1; stw 9,0xd1c(30); mr 3,30; stw 0,0xd34(30); stw 10,0x48(30); stw 11,0x40(30); stw 0,0xd20(30); stw 0,0xd24(30); stw 0,0xd28(30); stw 0,0xd2c(30); stw 0,0xd30(30); lwz 0,0x14(1); mtspr 8,0; lmw 30,0x8(1); addi 1,1,16"
extern "C" void _s80022F04_0();
extern "C" void f_80022F04() {}
