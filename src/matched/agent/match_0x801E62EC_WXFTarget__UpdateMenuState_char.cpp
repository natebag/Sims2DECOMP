// 0x801E62EC WXFTarget::UpdateMenuState(char (132 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-16(1); mfspr 0,8; stw 31,0xc(1); stw 0,0x14(1); mr 31,3; mr 3,5; bl _s801E62EC_0; mr 9,3; cmpwi 9,1; beq 1f; bgt 0f; cmpwi 9,0; beq 1f; b 3f; 0:; cmpwi 9,2; beq 2f; b 3f; 1:; lwz 0,0x8c(31); mr 3,31; stw 9,0x8c(31); stw 0,0x90(31); bl _s801E62EC_1; b 3f; 2:; lwz 0,0x8c(31); stw 9,0x8c(31); stw 0,0x90(31); 3:; mr 3,31; bl _s801E62EC_2; lwz 0,0x14(1); mtspr 8,0; lwz 31,0xc(1); addi 1,1,16"
extern "C" void _s801E62EC_0();
extern "C" void _s801E62EC_1();
extern "C" void _s801E62EC_2();
extern "C" void f_801E62EC() {}
