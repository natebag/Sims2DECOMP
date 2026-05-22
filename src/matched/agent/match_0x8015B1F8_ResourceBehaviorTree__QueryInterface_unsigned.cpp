// 0x8015B1F8 ResourceBehaviorTree::QueryInterface(unsigned (112 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-16(1); mfspr 0,8; stmw 30,0x8(1); stw 0,0x14(1); mr 31,3; mr. 30,5; beq 1f; cmpwi 4,1; beq 0f; lis 0,11243; ori 0,0,9254; cmpw 4,0; bne 1f; 0:; lwz 9,0x0(31); lha 3,0x10(9); lwz 0,0x14(9); add 3,31,3; mtspr 8,0; blrl; stw 31,0x0(30); li 3,1; b 2f; 1:; li 3,0; 2:; lwz 0,0x14(1); mtspr 8,0; lmw 30,0x8(1); addi 1,1,16"
extern "C" void f_8015B1F8() {}
