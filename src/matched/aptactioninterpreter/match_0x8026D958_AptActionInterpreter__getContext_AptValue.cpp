// 0x8026D958 AptActionInterpreter::getContext(AptValue (520 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-312(1); mfspr 0,8; stmw 23,0x114(1); stw 0,0x13c(1); lwz 5,0x0(5); mr 24,7; li 25,0; mr 28,4; stb 25,0x0(24); addi 4,5,8; mr 27,6; mr 29,3; lbz 0,0x8(5); cmpwi 0,47; bne 0f; lwz 9,-23008(13); addi 31,5,9; li 25,1; lwz 11,0x28(9); lwz 10,0x0(11); lwz 29,0x54(10); stw 29,0x0(27); b 1f; 0:; stw 29,0x0(27); mr 31,4; 1:; addi 9,1,8; li 23,0; mr 26,9; 2:; lbz 11,0x0(31); extsb 0,11; cmpwi 0,46; beq 4f; bgt 3f; cmpwi 0,0; beq 11f; b 14f; 3:; cmpwi 0,58; beq 8f; b 14f; 4:; lbz 0,0x1(31); extsb 0,0; cmpwi 0,46; bne 5f; stb 11,0x0(9); lbzu 0,0x1(31); stbu 0,0x1(9); addi 31,31,1; addi 9,9,1; b 2b; 5:; cmpwi 0,0; bne 6f; stw 0,0x0(27); mr 3,25; b 15f; 6:; stb 23,0x0(9); addi 3,1,264; mr 4,26; bl _s8026D958_0; mr 3,29; addi 4,1,264; mr 5,28; bl _s8026D958_1; lwz 4,0x108(1); mr 29,3; lhz 9,0x0(4); addi 9,9,-1; rlwinm 0,9,0,16,31; sth 9,0x0(4); cmpwi 0,0; bne 7f; lhz 5,0x4(4); lwz 3,-23020(13); addi 5,5,9; bl _s8026D958_2; 7:; li 28,0; cmpwi 29,0; bne 10f; stw 29,0x0(27); mr 3,25; b 15f; 8:; stb 23,0x0(9); addi 3,1,264; mr 4,26; bl _s8026D958_3; addi 4,1,264; mr 5,28; mr 3,29; bl _s8026D958_4; lwz 4,0x108(1); mr 30,3; lhz 9,0x0(4); addi 9,9,-1; rlwinm 0,9,0,16,31; sth 9,0x0(4); cmpwi 0,0; bne 9f; lhz 5,0x4(4); lwz 3,-23020(13); addi 5,5,9; bl _s8026D958_5; 9:; li 28,0; cmpwi 30,0; beq 10f; stw 30,0x0(27); mr 3,24; addi 4,31,1; b 13f; 10:; addi 31,31,1; mr 9,26; b 2b; 11:; stb 0,0x0(9); cmpwi 28,0; stw 28,0x0(27); bne 12f; stw 29,0x0(27); 12:; mr 3,24; addi 4,1,8; 13:; bl _s8026D958_6; mr 3,25; b 15f; 14:; lbz 0,0x0(31); addi 31,31,1; stb 0,0x0(9); addi 9,9,1; b 2b; 15:; lwz 0,0x13c(1); mtspr 8,0; lmw 23,0x114(1); addi 1,1,312"

extern "C" void _s8026D958_0();
extern "C" void _s8026D958_1();
extern "C" void _s8026D958_2();
extern "C" void _s8026D958_3();
extern "C" void _s8026D958_4();
extern "C" void _s8026D958_5();
extern "C" void _s8026D958_6();

struct AptActionInterpreter {
    void getContext();
};

void AptActionInterpreter::getContext() {
}
