// 0x801BB6C0 INGTarget::Update(void) (284 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-16(1); mfspr 0,8; stw 31,0xc(1); stw 0,0x14(1); mr 31,3; lwz 0,0x45c(31); cmpwi 0,0; bne 0f; lwz 0,0x464(31); cmpwi 0,0; bne 0f; lis 9,-32705; lfs f13,0x460(31); lfs f12,0x199c(9); fcmpu 0,f13,f12; ble 0f; lfs f0,-26800(13); fsubs f0,f13,f0; fcmpu 0,f0,f12; stfs f0,0x460(31); cror 3,2,0; bns 0f; li 0,1; stw 0,0x464(31); li 4,0; bl _s801BB6C0_0; 0:; lwz 0,0x458(31); cmpwi 0,0; beq 5f; cmpwi 0,1; beq 1f; cmpwi 0,2; beq 3f; b 5f; 1:; lwz 11,0x45c(31); cmpwi 11,0; beq 2f; lwz 9,0x80(11); li 4,3; lha 3,0x8(9); lwz 0,0xc(9); add 3,11,3; mtspr 8,0; blrl; 2:; li 3,332; bl _s801BB6C0_1; lwz 5,0x94(31); addi 4,31,132; bl _s801BB6C0_2; li 0,0; stw 3,0x45c(31); stw 0,0x458(31); b 5f; 3:; lwz 11,0x45c(31); cmpwi 11,0; beq 4f; lwz 9,0x80(11); li 4,3; lha 3,0x8(9); lwz 0,0xc(9); add 3,11,3; mtspr 8,0; blrl; 4:; li 0,0; stw 0,0x458(31); stw 0,0x45c(31); 5:; lwz 0,0x14(1); mtspr 8,0; lwz 31,0xc(1); addi 1,1,16"
extern "C" void _s801BB6C0_0();
extern "C" void _s801BB6C0_1();
extern "C" void _s801BB6C0_2();
extern "C" void f_801BB6C0() {}
