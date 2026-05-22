// 0x8005EC74 SAnimator2::EndFollow(void) (296 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-24(1); mfspr 0,8; stmw 29,0xc(1); stw 0,0x1c(1); mr 31,3; li 0,0; lwz 9,0x8(31); li 29,1; stw 0,0x5fc(31); stw 0,0x1cc(31); addi 11,9,820; lwz 9,0x8(11); cmpwi 9,-1; beq 0f; mulli 9,9,176; lwz 0,0x44(11); add 9,9,0; lwz 9,0x30(9); b 1f; 0:; li 9,0; 1:; andi. 0,9,33; bne 2f; lwz 9,0x0(31); lha 3,0x138(9); lwz 0,0x13c(9); add 3,31,3; mtspr 8,0; blrl; 2:; lwz 0,0x668(31); cmpwi 0,0; beq 3f; mr 3,31; bl _s8005EC74_0; 3:; lwz 0,0x10(31); cmpwi 0,1; bne 4f; li 29,0; 4:; lwz 0,0x18(31); cmpwi 0,5; beq 5f; mr 3,31; bl _s8005EC74_1; 5:; lis 9,-32707; lis 11,-32707; lwz 3,0x8(31); li 30,0; lfs f1,0x4720(9); li 4,0; lfs f2,0x4724(11); addi 3,3,820; stw 30,0x10(31); bl _s8005EC74_2; mr 3,31; bl _s8005EC74_3; lwz 0,0x600(31); cmpwi 0,1; bne 6f; lwz 10,0x4(31); li 4,17; li 5,0; lwz 11,0x0(10); lwz 9,0x4(11); lha 3,0x1e8(9); lwz 0,0x1ec(9); add 3,11,3; mtspr 8,0; blrl; stw 30,0x600(31); 6:; mr 3,29; lwz 0,0x1c(1); mtspr 8,0; lmw 29,0xc(1); addi 1,1,24"
extern "C" void _s8005EC74_0();
extern "C" void _s8005EC74_1();
extern "C" void _s8005EC74_2();
extern "C" void _s8005EC74_3();
extern "C" void f_8005EC74() {}
