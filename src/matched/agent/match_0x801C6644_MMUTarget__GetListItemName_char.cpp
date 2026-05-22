// 0x801C6644 MMUTarget::GetListItemName(char (72 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-8(1); mfspr 0,8; stw 0,0xc(1); mr 9,3; lwz 0,0x8c(9); cmpwi 0,1; bne 0f; bl _s801C6644_0; b 1f; 0:; cmpwi 0,2; li 3,0; bne 1f; mr 3,9; bl _s801C6644_1; 1:; lwz 0,0xc(1); mtspr 8,0; addi 1,1,8"
extern "C" void _s801C6644_0();
extern "C" void _s801C6644_1();
extern "C" void f_801C6644() {}
