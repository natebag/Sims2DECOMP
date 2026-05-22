// 0x803139A0 FlashBigFile::GetGeometry(char (72 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-16(1); mfspr 0,8; stmw 30,0x8(1); stw 0,0x14(1); bl _s803139A0_0; mr 30,3; lis 4,-32702; addi 4,4,1528; bl _s803139A0_1; cmpwi 3,0; mr 3,30; beq 0f; li 3,0; 0:; lwz 0,0x14(1); mtspr 8,0; lmw 30,0x8(1); addi 1,1,16"
extern "C" void _s803139A0_0();
extern "C" void _s803139A0_1();
extern "C" void f_803139A0() {}
