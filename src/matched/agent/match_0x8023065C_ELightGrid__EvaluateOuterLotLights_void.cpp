// 0x8023065C ELightGrid::EvaluateOuterLotLights(void) (136 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="mr 12,3; lwz 0,0x6020(12); cmplwi 0,0; beqlr; lwz 0,0x6034(12); addi 11,12,24628; lwz 8,0x8(11); addis 9,12,3; lwz 7,0x4(11); addi 10,9,-25752; stw 0,-25752(9); addi 6,12,24660; stw 8,0x8(10); addi 5,9,-25736; stw 7,0x4(10); addi 8,12,24644; addi 7,9,-25724; li 3,1; lwz 10,0x6054(12); li 4,0; lwz 0,0x8(6); lwz 11,0x4(6); stw 10,-25736(9); stw 0,0x8(5); stw 11,0x4(5); lwz 0,0x6044(12); lwz 11,0x8(8); lwz 10,0x4(8); stw 0,-25724(9); stw 11,0x8(7); stw 10,0x4(7); stw 4,-25508(9); stw 3,-25512(9)"
extern "C" void f_8023065C() {}
