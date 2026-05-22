// 0x801A2AAC ACTTarget::RemoveAllActions(int) (136 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-24(1); mfspr 0,8; stmw 28,0x8(1); stw 0,0x1c(1); mr 30,3; mr 28,4; addi 31,30,296; li 29,18; 0:; lwz 0,-56(31); cmpwi 0,0; beq 1f; lwz 4,-4(31); mr 3,30; bl _s801A2AAC_0; stw 3,0x0(31); cmpwi 3,0; beq 1f; mr 5,3; mr 4,28; mr 3,30; bl _s801A2AAC_1; 1:; addi 31,31,76; addic. 29,29,-1; bne 0b; lwz 0,0x648(30); cmpwi 0,0; beq 2f; mr 3,30; bl _s801A2AAC_2; 2:; lwz 0,0x1c(1); mtspr 8,0; lmw 28,0x8(1); addi 1,1,24"
extern "C" void _s801A2AAC_0();
extern "C" void _s801A2AAC_1();
extern "C" void _s801A2AAC_2();
extern "C" void f_801A2AAC() {}
