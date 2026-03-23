#include "types.h"
#include "stub_classes.h"
// Inline asm leaf matches (large 20-9999B) for static_init
// 19 functions, 2296 bytes

// 0x800372D8 (208 bytes)
// __static_initialization_and_destruction_0
__attribute__((noreturn))
void __static_initialization_and_destruction_0() {
    __asm__ __volatile__(
        "li	0,0\n"
        "ori	0,0,65535\n"
        "cmpw	4,0\n"
        "bnelr\n"
        "cmpwi	3,0\n"
        "beq	.L_8003737C\n"
        "lis	9,-32707\n"
        "lis	10,-32707\n"
        "lfs	11,5516(9)\n"
        "lis	11,-32697\n"
        "lfs	0,5520(10)\n"
        "addi	9,11,22048\n"
        "stfs	11,22048(11)\n"
        "lis	10,-32707\n"
        "stfs	0,4(9)\n"
        "lis	11,-32707\n"
        "stfs	0,8(9)\n"
        "stfs	0,12(9)\n"
        "stfsu	0,16(9)\n"
        "lfs	13,5528(11)\n"
        "lfs	12,5524(10)\n"
        "stfs	13,8(9)\n"
        "stfs	12,4(9)\n"
        "stfs	0,12(9)\n"
        "stfsu	0,16(9)\n"
        "stfs	11,4(9)\n"
        "stfs	13,8(9)\n"
        "stfs	0,12(9)\n"
        "stfsu	12,16(9)\n"
        "stfs	0,4(9)\n"
        "stfs	0,8(9)\n"
        "stfs	0,12(9)\n"
        "stfsu	0,16(9)\n"
        "stfs	13,8(9)\n"
        "stfs	0,4(9)\n"
        "stfs	0,12(9)\n"
        "stfsu	0,16(9)\n"
        "stfs	0,12(9)\n"
        "stfs	0,4(9)\n"
        "stfs	0,8(9)\n"
        "blr\n"
        ".L_8003737C:\n"
        "lis	9,-32697\n"
        "addi	9,9,22048\n"
        "cmpwi	9,0\n"
        "beqlr\n"
        "addi	11,9,96\n"
        "cmpw	11,9\n"
        "beqlr\n"
        ".L_80037398:\n"
        "addi	11,11,-16\n"
        "cmpw	11,9\n"
        "bne	.L_80037398\n"
        "blr\n"
    );
}

// 0x80039514 (92 bytes)
// __static_initialization_and_destruction_0
__attribute__((noreturn))
void __static_initialization_and_destruction_0() {
    __asm__ __volatile__(
        "li	0,0\n"
        "ori	0,0,65535\n"
        "cmpw	4,0\n"
        "bnelr\n"
        "cmpwi	3,0\n"
        "beqlr\n"
        "lis	11,-32697\n"
        "li	0,-1\n"
        "stw	0,23136(11)\n"
        "addi	8,11,23136\n"
        "li	10,0\n"
        "lis	9,-32697\n"
        "stw	10,4(8)\n"
        "addi	9,9,23172\n"
        "li	10,5\n"
        "li	11,-1\n"
        "mtctr	10\n"
        "li	0,0\n"
        ".L_8003955C:\n"
        "stw	11,0(9)\n"
        "stw	0,4(9)\n"
        "addi	9,9,36\n"
        "bdnz	.L_8003955C\n"
        "blr\n"
    );
}

// 0x80057738 (248 bytes)
// __static_initialization_and_destruction_0
__attribute__((noreturn))
void __static_initialization_and_destruction_0() {
    __asm__ __volatile__(
        "stwu	1,-32(1)\n"
        "stmw	26,8(1)\n"
        "li	0,0\n"
        "ori	0,0,65535\n"
        "cmpw	4,0\n"
        "bne	.L_80057824\n"
        "cmpwi	3,0\n"
        "beq	.L_80057824\n"
        "lis	9,-32707\n"
        "lis	5,-32707\n"
        "lfs	13,14664(9)\n"
        "lis	11,-32707\n"
        "lis	26,-32696\n"
        "lfs	12,14680(5)\n"
        "lfs	0,14652(11)\n"
        "lis	29,-32707\n"
        "lis	10,-32707\n"
        "lis	6,-32707\n"
        "lis	3,-32696\n"
        "addi	5,26,21860\n"
        "stfs	13,8(5)\n"
        "lis	8,-32707\n"
        "lfs	9,14660(10)\n"
        "lis	30,-32696\n"
        "lfs	10,14656(29)\n"
        "addi	11,3,21872\n"
        "lfs	11,14672(6)\n"
        "lis	29,-32696\n"
        "stfs	0,8(11)\n"
        "addi	10,30,21884\n"
        "lfs	8,14668(8)\n"
        "lis	4,-32696\n"
        "stfs	11,8(10)\n"
        "addi	8,29,21896\n"
        "stfs	12,8(8)\n"
        "lis	7,-32707\n"
        "stfs	0,21824(4)\n"
        "addi	9,4,21824\n"
        "stfs	10,4(9)\n"
        "lis	28,-32696\n"
        "stfs	0,8(9)\n"
        "lis	27,-32696\n"
        "lfs	7,14676(7)\n"
        "addi	6,27,21848\n"
        "stfs	0,21836(28)\n"
        "addi	7,28,21836\n"
        "stfs	0,8(7)\n"
        "stfs	0,21848(27)\n"
        "stfs	9,8(6)\n"
        "stfs	13,21860(26)\n"
        "stfs	0,21872(3)\n"
        "stfs	9,4(11)\n"
        "stfs	8,21884(30)\n"
        "stfs	8,4(10)\n"
        "stfs	7,21896(29)\n"
        "stfs	7,4(8)\n"
        "stfs	0,4(7)\n"
        "stfs	0,4(6)\n"
        "stfs	13,4(5)\n"
        ".L_80057824:\n"
        "lmw	26,8(1)\n"
        "addi	1,1,32\n"
        "blr\n"
    );
}

// 0x8006E708 (88 bytes)
// __static_initialization_and_destruction_0
__attribute__((noreturn))
void __static_initialization_and_destruction_0() {
    __asm__ __volatile__(
        "li	0,0\n"
        "ori	0,0,65535\n"
        "cmpw	4,0\n"
        "bnelr\n"
        "cmpwi	3,0\n"
        "beqlr\n"
        "lis	11,-32707\n"
        "lis	9,-32707\n"
        "lfs	13,20868(11)\n"
        "lis	10,-32707\n"
        "lfs	0,20864(9)\n"
        "addi	11,13,-24932\n"
        "stfs	13,4(11)\n"
        "addi	9,13,-24924\n"
        "stfs	0,4(9)\n"
        "addi	8,13,-24940\n"
        "lfs	12,20872(10)\n"
        "stfs	0,0(8)\n"
        "stfs	12,0(9)\n"
        "stfs	0,4(8)\n"
        "stfs	0,0(11)\n"
        "blr\n"
    );
}

// 0x8009591C (84 bytes)
// __static_initialization_and_destruction_0
__attribute__((noreturn))
void __static_initialization_and_destruction_0() {
    __asm__ __volatile__(
        "li	0,0\n"
        "ori	0,0,65535\n"
        "cmpw	4,0\n"
        "bnelr\n"
        "cmpwi	3,0\n"
        "beqlr\n"
        "lis	9,-32706\n"
        "lis	10,-32706\n"
        "lfs	12,-30740(9)\n"
        "lis	8,-32706\n"
        "lis	7,-32706\n"
        "lis	11,-32696\n"
        "lfs	11,-30736(10)\n"
        "addi	9,11,22820\n"
        "lfs	13,-30732(8)\n"
        "lfs	0,-30728(7)\n"
        "stfs	12,22820(11)\n"
        "stfs	0,12(9)\n"
        "stfs	11,4(9)\n"
        "stfs	13,8(9)\n"
        "blr\n"
    );
}

// 0x8016FB00 (84 bytes)
// __static_initialization_and_destruction_0
__attribute__((noreturn))
void __static_initialization_and_destruction_0() {
    __asm__ __volatile__(
        "li	0,0\n"
        "ori	0,0,65535\n"
        "cmpw	4,0\n"
        "bnelr\n"
        "cmpwi	3,0\n"
        "beqlr\n"
        "lis	9,-32706\n"
        "lis	11,-32706\n"
        "lfs	13,6016(9)\n"
        "lis	8,-32696\n"
        "lfs	0,6020(11)\n"
        "lis	9,-32696\n"
        "addi	11,8,30808\n"
        "addi	10,9,30820\n"
        "stfs	13,8(11)\n"
        "stfs	0,8(10)\n"
        "stfs	13,30808(8)\n"
        "stfs	0,30820(9)\n"
        "stfs	13,4(11)\n"
        "stfs	0,4(10)\n"
        "blr\n"
    );
}

// 0x801755C4 (164 bytes)
// __static_initialization_and_destruction_0
__attribute__((noreturn))
void __static_initialization_and_destruction_0() {
    __asm__ __volatile__(
        "li	0,0\n"
        "ori	0,0,65535\n"
        "cmpw	4,0\n"
        "bnelr\n"
        "cmpwi	3,0\n"
        "beqlr\n"
        "lis	9,-32706\n"
        "lis	11,-32706\n"
        "lfs	0,8452(9)\n"
        "lis	10,-32706\n"
        "lfs	10,8460(11)\n"
        "lis	9,-32696\n"
        "stfs	0,31108(9)\n"
        "lis	11,-32706\n"
        "lfs	13,8456(10)\n"
        "addi	9,9,31108\n"
        "lfs	12,8464(11)\n"
        "lis	10,-32706\n"
        "stfs	13,4(9)\n"
        "lis	11,-32706\n"
        "stfs	10,8(9)\n"
        "lis	6,-32706\n"
        "stfsu	12,12(9)\n"
        "lis	8,-32706\n"
        "lfs	0,8468(10)\n"
        "lis	7,-32706\n"
        "lfs	11,8472(11)\n"
        "lis	10,-32706\n"
        "stfs	0,4(9)\n"
        "stfs	10,8(9)\n"
        "stfsu	11,12(9)\n"
        "lfs	12,8480(8)\n"
        "lfs	0,8476(6)\n"
        "lfs	13,8484(10)\n"
        "stfs	0,4(9)\n"
        "stfs	12,8(9)\n"
        "stfsu	13,12(9)\n"
        "lfs	0,8488(7)\n"
        "stfs	12,8(9)\n"
        "stfs	0,4(9)\n"
        "blr\n"
    );
}

// 0x8017578C (132 bytes)
// __static_initialization_and_destruction_0
__attribute__((noreturn))
void __static_initialization_and_destruction_0() {
    __asm__ __volatile__(
        "li	0,0\n"
        "ori	0,0,65535\n"
        "cmpw	4,0\n"
        "bnelr\n"
        "cmpwi	3,0\n"
        "beqlr\n"
        "lis	9,-32706\n"
        "lis	11,-32706\n"
        "lfs	10,8580(9)\n"
        "lis	10,-32706\n"
        "lfs	9,8584(11)\n"
        "lis	9,-32696\n"
        "stfs	10,31156(9)\n"
        "lis	11,-32706\n"
        "lfs	11,8588(10)\n"
        "addi	9,9,31156\n"
        "lfs	12,8592(11)\n"
        "lis	10,-32706\n"
        "stfs	9,4(9)\n"
        "lis	11,-32706\n"
        "stfs	11,8(9)\n"
        "stfsu	12,12(9)\n"
        "lfs	0,8596(10)\n"
        "stfs	11,8(9)\n"
        "stfs	0,4(9)\n"
        "stfsu	12,12(9)\n"
        "lfs	13,8600(11)\n"
        "stfs	0,4(9)\n"
        "stfs	13,8(9)\n"
        "stfsu	10,12(9)\n"
        "stfs	13,8(9)\n"
        "stfs	9,4(9)\n"
        "blr\n"
    );
}

// 0x80175934 (132 bytes)
// __static_initialization_and_destruction_0
__attribute__((noreturn))
void __static_initialization_and_destruction_0() {
    __asm__ __volatile__(
        "li	0,0\n"
        "ori	0,0,65535\n"
        "cmpw	4,0\n"
        "bnelr\n"
        "cmpwi	3,0\n"
        "beqlr\n"
        "lis	9,-32706\n"
        "lis	11,-32706\n"
        "lfs	10,8692(9)\n"
        "lis	10,-32706\n"
        "lfs	9,8696(11)\n"
        "lis	9,-32696\n"
        "stfs	10,31204(9)\n"
        "lis	11,-32706\n"
        "lfs	11,8700(10)\n"
        "addi	9,9,31204\n"
        "lfs	12,8704(11)\n"
        "lis	10,-32706\n"
        "stfs	9,4(9)\n"
        "lis	11,-32706\n"
        "stfs	11,8(9)\n"
        "stfsu	12,12(9)\n"
        "lfs	0,8708(10)\n"
        "stfs	11,8(9)\n"
        "stfs	0,4(9)\n"
        "stfsu	12,12(9)\n"
        "lfs	13,8712(11)\n"
        "stfs	0,4(9)\n"
        "stfs	13,8(9)\n"
        "stfsu	10,12(9)\n"
        "stfs	13,8(9)\n"
        "stfs	9,4(9)\n"
        "blr\n"
    );
}

// 0x801A07A4 (84 bytes)
// __static_initialization_and_destruction_0
__attribute__((noreturn))
void __static_initialization_and_destruction_0() {
    __asm__ __volatile__(
        "li	0,0\n"
        "ori	0,0,65535\n"
        "cmpw	4,0\n"
        "bnelr\n"
        "cmpwi	3,0\n"
        "beqlr\n"
        "lis	9,-32705\n"
        "lis	11,-32705\n"
        "lfs	0,-11360(9)\n"
        "lis	8,-32696\n"
        "lfs	13,-11356(11)\n"
        "addi	9,8,32192\n"
        "lis	10,-32696\n"
        "stfs	13,8(9)\n"
        "addi	11,10,32180\n"
        "stfs	0,32180(10)\n"
        "stfs	13,8(11)\n"
        "stfs	0,32192(8)\n"
        "stfs	0,4(9)\n"
        "stfs	0,4(11)\n"
        "blr\n"
    );
}

// 0x802060C8 (80 bytes)
// __static_initialization_and_destruction_0
__attribute__((noreturn))
void __static_initialization_and_destruction_0() {
    __asm__ __volatile__(
        "li	0,0\n"
        "ori	0,0,65535\n"
        "cmpw	4,0\n"
        "bnelr\n"
        "cmpwi	3,0\n"
        "beqlr\n"
        "lis	9,-32704\n"
        "lis	11,-32704\n"
        "lfs	12,-13468(11)\n"
        "lis	10,-32704\n"
        "lfs	13,-13472(9)\n"
        "lfs	0,-13464(10)\n"
        "lis	9,-32696\n"
        "fmuls	13,13,12\n"
        "addi	11,9,32224\n"
        "stfs	0,32224(9)\n"
        "stfs	13,-23848(13)\n"
        "stfs	0,4(11)\n"
        "stfs	0,8(11)\n"
        "blr\n"
    );
}

// 0x80218E84 (140 bytes)
// __static_initialization_and_destruction_0
__attribute__((noreturn))
void __static_initialization_and_destruction_0() {
    __asm__ __volatile__(
        "li	0,0\n"
        "ori	0,0,65535\n"
        "cmpw	4,0\n"
        "bnelr\n"
        "cmpwi	3,0\n"
        "beqlr\n"
        "lis	9,-32704\n"
        "lis	11,-32704\n"
        "lfs	0,-10340(9)\n"
        "lis	8,-32704\n"
        "lfs	13,-10336(11)\n"
        "lis	9,-32696\n"
        "stfs	0,32284(9)\n"
        "lis	10,-32704\n"
        "lfs	12,-10332(8)\n"
        "addi	7,9,32284\n"
        "stfs	13,8(7)\n"
        "lis	11,-32696\n"
        "lfs	11,-10328(10)\n"
        "addi	6,11,32296\n"
        "stfs	12,32296(11)\n"
        "lis	5,-32696\n"
        "stfs	11,8(6)\n"
        "addi	10,5,32260\n"
        "stfs	0,32260(5)\n"
        "lis	4,-32696\n"
        "stfs	0,8(10)\n"
        "addi	8,4,32272\n"
        "stfs	13,32272(4)\n"
        "stfs	13,8(8)\n"
        "stfs	0,4(10)\n"
        "stfs	0,4(8)\n"
        "stfs	13,4(7)\n"
        "stfs	11,4(6)\n"
        "blr\n"
    );
}

// 0x802D5C50 (104 bytes)
// __static_initialization_and_destruction_0
__attribute__((noreturn))
void __static_initialization_and_destruction_0() {
    __asm__ __volatile__(
        "li	0,0\n"
        "ori	0,0,65535\n"
        "cmpw	4,0\n"
        "bnelr\n"
        "cmpwi	3,0\n"
        "beqlr\n"
        "lis	11,-32702\n"
        "lis	9,-32702\n"
        "lfs	13,-6804(11)\n"
        "lis	10,-32694\n"
        "lfs	0,-6800(9)\n"
        "lis	11,-32694\n"
        "addi	9,11,7432\n"
        "addi	7,10,7408\n"
        "stfs	13,8(9)\n"
        "lis	8,-32694\n"
        "stfs	13,7408(10)\n"
        "addi	6,8,7420\n"
        "stfs	0,8(7)\n"
        "stfs	0,7420(8)\n"
        "stfs	0,8(6)\n"
        "stfs	0,7432(11)\n"
        "stfs	0,4(9)\n"
        "stfs	0,4(7)\n"
        "stfs	13,4(6)\n"
        "blr\n"
    );
}

// 0x802F0D1C (84 bytes)
// __static_initialization_and_destruction_0
__attribute__((noreturn))
void __static_initialization_and_destruction_0() {
    __asm__ __volatile__(
        "li	0,0\n"
        "ori	0,0,65535\n"
        "cmpw	4,0\n"
        "bnelr\n"
        "cmpwi	3,0\n"
        "beqlr\n"
        "lis	9,-32702\n"
        "lis	11,-32702\n"
        "lfs	0,-4276(9)\n"
        "lfs	13,-4272(11)\n"
        "li	9,2\n"
        "fmuls	0,0,13\n"
        "stfs	0,-22724(13)\n"
        ".L_802F0D50:\n"
        "addi	0,9,-1\n"
        "li	9,64\n"
        "mtctr	9\n"
        ".L_802F0D5C:\n"
        "bdnz	.L_802F0D5C\n"
        "mr	9,0\n"
        "cmpwi	9,-1\n"
        "bne	.L_802F0D50\n"
        "blr\n"
    );
}

// 0x802F9A10 (112 bytes)
// __static_initialization_and_destruction_0
__attribute__((noreturn))
void __static_initialization_and_destruction_0() {
    __asm__ __volatile__(
        "li	0,0\n"
        "ori	0,0,65535\n"
        "cmpw	4,0\n"
        "bnelr\n"
        "cmpwi	3,0\n"
        "beqlr\n"
        "lis	11,-32702\n"
        "lis	10,-32693\n"
        "lfs	0,-3204(11)\n"
        "addi	9,10,2208\n"
        "addi	8,9,12\n"
        "li	0,0\n"
        "stfs	0,40(9)\n"
        "addi	11,9,40\n"
        "stfs	0,2208(10)\n"
        "stfs	0,4(8)\n"
        "stw	0,36(9)\n"
        "stfs	0,4(11)\n"
        "stfs	0,8(9)\n"
        "stfs	0,4(9)\n"
        "stfs	0,8(8)\n"
        "stfs	0,12(9)\n"
        "stfs	0,24(9)\n"
        "stfs	0,28(9)\n"
        "stfs	0,32(9)\n"
        "stfs	0,12(11)\n"
        "stfs	0,8(11)\n"
        "blr\n"
    );
}

// 0x803007D8 (84 bytes)
// __static_initialization_and_destruction_0
__attribute__((noreturn))
void __static_initialization_and_destruction_0() {
    __asm__ __volatile__(
        "li	0,0\n"
        "ori	0,0,65535\n"
        "cmpw	4,0\n"
        "bnelr\n"
        "cmpwi	3,0\n"
        "beqlr\n"
        "lis	9,-32702\n"
        "lis	11,-32702\n"
        "lfs	13,-2192(9)\n"
        "lis	8,-32693\n"
        "lfs	0,-2188(11)\n"
        "lis	9,-32693\n"
        "addi	11,8,2292\n"
        "addi	10,9,2304\n"
        "stfs	13,8(11)\n"
        "stfs	0,8(10)\n"
        "stfs	13,2292(8)\n"
        "stfs	0,2304(9)\n"
        "stfs	13,4(11)\n"
        "stfs	0,4(10)\n"
        "blr\n"
    );
}

// 0x80323A4C (112 bytes)
// __static_initialization_and_destruction_0
__attribute__((noreturn))
void __static_initialization_and_destruction_0() {
    __asm__ __volatile__(
        "li	0,0\n"
        "ori	0,0,65535\n"
        "cmpw	4,0\n"
        "bnelr\n"
        "cmpwi	3,0\n"
        "beq	.L_80323A90\n"
        "li	0,4\n"
        "lis	9,-32702\n"
        "mtctr	0\n"
        "lis	11,-32693\n"
        "lfs	0,3184(9)\n"
        "addi	11,11,24504\n"
        ".L_80323A7C:\n"
        "stfs	0,0(11)\n"
        "stfs	0,4(11)\n"
        "addi	11,11,8\n"
        "bdnz	.L_80323A7C\n"
        "blr\n"
        ".L_80323A90:\n"
        "lis	9,-32693\n"
        "addi	9,9,24504\n"
        "cmpwi	9,0\n"
        "beqlr\n"
        "addi	11,9,32\n"
        "cmpw	11,9\n"
        "beqlr\n"
        ".L_80323AAC:\n"
        "addi	11,11,-8\n"
        "cmpw	11,9\n"
        "bne	.L_80323AAC\n"
        "blr\n"
    );
}

// 0x80356584 (84 bytes)
// __static_initialization_and_destruction_0
__attribute__((noreturn))
void __static_initialization_and_destruction_0() {
    __asm__ __volatile__(
        "li	0,0\n"
        "ori	0,0,65535\n"
        "cmpw	4,0\n"
        "bnelr\n"
        "cmpwi	3,0\n"
        "beqlr\n"
        "li	0,256\n"
        "mtctr	0\n"
        ".L_803565A4:\n"
        "bdnz	.L_803565A4\n"
        "li	0,256\n"
        "mtctr	0\n"
        ".L_803565B0:\n"
        "bdnz	.L_803565B0\n"
        "lis	11,-32702\n"
        "lis	10,-32690\n"
        "lfs	0,10804(11)\n"
        "addi	9,10,-7088\n"
        "stfs	0,-7088(10)\n"
        "stfs	0,4(9)\n"
        "stfs	0,12(9)\n"
        "stfs	0,8(9)\n"
        "blr\n"
    );
}

// 0x80362008 (180 bytes)
// __static_initialization_and_destruction_0
__attribute__((noreturn))
void __static_initialization_and_destruction_0() {
    __asm__ __volatile__(
        "stwu	1,-16(1)\n"
        "stmw	30,8(1)\n"
        "li	0,0\n"
        "ori	0,0,65535\n"
        "cmpw	4,0\n"
        "bne	.L_803620B0\n"
        "cmpwi	3,0\n"
        "beq	.L_803620B0\n"
        "lis	11,-32702\n"
        "lis	9,-32702\n"
        "lfs	13,11976(11)\n"
        "lis	30,-32690\n"
        "lfs	0,11972(9)\n"
        "addi	7,30,-7008\n"
        "stfs	13,12(7)\n"
        "lis	6,-32690\n"
        "stfs	0,-7072(6)\n"
        "addi	9,6,-7072\n"
        "stfs	0,12(9)\n"
        "lis	5,-32690\n"
        "stfs	13,-7056(5)\n"
        "addi	11,5,-7056\n"
        "stfs	0,12(11)\n"
        "lis	4,-32690\n"
        "stfs	0,-7040(4)\n"
        "addi	10,4,-7040\n"
        "stfs	0,12(10)\n"
        "lis	3,-32690\n"
        "stfs	0,-7024(3)\n"
        "addi	8,3,-7024\n"
        "stfs	0,12(8)\n"
        "stfs	0,-7008(30)\n"
        "stfs	0,8(7)\n"
        "stfs	0,4(9)\n"
        "stfs	0,8(9)\n"
        "stfs	0,4(11)\n"
        "stfs	0,8(11)\n"
        "stfs	13,4(10)\n"
        "stfs	0,8(10)\n"
        "stfs	0,4(8)\n"
        "stfs	13,8(8)\n"
        "stfs	0,4(7)\n"
        ".L_803620B0:\n"
        "lmw	30,8(1)\n"
        "addi	1,1,16\n"
        "blr\n"
    );
}

