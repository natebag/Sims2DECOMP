// 0x8021C160 InteractorModule::PlacementObject::Initialize(void) (116 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-16(1); lwz 11,0x14(3); addi 10,1,8; addi 8,3,20; lwz 0,0x4(8); mr 9,11; cmpw 11,0; beq 1f; 0:; addi 9,9,6; cmpw 9,0; bne 0b; 1:; stw 11,0x4(8); li 9,0; stw 9,0x4(10); li 0,-1; stw 0,0x8(1); stw 9,0x28(3); lwz 0,0x4(10); rlwinm 0,0,4,0,27; stw 0,0x4(10); lwz 9,0x8(1); rlwinm 9,9,4,0,27; stw 9,0x8(1); lwz 11,0x8(1); lwz 12,0xc(1); stw 11,0x2c(3); stw 12,0x30(3); addi 1,1,16"
extern "C" void f_8021C160() {}
