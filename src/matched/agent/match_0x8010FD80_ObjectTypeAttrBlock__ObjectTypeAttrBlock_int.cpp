// 0x8010FD80 ObjectTypeAttrBlock::ObjectTypeAttrBlock(int, (96 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-16(1); mfspr 0,8; stw 31,0xc(1); stw 0,0x14(1); mr 31,3; cmplwi 5,31999; stw 4,0x0(31); stw 5,0x4(31); bgt 0f; rlwinm 3,5,1,0,30; bl _s8010FD80_0; stw 3,0x8(31); b 1f; 0:; li 0,0; stw 0,0x8(31); stw 0,0x4(31); 1:; mr 3,31; bl _s8010FD80_1; mr 3,31; lwz 0,0x14(1); mtspr 8,0; lwz 31,0xc(1); addi 1,1,16"
extern "C" void _s8010FD80_0();
extern "C" void _s8010FD80_1();
extern "C" void f_8010FD80() {}
