// 0x803612D4 EStringRedBlackTreeNoCase::RemoveAll(void) (116 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-24(1); mfspr 0,8; stmw 29,0xc(1); stw 0,0x1c(1); mr 29,3; lwz 31,0x4(29); cmpwi 31,0; beq 2f; 0:; lwz 30,0xc(31); cmpwi 31,0; beq 1f; lwz 4,0x1c(31); addi 3,31,28; bl _s803612D4_0; mr 3,31; bl _s803612D4_1; 1:; mr. 31,30; bne 0b; 2:; lis 9,-32700; li 0,0; addi 9,9,11816; stw 0,0x0(29); stw 9,0x8(29); stw 0,0x4(29); lwz 0,0x1c(1); mtspr 8,0; lmw 29,0xc(1); addi 1,1,24"
extern "C" void _s803612D4_0();
extern "C" void _s803612D4_1();
extern "C" void f_803612D4() {}
