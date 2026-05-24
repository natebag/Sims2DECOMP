// 0x802B3248 AptValue::urlEncode(void) (624 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-56(1); mfspr 0,8; stmw 25,0x1c(1); stw 0,0x3c(1); lis 31,-32700; mr 28,3; lhz 9,-6476(31); addi 30,31,-6476; stw 30,0x8(1); addi 9,9,1; sth 9,-6476(31); lwz 0,0x0(4); andis. 9,0,2048; bne 0f; stw 30,0x0(28); lhz 0,-6476(31); mr 9,0; sth 0,-6476(31); cmpwi 9,0; bne 13f; lhz 5,0x4(30); mr 4,30; b 1f; 0:; lwz 9,0x8(4); lha 3,0x20(9); lwz 0,0x24(9); add 3,4,3; mtspr 8,0; blrl; mr. 29,3; bne 2f; lwz 11,0x8(1); stw 11,0x0(28); lhz 9,0x0(11); addi 9,9,1; sth 9,0x0(11); lwz 4,0x8(1); lhz 9,0x0(4); addi 9,9,-1; rlwinm 0,9,0,16,31; sth 9,0x0(4); cmpwi 0,0; bne 13f; lhz 5,0x4(4); 1:; lwz 3,-23020(13); addi 5,5,9; bl _s802B3248_0; b 13f; 2:; lhz 9,-6476(31); mr 3,29; stw 30,0x10(1); lis 25,-32703; addi 9,9,1; sth 9,-6476(31); bl _s802B3248_1; mr. 31,3; beq 11f; lis 27,-32694; addi 30,1,16; addi 26,27,-11332; 3:; lwz 3,0x0(31); lwz 4,-11332(27); lhz 9,0x2(3); lhz 0,0x2(4); cmpw 9,0; beq 4f; li 3,0; b 6f; 4:; cmpw 3,4; bne 5f; li 3,1; b 6f; 5:; addi 3,3,8; addi 4,4,8; bl _s802B3248_2; subfic 0,3,0; adde 3,0,3; 6:; cmpwi 3,0; bne 10f; lwz 3,0x0(31); lwz 4,0x1e0(26); lhz 9,0x2(3); lhz 0,0x2(4); cmpw 9,0; beq 7f; li 3,0; b 9f; 7:; cmpw 3,4; bne 8f; li 3,1; b 9f; 8:; addi 3,3,8; addi 4,4,8; bl _s802B3248_3; subfic 0,3,0; adde 3,0,3; 9:; cmpwi 3,0; bne 10f; lwz 3,0x4(31); mr 4,30; bl _s802B3248_4; mr 4,31; addi 3,1,8; bl _s802B3248_5; lis 4,-32703; addi 3,1,8; addi 4,4,8408; bl _s802B3248_6; mr 4,30; addi 3,1,8; bl _s802B3248_7; addi 3,1,8; addi 4,25,8412; bl _s802B3248_8; 10:; mr 4,31; mr 3,29; bl _s802B3248_9; mr. 31,3; bne 3b; 11:; lis 4,-32703; addi 3,1,8; addi 4,4,8412; bl _s802B3248_10; lwz 11,0x8(1); stw 11,0x0(28); lhz 9,0x0(11); addi 9,9,1; sth 9,0x0(11); lwz 4,0x10(1); lhz 9,0x0(4); addi 9,9,-1; rlwinm 0,9,0,16,31; sth 9,0x0(4); cmpwi 0,0; bne 12f; lhz 5,0x4(4); lwz 3,-23020(13); addi 5,5,9; bl _s802B3248_11; 12:; lwz 4,0x8(1); lhz 9,0x0(4); addi 9,9,-1; rlwinm 0,9,0,16,31; sth 9,0x0(4); cmpwi 0,0; bne 13f; lhz 5,0x4(4); lwz 3,-23020(13); addi 5,5,9; bl _s802B3248_12; 13:; mr 3,28; lwz 0,0x3c(1); mtspr 8,0; lmw 25,0x1c(1); addi 1,1,56"

extern "C" void _s802B3248_0();
extern "C" void _s802B3248_1();
extern "C" void _s802B3248_2();
extern "C" void _s802B3248_3();
extern "C" void _s802B3248_4();
extern "C" void _s802B3248_5();
extern "C" void _s802B3248_6();
extern "C" void _s802B3248_7();
extern "C" void _s802B3248_8();
extern "C" void _s802B3248_9();
extern "C" void _s802B3248_10();
extern "C" void _s802B3248_11();
extern "C" void _s802B3248_12();

struct AptValue {
    void urlEncode();
};

void AptValue::urlEncode() {
}
