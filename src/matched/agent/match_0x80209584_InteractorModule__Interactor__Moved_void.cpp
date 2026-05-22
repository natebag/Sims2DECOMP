// 0x80209584 InteractorModule::Interactor::Moved(void) (72 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="lfs f13,0x14(3); li 0,0; lfs f0,0x8(3); addi 9,3,8; addi 11,3,20; fcmpu 0,f0,f13; bne 0f; lfs f13,0x4(9); lfs f0,0x4(11); fcmpu 0,f13,f0; bne 0f; lfs f13,0x8(9); lfs f0,0x8(11); fcmpu 0,f13,f0; beq 1f; 0:; li 0,1; 1:; mr 3,0"
extern "C" float f_80209584() {}
