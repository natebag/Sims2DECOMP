// 0x80166BB0 CasScene::HandleEventChangeFocus(CasEventChangeFocus (740 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-16(1); mfspr 0,8; stw 31,0xc(1); stw 0,0x14(1); lwz 0,0xc(4); mr 31,3; cmpwi 0,41; bgt 3f; cmpwi 0,38; bge 10f; cmpwi 0,22; beq 18f; bgt 1f; cmpwi 0,17; bgt 0f; cmpwi 0,9; bge 9f; cmpwi 0,0; blt 18f; cmpwi 0,1; ble 18f; b 7f; 0:; cmpwi 0,20; ble 10f; b 9f; 1:; cmpwi 0,31; bgt 2f; cmpwi 0,27; bge 10f; cmpwi 0,25; beq 12f; bgt 18f; b 11f; 2:; cmpwi 0,32; beq 18f; b 9f; 3:; cmpwi 0,52; beq 17f; bgt 5f; cmpwi 0,47; beq 12f; bgt 4f; cmpwi 0,45; bgt 18f; cmpwi 0,43; bge 11f; b 18f; 4:; cmpwi 0,49; beq 18f; blt 13f; cmpwi 0,50; beq 11f; cmpwi 0,51; beq 14f; b 18f; 5:; cmpwi 0,64; bgt 6f; cmpwi 0,63; bge 11f; cmpwi 0,53; beq 9f; b 18f; 6:; cmpwi 0,66; beq 18f; blt 12f; cmpwi 0,70; bgt 18f; b 8f; 7:; lis 9,-32706; lis 11,-32706; lfs f1,-872(9); mr 3,31; lfs f2,-868(11); li 4,8; bl _s80166BB0_0; lis 3,-32696; addi 4,31,1472; addi 3,3,30832; bl _s80166BB0_1; li 0,2; lis 5,-32696; lis 6,-32696; lwz 3,0xac0(31); stw 0,0xb1c(31); addi 5,5,30652; b 16f; 8:; lis 9,-32706; lis 11,-32706; lfs f1,-872(9); mr 3,31; lfs f2,-868(11); li 4,9; bl _s80166BB0_2; lis 3,-32696; addi 4,31,864; addi 3,3,30832; bl _s80166BB0_3; li 0,1; lis 5,-32696; lis 6,-32696; lwz 3,0xac0(31); stw 0,0xb1c(31); addi 5,5,30736; b 16f; 9:; lis 9,-32706; lis 11,-32706; lfs f1,-872(9); mr 3,31; lfs f2,-868(11); li 4,1; b 15f; 10:; lis 9,-32706; lis 11,-32706; lfs f1,-872(9); mr 3,31; lfs f2,-868(11); li 4,4; b 15f; 11:; lis 9,-32706; lis 11,-32706; lfs f1,-872(9); mr 3,31; lfs f2,-868(11); li 4,2; b 15f; 12:; lis 9,-32706; lis 11,-32706; lfs f1,-872(9); mr 3,31; lfs f2,-868(11); li 4,3; b 15f; 13:; lis 9,-32706; lis 11,-32706; lfs f1,-872(9); mr 3,31; lfs f2,-868(11); li 4,5; b 15f; 14:; lis 9,-32706; lis 11,-32706; lfs f1,-872(9); mr 3,31; lfs f2,-868(11); li 4,6; 15:; bl _s80166BB0_4; lis 3,-32696; addi 4,31,256; addi 3,3,30832; bl _s80166BB0_5; li 0,0; lis 5,-32696; lis 6,-32696; lwz 3,0xac0(31); stw 0,0xb1c(31); addi 5,5,30640; 16:; addi 6,6,30772; li 4,0; bl _s80166BB0_6; b 18f; 17:; lis 9,-32706; lis 11,-32706; lfs f1,-872(9); mr 3,31; lfs f2,-868(11); li 4,7; bl _s80166BB0_7; lis 3,-32696; addi 4,31,256; addi 3,3,30832; bl _s80166BB0_8; li 0,0; lis 5,-32696; lis 6,-32696; lwz 3,0xac0(31); stw 0,0xb1c(31); addi 5,5,30640; addi 6,6,30772; li 4,0; bl _s80166BB0_9; 18:; lwz 0,0x14(1); mtspr 8,0; lwz 31,0xc(1); addi 1,1,16"

extern "C" void _s80166BB0_0();
extern "C" void _s80166BB0_1();
extern "C" void _s80166BB0_2();
extern "C" void _s80166BB0_3();
extern "C" void _s80166BB0_4();
extern "C" void _s80166BB0_5();
extern "C" void _s80166BB0_6();
extern "C" void _s80166BB0_7();
extern "C" void _s80166BB0_8();
extern "C" void _s80166BB0_9();

struct CasScene {
    void HandleEventChangeFocus_CasEventChangeFocus();
};

void CasScene::HandleEventChangeFocus_CasEventChangeFocus() {
}
