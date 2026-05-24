// 0x802DF8EC EBitArray::SetSize(int, (324 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-32(1); mfspr 0,8; stmw 26,0x8(1); stw 0,0x24(1); mr 30,3; mr 26,4; mr. 29,5; bne 0f; mr 29,26; 0:; addi 0,29,31; rlwinm 29,0,0,0,26; cmpwi 7,29,0; bne cr7,1f; mr 3,30; bl _s802DF8EC_0; b 9f; 1:; lwz 0,0x8(30); cmpw 0,29; bne 3f; lwz 0,0x4(30); cmpw 0,26; bge 8f; cmpw 26,0; mr 31,26; bge 8f; 2:; mr 4,31; mr 3,30; li 5,0; addi 31,31,1; bl _s802DF8EC_1; lwz 0,0x4(30); cmpw 31,0; blt 2b; b 8f; 3:; mr 4,29; bge cr7,4f; addi 4,29,7; 4:; lwz 9,0x10(30); srawi 28,4,3; mr 4,28; lha 3,0x10(9); lwz 0,0x14(9); add 3,30,3; mtspr 8,0; blrl; mr. 27,3; beq 9f; lwz 4,0x0(30); cmpwi 4,0; beq 6f; lwz 9,0x4(30); mr 31,28; addi 9,9,31; rlwinm 0,9,29,3,29; cmpw 28,0; ble 5f; mr 31,0; 5:; mr 5,31; mr 3,27; crxor 6,6,6; bl _s802DF8EC_2; bl _s802DF8EC_3; lwz 4,0x0(30); bl _s802DF8EC_4; subf 5,31,28; add 3,27,31; li 4,0; bl _s802DF8EC_5; b 7f; 6:; mr 5,28; mr 3,27; li 4,0; bl _s802DF8EC_6; 7:; stw 29,0x8(30); stw 27,0x0(30); 8:; stw 26,0x4(30); 9:; lwz 0,0x24(1); mtspr 8,0; lmw 26,0x8(1); addi 1,1,32"

extern "C" void _s802DF8EC_0();
extern "C" void _s802DF8EC_1();
extern "C" void _s802DF8EC_2();
extern "C" void _s802DF8EC_3();
extern "C" void _s802DF8EC_4();
extern "C" void _s802DF8EC_5();
extern "C" void _s802DF8EC_6();

struct EBitArray {
    void SetSize();
};

void EBitArray::SetSize() {
}
