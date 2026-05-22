// 0x80034464 ESim::UpdateSkinChange(void) (352 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-16(1); mfspr 0,8; stmw 30,0x8(1); stw 0,0x14(1); mr 31,3; lwz 0,0x630(31); cmpwi 0,-1; beq 7f; cmpwi 0,0; bne 4f; lwz 0,-32584(13); cmpwi 0,0; bne 7f; lwz 0,0x430(31); cmpwi 0,0; beq 0f; lis 9,-32707; lfs f13,0x438(31); lfs f0,0x1208(9); fcmpu 0,f13,f0; cror 3,2,1; bso 1f; 0:; lwz 0,0x424(31); cmpwi 0,0; beq 7f; 1:; lwz 3,0x3d0(31); lwz 9,0x4(3); lha 0,0x160(9); lwz 9,0x164(9); add 3,3,0; mtspr 8,9; blrl; cmpwi 3,0; bne 6f; stw 31,-32584(13); li 30,1; stw 30,0x630(31); mr 3,31; bl _s80034464_0; cmpwi 3,0; beq 2f; lis 3,-32697; addi 3,3,14696; bl _s80034464_1; 2:; lwz 3,0x63c(31); bl _s80034464_2; cmpwi 3,0; beq 3f; mr 3,31; bl _s80034464_3; 3:; lis 3,-32697; stw 30,0x520(31); addi 3,3,14696; mr 4,31; li 5,1; bl _s80034464_4; b 7f; 4:; cmpwi 0,1; bne 5f; mr 3,31; bl _s80034464_5; mr. 3,3; bne 7f; stw 3,-32584(13); li 0,2; stw 0,0x630(31); b 7f; 5:; cmpwi 0,2; bne 7f; lwz 0,0x430(31); cmpwi 0,0; beq 6f; lwz 0,0x424(31); cmpwi 0,0; bne 6f; lwz 0,0x434(31); cmpwi 0,0; beq 7f; 6:; li 9,0; li 0,-1; stw 9,0x3d8(31); stw 0,0x630(31); stw 9,0x424(31); 7:; lwz 0,0x14(1); mtspr 8,0; lmw 30,0x8(1); addi 1,1,16"
extern "C" void _s80034464_0();
extern "C" void _s80034464_1();
extern "C" void _s80034464_2();
extern "C" void _s80034464_3();
extern "C" void _s80034464_4();
extern "C" void _s80034464_5();
extern "C" void f_80034464() {}
