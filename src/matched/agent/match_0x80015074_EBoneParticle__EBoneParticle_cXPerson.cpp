// 0x80015074 EBoneParticle::EBoneParticle(cXPerson (336 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-32(1); mfspr 0,8; stmw 27,0xc(1); stw 0,0x24(1); mr 31,3; li 29,0; li 0,0; stw 29,0x44(31); stw 29,0x48(31); mr 30,5; stw 29,0x4c(31); mr 28,4; sth 0,0x40(31); mr 27,6; bl _s80015074_0; lwz 0,0x0(30); li 8,1; stw 28,0x50(31); stw 0,0x54(31); stw 29,0x68(31); stw 29,0x6c(31); stw 29,0x70(31); stw 29,0x74(31); lbz 10,-18452(13); lwz 4,0x4(30); stw 4,0x60(31); lbz 9,-18451(13); lbz 0,-18452(13); lha 11,0x8(30); nor 0,0,9; and 11,11,0; stw 11,0x64(31); lhz 0,0xa(30); sth 0,0x40(31); lha 9,0x8(30); and. 0,9,10; bne 0f; li 8,0; 0:; stw 8,0x4c(31); li 10,1; lbz 9,-18451(13); lha 0,0x8(30); and. 8,0,9; bne 1f; li 10,0; 1:; stw 10,0x48(31); cmpwi 11,0; stw 27,0x7c(31); stw 29,0x78(31); bne 2f; lis 3,-32692; addi 3,3,6092; bl _s80015074_1; b 4f; 2:; cmpwi 11,1; bne 4f; cmpwi 28,0; beq 3f; lwz 9,0x4(28); lwz 0,0x18c(9); lha 3,0x188(9); mtspr 8,0; add 3,28,3; blrl; lwz 9,0x0(3); mr 5,31; lwz 4,0x54(31); lha 0,0xf0(9); lwz 9,0xf4(9); add 3,3,0; mtspr 8,9; blrl; 3:; lis 3,-32692; lwz 4,0x60(31); addi 3,3,-644; bl _s80015074_2; 4:; mr 3,31; bl _s80015074_3; mr 3,31; lwz 0,0x24(1); mtspr 8,0; lmw 27,0xc(1); addi 1,1,32"
extern "C" void _s80015074_0();
extern "C" void _s80015074_1();
extern "C" void _s80015074_2();
extern "C" void _s80015074_3();
extern "C" void f_80015074() {}
