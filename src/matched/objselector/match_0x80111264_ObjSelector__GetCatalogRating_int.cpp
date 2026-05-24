// 0x80111264 ObjSelector::GetCatalogRating(int) (328 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="cmpwi 4,6; beq 9f; bgt 1f; cmpwi 4,2; beq 5f; bgt 0f; cmpwi 4,0; beq 3f; cmpwi 4,1; beq 4f; b 17f; 0:; cmpwi 4,4; beq 7f; bgt 8f; b 6f; 1:; cmpwi 4,10; beq 13f; bgt 2f; cmpwi 4,8; beq 11f; bgt 12f; b 10f; 2:; cmpwi 4,12; beq 15f; blt 14f; cmpwi 4,13; beq 16f; b 17f; 3:; lwz 9,0x38(3); lha 3,0xa4(9); blr; 4:; lwz 9,0x38(3); lha 3,0xa6(9); blr; 5:; lwz 9,0x38(3); lha 3,0xa8(9); blr; 6:; lwz 9,0x38(3); lha 3,0xaa(9); blr; 7:; lwz 9,0x38(3); lha 3,0xac(9); blr; 8:; lwz 9,0x38(3); lha 3,0xae(9); blr; 9:; lwz 9,0x38(3); lha 3,0xb0(9); blr; 10:; lwz 9,0x38(3); li 3,0; lhz 0,0xb2(9); andi. 9,0,1; beqlr; li 3,1; blr; 11:; lwz 9,0x38(3); lhz 3,0xb2(9); rlwinm 3,3,31,31,31; blr; 12:; lwz 9,0x38(3); lhz 3,0xb2(9); rlwinm 3,3,30,31,31; blr; 13:; lwz 9,0x38(3); lhz 3,0xb2(9); rlwinm 3,3,29,31,31; blr; 14:; lwz 9,0x38(3); lhz 3,0xb2(9); rlwinm 3,3,28,31,31; blr; 15:; lwz 9,0x38(3); lhz 3,0xb2(9); rlwinm 3,3,27,31,31; blr; 16:; lwz 9,0x38(3); lhz 3,0xb2(9); rlwinm 3,3,26,31,31; blr; 17:; li 3,0"

struct ObjSelector {
    void GetCatalogRating();
};

void ObjSelector::GetCatalogRating() {
}
