// 0x8024041C DSIExcHandler (180B)
// ASMPROC_inject_before: before="blr" replace="bl f_802404D0" lines="mfdsisr 5; rlwinm. 5,5,10,31,31; beq 1f; stw 0,0(4); stw 1,4(4); stw 2,8(4); stmw 6,24(4); mfspr 0,913; stw 0,424(4); mfspr 0,914; stw 0,428(4); mfspr 0,915; stw 0,432(4); mfspr 0,916; stw 0,436(4); mfspr 0,917; stw 0,440(4); mfspr 0,918; stw 0,444(4); mfspr 0,919; stw 0,448(4); mfdsisr 5; mfdar 6; b f_802404D0; 1:; lwz 3,128(4); mtcrf 0xff,3; lwz 3,132(4); mtlr 3; lwz 3,136(4); mtctr 3; lwz 3,140(4); mtxer 3; lwz 3,408(4); mtspr 26,3; lwz 3,412(4); mtspr 27,3; lwz 3,12(4); lwz 5,20(4); lwz 4,16(4); b f_8023E3E8; li 3,0; li 4,0; li 5,0; li 6,0"
extern "C" void f_802404D0();
extern "C" void f_8023E3E8();
extern "C" void f_8024041C() {}
