// 0x8027D8C0 AptActionInterpreter::_FunctionAptActionGetUrl(AptActionInterpreter (416 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-1072(1); mfspr 0,8; stmw 29,0x424(1); stw 0,0x434(1); lwz 9,0x0(4); mr 31,3; addi 9,9,3; rlwinm 30,9,0,0,29; addi 0,30,8; stw 0,0x0(4); lwz 4,0x0(30); bl _s8027D8C0_0; mr. 29,3; beq 0f; lwz 5,0x4(30); mr 3,31; lwz 4,0x0(30); bl _s8027D8C0_1; b 5f; 0:; addi 3,1,8; lwz 4,0x0(30); mr 31,3; bl _s8027D8C0_2; addi 3,1,8; bl _s8027D8C0_3; addi 0,3,-1; lbzx 9,31,0; extsb 9,9; cmpwi 9,102; beq 1f; cmpwi 9,70; bne 4f; 1:; addi 0,3,-2; lbzx 9,31,0; extsb 9,9; cmpwi 9,119; beq 2f; cmpwi 9,87; bne 4f; 2:; addi 0,3,-3; lbzx 9,31,0; extsb 9,9; cmpwi 9,115; beq 3f; cmpwi 9,83; bne 4f; 3:; addi 9,3,-4; lbzx 0,31,9; cmpwi 0,46; bne 4f; stbx 29,31,9; addi 3,1,1032; lwz 4,0x4(30); bl _s8027D8C0_4; addi 3,1,1040; mr 4,31; lwz 30,-22996(13); bl _s8027D8C0_5; addi 4,1,1040; mr 3,30; addi 5,1,1032; bl _s8027D8C0_6; lwz 4,0x410(1); lhz 9,0x0(4); addi 9,9,-1; rlwinm 0,9,0,16,31; sth 9,0x0(4); cmpwi 0,0; bne 5f; lhz 5,0x4(4); lwz 3,-23020(13); addi 5,5,9; bl _s8027D8C0_7; b 5f; 4:; cmpwi 3,0; bne 5f; lwz 4,0x4(30); addi 3,1,1032; bl _s8027D8C0_8; lis 4,-32704; addi 3,1,1048; lwz 30,-22996(13); addi 4,4,5608; bl _s8027D8C0_9; addi 4,1,1048; mr 3,30; addi 5,1,1032; bl _s8027D8C0_10; lwz 4,0x418(1); lhz 9,0x0(4); addi 9,9,-1; rlwinm 0,9,0,16,31; sth 9,0x0(4); cmpwi 0,0; bne 5f; lhz 5,0x4(4); lwz 3,-23020(13); addi 5,5,9; bl _s8027D8C0_11; 5:; lwz 0,0x434(1); mtspr 8,0; lmw 29,0x424(1); addi 1,1,1072"
extern "C" void _s8027D8C0_0();
extern "C" void _s8027D8C0_1();
extern "C" void _s8027D8C0_2();
extern "C" void _s8027D8C0_3();
extern "C" void _s8027D8C0_4();
extern "C" void _s8027D8C0_5();
extern "C" void _s8027D8C0_6();
extern "C" void _s8027D8C0_7();
extern "C" void _s8027D8C0_8();
extern "C" void _s8027D8C0_9();
extern "C" void _s8027D8C0_10();
extern "C" void _s8027D8C0_11();
extern "C" void f_8027D8C0() {}
