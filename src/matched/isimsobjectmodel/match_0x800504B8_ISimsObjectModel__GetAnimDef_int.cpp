// 0x800504B8 ISimsObjectModel::GetAnimDef(int, (376 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-40(1); mfspr 0,8; stmw 25,0xc(1); stw 0,0x2c(1); mr 27,3; mr 25,4; lwz 11,0x328(27); lwz 9,0x4(11); lwz 0,0x314(9); lha 3,0x310(9); mtspr 8,0; add 3,11,3; blrl; lwz 0,0xc0(3); cmpwi 0,0; beq 2f; lwz 11,0x328(27); lwz 9,0x4(11); lwz 0,0x314(9); lha 3,0x310(9); mtspr 8,0; add 3,11,3; blrl; lwz 9,0xc0(3); li 0,0; lwz 9,0x0(9); cmpwi 9,0; beq 0f; lwz 0,-4(9); 0:; mr 28,0; b 3f; 1:; mr 29,31; li 26,1; b 5f; 2:; li 28,0; 3:; lwz 11,0x328(27); mr 29,25; lwz 9,0x4(11); lwz 0,0x314(9); lha 3,0x310(9); mtspr 8,0; add 3,11,3; blrl; lwz 9,0xc0(3); lwz 11,0x0(9); lwz 0,0x18(11); cmpwi 0,-1; beq 6f; li 26,0; li 31,0; cmpw 26,28; bge 5f; li 30,0; 4:; lwz 11,0x328(27); lwz 9,0x4(11); lwz 0,0x314(9); lha 3,0x310(9); mtspr 8,0; add 3,11,3; blrl; lwz 11,0xc0(3); lwz 9,0x0(11); add 9,9,30; lwz 0,0x18(9); cmpw 0,25; beq 1b; addi 31,31,1; addi 30,30,32; cmpw 31,28; blt 4b; 5:; cmpwi 26,0; bne 6f; li 29,0; 6:; cmpwi 29,0; blt 7f; cmpw 29,28; blt 8f; 7:; li 29,0; 8:; lwz 11,0x328(27); lwz 9,0x4(11); lwz 0,0x314(9); lha 3,0x310(9); mtspr 8,0; add 3,11,3; blrl; lwz 9,0xc0(3); rlwinm 0,29,5,0,26; lwz 3,0x0(9); add 3,3,0; lwz 0,0x2c(1); mtspr 8,0; lmw 25,0xc(1); addi 1,1,40"

struct ISimsObjectModel {
    void GetAnimDef();
};

void ISimsObjectModel::GetAnimDef() {
}
