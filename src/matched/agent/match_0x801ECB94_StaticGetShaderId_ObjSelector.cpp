// 0x801ECB94 StaticGetShaderId(ObjSelector (196 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-24(1); mfspr 0,8; stmw 29,0xc(1); stw 0,0x1c(1); mr. 3,3; bne 0f; lis 3,-10852; ori 3,3,31669; b 6f; 0:; bl _s801ECB94_0; li 30,0; lwz 31,0x50(3); li 29,0; b 2f; 1:; lwz 9,0x0(31); mr 4,3; mr 5,29; lha 3,0xa8(9); addi 29,29,1; lwz 0,0xac(9); add 3,31,3; mtspr 8,0; blrl; 2:; mr. 3,3; beq 3f; lwz 9,0x38(3); lwz 9,0xc0(9); cmpwi 9,0; beq 1b; lwz 30,0x1c(9); 3:; cmpwi 30,0; bne 4f; lis 30,-10852; ori 30,30,31669; 4:; lwz 0,-26656(13); cmpwi 0,0; beq 5f; lis 0,-23895; ori 0,0,64461; cmpw 30,0; bne 5f; lis 30,-9097; ori 30,30,37043; 5:; mr 3,30; 6:; lwz 0,0x1c(1); mtspr 8,0; lmw 29,0xc(1); addi 1,1,24"
extern "C" void _s801ECB94_0();
extern "C" void f_801ECB94() {}
