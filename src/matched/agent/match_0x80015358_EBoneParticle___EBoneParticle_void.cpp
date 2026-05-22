// 0x80015358 EBoneParticle::~EBoneParticle(void) (428 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-24(1); mfspr 0,8; stmw 29,0xc(1); stw 0,0x1c(1); mr 31,3; li 0,0; lwz 3,0x68(31); mr 29,4; stw 0,0x50(31); cmpwi 3,0; beq 3f; li 4,8; li 5,1; bl _s80015358_0; lwz 0,0x78(31); cmpwi 0,0; bne 0f; lwz 3,0x68(31); li 4,16384; li 5,1; bl _s80015358_1; b 1f; 0:; lwz 3,0x68(31); li 4,16384; li 5,0; bl _s80015358_2; lwz 3,0x68(31); li 5,1; lwz 4,-22708(13); bl _s80015358_3; lis 3,-32692; lwz 4,0x70(31); addi 3,3,6092; li 5,1; bl _s80015358_4; 1:; lwz 11,0x68(31); cmpwi 11,0; beq 2f; lwz 9,0x0(11); li 4,3; lha 3,0x30(9); lwz 0,0x34(9); add 3,11,3; mtspr 8,0; blrl; 2:; li 0,0; stw 0,0x60(31); stw 0,0x68(31); stw 0,0x70(31); b 7f; 3:; lwz 9,0x6c(31); cmpwi 9,0; beq 6f; lwz 0,0x78(31); cmpwi 0,0; bne 4f; lwz 0,0x140(9); ori 0,0,4096; stw 0,0x140(9); lwz 11,0x6c(31); lwz 9,0x144(11); lha 3,0x20(9); lwz 0,0x24(9); add 3,11,3; mtspr 8,0; blrl; b 5f; 4:; bl _s80015358_5; lwz 4,0x6c(31); bl _s80015358_6; 5:; li 0,0; stw 0,0x74(31); stw 0,0x6c(31); b 7f; 6:; lwz 4,0x60(31); cmpwi 4,0; beq 8f; lwz 30,0x64(31); cmpwi 30,0; bne 7f; lis 3,-32692; addi 3,3,6092; bl _s80015358_7; stw 30,0x60(31); stw 30,0x70(31); 7:; lwz 4,0x60(31); cmpwi 4,0; beq 8f; lwz 0,0x64(31); cmpwi 0,1; bne 8f; lis 3,-32692; addi 3,3,-644; bl _s80015358_8; li 0,0; stw 0,0x60(31); stw 0,0x74(31); 8:; andi. 0,29,1; beq 9f; bl _s80015358_9; mr 4,31; bl _s80015358_10; 9:; lwz 0,0x1c(1); mtspr 8,0; lmw 29,0xc(1); addi 1,1,24"
extern "C" void _s80015358_0();
extern "C" void _s80015358_1();
extern "C" void _s80015358_2();
extern "C" void _s80015358_3();
extern "C" void _s80015358_4();
extern "C" void _s80015358_5();
extern "C" void _s80015358_6();
extern "C" void _s80015358_7();
extern "C" void _s80015358_8();
extern "C" void _s80015358_9();
extern "C" void _s80015358_10();
extern "C" void f_80015358() {}
