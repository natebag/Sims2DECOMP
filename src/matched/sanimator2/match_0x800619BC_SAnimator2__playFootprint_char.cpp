// 0x800619BC SAnimator2::playFootprint(char (384 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-480(1); mfspr 0,8; stmw 28,0x1d0(1); stw 0,0x1e4(1); mr 31,3; mr 30,4; addi 4,1,8; bl _s800619BC_0; cmplwi 3,9; bgt 6f; lis 9,-32702; rlwinm 0,3,2,0,29; addi 9,9,15888; lis 4,-32707; lwzx 28,9,0; addi 4,4,18668; mr 3,30; bl _s800619BC_1; cmpwi 3,0; beq 0f; lis 4,-32707; mr 3,30; addi 4,4,18672; bl _s800619BC_2; cmpwi 3,0; bne 1f; 0:; lis 9,-32707; addi 30,9,18676; 1:; lwz 9,0x130(31); addi 0,9,-1; cmplwi 0,1; ble 2f; cmpwi 9,5; bne 3f; 2:; lis 9,-32707; addi 6,9,18684; b 5f; 3:; lwz 11,0x4(31); lis 9,-32707; addi 6,9,18692; cmpwi 11,0; beq 5f; lwz 9,0x0(11); lwz 11,0x0(9); lwz 9,0x14(11); cmpwi 9,0; beq 5f; lwz 9,0x63c(9); lwz 9,0xa8(9); cmpwi 9,0; beq 5f; lwz 9,0x110(9); lis 0,-31452; ori 0,0,31322; cmpw 9,0; beq 4f; lis 0,-6208; ori 0,0,34888; cmpw 9,0; beq 4f; lis 0,10189; ori 0,0,56719; cmpw 9,0; beq 4f; lis 0,-13981; ori 0,0,55067; cmpw 9,0; bne 5f; 4:; lis 9,-32707; addi 6,9,18700; 5:; addi 29,1,208; lis 4,-32707; addi 4,4,18708; mr 5,28; mr 7,30; mr 3,29; crxor 6,6,6; bl _s800619BC_3; lwz 11,0x4(31); lwz 30,-21492(13); lwz 10,0x0(11); lwz 9,0x4(10); lha 3,0x328(9); lwz 0,0x32c(9); add 3,10,3; mtspr 8,0; blrl; mr 5,3; mr 4,29; mr 3,30; bl _s800619BC_4; 6:; lwz 0,0x1e4(1); mtspr 8,0; lmw 28,0x1d0(1); addi 1,1,480"

extern "C" void _s800619BC_0();
extern "C" void _s800619BC_1();
extern "C" void _s800619BC_2();
extern "C" void _s800619BC_3();
extern "C" void _s800619BC_4();

struct SAnimator2 {
    void playFootprint();
};

void SAnimator2::playFootprint() {
}
