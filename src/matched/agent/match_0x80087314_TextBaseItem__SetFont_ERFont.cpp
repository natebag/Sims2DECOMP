// 0x80087314 TextBaseItem::SetFont(ERFont (64 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-16(1); mfspr 0,8; stmw 30,0x8(1); stw 0,0x14(1); mr 30,3; addi 3,30,32; stw 4,0x30(3); bl _s80087314_0; lwz 0,0x4(30); ori 0,0,2; stw 0,0x4(30); lwz 0,0x14(1); mtspr 8,0; lmw 30,0x8(1); addi 1,1,16"
extern "C" void _s80087314_0();
extern "C" void f_80087314() {}
