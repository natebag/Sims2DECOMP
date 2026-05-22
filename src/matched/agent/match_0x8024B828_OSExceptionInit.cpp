// 0x8024B828 OSExceptionInit (640 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="mfspr 0,8; stw 0,0x4(1); stwu 1,-56(1); stmw 20,0x8(1); lis 3,-32768; lwz 0,0x60(3); lis 4,-32731; addi 30,4,-17560; lis 5,-32731; lwz 25,0x0(30); lis 4,-32731; addi 5,5,-17664; addi 4,4,-17512; lis 6,-32700; cmplwi 0,0; mr 24,5; addi 29,6,-21680; subf 23,5,4; addi 20,3,96; bne 0f; addi 3,29,352; crxor 6,6,6; bl _s8024B828_0; lis 4,-32731; lis 3,-32731; addi 0,3,-17716; addi 4,4,-17752; subf 21,4,0; mr 3,20; mr 5,21; bl _s8024B828_1; mr 3,20; mr 4,21; bl _s8024B828_2; sync; mr 3,20; mr 4,21; bl _s8024B828_3; 0:; lis 4,-32731; lis 3,-32731; addi 31,4,-17716; addi 0,3,-17712; addi 28,29,292; subf 27,31,0; li 26,0; b 1f; 1:; lis 3,-32731; addi 21,3,-17576; lis 22,24576; b 2f; 2:; b 12f; 3:; lwz 3,-23740(13); cmplwi 3,0; beq 4f; lwz 0,0x0(3); cmplwi 0,2; blt 4f; mr 3,26; bl _s8024B828_4; cmpwi 3,0; beq 4f; addi 3,29,380; crxor 6,6,6; rlwinm 4,26,0,24,31; bl _s8024B828_5; b 11f; 4:; rlwinm 20,26,0,24,31; or 0,25,20; stw 0,0x0(30); mr 3,26; bl _s8024B828_6; cmpwi 3,0; beq 5f; mr 4,20; crxor 6,6,6; addi 3,29,428; bl _s8024B828_7; mr 3,21; mr 4,31; mr 5,27; bl _s8024B828_8; b 10f; 5:; mr 4,21; b 6f; 6:; cmplwi 27,0; addi 3,27,3; rlwinm 3,3,30,2,31; ble 10f; rlwinm 0,3,29,3,31; cmplwi 0,0; mtspr 9,0; beq 8f; b 7f; 7:; stw 22,0x0(4); addi 4,4,4; stw 22,0x0(4); addi 4,4,4; stw 22,0x0(4); addi 4,4,4; stw 22,0x0(4); addi 4,4,4; stw 22,0x0(4); addi 4,4,4; stw 22,0x0(4); addi 4,4,4; stw 22,0x0(4); addi 4,4,4; stw 22,0x0(4); addi 4,4,4; bdnz 7b; andi. 3,3,7; beq 10f; 8:; mtspr 9,3; b 9f; 9:; stw 22,0x0(4); addi 4,4,4; bdnz 9b; 10:; lwz 3,0x0(28); mr 4,24; mr 5,23; addis 20,3,-32768; mr 3,20; bl _s8024B828_9; mr 3,20; mr 4,23; bl _s8024B828_10; sync; mr 3,20; mr 4,23; bl _s8024B828_11; 11:; addi 28,28,4; addi 26,26,1; 12:; rlwinm 0,26,0,24,31; cmplwi 0,15; blt 3b; lis 3,-32768; addi 0,3,12288; stw 0,-23708(13); li 20,0; b 13f; 13:; lis 3,-32731; addi 23,3,-17508; b 14f; 14:; b 16f; 15:; mr 3,20; mr 4,23; bl _s8024B828_12; addi 20,20,1; 16:; rlwinm 0,20,0,24,31; cmplwi 0,15; blt 15b; stw 25,0x0(30); addi 3,29,476; crxor 6,6,6; bl _s8024B828_13; lmw 20,0x8(1); lwz 0,0x3c(1); addi 1,1,56; mtspr 8,0"
extern "C" void _s8024B828_0();
extern "C" void _s8024B828_1();
extern "C" void _s8024B828_2();
extern "C" void _s8024B828_3();
extern "C" void _s8024B828_4();
extern "C" void _s8024B828_5();
extern "C" void _s8024B828_6();
extern "C" void _s8024B828_7();
extern "C" void _s8024B828_8();
extern "C" void _s8024B828_9();
extern "C" void _s8024B828_10();
extern "C" void _s8024B828_11();
extern "C" void _s8024B828_12();
extern "C" void _s8024B828_13();
extern "C" void f_8024B828() {}
