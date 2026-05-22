// 0x80224AAC InteractorModule::WallPainter::AdjustCursorPosition(void) (268 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-16(1); mfspr 0,8; stmw 30,0x8(1); stw 0,0x14(1); mr 31,3; li 5,2; addi 30,31,32; addi 3,31,8; mr 4,30; bl _s80224AAC_0; lfs f13,0x60(31); addi 9,31,96; lfs f0,0x20(31); li 0,0; fcmpu 0,f13,f0; bne 0f; lfs f13,0x4(9); lfs f0,0x4(30); fcmpu 0,f13,f0; bne 0f; lfs f13,0x8(9); lfs f0,0x8(30); fcmpu 0,f13,f0; beq 1f; 0:; li 0,1; 1:; cmpwi 0,0; beq 7f; bl _s80224AAC_1; lwz 4,0x0(31); bl _s80224AAC_2; addi 4,31,96; addi 5,31,32; li 6,0; bl _s80224AAC_3; cmpwi 3,0; beq 3f; lfs f13,0x24(31); lfs f0,0x64(31); fcmpu 0,f13,f0; bgt 5f; bne 2f; lfs f13,0x20(31); lfs f0,0x60(31); fcmpu 0,f13,f0; bgt 5f; 2:; lfs f0,-23820(13); fneg f0,f0; b 6f; 3:; lfs f13,0x24(31); lfs f0,0x64(31); fcmpu 0,f13,f0; bgt 4f; bne 5f; lfs f13,0x20(31); lfs f0,0x60(31); fcmpu 0,f13,f0; ble 5f; 4:; lfs f0,-23820(13); fneg f0,f0; b 6f; 5:; lfs f0,-23820(13); 6:; stfs f0,0x84(31); 7:; lwz 0,0x14(1); mtspr 8,0; lmw 30,0x8(1); addi 1,1,16"
extern "C" void _s80224AAC_0();
extern "C" void _s80224AAC_1();
extern "C" void _s80224AAC_2();
extern "C" void _s80224AAC_3();
extern "C" void f_80224AAC() {}
