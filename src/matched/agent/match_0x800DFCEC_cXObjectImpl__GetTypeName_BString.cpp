// 0x800DFCEC cXObjectImpl::GetTypeName(BString (252 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-8(1); mfspr 0,8; stw 0,0xc(1); lwz 9,0x88(3); mr 3,4; lha 0,0x12(9); cmpwi 0,4; beq 6f; bgt 0f; cmpwi 0,1; beq 3f; ble 2f; cmpwi 0,2; beq 4f; cmpwi 0,3; beq 5f; b 2f; 0:; cmpwi 0,7; beq 9f; bgt 1f; cmpwi 0,5; beq 7f; cmpwi 0,6; beq 8f; b 2f; 1:; cmpwi 0,8; beq 10f; cmpwi 0,9; beq 11f; 2:; lis 9,-32706; addi 4,9,-20892; b 12f; 3:; lis 9,-32706; addi 4,9,-20884; b 12f; 4:; lis 9,-32706; addi 4,9,-20876; b 12f; 5:; lis 9,-32706; addi 4,9,-20868; b 12f; 6:; lis 9,-32706; addi 4,9,-20856; b 12f; 7:; lis 9,-32706; addi 4,9,-20844; b 12f; 8:; lis 9,-32706; addi 4,9,-20832; b 12f; 9:; lis 9,-32706; addi 4,9,-20824; b 12f; 10:; lis 9,-32706; addi 4,9,-20812; b 12f; 11:; lis 9,-32706; addi 4,9,-20804; 12:; bl _s800DFCEC_0; lwz 0,0xc(1); mtspr 8,0; addi 1,1,8"
extern "C" void _s800DFCEC_0();
extern "C" void f_800DFCEC() {}
