// 0x8010502C cXObjectImpl::RewriteDialogParamIndices(DialogParam (304 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-16(1); mfspr 0,8; stmw 30,0x8(1); stw 0,0x14(1); mr 31,4; mr 30,3; lbz 0,0x2(31); cmpwi 0,255; bne 0f; lwz 11,0x4(30); li 4,0; lwz 9,0x4(11); lha 3,0x270(9); lwz 0,0x274(9); add 3,11,3; mtspr 8,0; blrl; addi 3,3,1; stb 3,0x2(31); 0:; lbz 0,0x3(31); cmpwi 0,255; bne 1f; lwz 11,0x4(30); li 4,2; lwz 9,0x4(11); lha 3,0x270(9); lwz 0,0x274(9); add 3,11,3; mtspr 8,0; blrl; addi 3,3,1; stb 3,0x3(31); 1:; lbz 0,0x4(31); cmpwi 0,255; bne 2f; lwz 11,0x4(30); li 4,3; lwz 9,0x4(11); lha 3,0x270(9); lwz 0,0x274(9); add 3,11,3; mtspr 8,0; blrl; addi 3,3,1; stb 3,0x4(31); 2:; lbz 0,0x6(31); cmpwi 0,255; bne 3f; lwz 11,0x4(30); li 4,1; lwz 9,0x4(11); lha 3,0x270(9); lwz 0,0x274(9); add 3,11,3; mtspr 8,0; blrl; addi 3,3,1; stb 3,0x6(31); 3:; lbz 0,0x0(31); cmpwi 0,255; bne 4f; lwz 11,0x4(30); li 4,4; lwz 9,0x4(11); lha 3,0x270(9); lwz 0,0x274(9); add 3,11,3; mtspr 8,0; blrl; addi 3,3,1; stb 3,0x0(31); 4:; lwz 0,0x14(1); mtspr 8,0; lmw 30,0x8(1); addi 1,1,16"

struct cXObjectImpl {
    void RewriteDialogParamIndices_DialogParam();
};

void cXObjectImpl::RewriteDialogParamIndices_DialogParam() {
}
