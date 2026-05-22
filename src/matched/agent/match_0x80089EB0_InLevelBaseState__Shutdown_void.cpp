// 0x80089EB0 InLevelBaseState::Shutdown(void) (124 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-16(1); mfspr 0,8; stmw 30,0x8(1); stw 0,0x14(1); lis 9,-32697; lis 11,-32696; addi 30,9,23428; addi 11,11,22744; lwz 10,0x44(30); li 31,0; li 0,1; stw 31,0x28(11); stw 0,0x34(11); cmpwi 10,0; stw 31,0x2c(11); stw 0,0x30(11); beq 0f; lwz 9,0x80(10); li 4,3; lha 3,0x8(9); lwz 0,0xc(9); add 3,10,3; mtspr 8,0; blrl; stw 31,0x44(30); 0:; stw 31,0x8c(30); lwz 0,0x14(1); mtspr 8,0; lmw 30,0x8(1); addi 1,1,16"
extern "C" void f_80089EB0() {}
