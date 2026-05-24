// 0x80031360 ESim::ReadModelFromCache(void) (492 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-24(1); mfspr 0,8; stmw 30,0x10(1); stw 0,0x1c(1); lis 9,-32697; mr 31,3; addi 0,9,21760; lwz 11,0x5500(9); stw 0,0x8(1); li 4,-1; lwz 9,0x14(11); lha 3,0x10(11); mtspr 8,9; add 3,3,0; blrl; lwz 11,0x3d0(31); lwz 9,0x4(11); lwz 0,0x1b4(9); lha 3,0x1b0(9); mtspr 8,0; add 3,11,3; blrl; mr 30,3; li 0,0; lis 3,-32697; stw 0,0x644(31); addi 3,3,23428; addi 3,3,244; bl _s80031360_0; mr. 3,3; beq 0f; lha 0,0x4(3); cmpw 0,30; bne 0f; li 0,1; stw 0,0x644(31); 0:; lis 3,-32697; addi 3,3,23428; addi 3,3,260; bl _s80031360_1; mr. 3,3; beq 1f; lha 0,0x4(3); cmpw 0,30; bne 1f; li 0,2; stw 0,0x644(31); 1:; lwz 11,0x3d0(31); cmpwi 11,0; beq 6f; lwz 9,0x4(11); li 4,8; lha 3,0x138(9); lwz 0,0x13c(9); add 3,11,3; mtspr 8,0; blrl; cmpwi 3,0; bne 6f; lwz 0,0x644(31); mr 9,0; cmpwi 0,1; bne 3f; lwz 0,-32632(13); cmpwi 0,0; beq 3f; lwz 3,0x63c(31); cmpwi 7,3,0; beq cr7,2f; cmpw 3,0; beq 2f; beq cr7,2f; li 4,3; bl _s80031360_2; 2:; lwz 30,-32632(13); b 5f; 3:; cmpwi 9,2; bne 6f; lwz 0,-32628(13); cmpwi 0,0; beq 6f; lwz 3,0x63c(31); cmpwi 7,3,0; beq cr7,4f; cmpw 3,0; beq 4f; beq cr7,4f; li 4,3; bl _s80031360_3; 4:; lwz 30,-32628(13); 5:; lwz 11,0x3d0(31); stw 30,0x63c(31); lwz 9,0x4(11); lwz 0,0x154(9); lha 3,0x150(9); mtspr 8,0; add 3,11,3; blrl; mr 4,3; mr 3,30; bl _s80031360_4; lwz 11,0x8(1); lwz 9,0x0(11); lha 3,0x18(9); lwz 0,0x1c(9); add 3,11,3; mtspr 8,0; blrl; li 3,1; b 7f; 6:; lwz 3,0x8(1); lwz 9,0x0(3); lha 0,0x18(9); lwz 9,0x1c(9); add 3,3,0; mtspr 8,9; blrl; li 3,0; 7:; lwz 0,0x1c(1); mtspr 8,0; lmw 30,0x10(1); addi 1,1,24"

extern "C" void _s80031360_0();
extern "C" void _s80031360_1();
extern "C" void _s80031360_2();
extern "C" void _s80031360_3();
extern "C" void _s80031360_4();

struct ESim {
    void ReadModelFromCache();
};

void ESim::ReadModelFromCache() {
}
