// 0x8008DD70 ELiveMode::IsReadyForUpdate(void) (440 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-16(1); mfspr 0,8; stmw 30,0x8(1); stw 0,0x14(1); lis 9,-32697; mr 31,3; addi 30,9,23428; lwz 11,0x9c(30); cmpwi 11,0; beq 1f; bl _s8008DD70_0; cmpwi 3,0; bne 0f; mr 3,31; bl _s8008DD70_1; b 10f; 0:; lwz 9,-32160(13); lwz 0,0xb4(9); andi. 9,0,4; beq 10f; mr 3,31; bl _s8008DD70_2; lis 9,-32696; li 11,0; addi 9,9,22744; li 0,1; stw 11,0x28(9); stw 0,0xa8(30); stw 11,0x9c(30); b 10f; 1:; lwz 0,0x30(31); cmpwi 0,0; bne 2f; lwz 3,-21500(13); lis 4,21321; ori 4,4,19795; bl _s8008DD70_3; li 4,18; bl _s8008DD70_4; b 10f; 2:; lwz 9,0xc8(30); li 0,1; stw 0,0x90(30); cmpwi 9,0; beq 4f; lwz 9,0xcc(30); addi 9,9,-1; cmpwi 9,0; stw 9,0xcc(30); bgt 3f; lwz 3,0x100(30); stw 11,0xc8(30); bl _s8008DD70_5; lwz 0,0xec(30); cmpwi 0,0; beq 3f; lwz 3,0x110(30); bl _s8008DD70_6; 3:; lis 9,-32697; li 0,1; stw 0,0x5c44(9); 4:; lwz 0,0x24(31); cmpwi 0,0; beq 6f; lis 9,-32697; lwz 0,0x622c(9); cmpwi 0,0; beq 5f; mr 3,31; bl _s8008DD70_7; b 8f; 5:; mr 3,31; bl _s8008DD70_8; b 10f; 6:; lwz 0,0x28(31); cmpwi 0,0; beq 8f; lis 9,-32697; addi 9,9,23428; lwz 0,0xe8(9); cmpwi 0,0; bne 7f; lwz 0,0xf0(9); cmpwi 0,0; beq 10f; 7:; lis 9,-32707; li 0,0; lfs f0,0x7de8(9); stw 0,0x18(31); stfs f0,0x14(31); 8:; lwz 0,0x1c(31); cmpwi 0,1; beq 9f; li 3,1; b 11f; 9:; lwz 11,-21496(13); li 0,0; stw 0,0x1c(31); lwz 9,0x0(11); lha 3,0x58(9); lwz 0,0x5c(9); add 3,11,3; mtspr 8,0; blrl; 10:; li 3,0; 11:; lwz 0,0x14(1); mtspr 8,0; lmw 30,0x8(1); addi 1,1,16"
extern "C" void _s8008DD70_0();
extern "C" void _s8008DD70_1();
extern "C" void _s8008DD70_2();
extern "C" void _s8008DD70_3();
extern "C" void _s8008DD70_4();
extern "C" void _s8008DD70_5();
extern "C" void _s8008DD70_6();
extern "C" void _s8008DD70_7();
extern "C" void _s8008DD70_8();
extern "C" void f_8008DD70() {}
