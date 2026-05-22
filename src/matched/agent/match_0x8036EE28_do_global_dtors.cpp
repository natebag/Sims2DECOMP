// 0x8036EE28 __do_global_dtors (100 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-16(1); mfspr 0,8; stw 31,0xc(1); stw 0,0x14(1); lis 9,-32700; lwz 11,0x2e84(9); lwz 0,0x0(11); cmpwi 0,0; beq 1f; lis 31,-32700; 0:; lwz 9,0x2e84(31); addi 9,9,4; stw 9,0x2e84(31); lwz 0,-4(9); mtspr 8,0; blrl; lwz 9,0x2e84(31); lwz 0,0x0(9); cmpwi 0,0; bne 0b; 1:; lwz 0,0x14(1); mtspr 8,0; lwz 31,0xc(1); addi 1,1,16"
extern "C" void f_8036EE28() {}
