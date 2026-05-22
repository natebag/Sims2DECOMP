// 0x801C7D80 MMUTarget::UpdateMenuState(char (420 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-40(1); mfspr 0,8; stw 31,0x24(1); stw 0,0x2c(1); mr 31,3; mr 3,5; bl _s801C7D80_0; mr 11,3; mr 9,11; stw 11,0x18(1); cmpwi 9,1; beq 1f; bgt 0f; cmpwi 9,0; beq 3f; b 7f; 0:; cmpwi 9,2; beq 2f; cmpwi 9,4; beq 6f; b 7f; 1:; lwz 0,0xb0(31); mr 3,31; stw 9,0xb0(31); stw 0,0xb4(31); bl _s801C7D80_1; b 7f; 2:; lwz 0,0xac(31); cmpwi 0,0; bne 7f; lwz 0,0xb8(31); cmpwi 0,2; bne 7f; li 3,248; bl _s801C7D80_2; bl _s801C7D80_3; mr 0,3; stw 0,0xac(31); bl _s801C7D80_4; lwz 0,0xb0(31); lwz 9,0x18(1); stw 0,0xb4(31); stw 9,0xb0(31); b 7f; 3:; lwz 0,0xac(31); cmpwi 0,0; beq 4f; stw 9,0xac(31); 4:; lwz 0,0xb0(31); lwz 9,0x18(1); cmpwi 0,2; stw 0,0xb4(31); stw 9,0xb0(31); bne 5f; stw 11,0xb8(31); 5:; mr 3,31; bl _s801C7D80_5; b 7f; 6:; lwz 0,0xb0(31); mr 3,31; stw 11,0xb0(31); stw 0,0xb4(31); bl _s801C7D80_6; stw 3,0x100(31); mr 3,31; bl _s801C7D80_7; 7:; lwz 0,0xf8(31); cmpwi 0,1; bne 9f; addi 3,31,200; addi 4,1,24; lwz 9,0x18(3); lwz 11,0x10(3); addi 9,9,-4; cmpw 11,9; beq 8f; lwz 0,0x18(1); stw 0,0x0(11); lwz 9,0x10(3); addi 9,9,4; stw 9,0x10(3); b 9f; 8:; bl _s801C7D80_8; 9:; li 0,1; lwz 5,0xb0(31); lis 4,-32705; stw 0,0xf8(31); addi 4,4,-8800; addi 3,1,8; crxor 6,6,6; bl _s801C7D80_9; addi 0,1,8; lis 3,-32705; stw 0,0x1c(1); addi 3,3,11780; li 4,0; li 5,0; li 6,1; addi 7,1,28; bl _s801C7D80_10; lwz 0,0x2c(1); mtspr 8,0; lwz 31,0x24(1); addi 1,1,40"
extern "C" void _s801C7D80_0();
extern "C" void _s801C7D80_1();
extern "C" void _s801C7D80_2();
extern "C" void _s801C7D80_3();
extern "C" void _s801C7D80_4();
extern "C" void _s801C7D80_5();
extern "C" void _s801C7D80_6();
extern "C" void _s801C7D80_7();
extern "C" void _s801C7D80_8();
extern "C" void _s801C7D80_9();
extern "C" void _s801C7D80_10();
extern "C" void f_801C7D80() {}
