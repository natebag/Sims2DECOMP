// 0x801886C0 HUDTarget::UpdateActivePlayer(int, (100 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-16(1); mfspr 0,8; stw 31,0xc(1); stw 0,0x14(1); lis 9,-32697; rlwinm 4,4,2,0,29; addi 9,9,24012; mr 31,5; addi 9,9,188; lwzx 11,9,4; cmpwi 11,0; beq 0f; lwz 9,0x4(11); lha 3,0x308(9); lwz 0,0x30c(9); add 3,11,3; mtspr 8,0; blrl; mr 4,31; bl _s801886C0_0; 0:; lwz 0,0x14(1); mtspr 8,0; lwz 31,0xc(1); addi 1,1,16"
extern "C" void _s801886C0_0();
extern "C" void f_801886C0() {}
