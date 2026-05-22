// 0x8021C2B4 InteractorModule::PlacementObject::Reset(void) (144 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-24(1); mfspr 0,8; stw 31,0x14(1); stw 0,0x1c(1); mr 31,3; bl _s8021C2B4_0; mr 3,31; bl _s8021C2B4_1; lwz 0,0x4(31); cmpwi 0,0; beq 0f; mr 3,31; addi 4,31,4; bl _s8021C2B4_2; 0:; addi 10,1,8; li 11,0; stw 11,0x4(10); li 0,-1; stw 0,0x8(1); stw 11,0x0(31); lwz 9,0x4(10); stw 11,0x28(31); rlwinm 9,9,4,0,27; stw 9,0x4(10); lwz 0,0x8(1); rlwinm 0,0,4,0,27; stw 0,0x8(1); lwz 9,0x8(1); lwz 10,0xc(1); stw 9,0x2c(31); stw 10,0x30(31); lwz 0,0x1c(1); mtspr 8,0; lwz 31,0x14(1); addi 1,1,24"
extern "C" void _s8021C2B4_0();
extern "C" void _s8021C2B4_1();
extern "C" void _s8021C2B4_2();
extern "C" void f_8021C2B4() {}
