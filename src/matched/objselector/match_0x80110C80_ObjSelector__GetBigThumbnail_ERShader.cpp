// 0x80110C80 ObjSelector::GetBigThumbnail(ERShader (196 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-24(1); mfspr 0,8; stmw 29,0xc(1); stw 0,0x1c(1); mr 31,3; mr 29,4; bl _s80110C80_0; li 4,1; bl _s80110C80_1; mr. 4,3; beq 3f; lis 3,-32692; li 5,0; addi 3,3,-17444; li 6,0; bl _s80110C80_2; cmpwi 3,0; stw 3,0x0(29); beq 2f; li 30,0; li 31,0; 0:; lwz 9,0x0(29); addi 9,9,32; lwzx 3,9,31; cmpwi 3,0; beq 1f; lwz 11,0x14(3); cmpwi 11,0; beq 1f; lwz 9,0x24(11); lha 3,0x58(9); lwz 0,0x5c(9); add 3,11,3; mtspr 8,0; blrl; 1:; addi 30,30,1; addi 31,31,4; cmplwi 30,1; ble 0b; 2:; li 3,1; b 4f; 3:; mr 3,31; mr 4,29; bl _s80110C80_3; 4:; lwz 0,0x1c(1); mtspr 8,0; lmw 29,0xc(1); addi 1,1,24"

extern "C" void _s80110C80_0();
extern "C" void _s80110C80_1();
extern "C" void _s80110C80_2();
extern "C" void _s80110C80_3();

struct ObjSelector {
    void GetBigThumbnail_ERShader();
};

void ObjSelector::GetBigThumbnail_ERShader() {
}
