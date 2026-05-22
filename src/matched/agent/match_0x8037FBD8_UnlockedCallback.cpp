// 0x8037FBD8 UnlockedCallback (272 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="mfspr 0,8; cmpwi 4,0; stw 0,0x4(1); stwu 1,-24(1); stw 31,0x14(1); addi 31,3,0; mulli 5,31,272; stw 30,0x10(1); lis 3,-32688; addi 0,3,-24000; add 30,0,5; blt 1f; lis 3,-32712; addi 0,3,-1064; lis 3,-32712; stw 0,0xdc(30); addi 5,3,-3584; addi 3,31,0; li 4,0; bl _s8037FBD8_0; cmpwi 3,0; bne 0f; li 4,0; b 1f; 0:; li 0,0; stw 0,0xdc(30); mr 3,31; bl _s8037FBD8_1; mr 4,3; 1:; cmpwi 4,0; bge 5f; lbz 0,0x94(30); cmpwi 0,243; beq 5f; bge 2f; cmpwi 0,82; beq 3f; blt 5f; cmpwi 0,241; bge 4f; b 5f; 2:; cmpwi 0,245; bge 5f; b 4f; 3:; lwz 0,0xc8(30); cmplwi 0,0; mr 12,0; beq 5f; li 0,0; mtspr 8,12; stw 0,0xc8(30); mr 3,31; blrl; b 5f; 4:; lwz 12,0xcc(30); cmplwi 12,0; beq 5f; li 0,0; mtspr 8,12; stw 0,0xcc(30); mr 3,31; blrl; 5:; lwz 0,0x1c(1); lwz 31,0x14(1); lwz 30,0x10(1); addi 1,1,24; mtspr 8,0"
extern "C" void _s8037FBD8_0();
extern "C" void _s8037FBD8_1();
extern "C" void f_8037FBD8() {}
