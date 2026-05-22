// 0x802D06A0 __tcf_13 (108 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-16(1); mfspr 0,8; stmw 30,0x8(1); stw 0,0x14(1); lis 9,-32694; addi 3,9,6784; addic. 0,3,8; beq 1f; addi 31,3,424; cmpw 0,31; beq 1f; mr 30,0; 0:; addi 31,31,-52; li 4,0; lwz 9,0x14(31); lha 3,0x8(9); lwz 0,0xc(9); add 3,31,3; mtspr 8,0; blrl; cmpw 30,31; bne 0b; 1:; lwz 0,0x14(1); mtspr 8,0; lmw 30,0x8(1); addi 1,1,16"
extern "C" void f_802D06A0() {}
