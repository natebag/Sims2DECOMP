#include "types.h"
#include "stub_classes.h"
// Inline asm leaf matches for EString (stub_classes.h)
// 1 functions, 124 bytes

// 0x802D3EFC (124 bytes)
// EString::CharsEqualNoCase(char, char)
__attribute__((noreturn))
void EString::CharsEqualNoCase(char, char) {
    __asm__ __volatile__(
        "mr	9,3\n"
        "cmpw	9,4\n"
        "bne	.L_802D3F10\n"
        "li	3,1\n"
        "blr\n"
        ".L_802D3F10:\n"
        "addi	0,9,-97\n"
        "cmplwi	0,25\n"
        "bgt	.L_802D3F40\n"
        "cmpwi	4,64\n"
        "ble	.L_802D3F40\n"
        "cmpwi	4,90\n"
        "bgt	.L_802D3F40\n"
        "addi	3,9,-32\n"
        "xor	3,3,4\n"
        "subfic	0,3,0\n"
        "adde	3,0,3\n"
        "blr\n"
        ".L_802D3F40:\n"
        "addi	0,4,-97\n"
        "cmplwi	0,25\n"
        "bgt	.L_802D3F70\n"
        "cmpwi	9,64\n"
        "ble	.L_802D3F70\n"
        "cmpwi	9,90\n"
        "bgt	.L_802D3F70\n"
        "addi	3,4,-32\n"
        "xor	3,3,9\n"
        "subfic	0,3,0\n"
        "adde	3,0,3\n"
        "blr\n"
        ".L_802D3F70:\n"
        "li	3,0\n"
        "blr\n"
    );
}

