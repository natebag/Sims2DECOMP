// 0x801F6E88 INVTarget::GetOnMsgInvShpCanPurchase(char (708 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-48(1); mfspr 0,8; stmw 27,0x1c(1); stw 0,0x34(1); mr 31,3; mr 27,4; lwz 0,0x90(31); cmpwi 0,0; beq 20f; addi 5,1,8; lbz 4,0x3251(31); mr 28,5; addi 6,1,16; bl _s801F6E88_0; lwz 9,0x10(1); li 0,1; stb 0,0x3253(31); cmpwi 9,11; beq 4f; bgt 0f; cmpwi 9,9; beq 1f; cmpwi 9,10; beq 3f; b 6f; 0:; cmpwi 9,13; bgt 6f; b 5f; 1:; lwz 5,0x4(28); cmpwi 5,-1; bne 2f; lwz 3,0x90(31); li 4,4; li 5,-1; li 6,1; bl _s801F6E88_1; b 7f; 2:; lwz 3,0x90(31); li 4,2; li 6,1; bl _s801F6E88_2; b 7f; 3:; lwz 5,0x4(28); li 4,5; lwz 3,0x90(31); li 6,1; bl _s801F6E88_3; b 7f; 4:; lwz 5,0x4(28); li 4,3; lwz 3,0x90(31); li 6,1; bl _s801F6E88_4; b 7f; 5:; lwz 3,0x8(1); lwz 30,0x90(31); bl _s801F6E88_5; mr 5,3; lbz 6,0x3253(31); mr 3,30; li 4,1; bl _s801F6E88_6; b 7f; 6:; lwz 0,0x10(1); cmplwi 0,14; bgt 20f; lwz 3,0x8(1); lwz 30,0x90(31); bl _s801F6E88_7; mr 4,3; lbz 5,0x3253(31); lbz 6,0x3252(31); mr 3,30; bl _s801F6E88_8; 7:; mr 29,3; cmpwi 29,0; bne 9f; addi 30,31,12892; li 5,2; mr 4,30; mr 3,31; bl _s801F6E88_9; mr 3,30; bl _s801F6E88_10; lwz 3,0x3298(31); cmpwi 3,0; beq 8f; bl _s801F6E88_11; stw 29,0x3298(31); 8:; lis 4,-32704; mr 3,27; addi 4,4,-30824; crxor 6,6,6; bl _s801F6E88_12; b 20f; 9:; lwz 0,0x10(1); cmpwi 0,9; beq 10f; blt 14f; cmpwi 0,10; beq 12f; cmpwi 0,11; beq 13f; b 14f; 10:; lwz 5,0x4(28); cmpwi 5,-1; bne 11f; mr 3,31; li 4,4; li 5,-1; bl _s801F6E88_13; lwz 0,0x318c(31); stb 3,0x3253(31); cmpwi 7,0,19; mfcr 3; rlwinm 3,3,30,31,31; b 16f; 11:; mr 3,31; li 4,2; bl _s801F6E88_14; stb 3,0x3253(31); lwz 11,0x318c(31); lwz 9,0x8(1); lwz 0,0x4(9); cmpw cr7,11,0; b 15f; 12:; lwz 5,0x4(28); mr 3,31; li 4,5; bl _s801F6E88_15; stb 3,0x3253(31); lwz 11,0x318c(31); lwz 9,0x8(1); lwz 0,0x0(9); cmpw cr7,11,0; b 15f; 13:; lwz 5,0x4(28); mr 3,31; li 4,3; bl _s801F6E88_16; stb 3,0x3253(31); lwz 11,0x318c(31); lwz 9,0x8(1); lwz 0,0x0(9); cmpw cr7,11,0; b 15f; 14:; lwz 3,0x8(1); bl _s801F6E88_17; lbz 0,0x3253(31); lwz 9,0x318c(31); mullw 0,0,3; cmpw cr7,9,0; 15:; cror 31,30,29; mfcr 3; rlwinm 3,3,0,31,31; 16:; cmpwi 3,0; li 11,0; bne 17f; lis 9,-32697; lwz 0,0x6188(9); cmpwi 0,0; beq 18f; 17:; li 11,1; 18:; cmpwi 11,0; li 5,0; beq 19f; li 5,1; 19:; lis 4,-32704; mr 3,27; addi 4,4,-30836; crxor 6,6,6; bl _s801F6E88_18; 20:; lwz 0,0x34(1); mtspr 8,0; lmw 27,0x1c(1); addi 1,1,48"
extern "C" void _s801F6E88_0();
extern "C" void _s801F6E88_1();
extern "C" void _s801F6E88_2();
extern "C" void _s801F6E88_3();
extern "C" void _s801F6E88_4();
extern "C" void _s801F6E88_5();
extern "C" void _s801F6E88_6();
extern "C" void _s801F6E88_7();
extern "C" void _s801F6E88_8();
extern "C" void _s801F6E88_9();
extern "C" void _s801F6E88_10();
extern "C" void _s801F6E88_11();
extern "C" void _s801F6E88_12();
extern "C" void _s801F6E88_13();
extern "C" void _s801F6E88_14();
extern "C" void _s801F6E88_15();
extern "C" void _s801F6E88_16();
extern "C" void _s801F6E88_17();
extern "C" void _s801F6E88_18();
extern "C" void f_801F6E88() {}
