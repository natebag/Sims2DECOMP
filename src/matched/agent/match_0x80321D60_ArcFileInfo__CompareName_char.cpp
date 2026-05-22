// 0x80321D60 ArcFileInfo::CompareName(char (68 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-8(1); mfspr 0,8; stw 0,0xc(1); mr. 4,4; beq 0f; lwz 3,0x0(3); cmpwi 3,0; bne 1f; 0:; li 3,0; b 2f; 1:; bl _s80321D60_0; subfic 0,3,0; adde 3,0,3; 2:; lwz 0,0xc(1); mtspr 8,0; addi 1,1,8"
extern "C" void _s80321D60_0();
extern "C" void f_80321D60() {}
