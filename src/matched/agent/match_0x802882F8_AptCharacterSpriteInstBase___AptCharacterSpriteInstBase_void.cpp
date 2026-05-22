// 0x802882F8 AptCharacterSpriteInstBase::~AptCharacterSpriteInstBase(void) (144 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-16(1); mfspr 0,8; stmw 30,0x8(1); stw 0,0x14(1); mr 31,3; lis 9,-32704; lwz 0,0x2c(31); addi 9,9,20176; mr 30,4; stw 9,0x14(31); cmpwi 0,1; bne 0f; lwz 3,-23020(13); li 5,64; lwz 4,0x8(31); bl _s802882F8_0; 0:; addi 3,31,36; li 4,2; bl _s802882F8_1; lwz 3,0xc(31); lis 9,-32704; addi 9,9,20216; stw 9,0x14(31); cmpwi 3,0; beq 1f; li 4,3; bl _s802882F8_2; 1:; andi. 0,30,1; beq 2f; mr 3,31; bl _s802882F8_3; 2:; lwz 0,0x14(1); mtspr 8,0; lmw 30,0x8(1); addi 1,1,16"
extern "C" void _s802882F8_0();
extern "C" void _s802882F8_1();
extern "C" void _s802882F8_2();
extern "C" void _s802882F8_3();
extern "C" void f_802882F8() {}
