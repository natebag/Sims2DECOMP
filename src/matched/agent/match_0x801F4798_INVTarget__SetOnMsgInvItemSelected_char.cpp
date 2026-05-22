// 0x801F4798 INVTarget::SetOnMsgInvItemSelected(char (424 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-24(1); mfspr 0,8; stmw 28,0x8(1); stw 0,0x1c(1); mr 31,3; mr 3,4; bl _s801F4798_0; lis 9,-32697; lwz 0,0x618c(9); cmpwi 0,0; beq 0f; mr 3,31; bl _s801F4798_1; b 6f; 0:; lwz 0,0x84(31); addi 9,13,-28700; lwz 3,0x90(31); rlwinm 0,0,2,0,29; lwzx 4,9,0; bl _s801F4798_2; cmpwi 3,0; beq 6f; lis 30,-32697; li 29,0; addi 30,30,23428; li 28,0; addi 30,30,4; mr 3,30; bl _s801F4798_3; lis 9,-32704; lfs f13,0x8(30); lfs f0,-23668(9); fcmpu 0,f13,f0; cror 3,2,1; bns 1f; li 0,1; li 28,3; stw 0,0xa4(31); li 29,1; b 4f; 1:; lis 9,-32704; lfs f0,-23664(9); fcmpu 0,f13,f0; cror 3,2,1; bns 2f; addi 9,31,152; li 28,2; lwz 0,0x8(9); cmpwi 0,0; bne 4f; li 0,1; li 29,1; stw 0,0x8(9); b 4f; 2:; lis 9,-32704; lfs f0,-23660(9); fcmpu 0,f13,f0; cror 3,2,1; bns 3f; addi 9,31,152; li 28,1; lwz 0,0x4(9); cmpwi 0,0; bne 4f; stw 28,0x4(9); li 29,1; b 4f; 3:; lis 9,-32704; lfs f0,-23656(9); fcmpu 0,f13,f0; cror 3,2,1; bns 4f; lwz 0,0x98(31); cmpwi 0,0; bne 4f; li 0,1; li 29,1; stw 0,0x98(31); 4:; cmpwi 29,0; beq 5f; addi 30,31,12892; mr 5,28; mr 4,30; mr 3,31; bl _s801F4798_4; mr 3,30; bl _s801F4798_5; lwz 3,0x3298(31); cmpwi 3,0; beq 6f; bl _s801F4798_6; li 0,0; stw 0,0x3298(31); b 6f; 5:; lwz 9,0x80(31); li 4,0; lha 3,0x38(9); lwz 0,0x3c(9); add 3,31,3; mtspr 8,0; blrl; 6:; lwz 0,0x1c(1); mtspr 8,0; lmw 28,0x8(1); addi 1,1,24"
extern "C" void _s801F4798_0();
extern "C" void _s801F4798_1();
extern "C" void _s801F4798_2();
extern "C" void _s801F4798_3();
extern "C" void _s801F4798_4();
extern "C" void _s801F4798_5();
extern "C" void _s801F4798_6();
extern "C" void f_801F4798() {}
