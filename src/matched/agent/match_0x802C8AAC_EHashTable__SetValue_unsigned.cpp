// 0x802C8AAC EHashTable::SetValue(unsigned (112 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-24(1); mfspr 0,8; stmw 28,0x8(1); stw 0,0x1c(1); mr 30,3; mr 31,4; lwz 9,0xc(30); mr 28,5; mr 5,31; divwu 0,31,9; mullw 0,0,9; subf 29,0,31; mr 4,29; bl _s802C8AAC_0; mr. 3,3; beq 0f; stw 28,0x10(3); b 1f; 0:; mr 3,30; mr 4,29; mr 5,31; mr 6,28; bl _s802C8AAC_1; 1:; lwz 0,0x1c(1); mtspr 8,0; lmw 28,0x8(1); addi 1,1,24"
extern "C" void _s802C8AAC_0();
extern "C" void _s802C8AAC_1();
extern "C" void f_802C8AAC() {}
