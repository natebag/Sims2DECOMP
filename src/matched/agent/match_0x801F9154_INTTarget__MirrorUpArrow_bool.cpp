// 0x801F9154 INTTarget::MirrorUpArrow(bool) (76 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-8(1); mfspr 0,8; stw 0,0xc(1); lwz 0,0xdc(3); cmpw 0,4; beq 0f; lwz 0,0x88(3); stw 4,0xdc(3); cmpwi 0,0; beq 0f; mr 5,4; lwz 6,0x98(3); lwz 4,-28532(13); addi 3,3,200; bl _s801F9154_0; 0:; lwz 0,0xc(1); mtspr 8,0; addi 1,1,8"
extern "C" void _s801F9154_0();
extern "C" void f_801F9154() {}
