// 0x801A0318 CASRoommateTarget::GetLocalizableSubnav(int, (280 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-32(1); mfspr 0,8; stw 31,0x1c(1); stw 0,0x24(1); mr 31,5; cmpwi 4,1; beq 2f; bgt 0f; cmpwi 4,0; beq 1f; b 8f; 0:; cmpwi 4,2; beq 3f; cmpwi 4,3; beq 6f; b 8f; 1:; lis 4,-32697; lis 5,-32705; addi 4,4,24012; addi 5,5,-11448; addi 3,1,8; crxor 6,6,6; bl _s801A0318_0; lwz 9,0x8(1); b 4f; 2:; lis 4,-32697; lis 5,-32705; addi 4,4,24012; addi 5,5,-11432; addi 3,1,12; crxor 6,6,6; bl _s801A0318_1; lwz 9,0xc(1); b 4f; 3:; lis 4,-32697; lis 5,-32705; addi 4,4,24012; addi 5,5,-11416; addi 3,1,16; crxor 6,6,6; bl _s801A0318_2; lwz 9,0x10(1); 4:; li 4,0; cmpwi 9,0; beq 5f; lwz 4,0x0(9); 5:; mr 3,31; li 5,32; bl _s801A0318_3; b 8f; 6:; lis 4,-32697; lis 5,-32705; addi 4,4,24012; addi 5,5,-11396; addi 3,1,20; crxor 6,6,6; bl _s801A0318_4; lwz 9,0x14(1); li 4,0; cmpwi 9,0; beq 7f; lwz 4,0x0(9); 7:; mr 3,31; li 5,32; bl _s801A0318_5; 8:; lwz 0,0x24(1); mtspr 8,0; lwz 31,0x1c(1); addi 1,1,32"
extern "C" void _s801A0318_0();
extern "C" void _s801A0318_1();
extern "C" void _s801A0318_2();
extern "C" void _s801A0318_3();
extern "C" void _s801A0318_4();
extern "C" void _s801A0318_5();
extern "C" void f_801A0318() {}
