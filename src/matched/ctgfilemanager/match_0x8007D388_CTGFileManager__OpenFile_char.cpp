// 0x8007D388 CTGFileManager::OpenFile(char (252 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-296(1); mfspr 0,8; stmw 28,0x118(1); stw 0,0x12c(1); addi 30,1,8; mr 31,4; mr 29,5; addi 4,30,8; li 5,260; mr 3,30; bl _s8007D388_0; mr 28,30; mr 3,30; mr 4,31; li 5,-1; bl _s8007D388_1; cmpwi 29,0; beq 0f; lis 9,-32707; addi 4,9,26708; b 1f; 0:; lis 9,-32707; addi 4,9,26712; 1:; mr 3,31; bl _s8007D388_2; mr. 29,3; li 3,0; beq 2f; lis 4,-32707; addi 3,13,-24588; addi 4,4,26716; bl _s8007D388_3; lis 4,-32707; addi 4,4,26792; bl _s8007D388_4; li 4,324; bl _s8007D388_5; lis 4,-32707; addi 4,4,26796; bl _s8007D388_6; mr 4,31; bl _s8007D388_7; lis 4,-32707; addi 4,4,26808; bl _s8007D388_8; li 3,276; bl _s8007D388_9; li 6,0; li 7,0; li 4,0; li 5,0; bl _s8007D388_10; mr 30,3; mr 4,28; stw 29,0x110(30); addi 3,30,4; bl _s8007D388_11; mr 3,30; 2:; lwz 0,0x12c(1); mtspr 8,0; lmw 28,0x118(1); addi 1,1,296"

extern "C" void _s8007D388_0();
extern "C" void _s8007D388_1();
extern "C" void _s8007D388_2();
extern "C" void _s8007D388_3();
extern "C" void _s8007D388_4();
extern "C" void _s8007D388_5();
extern "C" void _s8007D388_6();
extern "C" void _s8007D388_7();
extern "C" void _s8007D388_8();
extern "C" void _s8007D388_9();
extern "C" void _s8007D388_10();
extern "C" void _s8007D388_11();

struct CTGFileManager {
    void OpenFile();
};

void CTGFileManager::OpenFile() {
}
