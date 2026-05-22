// 0x8022FBC4 ELightGrid::RoomData::Flush(void) (80 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-16(1); mfspr 0,8; stmw 30,0x8(1); stw 0,0x14(1); mr 30,3; addi 3,30,32; bl _s8022FBC4_0; mr 3,30; bl _s8022FBC4_1; li 0,0; li 9,256; stw 9,0x4c(30); stw 0,0x44(30); stw 0,0x48(30); stw 9,0x50(30); lwz 0,0x14(1); mtspr 8,0; lmw 30,0x8(1); addi 1,1,16"
extern "C" void _s8022FBC4_0();
extern "C" void _s8022FBC4_1();
extern "C" void f_8022FBC4() {}
