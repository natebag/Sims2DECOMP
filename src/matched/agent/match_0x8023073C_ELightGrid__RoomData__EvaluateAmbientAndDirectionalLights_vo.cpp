// 0x8023073C ELightGrid::RoomData::EvaluateAmbientAndDirectionalLights(void) (144 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-32(1); mfspr 0,8; stw 31,0x1c(1); stw 0,0x24(1); mr 31,3; lwz 11,0x1c(31); cmpwi 11,0; beq 0f; lwz 9,0x0(11); mr 4,31; addi 5,31,12; mr 6,31; lha 3,0x150(9); addi 7,31,16; lwz 0,0x154(9); add 3,11,3; mtspr 8,0; blrl; 0:; lwz 11,0x3c(31); cmpwi 11,0; beq 1f; lwz 9,0x0(11); addi 7,31,48; addi 4,31,32; addi 5,31,44; lha 3,0x150(9); addi 6,1,8; lwz 0,0x154(9); add 3,11,3; mtspr 8,0; blrl; 1:; lwz 0,0x24(1); mtspr 8,0; lwz 31,0x1c(1); addi 1,1,32"
extern "C" void f_8023073C() {}
