#include "types.h"
#include "stub_classes.h"
// Inline asm leaf matches for CasGenetics (stub_classes.h)
// 3 functions, 320 bytes

// 0x801617FC (68 bytes)
// CasGenetics::GetGrandparent(bool, unsigned int)
__attribute__((noreturn))
void CasGenetics::GetGrandparent(bool, unsigned int) {
    __asm__ __volatile__(
        "cmpwi	4,0\n"
        "li	9,0\n"
        "beq	.L_8016180C\n"
        "li	9,1\n"
        ".L_8016180C:\n"
        "slwi	9,9,4\n"
        "lwzx	11,9,3\n"
        "add	9,9,3\n"
        "lwz	0,4(9)\n"
        "subf	0,11,0\n"
        "srawi	0,0,2\n"
        "cmplw	5,0\n"
        "blt	.L_80161834\n"
        "li	3,0\n"
        "blr\n"
        ".L_80161834:\n"
        "slwi	9,5,2\n"
        "lwzx	3,11,9\n"
        "blr\n"
    );
}

// 0x80161840 (176 bytes)
// CasGenetics::UpdateGrandparentDescription(bool, unsigned int, CasSimDescriptionS2C &)
__attribute__((noreturn))
void CasGenetics::UpdateGrandparentDescription(bool, unsigned int, CasSimDescriptionS2C &) {
    __asm__ __volatile__(
        "cmplwi	5,25\n"
        "ble	.L_80161850\n"
        ".L_80161848:\n"
        "li	3,0\n"
        "blr\n"
        ".L_80161850:\n"
        "cmpwi	4,0\n"
        "li	9,0\n"
        "beq	.L_80161860\n"
        "li	9,1\n"
        ".L_80161860:\n"
        "slwi	9,9,4\n"
        "lwzx	11,9,3\n"
        "add	9,9,3\n"
        "lwz	0,4(9)\n"
        "subf	0,11,0\n"
        "srawi	0,0,2\n"
        "cmplw	5,0\n"
        "bge	.L_80161848\n"
        "slwi	9,5,2\n"
        "lwzx	5,11,9\n"
        "cmpwi	5,0\n"
        "beq	.L_80161848\n"
        "lwz	5,0(5)\n"
        "cmpwi	5,0\n"
        "beq	.L_80161848\n"
        "li	9,288\n"
        ".L_801618A0:\n"
        "lwz	0,0(6)\n"
        "addic.	9,9,-24\n"
        "stw	0,0(5)\n"
        "lwz	0,4(6)\n"
        "stw	0,4(5)\n"
        "lwz	0,8(6)\n"
        "stw	0,8(5)\n"
        "lwz	0,12(6)\n"
        "stw	0,12(5)\n"
        "lwz	0,16(6)\n"
        "stw	0,16(5)\n"
        "lwz	0,20(6)\n"
        "addi	6,6,24\n"
        "stw	0,20(5)\n"
        "addi	5,5,24\n"
        "bne	.L_801618A0\n"
        "lwz	0,0(6)\n"
        "li	3,1\n"
        "stw	0,0(5)\n"
        "blr\n"
    );
}

// 0x80161A20 (76 bytes)
// CasGenetics::FemaleFacialFeatureLocked(signed char)
__attribute__((noreturn))
void CasGenetics::FemaleFacialFeatureLocked(signed char) {
    __asm__ __volatile__(
        "addi	0,4,-6\n"
        "cmplwi	0,1\n"
        "ble	.L_80161A5C\n"
        "cmpwi	4,9\n"
        "beq	.L_80161A5C\n"
        "cmpwi	4,10\n"
        "beq	.L_80161A5C\n"
        "cmpwi	4,12\n"
        "beq	.L_80161A5C\n"
        "cmpwi	4,13\n"
        "beq	.L_80161A5C\n"
        "cmpwi	4,14\n"
        "beq	.L_80161A5C\n"
        "cmpwi	4,15\n"
        "bne	.L_80161A64\n"
        ".L_80161A5C:\n"
        "li	3,1\n"
        "blr\n"
        ".L_80161A64:\n"
        "li	3,0\n"
        "blr\n"
    );
}

