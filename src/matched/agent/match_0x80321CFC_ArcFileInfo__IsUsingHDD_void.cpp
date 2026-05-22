// 0x80321CFC ArcFileInfo::IsUsingHDD(void) (100 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-8(1); mfspr 0,8; stw 0,0xc(1); lwz 4,0x4(3); cmpwi 4,0; beq 0f; lwz 0,0x0(3); cmpwi 0,0; beq 0f; lwz 3,-22652(13); lwz 9,0x0(3); lha 0,0xa0(9); lwz 9,0xa4(9); add 3,3,0; mtspr 8,9; blrl; mr. 3,3; beq 0f; bl _s80321CFC_0; b 1f; 0:; li 3,0; 1:; lwz 0,0xc(1); mtspr 8,0; addi 1,1,8"
extern "C" void _s80321CFC_0();
extern "C" void f_80321CFC() {}
