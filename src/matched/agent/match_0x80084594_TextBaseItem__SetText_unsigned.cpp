// 0x80084594 TextBaseItem::SetText(unsigned (72 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-16(1); mfspr 0,8; stw 31,0xc(1); stw 0,0x14(1); mr 31,3; mr. 4,4; beq 0f; stw 4,0x20(31); addi 3,31,32; bl _s80084594_0; lwz 0,0x4(31); ori 0,0,2; stw 0,0x4(31); 0:; lwz 0,0x14(1); mtspr 8,0; lwz 31,0xc(1); addi 1,1,16"
extern "C" void _s80084594_0();
extern "C" void f_80084594() {}
