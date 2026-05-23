// 0x8005D394 SAnimator2::resolveSkillForPrimitive(StackElem (616 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-32(1); mfspr 0,8; stmw 27,0xc(1); stw 0,0x24(1); mr 27,6; li 11,0; stw 11,0x0(27); mr 28,5; mr 29,3; mr 31,4; lbz 0,0x5(28); lha 30,0x0(28); andi. 9,0,4; beq 2f; cmpwi 30,0; blt 0f; lbz 0,0x7(31); cmpw 30,0; blt 1f; 0:; lwz 9,0x4(29); li 0,1; li 4,8; lwz 11,0x0(9); stw 0,-24512(13); lwz 10,0x0(11); lwz 9,0x18(10); lwz 0,0x2c(9); lha 3,0x28(9); mtspr 8,0; add 3,10,3; blrl; lwz 11,0x4(29); li 4,8; lwz 10,0x0(11); lwz 9,0x4(10); lha 3,0x110(9); lwz 0,0x114(9); add 3,10,3; mtspr 8,0; blrl; b 13f; 1:; mr 3,31; bl _s8005D394_0; lwz 9,0x4(29); add 0,30,30; lhax 30,3,0; lwz 11,0x0(9); lha 4,0x4(31); lwz 9,0x4(11); lha 3,0x488(9); lwz 0,0x48c(9); add 3,11,3; mtspr 8,0; blrl; b 3f; 2:; lwz 3,0x4(29); lwz 9,0x4(3); lha 0,0x2e8(9); lwz 9,0x2ec(9); add 3,3,0; mtspr 8,9; blrl; 3:; mr 11,3; lbz 0,0x4(28); extsb 0,0; cmpwi 0,1; beq 11f; bgt 4f; cmpwi 0,0; beq 5f; b 15f; 4:; cmpwi 0,2; beq 10f; cmpwi 0,3; beq 14f; b 15f; 5:; cmpwi 11,0; bne 6f; lwz 9,0x4(29); li 0,1; li 4,23; lwz 11,0x0(9); stw 0,-24512(13); lwz 10,0x0(11); lwz 9,0x18(10); lwz 0,0x2c(9); lha 3,0x28(9); mtspr 8,0; add 3,10,3; blrl; lwz 11,0x4(29); li 4,23; lwz 10,0x0(11); lwz 9,0x4(10); lha 3,0x110(9); lwz 0,0x114(9); add 3,10,3; mtspr 8,0; blrl; b 13f; 6:; lbz 9,0x3(28); li 6,0; cmpwi 9,0; beq 7f; addi 6,9,3; b 9f; 7:; lbz 5,0x5(28); andi. 0,5,1; beq 8f; li 6,1; 8:; andi. 9,5,16; beq 9f; ori 6,6,2; 9:; lwz 4,0x4(29); mr 3,11; mr 5,30; mr 7,27; subfic 0,6,0; adde 6,0,6; bl _s8005D394_1; b 12f; 10:; lwz 3,0x4(29); mr 4,30; mr 5,27; bl _s8005D394_2; b 12f; 11:; lwz 3,0x4(29); mr 4,30; mr 5,27; bl _s8005D394_3; 12:; cmpwi 3,-1; bne 15f; cmpwi 4,-1; bne 15f; 13:; li 3,-1; li 4,-1; b 16f; 14:; lwz 3,0x4(29); mr 4,30; mr 5,27; bl _s8005D394_4; cmpwi 3,-1; bne 15f; cmpwi 4,-1; li 3,-1; li 4,-1; beq 16f; 15:; li 3,0; li 4,1; 16:; lwz 0,0x24(1); mtspr 8,0; lmw 27,0xc(1); addi 1,1,32"

extern "C" void _s8005D394_0();
extern "C" void _s8005D394_1();
extern "C" void _s8005D394_2();
extern "C" void _s8005D394_3();
extern "C" void _s8005D394_4();

struct SAnimator2 {
    void resolveSkillForPrimitive();
};

void SAnimator2::resolveSkillForPrimitive() {
}
