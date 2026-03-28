#include "types.h"
#include "stub_classes.h"
// Inline asm leaf matches for PRGTarget (stub_classes.h)
// 9 functions, 976 bytes

// 0x801D9398 (112 bytes)
// PRGTarget::GetUnlockedFashions(void)
__attribute__((noreturn))
void PRGTarget::GetUnlockedFashions(void) {
    __asm__ __volatile__(
        "stwu	1,-8(1)\n"
        "mflr	0\n"
        "stw	0,12(1)\n"
        "lwz	11,-21476(13)\n"
        "li	4,1\n"
        "lwz	9,0(11)\n"
        "lwz	0,292(9)\n"
        "lha	3,288(9)\n"
        "mtlr	0\n"
        "add	3,11,3\n"
        "blrl\n"
        "lwz	9,0(3)\n"
        "lha	0,328(9)\n"
        "lwz	9,332(9)\n"
        "add	3,3,0\n"
        "mtlr	9\n"
        "blrl\n"
        "lwz	9,0(3)\n"
        "li	4,1\n"
        "lha	0,32(9)\n"
        "lwz	9,36(9)\n"
        "add	3,3,0\n"
        "mtlr	9\n"
        "blrl\n"
        "lwz	0,12(1)\n"
        "mtlr	0\n"
        "addi	1,1,8\n"
        "blr\n"
    );
}

// 0x801D9408 (112 bytes)
// PRGTarget::GetUnlockedRecipies(void)
__attribute__((noreturn))
void PRGTarget::GetUnlockedRecipies(void) {
    __asm__ __volatile__(
        "stwu	1,-8(1)\n"
        "mflr	0\n"
        "stw	0,12(1)\n"
        "lwz	11,-21476(13)\n"
        "li	4,1\n"
        "lwz	9,0(11)\n"
        "lwz	0,292(9)\n"
        "lha	3,288(9)\n"
        "mtlr	0\n"
        "add	3,11,3\n"
        "blrl\n"
        "lwz	9,0(3)\n"
        "lha	0,328(9)\n"
        "lwz	9,332(9)\n"
        "add	3,3,0\n"
        "mtlr	9\n"
        "blrl\n"
        "lwz	9,0(3)\n"
        "li	4,0\n"
        "lha	0,32(9)\n"
        "lwz	9,36(9)\n"
        "add	3,3,0\n"
        "mtlr	9\n"
        "blrl\n"
        "lwz	0,12(1)\n"
        "mtlr	0\n"
        "addi	1,1,8\n"
        "blr\n"
    );
}

// 0x801D9478 (112 bytes)
// PRGTarget::GetUnlockedObjects(void)
__attribute__((noreturn))
void PRGTarget::GetUnlockedObjects(void) {
    __asm__ __volatile__(
        "stwu	1,-8(1)\n"
        "mflr	0\n"
        "stw	0,12(1)\n"
        "lwz	11,-21476(13)\n"
        "li	4,1\n"
        "lwz	9,0(11)\n"
        "lwz	0,292(9)\n"
        "lha	3,288(9)\n"
        "mtlr	0\n"
        "add	3,11,3\n"
        "blrl\n"
        "lwz	9,0(3)\n"
        "lha	0,328(9)\n"
        "lwz	9,332(9)\n"
        "add	3,3,0\n"
        "mtlr	9\n"
        "blrl\n"
        "lwz	9,0(3)\n"
        "li	4,5\n"
        "lha	0,32(9)\n"
        "lwz	9,36(9)\n"
        "add	3,3,0\n"
        "mtlr	9\n"
        "blrl\n"
        "lwz	0,12(1)\n"
        "mtlr	0\n"
        "addi	1,1,8\n"
        "blr\n"
    );
}

// 0x801D94E8 (144 bytes)
// PRGTarget::GetTotalPromotions(void)
__attribute__((noreturn))
void PRGTarget::GetTotalPromotions(void) {
    __asm__ __volatile__(
        "stwu	1,-24(1)\n"
        "mflr	0\n"
        "stmw	29,12(1)\n"
        "stw	0,28(1)\n"
        "lwz	11,-21476(13)\n"
        "lis	9,-32697\n"
        "lwz	4,23644(9)\n"
        "li	29,0\n"
        "lwz	9,0(11)\n"
        "li	30,0\n"
        "lha	3,288(9)\n"
        "lwz	0,292(9)\n"
        "add	3,11,3\n"
        "mtlr	0\n"
        "blrl\n"
        "mr	31,3\n"
        ".L_801D9528:\n"
        "lwz	9,0(31)\n"
        "addi	4,30,11\n"
        "lha	3,336(9)\n"
        "lwz	0,340(9)\n"
        "add	3,31,3\n"
        "mtlr	0\n"
        "blrl\n"
        "add	29,29,3\n"
        "cmpwi	29,90\n"
        "ble	.L_801D9554\n"
        "li	29,90\n"
        ".L_801D9554:\n"
        "addi	30,30,1\n"
        "cmpwi	30,9\n"
        "ble	.L_801D9528\n"
        "mr	3,29\n"
        "lwz	0,28(1)\n"
        "mtlr	0\n"
        "lmw	29,12(1)\n"
        "addi	1,1,24\n"
        "blr\n"
    );
}

// 0x801D9578 (140 bytes)
// PRGTarget::GetMaxedCareers(void)
__attribute__((noreturn))
void PRGTarget::GetMaxedCareers(void) {
    __asm__ __volatile__(
        "stwu	1,-24(1)\n"
        "mflr	0\n"
        "stmw	29,12(1)\n"
        "stw	0,28(1)\n"
        "lwz	11,-21476(13)\n"
        "lis	9,-32697\n"
        "lwz	4,23644(9)\n"
        "li	29,0\n"
        "lwz	9,0(11)\n"
        "li	30,0\n"
        "lha	3,288(9)\n"
        "lwz	0,292(9)\n"
        "add	3,11,3\n"
        "mtlr	0\n"
        "blrl\n"
        "mr	31,3\n"
        ".L_801D95B8:\n"
        "lwz	9,0(31)\n"
        "addi	4,30,11\n"
        "lha	3,336(9)\n"
        "lwz	0,340(9)\n"
        "add	3,31,3\n"
        "mtlr	0\n"
        "blrl\n"
        "cmpwi	3,9\n"
        "bne	.L_801D95E0\n"
        "addi	29,29,1\n"
        ".L_801D95E0:\n"
        "addi	30,30,1\n"
        "cmpwi	30,9\n"
        "ble	.L_801D95B8\n"
        "mr	3,29\n"
        "lwz	0,28(1)\n"
        "mtlr	0\n"
        "lmw	29,12(1)\n"
        "addi	1,1,24\n"
        "blr\n"
    );
}

// 0x801D9944 (92 bytes)
// PRGTarget::GetNPCsHelped(void)
__attribute__((noreturn))
void PRGTarget::GetNPCsHelped(void) {
    __asm__ __volatile__(
        "stwu	1,-8(1)\n"
        "mflr	0\n"
        "stw	0,12(1)\n"
        "lwz	10,-21476(13)\n"
        "lis	9,-32697\n"
        "lwz	4,23644(9)\n"
        "lwz	11,0(10)\n"
        "lwz	0,292(11)\n"
        "lha	3,288(11)\n"
        "mtlr	0\n"
        "add	3,10,3\n"
        "blrl\n"
        "lwz	9,0(3)\n"
        "li	4,10\n"
        "lha	0,336(9)\n"
        "lwz	9,340(9)\n"
        "add	3,3,0\n"
        "mtlr	9\n"
        "blrl\n"
        "lwz	0,12(1)\n"
        "mtlr	0\n"
        "addi	1,1,8\n"
        "blr\n"
    );
}

// 0x801D99A0 (112 bytes)
// PRGTarget::GetUnlockedLots(void)
__attribute__((noreturn))
void PRGTarget::GetUnlockedLots(void) {
    __asm__ __volatile__(
        "stwu	1,-8(1)\n"
        "mflr	0\n"
        "stw	0,12(1)\n"
        "lwz	11,-21476(13)\n"
        "li	4,1\n"
        "lwz	9,0(11)\n"
        "lwz	0,292(9)\n"
        "lha	3,288(9)\n"
        "mtlr	0\n"
        "add	3,11,3\n"
        "blrl\n"
        "lwz	9,0(3)\n"
        "lha	0,328(9)\n"
        "lwz	9,332(9)\n"
        "add	3,3,0\n"
        "mtlr	9\n"
        "blrl\n"
        "lwz	9,0(3)\n"
        "li	4,2\n"
        "lha	0,32(9)\n"
        "lwz	9,36(9)\n"
        "add	3,3,0\n"
        "mtlr	9\n"
        "blrl\n"
        "lwz	0,12(1)\n"
        "mtlr	0\n"
        "addi	1,1,8\n"
        "blr\n"
    );
}

// 0x801DA5D4 (76 bytes)
// PRGTarget::OnCancelKeyPressed(char *, char *)
__attribute__((noreturn))
void PRGTarget::OnCancelKeyPressed(char *, char *) {
    __asm__ __volatile__(
        "stwu	1,-8(1)\n"
        "mflr	0\n"
        "stw	0,12(1)\n"
        "lis	9,-32697\n"
        "lis	4,-32705\n"
        "lwz	11,24312(9)\n"
        "lis	5,-32705\n"
        "addi	4,4,-5352\n"
        "addi	5,5,-5340\n"
        "lwz	9,128(11)\n"
        "lha	3,16(9)\n"
        "lwz	0,20(9)\n"
        "add	3,11,3\n"
        "mtlr	0\n"
        "blrl\n"
        "lwz	0,12(1)\n"
        "mtlr	0\n"
        "addi	1,1,8\n"
        "blr\n"
    );
}

// 0x801DA624 (76 bytes)
// PRGTarget::Shutdown(void)
__attribute__((noreturn))
void PRGTarget::Shutdown(void) {
    __asm__ __volatile__(
        "stwu	1,-8(1)\n"
        "mflr	0\n"
        "stw	0,12(1)\n"
        "lis	9,-32697\n"
        "lis	4,-32705\n"
        "lwz	11,24312(9)\n"
        "lis	5,-32705\n"
        "addi	4,4,-5352\n"
        "addi	5,5,-5340\n"
        "lwz	9,128(11)\n"
        "lha	3,16(9)\n"
        "lwz	0,20(9)\n"
        "add	3,11,3\n"
        "mtlr	0\n"
        "blrl\n"
        "lwz	0,12(1)\n"
        "mtlr	0\n"
        "addi	1,1,8\n"
        "blr\n"
    );
}

