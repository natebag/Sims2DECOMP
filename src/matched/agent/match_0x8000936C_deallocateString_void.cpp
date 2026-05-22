// 0x8000936C deallocateString(void (124 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-16(1); mfspr 0,8; stmw 30,0x8(1); stw 0,0x14(1); mr 31,3; li 30,0; lwz 3,0x20(31); stw 30,0x0(31); cmpwi 3,0; beq 0f; lis 9,-32694; lwz 0,-16284(9); mtspr 8,0; blrl; stw 30,0x20(31); 0:; lwz 11,0x24(31); cmpwi 11,0; beq 1f; lwz 9,0x34(11); li 4,3; lha 3,0x8(9); lwz 0,0xc(9); add 3,11,3; mtspr 8,0; blrl; stw 30,0x24(31); 1:; lwz 0,0x14(1); mtspr 8,0; lmw 30,0x8(1); addi 1,1,16"
extern "C" void f_8000936C() {}
