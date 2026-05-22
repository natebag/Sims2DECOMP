// 0x8021C208 InteractorModule::PlacementObject::Destroy(void) (172 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-24(1); mfspr 0,8; stmw 30,0x10(1); stw 0,0x1c(1); mr 31,3; li 30,0; lwz 3,0x0(31); cmpwi 3,0; beq 0f; li 0,1; stw 0,-32044(13); bl _s8021C208_0; li 11,0; addi 10,1,8; stw 11,0x4(10); li 0,-1; stw 0,0x8(1); mr 30,3; stw 11,-32044(13); lwz 9,0x4(10); stw 11,0x0(31); stw 11,0x28(31); rlwinm 9,9,4,0,27; stw 9,0x4(10); lwz 0,0x8(1); rlwinm 0,0,4,0,27; stw 0,0x8(1); lwz 9,0x8(1); lwz 10,0xc(1); stw 9,0x2c(31); stw 10,0x30(31); 0:; lwz 0,0x4(31); cmpwi 0,0; beq 1f; mr 3,31; addi 4,3,4; bl _s8021C208_1; 1:; mr 3,30; lwz 0,0x1c(1); mtspr 8,0; lmw 30,0x10(1); addi 1,1,24"
extern "C" void _s8021C208_0();
extern "C" void _s8021C208_1();
extern "C" void f_8021C208() {}
