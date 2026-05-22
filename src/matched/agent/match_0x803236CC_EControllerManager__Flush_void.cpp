// 0x803236CC EControllerManager::Flush(void) (88 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-16(1); mfspr 0,8; stmw 30,0x8(1); stw 0,0x14(1); lis 9,-32688; addi 31,9,-12424; addi 30,31,12; 0:; lwz 3,0x0(31); addi 31,31,4; lwz 9,0x208(3); lha 0,0xa8(9); lwz 9,0xac(9); add 3,3,0; mtspr 8,9; blrl; cmpw 31,30; ble 0b; lwz 0,0x14(1); mtspr 8,0; lmw 30,0x8(1); addi 1,1,16"
extern "C" void f_803236CC() {}
