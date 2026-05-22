// 0x8028FA08 LoadGameTarget::SpawnNoSaveDialog(void) (428 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="lwz 0,0x14(1); mtspr 8,0; lmw 30,0x8(1); addi 1,1,16; blr; stwu 1,-16(1); mfspr 0,8; stmw 30,0x8(1); stw 0,0x14(1); mr 31,4; mr 30,3; lwz 0,0xc(31); cmpwi 0,3; beq 0f; stw 0,0xc(30); 0:; lwz 0,0x8(31); cmpwi 0,-1; beq 1f; stw 0,0x8(30); 1:; lis 4,-32704; mr 3,31; addi 4,4,18440; bl _s8028FA08_0; cmpwi 3,0; beq 2f; mr 3,30; mr 4,31; bl _s8028FA08_1; 2:; lis 9,-32704; lfs f13,0x4(31); lfs f0,0x4fa8(9); fcmpu 0,f13,f0; beq 3f; stfs f13,0x4(30); 3:; lwz 0,0x10(31); cmpwi 0,2; beq 4f; stw 0,0x10(30); 4:; lwz 0,0x14(31); cmpwi 0,-1; beq 5f; stw 0,0x14(30); 5:; lwz 0,0x18(31); cmpwi 0,-1; beq 6f; stw 0,0x18(30); 6:; lwz 3,0x1c(31); cmpwi 3,-1; beq 7f; stw 3,0x1c(30); 7:; lwz 0,0x14(1); mtspr 8,0; lmw 30,0x8(1); addi 1,1,16; blr; blr; stwu 1,-16(1); mfspr 0,8; stmw 30,0x8(1); stw 0,0x14(1); mr 31,3; lis 9,-32704; lwz 3,0xc(31); addi 9,9,20216; mr 30,4; stw 9,0x14(31); cmpwi 3,0; beq 8f; li 4,3; bl _s8028FA08_2; 8:; andi. 0,30,1; beq 9f; mr 3,31; bl _s8028FA08_3; 9:; lwz 0,0x14(1); mtspr 8,0; lmw 30,0x8(1); addi 1,1,16; blr; stwu 1,-16(1); mfspr 0,8; stw 31,0xc(1); stw 0,0x14(1); mr 31,3; lwz 3,0xc(31); cmpwi 3,0; beq 10f; bl _s8028FA08_4; 10:; li 0,1; stw 0,0x10(31); lwz 0,0x14(1); mtspr 8,0; lwz 31,0xc(1); addi 1,1,16; blr; lwz 0,0x1c(3); srawi 9,0,8; or 9,9,4; rlwimi 0,9,8,0,23; stw 0,0x1c(3); blr; lwz 0,0x1c(3); srawi 9,0,8; andc 4,9,4; rlwimi 0,4,8,0,23; stw 0,0x1c(3)"
extern "C" void _s8028FA08_0();
extern "C" void _s8028FA08_1();
extern "C" void _s8028FA08_2();
extern "C" void _s8028FA08_3();
extern "C" void _s8028FA08_4();
extern "C" void f_8028FA08() {}
