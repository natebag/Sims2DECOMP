// 0x802D74E8 efopen (76 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-16(1); mfspr 0,8; stw 0,0x14(1); mr 5,3; mr 6,4; li 0,0; lis 3,-32694; stw 0,0x8(1); addi 3,3,-10620; addi 4,1,8; lis 7,-32768; lis 8,-32768; li 9,0; bl _s802D74E8_0; lwz 3,0x8(1); lwz 0,0x14(1); mtspr 8,0; addi 1,1,16"
extern "C" void _s802D74E8_0();
extern "C" void f_802D74E8() {}
