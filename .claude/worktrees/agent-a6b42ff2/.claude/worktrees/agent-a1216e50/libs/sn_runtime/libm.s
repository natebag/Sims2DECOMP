# =============================================================================
# libm.s - SN Systems libm math functions
# Source: libm.a from SN Systems ProDG for GameCube
# All libm text functions from the DVD map, written as PPC assembly.
# =============================================================================

    .section .text
    .balign 4

# ---------------------------------------------------------------------------
# acosf @ 0x8024089c, size=0x24c (588 bytes)
# ---------------------------------------------------------------------------
    .global acosf
acosf:
    stwu    r1,-40(r1)
    mflr    r0
    stfd    f29,16(r1)
    stfd    f30,24(r1)
    stfd    f31,32(r1)
    stw     r0,44(r1)
    fmr     f6,f1
    fmr     f0,f6
    stfs    f0,8(r1)
    lwz     r9,8(r1)
    clrlwi  r11,r9,1
    lis     r0,16256
    cmpw    r11,r0
    bne    .L_acosf_004c
    cmpwi   r9,0
    lfs     f1,-28368(r13)
    bgt    .L_acosf_0230
    lfs     f1,-28364(r13)
    b    .L_acosf_0230
.L_acosf_004c:
    ble    .L_acosf_005c
    fsubs   f1,f6,f6
    fdivs   f1,f1,f1
    b    .L_acosf_0230
.L_acosf_005c:
    lis     r0,16127
    ori     r0,r0,65535
    cmpw    r11,r0
    bgt    .L_acosf_00f8
    lis     r0,8960
    cmpw    r11,r0
    bgt    .L_acosf_0080
    lfs     f1,-28360(r13)
    b    .L_acosf_0230
.L_acosf_0080:
    lfs     f0,-28352(r13)
    fmuls   f30,f6,f6
    lfs     f13,-28356(r13)
    lfs     f12,-28348(r13)
    fmadds  f13,f30,f13,f0
    lfs     f11,-28344(r13)
    fmadds  f13,f30,f13,f12
    lfs     f10,-28328(r13)
    lfs     f12,-28340(r13)
    fmadds  f13,f30,f13,f11
    lfs     f0,-28332(r13)
    lfs     f9,-28324(r13)
    fmadds  f13,f30,f13,f12
    fmadds  f0,f30,f0,f10
    lfs     f11,-28320(r13)
    lfs     f8,-28336(r13)
    fmadds  f0,f30,f0,f9
    lfs     f12,-28316(r13)
    fmadds  f0,f30,f0,f11
    fmadds  f13,f30,f13,f8
    lfs     f1,-28312(r13)
    fmadds  f29,f30,f0,f12
    lfs     f11,-28308(r13)
    fmuls   f31,f30,f13
    fdivs   f10,f31,f29
    fmuls   f0,f6,f10
    fsubs   f1,f1,f0
    fsubs   f1,f6,f1
    fsubs   f1,f11,f1
    b    .L_acosf_0230
.L_acosf_00f8:
    cmpwi   r9,0
    blt    .L_acosf_01a8
    lfs     f31,-28316(r13)
    lfs     f13,-28304(r13)
    fsubs   f0,f31,f6
    fmuls   f30,f0,f13
    fmr     f1,f30
    bl    sqrtf
    fmr     f6,f1
    lfs     f0,-28352(r13)
    fmr     f12,f6
    lfs     f13,-28356(r13)
    stfs    f12,8(r1)
    lfs     f11,-28348(r13)
    fmadds  f13,f30,f13,f0
    lwz     r0,8(r1)
    lfs     f0,-28332(r13)
    fmadds  f13,f30,f13,f11
    clrrwi  r9,r0,12
    lfs     f9,-28328(r13)
    lfs     f12,-28344(r13)
    stw     r9,8(r1)
    fmadds  f0,f30,f0,f9
    lfs     f7,-28324(r13)
    fmadds  f13,f30,f13,f12
    lfs     f8,-28340(r13)
    lfs     f11,-28320(r13)
    fmadds  f0,f30,f0,f7
    lfs     f1,8(r1)
    fmadds  f13,f30,f13,f8
    lfs     f10,-28336(r13)
    fmadds  f0,f30,f0,f11
    fmadds  f29,f30,f0,f31
    fmuls   f12,f1,f1
    fmadds  f13,f30,f13,f10
    fadds   f0,f6,f1
    fsubs   f12,f30,f12
    fmuls   f31,f30,f13
    fdivs   f12,f12,f0
    fdivs   f10,f31,f29
    fmadds  f0,f10,f6,f12
    fadds   f1,f1,f0
    fadds   f1,f1,f1
    b    .L_acosf_0230
.L_acosf_01a8:
    lfs     f7,-28316(r13)
    lfs     f12,-28304(r13)
    fadds   f0,f6,f7
    lfs     f11,-28352(r13)
    lfs     f13,-28356(r13)
    fmuls   f30,f0,f12
    lfs     f10,-28348(r13)
    fmr     f1,f30
    fmadds  f13,f30,f13,f11
    lfs     f12,-28344(r13)
    fmadds  f13,f30,f13,f10
    lfs     f0,-28332(r13)
    lfs     f11,-28328(r13)
    fmadds  f13,f30,f13,f12
    lfs     f10,-28340(r13)
    lfs     f8,-28324(r13)
    fmadds  f0,f30,f0,f11
    lfs     f9,-28336(r13)
    fmadds  f13,f30,f13,f10
    lfs     f12,-28320(r13)
    fmadds  f0,f30,f0,f8
    fmadds  f13,f30,f13,f9
    fmadds  f0,f30,f0,f12
    fmadds  f29,f30,f0,f7
    fmuls   f31,f30,f13
    bl    sqrtf
    fdivs   f10,f31,f29
    lfs     f0,-28312(r13)
    lfs     f13,-28300(r13)
    fmr     f6,f1
    fmsubs  f0,f10,f6,f0
    fadds   f1,f6,f0
    fadds   f1,f1,f1
    fsubs   f1,f13,f1
.L_acosf_0230:
    lwz     r0,44(r1)
    mtlr    r0
    lfd     f29,16(r1)
    lfd     f30,24(r1)
    lfd     f31,32(r1)
    addi    r1,r1,40
    blr

# ---------------------------------------------------------------------------
# atan2f @ 0x80240ae8, size=0x220 (544 bytes)
# ---------------------------------------------------------------------------
    .global atan2f
atan2f:
    stwu    r1,-24(r1)
    mflr    r0
    stw     r31,20(r1)
    stw     r0,28(r1)
    fmr     f0,f2
    stfs    f0,8(r1)
    lwz     r7,8(r1)
    clrlwi  r10,r7,1
    fmr     f0,f1
    stfs    f0,8(r1)
    lwz     r8,8(r1)
    clrlwi  r11,r8,1
    lis     r0,32640
    cmpw    r10,r0
    bgt    .L_atan2f_0044
    cmpw    r11,r0
    ble    .L_atan2f_004c
.L_atan2f_0044:
    fadds   f1,f2,f1
    b    .L_atan2f_020c
.L_atan2f_004c:
    lis     r0,16256
    cmpw    r7,r0
    bne    .L_atan2f_0060
    bl    atanf
    b    .L_atan2f_020c
.L_atan2f_0060:
    srwi    r9,r8,31
    rlwinm  r0,r7,2,30,30
    or      r31,r9,r0
    cmpwi   r11,0
    bne    .L_atan2f_0094
    cmpwi   r31,2
    beq    .L_atan2f_014c
    ble    .L_atan2f_008c
    cmpwi   r31,3
    beq    .L_atan2f_0154
    b    .L_atan2f_0094
.L_atan2f_008c:
    cmpwi   r31,0
    bge    .L_atan2f_020c
.L_atan2f_0094:
    cmpwi   r10,0
    bne    .L_atan2f_00b0
.L_atan2f_009c:
    cmpwi   r8,0
    lfs     f1,-28284(r13)
    bge    .L_atan2f_020c
    lfs     f1,-28288(r13)
    b    .L_atan2f_020c
.L_atan2f_00b0:
    lis     r0,32640
    cmpw    r10,r0
    bne    .L_atan2f_015c
    cmpw    r11,r10
    bne    .L_atan2f_0110
    cmpwi   r31,1
    beq    .L_atan2f_00f8
    bgt    .L_atan2f_00dc
    cmpwi   r31,0
    beq    .L_atan2f_00f0
    b    .L_atan2f_015c
.L_atan2f_00dc:
    cmpwi   r31,2
    beq    .L_atan2f_0100
    cmpwi   r31,3
    beq    .L_atan2f_0108
    b    .L_atan2f_015c
.L_atan2f_00f0:
    lfs     f1,-28280(r13)
    b    .L_atan2f_020c
.L_atan2f_00f8:
    lfs     f1,-28276(r13)
    b    .L_atan2f_020c
.L_atan2f_0100:
    lfs     f1,-28272(r13)
    b    .L_atan2f_020c
.L_atan2f_0108:
    lfs     f1,-28268(r13)
    b    .L_atan2f_020c
.L_atan2f_0110:
    cmpwi   r31,1
    beq    .L_atan2f_0144
    bgt    .L_atan2f_0128
    cmpwi   r31,0
    beq    .L_atan2f_013c
    b    .L_atan2f_015c
.L_atan2f_0128:
    cmpwi   r31,2
    beq    .L_atan2f_014c
    cmpwi   r31,3
    beq    .L_atan2f_0154
    b    .L_atan2f_015c
.L_atan2f_013c:
    lfs     f1,-28264(r13)
    b    .L_atan2f_020c
.L_atan2f_0144:
    lfs     f1,-28260(r13)
    b    .L_atan2f_020c
.L_atan2f_014c:
    lfs     f1,-28296(r13)
    b    .L_atan2f_020c
.L_atan2f_0154:
    lfs     f1,-28292(r13)
    b    .L_atan2f_020c
.L_atan2f_015c:
    lis     r0,32640
    cmpw    r11,r0
    beq    .L_atan2f_009c
    subf    r0,r10,r11
    srawi   r0,r0,23
    cmpwi   r0,60
    ble    .L_atan2f_0180
    lfs     f13,-28256(r13)
    b    .L_atan2f_01a8
.L_atan2f_0180:
    cmpwi   r7,0
    bge    .L_atan2f_0198
    cmpwi   r0,-60
    bge    .L_atan2f_0198
    lfs     f13,-28264(r13)
    b    .L_atan2f_01a8
.L_atan2f_0198:
    fdivs   f1,f1,f2
    bl    fabsf
    bl    atanf
    fmr     f13,f1
.L_atan2f_01a8:
    cmpwi   r31,1
    beq    .L_atan2f_01cc
    bgt    .L_atan2f_01c0
    cmpwi   r31,0
    beq    .L_atan2f_01e0
    b    .L_atan2f_01fc
.L_atan2f_01c0:
    cmpwi   r31,2
    beq    .L_atan2f_01e8
    b    .L_atan2f_01fc
.L_atan2f_01cc:
    stfs    f13,8(r1)
    lwz     r0,8(r1)
    xoris   r0,r0,32768
    stw     r0,8(r1)
    lfs     f13,8(r1)
.L_atan2f_01e0:
    fmr     f1,f13
    b    .L_atan2f_020c
.L_atan2f_01e8:
    lfs     f1,-28252(r13)
    lfs     f0,-28296(r13)
    fsubs   f1,f13,f1
    fsubs   f1,f0,f1
    b    .L_atan2f_020c
.L_atan2f_01fc:
    lfs     f1,-28252(r13)
    lfs     f0,-28296(r13)
    fsubs   f1,f13,f1
    fsubs   f1,f1,f0
.L_atan2f_020c:
    lwz     r0,28(r1)
    mtlr    r0
    lwz     r31,20(r1)
    addi    r1,r1,24
    blr

# ---------------------------------------------------------------------------
# fmodf @ 0x80240d08, size=0x1c8 (456 bytes)
# ---------------------------------------------------------------------------
    .global fmodf
fmodf:
    stwu    r1,-16(r1)
    stfs    f1,8(r1)
    lwz     r11,8(r1)
    mr      r0,r11
    fmr     f0,f2
    stfs    f0,8(r1)
    lwz     r9,8(r1)
    clrrwi  r6,r0,31
    clrlwi  r10,r0,1
    clrlwi. r8,r9,1
    beq    .L_fmodf_0048
    lis     r0,32639
    ori     r0,r0,65535
    cmpw    r10,r0
    bgt    .L_fmodf_0048
    lis     r0,32640
    cmpw    r8,r0
    ble    .L_fmodf_005c
.L_fmodf_0048:
    stw     r11,8(r1)
    lfs     f0,8(r1)
    fmuls   f1,f0,f2
    fdivs   f1,f1,f1
    b    .L_fmodf_01c0
.L_fmodf_005c:
    cmpw    r10,r8
    blt    .L_fmodf_01b4
    beq    .L_fmodf_0194
    lis     r0,127
    ori     r0,r0,65535
    cmpw    r10,r0
    bgt    .L_fmodf_0094
    li      r7,-126
    slwi.   r0,r10,8
    ble    .L_fmodf_009c
.L_fmodf_0084:
    addi    r7,r7,-1
    slwi.   r0,r0,1
    bgt    .L_fmodf_0084
    b    .L_fmodf_009c
.L_fmodf_0094:
    srawi   r9,r10,23
    addi    r7,r9,-127
.L_fmodf_009c:
    lis     r0,127
    ori     r0,r0,65535
    cmpw    r8,r0
    bgt    .L_fmodf_00cc
    li      r9,-126
    cmpwi   cr7,r7,-126
    slwi.   r0,r8,8
    blt    .L_fmodf_00d8
.L_fmodf_00bc:
    addi    r9,r9,-1
    slwi.   r0,r0,1
    bge    .L_fmodf_00bc
    b    .L_fmodf_00d8
.L_fmodf_00cc:
    srawi   r9,r8,23
    cmpwi   cr7,r7,-126
    addi    r9,r9,-127
.L_fmodf_00d8:
    blt    cr7,.L_fmodf_00e8
    clrlwi  r0,r10,9
    oris    r10,r0,128
    b    .L_fmodf_00f0
.L_fmodf_00e8:
    subfic  r11,r7,-126
    slw     r10,r10,r11
.L_fmodf_00f0:
    cmpwi   r9,-126
    blt    .L_fmodf_0104
    clrlwi  r0,r8,9
    oris    r8,r0,128
    b    .L_fmodf_010c
.L_fmodf_0104:
    subfic  r11,r9,-126
    slw     r8,r8,r11
.L_fmodf_010c:
    subf    r11,r9,r7
    b    .L_fmodf_012c
.L_fmodf_0114:
    subf.   r0,r8,r10
    bge    .L_fmodf_0124
    add     r10,r10,r10
    b    .L_fmodf_012c
.L_fmodf_0124:
    beq    .L_fmodf_0194
    add     r10,r0,r0
.L_fmodf_012c:
    mr      r0,r11
    cmpwi   r0,0
    addi    r11,r11,-1
    bne    .L_fmodf_0114
    subf.   r0,r8,r10
    blt    .L_fmodf_0148
    mr      r10,r0
.L_fmodf_0148:
    cmpwi   r10,0
    beq    .L_fmodf_0194
    lis     r0,127
    ori     r0,r0,65535
    cmpw    r10,r0
    bgt    .L_fmodf_0178
    lis     r0,127
    ori     r0,r0,65535
.L_fmodf_0168:
    add     r10,r10,r10
    addi    r9,r9,-1
    cmpw    r10,r0
    ble    .L_fmodf_0168
.L_fmodf_0178:
    cmpwi   r9,-126
    blt    .L_fmodf_01a8
    addi    r0,r9,127
    addis   r9,r10,-128
    slwi    r0,r0,23
    or      r10,r9,r0
    b    .L_fmodf_01b0
.L_fmodf_0194:
    srwi    r0,r6,31
    addi    r9,r13,-20988
    slwi    r0,r0,2
    lfsx    f1,r9,r0
    b    .L_fmodf_01c0
.L_fmodf_01a8:
    subfic  r11,r9,-126
    sraw    r10,r10,r11
.L_fmodf_01b0:
    or      r11,r10,r6
.L_fmodf_01b4:
    stw     r11,8(r1)
    lfs     f0,8(r1)
    fmr     f1,f0
.L_fmodf_01c0:
    addi    r1,r1,16
    blr

# ---------------------------------------------------------------------------
# sqrtf @ 0x80240ed0, size=0xf8 (248 bytes)
# ---------------------------------------------------------------------------
    .global sqrtf
sqrtf:
    stwu    r1,-16(r1)
    fmr     f0,f1
    stfs    f0,8(r1)
    lwz     r10,8(r1)
    mr      r11,r10
    rlwinm  r9,r11,0,1,8
    lis     r0,32640
    cmpw    r9,r0
    bne    .L_sqrtf_002c
    fmadds  f1,f1,f1,f1
    b    .L_sqrtf_00f0
.L_sqrtf_002c:
    cmpwi   cr7,r11,0
    bgt    cr7,.L_sqrtf_004c
    clrlwi. r0,r11,1
    beq    .L_sqrtf_00f0
    bge    cr7,.L_sqrtf_004c
    fsubs   f1,f1,f1
    fdivs   f1,f1,f1
    b    .L_sqrtf_00f0
.L_sqrtf_004c:
    srawi.  r9,r10,23
    bne    .L_sqrtf_0074
    li      r9,0
    andis.  r0,r11,128
    bne    .L_sqrtf_0070
.L_sqrtf_0060:
    slwi    r11,r11,1
    addi    r9,r9,1
    andis.  r0,r11,128
    beq    .L_sqrtf_0060
.L_sqrtf_0070:
    subfic  r9,r9,1
.L_sqrtf_0074:
    clrlwi  r0,r11,9
    addi    r9,r9,-127
    oris    r11,r0,128
    andi.   r0,r9,1
    beq    .L_sqrtf_008c
    add     r11,r11,r11
.L_sqrtf_008c:
    srawi   r9,r9,1
    add     r11,r11,r11
    li      r7,0
    li      r8,0
    lis     r10,256
.L_sqrtf_00a0:
    add     r0,r7,r10
    cmpw    r0,r11
    bgt    .L_sqrtf_00b8
    subf    r11,r0,r11
    add     r7,r0,r10
    add     r8,r8,r10
.L_sqrtf_00b8:
    add     r11,r11,r11
    srwi.   r10,r10,1
    bne    .L_sqrtf_00a0
    cmpwi   r11,0
    beq    .L_sqrtf_00d4
    clrlwi  r0,r8,31
    add     r8,r8,r0
.L_sqrtf_00d4:
    srawi   r11,r8,1
    slwi    r9,r9,23
    addis   r11,r11,16128
    add     r0,r11,r9
    stw     r0,8(r1)
    lfs     f0,8(r1)
    fmr     f1,f0
.L_sqrtf_00f0:
    addi    r1,r1,16
    blr

# ---------------------------------------------------------------------------
# atanf @ 0x80240fc8, size=0x210 (528 bytes)
# ---------------------------------------------------------------------------
    .global atanf
atanf:
    stwu    r1,-24(r1)
    mflr    r0
    stmw    r30,16(r1)
    stw     r0,28(r1)
    fmr     f5,f1
    fmr     f0,f5
    stfs    f0,8(r1)
    lwz     r30,8(r1)
    clrlwi  r31,r30,1
    lis     r0,20607
    ori     r0,r0,65535
    cmpw    r31,r0
    ble    .L_atanf_0074
    lis     r0,32640
    cmpw    r31,r0
    ble    .L_atanf_0048
    fadds   f1,f5,f5
    b    .L_atanf_01fc
.L_atanf_0048:
    cmpwi   r30,0
    ble    .L_atanf_0060
    lfs     f0,-20960(r13)
    lfs     f1,-20944(r13)
    fadds   f1,f0,f1
    b    .L_atanf_01fc
.L_atanf_0060:
    lfs     f1,-20960(r13)
    lfs     f0,-20944(r13)
    fneg    f1,f1
    fsubs   f1,f1,f0
    b    .L_atanf_01fc
.L_atanf_0074:
    lis     r0,16095
    ori     r0,r0,65535
    cmpw    r31,r0
    bgt    .L_atanf_00b8
    lis     r0,12543
    ori     r0,r0,65535
    cmpw    r31,r0
    bgt    .L_atanf_00b0
    lfs     f0,-28248(r13)
    lfs     f13,-28244(r13)
    fadds   f0,f5,f0
    fcmpu   cr0,f0,f13
    ble    .L_atanf_00b0
    fmr     f1,f5
    b    .L_atanf_01fc
.L_atanf_00b0:
    li      r0,-1
    b    .L_atanf_0154
.L_atanf_00b8:
    fmr     f1,f5
    bl    fabsf
    lis     r0,16279
    fmr     f5,f1
    ori     r0,r0,65535
    cmpw    r31,r0
    bgt    .L_atanf_011c
    lis     r0,16175
    ori     r0,r0,65535
    cmpw    r31,r0
    bgt    .L_atanf_0104
    lfs     f12,-28244(r13)
    fadds   f13,f5,f5
    lfs     f0,-28240(r13)
    li      r0,0
    fsubs   f13,f13,f12
    fadds   f0,f5,f0
    fdivs   f5,f13,f0
    b    .L_atanf_0154
.L_atanf_0104:
    lfs     f0,-28244(r13)
    li      r0,1
    fadds   f13,f5,f0
    fsubs   f0,f5,f0
    fdivs   f5,f0,f13
    b    .L_atanf_0154
.L_atanf_011c:
    lis     r0,16411
    ori     r0,r0,65535
    cmpw    r31,r0
    bgt    .L_atanf_0148
    lfs     f0,-28236(r13)
    li      r0,2
    lfs     f13,-28244(r13)
    fsubs   f12,f5,f0
    fmadds  f0,f5,f0,f13
    fdivs   f5,f12,f0
    b    .L_atanf_0154
.L_atanf_0148:
    lfs     f0,-28232(r13)
    li      r0,3
    fdivs   f5,f0,f5
.L_atanf_0154:
    fmuls   f6,f5,f5
    lfs     f10,-20908(r13)
    lfs     f13,-20900(r13)
    fmuls   f12,f6,f6
    lfs     f9,-20916(r13)
    cmpwi   r0,0
    fmadds  f13,f12,f13,f10
    lfs     f11,-20912(r13)
    fmadds  f13,f12,f13,f9
    lfs     f10,-20924(r13)
    lfs     f0,-20904(r13)
    lfs     f9,-20920(r13)
    fmadds  f13,f12,f13,f10
    fmadds  f0,f12,f0,f11
    lfs     f8,-20932(r13)
    lfs     f7,-20928(r13)
    fmadds  f0,f12,f0,f9
    lfs     f10,-20940(r13)
    fmadds  f13,f12,f13,f8
    lfs     f11,-20936(r13)
    fmadds  f0,f12,f0,f7
    fmadds  f13,f12,f13,f10
    fmadds  f0,f12,f0,f11
    fmuls   f1,f6,f13
    fmuls   f0,f12,f0
    bge    .L_atanf_01cc
    fadds   f1,f1,f0
    fmuls   f1,f5,f1
    fsubs   f1,f5,f1
    b    .L_atanf_01fc
.L_atanf_01cc:
    slwi    r0,r0,2
    addi    r9,r13,-20956
    lfsx    f12,r9,r0
    fadds   f0,f1,f0
    addi    r9,r13,-20972
    cmpwi   r30,0
    fmsubs  f0,f5,f0,f12
    lfsx    f13,r9,r0
    fsubs   f0,f0,f5
    fsubs   f1,f13,f0
    bge    .L_atanf_01fc
    fneg    f1,f1
.L_atanf_01fc:
    lwz     r0,28(r1)
    mtlr    r0
    lmw     r30,16(r1)
    addi    r1,r1,24
    blr

# ---------------------------------------------------------------------------
# ceilf @ 0x802411d8, size=0xc4 (196 bytes)
# ---------------------------------------------------------------------------
    .global ceilf
ceilf:
    stwu    r1,-16(r1)
    fmr     f0,f1
    stfs    f0,8(r1)
    lwz     r0,8(r1)
    mr      r11,r0
    rlwinm  r9,r11,9,24,31
    addi    r9,r9,-127
    cmpwi   r9,22
    bgt    .L_ceilf_00a0
    cmpwi   r9,0
    bge    .L_ceilf_005c
    lfs     f0,-28228(r13)
    lfs     f13,-28224(r13)
    fadds   f0,f1,f0
    fcmpu   cr0,f0,f13
    ble    .L_ceilf_00b0
    cmpwi   r11,0
    bge    .L_ceilf_0050
    lis     r11,-32768
    b    .L_ceilf_00b0
.L_ceilf_0050:
    beq    .L_ceilf_00b0
    lis     r11,16256
    b    .L_ceilf_00b0
.L_ceilf_005c:
    lis     r0,127
    ori     r0,r0,65535
    sraw    r10,r0,r9
    and.    r0,r11,r10
    beq    .L_ceilf_00bc
    lfs     f0,-28228(r13)
    lfs     f13,-28224(r13)
    fadds   f0,f1,f0
    fcmpu   cr0,f0,f13
    ble    .L_ceilf_00b0
    cmpwi   r11,0
    ble    .L_ceilf_0098
    lis     r0,128
    sraw    r0,r0,r9
    add     r11,r11,r0
.L_ceilf_0098:
    andc    r11,r11,r10
    b    .L_ceilf_00b0
.L_ceilf_00a0:
    cmpwi   r9,128
    bne    .L_ceilf_00bc
    fadds   f1,f1,f1
    b    .L_ceilf_00bc
.L_ceilf_00b0:
    stw     r11,8(r1)
    lfs     f0,8(r1)
    fmr     f1,f0
.L_ceilf_00bc:
    addi    r1,r1,16
    blr

# ---------------------------------------------------------------------------
# cosf @ 0x8024129c, size=0xdc (220 bytes)
# ---------------------------------------------------------------------------
    .global cosf
cosf:
    stwu    r1,-24(r1)
    mflr    r0
    stw     r0,28(r1)
    lfs     f2,-28220(r13)
    fmr     f0,f1
    stfs    f0,16(r1)
    lwz     r9,16(r1)
    clrlwi  r9,r9,1
    lis     r0,16201
    ori     r0,r0,4056
    cmpw    r9,r0
    bgt    .L_cosf_0038
    bl    __kernel_cosf
    b    .L_cosf_00cc
.L_cosf_0038:
    lis     r0,32639
    ori     r0,r0,65535
    cmpw    r9,r0
    ble    .L_cosf_0050
    fsubs   f1,f1,f1
    b    .L_cosf_00cc
.L_cosf_0050:
    addi    r3,r1,8
    bl    __ieee754_rem_pio2f
    clrlwi  r3,r3,30
    cmpwi   r3,1
    beq    .L_cosf_0090
    bgt    .L_cosf_0074
    cmpwi   r3,0
    beq    .L_cosf_0080
    b    .L_cosf_00bc
.L_cosf_0074:
    cmpwi   r3,2
    beq    .L_cosf_00a8
    b    .L_cosf_00bc
.L_cosf_0080:
    lfs     f1,8(r1)
    lfs     f2,12(r1)
    bl    __kernel_cosf
    b    .L_cosf_00cc
.L_cosf_0090:
    lfs     f1,8(r1)
    li      r3,1
    lfs     f2,12(r1)
    bl    __kernel_sinf
    fneg    f1,f1
    b    .L_cosf_00cc
.L_cosf_00a8:
    lfs     f1,8(r1)
    lfs     f2,12(r1)
    bl    __kernel_cosf
    fneg    f1,f1
    b    .L_cosf_00cc
.L_cosf_00bc:
    lfs     f1,8(r1)
    li      r3,1
    lfs     f2,12(r1)
    bl    __kernel_sinf
.L_cosf_00cc:
    lwz     r0,28(r1)
    mtlr    r0
    addi    r1,r1,24
    blr

# ---------------------------------------------------------------------------
# fabsf @ 0x80241378, size=0x24 (36 bytes)
# ---------------------------------------------------------------------------
    .global fabsf
fabsf:
    stwu    r1,-16(r1)
    stfs    f1,8(r1)
    lwz     r0,8(r1)
    clrlwi  r0,r0,1
    stw     r0,8(r1)
    lfs     f0,8(r1)
    fmr     f1,f0
    addi    r1,r1,16
    blr

# ---------------------------------------------------------------------------
# floorf @ 0x8024139c, size=0xc8 (200 bytes)
# ---------------------------------------------------------------------------
    .global floorf
floorf:
    stwu    r1,-16(r1)
    fmr     f0,f1
    stfs    f0,8(r1)
    lwz     r0,8(r1)
    mr      r11,r0
    rlwinm  r9,r11,9,24,31
    addi    r9,r9,-127
    cmpwi   r9,22
    bgt    .L_floorf_00a4
    cmpwi   r9,0
    bge    .L_floorf_0060
    lfs     f0,-28216(r13)
    lfs     f13,-28212(r13)
    fadds   f0,f1,f0
    fcmpu   cr0,f0,f13
    ble    .L_floorf_00b4
    cmpwi   r11,0
    blt    .L_floorf_0050
    li      r11,0
    b    .L_floorf_00b4
.L_floorf_0050:
    clrlwi. r0,r11,1
    beq    .L_floorf_00b4
    lis     r11,-16512
    b    .L_floorf_00b4
.L_floorf_0060:
    lis     r0,127
    ori     r0,r0,65535
    sraw    r10,r0,r9
    and.    r0,r11,r10
    beq    .L_floorf_00c0
    lfs     f0,-28216(r13)
    lfs     f13,-28212(r13)
    fadds   f0,f1,f0
    fcmpu   cr0,f0,f13
    ble    .L_floorf_00b4
    cmpwi   r11,0
    bge    .L_floorf_009c
    lis     r0,128
    sraw    r0,r0,r9
    add     r11,r11,r0
.L_floorf_009c:
    andc    r11,r11,r10
    b    .L_floorf_00b4
.L_floorf_00a4:
    cmpwi   r9,128
    bne    .L_floorf_00c0
    fadds   f1,f1,f1
    b    .L_floorf_00c0
.L_floorf_00b4:
    stw     r11,8(r1)
    lfs     f0,8(r1)
    fmr     f1,f0
.L_floorf_00c0:
    addi    r1,r1,16
    blr

# ---------------------------------------------------------------------------
# sinf @ 0x80241464, size=0xdc (220 bytes)
# ---------------------------------------------------------------------------
    .global sinf
sinf:
    stwu    r1,-24(r1)
    mflr    r0
    stw     r0,28(r1)
    lfs     f2,-28208(r13)
    fmr     f0,f1
    stfs    f0,16(r1)
    lwz     r9,16(r1)
    clrlwi  r9,r9,1
    lis     r0,16201
    ori     r0,r0,4056
    cmpw    r9,r0
    bgt    .L_sinf_003c
    li      r3,0
    bl    __kernel_sinf
    b    .L_sinf_00cc
.L_sinf_003c:
    lis     r0,32639
    ori     r0,r0,65535
    cmpw    r9,r0
    ble    .L_sinf_0054
    fsubs   f1,f1,f1
    b    .L_sinf_00cc
.L_sinf_0054:
    addi    r3,r1,8
    bl    __ieee754_rem_pio2f
    clrlwi  r3,r3,30
    cmpwi   r3,1
    beq    .L_sinf_0098
    bgt    .L_sinf_0078
    cmpwi   r3,0
    beq    .L_sinf_0084
    b    .L_sinf_00bc
.L_sinf_0078:
    cmpwi   r3,2
    beq    .L_sinf_00a8
    b    .L_sinf_00bc
.L_sinf_0084:
    lfs     f1,8(r1)
    li      r3,1
    lfs     f2,12(r1)
    bl    __kernel_sinf
    b    .L_sinf_00cc
.L_sinf_0098:
    lfs     f1,8(r1)
    lfs     f2,12(r1)
    bl    __kernel_cosf
    b    .L_sinf_00cc
.L_sinf_00a8:
    lfs     f1,8(r1)
    li      r3,1
    lfs     f2,12(r1)
    bl    __kernel_sinf
    b    .L_sinf_00c8
.L_sinf_00bc:
    lfs     f1,8(r1)
    lfs     f2,12(r1)
    bl    __kernel_cosf
.L_sinf_00c8:
    fneg    f1,f1
.L_sinf_00cc:
    lwz     r0,28(r1)
    mtlr    r0
    addi    r1,r1,24
    blr

# ---------------------------------------------------------------------------
# tanf @ 0x80241540, size=0x80 (128 bytes)
# ---------------------------------------------------------------------------
    .global tanf
tanf:
    stwu    r1,-24(r1)
    mflr    r0
    stw     r0,28(r1)
    lfs     f2,-28204(r13)
    fmr     f0,f1
    stfs    f0,16(r1)
    lwz     r9,16(r1)
    clrlwi  r9,r9,1
    lis     r0,16201
    ori     r0,r0,4058
    cmpw    r9,r0
    bgt    .L_tanf_003c
    li      r3,1
    bl    __kernel_tanf
    b    .L_tanf_0070
.L_tanf_003c:
    lis     r0,32639
    ori     r0,r0,65535
    cmpw    r9,r0
    bgt    .L_tanf_006c
    addi    r3,r1,8
    bl    __ieee754_rem_pio2f
    rlwinm  r3,r3,1,30,30
    lfs     f1,8(r1)
    lfs     f2,12(r1)
    subfic  r3,r3,1
    bl    __kernel_tanf
    b    .L_tanf_0070
.L_tanf_006c:
    fsubs   f1,f1,f1
.L_tanf_0070:
    lwz     r0,28(r1)
    mtlr    r0
    addi    r1,r1,24
    blr

# ---------------------------------------------------------------------------
# __kernel_cosf @ 0x802415c0, size=0xec (236 bytes)
# ---------------------------------------------------------------------------
    .global __kernel_cosf
__kernel_cosf:
    stwu    r1,-24(r1)
    fmr     f9,f1
    fmr     f0,f9
    stfs    f0,8(r1)
    lwz     r9,8(r1)
    clrlwi  r11,r9,1
    lis     r0,12799
    ori     r0,r0,65535
    cmpw    r11,r0
    bgt    .L___kernel_cosf_0048
    fmr     f0,f9
    fctiwz  f13,f0
    stfd    f13,16(r1)
    lwz     r9,20(r1)
    cmpwi   r9,0
    bne    .L___kernel_cosf_0048
    lfs     f1,-28200(r13)
    b    .L___kernel_cosf_00e4
.L___kernel_cosf_0048:
    lfs     f12,-28192(r13)
    fmuls   f10,f9,f9
    lfs     f0,-28196(r13)
    lis     r0,16025
    lfs     f11,-28188(r13)
    ori     r0,r0,39321
    fmadds  f0,f10,f0,f12
    lfs     f13,-28184(r13)
    fmadds  f0,f10,f0,f11
    lfs     f12,-28180(r13)
    fmadds  f0,f10,f0,f13
    lfs     f11,-28176(r13)
    fmadds  f0,f10,f0,f12
    cmpw    r11,r0
    fmadds  f0,f10,f0,f11
    fmuls   f12,f10,f0
    bgt    .L___kernel_cosf_00a4
    fmuls   f0,f9,f2
    lfs     f1,-28172(r13)
    fmsubs  f0,f10,f12,f0
    lfs     f13,-28200(r13)
    fmsubs  f1,f10,f1,f0
    b    .L___kernel_cosf_00e0
.L___kernel_cosf_00a4:
    lis     r0,16200
    cmpw    r11,r0
    ble    .L___kernel_cosf_00b8
    lwz     r0,-28168(r13)
    b    .L___kernel_cosf_00bc
.L___kernel_cosf_00b8:
    addis   r0,r11,-256
.L___kernel_cosf_00bc:
    fmuls   f0,f9,f2
    stw     r0,8(r1)
    fmsubs  f0,f10,f12,f0
    lfs     f1,-28172(r13)
    lfs     f12,8(r1)
    lfs     f13,-28200(r13)
    fmsubs  f1,f10,f1,f12
    fsubs   f13,f13,f12
    fsubs   f1,f1,f0
.L___kernel_cosf_00e0:
    fsubs   f1,f13,f1
.L___kernel_cosf_00e4:
    addi    r1,r1,24
    blr

# ---------------------------------------------------------------------------
# __kernel_sinf @ 0x802416ac, size=0xac (172 bytes)
# ---------------------------------------------------------------------------
    .global __kernel_sinf
__kernel_sinf:
    stwu    r1,-24(r1)
    fmr     f9,f1
    fmr     f0,f9
    stfs    f0,8(r1)
    lwz     r9,8(r1)
    clrlwi  r9,r9,1
    lis     r0,12799
    ori     r0,r0,65535
    cmpw    r9,r0
    bgt    .L___kernel_sinf_0040
    fmr     f0,f9
    fctiwz  f13,f0
    stfd    f13,16(r1)
    lwz     r9,20(r1)
    cmpwi   r9,0
    beq    .L___kernel_sinf_00a4
.L___kernel_sinf_0040:
    lfs     f13,-28160(r13)
    fmuls   f10,f9,f9
    lfs     f0,-28164(r13)
    fmuls   f8,f10,f9
    lfs     f11,-28156(r13)
    cmpwi   r3,0
    fmadds  f0,f10,f0,f13
    lfs     f12,-28152(r13)
    fmadds  f0,f10,f0,f11
    lfs     f13,-28148(r13)
    fmadds  f0,f10,f0,f12
    fmadds  f0,f10,f0,f13
    beq    .L___kernel_sinf_0098
    fmuls   f13,f8,f0
    lfs     f1,-28140(r13)
    lfs     f0,-28144(r13)
    fmsubs  f1,f2,f1,f13
    fmsubs  f1,f10,f1,f2
    fmuls   f0,f8,f0
    fsubs   f1,f1,f0
    fsubs   f1,f9,f1
    b    .L___kernel_sinf_00a4
.L___kernel_sinf_0098:
    lfs     f1,-28144(r13)
    fmadds  f1,f10,f0,f1
    fmadds  f1,f8,f1,f9
.L___kernel_sinf_00a4:
    addi    r1,r1,24
    blr

# ---------------------------------------------------------------------------
# __kernel_tanf @ 0x80241758, size=0x214 (532 bytes)
# ---------------------------------------------------------------------------
    .global __kernel_tanf
__kernel_tanf:
    stwu    r1,-24(r1)
    mflr    r0
    stw     r0,28(r1)
    fmr     f6,f1
    fmr     f0,f6
    stfs    f0,8(r1)
    lwz     r8,8(r1)
    clrlwi  r11,r8,1
    lis     r0,12671
    ori     r0,r0,65535
    cmpw    r11,r0
    bgt    .L___kernel_tanf_0080
    fmr     f0,f6
    fctiwz  f13,f0
    stfd    f13,16(r1)
    lwz     r9,20(r1)
    cmpwi   r9,0
    bne    .L___kernel_tanf_0080
    addi    r0,r3,1
    or.     r9,r11,r0
    bne    .L___kernel_tanf_0064
    bl    fabsf
    lfs     f0,-28136(r13)
    fdivs   f1,f0,f1
    b    .L___kernel_tanf_0204
.L___kernel_tanf_0064:
    cmpwi   r3,1
    beq    .L___kernel_tanf_0078
    lfs     f0,-28132(r13)
    fdivs   f1,f0,f6
    b    .L___kernel_tanf_0204
.L___kernel_tanf_0078:
    fmr     f1,f6
    b    .L___kernel_tanf_0204
.L___kernel_tanf_0080:
    lis     r0,16172
    ori     r0,r0,41279
    cmpw    r11,r0
    ble    .L___kernel_tanf_00b8
    cmpwi   r8,0
    bge    .L___kernel_tanf_00a0
    fneg    f6,f6
    fneg    f2,f2
.L___kernel_tanf_00a0:
    lfs     f0,-28124(r13)
    lfs     f13,-28128(r13)
    fsubs   f1,f0,f2
    fsubs   f7,f13,f6
    lfs     f2,-28120(r13)
    fadds   f6,f7,f1
.L___kernel_tanf_00b8:
    fmuls   f7,f6,f6
    lfs     f12,-20772(r13)
    lfs     f13,-20764(r13)
    fmuls   f1,f7,f7
    lfs     f11,-20768(r13)
    fmuls   f5,f7,f6
    lfs     f0,-20760(r13)
    fmadds  f13,f1,f13,f12
    lfs     f10,-20780(r13)
    lis     r0,16172
    fmadds  f0,f1,f0,f11
    lfs     f12,-20776(r13)
    lfs     f11,-20784(r13)
    fmadds  f13,f1,f13,f10
    fmadds  f0,f1,f0,f12
    lfs     f9,-20788(r13)
    fmadds  f0,f1,f0,f11
    lfs     f10,-20796(r13)
    lfs     f8,-20792(r13)
    fmadds  f13,f1,f13,f9
    lfs     f12,-20804(r13)
    fmadds  f13,f1,f13,f10
    lfs     f11,-20800(r13)
    fmadds  f0,f1,f0,f8
    fmadds  f9,f1,f13,f12
    lfs     f10,-20808(r13)
    fmadds  f0,f1,f0,f11
    ori     r0,r0,41279
    fmadds  f0,f7,f0,f9
    cmpw    r11,r0
    fmadds  f0,f5,f0,f2
    fmadds  f9,f7,f0,f2
    fmadds  f9,f10,f5,f9
    fadds   f1,f6,f9
    ble    .L___kernel_tanf_01ac
    xoris   r0,r3,32768
    stw     r0,20(r1)
    lis     r10,17200
    lfd     f12,-28112(r13)
    fmuls   f13,f1,f1
    stw     r10,16(r1)
    rlwinm  r0,r8,2,30,30
    subfic  r0,r0,1
    mr      r11,r9
    lfd     f0,16(r1)
    xoris   r0,r0,32768
    stw     r0,20(r1)
    fsub    f0,f0,f12
    frsp    f11,f0
    stw     r10,16(r1)
    fadds   f0,f1,f11
    fdivs   f13,f13,f0
    lfd     f1,16(r1)
    fsubs   f13,f13,f9
    fsubs   f13,f6,f13
    fsub    f1,f1,f12
    fadds   f13,f13,f13
    fsubs   f13,f11,f13
    frsp    f1,f1
    fmuls   f1,f1,f13
    b    .L___kernel_tanf_0204
.L___kernel_tanf_01ac:
    cmpwi   r3,1
    beq    .L___kernel_tanf_0204
    lfs     f13,-28132(r13)
    fmr     f0,f1
    stfs    f0,8(r1)
    fdivs   f13,f13,f1
    lfs     f12,-28136(r13)
    lwz     r0,8(r1)
    clrrwi  r9,r0,12
    stw     r9,8(r1)
    lfs     f7,8(r1)
    fmr     f0,f13
    stfs    f0,8(r1)
    fsubs   f0,f7,f6
    lwz     r0,8(r1)
    fsubs   f11,f9,f0
    clrrwi  r9,r0,12
    stw     r9,8(r1)
    lfs     f1,8(r1)
    fmadds  f5,f1,f7,f12
    fmadds  f0,f1,f11,f5
    fmadds  f1,f13,f0,f1
.L___kernel_tanf_0204:
    lwz     r0,28(r1)
    mtlr    r0
    addi    r1,r1,24
    blr

# ---------------------------------------------------------------------------
# __ieee754_rem_pio2f @ 0x8024196c, size=0x350 (848 bytes)
# ---------------------------------------------------------------------------
    .global __ieee754_rem_pio2f
__ieee754_rem_pio2f:
    stwu    r1,-64(r1)
    mflr    r0
    stmw    r29,52(r1)
    stw     r0,68(r1)
    mr      r31,r3
    fmr     f0,f1
    stfs    f0,24(r1)
    lwz     r29,24(r1)
    clrlwi  r30,r29,1
    lis     r0,16201
    ori     r0,r0,4056
    cmpw    r30,r0
    bgt    .L___ieee754_rem_pio2f_0044
    lfs     f0,-28104(r13)
    li      r3,0
    stfs    f1,0(r31)
    b    .L___ieee754_rem_pio2f_0338
.L___ieee754_rem_pio2f_0044:
    lis     r0,16406
    ori     r0,r0,52195
    cmpw    r30,r0
    bgt    .L___ieee754_rem_pio2f_00f4
    cmpwi   r29,0
    ble    .L___ieee754_rem_pio2f_00a8
    lfs     f0,-28100(r13)
    lis     r0,16329
    rlwinm  r9,r29,0,1,27
    ori     r0,r0,4048
    fsubs   f1,f1,f0
    cmpw    r9,r0
    beq    .L___ieee754_rem_pio2f_0080
    lfs     f12,-28096(r13)
    b    .L___ieee754_rem_pio2f_008c
.L___ieee754_rem_pio2f_0080:
    lfs     f0,-28092(r13)
    lfs     f12,-28088(r13)
    fsubs   f1,f1,f0
.L___ieee754_rem_pio2f_008c:
    fsubs   f13,f1,f12
    fsubs   f0,f1,f13
    stfs    f13,0(r31)
    fsubs   f0,f0,f12
    stfs    f0,4(r31)
    li      r3,1
    b    .L___ieee754_rem_pio2f_033c
.L___ieee754_rem_pio2f_00a8:
    lfs     f0,-28100(r13)
    lis     r0,16329
    rlwinm  r9,r29,0,1,27
    ori     r0,r0,4048
    fadds   f1,f1,f0
    cmpw    r9,r0
    beq    .L___ieee754_rem_pio2f_00cc
    lfs     f12,-28096(r13)
    b    .L___ieee754_rem_pio2f_00d8
.L___ieee754_rem_pio2f_00cc:
    lfs     f0,-28092(r13)
    lfs     f12,-28088(r13)
    fadds   f1,f1,f0
.L___ieee754_rem_pio2f_00d8:
    fadds   f13,f1,f12
    fsubs   f0,f1,f13
    stfs    f13,0(r31)
    fadds   f0,f0,f12
    stfs    f0,4(r31)
    li      r3,-1
    b    .L___ieee754_rem_pio2f_033c
.L___ieee754_rem_pio2f_00f4:
    lis     r0,17225
    ori     r0,r0,3968
    cmpw    r30,r0
    bgt    .L___ieee754_rem_pio2f_023c
    bl    fabsf
    lfs     f13,-28080(r13)
    fmr     f9,f1
    lfs     f0,-28084(r13)
    mr      r9,r11
    lis     r10,17200
    fmadds  f0,f9,f0,f13
    lfd     f11,-28072(r13)
    lfs     f13,-28100(r13)
    fctiwz  f12,f0
    lfs     f10,-28096(r13)
    stfd    f12,40(r1)
    lwz     r3,44(r1)
    xoris   r0,r3,32768
    cmpwi   r3,31
    stw     r0,44(r1)
    stw     r10,40(r1)
    lfd     f0,40(r1)
    fsub    f0,f0,f11
    frsp    f8,f0
    fmuls   f13,f8,f13
    fsubs   f11,f9,f13
    fmuls   f1,f8,f10
    bgt    .L___ieee754_rem_pio2f_018c
    addi    r0,r3,-1
    addi    r10,r13,-19964
    slwi    r0,r0,2
    rlwinm  r11,r29,0,1,23
    lwzx    r9,r10,r0
    cmpw    r11,r9
    beq    .L___ieee754_rem_pio2f_018c
    fsubs   f0,f11,f1
    stfs    f0,0(r31)
    b    .L___ieee754_rem_pio2f_0218
.L___ieee754_rem_pio2f_018c:
    fsubs   f0,f11,f1
    srawi   r9,r30,23
    stfs    f0,0(r31)
    stfs    f0,24(r1)
    lwz     r0,24(r1)
    rlwinm  r0,r0,9,24,31
    subf    r0,r0,r9
    cmpwi   r0,8
    ble    .L___ieee754_rem_pio2f_0218
    lfs     f0,-28092(r13)
    fmr     f9,f11
    lfs     f12,-28088(r13)
    fmuls   f1,f8,f0
    fsubs   f11,f11,f1
    fsubs   f0,f9,f11
    fsubs   f0,f0,f1
    fmsubs  f1,f8,f12,f0
    fsubs   f13,f11,f1
    stfs    f13,0(r31)
    stfs    f13,24(r1)
    lwz     r0,24(r1)
    rlwinm  r0,r0,9,24,31
    subf    r0,r0,r9
    cmpwi   r0,25
    ble    .L___ieee754_rem_pio2f_0218
    lfs     f0,-28064(r13)
    fmr     f9,f11
    lfs     f12,-28060(r13)
    fmuls   f1,f8,f0
    fsubs   f11,f11,f1
    fsubs   f0,f9,f11
    fsubs   f0,f0,f1
    fmsubs  f1,f8,f12,f0
    fsubs   f13,f11,f1
    stfs    f13,0(r31)
.L___ieee754_rem_pio2f_0218:
    lfs     f13,0(r31)
    cmpwi   r29,0
    fsubs   f0,f11,f13
    fsubs   f0,f0,f1
    stfs    f0,4(r31)
    bge    .L___ieee754_rem_pio2f_033c
    fneg    f13,f13
    neg     r3,r3
    b    .L___ieee754_rem_pio2f_0330
.L___ieee754_rem_pio2f_023c:
    lis     r0,32639
    ori     r0,r0,65535
    cmpw    r30,r0
    ble    .L___ieee754_rem_pio2f_025c
    fsubs   f0,f1,f1
    li      r3,0
    stfs    f0,0(r31)
    b    .L___ieee754_rem_pio2f_0338
.L___ieee754_rem_pio2f_025c:
    srawi   r9,r30,23
    addi    r5,r9,-134
    slwi    r0,r5,23
    subf    r30,r0,r30
    stw     r30,24(r1)
    lfs     f1,24(r1)
    cmpwi   r29,0
    addi    r8,r1,8
    lfd     f12,-28072(r13)
    lfs     f11,-28056(r13)
    mfcr    r30
    lis     r7,17200
    mr      r10,r8
    addi    r0,r1,12
.L___ieee754_rem_pio2f_0294:
    fmr     f0,f1
    fctiwz  f13,f0
    mr      r11,r9
    stfd    f13,40(r1)
    lwz     r9,44(r1)
    xoris   r9,r9,32768
    stw     r9,44(r1)
    stw     r7,40(r1)
    lfd     f0,40(r1)
    fsub    f0,f0,f12
    frsp    f0,f0
    stfs    f0,0(r10)
    fsubs   f0,f1,f0
    addi    r10,r10,4
    fmuls   f1,f0,f11
    cmpw    r10,r0
    ble    .L___ieee754_rem_pio2f_0294
    stfs    f1,16(r1)
    li      r6,3
    lfs     f13,-28104(r13)
    lfs     f0,8(r8)
    fcmpu   cr0,f0,f13
    bne    .L___ieee754_rem_pio2f_0304
    addi    r9,r8,8
.L___ieee754_rem_pio2f_02f4:
    lfsu    f0,-4(r9)
    addi    r6,r6,-1
    fcmpu   cr0,f0,f13
    beq    .L___ieee754_rem_pio2f_02f4
.L___ieee754_rem_pio2f_0304:
    addi    r3,r1,8
    mr      r4,r31
    li      r7,2
    addi    r8,r13,-20756
    bl    __kernel_rem_pio2f
    mtcrf   128,r30
    bge    .L___ieee754_rem_pio2f_033c
    lfs     f13,0(r31)
    neg     r3,r3
    lfs     f0,4(r31)
    fneg    f13,f13
.L___ieee754_rem_pio2f_0330:
    fneg    f0,f0
    stfs    f13,0(r31)
.L___ieee754_rem_pio2f_0338:
    stfs    f0,4(r31)
.L___ieee754_rem_pio2f_033c:
    lwz     r0,68(r1)
    mtlr    r0
    lmw     r29,52(r1)
    addi    r1,r1,64
    blr

# ---------------------------------------------------------------------------
# __kernel_rem_pio2f @ 0x80241cbc, size=0x884 (2180 bytes)
# ---------------------------------------------------------------------------
    .global __kernel_rem_pio2f
__kernel_rem_pio2f:
    stwu    r1,-416(r1)
    mflr    r0
    mfcr    r12
    stfd    f31,408(r1)
    stmw    r18,352(r1)
    stw     r0,420(r1)
    stw     r12,348(r1)
    mr      r19,r7
    addi    r9,r13,-19796
    slwi    r0,r19,2
    mr      r20,r3
    lwzx    r27,r9,r0
    mr      r26,r4
    mr      r18,r8
    addi    r29,r6,-1
    addic.  r0,r5,-3
    bge    .L___kernel_rem_pio2f_0048
    addi    r0,r5,4
.L___kernel_rem_pio2f_0048:
    srawi.  r24,r0,3
    bge    .L___kernel_rem_pio2f_0054
    li      r24,0
.L___kernel_rem_pio2f_0054:
    addi    r0,r24,1
    subf    r6,r29,r24
    slwi    r0,r0,3
    mtctr   r6
    addi    r21,r1,248
    subf    r28,r0,r5
    addi    r30,r1,8
    cmpwi   cr3,r19,2
    add.    r9,r29,r27
    blt    .L___kernel_rem_pio2f_00e8
    slwi    r0,r6,2
    lfd     f13,-28048(r13)
    lfs     f12,-28040(r13)
    add     r10,r0,r18
    addi    r8,r9,1
    lis     r7,17200
    addi    r11,r1,88
.L___kernel_rem_pio2f_0098:
    mfctr   r9
    cmpwi   r9,0
    blt    .L___kernel_rem_pio2f_00c8
    lwz     r0,0(r10)
    xoris   r0,r0,32768
    stw     r0,340(r1)
    stw     r7,336(r1)
    lfd     f0,336(r1)
    fsub    f0,f0,f13
    frsp    f0,f0
    stfs    f0,0(r11)
    b    .L___kernel_rem_pio2f_00cc
.L___kernel_rem_pio2f_00c8:
    stfs    f12,0(r11)
.L___kernel_rem_pio2f_00cc:
    mfctr   r6
    addi    r11,r11,4
    addi    r6,r6,1
    addi    r10,r10,4
    mtctr   r6
    addic.  r8,r8,-1
    bne    .L___kernel_rem_pio2f_0098
.L___kernel_rem_pio2f_00e8:
    li      r8,0
    cmpwi   cr4,r28,0
    cmpw    r8,r27
    bgt    .L___kernel_rem_pio2f_0158
    lfs     f12,-28040(r13)
    mr      r10,r21
.L___kernel_rem_pio2f_0100:
    fmr     f1,f12
    cmpwi   r29,0
    slwi    r6,r8,2
    addi    r5,r8,1
    blt    .L___kernel_rem_pio2f_0148
    add     r0,r29,r8
    addi    r9,r1,88
    slwi    r0,r0,2
    mr      r11,r20
    add     r9,r0,r9
    addi    r0,r29,1
    mtctr   r0
.L___kernel_rem_pio2f_0130:
    lfs     f13,0(r11)
    lfs     f0,0(r9)
    addi    r11,r11,4
    addi    r9,r9,-4
    fmadds  f1,f13,f0,f1
    bdnz    .L___kernel_rem_pio2f_0130
.L___kernel_rem_pio2f_0148:
    mr      r8,r5
    stfsx   f1,r10,r6
    cmpw    r8,r27
    ble    .L___kernel_rem_pio2f_0100
.L___kernel_rem_pio2f_0158:
    mr      r31,r27
.L___kernel_rem_pio2f_015c:
    slwi    r0,r31,2
    mtctr   r31
    mr      r22,r0
    lfsx    f31,r21,r0
    cmpwi   r31,0
    ble    .L___kernel_rem_pio2f_01f8
    addi    r0,r22,-4
    lfs     f9,-28036(r13)
    add     r7,r0,r21
    lfd     f11,-28048(r13)
    lfs     f10,-28032(r13)
    lis     r0,17200
    mr      r8,r30
.L___kernel_rem_pio2f_0190:
    fmuls   f0,f31,f9
    mr      r11,r9
    fctiwz  f13,f0
    mr      r10,r9
    stfd    f13,336(r1)
    mfctr   r6
    addic.  r6,r6,-1
    lwz     r9,340(r1)
    mtctr   r6
    xoris   r9,r9,32768
    stw     r9,340(r1)
    stw     r0,336(r1)
    lfd     f0,336(r1)
    fsub    f0,f0,f11
    frsp    f1,f0
    fmuls   f13,f1,f10
    fsubs   f13,f31,f13
    fctiwz  f12,f13
    stfd    f12,336(r1)
    lwz     r10,340(r1)
    stw     r10,0(r8)
    addi    r8,r8,4
    lfs     f0,0(r7)
    addi    r7,r7,-4
    fadds   f31,f0,f1
    bgt    .L___kernel_rem_pio2f_0190
.L___kernel_rem_pio2f_01f8:
    fmr     f1,f31
    mr      r3,r28
    bl    scalbnf
    lfs     f0,-28028(r13)
    fmr     f31,f1
    fmuls   f1,f31,f0
    bl    floorf
    lfs     f0,-28024(r13)
    mr      r9,r11
    lis     r10,17200
    fmuls   f1,f1,f0
    lfd     f12,-28048(r13)
    fsubs   f31,f31,f1
    li      r8,0
    fmr     f0,f31
    fctiwz  f13,f0
    stfd    f13,336(r1)
    lwz     r23,340(r1)
    xoris   r0,r23,32768
    stw     r0,340(r1)
    stw     r10,336(r1)
    lfd     f0,336(r1)
    fsub    f0,f0,f12
    frsp    f0,f0
    fsubs   f31,f31,f0
    ble    cr4,.L___kernel_rem_pio2f_0290
    addi    r11,r31,-1
    subfic  r9,r28,8
    slwi    r11,r11,2
    subfic  r10,r28,7
    lwzx    r0,r30,r11
    sraw    r8,r0,r9
    slw     r9,r8,r9
    add     r23,r23,r8
    subf    r0,r9,r0
    sraw    r8,r0,r10
    stwx    r0,r30,r11
    b    .L___kernel_rem_pio2f_02bc
.L___kernel_rem_pio2f_0290:
    bne    cr4,.L___kernel_rem_pio2f_02a8
    addi    r0,r31,-1
    slwi    r0,r0,2
    lwzx    r9,r30,r0
    srawi   r8,r9,8
    b    .L___kernel_rem_pio2f_02bc
.L___kernel_rem_pio2f_02a8:
    lfs     f0,-28020(r13)
    fcmpu   cr0,f31,f0
    cror    so,eq,gt
    bns    .L___kernel_rem_pio2f_02bc
    li      r8,2
.L___kernel_rem_pio2f_02bc:
    cmpwi   r8,0
    mfcr    r25
    ble    .L___kernel_rem_pio2f_0384
    cmpwi   cr7,r8,2
    addi    r23,r23,1
    li      r10,0
    cmpwi   r31,0
    ble    .L___kernel_rem_pio2f_0324
    mr      r11,r30
    li      r9,0
    mr      r8,r31
.L___kernel_rem_pio2f_02e8:
    lwzx    r0,r9,r11
    cmpwi   r10,0
    mtctr   r0
    bne    .L___kernel_rem_pio2f_030c
    cmpwi   r0,0
    beq    .L___kernel_rem_pio2f_0318
    subfic  r0,r0,256
    li      r10,1
    b    .L___kernel_rem_pio2f_0314
.L___kernel_rem_pio2f_030c:
    mfctr   r6
    subfic  r0,r6,255
.L___kernel_rem_pio2f_0314:
    stwx    r0,r9,r30
.L___kernel_rem_pio2f_0318:
    addi    r9,r9,4
    addic.  r8,r8,-1
    bne    .L___kernel_rem_pio2f_02e8
.L___kernel_rem_pio2f_0324:
    ble    cr4,.L___kernel_rem_pio2f_0364
    cmpwi   r28,1
    beq    .L___kernel_rem_pio2f_033c
    cmpwi   r28,2
    beq    .L___kernel_rem_pio2f_0350
    b    .L___kernel_rem_pio2f_0364
.L___kernel_rem_pio2f_033c:
    addi    r9,r31,-1
    slwi    r9,r9,2
    lwzx    r0,r30,r9
    clrlwi  r0,r0,25
    b    .L___kernel_rem_pio2f_0360
.L___kernel_rem_pio2f_0350:
    addi    r9,r31,-1
    slwi    r9,r9,2
    lwzx    r0,r30,r9
    clrlwi  r0,r0,26
.L___kernel_rem_pio2f_0360:
    stwx    r0,r30,r9
.L___kernel_rem_pio2f_0364:
    bne    cr7,.L___kernel_rem_pio2f_0384
    lfs     f1,-28016(r13)
    cmpwi   r10,0
    fsubs   f31,f1,f31
    beq    .L___kernel_rem_pio2f_0384
    mr      r3,r28
    bl    scalbnf
    fsubs   f31,f31,f1
.L___kernel_rem_pio2f_0384:
    lfs     f0,-28040(r13)
    fmr     f13,f0
    fcmpu   cr0,f31,f0
    bne    .L___kernel_rem_pio2f_04c8
    addi    r8,r31,-1
    li      r0,0
    mtctr   r0
    cmpw    r8,r27
    blt    .L___kernel_rem_pio2f_03d0
    slwi    r0,r8,2
    add     r9,r0,r30
.L___kernel_rem_pio2f_03b0:
    lwz     r0,0(r9)
    mfctr   r6
    addi    r8,r8,-1
    addi    r9,r9,-4
    or      r6,r6,r0
    cmpw    r8,r27
    mtctr   r6
    bge    .L___kernel_rem_pio2f_03b0
.L___kernel_rem_pio2f_03d0:
    mfctr   r7
    cmpwi   r7,0
    bne    .L___kernel_rem_pio2f_04c8
    addi    r0,r27,-1
    li      r7,1
    slwi    r0,r0,2
    addi    r11,r31,1
    lwzx    r9,r30,r0
    cmpwi   r9,0
    bne    .L___kernel_rem_pio2f_0414
    slwi    r9,r27,2
    add     r9,r9,r30
    addi    r9,r9,-4
.L___kernel_rem_pio2f_0404:
    lwzu    r0,-4(r9)
    addi    r7,r7,1
    cmpwi   r0,0
    beq    .L___kernel_rem_pio2f_0404
.L___kernel_rem_pio2f_0414:
    add     r0,r31,r7
    mr      r8,r11
    mr      r7,r0
    cmpw    r8,r0
    bgt    .L___kernel_rem_pio2f_04c0
    addi    r4,r1,88
    lfd     f12,-28048(r13)
    lfs     f11,-28040(r13)
    mr      r25,r4
    lis     r31,17200
    mr      r12,r21
    mr      r3,r7
.L___kernel_rem_pio2f_0444:
    add     r0,r24,r8
    slwi    r0,r0,2
    add     r9,r29,r8
    lwzx    r11,r18,r0
    slwi    r9,r9,2
    addi    r5,r8,1
    fmr     f1,f11
    xoris   r11,r11,32768
    cmpwi   r29,0
    stw     r11,340(r1)
    slwi    r6,r8,2
    stw     r31,336(r1)
    lfd     f0,336(r1)
    fsub    f0,f0,f12
    frsp    f0,f0
    stfsx   f0,r4,r9
    blt    .L___kernel_rem_pio2f_04b0
    addi    r10,r29,1
    add     r9,r9,r25
    mtctr   r10
    mr      r11,r20
.L___kernel_rem_pio2f_0498:
    lfs     f13,0(r11)
    lfs     f0,0(r9)
    addi    r11,r11,4
    addi    r9,r9,-4
    fmadds  f1,f13,f0,f1
    bdnz    .L___kernel_rem_pio2f_0498
.L___kernel_rem_pio2f_04b0:
    mr      r8,r5
    stfsx   f1,r12,r6
    cmpw    r8,r3
    ble    .L___kernel_rem_pio2f_0444
.L___kernel_rem_pio2f_04c0:
    mr      r31,r7
    b    .L___kernel_rem_pio2f_015c
.L___kernel_rem_pio2f_04c8:
    fcmpu   cr0,f31,f13
    bne    .L___kernel_rem_pio2f_0504
    addi    r31,r31,-1
    addi    r28,r28,-8
    slwi    r9,r31,2
    lwzx    r0,r30,r9
    cmpwi   r0,0
    bne    .L___kernel_rem_pio2f_05b4
    add     r9,r9,r30
.L___kernel_rem_pio2f_04ec:
    lwzu    r0,-4(r9)
    addi    r31,r31,-1
    addi    r28,r28,-8
    cmpwi   r0,0
    beq    .L___kernel_rem_pio2f_04ec
    b    .L___kernel_rem_pio2f_05b4
.L___kernel_rem_pio2f_0504:
    fmr     f1,f31
    neg     r3,r28
    bl    scalbnf
    lfs     f9,-28032(r13)
    fmr     f31,f1
    fcmpu   cr0,f31,f9
    cror    so,eq,gt
    bns    .L___kernel_rem_pio2f_05a0
    lfs     f0,-28036(r13)
    mr      r8,r9
    mr      r11,r9
    fmuls   f0,f31,f0
    mr      r10,r9
    lis     r0,17200
    fctiwz  f13,f0
    lfd     f10,-28048(r13)
    stfd    f13,336(r1)
    addi    r31,r31,1
    slwi    r7,r31,2
    addi    r28,r28,8
    lwz     r9,340(r1)
    xoris   r9,r9,32768
    stw     r9,340(r1)
    stw     r0,336(r1)
    lfd     f0,336(r1)
    fsub    f0,f0,f10
    frsp    f1,f0
    fmuls   f13,f1,f9
    fsubs   f13,f31,f13
    fctiwz  f12,f13
    stfd    f12,336(r1)
    fmr     f0,f1
    fctiwz  f11,f0
    lwz     r11,340(r1)
    stfd    f11,336(r1)
    stwx    r11,r30,r22
    lwz     r10,340(r1)
    stwx    r10,r30,r7
    b    .L___kernel_rem_pio2f_05b4
.L___kernel_rem_pio2f_05a0:
    fmr     f0,f31
    fctiwz  f13,f0
    stfd    f13,336(r1)
    lwz     r9,340(r1)
    stwx    r9,r30,r22
.L___kernel_rem_pio2f_05b4:
    lfs     f1,-28016(r13)
    mr      r3,r28
    bl    scalbnf
    mr.     r8,r31
    blt    .L___kernel_rem_pio2f_0614
    lfd     f13,-28048(r13)
    mr      r7,r30
    lfs     f12,-28036(r13)
    mr      r10,r21
    lis     r6,17200
    slwi    r11,r8,2
.L___kernel_rem_pio2f_05e0:
    lwzx    r0,r11,r7
    addic.  r8,r8,-1
    xoris   r0,r0,32768
    stw     r0,340(r1)
    stw     r6,336(r1)
    lfd     f0,336(r1)
    fsub    f0,f0,f13
    frsp    f0,f0
    fmuls   f0,f1,f0
    stfsx   f0,r11,r10
    fmuls   f1,f1,f12
    addi    r11,r11,-4
    bge    .L___kernel_rem_pio2f_05e0
.L___kernel_rem_pio2f_0614:
    mr.     r8,r31
    blt    .L___kernel_rem_pio2f_068c
    mr      r3,r21
.L___kernel_rem_pio2f_0620:
    li      r7,0
    lfs     f1,-28040(r13)
    cmpw    r7,r27
    addi    r4,r8,-1
    subf    r11,r8,r31
    addi    r6,r1,168
    bgt    .L___kernel_rem_pio2f_067c
    mr      r5,r11
    cmpw    r7,r11
    bgt    .L___kernel_rem_pio2f_067c
    slwi    r0,r8,2
    addi    r10,r13,-19784
    add     r9,r0,r3
.L___kernel_rem_pio2f_0654:
    lfs     f13,0(r10)
    addi    r7,r7,1
    lfs     f0,0(r9)
    addi    r10,r10,4
    addi    r9,r9,4
    cmpw    r7,r27
    fmadds  f1,f13,f0,f1
    bgt    .L___kernel_rem_pio2f_067c
    cmpw    r7,r5
    ble    .L___kernel_rem_pio2f_0654
.L___kernel_rem_pio2f_067c:
    slwi    r0,r11,2
    mr.     r8,r4
    stfsx   f1,r6,r0
    bge    .L___kernel_rem_pio2f_0620
.L___kernel_rem_pio2f_068c:
    bgt    cr3,.L___kernel_rem_pio2f_06a4
    cmpwi   r19,1
    bge    .L___kernel_rem_pio2f_06f4
    cmpwi   r19,0
    beq    .L___kernel_rem_pio2f_06b0
    b    .L___kernel_rem_pio2f_0860
.L___kernel_rem_pio2f_06a4:
    cmpwi   r19,3
    beq    .L___kernel_rem_pio2f_0774
    b    .L___kernel_rem_pio2f_0860
.L___kernel_rem_pio2f_06b0:
    lfs     f1,-28040(r13)
    mr.     r8,r31
    blt    .L___kernel_rem_pio2f_06dc
    addi    r9,r1,168
    slwi    r0,r8,2
    add     r9,r9,r0
.L___kernel_rem_pio2f_06c8:
    lfs     f0,0(r9)
    addic.  r8,r8,-1
    addi    r9,r9,-4
    fadds   f1,f1,f0
    bge    .L___kernel_rem_pio2f_06c8
.L___kernel_rem_pio2f_06dc:
    stfs    f1,0(r26)
    mtcrf   128,r25
    beq    .L___kernel_rem_pio2f_0860
    fneg    f0,f1
    stfs    f0,0(r26)
    b    .L___kernel_rem_pio2f_0860
.L___kernel_rem_pio2f_06f4:
    lfs     f1,-28040(r13)
    mr.     r8,r31
    blt    .L___kernel_rem_pio2f_0720
    addi    r9,r1,168
    slwi    r0,r8,2
    add     r9,r9,r0
.L___kernel_rem_pio2f_070c:
    lfs     f0,0(r9)
    addic.  r8,r8,-1
    addi    r9,r9,-4
    fadds   f1,f1,f0
    bge    .L___kernel_rem_pio2f_070c
.L___kernel_rem_pio2f_0720:
    stfs    f1,0(r26)
    mtcrf   128,r25
    beq    .L___kernel_rem_pio2f_0734
    fneg    f0,f1
    stfs    f0,0(r26)
.L___kernel_rem_pio2f_0734:
    lfs     f0,168(r1)
    cmpwi   r31,0
    fsubs   f1,f0,f1
    ble    .L___kernel_rem_pio2f_0760
    mr      r8,r31
    addi    r9,r1,172
.L___kernel_rem_pio2f_074c:
    lfs     f0,0(r9)
    addic.  r8,r8,-1
    addi    r9,r9,4
    fadds   f1,f1,f0
    bne    .L___kernel_rem_pio2f_074c
.L___kernel_rem_pio2f_0760:
    stfs    f1,4(r26)
    mtcrf   128,r25
    beq    .L___kernel_rem_pio2f_0860
    fneg    f0,f1
    b    .L___kernel_rem_pio2f_085c
.L___kernel_rem_pio2f_0774:
    mr.     r8,r31
    ble    .L___kernel_rem_pio2f_07b0
    addi    r9,r1,164
    slwi    r0,r8,2
    add     r9,r9,r0
.L___kernel_rem_pio2f_0788:
    lfs     f13,0(r9)
    addic.  r8,r8,-1
    lfs     f0,4(r9)
    fadds   f1,f13,f0
    fsubs   f13,f13,f1
    stfs    f1,0(r9)
    fadds   f0,f0,f13
    stfs    f0,4(r9)
    addi    r9,r9,-4
    bgt    .L___kernel_rem_pio2f_0788
.L___kernel_rem_pio2f_07b0:
    mr      r8,r31
    cmpwi   r8,1
    ble    .L___kernel_rem_pio2f_07f4
    addi    r9,r1,164
    slwi    r0,r8,2
    add     r9,r9,r0
.L___kernel_rem_pio2f_07c8:
    lfs     f13,0(r9)
    addi    r8,r8,-1
    lfs     f0,4(r9)
    cmpwi   r8,1
    fadds   f1,f13,f0
    fsubs   f13,f13,f1
    stfs    f1,0(r9)
    fadds   f0,f0,f13
    stfs    f0,4(r9)
    addi    r9,r9,-4
    bgt    .L___kernel_rem_pio2f_07c8
.L___kernel_rem_pio2f_07f4:
    mr      r8,r31
    lfs     f1,-28040(r13)
    cmpwi   r8,1
    lfs     f13,168(r1)
    ble    .L___kernel_rem_pio2f_082c
    addi    r9,r1,168
    slwi    r0,r8,2
    add     r9,r9,r0
.L___kernel_rem_pio2f_0814:
    lfs     f0,0(r9)
    addi    r8,r8,-1
    addi    r9,r9,-4
    cmpwi   r8,1
    fadds   f1,f1,f0
    bgt    .L___kernel_rem_pio2f_0814
.L___kernel_rem_pio2f_082c:
    mtcrf   128,r25
    bne    .L___kernel_rem_pio2f_0844
    lfs     f0,172(r1)
    stfs    f1,8(r26)
    stfs    f13,0(r26)
    b    .L___kernel_rem_pio2f_085c
.L___kernel_rem_pio2f_0844:
    lfs     f0,172(r1)
    fneg    f13,f13
    fneg    f12,f1
    stfs    f13,0(r26)
    fneg    f0,f0
    stfs    f12,8(r26)
.L___kernel_rem_pio2f_085c:
    stfs    f0,4(r26)
.L___kernel_rem_pio2f_0860:
    clrlwi  r3,r23,29
    lwz     r0,420(r1)
    lwz     r12,348(r1)
    mtlr    r0
    lmw     r18,352(r1)
    lfd     f31,408(r1)
    mtcrf   24,r12
    addi    r1,r1,416
    blr

# ---------------------------------------------------------------------------
# scalbnf @ 0x80242540, size=0x11c (284 bytes)
# ---------------------------------------------------------------------------
    .global scalbnf
scalbnf:
    stwu    r1,-16(r1)
    mflr    r0
    stw     r0,20(r1)
    fmr     f2,f1
    fmr     f0,f2
    stfs    f0,8(r1)
    lwz     r0,8(r1)
    mr      r11,r0
    rlwinm  r9,r11,9,24,31
    cmpwi   r9,0
    bne    .L_scalbnf_006c
    clrlwi. r0,r11,1
    beq    .L_scalbnf_010c
    lfs     f0,-28008(r13)
    fmuls   f2,f2,f0
    fmr     f0,f2
    stfs    f0,8(r1)
    lwz     r0,8(r1)
    mr      r11,r0
    rlwinm  r9,r11,9,24,31
    lis     r0,-1
    addi    r9,r9,-25
    ori     r0,r0,15536
    cmpw    r3,r0
    bge    .L_scalbnf_006c
    lfs     f1,-28004(r13)
    b    .L_scalbnf_0108
.L_scalbnf_006c:
    cmpwi   r9,255
    bne    .L_scalbnf_007c
    fadds   f1,f2,f2
    b    .L_scalbnf_010c
.L_scalbnf_007c:
    add     r9,r9,r3
    cmpwi   r9,254
    bgt    .L_scalbnf_00c4
    cmpwi   r9,0
    ble    .L_scalbnf_00ac
    slwi    r9,r9,23
    rlwinm  r0,r11,0,9,0
    or      r0,r0,r9
    stw     r0,8(r1)
    lfs     f2,8(r1)
    fmr     f1,f2
    b    .L_scalbnf_010c
.L_scalbnf_00ac:
    cmpwi   r9,-25
    bgt    .L_scalbnf_00ec
    li      r0,0
    ori     r0,r0,50000
    cmpw    r3,r0
    ble    .L_scalbnf_00d8
.L_scalbnf_00c4:
    lfs     f1,-28000(r13)
    bl    copysignf
    lfs     f0,-28000(r13)
    fmuls   f1,f1,f0
    b    .L_scalbnf_010c
.L_scalbnf_00d8:
    lfs     f1,-28004(r13)
    bl    copysignf
    lfs     f0,-28004(r13)
    fmuls   f1,f1,f0
    b    .L_scalbnf_010c
.L_scalbnf_00ec:
    addi    r9,r9,25
    rlwinm  r0,r11,0,9,0
    slwi    r9,r9,23
    or      r0,r0,r9
    stw     r0,8(r1)
    lfs     f2,8(r1)
    lfs     f1,-27996(r13)
.L_scalbnf_0108:
    fmuls   f1,f2,f1
.L_scalbnf_010c:
    lwz     r0,20(r1)
    mtlr    r0
    addi    r1,r1,16
    blr

# ---------------------------------------------------------------------------
# copysignf @ 0x8024265c, size=0x34 (52 bytes)
# ---------------------------------------------------------------------------
    .global copysignf
copysignf:
    stwu    r1,-16(r1)
    stfs    f1,8(r1)
    lwz     r9,8(r1)
    stfs    f2,8(r1)
    lwz     r0,8(r1)
    clrlwi  r9,r9,1
    clrrwi  r0,r0,31
    or      r9,r9,r0
    stw     r9,8(r1)
    lfs     f0,8(r1)
    fmr     f1,f0
    addi    r1,r1,16
    blr

# ---------------------------------------------------------------------------
# fmod @ 0x8036cf50, size=0x358 (856 bytes)
# ---------------------------------------------------------------------------
    .global fmod
fmod:
    stwu    r1,-32(r1)
    stmw    r28,16(r1)
    fmr     f0,f1
    stfd    f0,8(r1)
    lwz     r11,8(r1)
    lwz     r12,12(r1)
    mr      r7,r12
    fmr     f0,f2
    stfd    f0,8(r1)
    lwz     r9,8(r1)
    lwz     r10,12(r1)
    mr      r6,r10
    clrrwi  r3,r11,31
    clrlwi  r5,r9,1
    clrlwi  r8,r11,1
    or.     r0,r5,r6
    beq    .L_fmod_0070
    lis     r0,32751
    ori     r0,r0,65535
    cmpw    r8,r0
    bgt    .L_fmod_0070
    neg     r0,r6
    lis     r9,32752
    or      r0,r6,r0
    srwi    r0,r0,31
    or      r0,r5,r0
    cmplw   r0,r9
    ble    .L_fmod_007c
.L_fmod_0070:
    fmul    f1,f1,f2
    fdiv    f1,f1,f1
    b    .L_fmod_034c
.L_fmod_007c:
    cmpw    r8,r5
    bgt    .L_fmod_0098
    blt    .L_fmod_034c
    cmplw   r7,r6
    blt    .L_fmod_034c
    cmpw    r7,r6
    beq    .L_fmod_0314
.L_fmod_0098:
    lis     r0,15
    ori     r0,r0,65535
    cmpw    r8,r0
    bgt    .L_fmod_00ec
    cmpwi   r8,0
    bne    .L_fmod_00d0
    li      r10,-1043
    mr      r0,r7
    cmpwi   r7,0
    ble    .L_fmod_00f4
.L_fmod_00c0:
    addi    r10,r10,-1
    slwi.   r0,r0,1
    bgt    .L_fmod_00c0
    b    .L_fmod_00f4
.L_fmod_00d0:
    li      r10,-1022
    slwi.   r0,r8,11
    ble    .L_fmod_00f4
.L_fmod_00dc:
    addi    r10,r10,-1
    slwi.   r0,r0,1
    bgt    .L_fmod_00dc
    b    .L_fmod_00f4
.L_fmod_00ec:
    srawi   r9,r8,20
    addi    r10,r9,-1023
.L_fmod_00f4:
    lis     r0,15
    ori     r0,r0,65535
    cmpw    r5,r0
    bgt    .L_fmod_0150
    cmpwi   r5,0
    bne    .L_fmod_0130
    li      r4,-1043
    mr      r0,r6
    cmpwi   r6,0
    cmpwi   cr7,r10,-1022
    ble    .L_fmod_015c
.L_fmod_0120:
    addi    r4,r4,-1
    slwi.   r0,r0,1
    bgt    .L_fmod_0120
    b    .L_fmod_015c
.L_fmod_0130:
    li      r4,-1022
    cmpwi   cr7,r10,-1022
    slwi.   r0,r5,11
    ble    .L_fmod_015c
.L_fmod_0140:
    addi    r4,r4,-1
    slwi.   r0,r0,1
    bgt    .L_fmod_0140
    b    .L_fmod_015c
.L_fmod_0150:
    srawi   r9,r5,20
    cmpwi   cr7,r10,-1022
    addi    r4,r9,-1023
.L_fmod_015c:
    blt    cr7,.L_fmod_016c
    clrlwi  r0,r8,12
    oris    r8,r0,16
    b    .L_fmod_019c
.L_fmod_016c:
    subfic  r11,r10,-1022
    cmpwi   r11,31
    bgt    .L_fmod_0190
    subfic  r0,r11,32
    slw     r9,r8,r11
    srw     r0,r7,r0
    or      r8,r9,r0
    slw     r7,r7,r11
    b    .L_fmod_019c
.L_fmod_0190:
    addi    r0,r11,-32
    slw     r8,r7,r0
    li      r7,0
.L_fmod_019c:
    cmpwi   r4,-1022
    blt    .L_fmod_01b0
    clrlwi  r0,r5,12
    oris    r5,r0,16
    b    .L_fmod_01e0
.L_fmod_01b0:
    subfic  r11,r4,-1022
    cmpwi   r11,31
    bgt    .L_fmod_01d4
    subfic  r0,r11,32
    slw     r9,r5,r11
    srw     r0,r6,r0
    or      r5,r9,r0
    slw     r6,r6,r11
    b    .L_fmod_01e0
.L_fmod_01d4:
    addi    r0,r11,-32
    slw     r5,r6,r0
    li      r6,0
.L_fmod_01e0:
    subf    r11,r4,r10
    b    .L_fmod_0230
.L_fmod_01e8:
    subf    r9,r5,r8
    subf    r10,r6,r7
    cmplw   r7,r6
    bge    .L_fmod_01fc
    addi    r9,r9,-1
.L_fmod_01fc:
    cmpwi   r9,0
    bge    .L_fmod_0218
    srwi    r0,r7,31
    add     r9,r8,r8
    add     r8,r9,r0
    add     r7,r7,r7
    b    .L_fmod_0230
.L_fmod_0218:
    or.     r0,r9,r10
    beq    .L_fmod_0314
    add     r9,r9,r9
    srwi    r0,r10,31
    add     r8,r9,r0
    add     r7,r10,r10
.L_fmod_0230:
    mr      r0,r11
    cmpwi   r0,0
    addi    r11,r11,-1
    bne    .L_fmod_01e8
    subf    r9,r5,r8
    cmplw   r7,r6
    subf    r10,r6,r7
    bge    .L_fmod_0254
    addi    r9,r9,-1
.L_fmod_0254:
    cmpwi   r9,0
    blt    .L_fmod_0264
    mr      r8,r9
    mr      r7,r10
.L_fmod_0264:
    or.     r0,r8,r7
    beq    .L_fmod_0314
    lis     r0,15
    ori     r0,r0,65535
    cmpw    r8,r0
    bgt    .L_fmod_02a0
    lis     r11,15
    ori     r11,r11,65535
.L_fmod_0284:
    srwi    r0,r7,31
    add     r9,r8,r8
    add     r8,r9,r0
    add     r7,r7,r7
    addi    r4,r4,-1
    cmpw    r8,r11
    ble    .L_fmod_0284
.L_fmod_02a0:
    cmpwi   r4,-1022
    blt    .L_fmod_02d4
    addi    r0,r4,1023
    addis   r9,r8,-16
    slwi    r0,r0,20
    or      r8,r9,r0
    or      r30,r8,r3
    mr      r31,r7
    stw     r30,8(r1)
    stw     r31,12(r1)
    lfd     f0,8(r1)
    fmr     f1,f0
    b    .L_fmod_034c
.L_fmod_02d4:
    subfic  r11,r4,-1022
    cmpwi   r11,20
    bgt    .L_fmod_02f8
    subfic  r0,r11,32
    srw     r9,r7,r11
    slw     r0,r8,r0
    or      r7,r9,r0
    sraw    r8,r8,r11
    b    .L_fmod_0334
.L_fmod_02f8:
    cmpwi   r11,31
    bgt    .L_fmod_0328
    subfic  r0,r11,32
    srw     r9,r7,r11
    slw     r0,r8,r0
    or      r7,r0,r9
    b    .L_fmod_0330
.L_fmod_0314:
    srwi    r0,r3,31
    addi    r9,r13,-18416
    slwi    r0,r0,3
    lfdx    f1,r9,r0
    b    .L_fmod_034c
.L_fmod_0328:
    addi    r0,r11,-32
    sraw    r7,r8,r0
.L_fmod_0330:
    mr      r8,r3
.L_fmod_0334:
    or      r28,r8,r3
    mr      r29,r7
    stw     r28,8(r1)
    stw     r29,12(r1)
    lfd     f0,8(r1)
    fmr     f1,f0
.L_fmod_034c:
    lmw     r28,16(r1)
    addi    r1,r1,32
    blr

# ---------------------------------------------------------------------------
# asinf @ 0x8036d2a8, size=0x22c (556 bytes)
# ---------------------------------------------------------------------------
    .global asinf
asinf:
    stwu    r1,-48(r1)
    mflr    r0
    stfd    f29,24(r1)
    stfd    f30,32(r1)
    stfd    f31,40(r1)
    stmw    r30,16(r1)
    stw     r0,52(r1)
    fmr     f6,f1
    fmr     f0,f6
    stfs    f0,8(r1)
    lwz     r30,8(r1)
    clrlwi  r31,r30,1
    lis     r0,16256
    cmpw    r31,r0
    bne    .L_asinf_0050
    lfs     f1,-25804(r13)
    lfs     f0,-25808(r13)
    fmuls   f1,f6,f1
    fmadds  f1,f6,f0,f1
    b    .L_asinf_020c
.L_asinf_0050:
    ble    .L_asinf_0060
    fsubs   f1,f6,f6
    fdivs   f1,f1,f1
    b    .L_asinf_020c
.L_asinf_0060:
    lis     r0,16127
    ori     r0,r0,65535
    cmpw    r31,r0
    bgt    .L_asinf_0104
    lis     r0,12799
    ori     r0,r0,65535
    cmpw    r31,r0
    bgt    .L_asinf_00a0
    lfs     f0,-25800(r13)
    lfs     f13,-25796(r13)
    fadds   f0,f6,f0
    fcmpu   cr0,f0,f13
    fmr     f7,f13
    ble    .L_asinf_00a8
    fmr     f1,f6
    b    .L_asinf_020c
.L_asinf_00a0:
    lfs     f7,-25796(r13)
    fmuls   f31,f6,f6
.L_asinf_00a8:
    lfs     f13,-25788(r13)
    lfs     f0,-25792(r13)
    lfs     f12,-25784(r13)
    fmadds  f0,f31,f0,f13
    lfs     f11,-25780(r13)
    fmadds  f0,f31,f0,f12
    lfs     f13,-25768(r13)
    lfs     f10,-25764(r13)
    fmadds  f0,f31,f0,f11
    lfs     f9,-25776(r13)
    lfs     f8,-25760(r13)
    fmadds  f13,f31,f13,f10
    lfs     f11,-25772(r13)
    fmadds  f0,f31,f0,f9
    lfs     f12,-25756(r13)
    fmadds  f13,f31,f13,f8
    fmadds  f0,f31,f0,f11
    fmadds  f13,f31,f13,f12
    fmadds  f29,f31,f13,f7
    fmuls   f30,f31,f0
    fdivs   f7,f30,f29
    fmadds  f1,f6,f7,f6
    b    .L_asinf_020c
.L_asinf_0104:
    fmr     f1,f6
    bl    fabsf
    lfs     f8,-25796(r13)
    lfs     f0,-25752(r13)
    fsubs   f7,f8,f1
    lfs     f12,-25788(r13)
    lfs     f13,-25792(r13)
    fmuls   f31,f7,f0
    lfs     f10,-25784(r13)
    fmr     f1,f31
    fmadds  f13,f31,f13,f12
    lfs     f11,-25780(r13)
    lfs     f12,-25764(r13)
    fmadds  f13,f31,f13,f10
    lfs     f0,-25768(r13)
    fmadds  f13,f31,f13,f11
    lfs     f10,-25776(r13)
    fmadds  f0,f31,f0,f12
    lfs     f9,-25760(r13)
    lfs     f11,-25772(r13)
    fmadds  f13,f31,f13,f10
    lfs     f12,-25756(r13)
    fmadds  f0,f31,f0,f9
    fmadds  f13,f31,f13,f11
    fmadds  f0,f31,f0,f12
    fmadds  f29,f31,f0,f8
    fmuls   f30,f31,f13
    bl    sqrtf
    lis     r0,16249
    ori     r0,r0,39321
    cmpw    r31,r0
    ble    .L_asinf_01a4
    fdivs   f7,f30,f29
    lfs     f0,-25804(r13)
    lfs     f12,-25808(r13)
    fmadds  f13,f1,f7,f1
    fadds   f13,f13,f13
    fsubs   f13,f13,f0
    fsubs   f31,f12,f13
    b    .L_asinf_01f8
.L_asinf_01a4:
    stfs    f1,8(r1)
    lwz     r9,8(r1)
    mr      r0,r9
    clrrwi  r9,r0,12
    stw     r9,8(r1)
    lfs     f7,8(r1)
    fmuls   f0,f7,f7
    fsubs   f0,f31,f0
    lfs     f11,-25804(r13)
    fadds   f13,f1,f7
    lfs     f9,-25748(r13)
    fdivs   f0,f0,f13
    fdivs   f10,f30,f29
    fadds   f0,f0,f0
    fsubs   f11,f11,f0
    fadds   f13,f1,f1
    fadds   f12,f7,f7
    fmsubs  f30,f13,f10,f11
    fsubs   f29,f9,f12
    fsubs   f0,f30,f29
    fsubs   f31,f9,f0
.L_asinf_01f8:
    cmpwi   r30,0
    bgt    .L_asinf_0208
    fneg    f1,f31
    b    .L_asinf_020c
.L_asinf_0208:
    fmr     f1,f31
.L_asinf_020c:
    lwz     r0,52(r1)
    mtlr    r0
    lmw     r30,16(r1)
    lfd     f29,24(r1)
    lfd     f30,32(r1)
    lfd     f31,40(r1)
    addi    r1,r1,48
    blr

# ---------------------------------------------------------------------------
# expf @ 0x8036d4d4, size=0x22c (556 bytes)
# ---------------------------------------------------------------------------
    .global expf
expf:
    stwu    r1,-24(r1)
    fmr     f8,f1
    fmr     f0,f8
    stfs    f0,8(r1)
    lwz     r0,8(r1)
    mr      r9,r0
    srwi    r8,r9,31
    lis     r0,17073
    clrlwi  r9,r9,1
    ori     r0,r0,29207
    cmplw   r9,r0
    ble    .L_expf_0088
    lis     r0,32640
    cmplw   r9,r0
    ble    .L_expf_0044
    fadds   f1,f8,f8
    b    .L_expf_0224
.L_expf_0044:
    cmpw    r9,r0
    bne    .L_expf_0060
    cmpwi   r8,0
    lfs     f1,-25744(r13)
    bne    .L_expf_0224
    fmr     f1,f8
    b    .L_expf_0224
.L_expf_0060:
    lfs     f0,-25740(r13)
    fcmpu   cr0,f8,f0
    ble    .L_expf_0074
    lfs     f1,-25736(r13)
    b    .L_expf_0224
.L_expf_0074:
    lfs     f0,-25732(r13)
    fcmpu   cr0,f8,f0
    bge    .L_expf_0088
    lfs     f1,-25744(r13)
    b    .L_expf_0224
.L_expf_0088:
    lis     r0,16049
    ori     r0,r0,29208
    cmplw   r9,r0
    ble    .L_expf_0130
    lis     r0,16261
    ori     r0,r0,5521
    cmplw   r9,r0
    bgt    .L_expf_00cc
    slwi    r10,r8,2
    addi    r9,r13,-18312
    addi    r11,r13,-18304
    lfsx    f0,r9,r10
    subfic  r0,r8,1
    lfsx    f10,r11,r10
    fsubs   f7,f8,f0
    subf    r11,r8,r0
    b    .L_expf_0124
.L_expf_00cc:
    slwi    r0,r8,2
    addi    r9,r13,-18336
    lfsx    f13,r9,r0
    lfs     f0,-25728(r13)
    mr      r9,r11
    lis     r10,17200
    lfd     f11,-25720(r13)
    fmadds  f0,f8,f0,f13
    lfs     f10,-18304(r13)
    lfs     f13,-18312(r13)
    fctiwz  f12,f0
    stfd    f12,16(r1)
    lwz     r11,20(r1)
    xoris   r0,r11,32768
    stw     r0,20(r1)
    stw     r10,16(r1)
    lfd     f0,16(r1)
    fsub    f0,f0,f11
    frsp    f9,f0
    fmuls   f13,f9,f13
    fsubs   f7,f8,f13
    fmuls   f10,f9,f10
.L_expf_0124:
    fsubs   f8,f7,f10
    lfs     f6,-25708(r13)
    b    .L_expf_0168
.L_expf_0130:
    lis     r0,12671
    ori     r0,r0,65535
    cmplw   r9,r0
    bgt    .L_expf_0160
    lfs     f0,-25712(r13)
    lfs     f13,-25708(r13)
    fadds   f0,f8,f0
    fcmpu   cr0,f0,f13
    fmr     f6,f13
    ble    .L_expf_0168
    fadds   f1,f8,f6
    b    .L_expf_0224
.L_expf_0160:
    lfs     f6,-25708(r13)
    li      r11,0
.L_expf_0168:
    lfs     f13,-25700(r13)
    fmuls   f9,f8,f8
    lfs     f0,-25704(r13)
    cmpwi   r11,0
    lfs     f12,-25696(r13)
    fmadds  f0,f9,f0,f13
    lfs     f11,-25692(r13)
    fmadds  f0,f9,f0,f12
    lfs     f13,-25688(r13)
    fmadds  f0,f9,f0,f11
    fmadds  f0,f9,f0,f13
    fmuls   f0,f9,f0
    fsubs   f12,f8,f0
    bne    .L_expf_01bc
    lfs     f0,-25684(r13)
    fmuls   f1,f8,f12
    fsubs   f0,f12,f0
    fdivs   f1,f1,f0
    fsubs   f1,f1,f8
    fsubs   f1,f6,f1
    b    .L_expf_0224
.L_expf_01bc:
    lfs     f13,-25684(r13)
    fmuls   f0,f8,f12
    cmpwi   r11,-125
    fsubs   f13,f13,f12
    fdivs   f0,f0,f13
    fsubs   f0,f10,f0
    fsubs   f0,f0,f7
    fsubs   f0,f6,f0
    bge    .L_expf_0208
    stfs    f0,8(r1)
    addi    r0,r11,100
    slwi    r0,r0,23
    lfs     f1,-25680(r13)
    lwz     r9,8(r1)
    add     r9,r9,r0
    stw     r9,8(r1)
    lfs     f0,8(r1)
    fmuls   f1,f0,f1
    b    .L_expf_0224
.L_expf_0208:
    stfs    f0,8(r1)
    slwi    r0,r11,23
    lwz     r9,8(r1)
    add     r9,r9,r0
    stw     r9,8(r1)
    lfs     f0,8(r1)
    fmr     f1,f0
.L_expf_0224:
    addi    r1,r1,24
    blr

# ---------------------------------------------------------------------------
# logf @ 0x8036d700, size=0x280 (640 bytes)
# ---------------------------------------------------------------------------
    .global logf
logf:
    stwu    r1,-24(r1)
    fmr     f0,f1
    stfs    f0,8(r1)
    lwz     r0,8(r1)
    mr      r8,r0
    li      r7,0
    lis     r0,127
    ori     r0,r0,65535
    cmpw    r8,r0
    bgt    .L_logf_006c
    clrlwi. r0,r8,1
    bne    .L_logf_0038
    lfs     f1,-25672(r13)
    b    .L_logf_0278
.L_logf_0038:
    cmpwi   r8,0
    bge    .L_logf_0050
    lfs     f0,-25668(r13)
    fsubs   f1,f1,f1
    fdivs   f1,f1,f0
    b    .L_logf_0278
.L_logf_0050:
    lfs     f0,-25664(r13)
    li      r7,-25
    fmuls   f1,f1,f0
    fmr     f0,f1
    stfs    f0,8(r1)
    lwz     r0,8(r1)
    mr      r8,r0
.L_logf_006c:
    lis     r0,32639
    ori     r0,r0,65535
    cmpw    r8,r0
    ble    .L_logf_0084
    fadds   f1,f1,f1
    b    .L_logf_0278
.L_logf_0084:
    srawi   r11,r8,23
    addi    r0,r7,-127
    clrlwi  r8,r8,9
    add     r7,r0,r11
    addis   r9,r8,75
    addi    r9,r9,-1248
    rlwinm  r11,r9,0,8,8
    xoris   r0,r11,16256
    or      r0,r8,r0
    stw     r0,8(r1)
    lfs     f1,8(r1)
    srawi   r9,r11,23
    lfs     f0,-25660(r13)
    addi    r0,r8,15
    clrlwi  r0,r0,9
    add     r7,r7,r9
    fsubs   f3,f1,f0
    cmpwi   r0,15
    bgt    .L_logf_017c
    lfs     f1,-25668(r13)
    fcmpu   cr0,f3,f1
    bne    .L_logf_0118
    cmpwi   r7,0
    beq    .L_logf_0278
    xoris   r0,r7,32768
    stw     r0,20(r1)
    lis     r11,17200
    lfd     f13,-25656(r13)
    stw     r11,16(r1)
    lfs     f1,-25644(r13)
    lfd     f0,16(r1)
    lfs     f12,-25648(r13)
    fsub    f0,f0,f13
    frsp    f11,f0
    fmuls   f1,f11,f1
    fmadds  f1,f11,f12,f1
    b    .L_logf_0278
.L_logf_0118:
    lfs     f0,-25640(r13)
    fmuls   f12,f3,f3
    lfs     f13,-25636(r13)
    cmpwi   r7,0
    fmuls   f0,f3,f0
    fsubs   f13,f13,f0
    fmuls   f9,f12,f13
    bne    .L_logf_0140
    fsubs   f1,f3,f9
    b    .L_logf_0278
.L_logf_0140:
    xoris   r0,r7,32768
    stw     r0,20(r1)
    lis     r11,17200
    lfd     f13,-25656(r13)
    stw     r11,16(r1)
    lfs     f1,-25644(r13)
    lfd     f0,16(r1)
    lfs     f12,-25648(r13)
    fsub    f0,f0,f13
    frsp    f11,f0
    fmuls   f1,f11,f1
    fsubs   f1,f9,f1
    fsubs   f1,f1,f3
    fmsubs  f1,f11,f12,f1
    b    .L_logf_0278
.L_logf_017c:
    lfs     f0,-25632(r13)
    xoris   r0,r7,32768
    lis     r10,17200
    fadds   f0,f3,f0
    stw     r0,20(r1)
    fdivs   f2,f3,f0
    lfs     f11,-25616(r13)
    lfs     f4,-25612(r13)
    lis     r0,53
    stw     r10,16(r1)
    addis   r11,r8,-49
    lfs     f5,-25608(r13)
    ori     r0,r0,49800
    lfs     f10,-25628(r13)
    subf    r0,r8,r0
    lfs     f6,-25624(r13)
    addi    r11,r11,23600
    lfs     f7,-25604(r13)
    or.     r10,r11,r0
    lfd     f9,-25656(r13)
    lfd     f12,16(r1)
    lfs     f8,-25620(r13)
    fmuls   f13,f2,f2
    fmuls   f0,f13,f13
    fmadds  f11,f0,f11,f4
    fmadds  f11,f0,f11,f5
    fmadds  f11,f0,f11,f7
    fmadds  f10,f0,f10,f6
    fmuls   f13,f13,f11
    fsub    f12,f12,f9
    fmadds  f10,f0,f10,f8
    fmadds  f9,f0,f10,f13
    frsp    f11,f12
    ble    .L_logf_0244
    lfs     f0,-25636(r13)
    cmpwi   r7,0
    fmuls   f0,f3,f0
    fmuls   f10,f0,f3
    bne    .L_logf_0228
    fadds   f1,f10,f9
    fmuls   f1,f2,f1
    fsubs   f1,f10,f1
    b    .L_logf_0274
.L_logf_0228:
    lfs     f0,-25644(r13)
    fadds   f1,f10,f9
    lfs     f13,-25648(r13)
    fmuls   f0,f11,f0
    fmadds  f1,f2,f1,f0
    fsubs   f1,f10,f1
    b    .L_logf_0260
.L_logf_0244:
    cmpwi   r7,0
    beq    .L_logf_026c
    lfs     f0,-25644(r13)
    fsubs   f1,f3,f9
    lfs     f13,-25648(r13)
    fmuls   f0,f11,f0
    fmsubs  f1,f2,f1,f0
.L_logf_0260:
    fsubs   f1,f1,f3
    fmsubs  f1,f11,f13,f1
    b    .L_logf_0278
.L_logf_026c:
    fsubs   f1,f3,f9
    fmuls   f1,f2,f1
.L_logf_0274:
    fsubs   f1,f3,f1
.L_logf_0278:
    addi    r1,r1,24
    blr

# ---------------------------------------------------------------------------
# log10f @ 0x8036d980, size=0x10c (268 bytes)
# ---------------------------------------------------------------------------
    .global log10f
log10f:
    stwu    r1,-32(r1)
    mflr    r0
    stfd    f31,24(r1)
    stw     r0,36(r1)
    fmr     f0,f1
    stfs    f0,8(r1)
    lwz     r0,8(r1)
    mr      r8,r0
    li      r9,0
    lis     r0,127
    ori     r0,r0,65535
    cmpw    r8,r0
    bgt    .L_log10f_0078
    clrlwi. r0,r8,1
    bne    .L_log10f_0044
    lfs     f1,-25600(r13)
    b    .L_log10f_00f8
.L_log10f_0044:
    cmpwi   r8,0
    bge    .L_log10f_005c
    lfs     f0,-25596(r13)
    fsubs   f1,f1,f1
    fdivs   f1,f1,f0
    b    .L_log10f_00f8
.L_log10f_005c:
    lfs     f0,-25592(r13)
    li      r9,-25
    fmuls   f1,f1,f0
    fmr     f0,f1
    stfs    f0,8(r1)
    lwz     r0,8(r1)
    mr      r8,r0
.L_log10f_0078:
    lis     r0,32639
    ori     r0,r0,65535
    cmpw    r8,r0
    bgt    .L_log10f_00f4
    srawi   r0,r8,23
    addi    r9,r9,-127
    add     r9,r9,r0
    srwi    r0,r9,31
    lis     r10,17200
    add     r9,r9,r0
    lfd     f0,-25584(r13)
    xoris   r9,r9,32768
    subfic  r0,r0,127
    stw     r9,20(r1)
    slwi    r0,r0,23
    rlwimi  r8,r0,0,0,8
    stw     r10,16(r1)
    stw     r8,8(r1)
    lfd     f31,16(r1)
    lfs     f13,8(r1)
    fsub    f31,f31,f0
    frsp    f31,f31
    fmr     f1,f13
    bl    logf
    lfs     f13,-25572(r13)
    lfs     f0,-25576(r13)
    fmuls   f1,f1,f13
    lfs     f12,-25568(r13)
    fmadds  f0,f31,f0,f1
    fmadds  f1,f31,f12,f0
    b    .L_log10f_00f8
.L_log10f_00f4:
    fadds   f1,f1,f1
.L_log10f_00f8:
    lwz     r0,36(r1)
    mtlr    r0
    lfd     f31,24(r1)
    addi    r1,r1,32
    blr

# ---------------------------------------------------------------------------
# powf @ 0x8036da8c, size=0x6f4 (1780 bytes)
# ---------------------------------------------------------------------------
    .global powf
powf:
    stwu    r1,-64(r1)
    mflr    r0
    mfcr    r12
    stfd    f30,48(r1)
    stfd    f31,56(r1)
    stmw    r27,28(r1)
    stw     r0,68(r1)
    stw     r12,24(r1)
    fmr     f30,f2
    fmr     f31,f1
    fmr     f0,f31
    stfs    f0,8(r1)
    lwz     r28,8(r1)
    fmr     f12,f30
    stfs    f12,8(r1)
    lwz     r29,8(r1)
    clrlwi  r31,r28,1
    clrlwi. r30,r29,1
    bne    .L_powf_0054
    lfs     f1,-25560(r13)
    b    .L_powf_06d0
.L_powf_0054:
    lis     r0,32640
    cmpw    r31,r0
    bgt    .L_powf_0068
    cmpw    r30,r0
    ble    .L_powf_0070
.L_powf_0068:
    fadds   f1,f31,f30
    b    .L_powf_06d0
.L_powf_0070:
    li      r27,0
    cmpwi   cr4,r28,0
    bge    cr4,.L_powf_00c4
    lis     r0,19327
    ori     r0,r0,65535
    cmpw    r30,r0
    ble    .L_powf_0094
    li      r27,2
    b    .L_powf_00c4
.L_powf_0094:
    lis     r0,16255
    ori     r0,r0,65535
    cmpw    r30,r0
    ble    .L_powf_00c4
    srawi   r0,r30,23
    subfic  r0,r0,150
    sraw    r10,r30,r0
    slw     r0,r10,r0
    cmpw    r0,r30
    bne    .L_powf_00c4
    clrlwi  r0,r10,31
    subfic  r27,r0,2
.L_powf_00c4:
    lis     r0,32640
    cmpw    r30,r0
    bne    .L_powf_0110
    lis     r0,16256
    cmpw    r31,r0
    bne    .L_powf_00e4
    fsubs   f1,f30,f30
    b    .L_powf_06d0
.L_powf_00e4:
    ble    .L_powf_00fc
    cmpwi   r29,0
    lfs     f1,-25556(r13)
    blt    .L_powf_06d0
    fmr     f1,f30
    b    .L_powf_06d0
.L_powf_00fc:
    cmpwi   r29,0
    lfs     f1,-25556(r13)
    bge    .L_powf_06d0
    fneg    f1,f30
    b    .L_powf_06d0
.L_powf_0110:
    lis     r0,16256
    cmpw    r30,r0
    bne    .L_powf_0138
    cmpwi   r29,0
    bge    .L_powf_0130
    lfs     f1,-25560(r13)
    fdivs   f1,f1,f31
    b    .L_powf_06d0
.L_powf_0130:
    fmr     f1,f31
    b    .L_powf_06d0
.L_powf_0138:
    lis     r0,16384
    cmpw    r29,r0
    bne    .L_powf_014c
    fmuls   f1,f31,f31
    b    .L_powf_06d0
.L_powf_014c:
    lis     r0,16128
    cmpw    r29,r0
    bne    .L_powf_0168
    blt    cr4,.L_powf_0168
    fmr     f1,f31
    bl    sqrtf
    b    .L_powf_06d0
.L_powf_0168:
    fmr     f1,f31
    bl    fabsf
    lis     r0,32640
    cmpw    r31,r0
    beq    .L_powf_0190
    cmpwi   r31,0
    beq    .L_powf_0190
    lis     r0,16256
    cmpw    r31,r0
    bne    .L_powf_01d4
.L_powf_0190:
    fmr     f2,f1
    cmpwi   r29,0
    bge    .L_powf_01a4
    lfs     f0,-25560(r13)
    fdivs   f2,f0,f2
.L_powf_01a4:
    bge    cr4,.L_powf_01cc
    addis   r0,r31,-16256
    or.     r9,r0,r27
    bne    .L_powf_01c0
    fsubs   f0,f2,f2
    fdivs   f2,f0,f0
    b    .L_powf_01cc
.L_powf_01c0:
    cmpwi   r27,1
    bne    .L_powf_01cc
    fneg    f2,f2
.L_powf_01cc:
    fmr     f1,f2
    b    .L_powf_06d0
.L_powf_01d4:
    srwi    r9,r28,31
    mr      r6,r9
    addi    r9,r9,-1
    or.     r10,r9,r27
    bne    .L_powf_01f4
    fsubs   f1,f31,f31
    fdivs   f1,f1,f1
    b    .L_powf_06d0
.L_powf_01f4:
    lis     r0,19712
    cmpw    r30,r0
    ble    .L_powf_02b4
    lis     r0,16255
    ori     r0,r0,65527
    cmpw    r31,r0
    bgt    .L_powf_0224
    cmpwi   r29,0
    lfs     f1,-25556(r13)
    bge    .L_powf_06d0
    lfs     f1,-25552(r13)
    b    .L_powf_06d0
.L_powf_0224:
    lis     r0,16256
    ori     r0,r0,7
    cmpw    r31,r0
    ble    .L_powf_0248
    cmpwi   r29,0
    lfs     f1,-25556(r13)
    ble    .L_powf_06d0
    lfs     f1,-25552(r13)
    b    .L_powf_06d0
.L_powf_0248:
    lfs     f9,-25560(r13)
    lfs     f13,-25548(r13)
    fsubs   f1,f31,f9
    lfs     f0,-25544(r13)
    fmuls   f13,f1,f13
    lfs     f12,-25540(r13)
    fsubs   f0,f0,f13
    lfs     f11,-25528(r13)
    fmuls   f0,f1,f0
    lfs     f10,-25536(r13)
    fsubs   f12,f12,f0
    lfs     f13,-25532(r13)
    fmuls   f0,f1,f1
    fmuls   f0,f0,f12
    fmuls   f11,f0,f11
    fmsubs  f4,f1,f13,f11
    fmuls   f5,f1,f10
    fadds   f0,f5,f4
    stfs    f0,8(r1)
    lwz     r0,8(r1)
    clrrwi  r11,r0,12
    stw     r11,8(r1)
    lfs     f12,8(r1)
    fsubs   f0,f12,f5
    fsubs   f0,f4,f0
    fmr     f7,f9
    b    .L_powf_04c0
.L_powf_02b4:
    lis     r0,127
    li      r3,0
    ori     r0,r0,65535
    cmpw    r31,r0
    bgt    .L_powf_02e0
    lfs     f0,-25524(r13)
    li      r3,-24
    fmuls   f1,f1,f0
    stfs    f1,8(r1)
    lwz     r0,8(r1)
    mr      r31,r0
.L_powf_02e0:
    lis     r0,28
    srawi   r9,r31,23
    clrlwi  r10,r31,9
    addi    r11,r3,-127
    ori     r0,r0,50289
    add     r3,r11,r9
    cmpw    r10,r0
    oris    r31,r10,16256
    bgt    .L_powf_030c
    li      r7,0
    b    .L_powf_032c
.L_powf_030c:
    lis     r0,93
    li      r7,1
    ori     r0,r0,46038
    cmpw    r10,r0
    ble    .L_powf_032c
    li      r7,0
    addi    r3,r3,1
    addis   r31,r31,-128
.L_powf_032c:
    stw     r31,8(r1)
    lfs     f13,8(r1)
    fmr     f1,f13
    slwi    r8,r7,2
    addi    r9,r13,-18208
    lfs     f7,-25560(r13)
    lfsx    f13,r9,r8
    fadds   f0,f1,f13
    fdivs   f4,f7,f0
    fsubs   f5,f1,f13
    fmuls   f31,f5,f4
    fmr     f0,f31
    stfs    f0,8(r1)
    lwz     r0,8(r1)
    clrrwi  r9,r0,12
    stw     r9,8(r1)
    lfs     f9,8(r1)
    srawi   r11,r31,1
    slwi    r9,r7,21
    oris    r11,r11,8192
    addis   r9,r9,4
    add     r0,r11,r9
    stw     r0,8(r1)
    lfs     f0,8(r1)
    fsubs   f13,f0,f13
    lfs     f10,-25516(r13)
    fmuls   f6,f31,f31
    lfs     f12,-25520(r13)
    fmuls   f11,f9,f0
    lfs     f8,-25512(r13)
    fsubs   f1,f1,f13
    fmadds  f12,f6,f12,f10
    lfs     f0,-25544(r13)
    fmadds  f12,f6,f12,f8
    lfs     f13,-25508(r13)
    fmadds  f12,f6,f12,f0
    lfs     f8,-25504(r13)
    fmuls   f0,f9,f1
    lfs     f10,-25500(r13)
    fmadds  f12,f6,f12,f13
    fsubs   f11,f5,f11
    fmadds  f12,f6,f12,f8
    fsubs   f11,f11,f0
    fmuls   f8,f6,f6
    fmuls   f11,f4,f11
    fadds   f13,f9,f31
    fmuls   f13,f11,f13
    fmuls   f6,f9,f9
    fmadds  f1,f8,f12,f13
    fadds   f0,f6,f10
    fadds   f0,f0,f1
    stfs    f0,8(r1)
    lwz     r0,8(r1)
    clrrwi  r0,r0,12
    stw     r0,8(r1)
    lfs     f12,8(r1)
    fsubs   f10,f12,f10
    fsubs   f10,f10,f6
    fsubs   f1,f1,f10
    fmuls   f0,f1,f31
    fmadds  f4,f11,f12,f0
    fmuls   f5,f9,f12
    fadds   f13,f5,f4
    stfs    f13,8(r1)
    lwz     r0,8(r1)
    clrrwi  r9,r0,12
    stw     r9,8(r1)
    lfs     f6,8(r1)
    fsubs   f13,f6,f5
    xoris   r0,r3,32768
    lfs     f0,-25488(r13)
    fsubs   f9,f4,f13
    stw     r0,20(r1)
    lis     r9,17200
    fmuls   f0,f9,f0
    addi    r11,r13,-18192
    lfs     f11,-25492(r13)
    stw     r9,16(r1)
    lfsx    f9,r11,r8
    fmadds  f11,f6,f11,f0
    lfs     f10,-25496(r13)
    addi    r9,r13,-18200
    fadds   f11,f11,f9
    lfd     f13,16(r1)
    lfd     f12,-25480(r13)
    fmuls   f10,f6,f10
    lfsx    f9,r9,r8
    fadds   f0,f10,f11
    fsub    f13,f13,f12
    frsp    f1,f13
    fadds   f0,f0,f9
    fadds   f0,f0,f1
    stfs    f0,8(r1)
    lwz     r0,8(r1)
    clrrwi  r11,r0,12
    stw     r11,8(r1)
    lfs     f12,8(r1)
    fsubs   f0,f12,f1
    fsubs   f0,f0,f9
    fsubs   f0,f0,f10
    fsubs   f0,f11,f0
.L_powf_04c0:
    addi    r9,r6,-1
    addi    r0,r27,-1
    or.     r10,r9,r0
    fmr     f31,f7
    bne    .L_powf_04d8
    lfs     f31,-25472(r13)
.L_powf_04d8:
    fmr     f12,f30
    stfs    f12,8(r1)
    lwz     r0,8(r1)
    clrrwi  r9,r0,12
    stw     r9,8(r1)
    lfs     f12,8(r1)
    stw     r11,8(r1)
    fsubs   f13,f30,f12
    lfs     f12,8(r1)
    fmuls   f0,f30,f0
    stw     r9,8(r1)
    fmadds  f9,f13,f12,f0
    lfs     f13,8(r1)
    fmuls   f6,f13,f12
    fadds   f2,f9,f6
    fmr     f0,f2
    stfs    f0,8(r1)
    lwz     r8,8(r1)
    mr      r10,r8
    lis     r0,17152
    cmpw    r10,r0
    ble    .L_powf_0538
    lfs     f0,-25468(r13)
    b    .L_powf_0588
.L_powf_0538:
    bne    .L_powf_0558
    lfs     f0,-25464(r13)
    fsubs   f13,f2,f6
    fadds   f0,f9,f0
    fcmpu   cr0,f0,f13
    ble    .L_powf_0594
    lfs     f0,-25468(r13)
    b    .L_powf_0588
.L_powf_0558:
    lis     r9,17174
    clrlwi  r0,r10,1
    cmpw    r0,r9
    bgt    .L_powf_0584
    lis     r0,-15594
    cmpw    r10,r0
    bne    .L_powf_0594
    fsubs   f0,f2,f6
    fcmpu   cr0,f9,f0
    cror    so,eq,lt
    bns    .L_powf_0594
.L_powf_0584:
    lfs     f0,-25460(r13)
.L_powf_0588:
    fmuls   f1,f31,f0
    fmuls   f1,f1,f0
    b    .L_powf_06d0
.L_powf_0594:
    clrlwi  r0,r10,1
    lis     r9,16128
    srawi   r11,r0,23
    cmpw    r0,r9
    li      r3,0
    ble    .L_powf_05fc
    addi    r9,r11,-126
    lis     r0,128
    sraw    r0,r0,r9
    add     r3,r8,r0
    rlwinm  r9,r3,9,24,31
    addi    r7,r9,-127
    lis     r0,127
    ori     r0,r0,65535
    sraw    r0,r0,r7
    andc    r0,r3,r0
    stw     r0,8(r1)
    lfs     f1,8(r1)
    clrlwi  r9,r3,9
    oris    r9,r9,128
    subfic  r0,r7,23
    sraw    r3,r9,r0
    cmpwi   r8,0
    bge    .L_powf_05f8
    neg     r3,r3
.L_powf_05f8:
    fsubs   f6,f6,f1
.L_powf_05fc:
    fadds   f12,f9,f6
    stfs    f12,8(r1)
    lwz     r0,8(r1)
    clrrwi  r9,r0,12
    stw     r9,8(r1)
    lfs     f1,8(r1)
    lfs     f8,-25456(r13)
    lfs     f12,-25448(r13)
    fsubs   f13,f1,f6
    lfs     f11,-25452(r13)
    fmuls   f12,f1,f12
    lfs     f0,-25444(r13)
    fsubs   f13,f9,f13
    lfs     f10,-25436(r13)
    fmadds  f4,f13,f11,f12
    lfs     f9,-25440(r13)
    fmuls   f5,f1,f8
    lfs     f11,-25432(r13)
    fadds   f2,f5,f4
    lfs     f12,-25428(r13)
    fmuls   f1,f2,f2
    lfs     f13,-25424(r13)
    fmadds  f0,f1,f0,f9
    fmadds  f0,f1,f0,f10
    fmadds  f0,f1,f0,f11
    fmadds  f0,f1,f0,f12
    fmuls   f0,f1,f0
    fsubs   f0,f2,f0
    fsubs   f13,f0,f13
    stfs    f0,8(r1)
    fmuls   f12,f2,f0
    fdivs   f12,f12,f13
    fsubs   f0,f2,f5
    fsubs   f0,f4,f0
    fmadds  f13,f2,f0,f0
    fsubs   f1,f12,f13
    fsubs   f0,f1,f2
    fsubs   f2,f7,f0
    fmr     f12,f2
    stfs    f12,8(r1)
    lwz     r9,8(r1)
    slwi    r0,r3,23
    add     r10,r9,r0
    srawi.  r0,r10,23
    bgt    .L_powf_06c0
    fmr     f1,f2
    bl    scalbnf
    fmr     f2,f1
    b    .L_powf_06cc
.L_powf_06c0:
    stw     r10,8(r1)
    lfs     f0,8(r1)
    fmr     f2,f0
.L_powf_06cc:
    fmuls   f1,f31,f2
.L_powf_06d0:
    lwz     r0,68(r1)
    lwz     r12,24(r1)
    mtlr    r0
    lmw     r27,28(r1)
    lfd     f30,48(r1)
    lfd     f31,56(r1)
    mtcrf   8,r12
    addi    r1,r1,64
    blr

# ---------------------------------------------------------------------------
# modff @ 0x8036e180, size=0xa0 (160 bytes)
# ---------------------------------------------------------------------------
    .global modff
modff:
    stwu    r1,-16(r1)
    stfs    f1,8(r1)
    lwz     r8,8(r1)
    mr      r10,r8
    mr      r11,r10
    rlwinm  r9,r11,9,24,31
    addi    r9,r9,-127
    cmpwi   r9,22
    bgt    .L_modff_0084
    cmpwi   r9,0
    bge    .L_modff_0038
    clrrwi  r0,r11,31
    stw     r0,0(r3)
    b    .L_modff_0098
.L_modff_0038:
    lis     r0,127
    ori     r0,r0,65535
    sraw    r0,r0,r9
    and.    r9,r11,r0
    bne    .L_modff_0064
    stw     r8,0(r3)
    clrrwi  r8,r11,31
    stw     r8,8(r1)
    lfs     f0,8(r1)
    fmr     f1,f0
    b    .L_modff_0098
.L_modff_0064:
    andc    r0,r10,r0
    stw     r0,0(r3)
    stw     r8,8(r1)
    lfs     f13,8(r1)
    stw     r0,8(r1)
    lfs     f0,8(r1)
    fsubs   f1,f13,f0
    b    .L_modff_0098
.L_modff_0084:
    stw     r8,0(r3)
    clrrwi  r8,r10,31
    stw     r8,8(r1)
    lfs     f13,8(r1)
    fmr     f1,f13
.L_modff_0098:
    addi    r1,r1,16
    blr
