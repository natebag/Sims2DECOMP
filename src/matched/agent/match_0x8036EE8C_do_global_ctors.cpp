// 0x8036EE8C __do_global_ctors (144 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-16(1); mfspr 0,8; stmw 30,0x8(1); stw 0,0x14(1); lis 9,-32707; lwz 11,-22272(9); addi 10,9,-22272; cmpwi 11,-1; bne 1f; lwz 0,0x4(10); li 11,0; cmpwi 0,0; beq 1f; addi 9,10,4; 0:; lwzu 0,0x4(9); addi 11,11,1; cmpwi 0,0; bne 0b; 1:; mr. 0,11; beq 3f; lis 9,-32707; rlwinm 0,0,2,0,29; addi 9,9,-22272; mr 30,9; add 31,0,9; 2:; lwz 9,0x0(31); addi 31,31,-4; mtspr 8,9; blrl; cmpw 31,30; bne 2b; 3:; lwz 0,0x14(1); mtspr 8,0; lmw 30,0x8(1); addi 1,1,16"
extern "C" void f_8036EE8C() {}
