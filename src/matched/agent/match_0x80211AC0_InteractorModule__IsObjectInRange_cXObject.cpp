// 0x80211AC0 InteractorModule::IsObjectInRange(cXObject (244 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-24(1); mfspr 0,8; stmw 30,0x10(1); stw 0,0x1c(1); mr. 11,3; beq 1f; lwz 9,0x4(11); addi 3,1,8; li 31,0; lha 4,0x358(9); lwz 0,0x35c(9); add 4,11,4; mtspr 8,0; blrl; addi 3,1,8; bl _s80211AC0_0; cmpwi 3,0; blt 0f; addi 3,1,8; bl _s80211AC0_1; lwz 11,-21488(13); mr 30,3; lwz 9,0x0(11); lha 3,0x30(9); lwz 0,0x34(9); add 3,11,3; mtspr 8,0; blrl; addi 3,3,-1; cmpw 30,3; bgt 0f; addi 3,1,8; bl _s80211AC0_2; cmpwi 3,0; blt 0f; addi 3,1,8; bl _s80211AC0_3; lwz 11,-21488(13); mr 30,3; lwz 9,0x0(11); lha 3,0x38(9); lwz 0,0x3c(9); add 3,11,3; mtspr 8,0; blrl; addi 3,3,-1; cmpw cr7,30,3; cror 31,30,28; mfcr 31; rlwinm 31,31,0,31,31; 0:; addi 3,1,8; li 4,2; bl _s80211AC0_4; mr 3,31; b 2f; 1:; li 3,0; 2:; lwz 0,0x1c(1); mtspr 8,0; lmw 30,0x10(1); addi 1,1,24"
extern "C" void _s80211AC0_0();
extern "C" void _s80211AC0_1();
extern "C" void _s80211AC0_2();
extern "C" void _s80211AC0_3();
extern "C" void _s80211AC0_4();
extern "C" void f_80211AC0() {}
