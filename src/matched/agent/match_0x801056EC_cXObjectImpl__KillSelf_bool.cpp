// 0x801056EC cXObjectImpl::KillSelf(bool) (148 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-16(1); mfspr 0,8; stw 31,0xc(1); stw 0,0x14(1); mr 31,3; mr 5,4; lwz 11,0x58(31); lha 4,0x64(31); lwz 9,0x0(11); lha 3,0x60(9); lwz 0,0x64(9); add 3,11,3; mtspr 8,0; blrl; cmpwi 31,0; beq 0f; lwz 9,0x4(31); li 4,2; lwz 3,0x0(9); bl _s801056EC_0; mr 4,3; b 1f; 0:; li 4,0; 1:; cmpwi 4,0; beq 2f; lwz 3,-21476(13); lwz 9,0x0(3); lha 0,0xf0(9); lwz 9,0xf4(9); add 3,3,0; mtspr 8,9; blrl; 2:; lwz 0,0x14(1); mtspr 8,0; lwz 31,0xc(1); addi 1,1,16"
extern "C" void _s801056EC_0();
extern "C" void f_801056EC() {}
