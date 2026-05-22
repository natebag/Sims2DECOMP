// 0x8022170C InteractorModule::WallManipulator::ClearWallFadeOffList(void) (96 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="addi 11,3,168; lwz 9,0xa8(3); lwz 0,0x4(11); li 10,0; subf 0,9,0; srawi. 9,0,2; ble 1f; mr 7,11; li 6,0; li 8,0; 0:; lwz 9,0xa8(3); addi 10,10,1; lwzx 11,9,8; addi 8,8,4; stw 6,0x3b0(11); lwz 0,0x4(7); lwz 9,0xa8(3); subf 0,9,0; srawi 0,0,2; cmpw 10,0; blt 0b; 1:; lwz 0,0xa8(3); stw 0,0xac(3)"
extern "C" void f_8022170C() {}
