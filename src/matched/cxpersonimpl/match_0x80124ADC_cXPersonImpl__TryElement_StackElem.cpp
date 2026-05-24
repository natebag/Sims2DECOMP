// 0x80124ADC cXPersonImpl::TryElement(StackElem (580 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-16(1); mfspr 0,8; stw 31,0xc(1); stw 0,0x14(1); mr 9,3; mr 11,4; mr 31,5; li 3,-1; cmpwi 31,37; mr 5,6; li 4,-1; sth 31,-31700(13); beq 22f; bgt 3f; cmpwi 31,22; beq 10f; bgt 1f; cmpwi 31,6; beq 8f; bgt 0f; cmpwi 31,3; beq 13f; b 24f; 0:; cmpwi 31,17; beq 14f; b 24f; 1:; cmpwi 31,29; beq 7f; bgt 2f; cmpwi 31,27; beq 21f; b 24f; 2:; cmpwi 31,30; beq 9f; b 24f; 3:; cmpwi 31,47; beq 12f; bgt 5f; cmpwi 31,44; beq 16f; bgt 4f; cmpwi 31,38; beq 25f; b 24f; 4:; cmpwi 31,45; beq 11f; b 24f; 5:; cmpwi 31,64; beq 15f; bgt 6f; cmpwi 31,62; beq 23f; b 24f; 6:; cmpwi 31,100; beq 25f; b 24f; 7:; mr 3,9; mr 4,11; bl _s80124ADC_0; b 25f; 8:; mr 3,9; mr 4,11; bl _s80124ADC_1; b 25f; 9:; mr 3,9; mr 4,11; bl _s80124ADC_2; b 25f; 10:; mr 3,9; mr 4,11; bl _s80124ADC_3; b 25f; 11:; mr 3,9; mr 4,11; bl _s80124ADC_4; b 25f; 12:; mr 3,9; mr 4,11; bl _s80124ADC_5; b 25f; 13:; mr 3,9; mr 4,11; bl _s80124ADC_6; b 25f; 14:; mr 3,9; mr 4,11; bl _s80124ADC_7; b 25f; 15:; mr 3,9; mr 4,11; bl _s80124ADC_8; b 25f; 16:; lbz 10,0x3(5); li 8,0; cmpwi 10,0; beq 17f; addi 8,10,3; b 19f; 17:; lbz 0,0x5(5); andi. 10,0,1; beq 18f; li 8,1; 18:; andi. 10,0,16; beq 19f; ori 8,8,2; 19:; addi 0,8,-7; cmplwi 0,1; bgt 20f; lwz 3,0x0(9); mr 4,11; bl _s80124ADC_9; b 25f; 20:; lwz 3,0x3f4(9); mr 4,11; lwz 9,0x0(3); lha 0,0x48(9); lwz 9,0x4c(9); add 3,3,0; mtspr 8,9; blrl; b 25f; 21:; mr 3,9; mr 4,11; bl _s80124ADC_10; b 25f; 22:; mr 3,9; mr 4,11; bl _s80124ADC_11; b 25f; 23:; mr 3,9; mr 4,11; bl _s80124ADC_12; b 25f; 24:; mr 6,5; lwz 3,0x0(9); mr 4,11; mr 5,31; bl _s80124ADC_13; 25:; subfic 0,31,-1000; sth 0,-31700(13); lwz 0,0x14(1); mtspr 8,0; lwz 31,0xc(1); addi 1,1,16"

extern "C" void _s80124ADC_0();
extern "C" void _s80124ADC_1();
extern "C" void _s80124ADC_2();
extern "C" void _s80124ADC_3();
extern "C" void _s80124ADC_4();
extern "C" void _s80124ADC_5();
extern "C" void _s80124ADC_6();
extern "C" void _s80124ADC_7();
extern "C" void _s80124ADC_8();
extern "C" void _s80124ADC_9();
extern "C" void _s80124ADC_10();
extern "C" void _s80124ADC_11();
extern "C" void _s80124ADC_12();
extern "C" void _s80124ADC_13();

struct cXPersonImpl {
    void TryElement_StackElem();
};

void cXPersonImpl::TryElement_StackElem() {
}
