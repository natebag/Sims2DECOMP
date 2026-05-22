// 0x80206180 InteractorModule::DirectInteractor::UpdateInteractorPos(void) (120 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-32(1); mfspr 0,8; stw 31,0x1c(1); stw 0,0x24(1); mr 31,3; lwz 11,0x70(31); cmpwi 11,0; beq 0f; lwz 9,0x4(11); lwz 0,0x18c(9); lha 3,0x188(9); mtspr 8,0; add 3,11,3; blrl; mr 4,3; addi 3,1,8; bl _s80206180_0; lwz 10,0x8(1); addi 9,1,8; lwz 8,0x8(9); addi 11,31,8; lwz 0,0x4(9); stw 10,0x8(31); stw 8,0x8(11); stw 0,0x4(11); 0:; lwz 0,0x24(1); mtspr 8,0; lwz 31,0x1c(1); addi 1,1,32"
extern "C" void _s80206180_0();
extern "C" void f_80206180() {}
