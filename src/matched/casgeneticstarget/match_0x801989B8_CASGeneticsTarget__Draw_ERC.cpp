// 0x801989B8 CASGeneticsTarget::Draw(ERC (260 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-24(1); mfspr 0,8; stmw 29,0xc(1); stw 0,0x1c(1); mr 30,3; mr 31,4; lwz 0,0x2f8(30); cmpwi 0,0; beq 6f; lwz 0,-31440(13); cmpwi 0,2; beq 3f; cmplwi 0,2; bgt 0f; cmpwi 0,1; beq 1f; b 6f; 0:; cmpwi 0,3; beq 1f; cmpwi 0,4; beq 5f; b 6f; 1:; li 31,0; li 29,26; 2:; bl _s801989B8_0; mr 5,3; mr 4,31; divwu 0,5,29; mr 3,30; addi 31,31,1; mulli 0,0,26; subf 5,0,5; bl _s801989B8_1; cmpwi 31,3; ble 2b; b 6f; 3:; li 31,2; li 29,26; 4:; bl _s801989B8_2; mr 5,3; mr 4,31; divwu 0,5,29; mr 3,30; addi 31,31,1; mulli 0,0,26; subf 5,0,5; bl _s801989B8_3; cmpwi 31,3; ble 4b; b 6f; 5:; lwz 9,0x70(31); addi 4,30,796; lha 3,0x168(9); lwz 0,0x16c(9); add 3,31,3; mtspr 8,0; blrl; lwz 3,0x2f8(30); mr 4,31; bl _s801989B8_4; 6:; lwz 0,0x1c(1); mtspr 8,0; lmw 29,0xc(1); addi 1,1,24"

extern "C" void _s801989B8_0();
extern "C" void _s801989B8_1();
extern "C" void _s801989B8_2();
extern "C" void _s801989B8_3();
extern "C" void _s801989B8_4();

struct CASGeneticsTarget {
    void Draw();
};

void CASGeneticsTarget::Draw() {
}
