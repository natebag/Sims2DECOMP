# DolphinSDK hardware libraries - Medium functions (65-256 bytes)
# Auto-generated from ELF disassembly
# Libraries: exi.a, si.a, dvd.a, vi.a, pad.a, ai.a, mtx.a, gx.a, db.a

.section .text

# ============================================================
# exi.a
# ============================================================

#
# === EXIBios.o ===
#

.global SetExiInterruptMask
.balign 4
SetExiInterruptMask:
/* 0x8025639C | size=0xF4 (244 bytes) */
    mflr    r0
    stw     r0,4(r1)
    stwu    r1,-24(r1)
    stw     r31,20(r1)
    addi    r31,r4,0
    lis     r4,-32694
    addi    r4,r4,-22064
    addi    r4,r4,128
    cmpwi   r3,1
    beq-    .L_8025641C
    bge-    .L_802563D4
    cmpwi   r3,0
    bge-    .L_802563E0
    b       .L_8025647C
.L_802563D4:
    cmpwi   r3,3
    bge-    .L_8025647C
    b       .L_8025644C
.L_802563E0:
    lwz     r0,0(r31)
    cmplwi  r0,0
    bne-    .L_802563F8
    lwz     r0,0(r4)
    cmplwi  r0,0
    beq-    .L_80256404
.L_802563F8:
    lwz     r0,12(r31)
    rlwinm. r0,r0,0,27,27
    beq-    .L_80256410
.L_80256404:
    lis     r3,65
    bl      __OSMaskInterrupts
    b       .L_8025647C
.L_80256410:
    lis     r3,65
    bl      __OSUnmaskInterrupts
    b       .L_8025647C
.L_8025641C:
    lwz     r0,0(r31)
    cmplwi  r0,0
    beq-    .L_80256434
    lwz     r0,12(r31)
    rlwinm. r0,r0,0,27,27
    beq-    .L_80256440
.L_80256434:
    lis     r3,8
    bl      __OSMaskInterrupts
    b       .L_8025647C
.L_80256440:
    lis     r3,8
    bl      __OSUnmaskInterrupts
    b       .L_8025647C
.L_8025644C:
    li      r3,25
    bl      __OSGetInterruptHandler
    cmplwi  r3,0
    beq-    .L_80256468
    lwz     r0,12(r31)
    rlwinm. r0,r0,0,27,27
    beq-    .L_80256474
.L_80256468:
    li      r3,64
    bl      __OSMaskInterrupts
    b       .L_8025647C
.L_80256474:
    li      r3,64
    bl      __OSUnmaskInterrupts
.L_8025647C:
    lwz     r0,28(r1)
    lwz     r31,20(r1)
    addi    r1,r1,24
    mtlr    r0
    blr
.size SetExiInterruptMask, . - SetExiInterruptMask

.global EXIImmEx
.balign 4
EXIImmEx:
/* 0x80256840 | size=0xA0 (160 bytes) */
    mflr    r0
    stw     r0,4(r1)
    stwu    r1,-48(r1)
    stmw    r27,28(r1)
    addi    r27,r3,0
    addi    r28,r4,0
    addi    r29,r5,0
    addi    r30,r6,0
    b       .L_802568C0
.L_80256864:
    cmpwi   r29,4
    bge-    .L_80256874
    mr      r31,r29
    b       .L_80256878
.L_80256874:
    li      r31,4
.L_80256878:
    addi    r5,r31,0
    addi    r3,r27,0
    addi    r4,r28,0
    addi    r6,r30,0
    li      r7,0
    bl      EXIImm
    cmpwi   r3,0
    bne-    .L_802568A0
    li      r3,0
    b       .L_802568CC
.L_802568A0:
    mr      r3,r27
    bl      EXISync
    cmpwi   r3,0
    bne-    .L_802568B8
    li      r3,0
    b       .L_802568CC
.L_802568B8:
    add     r28,r28,r31
    subf    r29,r31,r29
.L_802568C0:
    cmpwi   r29,0
    bne+    .L_80256864
    li      r3,1
.L_802568CC:
    lwz     r0,52(r1)
    lmw     r27,28(r1)
    addi    r1,r1,48
    mtlr    r0
    blr
.size EXIImmEx, . - EXIImmEx

.global EXIDma
.balign 4
EXIDma:
/* 0x802568E0 | size=0xEC (236 bytes) */
    mflr    r0
    stw     r0,4(r1)
    stwu    r1,-64(r1)
    stmw    r25,36(r1)
    addi    r27,r3,0
    addi    r28,r4,0
    addi    r29,r5,0
    addi    r30,r6,0
    addi    r25,r7,0
    slwi    r4,r3,6
    lis     r3,-32694
    addi    r0,r3,-22064
    add     r26,r0,r4
    bl      OSDisableInterrupts
    mr      r31,r3
    lwz     r0,12(r26)
    clrlwi. r0,r0,30
    bne-    .L_80256934
    lwz     r0,12(r26)
    rlwinm. r0,r0,0,29,29
    bne-    .L_80256944
.L_80256934:
    mr      r3,r31
    bl      OSRestoreInterrupts
    li      r3,0
    b       .L_802569B8
.L_80256944:
    stw     r25,4(r26)
    lwz     r0,4(r26)
    cmplwi  r0,0
    beq-    .L_80256978
    addi    r3,r27,0
    li      r4,0
    li      r5,1
    li      r6,0
    bl      EXIClearInterrupts
    lis     r3,32
    mulli   r0,r27,3
    srw     r3,r3,r0
    bl      __OSUnmaskInterrupts
.L_80256978:
    lwz     r0,12(r26)
    ori     r0,r0,1
    stw     r0,12(r26)
    rlwinm  r4,r28,0,6,26
    lis     r3,-13312
    addi    r0,r3,26624
    mulli   r3,r27,20
    add     r3,r0,r3
    stw     r4,4(r3)
    stw     r29,8(r3)
    slwi    r0,r30,2
    ori     r0,r0,3
    stw     r0,12(r3)
    mr      r3,r31
    bl      OSRestoreInterrupts
    li      r3,1
.L_802569B8:
    lwz     r0,68(r1)
    lmw     r25,36(r1)
    addi    r1,r1,64
    mtlr    r0
    blr
.size EXIDma, . - EXIDma

.global EXIClearInterrupts
.balign 4
EXIClearInterrupts:
/* 0x80256C18 | size=0x48 (72 bytes) */
    mulli   r0,r3,20
    lis     r3,-13312
    addi    r7,r3,26624
    add     r7,r7,r0
    lwz     r0,0(r7)
    mr      r3,r0
    andi.   r0,r0,2037
    cmpwi   r4,0
    beq-    .L_80256C40
    ori     r0,r0,2
.L_80256C40:
    cmpwi   r5,0
    beq-    .L_80256C4C
    ori     r0,r0,8
.L_80256C4C:
    cmpwi   r6,0
    beq-    .L_80256C58
    ori     r0,r0,2048
.L_80256C58:
    stw     r0,0(r7)
    blr
.size EXIClearInterrupts, . - EXIClearInterrupts

.global EXISetExiCallback
.balign 4
EXISetExiCallback:
/* 0x80256C60 | size=0x7C (124 bytes) */
    mflr    r0
    stw     r0,4(r1)
    stwu    r1,-40(r1)
    stmw    r26,16(r1)
    addi    r26,r3,0
    addi    r27,r4,0
    slwi    r0,r3,6
    lis     r3,-32694
    addi    r31,r3,-22064
    add     r30,r31,r0
    bl      OSDisableInterrupts
    mr      r28,r3
    lwz     r29,0(r30)
    stw     r27,0(r30)
    cmpwi   r26,2
    beq-    .L_80256CB0
    addi    r3,r26,0
    addi    r4,r30,0
    bl      SetExiInterruptMask
    b       .L_80256CBC
.L_80256CB0:
    li      r3,0
    addi    r4,r31,0
    bl      SetExiInterruptMask
.L_80256CBC:
    mr      r3,r28
    bl      OSRestoreInterrupts
    mr      r3,r29
    lwz     r0,44(r1)
    lmw     r26,16(r1)
    addi    r1,r1,40
    mtlr    r0
    blr
.size EXISetExiCallback, . - EXISetExiCallback

.global EXIProbeReset
.balign 4
EXIProbeReset:
/* 0x80256CDC | size=0x4C (76 bytes) */
    mflr    r0
    stw     r0,4(r1)
    stwu    r1,-8(r1)
    li      r0,0
    lis     r4,-32768
    stw     r0,12484(r4)
    stw     r0,12480(r4)
    lis     r3,-32694
    addi    r3,r3,-22064
    stw     r0,96(r3)
    stw     r0,32(r3)
    li      r3,0
    bl      __EXIProbe
    li      r3,1
    bl      __EXIProbe
    lwz     r0,12(r1)
    addi    r1,r1,8
    mtlr    r0
    blr
.size EXIProbeReset, . - EXIProbeReset

.global EXIProbe
.balign 4
EXIProbe:
/* 0x80256E9C | size=0x80 (128 bytes) */
    mflr    r0
    stw     r0,4(r1)
    stwu    r1,-24(r1)
    stw     r31,20(r1)
    stw     r30,16(r1)
    addi    r30,r3,0
    slwi    r4,r3,6
    lis     r3,-32694
    addi    r0,r3,-22064
    add     r31,r0,r4
    addi    r3,r30,0
    bl      __EXIProbe
    cmpwi   r3,0
    beq-    .L_80256F04
    lwz     r0,32(r31)
    cmpwi   r0,0
    bne-    .L_80256F04
    addi    r3,r30,0
    li      r4,0
    addi    r5,r1,12
    bl      EXIGetID
    cmpwi   r3,0
    beq-    .L_80256F00
    li      r3,1
    b       .L_80256F04
.L_80256F00:
    li      r3,0
.L_80256F04:
    lwz     r0,28(r1)
    lwz     r31,20(r1)
    lwz     r30,16(r1)
    addi    r1,r1,24
    mtlr    r0
    blr
.size EXIProbe, . - EXIProbe

.global EXIProbeEx
.balign 4
EXIProbeEx:
/* 0x80256F1C | size=0xB4 (180 bytes) */
    mflr    r0
    stw     r0,4(r1)
    stwu    r1,-24(r1)
    stw     r31,20(r1)
    stw     r30,16(r1)
    addi    r30,r3,0
    slwi    r4,r3,6
    lis     r3,-32694
    addi    r0,r3,-22064
    add     r31,r0,r4
    addi    r3,r30,0
    bl      __EXIProbe
    cmpwi   r3,0
    beq-    .L_80256F84
    lwz     r0,32(r31)
    cmpwi   r0,0
    bne-    .L_80256F84
    addi    r3,r30,0
    li      r4,0
    addi    r5,r1,12
    bl      EXIGetID
    cmpwi   r3,0
    beq-    .L_80256F80
    li      r3,1
    b       .L_80256F84
.L_80256F80:
    li      r3,0
.L_80256F84:
    cmpwi   r3,0
    beq-    .L_80256F94
    li      r3,1
    b       .L_80256FB8
.L_80256F94:
    slwi    r0,r30,2
    lis     r3,-32768
    addi    r3,r3,12480
    lwzx    r0,r3,r0
    cmpwi   r0,0
    beq-    .L_80256FB4
    li      r3,0
    b       .L_80256FB8
.L_80256FB4:
    li      r3,-1
.L_80256FB8:
    lwz     r0,28(r1)
    lwz     r31,20(r1)
    lwz     r30,16(r1)
    addi    r1,r1,24
    mtlr    r0
    blr
.size EXIProbeEx, . - EXIProbeEx

.global __EXIAttach
.balign 4
__EXIAttach:
/* 0x80256FD0 | size=0xD4 (212 bytes) */
    mflr    r0
    stw     r0,4(r1)
    stwu    r1,-40(r1)
    stw     r31,36(r1)
    stw     r30,32(r1)
    stw     r29,28(r1)
    stw     r28,24(r1)
    addi    r28,r3,0
    addi    r29,r4,0
    slwi    r4,r3,6
    lis     r3,-32694
    addi    r0,r3,-22064
    add     r31,r0,r4
    bl      OSDisableInterrupts
    mr      r30,r3
    lwz     r0,12(r31)
    rlwinm. r0,r0,0,28,28
    bne-    .L_80257028
    mr      r3,r28
    bl      __EXIProbe
    cmpwi   r3,0
    bne-    .L_80257038
.L_80257028:
    mr      r3,r30
    bl      OSRestoreInterrupts
    li      r3,0
    b       .L_80257084
.L_80257038:
    mulli   r0,r28,20
    lis     r3,-13312
    addi    r3,r3,26624
    add     r3,r3,r0
    lwz     r0,0(r3)
    andi.   r0,r0,2037
    ori     r0,r0,2
    stw     r0,0(r3)
    stw     r29,8(r31)
    lis     r3,16
    mulli   r0,r28,3
    srw     r3,r3,r0
    bl      __OSUnmaskInterrupts
    lwz     r0,12(r31)
    ori     r0,r0,8
    stw     r0,12(r31)
    mr      r3,r30
    bl      OSRestoreInterrupts
    li      r3,1
.L_80257084:
    lwz     r0,44(r1)
    lwz     r31,36(r1)
    lwz     r30,32(r1)
    lwz     r29,28(r1)
    lwz     r28,24(r1)
    addi    r1,r1,40
    mtlr    r0
    blr
.size __EXIAttach, . - __EXIAttach

.global EXIDetach
.balign 4
EXIDetach:
/* 0x802571B0 | size=0xBC (188 bytes) */
    mflr    r0
    stw     r0,4(r1)
    stwu    r1,-32(r1)
    stw     r31,28(r1)
    stw     r30,24(r1)
    stw     r29,20(r1)
    addi    r29,r3,0
    slwi    r4,r3,6
    lis     r3,-32694
    addi    r0,r3,-22064
    add     r31,r0,r4
    bl      OSDisableInterrupts
    mr      r30,r3
    lwz     r0,12(r31)
    rlwinm. r0,r0,0,28,28
    bne-    .L_80257200
    mr      r3,r30
    bl      OSRestoreInterrupts
    li      r3,1
    b       .L_80257250
.L_80257200:
    lwz     r0,12(r31)
    rlwinm. r0,r0,0,27,27
    beq-    .L_80257228
    lwz     r0,24(r31)
    cmplwi  r0,0
    bne-    .L_80257228
    mr      r3,r30
    bl      OSRestoreInterrupts
    li      r3,0
    b       .L_80257250
.L_80257228:
    lwz     r0,12(r31)
    rlwinm  r0,r0,0,29,27
    stw     r0,12(r31)
    lis     r3,80
    mulli   r0,r29,3
    srw     r3,r3,r0
    bl      __OSMaskInterrupts
    mr      r3,r30
    bl      OSRestoreInterrupts
    li      r3,1
.L_80257250:
    lwz     r0,36(r1)
    lwz     r31,28(r1)
    lwz     r30,24(r1)
    lwz     r29,20(r1)
    addi    r1,r1,32
    mtlr    r0
    blr
.size EXIDetach, . - EXIDetach

.global EXIIntrruptHandler
.balign 4
EXIIntrruptHandler:
/* 0x802575FC | size=0xC8 (200 bytes) */
    mflr    r0
    stw     r0,4(r1)
    stwu    r1,-760(r1)
    stw     r31,756(r1)
    stw     r30,752(r1)
    stw     r29,748(r1)
    addi    r31,r4,0
    extsh   r3,r3
    addi    r0,r3,-9
    lis     r3,21845
    addi    r3,r3,21846
    mulhw   r3,r3,r0
    srwi    r0,r3,31
    add     r30,r3,r0
    mulli   r0,r30,20
    lis     r3,-13312
    addi    r3,r3,26624
    add     r3,r3,r0
    lwz     r0,0(r3)
    andi.   r0,r0,2037
    ori     r0,r0,2
    stw     r0,0(r3)
    slwi    r4,r30,6
    lis     r3,-32694
    addi    r0,r3,-22064
    add     r3,r0,r4
    lwz     r0,0(r3)
    mr      r29,r0
    cmplwi  r0,0
    beq-    .L_802576A8
    addi    r3,r1,24
    bl      OSClearContext
    addi    r3,r1,24
    bl      OSSetCurrentContext
    addi    r3,r30,0
    addi    r4,r31,0
    addi    r12,r29,0
    mtlr    r12
    blrl
    addi    r3,r1,24
    bl      OSClearContext
    mr      r3,r31
    bl      OSSetCurrentContext
.L_802576A8:
    lwz     r0,764(r1)
    lwz     r31,756(r1)
    lwz     r30,752(r1)
    lwz     r29,748(r1)
    addi    r1,r1,760
    mtlr    r0
    blr
.size EXIIntrruptHandler, . - EXIIntrruptHandler

.global EXTIntrruptHandler
.balign 4
EXTIntrruptHandler:
/* 0x802578DC | size=0xD0 (208 bytes) */
    mflr    r0
    stw     r0,4(r1)
    stwu    r1,-744(r1)
    stw     r31,740(r1)
    stw     r30,736(r1)
    stw     r29,732(r1)
    stw     r28,728(r1)
    addi    r31,r4,0
    extsh   r3,r3
    addi    r0,r3,-11
    lis     r3,21845
    addi    r3,r3,21846
    mulhw   r3,r3,r0
    srwi    r0,r3,31
    add     r30,r3,r0
    lis     r3,80
    mulli   r0,r30,3
    srw     r3,r3,r0
    bl      __OSMaskInterrupts
    slwi    r4,r30,6
    lis     r3,-32694
    addi    r0,r3,-22064
    add     r29,r0,r4
    lwz     r28,8(r29)
    lwz     r0,12(r29)
    rlwinm  r0,r0,0,29,27
    stw     r0,12(r29)
    cmplwi  r28,0
    beq-    .L_8025798C
    addi    r3,r1,16
    bl      OSClearContext
    addi    r3,r1,16
    bl      OSSetCurrentContext
    li      r0,0
    stw     r0,8(r29)
    addi    r3,r30,0
    addi    r4,r31,0
    addi    r12,r28,0
    mtlr    r12
    blrl
    addi    r3,r1,16
    bl      OSClearContext
    mr      r3,r31
    bl      OSSetCurrentContext
.L_8025798C:
    lwz     r0,748(r1)
    lwz     r31,740(r1)
    lwz     r30,736(r1)
    lwz     r29,732(r1)
    lwz     r28,728(r1)
    addi    r1,r1,744
    mtlr    r0
    blr
.size EXTIntrruptHandler, . - EXTIntrruptHandler

.global EXILock
.balign 4
EXILock:
/* 0x80257B80 | size=0xF4 (244 bytes) */
    mflr    r0
    stw     r0,4(r1)
    stwu    r1,-48(r1)
    stmw    r27,28(r1)
    addi    r27,r3,0
    addi    r31,r4,0
    addi    r28,r5,0
    slwi    r4,r3,6
    lis     r3,-32694
    addi    r0,r3,-22064
    add     r30,r0,r4
    bl      OSDisableInterrupts
    mr      r29,r3
    lwz     r0,12(r30)
    rlwinm. r0,r0,0,27,27
    beq-    .L_80257C38
    cmplwi  r28,0
    beq-    .L_80257C28
    mr      r3,r30
    lwz     r4,36(r30)
    mtctr   r4
    cmpwi   r4,0
    ble-    .L_80257C00
.L_80257BDC:
    lwz     r0,40(r3)
    cmplw   r0,r31
    bne-    .L_80257BF8
    mr      r3,r29
    bl      OSRestoreInterrupts
    li      r3,0
    b       .L_80257C60
.L_80257BF8:
    addi    r3,r3,8
    bdnz+   .L_80257BDC
.L_80257C00:
    slwi    r0,r4,3
    add     r3,r30,r0
    stw     r28,44(r3)
    lwz     r0,36(r30)
    slwi    r0,r0,3
    add     r3,r30,r0
    stw     r31,40(r3)
    lwz     r3,36(r30)
    addi    r0,r3,1
    stw     r0,36(r30)
.L_80257C28:
    mr      r3,r29
    bl      OSRestoreInterrupts
    li      r3,0
    b       .L_80257C60
.L_80257C38:
    lwz     r0,12(r30)
    ori     r0,r0,16
    stw     r0,12(r30)
    stw     r31,24(r30)
    addi    r3,r27,0
    addi    r4,r30,0
    bl      SetExiInterruptMask
    mr      r3,r29
    bl      OSRestoreInterrupts
    li      r3,1
.L_80257C60:
    lwz     r0,52(r1)
    lmw     r27,28(r1)
    addi    r1,r1,48
    mtlr    r0
    blr
.size EXILock, . - EXILock

.global EXIUnlock
.balign 4
EXIUnlock:
/* 0x80257C74 | size=0xDC (220 bytes) */
    mflr    r0
    stw     r0,4(r1)
    stwu    r1,-32(r1)
    stw     r31,28(r1)
    stw     r30,24(r1)
    stw     r29,20(r1)
    stw     r28,16(r1)
    addi    r28,r3,0
    slwi    r4,r3,6
    lis     r3,-32694
    addi    r0,r3,-22064
    add     r31,r0,r4
    bl      OSDisableInterrupts
    mr      r30,r3
    lwz     r0,12(r31)
    rlwinm. r0,r0,0,27,27
    bne-    .L_80257CC8
    mr      r3,r30
    bl      OSRestoreInterrupts
    li      r3,0
    b       .L_80257D30
.L_80257CC8:
    lwz     r0,12(r31)
    rlwinm  r0,r0,0,28,26
    stw     r0,12(r31)
    addi    r3,r28,0
    addi    r4,r31,0
    bl      SetExiInterruptMask
    lwz     r3,36(r31)
    cmpwi   r3,0
    ble-    .L_80257D24
    lwz     r29,44(r31)
    addic.  r0,r3,-1
    stw     r0,36(r31)
    ble-    .L_80257D10
    addi    r3,r31,40
    addi    r4,r31,48
    lwz     r0,36(r31)
    slwi    r5,r0,3
    bl      memmove
.L_80257D10:
    addi    r3,r28,0
    li      r4,0
    addi    r12,r29,0
    mtlr    r12
    blrl
.L_80257D24:
    mr      r3,r30
    bl      OSRestoreInterrupts
    li      r3,1
.L_80257D30:
    lwz     r0,36(r1)
    lwz     r31,28(r1)
    lwz     r30,24(r1)
    lwz     r29,20(r1)
    lwz     r28,16(r1)
    addi    r1,r1,32
    mtlr    r0
    blr
.size EXIUnlock, . - EXIUnlock

#
# === EXIUart.o ===
#

.global InitializeUART
.balign 4
InitializeUART:
/* 0x802587D4 | size=0x70 (112 bytes) */
    mflr    r0
    stw     r0,4(r1)
    stwu    r1,-8(r1)
    lwz     r3,-23548(r13)
    addis   r0,r3,23041
    cmplwi  r0,90
    bne-    .L_802587F8
    li      r3,0
    b       .L_80258834
.L_802587F8:
    bl      OSGetConsoleType
    rlwinm. r0,r3,0,3,3
    bne-    .L_80258814
    li      r0,0
    stw     r0,-23552(r13)
    li      r3,2
    b       .L_80258834
.L_80258814:
    lis     r3,-23041
    addi    r0,r3,90
    li      r3,0
    stw     r0,-23552(r13)
    li      r0,1
    stw     r3,-23560(r13)
    li      r3,0
    stw     r0,-23556(r13)
.L_80258834:
    lwz     r0,12(r1)
    addi    r1,r1,8
    mtlr    r0
    blr
.size InitializeUART, . - InitializeUART

.global QueueLength
.balign 4
QueueLength:
/* 0x8025884C | size=0x98 (152 bytes) */
    mflr    r0
    li      r5,3
    stw     r0,4(r1)
    stwu    r1,-16(r1)
    lwz     r3,-23560(r13)
    lwz     r4,-23556(r13)
    bl      EXISelect
    cmpwi   r3,0
    bne-    .L_80258878
    li      r3,-1
    b       .L_802588D4
.L_80258878:
    lis     r0,8193
    lwz     r3,-23560(r13)
    stw     r0,8(r1)
    addi    r4,r1,8
    li      r5,4
    li      r6,1
    li      r7,0
    bl      EXIImm
    lwz     r3,-23560(r13)
    bl      EXISync
    lwz     r3,-23560(r13)
    addi    r4,r1,8
    li      r5,1
    li      r6,0
    li      r7,0
    bl      EXIImm
    lwz     r3,-23560(r13)
    bl      EXISync
    lwz     r3,-23560(r13)
    bl      EXIDeselect
    lwz     r0,8(r1)
    srwi    r0,r0,24
    subfic  r3,r0,16
.L_802588D4:
    lwz     r0,20(r1)
    addi    r1,r1,16
    mtlr    r0
    blr
.size QueueLength, . - QueueLength

# ============================================================
# si.a
# ============================================================

#
# === SIBios.o ===
#

.global SITransferNext
.balign 4
SITransferNext:
/* 0x80258E58 | size=0xF0 (240 bytes) */
    mflr    r0
    lis     r4,-32694
    stw     r0,4(r1)
    stwu    r1,-32(r1)
    stw     r31,28(r1)
    addi    r31,r4,-21872
    stw     r30,24(r1)
    stw     r29,20(r1)
    li      r29,0
    stw     r28,16(r1)
    addi    r28,r3,0
.L_80258E84:
    addi    r28,r28,1
    srawi   r0,r28,2
    addze   r0,r0
    slwi    r0,r0,2
    subfc   r0,r0,r28
    mr      r28,r0
    slwi    r0,r0,5
    add     r30,r31,r0
    lwz     r0,0(r30)
    cmpwi   r0,-1
    beq-    .L_80258F1C
    bl      __OSGetSystemTime
    lwz     r0,24(r30)
    xoris   r5,r3,32768
    lwz     r6,28(r30)
    xoris   r3,r0,32768
    subfc   r0,r6,r4
    subfe   r3,r3,r5
    subfe   r3,r5,r5
    neg.    r3,r3
    bne-    .L_80258F1C
    lwz     r3,0(r30)
    lwz     r4,4(r30)
    lwz     r5,8(r30)
    lwz     r6,12(r30)
    lwz     r7,16(r30)
    lwz     r8,20(r30)
    bl      __SITransfer
    cmpwi   r3,0
    beq-    .L_80258F28
    mulli   r4,r28,40
    lis     r3,-32694
    addi    r0,r3,-21744
    add     r3,r0,r4
    bl      OSCancelAlarm
    li      r0,-1
    stw     r0,0(r30)
    b       .L_80258F28
.L_80258F1C:
    addi    r29,r29,1
    cmpwi   r29,4
    blt+    .L_80258E84
.L_80258F28:
    lwz     r0,36(r1)
    lwz     r31,28(r1)
    lwz     r30,24(r1)
    lwz     r29,20(r1)
    lwz     r28,16(r1)
    addi    r1,r1,32
    mtlr    r0
    blr
.size SITransferNext, . - SITransferNext

.global SIEnablePollingInterrupt
.balign 4
SIEnablePollingInterrupt:
/* 0x8025928C | size=0x98 (152 bytes) */
    mflr    r0
    lis     r4,-32694
    stw     r0,4(r1)
    stwu    r1,-48(r1)
    stw     r31,44(r1)
    addi    r31,r4,-21872
    stw     r30,40(r1)
    stw     r29,36(r1)
    addi    r29,r3,0
    bl      OSDisableInterrupts
    lis     r4,-13312
    lwzu    r5,25652(r4)
    rlwinm. r0,r5,0,4,4
    beq-    .L_802592CC
    li      r30,1
    b       .L_802592D0
.L_802592CC:
    li      r30,0
.L_802592D0:
    cmpwi   r29,0
    beq-    .L_802592F4
    li      r0,0
    stw     r0,480(r31)
    oris    r5,r5,2048
    stw     r0,484(r31)
    stw     r0,488(r31)
    stw     r0,492(r31)
    b       .L_802592F8
.L_802592F4:
    rlwinm  r5,r5,0,5,3
.L_802592F8:
    rlwinm  r5,r5,0,1,30
    stw     r5,0(r4)
    bl      OSRestoreInterrupts
    mr      r3,r30
    lwz     r0,52(r1)
    lwz     r31,44(r1)
    lwz     r30,40(r1)
    lwz     r29,36(r1)
    addi    r1,r1,48
    mtlr    r0
    blr
.size SIEnablePollingInterrupt, . - SIEnablePollingInterrupt

.global SIRegisterPollingHandler
.balign 4
SIRegisterPollingHandler:
/* 0x80259324 | size=0xCC (204 bytes) */
    mflr    r0
    stw     r0,4(r1)
    stwu    r1,-24(r1)
    stw     r31,20(r1)
    stw     r30,16(r1)
    mr      r30,r3
    bl      OSDisableInterrupts
    lis     r4,-32694
    li      r0,4
    addi    r4,r4,-21456
    mtctr   r0
    addi    r31,r3,0
    addi    r3,r4,0
.L_80259358:
    lwz     r0,0(r3)
    cmplw   r0,r30
    bne-    .L_80259374
    mr      r3,r31
    bl      OSRestoreInterrupts
    li      r3,1
    b       .L_802593D8
.L_80259374:
    addi    r3,r3,4
    bdnz+   .L_80259358
    li      r0,4
    mtctr   r0
    li      r5,0
.L_80259388:
    lwz     r0,0(r4)
    cmplwi  r0,0
    bne-    .L_802593C0
    lis     r3,-32694
    slwi    r4,r5,2
    addi    r0,r3,-21456
    add     r3,r0,r4
    stw     r30,0(r3)
    li      r3,1
    bl      SIEnablePollingInterrupt
    mr      r3,r31
    bl      OSRestoreInterrupts
    li      r3,1
    b       .L_802593D8
.L_802593C0:
    addi    r4,r4,4
    addi    r5,r5,1
    bdnz+   .L_80259388
    mr      r3,r31
    bl      OSRestoreInterrupts
    li      r3,0
.L_802593D8:
    lwz     r0,28(r1)
    lwz     r31,20(r1)
    lwz     r30,16(r1)
    addi    r1,r1,24
    mtlr    r0
    blr
.size SIRegisterPollingHandler, . - SIRegisterPollingHandler

.global SIUnregisterPollingHandler
.balign 4
SIUnregisterPollingHandler:
/* 0x802593F0 | size=0xF4 (244 bytes) */
    mflr    r0
    stw     r0,4(r1)
    stwu    r1,-24(r1)
    stw     r31,20(r1)
    stw     r30,16(r1)
    mr      r30,r3
    bl      OSDisableInterrupts
    lis     r4,-32694
    li      r0,4
    addi    r5,r4,-21456
    mtctr   r0
    addi    r31,r3,0
    addi    r3,r5,0
    li      r4,0
.L_80259428:
    lwz     r0,0(r3)
    cmplw   r0,r30
    bne-    .L_802594B4
    lis     r3,-32694
    slwi    r4,r4,2
    addi    r0,r3,-21456
    add     r3,r0,r4
    li      r0,0
    stw     r0,0(r3)
    li      r4,0
    lwz     r0,0(r5)
    cmplwi  r0,0
    bne-    .L_80259494
    addi    r3,r5,4
    lwz     r0,4(r5)
    li      r4,1
    cmplwi  r0,0
    bne-    .L_80259494
    lwzu    r0,4(r3)
    li      r4,2
    cmplwi  r0,0
    bne-    .L_80259494
    lwz     r0,4(r3)
    li      r4,3
    cmplwi  r0,0
    bne-    .L_80259494
    li      r4,4
.L_80259494:
    cmpwi   r4,4
    bne-    .L_802594A4
    li      r3,0
    bl      SIEnablePollingInterrupt
.L_802594A4:
    mr      r3,r31
    bl      OSRestoreInterrupts
    li      r3,1
    b       .L_802594CC
.L_802594B4:
    addi    r3,r3,4
    addi    r4,r4,1
    bdnz+   .L_80259428
    mr      r3,r31
    bl      OSRestoreInterrupts
    li      r3,0
.L_802594CC:
    lwz     r0,28(r1)
    lwz     r31,20(r1)
    lwz     r30,16(r1)
    addi    r1,r1,24
    mtlr    r0
    blr
.size SIUnregisterPollingHandler, . - SIUnregisterPollingHandler

.global SIInit
.balign 4
SIInit:
/* 0x802594E4 | size=0xB4 (180 bytes) */
    mflr    r0
    lis     r4,-32694
    stw     r0,4(r1)
    stwu    r1,-16(r1)
    stw     r31,12(r1)
    addi    r31,r4,-21872
    lwz     r3,-27832(r13)
    bl      OSRegisterVersion
    li      r5,-1
    stw     r5,96(r31)
    lis     r3,-32700
    addi    r4,r3,-15972
    stw     r5,64(r31)
    li      r0,0
    li      r3,0
    stw     r5,32(r31)
    stw     r5,0(r31)
    stw     r0,4(r4)
    bl      SISetSamplingRate
    lis     r3,-13312
.L_80259534:
    addi    r4,r3,25600
    lwzu    r0,52(r4)
    clrlwi. r0,r0,31
    bne+    .L_80259534
    lis     r0,-32768
    lis     r3,-32730
    stw     r0,0(r4)
    addi    r4,r3,-28856
    li      r3,20
    bl      __OSSetInterruptHandler
    li      r3,2048
    bl      __OSUnmaskInterrupts
    li      r3,0
    bl      SIGetType
    li      r3,1
    bl      SIGetType
    li      r3,2
    bl      SIGetType
    li      r3,3
    bl      SIGetType
    lwz     r0,20(r1)
    lwz     r31,12(r1)
    addi    r1,r1,16
    mtlr    r0
    blr
.size SIInit, . - SIInit

.global SIGetStatus
.balign 4
SIGetStatus:
/* 0x802598AC | size=0x7C (124 bytes) */
    mflr    r0
    stw     r0,4(r1)
    stwu    r1,-24(r1)
    stw     r31,20(r1)
    stw     r30,16(r1)
    mr      r30,r3
    bl      OSDisableInterrupts
    lis     r4,-13312
    subfic  r0,r30,3
    lwz     r31,25656(r4)
    slwi    r0,r0,3
    srw     r31,r31,r0
    rlwinm. r0,r31,0,28,28
    beq-    .L_80259908
    lis     r4,-32700
    slwi    r5,r30,2
    addi    r0,r4,-15952
    add     r4,r0,r5
    lwz     r0,0(r4)
    rlwinm. r0,r0,0,24,24
    bne-    .L_80259908
    li      r0,8
    stw     r0,0(r4)
.L_80259908:
    bl      OSRestoreInterrupts
    mr      r3,r31
    lwz     r0,28(r1)
    lwz     r31,20(r1)
    lwz     r30,16(r1)
    addi    r1,r1,24
    mtlr    r0
    blr
.size SIGetStatus, . - SIGetStatus

.global SISetXY
.balign 4
SISetXY:
/* 0x80259960 | size=0x6C (108 bytes) */
    mflr    r0
    stw     r0,4(r1)
    slwi    r0,r4,8
    stwu    r1,-24(r1)
    stw     r31,20(r1)
    slwi    r31,r3,16
    or      r31,r31,r0
    bl      OSDisableInterrupts
    lis     r4,-32700
    addi    r4,r4,-15972
    lwz     r0,4(r4)
    addi    r5,r4,4
    lis     r4,-13312
    rlwinm  r0,r0,0,24,5
    stw     r0,0(r5)
    lwz     r0,0(r5)
    or      r0,r0,r31
    stw     r0,0(r5)
    lwz     r31,0(r5)
    stw     r31,25648(r4)
    bl      OSRestoreInterrupts
    mr      r3,r31
    lwz     r0,28(r1)
    lwz     r31,20(r1)
    addi    r1,r1,24
    mtlr    r0
    blr
.size SISetXY, . - SISetXY

.global SIEnablePolling
.balign 4
SIEnablePolling:
/* 0x802599CC | size=0x9C (156 bytes) */
    mflr    r0
    stw     r0,4(r1)
    stwu    r1,-24(r1)
    stw     r31,20(r1)
    mr.     r31,r3
    bne-    .L_802599F4
    lis     r3,-32700
    addi    r3,r3,-15972
    lwz     r3,4(r3)
    b       .L_80259A54
.L_802599F4:
    bl      OSDisableInterrupts
    lis     r4,-32700
    addi    r4,r4,-15972
    srwi    r31,r31,24
    lwz     r0,4(r4)
    addi    r5,r4,4
    rlwinm  r4,r31,28,28,31
    andc    r0,r0,r4
    stw     r0,0(r5)
    oris    r0,r4,1023
    ori     r0,r0,65520
    and     r31,r31,r0
    lwz     r0,0(r5)
    rlwinm  r31,r31,0,24,5
    or      r0,r0,r31
    stw     r0,0(r5)
    lis     r4,-13312
    addi    r4,r4,25600
    lwz     r31,0(r5)
    lis     r0,-32768
    stw     r0,56(r4)
    stw     r31,48(r4)
    bl      OSRestoreInterrupts
    mr      r3,r31
.L_80259A54:
    lwz     r0,28(r1)
    lwz     r31,20(r1)
    addi    r1,r1,24
    mtlr    r0
    blr
.size SIEnablePolling, . - SIEnablePolling

.global SIDisablePolling
.balign 4
SIDisablePolling:
/* 0x80259A68 | size=0x6C (108 bytes) */
    mflr    r0
    stw     r0,4(r1)
    stwu    r1,-24(r1)
    stw     r31,20(r1)
    mr.     r31,r3
    bne-    .L_80259A90
    lis     r3,-32700
    addi    r3,r3,-15972
    lwz     r3,4(r3)
    b       .L_80259AC0
.L_80259A90:
    bl      OSDisableInterrupts
    lis     r4,-32700
    addi    r4,r4,-15972
    lwz     r0,4(r4)
    rlwinm  r31,r31,8,24,27
    addi    r5,r4,4
    lis     r4,-13312
    andc    r31,r0,r31
    stw     r31,25648(r4)
    stw     r31,0(r5)
    bl      OSRestoreInterrupts
    mr      r3,r31
.L_80259AC0:
    lwz     r0,28(r1)
    lwz     r31,20(r1)
    addi    r1,r1,24
    mtlr    r0
    blr
.size SIDisablePolling, . - SIDisablePolling

.global SIGetResponseRaw
.balign 4
SIGetResponseRaw:
/* 0x80259AD4 | size=0xD4 (212 bytes) */
    mflr    r0
    lis     r4,-32694
    stw     r0,4(r1)
    stwu    r1,-40(r1)
    stw     r31,36(r1)
    addi    r31,r4,-21872
    stw     r30,32(r1)
    addi    r30,r3,0
    stw     r29,28(r1)
    bl      OSDisableInterrupts
    lis     r4,-13312
    subfic  r0,r30,3
    lwz     r29,25656(r4)
    slwi    r0,r0,3
    srw     r29,r29,r0
    rlwinm. r0,r29,0,28,28
    beq-    .L_80259B3C
    lis     r4,-32700
    slwi    r5,r30,2
    addi    r0,r4,-15952
    add     r4,r0,r5
    lwz     r0,0(r4)
    rlwinm. r0,r0,0,24,24
    bne-    .L_80259B3C
    li      r0,8
    stw     r0,0(r4)
.L_80259B3C:
    bl      OSRestoreInterrupts
    rlwinm. r0,r29,0,26,26
    beq-    .L_80259B88
    mulli   r4,r30,12
    lis     r3,-13312
    addi    r0,r3,25600
    add     r3,r0,r4
    slwi    r4,r30,3
    lwz     r0,4(r3)
    add     r6,r31,r4
    stw     r0,448(r6)
    slwi    r0,r30,2
    add     r4,r31,r0
    lwz     r5,8(r3)
    li      r0,1
    li      r3,1
    stw     r5,452(r6)
    stw     r0,432(r4)
    b       .L_80259B8C
.L_80259B88:
    li      r3,0
.L_80259B8C:
    lwz     r0,44(r1)
    lwz     r31,36(r1)
    lwz     r30,32(r1)
    lwz     r29,28(r1)
    addi    r1,r1,40
    mtlr    r0
    blr
.size SIGetResponseRaw, . - SIGetResponseRaw

.global SIGetResponse
.balign 4
SIGetResponse:
/* 0x80259BA8 | size=0xC4 (196 bytes) */
    mflr    r0
    lis     r5,-32694
    stw     r0,4(r1)
    stwu    r1,-40(r1)
    stmw    r27,20(r1)
    addi    r29,r3,0
    addi    r30,r4,0
    addi    r28,r5,-21872
    bl      OSDisableInterrupts
    addi    r31,r3,0
    addi    r3,r29,0
    bl      SIGetStatus
    rlwinm. r0,r3,0,26,26
    beq-    .L_80259C18
    mulli   r4,r29,12
    lis     r3,-13312
    addi    r0,r3,25600
    add     r4,r0,r4
    slwi    r3,r29,3
    lwz     r0,4(r4)
    add     r5,r28,r3
    stw     r0,448(r5)
    slwi    r0,r29,2
    add     r3,r28,r0
    lwz     r4,8(r4)
    li      r0,1
    stw     r4,452(r5)
    stw     r0,432(r3)
.L_80259C18:
    slwi    r0,r29,2
    add     r3,r28,r0
    lwz     r27,432(r3)
    li      r0,0
    cmpwi   r27,0
    stw     r0,432(r3)
    beq-    .L_80259C4C
    slwi    r0,r29,3
    add     r3,r28,r0
    lwz     r0,448(r3)
    stw     r0,0(r30)
    lwz     r0,452(r3)
    stw     r0,4(r30)
.L_80259C4C:
    mr      r3,r31
    bl      OSRestoreInterrupts
    mr      r3,r27
    lmw     r27,20(r1)
    lwz     r0,44(r1)
    addi    r1,r1,40
    mtlr    r0
    blr
.size SIGetResponse, . - SIGetResponse

.global AlarmHandler_SIBios
.balign 4
AlarmHandler_SIBios:
/* 0x80259C6C | size=0x8C (140 bytes) */
    mflr    r0
    lis     r4,-32694
    stw     r0,4(r1)
    addi    r0,r4,-21744
    lis     r4,26214
    subf    r0,r0,r3
    stwu    r1,-32(r1)
    addi    r3,r4,26215
    mulhw   r0,r3,r0
    stw     r31,28(r1)
    srawi   r0,r0,4
    srwi    r3,r0,31
    add     r0,r0,r3
    lis     r3,-32694
    slwi    r4,r0,5
    addi    r0,r3,-21872
    add     r31,r0,r4
    lwz     r3,0(r31)
    cmpwi   r3,-1
    beq-    .L_80259CE4
    lwz     r4,4(r31)
    lwz     r5,8(r31)
    lwz     r6,12(r31)
    lwz     r7,16(r31)
    lwz     r8,20(r31)
    bl      __SITransfer
    cmpwi   r3,0
    beq-    .L_80259CE4
    li      r0,-1
    stw     r0,0(r31)
.L_80259CE4:
    lwz     r0,36(r1)
    lwz     r31,28(r1)
    addi    r1,r1,32
    mtlr    r0
    blr
.size AlarmHandler_SIBios, . - AlarmHandler_SIBios

.global CallTypeAndStatusCallback
.balign 4
CallTypeAndStatusCallback:
/* 0x80259E64 | size=0x78 (120 bytes) */
    mflr    r0
    stw     r0,4(r1)
    stwu    r1,-40(r1)
    stmw    r27,20(r1)
    addi    r27,r3,0
    lis     r3,-32694
    slwi    r5,r27,4
    addi    r0,r3,-21520
    add     r30,r0,r5
    addi    r28,r4,0
    li      r29,0
    li      r31,0
.L_80259E94:
    lwz     r0,0(r30)
    cmplwi  r0,0
    mr      r12,r0
    beq-    .L_80259EB8
    stw     r31,0(r30)
    mtlr    r12
    addi    r3,r27,0
    addi    r4,r28,0
    blrl
.L_80259EB8:
    addi    r29,r29,1
    cmpwi   r29,4
    addi    r30,r30,4
    blt+    .L_80259E94
    lmw     r27,20(r1)
    lwz     r0,44(r1)
    addi    r1,r1,40
    mtlr    r0
    blr
.size CallTypeAndStatusCallback, . - CallTypeAndStatusCallback

#
# === SISamplingRate.o ===
#

.global SISetSamplingRate
.balign 4
SISetSamplingRate:
/* 0x8025A73C | size=0xE4 (228 bytes) */
    mflr    r0
    stw     r0,4(r1)
    stwu    r1,-32(r1)
    stw     r31,28(r1)
    stw     r30,24(r1)
    stw     r29,20(r1)
    addi    r29,r3,0
    cmplwi  r29,11
    lis     r3,-32700
    addi    r31,r3,-15760
    ble-    .L_8025A76C
    li      r29,11
.L_8025A76C:
    bl      OSDisableInterrupts
    stw     r29,-23528(r13)
    mr      r30,r3
    bl      VIGetTvFormat
    cmpwi   r3,2
    beq-    .L_8025A7A4
    bge-    .L_8025A798
    cmpwi   r3,0
    beq-    .L_8025A7A4
    bge-    .L_8025A7AC
    b       .L_8025A7B4
.L_8025A798:
    cmpwi   r3,5
    beq-    .L_8025A7A4
    b       .L_8025A7B4
.L_8025A7A4:
    mr      r4,r31
    b       .L_8025A7C8
.L_8025A7AC:
    addi    r4,r31,48
    b       .L_8025A7C8
.L_8025A7B4:
    addi    r3,r31,96
    crclr   4*cr1+eq
    bl      OSReport
    li      r29,0
    addi    r4,r31,0
.L_8025A7C8:
    lis     r3,-13312
    lhz     r0,8300(r3)
    clrlwi. r0,r0,31
    beq-    .L_8025A7E0
    li      r5,2
    b       .L_8025A7E4
.L_8025A7E0:
    li      r5,1
.L_8025A7E4:
    slwi    r3,r29,2
    lhzx    r0,r4,r3
    add     r3,r4,r3
    lbz     r4,2(r3)
    mullw   r3,r5,r0
    bl      SISetXY
    mr      r3,r30
    bl      OSRestoreInterrupts
    lwz     r0,36(r1)
    lwz     r31,28(r1)
    lwz     r30,24(r1)
    lwz     r29,20(r1)
    addi    r1,r1,32
    mtlr    r0
    blr
.size SISetSamplingRate, . - SISetSamplingRate

# ============================================================
# db.a
# ============================================================

#
# === db.o ===
#

.global __DBExceptionDestinationAux
.balign 4
__DBExceptionDestinationAux:
/* 0x8025A888 | size=0x48 (72 bytes) */
    mflr    r0
    lis     r3,-32700
    stw     r0,4(r1)
    addi    r3,r3,-15608
    crclr   4*cr1+eq
    stwu    r1,-24(r1)
    stw     r31,20(r1)
    lwz     r4,192(0)
    addis   r31,r4,-32768
    bl      OSReport
    mr      r3,r31
    bl      OSDumpContext
    bl      PPCHalt
    lwz     r0,28(r1)
    lwz     r31,20(r1)
    addi    r1,r1,24
    mtlr    r0
    blr
.size __DBExceptionDestinationAux, . - __DBExceptionDestinationAux

.global __DBMarkException
.balign 4
__DBMarkException:
/* 0x8025A8FC | size=0x44 (68 bytes) */
    cmpwi   r4,0
    clrlwi  r0,r3,24
    li      r3,1
    slw     r4,r3,r0
    beq-    .L_8025A928
    lwz     r3,-23520(r13)
    addi    r3,r3,4
    lwz     r0,0(r3)
    or      r0,r0,r4
    stw     r0,0(r3)
    b       .L_8025A93C
.L_8025A928:
    lwz     r3,-23520(r13)
    addi    r3,r3,4
    lwz     r0,0(r3)
    andc    r0,r0,r4
    stw     r0,0(r3)
.L_8025A93C:
    blr
.size __DBMarkException, . - __DBMarkException

.global DBPrintf
.balign 4
DBPrintf:
/* 0x8025A94C | size=0x50 (80 bytes) */
    stwu    r1,-112(r1)
    bne-    cr1,.L_8025A974
    stfd    f1,40(r1)
    stfd    f2,48(r1)
    stfd    f3,56(r1)
    stfd    f4,64(r1)
    stfd    f5,72(r1)
    stfd    f6,80(r1)
    stfd    f7,88(r1)
    stfd    f8,96(r1)
.L_8025A974:
    stw     r3,8(r1)
    stw     r4,12(r1)
    stw     r5,16(r1)
    stw     r6,20(r1)
    stw     r7,24(r1)
    stw     r8,28(r1)
    stw     r9,32(r1)
    stw     r10,36(r1)
    addi    r1,r1,112
    blr
.size DBPrintf, . - DBPrintf

# ============================================================
# mtx.a
# ============================================================

#
# === mtx.o ===
#

.global C_MTXCopy
.balign 4
C_MTXCopy:
/* 0x80371F9C | size=0x6C (108 bytes) */
    cmplw   r3,r4
    beqlr-
    lfs     f0,0(r3)
    stfs    f0,0(r4)
    lfs     f0,4(r3)
    stfs    f0,4(r4)
    lfs     f0,8(r3)
    stfs    f0,8(r4)
    lfs     f0,12(r3)
    stfs    f0,12(r4)
    lfs     f0,16(r3)
    stfs    f0,16(r4)
    lfs     f0,20(r3)
    stfs    f0,20(r4)
    lfs     f0,24(r3)
    stfs    f0,24(r4)
    lfs     f0,28(r3)
    stfs    f0,28(r4)
    lfs     f0,32(r3)
    stfs    f0,32(r4)
    lfs     f0,36(r3)
    stfs    f0,36(r4)
    lfs     f0,40(r3)
    stfs    f0,40(r4)
    lfs     f0,44(r3)
    stfs    f0,44(r4)
    blr
.size C_MTXCopy, . - C_MTXCopy

.global PSMTXConcat
.balign 4
PSMTXConcat:
/* 0x803722E4 | size=0xCC (204 bytes) */
    stwu    r1,-64(r1)
    psq_l   f0,0(r3),0,0
    stfd    f14,8(r1)
    psq_l   f6,0(r4),0,0
    lis     r6,-32688
    psq_l   f7,8(r4),0,0
    stfd    f15,16(r1)
    addi    r6,r6,-2576
    stfd    f31,40(r1)
    psq_l   f8,16(r4),0,0
    ps_muls0 f12,f6,f0
    psq_l   f2,16(r3),0,0
    ps_muls0 f13,f7,f0
    psq_l   f31,0(r6),0,0
    ps_muls0 f14,f6,f2
    psq_l   f9,24(r4),0,0
    ps_muls0 f15,f7,f2
    psq_l   f1,8(r3),0,0
    ps_madds1 f12,f8,f0,f12
    psq_l   f3,24(r3),0,0
    ps_madds1 f14,f8,f2,f14
    psq_l   f10,32(r4),0,0
    ps_madds1 f13,f9,f0,f13
    psq_l   f11,40(r4),0,0
    ps_madds1 f15,f9,f2,f15
    psq_l   f4,32(r3),0,0
    psq_l   f5,40(r3),0,0
    ps_madds0 f12,f10,f1,f12
    ps_madds0 f13,f11,f1,f13
    ps_madds0 f14,f10,f3,f14
    ps_madds0 f15,f11,f3,f15
    psq_st  f12,0(r5),0,0
    ps_muls0 f2,f6,f4
    ps_madds1 f13,f31,f1,f13
    ps_muls0 f0,f7,f4
    psq_st  f14,16(r5),0,0
    ps_madds1 f15,f31,f3,f15
    psq_st  f13,8(r5),0,0
    ps_madds1 f2,f8,f4,f2
    ps_madds1 f0,f9,f4,f0
    ps_madds0 f2,f10,f5,f2
    lfd     f14,8(r1)
    psq_st  f15,24(r5),0,0
    ps_madds0 f0,f11,f5,f0
    psq_st  f2,32(r5),0,0
    ps_madds1 f0,f31,f5,f0
    lfd     f15,16(r1)
    psq_st  f0,40(r5),0,0
    lfd     f31,40(r1)
    addi    r1,r1,64
    blr
.size PSMTXConcat, . - PSMTXConcat

.global C_MTXConcatArray
.balign 4
C_MTXConcatArray:
/* 0x803723B0 | size=0x68 (104 bytes) */
    mflr    r0
    stw     r0,4(r1)
    stwu    r1,-48(r1)
    stmw    r27,28(r1)
    mr      r27,r3
    mr      r28,r4
    mr      r29,r5
    mr      r30,r6
    li      r31,0
    b       .L_803723D8
.L_803723D8:
    b       .L_803723DC
.L_803723DC:
    b       .L_803723FC
.L_803723E0:
    mr      r3,r27
    mr      r4,r28
    mr      r5,r29
    bl      C_MTXConcat
    addi    r28,r28,48
    addi    r29,r29,48
    addi    r31,r31,1
.L_803723FC:
    cmplw   r31,r30
    blt+    .L_803723E0
    lmw     r27,28(r1)
    lwz     r0,52(r1)
    addi    r1,r1,48
    mtlr    r0
    blr
.size C_MTXConcatArray, . - C_MTXConcatArray

.global C_MTXTranspose
.balign 4
C_MTXTranspose:
/* 0x80372570 | size=0x9C (156 bytes) */
    mflr    r0
    stw     r0,4(r1)
    stwu    r1,-64(r1)
    cmplw   r3,r4
    bne-    .L_8037258C
    addi    r5,r1,16
    b       .L_80372590
.L_8037258C:
    mr      r5,r4
.L_80372590:
    lfs     f0,0(r3)
    addi    r0,r1,16
    cmplw   r5,r0
    stfs    f0,0(r5)
    lfs     f0,16(r3)
    stfs    f0,4(r5)
    lfs     f0,32(r3)
    stfs    f0,8(r5)
    lfs     f1,-17964(r13)
    stfs    f1,12(r5)
    lfs     f0,4(r3)
    stfs    f0,16(r5)
    lfs     f0,20(r3)
    stfs    f0,20(r5)
    lfs     f0,36(r3)
    stfs    f0,24(r5)
    stfs    f1,28(r5)
    lfs     f0,8(r3)
    stfs    f0,32(r5)
    lfs     f0,24(r3)
    stfs    f0,36(r5)
    lfs     f0,40(r3)
    stfs    f0,40(r5)
    stfs    f1,44(r5)
    bne-    .L_803725FC
    mr      r3,r0
    bl      C_MTXCopy
.L_803725FC:
    lwz     r0,68(r1)
    addi    r1,r1,64
    mtlr    r0
    blr
.size C_MTXTranspose, . - C_MTXTranspose

.global PSMTXTranspose
.balign 4
PSMTXTranspose:
/* 0x8037260C | size=0x50 (80 bytes) */
    lfs     f0,-17964(r13)
    psq_l   f1,0(r3),0,0
    stfs    f0,44(r4)
    psq_l   f2,16(r3),0,0
    ps_merge00 f4,f1,f2
    psq_l   f3,8(r3),1,0
    ps_merge11 f5,f1,f2
    psq_l   f2,24(r3),1,0
    psq_st  f4,0(r4),0,0
    psq_l   f1,32(r3),0,0
    ps_merge00 f2,f3,f2
    psq_st  f5,16(r4),0,0
    ps_merge00 f4,f1,f0
    psq_st  f2,32(r4),0,0
    ps_merge10 f5,f1,f0
    psq_st  f4,8(r4),0,0
    lfs     f3,40(r3)
    psq_st  f5,24(r4),0,0
    stfs    f3,40(r4)
    blr
.size PSMTXTranspose, . - PSMTXTranspose

.global PSMTXInverse
.balign 4
PSMTXInverse:
/* 0x80372908 | size=0xF8 (248 bytes) */
    psq_l   f0,0(r3),1,0
    psq_l   f1,4(r3),0,0
    psq_l   f2,16(r3),1,0
    ps_merge10 f6,f1,f0
    psq_l   f3,20(r3),0,0
    psq_l   f4,32(r3),1,0
    ps_merge10 f7,f3,f2
    psq_l   f5,36(r3),0,0
    ps_mul  f11,f3,f6
    ps_mul  f13,f5,f7
    ps_merge10 f8,f5,f4
    ps_msub f11,f1,f7,f11
    ps_mul  f12,f1,f8
    ps_msub f13,f3,f8,f13
    ps_mul  f10,f3,f4
    ps_msub f12,f5,f6,f12
    ps_mul  f9,f0,f5
    ps_mul  f8,f1,f2
    ps_sub  f6,f6,f6
    ps_msub f10,f2,f5,f10
    ps_mul  f7,f0,f13
    ps_msub f9,f1,f4,f9
    ps_madd f7,f2,f12,f7
    ps_msub f8,f0,f3,f8
    ps_madd f7,f4,f11,f7
    ps_cmpo0 cr0,f7,f6
    bne-    .L_8037297C
    li      r3,0
    blr
.L_8037297C:
    fres    f0,f7
    ps_add  f6,f0,f0
    ps_mul  f5,f0,f0
    ps_nmsub f0,f7,f5,f6
    lfs     f1,12(r3)
    ps_muls0 f13,f13,f0
    lfs     f2,28(r3)
    ps_muls0 f12,f12,f0
    lfs     f3,44(r3)
    ps_muls0 f11,f11,f0
    ps_merge00 f5,f13,f12
    ps_muls0 f10,f10,f0
    ps_merge11 f4,f13,f12
    ps_muls0 f9,f9,f0
    psq_st  f5,0(r4),0,0
    ps_mul  f6,f13,f1
    psq_st  f4,16(r4),0,0
    ps_muls0 f8,f8,f0
    ps_madd f6,f12,f2,f6
    psq_st  f10,32(r4),1,0
    ps_nmadd f6,f11,f3,f6
    psq_st  f9,36(r4),1,0
    ps_mul  f7,f10,f1
    ps_merge00 f5,f11,f6
    psq_st  f8,40(r4),1,0
    ps_merge11 f4,f11,f6
    psq_st  f5,8(r4),0,0
    ps_madd f7,f9,f2,f7
    psq_st  f4,24(r4),0,0
    ps_nmadd f7,f8,f3,f7
    li      r3,1
    psq_st  f7,44(r4),1,0
    blr
.size PSMTXInverse, . - PSMTXInverse

.global PSMTXInvXpose
.balign 4
PSMTXInvXpose:
/* 0x80372C1C | size=0xC8 (200 bytes) */
    psq_l   f0,0(r3),1,0
    psq_l   f1,4(r3),0,0
    psq_l   f2,16(r3),1,0
    ps_merge10 f6,f1,f0
    psq_l   f3,20(r3),0,0
    psq_l   f4,32(r3),1,0
    ps_merge10 f7,f3,f2
    psq_l   f5,36(r3),0,0
    ps_mul  f11,f3,f6
    ps_merge10 f8,f5,f4
    ps_mul  f13,f5,f7
    ps_msub f11,f1,f7,f11
    ps_mul  f12,f1,f8
    ps_msub f13,f3,f8,f13
    ps_msub f12,f5,f6,f12
    ps_mul  f10,f3,f4
    ps_mul  f9,f0,f5
    ps_mul  f8,f1,f2
    ps_msub f10,f2,f5,f10
    ps_msub f9,f1,f4,f9
    ps_msub f8,f0,f3,f8
    ps_mul  f7,f0,f13
    ps_sub  f1,f1,f1
    ps_madd f7,f2,f12,f7
    ps_madd f7,f4,f11,f7
    ps_cmpo0 cr0,f7,f1
    bne-    .L_80372C90
    li      r3,0
    blr
.L_80372C90:
    fres    f0,f7
    psq_st  f1,12(r4),1,0
    ps_add  f6,f0,f0
    ps_mul  f5,f0,f0
    psq_st  f1,28(r4),1,0
    ps_nmsub f0,f7,f5,f6
    psq_st  f1,44(r4),1,0
    ps_muls0 f13,f13,f0
    ps_muls0 f12,f12,f0
    ps_muls0 f11,f11,f0
    psq_st  f13,0(r4),0,0
    psq_st  f12,16(r4),0,0
    ps_muls0 f10,f10,f0
    ps_muls0 f9,f9,f0
    psq_st  f11,32(r4),0,0
    psq_st  f10,8(r4),1,0
    ps_muls0 f8,f8,f0
    li      r3,1
    psq_st  f9,24(r4),1,0
    psq_st  f8,40(r4),1,0
    blr
.size PSMTXInvXpose, . - PSMTXInvXpose

.global C_MTXRotRad
.balign 4
C_MTXRotRad:
/* 0x80372CE4 | size=0x70 (112 bytes) */
    mflr    r0
    stw     r0,4(r1)
    stwu    r1,-40(r1)
    stfd    f31,32(r1)
    stw     r31,28(r1)
    stw     r30,24(r1)
    fmr     f31,f1
    mr      r30,r3
    mr      r31,r4
    fmr     f1,f31
    bl      sinf
    fmr     f0,f1
    fmr     f1,f31
    fmr     f31,f0
    bl      cosf
    fmr     f0,f1
    mr      r3,r30
    fmr     f1,f31
    mr      r4,r31
    fmr     f2,f0
    bl      C_MTXRotTrig
    lwz     r0,44(r1)
    lfd     f31,32(r1)
    lwz     r31,28(r1)
    lwz     r30,24(r1)
    addi    r1,r1,40
    mtlr    r0
    blr
.size C_MTXRotRad, . - C_MTXRotRad

.global PSMTXRotRad
.balign 4
PSMTXRotRad:
/* 0x80372D54 | size=0x70 (112 bytes) */
    mflr    r0
    stw     r0,4(r1)
    stwu    r1,-40(r1)
    stfd    f31,32(r1)
    stw     r31,28(r1)
    stw     r30,24(r1)
    fmr     f31,f1
    mr      r30,r3
    mr      r31,r4
    fmr     f1,f31
    bl      sinf
    fmr     f0,f1
    fmr     f1,f31
    fmr     f31,f0
    bl      cosf
    fmr     f0,f1
    mr      r3,r30
    fmr     f1,f31
    mr      r4,r31
    fmr     f2,f0
    bl      PSMTXRotTrig
    lwz     r0,44(r1)
    lfd     f31,32(r1)
    lwz     r31,28(r1)
    lwz     r30,24(r1)
    addi    r1,r1,40
    mtlr    r0
    blr
.size PSMTXRotRad, . - PSMTXRotRad

.global PSMTXRotTrig
.balign 4
PSMTXRotTrig:
/* 0x80372EC8 | size=0xB0 (176 bytes) */
    frsp    f5,f1
    frsp    f4,f2
    lfs     f0,-17964(r13)
    lfs     f1,-17968(r13)
    ori     r0,r4,32
    ps_neg  f2,f5
    cmplwi  r0,120
    beq-    .L_80372EFC
    cmplwi  r0,121
    beq-    .L_80372F24
    cmplwi  r0,122
    beq-    .L_80372F50
    b       .L_80372F74
.L_80372EFC:
    psq_st  f1,0(r3),1,0
    psq_st  f0,4(r3),0,0
    ps_merge00 f3,f5,f4
    psq_st  f0,12(r3),0,0
    ps_merge00 f1,f4,f2
    psq_st  f0,28(r3),0,0
    psq_st  f0,44(r3),1,0
    psq_st  f3,36(r3),0,0
    psq_st  f1,20(r3),0,0
    b       .L_80372F74
.L_80372F24:
    ps_merge00 f3,f4,f0
    ps_merge00 f1,f0,f1
    psq_st  f0,24(r3),0,0
    psq_st  f3,0(r3),0,0
    ps_merge00 f2,f2,f0
    ps_merge00 f0,f5,f0
    psq_st  f3,40(r3),0,0
    psq_st  f1,16(r3),0,0
    psq_st  f0,8(r3),0,0
    psq_st  f2,32(r3),0,0
    b       .L_80372F74
.L_80372F50:
    psq_st  f0,8(r3),0,0
    ps_merge00 f3,f5,f4
    ps_merge00 f2,f4,f2
    psq_st  f0,24(r3),0,0
    psq_st  f0,32(r3),0,0
    ps_merge00 f1,f1,f0
    psq_st  f3,16(r3),0,0
    psq_st  f2,0(r3),0,0
    psq_st  f1,40(r3),0,0
.L_80372F74:
    blr
.size PSMTXRotTrig, . - PSMTXRotTrig

.global __PSMTXRotAxisRadInternal
.balign 4
__PSMTXRotAxisRadInternal:
/* 0x80373090 | size=0xB0 (176 bytes) */
    lfs     f10,-17960(r13)
    lfs     f9,-17956(r13)
    frsp    f11,f2
    psq_l   f2,0(r4),0,0
    frsp    f12,f1
    lfs     f3,8(r4)
    ps_mul  f4,f2,f2
    fadds   f8,f10,f10
    ps_madd f5,f3,f3,f4
    fsubs   f1,f10,f10
    ps_sum0 f6,f5,f3,f4
    fsubs   f0,f8,f11
    frsqrte f7,f6
    fmuls   f4,f7,f7
    fmuls   f5,f7,f10
    fnmsubs f4,f4,f6,f9
    fmuls   f7,f4,f5
    ps_merge00 f11,f11,f11
    ps_muls0 f2,f2,f7
    ps_muls0 f3,f3,f7
    ps_muls0 f6,f2,f0
    ps_muls0 f10,f2,f12
    ps_muls0 f7,f3,f0
    ps_muls1 f5,f6,f2
    ps_muls0 f4,f6,f2
    ps_muls0 f6,f6,f3
    fnmsubs f0,f3,f12,f5
    fmadds  f8,f3,f12,f5
    ps_neg  f2,f10
    ps_sum0 f9,f6,f1,f10
    ps_sum0 f4,f4,f0,f11
    ps_sum1 f5,f11,f8,f5
    ps_sum0 f0,f2,f1,f6
    psq_st  f9,8(r3),0,0
    ps_sum0 f2,f6,f6,f2
    psq_st  f4,0(r3),0,0
    ps_muls0 f7,f7,f3
    psq_st  f5,16(r3),0,0
    ps_sum1 f6,f10,f2,f6
    psq_st  f0,24(r3),0,0
    ps_sum0 f7,f7,f1,f11
    psq_st  f6,32(r3),0,0
    psq_st  f7,40(r3),0,0
    blr
.size __PSMTXRotAxisRadInternal, . - __PSMTXRotAxisRadInternal

.global PSMTXRotAxisRad
.balign 4
PSMTXRotAxisRad:
/* 0x80373140 | size=0x70 (112 bytes) */
    mflr    r0
    stw     r0,4(r1)
    stwu    r1,-40(r1)
    stfd    f31,32(r1)
    stw     r31,28(r1)
    stw     r30,24(r1)
    fmr     f31,f1
    mr      r30,r3
    mr      r31,r4
    fmr     f1,f31
    bl      sinf
    fmr     f0,f1
    fmr     f1,f31
    fmr     f31,f0
    bl      cosf
    fmr     f0,f1
    mr      r3,r30
    fmr     f1,f31
    mr      r4,r31
    fmr     f2,f0
    bl      __PSMTXRotAxisRadInternal
    lwz     r0,44(r1)
    lfd     f31,32(r1)
    lwz     r31,28(r1)
    lwz     r30,24(r1)
    addi    r1,r1,40
    mtlr    r0
    blr
.size PSMTXRotAxisRad, . - PSMTXRotAxisRad

.global C_MTXTransApply
.balign 4
C_MTXTransApply:
/* 0x80373220 | size=0x78 (120 bytes) */
    cmplw   r3,r4
    beq-    .L_80373270
    lfs     f0,0(r3)
    stfs    f0,0(r4)
    lfs     f0,4(r3)
    stfs    f0,4(r4)
    lfs     f0,8(r3)
    stfs    f0,8(r4)
    lfs     f0,16(r3)
    stfs    f0,16(r4)
    lfs     f0,20(r3)
    stfs    f0,20(r4)
    lfs     f0,24(r3)
    stfs    f0,24(r4)
    lfs     f0,32(r3)
    stfs    f0,32(r4)
    lfs     f0,36(r3)
    stfs    f0,36(r4)
    lfs     f0,40(r3)
    stfs    f0,40(r4)
.L_80373270:
    lfs     f0,12(r3)
    fadds   f0,f0,f1
    stfs    f0,12(r4)
    lfs     f0,28(r3)
    fadds   f0,f0,f2
    stfs    f0,28(r4)
    lfs     f0,44(r3)
    fadds   f0,f0,f3
    stfs    f0,44(r4)
    blr
.size C_MTXTransApply, . - C_MTXTransApply

.global PSMTXTransApply
.balign 4
PSMTXTransApply:
/* 0x80373298 | size=0x4C (76 bytes) */
    psq_l   f4,0(r3),0,0
    frsp    f1,f1
    psq_l   f5,8(r3),0,0
    frsp    f2,f2
    psq_l   f7,24(r3),0,0
    frsp    f3,f3
    psq_l   f8,40(r3),0,0
    psq_st  f4,0(r4),0,0
    ps_sum1 f5,f1,f5,f5
    psq_l   f6,16(r3),0,0
    psq_st  f5,8(r4),0,0
    ps_sum1 f7,f2,f7,f7
    psq_l   f9,32(r3),0,0
    psq_st  f6,16(r4),0,0
    ps_sum1 f8,f3,f8,f8
    psq_st  f7,24(r4),0,0
    psq_st  f9,32(r4),0,0
    psq_st  f8,40(r4),0,0
    blr
.size PSMTXTransApply, . - PSMTXTransApply

.global C_MTXScaleApply
.balign 4
C_MTXScaleApply:
/* 0x80373344 | size=0x94 (148 bytes) */
    lfs     f0,0(r3)
    fmuls   f0,f0,f1
    stfs    f0,0(r4)
    lfs     f0,4(r3)
    fmuls   f0,f0,f1
    stfs    f0,4(r4)
    lfs     f0,8(r3)
    fmuls   f0,f0,f1
    stfs    f0,8(r4)
    lfs     f0,12(r3)
    fmuls   f0,f0,f1
    stfs    f0,12(r4)
    lfs     f0,16(r3)
    fmuls   f0,f0,f2
    stfs    f0,16(r4)
    lfs     f0,20(r3)
    fmuls   f0,f0,f2
    stfs    f0,20(r4)
    lfs     f0,24(r3)
    fmuls   f0,f0,f2
    stfs    f0,24(r4)
    lfs     f0,28(r3)
    fmuls   f0,f0,f2
    stfs    f0,28(r4)
    lfs     f0,32(r3)
    fmuls   f0,f0,f3
    stfs    f0,32(r4)
    lfs     f0,36(r3)
    fmuls   f0,f0,f3
    stfs    f0,36(r4)
    lfs     f0,40(r3)
    fmuls   f0,f0,f3
    stfs    f0,40(r4)
    lfs     f0,44(r3)
    fmuls   f0,f0,f3
    stfs    f0,44(r4)
    blr
.size C_MTXScaleApply, . - C_MTXScaleApply

.global PSMTXScaleApply
.balign 4
PSMTXScaleApply:
/* 0x803733D8 | size=0x58 (88 bytes) */
    frsp    f1,f1
    psq_l   f4,0(r3),0,0
    frsp    f2,f2
    psq_l   f5,8(r3),0,0
    frsp    f3,f3
    ps_muls0 f4,f4,f1
    psq_l   f6,16(r3),0,0
    ps_muls0 f5,f5,f1
    psq_l   f7,24(r3),0,0
    ps_muls0 f6,f6,f2
    psq_l   f8,32(r3),0,0
    psq_st  f4,0(r4),0,0
    ps_muls0 f7,f7,f2
    psq_l   f2,40(r3),0,0
    psq_st  f5,8(r4),0,0
    ps_muls0 f8,f8,f3
    psq_st  f6,16(r4),0,0
    ps_muls0 f2,f2,f3
    psq_st  f7,24(r4),0,0
    psq_st  f8,32(r4),0,0
    psq_st  f2,40(r4),0,0
    blr
.size PSMTXScaleApply, . - PSMTXScaleApply

.global C_MTXQuat
.balign 4
C_MTXQuat:
/* 0x80373430 | size=0xF0 (240 bytes) */
    stwu    r1,-40(r1)
    stfd    f31,32(r1)
    stfd    f30,24(r1)
    stfd    f29,16(r1)
    lfs     f5,0(r4)
    lfs     f4,4(r4)
    fmuls   f1,f5,f5
    lfs     f6,8(r4)
    fmuls   f0,f4,f4
    lfs     f8,12(r4)
    fmuls   f2,f6,f6
    fadds   f0,f1,f0
    lfs     f3,-17952(r13)
    fmuls   f1,f8,f8
    lfs     f7,-17968(r13)
    fadds   f0,f2,f0
    fadds   f0,f1,f0
    fdivs   f0,f3,f0
    fmuls   f10,f6,f0
    fmuls   f1,f4,f0
    fmuls   f9,f5,f0
    fmuls   f29,f6,f10
    fmuls   f30,f4,f1
    fmuls   f12,f5,f9
    fmuls   f6,f8,f10
    fmuls   f13,f5,f1
    fadds   f0,f30,f29
    fmuls   f11,f8,f1
    fmuls   f31,f5,f10
    fsubs   f0,f7,f0
    fsubs   f3,f13,f6
    fadds   f2,f31,f11
    stfs    f0,0(r3)
    fadds   f1,f12,f29
    fadds   f0,f12,f30
    stfs    f3,4(r3)
    fadds   f5,f13,f6
    stfs    f2,8(r3)
    fmuls   f8,f8,f9
    fmuls   f9,f4,f10
    lfs     f6,-17964(r13)
    fsubs   f4,f7,f1
    stfs    f6,12(r3)
    fsubs   f3,f9,f8
    fsubs   f2,f31,f11
    stfs    f5,16(r3)
    fadds   f1,f9,f8
    stfs    f4,20(r3)
    fsubs   f0,f7,f0
    stfs    f3,24(r3)
    stfs    f6,28(r3)
    stfs    f2,32(r3)
    stfs    f1,36(r3)
    stfs    f0,40(r3)
    stfs    f6,44(r3)
    lfd     f31,32(r1)
    lfd     f30,24(r1)
    lfd     f29,16(r1)
    addi    r1,r1,40
    blr
.size C_MTXQuat, . - C_MTXQuat

.global PSMTXQuat
.balign 4
PSMTXQuat:
/* 0x80373520 | size=0xA4 (164 bytes) */
    lfs     f1,-17968(r13)
    psq_l   f4,0(r4),0,0
    psq_l   f5,8(r4),0,0
    fsubs   f0,f1,f1
    fadds   f2,f1,f1
    ps_mul  f6,f4,f4
    ps_merge10 f9,f4,f4
    ps_madd f8,f5,f5,f6
    ps_mul  f7,f5,f5
    ps_sum0 f3,f8,f8,f8
    ps_muls1 f10,f9,f5
    fres    f11,f3
    ps_sum1 f8,f7,f8,f6
    ps_nmsub f3,f3,f11,f2
    ps_muls1 f7,f5,f5
    ps_mul  f3,f11,f3
    ps_sum0 f6,f6,f6,f6
    fmuls   f3,f3,f2
    ps_madd f11,f4,f9,f7
    ps_msub f7,f4,f9,f7
    psq_st  f0,12(r3),1,0
    ps_nmsub f6,f6,f3,f1
    ps_nmsub f8,f8,f3,f1
    psq_st  f0,44(r3),1,0
    ps_mul  f11,f11,f3
    ps_mul  f7,f7,f3
    psq_st  f6,40(r3),1,0
    ps_madds0 f9,f4,f5,f10
    ps_merge00 f5,f11,f8
    ps_nmsub f10,f10,f2,f9
    ps_merge10 f4,f8,f7
    psq_st  f5,16(r3),0,0
    ps_mul  f9,f9,f3
    ps_mul  f10,f10,f3
    psq_st  f4,0(r3),0,0
    psq_st  f9,8(r3),1,0
    ps_merge10 f7,f10,f0
    ps_merge01 f11,f10,f9
    psq_st  f7,24(r3),0,0
    psq_st  f11,32(r3),0,0
    blr
.size PSMTXQuat, . - PSMTXQuat

.global C_MTXReflect
.balign 4
C_MTXReflect:
/* 0x803735C4 | size=0x100 (256 bytes) */
    mflr    r0
    stw     r0,4(r1)
    stwu    r1,-56(r1)
    stfd    f31,48(r1)
    stfd    f30,40(r1)
    stfd    f29,32(r1)
    stw     r31,28(r1)
    stw     r30,24(r1)
    mr      r30,r3
    mr      r31,r5
    lfs     f1,-17948(r13)
    mr      r3,r4
    lfs     f0,0(r31)
    mr      r4,r31
    lfs     f4,4(r31)
    fmuls   f2,f1,f0
    lfs     f3,8(r31)
    fmuls   f0,f1,f4
    fmuls   f31,f2,f4
    fmuls   f30,f2,f3
    fmuls   f29,f0,f3
    bl      C_VECDotProduct
    lfs     f3,-17952(r13)
    lfs     f4,0(r31)
    lfs     f2,-17968(r13)
    fmuls   f5,f3,f1
    fmuls   f0,f3,f4
    fmuls   f0,f0,f4
    fsubs   f0,f2,f0
    stfs    f0,0(r30)
    stfs    f31,4(r30)
    stfs    f30,8(r30)
    lfs     f0,0(r31)
    fmuls   f0,f5,f0
    stfs    f0,12(r30)
    stfs    f31,16(r30)
    lfs     f1,4(r31)
    fmuls   f0,f3,f1
    fmuls   f0,f0,f1
    fsubs   f0,f2,f0
    stfs    f0,20(r30)
    stfs    f29,24(r30)
    lfs     f0,4(r31)
    fmuls   f0,f5,f0
    stfs    f0,28(r30)
    stfs    f30,32(r30)
    stfs    f29,36(r30)
    lfs     f1,8(r31)
    fmuls   f0,f3,f1
    fmuls   f0,f0,f1
    fsubs   f0,f2,f0
    stfs    f0,40(r30)
    lfs     f0,8(r31)
    fmuls   f0,f5,f0
    stfs    f0,44(r30)
    lwz     r0,60(r1)
    lfd     f31,48(r1)
    lfd     f30,40(r1)
    lfd     f29,32(r1)
    lwz     r31,28(r1)
    lwz     r30,24(r1)
    addi    r1,r1,56
    mtlr    r0
    blr
.size C_MTXReflect, . - C_MTXReflect

.global PSMTXReflect
.balign 4
PSMTXReflect:
/* 0x803736C4 | size=0x70 (112 bytes) */
    lfs     f0,-17968(r13)
    psq_l   f2,8(r5),1,0
    psq_l   f1,0(r5),0,0
    psq_l   f5,0(r4),0,0
    ps_nmadd f4,f2,f0,f2
    psq_l   f6,8(r4),1,0
    ps_nmadd f3,f1,f0,f1
    ps_muls0 f8,f1,f4
    ps_mul  f5,f3,f5
    ps_muls0 f7,f1,f3
    ps_sum0 f5,f5,f5,f5
    ps_muls1 f3,f1,f3
    psq_st  f8,32(r3),0,0
    ps_sum0 f7,f7,f7,f0
    ps_nmadd f5,f4,f6,f5
    ps_sum1 f3,f0,f3,f3
    psq_st  f7,0(r3),0,0
    ps_muls0 f1,f1,f5
    ps_merge00 f4,f4,f5
    psq_st  f3,16(r3),0,0
    ps_merge00 f3,f8,f1
    ps_muls0 f4,f4,f2
    ps_merge11 f1,f8,f1
    psq_st  f3,8(r3),0,0
    ps_sum0 f4,f4,f4,f0
    psq_st  f1,24(r3),0,0
    psq_st  f4,40(r3),0,0
    blr
.size PSMTXReflect, . - PSMTXReflect

.global C_MTXLightFrustum
.balign 4
C_MTXLightFrustum:
/* 0x803738C0 | size=0x94 (148 bytes) */
    stwu    r1,-48(r1)
    lfs     f12,56(r1)
    fsubs   f10,f4,f3
    lfs     f11,-17968(r13)
    fsubs   f0,f1,f2
    lfs     f9,-17952(r13)
    fadds   f3,f4,f3
    fdivs   f10,f11,f10
    fmuls   f5,f9,f5
    fdivs   f9,f11,f0
    fmuls   f4,f5,f10
    fmuls   f3,f10,f3
    fadds   f0,f1,f2
    fmuls   f1,f6,f4
    fmuls   f2,f6,f3
    fmuls   f0,f9,f0
    stfs    f1,0(r3)
    fmuls   f1,f5,f9
    fsubs   f2,f2,f8
    lfs     f3,-17964(r13)
    fmuls   f0,f7,f0
    stfs    f3,4(r3)
    fmuls   f1,f7,f1
    stfs    f2,8(r3)
    fsubs   f0,f0,f12
    stfs    f3,12(r3)
    stfs    f3,16(r3)
    stfs    f1,20(r3)
    stfs    f0,24(r3)
    stfs    f3,28(r3)
    stfs    f3,32(r3)
    stfs    f3,36(r3)
    lfs     f0,-17944(r13)
    stfs    f0,40(r3)
    stfs    f3,44(r3)
    addi    r1,r1,48
    blr
.size C_MTXLightFrustum, . - C_MTXLightFrustum

.global C_MTXLightPerspective
.balign 4
C_MTXLightPerspective:
/* 0x80373954 | size=0xCC (204 bytes) */
    mflr    r0
    stw     r0,4(r1)
    stwu    r1,-88(r1)
    stfd    f31,80(r1)
    stfd    f30,72(r1)
    stfd    f29,64(r1)
    stfd    f28,56(r1)
    stfd    f27,48(r1)
    stw     r31,44(r1)
    fmr     f27,f2
    mr      r31,r3
    fmr     f28,f3
    fmr     f29,f4
    fmr     f30,f5
    fmr     f31,f6
    lfs     f2,-17960(r13)
    lfs     f0,-17940(r13)
    fmuls   f1,f2,f1
    fmuls   f1,f0,f1
    bl      tanf
    lfs     f3,-17968(r13)
    fneg    f2,f30
    fneg    f0,f31
    fdivs   f4,f3,f1
    fdivs   f1,f4,f27
    fmuls   f3,f28,f1
    fmuls   f1,f4,f29
    stfs    f3,0(r31)
    lfs     f3,-17964(r13)
    stfs    f3,4(r31)
    stfs    f2,8(r31)
    stfs    f3,12(r31)
    stfs    f3,16(r31)
    stfs    f1,20(r31)
    stfs    f0,24(r31)
    stfs    f3,28(r31)
    stfs    f3,32(r31)
    stfs    f3,36(r31)
    lfs     f0,-17944(r13)
    stfs    f0,40(r31)
    stfs    f3,44(r31)
    lwz     r0,92(r1)
    lfd     f31,80(r1)
    lfd     f30,72(r1)
    lfd     f29,64(r1)
    lfd     f28,56(r1)
    lfd     f27,48(r1)
    lwz     r31,44(r1)
    addi    r1,r1,88
    mtlr    r0
    blr
.size C_MTXLightPerspective, . - C_MTXLightPerspective

.global C_MTXLightOrtho
.balign 4
C_MTXLightOrtho:
/* 0x80373A20 | size=0x88 (136 bytes) */
    fsubs   f10,f4,f3
    lfs     f11,-17968(r13)
    fsubs   f0,f1,f2
    lfs     f9,-17952(r13)
    fadds   f3,f4,f3
    fdivs   f12,f11,f10
    fdivs   f10,f11,f0
    fmuls   f4,f9,f12
    fneg    f3,f3
    fadds   f0,f1,f2
    fmuls   f1,f4,f5
    fmuls   f2,f12,f3
    fneg    f0,f0
    stfs    f1,0(r3)
    fmuls   f1,f9,f10
    fmuls   f2,f5,f2
    lfs     f3,-17964(r13)
    fmuls   f0,f10,f0
    stfs    f3,4(r3)
    fadds   f2,f7,f2
    fmuls   f1,f1,f6
    stfs    f3,8(r3)
    fmuls   f0,f6,f0
    stfs    f2,12(r3)
    stfs    f3,16(r3)
    fadds   f0,f8,f0
    stfs    f1,20(r3)
    stfs    f3,24(r3)
    stfs    f0,28(r3)
    stfs    f3,32(r3)
    stfs    f3,36(r3)
    stfs    f3,40(r3)
    stfs    f11,44(r3)
    blr
.size C_MTXLightOrtho, . - C_MTXLightOrtho

#
# === mtx44.o ===
#

.global C_MTXFrustum
.balign 4
C_MTXFrustum:
/* 0x80374134 | size=0x9C (156 bytes) */
    fsubs   f9,f4,f3
    lfs     f10,-17872(r13)
    fsubs   f0,f1,f2
    lfs     f8,-17868(r13)
    fsubs   f7,f6,f5
    fdivs   f11,f10,f9
    fmuls   f8,f8,f5
    fdivs   f9,f10,f0
    fmuls   f0,f8,f11
    fadds   f3,f4,f3
    fadds   f2,f1,f2
    stfs    f0,0(r3)
    fmuls   f0,f6,f5
    fdivs   f6,f10,f7
    lfs     f4,-17864(r13)
    stfs    f4,4(r3)
    fmuls   f3,f11,f3
    fneg    f1,f5
    fneg    f0,f0
    stfs    f3,8(r3)
    fmuls   f3,f8,f9
    fmuls   f2,f9,f2
    stfs    f4,12(r3)
    fmuls   f1,f1,f6
    stfs    f4,16(r3)
    fmuls   f0,f6,f0
    stfs    f3,20(r3)
    stfs    f2,24(r3)
    stfs    f4,28(r3)
    stfs    f4,32(r3)
    stfs    f4,36(r3)
    stfs    f1,40(r3)
    stfs    f0,44(r3)
    stfs    f4,48(r3)
    stfs    f4,52(r3)
    lfs     f0,-17860(r13)
    stfs    f0,56(r3)
    stfs    f4,60(r3)
    blr
.size C_MTXFrustum, . - C_MTXFrustum

.global C_MTXPerspective
.balign 4
C_MTXPerspective:
/* 0x803741D0 | size=0xD0 (208 bytes) */
    mflr    r0
    stw     r0,4(r1)
    stwu    r1,-64(r1)
    stfd    f31,56(r1)
    fmr     f31,f4
    stfd    f30,48(r1)
    fmr     f30,f3
    stfd    f29,40(r1)
    fmr     f29,f2
    stw     r31,36(r1)
    mr      r31,r3
    lfs     f5,-17856(r13)
    lfs     f0,-17852(r13)
    fmuls   f1,f5,f1
    fmuls   f1,f0,f1
    bl      tanf
    lfs     f3,-17872(r13)
    fsubs   f2,f31,f30
    fmuls   f0,f31,f30
    fdivs   f4,f3,f1
    fdivs   f1,f4,f29
    stfs    f1,0(r31)
    fdivs   f3,f3,f2
    lfs     f2,-17864(r13)
    stfs    f2,4(r31)
    stfs    f2,8(r31)
    stfs    f2,12(r31)
    stfs    f2,16(r31)
    fneg    f1,f30
    fneg    f0,f0
    stfs    f4,20(r31)
    fmuls   f1,f1,f3
    stfs    f2,24(r31)
    fmuls   f0,f3,f0
    stfs    f2,28(r31)
    stfs    f2,32(r31)
    stfs    f2,36(r31)
    stfs    f1,40(r31)
    stfs    f0,44(r31)
    stfs    f2,48(r31)
    stfs    f2,52(r31)
    lfs     f0,-17860(r13)
    stfs    f0,56(r31)
    stfs    f2,60(r31)
    lwz     r0,68(r1)
    lfd     f31,56(r1)
    lfd     f30,48(r1)
    lfd     f29,40(r1)
    lwz     r31,36(r1)
    addi    r1,r1,64
    mtlr    r0
    blr
.size C_MTXPerspective, . - C_MTXPerspective

.global C_MTXOrtho
.balign 4
C_MTXOrtho:
/* 0x803742A0 | size=0x98 (152 bytes) */
    fsubs   f8,f4,f3
    lfs     f9,-17872(r13)
    fsubs   f0,f1,f2
    lfs     f7,-17868(r13)
    fadds   f3,f4,f3
    fdivs   f10,f9,f8
    fdivs   f8,f9,f0
    fmuls   f4,f7,f10
    fneg    f3,f3
    fsubs   f0,f6,f5
    stfs    f4,0(r3)
    fadds   f1,f1,f2
    fmuls   f2,f10,f3
    lfs     f3,-17864(r13)
    fneg    f1,f1
    stfs    f3,4(r3)
    fdivs   f4,f9,f0
    stfs    f3,8(r3)
    stfs    f2,12(r3)
    stfs    f3,16(r3)
    fmuls   f2,f7,f8
    fneg    f0,f6
    fmuls   f1,f8,f1
    stfs    f2,20(r3)
    fmuls   f0,f0,f4
    stfs    f3,24(r3)
    stfs    f1,28(r3)
    stfs    f3,32(r3)
    stfs    f3,36(r3)
    lfs     f1,-17860(r13)
    fmuls   f1,f1,f4
    stfs    f1,40(r3)
    stfs    f0,44(r3)
    stfs    f3,48(r3)
    stfs    f3,52(r3)
    stfs    f3,56(r3)
    stfs    f9,60(r3)
    blr
.size C_MTXOrtho, . - C_MTXOrtho

.global C_MTX44Identity
.balign 4
C_MTX44Identity:
/* 0x80374338 | size=0x4C (76 bytes) */
    lfs     f1,-17872(r13)
    stfs    f1,0(r3)
    lfs     f0,-17864(r13)
    stfs    f0,4(r3)
    stfs    f0,8(r3)
    stfs    f0,12(r3)
    stfs    f0,16(r3)
    stfs    f1,20(r3)
    stfs    f0,24(r3)
    stfs    f0,28(r3)
    stfs    f0,32(r3)
    stfs    f0,36(r3)
    stfs    f1,40(r3)
    stfs    f0,44(r3)
    stfs    f0,48(r3)
    stfs    f0,52(r3)
    stfs    f0,56(r3)
    stfs    f1,60(r3)
    blr
.size C_MTX44Identity, . - C_MTX44Identity

.global C_MTX44Copy
.balign 4
C_MTX44Copy:
/* 0x803743B8 | size=0x8C (140 bytes) */
    cmplw   r3,r4
    beqlr-
    lfs     f0,0(r3)
    stfs    f0,0(r4)
    lfs     f0,4(r3)
    stfs    f0,4(r4)
    lfs     f0,8(r3)
    stfs    f0,8(r4)
    lfs     f0,12(r3)
    stfs    f0,12(r4)
    lfs     f0,16(r3)
    stfs    f0,16(r4)
    lfs     f0,20(r3)
    stfs    f0,20(r4)
    lfs     f0,24(r3)
    stfs    f0,24(r4)
    lfs     f0,28(r3)
    stfs    f0,28(r4)
    lfs     f0,32(r3)
    stfs    f0,32(r4)
    lfs     f0,36(r3)
    stfs    f0,36(r4)
    lfs     f0,40(r3)
    stfs    f0,40(r4)
    lfs     f0,44(r3)
    stfs    f0,44(r4)
    lfs     f0,48(r3)
    stfs    f0,48(r4)
    lfs     f0,52(r3)
    stfs    f0,52(r4)
    lfs     f0,56(r3)
    stfs    f0,56(r4)
    lfs     f0,60(r3)
    stfs    f0,60(r4)
    blr
.size C_MTX44Copy, . - C_MTX44Copy

.global PSMTX44Copy
.balign 4
PSMTX44Copy:
/* 0x80374444 | size=0x44 (68 bytes) */
    psq_l   f1,0(r3),0,0
    psq_st  f1,0(r4),0,0
    psq_l   f1,8(r3),0,0
    psq_st  f1,8(r4),0,0
    psq_l   f1,16(r3),0,0
    psq_st  f1,16(r4),0,0
    psq_l   f1,24(r3),0,0
    psq_st  f1,24(r4),0,0
    psq_l   f1,32(r3),0,0
    psq_st  f1,32(r4),0,0
    psq_l   f1,40(r3),0,0
    psq_st  f1,40(r4),0,0
    psq_l   f1,48(r3),0,0
    psq_st  f1,48(r4),0,0
    psq_l   f1,56(r3),0,0
    psq_st  f1,56(r4),0,0
    blr
.size PSMTX44Copy, . - PSMTX44Copy

.global C_MTX44Transpose
.balign 4
C_MTX44Transpose:
/* 0x803749DC | size=0xC4 (196 bytes) */
    mflr    r0
    stw     r0,4(r1)
    stwu    r1,-80(r1)
    cmplw   r3,r4
    bne-    .L_803749F8
    addi    r5,r1,16
    b       .L_803749FC
.L_803749F8:
    mr      r5,r4
.L_803749FC:
    lfs     f0,0(r3)
    addi    r0,r1,16
    cmplw   r5,r0
    stfs    f0,0(r5)
    lfs     f0,16(r3)
    stfs    f0,4(r5)
    lfs     f0,32(r3)
    stfs    f0,8(r5)
    lfs     f0,48(r3)
    stfs    f0,12(r5)
    lfs     f0,4(r3)
    stfs    f0,16(r5)
    lfs     f0,20(r3)
    stfs    f0,20(r5)
    lfs     f0,36(r3)
    stfs    f0,24(r5)
    lfs     f0,52(r3)
    stfs    f0,28(r5)
    lfs     f0,8(r3)
    stfs    f0,32(r5)
    lfs     f0,24(r3)
    stfs    f0,36(r5)
    lfs     f0,40(r3)
    stfs    f0,40(r5)
    lfs     f0,56(r3)
    stfs    f0,44(r5)
    lfs     f0,12(r3)
    stfs    f0,48(r5)
    lfs     f0,28(r3)
    stfs    f0,52(r5)
    lfs     f0,44(r3)
    stfs    f0,56(r5)
    lfs     f0,60(r3)
    stfs    f0,60(r5)
    bne-    .L_80374A90
    mr      r3,r0
    bl      PSMTX44Copy
.L_80374A90:
    lwz     r0,84(r1)
    addi    r1,r1,80
    mtlr    r0
    blr
.size C_MTX44Transpose, . - C_MTX44Transpose

.global PSMTX44Transpose
.balign 4
PSMTX44Transpose:
/* 0x80374AA0 | size=0x64 (100 bytes) */
    psq_l   f0,0(r3),0,0
    psq_l   f1,16(r3),0,0
    ps_merge00 f4,f0,f1
    psq_l   f2,8(r3),0,0
    psq_st  f4,0(r4),0,0
    ps_merge11 f5,f0,f1
    psq_l   f3,24(r3),0,0
    psq_st  f5,16(r4),0,0
    ps_merge00 f4,f2,f3
    psq_l   f0,32(r3),0,0
    psq_st  f4,32(r4),0,0
    ps_merge11 f5,f2,f3
    psq_l   f1,48(r3),0,0
    psq_st  f5,48(r4),0,0
    ps_merge00 f4,f0,f1
    psq_l   f2,40(r3),0,0
    psq_st  f4,8(r4),0,0
    ps_merge11 f5,f0,f1
    psq_l   f3,56(r3),0,0
    psq_st  f5,24(r4),0,0
    ps_merge00 f4,f2,f3
    psq_st  f4,40(r4),0,0
    ps_merge11 f5,f2,f3
    psq_st  f5,56(r4),0,0
    blr
.size PSMTX44Transpose, . - PSMTX44Transpose

.global C_MTX44Trans
.balign 4
C_MTX44Trans:
/* 0x80374EF4 | size=0x4C (76 bytes) */
    lfs     f4,-17872(r13)
    stfs    f4,0(r3)
    lfs     f0,-17864(r13)
    stfs    f0,4(r3)
    stfs    f0,8(r3)
    stfs    f1,12(r3)
    stfs    f0,16(r3)
    stfs    f4,20(r3)
    stfs    f0,24(r3)
    stfs    f2,28(r3)
    stfs    f0,32(r3)
    stfs    f0,36(r3)
    stfs    f4,40(r3)
    stfs    f3,44(r3)
    stfs    f0,48(r3)
    stfs    f0,52(r3)
    stfs    f0,56(r3)
    stfs    f4,60(r3)
    blr
.size C_MTX44Trans, . - C_MTX44Trans

.global C_MTX44TransApply
.balign 4
C_MTX44TransApply:
/* 0x80374F7C | size=0x98 (152 bytes) */
    cmplw   r3,r4
    beq-    .L_80374FEC
    lfs     f0,0(r3)
    stfs    f0,0(r4)
    lfs     f0,4(r3)
    stfs    f0,4(r4)
    lfs     f0,8(r3)
    stfs    f0,8(r4)
    lfs     f0,16(r3)
    stfs    f0,16(r4)
    lfs     f0,20(r3)
    stfs    f0,20(r4)
    lfs     f0,24(r3)
    stfs    f0,24(r4)
    lfs     f0,32(r3)
    stfs    f0,32(r4)
    lfs     f0,36(r3)
    stfs    f0,36(r4)
    lfs     f0,40(r3)
    stfs    f0,40(r4)
    lfs     f0,48(r3)
    stfs    f0,48(r4)
    lfs     f0,52(r3)
    stfs    f0,52(r4)
    lfs     f0,56(r3)
    stfs    f0,56(r4)
    lfs     f0,60(r3)
    stfs    f0,60(r4)
.L_80374FEC:
    lfs     f0,12(r3)
    fadds   f0,f0,f1
    stfs    f0,12(r4)
    lfs     f0,28(r3)
    fadds   f0,f0,f2
    stfs    f0,28(r4)
    lfs     f0,44(r3)
    fadds   f0,f0,f3
    stfs    f0,44(r4)
    blr
.size C_MTX44TransApply, . - C_MTX44TransApply

.global PSMTX44TransApply
.balign 4
PSMTX44TransApply:
/* 0x80375014 | size=0x5C (92 bytes) */
    psq_l   f4,0(r3),0,0
    frsp    f1,f1
    psq_l   f5,8(r3),0,0
    frsp    f2,f2
    psq_l   f6,16(r3),0,0
    frsp    f3,f3
    psq_l   f7,24(r3),0,0
    psq_st  f4,0(r4),0,0
    ps_sum1 f5,f1,f5,f5
    psq_l   f4,40(r3),0,0
    psq_st  f6,16(r4),0,0
    ps_sum1 f7,f2,f7,f7
    psq_l   f8,32(r3),0,0
    psq_st  f5,8(r4),0,0
    ps_sum1 f4,f3,f4,f4
    psq_st  f7,24(r4),0,0
    psq_st  f8,32(r4),0,0
    psq_l   f5,48(r3),0,0
    psq_l   f6,56(r3),0,0
    psq_st  f4,40(r4),0,0
    psq_st  f5,48(r4),0,0
    psq_st  f6,56(r4),0,0
    blr
.size PSMTX44TransApply, . - PSMTX44TransApply

.global C_MTX44Scale
.balign 4
C_MTX44Scale:
/* 0x80375070 | size=0x4C (76 bytes) */
    stfs    f1,0(r3)
    lfs     f0,-17864(r13)
    stfs    f0,4(r3)
    stfs    f0,8(r3)
    stfs    f0,12(r3)
    stfs    f0,16(r3)
    stfs    f2,20(r3)
    stfs    f0,24(r3)
    stfs    f0,28(r3)
    stfs    f0,32(r3)
    stfs    f0,36(r3)
    stfs    f3,40(r3)
    stfs    f0,44(r3)
    stfs    f0,48(r3)
    stfs    f0,52(r3)
    stfs    f0,56(r3)
    lfs     f0,-17872(r13)
    stfs    f0,60(r3)
    blr
.size C_MTX44Scale, . - C_MTX44Scale

.global C_MTX44ScaleApply
.balign 4
C_MTX44ScaleApply:
/* 0x803750F0 | size=0xB4 (180 bytes) */
    lfs     f0,0(r3)
    fmuls   f0,f0,f1
    stfs    f0,0(r4)
    lfs     f0,4(r3)
    fmuls   f0,f0,f1
    stfs    f0,4(r4)
    lfs     f0,8(r3)
    fmuls   f0,f0,f1
    stfs    f0,8(r4)
    lfs     f0,12(r3)
    fmuls   f0,f0,f1
    stfs    f0,12(r4)
    lfs     f0,16(r3)
    fmuls   f0,f0,f2
    stfs    f0,16(r4)
    lfs     f0,20(r3)
    fmuls   f0,f0,f2
    stfs    f0,20(r4)
    lfs     f0,24(r3)
    fmuls   f0,f0,f2
    stfs    f0,24(r4)
    lfs     f0,28(r3)
    fmuls   f0,f0,f2
    stfs    f0,28(r4)
    lfs     f0,32(r3)
    fmuls   f0,f0,f3
    stfs    f0,32(r4)
    lfs     f0,36(r3)
    fmuls   f0,f0,f3
    stfs    f0,36(r4)
    lfs     f0,40(r3)
    fmuls   f0,f0,f3
    stfs    f0,40(r4)
    lfs     f0,44(r3)
    fmuls   f0,f0,f3
    stfs    f0,44(r4)
    lfs     f0,48(r3)
    stfs    f0,48(r4)
    lfs     f0,52(r3)
    stfs    f0,52(r4)
    lfs     f0,56(r3)
    stfs    f0,56(r4)
    lfs     f0,60(r3)
    stfs    f0,60(r4)
    blr
.size C_MTX44ScaleApply, . - C_MTX44ScaleApply

.global PSMTX44ScaleApply
.balign 4
PSMTX44ScaleApply:
/* 0x803751A4 | size=0x68 (104 bytes) */
    psq_l   f4,0(r3),0,0
    frsp    f1,f1
    psq_l   f5,8(r3),0,0
    frsp    f2,f2
    psq_l   f6,16(r3),0,0
    ps_muls0 f4,f4,f1
    psq_l   f7,24(r3),0,0
    ps_muls0 f5,f5,f1
    psq_l   f8,32(r3),0,0
    frsp    f3,f3
    psq_st  f4,0(r4),0,0
    ps_muls0 f6,f6,f2
    psq_l   f9,40(r3),0,0
    psq_st  f5,8(r4),0,0
    ps_muls0 f7,f7,f2
    psq_l   f10,48(r3),0,0
    psq_st  f6,16(r4),0,0
    ps_muls0 f8,f8,f3
    psq_l   f11,56(r3),0,0
    psq_st  f7,24(r4),0,0
    ps_muls0 f9,f9,f3
    psq_st  f8,32(r4),0,0
    psq_st  f9,40(r4),0,0
    psq_st  f10,48(r4),0,0
    psq_st  f11,56(r4),0,0
    blr
.size PSMTX44ScaleApply, . - PSMTX44ScaleApply

.global C_MTX44RotRad
.balign 4
C_MTX44RotRad:
/* 0x8037520C | size=0x70 (112 bytes) */
    mflr    r0
    stw     r0,4(r1)
    stwu    r1,-40(r1)
    stfd    f31,32(r1)
    stw     r31,28(r1)
    stw     r30,24(r1)
    fmr     f31,f1
    mr      r30,r3
    mr      r31,r4
    fmr     f1,f31
    bl      sinf
    fmr     f0,f1
    fmr     f1,f31
    fmr     f31,f0
    bl      cosf
    fmr     f0,f1
    mr      r3,r30
    fmr     f1,f31
    mr      r4,r31
    fmr     f2,f0
    bl      C_MTX44RotTrig
    lwz     r0,44(r1)
    lfd     f31,32(r1)
    lwz     r31,28(r1)
    lwz     r30,24(r1)
    addi    r1,r1,40
    mtlr    r0
    blr
.size C_MTX44RotRad, . - C_MTX44RotRad

.global PSMTX44RotRad
.balign 4
PSMTX44RotRad:
/* 0x8037527C | size=0x70 (112 bytes) */
    mflr    r0
    stw     r0,4(r1)
    stwu    r1,-40(r1)
    stfd    f31,32(r1)
    stw     r31,28(r1)
    stw     r30,24(r1)
    fmr     f31,f1
    mr      r30,r3
    mr      r31,r4
    fmr     f1,f31
    bl      sinf
    fmr     f0,f1
    fmr     f1,f31
    fmr     f31,f0
    bl      cosf
    fmr     f0,f1
    mr      r3,r30
    fmr     f1,f31
    mr      r4,r31
    fmr     f2,f0
    bl      PSMTX44RotTrig
    lwz     r0,44(r1)
    lfd     f31,32(r1)
    lwz     r31,28(r1)
    lwz     r30,24(r1)
    addi    r1,r1,40
    mtlr    r0
    blr
.size PSMTX44RotRad, . - PSMTX44RotRad

.global PSMTX44RotTrig
.balign 4
PSMTX44RotTrig:
/* 0x80375408 | size=0xD4 (212 bytes) */
    lfs     f4,-17864(r13)
    lfs     f3,-17872(r13)
    frsp    f6,f1
    ori     r0,r4,32
    frsp    f5,f2
    cmplwi  r0,120
    beq-    .L_80375438
    cmplwi  r0,121
    beq-    .L_8037546C
    cmplwi  r0,122
    beq-    .L_803754A4
    b       .L_803754D8
.L_80375438:
    psq_st  f3,0(r3),1,0
    psq_st  f4,4(r3),0,0
    ps_neg  f0,f6
    psq_st  f4,12(r3),0,0
    ps_merge00 f1,f6,f5
    psq_st  f4,28(r3),0,0
    ps_merge00 f0,f5,f0
    psq_st  f4,44(r3),0,0
    psq_st  f4,52(r3),0,0
    psq_st  f1,36(r3),0,0
    psq_st  f0,20(r3),0,0
    psq_st  f3,60(r3),1,0
    b       .L_803754D8
.L_8037546C:
    ps_merge00 f1,f5,f4
    psq_st  f4,48(r3),0,0
    ps_neg  f0,f6
    psq_st  f4,24(r3),0,0
    ps_merge00 f3,f4,f3
    psq_st  f1,0(r3),0,0
    ps_merge00 f0,f0,f4
    ps_merge00 f2,f6,f4
    psq_st  f3,16(r3),0,0
    psq_st  f2,8(r3),0,0
    psq_st  f0,32(r3),0,0
    psq_st  f1,40(r3),0,0
    psq_st  f3,56(r3),0,0
    b       .L_803754D8
.L_803754A4:
    psq_st  f4,8(r3),0,0
    ps_neg  f0,f6
    psq_st  f4,24(r3),0,0
    ps_merge00 f1,f6,f5
    psq_st  f4,32(r3),0,0
    ps_merge00 f2,f3,f4
    psq_st  f4,48(r3),0,0
    ps_merge00 f3,f4,f3
    psq_st  f1,16(r3),0,0
    ps_merge00 f0,f5,f0
    psq_st  f2,40(r3),0,0
    psq_st  f3,56(r3),0,0
    psq_st  f0,0(r3),0,0
.L_803754D8:
    blr
.size PSMTX44RotTrig, . - PSMTX44RotTrig

.global __PSMTX44RotAxisRadInternal
.balign 4
__PSMTX44RotAxisRadInternal:
/* 0x80375608 | size=0xBC (188 bytes) */
    lfs     f10,-17856(r13)
    lfs     f9,-17848(r13)
    frsp    f11,f2
    psq_l   f2,0(r4),0,0
    frsp    f12,f1
    lfs     f3,8(r4)
    ps_mul  f4,f2,f2
    fadds   f8,f10,f10
    ps_madd f5,f3,f3,f4
    fsubs   f1,f10,f10
    ps_sum0 f6,f5,f3,f4
    fsubs   f0,f8,f11
    frsqrte f7,f6
    ps_merge00 f8,f1,f8
    fmuls   f4,f7,f7
    fmuls   f5,f7,f10
    psq_st  f1,48(r3),0,0
    fnmsubs f4,f4,f6,f9
    fmuls   f7,f4,f5
    psq_st  f8,56(r3),0,0
    ps_merge00 f11,f11,f11
    ps_muls0 f2,f2,f7
    ps_muls0 f3,f3,f7
    ps_muls0 f6,f2,f0
    ps_muls0 f10,f2,f12
    ps_muls0 f7,f3,f0
    ps_muls1 f5,f6,f2
    ps_muls0 f4,f6,f2
    ps_muls0 f6,f6,f3
    fnmsubs f0,f3,f12,f5
    fmadds  f8,f3,f12,f5
    ps_neg  f2,f10
    ps_sum0 f9,f6,f1,f10
    ps_sum0 f4,f4,f0,f11
    ps_sum1 f5,f11,f8,f5
    ps_sum0 f0,f2,f1,f6
    psq_st  f9,8(r3),0,0
    ps_sum0 f2,f6,f6,f2
    psq_st  f4,0(r3),0,0
    ps_muls0 f7,f7,f3
    psq_st  f5,16(r3),0,0
    ps_sum1 f6,f10,f2,f6
    psq_st  f0,24(r3),0,0
    ps_sum0 f7,f7,f1,f11
    psq_st  f6,32(r3),0,0
    psq_st  f7,40(r3),0,0
    blr
.size __PSMTX44RotAxisRadInternal, . - __PSMTX44RotAxisRadInternal

.global PSMTX44RotAxisRad
.balign 4
PSMTX44RotAxisRad:
/* 0x803756C4 | size=0x70 (112 bytes) */
    mflr    r0
    stw     r0,4(r1)
    stwu    r1,-40(r1)
    stfd    f31,32(r1)
    stw     r31,28(r1)
    stw     r30,24(r1)
    fmr     f31,f1
    mr      r30,r3
    mr      r31,r4
    fmr     f1,f31
    bl      sinf
    fmr     f0,f1
    fmr     f1,f31
    fmr     f31,f0
    bl      cosf
    fmr     f0,f1
    mr      r3,r30
    fmr     f1,f31
    mr      r4,r31
    fmr     f2,f0
    bl      __PSMTX44RotAxisRadInternal
    lwz     r0,44(r1)
    lfd     f31,32(r1)
    lwz     r31,28(r1)
    lwz     r30,24(r1)
    addi    r1,r1,40
    mtlr    r0
    blr
.size PSMTX44RotAxisRad, . - PSMTX44RotAxisRad

#
# === mtxvec.o ===
#

.global C_MTXMultVec
.balign 4
C_MTXMultVec:
/* 0x80373AA8 | size=0x94 (148 bytes) */
    lfs     f10,0(r4)
    lfs     f0,0(r3)
    lfs     f2,16(r3)
    lfs     f9,4(r4)
    fmuls   f1,f0,f10
    lfs     f0,4(r3)
    fmuls   f7,f2,f10
    lfs     f2,20(r3)
    fmuls   f0,f0,f9
    fmuls   f6,f2,f9
    lfs     f4,32(r3)
    lfs     f3,36(r3)
    lfs     f11,8(r4)
    lfs     f2,8(r3)
    lfs     f8,24(r3)
    fadds   f0,f1,f0
    fmuls   f1,f2,f11
    lfs     f5,40(r3)
    fmuls   f4,f4,f10
    fmuls   f3,f3,f9
    fmuls   f8,f8,f11
    fadds   f6,f7,f6
    lfs     f2,12(r3)
    fadds   f0,f1,f0
    fmuls   f5,f5,f11
    fadds   f1,f4,f3
    fadds   f3,f8,f6
    lfs     f4,28(r3)
    fadds   f0,f2,f0
    lfs     f2,44(r3)
    fadds   f1,f5,f1
    fadds   f3,f4,f3
    stfs    f0,0(r5)
    fadds   f0,f2,f1
    stfs    f3,4(r5)
    stfs    f0,8(r5)
    blr
.size C_MTXMultVec, . - C_MTXMultVec

.global PSMTXMultVec
.balign 4
PSMTXMultVec:
/* 0x80373B3C | size=0x54 (84 bytes) */
    psq_l   f0,0(r4),0,0
    psq_l   f2,0(r3),0,0
    psq_l   f1,8(r4),1,0
    ps_mul  f4,f2,f0
    psq_l   f3,8(r3),0,0
    ps_madd f5,f3,f1,f4
    psq_l   f8,16(r3),0,0
    ps_sum0 f6,f5,f6,f5
    psq_l   f9,24(r3),0,0
    ps_mul  f10,f8,f0
    psq_st  f6,0(r5),1,0
    ps_madd f11,f9,f1,f10
    psq_l   f2,32(r3),0,0
    ps_sum0 f12,f11,f12,f11
    psq_l   f3,40(r3),0,0
    ps_mul  f4,f2,f0
    psq_st  f12,4(r5),1,0
    ps_madd f5,f3,f1,f4
    ps_sum0 f6,f5,f6,f5
    psq_st  f6,8(r5),1,0
    blr
.size PSMTXMultVec, . - PSMTXMultVec

.global PSMTXMultVecArray
.balign 4
PSMTXMultVecArray:
/* 0x80373D94 | size=0x8C (140 bytes) */
    psq_l   f13,0(r3),0,0
    psq_l   f12,16(r3),0,0
    addi    r6,r6,-1
    psq_l   f11,8(r3),0,0
    ps_merge00 f0,f13,f12
    addi    r5,r5,-4
    psq_l   f10,24(r3),0,0
    ps_merge11 f1,f13,f12
    mtctr   r6
    psq_l   f4,32(r3),0,0
    ps_merge00 f2,f11,f10
    psq_l   f5,40(r3),0,0
    ps_merge11 f3,f11,f10
    psq_l   f6,0(r4),0,0
    psq_lu  f7,8(r4),1,0
    ps_madds0 f8,f0,f6,f3
    ps_mul  f9,f4,f6
    ps_madds1 f8,f1,f6,f8
    ps_madd f10,f5,f7,f9
.L_80373DE0:
    psq_lu  f6,4(r4),0,0
    ps_madds0 f12,f2,f7,f8
    psq_lu  f7,8(r4),1,0
    ps_sum0 f13,f10,f9,f10
    ps_madds0 f8,f0,f6,f3
    ps_mul  f9,f4,f6
    psq_stu f12,4(r5),0,0
    ps_madds1 f8,f1,f6,f8
    psq_stu f13,8(r5),1,0
    ps_madd f10,f5,f7,f9
    bdnz+   .L_80373DE0
    ps_madds0 f12,f2,f7,f8
    ps_sum0 f13,f10,f9,f10
    psq_stu f12,4(r5),0,0
    psq_stu f13,8(r5),1,0
    blr
.size PSMTXMultVecArray, . - PSMTXMultVecArray

.global C_MTXMultVecSR
.balign 4
C_MTXMultVecSR:
/* 0x80373E20 | size=0x7C (124 bytes) */
    lfs     f10,0(r4)
    lfs     f0,0(r3)
    lfs     f2,16(r3)
    lfs     f9,4(r4)
    fmuls   f1,f0,f10
    lfs     f0,4(r3)
    fmuls   f7,f2,f10
    lfs     f2,20(r3)
    fmuls   f0,f0,f9
    fmuls   f6,f2,f9
    lfs     f4,32(r3)
    lfs     f3,36(r3)
    lfs     f11,8(r4)
    lfs     f2,8(r3)
    lfs     f8,24(r3)
    fadds   f0,f1,f0
    fmuls   f1,f2,f11
    lfs     f5,40(r3)
    fmuls   f4,f4,f10
    fmuls   f2,f3,f9
    fadds   f0,f1,f0
    fmuls   f8,f8,f11
    fadds   f3,f7,f6
    fmuls   f1,f5,f11
    stfs    f0,0(r5)
    fadds   f0,f4,f2
    fadds   f2,f8,f3
    fadds   f0,f1,f0
    stfs    f2,4(r5)
    stfs    f0,8(r5)
    blr
.size C_MTXMultVecSR, . - C_MTXMultVecSR

.global PSMTXMultVecSR
.balign 4
PSMTXMultVecSR:
/* 0x80373E9C | size=0x54 (84 bytes) */
    psq_l   f0,0(r3),0,0
    psq_l   f6,0(r4),0,0
    psq_l   f2,16(r3),0,0
    ps_mul  f8,f0,f6
    psq_l   f4,32(r3),0,0
    ps_mul  f10,f2,f6
    psq_l   f7,8(r4),1,0
    ps_mul  f12,f4,f6
    psq_l   f3,24(r3),0,0
    ps_sum0 f8,f8,f8,f8
    psq_l   f5,40(r3),0,0
    ps_sum0 f10,f10,f10,f10
    psq_l   f1,8(r3),0,0
    ps_sum0 f12,f12,f12,f12
    ps_madd f9,f1,f7,f8
    psq_st  f9,0(r5),1,0
    ps_madd f11,f3,f7,f10
    psq_st  f11,4(r5),1,0
    ps_madd f13,f5,f7,f12
    psq_st  f13,8(r5),1,0
    blr
.size PSMTXMultVecSR, . - PSMTXMultVecSR

.global PSMTXMultVecArraySR
.balign 4
PSMTXMultVecArraySR:
/* 0x803740AC | size=0x88 (136 bytes) */
    psq_l   f13,0(r3),0,0
    psq_l   f12,16(r3),0,0
    addi    r6,r6,-1
    psq_l   f11,8(r3),1,0
    ps_merge00 f0,f13,f12
    addi    r5,r5,-4
    psq_l   f10,24(r3),1,0
    ps_merge11 f1,f13,f12
    mtctr   r6
    psq_l   f3,32(r3),0,0
    ps_merge00 f2,f11,f10
    psq_l   f4,40(r3),1,0
    psq_l   f6,0(r4),0,0
    psq_lu  f7,8(r4),1,0
    ps_muls0 f8,f0,f6
    ps_mul  f9,f3,f6
    ps_madds1 f8,f1,f6,f8
    ps_madd f10,f4,f7,f9
.L_803740F4:
    psq_lu  f6,4(r4),0,0
    ps_madds0 f12,f2,f7,f8
    psq_lu  f7,8(r4),1,0
    ps_sum0 f13,f10,f9,f9
    ps_muls0 f8,f0,f6
    ps_mul  f9,f3,f6
    psq_stu f12,4(r5),0,0
    ps_madds1 f8,f1,f6,f8
    psq_stu f13,8(r5),1,0
    ps_madd f10,f4,f7,f9
    bdnz+   .L_803740F4
    ps_madds0 f12,f2,f7,f8
    ps_sum0 f13,f10,f9,f9
    psq_stu f12,4(r5),0,0
    psq_stu f13,8(r5),1,0
    blr
.size PSMTXMultVecArraySR, . - PSMTXMultVecArraySR

#
# === vec.o ===
#

.global C_VECNormalize
.balign 4
C_VECNormalize:
/* 0x8025AA90 | size=0xC8 (200 bytes) */
    stwu    r1,-24(r1)
    lfs     f1,0(r3)
    lfs     f0,4(r3)
    fmuls   f2,f1,f1
    lfs     f3,8(r3)
    fmuls   f1,f0,f0
    lfs     f0,-18512(r13)
    fmuls   f3,f3,f3
    fadds   f1,f2,f1
    fadds   f1,f3,f1
    fcmpo   cr0,f1,f0
    fmr     f4,f1
    ble-    .L_8025AB20
    frsqrte f1,f4
    lfd     f3,-18504(r13)
    lfd     f2,-18496(r13)
    fmul    f0,f1,f1
    fmul    f1,f3,f1
    fmul    f0,f4,f0
    fsub    f0,f2,f0
    fmul    f1,f1,f0
    fmul    f0,f1,f1
    fmul    f1,f3,f1
    fmul    f0,f4,f0
    fsub    f0,f2,f0
    fmul    f1,f1,f0
    fmul    f0,f1,f1
    fmul    f1,f3,f1
    fmul    f0,f4,f0
    fsub    f0,f2,f0
    fmul    f0,f1,f0
    fmul    f0,f4,f0
    frsp    f0,f0
    stfs    f0,16(r1)
    lfs     f2,16(r1)
    b       .L_8025AB24
.L_8025AB20:
    fmr     f2,f4
.L_8025AB24:
    lfs     f1,-18488(r13)
    lfs     f0,0(r3)
    fdivs   f1,f1,f2
    fmuls   f0,f0,f1
    stfs    f0,0(r4)
    lfs     f0,4(r3)
    fmuls   f0,f0,f1
    stfs    f0,4(r4)
    lfs     f0,8(r3)
    fmuls   f0,f0,f1
    stfs    f0,8(r4)
    addi    r1,r1,24
    blr
.size C_VECNormalize, . - C_VECNormalize

.global PSVECNormalize
.balign 4
PSVECNormalize:
/* 0x8025AB58 | size=0x44 (68 bytes) */
    lfs     f0,-18484(r13)
    lfs     f1,-18480(r13)
    psq_l   f2,0(r3),0,0
    ps_mul  f5,f2,f2
    psq_l   f3,8(r3),1,0
    ps_madd f4,f3,f3,f5
    ps_sum0 f4,f4,f3,f5
    frsqrte f5,f4
    fmuls   f6,f5,f5
    fmuls   f0,f5,f0
    fnmsubs f6,f6,f4,f1
    fmuls   f5,f6,f0
    ps_muls0 f2,f2,f5
    psq_st  f2,0(r4),0,0
    ps_muls0 f3,f3,f5
    psq_st  f3,8(r4),1,0
    blr
.size PSVECNormalize, . - PSVECNormalize

.global C_VECMag
.balign 4
C_VECMag:
/* 0x8025ABD8 | size=0x94 (148 bytes) */
    stwu    r1,-24(r1)
    lfs     f1,0(r3)
    lfs     f0,4(r3)
    fmuls   f2,f1,f1
    lfs     f3,8(r3)
    fmuls   f1,f0,f0
    lfs     f0,-18512(r13)
    fmuls   f3,f3,f3
    fadds   f1,f2,f1
    fadds   f1,f3,f1
    fcmpo   cr0,f1,f0
    ble-    .L_8025AC64
    frsqrte f2,f1
    lfd     f4,-18504(r13)
    lfd     f3,-18496(r13)
    fmul    f0,f2,f2
    fmul    f2,f4,f2
    fmul    f0,f1,f0
    fsub    f0,f3,f0
    fmul    f2,f2,f0
    fmul    f0,f2,f2
    fmul    f2,f4,f2
    fmul    f0,f1,f0
    fsub    f0,f3,f0
    fmul    f2,f2,f0
    fmul    f0,f2,f2
    fmul    f2,f4,f2
    fmul    f0,f1,f0
    fsub    f0,f3,f0
    fmul    f0,f2,f0
    fmul    f0,f1,f0
    frsp    f0,f0
    stfs    f0,20(r1)
    lfs     f1,20(r1)
    b       .L_8025AC64
.L_8025AC64:
    addi    r1,r1,24
    blr
.size C_VECMag, . - C_VECMag

.global PSVECMag
.balign 4
PSVECMag:
/* 0x8025AC6C | size=0x44 (68 bytes) */
    lfs     f4,-18484(r13)
    psq_l   f0,0(r3),0,0
    ps_mul  f0,f0,f0
    lfs     f1,8(r3)
    fsubs   f2,f4,f4
    ps_madd f1,f1,f1,f0
    ps_sum0 f1,f1,f0,f0
    fcmpu   cr0,f1,f2
    beq-    .L_8025ACAC
    frsqrte f0,f1
    lfs     f3,-18480(r13)
    fmuls   f2,f0,f0
    fmuls   f0,f0,f4
    fnmsubs f2,f2,f1,f3
    fmuls   f0,f2,f0
    fmuls   f1,f1,f0
.L_8025ACAC:
    blr
.size PSVECMag, . - PSVECMag

.global C_VECCrossProduct
.balign 4
C_VECCrossProduct:
/* 0x8025AD00 | size=0x4C (76 bytes) */
    lfs     f1,8(r3)
    lfs     f6,4(r4)
    lfs     f5,0(r4)
    lfs     f7,4(r3)
    fmuls   f0,f1,f6
    lfs     f3,8(r4)
    fmuls   f4,f1,f5
    lfs     f2,0(r3)
    fmuls   f1,f7,f3
    fmuls   f3,f2,f3
    fmuls   f2,f2,f6
    fsubs   f0,f1,f0
    fmuls   f1,f7,f5
    fsubs   f3,f4,f3
    stfs    f0,0(r5)
    fsubs   f0,f2,f1
    stfs    f3,4(r5)
    stfs    f0,8(r5)
    blr
.size C_VECCrossProduct, . - C_VECCrossProduct

.global C_VECHalfAngle
.balign 4
C_VECHalfAngle:
/* 0x8025AD88 | size=0xD8 (216 bytes) */
    mflr    r0
    stw     r0,4(r1)
    stwu    r1,-64(r1)
    stw     r31,60(r1)
    mr      r31,r5
    lfs     f0,0(r3)
    fneg    f0,f0
    stfs    f0,44(r1)
    lfs     f0,4(r3)
    fneg    f0,f0
    stfs    f0,48(r1)
    lfs     f0,8(r3)
    addi    r3,r1,44
    fneg    f0,f0
    stfs    f0,52(r1)
    lfs     f0,0(r4)
    fneg    f0,f0
    stfs    f0,32(r1)
    lfs     f0,4(r4)
    fneg    f0,f0
    stfs    f0,36(r1)
    lfs     f0,8(r4)
    mr      r4,r3
    fneg    f0,f0
    stfs    f0,40(r1)
    bl      PSVECNormalize
    addi    r3,r1,32
    mr      r4,r3
    bl      PSVECNormalize
    addi    r3,r1,44
    addi    r4,r1,32
    addi    r5,r1,20
    bl      PSVECAdd
    addi    r3,r1,20
    mr      r4,r3
    bl      PSVECDotProduct
    lfs     f0,-18512(r13)
    fcmpo   cr0,f1,f0
    ble-    .L_8025AE34
    addi    r3,r1,20
    mr      r4,r31
    bl      PSVECNormalize
    b       .L_8025AE4C
.L_8025AE34:
    lwz     r3,20(r1)
    lwz     r0,24(r1)
    stw     r3,0(r31)
    stw     r0,4(r31)
    lwz     r0,28(r1)
    stw     r0,8(r31)
.L_8025AE4C:
    lwz     r0,68(r1)
    lwz     r31,60(r1)
    addi    r1,r1,64
    mtlr    r0
    blr
.size C_VECHalfAngle, . - C_VECHalfAngle

.global C_VECReflect
.balign 4
C_VECReflect:
/* 0x8025AE60 | size=0xD4 (212 bytes) */
    mflr    r0
    stw     r0,4(r1)
    stwu    r1,-56(r1)
    stw     r31,52(r1)
    stw     r30,48(r1)
    mr      r30,r4
    mr      r31,r5
    lfs     f0,0(r3)
    fneg    f0,f0
    stfs    f0,32(r1)
    lfs     f0,4(r3)
    fneg    f0,f0
    stfs    f0,36(r1)
    lfs     f0,8(r3)
    addi    r3,r1,32
    mr      r4,r3
    fneg    f0,f0
    stfs    f0,40(r1)
    bl      PSVECNormalize
    mr      r3,r30
    addi    r4,r1,20
    bl      PSVECNormalize
    addi    r3,r1,32
    addi    r4,r1,20
    bl      PSVECDotProduct
    lfs     f3,-18476(r13)
    mr      r3,r31
    lfs     f2,20(r1)
    mr      r4,r31
    lfs     f0,32(r1)
    fmuls   f2,f3,f2
    fmuls   f2,f2,f1
    fsubs   f0,f2,f0
    stfs    f0,0(r31)
    lfs     f2,24(r1)
    lfs     f0,36(r1)
    fmuls   f2,f3,f2
    fmuls   f2,f2,f1
    fsubs   f0,f2,f0
    stfs    f0,4(r31)
    lfs     f2,28(r1)
    lfs     f0,40(r1)
    fmuls   f2,f3,f2
    fmuls   f1,f2,f1
    fsubs   f0,f1,f0
    stfs    f0,8(r31)
    bl      PSVECNormalize
    lwz     r0,60(r1)
    lwz     r31,52(r1)
    lwz     r30,48(r1)
    addi    r1,r1,56
    mtlr    r0
    blr
.size C_VECReflect, . - C_VECReflect

.global C_VECDistance
.balign 4
C_VECDistance:
/* 0x8025AF98 | size=0xAC (172 bytes) */
    stwu    r1,-40(r1)
    lfs     f3,0(r3)
    lfs     f1,0(r4)
    lfs     f2,4(r3)
    lfs     f0,4(r4)
    fsubs   f3,f3,f1
    lfs     f1,8(r3)
    fsubs   f4,f2,f0
    lfs     f0,8(r4)
    fmuls   f2,f3,f3
    fsubs   f3,f1,f0
    lfs     f0,-18512(r13)
    fmuls   f1,f4,f4
    fmuls   f3,f3,f3
    fadds   f1,f2,f1
    fadds   f1,f3,f1
    fcmpo   cr0,f1,f0
    ble-    .L_8025B03C
    frsqrte f2,f1
    lfd     f4,-18504(r13)
    lfd     f3,-18496(r13)
    fmul    f0,f2,f2
    fmul    f2,f4,f2
    fmul    f0,f1,f0
    fsub    f0,f3,f0
    fmul    f2,f2,f0
    fmul    f0,f2,f2
    fmul    f2,f4,f2
    fmul    f0,f1,f0
    fsub    f0,f3,f0
    fmul    f2,f2,f0
    fmul    f0,f2,f2
    fmul    f2,f4,f2
    fmul    f0,f1,f0
    fsub    f0,f3,f0
    fmul    f0,f2,f0
    fmul    f0,f1,f0
    frsp    f0,f0
    stfs    f0,20(r1)
    lfs     f1,20(r1)
    b       .L_8025B03C
.L_8025B03C:
    addi    r1,r1,40
    blr
.size C_VECDistance, . - C_VECDistance

.global PSVECDistance
.balign 4
PSVECDistance:
/* 0x8025B044 | size=0x54 (84 bytes) */
    psq_l   f0,4(r3),0,0
    psq_l   f1,4(r4),0,0
    ps_sub  f2,f0,f1
    psq_l   f0,0(r3),0,0
    psq_l   f1,0(r4),0,0
    ps_mul  f2,f2,f2
    ps_sub  f0,f0,f1
    lfs     f3,-18484(r13)
    ps_madd f1,f0,f0,f2
    fsubs   f0,f3,f3
    ps_sum0 f1,f1,f2,f2
    fcmpu   cr0,f0,f1
    beq-    .L_8025B094
    lfs     f4,-18480(r13)
    frsqrte f0,f1
    fmuls   f2,f0,f0
    fmuls   f0,f0,f3
    fnmsubs f2,f2,f1,f4
    fmuls   f0,f2,f0
    fmuls   f1,f1,f0
.L_8025B094:
    blr
.size PSVECDistance, . - PSVECDistance

# ============================================================
# dvd.a
# ============================================================

#
# === dvd.o ===
#

.global DVDInit
.balign 4
DVDInit:
/* 0x8025C2A4 | size=0xD8 (216 bytes) */
    mflr    r0
    stw     r0,4(r1)
    stwu    r1,-16(r1)
    stw     r31,12(r1)
    stw     r30,8(r1)
    lwz     r0,-23404(r13)
    cmpwi   r0,0
    bne-    .L_8025C364
    lwz     r3,-27792(r13)
    bl      OSRegisterVersion
    li      r30,1
    stw     r30,-23404(r13)
    bl      __DVDFSInit
    bl      __DVDClearWaitingQueue
    bl      __DVDInitWA
    lis     r0,-32768
    li      r31,0
    stw     r0,-23472(r13)
    lis     r3,-32730
    addi    r4,r3,3168
    stw     r31,-23408(r13)
    li      r3,21
    stw     r0,-23476(r13)
    bl      __OSSetInterruptHandler
    li      r3,1024
    bl      __OSUnmaskInterrupts
    addi    r3,r13,-23488
    bl      OSInitThreadQueue
    lis     r3,-13312
    li      r0,42
    stw     r0,24576(r3)
    stw     r31,24580(r3)
    lwz     r3,-23472(r13)
    addi    r3,r3,32
    lwz     r3,0(r3)
    addis   r0,r3,6880
    cmplwi  r0,31778
    bne-    .L_8025C354
    lis     r3,-32700
    crclr   4*cr1+eq
    addi    r3,r3,-14504
    bl      OSReport
    bl      __fstLoad
    b       .L_8025C364
.L_8025C354:
    addis   r0,r3,-3349
    cmplwi  r0,59998
    beq-    .L_8025C364
    stw     r30,-23412(r13)
.L_8025C364:
    lwz     r0,20(r1)
    lwz     r31,12(r1)
    lwz     r30,8(r1)
    addi    r1,r1,16
    mtlr    r0
    blr
.size DVDInit, . - DVDInit

.global stateReadingFST
.balign 4
stateReadingFST:
/* 0x8025C37C | size=0x94 (148 bytes) */
    mflr    r0
    lis     r3,-32730
    stw     r0,4(r1)
    addi    r0,r3,-15492
    lis     r3,-32694
    stwu    r1,-16(r1)
    addi    r3,r3,-17248
    stw     r31,12(r1)
    addi    r31,r3,8
    stw     r0,-23392(r13)
    lwz     r4,-23472(r13)
    lwz     r0,0(r31)
    lwz     r3,60(r4)
    cmplw   r3,r0
    bge-    .L_8025C3D0
    lis     r3,-32700
    crclr   4*cr1+eq
    addi    r5,r3,-14492
    addi    r3,r13,-27780
    li      r4,661
    bl      OSPanic
.L_8025C3D0:
    lis     r3,-32694
    lwz     r6,0(r31)
    addi    r5,r3,-17248
    lwz     r7,-23472(r13)
    lis     r4,-32730
    lwz     r5,4(r5)
    addi    r0,r6,31
    lwz     r3,56(r7)
    addi    r6,r4,-15344
    clrrwi  r4,r0,5
    bl      DVDLowRead
    lwz     r0,20(r1)
    lwz     r31,12(r1)
    addi    r1,r1,16
    mtlr    r0
    blr
.size stateReadingFST, . - stateReadingFST

.global cbForStateReadingFST
.balign 4
cbForStateReadingFST:
/* 0x8025C410 | size=0x80 (128 bytes) */
    mflr    r0
    cmplwi  r3,16
    stw     r0,4(r1)
    stwu    r1,-24(r1)
    stw     r31,20(r1)
    bne-    .L_8025C430
    bl      stateTimeout
    b       .L_8025C47C
.L_8025C430:
    clrlwi. r0,r3,31
    beq-    .L_8025C478
    li      r31,0
    stw     r31,-23428(r13)
    bl      __DVDFSInit
    lis     r3,-32694
    lwz     r4,-23480(r13)
    addi    r0,r3,-17184
    stw     r0,-23480(r13)
    stw     r31,12(r4)
    lwz     r12,40(r4)
    cmplwi  r12,0
    beq-    .L_8025C470
    mtlr    r12
    li      r3,0
    blrl
.L_8025C470:
    bl      stateReady
    b       .L_8025C47C
.L_8025C478:
    bl      stateGettingError
.L_8025C47C:
    lwz     r0,28(r1)
    lwz     r31,20(r1)
    addi    r1,r1,24
    mtlr    r0
    blr
.size cbForStateReadingFST, . - cbForStateReadingFST

.global cbForStateError
.balign 4
cbForStateError:
/* 0x8025C490 | size=0xAC (172 bytes) */
    mflr    r0
    cmplwi  r3,16
    stw     r0,4(r1)
    li      r0,-1
    stwu    r1,-24(r1)
    stw     r31,20(r1)
    lwz     r4,-23480(r13)
    stw     r0,12(r4)
    bne-    .L_8025C4BC
    bl      stateTimeout
    b       .L_8025C528
.L_8025C4BC:
    bl      __DVDPrintFatalMessage
    lis     r3,-32694
    lwz     r31,-23480(r13)
    addi    r0,r3,-17184
    li      r3,1
    stw     r0,-23480(r13)
    stw     r3,-23456(r13)
    lwz     r12,40(r31)
    cmplwi  r12,0
    beq-    .L_8025C4F4
    mtlr    r12
    addi    r4,r31,0
    li      r3,-1
    blrl
.L_8025C4F4:
    lwz     r0,-23448(r13)
    cmplwi  r0,0
    beq-    .L_8025C524
    lwz     r12,-23444(r13)
    li      r0,0
    stw     r0,-23448(r13)
    cmplwi  r12,0
    beq-    .L_8025C524
    mtlr    r12
    addi    r4,r31,0
    li      r3,0
    blrl
.L_8025C524:
    bl      stateReady
.L_8025C528:
    lwz     r0,28(r1)
    lwz     r31,20(r1)
    addi    r1,r1,24
    mtlr    r0
    blr
.size cbForStateError, . - cbForStateError

.global CategorizeError
.balign 4
CategorizeError:
/* 0x8025C5C4 | size=0xB4 (180 bytes) */
    addis   r0,r3,-2
    cmplwi  r0,1024
    bne-    .L_8025C5DC
    stw     r3,-23432(r13)
    li      r3,1
    blr
.L_8025C5DC:
    clrlwi  r4,r3,8
    addis   r0,r4,-6
    cmplwi  r0,10240
    beq-    .L_8025C604
    addis   r0,r4,-2
    cmplwi  r0,14848
    beq-    .L_8025C604
    addis   r0,r4,-11
    cmplwi  r0,23041
    bne-    .L_8025C60C
.L_8025C604:
    li      r3,0
    blr
.L_8025C60C:
    lwz     r3,-23428(r13)
    addi    r0,r3,1
    stw     r0,-23428(r13)
    lwz     r0,-23428(r13)
    cmpwi   r0,2
    bne-    .L_8025C648
    lwz     r0,-23432(r13)
    cmplw   r4,r0
    bne-    .L_8025C63C
    stw     r4,-23432(r13)
    li      r3,1
    blr
.L_8025C63C:
    stw     r4,-23432(r13)
    li      r3,2
    blr
.L_8025C648:
    addis   r0,r4,-3
    stw     r4,-23432(r13)
    cmplwi  r0,4352
    beq-    .L_8025C668
    lwz     r3,-23480(r13)
    lwz     r0,8(r3)
    cmplwi  r0,5
    bne-    .L_8025C670
.L_8025C668:
    li      r3,2
    blr
.L_8025C670:
    li      r3,3
    blr
.size CategorizeError, . - CategorizeError

.global CheckCancel
.balign 4
CheckCancel:
/* 0x8025C678 | size=0x9C (156 bytes) */
    mflr    r0
    stw     r0,4(r1)
    stwu    r1,-24(r1)
    stw     r31,20(r1)
    lwz     r0,-23448(r13)
    cmplwi  r0,0
    beq-    .L_8025C6FC
    lis     r4,-32694
    stw     r3,-23440(r13)
    li      r0,0
    lwz     r31,-23480(r13)
    addi    r3,r4,-17184
    stw     r0,-23448(r13)
    li      r0,10
    stw     r3,-23480(r13)
    stw     r0,12(r31)
    lwz     r12,40(r31)
    cmplwi  r12,0
    beq-    .L_8025C6D4
    mtlr    r12
    addi    r4,r31,0
    li      r3,-3
    blrl
.L_8025C6D4:
    lwz     r12,-23444(r13)
    cmplwi  r12,0
    beq-    .L_8025C6F0
    mtlr    r12
    addi    r4,r31,0
    li      r3,0
    blrl
.L_8025C6F0:
    bl      stateReady
    li      r3,1
    b       .L_8025C700
.L_8025C6FC:
    li      r3,0
.L_8025C700:
    lwz     r0,28(r1)
    lwz     r31,20(r1)
    addi    r1,r1,24
    mtlr    r0
    blr
.size CheckCancel, . - CheckCancel

.global cbForUnrecoveredError
.balign 4
cbForUnrecoveredError:
/* 0x8025C978 | size=0x5C (92 bytes) */
    mflr    r0
    cmplwi  r3,16
    stw     r0,4(r1)
    stwu    r1,-8(r1)
    bne-    .L_8025C9A8
    lis     r3,291
    addi    r3,r3,17768
    bl      __DVDStoreErrorCode
    bl      DVDReset
    li      r3,0
    bl      cbForStateError
    b       .L_8025C9C4
.L_8025C9A8:
    clrlwi. r0,r3,31
    beq-    .L_8025C9B8
    bl      stateGoToRetry
    b       .L_8025C9C4
.L_8025C9B8:
    lis     r3,-32730
    addi    r3,r3,-13868
    bl      DVDLowRequestError
.L_8025C9C4:
    lwz     r0,12(r1)
    addi    r1,r1,8
    mtlr    r0
    blr
.size cbForUnrecoveredError, . - cbForUnrecoveredError

.global cbForUnrecoveredErrorRetry
.balign 4
cbForUnrecoveredErrorRetry:
/* 0x8025C9D4 | size=0x80 (128 bytes) */
    mflr    r0
    cmplwi  r3,16
    stw     r0,4(r1)
    stwu    r1,-8(r1)
    bne-    .L_8025CA04
    lis     r3,291
    addi    r3,r3,17768
    bl      __DVDStoreErrorCode
    bl      DVDReset
    li      r3,0
    bl      cbForStateError
    b       .L_8025CA44
.L_8025CA04:
    rlwinm. r0,r3,0,30,30
    beq-    .L_8025CA28
    lis     r3,291
    addi    r3,r3,17767
    bl      __DVDStoreErrorCode
    lis     r3,-32730
    addi    r3,r3,-15216
    bl      DVDLowStopMotor
    b       .L_8025CA44
.L_8025CA28:
    lis     r3,-13312
    addi    r3,r3,24576
    lwz     r3,32(r3)
    bl      __DVDStoreErrorCode
    lis     r3,-32730
    addi    r3,r3,-15216
    bl      DVDLowStopMotor
.L_8025CA44:
    lwz     r0,12(r1)
    addi    r1,r1,8
    mtlr    r0
    blr
.size cbForUnrecoveredErrorRetry, . - cbForUnrecoveredErrorRetry

.global stateCheckID
.balign 4
stateCheckID:
/* 0x8025CBBC | size=0xE0 (224 bytes) */
    mflr    r0
    lis     r3,-32694
    stw     r0,4(r1)
    stwu    r1,-16(r1)
    stw     r31,12(r1)
    addi    r31,r3,-17248
    lwz     r0,-23452(r13)
    cmpwi   r0,3
    beq-    .L_8025CBE4
    b       .L_8025CC4C
.L_8025CBE4:
    lwz     r4,-23480(r13)
    addi    r3,r31,32
    lwz     r4,36(r4)
    bl      DVDCompareDiskID
    cmpwi   r3,0
    beq-    .L_8025CC3C
    lwz     r3,-23476(r13)
    addi    r4,r31,32
    li      r5,32
    bl      memcpy
    lwz     r4,-23480(r13)
    li      r0,1
    addi    r3,r31,0
    stw     r0,12(r4)
    li      r4,32
    bl      DCInvalidateRange
    lis     r4,-32730
    lwz     r3,-23480(r13)
    addi    r0,r4,-13104
    stw     r0,-23392(r13)
    bl      stateCheckID2a
    b       .L_8025CC88
.L_8025CC3C:
    lis     r3,-32730
    addi    r3,r3,-12892
    bl      DVDLowStopMotor
    b       .L_8025CC88
.L_8025CC4C:
    lwz     r4,-23476(r13)
    addi    r3,r31,32
    li      r5,32
    bl      memcmp
    cmpwi   r3,0
    beq-    .L_8025CC74
    lis     r3,-32730
    addi    r3,r3,-12892
    bl      DVDLowStopMotor
    b       .L_8025CC88
.L_8025CC74:
    lis     r4,-32730
    lwz     r3,-23480(r13)
    addi    r0,r4,-13156
    stw     r0,-23392(r13)
    bl      stateCheckID3
.L_8025CC88:
    lwz     r0,20(r1)
    lwz     r31,12(r1)
    addi    r1,r1,16
    mtlr    r0
    blr
.size stateCheckID, . - stateCheckID

.global cbForStateCheckID2a
.balign 4
cbForStateCheckID2a:
/* 0x8025CD04 | size=0x68 (104 bytes) */
    mflr    r0
    cmplwi  r3,16
    stw     r0,4(r1)
    stwu    r1,-8(r1)
    bne-    .L_8025CD34
    lis     r3,291
    addi    r3,r3,17768
    bl      __DVDStoreErrorCode
    bl      DVDReset
    li      r3,0
    bl      cbForStateError
    b       .L_8025CD5C
.L_8025CD34:
    clrlwi. r0,r3,31
    beq-    .L_8025CD50
    li      r0,0
    lwz     r3,-23480(r13)
    stw     r0,-23428(r13)
    bl      stateCheckID2
    b       .L_8025CD5C
.L_8025CD50:
    lis     r3,-32730
    addi    r3,r3,-14572
    bl      DVDLowRequestError
.L_8025CD5C:
    lwz     r0,12(r1)
    addi    r1,r1,8
    mtlr    r0
    blr
.size cbForStateCheckID2a, . - cbForStateCheckID2a

.global cbForStateCheckID1
.balign 4
cbForStateCheckID1:
/* 0x8025CDA4 | size=0xFC (252 bytes) */
    mflr    r0
    cmplwi  r3,16
    stw     r0,4(r1)
    stwu    r1,-24(r1)
    stw     r31,20(r1)
    bne-    .L_8025CDD8
    lis     r3,291
    addi    r3,r3,17768
    bl      __DVDStoreErrorCode
    bl      DVDReset
    li      r3,0
    bl      cbForStateError
    b       .L_8025CE8C
.L_8025CDD8:
    rlwinm. r0,r3,0,30,30
    beq-    .L_8025CDFC
    lis     r3,291
    addi    r3,r3,17767
    bl      __DVDStoreErrorCode
    lis     r3,-32730
    addi    r3,r3,-15216
    bl      DVDLowStopMotor
    b       .L_8025CE8C
.L_8025CDFC:
    li      r4,0
    stw     r4,-23428(r13)
    lwz     r0,-23448(r13)
    cmplwi  r0,0
    beq-    .L_8025CE74
    li      r0,1
    lwz     r31,-23480(r13)
    stw     r0,-23440(r13)
    lis     r3,-32694
    addi    r3,r3,-17184
    stw     r4,-23448(r13)
    li      r0,10
    stw     r3,-23480(r13)
    stw     r0,12(r31)
    lwz     r12,40(r31)
    cmplwi  r12,0
    beq-    .L_8025CE50
    mtlr    r12
    addi    r4,r31,0
    li      r3,-3
    blrl
.L_8025CE50:
    lwz     r12,-23444(r13)
    cmplwi  r12,0
    beq-    .L_8025CE6C
    mtlr    r12
    addi    r4,r31,0
    li      r3,0
    blrl
.L_8025CE6C:
    bl      stateReady
    li      r4,1
.L_8025CE74:
    cmpwi   r4,0
    bne-    .L_8025CE8C
    lwz     r3,-23480(r13)
    li      r0,6
    stw     r0,12(r3)
    bl      stateMotorStopped
.L_8025CE8C:
    lwz     r0,28(r1)
    lwz     r31,20(r1)
    addi    r1,r1,24
    mtlr    r0
    blr
.size cbForStateCheckID1, . - cbForStateCheckID1

.global cbForStateCheckID2
.balign 4
cbForStateCheckID2:
/* 0x8025CEA0 | size=0xD8 (216 bytes) */
    mflr    r0
    cmplwi  r3,16
    stw     r0,4(r1)
    stwu    r1,-24(r1)
    stw     r31,20(r1)
    bne-    .L_8025CED4
    lis     r3,291
    addi    r3,r3,17768
    bl      __DVDStoreErrorCode
    bl      DVDReset
    li      r3,0
    bl      cbForStateError
    b       .L_8025CF64
.L_8025CED4:
    clrlwi. r0,r3,31
    beq-    .L_8025CF58
    lis     r3,-32730
    lwz     r4,-23472(r13)
    addi    r0,r3,-15492
    li      r5,0
    stw     r0,-23392(r13)
    lis     r3,-32694
    stw     r5,-23428(r13)
    addi    r3,r3,-17248
    addi    r31,r3,8
    lwz     r3,60(r4)
    lwz     r0,0(r31)
    cmplw   r3,r0
    bge-    .L_8025CF28
    lis     r3,-32700
    crclr   4*cr1+eq
    addi    r5,r3,-14492
    addi    r3,r13,-27780
    li      r4,661
    bl      OSPanic
.L_8025CF28:
    lis     r3,-32694
    lwz     r6,0(r31)
    addi    r5,r3,-17248
    lwz     r7,-23472(r13)
    lis     r4,-32730
    lwz     r5,4(r5)
    addi    r0,r6,31
    lwz     r3,56(r7)
    addi    r6,r4,-15344
    clrrwi  r4,r0,5
    bl      DVDLowRead
    b       .L_8025CF64
.L_8025CF58:
    lis     r3,-32730
    addi    r3,r3,-14572
    bl      DVDLowRequestError
.L_8025CF64:
    lwz     r0,28(r1)
    lwz     r31,20(r1)
    addi    r1,r1,24
    mtlr    r0
    blr
.size cbForStateCheckID2, . - cbForStateCheckID2

.global cbForStateCheckID3
.balign 4
cbForStateCheckID3:
/* 0x8025CF78 | size=0xF0 (240 bytes) */
    mflr    r0
    cmplwi  r3,16
    stw     r0,4(r1)
    stwu    r1,-24(r1)
    stw     r31,20(r1)
    bne-    .L_8025CFAC
    lis     r3,291
    addi    r3,r3,17768
    bl      __DVDStoreErrorCode
    bl      DVDReset
    li      r3,0
    bl      cbForStateError
    b       .L_8025D054
.L_8025CFAC:
    clrlwi. r0,r3,31
    beq-    .L_8025D048
    li      r4,0
    stw     r4,-23428(r13)
    lwz     r0,-23448(r13)
    cmplwi  r0,0
    beq-    .L_8025D028
    stw     r4,-23440(r13)
    lis     r3,-32694
    lwz     r31,-23480(r13)
    addi    r3,r3,-17184
    stw     r4,-23448(r13)
    li      r0,10
    stw     r3,-23480(r13)
    stw     r0,12(r31)
    lwz     r12,40(r31)
    cmplwi  r12,0
    beq-    .L_8025D004
    mtlr    r12
    addi    r4,r31,0
    li      r3,-3
    blrl
.L_8025D004:
    lwz     r12,-23444(r13)
    cmplwi  r12,0
    beq-    .L_8025D020
    mtlr    r12
    addi    r4,r31,0
    li      r3,0
    blrl
.L_8025D020:
    bl      stateReady
    li      r4,1
.L_8025D028:
    cmpwi   r4,0
    bne-    .L_8025D054
    lwz     r3,-23480(r13)
    li      r0,1
    stw     r0,12(r3)
    lwz     r3,-23480(r13)
    bl      stateBusy
    b       .L_8025D054
.L_8025D048:
    lis     r3,-32730
    addi    r3,r3,-14572
    bl      DVDLowRequestError
.L_8025D054:
    lwz     r0,28(r1)
    lwz     r31,20(r1)
    addi    r1,r1,24
    mtlr    r0
    blr
.size cbForStateCheckID3, . - cbForStateCheckID3

.global AlarmHandler_dvd
.balign 4
AlarmHandler_dvd:
/* 0x8025D068 | size=0x44 (68 bytes) */
    mflr    r0
    stw     r0,4(r1)
    stwu    r1,-8(r1)
    bl      DVDReset
    lis     r3,-32694
    addi    r3,r3,-17216
    li      r4,32
    bl      DCInvalidateRange
    lis     r4,-32730
    lwz     r3,-23480(r13)
    addi    r0,r4,-11904
    stw     r0,-23392(r13)
    bl      stateCoverClosed_CMD
    lwz     r0,12(r1)
    addi    r1,r1,8
    mtlr    r0
    blr
.size AlarmHandler_dvd, . - AlarmHandler_dvd

.global stateCoverClosed
.balign 4
stateCoverClosed:
/* 0x8025D0AC | size=0xD4 (212 bytes) */
    mflr    r0
    lis     r3,-32694
    stw     r0,4(r1)
    stwu    r1,-16(r1)
    stw     r31,12(r1)
    addi    r31,r3,-17248
    lwz     r0,-23452(r13)
    cmpwi   r0,13
    beq-    .L_8025D0F4
    bge-    .L_8025D0E8
    cmpwi   r0,6
    bge-    .L_8025D124
    cmpwi   r0,4
    bge-    .L_8025D0F4
    b       .L_8025D124
.L_8025D0E8:
    cmpwi   r0,15
    beq-    .L_8025D0F4
    b       .L_8025D124
.L_8025D0F4:
    bl      __DVDClearWaitingQueue
    lwz     r4,-23480(r13)
    addi    r0,r31,64
    stw     r0,-23480(r13)
    lwz     r12,40(r4)
    cmplwi  r12,0
    beq-    .L_8025D11C
    mtlr    r12
    li      r3,-4
    blrl
.L_8025D11C:
    bl      stateReady
    b       .L_8025D16C
.L_8025D124:
    li      r0,0
    stw     r0,-23408(r13)
    bl      DVDReset
    addi    r3,r31,112
    bl      OSCreateAlarm
    lis     r3,-32768
    lwz     r0,248(r3)
    lis     r4,4194
    lis     r3,-32730
    srwi    r0,r0,2
    addi    r4,r4,19923
    mulhwu  r0,r4,r0
    srwi    r0,r0,6
    mulli   r6,r0,1150
    addi    r7,r3,-12184
    addi    r3,r31,112
    li      r5,0
    bl      OSSetAlarm
.L_8025D16C:
    lwz     r0,20(r1)
    lwz     r31,12(r1)
    addi    r1,r1,16
    mtlr    r0
    blr
.size stateCoverClosed, . - stateCoverClosed

.global cbForStateCoverClosed
.balign 4
cbForStateCoverClosed:
/* 0x8025D1B0 | size=0x64 (100 bytes) */
    mflr    r0
    cmplwi  r3,16
    stw     r0,4(r1)
    stwu    r1,-8(r1)
    bne-    .L_8025D1E0
    lis     r3,291
    addi    r3,r3,17768
    bl      __DVDStoreErrorCode
    bl      DVDReset
    li      r3,0
    bl      cbForStateError
    b       .L_8025D204
.L_8025D1E0:
    clrlwi. r0,r3,31
    beq-    .L_8025D1F8
    li      r0,0
    stw     r0,-23428(r13)
    bl      stateCheckID
    b       .L_8025D204
.L_8025D1F8:
    lis     r3,-32730
    addi    r3,r3,-14572
    bl      DVDLowRequestError
.L_8025D204:
    lwz     r0,12(r1)
    addi    r1,r1,8
    mtlr    r0
    blr
.size cbForStateCoverClosed, . - cbForStateCoverClosed

.global cbForStateMotorStopped
.balign 4
cbForStateMotorStopped:
/* 0x8025D23C | size=0xEC (236 bytes) */
    mflr    r0
    lis     r3,-13312
    stw     r0,4(r1)
    li      r0,0
    lis     r4,-32694
    stwu    r1,-24(r1)
    stw     r31,20(r1)
    addi    r31,r4,-17248
    stw     r0,24580(r3)
    li      r0,3
    lwz     r3,-23480(r13)
    stw     r0,12(r3)
    lwz     r0,-23452(r13)
    cmpwi   r0,13
    beq-    .L_8025D29C
    bge-    .L_8025D290
    cmpwi   r0,6
    bge-    .L_8025D2CC
    cmpwi   r0,4
    bge-    .L_8025D29C
    b       .L_8025D2CC
.L_8025D290:
    cmpwi   r0,15
    beq-    .L_8025D29C
    b       .L_8025D2CC
.L_8025D29C:
    bl      __DVDClearWaitingQueue
    lwz     r4,-23480(r13)
    addi    r0,r31,64
    stw     r0,-23480(r13)
    lwz     r12,40(r4)
    cmplwi  r12,0
    beq-    .L_8025D2C4
    mtlr    r12
    li      r3,-4
    blrl
.L_8025D2C4:
    bl      stateReady
    b       .L_8025D314
.L_8025D2CC:
    li      r0,0
    stw     r0,-23408(r13)
    bl      DVDReset
    addi    r3,r31,112
    bl      OSCreateAlarm
    lis     r3,-32768
    lwz     r0,248(r3)
    lis     r4,4194
    lis     r3,-32730
    srwi    r0,r0,2
    addi    r4,r4,19923
    mulhwu  r0,r4,r0
    srwi    r0,r0,6
    mulli   r6,r0,1150
    addi    r7,r3,-12184
    addi    r3,r31,112
    li      r5,0
    bl      OSSetAlarm
.L_8025D314:
    lwz     r0,28(r1)
    lwz     r31,20(r1)
    addi    r1,r1,24
    mtlr    r0
    blr
.size cbForStateMotorStopped, . - cbForStateMotorStopped

.global IsImmCommandWithResult
.balign 4
IsImmCommandWithResult:
/* 0x8025D990 | size=0x5C (92 bytes) */
    addi    r0,r3,-9
    cmplwi  r0,3
    bgt-    .L_8025D9A4
    li      r3,1
    blr
.L_8025D9A4:
    lis     r4,-32700
    lwzu    r0,-14372(r4)
    cmplw   r3,r0
    bne-    .L_8025D9BC
    li      r3,1
    blr
.L_8025D9BC:
    lwzu    r0,4(r4)
    cmplw   r3,r0
    bne-    .L_8025D9D0
    li      r3,1
    blr
.L_8025D9D0:
    lwz     r0,4(r4)
    cmplw   r3,r0
    bne-    .L_8025D9E4
    li      r3,1
    blr
.L_8025D9E4:
    li      r3,0
    blr
.size IsImmCommandWithResult, . - IsImmCommandWithResult

.global issueCommand
.balign 4
issueCommand:
/* 0x8025E090 | size=0xBC (188 bytes) */
    mflr    r0
    stw     r0,4(r1)
    stwu    r1,-32(r1)
    stw     r31,28(r1)
    stw     r30,24(r1)
    addi    r30,r4,0
    stw     r29,20(r1)
    addi    r29,r3,0
    lwz     r0,-27788(r13)
    cmpwi   r0,0
    beq-    .L_8025E0E8
    lwz     r3,8(r30)
    cmplwi  r3,1
    beq-    .L_8025E0DC
    addi    r0,r3,-4
    cmplwi  r0,1
    ble-    .L_8025E0DC
    cmplwi  r3,14
    bne-    .L_8025E0E8
.L_8025E0DC:
    lwz     r3,24(r30)
    lwz     r4,20(r30)
    bl      DCInvalidateRange
.L_8025E0E8:
    bl      OSDisableInterrupts
    li      r0,2
    stw     r0,12(r30)
    addi    r31,r3,0
    addi    r3,r29,0
    addi    r4,r30,0
    bl      __DVDPushWaitingQueue
    lwz     r0,-23480(r13)
    addi    r30,r3,0
    cmplwi  r0,0
    bne-    .L_8025E124
    lwz     r0,-23468(r13)
    cmpwi   r0,0
    bne-    .L_8025E124
    bl      stateReady
.L_8025E124:
    mr      r3,r31
    bl      OSRestoreInterrupts
    mr      r3,r30
    lwz     r0,36(r1)
    lwz     r31,28(r1)
    lwz     r30,24(r1)
    lwz     r29,20(r1)
    addi    r1,r1,32
    mtlr    r0
    blr
.size issueCommand, . - issueCommand

.global DVDReadAbsAsyncPrio
.balign 4
DVDReadAbsAsyncPrio:
/* 0x8025E14C | size=0xDC (220 bytes) */
    mflr    r0
    stw     r0,4(r1)
    li      r0,1
    stwu    r1,-56(r1)
    stw     r31,52(r1)
    addi    r31,r8,0
    stw     r30,48(r1)
    stw     r29,44(r1)
    addi    r29,r3,0
    stw     r0,8(r3)
    li      r0,0
    stw     r4,24(r3)
    stw     r5,20(r3)
    stw     r6,16(r3)
    stw     r0,32(r3)
    stw     r7,40(r3)
    lwz     r0,-27788(r13)
    cmpwi   r0,0
    beq-    .L_8025E1C4
    lwz     r3,8(r29)
    cmplwi  r3,1
    beq-    .L_8025E1B8
    addi    r0,r3,-4
    cmplwi  r0,1
    ble-    .L_8025E1B8
    cmplwi  r3,14
    bne-    .L_8025E1C4
.L_8025E1B8:
    lwz     r3,24(r29)
    lwz     r4,20(r29)
    bl      DCInvalidateRange
.L_8025E1C4:
    bl      OSDisableInterrupts
    li      r0,2
    stw     r0,12(r29)
    addi    r30,r3,0
    addi    r3,r31,0
    addi    r4,r29,0
    bl      __DVDPushWaitingQueue
    lwz     r0,-23480(r13)
    addi    r31,r3,0
    cmplwi  r0,0
    bne-    .L_8025E200
    lwz     r0,-23468(r13)
    cmpwi   r0,0
    bne-    .L_8025E200
    bl      stateReady
.L_8025E200:
    mr      r3,r30
    bl      OSRestoreInterrupts
    mr      r3,r31
    lwz     r0,60(r1)
    lwz     r31,52(r1)
    lwz     r30,48(r1)
    lwz     r29,44(r1)
    addi    r1,r1,56
    mtlr    r0
    blr
.size DVDReadAbsAsyncPrio, . - DVDReadAbsAsyncPrio

.global DVDSeekAbsAsyncPrio
.balign 4
DVDSeekAbsAsyncPrio:
/* 0x8025E228 | size=0xCC (204 bytes) */
    mflr    r0
    stw     r0,4(r1)
    li      r0,2
    stwu    r1,-48(r1)
    stw     r31,44(r1)
    mr      r31,r6
    stw     r30,40(r1)
    stw     r29,36(r1)
    addi    r29,r3,0
    stw     r0,8(r3)
    stw     r4,16(r3)
    stw     r5,40(r3)
    lwz     r0,-27788(r13)
    cmpwi   r0,0
    beq-    .L_8025E290
    lwz     r3,8(r29)
    cmplwi  r3,1
    beq-    .L_8025E284
    addi    r0,r3,-4
    cmplwi  r0,1
    ble-    .L_8025E284
    cmplwi  r3,14
    bne-    .L_8025E290
.L_8025E284:
    lwz     r3,24(r29)
    lwz     r4,20(r29)
    bl      DCInvalidateRange
.L_8025E290:
    bl      OSDisableInterrupts
    li      r0,2
    stw     r0,12(r29)
    addi    r30,r3,0
    addi    r3,r31,0
    addi    r4,r29,0
    bl      __DVDPushWaitingQueue
    lwz     r0,-23480(r13)
    addi    r31,r3,0
    cmplwi  r0,0
    bne-    .L_8025E2CC
    lwz     r0,-23468(r13)
    cmpwi   r0,0
    bne-    .L_8025E2CC
    bl      stateReady
.L_8025E2CC:
    mr      r3,r30
    bl      OSRestoreInterrupts
    mr      r3,r31
    lwz     r0,52(r1)
    lwz     r31,44(r1)
    lwz     r30,40(r1)
    lwz     r29,36(r1)
    addi    r1,r1,48
    mtlr    r0
    blr
.size DVDSeekAbsAsyncPrio, . - DVDSeekAbsAsyncPrio

.global DVDReadAbsAsyncForBS
.balign 4
DVDReadAbsAsyncForBS:
/* 0x8025E2F4 | size=0xD0 (208 bytes) */
    mflr    r0
    stw     r0,4(r1)
    li      r0,4
    stwu    r1,-48(r1)
    stw     r31,44(r1)
    addi    r31,r3,0
    stw     r30,40(r1)
    stw     r0,8(r3)
    li      r0,0
    stw     r4,24(r3)
    stw     r5,20(r3)
    stw     r6,16(r3)
    stw     r0,32(r3)
    stw     r7,40(r3)
    lwz     r0,-27788(r13)
    cmpwi   r0,0
    beq-    .L_8025E364
    lwz     r3,8(r31)
    cmplwi  r3,1
    beq-    .L_8025E358
    addi    r0,r3,-4
    cmplwi  r0,1
    ble-    .L_8025E358
    cmplwi  r3,14
    bne-    .L_8025E364
.L_8025E358:
    lwz     r3,24(r31)
    lwz     r4,20(r31)
    bl      DCInvalidateRange
.L_8025E364:
    bl      OSDisableInterrupts
    li      r0,2
    stw     r0,12(r31)
    addi    r30,r3,0
    addi    r4,r31,0
    li      r3,2
    bl      __DVDPushWaitingQueue
    lwz     r0,-23480(r13)
    addi    r31,r3,0
    cmplwi  r0,0
    bne-    .L_8025E3A0
    lwz     r0,-23468(r13)
    cmpwi   r0,0
    bne-    .L_8025E3A0
    bl      stateReady
.L_8025E3A0:
    mr      r3,r30
    bl      OSRestoreInterrupts
    mr      r3,r31
    lwz     r0,52(r1)
    lwz     r31,44(r1)
    lwz     r30,40(r1)
    addi    r1,r1,48
    mtlr    r0
    blr
.size DVDReadAbsAsyncForBS, . - DVDReadAbsAsyncForBS

.global DVDReadDiskID
.balign 4
DVDReadDiskID:
/* 0x8025E3C4 | size=0xD4 (212 bytes) */
    mflr    r0
    stw     r0,4(r1)
    li      r0,5
    stwu    r1,-40(r1)
    stw     r31,36(r1)
    addi    r31,r3,0
    stw     r30,32(r1)
    stw     r0,8(r3)
    li      r3,32
    li      r0,0
    stw     r4,24(r31)
    stw     r3,20(r31)
    stw     r0,16(r31)
    stw     r0,32(r31)
    stw     r5,40(r31)
    lwz     r0,-27788(r13)
    cmpwi   r0,0
    beq-    .L_8025E438
    lwz     r3,8(r31)
    cmplwi  r3,1
    beq-    .L_8025E42C
    addi    r0,r3,-4
    cmplwi  r0,1
    ble-    .L_8025E42C
    cmplwi  r3,14
    bne-    .L_8025E438
.L_8025E42C:
    lwz     r3,24(r31)
    lwz     r4,20(r31)
    bl      DCInvalidateRange
.L_8025E438:
    bl      OSDisableInterrupts
    li      r0,2
    stw     r0,12(r31)
    addi    r30,r3,0
    addi    r4,r31,0
    li      r3,2
    bl      __DVDPushWaitingQueue
    lwz     r0,-23480(r13)
    addi    r31,r3,0
    cmplwi  r0,0
    bne-    .L_8025E474
    lwz     r0,-23468(r13)
    cmpwi   r0,0
    bne-    .L_8025E474
    bl      stateReady
.L_8025E474:
    mr      r3,r30
    bl      OSRestoreInterrupts
    mr      r3,r31
    lwz     r0,44(r1)
    lwz     r31,36(r1)
    lwz     r30,32(r1)
    addi    r1,r1,40
    mtlr    r0
    blr
.size DVDReadDiskID, . - DVDReadDiskID

.global DVDPrepareStreamAbsAsync
.balign 4
DVDPrepareStreamAbsAsync:
/* 0x8025E498 | size=0xC4 (196 bytes) */
    mflr    r0
    stw     r0,4(r1)
    li      r0,6
    stwu    r1,-40(r1)
    stw     r31,36(r1)
    addi    r31,r3,0
    stw     r30,32(r1)
    stw     r0,8(r3)
    stw     r4,20(r3)
    stw     r5,16(r3)
    stw     r6,40(r3)
    lwz     r0,-27788(r13)
    cmpwi   r0,0
    beq-    .L_8025E4FC
    lwz     r3,8(r31)
    cmplwi  r3,1
    beq-    .L_8025E4F0
    addi    r0,r3,-4
    cmplwi  r0,1
    ble-    .L_8025E4F0
    cmplwi  r3,14
    bne-    .L_8025E4FC
.L_8025E4F0:
    lwz     r3,24(r31)
    lwz     r4,20(r31)
    bl      DCInvalidateRange
.L_8025E4FC:
    bl      OSDisableInterrupts
    li      r0,2
    stw     r0,12(r31)
    addi    r30,r3,0
    addi    r4,r31,0
    li      r3,1
    bl      __DVDPushWaitingQueue
    lwz     r0,-23480(r13)
    addi    r31,r3,0
    cmplwi  r0,0
    bne-    .L_8025E538
    lwz     r0,-23468(r13)
    cmpwi   r0,0
    bne-    .L_8025E538
    bl      stateReady
.L_8025E538:
    mr      r3,r30
    bl      OSRestoreInterrupts
    mr      r3,r31
    lwz     r0,44(r1)
    lwz     r31,36(r1)
    lwz     r30,32(r1)
    addi    r1,r1,40
    mtlr    r0
    blr
.size DVDPrepareStreamAbsAsync, . - DVDPrepareStreamAbsAsync

.global DVDCancelStreamAsync
.balign 4
DVDCancelStreamAsync:
/* 0x8025E55C | size=0xBC (188 bytes) */
    mflr    r0
    stw     r0,4(r1)
    li      r0,7
    stwu    r1,-32(r1)
    stw     r31,28(r1)
    addi    r31,r3,0
    stw     r30,24(r1)
    stw     r0,8(r3)
    stw     r4,40(r3)
    lwz     r0,-27788(r13)
    cmpwi   r0,0
    beq-    .L_8025E5B8
    lwz     r3,8(r31)
    cmplwi  r3,1
    beq-    .L_8025E5AC
    addi    r0,r3,-4
    cmplwi  r0,1
    ble-    .L_8025E5AC
    cmplwi  r3,14
    bne-    .L_8025E5B8
.L_8025E5AC:
    lwz     r3,24(r31)
    lwz     r4,20(r31)
    bl      DCInvalidateRange
.L_8025E5B8:
    bl      OSDisableInterrupts
    li      r0,2
    stw     r0,12(r31)
    addi    r30,r3,0
    addi    r4,r31,0
    li      r3,1
    bl      __DVDPushWaitingQueue
    lwz     r0,-23480(r13)
    addi    r31,r3,0
    cmplwi  r0,0
    bne-    .L_8025E5F4
    lwz     r0,-23468(r13)
    cmpwi   r0,0
    bne-    .L_8025E5F4
    bl      stateReady
.L_8025E5F4:
    mr      r3,r30
    bl      OSRestoreInterrupts
    mr      r3,r31
    lwz     r0,36(r1)
    lwz     r31,28(r1)
    lwz     r30,24(r1)
    addi    r1,r1,32
    mtlr    r0
    blr
.size DVDCancelStreamAsync, . - DVDCancelStreamAsync

.global DVDCancelStream
.balign 4
DVDCancelStream:
/* 0x8025E618 | size=0xA0 (160 bytes) */
    mflr    r0
    stw     r0,4(r1)
    li      r0,7
    stwu    r1,-32(r1)
    stw     r31,28(r1)
    stw     r30,24(r1)
    addi    r30,r3,0
    lis     r3,-32730
    stw     r0,8(r30)
    addi    r0,r3,-6472
    addi    r4,r30,0
    stw     r0,40(r30)
    li      r3,1
    bl      issueCommand
    cmpwi   r3,0
    bne-    .L_8025E660
    li      r3,-1
    b       .L_8025E6A0
.L_8025E660:
    bl      OSDisableInterrupts
    mr      r31,r3
.L_8025E668:
    lwz     r3,12(r30)
    addi    r0,r3,1
    cmplwi  r0,1
    ble-    .L_8025E680
    cmpwi   r3,10
    bne-    .L_8025E688
.L_8025E680:
    lwz     r30,32(r30)
    b       .L_8025E694
.L_8025E688:
    addi    r3,r13,-23488
    bl      OSSleepThread
    b       .L_8025E668
.L_8025E694:
    mr      r3,r31
    bl      OSRestoreInterrupts
    mr      r3,r30
.L_8025E6A0:
    lwz     r0,36(r1)
    lwz     r31,28(r1)
    lwz     r30,24(r1)
    addi    r1,r1,32
    mtlr    r0
    blr
.size DVDCancelStream, . - DVDCancelStream

.global DVDStopStreamAtEndAsync
.balign 4
DVDStopStreamAtEndAsync:
/* 0x8025E6E0 | size=0xBC (188 bytes) */
    mflr    r0
    stw     r0,4(r1)
    li      r0,8
    stwu    r1,-32(r1)
    stw     r31,28(r1)
    addi    r31,r3,0
    stw     r30,24(r1)
    stw     r0,8(r3)
    stw     r4,40(r3)
    lwz     r0,-27788(r13)
    cmpwi   r0,0
    beq-    .L_8025E73C
    lwz     r3,8(r31)
    cmplwi  r3,1
    beq-    .L_8025E730
    addi    r0,r3,-4
    cmplwi  r0,1
    ble-    .L_8025E730
    cmplwi  r3,14
    bne-    .L_8025E73C
.L_8025E730:
    lwz     r3,24(r31)
    lwz     r4,20(r31)
    bl      DCInvalidateRange
.L_8025E73C:
    bl      OSDisableInterrupts
    li      r0,2
    stw     r0,12(r31)
    addi    r30,r3,0
    addi    r4,r31,0
    li      r3,1
    bl      __DVDPushWaitingQueue
    lwz     r0,-23480(r13)
    addi    r31,r3,0
    cmplwi  r0,0
    bne-    .L_8025E778
    lwz     r0,-23468(r13)
    cmpwi   r0,0
    bne-    .L_8025E778
    bl      stateReady
.L_8025E778:
    mr      r3,r30
    bl      OSRestoreInterrupts
    mr      r3,r31
    lwz     r0,36(r1)
    lwz     r31,28(r1)
    lwz     r30,24(r1)
    addi    r1,r1,32
    mtlr    r0
    blr
.size DVDStopStreamAtEndAsync, . - DVDStopStreamAtEndAsync

.global DVDStopStreamAtEnd
.balign 4
DVDStopStreamAtEnd:
/* 0x8025E79C | size=0xA0 (160 bytes) */
    mflr    r0
    stw     r0,4(r1)
    li      r0,8
    stwu    r1,-32(r1)
    stw     r31,28(r1)
    stw     r30,24(r1)
    addi    r30,r3,0
    lis     r3,-32730
    stw     r0,8(r30)
    addi    r0,r3,-6084
    addi    r4,r30,0
    stw     r0,40(r30)
    li      r3,1
    bl      issueCommand
    cmpwi   r3,0
    bne-    .L_8025E7E4
    li      r3,-1
    b       .L_8025E824
.L_8025E7E4:
    bl      OSDisableInterrupts
    mr      r31,r3
.L_8025E7EC:
    lwz     r3,12(r30)
    addi    r0,r3,1
    cmplwi  r0,1
    ble-    .L_8025E804
    cmpwi   r3,10
    bne-    .L_8025E80C
.L_8025E804:
    lwz     r30,32(r30)
    b       .L_8025E818
.L_8025E80C:
    addi    r3,r13,-23488
    bl      OSSleepThread
    b       .L_8025E7EC
.L_8025E818:
    mr      r3,r31
    bl      OSRestoreInterrupts
    mr      r3,r30
.L_8025E824:
    lwz     r0,36(r1)
    lwz     r31,28(r1)
    lwz     r30,24(r1)
    addi    r1,r1,32
    mtlr    r0
    blr
.size DVDStopStreamAtEnd, . - DVDStopStreamAtEnd

.global DVDGetStreamErrorStatusAsync
.balign 4
DVDGetStreamErrorStatusAsync:
/* 0x8025E864 | size=0xBC (188 bytes) */
    mflr    r0
    stw     r0,4(r1)
    li      r0,9
    stwu    r1,-32(r1)
    stw     r31,28(r1)
    addi    r31,r3,0
    stw     r30,24(r1)
    stw     r0,8(r3)
    stw     r4,40(r3)
    lwz     r0,-27788(r13)
    cmpwi   r0,0
    beq-    .L_8025E8C0
    lwz     r3,8(r31)
    cmplwi  r3,1
    beq-    .L_8025E8B4
    addi    r0,r3,-4
    cmplwi  r0,1
    ble-    .L_8025E8B4
    cmplwi  r3,14
    bne-    .L_8025E8C0
.L_8025E8B4:
    lwz     r3,24(r31)
    lwz     r4,20(r31)
    bl      DCInvalidateRange
.L_8025E8C0:
    bl      OSDisableInterrupts
    li      r0,2
    stw     r0,12(r31)
    addi    r30,r3,0
    addi    r4,r31,0
    li      r3,1
    bl      __DVDPushWaitingQueue
    lwz     r0,-23480(r13)
    addi    r31,r3,0
    cmplwi  r0,0
    bne-    .L_8025E8FC
    lwz     r0,-23468(r13)
    cmpwi   r0,0
    bne-    .L_8025E8FC
    bl      stateReady
.L_8025E8FC:
    mr      r3,r30
    bl      OSRestoreInterrupts
    mr      r3,r31
    lwz     r0,36(r1)
    lwz     r31,28(r1)
    lwz     r30,24(r1)
    addi    r1,r1,32
    mtlr    r0
    blr
.size DVDGetStreamErrorStatusAsync, . - DVDGetStreamErrorStatusAsync

.global DVDGetStreamErrorStatus
.balign 4
DVDGetStreamErrorStatus:
/* 0x8025E920 | size=0xA0 (160 bytes) */
    mflr    r0
    stw     r0,4(r1)
    li      r0,9
    stwu    r1,-32(r1)
    stw     r31,28(r1)
    stw     r30,24(r1)
    addi    r30,r3,0
    lis     r3,-32730
    stw     r0,8(r30)
    addi    r0,r3,-5696
    addi    r4,r30,0
    stw     r0,40(r30)
    li      r3,1
    bl      issueCommand
    cmpwi   r3,0
    bne-    .L_8025E968
    li      r3,-1
    b       .L_8025E9A8
.L_8025E968:
    bl      OSDisableInterrupts
    mr      r31,r3
.L_8025E970:
    lwz     r3,12(r30)
    addi    r0,r3,1
    cmplwi  r0,1
    ble-    .L_8025E988
    cmpwi   r3,10
    bne-    .L_8025E990
.L_8025E988:
    lwz     r30,32(r30)
    b       .L_8025E99C
.L_8025E990:
    addi    r3,r13,-23488
    bl      OSSleepThread
    b       .L_8025E970
.L_8025E99C:
    mr      r3,r31
    bl      OSRestoreInterrupts
    mr      r3,r30
.L_8025E9A8:
    lwz     r0,36(r1)
    lwz     r31,28(r1)
    lwz     r30,24(r1)
    addi    r1,r1,32
    mtlr    r0
    blr
.size DVDGetStreamErrorStatus, . - DVDGetStreamErrorStatus

.global DVDGetStreamPlayAddrAsync
.balign 4
DVDGetStreamPlayAddrAsync:
/* 0x8025E9E8 | size=0xBC (188 bytes) */
    mflr    r0
    stw     r0,4(r1)
    li      r0,10
    stwu    r1,-32(r1)
    stw     r31,28(r1)
    addi    r31,r3,0
    stw     r30,24(r1)
    stw     r0,8(r3)
    stw     r4,40(r3)
    lwz     r0,-27788(r13)
    cmpwi   r0,0
    beq-    .L_8025EA44
    lwz     r3,8(r31)
    cmplwi  r3,1
    beq-    .L_8025EA38
    addi    r0,r3,-4
    cmplwi  r0,1
    ble-    .L_8025EA38
    cmplwi  r3,14
    bne-    .L_8025EA44
.L_8025EA38:
    lwz     r3,24(r31)
    lwz     r4,20(r31)
    bl      DCInvalidateRange
.L_8025EA44:
    bl      OSDisableInterrupts
    li      r0,2
    stw     r0,12(r31)
    addi    r30,r3,0
    addi    r4,r31,0
    li      r3,1
    bl      __DVDPushWaitingQueue
    lwz     r0,-23480(r13)
    addi    r31,r3,0
    cmplwi  r0,0
    bne-    .L_8025EA80
    lwz     r0,-23468(r13)
    cmpwi   r0,0
    bne-    .L_8025EA80
    bl      stateReady
.L_8025EA80:
    mr      r3,r30
    bl      OSRestoreInterrupts
    mr      r3,r31
    lwz     r0,36(r1)
    lwz     r31,28(r1)
    lwz     r30,24(r1)
    addi    r1,r1,32
    mtlr    r0
    blr
.size DVDGetStreamPlayAddrAsync, . - DVDGetStreamPlayAddrAsync

.global DVDGetStreamPlayAddr
.balign 4
DVDGetStreamPlayAddr:
/* 0x8025EAA4 | size=0xA0 (160 bytes) */
    mflr    r0
    stw     r0,4(r1)
    li      r0,10
    stwu    r1,-32(r1)
    stw     r31,28(r1)
    stw     r30,24(r1)
    addi    r30,r3,0
    lis     r3,-32730
    stw     r0,8(r30)
    addi    r0,r3,-5308
    addi    r4,r30,0
    stw     r0,40(r30)
    li      r3,1
    bl      issueCommand
    cmpwi   r3,0
    bne-    .L_8025EAEC
    li      r3,-1
    b       .L_8025EB2C
.L_8025EAEC:
    bl      OSDisableInterrupts
    mr      r31,r3
.L_8025EAF4:
    lwz     r3,12(r30)
    addi    r0,r3,1
    cmplwi  r0,1
    ble-    .L_8025EB0C
    cmpwi   r3,10
    bne-    .L_8025EB14
.L_8025EB0C:
    lwz     r30,32(r30)
    b       .L_8025EB20
.L_8025EB14:
    addi    r3,r13,-23488
    bl      OSSleepThread
    b       .L_8025EAF4
.L_8025EB20:
    mr      r3,r31
    bl      OSRestoreInterrupts
    mr      r3,r30
.L_8025EB2C:
    lwz     r0,36(r1)
    lwz     r31,28(r1)
    lwz     r30,24(r1)
    addi    r1,r1,32
    mtlr    r0
    blr
.size DVDGetStreamPlayAddr, . - DVDGetStreamPlayAddr

.global DVDGetStreamStartAddrAsync
.balign 4
DVDGetStreamStartAddrAsync:
/* 0x8025EB6C | size=0xBC (188 bytes) */
    mflr    r0
    stw     r0,4(r1)
    li      r0,11
    stwu    r1,-32(r1)
    stw     r31,28(r1)
    addi    r31,r3,0
    stw     r30,24(r1)
    stw     r0,8(r3)
    stw     r4,40(r3)
    lwz     r0,-27788(r13)
    cmpwi   r0,0
    beq-    .L_8025EBC8
    lwz     r3,8(r31)
    cmplwi  r3,1
    beq-    .L_8025EBBC
    addi    r0,r3,-4
    cmplwi  r0,1
    ble-    .L_8025EBBC
    cmplwi  r3,14
    bne-    .L_8025EBC8
.L_8025EBBC:
    lwz     r3,24(r31)
    lwz     r4,20(r31)
    bl      DCInvalidateRange
.L_8025EBC8:
    bl      OSDisableInterrupts
    li      r0,2
    stw     r0,12(r31)
    addi    r30,r3,0
    addi    r4,r31,0
    li      r3,1
    bl      __DVDPushWaitingQueue
    lwz     r0,-23480(r13)
    addi    r31,r3,0
    cmplwi  r0,0
    bne-    .L_8025EC04
    lwz     r0,-23468(r13)
    cmpwi   r0,0
    bne-    .L_8025EC04
    bl      stateReady
.L_8025EC04:
    mr      r3,r30
    bl      OSRestoreInterrupts
    mr      r3,r31
    lwz     r0,36(r1)
    lwz     r31,28(r1)
    lwz     r30,24(r1)
    addi    r1,r1,32
    mtlr    r0
    blr
.size DVDGetStreamStartAddrAsync, . - DVDGetStreamStartAddrAsync

.global DVDGetStreamStartAddr
.balign 4
DVDGetStreamStartAddr:
/* 0x8025EC28 | size=0xA0 (160 bytes) */
    mflr    r0
    stw     r0,4(r1)
    li      r0,11
    stwu    r1,-32(r1)
    stw     r31,28(r1)
    stw     r30,24(r1)
    addi    r30,r3,0
    lis     r3,-32730
    stw     r0,8(r30)
    addi    r0,r3,-4920
    addi    r4,r30,0
    stw     r0,40(r30)
    li      r3,1
    bl      issueCommand
    cmpwi   r3,0
    bne-    .L_8025EC70
    li      r3,-1
    b       .L_8025ECB0
.L_8025EC70:
    bl      OSDisableInterrupts
    mr      r31,r3
.L_8025EC78:
    lwz     r3,12(r30)
    addi    r0,r3,1
    cmplwi  r0,1
    ble-    .L_8025EC90
    cmpwi   r3,10
    bne-    .L_8025EC98
.L_8025EC90:
    lwz     r30,32(r30)
    b       .L_8025ECA4
.L_8025EC98:
    addi    r3,r13,-23488
    bl      OSSleepThread
    b       .L_8025EC78
.L_8025ECA4:
    mr      r3,r31
    bl      OSRestoreInterrupts
    mr      r3,r30
.L_8025ECB0:
    lwz     r0,36(r1)
    lwz     r31,28(r1)
    lwz     r30,24(r1)
    addi    r1,r1,32
    mtlr    r0
    blr
.size DVDGetStreamStartAddr, . - DVDGetStreamStartAddr

.global DVDGetStreamLengthAsync
.balign 4
DVDGetStreamLengthAsync:
/* 0x8025ECF0 | size=0xBC (188 bytes) */
    mflr    r0
    stw     r0,4(r1)
    li      r0,12
    stwu    r1,-32(r1)
    stw     r31,28(r1)
    addi    r31,r3,0
    stw     r30,24(r1)
    stw     r0,8(r3)
    stw     r4,40(r3)
    lwz     r0,-27788(r13)
    cmpwi   r0,0
    beq-    .L_8025ED4C
    lwz     r3,8(r31)
    cmplwi  r3,1
    beq-    .L_8025ED40
    addi    r0,r3,-4
    cmplwi  r0,1
    ble-    .L_8025ED40
    cmplwi  r3,14
    bne-    .L_8025ED4C
.L_8025ED40:
    lwz     r3,24(r31)
    lwz     r4,20(r31)
    bl      DCInvalidateRange
.L_8025ED4C:
    bl      OSDisableInterrupts
    li      r0,2
    stw     r0,12(r31)
    addi    r30,r3,0
    addi    r4,r31,0
    li      r3,1
    bl      __DVDPushWaitingQueue
    lwz     r0,-23480(r13)
    addi    r31,r3,0
    cmplwi  r0,0
    bne-    .L_8025ED88
    lwz     r0,-23468(r13)
    cmpwi   r0,0
    bne-    .L_8025ED88
    bl      stateReady
.L_8025ED88:
    mr      r3,r30
    bl      OSRestoreInterrupts
    mr      r3,r31
    lwz     r0,36(r1)
    lwz     r31,28(r1)
    lwz     r30,24(r1)
    addi    r1,r1,32
    mtlr    r0
    blr
.size DVDGetStreamLengthAsync, . - DVDGetStreamLengthAsync

.global DVDGetStreamLength
.balign 4
DVDGetStreamLength:
/* 0x8025EDAC | size=0xA0 (160 bytes) */
    mflr    r0
    stw     r0,4(r1)
    li      r0,12
    stwu    r1,-32(r1)
    stw     r31,28(r1)
    stw     r30,24(r1)
    addi    r30,r3,0
    lis     r3,-32730
    stw     r0,8(r30)
    addi    r0,r3,-4532
    addi    r4,r30,0
    stw     r0,40(r30)
    li      r3,1
    bl      issueCommand
    cmpwi   r3,0
    bne-    .L_8025EDF4
    li      r3,-1
    b       .L_8025EE34
.L_8025EDF4:
    bl      OSDisableInterrupts
    mr      r31,r3
.L_8025EDFC:
    lwz     r3,12(r30)
    addi    r0,r3,1
    cmplwi  r0,1
    ble-    .L_8025EE14
    cmpwi   r3,10
    bne-    .L_8025EE1C
.L_8025EE14:
    lwz     r30,32(r30)
    b       .L_8025EE28
.L_8025EE1C:
    addi    r3,r13,-23488
    bl      OSSleepThread
    b       .L_8025EDFC
.L_8025EE28:
    mr      r3,r31
    bl      OSRestoreInterrupts
    mr      r3,r30
.L_8025EE34:
    lwz     r0,36(r1)
    lwz     r31,28(r1)
    lwz     r30,24(r1)
    addi    r1,r1,32
    mtlr    r0
    blr
.size DVDGetStreamLength, . - DVDGetStreamLength

.global __DVDAudioBufferConfig
.balign 4
__DVDAudioBufferConfig:
/* 0x8025EE74 | size=0xBC (188 bytes) */
    mflr    r0
    stw     r0,4(r1)
    li      r0,13
    stwu    r1,-48(r1)
    stw     r31,44(r1)
    stw     r30,40(r1)
    addi    r30,r3,0
    stw     r0,8(r3)
    stw     r4,16(r3)
    stw     r5,20(r3)
    stw     r6,40(r3)
    lwz     r0,-27788(r13)
    cmpwi   r0,0
    beq-    .L_8025EED8
    lwz     r3,8(r30)
    cmplwi  r3,1
    beq-    .L_8025EECC
    addi    r0,r3,-4
    cmplwi  r0,1
    ble-    .L_8025EECC
    cmplwi  r3,14
    bne-    .L_8025EED8
.L_8025EECC:
    lwz     r3,24(r30)
    lwz     r4,20(r30)
    bl      DCInvalidateRange
.L_8025EED8:
    bl      OSDisableInterrupts
    li      r0,2
    stw     r0,12(r30)
    addi    r31,r3,0
    addi    r4,r30,0
    li      r3,2
    bl      __DVDPushWaitingQueue
    lwz     r0,-23480(r13)
    cmplwi  r0,0
    bne-    .L_8025EF10
    lwz     r0,-23468(r13)
    cmpwi   r0,0
    bne-    .L_8025EF10
    bl      stateReady
.L_8025EF10:
    mr      r3,r31
    bl      OSRestoreInterrupts
    lwz     r0,52(r1)
    lwz     r31,44(r1)
    lwz     r30,40(r1)
    addi    r1,r1,48
    mtlr    r0
    blr
.size __DVDAudioBufferConfig, . - __DVDAudioBufferConfig

.global DVDChangeDiskAsyncForBS
.balign 4
DVDChangeDiskAsyncForBS:
/* 0x8025EF30 | size=0xBC (188 bytes) */
    mflr    r0
    stw     r0,4(r1)
    li      r0,15
    stwu    r1,-32(r1)
    stw     r31,28(r1)
    addi    r31,r3,0
    stw     r30,24(r1)
    stw     r0,8(r3)
    stw     r4,40(r3)
    lwz     r0,-27788(r13)
    cmpwi   r0,0
    beq-    .L_8025EF8C
    lwz     r3,8(r31)
    cmplwi  r3,1
    beq-    .L_8025EF80
    addi    r0,r3,-4
    cmplwi  r0,1
    ble-    .L_8025EF80
    cmplwi  r3,14
    bne-    .L_8025EF8C
.L_8025EF80:
    lwz     r3,24(r31)
    lwz     r4,20(r31)
    bl      DCInvalidateRange
.L_8025EF8C:
    bl      OSDisableInterrupts
    li      r0,2
    stw     r0,12(r31)
    addi    r30,r3,0
    addi    r4,r31,0
    li      r3,2
    bl      __DVDPushWaitingQueue
    lwz     r0,-23480(r13)
    addi    r31,r3,0
    cmplwi  r0,0
    bne-    .L_8025EFC8
    lwz     r0,-23468(r13)
    cmpwi   r0,0
    bne-    .L_8025EFC8
    bl      stateReady
.L_8025EFC8:
    mr      r3,r30
    bl      OSRestoreInterrupts
    mr      r3,r31
    lwz     r0,36(r1)
    lwz     r31,28(r1)
    lwz     r30,24(r1)
    addi    r1,r1,32
    mtlr    r0
    blr
.size DVDChangeDiskAsyncForBS, . - DVDChangeDiskAsyncForBS

.global DVDStopMotorAsync
.balign 4
DVDStopMotorAsync:
/* 0x8025F224 | size=0xBC (188 bytes) */
    mflr    r0
    stw     r0,4(r1)
    li      r0,16
    stwu    r1,-32(r1)
    stw     r31,28(r1)
    addi    r31,r3,0
    stw     r30,24(r1)
    stw     r0,8(r3)
    stw     r4,40(r3)
    lwz     r0,-27788(r13)
    cmpwi   r0,0
    beq-    .L_8025F280
    lwz     r3,8(r31)
    cmplwi  r3,1
    beq-    .L_8025F274
    addi    r0,r3,-4
    cmplwi  r0,1
    ble-    .L_8025F274
    cmplwi  r3,14
    bne-    .L_8025F280
.L_8025F274:
    lwz     r3,24(r31)
    lwz     r4,20(r31)
    bl      DCInvalidateRange
.L_8025F280:
    bl      OSDisableInterrupts
    li      r0,2
    stw     r0,12(r31)
    addi    r30,r3,0
    addi    r4,r31,0
    li      r3,2
    bl      __DVDPushWaitingQueue
    lwz     r0,-23480(r13)
    addi    r31,r3,0
    cmplwi  r0,0
    bne-    .L_8025F2BC
    lwz     r0,-23468(r13)
    cmpwi   r0,0
    bne-    .L_8025F2BC
    bl      stateReady
.L_8025F2BC:
    mr      r3,r30
    bl      OSRestoreInterrupts
    mr      r3,r31
    lwz     r0,36(r1)
    lwz     r31,28(r1)
    lwz     r30,24(r1)
    addi    r1,r1,32
    mtlr    r0
    blr
.size DVDStopMotorAsync, . - DVDStopMotorAsync

.global DVDStopMotor
.balign 4
DVDStopMotor:
/* 0x8025F2E0 | size=0xB4 (180 bytes) */
    mflr    r0
    stw     r0,4(r1)
    li      r0,16
    stwu    r1,-32(r1)
    stw     r31,28(r1)
    stw     r30,24(r1)
    addi    r30,r3,0
    lis     r3,-32730
    stw     r0,8(r30)
    addi    r0,r3,-3180
    addi    r4,r30,0
    stw     r0,40(r30)
    li      r3,2
    bl      issueCommand
    cmpwi   r3,0
    bne-    .L_8025F328
    li      r3,-1
    b       .L_8025F37C
.L_8025F328:
    bl      OSDisableInterrupts
    mr      r31,r3
.L_8025F330:
    lwz     r0,12(r30)
    cmpwi   r0,0
    bne-    .L_8025F344
    li      r30,0
    b       .L_8025F370
.L_8025F344:
    cmpwi   r0,-1
    bne-    .L_8025F354
    li      r30,-1
    b       .L_8025F370
.L_8025F354:
    cmpwi   r0,10
    bne-    .L_8025F364
    li      r30,-3
    b       .L_8025F370
.L_8025F364:
    addi    r3,r13,-23488
    bl      OSSleepThread
    b       .L_8025F330
.L_8025F370:
    mr      r3,r31
    bl      OSRestoreInterrupts
    mr      r3,r30
.L_8025F37C:
    lwz     r0,36(r1)
    lwz     r31,28(r1)
    lwz     r30,24(r1)
    addi    r1,r1,32
    mtlr    r0
    blr
.size DVDStopMotor, . - DVDStopMotor

.global DVDInquiryAsync
.balign 4
DVDInquiryAsync:
/* 0x8025F3B8 | size=0xD0 (208 bytes) */
    mflr    r0
    stw     r0,4(r1)
    li      r0,14
    stwu    r1,-40(r1)
    stw     r31,36(r1)
    addi    r31,r3,0
    stw     r30,32(r1)
    stw     r0,8(r3)
    li      r3,32
    li      r0,0
    stw     r4,24(r31)
    stw     r3,20(r31)
    stw     r0,32(r31)
    stw     r5,40(r31)
    lwz     r0,-27788(r13)
    cmpwi   r0,0
    beq-    .L_8025F428
    lwz     r3,8(r31)
    cmplwi  r3,1
    beq-    .L_8025F41C
    addi    r0,r3,-4
    cmplwi  r0,1
    ble-    .L_8025F41C
    cmplwi  r3,14
    bne-    .L_8025F428
.L_8025F41C:
    lwz     r3,24(r31)
    lwz     r4,20(r31)
    bl      DCInvalidateRange
.L_8025F428:
    bl      OSDisableInterrupts
    li      r0,2
    stw     r0,12(r31)
    addi    r30,r3,0
    addi    r4,r31,0
    li      r3,2
    bl      __DVDPushWaitingQueue
    lwz     r0,-23480(r13)
    addi    r31,r3,0
    cmplwi  r0,0
    bne-    .L_8025F464
    lwz     r0,-23468(r13)
    cmpwi   r0,0
    bne-    .L_8025F464
    bl      stateReady
.L_8025F464:
    mr      r3,r30
    bl      OSRestoreInterrupts
    mr      r3,r31
    lwz     r0,44(r1)
    lwz     r31,36(r1)
    lwz     r30,32(r1)
    addi    r1,r1,40
    mtlr    r0
    blr
.size DVDInquiryAsync, . - DVDInquiryAsync

.global DVDInquiry
.balign 4
DVDInquiry:
/* 0x8025F488 | size=0xC8 (200 bytes) */
    mflr    r0
    li      r6,32
    stw     r0,4(r1)
    li      r0,14
    li      r5,0
    stwu    r1,-40(r1)
    stw     r31,36(r1)
    stw     r30,32(r1)
    addi    r30,r3,0
    stw     r0,8(r3)
    lis     r3,-32730
    addi    r0,r3,-2736
    stw     r4,24(r30)
    addi    r4,r30,0
    li      r3,2
    stw     r6,20(r30)
    stw     r5,32(r30)
    stw     r0,40(r30)
    bl      issueCommand
    cmpwi   r3,0
    bne-    .L_8025F4E4
    li      r3,-1
    b       .L_8025F538
.L_8025F4E4:
    bl      OSDisableInterrupts
    mr      r31,r3
.L_8025F4EC:
    lwz     r0,12(r30)
    cmpwi   r0,0
    bne-    .L_8025F500
    lwz     r30,32(r30)
    b       .L_8025F52C
.L_8025F500:
    cmpwi   r0,-1
    bne-    .L_8025F510
    li      r30,-1
    b       .L_8025F52C
.L_8025F510:
    cmpwi   r0,10
    bne-    .L_8025F520
    li      r30,-3
    b       .L_8025F52C
.L_8025F520:
    addi    r3,r13,-23488
    bl      OSSleepThread
    b       .L_8025F4EC
.L_8025F52C:
    mr      r3,r31
    bl      OSRestoreInterrupts
    mr      r3,r30
.L_8025F538:
    lwz     r0,44(r1)
    lwz     r31,36(r1)
    lwz     r30,32(r1)
    addi    r1,r1,40
    mtlr    r0
    blr
.size DVDInquiry, . - DVDInquiry

.global DVDReset
.balign 4
DVDReset:
/* 0x8025F574 | size=0x44 (68 bytes) */
    mflr    r0
    stw     r0,4(r1)
    stwu    r1,-8(r1)
    bl      DVDLowReset
    lis     r3,-13312
    li      r0,42
    stw     r0,24576(r3)
    addi    r4,r3,24576
    li      r0,0
    lwz     r3,24580(r3)
    stw     r3,4(r4)
    stw     r0,-23424(r13)
    stw     r0,-23440(r13)
    lwz     r0,12(r1)
    addi    r1,r1,8
    mtlr    r0
    blr
.size DVDReset, . - DVDReset

.global DVDGetCommandBlockStatus
.balign 4
DVDGetCommandBlockStatus:
/* 0x8025F5C0 | size=0x4C (76 bytes) */
    mflr    r0
    stw     r0,4(r1)
    stwu    r1,-24(r1)
    stw     r31,20(r1)
    mr      r31,r3
    bl      OSDisableInterrupts
    lwz     r0,12(r31)
    cmpwi   r0,3
    bne-    .L_8025F5EC
    li      r31,1
    b       .L_8025F5F0
.L_8025F5EC:
    mr      r31,r0
.L_8025F5F0:
    bl      OSRestoreInterrupts
    mr      r3,r31
    lwz     r0,28(r1)
    lwz     r31,20(r1)
    addi    r1,r1,24
    mtlr    r0
    blr
.size DVDGetCommandBlockStatus, . - DVDGetCommandBlockStatus

.global DVDGetDriveStatus
.balign 4
DVDGetDriveStatus:
/* 0x8025F60C | size=0xAC (172 bytes) */
    mflr    r0
    stw     r0,4(r1)
    stwu    r1,-24(r1)
    stw     r31,20(r1)
    stw     r30,16(r1)
    bl      OSDisableInterrupts
    lwz     r0,-23456(r13)
    addi    r30,r3,0
    cmpwi   r0,0
    beq-    .L_8025F63C
    li      r31,-1
    b       .L_8025F694
.L_8025F63C:
    lwz     r0,-23464(r13)
    cmpwi   r0,0
    beq-    .L_8025F650
    li      r31,8
    b       .L_8025F694
.L_8025F650:
    lwz     r31,-23480(r13)
    cmplwi  r31,0
    bne-    .L_8025F664
    li      r31,0
    b       .L_8025F694
.L_8025F664:
    lis     r3,-32694
    addi    r0,r3,-17184
    cmplw   r31,r0
    bne-    .L_8025F67C
    li      r31,0
    b       .L_8025F694
.L_8025F67C:
    bl      OSDisableInterrupts
    lwz     r31,12(r31)
    cmpwi   r31,3
    bne-    .L_8025F690
    li      r31,1
.L_8025F690:
    bl      OSRestoreInterrupts
.L_8025F694:
    mr      r3,r30
    bl      OSRestoreInterrupts
    mr      r3,r31
    lwz     r0,28(r1)
    lwz     r31,20(r1)
    lwz     r30,16(r1)
    addi    r1,r1,24
    mtlr    r0
    blr
.size DVDGetDriveStatus, . - DVDGetDriveStatus

.global DVDResume
.balign 4
DVDResume:
/* 0x8025F704 | size=0x50 (80 bytes) */
    mflr    r0
    stw     r0,4(r1)
    stwu    r1,-16(r1)
    stw     r31,12(r1)
    bl      OSDisableInterrupts
    li      r4,0
    stw     r4,-23468(r13)
    mr      r31,r3
    lwz     r0,-23464(r13)
    cmpwi   r0,0
    beq-    .L_8025F738
    stw     r4,-23464(r13)
    bl      stateReady
.L_8025F738:
    mr      r3,r31
    bl      OSRestoreInterrupts
    lwz     r0,20(r1)
    lwz     r31,12(r1)
    addi    r1,r1,16
    mtlr    r0
    blr
.size DVDResume, . - DVDResume

.global DVDCancel
.balign 4
DVDCancel:
/* 0x8025F9D0 | size=0xAC (172 bytes) */
    mflr    r0
    lis     r4,-32730
    stw     r0,4(r1)
    addi    r4,r4,-1412
    stwu    r1,-24(r1)
    stw     r31,20(r1)
    stw     r30,16(r1)
    addi    r30,r3,0
    bl      DVDCancelAsync
    cmpwi   r3,0
    bne-    .L_8025FA04
    li      r3,-1
    b       .L_8025FA64
.L_8025FA04:
    bl      OSDisableInterrupts
    mr      r31,r3
.L_8025FA0C:
    lwz     r3,12(r30)
    addi    r0,r3,1
    cmplwi  r0,1
    ble-    .L_8025FA58
    cmpwi   r3,10
    beq-    .L_8025FA58
    cmpwi   r3,3
    bne-    .L_8025FA4C
    lwz     r3,8(r30)
    addi    r0,r3,-4
    cmplwi  r0,1
    ble-    .L_8025FA58
    cmplwi  r3,13
    beq-    .L_8025FA58
    cmplwi  r3,15
    beq-    .L_8025FA58
.L_8025FA4C:
    addi    r3,r13,-23488
    bl      OSSleepThread
    b       .L_8025FA0C
.L_8025FA58:
    mr      r3,r31
    bl      OSRestoreInterrupts
    li      r3,0
.L_8025FA64:
    lwz     r0,28(r1)
    lwz     r31,20(r1)
    lwz     r30,16(r1)
    addi    r1,r1,24
    mtlr    r0
    blr
.size DVDCancel, . - DVDCancel

.global DVDCancelAllAsync
.balign 4
DVDCancelAllAsync:
/* 0x8025FAA0 | size=0xEC (236 bytes) */
    mflr    r0
    stw     r0,4(r1)
    stwu    r1,-32(r1)
    stw     r31,28(r1)
    mr      r31,r3
    stw     r30,24(r1)
    stw     r29,20(r1)
    bl      OSDisableInterrupts
    mr      r30,r3
    bl      OSDisableInterrupts
    lwz     r0,-23480(r13)
    li      r4,1
    stw     r4,-23468(r13)
    cmplwi  r0,0
    bne-    .L_8025FAE0
    stw     r4,-23464(r13)
.L_8025FAE0:
    bl      OSRestoreInterrupts
    b       .L_8025FAF0
.L_8025FAE8:
    li      r4,0
    bl      DVDCancelAsync
.L_8025FAF0:
    bl      __DVDPopWaitingQueue
    cmplwi  r3,0
    bne+    .L_8025FAE8
    lwz     r3,-23480(r13)
    cmplwi  r3,0
    beq-    .L_8025FB18
    mr      r4,r31
    bl      DVDCancelAsync
    mr      r29,r3
    b       .L_8025FB38
.L_8025FB18:
    cmplwi  r31,0
    li      r29,1
    beq-    .L_8025FB38
    addi    r12,r31,0
    mtlr    r12
    li      r3,0
    li      r4,0
    blrl
.L_8025FB38:
    bl      OSDisableInterrupts
    li      r4,0
    stw     r4,-23468(r13)
    mr      r31,r3
    lwz     r0,-23464(r13)
    cmpwi   r0,0
    beq-    .L_8025FB5C
    stw     r4,-23464(r13)
    bl      stateReady
.L_8025FB5C:
    mr      r3,r31
    bl      OSRestoreInterrupts
    mr      r3,r30
    bl      OSRestoreInterrupts
    mr      r3,r29
    lwz     r0,36(r1)
    lwz     r31,28(r1)
    lwz     r30,24(r1)
    lwz     r29,20(r1)
    addi    r1,r1,32
    mtlr    r0
    blr
.size DVDCancelAllAsync, . - DVDCancelAllAsync

.global DVDCheckDisk
.balign 4
DVDCheckDisk:
/* 0x8025FCF8 | size=0xF8 (248 bytes) */
    mflr    r0
    stw     r0,4(r1)
    stwu    r1,-16(r1)
    stw     r31,12(r1)
    bl      OSDisableInterrupts
    lwz     r0,-23456(r13)
    cmpwi   r0,0
    beq-    .L_8025FD20
    li      r4,-1
    b       .L_8025FD64
.L_8025FD20:
    lwz     r0,-23464(r13)
    cmpwi   r0,0
    beq-    .L_8025FD34
    li      r4,8
    b       .L_8025FD64
.L_8025FD34:
    lwz     r5,-23480(r13)
    cmplwi  r5,0
    bne-    .L_8025FD48
    li      r4,0
    b       .L_8025FD64
.L_8025FD48:
    lis     r4,-32694
    addi    r0,r4,-17184
    cmplw   r5,r0
    bne-    .L_8025FD60
    li      r4,0
    b       .L_8025FD64
.L_8025FD60:
    lwz     r4,12(r5)
.L_8025FD64:
    addi    r0,r4,1
    cmplwi  r0,12
    bgt-    .L_8025FDD4
    lis     r4,-32700
    addi    r4,r4,-14240
    slwi    r0,r0,2
    lwzx    r0,r4,r0
    mtctr   r0
    bctr
    li      r31,1
    b       .L_8025FDD4
    li      r31,0
    b       .L_8025FDD4
    lis     r4,-13312
    addi    r4,r4,24576
    lwz     r4,4(r4)
    rlwinm. r0,r4,30,31,31
    bne-    .L_8025FDB4
    clrlwi. r0,r4,31
    beq-    .L_8025FDBC
.L_8025FDB4:
    li      r31,0
    b       .L_8025FDD4
.L_8025FDBC:
    lwz     r0,-23440(r13)
    cmplwi  r0,0
    beq-    .L_8025FDD0
    li      r31,0
    b       .L_8025FDD4
.L_8025FDD0:
    li      r31,1
.L_8025FDD4:
    bl      OSRestoreInterrupts
    mr      r3,r31
    lwz     r0,20(r1)
    lwz     r31,12(r1)
    addi    r1,r1,16
    mtlr    r0
    blr
.size DVDCheckDisk, . - DVDCheckDisk

#
# === dvdFatal.o ===
#

.global ShowMessage
.balign 4
ShowMessage:
/* 0x80260820 | size=0x8C (140 bytes) */
    mflr    r0
    stw     r0,4(r1)
    stwu    r1,-24(r1)
    lwz     r3,-18472(r13)
    lwz     r0,-18468(r13)
    stw     r3,20(r1)
    stw     r0,16(r1)
    bl      VIGetTvFormat
    cmplwi  r3,0
    bne-    .L_80260868
    bl      OSGetFontEncode
    clrlwi  r0,r3,16
    cmplwi  r0,1
    bne-    .L_80260860
    lwz     r5,-27704(r13)
    b       .L_80260880
.L_80260860:
    lwz     r5,-27700(r13)
    b       .L_80260880
.L_80260868:
    bl      OSGetLanguage
    lis     r4,-32704
    rlwinm  r3,r3,2,22,29
    addi    r0,r4,1096
    add     r3,r0,r3
    lwz     r5,0(r3)
.L_80260880:
    lwz     r6,20(r1)
    addi    r4,r1,8
    lwz     r0,16(r1)
    addi    r3,r1,12
    stw     r6,8(r1)
    stw     r0,12(r1)
    bl      OSFatal
    lwz     r0,28(r1)
    addi    r1,r1,24
    mtlr    r0
    blr
.size ShowMessage, . - ShowMessage

.global DVDSetAutoFatalMessaging
.balign 4
DVDSetAutoFatalMessaging:
/* 0x802608AC | size=0x70 (112 bytes) */
    mflr    r0
    stw     r0,4(r1)
    stwu    r1,-24(r1)
    stw     r31,20(r1)
    stw     r30,16(r1)
    mr      r30,r3
    bl      OSDisableInterrupts
    lwz     r0,-23384(r13)
    cmplwi  r0,0
    beq-    .L_802608DC
    li      r31,1
    b       .L_802608E0
.L_802608DC:
    li      r31,0
.L_802608E0:
    cmpwi   r30,0
    beq-    .L_802608F4
    lis     r4,-32730
    addi    r0,r4,2080
    b       .L_802608F8
.L_802608F4:
    li      r0,0
.L_802608F8:
    stw     r0,-23384(r13)
    bl      OSRestoreInterrupts
    mr      r3,r31
    lwz     r0,28(r1)
    lwz     r31,20(r1)
    lwz     r30,16(r1)
    addi    r1,r1,24
    mtlr    r0
    blr
.size DVDSetAutoFatalMessaging, . - DVDSetAutoFatalMessaging

#
# === dvderror.o ===
#

.global __DVDStoreErrorCode
.balign 4
__DVDStoreErrorCode:
/* 0x802605F4 | size=0x7C (124 bytes) */
    mflr    r0
    stw     r0,4(r1)
    addis   r0,r3,-291
    cmplwi  r0,17767
    stwu    r1,-24(r1)
    stw     r31,20(r1)
    bne-    .L_80260618
    li      r31,255
    b       .L_8026064C
.L_80260618:
    cmplwi  r0,17768
    bne-    .L_80260628
    li      r31,254
    b       .L_8026064C
.L_80260628:
    srwi    r31,r3,24
    clrlwi  r3,r3,8
    bl      ErrorCode2Num
    cmplwi  r31,6
    blt-    .L_80260640
    li      r31,6
.L_80260640:
    mulli   r0,r31,30
    clrlwi  r3,r3,24
    add     r31,r3,r0
.L_8026064C:
    bl      __OSLockSramEx
    stb     r31,36(r3)
    li      r3,1
    bl      __OSUnlockSramEx
    lwz     r0,28(r1)
    lwz     r31,20(r1)
    addi    r1,r1,24
    mtlr    r0
    blr
.size __DVDStoreErrorCode, . - __DVDStoreErrorCode

#
# === dvdfs.o ===
#

.global isSame
.balign 4
isSame:
/* 0x8025B0D0 | size=0xA0 (160 bytes) */
    mflr    r0
    stw     r0,4(r1)
    stwu    r1,-32(r1)
    stw     r31,28(r1)
    stw     r30,24(r1)
    addi    r30,r4,0
    stw     r29,20(r1)
    addi    r29,r3,0
    b       .L_8025B128
.L_8025B0F4:
    lbz     r0,0(r30)
    addi    r30,r30,1
    extsb   r3,r0
    bl      tolower
    lbz     r0,0(r29)
    addi    r31,r3,0
    addi    r29,r29,1
    extsb   r3,r0
    bl      tolower
    cmpw    r3,r31
    beq-    .L_8025B128
    li      r3,0
    b       .L_8025B154
.L_8025B128:
    lbz     r0,0(r30)
    extsb.  r0,r0
    bne+    .L_8025B0F4
    lbz     r3,0(r29)
    cmpwi   r3,47
    beq-    .L_8025B148
    extsb.  r0,r3
    bne-    .L_8025B150
.L_8025B148:
    li      r3,1
    b       .L_8025B154
.L_8025B150:
    li      r3,0
.L_8025B154:
    lwz     r0,36(r1)
    lwz     r31,28(r1)
    lwz     r30,24(r1)
    lwz     r29,20(r1)
    addi    r1,r1,32
    mtlr    r0
    blr
.size isSame, . - isSame

.global DVDFastOpen
.balign 4
DVDFastOpen:
/* 0x8025B464 | size=0x74 (116 bytes) */
    cmpwi   r3,0
    blt-    .L_8025B4A0
    lwz     r0,-23500(r13)
    cmplw   r3,r0
    bge-    .L_8025B4A0
    mulli   r6,r3,12
    lwz     r3,-23508(r13)
    lwzx    r0,r3,r6
    clrrwi. r0,r0,24
    bne-    .L_8025B494
    li      r0,0
    b       .L_8025B498
.L_8025B494:
    li      r0,1
.L_8025B498:
    cmpwi   r0,0
    beq-    .L_8025B4A8
.L_8025B4A0:
    li      r3,0
    blr
.L_8025B4A8:
    add     r3,r3,r6
    lwz     r5,4(r3)
    li      r0,0
    li      r3,1
    stw     r5,48(r4)
    lwz     r5,-23508(r13)
    add     r5,r5,r6
    lwz     r5,8(r5)
    stw     r5,52(r4)
    stw     r0,56(r4)
    stw     r0,12(r4)
    blr
.size DVDFastOpen, . - DVDFastOpen

.global DVDOpen
.balign 4
DVDOpen:
/* 0x8025B4D8 | size=0xC8 (200 bytes) */
    mflr    r0
    stw     r0,4(r1)
    stwu    r1,-152(r1)
    stw     r31,148(r1)
    addi    r31,r4,0
    stw     r30,144(r1)
    addi    r30,r3,0
    bl      DVDConvertPathToEntrynum
    cmpwi   r3,0
    bge-    .L_8025B52C
    addi    r3,r1,16
    li      r4,128
    bl      DVDGetCurrentDir
    lis     r3,-32700
    crclr   4*cr1+eq
    addi    r3,r3,-15384
    addi    r4,r30,0
    addi    r5,r1,16
    bl      OSReport
    li      r3,0
    b       .L_8025B588
.L_8025B52C:
    mulli   r5,r3,12
    lwz     r3,-23508(r13)
    lwzx    r0,r3,r5
    clrrwi. r0,r0,24
    bne-    .L_8025B548
    li      r0,0
    b       .L_8025B54C
.L_8025B548:
    li      r0,1
.L_8025B54C:
    cmpwi   r0,0
    beq-    .L_8025B55C
    li      r3,0
    b       .L_8025B588
.L_8025B55C:
    add     r3,r3,r5
    lwz     r4,4(r3)
    li      r0,0
    li      r3,1
    stw     r4,48(r31)
    lwz     r4,-23508(r13)
    add     r4,r4,r5
    lwz     r4,8(r4)
    stw     r4,52(r31)
    stw     r0,56(r31)
    stw     r0,12(r31)
.L_8025B588:
    lwz     r0,156(r1)
    lwz     r31,148(r1)
    lwz     r30,144(r1)
    addi    r1,r1,152
    mtlr    r0
    blr
.size DVDOpen, . - DVDOpen

.global DVDGetCurrentDir
.balign 4
DVDGetCurrentDir:
/* 0x8025B8B0 | size=0xC4 (196 bytes) */
    mflr    r0
    stw     r0,4(r1)
    stwu    r1,-32(r1)
    stw     r31,28(r1)
    stw     r30,24(r1)
    addi    r30,r4,0
    addi    r5,r30,0
    stw     r29,20(r1)
    addi    r29,r3,0
    addi    r4,r29,0
    lwz     r31,-23496(r13)
    addi    r3,r31,0
    bl      entryToPath
    cmplw   r3,r30
    bne-    .L_8025B8FC
    li      r0,0
    add     r3,r29,r30
    stb     r0,-1(r3)
    b       .L_8025B954
.L_8025B8FC:
    mulli   r0,r31,12
    lwz     r4,-23508(r13)
    lwzx    r0,r4,r0
    clrrwi. r0,r0,24
    bne-    .L_8025B918
    li      r0,0
    b       .L_8025B91C
.L_8025B918:
    li      r0,1
.L_8025B91C:
    cmpwi   r0,0
    beq-    .L_8025B948
    addi    r0,r30,-1
    cmplw   r3,r0
    bne-    .L_8025B93C
    li      r0,0
    stbx    r0,r29,r3
    b       .L_8025B954
.L_8025B93C:
    li      r0,47
    stbx    r0,r29,r3
    addi    r3,r3,1
.L_8025B948:
    li      r0,0
    stbx    r0,r29,r3
    li      r0,1
.L_8025B954:
    mr      r3,r0
    lwz     r0,36(r1)
    lwz     r31,28(r1)
    lwz     r30,24(r1)
    lwz     r29,20(r1)
    addi    r1,r1,32
    mtlr    r0
    blr
.size DVDGetCurrentDir, . - DVDGetCurrentDir

.global DVDChangeDir
.balign 4
DVDChangeDir:
/* 0x8025B974 | size=0x60 (96 bytes) */
    mflr    r0
    stw     r0,4(r1)
    stwu    r1,-8(r1)
    bl      DVDConvertPathToEntrynum
    cmpwi   r3,0
    blt-    .L_8025B9B4
    mulli   r0,r3,12
    lwz     r4,-23508(r13)
    lwzx    r0,r4,r0
    clrrwi. r0,r0,24
    bne-    .L_8025B9A8
    li      r0,0
    b       .L_8025B9AC
.L_8025B9A8:
    li      r0,1
.L_8025B9AC:
    cmpwi   r0,0
    bne-    .L_8025B9BC
.L_8025B9B4:
    li      r3,0
    b       .L_8025B9C4
.L_8025B9BC:
    stw     r3,-23496(r13)
    li      r3,1
.L_8025B9C4:
    lwz     r0,12(r1)
    addi    r1,r1,8
    mtlr    r0
    blr
.size DVDChangeDir, . - DVDChangeDir

.global DVDReadAsyncPrio
.balign 4
DVDReadAsyncPrio:
/* 0x8025B9D4 | size=0xC0 (192 bytes) */
    mflr    r0
    stw     r0,4(r1)
    stwu    r1,-56(r1)
    stmw    r26,32(r1)
    mr.     r29,r6
    addi    r26,r3,0
    addi    r27,r4,0
    addi    r28,r5,0
    addi    r30,r7,0
    addi    r31,r8,0
    blt-    .L_8025BA0C
    lwz     r0,52(r26)
    cmplw   r29,r0
    ble-    .L_8025BA24
.L_8025BA0C:
    lis     r3,-32700
    crclr   4*cr1+eq
    addi    r5,r3,-15328
    addi    r3,r13,-27800
    li      r4,750
    bl      OSPanic
.L_8025BA24:
    add.    r4,r29,r28
    blt-    .L_8025BA3C
    lwz     r3,52(r26)
    addi    r0,r3,32
    cmplw   r4,r0
    blt-    .L_8025BA54
.L_8025BA3C:
    lis     r3,-32700
    crclr   4*cr1+eq
    addi    r5,r3,-15328
    addi    r3,r13,-27800
    li      r4,756
    bl      OSPanic
.L_8025BA54:
    stw     r30,56(r26)
    lis     r3,-32730
    addi    r7,r3,-17772
    lwz     r0,48(r26)
    addi    r3,r26,0
    addi    r4,r27,0
    addi    r5,r28,0
    addi    r8,r31,0
    add     r6,r0,r29
    bl      DVDReadAbsAsyncPrio
    lmw     r26,32(r1)
    li      r3,1
    lwz     r0,60(r1)
    addi    r1,r1,56
    mtlr    r0
    blr
.size DVDReadAsyncPrio, . - DVDReadAsyncPrio

.global DVDSeekAsyncPrio
.balign 4
DVDSeekAsyncPrio:
/* 0x8025BC00 | size=0x98 (152 bytes) */
    mflr    r0
    stw     r0,4(r1)
    stwu    r1,-40(r1)
    stw     r31,36(r1)
    addi    r31,r6,0
    stw     r30,32(r1)
    addi    r30,r5,0
    stw     r29,28(r1)
    mr.     r29,r4
    stw     r28,24(r1)
    addi    r28,r3,0
    blt-    .L_8025BC3C
    lwz     r0,52(r28)
    cmplw   r29,r0
    ble-    .L_8025BC54
.L_8025BC3C:
    lis     r3,-32700
    crclr   4*cr1+eq
    addi    r5,r3,-15228
    addi    r3,r13,-27800
    li      r4,907
    bl      OSPanic
.L_8025BC54:
    stw     r30,56(r28)
    lis     r3,-32730
    addi    r5,r3,-17256
    lwz     r0,48(r28)
    addi    r3,r28,0
    addi    r6,r31,0
    add     r4,r0,r29
    bl      DVDSeekAbsAsyncPrio
    lwz     r0,44(r1)
    li      r3,1
    lwz     r31,36(r1)
    lwz     r30,32(r1)
    lwz     r29,28(r1)
    lwz     r28,24(r1)
    addi    r1,r1,40
    mtlr    r0
    blr
.size DVDSeekAsyncPrio, . - DVDSeekAsyncPrio

.global DVDSeekPrio
.balign 4
DVDSeekPrio:
/* 0x8025BCC8 | size=0xAC (172 bytes) */
    mflr    r0
    lis     r7,-32730
    stw     r0,4(r1)
    addi    r6,r5,0
    addi    r5,r7,-17036
    stwu    r1,-32(r1)
    stw     r31,28(r1)
    stw     r30,24(r1)
    addi    r30,r3,0
    lwz     r0,48(r3)
    add     r4,r0,r4
    bl      DVDSeekAbsAsyncPrio
    cmpwi   r3,0
    bne-    .L_8025BD08
    li      r3,-1
    b       .L_8025BD5C
.L_8025BD08:
    bl      OSDisableInterrupts
    mr      r31,r3
.L_8025BD10:
    lwz     r0,12(r30)
    cmpwi   r0,0
    bne-    .L_8025BD24
    li      r30,0
    b       .L_8025BD50
.L_8025BD24:
    cmpwi   r0,-1
    bne-    .L_8025BD34
    li      r30,-1
    b       .L_8025BD50
.L_8025BD34:
    cmpwi   r0,10
    bne-    .L_8025BD44
    li      r30,-3
    b       .L_8025BD50
.L_8025BD44:
    addi    r3,r13,-23488
    bl      OSSleepThread
    b       .L_8025BD10
.L_8025BD50:
    mr      r3,r31
    bl      OSRestoreInterrupts
    mr      r3,r30
.L_8025BD5C:
    lwz     r0,36(r1)
    lwz     r31,28(r1)
    lwz     r30,24(r1)
    addi    r1,r1,32
    mtlr    r0
    blr
.size DVDSeekPrio, . - DVDSeekPrio

.global DVDFastOpenDir
.balign 4
DVDFastOpenDir:
/* 0x8025BDB8 | size=0x68 (104 bytes) */
    cmpwi   r3,0
    blt-    .L_8025BDF4
    lwz     r0,-23500(r13)
    cmplw   r3,r0
    bge-    .L_8025BDF4
    mulli   r6,r3,12
    lwz     r5,-23508(r13)
    lwzx    r0,r5,r6
    clrrwi. r0,r0,24
    bne-    .L_8025BDE8
    li      r0,0
    b       .L_8025BDEC
.L_8025BDE8:
    li      r0,1
.L_8025BDEC:
    cmpwi   r0,0
    bne-    .L_8025BDFC
.L_8025BDF4:
    li      r3,0
    blr
.L_8025BDFC:
    stw     r3,0(r4)
    addi    r0,r3,1
    li      r3,1
    stw     r0,4(r4)
    lwz     r0,-23508(r13)
    add     r5,r0,r6
    lwz     r0,8(r5)
    stw     r0,8(r4)
    blr
.size DVDFastOpenDir, . - DVDFastOpenDir

.global DVDOpenDir
.balign 4
DVDOpenDir:
/* 0x8025BE20 | size=0xC0 (192 bytes) */
    mflr    r0
    stw     r0,4(r1)
    stwu    r1,-152(r1)
    stw     r31,148(r1)
    addi    r31,r4,0
    stw     r30,144(r1)
    addi    r30,r3,0
    bl      DVDConvertPathToEntrynum
    cmpwi   r3,0
    bge-    .L_8025BE78
    lwz     r3,-23496(r13)
    addi    r4,r1,16
    li      r5,128
    bl      DVDConvertEntrynumToPath
    lis     r3,-32700
    crclr   4*cr1+eq
    addi    r3,r3,-15188
    addi    r4,r30,0
    addi    r5,r1,16
    bl      OSReport
    li      r3,0
    b       .L_8025BEC8
.L_8025BE78:
    mulli   r5,r3,12
    lwz     r4,-23508(r13)
    lwzx    r0,r4,r5
    clrrwi. r0,r0,24
    bne-    .L_8025BE94
    li      r0,0
    b       .L_8025BE98
.L_8025BE94:
    li      r0,1
.L_8025BE98:
    cmpwi   r0,0
    bne-    .L_8025BEA8
    li      r3,0
    b       .L_8025BEC8
.L_8025BEA8:
    stw     r3,0(r31)
    addi    r0,r3,1
    li      r3,1
    stw     r0,4(r31)
    lwz     r0,-23508(r13)
    add     r4,r0,r5
    lwz     r0,8(r4)
    stw     r0,8(r31)
.L_8025BEC8:
    lwz     r0,156(r1)
    lwz     r31,148(r1)
    lwz     r30,144(r1)
    addi    r1,r1,152
    mtlr    r0
    blr
.size DVDOpenDir, . - DVDOpenDir

.global DVDReadDir
.balign 4
DVDReadDir:
/* 0x8025BEE0 | size=0xA4 (164 bytes) */
    lwz     r7,4(r3)
    lwz     r0,0(r3)
    cmplw   r7,r0
    ble-    .L_8025BEFC
    lwz     r0,8(r3)
    cmplw   r0,r7
    bgt-    .L_8025BF04
.L_8025BEFC:
    li      r3,0
    blr
.L_8025BF04:
    stw     r7,0(r4)
    mulli   r8,r7,12
    lwz     r5,-23508(r13)
    lwzx    r0,r5,r8
    clrrwi. r0,r0,24
    bne-    .L_8025BF24
    li      r0,0
    b       .L_8025BF28
.L_8025BF24:
    li      r0,1
.L_8025BF28:
    stw     r0,4(r4)
    lwz     r5,-23508(r13)
    lwz     r6,-23504(r13)
    lwzx    r0,r5,r8
    clrlwi  r0,r0,8
    add     r0,r6,r0
    stw     r0,8(r4)
    lwz     r4,-23508(r13)
    lwzx    r0,r4,r8
    clrrwi. r0,r0,24
    bne-    .L_8025BF5C
    li      r0,0
    b       .L_8025BF60
.L_8025BF5C:
    li      r0,1
.L_8025BF60:
    cmpwi   r0,0
    beq-    .L_8025BF74
    add     r4,r4,r8
    lwz     r0,8(r4)
    b       .L_8025BF78
.L_8025BF74:
    addi    r0,r7,1
.L_8025BF78:
    stw     r0,4(r3)
    li      r3,1
    blr
.size DVDReadDir, . - DVDReadDir

.global DVDPrepareStreamAsync
.balign 4
DVDPrepareStreamAsync:
/* 0x8025BFA8 | size=0xEC (236 bytes) */
    mflr    r0
    stw     r0,4(r1)
    stwu    r1,-56(r1)
    stmw    r27,36(r1)
    addi    r29,r5,0
    mr      r27,r3
    addi    r28,r4,0
    addi    r30,r6,0
    lwz     r7,48(r3)
    lis     r3,-32700
    addi    r31,r3,-15584
    add     r0,r7,r29
    clrlwi. r0,r0,17
    beq-    .L_8025BFFC
    addi    r6,r7,0
    crclr   4*cr1+eq
    addi    r7,r29,0
    addi    r5,r31,456
    addi    r3,r13,-27800
    li      r4,1211
    bl      OSPanic
.L_8025BFFC:
    cmplwi  r28,0
    bne-    .L_8025C00C
    lwz     r0,52(r27)
    subf    r28,r29,r0
.L_8025C00C:
    clrlwi. r0,r28,17
    beq-    .L_8025C02C
    addi    r6,r28,0
    crclr   4*cr1+eq
    addi    r5,r31,560
    addi    r3,r13,-27800
    li      r4,1221
    bl      OSPanic
.L_8025C02C:
    lwz     r3,52(r27)
    cmplw   r29,r3
    bgt-    .L_8025C044
    add     r0,r29,r28
    cmplw   r0,r3
    ble-    .L_8025C060
.L_8025C044:
    addi    r6,r29,0
    crclr   4*cr1+eq
    addi    r7,r28,0
    addi    r5,r31,648
    addi    r3,r13,-27800
    li      r4,1229
    bl      OSPanic
.L_8025C060:
    stw     r30,56(r27)
    lis     r3,-32730
    addi    r6,r3,-16236
    lwz     r0,48(r27)
    addi    r3,r27,0
    addi    r4,r28,0
    add     r5,r0,r29
    bl      DVDPrepareStreamAbsAsync
    lmw     r27,36(r1)
    lwz     r0,60(r1)
    addi    r1,r1,56
    mtlr    r0
    blr
.size DVDPrepareStreamAsync, . - DVDPrepareStreamAsync

.global DVDGetTransferredSize
.balign 4
DVDGetTransferredSize:
/* 0x8025C22C | size=0x6C (108 bytes) */
    lwz     r0,12(r3)
    cmpwi   r0,2
    beq-    .L_8025C274
    bge-    .L_8025C250
    cmpwi   r0,1
    bge-    .L_8025C27C
    cmpwi   r0,-1
    bge-    .L_8025C26C
    blr
.L_8025C250:
    cmpwi   r0,10
    bge-    .L_8025C264
    cmpwi   r0,8
    bgelr-
    b       .L_8025C26C
.L_8025C264:
    cmpwi   r0,12
    bgelr-
.L_8025C26C:
    lwz     r3,32(r3)
    blr
.L_8025C274:
    li      r3,0
    blr
.L_8025C27C:
    lis     r4,-13312
    lwz     r0,28(r3)
    lwz     r5,32(r3)
    lwz     r3,24600(r4)
    subf    r0,r3,r0
    add     r3,r5,r0
    blr
.size DVDGetTransferredSize, . - DVDGetTransferredSize

#
# === dvdidutils.o ===
#

.global DVDCompareDiskID
.balign 4
DVDCompareDiskID:
/* 0x802606A8 | size=0xF8 (248 bytes) */
    mflr    r0
    stw     r0,4(r1)
    stwu    r1,-24(r1)
    stw     r31,20(r1)
    addi    r31,r4,0
    stw     r30,16(r1)
    mr      r30,r3
    lbz     r0,0(r3)
    extsb.  r0,r0
    beq-    .L_802606FC
    lbz     r0,0(r31)
    extsb.  r0,r0
    beq-    .L_802606FC
    addi    r3,r30,0
    addi    r4,r31,0
    li      r5,4
    bl      strncmp
    cmpwi   r3,0
    beq-    .L_802606FC
    li      r3,0
    b       .L_80260788
.L_802606FC:
    lbz     r0,4(r30)
    extsb.  r0,r0
    beq-    .L_8026072C
    lbz     r0,4(r31)
    extsb.  r0,r0
    beq-    .L_8026072C
    addi    r3,r30,4
    addi    r4,r31,4
    li      r5,2
    bl      strncmp
    cmpwi   r3,0
    beq-    .L_80260734
.L_8026072C:
    li      r3,0
    b       .L_80260788
.L_80260734:
    lbz     r3,6(r30)
    cmplwi  r3,255
    beq-    .L_8026075C
    lbz     r0,6(r31)
    cmplwi  r0,255
    beq-    .L_8026075C
    cmplw   r3,r0
    beq-    .L_8026075C
    li      r3,0
    b       .L_80260788
.L_8026075C:
    lbz     r3,7(r30)
    cmplwi  r3,255
    beq-    .L_80260784
    lbz     r0,7(r31)
    cmplwi  r0,255
    beq-    .L_80260784
    cmplw   r3,r0
    beq-    .L_80260784
    li      r3,0
    b       .L_80260788
.L_80260784:
    li      r3,1
.L_80260788:
    lwz     r0,28(r1)
    lwz     r31,20(r1)
    lwz     r30,16(r1)
    addi    r1,r1,24
    mtlr    r0
    blr
.size DVDCompareDiskID, . - DVDCompareDiskID

.global DVDGenerateDiskID
.balign 4
DVDGenerateDiskID:
/* 0x802607A0 | size=0x80 (128 bytes) */
    mflr    r0
    stw     r0,4(r1)
    stwu    r1,-48(r1)
    stmw    r27,28(r1)
    addi    r28,r4,0
    addi    r29,r5,0
    addi    r27,r3,0
    addi    r30,r6,0
    addi    r31,r7,0
    li      r4,0
    li      r5,32
    bl      memset
    cmplwi  r28,0
    beq-    .L_802607E8
    addi    r3,r27,0
    addi    r4,r28,0
    li      r5,4
    bl      strncpy
.L_802607E8:
    cmplwi  r29,0
    beq-    .L_80260800
    addi    r4,r29,0
    addi    r3,r27,4
    li      r5,2
    bl      strncpy
.L_80260800:
    stb     r30,6(r27)
    mr      r3,r27
    stb     r31,7(r27)
    lwz     r0,52(r1)
    lmw     r27,28(r1)
    addi    r1,r1,48
    mtlr    r0
    blr
.size DVDGenerateDiskID, . - DVDGenerateDiskID

#
# === dvdlow.o ===
#

.global ProcessNextCommand
.balign 4
ProcessNextCommand:
/* 0x80260BCC | size=0x94 (148 bytes) */
    mflr    r0
    lis     r3,-32694
    stw     r0,4(r1)
    addi    r4,r3,-16952
    stwu    r1,-8(r1)
    lwz     r0,-23292(r13)
    mulli   r0,r0,20
    lwzx    r3,r4,r0
    cmpwi   r3,1
    bne-    .L_80260C20
    lwz     r3,-23292(r13)
    add     r6,r4,r0
    addi    r0,r3,1
    stw     r0,-23292(r13)
    lwz     r3,4(r6)
    lwz     r4,8(r6)
    lwz     r5,12(r6)
    lwz     r6,16(r6)
    bl      Read
    li      r3,1
    b       .L_80260C50
.L_80260C20:
    cmpwi   r3,2
    bne-    .L_80260C4C
    lwz     r3,-23292(r13)
    add     r4,r4,r0
    addi    r0,r3,1
    stw     r0,-23292(r13)
    lwz     r3,12(r4)
    lwz     r4,16(r4)
    bl      DVDLowSeek
    li      r3,1
    b       .L_80260C50
.L_80260C4C:
    li      r3,0
.L_80260C50:
    lwz     r0,12(r1)
    addi    r1,r1,8
    mtlr    r0
    blr
.size ProcessNextCommand, . - ProcessNextCommand

.global AlarmHandler_dvdlow
.balign 4
AlarmHandler_dvdlow:
/* 0x80260F40 | size=0x84 (132 bytes) */
    mflr    r0
    lis     r3,-32694
    stw     r0,4(r1)
    addi    r4,r3,-16952
    stwu    r1,-8(r1)
    lwz     r0,-23292(r13)
    mulli   r0,r0,20
    lwzx    r3,r4,r0
    cmpwi   r3,1
    bne-    .L_80260F90
    lwz     r3,-23292(r13)
    add     r6,r4,r0
    addi    r0,r3,1
    stw     r0,-23292(r13)
    lwz     r3,4(r6)
    lwz     r4,8(r6)
    lwz     r5,12(r6)
    lwz     r6,16(r6)
    bl      Read
    b       .L_80260FB4
.L_80260F90:
    cmpwi   r3,2
    bne-    .L_80260FB4
    lwz     r3,-23292(r13)
    add     r4,r4,r0
    addi    r0,r3,1
    stw     r0,-23292(r13)
    lwz     r3,12(r4)
    lwz     r4,16(r4)
    bl      DVDLowSeek
.L_80260FB4:
    lwz     r0,12(r1)
    addi    r1,r1,8
    mtlr    r0
    blr
.size AlarmHandler_dvdlow, . - AlarmHandler_dvdlow

.global AlarmHandlerForTimeout
.balign 4
AlarmHandlerForTimeout:
/* 0x80260FC4 | size=0x70 (112 bytes) */
    mflr    r0
    li      r3,1024
    stw     r0,4(r1)
    stwu    r1,-736(r1)
    stw     r31,732(r1)
    addi    r31,r4,0
    bl      __OSMaskInterrupts
    addi    r3,r1,16
    bl      OSClearContext
    addi    r3,r1,16
    bl      OSSetCurrentContext
    lwz     r12,-23352(r13)
    li      r0,0
    cmplwi  r12,0
    stw     r0,-23352(r13)
    beq-    .L_80261010
    mtlr    r12
    li      r3,16
    blrl
.L_80261010:
    addi    r3,r1,16
    bl      OSClearContext
    mr      r3,r31
    bl      OSSetCurrentContext
    lwz     r0,740(r1)
    lwz     r31,732(r1)
    addi    r1,r1,736
    mtlr    r0
    blr
.size AlarmHandlerForTimeout, . - AlarmHandlerForTimeout

.global SetTimeoutAlarm
.balign 4
SetTimeoutAlarm:
/* 0x80261034 | size=0x64 (100 bytes) */
    mflr    r0
    lis     r5,-32694
    stw     r0,4(r1)
    stwu    r1,-32(r1)
    stw     r31,28(r1)
    addi    r31,r5,-16848
    stw     r30,24(r1)
    addi    r30,r3,0
    addi    r3,r31,0
    stw     r29,20(r1)
    addi    r29,r4,0
    bl      OSCreateAlarm
    lis     r3,-32730
    addi    r7,r3,4036
    addi    r3,r31,0
    addi    r6,r29,0
    addi    r5,r30,0
    bl      OSSetAlarm
    lwz     r0,36(r1)
    lwz     r31,28(r1)
    lwz     r30,24(r1)
    lwz     r29,20(r1)
    addi    r1,r1,32
    mtlr    r0
    blr
.size SetTimeoutAlarm, . - SetTimeoutAlarm

.global HitCache
.balign 4
HitCache:
/* 0x802611E0 | size=0xA0 (160 bytes) */
    mflr    r0
    stw     r0,4(r1)
    stwu    r1,-24(r1)
    stw     r31,20(r1)
    stw     r30,16(r1)
    lwz     r5,4(r4)
    lwz     r6,8(r4)
    lwz     r0,8(r3)
    addi    r4,r5,-1
    add     r3,r6,r4
    srwi    r31,r3,15
    srwi    r30,r0,15
    bl      DVDGetCurrentDiskID
    lbz     r0,8(r3)
    cmplwi  r0,0
    beq-    .L_80261228
    li      r0,1
    b       .L_8026122C
.L_80261228:
    li      r0,0
.L_8026122C:
    cmpwi   r0,0
    beq-    .L_8026123C
    li      r3,5
    b       .L_80261240
.L_8026123C:
    li      r3,15
.L_80261240:
    addi    r0,r31,-2
    cmplw   r30,r0
    bgt-    .L_8026125C
    addi    r0,r3,3
    add     r0,r31,r0
    cmplw   r30,r0
    bge-    .L_80261264
.L_8026125C:
    li      r3,1
    b       .L_80261268
.L_80261264:
    li      r3,0
.L_80261268:
    lwz     r0,28(r1)
    lwz     r31,20(r1)
    lwz     r30,16(r1)
    addi    r1,r1,24
    mtlr    r0
    blr
.size HitCache, . - HitCache

.global SeekTwiceBeforeRead
.balign 4
SeekTwiceBeforeRead:
/* 0x802612B4 | size=0x80 (128 bytes) */
    mflr    r0
    lis     r7,-32694
    stw     r0,4(r1)
    clrrwi. r8,r5,15
    addi    r9,r7,-16952
    stwu    r1,-8(r1)
    bne-    .L_802612D8
    li      r10,0
    b       .L_802612E0
.L_802612D8:
    lwz     r0,-23320(r13)
    add     r10,r8,r0
.L_802612E0:
    li      r0,2
    stw     r0,0(r9)
    li      r8,1
    li      r7,-1
    stw     r10,12(r9)
    li      r0,0
    stw     r6,16(r9)
    stw     r8,20(r9)
    stw     r3,24(r9)
    mr      r3,r10
    stw     r4,28(r9)
    mr      r4,r6
    stw     r5,32(r9)
    stw     r6,36(r9)
    stw     r7,40(r9)
    stw     r0,-23292(r13)
    bl      DVDLowSeek
    lwz     r0,12(r1)
    addi    r1,r1,8
    mtlr    r0
    blr
.size SeekTwiceBeforeRead, . - SeekTwiceBeforeRead

.global WaitBeforeRead
.balign 4
WaitBeforeRead:
/* 0x80261334 | size=0x8C (140 bytes) */
    mflr    r0
    lis     r9,-32694
    stw     r0,4(r1)
    li      r0,1
    stwu    r1,-48(r1)
    stw     r31,44(r1)
    addi    r31,r9,-16952
    li      r9,-1
    stw     r30,40(r1)
    addi    r30,r7,0
    stw     r29,36(r1)
    addi    r29,r8,0
    stw     r0,0(r31)
    li      r0,0
    stw     r3,4(r31)
    addi    r3,r31,64
    stw     r4,8(r31)
    stw     r5,12(r31)
    stw     r6,16(r31)
    stw     r9,20(r31)
    stw     r0,-23292(r13)
    bl      OSCreateAlarm
    lis     r3,-32730
    addi    r7,r3,3904
    addi    r6,r29,0
    addi    r5,r30,0
    addi    r3,r31,64
    bl      OSSetAlarm
    lwz     r0,52(r1)
    lwz     r31,44(r1)
    lwz     r30,40(r1)
    lwz     r29,36(r1)
    addi    r1,r1,48
    mtlr    r0
    blr
.size WaitBeforeRead, . - WaitBeforeRead

.global DVDLowSeek
.balign 4
DVDLowSeek:
/* 0x80261658 | size=0x94 (148 bytes) */
    mflr    r0
    stw     r0,4(r1)
    li      r0,0
    stwu    r1,-24(r1)
    stw     r31,20(r1)
    stw     r30,16(r1)
    stw     r4,-23352(r13)
    lis     r4,-13312
    addi    r4,r4,24576
    stw     r0,-23360(r13)
    lis     r0,-21760
    stw     r0,8(r4)
    srwi    r0,r3,2
    lis     r3,-32694
    stw     r0,12(r4)
    li      r0,1
    addi    r31,r3,-16848
    stw     r0,28(r4)
    lis     r4,-32768
    addi    r3,r31,0
    lwz     r0,248(r4)
    srwi    r0,r0,2
    mulli   r30,r0,10
    bl      OSCreateAlarm
    lis     r3,-32730
    addi    r7,r3,4036
    addi    r3,r31,0
    addi    r6,r30,0
    li      r5,0
    bl      OSSetAlarm
    lwz     r0,28(r1)
    li      r3,1
    lwz     r31,20(r1)
    lwz     r30,16(r1)
    addi    r1,r1,24
    mtlr    r0
    blr
.size DVDLowSeek, . - DVDLowSeek

.global DVDLowReadDiskID
.balign 4
DVDLowReadDiskID:
/* 0x80261718 | size=0xA4 (164 bytes) */
    mflr    r0
    li      r8,0
    stw     r0,4(r1)
    lis     r5,-22528
    addi    r0,r5,64
    stwu    r1,-24(r1)
    li      r6,32
    lis     r5,-32768
    stw     r31,20(r1)
    stw     r30,16(r1)
    stw     r4,-23352(r13)
    lis     r4,-13312
    addi    r7,r4,24576
    stw     r8,-23360(r13)
    stw     r0,24584(r4)
    lis     r4,-32694
    li      r0,3
    stw     r8,12(r7)
    addi    r31,r4,-16848
    stw     r6,16(r7)
    stw     r3,20(r7)
    mr      r3,r31
    stw     r6,24(r7)
    stw     r0,28(r7)
    lwz     r0,248(r5)
    srwi    r0,r0,2
    mulli   r30,r0,10
    bl      OSCreateAlarm
    lis     r3,-32730
    addi    r7,r3,4036
    addi    r3,r31,0
    addi    r6,r30,0
    li      r5,0
    bl      OSSetAlarm
    lwz     r0,28(r1)
    li      r3,1
    lwz     r31,20(r1)
    lwz     r30,16(r1)
    addi    r1,r1,24
    mtlr    r0
    blr
.size DVDLowReadDiskID, . - DVDLowReadDiskID

.global DVDLowStopMotor
.balign 4
DVDLowStopMotor:
/* 0x802617BC | size=0x8C (140 bytes) */
    mflr    r0
    stw     r0,4(r1)
    li      r0,0
    stwu    r1,-24(r1)
    stw     r31,20(r1)
    stw     r30,16(r1)
    stw     r3,-23352(r13)
    lis     r3,-13312
    addi    r4,r3,24576
    stw     r0,-23360(r13)
    lis     r0,-7424
    stw     r0,24584(r3)
    li      r0,1
    lis     r3,-32694
    stw     r0,28(r4)
    lis     r4,-32768
    addi    r31,r3,-16848
    lwz     r0,248(r4)
    addi    r3,r31,0
    srwi    r0,r0,2
    mulli   r30,r0,10
    bl      OSCreateAlarm
    lis     r3,-32730
    addi    r7,r3,4036
    addi    r3,r31,0
    addi    r6,r30,0
    li      r5,0
    bl      OSSetAlarm
    lwz     r0,28(r1)
    li      r3,1
    lwz     r31,20(r1)
    lwz     r30,16(r1)
    addi    r1,r1,24
    mtlr    r0
    blr
.size DVDLowStopMotor, . - DVDLowStopMotor

.global DVDLowRequestError
.balign 4
DVDLowRequestError:
/* 0x80261848 | size=0x8C (140 bytes) */
    mflr    r0
    stw     r0,4(r1)
    li      r0,0
    stwu    r1,-24(r1)
    stw     r31,20(r1)
    stw     r30,16(r1)
    stw     r3,-23352(r13)
    lis     r3,-13312
    addi    r4,r3,24576
    stw     r0,-23360(r13)
    lis     r0,-8192
    stw     r0,24584(r3)
    li      r0,1
    lis     r3,-32694
    stw     r0,28(r4)
    lis     r4,-32768
    addi    r31,r3,-16848
    lwz     r0,248(r4)
    addi    r3,r31,0
    srwi    r0,r0,2
    mulli   r30,r0,10
    bl      OSCreateAlarm
    lis     r3,-32730
    addi    r7,r3,4036
    addi    r3,r31,0
    addi    r6,r30,0
    li      r5,0
    bl      OSSetAlarm
    lwz     r0,28(r1)
    li      r3,1
    lwz     r31,20(r1)
    lwz     r30,16(r1)
    addi    r1,r1,24
    mtlr    r0
    blr
.size DVDLowRequestError, . - DVDLowRequestError

.global DVDLowInquiry
.balign 4
DVDLowInquiry:
/* 0x802618D4 | size=0x9C (156 bytes) */
    mflr    r0
    li      r6,32
    stw     r0,4(r1)
    li      r0,0
    lis     r5,-32768
    stwu    r1,-24(r1)
    stw     r31,20(r1)
    stw     r30,16(r1)
    stw     r4,-23352(r13)
    lis     r4,-13312
    addi    r7,r4,24576
    stw     r0,-23360(r13)
    lis     r0,4608
    stw     r0,24584(r4)
    lis     r4,-32694
    li      r0,3
    stw     r6,16(r7)
    addi    r31,r4,-16848
    stw     r3,20(r7)
    addi    r3,r31,0
    stw     r6,24(r7)
    stw     r0,28(r7)
    lwz     r0,248(r5)
    srwi    r0,r0,2
    mulli   r30,r0,10
    bl      OSCreateAlarm
    lis     r3,-32730
    addi    r7,r3,4036
    addi    r3,r31,0
    addi    r6,r30,0
    li      r5,0
    bl      OSSetAlarm
    lwz     r0,28(r1)
    li      r3,1
    lwz     r31,20(r1)
    lwz     r30,16(r1)
    addi    r1,r1,24
    mtlr    r0
    blr
.size DVDLowInquiry, . - DVDLowInquiry

.global DVDLowAudioStream
.balign 4
DVDLowAudioStream:
/* 0x80261970 | size=0x98 (152 bytes) */
    mflr    r0
    stw     r0,4(r1)
    li      r0,0
    stwu    r1,-32(r1)
    stw     r31,28(r1)
    stw     r30,24(r1)
    stw     r6,-23352(r13)
    lis     r6,-13312
    addi    r6,r6,24576
    stw     r0,-23360(r13)
    oris    r0,r3,57600
    lis     r3,-32694
    stw     r0,8(r6)
    srwi    r0,r5,2
    addi    r31,r3,-16848
    stw     r0,12(r6)
    li      r0,1
    addi    r3,r31,0
    stw     r4,16(r6)
    lis     r4,-32768
    stw     r0,28(r6)
    lwz     r0,248(r4)
    srwi    r0,r0,2
    mulli   r30,r0,10
    bl      OSCreateAlarm
    lis     r3,-32730
    addi    r7,r3,4036
    addi    r3,r31,0
    addi    r6,r30,0
    li      r5,0
    bl      OSSetAlarm
    lwz     r0,36(r1)
    li      r3,1
    lwz     r31,28(r1)
    lwz     r30,24(r1)
    addi    r1,r1,32
    mtlr    r0
    blr
.size DVDLowAudioStream, . - DVDLowAudioStream

.global DVDLowRequestAudioStatus
.balign 4
DVDLowRequestAudioStatus:
/* 0x80261A08 | size=0x8C (140 bytes) */
    mflr    r0
    stw     r0,4(r1)
    li      r0,0
    stwu    r1,-24(r1)
    stw     r31,20(r1)
    stw     r30,16(r1)
    stw     r4,-23352(r13)
    lis     r4,-13312
    addi    r4,r4,24576
    stw     r0,-23360(r13)
    oris    r0,r3,57856
    lis     r3,-32694
    stw     r0,8(r4)
    li      r0,1
    addi    r31,r3,-16848
    stw     r0,28(r4)
    lis     r4,-32768
    addi    r3,r31,0
    lwz     r0,248(r4)
    srwi    r0,r0,2
    mulli   r30,r0,10
    bl      OSCreateAlarm
    lis     r3,-32730
    addi    r7,r3,4036
    addi    r3,r31,0
    addi    r6,r30,0
    li      r5,0
    bl      OSSetAlarm
    lwz     r0,28(r1)
    li      r3,1
    lwz     r31,20(r1)
    lwz     r30,16(r1)
    addi    r1,r1,24
    mtlr    r0
    blr
.size DVDLowRequestAudioStatus, . - DVDLowRequestAudioStatus

.global DVDLowAudioBufferConfig
.balign 4
DVDLowAudioBufferConfig:
/* 0x80261A94 | size=0x9C (156 bytes) */
    mflr    r0
    cmpwi   r3,0
    stw     r0,4(r1)
    li      r0,0
    stwu    r1,-32(r1)
    stw     r31,28(r1)
    stw     r30,24(r1)
    stw     r5,-23352(r13)
    stw     r0,-23360(r13)
    beq-    .L_80261AC0
    lis     r0,1
.L_80261AC0:
    oris    r0,r0,58368
    lis     r3,-13312
    or      r0,r4,r0
    addi    r3,r3,24576
    stw     r0,8(r3)
    li      r0,1
    lis     r4,-32768
    stw     r0,28(r3)
    lis     r3,-32694
    addi    r31,r3,-16848
    lwz     r0,248(r4)
    addi    r3,r31,0
    srwi    r0,r0,2
    mulli   r30,r0,10
    bl      OSCreateAlarm
    lis     r3,-32730
    addi    r7,r3,4036
    addi    r3,r31,0
    addi    r6,r30,0
    li      r5,0
    bl      OSSetAlarm
    lwz     r0,36(r1)
    li      r3,1
    lwz     r31,28(r1)
    lwz     r30,24(r1)
    addi    r1,r1,32
    mtlr    r0
    blr
.size DVDLowAudioBufferConfig, . - DVDLowAudioBufferConfig

.global DVDLowReset
.balign 4
DVDLowReset:
/* 0x80261B30 | size=0xBC (188 bytes) */
    mflr    r0
    lis     r4,-13312
    stw     r0,4(r1)
    li      r0,2
    stwu    r1,-32(r1)
    stmw    r26,8(r1)
    addi    r31,r4,12288
    stw     r0,24580(r4)
    lwz     r30,12324(r4)
    rlwinm  r0,r30,0,30,28
    ori     r0,r0,1
    stwu    r0,36(r31)
    bl      __OSGetSystemTime
    lis     r5,-32768
    lwz     r0,248(r5)
    lis     r5,17180
    addi    r5,r5,-8573
    srwi    r0,r0,2
    mulhwu  r0,r5,r0
    srwi    r0,r0,15
    mulli   r0,r0,12
    addi    r26,r4,0
    addi    r27,r3,0
    srwi    r28,r0,3
    li      r29,0
.L_80261B94:
    bl      __OSGetSystemTime
    subfc   r5,r26,r4
    subfe   r0,r27,r3
    xoris   r4,r0,32768
    xoris   r3,r29,32768
    subfc   r0,r28,r5
    subfe   r3,r3,r4
    subfe   r3,r4,r4
    neg.    r3,r3
    bne+    .L_80261B94
    ori     r0,r30,5
    stw     r0,0(r31)
    li      r0,1
    stw     r0,-23336(r13)
    bl      __OSGetSystemTime
    stw     r4,-23340(r13)
    stw     r3,-23344(r13)
    lmw     r26,8(r1)
    lwz     r0,36(r1)
    addi    r1,r1,32
    mtlr    r0
    blr
.size DVDLowReset, . - DVDLowReset

.global DVDLowSetResetCoverCallback
.balign 4
DVDLowSetResetCoverCallback:
/* 0x80261BEC | size=0x44 (68 bytes) */
    mflr    r0
    stw     r0,4(r1)
    stwu    r1,-24(r1)
    stw     r31,20(r1)
    stw     r30,16(r1)
    mr      r30,r3
    bl      OSDisableInterrupts
    lwz     r31,-23348(r13)
    stw     r30,-23348(r13)
    bl      OSRestoreInterrupts
    mr      r3,r31
    lwz     r0,28(r1)
    lwz     r31,20(r1)
    lwz     r30,16(r1)
    addi    r1,r1,24
    mtlr    r0
    blr
.size DVDLowSetResetCoverCallback, . - DVDLowSetResetCoverCallback

.global AlarmHandlerForBreak
.balign 4
AlarmHandlerForBreak:
/* 0x80261C4C | size=0x74 (116 bytes) */
    mflr    r0
    lis     r4,-13312
    stw     r0,4(r1)
    addi    r3,r4,24576
    stwu    r1,-8(r1)
    lwz     r0,-23356(r13)
    lwz     r3,24(r3)
    cmplw   r3,r0
    bge-    .L_80261C88
    lwz     r3,24576(r4)
    li      r0,1
    ori     r3,r3,65
    stw     r3,24576(r4)
    stw     r0,-23328(r13)
    b       .L_80261CB0
.L_80261C88:
    lis     r3,-32768
    lwz     r0,248(r3)
    lis     r3,4194
    addi    r3,r3,19923
    srwi    r0,r0,2
    mulhwu  r0,r3,r0
    srwi    r0,r0,6
    mulli   r4,r0,20
    li      r3,0
    bl      SetBreakAlarm
.L_80261CB0:
    lwz     r0,12(r1)
    addi    r1,r1,8
    mtlr    r0
    blr
.size AlarmHandlerForBreak, . - AlarmHandlerForBreak

.global SetBreakAlarm
.balign 4
SetBreakAlarm:
/* 0x80261CC0 | size=0x64 (100 bytes) */
    mflr    r0
    lis     r5,-32694
    stw     r0,4(r1)
    stwu    r1,-32(r1)
    stw     r31,28(r1)
    addi    r31,r5,-16808
    stw     r30,24(r1)
    addi    r30,r3,0
    addi    r3,r31,0
    stw     r29,20(r1)
    addi    r29,r4,0
    bl      OSCreateAlarm
    lis     r3,-32730
    addi    r7,r3,7244
    addi    r3,r31,0
    addi    r6,r29,0
    addi    r5,r30,0
    bl      OSSetAlarm
    lwz     r0,36(r1)
    lwz     r31,28(r1)
    lwz     r30,24(r1)
    lwz     r29,20(r1)
    addi    r1,r1,32
    mtlr    r0
    blr
.size SetBreakAlarm, . - SetBreakAlarm

.global DVDLowGetCoverStatus
.balign 4
DVDLowGetCoverStatus:
/* 0x80261D54 | size=0x94 (148 bytes) */
    mflr    r0
    stw     r0,4(r1)
    stwu    r1,-8(r1)
    bl      __OSGetSystemTime
    lis     r5,-32768
    lwz     r7,-23344(r13)
    lwz     r6,248(r5)
    lis     r5,4194
    addi    r5,r5,19923
    lwz     r8,-23340(r13)
    srwi    r6,r6,2
    mulhwu  r5,r5,r6
    srwi    r5,r5,6
    mulli   r5,r5,100
    subfc   r6,r8,r4
    subfe   r3,r7,r3
    li      r0,0
    xoris   r4,r3,32768
    xoris   r3,r0,32768
    subfc   r0,r5,r6
    subfe   r3,r3,r4
    subfe   r3,r4,r4
    neg.    r3,r3
    beq-    .L_80261DBC
    li      r3,0
    b       .L_80261DD8
.L_80261DBC:
    lis     r3,-13312
    lwz     r0,24580(r3)
    clrlwi. r0,r0,31
    beq-    .L_80261DD4
    li      r3,1
    b       .L_80261DD8
.L_80261DD4:
    li      r3,2
.L_80261DD8:
    lwz     r0,12(r1)
    addi    r1,r1,8
    mtlr    r0
    blr
.size DVDLowGetCoverStatus, . - DVDLowGetCoverStatus

.global __DVDLowSetWAType
.balign 4
__DVDLowSetWAType:
/* 0x80261DE8 | size=0x44 (68 bytes) */
    mflr    r0
    stw     r0,4(r1)
    stwu    r1,-24(r1)
    stw     r31,20(r1)
    addi    r31,r4,0
    stw     r30,16(r1)
    addi    r30,r3,0
    bl      OSDisableInterrupts
    stw     r30,-23324(r13)
    stw     r31,-23320(r13)
    bl      OSRestoreInterrupts
    lwz     r0,28(r1)
    lwz     r31,20(r1)
    lwz     r30,16(r1)
    addi    r1,r1,24
    mtlr    r0
    blr
.size __DVDLowSetWAType, . - __DVDLowSetWAType

#
# === dvdqueue.o ===
#

.global __DVDPushWaitingQueue
.balign 4
__DVDPushWaitingQueue:
/* 0x8025FF7C | size=0x68 (104 bytes) */
    mflr    r0
    stw     r0,4(r1)
    stwu    r1,-24(r1)
    stw     r31,20(r1)
    addi    r31,r4,0
    stw     r30,16(r1)
    addi    r30,r3,0
    bl      OSDisableInterrupts
    lis     r4,-32694
    slwi    r5,r30,3
    addi    r0,r4,-17096
    add     r5,r0,r5
    lwz     r4,4(r5)
    stw     r31,0(r4)
    lwz     r0,4(r5)
    stw     r0,4(r31)
    stw     r5,0(r31)
    stw     r31,4(r5)
    bl      OSRestoreInterrupts
    lwz     r0,28(r1)
    li      r3,1
    lwz     r31,20(r1)
    lwz     r30,16(r1)
    addi    r1,r1,24
    mtlr    r0
    blr
.size __DVDPushWaitingQueue, . - __DVDPushWaitingQueue

.global PopWaitingQueuePrio
.balign 4
PopWaitingQueuePrio:
/* 0x8025FFE4 | size=0x64 (100 bytes) */
    mflr    r0
    stw     r0,4(r1)
    stwu    r1,-24(r1)
    stw     r31,20(r1)
    mr      r31,r3
    bl      OSDisableInterrupts
    lis     r4,-32694
    slwi    r5,r31,3
    addi    r0,r4,-17096
    add     r5,r0,r5
    lwz     r31,0(r5)
    lwz     r0,0(r31)
    stw     r0,0(r5)
    lwz     r4,0(r31)
    stw     r5,4(r4)
    bl      OSRestoreInterrupts
    li      r0,0
    stw     r0,0(r31)
    mr      r3,r31
    stw     r0,4(r31)
    lwz     r0,28(r1)
    lwz     r31,20(r1)
    addi    r1,r1,24
    mtlr    r0
    blr
.size PopWaitingQueuePrio, . - PopWaitingQueuePrio

.global __DVDPopWaitingQueue
.balign 4
__DVDPopWaitingQueue:
/* 0x80260048 | size=0xA0 (160 bytes) */
    mflr    r0
    stw     r0,4(r1)
    stwu    r1,-16(r1)
    stw     r31,12(r1)
    bl      OSDisableInterrupts
    li      r0,4
    lis     r4,-32694
    mtctr   r0
    addi    r4,r4,-17096
    li      r31,0
.L_80260070:
    lwz     r0,0(r4)
    cmplw   r0,r4
    beq-    .L_802600C0
    bl      OSRestoreInterrupts
    bl      OSDisableInterrupts
    lis     r4,-32694
    slwi    r5,r31,3
    addi    r0,r4,-17096
    add     r5,r0,r5
    lwz     r31,0(r5)
    lwz     r0,0(r31)
    stw     r0,0(r5)
    lwz     r4,0(r31)
    stw     r5,4(r4)
    bl      OSRestoreInterrupts
    li      r0,0
    stw     r0,0(r31)
    mr      r3,r31
    stw     r0,4(r31)
    b       .L_802600D4
.L_802600C0:
    addi    r4,r4,8
    addi    r31,r31,1
    bdnz+   .L_80260070
    bl      OSRestoreInterrupts
    li      r3,0
.L_802600D4:
    lwz     r0,20(r1)
    lwz     r31,12(r1)
    addi    r1,r1,16
    mtlr    r0
    blr
.size __DVDPopWaitingQueue, . - __DVDPopWaitingQueue

.global __DVDCheckWaitingQueue
.balign 4
__DVDCheckWaitingQueue:
/* 0x802600E8 | size=0x58 (88 bytes) */
    mflr    r0
    stw     r0,4(r1)
    stwu    r1,-8(r1)
    bl      OSDisableInterrupts
    li      r0,4
    lis     r4,-32694
    mtctr   r0
    addi    r4,r4,-17096
.L_80260108:
    lwz     r0,0(r4)
    cmplw   r0,r4
    beq-    .L_80260120
    bl      OSRestoreInterrupts
    li      r3,1
    b       .L_80260130
.L_80260120:
    addi    r4,r4,8
    bdnz+   .L_80260108
    bl      OSRestoreInterrupts
    li      r3,0
.L_80260130:
    lwz     r0,12(r1)
    addi    r1,r1,8
    mtlr    r0
    blr
.size __DVDCheckWaitingQueue, . - __DVDCheckWaitingQueue

.global __DVDDequeueWaitingQueue
.balign 4
__DVDDequeueWaitingQueue:
/* 0x80260140 | size=0x60 (96 bytes) */
    mflr    r0
    stw     r0,4(r1)
    stwu    r1,-24(r1)
    stw     r31,20(r1)
    mr      r31,r3
    bl      OSDisableInterrupts
    lwz     r4,4(r31)
    lwz     r5,0(r31)
    cmplwi  r4,0
    beq-    .L_80260170
    cmplwi  r5,0
    bne-    .L_8026017C
.L_80260170:
    bl      OSRestoreInterrupts
    li      r3,0
    b       .L_8026018C
.L_8026017C:
    stw     r5,0(r4)
    stw     r4,4(r5)
    bl      OSRestoreInterrupts
    li      r3,1
.L_8026018C:
    lwz     r0,28(r1)
    lwz     r31,20(r1)
    addi    r1,r1,24
    mtlr    r0
    blr
.size __DVDDequeueWaitingQueue, . - __DVDDequeueWaitingQueue

.global __DVDIsBlockInWaitingQueue
.balign 4
__DVDIsBlockInWaitingQueue:
/* 0x802601A0 | size=0xCC (204 bytes) */
    lis     r4,-32694
    lwzu    r0,-17096(r4)
    cmplw   r0,r4
    beq-    .L_802601D4
    mr      r5,r0
    b       .L_802601CC
.L_802601B8:
    cmplw   r5,r3
    bne-    .L_802601C8
    li      r3,1
    blr
.L_802601C8:
    lwz     r5,0(r5)
.L_802601CC:
    cmplw   r5,r4
    bne+    .L_802601B8
.L_802601D4:
    lwzu    r0,8(r4)
    cmplw   r0,r4
    beq-    .L_80260204
    mr      r5,r0
    b       .L_802601FC
.L_802601E8:
    cmplw   r5,r3
    bne-    .L_802601F8
    li      r3,1
    blr
.L_802601F8:
    lwz     r5,0(r5)
.L_802601FC:
    cmplw   r5,r4
    bne+    .L_802601E8
.L_80260204:
    lwzu    r0,8(r4)
    cmplw   r0,r4
    beq-    .L_80260234
    mr      r5,r0
    b       .L_8026022C
.L_80260218:
    cmplw   r5,r3
    bne-    .L_80260228
    li      r3,1
    blr
.L_80260228:
    lwz     r5,0(r5)
.L_8026022C:
    cmplw   r5,r4
    bne+    .L_80260218
.L_80260234:
    lwzu    r0,8(r4)
    cmplw   r0,r4
    beq-    .L_80260264
    mr      r5,r0
    b       .L_8026025C
.L_80260248:
    cmplw   r5,r3
    bne-    .L_80260258
    li      r3,1
    blr
.L_80260258:
    lwz     r5,0(r5)
.L_8026025C:
    cmplw   r5,r4
    bne+    .L_80260248
.L_80260264:
    li      r3,0
    blr
.size __DVDIsBlockInWaitingQueue, . - __DVDIsBlockInWaitingQueue

#
# === fstload.o ===
#

.global cb
.balign 4
cb:
/* 0x8026094C | size=0xD8 (216 bytes) */
    mflr    r0
    cmpwi   r3,0
    stw     r0,4(r1)
    stwu    r1,-24(r1)
    stw     r31,20(r1)
    addi    r31,r4,0
    ble-    .L_802609E0
    lwz     r0,-23376(r13)
    cmpwi   r0,1
    beq-    .L_802609AC
    bge-    .L_80260A10
    cmpwi   r0,0
    bge-    .L_80260984
    b       .L_80260A10
.L_80260984:
    li      r0,1
    lwz     r4,-23372(r13)
    lis     r3,-32730
    stw     r0,-23376(r13)
    addi    r7,r3,2380
    addi    r3,r31,0
    li      r5,32
    li      r6,1056
    bl      DVDReadAbsAsyncForBS
    b       .L_80260A10
.L_802609AC:
    li      r0,2
    lwz     r6,-23372(r13)
    stw     r0,-23376(r13)
    lis     r3,-32730
    addi    r7,r3,2380
    lwz     r5,8(r6)
    mr      r3,r31
    lwz     r4,16(r6)
    addi    r0,r5,31
    lwz     r6,4(r6)
    clrrwi  r5,r0,5
    bl      DVDReadAbsAsyncForBS
    b       .L_80260A10
.L_802609E0:
    cmpwi   r3,-1
    beq-    .L_80260A10
    cmpwi   r3,-4
    bne-    .L_80260A10
    li      r0,0
    stw     r0,-23376(r13)
    bl      DVDReset
    lis     r3,-32730
    lwz     r4,-23368(r13)
    addi    r5,r3,2380
    addi    r3,r31,0
    bl      DVDReadDiskID
.L_80260A10:
    lwz     r0,28(r1)
    lwz     r31,20(r1)
    addi    r1,r1,24
    mtlr    r0
    blr
.size cb, . - cb

# ============================================================
# vi.a
# ============================================================

#
# === vi.o ===
#

.global cntlzd
.balign 4
cntlzd:
/* 0x80261E6C | size=0x5C (92 bytes) */
    mflr    r0
    li      r5,32
    stw     r0,4(r1)
    stwu    r1,-24(r1)
    stw     r31,20(r1)
    addi    r31,r3,0
    stw     r30,16(r1)
    addi    r30,r4,0
    bl      __shr2u
    cntlzw  r3,r4
    cmpwi   r3,32
    li      r0,-1
    and     r0,r30,r0
    bge-    .L_80261EA8
    b       .L_80261EB0
.L_80261EA8:
    cntlzw  r3,r0
    addi    r3,r3,32
.L_80261EB0:
    lwz     r0,28(r1)
    lwz     r31,20(r1)
    lwz     r30,16(r1)
    addi    r1,r1,24
    mtlr    r0
    blr
.size cntlzd, . - cntlzd

.global VISetPreRetraceCallback
.balign 4
VISetPreRetraceCallback:
/* 0x8026225C | size=0x44 (68 bytes) */
    mflr    r0
    stw     r0,4(r1)
    stwu    r1,-24(r1)
    stw     r31,20(r1)
    stw     r30,16(r1)
    mr      r30,r3
    lwz     r31,-23268(r13)
    bl      OSDisableInterrupts
    stw     r30,-23268(r13)
    bl      OSRestoreInterrupts
    mr      r3,r31
    lwz     r0,28(r1)
    lwz     r31,20(r1)
    lwz     r30,16(r1)
    addi    r1,r1,24
    mtlr    r0
    blr
.size VISetPreRetraceCallback, . - VISetPreRetraceCallback

.global VISetPostRetraceCallback
.balign 4
VISetPostRetraceCallback:
/* 0x802622A0 | size=0x44 (68 bytes) */
    mflr    r0
    stw     r0,4(r1)
    stwu    r1,-24(r1)
    stw     r31,20(r1)
    stw     r30,16(r1)
    mr      r30,r3
    lwz     r31,-23264(r13)
    bl      OSDisableInterrupts
    stw     r30,-23264(r13)
    bl      OSRestoreInterrupts
    mr      r3,r31
    lwz     r0,28(r1)
    lwz     r31,20(r1)
    lwz     r30,16(r1)
    addi    r1,r1,24
    mtlr    r0
    blr
.size VISetPostRetraceCallback, . - VISetPostRetraceCallback

.global getTiming
.balign 4
getTiming:
/* 0x802622F4 | size=0xA8 (168 bytes) */
    cmplwi  r3,30
    lis     r4,-32700
    addi    r5,r4,-12696
    bgt-    .L_80262394
    lis     r4,-32700
    addi    r4,r4,-12196
    slwi    r0,r3,2
    lwzx    r0,r4,r0
    mtctr   r0
    bctr
    addi    r3,r5,68
    blr
    addi    r3,r5,106
    blr
    addi    r3,r5,144
    blr
    addi    r3,r5,182
    blr
    addi    r3,r5,68
    blr
    addi    r3,r5,106
    blr
    addi    r3,r5,220
    blr
    addi    r3,r5,258
    blr
    addi    r3,r5,296
    blr
    addi    r3,r5,334
    blr
    addi    r3,r5,144
    blr
    addi    r3,r5,182
    blr
    addi    r3,r5,372
    blr
    addi    r3,r5,410
    blr
    lwz     r3,-23196(r13)
    blr
.L_80262394:
    li      r3,0
    blr
.size getTiming, . - getTiming

.global VIWaitForRetrace
.balign 4
VIWaitForRetrace:
/* 0x80262BEC | size=0x54 (84 bytes) */
    mflr    r0
    stw     r0,4(r1)
    stwu    r1,-16(r1)
    stw     r31,12(r1)
    stw     r30,8(r1)
    bl      OSDisableInterrupts
    lwz     r30,-23284(r13)
    mr      r31,r3
.L_80262C0C:
    addi    r3,r13,-23276
    bl      OSSleepThread
    lwz     r0,-23284(r13)
    cmplw   r30,r0
    beq+    .L_80262C0C
    mr      r3,r31
    bl      OSRestoreInterrupts
    lwz     r0,20(r1)
    lwz     r31,12(r1)
    lwz     r30,8(r1)
    addi    r1,r1,16
    mtlr    r0
    blr
.size VIWaitForRetrace, . - VIWaitForRetrace

.global setInterruptRegs
.balign 4
setInterruptRegs:
/* 0x80262C40 | size=0x7C (124 bytes) */
    lhz     r5,24(r3)
    srawi   r4,r5,1
    addze   r4,r4
    srawi   r0,r5,1
    addze   r0,r0
    slwi    r0,r0,1
    subfc   r0,r0,r5
    clrlwi. r0,r0,16
    clrlwi  r4,r4,16
    beq-    .L_80262C70
    lhz     r3,26(r3)
    b       .L_80262C74
.L_80262C70:
    li      r3,0
.L_80262C74:
    addi    r0,r3,1
    lis     r3,-32694
    addi    r5,r3,-16744
    sth     r0,50(r5)
    addi    r0,r4,1
    ori     r0,r0,4096
    lwz     r3,-23240(r13)
    lwz     r4,-23236(r13)
    ori     r3,r3,64
    stw     r4,-23236(r13)
    stw     r3,-23240(r13)
    sth     r0,48(r5)
    lwz     r0,-23240(r13)
    lwz     r3,-23236(r13)
    ori     r0,r0,128
    stw     r3,-23236(r13)
    stw     r0,-23240(r13)
    blr
.size setInterruptRegs, . - setInterruptRegs

.global setPicConfig
.balign 4
setPicConfig:
/* 0x80262CBC | size=0x98 (152 bytes) */
    clrlwi  r3,r3,16
    addi    r0,r3,15
    srawi   r0,r0,4
    addze   r0,r0
    cmpwi   r4,0
    stb     r0,0(r7)
    bne-    .L_80262CE0
    lbz     r0,0(r7)
    b       .L_80262CE8
.L_80262CE0:
    lbz     r0,0(r7)
    rlwinm  r0,r0,1,24,30
.L_80262CE8:
    clrlwi  r3,r5,16
    stb     r0,0(r8)
    srawi   r0,r3,4
    addze   r0,r0
    slwi    r0,r0,4
    subfc   r0,r0,r3
    stb     r0,0(r10)
    clrlwi  r4,r6,16
    lis     r3,-32694
    lbz     r5,0(r10)
    addi    r0,r4,15
    addi    r3,r3,-16744
    add     r0,r5,r0
    srawi   r0,r0,4
    addze   r0,r0
    stb     r0,0(r9)
    lis     r0,2048
    lbz     r4,0(r9)
    lbz     r5,0(r8)
    rlwimi  r5,r4,8,16,23
    sth     r5,72(r3)
    lwz     r3,-23240(r13)
    lwz     r4,-23236(r13)
    or      r0,r4,r0
    stw     r0,-23236(r13)
    stw     r3,-23240(r13)
    blr
.size setPicConfig, . - setPicConfig

.global setBBIntervalRegs
.balign 4
setBBIntervalRegs:
/* 0x80262D54 | size=0xBC (188 bytes) */
    lhz     r0,16(r3)
    lis     r4,-32694
    lbz     r5,12(r3)
    addi    r4,r4,-16744
    slwi    r0,r0,5
    or      r0,r5,r0
    sth     r0,22(r4)
    lis     r7,16
    lis     r6,32
    lwz     r8,-23240(r13)
    lis     r5,4
    lis     r0,8
    lwz     r9,-23236(r13)
    or      r7,r8,r7
    stw     r9,-23236(r13)
    stw     r7,-23240(r13)
    lhz     r7,20(r3)
    lbz     r8,14(r3)
    slwi    r7,r7,5
    or      r7,r8,r7
    sth     r7,20(r4)
    lwz     r7,-23240(r13)
    lwz     r8,-23236(r13)
    or      r6,r7,r6
    stw     r8,-23236(r13)
    stw     r6,-23240(r13)
    lhz     r6,18(r3)
    lbz     r7,13(r3)
    slwi    r6,r6,5
    or      r6,r7,r6
    sth     r6,26(r4)
    lwz     r6,-23240(r13)
    lwz     r7,-23236(r13)
    or      r5,r6,r5
    stw     r7,-23236(r13)
    stw     r5,-23240(r13)
    lhz     r5,22(r3)
    lbz     r6,15(r3)
    slwi    r3,r5,5
    or      r3,r6,r3
    sth     r3,24(r4)
    lwz     r3,-23240(r13)
    lwz     r4,-23236(r13)
    or      r0,r3,r0
    stw     r4,-23236(r13)
    stw     r0,-23240(r13)
    blr
.size setBBIntervalRegs, . - setBBIntervalRegs

.global setScalingRegs
.balign 4
setScalingRegs:
/* 0x80262E10 | size=0x9C (156 bytes) */
    cmpwi   r5,0
    lis     r5,-32694
    addi    r5,r5,-16744
    beq-    .L_80262E28
    rlwinm  r0,r3,1,15,30
    b       .L_80262E2C
.L_80262E28:
    clrlwi  r0,r3,16
.L_80262E2C:
    clrlwi  r6,r0,16
    clrlwi  r4,r4,16
    cmplw   r6,r4
    bge-    .L_80262E88
    slwi    r3,r6,8
    addi    r0,r3,-1
    add     r0,r4,r0
    divwu   r0,r0,r4
    ori     r0,r0,4096
    sth     r0,74(r5)
    lis     r0,1024
    lwz     r3,-23240(r13)
    lwz     r4,-23236(r13)
    or      r0,r4,r0
    stw     r0,-23236(r13)
    stw     r3,-23240(r13)
    sth     r6,112(r5)
    lwz     r3,-23240(r13)
    lwz     r0,-23236(r13)
    ori     r0,r0,128
    stw     r0,-23236(r13)
    stw     r3,-23240(r13)
    blr
.L_80262E88:
    li      r0,256
    sth     r0,74(r5)
    lis     r0,1024
    lwz     r3,-23240(r13)
    lwz     r4,-23236(r13)
    or      r0,r4,r0
    stw     r0,-23236(r13)
    stw     r3,-23240(r13)
    blr
.size setScalingRegs, . - setScalingRegs

.global calcFbbs
.balign 4
calcFbbs:
/* 0x80262EAC | size=0x80 (128 bytes) */
    rlwinm  r6,r6,5,19,26
    clrlwi  r0,r5,16
    mullw   r0,r6,r0
    rlwinm  r4,r4,1,15,26
    add     r0,r4,r0
    add     r0,r3,r0
    cmpwi   r7,0
    stw     r0,0(r9)
    bne-    .L_80262ED8
    lwz     r0,0(r9)
    b       .L_80262EE0
.L_80262ED8:
    lwz     r0,0(r9)
    add     r0,r0,r6
.L_80262EE0:
    clrlwi  r3,r8,16
    stw     r0,0(r10)
    srawi   r0,r3,1
    addze   r0,r0
    slwi    r0,r0,1
    subfc   r0,r0,r3
    cmpwi   r0,1
    bne-    .L_80262F10
    lwz     r3,0(r9)
    lwz     r0,0(r10)
    stw     r0,0(r9)
    stw     r3,0(r10)
.L_80262F10:
    lwz     r0,0(r9)
    clrlwi  r0,r0,2
    stw     r0,0(r9)
    lwz     r0,0(r10)
    clrlwi  r0,r0,2
    stw     r0,0(r10)
    blr
.size calcFbbs, . - calcFbbs

.global setHorizontalRegs
.balign 4
setHorizontalRegs:
/* 0x80263200 | size=0xCC (204 bytes) */
    lis     r6,-32694
    lhz     r0,26(r3)
    addi    r6,r6,-16744
    sth     r0,6(r6)
    clrlwi  r0,r5,16
    lis     r5,4096
    lwz     r8,-23240(r13)
    clrlwi  r10,r4,16
    lis     r7,8192
    lwz     r9,-23236(r13)
    or      r4,r8,r5
    subfic  r8,r0,720
    stw     r9,-23236(r13)
    lis     r5,1024
    lis     r0,2048
    stw     r4,-23240(r13)
    lbz     r4,29(r3)
    lbz     r9,30(r3)
    rlwimi  r9,r4,8,16,23
    sth     r9,4(r6)
    lwz     r4,-23240(r13)
    lwz     r9,-23236(r13)
    or      r4,r4,r7
    stw     r9,-23236(r13)
    stw     r4,-23240(r13)
    lbz     r4,31(r3)
    lhz     r7,32(r3)
    add     r9,r4,r10
    lbz     r4,28(r3)
    addi    r9,r9,-40
    rlwinm  r3,r9,7,16,24
    or      r3,r4,r3
    sth     r3,10(r6)
    add     r3,r7,r10
    addi    r3,r3,40
    lwz     r7,-23240(r13)
    subf    r3,r8,r3
    srwi    r4,r9,9
    lwz     r8,-23236(r13)
    slwi    r3,r3,1
    or      r5,r7,r5
    stw     r8,-23236(r13)
    or      r3,r4,r3
    stw     r5,-23240(r13)
    sth     r3,8(r6)
    lwz     r3,-23240(r13)
    lwz     r4,-23236(r13)
    or      r0,r3,r0
    stw     r4,-23236(r13)
    stw     r0,-23240(r13)
    blr
.size setHorizontalRegs, . - setHorizontalRegs

.global PrintDebugPalCaution
.balign 4
PrintDebugPalCaution:
/* 0x8026346C | size=0x94 (148 bytes) */
    mflr    r0
    lis     r3,-32700
    stw     r0,4(r1)
    stwu    r1,-16(r1)
    stw     r31,12(r1)
    addi    r31,r3,-12696
    lwz     r0,-23192(r13)
    cmplwi  r0,0
    bne-    .L_802634EC
    li      r0,1
    crclr   4*cr1+eq
    stw     r0,-23192(r13)
    addi    r3,r31,624
    bl      OSReport
    addi    r3,r31,668
    crclr   4*cr1+eq
    bl      OSReport
    addi    r3,r31,712
    crclr   4*cr1+eq
    bl      OSReport
    addi    r3,r31,756
    crclr   4*cr1+eq
    bl      OSReport
    addi    r3,r31,800
    crclr   4*cr1+eq
    bl      OSReport
    addi    r3,r31,844
    crclr   4*cr1+eq
    bl      OSReport
    addi    r3,r31,624
    crclr   4*cr1+eq
    bl      OSReport
.L_802634EC:
    lwz     r0,20(r1)
    lwz     r31,12(r1)
    addi    r1,r1,16
    mtlr    r0
    blr
.size PrintDebugPalCaution, . - PrintDebugPalCaution

.global VISetNextFrameBuffer
.balign 4
VISetNextFrameBuffer:
/* 0x802641CC | size=0x6C (108 bytes) */
    mflr    r0
    lis     r4,-32694
    stw     r0,4(r1)
    stwu    r1,-24(r1)
    stw     r31,20(r1)
    addi    r31,r4,-16744
    stw     r30,16(r1)
    addi    r30,r3,0
    bl      OSDisableInterrupts
    stw     r30,288(r31)
    li      r0,1
    addi    r30,r3,0
    stw     r0,-23200(r13)
    addi    r3,r31,240
    addi    r4,r31,292
    addi    r5,r31,296
    addi    r6,r31,316
    addi    r7,r31,320
    bl      setFbbRegs
    mr      r3,r30
    bl      OSRestoreInterrupts
    lwz     r0,28(r1)
    lwz     r31,20(r1)
    lwz     r30,16(r1)
    addi    r1,r1,24
    mtlr    r0
    blr
.size VISetNextFrameBuffer, . - VISetNextFrameBuffer

.global VISetNextRightFrameBuffer
.balign 4
VISetNextRightFrameBuffer:
/* 0x80264248 | size=0x6C (108 bytes) */
    mflr    r0
    lis     r4,-32694
    stw     r0,4(r1)
    stwu    r1,-24(r1)
    stw     r31,20(r1)
    addi    r31,r4,-16744
    stw     r30,16(r1)
    addi    r30,r3,0
    bl      OSDisableInterrupts
    stw     r30,312(r31)
    li      r0,1
    addi    r30,r3,0
    stw     r0,-23200(r13)
    addi    r3,r31,240
    addi    r4,r31,292
    addi    r5,r31,296
    addi    r6,r31,316
    addi    r7,r31,320
    bl      setFbbRegs
    mr      r3,r30
    bl      OSRestoreInterrupts
    lwz     r0,28(r1)
    lwz     r31,20(r1)
    lwz     r30,16(r1)
    addi    r1,r1,24
    mtlr    r0
    blr
.size VISetNextRightFrameBuffer, . - VISetNextRightFrameBuffer

.global VISetBlack
.balign 4
VISetBlack:
/* 0x802642B4 | size=0x7C (124 bytes) */
    mflr    r0
    lis     r4,-32694
    stw     r0,4(r1)
    stwu    r1,-32(r1)
    stw     r31,28(r1)
    addi    r31,r4,-16744
    stw     r30,24(r1)
    addi    r30,r3,0
    bl      OSDisableInterrupts
    stw     r30,304(r31)
    mr      r30,r3
    lwz     r10,324(r31)
    lwz     r0,304(r31)
    stw     r0,8(r1)
    lhz     r3,250(r31)
    lhz     r4,246(r31)
    lbz     r5,0(r10)
    lhz     r6,2(r10)
    lhz     r7,4(r10)
    lhz     r8,6(r10)
    lhz     r9,8(r10)
    lhz     r10,10(r10)
    bl      setVerticalRegs
    mr      r3,r30
    bl      OSRestoreInterrupts
    lwz     r0,36(r1)
    lwz     r31,28(r1)
    lwz     r30,24(r1)
    addi    r1,r1,32
    mtlr    r0
    blr
.size VISetBlack, . - VISetBlack

.global VISet3D
.balign 4
VISet3D:
/* 0x80264330 | size=0x100 (256 bytes) */
    mflr    r0
    lis     r4,-32694
    stw     r0,4(r1)
    stwu    r1,-32(r1)
    stw     r31,28(r1)
    addi    r31,r4,-16744
    stw     r30,24(r1)
    addi    r30,r3,0
    bl      OSDisableInterrupts
    stw     r30,308(r31)
    lis     r0,16384
    lwz     r7,308(r31)
    lhz     r5,2(r31)
    slwi    r4,r7,3
    rlwinm  r5,r5,0,29,27
    or      r4,r5,r4
    sth     r4,2(r31)
    cmpwi   r7,0
    lwz     r4,-23240(r13)
    lwz     r5,-23236(r13)
    or      r0,r4,r0
    stw     r5,-23236(r13)
    stw     r0,-23240(r13)
    lhz     r5,244(r31)
    lhz     r0,266(r31)
    beq-    .L_8026439C
    slwi    r0,r0,1
.L_8026439C:
    clrlwi  r6,r0,16
    cmplw   r6,r5
    bge-    .L_802643F4
    slwi    r4,r6,8
    addi    r0,r4,-1
    add     r0,r5,r0
    divwu   r0,r0,r5
    ori     r0,r0,4096
    sth     r0,74(r31)
    lis     r0,1024
    lwz     r4,-23240(r13)
    lwz     r5,-23236(r13)
    or      r0,r5,r0
    stw     r0,-23236(r13)
    stw     r4,-23240(r13)
    sth     r6,112(r31)
    lwz     r4,-23240(r13)
    lwz     r0,-23236(r13)
    ori     r0,r0,128
    stw     r0,-23236(r13)
    stw     r4,-23240(r13)
    b       .L_80264414
.L_802643F4:
    li      r0,256
    sth     r0,74(r31)
    lis     r0,1024
    lwz     r4,-23240(r13)
    lwz     r5,-23236(r13)
    or      r0,r5,r0
    stw     r0,-23236(r13)
    stw     r4,-23240(r13)
.L_80264414:
    bl      OSRestoreInterrupts
    lwz     r0,36(r1)
    lwz     r31,28(r1)
    lwz     r30,24(r1)
    addi    r1,r1,32
    mtlr    r0
    blr
.size VISet3D, . - VISet3D

.global getCurrentHalfLine
.balign 4
getCurrentHalfLine:
/* 0x80264474 | size=0x50 (80 bytes) */
    lis     r3,-13312
    addi    r7,r3,8192
    lhzu    r0,44(r7)
    addi    r4,r3,8192
    clrlwi  r5,r0,21
.L_80264488:
    lhz     r0,0(r7)
    mr      r6,r5
    lhz     r3,46(r4)
    clrlwi  r5,r0,21
    cmplw   r6,r5
    clrlwi  r6,r3,21
    bne+    .L_80264488
    lwz     r3,-23216(r13)
    addi    r5,r5,-1
    addi    r4,r6,-1
    lhz     r0,26(r3)
    slwi    r3,r5,1
    divwu   r0,r4,r0
    add     r3,r3,r0
    blr
.size getCurrentHalfLine, . - getCurrentHalfLine

.global getCurrentFieldEvenOdd
.balign 4
getCurrentFieldEvenOdd:
/* 0x802644C4 | size=0x68 (104 bytes) */
    lis     r3,-13312
    addi    r7,r3,8192
    lhzu    r0,44(r7)
    addi    r4,r3,8192
    clrlwi  r5,r0,21
.L_802644D8:
    lhz     r0,0(r7)
    mr      r6,r5
    lhz     r3,46(r4)
    clrlwi  r5,r0,21
    cmplw   r6,r5
    clrlwi  r3,r3,21
    bne+    .L_802644D8
    lwz     r6,-23216(r13)
    addi    r0,r5,-1
    addi    r4,r3,-1
    lhz     r3,26(r6)
    slwi    r5,r0,1
    lhz     r0,24(r6)
    divwu   r3,r4,r3
    add     r3,r5,r3
    cmplw   r3,r0
    bge-    .L_80264524
    li      r3,1
    blr
.L_80264524:
    li      r3,0
    blr
.size getCurrentFieldEvenOdd, . - getCurrentFieldEvenOdd

.global VIGetNextField
.balign 4
VIGetNextField:
/* 0x8026452C | size=0x9C (156 bytes) */
    mflr    r0
    stw     r0,4(r1)
    stwu    r1,-40(r1)
    stw     r31,36(r1)
    stw     r30,32(r1)
    bl      OSDisableInterrupts
    addi    r30,r3,0
    addi    r3,r1,16
    addi    r4,r1,20
    bl      GetCurrentDisplayPosition
    lwz     r5,-23216(r13)
    lwz     r3,16(r1)
    lhz     r0,26(r5)
    addi    r3,r3,-1
    lwz     r4,20(r1)
    divwu   r3,r3,r0
    lhz     r0,24(r5)
    addi    r4,r4,-1
    slwi    r4,r4,1
    add     r3,r4,r3
    cmplw   r3,r0
    bge-    .L_8026458C
    li      r31,1
    b       .L_80264590
.L_8026458C:
    li      r31,0
.L_80264590:
    mr      r3,r30
    bl      OSRestoreInterrupts
    lis     r3,-32694
    addi    r3,r3,-16504
    lhz     r0,10(r3)
    xori    r3,r31,1
    clrlwi  r0,r0,31
    xor     r3,r3,r0
    lwz     r0,44(r1)
    lwz     r31,36(r1)
    lwz     r30,32(r1)
    addi    r1,r1,40
    mtlr    r0
    blr
.size VIGetNextField, . - VIGetNextField

.global VIGetCurrentLine
.balign 4
VIGetCurrentLine:
/* 0x802645C8 | size=0x98 (152 bytes) */
    mflr    r0
    stw     r0,4(r1)
    stwu    r1,-32(r1)
    stw     r31,28(r1)
    stw     r30,24(r1)
    lwz     r31,-23216(r13)
    bl      OSDisableInterrupts
    lis     r4,-13312
    addi    r8,r4,8192
    lhzu    r0,44(r8)
    addi    r5,r4,8192
    clrlwi  r6,r0,21
.L_802645F8:
    lhz     r0,0(r8)
    mr      r7,r6
    lhz     r4,46(r5)
    clrlwi  r6,r0,21
    cmplw   r7,r6
    clrlwi  r7,r4,21
    bne+    .L_802645F8
    lwz     r4,-23216(r13)
    addi    r5,r7,-1
    addi    r6,r6,-1
    lhz     r0,26(r4)
    slwi    r4,r6,1
    divwu   r0,r5,r0
    add     r30,r4,r0
    bl      OSRestoreInterrupts
    lhz     r0,24(r31)
    cmplw   r30,r0
    blt-    .L_80264644
    subf    r30,r0,r30
.L_80264644:
    srwi    r3,r30,1
    lwz     r0,36(r1)
    lwz     r31,28(r1)
    lwz     r30,24(r1)
    addi    r1,r1,32
    mtlr    r0
    blr
.size VIGetCurrentLine, . - VIGetCurrentLine

.global VIGetTvFormat
.balign 4
VIGetTvFormat:
/* 0x80264660 | size=0x68 (104 bytes) */
    mflr    r0
    stw     r0,4(r1)
    stwu    r1,-16(r1)
    stw     r31,12(r1)
    bl      OSDisableInterrupts
    lwz     r5,-23212(r13)
    cmplwi  r5,7
    bgt-    .L_802646AC
    lis     r4,-32700
    addi    r4,r4,-11732
    slwi    r0,r5,2
    lwzx    r0,r4,r0
    mtctr   r0
    bctr
    li      r31,0
    b       .L_802646AC
    li      r31,1
    b       .L_802646AC
    mr      r31,r5
.L_802646AC:
    bl      OSRestoreInterrupts
    mr      r3,r31
    lwz     r0,20(r1)
    lwz     r31,12(r1)
    addi    r1,r1,16
    mtlr    r0
    blr
.size VIGetTvFormat, . - VIGetTvFormat

.global VIGetScanMode
.balign 4
VIGetScanMode:
/* 0x802646C8 | size=0x68 (104 bytes) */
    mflr    r0
    stw     r0,4(r1)
    stwu    r1,-16(r1)
    stw     r31,12(r1)
    bl      OSDisableInterrupts
    lis     r4,-13312
    addi    r4,r4,8192
    lhz     r0,108(r4)
    clrlwi  r0,r0,31
    cmplwi  r0,1
    bne-    .L_802646FC
    li      r31,2
    b       .L_80264714
.L_802646FC:
    lhz     r0,2(r4)
    rlwinm. r0,r0,30,31,31
    bne-    .L_80264710
    li      r31,0
    b       .L_80264714
.L_80264710:
    li      r31,1
.L_80264714:
    bl      OSRestoreInterrupts
    mr      r3,r31
    lwz     r0,20(r1)
    lwz     r31,12(r1)
    addi    r1,r1,16
    mtlr    r0
    blr
.size VIGetScanMode, . - VIGetScanMode

.global __VIGetAdjustingValues
.balign 4
__VIGetAdjustingValues:
/* 0x80264A34 | size=0x4C (76 bytes) */
    mflr    r0
    stw     r0,4(r1)
    stwu    r1,-24(r1)
    stw     r31,20(r1)
    addi    r31,r4,0
    stw     r30,16(r1)
    addi    r30,r3,0
    bl      OSDisableInterrupts
    lha     r0,-23252(r13)
    sth     r0,0(r30)
    lha     r0,-23250(r13)
    sth     r0,0(r31)
    bl      OSRestoreInterrupts
    lwz     r0,28(r1)
    lwz     r31,20(r1)
    lwz     r30,16(r1)
    addi    r1,r1,24
    mtlr    r0
    blr
.size __VIGetAdjustingValues, . - __VIGetAdjustingValues

.global __VIDisableRawPositionInterrupt
.balign 4
__VIDisableRawPositionInterrupt:
/* 0x80264C00 | size=0x4C (76 bytes) */
    mflr    r0
    stw     r0,4(r1)
    stwu    r1,-16(r1)
    stw     r31,12(r1)
    bl      OSDisableInterrupts
    lis     r4,-13312
    addi    r4,r4,8192
    li      r0,0
    sth     r0,56(r4)
    sth     r0,60(r4)
    lwz     r31,-23260(r13)
    stw     r0,-23260(r13)
    bl      OSRestoreInterrupts
    mr      r3,r31
    lwz     r0,20(r1)
    lwz     r31,12(r1)
    addi    r1,r1,16
    mtlr    r0
    blr
.size __VIDisableRawPositionInterrupt, . - __VIDisableRawPositionInterrupt

.global __VIGetCurrentPosition
.balign 4
__VIGetCurrentPosition:
/* 0x80264E68 | size=0x60 (96 bytes) */
    mflr    r0
    lis     r7,-13312
    stw     r0,4(r1)
    addi    r6,r4,0
    addi    r9,r7,8192
    stwu    r1,-8(r1)
    addi    r5,r3,0
    addi    r4,r7,8192
    lhzu    r0,44(r9)
    clrlwi  r8,r0,21
.L_80264E90:
    lhz     r0,0(r9)
    mr      r7,r8
    lhz     r3,46(r4)
    clrlwi  r8,r0,21
    cmplw   r7,r8
    clrlwi  r0,r3,21
    bne+    .L_80264E90
    mr      r3,r0
    addi    r4,r8,0
    bl      __VIDisplayPositionToXY
    lwz     r0,12(r1)
    addi    r1,r1,8
    mtlr    r0
    blr
.size __VIGetCurrentPosition, . - __VIGetCurrentPosition

.global __VIGetLatch0Position
.balign 4
__VIGetLatch0Position:
/* 0x80264EF4 | size=0x74 (116 bytes) */
    mflr    r0
    lis     r7,-13312
    stw     r0,4(r1)
    addi    r8,r7,8192
    addi    r5,r3,0
    stwu    r1,-8(r1)
    addi    r6,r4,0
    lhzu    r0,64(r8)
    rlwinm. r0,r0,17,31,31
    beq-    .L_80264F48
    addi    r7,r7,8192
    lhz     r4,0(r8)
    lhz     r3,66(r7)
    li      r0,0
    clrlwi  r4,r4,21
    sth     r0,0(r8)
    clrlwi  r3,r3,21
    sth     r0,66(r7)
    bl      __VIDisplayPositionToXY
    li      r3,1
    b       .L_80264F58
.L_80264F48:
    li      r0,-1
    sth     r0,0(r6)
    li      r3,0
    sth     r0,0(r5)
.L_80264F58:
    lwz     r0,12(r1)
    addi    r1,r1,8
    mtlr    r0
    blr
.size __VIGetLatch0Position, . - __VIGetLatch0Position

.global __VIGetLatch1Position
.balign 4
__VIGetLatch1Position:
/* 0x80264F68 | size=0x74 (116 bytes) */
    mflr    r0
    lis     r7,-13312
    stw     r0,4(r1)
    addi    r8,r7,8192
    addi    r5,r3,0
    stwu    r1,-8(r1)
    addi    r6,r4,0
    lhzu    r0,68(r8)
    rlwinm. r0,r0,17,31,31
    beq-    .L_80264FBC
    addi    r7,r7,8192
    lhz     r4,0(r8)
    lhz     r3,70(r7)
    li      r0,0
    clrlwi  r4,r4,21
    sth     r0,0(r8)
    clrlwi  r3,r3,21
    sth     r0,70(r7)
    bl      __VIDisplayPositionToXY
    li      r3,1
    b       .L_80264FCC
.L_80264FBC:
    li      r0,-1
    sth     r0,0(r6)
    li      r3,0
    sth     r0,0(r5)
.L_80264FCC:
    lwz     r0,12(r1)
    addi    r1,r1,8
    mtlr    r0
    blr
.size __VIGetLatch1Position, . - __VIGetLatch1Position

# ============================================================
# pad.a
# ============================================================

#
# === Pad.o ===
#

.global PADEnable
.balign 4
PADEnable:
/* 0x8026501C | size=0x60 (96 bytes) */
    mflr    r0
    stw     r0,4(r1)
    lis     r0,-32768
    stwu    r1,-32(r1)
    stw     r31,28(r1)
    mr      r31,r3
    srw     r0,r0,r31
    lwz     r3,-23180(r13)
    addi    r4,r1,12
    or      r0,r3,r0
    stw     r0,-23180(r13)
    addi    r3,r31,0
    bl      SIGetResponse
    lwz     r0,-27644(r13)
    addi    r3,r31,0
    oris    r4,r0,64
    bl      SISetCommand
    lwz     r3,-23180(r13)
    bl      SIEnablePolling
    lwz     r0,36(r1)
    lwz     r31,28(r1)
    addi    r1,r1,32
    mtlr    r0
    blr
.size PADEnable, . - PADEnable

.global PADDisable
.balign 4
PADDisable:
/* 0x8026507C | size=0xA4 (164 bytes) */
    mflr    r0
    stw     r0,4(r1)
    stwu    r1,-32(r1)
    stw     r31,28(r1)
    stw     r30,24(r1)
    stw     r29,20(r1)
    mr      r29,r3
    bl      OSDisableInterrupts
    lis     r0,-32768
    srw     r30,r0,r29
    addi    r31,r3,0
    addi    r3,r30,0
    bl      SIDisablePolling
    lwz     r0,-23180(r13)
    not     r9,r30
    lwz     r6,-23168(r13)
    mr      r3,r29
    lwz     r5,-23164(r13)
    lwz     r4,-23160(r13)
    and     r8,r0,r9
    lwz     r0,-23156(r13)
    and     r7,r6,r9
    and     r6,r5,r9
    and     r5,r4,r9
    stw     r8,-23180(r13)
    and     r0,r0,r9
    stw     r7,-23168(r13)
    li      r4,0
    stw     r6,-23164(r13)
    stw     r5,-23160(r13)
    stw     r0,-23156(r13)
    bl      OSSetWirelessID
    mr      r3,r31
    bl      OSRestoreInterrupts
    lwz     r0,36(r1)
    lwz     r31,28(r1)
    lwz     r30,24(r1)
    lwz     r29,20(r1)
    addi    r1,r1,32
    mtlr    r0
    blr
.size PADDisable, . - PADDisable

.global DoReset
.balign 4
DoReset:
/* 0x80265120 | size=0x70 (112 bytes) */
    mflr    r0
    stw     r0,4(r1)
    stwu    r1,-8(r1)
    lwz     r5,-23176(r13)
    cntlzw  r0,r5
    stw     r0,-27652(r13)
    lwz     r4,-27652(r13)
    cmpwi   r4,32
    beq-    .L_80265180
    lis     r0,-32768
    srw     r0,r0,r4
    andc    r0,r5,r0
    mulli   r4,r4,12
    stw     r0,-23176(r13)
    lis     r3,-32694
    addi    r0,r3,-16400
    add     r3,r0,r4
    li      r4,0
    li      r5,12
    bl      memset
    lis     r4,-32730
    lwz     r3,-27652(r13)
    addi    r4,r4,21916
    bl      SIGetTypeAsync
.L_80265180:
    lwz     r0,12(r1)
    addi    r1,r1,8
    mtlr    r0
    blr
.size DoReset, . - DoReset

.global PADOriginCallback
.balign 4
PADOriginCallback:
/* 0x80265334 | size=0xC4 (196 bytes) */
    mflr    r0
    stw     r0,4(r1)
    clrlwi. r0,r4,28
    stwu    r1,-48(r1)
    stw     r31,44(r1)
    bne-    .L_80265390
    lwz     r3,-27652(r13)
    bl      UpdateOrigin
    lwz     r31,-27652(r13)
    lis     r0,-32768
    lwz     r3,-23180(r13)
    addi    r4,r1,28
    srw     r0,r0,r31
    or      r0,r3,r0
    stw     r0,-23180(r13)
    mr      r3,r31
    bl      SIGetResponse
    lwz     r0,-27644(r13)
    addi    r3,r31,0
    oris    r4,r0,64
    bl      SISetCommand
    lwz     r3,-23180(r13)
    bl      SIEnablePolling
.L_80265390:
    lwz     r5,-23176(r13)
    cntlzw  r0,r5
    stw     r0,-27652(r13)
    lwz     r4,-27652(r13)
    cmpwi   r4,32
    beq-    .L_802653E4
    lis     r0,-32768
    srw     r0,r0,r4
    andc    r0,r5,r0
    mulli   r4,r4,12
    stw     r0,-23176(r13)
    lis     r3,-32694
    addi    r0,r3,-16400
    add     r3,r0,r4
    li      r4,0
    li      r5,12
    bl      memset
    lis     r4,-32730
    lwz     r3,-27652(r13)
    addi    r4,r4,21916
    bl      SIGetTypeAsync
.L_802653E4:
    lwz     r0,52(r1)
    lwz     r31,44(r1)
    addi    r1,r1,48
    mtlr    r0
    blr
.size PADOriginCallback, . - PADOriginCallback

.global PADOriginUpdateCallback
.balign 4
PADOriginUpdateCallback:
/* 0x802653F8 | size=0xCC (204 bytes) */
    mflr    r0
    stw     r0,4(r1)
    lis     r0,-32768
    stwu    r1,-40(r1)
    stw     r31,36(r1)
    addi    r31,r4,0
    stw     r30,32(r1)
    stw     r29,28(r1)
    mr      r29,r3
    srw     r30,r0,r29
    lwz     r3,-23180(r13)
    and.    r0,r3,r30
    beq-    .L_802654A8
    clrlwi. r0,r31,28
    bne-    .L_8026543C
    mr      r3,r29
    bl      UpdateOrigin
.L_8026543C:
    rlwinm. r0,r31,0,28,28
    beq-    .L_802654A8
    bl      OSDisableInterrupts
    addi    r31,r3,0
    addi    r3,r30,0
    bl      SIDisablePolling
    lwz     r0,-23180(r13)
    not     r9,r30
    lwz     r6,-23168(r13)
    mr      r3,r29
    lwz     r5,-23164(r13)
    lwz     r4,-23160(r13)
    and     r8,r0,r9
    lwz     r0,-23156(r13)
    and     r7,r6,r9
    and     r6,r5,r9
    and     r5,r4,r9
    stw     r8,-23180(r13)
    and     r0,r0,r9
    stw     r7,-23168(r13)
    li      r4,0
    stw     r6,-23164(r13)
    stw     r5,-23160(r13)
    stw     r0,-23156(r13)
    bl      OSSetWirelessID
    mr      r3,r31
    bl      OSRestoreInterrupts
.L_802654A8:
    lwz     r0,44(r1)
    lwz     r31,36(r1)
    lwz     r30,32(r1)
    lwz     r29,28(r1)
    addi    r1,r1,40
    mtlr    r0
    blr
.size PADOriginUpdateCallback, . - PADOriginUpdateCallback

.global PADProbeCallback
.balign 4
PADProbeCallback:
/* 0x802654C4 | size=0xD8 (216 bytes) */
    mflr    r0
    stw     r0,4(r1)
    clrlwi. r0,r4,28
    stwu    r1,-48(r1)
    stw     r31,44(r1)
    stw     r30,40(r1)
    bne-    .L_80265530
    lwz     r30,-27652(r13)
    lis     r31,-32768
    lwz     r3,-23180(r13)
    addi    r4,r1,28
    srw     r0,r31,r30
    or      r0,r3,r0
    stw     r0,-23180(r13)
    mr      r3,r30
    bl      SIGetResponse
    lwz     r0,-27644(r13)
    addi    r3,r30,0
    oris    r4,r0,64
    bl      SISetCommand
    lwz     r3,-23180(r13)
    bl      SIEnablePolling
    lwz     r0,-27652(r13)
    lwz     r3,-23168(r13)
    srw     r0,r31,r0
    or      r0,r3,r0
    stw     r0,-23168(r13)
.L_80265530:
    lwz     r5,-23176(r13)
    cntlzw  r0,r5
    stw     r0,-27652(r13)
    lwz     r4,-27652(r13)
    cmpwi   r4,32
    beq-    .L_80265584
    lis     r0,-32768
    srw     r0,r0,r4
    andc    r0,r5,r0
    mulli   r4,r4,12
    stw     r0,-23176(r13)
    lis     r3,-32694
    addi    r0,r3,-16400
    add     r3,r0,r4
    li      r4,0
    li      r5,12
    bl      memset
    lis     r4,-32730
    lwz     r3,-27652(r13)
    addi    r4,r4,21916
    bl      SIGetTypeAsync
.L_80265584:
    lwz     r0,52(r1)
    lwz     r31,44(r1)
    lwz     r30,40(r1)
    addi    r1,r1,48
    mtlr    r0
    blr
.size PADProbeCallback, . - PADProbeCallback

.global PADControlAllMotors
.balign 4
PADControlAllMotors:
/* 0x8026609C | size=0xCC (204 bytes) */
    mflr    r0
    stw     r0,4(r1)
    stwu    r1,-40(r1)
    stmw    r26,16(r1)
    mr      r26,r3
    bl      OSDisableInterrupts
    lis     r30,-32768
    lbz     r0,12515(r30)
    addi    r29,r3,0
    li      r27,0
    rlwinm  r31,r0,0,26,26
    li      r28,0
.L_802660CC:
    lwz     r3,-23180(r13)
    srw     r0,r30,r28
    and.    r0,r3,r0
    beq-    .L_80266130
    mr      r3,r28
    bl      SIGetType
    rlwinm. r0,r3,0,2,2
    bne-    .L_80266130
    lwz     r0,-27640(r13)
    lwz     r3,0(r26)
    cmplwi  r0,2
    bge-    .L_80266108
    cmplwi  r3,2
    bne-    .L_80266108
    li      r3,0
.L_80266108:
    cmpwi   r31,0
    beq-    .L_80266114
    li      r3,0
.L_80266114:
    lwz     r4,-27644(r13)
    clrlwi  r0,r3,30
    addi    r3,r28,0
    oris    r4,r4,64
    or      r4,r4,r0
    bl      SISetCommand
    li      r27,1
.L_80266130:
    addi    r28,r28,1
    cmpwi   r28,4
    addi    r26,r26,4
    blt+    .L_802660CC
    cmpwi   r27,0
    beq-    .L_8026614C
    bl      SITransferCommands
.L_8026614C:
    mr      r3,r29
    bl      OSRestoreInterrupts
    lmw     r26,16(r1)
    lwz     r0,44(r1)
    addi    r1,r1,40
    mtlr    r0
    blr
.size PADControlAllMotors, . - PADControlAllMotors

.global PADControlMotor
.balign 4
PADControlMotor:
/* 0x80266168 | size=0xB8 (184 bytes) */
    mflr    r0
    stw     r0,4(r1)
    stwu    r1,-40(r1)
    stw     r31,36(r1)
    stw     r30,32(r1)
    addi    r30,r4,0
    stw     r29,28(r1)
    addi    r29,r3,0
    bl      OSDisableInterrupts
    lis     r0,-32768
    lwz     r4,-23180(r13)
    srw     r0,r0,r29
    and.    r0,r4,r0
    addi    r31,r3,0
    beq-    .L_802661FC
    mr      r3,r29
    bl      SIGetType
    rlwinm. r0,r3,0,2,2
    bne-    .L_802661FC
    lwz     r0,-27640(r13)
    cmplwi  r0,2
    bge-    .L_802661CC
    cmplwi  r30,2
    bne-    .L_802661CC
    li      r30,0
.L_802661CC:
    lis     r3,-32768
    lbz     r0,12515(r3)
    rlwinm. r0,r0,0,26,26
    beq-    .L_802661E0
    li      r30,0
.L_802661E0:
    lwz     r4,-27644(r13)
    clrlwi  r0,r30,30
    addi    r3,r29,0
    oris    r4,r4,64
    or      r4,r4,r0
    bl      SISetCommand
    bl      SITransferCommands
.L_802661FC:
    mr      r3,r31
    bl      OSRestoreInterrupts
    lwz     r0,44(r1)
    lwz     r31,36(r1)
    lwz     r30,32(r1)
    lwz     r29,28(r1)
    addi    r1,r1,40
    mtlr    r0
    blr
.size PADControlMotor, . - PADControlMotor

.global PADSetSpec
.balign 4
PADSetSpec:
/* 0x80266220 | size=0x60 (96 bytes) */
    li      r0,0
    cmpwi   r3,1
    stw     r0,-23140(r13)
    beq-    .L_8026625C
    bge-    .L_80266240
    cmpwi   r3,0
    bge-    .L_8026624C
    b       .L_80266278
.L_80266240:
    cmpwi   r3,6
    bge-    .L_80266278
    b       .L_8026626C
.L_8026624C:
    lis     r4,-32730
    addi    r0,r4,25224
    stw     r0,-27636(r13)
    b       .L_80266278
.L_8026625C:
    lis     r4,-32730
    addi    r0,r4,25596
    stw     r0,-27636(r13)
    b       .L_80266278
.L_8026626C:
    lis     r4,-32730
    addi    r0,r4,26080
    stw     r0,-27636(r13)
.L_80266278:
    stw     r3,-27640(r13)
    blr
.size PADSetSpec, . - PADSetSpec

.global ClampS8
.balign 4
ClampS8:
/* 0x80266570 | size=0x54 (84 bytes) */
    extsb.  r0,r4
    ble-    .L_80266598
    extsb   r5,r4
    addi    r0,r5,-128
    extsb   r5,r0
    extsb   r0,r3
    cmpw    r0,r5
    bge-    .L_802665BC
    mr      r3,r5
    b       .L_802665BC
.L_80266598:
    extsb.  r0,r4
    bge-    .L_802665BC
    extsb   r5,r4
    addi    r0,r5,127
    extsb   r5,r0
    extsb   r0,r3
    cmpw    r5,r0
    bge-    .L_802665BC
    mr      r3,r5
.L_802665BC:
    subf    r3,r4,r3
    blr
.size ClampS8, . - ClampS8

.global PADGetType
.balign 4
PADGetType:
/* 0x80266A50 | size=0x74 (116 bytes) */
    mflr    r0
    stw     r0,4(r1)
    stwu    r1,-24(r1)
    stw     r31,20(r1)
    addi    r31,r4,0
    stw     r30,16(r1)
    addi    r30,r3,0
    bl      SIGetType
    stw     r3,0(r31)
    lis     r0,-32768
    srw     r3,r0,r30
    lwz     r0,-23176(r13)
    and.    r0,r0,r3
    bne-    .L_80266AA0
    lwz     r0,-27652(r13)
    cmpw    r0,r30
    beq-    .L_80266AA0
    lwz     r0,-23180(r13)
    and.    r0,r0,r3
    bne-    .L_80266AA8
.L_80266AA0:
    li      r3,0
    b       .L_80266AAC
.L_80266AA8:
    li      r3,1
.L_80266AAC:
    lwz     r0,28(r1)
    lwz     r31,20(r1)
    lwz     r30,16(r1)
    addi    r1,r1,24
    mtlr    r0
    blr
.size PADGetType, . - PADGetType

.global PADSync
.balign 4
PADSync:
/* 0x80266AC4 | size=0x64 (100 bytes) */
    mflr    r0
    stw     r0,4(r1)
    stwu    r1,-16(r1)
    stw     r31,12(r1)
    li      r31,0
    addi    r3,r31,0
    lwz     r0,-23176(r13)
    cmplwi  r0,0
    bne-    .L_80266AF8
    lwz     r0,-27652(r13)
    cmpwi   r0,32
    bne-    .L_80266AF8
    li      r3,1
.L_80266AF8:
    cmpwi   r3,0
    beq-    .L_80266B10
    bl      SIBusy
    cmpwi   r3,0
    bne-    .L_80266B10
    li      r31,1
.L_80266B10:
    mr      r3,r31
    lwz     r0,20(r1)
    lwz     r31,12(r1)
    addi    r1,r1,16
    mtlr    r0
    blr
.size PADSync, . - PADSync

.global PADSetAnalogMode
.balign 4
PADSetAnalogMode:
/* 0x80266B28 | size=0x74 (116 bytes) */
    mflr    r0
    stw     r0,4(r1)
    stwu    r1,-24(r1)
    stw     r31,20(r1)
    mr      r31,r3
    bl      OSDisableInterrupts
    lwz     r5,-23180(r13)
    slwi    r6,r31,8
    lwz     r4,-23168(r13)
    mr      r31,r3
    addi    r8,r5,0
    not     r7,r8
    lwz     r0,-23164(r13)
    andc    r5,r5,r5
    stw     r6,-27644(r13)
    and     r4,r4,r7
    and     r0,r0,r7
    stw     r5,-23180(r13)
    mr      r3,r8
    stw     r4,-23168(r13)
    stw     r0,-23164(r13)
    bl      SIDisablePolling
    mr      r3,r31
    bl      OSRestoreInterrupts
    lwz     r0,28(r1)
    lwz     r31,20(r1)
    addi    r1,r1,24
    mtlr    r0
    blr
.size PADSetAnalogMode, . - PADSetAnalogMode

.global OnReset
.balign 4
OnReset:
/* 0x80266B9C | size=0xBC (188 bytes) */
    mflr    r0
    stw     r0,4(r1)
    stwu    r1,-32(r1)
    stw     r31,28(r1)
    addi    r31,r3,0
    lwz     r0,-23148(r13)
    cmplwi  r0,0
    beq-    .L_80266BC4
    li      r3,0
    bl      PADSetSamplingCallback
.L_80266BC4:
    cmpwi   r31,0
    bne-    .L_80266C38
    lwz     r0,-23176(r13)
    li      r31,0
    addi    r3,r31,0
    cmplwi  r0,0
    bne-    .L_80266BF0
    lwz     r0,-27652(r13)
    cmpwi   r0,32
    bne-    .L_80266BF0
    li      r3,1
.L_80266BF0:
    cmpwi   r3,0
    beq-    .L_80266C08
    bl      SIBusy
    cmpwi   r3,0
    bne-    .L_80266C08
    li      r31,1
.L_80266C08:
    lwz     r0,-23144(r13)
    cmpwi   r0,0
    bne-    .L_80266C30
    cmpwi   r31,0
    beq-    .L_80266C30
    lis     r3,-4096
    bl      PADRecalibrate
    stw     r3,-23144(r13)
    li      r3,0
    b       .L_80266C44
.L_80266C30:
    mr      r3,r31
    b       .L_80266C44
.L_80266C38:
    li      r0,0
    stw     r0,-23144(r13)
    li      r3,1
.L_80266C44:
    lwz     r0,36(r1)
    lwz     r31,28(r1)
    addi    r1,r1,32
    mtlr    r0
    blr
.size OnReset, . - OnReset

.global SamplingHandler
.balign 4
SamplingHandler:
/* 0x80266C64 | size=0x60 (96 bytes) */
    mflr    r0
    stw     r0,4(r1)
    stwu    r1,-736(r1)
    stw     r31,732(r1)
    addi    r31,r4,0
    lwz     r0,-23148(r13)
    cmplwi  r0,0
    beq-    .L_80266CB0
    addi    r3,r1,16
    bl      OSClearContext
    addi    r3,r1,16
    bl      OSSetCurrentContext
    lwz     r12,-23148(r13)
    mtlr    r12
    blrl
    addi    r3,r1,16
    bl      OSClearContext
    mr      r3,r31
    bl      OSSetCurrentContext
.L_80266CB0:
    lwz     r0,740(r1)
    lwz     r31,732(r1)
    addi    r1,r1,736
    mtlr    r0
    blr
.size SamplingHandler, . - SamplingHandler

.global PADSetSamplingCallback
.balign 4
PADSetSamplingCallback:
/* 0x80266CC4 | size=0x54 (84 bytes) */
    mflr    r0
    cmplwi  r3,0
    stw     r0,4(r1)
    stwu    r1,-24(r1)
    stw     r31,20(r1)
    lwz     r31,-23148(r13)
    stw     r3,-23148(r13)
    beq-    .L_80266CF4
    lis     r3,-32730
    addi    r3,r3,27748
    bl      SIRegisterPollingHandler
    b       .L_80266D00
.L_80266CF4:
    lis     r3,-32730
    addi    r3,r3,27748
    bl      SIUnregisterPollingHandler
.L_80266D00:
    mr      r3,r31
    lwz     r0,28(r1)
    lwz     r31,20(r1)
    addi    r1,r1,24
    mtlr    r0
    blr
.size PADSetSamplingCallback, . - PADSetSamplingCallback

.global __PADDisableRecalibration
.balign 4
__PADDisableRecalibration:
/* 0x80266D18 | size=0x7C (124 bytes) */
    mflr    r0
    stw     r0,4(r1)
    stwu    r1,-24(r1)
    stw     r31,20(r1)
    stw     r30,16(r1)
    mr      r30,r3
    bl      OSDisableInterrupts
    lis     r4,-32768
    lbz     r0,12515(r4)
    rlwinm. r0,r0,0,25,25
    beq-    .L_80266D4C
    li      r31,1
    b       .L_80266D50
.L_80266D4C:
    li      r31,0
.L_80266D50:
    lis     r4,-32768
    lbz     r0,12515(r4)
    cmpwi   r30,0
    rlwinm  r0,r0,0,26,24
    stb     r0,12515(r4)
    beq-    .L_80266D74
    lbz     r0,12515(r4)
    ori     r0,r0,64
    stb     r0,12515(r4)
.L_80266D74:
    bl      OSRestoreInterrupts
    mr      r3,r31
    lwz     r0,28(r1)
    lwz     r31,20(r1)
    lwz     r30,16(r1)
    addi    r1,r1,24
    mtlr    r0
    blr
.size __PADDisableRecalibration, . - __PADDisableRecalibration

.global __PADDisableRumble
.balign 4
__PADDisableRumble:
/* 0x80266D94 | size=0x7C (124 bytes) */
    mflr    r0
    stw     r0,4(r1)
    stwu    r1,-24(r1)
    stw     r31,20(r1)
    stw     r30,16(r1)
    mr      r30,r3
    bl      OSDisableInterrupts
    lis     r4,-32768
    lbz     r0,12515(r4)
    rlwinm. r0,r0,0,26,26
    beq-    .L_80266DC8
    li      r31,1
    b       .L_80266DCC
.L_80266DC8:
    li      r31,0
.L_80266DCC:
    lis     r4,-32768
    lbz     r0,12515(r4)
    cmpwi   r30,0
    rlwinm  r0,r0,0,27,25
    stb     r0,12515(r4)
    beq-    .L_80266DF0
    lbz     r0,12515(r4)
    ori     r0,r0,32
    stb     r0,12515(r4)
.L_80266DF0:
    bl      OSRestoreInterrupts
    mr      r3,r31
    lwz     r0,28(r1)
    lwz     r31,20(r1)
    lwz     r30,16(r1)
    addi    r1,r1,24
    mtlr    r0
    blr
.size __PADDisableRumble, . - __PADDisableRumble

# ============================================================
# ai.a
# ============================================================

#
# === ai.o ===
#

.global AIRegisterDMACallback
.balign 4
AIRegisterDMACallback:
/* 0x80266E4C | size=0x44 (68 bytes) */
    mflr    r0
    stw     r0,4(r1)
    stwu    r1,-24(r1)
    stw     r31,20(r1)
    stw     r30,16(r1)
    mr      r30,r3
    lwz     r31,-23132(r13)
    bl      OSDisableInterrupts
    stw     r30,-23132(r13)
    bl      OSRestoreInterrupts
    mr      r3,r31
    lwz     r0,28(r1)
    lwz     r31,20(r1)
    lwz     r30,16(r1)
    addi    r1,r1,24
    mtlr    r0
    blr
.size AIRegisterDMACallback, . - AIRegisterDMACallback

.global AIInitDMA
.balign 4
AIInitDMA:
/* 0x80266E90 | size=0x88 (136 bytes) */
    mflr    r0
    stw     r0,4(r1)
    stwu    r1,-24(r1)
    stw     r31,20(r1)
    addi    r31,r4,0
    stw     r30,16(r1)
    addi    r30,r3,0
    bl      OSDisableInterrupts
    lis     r4,-13312
    lhz     r0,20528(r4)
    addi    r5,r4,20480
    addi    r6,r4,20480
    addi    r7,r4,20480
    clrrwi  r4,r0,10
    srwi    r0,r30,16
    or      r0,r4,r0
    sth     r0,48(r5)
    clrlwi  r0,r30,16
    lhz     r4,50(r6)
    rlwinm  r4,r4,0,27,15
    or      r0,r4,r0
    sth     r0,50(r6)
    rlwinm  r0,r31,27,16,31
    lhz     r4,54(r7)
    clrrwi  r4,r4,15
    or      r0,r4,r0
    sth     r0,54(r7)
    bl      OSRestoreInterrupts
    lwz     r0,28(r1)
    lwz     r31,20(r1)
    lwz     r30,16(r1)
    addi    r1,r1,24
    mtlr    r0
    blr
.size AIInitDMA, . - AIInitDMA

.global AIRegisterStreamCallback
.balign 4
AIRegisterStreamCallback:
/* 0x80266F9C | size=0x44 (68 bytes) */
    mflr    r0
    stw     r0,4(r1)
    stwu    r1,-24(r1)
    stw     r31,20(r1)
    stw     r30,16(r1)
    mr      r30,r3
    lwz     r31,-23136(r13)
    bl      OSDisableInterrupts
    stw     r30,-23136(r13)
    bl      OSRestoreInterrupts
    mr      r3,r31
    lwz     r0,28(r1)
    lwz     r31,20(r1)
    lwz     r30,16(r1)
    addi    r1,r1,24
    mtlr    r0
    blr
.size AIRegisterStreamCallback, . - AIRegisterStreamCallback

.global AISetStreamPlayState
.balign 4
AISetStreamPlayState:
/* 0x80267024 | size=0xD8 (216 bytes) */
    mflr    r0
    stw     r0,4(r1)
    stwu    r1,-32(r1)
    stw     r31,28(r1)
    stw     r30,24(r1)
    stw     r29,20(r1)
    mr      r29,r3
    bl      AIGetStreamPlayState
    cmplw   r29,r3
    beq-    .L_802670E0
    bl      AIGetStreamSampleRate
    cmplwi  r3,0
    bne-    .L_802670CC
    cmplwi  r29,1
    bne-    .L_802670CC
    bl      AIGetStreamVolRight
    mr      r30,r3
    bl      AIGetStreamVolLeft
    addi    r29,r3,0
    li      r3,0
    bl      AISetStreamVolRight
    li      r3,0
    bl      AISetStreamVolLeft
    bl      OSDisableInterrupts
    mr      r31,r3
    bl      __AI_SRC_INIT
    lis     r4,-13312
    lwz     r0,27648(r4)
    addi    r3,r31,0
    rlwinm  r0,r0,0,27,25
    ori     r0,r0,32
    stw     r0,27648(r4)
    lwz     r0,27648(r4)
    clrrwi  r0,r0,1
    ori     r0,r0,1
    stw     r0,27648(r4)
    bl      OSRestoreInterrupts
    mr      r3,r30
    bl      AISetStreamVolLeft
    mr      r3,r29
    bl      AISetStreamVolRight
    b       .L_802670E0
.L_802670CC:
    lis     r3,-13312
    lwz     r0,27648(r3)
    clrrwi  r0,r0,1
    or      r0,r0,r29
    stw     r0,27648(r3)
.L_802670E0:
    lwz     r0,36(r1)
    lwz     r31,28(r1)
    lwz     r30,24(r1)
    lwz     r29,20(r1)
    addi    r1,r1,32
    mtlr    r0
    blr
.size AISetStreamPlayState, . - AISetStreamPlayState

.global AISetDSPSampleRate
.balign 4
AISetDSPSampleRate:
/* 0x8026710C | size=0xE0 (224 bytes) */
    mflr    r0
    stw     r0,4(r1)
    stwu    r1,-40(r1)
    stmw    r26,16(r1)
    mr      r26,r3
    bl      AIGetDSPSampleRate
    cmplw   r26,r3
    beq-    .L_802671D8
    lis     r31,-13312
    lwz     r0,27648(r31)
    cmplwi  r26,0
    rlwinm  r0,r0,0,26,24
    stw     r0,27648(r31)
    bne-    .L_802671D8
    bl      AIGetStreamVolLeft
    mr      r30,r3
    bl      AIGetStreamVolRight
    lwz     r0,27648(r31)
    addi    r29,r3,0
    clrlwi  r27,r0,31
    bl      AIGetStreamSampleRate
    addi    r28,r3,0
    li      r3,0
    bl      AISetStreamVolLeft
    li      r3,0
    bl      AISetStreamVolRight
    bl      OSDisableInterrupts
    mr      r26,r3
    bl      __AI_SRC_INIT
    lwz     r4,27648(r31)
    slwi    r0,r28,1
    addi    r3,r26,0
    rlwinm  r4,r4,0,27,25
    ori     r4,r4,32
    stw     r4,27648(r31)
    lwz     r4,27648(r31)
    rlwinm  r4,r4,0,31,29
    or      r0,r4,r0
    stw     r0,27648(r31)
    lwz     r0,27648(r31)
    clrrwi  r0,r0,1
    or      r0,r0,r27
    stw     r0,27648(r31)
    lwz     r0,27648(r31)
    ori     r0,r0,64
    stw     r0,27648(r31)
    bl      OSRestoreInterrupts
    mr      r3,r30
    bl      AISetStreamVolLeft
    mr      r3,r29
    bl      AISetStreamVolRight
.L_802671D8:
    lmw     r26,16(r1)
    lwz     r0,44(r1)
    addi    r1,r1,40
    mtlr    r0
    blr
.size AISetDSPSampleRate, . - AISetDSPSampleRate

.global __AI_set_stream_sample_rate
.balign 4
__AI_set_stream_sample_rate:
/* 0x80267248 | size=0xD4 (212 bytes) */
    mflr    r0
    stw     r0,4(r1)
    stwu    r1,-48(r1)
    stmw    r25,20(r1)
    mr      r25,r3
    bl      AIGetStreamSampleRate
    cmplw   r25,r3
    beq-    .L_80267308
    lis     r31,-13312
    lwz     r0,27648(r31)
    clrlwi  r0,r0,31
    mr      r29,r0
    bl      AIGetStreamVolLeft
    mr      r28,r3
    bl      AIGetStreamVolRight
    addi    r27,r3,0
    li      r3,0
    bl      AISetStreamVolRight
    li      r3,0
    bl      AISetStreamVolLeft
    lwz     r3,27648(r31)
    lwz     r0,27648(r31)
    rlwinm  r26,r3,0,25,25
    rlwinm  r0,r0,0,26,24
    stw     r0,27648(r31)
    bl      OSDisableInterrupts
    mr      r30,r3
    bl      __AI_SRC_INIT
    lwz     r4,27648(r31)
    slwi    r0,r25,1
    addi    r3,r30,0
    or      r4,r4,r26
    stw     r4,27648(r31)
    lwz     r4,27648(r31)
    rlwinm  r4,r4,0,27,25
    ori     r4,r4,32
    stw     r4,27648(r31)
    lwz     r4,27648(r31)
    rlwinm  r4,r4,0,31,29
    or      r0,r4,r0
    stw     r0,27648(r31)
    bl      OSRestoreInterrupts
    mr      r3,r29
    bl      AISetStreamPlayState
    mr      r3,r28
    bl      AISetStreamVolLeft
    mr      r3,r27
    bl      AISetStreamVolRight
.L_80267308:
    lmw     r25,20(r1)
    lwz     r0,52(r1)
    addi    r1,r1,48
    mtlr    r0
    blr
.size __AI_set_stream_sample_rate, . - __AI_set_stream_sample_rate

.global __AISHandler
.balign 4
__AISHandler:
/* 0x802674FC | size=0x7C (124 bytes) */
    mflr    r0
    stw     r0,4(r1)
    stwu    r1,-736(r1)
    stw     r31,732(r1)
    lis     r31,-13312
    lwz     r0,27648(r31)
    addi    r3,r1,16
    stw     r30,728(r1)
    ori     r0,r0,8
    stw     r0,27648(r31)
    addi    r30,r4,0
    bl      OSClearContext
    addi    r3,r1,16
    bl      OSSetCurrentContext
    lwz     r12,-23136(r13)
    cmplwi  r12,0
    beq-    .L_80267550
    addi    r3,r31,27648
    mtlr    r12
    lwz     r3,8(r3)
    blrl
.L_80267550:
    addi    r3,r1,16
    bl      OSClearContext
    mr      r3,r30
    bl      OSSetCurrentContext
    lwz     r0,740(r1)
    lwz     r31,732(r1)
    lwz     r30,728(r1)
    addi    r1,r1,736
    mtlr    r0
    blr
.size __AISHandler, . - __AISHandler

.global __AIDHandler
.balign 4
__AIDHandler:
/* 0x80267578 | size=0xAC (172 bytes) */
    mflr    r0
    lis     r3,-13312
    stw     r0,4(r1)
    addi    r3,r3,20480
    li      r0,-161
    stwu    r1,-736(r1)
    stw     r31,732(r1)
    addi    r31,r4,0
    lhz     r5,10(r3)
    and     r0,r5,r0
    ori     r0,r0,8
    sth     r0,10(r3)
    addi    r3,r1,16
    bl      OSClearContext
    addi    r3,r1,16
    bl      OSSetCurrentContext
    lwz     r3,-23132(r13)
    cmplwi  r3,0
    beq-    .L_80267600
    lwz     r0,-23116(r13)
    cmpwi   r0,0
    bne-    .L_80267600
    lwz     r0,-23128(r13)
    li      r4,1
    stw     r4,-23116(r13)
    cmplwi  r0,0
    beq-    .L_802675EC
    bl      __AICallbackStackSwitch
    b       .L_802675F8
.L_802675EC:
    addi    r12,r3,0
    mtlr    r12
    blrl
.L_802675F8:
    li      r0,0
    stw     r0,-23116(r13)
.L_80267600:
    addi    r3,r1,16
    bl      OSClearContext
    mr      r3,r31
    bl      OSSetCurrentContext
    lwz     r0,740(r1)
    lwz     r31,732(r1)
    addi    r1,r1,736
    mtlr    r0
    blr
.size __AIDHandler, . - __AIDHandler

.global __AICallbackStackSwitch
.balign 4
__AICallbackStackSwitch:
/* 0x80267624 | size=0x58 (88 bytes) */
    mflr    r0
    stw     r0,4(r1)
    stwu    r1,-24(r1)
    stw     r31,20(r1)
    mr      r31,r3
    lis     r5,-32688
    addi    r5,r5,-308
    stw     r1,0(r5)
    lis     r5,-32688
    addi    r5,r5,-312
    lwz     r1,0(r5)
    addi    r1,r1,-8
    mtlr    r31
    blrl
    lis     r5,-32688
    addi    r5,r5,-308
    lwz     r1,0(r5)
    lwz     r0,28(r1)
    lwz     r31,20(r1)
    addi    r1,r1,24
    mtlr    r0
    blr
.size __AICallbackStackSwitch, . - __AICallbackStackSwitch

# ============================================================
# gx.a
# ============================================================

#
# === GXAttr.o ===
#

.global __GXXfVtxSpecs
.balign 4
__GXXfVtxSpecs:
/* 0x80389428 | size=0x8C (140 bytes) */
    lwz     r3,-17720(r13)
    lbz     r0,1237(r3)
    cmplwi  r0,0
    beq-    .L_80389440
    li      r7,2
    b       .L_80389458
.L_80389440:
    lbz     r0,1236(r3)
    cmplwi  r0,0
    beq-    .L_80389454
    li      r7,1
    b       .L_80389458
.L_80389454:
    li      r7,0
.L_80389458:
    lwz     r5,-17720(r13)
    li      r0,16
    lwz     r6,20(r3)
    lis     r4,-13311
    lwz     r3,24(r5)
    rlwinm  r6,r6,19,28,31
    cntlzw  r6,r6
    stb     r0,-32768(r4)
    clrlwi  r3,r3,16
    subfic  r6,r6,33
    cntlzw  r0,r3
    subfic  r3,r0,33
    li      r0,4104
    stw     r0,-32768(r4)
    srwi    r6,r6,1
    slwi    r0,r7,2
    rlwinm  r3,r3,3,0,27
    or      r0,r6,r0
    or      r0,r3,r0
    stw     r0,-32768(r4)
    li      r0,1
    sth     r0,2(r5)
    blr
.size __GXXfVtxSpecs, . - __GXXfVtxSpecs

.global __GXSetVCD
.balign 4
__GXSetVCD:
/* 0x803899A8 | size=0xBC (188 bytes) */
    li      r6,8
    lwz     r4,-17720(r13)
    lis     r5,-13311
    stb     r6,-32768(r5)
    li      r3,80
    li      r0,96
    stb     r3,-32768(r5)
    lwz     r3,20(r4)
    stw     r3,-32768(r5)
    stb     r6,-32768(r5)
    stb     r0,-32768(r5)
    lwz     r0,24(r4)
    stw     r0,-32768(r5)
    lbz     r0,1237(r4)
    cmplwi  r0,0
    beq-    .L_803899F0
    li      r7,2
    b       .L_80389A08
.L_803899F0:
    lbz     r0,1236(r4)
    cmplwi  r0,0
    beq-    .L_80389A04
    li      r7,1
    b       .L_80389A08
.L_80389A04:
    li      r7,0
.L_80389A08:
    lwz     r5,-17720(r13)
    li      r0,16
    lwz     r6,20(r4)
    lis     r4,-13311
    lwz     r3,24(r5)
    rlwinm  r6,r6,19,28,31
    cntlzw  r6,r6
    stb     r0,-32768(r4)
    clrlwi  r3,r3,16
    subfic  r6,r6,33
    cntlzw  r0,r3
    subfic  r3,r0,33
    li      r0,4104
    stw     r0,-32768(r4)
    srwi    r6,r6,1
    slwi    r0,r7,2
    rlwinm  r3,r3,3,0,27
    or      r0,r6,r0
    or      r0,r3,r0
    stw     r0,-32768(r4)
    li      r0,1
    sth     r0,2(r5)
    blr
.size __GXSetVCD, . - __GXSetVCD

.global GXGetVtxDescv
.balign 4
GXGetVtxDescv:
/* 0x80389D3C | size=0x90 (144 bytes) */
    mflr    r0
    stw     r0,4(r1)
    stwu    r1,-32(r1)
    stw     r31,28(r1)
    li      r31,0
    stw     r30,24(r1)
    li      r30,0
    stw     r29,20(r1)
    addi    r29,r3,0
.L_80389D60:
    add     r4,r29,r31
    stw     r30,0(r4)
    addi    r3,r30,0
    addi    r4,r4,4
    bl      GXGetVtxDesc
    addi    r30,r30,1
    cmpwi   r30,20
    addi    r31,r31,8
    ble+    .L_80389D60
    slwi    r0,r30,3
    add     r3,r29,r0
    li      r0,25
    stw     r0,0(r3)
    addi    r4,r3,4
    li      r3,25
    bl      GXGetVtxDesc
    addi    r30,r30,1
    slwi    r0,r30,3
    li      r3,255
    stwx    r3,r29,r0
    lwz     r0,36(r1)
    lwz     r31,28(r1)
    lwz     r30,24(r1)
    lwz     r29,20(r1)
    addi    r1,r1,32
    mtlr    r0
    blr
.size GXGetVtxDescv, . - GXGetVtxDescv

.global __GXSetVAT
.balign 4
__GXSetVAT:
/* 0x8038A2E0 | size=0x88 (136 bytes) */
    lwz     r9,-17720(r13)
    li      r11,0
    li      r10,0
    lbz     r12,1451(r9)
    lis     r7,-13311
.L_8038A2F4:
    clrlwi. r0,r12,31
    beq-    .L_8038A348
    li      r8,8
    stb     r8,-32768(r7)
    ori     r3,r11,112
    addi    r0,r10,28
    stb     r3,-32768(r7)
    ori     r5,r11,128
    addi    r4,r10,60
    lwzx    r6,r9,r0
    ori     r3,r11,144
    addi    r0,r10,92
    stw     r6,-32768(r7)
    stb     r8,-32768(r7)
    stb     r5,-32768(r7)
    lwzx    r4,r9,r4
    stw     r4,-32768(r7)
    stb     r8,-32768(r7)
    stb     r3,-32768(r7)
    lwzx    r0,r9,r0
    stw     r0,-32768(r7)
.L_8038A348:
    srwi.   r12,r12,1
    addi    r10,r10,4
    addi    r11,r11,1
    bne+    .L_8038A2F4
    lwz     r3,-17720(r13)
    li      r0,0
    stb     r0,1451(r3)
    blr
.size __GXSetVAT, . - __GXSetVAT

.global GXGetVtxAttrFmtv
.balign 4
GXGetVtxAttrFmtv:
/* 0x8038A5E8 | size=0x74 (116 bytes) */
    mflr    r0
    stw     r0,4(r1)
    stwu    r1,-32(r1)
    stw     r31,28(r1)
    li      r31,9
    stw     r30,24(r1)
    addi    r30,r4,0
    stw     r29,20(r1)
    addi    r29,r3,0
.L_8038A60C:
    stw     r31,0(r30)
    addi    r3,r29,0
    addi    r4,r31,0
    addi    r5,r30,4
    addi    r6,r30,8
    addi    r7,r30,12
    bl      GXGetVtxAttrFmt
    addi    r31,r31,1
    cmpwi   r31,20
    addi    r30,r30,16
    ble+    .L_8038A60C
    li      r0,255
    stw     r0,0(r30)
    lwz     r0,36(r1)
    lwz     r31,28(r1)
    lwz     r30,24(r1)
    lwz     r29,20(r1)
    addi    r1,r1,32
    mtlr    r0
    blr
.size GXGetVtxAttrFmtv, . - GXGetVtxAttrFmtv

.global GXSetArray
.balign 4
GXSetArray:
/* 0x8038A65C | size=0x44 (68 bytes) */
    cmpwi   r3,25
    bne-    .L_8038A668
    li      r3,10
.L_8038A668:
    li      r7,8
    addi    r3,r3,-9
    lis     r6,-13311
    stb     r7,-32768(r6)
    ori     r0,r3,160
    clrlwi  r4,r4,2
    stb     r0,-32768(r6)
    ori     r3,r3,176
    clrlwi  r0,r5,24
    stw     r4,-32768(r6)
    stb     r7,-32768(r6)
    stb     r3,-32768(r6)
    stw     r0,-32768(r6)
    blr
.size GXSetArray, . - GXSetArray

#
# === GXBump.o ===
#

.global GXSetTevIndirect
.balign 4
GXSetTevIndirect:
/* 0x8038EC58 | size=0x6C (108 bytes) */
    stwu    r1,-48(r1)
    li      r0,0
    rlwimi  r0,r4,0,30,31
    stw     r31,44(r1)
    mr      r11,r0
    rlwimi  r11,r5,2,28,29
    lwz     r12,60(r1)
    lbz     r31,59(r1)
    rlwimi  r11,r6,4,25,27
    lwz     r4,-17720(r13)
    rlwimi  r11,r12,7,23,24
    rlwimi  r11,r7,9,19,22
    rlwimi  r11,r8,13,16,18
    rlwimi  r11,r9,16,13,15
    rlwimi  r11,r31,19,12,12
    li      r0,97
    lis     r5,-13311
    stb     r0,-32768(r5)
    addi    r0,r3,16
    rlwimi  r11,r10,20,11,11
    rlwimi  r11,r0,24,0,7
    stw     r11,-32768(r5)
    li      r0,0
    sth     r0,2(r4)
    lwz     r31,44(r1)
    addi    r1,r1,48
    blr
.size GXSetTevIndirect, . - GXSetTevIndirect

.global GXSetIndTexOrder
.balign 4
GXSetIndTexOrder:
/* 0x8038EF80 | size=0xEC (236 bytes) */
    cmpwi   r5,255
    bne-    .L_8038EF8C
    li      r5,0
.L_8038EF8C:
    cmpwi   r4,255
    bne-    .L_8038EF98
    li      r4,0
.L_8038EF98:
    cmpwi   r3,2
    beq-    .L_8038F000
    bge-    .L_8038EFB4
    cmpwi   r3,0
    beq-    .L_8038EFC0
    bge-    .L_8038EFE0
    b       .L_8038F03C
.L_8038EFB4:
    cmpwi   r3,4
    bge-    .L_8038F03C
    b       .L_8038F020
.L_8038EFC0:
    lwz     r3,-17720(r13)
    lwz     r0,288(r3)
    rlwimi  r0,r5,0,29,31
    stw     r0,288(r3)
    lwz     r0,288(r3)
    rlwimi  r0,r4,3,26,28
    stw     r0,288(r3)
    b       .L_8038F03C
.L_8038EFE0:
    lwz     r3,-17720(r13)
    lwz     r0,288(r3)
    rlwimi  r0,r5,6,23,25
    stw     r0,288(r3)
    lwz     r0,288(r3)
    rlwimi  r0,r4,9,20,22
    stw     r0,288(r3)
    b       .L_8038F03C
.L_8038F000:
    lwz     r3,-17720(r13)
    lwz     r0,288(r3)
    rlwimi  r0,r5,12,17,19
    stw     r0,288(r3)
    lwz     r0,288(r3)
    rlwimi  r0,r4,15,14,16
    stw     r0,288(r3)
    b       .L_8038F03C
.L_8038F020:
    lwz     r3,-17720(r13)
    lwz     r0,288(r3)
    rlwimi  r0,r5,18,11,13
    stw     r0,288(r3)
    lwz     r0,288(r3)
    rlwimi  r0,r4,21,8,10
    stw     r0,288(r3)
.L_8038F03C:
    li      r0,97
    lwz     r4,-17720(r13)
    lis     r5,-13311
    stb     r0,-32768(r5)
    li      r0,0
    lwz     r3,288(r4)
    stw     r3,-32768(r5)
    lwz     r3,1452(r4)
    ori     r3,r3,3
    stw     r3,1452(r4)
    sth     r0,2(r4)
    blr
.size GXSetIndTexOrder, . - GXSetIndTexOrder

.global GXSetTevDirect
.balign 4
GXSetTevDirect:
/* 0x8038F090 | size=0x48 (72 bytes) */
    mflr    r0
    li      r4,0
    stw     r0,4(r1)
    li      r0,0
    li      r5,0
    stwu    r1,-24(r1)
    li      r6,0
    li      r7,0
    stw     r0,8(r1)
    li      r8,0
    li      r9,0
    stw     r0,12(r1)
    li      r10,0
    bl      GXSetTevIndirect
    lwz     r0,28(r1)
    addi    r1,r1,24
    mtlr    r0
    blr
.size GXSetTevDirect, . - GXSetTevDirect

.global GXSetTevIndWarp
.balign 4
GXSetTevIndWarp:
/* 0x8038F0D8 | size=0x64 (100 bytes) */
    mflr    r0
    stw     r0,4(r1)
    clrlwi. r0,r6,24
    stwu    r1,-32(r1)
    beq-    .L_8038F0F4
    li      r6,6
    b       .L_8038F0F8
.L_8038F0F4:
    li      r6,0
.L_8038F0F8:
    clrlwi. r0,r5,24
    addi    r8,r6,0
    beq-    .L_8038F10C
    li      r6,7
    b       .L_8038F110
.L_8038F10C:
    li      r6,0
.L_8038F110:
    li      r0,0
    stw     r0,8(r1)
    addi    r9,r8,0
    li      r5,0
    stw     r0,12(r1)
    li      r10,0
    bl      GXSetTevIndirect
    lwz     r0,36(r1)
    addi    r1,r1,32
    mtlr    r0
    blr
.size GXSetTevIndWarp, . - GXSetTevIndWarp

.global GXSetTevIndBumpXYZ
.balign 4
GXSetTevIndBumpXYZ:
/* 0x8038F3F4 | size=0x44 (68 bytes) */
    mflr    r0
    addi    r7,r5,0
    stw     r0,4(r1)
    li      r0,0
    li      r5,0
    stwu    r1,-32(r1)
    li      r6,7
    li      r8,0
    stw     r0,8(r1)
    li      r9,0
    li      r10,0
    stw     r0,12(r1)
    bl      GXSetTevIndirect
    lwz     r0,36(r1)
    addi    r1,r1,32
    mtlr    r0
    blr
.size GXSetTevIndBumpXYZ, . - GXSetTevIndBumpXYZ

.global GXSetTevIndRepeat
.balign 4
GXSetTevIndRepeat:
/* 0x8038F438 | size=0x48 (72 bytes) */
    mflr    r0
    li      r4,0
    stw     r0,4(r1)
    li      r0,0
    li      r5,0
    stwu    r1,-24(r1)
    li      r6,0
    li      r7,0
    stw     r0,8(r1)
    li      r8,6
    li      r9,6
    stw     r0,12(r1)
    li      r10,1
    bl      GXSetTevIndirect
    lwz     r0,28(r1)
    addi    r1,r1,24
    mtlr    r0
    blr
.size GXSetTevIndRepeat, . - GXSetTevIndRepeat

#
# === GXDisplayList.o ===
#

.global GXBeginDisplayList
.balign 4
GXBeginDisplayList:
/* 0x80390414 | size=0xCC (204 bytes) */
    mflr    r0
    lis     r5,-32688
    stw     r0,4(r1)
    stwu    r1,-32(r1)
    stw     r31,28(r1)
    addi    r31,r5,-21840
    stw     r30,24(r1)
    stw     r29,20(r1)
    addi    r29,r4,0
    stw     r28,16(r1)
    addi    r28,r3,0
    bl      GXGetCPUFifo
    lwz     r4,-17720(r13)
    mr      r30,r3
    lwz     r0,1452(r4)
    cmplwi  r0,0
    beq-    .L_8039045C
    bl      __GXSetDirtyState
.L_8039045C:
    lwz     r4,-17720(r13)
    lbz     r0,1449(r4)
    cmplwi  r0,0
    beq-    .L_80390478
    addi    r3,r31,36
    li      r5,1456
    bl      memcpy
.L_80390478:
    addi    r0,r29,-4
    stw     r28,0(r31)
    add     r0,r28,r0
    stw     r0,4(r31)
    li      r4,0
    li      r0,1
    stw     r29,8(r31)
    mr      r3,r30
    stw     r4,28(r31)
    stw     r28,20(r31)
    stw     r28,24(r31)
    lwz     r4,-17720(r13)
    stb     r0,1448(r4)
    bl      GXSaveCPUFifo
    stw     r30,-21904(r13)
    mr      r3,r31
    bl      GXSetCPUFifo
    bl      GXResetWriteGatherPipe
    lwz     r0,36(r1)
    lwz     r31,28(r1)
    lwz     r30,24(r1)
    lwz     r29,20(r1)
    lwz     r28,16(r1)
    addi    r1,r1,32
    mtlr    r0
    blr
.size GXBeginDisplayList, . - GXBeginDisplayList

.global GXEndDisplayList
.balign 4
GXEndDisplayList:
/* 0x803904E0 | size=0xC4 (196 bytes) */
    mflr    r0
    lis     r3,-32688
    stw     r0,4(r1)
    stwu    r1,-24(r1)
    stw     r31,20(r1)
    addi    r31,r3,-21840
    stw     r30,16(r1)
    stw     r29,12(r1)
    stw     r28,8(r1)
    bl      GXFlush
    lwz     r4,-22000(r13)
    mr      r3,r31
    lwz     r0,20(r4)
    rlwinm  r30,r0,6,31,31
    bl      __GXSaveCPUFifoAux
    lwz     r3,-21904(r13)
    bl      GXSetCPUFifo
    lwz     r3,-17720(r13)
    lbz     r0,1449(r3)
    cmplwi  r0,0
    beq-    .L_80390564
    bl      OSDisableInterrupts
    lwz     r4,-17720(r13)
    mr      r29,r3
    li      r5,1456
    lwz     r28,8(r4)
    addi    r3,r4,0
    addi    r4,r31,36
    bl      memcpy
    lwz     r4,-17720(r13)
    mr      r3,r29
    stw     r28,8(r4)
    bl      OSRestoreInterrupts
.L_80390564:
    lwz     r3,-17720(r13)
    li      r0,0
    cmplwi  r30,0
    stb     r0,1448(r3)
    bne-    .L_80390580
    lwz     r3,28(r31)
    b       .L_80390584
.L_80390580:
    li      r3,0
.L_80390584:
    lwz     r0,28(r1)
    lwz     r31,20(r1)
    lwz     r30,16(r1)
    lwz     r29,12(r1)
    lwz     r28,8(r1)
    addi    r1,r1,24
    mtlr    r0
    blr
.size GXEndDisplayList, . - GXEndDisplayList

.global GXCallDisplayList
.balign 4
GXCallDisplayList:
/* 0x803905A4 | size=0x70 (112 bytes) */
    mflr    r0
    stw     r0,4(r1)
    stwu    r1,-24(r1)
    stw     r31,20(r1)
    addi    r31,r4,0
    stw     r30,16(r1)
    addi    r30,r3,0
    lwz     r5,-17720(r13)
    lwz     r0,1452(r5)
    cmplwi  r0,0
    beq-    .L_803905D4
    bl      __GXSetDirtyState
.L_803905D4:
    lwz     r3,-17720(r13)
    lwz     r0,0(r3)
    cmplwi  r0,0
    bne-    .L_803905E8
    bl      __GXSendFlushPrim
.L_803905E8:
    li      r0,64
    lis     r3,-13311
    stb     r0,-32768(r3)
    stw     r30,-32768(r3)
    stw     r31,-32768(r3)
    lwz     r0,28(r1)
    lwz     r31,20(r1)
    lwz     r30,16(r1)
    addi    r1,r1,24
    mtlr    r0
    blr
.size GXCallDisplayList, . - GXCallDisplayList

#
# === GXFifo.o ===
#

.global GXOverflowHandler
.balign 4
GXOverflowHandler:
/* 0x8038846C | size=0x50 (80 bytes) */
    mflr    r0
    li      r3,0
    stw     r0,4(r1)
    li      r4,1
    stwu    r1,-8(r1)
    lwz     r5,-21936(r13)
    addi    r0,r5,1
    stw     r0,-21936(r13)
    bl      __GXWriteFifoIntEnable
    li      r3,1
    li      r4,0
    bl      __GXWriteFifoIntReset
    li      r0,1
    lwz     r3,-21952(r13)
    stw     r0,-21944(r13)
    bl      OSSuspendThread
    lwz     r0,12(r1)
    addi    r1,r1,8
    mtlr    r0
    blr
.size GXOverflowHandler, . - GXOverflowHandler

.global GXUnderflowHandler
.balign 4
GXUnderflowHandler:
/* 0x803884BC | size=0x44 (68 bytes) */
    mflr    r0
    stw     r0,4(r1)
    stwu    r1,-8(r1)
    lwz     r3,-21952(r13)
    bl      OSResumeThread
    li      r0,0
    stw     r0,-21944(r13)
    li      r3,1
    li      r4,1
    bl      __GXWriteFifoIntReset
    li      r3,1
    li      r4,0
    bl      __GXWriteFifoIntEnable
    lwz     r0,12(r1)
    addi    r1,r1,8
    mtlr    r0
    blr
.size GXUnderflowHandler, . - GXUnderflowHandler

.global GXBreakPointHandler
.balign 4
GXBreakPointHandler:
/* 0x80388500 | size=0x80 (128 bytes) */
    mflr    r0
    stw     r0,4(r1)
    li      r0,0
    stwu    r1,-736(r1)
    stw     r31,732(r1)
    addi    r31,r4,0
    lwz     r5,-17720(r13)
    lwz     r3,8(r5)
    rlwimi  r3,r0,5,26,26
    stw     r3,8(r5)
    lwz     r0,8(r5)
    lwz     r3,-21996(r13)
    sth     r0,2(r3)
    lwz     r0,-21940(r13)
    cmplwi  r0,0
    beq-    .L_8038856C
    addi    r3,r1,16
    bl      OSClearContext
    addi    r3,r1,16
    bl      OSSetCurrentContext
    lwz     r12,-21940(r13)
    mtlr    r12
    blrl
    addi    r3,r1,16
    bl      OSClearContext
    mr      r3,r31
    bl      OSSetCurrentContext
.L_8038856C:
    lwz     r0,740(r1)
    lwz     r31,732(r1)
    addi    r1,r1,736
    mtlr    r0
    blr
.size GXBreakPointHandler, . - GXBreakPointHandler

.global GXInitFifoBase
.balign 4
GXInitFifoBase:
/* 0x803886B4 | size=0x6C (108 bytes) */
    mflr    r0
    stw     r0,4(r1)
    addi    r0,r5,-4
    stwu    r1,-32(r1)
    stw     r31,28(r1)
    addi    r31,r4,0
    add     r0,r31,r0
    stw     r30,24(r1)
    addi    r30,r3,0
    addi    r4,r5,-16384
    stw     r31,0(r3)
    stw     r0,4(r3)
    li      r0,0
    stw     r5,8(r3)
    rlwinm  r5,r5,31,1,26
    stw     r0,28(r30)
    bl      GXInitFifoLimits
    addi    r3,r30,0
    addi    r4,r31,0
    addi    r5,r31,0
    bl      GXInitFifoPtrs
    lwz     r0,36(r1)
    lwz     r31,28(r1)
    lwz     r30,24(r1)
    addi    r1,r1,32
    mtlr    r0
    blr
.size GXInitFifoBase, . - GXInitFifoBase

.global GXInitFifoPtrs
.balign 4
GXInitFifoPtrs:
/* 0x80388720 | size=0x70 (112 bytes) */
    mflr    r0
    stw     r0,4(r1)
    stwu    r1,-40(r1)
    stw     r31,36(r1)
    addi    r31,r5,0
    stw     r30,32(r1)
    addi    r30,r4,0
    stw     r29,28(r1)
    addi    r29,r3,0
    bl      OSDisableInterrupts
    stw     r30,20(r29)
    subf    r0,r30,r31
    stw     r31,24(r29)
    stw     r0,28(r29)
    lwz     r4,28(r29)
    cmpwi   r4,0
    bge-    .L_80388770
    lwz     r0,8(r29)
    add     r0,r4,r0
    stw     r0,28(r29)
.L_80388770:
    bl      OSRestoreInterrupts
    lwz     r0,44(r1)
    lwz     r31,36(r1)
    lwz     r30,32(r1)
    lwz     r29,28(r1)
    addi    r1,r1,40
    mtlr    r0
    blr
.size GXInitFifoPtrs, . - GXInitFifoPtrs

.global __GXSaveCPUFifoAux
.balign 4
__GXSaveCPUFifoAux:
/* 0x80388A70 | size=0xC8 (200 bytes) */
    mflr    r0
    stw     r0,4(r1)
    stwu    r1,-24(r1)
    stw     r31,20(r1)
    mr      r31,r3
    bl      OSDisableInterrupts
    lwz     r4,-22000(r13)
    lwz     r4,12(r4)
    addis   r0,r4,-32768
    stw     r0,0(r31)
    lwz     r4,-22000(r13)
    lwz     r4,16(r4)
    addis   r0,r4,-32768
    stw     r0,4(r31)
    lwz     r4,-22000(r13)
    lwz     r0,20(r4)
    rlwinm  r4,r0,0,6,4
    addis   r0,r4,-32768
    stw     r0,24(r31)
    lbz     r0,-21948(r13)
    cmplwi  r0,0
    beq-    .L_80388AF8
    lwz     r5,-21996(r13)
    lhz     r4,58(r5)
    lhz     r5,56(r5)
    rlwimi  r5,r4,16,0,15
    addis   r0,r5,-32768
    stw     r0,20(r31)
    lwz     r5,-21996(r13)
    lhz     r4,50(r5)
    lhz     r0,48(r5)
    rlwimi  r0,r4,16,0,15
    stw     r0,28(r31)
    b       .L_80388B20
.L_80388AF8:
    lwz     r4,20(r31)
    lwz     r0,24(r31)
    subf    r0,r4,r0
    stw     r0,28(r31)
    lwz     r4,28(r31)
    cmpwi   r4,0
    bge-    .L_80388B20
    lwz     r0,8(r31)
    add     r0,r4,r0
    stw     r0,28(r31)
.L_80388B20:
    bl      OSRestoreInterrupts
    lwz     r0,28(r1)
    lwz     r31,20(r1)
    addi    r1,r1,24
    mtlr    r0
    blr
.size __GXSaveCPUFifoAux, . - __GXSaveCPUFifoAux

.global GXGetGPStatus
.balign 4
GXGetGPStatus:
/* 0x80388B68 | size=0x50 (80 bytes) */
    lwz     r9,-21996(r13)
    lwz     r8,-17720(r13)
    lhz     r0,0(r9)
    stw     r0,12(r8)
    lwz     r0,12(r8)
    clrlwi  r0,r0,31
    stb     r0,0(r3)
    lwz     r0,12(r8)
    rlwinm  r0,r0,31,31,31
    stb     r0,0(r4)
    lwz     r0,12(r8)
    rlwinm  r0,r0,30,31,31
    stb     r0,0(r5)
    lwz     r0,12(r8)
    rlwinm  r0,r0,29,31,31
    stb     r0,0(r6)
    lwz     r0,12(r8)
    rlwinm  r0,r0,28,31,31
    stb     r0,0(r7)
    blr
.size GXGetGPStatus, . - GXGetGPStatus

.global GXGetFifoPtrs
.balign 4
GXGetFifoPtrs:
/* 0x80388CCC | size=0x98 (152 bytes) */
    lwz     r0,-21960(r13)
    cmplw   r3,r0
    bne-    .L_80388CEC
    lwz     r6,-22000(r13)
    lwz     r0,20(r6)
    rlwinm  r6,r0,0,6,4
    addis   r0,r6,-32768
    stw     r0,24(r3)
.L_80388CEC:
    lwz     r0,-21956(r13)
    cmplw   r3,r0
    bne-    .L_80388D28
    lwz     r7,-21996(r13)
    lhz     r6,58(r7)
    lhz     r7,56(r7)
    rlwimi  r7,r6,16,0,15
    addis   r0,r7,-32768
    stw     r0,20(r3)
    lwz     r7,-21996(r13)
    lhz     r6,50(r7)
    lhz     r0,48(r7)
    rlwimi  r0,r6,16,0,15
    stw     r0,28(r3)
    b       .L_80388D50
.L_80388D28:
    lwz     r6,20(r3)
    lwz     r0,24(r3)
    subf    r0,r6,r0
    stw     r0,28(r3)
    lwz     r6,28(r3)
    cmpwi   r6,0
    bge-    .L_80388D50
    lwz     r0,8(r3)
    add     r0,r6,r0
    stw     r0,28(r3)
.L_80388D50:
    lwz     r0,20(r3)
    stw     r0,0(r4)
    lwz     r0,24(r3)
    stw     r0,0(r5)
    blr
.size GXGetFifoPtrs, . - GXGetFifoPtrs

.global GXSetBreakPtCallback
.balign 4
GXSetBreakPtCallback:
/* 0x80388D88 | size=0x44 (68 bytes) */
    mflr    r0
    stw     r0,4(r1)
    stwu    r1,-24(r1)
    stw     r31,20(r1)
    stw     r30,16(r1)
    mr      r30,r3
    lwz     r31,-21940(r13)
    bl      OSDisableInterrupts
    stw     r30,-21940(r13)
    bl      OSRestoreInterrupts
    mr      r3,r31
    lwz     r0,28(r1)
    lwz     r31,20(r1)
    lwz     r30,16(r1)
    addi    r1,r1,24
    mtlr    r0
    blr
.size GXSetBreakPtCallback, . - GXSetBreakPtCallback

.global GXEnableBreakPt
.balign 4
GXEnableBreakPt:
/* 0x80388DCC | size=0x8C (140 bytes) */
    mflr    r0
    stw     r0,4(r1)
    stwu    r1,-24(r1)
    stw     r31,20(r1)
    stw     r30,16(r1)
    mr      r30,r3
    bl      OSDisableInterrupts
    mr      r31,r3
    bl      __GXFifoReadDisable
    lwz     r3,-21996(r13)
    rlwinm  r0,r30,16,18,31
    sth     r30,60(r3)
    li      r3,1
    lwz     r4,-21996(r13)
    sth     r0,62(r4)
    lwz     r4,-17720(r13)
    lwz     r0,8(r4)
    rlwimi  r0,r3,1,30,30
    stw     r0,8(r4)
    lwz     r0,8(r4)
    rlwimi  r0,r3,5,26,26
    stw     r0,8(r4)
    lwz     r0,8(r4)
    lwz     r3,-21996(r13)
    sth     r0,2(r3)
    stw     r30,-21932(r13)
    bl      __GXFifoReadEnable
    mr      r3,r31
    bl      OSRestoreInterrupts
    lwz     r0,28(r1)
    lwz     r31,20(r1)
    lwz     r30,16(r1)
    addi    r1,r1,24
    mtlr    r0
    blr
.size GXEnableBreakPt, . - GXEnableBreakPt

.global GXDisableBreakPt
.balign 4
GXDisableBreakPt:
/* 0x80388E58 | size=0x54 (84 bytes) */
    mflr    r0
    stw     r0,4(r1)
    stwu    r1,-8(r1)
    bl      OSDisableInterrupts
    lwz     r4,-17720(r13)
    li      r5,0
    lwz     r0,8(r4)
    rlwimi  r0,r5,1,30,30
    stw     r0,8(r4)
    lwz     r0,8(r4)
    rlwimi  r0,r5,5,26,26
    stw     r0,8(r4)
    lwz     r0,8(r4)
    lwz     r4,-21996(r13)
    sth     r0,2(r4)
    stw     r5,-21932(r13)
    bl      OSRestoreInterrupts
    lwz     r0,12(r1)
    addi    r1,r1,8
    mtlr    r0
    blr
.size GXDisableBreakPt, . - GXDisableBreakPt

.global __GXFifoInit
.balign 4
__GXFifoInit:
/* 0x80388EAC | size=0x4C (76 bytes) */
    mflr    r0
    lis     r3,-32711
    stw     r0,4(r1)
    addi    r4,r3,-31360
    li      r3,17
    stwu    r1,-8(r1)
    bl      __OSSetInterruptHandler
    li      r3,16384
    bl      __OSUnmaskInterrupts
    bl      OSGetCurrentThread
    li      r0,0
    stw     r3,-21952(r13)
    stw     r0,-21944(r13)
    stw     r0,-21960(r13)
    stw     r0,-21956(r13)
    lwz     r0,12(r1)
    addi    r1,r1,8
    mtlr    r0
    blr
.size __GXFifoInit, . - __GXFifoInit

.global __GXCleanGPFifo
.balign 4
__GXCleanGPFifo:
/* 0x80389004 | size=0x100 (256 bytes) */
    mflr    r0
    stw     r0,4(r1)
    stwu    r1,-168(r1)
    stw     r31,164(r1)
    stw     r30,160(r1)
    stw     r29,156(r1)
    bl      GXGetGPFifo
    mr.     r31,r3
    beq-    .L_803890E8
    bl      GXGetCPUFifo
    li      r0,16
    lwz     r29,0(r31)
    mtctr   r0
    addi    r30,r3,0
    addi    r5,r1,12
    addi    r4,r31,-8
.L_80389044:
    lwzu    r3,8(r4)
    lwz     r0,4(r4)
    stwu    r3,8(r5)
    stw     r0,4(r5)
    bdnz+   .L_80389044
    bl      OSDisableInterrupts
    stw     r29,40(r1)
    li      r0,0
    stw     r29,44(r1)
    stw     r0,48(r1)
    lwz     r4,48(r1)
    cmpwi   r4,0
    bge-    .L_80389084
    lwz     r0,28(r1)
    add     r0,r4,r0
    stw     r0,48(r1)
.L_80389084:
    bl      OSRestoreInterrupts
    addi    r3,r1,20
    bl      GXSetGPFifo
    cmplw   r30,r31
    bne-    .L_803890A0
    addi    r3,r1,20
    bl      GXSetCPUFifo
.L_803890A0:
    bl      OSDisableInterrupts
    stw     r29,20(r31)
    li      r0,0
    stw     r29,24(r31)
    stw     r0,28(r31)
    lwz     r4,28(r31)
    cmpwi   r4,0
    bge-    .L_803890CC
    lwz     r0,8(r31)
    add     r0,r4,r0
    stw     r0,28(r31)
.L_803890CC:
    bl      OSRestoreInterrupts
    mr      r3,r31
    bl      GXSetGPFifo
    cmplw   r30,r31
    bne-    .L_803890E8
    mr      r3,r30
    bl      GXSetCPUFifo
.L_803890E8:
    lwz     r0,172(r1)
    lwz     r31,164(r1)
    lwz     r30,160(r1)
    lwz     r29,156(r1)
    addi    r1,r1,168
    mtlr    r0
    blr
.size __GXCleanGPFifo, . - __GXCleanGPFifo

.global GXSetCurrentGXThread
.balign 4
GXSetCurrentGXThread:
/* 0x80389104 | size=0x4C (76 bytes) */
    mflr    r0
    stw     r0,4(r1)
    stwu    r1,-16(r1)
    stw     r31,12(r1)
    stw     r30,8(r1)
    bl      OSDisableInterrupts
    lwz     r30,-21952(r13)
    mr      r31,r3
    bl      OSGetCurrentThread
    stw     r3,-21952(r13)
    mr      r3,r31
    bl      OSRestoreInterrupts
    mr      r3,r30
    lwz     r0,20(r1)
    lwz     r31,12(r1)
    lwz     r30,8(r1)
    addi    r1,r1,16
    mtlr    r0
    blr
.size GXSetCurrentGXThread, . - GXSetCurrentGXThread

#
# === GXFrameBuf.o ===
#

.global GXSetDispCopySrc
.balign 4
GXSetDispCopySrc:
/* 0x8038BC2C | size=0x7C (124 bytes) */
    lwz     r8,-17720(r13)
    li      r9,0
    clrlwi  r7,r5,16
    stw     r9,480(r8)
    clrlwi  r5,r6,16
    clrlwi  r0,r3,16
    lwz     r3,480(r8)
    rlwimi  r3,r0,0,22,31
    clrlwi  r0,r4,16
    stw     r3,480(r8)
    li      r6,73
    addi    r4,r7,-1
    lwz     r7,480(r8)
    rlwimi  r7,r0,10,12,21
    addi    r3,r5,-1
    stw     r7,480(r8)
    li      r0,74
    lwz     r5,480(r8)
    rlwimi  r5,r6,24,0,7
    stw     r5,480(r8)
    stw     r9,484(r8)
    lwz     r5,484(r8)
    rlwimi  r5,r4,0,22,31
    stw     r5,484(r8)
    lwz     r4,484(r8)
    rlwimi  r4,r3,10,12,21
    stw     r4,484(r8)
    lwz     r3,484(r8)
    rlwimi  r3,r0,24,0,7
    stw     r3,484(r8)
    blr
.size GXSetDispCopySrc, . - GXSetDispCopySrc

.global GXSetTexCopySrc
.balign 4
GXSetTexCopySrc:
/* 0x8038BCA8 | size=0x7C (124 bytes) */
    lwz     r8,-17720(r13)
    li      r9,0
    clrlwi  r7,r5,16
    stw     r9,496(r8)
    clrlwi  r5,r6,16
    clrlwi  r0,r3,16
    lwz     r3,496(r8)
    rlwimi  r3,r0,0,22,31
    clrlwi  r0,r4,16
    stw     r3,496(r8)
    li      r6,73
    addi    r4,r7,-1
    lwz     r7,496(r8)
    rlwimi  r7,r0,10,12,21
    addi    r3,r5,-1
    stw     r7,496(r8)
    li      r0,74
    lwz     r5,496(r8)
    rlwimi  r5,r6,24,0,7
    stw     r5,496(r8)
    stw     r9,500(r8)
    lwz     r5,500(r8)
    rlwimi  r5,r4,0,22,31
    stw     r5,500(r8)
    lwz     r4,500(r8)
    rlwimi  r4,r3,10,12,21
    stw     r4,500(r8)
    lwz     r3,500(r8)
    rlwimi  r3,r0,24,0,7
    stw     r3,500(r8)
    blr
.size GXSetTexCopySrc, . - GXSetTexCopySrc

.global GXSetCopyClamp
.balign 4
GXSetCopyClamp:
/* 0x8038BEAC | size=0x58 (88 bytes) */
    clrlwi  r5,r3,31
    lwz     r4,-17720(r13)
    addi    r0,r5,-1
    cntlzw  r5,r0
    lwz     r0,492(r4)
    rlwinm  r5,r5,27,24,31
    rlwinm  r3,r3,0,30,30
    rlwimi  r0,r5,0,31,31
    addi    r3,r3,-2
    stw     r0,492(r4)
    cntlzw  r0,r3
    rlwinm  r3,r0,27,24,31
    lwz     r0,492(r4)
    rlwimi  r0,r3,1,30,30
    stw     r0,492(r4)
    lwz     r0,508(r4)
    rlwimi  r0,r5,0,31,31
    stw     r0,508(r4)
    lwz     r0,508(r4)
    rlwimi  r0,r3,1,30,30
    stw     r0,508(r4)
    blr
.size GXSetCopyClamp, . - GXSetCopyClamp

.global __GXGetNumXfbLines
.balign 4
__GXGetNumXfbLines:
/* 0x8038BF04 | size=0x58 (88 bytes) */
    addi    r0,r3,-1
    slwi    r0,r0,8
    divwu   r5,r0,r4
    cmplwi  r4,128
    addi    r5,r5,1
    ble-    .L_8038BF48
    cmplwi  r4,256
    bge-    .L_8038BF48
    b       .L_8038BF2C
.L_8038BF28:
    srwi    r4,r4,1
.L_8038BF2C:
    clrlwi. r0,r4,31
    beq+    .L_8038BF28
    divwu   r0,r3,r4
    mullw   r0,r0,r4
    subf.   r0,r0,r3
    bne-    .L_8038BF48
    addi    r5,r5,1
.L_8038BF48:
    cmplwi  r5,1024
    ble-    .L_8038BF54
    li      r5,1024
.L_8038BF54:
    mr      r3,r5
    blr
.size __GXGetNumXfbLines, . - __GXGetNumXfbLines

.global GXGetNumXfbLines
.balign 4
GXGetNumXfbLines:
/* 0x8038BF5C | size=0x90 (144 bytes) */
    mflr    r0
    stw     r0,4(r1)
    stwu    r1,-32(r1)
    stw     r31,28(r1)
    mr      r31,r3
    lfs     f0,-17680(r13)
    fdivs   f1,f0,f1
    bl      __cvt_fp2unsigned
    clrlwi  r5,r31,16
    addi    r0,r5,-1
    clrlwi  r4,r3,23
    slwi    r0,r0,8
    divwu   r3,r0,r4
    cmplwi  r4,128
    addi    r3,r3,1
    ble-    .L_8038BFC8
    cmplwi  r4,256
    bge-    .L_8038BFC8
    b       .L_8038BFAC
.L_8038BFA8:
    srwi    r4,r4,1
.L_8038BFAC:
    clrlwi. r0,r4,31
    beq+    .L_8038BFA8
    divwu   r0,r5,r4
    mullw   r0,r0,r4
    subf.   r0,r0,r5
    bne-    .L_8038BFC8
    addi    r3,r3,1
.L_8038BFC8:
    cmplwi  r3,1024
    ble-    .L_8038BFD4
    li      r3,1024
.L_8038BFD4:
    lwz     r0,36(r1)
    clrlwi  r3,r3,16
    lwz     r31,28(r1)
    addi    r1,r1,32
    mtlr    r0
    blr
.size GXGetNumXfbLines, . - GXGetNumXfbLines

.global GXSetDispCopyYScale
.balign 4
GXSetDispCopyYScale:
/* 0x8038C224 | size=0xCC (204 bytes) */
    mflr    r0
    stw     r0,4(r1)
    stwu    r1,-8(r1)
    lfs     f0,-17680(r13)
    fdivs   f1,f0,f1
    bl      __cvt_fp2unsigned
    clrlwi  r7,r3,23
    lwz     r3,-17720(r13)
    li      r0,97
    lis     r4,-13311
    subfic  r5,r7,256
    stb     r0,-32768(r4)
    addic   r0,r5,-1
    subfe   r5,r0,r5
    li      r6,0
    li      r0,78
    rlwimi  r6,r7,0,23,31
    rlwimi  r6,r0,24,0,7
    stw     r6,-32768(r4)
    li      r0,0
    cmplwi  r7,128
    sth     r0,2(r3)
    addi    r4,r7,0
    lwz     r0,492(r3)
    rlwimi  r0,r5,10,21,21
    stw     r0,492(r3)
    lwz     r0,484(r3)
    rlwinm  r5,r0,22,22,31
    rlwinm  r0,r0,30,14,23
    divwu   r3,r0,r7
    addi    r5,r5,1
    addi    r3,r3,1
    ble-    .L_8038C2D4
    cmplwi  r7,256
    bge-    .L_8038C2D4
    b       .L_8038C2B8
.L_8038C2B4:
    srwi    r4,r4,1
.L_8038C2B8:
    clrlwi. r0,r4,31
    beq+    .L_8038C2B4
    divwu   r0,r5,r4
    mullw   r0,r0,r4
    subf.   r0,r0,r5
    bne-    .L_8038C2D4
    addi    r3,r3,1
.L_8038C2D4:
    cmplwi  r3,1024
    ble-    .L_8038C2E0
    li      r3,1024
.L_8038C2E0:
    lwz     r0,12(r1)
    addi    r1,r1,8
    mtlr    r0
    blr
.size GXSetDispCopyYScale, . - GXSetDispCopyYScale

.global GXSetCopyClear
.balign 4
GXSetCopyClear:
/* 0x8038C2F0 | size=0x78 (120 bytes) */
    lbz     r5,0(r3)
    li      r6,0
    lbz     r0,3(r3)
    li      r9,97
    rlwimi  r6,r5,0,24,31
    lis     r8,-13311
    lwz     r5,-17720(r13)
    rlwimi  r6,r0,8,16,23
    stb     r9,-32768(r8)
    li      r0,79
    rlwimi  r6,r0,24,0,7
    stw     r6,-32768(r8)
    li      r10,0
    li      r6,80
    lbz     r7,2(r3)
    li      r11,0
    lbz     r3,1(r3)
    li      r0,81
    rlwimi  r11,r7,0,24,31
    rlwimi  r11,r3,8,16,23
    stb     r9,-32768(r8)
    rlwimi  r11,r6,24,0,7
    stw     r11,-32768(r8)
    rlwimi  r10,r4,0,8,31
    rlwimi  r10,r0,24,0,7
    stb     r9,-32768(r8)
    li      r0,0
    stw     r10,-32768(r8)
    sth     r0,2(r5)
    blr
.size GXSetCopyClear, . - GXSetCopyClear

#
# === GXGeometry.o ===
#

.global __GXSetDirtyState
.balign 4
__GXSetDirtyState:
/* 0x8038B770 | size=0x80 (128 bytes) */
    mflr    r0
    stw     r0,4(r1)
    stwu    r1,-16(r1)
    stw     r31,12(r1)
    lwz     r3,-17720(r13)
    lwz     r31,1452(r3)
    clrlwi. r0,r31,31
    beq-    .L_8038B794
    bl      __GXSetSUTexRegs
.L_8038B794:
    rlwinm. r0,r31,0,30,30
    beq-    .L_8038B7A0
    bl      __GXUpdateBPMask
.L_8038B7A0:
    rlwinm. r0,r31,0,29,29
    beq-    .L_8038B7AC
    bl      __GXSetGenMode
.L_8038B7AC:
    rlwinm. r0,r31,0,28,28
    beq-    .L_8038B7B8
    bl      __GXSetVCD
.L_8038B7B8:
    rlwinm. r0,r31,0,27,27
    beq-    .L_8038B7C4
    bl      __GXSetVAT
.L_8038B7C4:
    rlwinm. r0,r31,0,27,28
    beq-    .L_8038B7D0
    bl      __GXCalculateVLim
.L_8038B7D0:
    lwz     r3,-17720(r13)
    li      r0,0
    stw     r0,1452(r3)
    lwz     r0,20(r1)
    lwz     r31,12(r1)
    addi    r1,r1,16
    mtlr    r0
    blr
.size __GXSetDirtyState, . - __GXSetDirtyState

.global GXBegin
.balign 4
GXBegin:
/* 0x8038B7F0 | size=0xD0 (208 bytes) */
    mflr    r0
    stw     r0,4(r1)
    stwu    r1,-40(r1)
    stw     r31,36(r1)
    stw     r30,32(r1)
    addi    r30,r5,0
    stw     r29,28(r1)
    addi    r29,r4,0
    stw     r28,24(r1)
    addi    r28,r3,0
    lwz     r6,-17720(r13)
    lwz     r31,1452(r6)
    cmplwi  r31,0
    beq-    .L_8038B87C
    clrlwi. r0,r31,31
    beq-    .L_8038B834
    bl      __GXSetSUTexRegs
.L_8038B834:
    rlwinm. r0,r31,0,30,30
    beq-    .L_8038B840
    bl      __GXUpdateBPMask
.L_8038B840:
    rlwinm. r0,r31,0,29,29
    beq-    .L_8038B84C
    bl      __GXSetGenMode
.L_8038B84C:
    rlwinm. r0,r31,0,28,28
    beq-    .L_8038B858
    bl      __GXSetVCD
.L_8038B858:
    rlwinm. r0,r31,0,27,27
    beq-    .L_8038B864
    bl      __GXSetVAT
.L_8038B864:
    rlwinm. r0,r31,0,27,28
    beq-    .L_8038B870
    bl      __GXCalculateVLim
.L_8038B870:
    lwz     r3,-17720(r13)
    li      r0,0
    stw     r0,1452(r3)
.L_8038B87C:
    lwz     r3,-17720(r13)
    lwz     r0,0(r3)
    cmplwi  r0,0
    bne-    .L_8038B890
    bl      __GXSendFlushPrim
.L_8038B890:
    or      r0,r29,r28
    lis     r3,-13311
    stb     r0,-32768(r3)
    sth     r30,-32768(r3)
    lwz     r0,44(r1)
    lwz     r31,36(r1)
    lwz     r30,32(r1)
    lwz     r29,28(r1)
    lwz     r28,24(r1)
    addi    r1,r1,40
    mtlr    r0
    blr
.size GXBegin, . - GXBegin

.global __GXSendFlushPrim
.balign 4
__GXSendFlushPrim:
/* 0x8038B8C0 | size=0x88 (136 bytes) */
    lwz     r3,-17720(r13)
    li      r0,152
    lis     r5,-13311
    lhz     r6,4(r3)
    li      r4,0
    lhz     r3,6(r3)
    mullw   r7,r6,r3
    stb     r0,-32768(r5)
    sth     r6,-32768(r5)
    addi    r3,r7,3
    cmplwi  r7,0
    srwi    r3,r3,2
    ble-    .L_8038B938
    srwi.   r0,r3,3
    mtctr   r0
    beq-    .L_8038B92C
.L_8038B900:
    stw     r4,-32768(r5)
    stw     r4,-32768(r5)
    stw     r4,-32768(r5)
    stw     r4,-32768(r5)
    stw     r4,-32768(r5)
    stw     r4,-32768(r5)
    stw     r4,-32768(r5)
    stw     r4,-32768(r5)
    bdnz+   .L_8038B900
    andi.   r3,r3,7
    beq-    .L_8038B938
.L_8038B92C:
    mtctr   r3
.L_8038B930:
    stw     r4,-32768(r5)
    bdnz+   .L_8038B930
.L_8038B938:
    lwz     r3,-17720(r13)
    li      r0,1
    sth     r0,2(r3)
    blr
.size __GXSendFlushPrim, . - __GXSendFlushPrim

.global GXEnableTexOffsets
.balign 4
GXEnableTexOffsets:
/* 0x8038BA04 | size=0x48 (72 bytes) */
    lwz     r7,-17720(r13)
    slwi    r3,r3,2
    clrlwi  r0,r5,24
    add     r6,r7,r3
    lwz     r3,184(r6)
    rlwimi  r3,r4,18,13,13
    lis     r4,-13311
    stw     r3,184(r6)
    li      r3,97
    lwz     r5,184(r6)
    rlwimi  r5,r0,19,12,12
    li      r0,0
    stw     r5,184(r6)
    stb     r3,-32768(r4)
    lwz     r3,184(r6)
    stw     r3,-32768(r4)
    sth     r0,2(r7)
    blr
.size GXEnableTexOffsets, . - GXEnableTexOffsets

#
# === GXInit.o ===
#

.global __GXDefaultTexRegionCallback
.balign 4
__GXDefaultTexRegionCallback:
/* 0x803870E0 | size=0xFC (252 bytes) */
    mflr    r0
    stw     r0,4(r1)
    stwu    r1,-32(r1)
    stw     r31,28(r1)
    stw     r30,24(r1)
    stw     r29,20(r1)
    mr      r29,r3
    mr      r30,r4
    mr      r3,r29
    bl      GXGetTexObjFmt
    mr      r31,r3
    mr      r3,r29
    bl      GXGetTexObjMipMap
    srawi   r4,r30,3
    addze   r4,r4
    slwi    r4,r4,3
    cmpwi   r31,7
    subfc   r4,r4,r30
    beq-    .L_80387190
    bge-    .L_8038713C
    cmpwi   r31,6
    bge-    .L_80387148
    b       .L_80387190
.L_8038713C:
    cmpwi   r31,11
    bge-    .L_80387190
    b       .L_8038717C
.L_80387148:
    clrlwi  r0,r3,24
    cmplwi  r0,0
    beq-    .L_80387168
    slwi    r3,r4,4
    lwz     r0,-17720(r13)
    addi    r3,r3,776
    add     r3,r0,r3
    b       .L_803871C0
.L_80387168:
    slwi    r3,r4,4
    lwz     r0,-17720(r13)
    addi    r3,r3,648
    add     r3,r0,r3
    b       .L_803871C0
.L_8038717C:
    slwi    r3,r4,4
    lwz     r0,-17720(r13)
    addi    r3,r3,520
    add     r3,r0,r3
    b       .L_803871C0
.L_80387190:
    clrlwi  r0,r3,24
    cmplwi  r0,0
    beq-    .L_803871B0
    slwi    r3,r4,4
    lwz     r0,-17720(r13)
    addi    r3,r3,648
    add     r3,r0,r3
    b       .L_803871C0
.L_803871B0:
    slwi    r3,r4,4
    lwz     r0,-17720(r13)
    addi    r3,r3,520
    add     r3,r0,r3
.L_803871C0:
    lwz     r0,36(r1)
    lwz     r31,28(r1)
    lwz     r30,24(r1)
    lwz     r29,20(r1)
    addi    r1,r1,32
    mtlr    r0
    blr
.size __GXDefaultTexRegionCallback, . - __GXDefaultTexRegionCallback

#
# === GXLight.o ===
#

.global GXInitLightDistAttn
.balign 4
GXInitLightDistAttn:
/* 0x8038CAE8 | size=0xD0 (208 bytes) */
    lfs     f0,-17632(r13)
    fcmpo   cr0,f1,f0
    bge-    .L_8038CAF8
    li      r4,0
.L_8038CAF8:
    lfs     f0,-17632(r13)
    fcmpo   cr0,f2,f0
    cror    eq,lt,eq
    beq-    .L_8038CB18
    lfs     f0,-17608(r13)
    fcmpo   cr0,f2,f0
    cror    eq,gt,eq
    bne-    .L_8038CB1C
.L_8038CB18:
    li      r4,0
.L_8038CB1C:
    cmpwi   r4,2
    beq-    .L_8038CB5C
    bge-    .L_8038CB38
    cmpwi   r4,0
    beq-    .L_8038CB9C
    bge-    .L_8038CB44
    b       .L_8038CB9C
.L_8038CB38:
    cmpwi   r4,4
    bge-    .L_8038CB9C
    b       .L_8038CB80
.L_8038CB44:
    lfs     f5,-17608(r13)
    fmuls   f0,f2,f1
    lfs     f4,-17632(r13)
    fsubs   f1,f5,f2
    fdivs   f3,f1,f0
    b       .L_8038CBA8
.L_8038CB5C:
    lfs     f5,-17608(r13)
    fmuls   f4,f2,f1
    lfs     f3,-17588(r13)
    fsubs   f2,f5,f2
    fmuls   f0,f1,f4
    fmuls   f1,f3,f2
    fdivs   f3,f1,f4
    fdivs   f4,f1,f0
    b       .L_8038CBA8
.L_8038CB80:
    fmuls   f0,f2,f1
    lfs     f5,-17608(r13)
    lfs     f3,-17632(r13)
    fsubs   f2,f5,f2
    fmuls   f0,f1,f0
    fdivs   f4,f2,f0
    b       .L_8038CBA8
.L_8038CB9C:
    lfs     f3,-17632(r13)
    lfs     f5,-17608(r13)
    fmr     f4,f3
.L_8038CBA8:
    stfs    f5,28(r3)
    stfs    f3,32(r3)
    stfs    f4,36(r3)
    blr
.size GXInitLightDistAttn, . - GXInitLightDistAttn

.global GXInitSpecularDir
.balign 4
GXInitSpecularDir:
/* 0x8038CC28 | size=0xE4 (228 bytes) */
    stwu    r1,-32(r1)
    fneg    f0,f1
    fneg    f4,f2
    lfs     f5,-17608(r13)
    fmuls   f8,f0,f0
    lfs     f6,-17632(r13)
    fsubs   f5,f5,f3
    fmuls   f7,f4,f4
    fmuls   f9,f5,f5
    fadds   f7,f8,f7
    fadds   f7,f9,f7
    fcmpu   cr0,f6,f7
    fmr     f10,f7
    beq-    .L_8038CCD0
    fcmpo   cr0,f10,f6
    ble-    .L_8038CCC4
    frsqrte f7,f10
    lfd     f9,-17584(r13)
    lfd     f8,-17576(r13)
    fmul    f6,f7,f7
    fmul    f7,f9,f7
    fmul    f6,f10,f6
    fsub    f6,f8,f6
    fmul    f7,f7,f6
    fmul    f6,f7,f7
    fmul    f7,f9,f7
    fmul    f6,f10,f6
    fsub    f6,f8,f6
    fmul    f7,f7,f6
    fmul    f6,f7,f7
    fmul    f7,f9,f7
    fmul    f6,f10,f6
    fsub    f6,f8,f6
    fmul    f6,f7,f6
    fmul    f6,f10,f6
    frsp    f6,f6
    stfs    f6,24(r1)
    lfs     f7,24(r1)
    b       .L_8038CCC8
.L_8038CCC4:
    fmr     f7,f10
.L_8038CCC8:
    lfs     f6,-17608(r13)
    fdivs   f10,f6,f7
.L_8038CCD0:
    fmuls   f6,f0,f10
    fmuls   f4,f4,f10
    fmuls   f0,f5,f10
    stfs    f6,52(r3)
    stfs    f4,56(r3)
    stfs    f0,60(r3)
    lfs     f0,-17568(r13)
    fmuls   f4,f0,f1
    fmuls   f1,f0,f2
    fmuls   f0,f0,f3
    stfs    f4,40(r3)
    stfs    f1,44(r3)
    stfs    f0,48(r3)
    addi    r1,r1,32
    blr
.size GXInitSpecularDir, . - GXInitSpecularDir

.global GXLoadLightObjImm
.balign 4
GXLoadLightObjImm:
/* 0x8038CD50 | size=0x7C (124 bytes) */
    cntlzw  r0,r4
    subfic  r0,r0,31
    rlwinm  r5,r0,4,25,27
    lis     r4,-13311
    li      r0,16
    addi    r5,r5,1536
    stb     r0,-32768(r4)
    oris    r0,r5,15
    stwu    r0,-32768(r4)
    lwz     r0,12(r3)
    xor     r6,r6,r6
    psq_l   f5,16(r3),0,0
    psq_l   f4,24(r3),0,0
    psq_l   f3,32(r3),0,0
    psq_l   f2,40(r3),0,0
    psq_l   f1,48(r3),0,0
    psq_l   f0,56(r3),0,0
    stw     r6,0(r4)
    stw     r6,0(r4)
    stw     r6,0(r4)
    stw     r0,0(r4)
    psq_st  f5,0(r4),0,0
    psq_st  f4,0(r4),0,0
    psq_st  f3,0(r4),0,0
    psq_st  f2,0(r4),0,0
    psq_st  f1,0(r4),0,0
    psq_st  f0,0(r4),0,0
    lwz     r3,-17720(r13)
    li      r0,1
    sth     r0,2(r3)
    blr
.size GXLoadLightObjImm, . - GXLoadLightObjImm

.global GXLoadLightObjIndx
.balign 4
GXLoadLightObjIndx:
/* 0x8038CDCC | size=0x48 (72 bytes) */
    cntlzw  r0,r4
    lwz     r4,-17720(r13)
    subfic  r0,r0,31
    rlwinm  r5,r0,4,25,27
    addi    r0,r5,1536
    li      r5,0
    rlwimi  r5,r0,0,20,31
    addi    r6,r5,0
    li      r0,15
    rlwimi  r6,r0,12,16,19
    li      r0,56
    lis     r5,-13311
    stb     r0,-32768(r5)
    rlwimi  r6,r3,16,0,15
    li      r0,1
    stw     r6,-32768(r5)
    sth     r0,2(r4)
    blr
.size GXLoadLightObjIndx, . - GXLoadLightObjIndx

.global GXSetChanAmbColor
.balign 4
GXSetChanAmbColor:
/* 0x8038CE14 | size=0xE8 (232 bytes) */
    cmpwi   r3,3
    beq-    .L_8038CE94
    bge-    .L_8038CE38
    cmpwi   r3,1
    beq-    .L_8038CE64
    bge-    .L_8038CE7C
    cmpwi   r3,0
    bge-    .L_8038CE48
    blr
.L_8038CE38:
    cmpwi   r3,5
    beq-    .L_8038CEB8
    bgelr-
    b       .L_8038CEAC
.L_8038CE48:
    lwz     r3,-17720(r13)
    li      r5,0
    lwz     r0,0(r4)
    lwz     r3,168(r3)
    rlwimi  r3,r0,0,0,23
    addi    r7,r3,0
    b       .L_8038CEC8
.L_8038CE64:
    lwz     r3,-17720(r13)
    li      r5,1
    lwz     r0,0(r4)
    lwz     r7,172(r3)
    rlwimi  r7,r0,0,0,23
    b       .L_8038CEC8
.L_8038CE7C:
    lwz     r3,-17720(r13)
    li      r5,0
    lbz     r0,3(r4)
    lwz     r7,168(r3)
    rlwimi  r7,r0,0,24,31
    b       .L_8038CEC8
.L_8038CE94:
    lwz     r3,-17720(r13)
    li      r5,1
    lbz     r0,3(r4)
    lwz     r7,172(r3)
    rlwimi  r7,r0,0,24,31
    b       .L_8038CEC8
.L_8038CEAC:
    lwz     r7,0(r4)
    li      r5,0
    b       .L_8038CEC8
.L_8038CEB8:
    lwz     r7,0(r4)
    li      r5,1
    b       .L_8038CEC8
    blr
.L_8038CEC8:
    li      r0,16
    lwz     r4,-17720(r13)
    lis     r6,-13311
    stb     r0,-32768(r6)
    addi    r3,r5,4106
    slwi    r0,r5,2
    stw     r3,-32768(r6)
    li      r5,1
    add     r3,r4,r0
    stw     r7,-32768(r6)
    sth     r5,2(r4)
    stw     r7,168(r3)
    blr
.size GXSetChanAmbColor, . - GXSetChanAmbColor

.global GXSetChanMatColor
.balign 4
GXSetChanMatColor:
/* 0x8038CEFC | size=0xE8 (232 bytes) */
    cmpwi   r3,3
    beq-    .L_8038CF7C
    bge-    .L_8038CF20
    cmpwi   r3,1
    beq-    .L_8038CF4C
    bge-    .L_8038CF64
    cmpwi   r3,0
    bge-    .L_8038CF30
    blr
.L_8038CF20:
    cmpwi   r3,5
    beq-    .L_8038CFA0
    bgelr-
    b       .L_8038CF94
.L_8038CF30:
    lwz     r3,-17720(r13)
    li      r5,0
    lwz     r0,0(r4)
    lwz     r3,176(r3)
    rlwimi  r3,r0,0,0,23
    addi    r7,r3,0
    b       .L_8038CFB0
.L_8038CF4C:
    lwz     r3,-17720(r13)
    li      r5,1
    lwz     r0,0(r4)
    lwz     r7,180(r3)
    rlwimi  r7,r0,0,0,23
    b       .L_8038CFB0
.L_8038CF64:
    lwz     r3,-17720(r13)
    li      r5,0
    lbz     r0,3(r4)
    lwz     r7,176(r3)
    rlwimi  r7,r0,0,24,31
    b       .L_8038CFB0
.L_8038CF7C:
    lwz     r3,-17720(r13)
    li      r5,1
    lbz     r0,3(r4)
    lwz     r7,180(r3)
    rlwimi  r7,r0,0,24,31
    b       .L_8038CFB0
.L_8038CF94:
    lwz     r7,0(r4)
    li      r5,0
    b       .L_8038CFB0
.L_8038CFA0:
    lwz     r7,0(r4)
    li      r5,1
    b       .L_8038CFB0
    blr
.L_8038CFB0:
    li      r0,16
    lwz     r4,-17720(r13)
    lis     r6,-13311
    stb     r0,-32768(r6)
    addi    r3,r5,4108
    slwi    r0,r5,2
    stw     r3,-32768(r6)
    li      r5,1
    add     r3,r4,r0
    stw     r7,-32768(r6)
    sth     r5,2(r4)
    stw     r7,176(r3)
    blr
.size GXSetChanMatColor, . - GXSetChanMatColor

.global GXSetChanCtrl
.balign 4
GXSetChanCtrl:
/* 0x8038D020 | size=0xB0 (176 bytes) */
    clrlwi  r0,r4,24
    li      r4,0
    rlwimi  r4,r0,1,30,30
    addi    r10,r4,0
    rlwimi  r10,r6,0,31,31
    cmpwi   r9,0
    rlwimi  r10,r5,6,25,25
    clrlwi  r11,r3,30
    bne-    .L_8038D048
    li      r8,0
.L_8038D048:
    subfic  r4,r9,2
    addic   r0,r4,-1
    subfe   r0,r0,r4
    neg     r9,r9
    rlwimi  r10,r8,7,23,24
    addic   r6,r9,-1
    rlwimi  r10,r0,9,22,22
    subfe   r6,r6,r9
    rlwimi  r10,r6,10,21,21
    rlwimi  r10,r7,2,26,29
    li      r5,16
    lis     r4,-13311
    stb     r5,-32768(r4)
    addi    r0,r11,4110
    rlwimi  r10,r7,7,17,20
    stw     r0,-32768(r4)
    cmpwi   r3,4
    stw     r10,-32768(r4)
    bne-    .L_8038D0A8
    stb     r5,-32768(r4)
    li      r0,4112
    stw     r0,-32768(r4)
    stw     r10,-32768(r4)
    b       .L_8038D0C0
.L_8038D0A8:
    cmpwi   r3,5
    bne-    .L_8038D0C0
    stb     r5,-32768(r4)
    li      r0,4113
    stw     r0,-32768(r4)
    stw     r10,-32768(r4)
.L_8038D0C0:
    lwz     r3,-17720(r13)
    li      r0,1
    sth     r0,2(r3)
    blr
.size GXSetChanCtrl, . - GXSetChanCtrl

#
# === GXMisc.o ===
#

.global GXSetMisc
.balign 4
GXSetMisc:
/* 0x8038A96C | size=0x94 (148 bytes) */
    cmpwi   r3,2
    beq-    .L_8038A9D0
    bge-    .L_8038A988
    cmpwi   r3,0
    beqlr-
    bge-    .L_8038A994
    blr
.L_8038A988:
    cmpwi   r3,4
    bgelr-
    b       .L_8038A9E8
.L_8038A994:
    lwz     r5,-17720(r13)
    li      r0,1
    sth     r4,4(r5)
    lhz     r3,4(r5)
    cntlzw  r3,r3
    rlwinm  r3,r3,27,16,31
    sth     r3,0(r5)
    sth     r0,2(r5)
    lhz     r0,4(r5)
    cmplwi  r0,0
    beqlr-
    lwz     r0,1452(r5)
    ori     r0,r0,8
    stw     r0,1452(r5)
    blr
.L_8038A9D0:
    neg     r4,r4
    lwz     r3,-17720(r13)
    addic   r0,r4,-1
    subfe   r0,r0,r4
    stb     r0,1449(r3)
    blr
.L_8038A9E8:
    neg     r4,r4
    lwz     r3,-17720(r13)
    addic   r0,r4,-1
    subfe   r0,r0,r4
    stb     r0,1450(r3)
    blr
.size GXSetMisc, . - GXSetMisc

.global GXFlush
.balign 4
GXFlush:
/* 0x8038AA00 | size=0x5C (92 bytes) */
    mflr    r0
    stw     r0,4(r1)
    stwu    r1,-8(r1)
    lwz     r3,-17720(r13)
    lwz     r0,1452(r3)
    cmplwi  r0,0
    beq-    .L_8038AA20
    bl      __GXSetDirtyState
.L_8038AA20:
    li      r0,0
    lis     r3,-13311
    stw     r0,-32768(r3)
    stw     r0,-32768(r3)
    stw     r0,-32768(r3)
    stw     r0,-32768(r3)
    stw     r0,-32768(r3)
    stw     r0,-32768(r3)
    stw     r0,-32768(r3)
    stw     r0,-32768(r3)
    bl      PPCSync
    lwz     r0,12(r1)
    addi    r1,r1,8
    mtlr    r0
    blr
.size GXFlush, . - GXFlush

.global __GXAbortWait
.balign 4
__GXAbortWait:
/* 0x8038AA90 | size=0x7C (124 bytes) */
    mflr    r0
    stw     r0,4(r1)
    stwu    r1,-32(r1)
    stw     r31,28(r1)
    stw     r30,24(r1)
    mr      r30,r3
    stw     r29,20(r1)
    stw     r28,16(r1)
    bl      OSGetTime
    li      r0,0
    addi    r28,r4,0
    addi    r29,r3,0
    srwi    r30,r30,2
    xoris   r31,r0,32768
.L_8038AAC8:
    bl      OSGetTime
    subfc   r4,r28,r4
    subfe   r0,r29,r3
    xoris   r3,r0,32768
    subfc   r0,r4,r30
    subfe   r3,r3,r31
    subfe   r3,r31,r31
    neg.    r3,r3
    beq+    .L_8038AAC8
    lwz     r0,36(r1)
    lwz     r31,28(r1)
    lwz     r30,24(r1)
    lwz     r29,20(r1)
    lwz     r28,16(r1)
    addi    r1,r1,32
    mtlr    r0
    blr
.size __GXAbortWait, . - __GXAbortWait

.global __GXAbortWaitPECopyDone
.balign 4
__GXAbortWaitPECopyDone:
/* 0x8038AB0C | size=0xC4 (196 bytes) */
    mflr    r0
    stw     r0,4(r1)
    stwu    r1,-40(r1)
    stmw    r27,20(r1)
    lwz     r3,-21988(r13)
    lhz     r4,78(r3)
    addi    r6,r3,78
    addi    r5,r3,80
.L_8038AB2C:
    mr      r0,r4
    lhz     r4,0(r6)
    lhz     r3,0(r5)
    cmplw   r4,r0
    bne+    .L_8038AB2C
    slwi    r0,r4,16
    or      r0,r0,r3
.L_8038AB48:
    mr      r27,r0
    bl      OSGetTime
    li      r0,0
    addi    r28,r4,0
    addi    r29,r3,0
    xoris   r31,r0,32768
    li      r30,8
.L_8038AB64:
    bl      OSGetTime
    subfc   r4,r28,r4
    subfe   r0,r29,r3
    xoris   r3,r0,32768
    subfc   r0,r4,r30
    subfe   r3,r3,r31
    subfe   r3,r31,r31
    neg.    r3,r3
    beq+    .L_8038AB64
    lwz     r3,-21988(r13)
    addi    r6,r3,78
    lhz     r4,78(r3)
    addi    r5,r3,80
.L_8038AB98:
    mr      r0,r4
    lhz     r4,0(r6)
    lhz     r3,0(r5)
    cmplw   r4,r0
    bne+    .L_8038AB98
    slwi    r0,r4,16
    or      r0,r0,r3
    cmplw   r0,r27
    bne+    .L_8038AB48
    lmw     r27,20(r1)
    lwz     r0,44(r1)
    addi    r1,r1,40
    mtlr    r0
    blr
.size __GXAbortWaitPECopyDone, . - __GXAbortWaitPECopyDone

.global GXSetDrawSync
.balign 4
GXSetDrawSync:
/* 0x8038AF04 | size=0xB4 (180 bytes) */
    mflr    r0
    stw     r0,4(r1)
    stwu    r1,-24(r1)
    stw     r31,20(r1)
    stw     r30,16(r1)
    mr      r30,r3
    bl      OSDisableInterrupts
    li      r6,97
    lwz     r4,-17720(r13)
    lis     r5,-13311
    clrlwi  r0,r30,16
    stb     r6,-32768(r5)
    oris    r7,r0,18432
    stw     r7,-32768(r5)
    rlwimi  r7,r30,0,16,31
    li      r0,71
    stb     r6,-32768(r5)
    rlwimi  r7,r0,24,0,7
    mr      r30,r3
    stw     r7,-32768(r5)
    lwz     r0,1452(r4)
    cmplwi  r0,0
    beq-    .L_8038AF64
    bl      __GXSetDirtyState
.L_8038AF64:
    li      r31,0
    lis     r3,-13311
    stw     r31,-32768(r3)
    stw     r31,-32768(r3)
    stw     r31,-32768(r3)
    stw     r31,-32768(r3)
    stw     r31,-32768(r3)
    stw     r31,-32768(r3)
    stw     r31,-32768(r3)
    stw     r31,-32768(r3)
    bl      PPCSync
    mr      r3,r30
    bl      OSRestoreInterrupts
    lwz     r3,-17720(r13)
    sth     r31,2(r3)
    lwz     r0,28(r1)
    lwz     r31,20(r1)
    lwz     r30,16(r1)
    addi    r1,r1,24
    mtlr    r0
    blr
.size GXSetDrawSync, . - GXSetDrawSync

.global GXSetDrawDone
.balign 4
GXSetDrawDone:
/* 0x8038AFC4 | size=0x98 (152 bytes) */
    mflr    r0
    stw     r0,4(r1)
    stwu    r1,-24(r1)
    stw     r31,20(r1)
    stw     r30,16(r1)
    bl      OSDisableInterrupts
    li      r0,97
    lwz     r4,-17720(r13)
    lis     r6,-13311
    lis     r5,17664
    stb     r0,-32768(r6)
    addi    r0,r5,2
    stw     r0,-32768(r6)
    mr      r30,r3
    lwz     r0,1452(r4)
    cmplwi  r0,0
    beq-    .L_8038B00C
    bl      __GXSetDirtyState
.L_8038B00C:
    li      r31,0
    lis     r3,-13311
    stw     r31,-32768(r3)
    stw     r31,-32768(r3)
    stw     r31,-32768(r3)
    stw     r31,-32768(r3)
    stw     r31,-32768(r3)
    stw     r31,-32768(r3)
    stw     r31,-32768(r3)
    stw     r31,-32768(r3)
    bl      PPCSync
    stb     r31,-21920(r13)
    mr      r3,r30
    bl      OSRestoreInterrupts
    lwz     r0,28(r1)
    lwz     r31,20(r1)
    lwz     r30,16(r1)
    addi    r1,r1,24
    mtlr    r0
    blr
.size GXSetDrawDone, . - GXSetDrawDone

.global GXWaitDrawDone
.balign 4
GXWaitDrawDone:
/* 0x8038B05C | size=0x4C (76 bytes) */
    mflr    r0
    stw     r0,4(r1)
    stwu    r1,-16(r1)
    stw     r31,12(r1)
    bl      OSDisableInterrupts
    mr      r31,r3
    b       .L_8038B080
.L_8038B078:
    addi    r3,r13,-21916
    bl      OSSleepThread
.L_8038B080:
    lbz     r0,-21920(r13)
    cmplwi  r0,0
    beq+    .L_8038B078
    mr      r3,r31
    bl      OSRestoreInterrupts
    lwz     r0,20(r1)
    lwz     r31,12(r1)
    addi    r1,r1,16
    mtlr    r0
    blr
.size GXWaitDrawDone, . - GXWaitDrawDone

.global GXDrawDone
.balign 4
GXDrawDone:
/* 0x8038B0A8 | size=0x80 (128 bytes) */
    mflr    r0
    stw     r0,4(r1)
    stwu    r1,-24(r1)
    stw     r31,20(r1)
    bl      OSDisableInterrupts
    li      r0,97
    lis     r5,-13311
    lis     r4,17664
    stb     r0,-32768(r5)
    addi    r0,r4,2
    stw     r0,-32768(r5)
    mr      r31,r3
    bl      GXFlush
    li      r0,0
    stb     r0,-21920(r13)
    mr      r3,r31
    bl      OSRestoreInterrupts
    bl      OSDisableInterrupts
    mr      r31,r3
    b       .L_8038B100
.L_8038B0F8:
    addi    r3,r13,-21916
    bl      OSSleepThread
.L_8038B100:
    lbz     r0,-21920(r13)
    cmplwi  r0,0
    beq+    .L_8038B0F8
    mr      r3,r31
    bl      OSRestoreInterrupts
    lwz     r0,28(r1)
    lwz     r31,20(r1)
    addi    r1,r1,24
    mtlr    r0
    blr
.size GXDrawDone, . - GXDrawDone

.global GXPokeBlendMode
.balign 4
GXPokeBlendMode:
/* 0x8038B1BC | size=0x64 (100 bytes) */
    lwz     r7,-21992(r13)
    cmpwi   r3,1
    li      r9,1
    lhz     r10,2(r7)
    beq-    .L_8038B1DC
    cmpwi   r3,3
    beq-    .L_8038B1DC
    li      r9,0
.L_8038B1DC:
    subfic  r0,r3,3
    lwz     r7,-21992(r13)
    cntlzw  r8,r0
    subfic  r0,r3,2
    rlwimi  r10,r9,0,31,31
    srwi    r3,r8,5
    addi    r8,r10,0
    cntlzw  r0,r0
    rlwimi  r8,r3,11,20,20
    rlwimi  r8,r0,28,30,30
    rlwimi  r8,r6,12,16,19
    rlwimi  r8,r4,8,21,23
    li      r0,65
    rlwimi  r8,r5,5,24,26
    rlwimi  r8,r0,24,0,7
    sth     r8,2(r7)
    blr
.size GXPokeBlendMode, . - GXPokeBlendMode

.global GXSetDrawSyncCallback
.balign 4
GXSetDrawSyncCallback:
/* 0x8038B31C | size=0x44 (68 bytes) */
    mflr    r0
    stw     r0,4(r1)
    stwu    r1,-24(r1)
    stw     r31,20(r1)
    stw     r30,16(r1)
    mr      r30,r3
    lwz     r31,-21928(r13)
    bl      OSDisableInterrupts
    stw     r30,-21928(r13)
    bl      OSRestoreInterrupts
    mr      r3,r31
    lwz     r0,28(r1)
    lwz     r31,20(r1)
    lwz     r30,16(r1)
    addi    r1,r1,24
    mtlr    r0
    blr
.size GXSetDrawSyncCallback, . - GXSetDrawSyncCallback

.global GXTokenInterruptHandler
.balign 4
GXTokenInterruptHandler:
/* 0x8038B360 | size=0x88 (136 bytes) */
    mflr    r0
    stw     r0,4(r1)
    stwu    r1,-736(r1)
    stw     r31,732(r1)
    stw     r30,728(r1)
    mr      r30,r4
    lwz     r0,-21928(r13)
    lwz     r3,-21992(r13)
    cmplwi  r0,0
    lhz     r31,14(r3)
    beq-    .L_8038B3BC
    addi    r3,r1,16
    bl      OSClearContext
    addi    r3,r1,16
    bl      OSSetCurrentContext
    lwz     r12,-21928(r13)
    addi    r3,r31,0
    mtlr    r12
    blrl
    addi    r3,r1,16
    bl      OSClearContext
    mr      r3,r30
    bl      OSSetCurrentContext
.L_8038B3BC:
    lwz     r3,-21992(r13)
    li      r0,1
    lhz     r4,10(r3)
    rlwimi  r4,r0,2,29,29
    sth     r4,10(r3)
    lwz     r0,740(r1)
    lwz     r31,732(r1)
    lwz     r30,728(r1)
    addi    r1,r1,736
    mtlr    r0
    blr
.size GXTokenInterruptHandler, . - GXTokenInterruptHandler

.global GXSetDrawDoneCallback
.balign 4
GXSetDrawDoneCallback:
/* 0x8038B3E8 | size=0x44 (68 bytes) */
    mflr    r0
    stw     r0,4(r1)
    stwu    r1,-24(r1)
    stw     r31,20(r1)
    stw     r30,16(r1)
    mr      r30,r3
    lwz     r31,-21924(r13)
    bl      OSDisableInterrupts
    stw     r30,-21924(r13)
    bl      OSRestoreInterrupts
    mr      r3,r31
    lwz     r0,28(r1)
    lwz     r31,20(r1)
    lwz     r30,16(r1)
    addi    r1,r1,24
    mtlr    r0
    blr
.size GXSetDrawDoneCallback, . - GXSetDrawDoneCallback

.global GXFinishInterruptHandler
.balign 4
GXFinishInterruptHandler:
/* 0x8038B42C | size=0x80 (128 bytes) */
    mflr    r0
    li      r3,1
    stw     r0,4(r1)
    stwu    r1,-736(r1)
    stw     r31,732(r1)
    addi    r31,r4,0
    lwz     r5,-21992(r13)
    lhz     r0,10(r5)
    rlwimi  r0,r3,3,28,28
    sth     r0,10(r5)
    lwz     r0,-21924(r13)
    stb     r3,-21920(r13)
    cmplwi  r0,0
    beq-    .L_8038B490
    addi    r3,r1,16
    bl      OSClearContext
    addi    r3,r1,16
    bl      OSSetCurrentContext
    lwz     r12,-21924(r13)
    mtlr    r12
    blrl
    addi    r3,r1,16
    bl      OSClearContext
    mr      r3,r31
    bl      OSSetCurrentContext
.L_8038B490:
    addi    r3,r13,-21916
    bl      OSWakeupThread
    lwz     r0,740(r1)
    lwz     r31,732(r1)
    addi    r1,r1,736
    mtlr    r0
    blr
.size GXFinishInterruptHandler, . - GXFinishInterruptHandler

.global __GXPEInit
.balign 4
__GXPEInit:
/* 0x8038B4AC | size=0x74 (116 bytes) */
    mflr    r0
    lis     r3,-32711
    stw     r0,4(r1)
    addi    r4,r3,-19616
    li      r3,18
    stwu    r1,-8(r1)
    bl      __OSSetInterruptHandler
    lis     r3,-32711
    addi    r4,r3,-19412
    li      r3,19
    bl      __OSSetInterruptHandler
    addi    r3,r13,-21916
    bl      OSInitThreadQueue
    li      r3,8192
    bl      __OSUnmaskInterrupts
    li      r3,4096
    bl      __OSUnmaskInterrupts
    lwz     r3,-21992(r13)
    li      r0,1
    lhz     r4,10(r3)
    rlwimi  r4,r0,2,29,29
    rlwimi  r4,r0,3,28,28
    rlwimi  r4,r0,0,31,31
    rlwimi  r4,r0,1,30,30
    sth     r4,10(r3)
    lwz     r0,12(r1)
    addi    r1,r1,8
    mtlr    r0
    blr
.size __GXPEInit, . - __GXPEInit

#
# === GXPerf.o ===
#

.global GXClearMemMetric
.balign 4
GXClearMemMetric:
/* 0x80391C9C | size=0xA8 (168 bytes) */
    lwz     r3,-21988(r13)
    li      r0,0
    sth     r0,50(r3)
    lwz     r3,-21988(r13)
    sth     r0,52(r3)
    lwz     r3,-21988(r13)
    sth     r0,54(r3)
    lwz     r3,-21988(r13)
    sth     r0,56(r3)
    lwz     r3,-21988(r13)
    sth     r0,60(r3)
    lwz     r3,-21988(r13)
    sth     r0,58(r3)
    lwz     r3,-21988(r13)
    sth     r0,64(r3)
    lwz     r3,-21988(r13)
    sth     r0,62(r3)
    lwz     r3,-21988(r13)
    sth     r0,68(r3)
    lwz     r3,-21988(r13)
    sth     r0,66(r3)
    lwz     r3,-21988(r13)
    sth     r0,72(r3)
    lwz     r3,-21988(r13)
    sth     r0,70(r3)
    lwz     r3,-21988(r13)
    sth     r0,76(r3)
    lwz     r3,-21988(r13)
    sth     r0,74(r3)
    lwz     r3,-21988(r13)
    sth     r0,80(r3)
    lwz     r3,-21988(r13)
    sth     r0,78(r3)
    lwz     r3,-21988(r13)
    sth     r0,84(r3)
    lwz     r3,-21988(r13)
    sth     r0,82(r3)
    lwz     r3,-21988(r13)
    sth     r0,88(r3)
    lwz     r3,-21988(r13)
    sth     r0,86(r3)
    blr
.size GXClearMemMetric, . - GXClearMemMetric

.global GXSetVCacheMetric
.balign 4
GXSetVCacheMetric:
/* 0x80391EAC | size=0x44 (68 bytes) */
    lwz     r7,-17720(r13)
    li      r6,8
    lis     r5,-13311
    lwz     r0,1444(r7)
    rlwimi  r0,r3,0,28,31
    li      r4,32
    stw     r0,1444(r7)
    li      r3,16
    li      r0,1
    stb     r6,-32768(r5)
    stb     r4,-32768(r5)
    lwz     r4,1444(r7)
    stw     r4,-32768(r5)
    stb     r6,-32768(r5)
    stb     r3,-32768(r5)
    stw     r0,-32768(r5)
    blr
.size GXSetVCacheMetric, . - GXSetVCacheMetric

.global GXReadVCacheMetric
.balign 4
GXReadVCacheMetric:
/* 0x80391EF0 | size=0x94 (148 bytes) */
    lwz     r6,-21996(r13)
    addi    r9,r6,82
    lhz     r7,82(r6)
    addi    r8,r6,80
.L_80391F00:
    mr      r0,r7
    lhz     r6,0(r8)
    lhz     r7,0(r9)
    cmplw   r7,r0
    bne+    .L_80391F00
    slwi    r0,r7,16
    or      r0,r0,r6
    stw     r0,0(r3)
    lwz     r3,-21996(r13)
    addi    r8,r3,86
    lhz     r6,86(r3)
    addi    r7,r3,84
.L_80391F30:
    mr      r0,r6
    lhz     r3,0(r7)
    lhz     r6,0(r8)
    cmplw   r6,r0
    bne+    .L_80391F30
    slwi    r0,r6,16
    or      r0,r0,r3
    stw     r0,0(r4)
    lwz     r3,-21996(r13)
    addi    r7,r3,90
    lhz     r4,90(r3)
    addi    r6,r3,88
.L_80391F60:
    mr      r0,r4
    lhz     r3,0(r6)
    lhz     r4,0(r7)
    cmplw   r4,r0
    bne+    .L_80391F60
    slwi    r0,r4,16
    or      r0,r0,r3
    stw     r0,0(r5)
    blr
.size GXReadVCacheMetric, . - GXReadVCacheMetric

.global GXInitXfRasMetric
.balign 4
GXInitXfRasMetric:
/* 0x80391FA0 | size=0x44 (68 bytes) */
    li      r0,97
    lwz     r3,-17720(r13)
    lis     r5,-13311
    lis     r4,9219
    stb     r0,-32768(r5)
    addi    r0,r4,-16350
    stw     r0,-32768(r5)
    li      r0,16
    lis     r4,3
    stb     r0,-32768(r5)
    li      r0,4102
    addi    r4,r4,4096
    stw     r0,-32768(r5)
    li      r0,1
    stw     r4,-32768(r5)
    sth     r0,2(r3)
    blr
.size GXInitXfRasMetric, . - GXInitXfRasMetric

.global GXReadXfRasMetric
.balign 4
GXReadXfRasMetric:
/* 0x80391FE4 | size=0xC4 (196 bytes) */
    lwz     r7,-21996(r13)
    addi    r10,r7,66
    lhz     r8,66(r7)
    addi    r9,r7,64
.L_80391FF4:
    mr      r0,r8
    lhz     r7,0(r9)
    lhz     r8,0(r10)
    cmplw   r8,r0
    bne+    .L_80391FF4
    slwi    r0,r8,16
    or      r0,r0,r7
    stw     r0,0(r5)
    lwz     r5,-21996(r13)
    addi    r9,r5,70
    lhz     r7,70(r5)
    addi    r8,r5,68
.L_80392024:
    mr      r0,r7
    lhz     r5,0(r8)
    lhz     r7,0(r9)
    cmplw   r7,r0
    bne+    .L_80392024
    slwi    r0,r7,16
    or      r0,r0,r5
    stw     r0,0(r6)
    lwz     r5,-21996(r13)
    addi    r8,r5,74
    lhz     r6,74(r5)
    addi    r7,r5,72
.L_80392054:
    mr      r0,r6
    lhz     r5,0(r7)
    lhz     r6,0(r8)
    cmplw   r6,r0
    bne+    .L_80392054
    slwi    r0,r6,16
    or      r0,r0,r5
    stw     r0,0(r3)
    lwz     r3,-21996(r13)
    addi    r7,r3,78
    lhz     r5,78(r3)
    addi    r6,r3,76
.L_80392084:
    mr      r0,r5
    lhz     r3,0(r6)
    lhz     r5,0(r7)
    cmplw   r5,r0
    bne+    .L_80392084
    slwi    r0,r5,16
    or      r0,r0,r3
    stw     r0,0(r4)
    blr
.size GXReadXfRasMetric, . - GXReadXfRasMetric

#
# === GXPixel.o ===
#

.global GXSetBlendMode
.balign 4
GXSetBlendMode:
/* 0x80390114 | size=0x54 (84 bytes) */
    lwz     r8,-17720(r13)
    subfic  r0,r3,3
    cntlzw  r7,r0
    subfic  r0,r3,2
    lwz     r9,464(r8)
    rlwimi  r9,r7,6,20,20
    addi    r7,r9,0
    rlwimi  r7,r3,0,31,31
    cntlzw  r0,r0
    rlwimi  r7,r0,28,30,30
    rlwimi  r7,r6,12,16,19
    rlwimi  r7,r4,8,21,23
    li      r0,97
    lis     r3,-13311
    stb     r0,-32768(r3)
    rlwimi  r7,r5,5,24,26
    li      r0,0
    stw     r7,-32768(r3)
    stw     r7,464(r8)
    sth     r0,2(r8)
    blr
.size GXSetBlendMode, . - GXSetBlendMode

.global GXSetPixelFmt
.balign 4
GXSetPixelFmt:
/* 0x80390228 | size=0xD4 (212 bytes) */
    lis     r5,-32698
    lwz     r7,-17720(r13)
    slwi    r6,r3,2
    addi    r0,r5,-22880
    lwz     r5,476(r7)
    add     r6,r0,r6
    lwz     r0,0(r6)
    addi    r8,r5,0
    rlwimi  r5,r0,0,29,31
    stw     r5,476(r7)
    lwz     r0,476(r7)
    rlwimi  r0,r4,3,26,28
    stw     r0,476(r7)
    lwz     r5,476(r7)
    cmplw   r8,r5
    beq-    .L_803902A8
    li      r0,97
    lis     r4,-13311
    stb     r0,-32768(r4)
    cmpwi   r3,2
    stw     r5,-32768(r4)
    bne-    .L_80390288
    li      r0,1
    b       .L_8039028C
.L_80390288:
    li      r0,0
.L_8039028C:
    lwz     r5,-17720(r13)
    lwz     r4,516(r5)
    rlwimi  r4,r0,9,22,22
    stw     r4,516(r5)
    lwz     r0,1452(r5)
    ori     r0,r0,4
    stw     r0,1452(r5)
.L_803902A8:
    lwz     r0,0(r6)
    cmplwi  r0,4
    bne-    .L_803902EC
    lwz     r6,-17720(r13)
    addi    r0,r3,-4
    li      r4,66
    lwz     r3,468(r6)
    rlwimi  r3,r0,9,21,22
    li      r0,97
    stw     r3,468(r6)
    lis     r3,-13311
    lwz     r5,468(r6)
    rlwimi  r5,r4,24,0,7
    stw     r5,468(r6)
    stb     r0,-32768(r3)
    lwz     r0,468(r6)
    stw     r0,-32768(r3)
.L_803902EC:
    lwz     r3,-17720(r13)
    li      r0,0
    sth     r0,2(r3)
    blr
.size GXSetPixelFmt, . - GXSetPixelFmt

.global GXSetFieldMode
.balign 4
GXSetFieldMode:
/* 0x8039039C | size=0x78 (120 bytes) */
    mflr    r0
    stw     r0,4(r1)
    clrlwi  r0,r4,24
    stwu    r1,-32(r1)
    stw     r31,28(r1)
    lis     r31,-13311
    stw     r30,24(r1)
    li      r30,97
    stw     r29,20(r1)
    mr      r29,r3
    lwz     r5,-17720(r13)
    lwz     r4,124(r5)
    rlwimi  r4,r0,22,9,9
    stw     r4,124(r5)
    stb     r30,-32768(r31)
    lwz     r0,124(r5)
    stw     r0,-32768(r31)
    bl      __GXFlushTextureState
    clrlwi  r0,r29,24
    stb     r30,-32768(r31)
    oris    r0,r0,26624
    stw     r0,-32768(r31)
    bl      __GXFlushTextureState
    lwz     r0,36(r1)
    lwz     r31,28(r1)
    lwz     r30,24(r1)
    lwz     r29,20(r1)
    addi    r1,r1,32
    mtlr    r0
    blr
.size GXSetFieldMode, . - GXSetFieldMode

#
# === GXTev.o ===
#

.global GXSetTevOp
.balign 4
GXSetTevOp:
/* 0x8038F4D8 | size=0x8C (140 bytes) */
    cmpwi   r3,0
    lis     r5,-32698
    addi    r0,r5,-23000
    bne-    .L_8038F4F8
    slwi    r4,r4,2
    add     r5,r0,r4
    addi    r9,r5,40
    b       .L_8038F50C
.L_8038F4F8:
    slwi    r4,r4,2
    add     r5,r0,r4
    add     r9,r0,r4
    addi    r5,r5,20
    addi    r9,r9,60
.L_8038F50C:
    lwz     r7,-17720(r13)
    slwi    r3,r3,2
    lwz     r0,0(r5)
    li      r5,97
    add     r6,r7,r3
    lwz     r3,304(r6)
    lis     r4,-13311
    stb     r5,-32768(r4)
    clrrwi  r3,r3,24
    rlwimi  r3,r0,0,8,31
    stw     r3,-32768(r4)
    li      r0,0
    stw     r3,304(r6)
    lwz     r8,368(r6)
    lwz     r3,0(r9)
    rlwinm  r8,r8,0,28,7
    stb     r5,-32768(r4)
    rlwimi  r8,r3,0,8,27
    stw     r8,-32768(r4)
    stw     r8,368(r6)
    sth     r0,2(r7)
    blr
.size GXSetTevOp, . - GXSetTevOp

.global GXSetTevColorIn
.balign 4
GXSetTevColorIn:
/* 0x8038F564 | size=0x44 (68 bytes) */
    lwz     r9,-17720(r13)
    slwi    r3,r3,2
    li      r0,97
    add     r8,r9,r3
    lwz     r10,304(r8)
    lis     r3,-13311
    rlwimi  r10,r4,12,16,19
    stb     r0,-32768(r3)
    addi    r4,r10,0
    rlwimi  r4,r5,8,20,23
    rlwimi  r4,r6,4,24,27
    rlwimi  r4,r7,0,28,31
    stw     r4,-32768(r3)
    li      r0,0
    stw     r4,304(r8)
    sth     r0,2(r9)
    blr
.size GXSetTevColorIn, . - GXSetTevColorIn

.global GXSetTevAlphaIn
.balign 4
GXSetTevAlphaIn:
/* 0x8038F5A8 | size=0x44 (68 bytes) */
    lwz     r9,-17720(r13)
    slwi    r3,r3,2
    li      r0,97
    add     r8,r9,r3
    lwz     r10,368(r8)
    lis     r3,-13311
    rlwimi  r10,r4,13,16,18
    stb     r0,-32768(r3)
    addi    r4,r10,0
    rlwimi  r4,r5,10,19,21
    rlwimi  r4,r6,7,22,24
    rlwimi  r4,r7,4,25,27
    stw     r4,-32768(r3)
    li      r0,0
    stw     r4,368(r8)
    sth     r0,2(r9)
    blr
.size GXSetTevAlphaIn, . - GXSetTevAlphaIn

.global GXSetTevColorOp
.balign 4
GXSetTevColorOp:
/* 0x8038F5EC | size=0x68 (104 bytes) */
    lwz     r0,-17720(r13)
    slwi    r9,r3,2
    cmpwi   r4,1
    add     r3,r0,r9
    lwz     r3,304(r3)
    rlwimi  r3,r4,18,13,13
    addi    r10,r3,0
    bgt-    .L_8038F618
    rlwimi  r10,r6,20,10,11
    rlwimi  r10,r5,16,14,15
    b       .L_8038F624
.L_8038F618:
    li      r0,3
    rlwimi  r10,r4,19,10,11
    rlwimi  r10,r0,16,14,15
.L_8038F624:
    li      r0,97
    lwz     r4,-17720(r13)
    lis     r5,-13311
    stb     r0,-32768(r5)
    rlwimi  r10,r7,19,12,12
    rlwimi  r10,r8,22,8,9
    stw     r10,-32768(r5)
    add     r3,r4,r9
    li      r0,0
    stw     r10,304(r3)
    sth     r0,2(r4)
    blr
.size GXSetTevColorOp, . - GXSetTevColorOp

.global GXSetTevAlphaOp
.balign 4
GXSetTevAlphaOp:
/* 0x8038F654 | size=0x68 (104 bytes) */
    lwz     r0,-17720(r13)
    slwi    r9,r3,2
    cmpwi   r4,1
    add     r3,r0,r9
    lwz     r3,368(r3)
    rlwimi  r3,r4,18,13,13
    addi    r10,r3,0
    bgt-    .L_8038F680
    rlwimi  r10,r6,20,10,11
    rlwimi  r10,r5,16,14,15
    b       .L_8038F68C
.L_8038F680:
    li      r0,3
    rlwimi  r10,r4,19,10,11
    rlwimi  r10,r0,16,14,15
.L_8038F68C:
    li      r0,97
    lwz     r4,-17720(r13)
    lis     r5,-13311
    stb     r0,-32768(r5)
    rlwimi  r10,r7,19,12,12
    rlwimi  r10,r8,22,8,9
    stw     r10,-32768(r5)
    add     r3,r4,r9
    li      r0,0
    stw     r10,368(r3)
    sth     r0,2(r4)
    blr
.size GXSetTevAlphaOp, . - GXSetTevAlphaOp

.global GXSetTevColor
.balign 4
GXSetTevColor:
/* 0x8038F6BC | size=0x60 (96 bytes) */
    slwi    r6,r3,1
    lwz     r8,0(r4)
    addi    r4,r6,224
    lwz     r3,-17720(r13)
    slwi    r7,r4,24
    li      r5,97
    lis     r4,-13311
    rlwimi  r7,r8,8,24,31
    stb     r5,-32768(r4)
    rlwimi  r7,r8,12,12,19
    stw     r7,-32768(r4)
    addi    r6,r6,225
    slwi    r6,r6,24
    rlwimi  r6,r8,24,24,31
    stb     r5,-32768(r4)
    rlwimi  r6,r8,28,12,19
    stw     r6,-32768(r4)
    li      r0,0
    stb     r5,-32768(r4)
    stw     r6,-32768(r4)
    stb     r5,-32768(r4)
    stw     r6,-32768(r4)
    sth     r0,2(r3)
    blr
.size GXSetTevColor, . - GXSetTevColor

.global GXSetTevColorS10
.balign 4
GXSetTevColorS10:
/* 0x8038F71C | size=0x64 (100 bytes) */
    lwz     r8,0(r4)
    slwi    r6,r3,1
    lwz     r9,4(r4)
    li      r5,97
    addi    r3,r6,224
    slwi    r7,r3,24
    lwz     r3,-17720(r13)
    lis     r4,-13311
    rlwimi  r7,r8,16,21,31
    stb     r5,-32768(r4)
    rlwimi  r7,r9,12,9,19
    stw     r7,-32768(r4)
    addi    r6,r6,225
    slwi    r6,r6,24
    rlwimi  r6,r9,16,21,31
    stb     r5,-32768(r4)
    rlwimi  r6,r8,12,9,19
    stw     r6,-32768(r4)
    li      r0,0
    stb     r5,-32768(r4)
    stw     r6,-32768(r4)
    stb     r5,-32768(r4)
    stw     r6,-32768(r4)
    sth     r0,2(r3)
    blr
.size GXSetTevColorS10, . - GXSetTevColorS10

.global GXSetTevKColor
.balign 4
GXSetTevKColor:
/* 0x8038F780 | size=0x64 (100 bytes) */
    slwi    r5,r3,1
    lwz     r9,0(r4)
    addi    r4,r5,224
    lwz     r3,-17720(r13)
    slwi    r4,r4,24
    rlwimi  r4,r9,8,24,31
    addi    r8,r4,0
    li      r0,97
    lis     r4,-13311
    addi    r6,r5,225
    stb     r0,-32768(r4)
    slwi    r6,r6,24
    rlwimi  r6,r9,24,24,31
    addi    r5,r6,0
    li      r7,8
    rlwimi  r8,r9,12,12,19
    rlwimi  r8,r7,20,8,11
    stw     r8,-32768(r4)
    rlwimi  r5,r9,28,12,19
    rlwimi  r5,r7,20,8,11
    stb     r0,-32768(r4)
    li      r0,0
    stw     r5,-32768(r4)
    sth     r0,2(r3)
    blr
.size GXSetTevKColor, . - GXSetTevKColor

.global GXSetTevKColorSel
.balign 4
GXSetTevKColorSel:
/* 0x8038F7E4 | size=0x5C (92 bytes) */
    srawi   r5,r3,1
    lwz     r6,-17720(r13)
    clrlwi. r0,r3,31
    slwi    r3,r5,2
    addi    r7,r3,432
    add     r7,r6,r7
    beq-    .L_8038F810
    lwz     r0,0(r7)
    rlwimi  r0,r4,14,13,17
    stw     r0,0(r7)
    b       .L_8038F81C
.L_8038F810:
    lwz     r0,0(r7)
    rlwimi  r0,r4,4,23,27
    stw     r0,0(r7)
.L_8038F81C:
    li      r0,97
    lwz     r3,-17720(r13)
    lis     r5,-13311
    stb     r0,-32768(r5)
    li      r0,0
    lwz     r4,0(r7)
    stw     r4,-32768(r5)
    sth     r0,2(r3)
    blr
.size GXSetTevKColorSel, . - GXSetTevKColorSel

.global GXSetTevKAlphaSel
.balign 4
GXSetTevKAlphaSel:
/* 0x8038F840 | size=0x5C (92 bytes) */
    srawi   r5,r3,1
    lwz     r6,-17720(r13)
    clrlwi. r0,r3,31
    slwi    r3,r5,2
    addi    r7,r3,432
    add     r7,r6,r7
    beq-    .L_8038F86C
    lwz     r0,0(r7)
    rlwimi  r0,r4,19,8,12
    stw     r0,0(r7)
    b       .L_8038F878
.L_8038F86C:
    lwz     r0,0(r7)
    rlwimi  r0,r4,9,18,22
    stw     r0,0(r7)
.L_8038F878:
    li      r0,97
    lwz     r3,-17720(r13)
    lis     r5,-13311
    stb     r0,-32768(r5)
    li      r0,0
    lwz     r4,0(r7)
    stw     r4,-32768(r5)
    sth     r0,2(r3)
    blr
.size GXSetTevKAlphaSel, . - GXSetTevKAlphaSel

.global GXSetTevSwapMode
.balign 4
GXSetTevSwapMode:
/* 0x8038F89C | size=0x48 (72 bytes) */
    slwi    r3,r3,2
    lwz     r7,-17720(r13)
    addi    r8,r3,368
    add     r8,r7,r8
    lwz     r0,0(r8)
    rlwimi  r0,r4,0,30,31
    li      r3,97
    stw     r0,0(r8)
    lis     r4,-13311
    li      r0,0
    lwz     r6,0(r8)
    rlwimi  r6,r5,2,28,29
    stw     r6,0(r8)
    stb     r3,-32768(r4)
    lwz     r3,0(r8)
    stw     r3,-32768(r4)
    sth     r0,2(r7)
    blr
.size GXSetTevSwapMode, . - GXSetTevSwapMode

.global GXSetTevSwapModeTable
.balign 4
GXSetTevSwapModeTable:
/* 0x8038F8E4 | size=0x80 (128 bytes) */
    slwi    r9,r3,1
    lwz     r8,-17720(r13)
    slwi    r3,r3,3
    addi    r10,r3,432
    add     r10,r8,r10
    lwz     r3,0(r10)
    rlwimi  r3,r4,0,30,31
    addi    r0,r9,1
    stw     r3,0(r10)
    slwi    r3,r0,2
    addi    r9,r3,432
    lwz     r0,0(r10)
    rlwimi  r0,r5,2,28,29
    li      r5,97
    stw     r0,0(r10)
    lis     r4,-13311
    add     r9,r8,r9
    stb     r5,-32768(r4)
    li      r0,0
    lwz     r3,0(r10)
    stw     r3,-32768(r4)
    lwz     r3,0(r9)
    rlwimi  r3,r6,0,30,31
    stw     r3,0(r9)
    lwz     r3,0(r9)
    rlwimi  r3,r7,2,28,29
    stw     r3,0(r9)
    stb     r5,-32768(r4)
    lwz     r3,0(r9)
    stw     r3,-32768(r4)
    sth     r0,2(r8)
    blr
.size GXSetTevSwapModeTable, . - GXSetTevSwapModeTable

.global GXSetAlphaCompare
.balign 4
GXSetAlphaCompare:
/* 0x8038F968 | size=0x44 (68 bytes) */
    clrlwi  r0,r4,24
    lwz     r4,-17720(r13)
    lis     r8,-3328
    rlwimi  r8,r0,0,24,31
    clrlwi  r0,r7,24
    addi    r7,r8,0
    rlwimi  r7,r0,8,16,23
    rlwimi  r7,r3,16,13,15
    rlwimi  r7,r6,19,10,12
    li      r0,97
    lis     r3,-13311
    stb     r0,-32768(r3)
    rlwimi  r7,r5,22,8,9
    li      r0,0
    stw     r7,-32768(r3)
    sth     r0,2(r4)
    blr
.size GXSetAlphaCompare, . - GXSetAlphaCompare

.global GXSetZTexture
.balign 4
GXSetZTexture:
/* 0x8038F9AC | size=0x8C (140 bytes) */
    cmpwi   r4,19
    li      r0,244
    li      r6,0
    rlwimi  r6,r5,0,8,31
    rlwimi  r6,r0,24,0,7
    li      r7,0
    beq-    .L_8038F9EC
    bge-    .L_8038F9D8
    cmpwi   r4,17
    beq-    .L_8038F9E4
    b       .L_8038F9FC
.L_8038F9D8:
    cmpwi   r4,22
    beq-    .L_8038F9F4
    b       .L_8038F9FC
.L_8038F9E4:
    li      r8,0
    b       .L_8038FA00
.L_8038F9EC:
    li      r8,1
    b       .L_8038FA00
.L_8038F9F4:
    li      r8,2
    b       .L_8038FA00
.L_8038F9FC:
    li      r8,2
.L_8038FA00:
    li      r0,97
    lwz     r4,-17720(r13)
    lis     r5,-13311
    stb     r0,-32768(r5)
    rlwimi  r7,r8,0,30,31
    rlwimi  r7,r3,2,28,29
    stw     r6,-32768(r5)
    li      r3,245
    rlwimi  r7,r3,24,0,7
    stb     r0,-32768(r5)
    li      r0,0
    stw     r7,-32768(r5)
    sth     r0,2(r4)
    blr
.size GXSetZTexture, . - GXSetZTexture

#
# === GXTexture.o ===
#

.global __GXGetTexTileShift
.balign 4
__GXGetTexTileShift:
/* 0x8038D0D0 | size=0x64 (100 bytes) */
    cmplwi  r3,60
    bgt-    .L_8038D124
    lis     r6,-32698
    addi    r6,r6,-23792
    slwi    r0,r3,2
    lwzx    r0,r6,r0
    mtctr   r0
    bctr
    li      r0,3
    stw     r0,0(r4)
    stw     r0,0(r5)
    blr
    li      r0,3
    stw     r0,0(r4)
    li      r0,2
    stw     r0,0(r5)
    blr
    li      r0,2
    stw     r0,0(r4)
    stw     r0,0(r5)
    blr
.L_8038D124:
    li      r0,0
    stw     r0,0(r5)
    stw     r0,0(r4)
    blr
.size __GXGetTexTileShift, . - __GXGetTexTileShift

.global __GetImageTileCount
.balign 4
__GetImageTileCount:
/* 0x8038D290 | size=0xC8 (200 bytes) */
    cmplwi  r3,60
    bgt-    .L_8038D2D4
    lis     r9,-32698
    addi    r9,r9,-23304
    slwi    r0,r3,2
    lwzx    r0,r9,r0
    mtctr   r0
    bctr
    li      r11,3
    li      r12,3
    b       .L_8038D2DC
    li      r11,3
    li      r12,2
    b       .L_8038D2DC
    li      r11,2
    li      r12,2
    b       .L_8038D2DC
.L_8038D2D4:
    li      r12,0
    li      r11,0
.L_8038D2DC:
    clrlwi. r0,r4,16
    bne-    .L_8038D2E8
    li      r4,1
.L_8038D2E8:
    clrlwi. r0,r5,16
    bne-    .L_8038D2F4
    li      r5,1
.L_8038D2F4:
    li      r10,1
    slw     r9,r10,r11
    clrlwi  r4,r4,16
    addi    r0,r9,-1
    add     r0,r4,r0
    sraw    r0,r0,r11
    slw     r4,r10,r12
    stw     r0,0(r6)
    clrlwi  r5,r5,16
    addi    r0,r4,-1
    add     r0,r5,r0
    sraw    r0,r0,r12
    cmpwi   r3,6
    stw     r0,0(r7)
    beq-    .L_8038D33C
    cmpwi   r3,22
    beq-    .L_8038D33C
    li      r10,0
.L_8038D33C:
    cmpwi   r10,0
    beq-    .L_8038D34C
    li      r0,2
    b       .L_8038D350
.L_8038D34C:
    li      r0,1
.L_8038D350:
    stw     r0,0(r8)
    blr
.size __GetImageTileCount, . - __GetImageTileCount

.global GXInitTexObjCI
.balign 4
GXInitTexObjCI:
/* 0x8038D5A4 | size=0x48 (72 bytes) */
    mflr    r0
    stw     r0,4(r1)
    stwu    r1,-48(r1)
    stw     r31,44(r1)
    lwz     r31,56(r1)
    stw     r30,40(r1)
    mr      r30,r3
    bl      GXInitTexObj
    lbz     r0,31(r30)
    rlwinm  r0,r0,0,31,29
    stb     r0,31(r30)
    stw     r31,24(r30)
    lwz     r0,52(r1)
    lwz     r31,44(r1)
    lwz     r30,40(r1)
    addi    r1,r1,48
    mtlr    r0
    blr
.size GXInitTexObjCI, . - GXInitTexObjCI

.global GXInitTexObjMaxLOD
.balign 4
GXInitTexObjMaxLOD:
/* 0x8038D7BC | size=0x50 (80 bytes) */
    stwu    r1,-24(r1)
    lfs     f0,-17528(r13)
    fcmpo   cr0,f1,f0
    bge-    .L_8038D7D4
    fmr     f1,f0
    b       .L_8038D7E4
.L_8038D7D4:
    lfs     f0,-17524(r13)
    fcmpo   cr0,f1,f0
    ble-    .L_8038D7E4
    fmr     f1,f0
.L_8038D7E4:
    lfs     f0,-17560(r13)
    lwz     r4,4(r3)
    fmuls   f0,f0,f1
    fctiwz  f0,f0
    stfd    f0,16(r1)
    lwz     r0,20(r1)
    rlwimi  r4,r0,8,16,23
    stw     r4,4(r3)
    addi    r1,r1,24
    blr
.size GXInitTexObjMaxLOD, . - GXInitTexObjMaxLOD

.global GXInitTexObjMinLOD
.balign 4
GXInitTexObjMinLOD:
/* 0x8038D80C | size=0x50 (80 bytes) */
    stwu    r1,-24(r1)
    lfs     f0,-17528(r13)
    fcmpo   cr0,f1,f0
    bge-    .L_8038D824
    fmr     f1,f0
    b       .L_8038D834
.L_8038D824:
    lfs     f0,-17524(r13)
    fcmpo   cr0,f1,f0
    ble-    .L_8038D834
    fmr     f1,f0
.L_8038D834:
    lfs     f0,-17560(r13)
    lwz     r4,4(r3)
    fmuls   f0,f0,f1
    fctiwz  f0,f0
    stfd    f0,16(r1)
    lwz     r0,20(r1)
    rlwimi  r4,r0,0,24,31
    stw     r4,4(r3)
    addi    r1,r1,24
    blr
.size GXInitTexObjMinLOD, . - GXInitTexObjMinLOD

.global GXInitTexObjLODBias
.balign 4
GXInitTexObjLODBias:
/* 0x8038D85C | size=0x54 (84 bytes) */
    stwu    r1,-24(r1)
    lfs     f0,-17544(r13)
    fcmpo   cr0,f1,f0
    bge-    .L_8038D874
    fmr     f1,f0
    b       .L_8038D888
.L_8038D874:
    lfs     f0,-17540(r13)
    fcmpo   cr0,f1,f0
    cror    eq,gt,eq
    bne-    .L_8038D888
    lfs     f1,-17536(r13)
.L_8038D888:
    lfs     f0,-17532(r13)
    lwz     r4,0(r3)
    fmuls   f0,f0,f1
    fctiwz  f0,f0
    stfd    f0,16(r1)
    lwz     r0,20(r1)
    rlwimi  r4,r0,9,15,22
    stw     r4,0(r3)
    addi    r1,r1,24
    blr
.size GXInitTexObjLODBias, . - GXInitTexObjLODBias

.global GXGetTexObjAll
.balign 4
GXGetTexObjAll:
/* 0x8038D908 | size=0x68 (104 bytes) */
    lwz     r0,12(r3)
    rlwinm  r0,r0,5,6,26
    stw     r0,0(r4)
    lwz     r0,8(r3)
    clrlwi  r4,r0,22
    addi    r0,r4,1
    sth     r0,0(r5)
    lwz     r0,8(r3)
    rlwinm  r4,r0,22,22,31
    addi    r0,r4,1
    sth     r0,0(r6)
    lwz     r0,20(r3)
    stw     r0,0(r7)
    lwz     r0,0(r3)
    clrlwi  r0,r0,30
    stw     r0,0(r8)
    lwz     r0,0(r3)
    rlwinm  r0,r0,30,30,31
    stw     r0,0(r9)
    lbz     r0,31(r3)
    clrlwi  r3,r0,31
    addi    r0,r3,-1
    cntlzw  r0,r0
    rlwinm  r0,r0,27,24,31
    stb     r0,0(r10)
    blr
.size GXGetTexObjAll, . - GXGetTexObjAll

.global GXGetTexObjLODAll
.balign 4
GXGetTexObjLODAll:
/* 0x8038D9D4 | size=0xE4 (228 bytes) */
    stwu    r1,-80(r1)
    lis     r12,17200
    stw     r31,76(r1)
    addi    r31,r13,-25232
    lwz     r11,88(r1)
    lwz     r0,0(r3)
    rlwinm  r0,r0,27,29,31
    lbzx    r0,r31,r0
    stw     r0,0(r4)
    lwz     r0,0(r3)
    rlwinm  r0,r0,28,31,31
    stw     r0,0(r5)
    lwz     r0,4(r3)
    lfd     f2,-17552(r13)
    clrlwi  r0,r0,24
    lfs     f1,-17520(r13)
    stw     r0,68(r1)
    stw     r12,64(r1)
    lfd     f0,64(r1)
    fsubs   f0,f0,f2
    fmuls   f0,f0,f1
    stfs    f0,0(r6)
    lwz     r0,4(r3)
    rlwinm  r0,r0,24,24,31
    stw     r0,60(r1)
    stw     r12,56(r1)
    lfd     f0,56(r1)
    fsubs   f0,f0,f2
    fmuls   f0,f0,f1
    stfs    f0,0(r7)
    lwz     r0,0(r3)
    lfd     f2,-17512(r13)
    rlwinm  r0,r0,23,24,31
    lfs     f0,-17516(r13)
    extsh   r0,r0
    extsb   r0,r0
    xoris   r0,r0,32768
    stw     r0,52(r1)
    stw     r12,48(r1)
    lfd     f1,48(r1)
    fsubs   f1,f1,f2
    fmuls   f0,f1,f0
    stfs    f0,0(r8)
    lwz     r0,0(r3)
    rlwinm  r0,r0,11,31,31
    stb     r0,0(r9)
    lwz     r0,0(r3)
    rlwinm  r0,r0,24,31,31
    cntlzw  r0,r0
    rlwinm  r0,r0,27,24,31
    stb     r0,0(r10)
    lwz     r0,0(r3)
    rlwinm  r0,r0,13,30,31
    stw     r0,0(r11)
    lwz     r31,76(r1)
    addi    r1,r1,80
    blr
.size GXGetTexObjLODAll, . - GXGetTexObjLODAll

.global GXLoadTexObj
.balign 4
GXLoadTexObj:
/* 0x8038DD30 | size=0x54 (84 bytes) */
    mflr    r0
    stw     r0,4(r1)
    stwu    r1,-24(r1)
    stw     r31,20(r1)
    addi    r31,r4,0
    stw     r30,16(r1)
    addi    r30,r3,0
    lwz     r5,-17720(r13)
    lwz     r12,1224(r5)
    mtlr    r12
    blrl
    addi    r4,r3,0
    addi    r3,r30,0
    addi    r5,r31,0
    bl      GXLoadTexObjPreLoaded
    lwz     r0,28(r1)
    lwz     r31,20(r1)
    lwz     r30,16(r1)
    addi    r1,r1,24
    mtlr    r0
    blr
.size GXLoadTexObj, . - GXLoadTexObj

.global GXLoadTlut
.balign 4
GXLoadTlut:
/* 0x8038DE00 | size=0x98 (152 bytes) */
    mflr    r0
    stw     r0,4(r1)
    stwu    r1,-24(r1)
    stw     r31,20(r1)
    stw     r30,16(r1)
    mr      r30,r3
    addi    r3,r4,0
    lwz     r5,-17720(r13)
    lwz     r12,1228(r5)
    mtlr    r12
    blrl
    mr      r31,r3
    bl      __GXFlushTextureState
    li      r4,97
    lis     r3,-13311
    stb     r4,-32768(r3)
    lwz     r0,4(r30)
    stw     r0,-32768(r3)
    stb     r4,-32768(r3)
    lwz     r0,0(r31)
    stw     r0,-32768(r3)
    bl      __GXFlushTextureState
    lwz     r3,0(r31)
    lwz     r0,0(r30)
    rlwimi  r0,r3,0,22,31
    stw     r0,0(r30)
    lwz     r3,0(r30)
    lwz     r0,4(r30)
    stw     r3,4(r31)
    stw     r0,8(r31)
    lwz     r0,8(r30)
    stw     r0,12(r31)
    lwz     r0,28(r1)
    lwz     r31,20(r1)
    lwz     r30,16(r1)
    addi    r1,r1,24
    mtlr    r0
    blr
.size GXLoadTlut, . - GXLoadTlut

.global GXInitTexCacheRegion
.balign 4
GXInitTexCacheRegion:
/* 0x8038DE98 | size=0xF4 (244 bytes) */
    cmpwi   r6,1
    beq-    .L_8038DEC4
    bge-    .L_8038DEB0
    cmpwi   r6,0
    bge-    .L_8038DEBC
    b       .L_8038DED0
.L_8038DEB0:
    cmpwi   r6,3
    bge-    .L_8038DED0
    b       .L_8038DECC
.L_8038DEBC:
    li      r9,3
    b       .L_8038DED0
.L_8038DEC4:
    li      r9,4
    b       .L_8038DED0
.L_8038DECC:
    li      r9,5
.L_8038DED0:
    li      r6,0
    stw     r6,0(r3)
    srwi    r0,r5,5
    cmpwi   r8,2
    lwz     r5,0(r3)
    rlwimi  r5,r0,0,17,31
    stw     r5,0(r3)
    lwz     r0,0(r3)
    rlwimi  r0,r9,15,14,16
    stw     r0,0(r3)
    lwz     r0,0(r3)
    rlwimi  r0,r9,18,11,13
    stw     r0,0(r3)
    lwz     r0,0(r3)
    rlwimi  r0,r6,21,10,10
    stw     r0,0(r3)
    beq-    .L_8038DF44
    bge-    .L_8038DF28
    cmpwi   r8,0
    beq-    .L_8038DF34
    bge-    .L_8038DF3C
    b       .L_8038DF50
.L_8038DF28:
    cmpwi   r8,4
    bge-    .L_8038DF50
    b       .L_8038DF4C
.L_8038DF34:
    li      r9,3
    b       .L_8038DF50
.L_8038DF3C:
    li      r9,4
    b       .L_8038DF50
.L_8038DF44:
    li      r9,5
    b       .L_8038DF50
.L_8038DF4C:
    li      r9,0
.L_8038DF50:
    li      r0,0
    stw     r0,4(r3)
    li      r0,1
    lwz     r6,4(r3)
    rlwimi  r6,r7,27,17,31
    stw     r6,4(r3)
    lwz     r5,4(r3)
    rlwimi  r5,r9,15,14,16
    stw     r5,4(r3)
    lwz     r5,4(r3)
    rlwimi  r5,r9,18,11,13
    stw     r5,4(r3)
    stb     r4,12(r3)
    stb     r0,13(r3)
    blr
.size GXInitTexCacheRegion, . - GXInitTexCacheRegion

.global GXInitTexPreLoadRegion
.balign 4
GXInitTexPreLoadRegion:
/* 0x8038DF8C | size=0x84 (132 bytes) */
    li      r9,0
    stw     r9,0(r3)
    srwi    r0,r4,5
    li      r8,1
    lwz     r4,0(r3)
    rlwimi  r4,r0,0,17,31
    stw     r4,0(r3)
    rlwinm  r4,r5,27,16,31
    lwz     r0,0(r3)
    rlwimi  r0,r9,15,14,16
    stw     r0,0(r3)
    rlwinm  r0,r7,27,16,31
    lwz     r5,0(r3)
    rlwimi  r5,r9,18,11,13
    stw     r5,0(r3)
    lwz     r5,0(r3)
    rlwimi  r5,r8,21,10,10
    stw     r5,0(r3)
    stw     r9,4(r3)
    lwz     r5,4(r3)
    rlwimi  r5,r6,27,17,31
    stw     r5,4(r3)
    lwz     r5,4(r3)
    rlwimi  r5,r9,15,14,16
    stw     r5,4(r3)
    lwz     r5,4(r3)
    rlwimi  r5,r9,18,11,13
    stw     r5,4(r3)
    stb     r9,12(r3)
    stb     r9,13(r3)
    sth     r4,8(r3)
    sth     r0,10(r3)
    blr
.size GXInitTexPreLoadRegion, . - GXInitTexPreLoadRegion

.global GXInvalidateTexAll
.balign 4
GXInvalidateTexAll:
/* 0x8038E2A0 | size=0x48 (72 bytes) */
    mflr    r0
    stw     r0,4(r1)
    stwu    r1,-8(r1)
    bl      __GXFlushTextureState
    li      r6,97
    lis     r3,26112
    lis     r5,-13311
    stb     r6,-32768(r5)
    addi    r4,r3,4096
    addi    r0,r3,4352
    stw     r4,-32768(r5)
    stb     r6,-32768(r5)
    stw     r0,-32768(r5)
    bl      __GXFlushTextureState
    lwz     r0,12(r1)
    addi    r1,r1,8
    mtlr    r0
    blr
.size GXInvalidateTexAll, . - GXInvalidateTexAll

.global GXSetTexCoordScaleManually
.balign 4
GXSetTexCoordScaleManually:
/* 0x8038E574 | size=0x7C (124 bytes) */
    lwz     r8,-17720(r13)
    li      r0,1
    clrlwi. r4,r4,24
    lwz     r7,1428(r8)
    slw     r0,r0,r3
    andc    r7,r7,r0
    slw     r0,r4,r3
    or      r0,r7,r0
    stw     r0,1428(r8)
    beqlr-
    slwi    r0,r3,2
    add     r7,r8,r0
    addi    r0,r5,-1
    lwz     r3,184(r7)
    rlwimi  r3,r0,0,16,31
    stw     r3,184(r7)
    addi    r0,r6,-1
    li      r5,97
    lwz     r3,216(r7)
    rlwimi  r3,r0,0,16,31
    lis     r4,-13311
    stw     r3,216(r7)
    li      r0,0
    stb     r5,-32768(r4)
    lwz     r3,184(r7)
    stw     r3,-32768(r4)
    stb     r5,-32768(r4)
    lwz     r3,216(r7)
    stw     r3,-32768(r4)
    sth     r0,2(r8)
    blr
.size GXSetTexCoordScaleManually, . - GXSetTexCoordScaleManually

.global GXSetTexCoordCylWrap
.balign 4
GXSetTexCoordCylWrap:
/* 0x8038E5F0 | size=0x64 (100 bytes) */
    lwz     r8,-17720(r13)
    slwi    r6,r3,2
    li      r0,1
    add     r7,r8,r6
    lwz     r6,184(r7)
    rlwimi  r6,r4,17,14,14
    slw     r0,r0,r3
    stw     r6,184(r7)
    lwz     r3,216(r7)
    rlwimi  r3,r5,17,14,14
    stw     r3,216(r7)
    lwz     r3,1428(r8)
    and.    r0,r3,r0
    beqlr-
    li      r5,97
    lis     r4,-13311
    stb     r5,-32768(r4)
    li      r0,0
    lwz     r3,184(r7)
    stw     r3,-32768(r4)
    stb     r5,-32768(r4)
    lwz     r3,216(r7)
    stw     r3,-32768(r4)
    sth     r0,2(r8)
    blr
.size GXSetTexCoordCylWrap, . - GXSetTexCoordCylWrap

.global GXSetTexCoordBias
.balign 4
GXSetTexCoordBias:
/* 0x8038E654 | size=0x64 (100 bytes) */
    lwz     r8,-17720(r13)
    slwi    r6,r3,2
    li      r0,1
    add     r7,r8,r6
    lwz     r6,184(r7)
    rlwimi  r6,r4,16,15,15
    slw     r0,r0,r3
    stw     r6,184(r7)
    lwz     r3,216(r7)
    rlwimi  r3,r5,16,15,15
    stw     r3,216(r7)
    lwz     r3,1428(r8)
    and.    r0,r3,r0
    beqlr-
    li      r5,97
    lis     r4,-13311
    stb     r5,-32768(r4)
    li      r0,0
    lwz     r3,184(r7)
    stw     r3,-32768(r4)
    stb     r5,-32768(r4)
    lwz     r3,216(r7)
    stw     r3,-32768(r4)
    sth     r0,2(r8)
    blr
.size GXSetTexCoordBias, . - GXSetTexCoordBias

.global __SetSURegs
.balign 4
__SetSURegs:
/* 0x8038E6B8 | size=0xA0 (160 bytes) */
    lwz     r8,-17720(r13)
    slwi    r3,r3,2
    slwi    r0,r4,2
    add     r3,r8,r3
    lwz     r4,1300(r3)
    add     r7,r8,r0
    lwz     r0,184(r7)
    li      r5,97
    clrlwi  r6,r4,22
    rlwimi  r0,r6,0,16,31
    stw     r0,184(r7)
    rlwinm  r4,r4,22,22,31
    lwz     r0,216(r7)
    rlwimi  r0,r4,0,16,31
    lis     r4,-13311
    stw     r0,216(r7)
    li      r0,0
    lwz     r9,1332(r3)
    lwz     r3,184(r7)
    clrlwi  r6,r9,30
    subfic  r6,r6,1
    cntlzw  r6,r6
    rlwinm  r10,r6,27,24,31
    rlwinm  r6,r9,30,30,31
    rlwimi  r3,r10,16,15,15
    subfic  r6,r6,1
    stw     r3,184(r7)
    cntlzw  r3,r6
    rlwinm  r6,r3,27,24,31
    lwz     r3,216(r7)
    rlwimi  r3,r6,16,15,15
    stw     r3,216(r7)
    stb     r5,-32768(r4)
    lwz     r3,184(r7)
    stw     r3,-32768(r4)
    stb     r5,-32768(r4)
    lwz     r3,216(r7)
    stw     r3,-32768(r4)
    sth     r0,2(r8)
    blr
.size __SetSURegs, . - __SetSURegs

#
# === GXTransform.o ===
#

.global __GXSetProjection
.balign 4
__GXSetProjection:
/* 0x803907C0 | size=0x48 (72 bytes) */
    lis     r4,-13311
    lwz     r3,-17720(r13)
    li      r0,16
    lis     r5,6
    stb     r0,-32768(r4)
    addi    r0,r5,4128
    stw     r0,-32768(r4)
    addi    r6,r4,-32768
    addi    r5,r3,1244
    psq_l   f2,0(r5),0,0
    psq_l   f1,8(r5),0,0
    psq_l   f0,16(r5),0,0
    psq_st  f2,0(r6),0,0
    psq_st  f1,0(r6),0,0
    psq_st  f0,0(r6),0,0
    lwz     r0,1240(r3)
    stw     r0,-32768(r4)
    blr
.size __GXSetProjection, . - __GXSetProjection

.global GXSetProjection
.balign 4
GXSetProjection:
/* 0x80390808 | size=0xA4 (164 bytes) */
    lwz     r5,-17720(r13)
    cmpwi   r4,1
    stw     r4,1240(r5)
    lfs     f0,0(r3)
    stfs    f0,1244(r5)
    lfs     f0,20(r3)
    stfs    f0,1252(r5)
    lfs     f0,40(r3)
    stfs    f0,1260(r5)
    lfs     f0,44(r3)
    stfs    f0,1264(r5)
    bne-    .L_8039084C
    lfs     f0,12(r3)
    stfs    f0,1248(r5)
    lfs     f0,28(r3)
    stfs    f0,1256(r5)
    b       .L_8039085C
.L_8039084C:
    lfs     f0,8(r3)
    stfs    f0,1248(r5)
    lfs     f0,24(r3)
    stfs    f0,1256(r5)
.L_8039085C:
    lis     r5,-13311
    lwz     r4,-17720(r13)
    li      r0,16
    lis     r3,6
    stb     r0,-32768(r5)
    addi    r0,r3,4128
    stw     r0,-32768(r5)
    addi    r6,r5,-32768
    addi    r3,r4,1244
    psq_l   f2,0(r3),0,0
    psq_l   f1,8(r3),0,0
    psq_l   f0,16(r3),0,0
    psq_st  f2,0(r6),0,0
    psq_st  f1,0(r6),0,0
    psq_st  f0,0(r6),0,0
    lwz     r3,1240(r4)
    li      r0,1
    stw     r3,-32768(r5)
    sth     r0,2(r4)
    blr
.size GXSetProjection, . - GXSetProjection

.global GXSetProjectionv
.balign 4
GXSetProjectionv:
/* 0x803908AC | size=0x8C (140 bytes) */
    lfs     f1,-17352(r13)
    lfs     f0,0(r3)
    fcmpu   cr0,f1,f0
    bne-    .L_803908C4
    li      r0,0
    b       .L_803908C8
.L_803908C4:
    li      r0,1
.L_803908C8:
    lwz     r5,-17720(r13)
    addi    r3,r3,4
    stw     r0,1240(r5)
    addi    r6,r5,1244
    psq_l   f2,0(r3),0,0
    psq_l   f1,8(r3),0,0
    psq_l   f0,16(r3),0,0
    psq_st  f2,0(r6),0,0
    psq_st  f1,8(r6),0,0
    psq_st  f0,16(r6),0,0
    lis     r4,-13311
    li      r0,16
    lis     r3,6
    stb     r0,-32768(r4)
    addi    r0,r3,4128
    stw     r0,-32768(r4)
    addi    r3,r4,-32768
    psq_l   f2,0(r6),0,0
    psq_l   f1,8(r6),0,0
    psq_l   f0,16(r6),0,0
    psq_st  f2,0(r3),0,0
    psq_st  f1,0(r3),0,0
    psq_st  f0,0(r3),0,0
    lwz     r3,1240(r5)
    li      r0,1
    stw     r3,-32768(r4)
    sth     r0,2(r5)
    blr
.size GXSetProjectionv, . - GXSetProjectionv

.global GXGetProjectionv
.balign 4
GXGetProjectionv:
/* 0x80390938 | size=0x48 (72 bytes) */
    lwz     r4,-17720(r13)
    lwz     r0,1240(r4)
    cmplwi  r0,0
    beq-    .L_80390950
    lfs     f0,-17348(r13)
    b       .L_80390954
.L_80390950:
    lfs     f0,-17352(r13)
.L_80390954:
    stfs    f0,0(r3)
    addi    r4,r3,4
    lwz     r3,-17720(r13)
    addi    r3,r3,1244
    psq_l   f2,0(r3),0,0
    psq_l   f1,8(r3),0,0
    psq_l   f0,16(r3),0,0
    psq_st  f2,0(r4),0,0
    psq_st  f1,8(r4),0,0
    psq_st  f0,16(r4),0,0
    blr
.size GXGetProjectionv, . - GXGetProjectionv

.global GXLoadPosMtxImm
.balign 4
GXLoadPosMtxImm:
/* 0x80390A38 | size=0x50 (80 bytes) */
    lis     r5,-13311
    li      r0,16
    slwi    r4,r4,2
    stb     r0,-32768(r5)
    oris    r0,r4,11
    stw     r0,-32768(r5)
    addi    r4,r5,-32768
    psq_l   f5,0(r3),0,0
    psq_l   f4,8(r3),0,0
    psq_l   f3,16(r3),0,0
    psq_l   f2,24(r3),0,0
    psq_l   f1,32(r3),0,0
    psq_l   f0,40(r3),0,0
    psq_st  f5,0(r4),0,0
    psq_st  f4,0(r4),0,0
    psq_st  f3,0(r4),0,0
    psq_st  f2,0(r4),0,0
    psq_st  f1,0(r4),0,0
    psq_st  f0,0(r4),0,0
    blr
.size GXLoadPosMtxImm, . - GXLoadPosMtxImm

.global GXLoadNrmMtxImm
.balign 4
GXLoadNrmMtxImm:
/* 0x80390AB8 | size=0x50 (80 bytes) */
    mulli   r5,r4,3
    lis     r4,-13311
    li      r0,16
    addi    r5,r5,1024
    stb     r0,-32768(r4)
    oris    r0,r5,8
    stwu    r0,-32768(r4)
    psq_l   f5,0(r3),0,0
    lfs     f4,8(r3)
    psq_l   f3,16(r3),0,0
    lfs     f2,24(r3)
    psq_l   f1,32(r3),0,0
    lfs     f0,40(r3)
    psq_st  f5,0(r4),0,0
    stfs    f4,0(r4)
    psq_st  f3,0(r4),0,0
    stfs    f2,0(r4)
    psq_st  f1,0(r4),0,0
    stfs    f0,0(r4)
    blr
.size GXLoadNrmMtxImm, . - GXLoadNrmMtxImm

.global GXLoadNrmMtxImm3x3
.balign 4
GXLoadNrmMtxImm3x3:
/* 0x80390B08 | size=0x48 (72 bytes) */
    mulli   r5,r4,3
    lis     r4,-13311
    li      r0,16
    addi    r5,r5,1024
    stb     r0,-32768(r4)
    oris    r0,r5,8
    stwu    r0,-32768(r4)
    psq_l   f4,0(r3),0,0
    psq_l   f3,8(r3),0,0
    psq_l   f2,16(r3),0,0
    psq_l   f1,24(r3),0,0
    lfs     f0,32(r3)
    psq_st  f4,0(r4),0,0
    psq_st  f3,0(r4),0,0
    psq_st  f2,0(r4),0,0
    psq_st  f1,0(r4),0,0
    stfs    f0,0(r4)
    blr
.size GXLoadNrmMtxImm3x3, . - GXLoadNrmMtxImm3x3

.global GXLoadTexMtxImm
.balign 4
GXLoadTexMtxImm:
/* 0x80390BB8 | size=0xB4 (180 bytes) */
    cmplwi  r4,64
    blt-    .L_80390BD0
    addi    r0,r4,-64
    slwi    r4,r0,2
    addi    r7,r4,1280
    b       .L_80390BD4
.L_80390BD0:
    slwi    r7,r4,2
.L_80390BD4:
    cmpwi   r5,1
    bne-    .L_80390BE4
    li      r4,8
    b       .L_80390BE8
.L_80390BE4:
    li      r4,12
.L_80390BE8:
    addi    r0,r4,-1
    slwi    r6,r0,16
    li      r0,16
    lis     r4,-13311
    stb     r0,-32768(r4)
    or      r0,r7,r6
    cmpwi   r5,0
    stw     r0,-32768(r4)
    bne-    .L_80390C44
    addi    r4,r4,-32768
    psq_l   f5,0(r3),0,0
    psq_l   f4,8(r3),0,0
    psq_l   f3,16(r3),0,0
    psq_l   f2,24(r3),0,0
    psq_l   f1,32(r3),0,0
    psq_l   f0,40(r3),0,0
    psq_st  f5,0(r4),0,0
    psq_st  f4,0(r4),0,0
    psq_st  f3,0(r4),0,0
    psq_st  f2,0(r4),0,0
    psq_st  f1,0(r4),0,0
    psq_st  f0,0(r4),0,0
    blr
.L_80390C44:
    addi    r4,r4,-32768
    psq_l   f3,0(r3),0,0
    psq_l   f2,8(r3),0,0
    psq_l   f1,16(r3),0,0
    psq_l   f0,24(r3),0,0
    psq_st  f3,0(r4),0,0
    psq_st  f2,0(r4),0,0
    psq_st  f1,0(r4),0,0
    psq_st  f0,0(r4),0,0
    blr
.size GXLoadTexMtxImm, . - GXLoadTexMtxImm

.global GXLoadTexMtxIndx
.balign 4
GXLoadTexMtxIndx:
/* 0x80390C6C | size=0x58 (88 bytes) */
    cmplwi  r4,64
    blt-    .L_80390C84
    addi    r0,r4,-64
    slwi    r4,r0,2
    addi    r0,r4,1280
    b       .L_80390C88
.L_80390C84:
    slwi    r0,r4,2
.L_80390C88:
    cmpwi   r5,1
    bne-    .L_80390C98
    li      r4,8
    b       .L_80390C9C
.L_80390C98:
    li      r4,12
.L_80390C9C:
    li      r5,0
    rlwimi  r5,r0,0,20,31
    addi    r0,r4,-1
    rlwimi  r5,r0,12,16,19
    li      r0,48
    lis     r4,-13311
    stb     r0,-32768(r4)
    rlwimi  r5,r3,16,0,15
    stw     r5,-32768(r4)
    blr
.size GXLoadTexMtxIndx, . - GXLoadTexMtxIndx

.global __GXSetViewport
.balign 4
__GXSetViewport:
/* 0x80390CC4 | size=0x90 (144 bytes) */
    lwz     r6,-17720(r13)
    lis     r3,5
    lfs     f1,-17344(r13)
    li      r5,16
    lfs     f3,1280(r6)
    lfs     f2,1276(r6)
    lis     r4,-13311
    fneg    f0,f3
    lfs     f5,1268(r6)
    fmuls   f7,f2,f1
    lfs     f4,1272(r6)
    addi    r0,r3,4122
    fmuls   f3,f3,f1
    lfs     f2,1288(r6)
    lfs     f6,1296(r6)
    fmuls   f8,f0,f1
    lfs     f1,1284(r6)
    lfs     f0,1292(r6)
    fmuls   f9,f2,f6
    fmuls   f1,f1,f6
    lfs     f6,-17340(r13)
    stb     r5,-32768(r4)
    fadds   f5,f5,f7
    stw     r0,-32768(r4)
    fadds   f2,f4,f3
    stfs    f7,-32768(r4)
    fsubs   f1,f9,f1
    fadds   f3,f6,f5
    stfs    f8,-32768(r4)
    fadds   f2,f6,f2
    stfs    f1,-32768(r4)
    fadds   f0,f9,f0
    stfs    f3,-32768(r4)
    stfs    f2,-32768(r4)
    stfs    f0,-32768(r4)
    blr
.size __GXSetViewport, . - __GXSetViewport

.global GXSetViewportJitter
.balign 4
GXSetViewportJitter:
/* 0x80390D54 | size=0x58 (88 bytes) */
    mflr    r0
    cmplwi  r3,0
    stw     r0,4(r1)
    stwu    r1,-8(r1)
    bne-    .L_80390D70
    lfs     f0,-17344(r13)
    fsubs   f2,f2,f0
.L_80390D70:
    lwz     r3,-17720(r13)
    stfs    f1,1268(r3)
    stfs    f2,1272(r3)
    stfs    f3,1276(r3)
    stfs    f4,1280(r3)
    stfs    f5,1284(r3)
    stfs    f6,1288(r3)
    bl      __GXSetViewport
    lwz     r3,-17720(r13)
    li      r0,1
    sth     r0,2(r3)
    lwz     r0,12(r1)
    addi    r1,r1,8
    mtlr    r0
    blr
.size GXSetViewportJitter, . - GXSetViewportJitter

.global GXSetViewport
.balign 4
GXSetViewport:
/* 0x80390DAC | size=0x48 (72 bytes) */
    mflr    r0
    stw     r0,4(r1)
    stwu    r1,-8(r1)
    lwz     r3,-17720(r13)
    stfs    f1,1268(r3)
    stfs    f2,1272(r3)
    stfs    f3,1276(r3)
    stfs    f4,1280(r3)
    stfs    f5,1284(r3)
    stfs    f6,1288(r3)
    bl      __GXSetViewport
    lwz     r3,-17720(r13)
    li      r0,1
    sth     r0,2(r3)
    lwz     r0,12(r1)
    addi    r1,r1,8
    mtlr    r0
    blr
.size GXSetViewport, . - GXSetViewport

.global GXSetZScaleOffset
.balign 4
GXSetZScaleOffset:
/* 0x80390E18 | size=0x6C (108 bytes) */
    lfs     f0,-17336(r13)
    li      r6,16
    lwz     r7,-17720(r13)
    lis     r5,-13311
    fmuls   f3,f0,f2
    fmuls   f0,f0,f1
    li      r4,4124
    li      r3,4127
    stfs    f3,1292(r7)
    li      r0,1
    lfs     f1,-17348(r13)
    fadds   f2,f1,f0
    stfs    f2,1296(r7)
    lfs     f1,1288(r7)
    lfs     f0,1284(r7)
    fmuls   f1,f1,f2
    fmuls   f0,f0,f2
    stb     r6,-32768(r5)
    stw     r4,-32768(r5)
    fadds   f3,f3,f1
    fsubs   f0,f1,f0
    stfs    f0,-32768(r5)
    stb     r6,-32768(r5)
    stw     r3,-32768(r5)
    stfs    f3,-32768(r5)
    sth     r0,2(r7)
    blr
.size GXSetZScaleOffset, . - GXSetZScaleOffset

.global GXSetScissor
.balign 4
GXSetScissor:
/* 0x80390E84 | size=0x78 (120 bytes) */
    lwz     r7,-17720(r13)
    addi    r4,r4,342
    addi    r6,r6,-1
    lwz     r0,248(r7)
    rlwimi  r0,r4,0,21,31
    addi    r3,r3,342
    stw     r0,248(r7)
    addi    r8,r5,-1
    add     r6,r4,r6
    lwz     r0,248(r7)
    rlwimi  r0,r3,12,9,19
    add     r8,r3,r8
    stw     r0,248(r7)
    li      r5,97
    lis     r4,-13311
    lwz     r3,252(r7)
    rlwimi  r3,r6,0,21,31
    li      r0,0
    stw     r3,252(r7)
    lwz     r3,252(r7)
    rlwimi  r3,r8,12,9,19
    stw     r3,252(r7)
    stb     r5,-32768(r4)
    lwz     r3,248(r7)
    stw     r3,-32768(r4)
    stb     r5,-32768(r4)
    lwz     r3,252(r7)
    stw     r3,-32768(r4)
    sth     r0,2(r7)
    blr
.size GXSetScissor, . - GXSetScissor

.global GXGetScissor
.balign 4
GXGetScissor:
/* 0x80390EFC | size=0x48 (72 bytes) */
    lwz     r8,-17720(r13)
    lwz     r7,248(r8)
    lwz     r8,252(r8)
    rlwinm  r9,r7,20,21,31
    addi    r0,r9,-342
    stw     r0,0(r3)
    clrlwi  r7,r7,21
    addi    r3,r7,-342
    stw     r3,0(r4)
    rlwinm  r0,r8,20,21,31
    subf    r3,r9,r0
    addi    r0,r3,1
    clrlwi  r4,r8,21
    stw     r0,0(r5)
    subf    r3,r7,r4
    addi    r0,r3,1
    stw     r0,0(r6)
    blr
.size GXGetScissor, . - GXGetScissor

.global __GXSetMatrixIndex
.balign 4
__GXSetMatrixIndex:
/* 0x80390FAC | size=0x84 (132 bytes) */
    cmpwi   r3,5
    bge-    .L_80390FEC
    li      r0,8
    lwz     r4,-17720(r13)
    lis     r5,-13311
    stb     r0,-32768(r5)
    li      r0,48
    li      r3,16
    stb     r0,-32768(r5)
    li      r0,4120
    lwz     r4,128(r4)
    stw     r4,-32768(r5)
    stb     r3,-32768(r5)
    stw     r0,-32768(r5)
    stw     r4,-32768(r5)
    b       .L_80391020
.L_80390FEC:
    li      r0,8
    lwz     r4,-17720(r13)
    lis     r5,-13311
    stb     r0,-32768(r5)
    li      r0,64
    li      r3,16
    stb     r0,-32768(r5)
    li      r0,4121
    lwz     r4,132(r4)
    stw     r4,-32768(r5)
    stb     r3,-32768(r5)
    stw     r0,-32768(r5)
    stw     r4,-32768(r5)
.L_80391020:
    lwz     r3,-17720(r13)
    li      r0,1
    sth     r0,2(r3)
    blr
.size __GXSetMatrixIndex, . - __GXSetMatrixIndex
