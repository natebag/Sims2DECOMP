// 0x8028FA1C TextFormat::copyTextFormatObj(TextFormat (200 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-16(1); mfspr 0,8; stmw 30,0x8(1); stw 0,0x14(1); mr 31,4; mr 30,3; lwz 0,0xc(31); cmpwi 0,3; beq 0f; stw 0,0xc(30); 0:; lwz 0,0x8(31); cmpwi 0,-1; beq 1f; stw 0,0x8(30); 1:; lis 4,-32704; mr 3,31; addi 4,4,18440; bl _s8028FA1C_0; cmpwi 3,0; beq 2f; mr 3,30; mr 4,31; bl _s8028FA1C_1; 2:; lis 9,-32704; lfs f13,0x4(31); lfs f0,0x4fa8(9); fcmpu 0,f13,f0; beq 3f; stfs f13,0x4(30); 3:; lwz 0,0x10(31); cmpwi 0,2; beq 4f; stw 0,0x10(30); 4:; lwz 0,0x14(31); cmpwi 0,-1; beq 5f; stw 0,0x14(30); 5:; lwz 0,0x18(31); cmpwi 0,-1; beq 6f; stw 0,0x18(30); 6:; lwz 3,0x1c(31); cmpwi 3,-1; beq 7f; stw 3,0x1c(30); 7:; lwz 0,0x14(1); mtspr 8,0; lmw 30,0x8(1); addi 1,1,16"
extern "C" void _s8028FA1C_0();
extern "C" void _s8028FA1C_1();
extern "C" void f_8028FA1C() {}
