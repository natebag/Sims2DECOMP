# DolphinSDK os.a - Large functions (257-1024 bytes)
# Auto-generated from ELF disassembly
# Functions in the 257-1024 byte range

.section .text

#
# === OS.o (os.a) ===
#

.global __OSFPRInit
.balign 4
__OSFPRInit:
/* 0x8024B05C | size=0x128 (296 bytes) */
    mfmsr   r3
    ori     r3,r3,8192
    mtmsr   r3
    mfhid2  r3
    rlwinm. r3,r3,3,31,31
    beq-	.L_8024B0FC
    lis     r3,-32688
    addi    r3,r3,-904
    psq_l   f0,0(r3),0,0
    ps_mr   f1,f0
    ps_mr   f2,f0
    ps_mr   f3,f0
    ps_mr   f4,f0
    ps_mr   f5,f0
    ps_mr   f6,f0
    ps_mr   f7,f0
    ps_mr   f8,f0
    ps_mr   f9,f0
    ps_mr   f10,f0
    ps_mr   f11,f0
    ps_mr   f12,f0
    ps_mr   f13,f0
    ps_mr   f14,f0
    ps_mr   f15,f0
    ps_mr   f16,f0
    ps_mr   f17,f0
    ps_mr   f18,f0
    ps_mr   f19,f0
    ps_mr   f20,f0
    ps_mr   f21,f0
    ps_mr   f22,f0
    ps_mr   f23,f0
    ps_mr   f24,f0
    ps_mr   f25,f0
    ps_mr   f26,f0
    ps_mr   f27,f0
    ps_mr   f28,f0
    ps_mr   f29,f0
    ps_mr   f30,f0
    ps_mr   f31,f0
.L_8024B0FC:
    lfd     f0,-23728(r13)
    fmr     f1,f0
    fmr     f2,f0
    fmr     f3,f0
    fmr     f4,f0
    fmr     f5,f0
    fmr     f6,f0
    fmr     f7,f0
    fmr     f8,f0
    fmr     f9,f0
    fmr     f10,f0
    fmr     f11,f0
    fmr     f12,f0
    fmr     f13,f0
    fmr     f14,f0
    fmr     f15,f0
    fmr     f16,f0
    fmr     f17,f0
    fmr     f18,f0
    fmr     f19,f0
    fmr     f20,f0
    fmr     f21,f0
    fmr     f22,f0
    fmr     f23,f0
    fmr     f24,f0
    fmr     f25,f0
    fmr     f26,f0
    fmr     f27,f0
    fmr     f28,f0
    fmr     f29,f0
    fmr     f30,f0
    fmr     f31,f0
    mtfsf   255,f0
    blr
.size __OSFPRInit, . - __OSFPRInit

.global ClearArena
.balign 4
ClearArena:
/* 0x8024B1D4 | size=0x138 (312 bytes) */
    mflr    r0
    stw     r0,4(r1)
    stwu    r1,-16(r1)
    stw     r31,12(r1)
    stw     r30,8(r1)
    bl	OSGetResetCode
    clrrwi  r0,r3,31
    cmplwi  r0,0
    beq-	.L_8024B200
    li      r0,1
    b	.L_8024B204
.L_8024B200:
    li      r0,0
.L_8024B204:
    cmpwi   r0,0
    bne-	.L_8024B230
    bl	OSGetArenaHi
    mr      r30,r3
    bl	OSGetArenaLo
    subf    r30,r3,r30
    bl	OSGetArenaLo
    mr      r5,r30
    li      r4,0
    bl	memset
    b	.L_8024B2F4
.L_8024B230:
    lis     r3,-32694
    addi    r30,r3,-24816
    addi    r31,r30,12
    lwz     r0,0(r31)
    cmplwi  r0,0
    bne-	.L_8024B26C
    bl	OSGetArenaHi
    mr      r31,r3
    bl	OSGetArenaLo
    subf    r31,r3,r31
    bl	OSGetArenaLo
    mr      r5,r31
    li      r4,0
    bl	memset
    b	.L_8024B2F4
.L_8024B26C:
    bl	OSGetArenaLo
    lwz     r0,0(r31)
    cmplw   r3,r0
    bge-	.L_8024B2F4
    bl	OSGetArenaHi
    lwz     r0,0(r31)
    cmplw   r3,r0
    bgt-	.L_8024B2B0
    bl	OSGetArenaHi
    mr      r31,r3
    bl	OSGetArenaLo
    subf    r31,r3,r31
    bl	OSGetArenaLo
    mr      r5,r31
    li      r4,0
    bl	memset
    b	.L_8024B2F4
.L_8024B2B0:
    bl	OSGetArenaLo
    lwz     r0,0(r31)
    subf    r31,r3,r0
    bl	OSGetArenaLo
    mr      r5,r31
    li      r4,0
    bl	memset
    bl	OSGetArenaHi
    addi    r4,r30,16
    lwz     r30,0(r4)
    cmplw   r3,r30
    ble-	.L_8024B2F4
    bl	OSGetArenaHi
    subf    r5,r30,r3
    mr      r3,r30
    li      r4,0
    bl	memset
.L_8024B2F4:
    lwz     r0,20(r1)
    lwz     r31,12(r1)
    lwz     r30,8(r1)
    addi    r1,r1,16
    mtlr    r0
    blr
.size ClearArena, . - ClearArena

.global OSExceptionInit
.balign 4
OSExceptionInit:
/* 0x8024B828 | size=0x280 (640 bytes) */
    mflr    r0
    stw     r0,4(r1)
    stwu    r1,-56(r1)
    stmw    r20,8(r1)
    lis     r3,-32768
    lwz     r0,96(r3)
    lis     r4,-32731
    addi    r30,r4,-17560
    lis     r5,-32731
    lwz     r25,0(r30)
    lis     r4,-32731
    addi    r5,r5,-17664
    addi    r4,r4,-17512
    lis     r6,-32700
    cmplwi  r0,0
    mr      r24,r5
    addi    r29,r6,-21680
    subf    r23,r5,r4
    addi    r20,r3,96
    bne-	.L_8024B8C0
    addi    r3,r29,352
    crclr   4*cr1+eq
    bl	DBPrintf
    lis     r4,-32731
    lis     r3,-32731
    addi    r0,r3,-17716
    addi    r4,r4,-17752
    subf    r21,r4,r0
    mr      r3,r20
    mr      r5,r21
    bl	memcpy
    mr      r3,r20
    mr      r4,r21
    bl	DCFlushRangeNoSync
    sync
    mr      r3,r20
    mr      r4,r21
    bl	ICInvalidateRange
.L_8024B8C0:
    lis     r4,-32731
    lis     r3,-32731
    addi    r31,r4,-17716
    addi    r0,r3,-17712
    addi    r28,r29,292
    subf    r27,r31,r0
    li      r26,0
    b	.L_8024B8E0
.L_8024B8E0:
    lis     r3,-32731
    addi    r21,r3,-17576
    lis     r22,24576
    b	.L_8024B8F0
.L_8024B8F0:
    b	.L_8024BA38
.L_8024B8F4:
    lwz     r3,-23740(r13)
    cmplwi  r3,0
    beq-	.L_8024B930
    lwz     r0,0(r3)
    cmplwi  r0,2
    blt-	.L_8024B930
    mr      r3,r26
    bl	__DBIsExceptionMarked
    cmpwi   r3,0
    beq-	.L_8024B930
    addi    r3,r29,380
    crclr   4*cr1+eq
    clrlwi  r4,r26,24
    bl	DBPrintf
    b	.L_8024BA30
.L_8024B930:
    clrlwi  r20,r26,24
    or      r0,r25,r20
    stw     r0,0(r30)
    mr      r3,r26
    bl	__DBIsExceptionMarked
    cmpwi   r3,0
    beq-	.L_8024B970
    mr      r4,r20
    crclr   4*cr1+eq
    addi    r3,r29,428
    bl	DBPrintf
    mr      r3,r21
    mr      r4,r31
    mr      r5,r27
    bl	memcpy
    b	.L_8024B9FC
.L_8024B970:
    mr      r4,r21
    b	.L_8024B978
.L_8024B978:
    cmplwi  r27,0
    addi    r3,r27,3
    srwi    r3,r3,2
    ble-	.L_8024B9FC
    srwi    r0,r3,3
    cmplwi  r0,0
    mtctr   r0
    beq-	.L_8024B9E8
    b	.L_8024B99C
.L_8024B99C:
    stw     r22,0(r4)
    addi    r4,r4,4
    stw     r22,0(r4)
    addi    r4,r4,4
    stw     r22,0(r4)
    addi    r4,r4,4
    stw     r22,0(r4)
    addi    r4,r4,4
    stw     r22,0(r4)
    addi    r4,r4,4
    stw     r22,0(r4)
    addi    r4,r4,4
    stw     r22,0(r4)
    addi    r4,r4,4
    stw     r22,0(r4)
    addi    r4,r4,4
    bdnz+	.L_8024B99C
    andi.   r3,r3,7
    beq-	.L_8024B9FC
.L_8024B9E8:
    mtctr   r3
    b	.L_8024B9F0
.L_8024B9F0:
    stw     r22,0(r4)
    addi    r4,r4,4
    bdnz+	.L_8024B9F0
.L_8024B9FC:
    lwz     r3,0(r28)
    mr      r4,r24
    mr      r5,r23
    addis   r20,r3,-32768
    mr      r3,r20
    bl	memcpy
    mr      r3,r20
    mr      r4,r23
    bl	DCFlushRangeNoSync
    sync
    mr      r3,r20
    mr      r4,r23
    bl	ICInvalidateRange
.L_8024BA30:
    addi    r28,r28,4
    addi    r26,r26,1
.L_8024BA38:
    clrlwi  r0,r26,24
    cmplwi  r0,15
    blt+	.L_8024B8F4
    lis     r3,-32768
    addi    r0,r3,12288
    stw     r0,-23708(r13)
    li      r20,0
    b	.L_8024BA58
.L_8024BA58:
    lis     r3,-32731
    addi    r23,r3,-17508
    b	.L_8024BA64
.L_8024BA64:
    b	.L_8024BA78
.L_8024BA68:
    mr      r3,r20
    mr      r4,r23
    bl	__OSDBJUMPEND
    addi    r20,r20,1
.L_8024BA78:
    clrlwi  r0,r20,24
    cmplwi  r0,15
    blt+	.L_8024BA68
    stw     r25,0(r30)
    addi    r3,r29,476
    crclr   4*cr1+eq
    bl	DBPrintf
    lmw     r20,8(r1)
    lwz     r0,60(r1)
    addi    r1,r1,56
    mtlr    r0
    blr
.size OSExceptionInit, . - OSExceptionInit

#
# === OSAlarm.o (os.a) ===
#

.global OSCheckAlarmQueue
.balign 4
OSCheckAlarmQueue:
/* 0x8024BC88 | size=0x140 (320 bytes) */
    mflr    r0
    lis     r3,-32700
    stw     r0,4(r1)
    addi    r4,r3,-21176
    stwu    r1,-8(r1)
    lwz     r5,-23688(r13)
    cmplwi  r5,0
    bne-	.L_8024BCB8
    addi    r3,r13,-23688
    lwz     r0,4(r3)
    cmplwi  r0,0
    beq-	.L_8024BCE8
.L_8024BCB8:
    cmplwi  r5,0
    beq-	.L_8024BCD0
    addi    r3,r13,-23688
    lwz     r0,4(r3)
    cmplwi  r0,0
    bne-	.L_8024BCE8
.L_8024BCD0:
    addi    r3,r4,16
    crclr   4*cr1+eq
    li      r4,146
    bl	OSReport
    li      r3,0
    b	.L_8024BDB8
.L_8024BCE8:
    cmplwi  r5,0
    beq-	.L_8024BD14
    lwz     r0,16(r5)
    cmplwi  r0,0
    beq-	.L_8024BD14
    addi    r3,r4,156
    crclr   4*cr1+eq
    li      r4,147
    bl	OSReport
    li      r3,0
    b	.L_8024BDB8
.L_8024BD14:
    addi    r3,r13,-23688
    lwz     r3,4(r3)
    cmplwi  r3,0
    beq-	.L_8024BD48
    lwz     r0,20(r3)
    cmplwi  r0,0
    beq-	.L_8024BD48
    addi    r3,r4,248
    crclr   4*cr1+eq
    li      r4,148
    bl	OSReport
    li      r3,0
    b	.L_8024BDB8
.L_8024BD48:
    mr      r6,r5
    b	.L_8024BDAC
.L_8024BD50:
    lwz     r5,20(r6)
    cmplwi  r5,0
    beq-	.L_8024BD80
    lwz     r0,16(r5)
    cmplw   r0,r6
    beq-	.L_8024BD80
    addi    r3,r4,340
    crclr   4*cr1+eq
    li      r4,151
    bl	OSReport
    li      r3,0
    b	.L_8024BDB8
.L_8024BD80:
    cmplwi  r5,0
    bne-	.L_8024BDA8
    cmplw   r3,r6
    beq-	.L_8024BDA8
    addi    r3,r4,424
    crclr   4*cr1+eq
    li      r4,152
    bl	OSReport
    li      r3,0
    b	.L_8024BDB8
.L_8024BDA8:
    mr      r6,r5
.L_8024BDAC:
    cmplwi  r6,0
    bne+	.L_8024BD50
    li      r3,1
.L_8024BDB8:
    lwz     r0,12(r1)
    addi    r1,r1,8
    mtlr    r0
    blr
.size OSCheckAlarmQueue, . - OSCheckAlarmQueue

.global InsertAlarm
.balign 4
InsertAlarm:
/* 0x8024BEC8 | size=0x250 (592 bytes) */
    mflr    r0
    stw     r0,4(r1)
    stwu    r1,-64(r1)
    stmw    r25,36(r1)
    li      r28,0
    mr      r29,r3
    xoris   r4,r28,32768
    addi    r25,r5,0
    addi    r30,r6,0
    addi    r31,r7,0
    lwz     r0,24(r3)
    lwz     r8,28(r3)
    xoris   r3,r0,32768
    subfc   r0,r8,r28
    subfe   r3,r3,r4
    subfe   r3,r4,r4
    neg.    r3,r3
    beq-	.L_8024BF88
    bl	__OSGetSystemTime
    lwz     r7,32(r29)
    xoris   r5,r3,32768
    lwz     r8,36(r29)
    xoris   r6,r7,32768
    subfc   r0,r4,r8
    subfe   r5,r5,r6
    subfe   r5,r6,r6
    neg.    r5,r5
    addi    r30,r8,0
    addi    r25,r7,0
    beq-	.L_8024BF88
    lwz     r27,24(r29)
    subfc   r4,r8,r4
    lwz     r26,28(r29)
    subfe   r3,r7,r3
    addi    r5,r27,0
    addi    r6,r26,0
    bl	__div2i
    li      r0,1
    addc    r5,r4,r0
    mullw   r4,r27,r5
    mulhwu  r0,r26,r5
    adde    r3,r3,r28
    add     r4,r4,r0
    mullw   r0,r26,r3
    mullw   r3,r26,r5
    add     r0,r4,r0
    addc    r30,r30,r3
    adde    r25,r25,r0
.L_8024BF88:
    stw     r31,0(r29)
    xoris   r4,r25,32768
    stw     r30,12(r29)
    stw     r25,8(r29)
    lwz     r6,-23688(r13)
    b	.L_8024C060
.L_8024BFA0:
    lwz     r0,8(r6)
    lwz     r5,12(r6)
    xoris   r3,r0,32768
    subfc   r0,r5,r30
    subfe   r3,r3,r4
    subfe   r3,r4,r4
    neg.    r3,r3
    beq-	.L_8024C05C
    lwz     r0,16(r6)
    stw     r0,16(r29)
    stw     r29,16(r6)
    stw     r6,20(r29)
    lwz     r3,16(r29)
    cmplwi  r3,0
    beq-	.L_8024BFE4
    stw     r29,20(r3)
    b	.L_8024C104
.L_8024BFE4:
    stw     r29,-23688(r13)
    bl	__OSGetSystemTime
    lwz     r6,12(r29)
    li      r7,0
    lwz     r0,8(r29)
    xoris   r5,r7,32768
    subfc   r8,r4,r6
    subfe   r0,r3,r0
    xoris   r6,r0,32768
    subfc   r0,r7,r8
    subfe   r5,r5,r6
    subfe   r5,r6,r6
    neg.    r5,r5
    beq-	.L_8024C028
    li      r3,0
    bl	PPCMtdec
    b	.L_8024C104
.L_8024C028:
    lis     r4,-32768
    xoris   r3,r7,32768
    subfc   r0,r4,r8
    subfe   r3,r3,r6
    subfe   r3,r6,r6
    neg.    r3,r3
    beq-	.L_8024C050
    mr      r3,r8
    bl	PPCMtdec
    b	.L_8024C104
.L_8024C050:
    addi    r3,r4,-1
    bl	PPCMtdec
    b	.L_8024C104
.L_8024C05C:
    lwz     r6,20(r6)
.L_8024C060:
    cmplwi  r6,0
    bne+	.L_8024BFA0
    li      r30,0
    stw     r30,20(r29)
    addi    r3,r13,-23688
    lwz     r4,4(r3)
    stwu    r29,4(r3)
    cmplwi  r4,0
    stw     r4,16(r29)
    beq-	.L_8024C090
    stw     r29,20(r4)
    b	.L_8024C104
.L_8024C090:
    stw     r29,0(r3)
    stw     r29,-23688(r13)
    bl	__OSGetSystemTime
    lwz     r6,12(r29)
    xoris   r5,r30,32768
    lwz     r0,8(r29)
    subfc   r7,r4,r6
    subfe   r0,r3,r0
    xoris   r6,r0,32768
    subfc   r0,r30,r7
    subfe   r5,r5,r6
    subfe   r5,r6,r6
    neg.    r5,r5
    beq-	.L_8024C0D4
    li      r3,0
    bl	PPCMtdec
    b	.L_8024C104
.L_8024C0D4:
    lis     r4,-32768
    xoris   r3,r30,32768
    subfc   r0,r4,r7
    subfe   r3,r3,r6
    subfe   r3,r6,r6
    neg.    r3,r3
    beq-	.L_8024C0FC
    mr      r3,r7
    bl	PPCMtdec
    b	.L_8024C104
.L_8024C0FC:
    addi    r3,r4,-1
    bl	PPCMtdec
.L_8024C104:
    lmw     r25,36(r1)
    lwz     r0,68(r1)
    addi    r1,r1,64
    mtlr    r0
    blr
.size InsertAlarm, . - InsertAlarm

.global OSCancelAlarm
.balign 4
OSCancelAlarm:
/* 0x8024C26C | size=0x11C (284 bytes) */
    mflr    r0
    stw     r0,4(r1)
    stwu    r1,-32(r1)
    stw     r31,28(r1)
    stw     r30,24(r1)
    mr      r30,r3
    stw     r29,20(r1)
    bl	OSDisableInterrupts
    lwz     r0,0(r30)
    addi    r31,r3,0
    cmplwi  r0,0
    bne-	.L_8024C2A8
    mr      r3,r31
    bl	OSRestoreInterrupts
    b	.L_8024C36C
.L_8024C2A8:
    lwz     r29,20(r30)
    cmplwi  r29,0
    bne-	.L_8024C2C4
    lwz     r0,16(r30)
    addi    r3,r13,-23688
    stw     r0,4(r3)
    b	.L_8024C2CC
.L_8024C2C4:
    lwz     r0,16(r30)
    stw     r0,16(r29)
.L_8024C2CC:
    lwz     r3,16(r30)
    cmplwi  r3,0
    beq-	.L_8024C2E0
    stw     r29,20(r3)
    b	.L_8024C35C
.L_8024C2E0:
    cmplwi  r29,0
    stw     r29,-23688(r13)
    beq-	.L_8024C35C
    bl	__OSGetSystemTime
    lwz     r6,12(r29)
    li      r7,0
    lwz     r0,8(r29)
    xoris   r5,r7,32768
    subfc   r8,r4,r6
    subfe   r0,r3,r0
    xoris   r6,r0,32768
    subfc   r0,r7,r8
    subfe   r5,r5,r6
    subfe   r5,r6,r6
    neg.    r5,r5
    beq-	.L_8024C32C
    li      r3,0
    bl	PPCMtdec
    b	.L_8024C35C
.L_8024C32C:
    lis     r4,-32768
    xoris   r3,r7,32768
    subfc   r0,r4,r8
    subfe   r3,r3,r6
    subfe   r3,r6,r6
    neg.    r3,r3
    beq-	.L_8024C354
    mr      r3,r8
    bl	PPCMtdec
    b	.L_8024C35C
.L_8024C354:
    addi    r3,r4,-1
    bl	PPCMtdec
.L_8024C35C:
    li      r0,0
    stw     r0,0(r30)
    mr      r3,r31
    bl	OSRestoreInterrupts
.L_8024C36C:
    lwz     r0,36(r1)
    lwz     r31,28(r1)
    lwz     r30,24(r1)
    lwz     r29,20(r1)
    addi    r1,r1,32
    mtlr    r0
    blr
.size OSCancelAlarm, . - OSCancelAlarm

.global DecrementerExceptionCallback
.balign 4
DecrementerExceptionCallback:
/* 0x8024C388 | size=0x230 (560 bytes) */
    mflr    r0
    stw     r0,4(r1)
    stwu    r1,-752(r1)
    stw     r31,748(r1)
    stw     r30,744(r1)
    stw     r29,740(r1)
    mr      r29,r4
    stw     r28,736(r1)
    bl	__OSGetSystemTime
    lwz     r0,-23688(r13)
    addi    r28,r4,0
    addi    r30,r3,0
    cmplwi  r0,0
    mr      r31,r0
    bne-	.L_8024C3CC
    mr      r3,r29
    bl	OSLoadContext
.L_8024C3CC:
    lwz     r0,8(r31)
    xoris   r4,r30,32768
    lwz     r5,12(r31)
    xoris   r3,r0,32768
    subfc   r0,r5,r28
    subfe   r3,r3,r4
    subfe   r3,r4,r4
    neg.    r3,r3
    beq-	.L_8024C468
    bl	__OSGetSystemTime
    lwz     r6,12(r31)
    li      r7,0
    lwz     r0,8(r31)
    xoris   r5,r7,32768
    subfc   r8,r4,r6
    subfe   r0,r3,r0
    xoris   r6,r0,32768
    subfc   r0,r7,r8
    subfe   r5,r5,r6
    subfe   r5,r6,r6
    neg.    r5,r5
    beq-	.L_8024C430
    li      r3,0
    bl	PPCMtdec
    b	.L_8024C460
.L_8024C430:
    lis     r4,-32768
    xoris   r3,r7,32768
    subfc   r0,r4,r8
    subfe   r3,r3,r6
    subfe   r3,r6,r6
    neg.    r3,r3
    beq-	.L_8024C458
    mr      r3,r8
    bl	PPCMtdec
    b	.L_8024C460
.L_8024C458:
    addi    r3,r4,-1
    bl	PPCMtdec
.L_8024C460:
    mr      r3,r29
    bl	OSLoadContext
.L_8024C468:
    lwz     r3,20(r31)
    cmplwi  r3,0
    stw     r3,-23688(r13)
    bne-	.L_8024C488
    li      r0,0
    addi    r3,r13,-23688
    stw     r0,4(r3)
    b	.L_8024C490
.L_8024C488:
    li      r0,0
    stw     r0,16(r3)
.L_8024C490:
    lwz     r30,0(r31)
    li      r6,0
    xoris   r4,r6,32768
    stw     r6,0(r31)
    lwz     r0,24(r31)
    lwz     r5,28(r31)
    xoris   r3,r0,32768
    subfc   r0,r5,r6
    subfe   r3,r3,r4
    subfe   r3,r4,r4
    neg.    r3,r3
    beq-	.L_8024C4D4
    addi    r3,r31,0
    addi    r7,r30,0
    li      r6,0
    li      r5,0
    bl	InsertAlarm
.L_8024C4D4:
    lwz     r28,-23688(r13)
    cmplwi  r28,0
    beq-	.L_8024C550
    bl	__OSGetSystemTime
    lwz     r6,12(r28)
    li      r7,0
    lwz     r0,8(r28)
    xoris   r5,r7,32768
    subfc   r8,r4,r6
    subfe   r0,r3,r0
    xoris   r6,r0,32768
    subfc   r0,r7,r8
    subfe   r5,r5,r6
    subfe   r5,r6,r6
    neg.    r5,r5
    beq-	.L_8024C520
    li      r3,0
    bl	PPCMtdec
    b	.L_8024C550
.L_8024C520:
    lis     r4,-32768
    xoris   r3,r7,32768
    subfc   r0,r4,r8
    subfe   r3,r3,r6
    subfe   r3,r6,r6
    neg.    r3,r3
    beq-	.L_8024C548
    mr      r3,r8
    bl	PPCMtdec
    b	.L_8024C550
.L_8024C548:
    addi    r3,r4,-1
    bl	PPCMtdec
.L_8024C550:
    bl	OSDisableScheduler
    addi    r3,r1,24
    bl	OSClearContext
    addi    r3,r1,24
    bl	OSSetCurrentContext
    addi    r12,r30,0
    mtlr    r12
    addi    r3,r31,0
    addi    r4,r29,0
    blrl
    addi    r3,r1,24
    bl	OSClearContext
    mr      r3,r29
    bl	OSSetCurrentContext
    bl	OSEnableScheduler
    bl	__OSReschedule
    mr      r3,r29
    bl	OSLoadContext
    lwz     r0,756(r1)
    lwz     r31,748(r1)
    lwz     r30,744(r1)
    lwz     r29,740(r1)
    lwz     r28,736(r1)
    addi    r1,r1,752
    mtlr    r0
    blr
.size DecrementerExceptionCallback, . - DecrementerExceptionCallback

#
# === OSAudioSystem.o (os.a) ===
#

.global __OSInitAudioSystem
.balign 4
__OSInitAudioSystem:
/* 0x8024C7CC | size=0x1BC (444 bytes) */
    mflr    r0
    stw     r0,4(r1)
    stwu    r1,-48(r1)
    stmw    r25,20(r1)
    bl	OSGetArenaHi
    lis     r4,-32512
    li      r5,128
    addi    r3,r3,-128
    bl	memcpy
    lis     r3,-32700
    addi    r4,r3,-20672
    lis     r3,-32512
    li      r5,128
    bl	memcpy
    lis     r3,-32512
    li      r4,128
    bl	DCFlushRange
    lis     r3,-13312
    addi    r3,r3,20480
    li      r0,67
    sth     r0,18(r3)
    addi    r31,r3,10
    li      r0,2220
    sth     r0,10(r3)
    lhz     r0,10(r3)
    ori     r0,r0,1
    sth     r0,10(r3)
.L_8024C838:
    lhz     r0,0(r31)
    clrlwi. r0,r0,31
    bne+	.L_8024C838
    li      r0,0
    lis     r4,-13312
    sth     r0,20480(r4)
.L_8024C850:
    addi    r30,r4,20480
    lhzu    r3,4(r30)
    addi    r29,r4,20480
    lhzu    r0,6(r29)
    rlwimi  r0,r3,16,0,15
    clrrwi. r0,r0,31
    bne+	.L_8024C850
    lis     r3,-13312
    lis     r0,256
    addi    r27,r3,20480
    stwu    r0,32(r27)
    li      r0,0
    addi    r26,r3,20480
    stwu    r0,36(r26)
    li      r0,32
    addi    r25,r3,20480
    stwu    r0,40(r25)
    lhz     r3,0(r31)
    b	.L_8024C8A0
.L_8024C89C:
    lhz     r3,0(r31)
.L_8024C8A0:
    rlwinm. r0,r3,0,26,26
    beq+	.L_8024C89C
    sth     r3,0(r31)
    bl	OSGetTick
    mr      r28,r3
.L_8024C8B4:
    bl	OSGetTick
    subf    r0,r28,r3
    cmpwi   r0,2194
    blt+	.L_8024C8B4
    lis     r0,256
    stw     r0,0(r27)
    li      r3,0
    li      r0,32
    stw     r3,0(r26)
    stw     r0,0(r25)
    lhz     r3,0(r31)
    b	.L_8024C8E8
.L_8024C8E4:
    lhz     r3,0(r31)
.L_8024C8E8:
    rlwinm. r0,r3,0,26,26
    beq+	.L_8024C8E4
    sth     r3,0(r31)
    lhz     r0,0(r31)
    rlwinm  r0,r0,0,21,19
    sth     r0,0(r31)
.L_8024C900:
    lhz     r0,0(r31)
    rlwinm. r0,r0,0,21,21
    bne+	.L_8024C900
    lhz     r0,0(r31)
    rlwinm  r0,r0,0,30,28
    sth     r0,0(r31)
    lhz     r0,0(r30)
    b	.L_8024C924
.L_8024C920:
    lhz     r0,0(r30)
.L_8024C924:
    clrlwi  r5,r0,16
    rlwinm. r0,r0,0,16,16
    beq+	.L_8024C920
    lhz     r0,0(r31)
    lhz     r4,0(r29)
    ori     r0,r0,4
    sth     r0,0(r31)
    li      r0,2220
    sth     r0,0(r31)
    lhz     r0,0(r31)
    ori     r0,r0,1
    sth     r0,0(r31)
.L_8024C954:
    lhz     r0,0(r31)
    clrlwi. r0,r0,31
    bne+	.L_8024C954
    bl	OSGetArenaHi
    addi    r4,r3,-128
    lis     r3,-32512
    li      r5,128
    bl	memcpy
    lmw     r25,20(r1)
    lwz     r0,52(r1)
    addi    r1,r1,48
    mtlr    r0
    blr
.size __OSInitAudioSystem, . - __OSInitAudioSystem

#
# === OSCache.o (os.a) ===
#

.global DMAErrorHandler
.balign 4
DMAErrorHandler:
/* 0x8024D2E8 | size=0x160 (352 bytes) */
    mflr    r0
    stw     r0,4(r1)
    stwu    r1,-128(r1)
    stw     r31,124(r1)
    stw     r30,120(r1)
    stw     r29,116(r1)
    bne-	cr1,.L_8024D324
    stfd    f1,40(r1)
    stfd    f2,48(r1)
    stfd    f3,56(r1)
    stfd    f4,64(r1)
    stfd    f5,72(r1)
    stfd    f6,80(r1)
    stfd    f7,88(r1)
    stfd    f8,96(r1)
.L_8024D324:
    stw     r3,8(r1)
    stw     r4,12(r1)
    stw     r5,16(r1)
    stw     r6,20(r1)
    stw     r7,24(r1)
    stw     r8,28(r1)
    stw     r9,32(r1)
    stw     r10,36(r1)
    mr      r29,r4
    lis     r3,-32700
    addi    r31,r3,-20544
    bl	PPCMfhid2
    mr      r30,r3
    crclr   4*cr1+eq
    addi    r3,r31,44
    bl	OSReport
    lwz     r5,412(r29)
    mr      r4,r30
    addi    r3,r31,68
    crclr   4*cr1+eq
    bl	OSReport
    rlwinm  r0,r30,0,8,11
    cmplwi  r0,0
    beq-	.L_8024D394
    lwz     r0,412(r29)
    rlwinm  r0,r0,0,10,10
    cmplwi  r0,0
    bne-	.L_8024D3AC
.L_8024D394:
    addi    r3,r31,96
    crclr   4*cr1+eq
    bl	OSReport
    mr      r3,r29
    bl	OSDumpContext
    bl	PPCHalt
.L_8024D3AC:
    addi    r3,r31,144
    crclr   4*cr1+eq
    bl	OSReport
    addi    r3,r31,204
    crclr   4*cr1+eq
    bl	OSReport
    rlwinm  r0,r30,0,8,8
    cmplwi  r0,0
    beq-	.L_8024D3DC
    addi    r3,r31,260
    crclr   4*cr1+eq
    bl	OSReport
.L_8024D3DC:
    rlwinm  r0,r30,0,9,9
    cmplwi  r0,0
    beq-	.L_8024D3F4
    addi    r3,r31,324
    crclr   4*cr1+eq
    bl	OSReport
.L_8024D3F4:
    rlwinm  r0,r30,0,10,10
    cmplwi  r0,0
    beq-	.L_8024D40C
    addi    r3,r31,368
    crclr   4*cr1+eq
    bl	OSReport
.L_8024D40C:
    rlwinm  r0,r30,0,11,11
    cmplwi  r0,0
    beq-	.L_8024D424
    addi    r3,r31,400
    crclr   4*cr1+eq
    bl	OSReport
.L_8024D424:
    mr      r3,r30
    bl	PPCMthid2
    lwz     r0,132(r1)
    lwz     r31,124(r1)
    lwz     r30,120(r1)
    lwz     r29,116(r1)
    addi    r1,r1,128
    mtlr    r0
    blr
.size DMAErrorHandler, . - DMAErrorHandler

#
# === OSContext.o (os.a) ===
#

.global __OSLoadFPUContext
.balign 4
__OSLoadFPUContext:
/* 0x8024D53C | size=0x124 (292 bytes) */
    lhz     r5,418(r4)
    clrlwi. r5,r5,31
    beq-	.L_8024D65C
    lfd     f0,400(r4)
    mtfsf   255,f0
    mfhid2  r5
    rlwinm. r5,r5,3,31,31
    beq-	.L_8024D5DC
    psq_l   f0,456(r4),0,0
    psq_l   f1,464(r4),0,0
    psq_l   f2,472(r4),0,0
    psq_l   f3,480(r4),0,0
    psq_l   f4,488(r4),0,0
    psq_l   f5,496(r4),0,0
    psq_l   f6,504(r4),0,0
    psq_l   f7,512(r4),0,0
    psq_l   f8,520(r4),0,0
    psq_l   f9,528(r4),0,0
    psq_l   f10,536(r4),0,0
    psq_l   f11,544(r4),0,0
    psq_l   f12,552(r4),0,0
    psq_l   f13,560(r4),0,0
    psq_l   f14,568(r4),0,0
    psq_l   f15,576(r4),0,0
    psq_l   f16,584(r4),0,0
    psq_l   f17,592(r4),0,0
    psq_l   f18,600(r4),0,0
    psq_l   f19,608(r4),0,0
    psq_l   f20,616(r4),0,0
    psq_l   f21,624(r4),0,0
    psq_l   f22,632(r4),0,0
    psq_l   f23,640(r4),0,0
    psq_l   f24,648(r4),0,0
    psq_l   f25,656(r4),0,0
    psq_l   f26,664(r4),0,0
    psq_l   f27,672(r4),0,0
    psq_l   f28,680(r4),0,0
    psq_l   f29,688(r4),0,0
    psq_l   f30,696(r4),0,0
    psq_l   f31,704(r4),0,0
.L_8024D5DC:
    lfd     f0,144(r4)
    lfd     f1,152(r4)
    lfd     f2,160(r4)
    lfd     f3,168(r4)
    lfd     f4,176(r4)
    lfd     f5,184(r4)
    lfd     f6,192(r4)
    lfd     f7,200(r4)
    lfd     f8,208(r4)
    lfd     f9,216(r4)
    lfd     f10,224(r4)
    lfd     f11,232(r4)
    lfd     f12,240(r4)
    lfd     f13,248(r4)
    lfd     f14,256(r4)
    lfd     f15,264(r4)
    lfd     f16,272(r4)
    lfd     f17,280(r4)
    lfd     f18,288(r4)
    lfd     f19,296(r4)
    lfd     f20,304(r4)
    lfd     f21,312(r4)
    lfd     f22,320(r4)
    lfd     f23,328(r4)
    lfd     f24,336(r4)
    lfd     f25,344(r4)
    lfd     f26,352(r4)
    lfd     f27,360(r4)
    lfd     f28,368(r4)
    lfd     f29,376(r4)
    lfd     f30,384(r4)
    lfd     f31,392(r4)
.L_8024D65C:
    blr
.size __OSLoadFPUContext, . - __OSLoadFPUContext

.global __OSSaveFPUContext
.balign 4
__OSSaveFPUContext:
/* 0x8024D660 | size=0x128 (296 bytes) */
    lhz     r3,418(r5)
    ori     r3,r3,1
    sth     r3,418(r5)
    stfd    f0,144(r5)
    stfd    f1,152(r5)
    stfd    f2,160(r5)
    stfd    f3,168(r5)
    stfd    f4,176(r5)
    stfd    f5,184(r5)
    stfd    f6,192(r5)
    stfd    f7,200(r5)
    stfd    f8,208(r5)
    stfd    f9,216(r5)
    stfd    f10,224(r5)
    stfd    f11,232(r5)
    stfd    f12,240(r5)
    stfd    f13,248(r5)
    stfd    f14,256(r5)
    stfd    f15,264(r5)
    stfd    f16,272(r5)
    stfd    f17,280(r5)
    stfd    f18,288(r5)
    stfd    f19,296(r5)
    stfd    f20,304(r5)
    stfd    f21,312(r5)
    stfd    f22,320(r5)
    stfd    f23,328(r5)
    stfd    f24,336(r5)
    stfd    f25,344(r5)
    stfd    f26,352(r5)
    stfd    f27,360(r5)
    stfd    f28,368(r5)
    stfd    f29,376(r5)
    stfd    f30,384(r5)
    stfd    f31,392(r5)
    mffs    f0
    stfd    f0,400(r5)
    lfd     f0,144(r5)
    mfhid2  r3
    rlwinm. r3,r3,3,31,31
    beq-	.L_8024D784
    psq_st  f0,456(r5),0,0
    psq_st  f1,464(r5),0,0
    psq_st  f2,472(r5),0,0
    psq_st  f3,480(r5),0,0
    psq_st  f4,488(r5),0,0
    psq_st  f5,496(r5),0,0
    psq_st  f6,504(r5),0,0
    psq_st  f7,512(r5),0,0
    psq_st  f8,520(r5),0,0
    psq_st  f9,528(r5),0,0
    psq_st  f10,536(r5),0,0
    psq_st  f11,544(r5),0,0
    psq_st  f12,552(r5),0,0
    psq_st  f13,560(r5),0,0
    psq_st  f14,568(r5),0,0
    psq_st  f15,576(r5),0,0
    psq_st  f16,584(r5),0,0
    psq_st  f17,592(r5),0,0
    psq_st  f18,600(r5),0,0
    psq_st  f19,608(r5),0,0
    psq_st  f20,616(r5),0,0
    psq_st  f21,624(r5),0,0
    psq_st  f22,632(r5),0,0
    psq_st  f23,640(r5),0,0
    psq_st  f24,648(r5),0,0
    psq_st  f25,656(r5),0,0
    psq_st  f26,664(r5),0,0
    psq_st  f27,672(r5),0,0
    psq_st  f28,680(r5),0,0
    psq_st  f29,688(r5),0,0
    psq_st  f30,696(r5),0,0
    psq_st  f31,704(r5),0,0
.L_8024D784:
    blr
.size __OSSaveFPUContext, . - __OSSaveFPUContext

.global OSDumpContext
.balign 4
OSDumpContext:
/* 0x8024DA80 | size=0x2A8 (680 bytes) */
    mflr    r0
    stw     r0,4(r1)
    stwu    r1,-760(r1)
    stmw    r25,732(r1)
    mr      r28,r3
    lis     r3,-32700
    crclr   4*cr1+eq
    addi    r31,r3,-19984
    mr      r3,r31
    mr      r4,r28
    bl	OSReport
    li      r25,0
    slwi    r0,r25,2
    add     r27,r28,r0
    b	.L_8024DABC
.L_8024DABC:
    b	.L_8024DAC0
.L_8024DAC0:
    b	.L_8024DAC4
.L_8024DAC4:
    lwz     r8,64(r27)
    mr      r4,r25
    lwz     r5,0(r27)
    addi    r3,r31,68
    crclr   4*cr1+eq
    mr      r6,r5
    mr      r9,r8
    addi    r7,r25,16
    bl	OSReport
    addi    r27,r27,4
    addi    r25,r25,1
    cmplwi  r25,16
    blt+	.L_8024DAC4
    lwz     r4,132(r28)
    addi    r3,r31,116
    lwz     r5,128(r28)
    crclr   4*cr1+eq
    bl	OSReport
    lwz     r4,408(r28)
    addi    r3,r31,164
    lwz     r5,412(r28)
    crclr   4*cr1+eq
    bl	OSReport
    addi    r3,r31,212
    crclr   4*cr1+eq
    bl	OSReport
    li      r25,0
    slwi    r0,r25,2
    add     r27,r28,r0
    b	.L_8024DB3C
.L_8024DB3C:
    b	.L_8024DB40
.L_8024DB40:
    b	.L_8024DB44
.L_8024DB44:
    lwz     r5,420(r27)
    mr      r4,r25
    lwz     r7,436(r27)
    addi    r3,r31,232
    addi    r6,r25,4
    crclr   4*cr1+eq
    bl	OSReport
    addi    r27,r27,4
    addi    r25,r25,1
    cmplwi  r25,4
    blt+	.L_8024DB44
    lhz     r0,418(r28)
    clrlwi  r0,r0,31
    cmplwi  r0,0
    beq-	.L_8024DCB8
    bl	OSDisableInterrupts
    lis     r6,-32768
    lwz     r0,212(r6)
    li      r5,0
    addi    r4,r1,16
    sth     r5,432(r1)
    mr      r30,r0
    mr      r29,r3
    sth     r5,434(r1)
    lwz     r0,216(r6)
    cmplw   r4,r0
    bne-	.L_8024DBB4
    stw     r5,216(r6)
.L_8024DBB4:
    addi    r3,r1,16
    bl	OSSetCurrentContext
    addi    r3,r31,268
    crclr   4*cr1+eq
    bl	OSReport
    li      r25,0
    slwi    r0,r25,3
    add     r26,r28,r0
    b	.L_8024DBD8
.L_8024DBD8:
    b	.L_8024DBDC
.L_8024DBDC:
    b	.L_8024DBE0
.L_8024DBE0:
    lfd     f1,152(r26)
    bl	__cvt_fp2unsigned
    mr      r27,r3
    lfd     f1,144(r26)
    bl	__cvt_fp2unsigned
    mr      r5,r3
    crclr   4*cr1+eq
    mr      r4,r25
    mr      r7,r27
    addi    r3,r31,288
    addi    r6,r25,1
    bl	OSReport
    addi    r26,r26,16
    addi    r25,r25,2
    cmplwi  r25,32
    blt+	.L_8024DBE0
    addi    r3,r31,316
    crclr   4*cr1+eq
    bl	OSReport
    li      r25,0
    slwi    r0,r25,3
    add     r26,r28,r0
    b	.L_8024DC3C
.L_8024DC3C:
    b	.L_8024DC40
.L_8024DC40:
    b	.L_8024DC44
.L_8024DC44:
    lfd     f1,464(r26)
    bl	__cvt_fp2unsigned
    mr      r27,r3
    lfd     f1,456(r26)
    bl	__cvt_fp2unsigned
    mr      r5,r3
    crclr   4*cr1+eq
    mr      r4,r25
    mr      r7,r27
    addi    r3,r31,336
    addi    r6,r25,1
    bl	OSReport
    addi    r26,r26,16
    addi    r25,r25,2
    cmplwi  r25,32
    blt+	.L_8024DC44
    li      r5,0
    sth     r5,432(r1)
    lis     r3,-32768
    addi    r4,r1,16
    sth     r5,434(r1)
    lwz     r0,216(r3)
    cmplw   r4,r0
    bne-	.L_8024DCA8
    stw     r5,216(r3)
.L_8024DCA8:
    mr      r3,r30
    bl	OSSetCurrentContext
    mr      r3,r29
    bl	OSRestoreInterrupts
.L_8024DCB8:
    addi    r3,r31,368
    crclr   4*cr1+eq
    bl	OSReport
    lwz     r25,4(r28)
    li      r26,0
    b	.L_8024DCD0
.L_8024DCD0:
    b	.L_8024DCD4
.L_8024DCD4:
    b	.L_8024DCF4
.L_8024DCD8:
    lwz     r5,0(r25)
    mr      r4,r25
    lwz     r6,4(r25)
    addi    r3,r31,408
    crclr   4*cr1+eq
    bl	OSReport
    lwz     r25,0(r25)
.L_8024DCF4:
    cmplwi  r25,0
    beq-	.L_8024DD14
    addis   r0,r25,1
    cmplwi  r0,65535
    beq-	.L_8024DD14
    cmplwi  r26,16
    addi    r26,r26,1
    blt+	.L_8024DCD8
.L_8024DD14:
    lmw     r25,732(r1)
    lwz     r0,764(r1)
    addi    r1,r1,760
    mtlr    r0
    blr
.size OSDumpContext, . - OSDumpContext

.global OSFillFPUContext
.balign 4
OSFillFPUContext:
/* 0x8024DDF4 | size=0x12C (300 bytes) */
    mfmsr   r5
    ori     r5,r5,8192
    mtmsr   r5
    isync
    stfd    f0,144(r3)
    stfd    f1,152(r3)
    stfd    f2,160(r3)
    stfd    f3,168(r3)
    stfd    f4,176(r3)
    stfd    f5,184(r3)
    stfd    f6,192(r3)
    stfd    f7,200(r3)
    stfd    f8,208(r3)
    stfd    f9,216(r3)
    stfd    f10,224(r3)
    stfd    f11,232(r3)
    stfd    f12,240(r3)
    stfd    f13,248(r3)
    stfd    f14,256(r3)
    stfd    f15,264(r3)
    stfd    f16,272(r3)
    stfd    f17,280(r3)
    stfd    f18,288(r3)
    stfd    f19,296(r3)
    stfd    f20,304(r3)
    stfd    f21,312(r3)
    stfd    f22,320(r3)
    stfd    f23,328(r3)
    stfd    f24,336(r3)
    stfd    f25,344(r3)
    stfd    f26,352(r3)
    stfd    f27,360(r3)
    stfd    f28,368(r3)
    stfd    f29,376(r3)
    stfd    f30,384(r3)
    stfd    f31,392(r3)
    mffs    f0
    stfd    f0,400(r3)
    lfd     f0,144(r3)
    mfhid2  r5
    rlwinm. r5,r5,3,31,31
    beq-	.L_8024DF1C
    psq_st  f0,456(r3),0,0
    psq_st  f1,464(r3),0,0
    psq_st  f2,472(r3),0,0
    psq_st  f3,480(r3),0,0
    psq_st  f4,488(r3),0,0
    psq_st  f5,496(r3),0,0
    psq_st  f6,504(r3),0,0
    psq_st  f7,512(r3),0,0
    psq_st  f8,520(r3),0,0
    psq_st  f9,528(r3),0,0
    psq_st  f10,536(r3),0,0
    psq_st  f11,544(r3),0,0
    psq_st  f12,552(r3),0,0
    psq_st  f13,560(r3),0,0
    psq_st  f14,568(r3),0,0
    psq_st  f15,576(r3),0,0
    psq_st  f16,584(r3),0,0
    psq_st  f17,592(r3),0,0
    psq_st  f18,600(r3),0,0
    psq_st  f19,608(r3),0,0
    psq_st  f20,616(r3),0,0
    psq_st  f21,624(r3),0,0
    psq_st  f22,632(r3),0,0
    psq_st  f23,640(r3),0,0
    psq_st  f24,648(r3),0,0
    psq_st  f25,656(r3),0,0
    psq_st  f26,664(r3),0,0
    psq_st  f27,672(r3),0,0
    psq_st  f28,680(r3),0,0
    psq_st  f29,688(r3),0,0
    psq_st  f30,696(r3),0,0
    psq_st  f31,704(r3),0,0
.L_8024DF1C:
    blr
.size OSFillFPUContext, . - OSFillFPUContext

#
# === OSError.o (os.a) ===
#

.global OSPanic
.balign 4
OSPanic:
/* 0x8024DFC0 | size=0x12C (300 bytes) */
    mflr    r0
    stw     r0,4(r1)
    stwu    r1,-144(r1)
    stw     r31,140(r1)
    stw     r30,136(r1)
    stw     r29,132(r1)
    stw     r28,128(r1)
    bne-	cr1,.L_8024E000
    stfd    f1,40(r1)
    stfd    f2,48(r1)
    stfd    f3,56(r1)
    stfd    f4,64(r1)
    stfd    f5,72(r1)
    stfd    f6,80(r1)
    stfd    f7,88(r1)
    stfd    f8,96(r1)
.L_8024E000:
    stw     r3,8(r1)
    addi    r28,r3,0
    addi    r30,r4,0
    stw     r4,12(r1)
    addi    r29,r5,0
    stw     r5,16(r1)
    stw     r6,20(r1)
    lis     r6,-32700
    addi    r31,r6,-19512
    stw     r7,24(r1)
    stw     r8,28(r1)
    stw     r9,32(r1)
    stw     r10,36(r1)
    bl	OSDisableInterrupts
    lis     r0,768
    stw     r0,116(r1)
    addi    r0,r1,152
    addi    r4,r1,116
    stw     r0,120(r1)
    addi    r0,r1,8
    addi    r3,r29,0
    stw     r0,124(r1)
    bl	vprintf
    addi    r3,r31,0
    crclr   4*cr1+eq
    addi    r4,r28,0
    addi    r5,r30,0
    bl	OSReport
    addi    r3,r31,24
    crclr   4*cr1+eq
    bl	OSReport
    li      r30,0
    bl	OSGetStackPointer
    mr      r29,r3
    b	.L_8024E0A8
.L_8024E08C:
    lwz     r5,0(r29)
    mr      r4,r29
    lwz     r6,4(r29)
    addi    r3,r31,64
    crclr   4*cr1+eq
    bl	OSReport
    lwz     r29,0(r29)
.L_8024E0A8:
    cmplwi  r29,0
    beq-	.L_8024E0C8
    addis   r0,r29,1
    cmplwi  r0,65535
    beq-	.L_8024E0C8
    cmplwi  r30,16
    addi    r30,r30,1
    blt+	.L_8024E08C
.L_8024E0C8:
    bl	PPCHalt
    lwz     r0,148(r1)
    lwz     r31,140(r1)
    lwz     r30,136(r1)
    lwz     r29,132(r1)
    lwz     r28,128(r1)
    addi    r1,r1,144
    mtlr    r0
    blr
.size OSPanic, . - OSPanic

.global OSSetErrorHandler
.balign 4
OSSetErrorHandler:
/* 0x8024E0EC | size=0x218 (536 bytes) */
    mflr    r0
    stw     r0,4(r1)
    stwu    r1,-48(r1)
    stw     r31,44(r1)
    stw     r30,40(r1)
    stw     r29,36(r1)
    addi    r29,r3,0
    stw     r28,32(r1)
    addi    r28,r4,0
    bl	OSDisableInterrupts
    lis     r4,-32694
    rlwinm  r5,r29,2,14,29
    addi    r0,r4,-24784
    clrlwi  r6,r29,16
    add     r4,r0,r5
    lwz     r30,0(r4)
    cmplwi  r6,16
    mr      r29,r3
    stw     r28,0(r4)
    bne-	.L_8024E2D8
    bl	PPCMfmsr
    addi    r31,r3,0
    ori     r3,r31,8192
    bl	PPCMtmsr
    bl	PPCMffpscr
    cmplwi  r28,0
    beq-	.L_8024E26C
    lis     r5,-32768
    lis     r4,24582
    lwz     r6,220(r5)
    addi    r4,r4,-1793
    b	.L_8024E250
.L_8024E16C:
    lwz     r0,412(r6)
    ori     r0,r0,2304
    stw     r0,412(r6)
    lhz     r5,418(r6)
    clrlwi. r0,r5,31
    bne-	.L_8024E22C
    ori     r5,r5,1
    li      r0,4
    sth     r5,418(r6)
    mtctr   r0
    addi    r5,r6,0
.L_8024E198:
    li      r0,-1
    stw     r0,148(r5)
    stw     r0,144(r5)
    stw     r0,460(r5)
    stw     r0,456(r5)
    stw     r0,156(r5)
    stw     r0,152(r5)
    stw     r0,468(r5)
    stw     r0,464(r5)
    stw     r0,164(r5)
    stw     r0,160(r5)
    stw     r0,476(r5)
    stw     r0,472(r5)
    stw     r0,172(r5)
    stw     r0,168(r5)
    stw     r0,484(r5)
    stw     r0,480(r5)
    stw     r0,180(r5)
    stw     r0,176(r5)
    stw     r0,492(r5)
    stw     r0,488(r5)
    stw     r0,188(r5)
    stw     r0,184(r5)
    stw     r0,500(r5)
    stw     r0,496(r5)
    stw     r0,196(r5)
    stw     r0,192(r5)
    stw     r0,508(r5)
    stw     r0,504(r5)
    stw     r0,204(r5)
    stw     r0,200(r5)
    stw     r0,516(r5)
    stw     r0,512(r5)
    addi    r5,r5,64
    bdnz+	.L_8024E198
    li      r0,4
    stw     r0,404(r6)
.L_8024E22C:
    lwz     r0,-27912(r13)
    lwz     r5,404(r6)
    rlwinm  r0,r0,0,24,28
    or      r0,r5,r0
    stw     r0,404(r6)
    lwz     r0,404(r6)
    and     r0,r0,r4
    stw     r0,404(r6)
    lwz     r6,764(r6)
.L_8024E250:
    cmplwi  r6,0
    bne+	.L_8024E16C
    lwz     r0,-27912(r13)
    ori     r31,r31,2304
    rlwinm  r0,r0,0,24,28
    or      r3,r3,r0
    b	.L_8024E2C0
.L_8024E26C:
    lis     r5,-32768
    lis     r4,24582
    lwz     r6,220(r5)
    addi    r4,r4,-1793
    li      r5,-2305
    b	.L_8024E2AC
.L_8024E284:
    lwz     r0,412(r6)
    and     r0,r0,r5
    stw     r0,412(r6)
    lwz     r0,404(r6)
    rlwinm  r0,r0,0,29,23
    stw     r0,404(r6)
    lwz     r0,404(r6)
    and     r0,r0,r4
    stw     r0,404(r6)
    lwz     r6,764(r6)
.L_8024E2AC:
    cmplwi  r6,0
    bne+	.L_8024E284
    li      r0,-2305
    rlwinm  r3,r3,0,29,23
    and     r31,r31,r0
.L_8024E2C0:
    lis     r4,24582
    addi    r0,r4,-1793
    and     r3,r3,r0
    bl	PPCMtfpscr
    mr      r3,r31
    bl	PPCMtmsr
.L_8024E2D8:
    mr      r3,r29
    bl	OSRestoreInterrupts
    mr      r3,r30
    lwz     r0,52(r1)
    lwz     r31,44(r1)
    lwz     r30,40(r1)
    lwz     r29,36(r1)
    lwz     r28,32(r1)
    addi    r1,r1,48
    mtlr    r0
    blr
.size OSSetErrorHandler, . - OSSetErrorHandler

.global __OSUnhandledException
.balign 4
__OSUnhandledException:
/* 0x8024E304 | size=0x2E8 (744 bytes) */
    mflr    r0
    lis     r8,-32694
    stw     r0,4(r1)
    lis     r7,-32700
    stwu    r1,-64(r1)
    stmw    r22,24(r1)
    addi    r24,r3,0
    addi    r25,r4,0
    addi    r26,r5,0
    addi    r27,r6,0
    addi    r30,r8,-24784
    addi    r31,r7,-19512
    bl	OSGetTime
    lwz     r5,412(r25)
    addi    r28,r4,0
    addi    r29,r3,0
    rlwinm. r0,r5,0,30,30
    bne-	.L_8024E360
    addi    r3,r31,92
    crclr   4*cr1+eq
    clrlwi  r4,r24,24
    bl	OSReport
    b	.L_8024E4B0
.L_8024E360:
    clrlwi  r0,r24,24
    cmplwi  r0,6
    bne-	.L_8024E440
    rlwinm. r0,r5,0,11,11
    beq-	.L_8024E440
    lwz     r0,64(r30)
    cmplwi  r0,0
    beq-	.L_8024E440
    li      r24,16
    bl	PPCMfmsr
    addi    r23,r3,0
    ori     r3,r23,8192
    bl	PPCMtmsr
    lis     r3,-32768
    lwz     r3,216(r3)
    cmplwi  r3,0
    beq-	.L_8024E3A8
    bl	OSSaveFPUContext
.L_8024E3A8:
    bl	PPCMffpscr
    lis     r4,24582
    addi    r22,r4,-1793
    and     r3,r3,r22
    bl	PPCMtfpscr
    mr      r3,r23
    bl	PPCMtmsr
    lis     r23,-32768
    lwz     r0,216(r23)
    cmplw   r0,r25
    bne-	.L_8024E424
    bl	OSDisableScheduler
    lwz     r12,64(r30)
    addi    r4,r25,0
    addi    r5,r26,0
    crclr   4*cr1+eq
    mtlr    r12
    addi    r6,r27,0
    li      r3,16
    blrl
    lwz     r3,412(r25)
    li      r0,0
    rlwinm  r3,r3,0,19,17
    stw     r3,412(r25)
    stw     r0,216(r23)
    lwz     r0,404(r25)
    and     r0,r0,r22
    stw     r0,404(r25)
    bl	OSEnableScheduler
    bl	__OSReschedule
    b	.L_8024E438
.L_8024E424:
    lwz     r3,412(r25)
    li      r0,0
    rlwinm  r3,r3,0,19,17
    stw     r3,412(r25)
    stw     r0,216(r23)
.L_8024E438:
    mr      r3,r25
    bl	OSLoadContext
.L_8024E440:
    clrlwi  r23,r24,24
    rlwinm  r0,r24,2,22,29
    add     r22,r30,r0
    lwz     r0,0(r22)
    cmplwi  r0,0
    beq-	.L_8024E48C
    bl	OSDisableScheduler
    lwz     r12,0(r22)
    addi    r3,r23,0
    addi    r4,r25,0
    crclr   4*cr1+eq
    mtlr    r12
    addi    r5,r26,0
    addi    r6,r27,0
    blrl
    bl	OSEnableScheduler
    bl	__OSReschedule
    mr      r3,r25
    bl	OSLoadContext
.L_8024E48C:
    clrlwi  r0,r24,24
    cmplwi  r0,8
    bne-	.L_8024E4A0
    mr      r3,r25
    bl	OSLoadContext
.L_8024E4A0:
    addi    r3,r31,124
    crclr   4*cr1+eq
    clrlwi  r4,r24,24
    bl	OSReport
.L_8024E4B0:
    addi    r3,r13,-27908
    crclr   4*cr1+eq
    bl	OSReport
    mr      r3,r25
    bl	OSDumpContext
    addi    r4,r26,0
    crclr   4*cr1+eq
    addi    r5,r27,0
    addi    r3,r31,148
    bl	OSReport
    addi    r6,r28,0
    crclr   4*cr1+eq
    addi    r5,r29,0
    addi    r3,r31,200
    bl	OSReport
    clrlwi  r0,r24,24
    cmplwi  r0,15
    bgt-	.L_8024E5B8
    lis     r3,-32700
    addi    r3,r3,-18780
    slwi    r0,r0,2
    lwzx    r0,r3,r0
    mtctr   r0
    bctr
    lwz     r4,408(r25)
    addi    r5,r27,0
    addi    r3,r31,216
    crclr   4*cr1+eq
    bl	OSReport
    b	.L_8024E5B8
    lwz     r4,408(r25)
    addi    r3,r31,312
    crclr   4*cr1+eq
    bl	OSReport
    b	.L_8024E5B8
    lwz     r4,408(r25)
    addi    r5,r27,0
    addi    r3,r31,388
    crclr   4*cr1+eq
    bl	OSReport
    b	.L_8024E5B8
    lwz     r4,408(r25)
    addi    r5,r27,0
    addi    r3,r31,488
    crclr   4*cr1+eq
    bl	OSReport
    b	.L_8024E5B8
    addi    r3,r13,-27908
    crclr   4*cr1+eq
    bl	OSReport
    lis     r25,-13312
    crclr   4*cr1+eq
    addi    r24,r25,20480
    lhz     r4,20528(r25)
    addi    r3,r31,584
    lhz     r5,20530(r25)
    bl	OSReport
    lhz     r4,32(r24)
    addi    r3,r31,616
    lhz     r5,34(r24)
    crclr   4*cr1+eq
    bl	OSReport
    lwz     r4,24596(r25)
    crclr   4*cr1+eq
    addi    r3,r31,648
    bl	OSReport
.L_8024E5B8:
    lha     r4,-23656(r13)
    addi    r3,r31,676
    crclr   4*cr1+eq
    lwz     r5,-23660(r13)
    lwz     r7,-23648(r13)
    lwz     r8,-23644(r13)
    bl	OSReport
    bl	PPCHalt
    lmw     r22,24(r1)
    lwz     r0,68(r1)
    addi    r1,r1,64
    mtlr    r0
    blr
.size __OSUnhandledException, . - __OSUnhandledException

#
# === OSExec.o (os.a) ===
#

.global PackArgs
.balign 4
PackArgs:
/* 0x8024E5EC | size=0x188 (392 bytes) */
    mflr    r0
    stw     r0,4(r1)
    stwu    r1,-48(r1)
    stmw    r26,24(r1)
    addi    r26,r4,0
    addi    r29,r5,0
    addi    r30,r3,0
    li      r4,0
    li      r5,8192
    bl	memset
    cmpwi   r26,0
    bne-	.L_8024E628
    li      r0,0
    stw     r0,8(r30)
    b	.L_8024E748
.L_8024E628:
    slwi    r0,r26,2
    addi    r31,r26,0
    addi    r27,r30,8192
    add     r28,r29,r0
    b	.L_8024E660
.L_8024E63C:
    lwz     r3,0(r28)
    bl	strlen
    addi    r0,r3,1
    lwz     r4,0(r28)
    subf    r27,r0,r27
    addi    r3,r27,0
    bl	strcpy
    subf    r0,r30,r27
    stw     r0,0(r28)
.L_8024E660:
    addic.  r26,r26,-1
    addi    r28,r28,-4
    bge+	.L_8024E63C
    subf    r0,r30,r27
    addi    r3,r31,1
    clrrwi  r0,r0,2
    cmplwi  r3,0
    add     r6,r30,r0
    slwi    r0,r3,2
    subf    r6,r0,r6
    addi    r5,r6,0
    li      r7,0
    ble-	.L_8024E738
    cmplwi  r3,8
    addi    r3,r31,-7
    ble-	.L_8024E750
    addi    r0,r3,7
    srwi    r0,r0,3
    cmplwi  r3,0
    mtctr   r0
    addi    r3,r29,0
    addi    r4,r5,0
    ble-	.L_8024E750
.L_8024E6BC:
    lwz     r0,0(r3)
    addi    r7,r7,8
    stw     r0,0(r4)
    lwz     r0,4(r3)
    stw     r0,4(r4)
    lwz     r0,8(r3)
    stw     r0,8(r4)
    lwz     r0,12(r3)
    stw     r0,12(r4)
    lwz     r0,16(r3)
    stw     r0,16(r4)
    lwz     r0,20(r3)
    stw     r0,20(r4)
    lwz     r0,24(r3)
    stw     r0,24(r4)
    lwz     r0,28(r3)
    addi    r3,r3,32
    stw     r0,28(r4)
    addi    r4,r4,32
    bdnz+	.L_8024E6BC
    b	.L_8024E750
.L_8024E710:
    addi    r3,r31,1
    subf    r0,r7,r3
    cmplw   r7,r3
    mtctr   r0
    bge-	.L_8024E738
.L_8024E724:
    lwz     r0,0(r4)
    addi    r4,r4,4
    stw     r0,0(r5)
    addi    r5,r5,4
    bdnz+	.L_8024E724
.L_8024E738:
    addi    r0,r6,-4
    stw     r31,-4(r6)
    subf    r0,r30,r0
    stw     r0,8(r30)
.L_8024E748:
    li      r3,1
    b	.L_8024E760
.L_8024E750:
    slwi    r0,r7,2
    add     r4,r29,r0
    add     r5,r5,r0
    b	.L_8024E710
.L_8024E760:
    lmw     r26,24(r1)
    lwz     r0,52(r1)
    addi    r1,r1,48
    mtlr    r0
    blr
.size PackArgs, . - PackArgs

.global LoadDol
.balign 4
LoadDol:
/* 0x8024EBA4 | size=0x110 (272 bytes) */
    mflr    r0
    stw     r0,4(r1)
    stwu    r1,-96(r1)
    stw     r31,92(r1)
    stw     r30,88(r1)
    mr      r30,r3
    mr      r12,r4
    addi    r3,r1,84
    addi    r4,r1,80
    addi    r5,r1,76
    mtlr    r12
    blrl
    li      r3,28
    li      r4,1
    bl	OSAllocFromArenaLo
    mr      r31,r3
    mr      r3,r31
    mr      r4,r30
    li      r5,28
    bl	memcpy
    lis     r4,-32768
    lwz     r12,84(r1)
    lis     r3,-32731
    stw     r31,12528(r4)
    addi    r3,r3,-8416
    mtlr    r12
    blrl
    mr      r3,r31
    bl	OSSetArenaLo
    b	.L_8024EC1C
.L_8024EC1C:
    b	.L_8024EC20
.L_8024EC20:
    b	.L_8024EC70
.L_8024EC24:
    lwz     r6,64(r1)
    addi    r3,r1,16
    lwz     r5,68(r1)
    li      r7,0
    lwz     r4,72(r1)
    li      r8,0
    bl	DVDReadAbsAsyncPrio
    b	.L_8024EC44
.L_8024EC44:
    b	.L_8024EC48
.L_8024EC48:
    b	.L_8024EC60
.L_8024EC4C:
    bl	DVDCheckDisk
    cmpwi   r3,0
    bne-	.L_8024EC60
    li      r3,0
    bl	__OSDoHotReset
.L_8024EC60:
    addi    r3,r1,16
    bl	DVDGetCommandBlockStatus
    cmpwi   r3,0
    bne+	.L_8024EC4C
.L_8024EC70:
    lwz     r12,80(r1)
    addi    r3,r1,72
    addi    r4,r1,68
    addi    r5,r1,64
    mtlr    r12
    blrl
    cmpwi   r3,0
    bne+	.L_8024EC24
    lwz     r12,76(r1)
    mtlr    r12
    blrl
    lwz     r0,100(r1)
    lwz     r31,92(r1)
    lwz     r30,88(r1)
    addi    r1,r1,96
    mtlr    r0
    blr
.size LoadDol, . - LoadDol

.global __OSBootDol
.balign 4
__OSBootDol:
/* 0x8024F178 | size=0x19C (412 bytes) */
    mflr    r0
    stw     r0,4(r1)
    stwu    r1,-64(r1)
    stw     r31,60(r1)
    stw     r30,56(r1)
    stw     r29,52(r1)
    mr      r31,r3
    mr      r29,r4
    mr      r30,r5
    addi    r3,r1,24
    addi    r4,r1,20
    bl	OSGetSaveRegion
    mr      r5,r31
    crclr   4*cr1+eq
    addi    r3,r1,28
    addi    r4,r13,-27904
    bl	sprintf
    cmplwi  r30,0
    li      r31,0
    beq-	.L_8024F1EC
    mr      r3,r30
    b	.L_8024F1D0
.L_8024F1D0:
    b	.L_8024F1D4
.L_8024F1D4:
    b	.L_8024F1E0
.L_8024F1D8:
    addi    r3,r3,4
    addi    r31,r31,1
.L_8024F1E0:
    lwz     r0,0(r3)
    cmplwi  r0,0
    bne+	.L_8024F1D8
.L_8024F1EC:
    addi    r0,r31,2
    slwi    r3,r0,2
    li      r4,1
    bl	OSAllocFromArenaLo
    addi    r0,r1,28
    stw     r0,0(r3)
    addi    r5,r30,4
    addi    r6,r3,4
    b	.L_8024F210
.L_8024F210:
    addi    r8,r31,1
    cmpwi   r8,1
    addi    r4,r8,-1
    ble-	.L_8024F2DC
    srwi    r0,r4,3
    cmplwi  r0,0
    mtctr   r0
    beq-	.L_8024F2C0
    b	.L_8024F234
.L_8024F234:
    lwz     r0,-4(r5)
    addi    r5,r5,4
    stw     r0,0(r6)
    addi    r6,r6,4
    lwz     r0,-4(r5)
    addi    r5,r5,4
    stw     r0,0(r6)
    addi    r6,r6,4
    lwz     r0,-4(r5)
    addi    r5,r5,4
    stw     r0,0(r6)
    addi    r6,r6,4
    lwz     r0,-4(r5)
    addi    r5,r5,4
    stw     r0,0(r6)
    addi    r6,r6,4
    lwz     r0,-4(r5)
    addi    r5,r5,4
    stw     r0,0(r6)
    addi    r6,r6,4
    lwz     r0,-4(r5)
    addi    r5,r5,4
    stw     r0,0(r6)
    addi    r6,r6,4
    lwz     r0,-4(r5)
    addi    r5,r5,4
    stw     r0,0(r6)
    addi    r6,r6,4
    lwz     r0,-4(r5)
    addi    r5,r5,4
    stw     r0,0(r6)
    addi    r6,r6,4
    bdnz+	.L_8024F234
    andi.   r4,r4,7
    beq-	.L_8024F2DC
.L_8024F2C0:
    mtctr   r4
    b	.L_8024F2C8
.L_8024F2C8:
    lwz     r0,-4(r5)
    addi    r5,r5,4
    stw     r0,0(r6)
    addi    r6,r6,4
    bdnz+	.L_8024F2C8
.L_8024F2DC:
    lwz     r5,24(r1)
    mr      r9,r3
    lwz     r6,20(r1)
    mr      r4,r29
    li      r3,-1
    li      r7,0
    bl	__OSBootDolSimple
    lwz     r0,68(r1)
    lwz     r31,60(r1)
    lwz     r30,56(r1)
    lwz     r29,52(r1)
    addi    r1,r1,64
    mtlr    r0
    blr
.size __OSBootDol, . - __OSBootDol

.global OSExecl
.balign 4
OSExecl:
/* 0x8024F40C | size=0x144 (324 bytes) */
    mflr    r0
    stw     r0,4(r1)
    stwu    r1,-200(r1)
    stw     r31,196(r1)
    stw     r30,192(r1)
    stw     r29,188(r1)
    stw     r28,184(r1)
    bne-	cr1,.L_8024F44C
    stfd    f1,40(r1)
    stfd    f2,48(r1)
    stfd    f3,56(r1)
    stfd    f4,64(r1)
    stfd    f5,72(r1)
    stfd    f6,80(r1)
    stfd    f7,88(r1)
    stfd    f8,96(r1)
.L_8024F44C:
    stw     r3,8(r1)
    stw     r4,12(r1)
    stw     r5,16(r1)
    stw     r6,20(r1)
    stw     r7,24(r1)
    stw     r8,28(r1)
    stw     r9,32(r1)
    stw     r10,36(r1)
    mr      r28,r3
    mr      r29,r4
    bl	OSDisableScheduler
    li      r3,0
    bl	__OSShutdownDevices
    bl	OSEnableScheduler
    lis     r3,-32472
    bl	OSSetArenaLo
    lis     r3,-32465
    bl	OSSetArenaHi
    li      r3,4
    li      r4,4096
    bl	OSAllocFromArenaLo
    lis     r0,512
    stw     r0,172(r1)
    addi    r0,r1,208
    mr      r30,r3
    stw     r0,176(r1)
    addi    r0,r1,8
    li      r31,1
    stw     r0,180(r1)
    stw     r29,0(r30)
    b	.L_8024F4C8
.L_8024F4C8:
    b	.L_8024F4CC
.L_8024F4CC:
    addi    r3,r1,172
    li      r4,1
    bl	__va_arg
    lwz     r3,0(r3)
    mr      r0,r31
    slwi    r0,r0,2
    cmplwi  r3,0
    stwx    r3,r30,r0
    addi    r31,r31,1
    bne+	.L_8024F4CC
    lbz     r0,0(r28)
    extsb   r0,r0
    cmpwi   r0,0
    bne-	.L_8024F50C
    li      r3,0
    b	.L_8024F524
.L_8024F50C:
    mr      r3,r28
    addi    r4,r1,112
    bl	DVDOpen
    cmpwi   r3,0
    beq-	.L_8024F530
    lwz     r3,160(r1)
.L_8024F524:
    mr      r5,r30
    lis     r4,-16384
    bl	__OSBootDol
.L_8024F530:
    lwz     r0,204(r1)
    lwz     r31,196(r1)
    lwz     r30,192(r1)
    lwz     r29,188(r1)
    lwz     r28,184(r1)
    addi    r1,r1,200
    mtlr    r0
    blr
.size OSExecl, . - OSExecl

#
# === OSFatal.o (os.a) ===
#

.global ScreenReport
.balign 4
ScreenReport:
/* 0x8036F04C | size=0x3DC (988 bytes) */
    mflr    r0
    clrlwi  r11,r5,16
    stw     r0,4(r1)
    lis     r5,-32639
    stwu    r1,-416(r1)
    stmw    r16,352(r1)
    clrlwi  r21,r4,16
    lis     r4,-30583
    addi    r26,r3,0
    addi    r27,r6,0
    addi    r28,r7,0
    addi    r29,r8,0
    addi    r30,r9,0
    addi    r16,r11,-24
    addi    r22,r21,-48
    addi    r25,r5,-32639
    addi    r24,r4,-30583
    addi    r23,r1,60
.L_8036F094:
    cmpw    r16,r29
    blt-	.L_8036F414
    mullw   r0,r29,r21
    add     r0,r28,r0
    slwi    r0,r0,1
    addi    r31,r28,0
    add     r19,r26,r0
    b	.L_8036F408
.L_8036F0B4:
    extsb   r0,r3
    cmpwi   r0,10
    bne-	.L_8036F0CC
    add     r29,r29,r30
    addi    r10,r10,1
    b	.L_8036F094
.L_8036F0CC:
    cmpw    r22,r31
    bge-	.L_8036F0DC
    add     r29,r29,r30
    b	.L_8036F094
.L_8036F0DC:
    li      r0,3
    mtctr   r0
    li      r4,0
    li      r5,0
.L_8036F0EC:
    clrlwi  r0,r4,29
    add     r6,r0,r5
    addi    r3,r4,1
    srwi    r0,r3,3
    slwi    r6,r6,2
    addi    r9,r1,60
    add     r9,r9,r6
    li      r20,0
    stw     r20,0(r9)
    mulli   r0,r0,24
    stw     r20,32(r9)
    clrlwi  r3,r3,29
    addi    r8,r4,2
    stw     r20,64(r9)
    add     r3,r3,r0
    slwi    r9,r3,2
    addi    r3,r1,60
    add     r3,r3,r9
    stw     r20,0(r3)
    srwi    r7,r8,3
    addi    r6,r4,3
    stw     r20,32(r3)
    srwi    r0,r6,3
    mulli   r7,r7,24
    stw     r20,64(r3)
    clrlwi  r3,r8,29
    add     r3,r3,r7
    slwi    r7,r3,2
    addi    r3,r1,60
    add     r3,r3,r7
    stw     r20,0(r3)
    addi    r18,r4,4
    srwi    r12,r18,3
    stw     r20,32(r3)
    addi    r11,r4,5
    srwi    r9,r11,3
    stw     r20,64(r3)
    clrlwi  r3,r6,29
    mulli   r0,r0,24
    add     r3,r3,r0
    slwi    r17,r3,2
    addi    r3,r1,60
    add     r3,r3,r17
    stw     r20,0(r3)
    addi    r8,r4,6
    mulli   r12,r12,24
    stw     r20,32(r3)
    addi    r6,r4,7
    stw     r20,64(r3)
    clrlwi  r17,r18,29
    add     r12,r17,r12
    srwi    r0,r6,3
    slwi    r12,r12,2
    addi    r3,r1,60
    add     r3,r3,r12
    stw     r20,0(r3)
    mulli   r9,r9,24
    stw     r20,32(r3)
    clrlwi  r11,r11,29
    add     r9,r11,r9
    stw     r20,64(r3)
    slwi    r3,r9,2
    addi    r9,r1,60
    add     r9,r9,r3
    srwi    r7,r8,3
    stw     r20,0(r9)
    mulli   r3,r7,24
    stw     r20,32(r9)
    clrlwi  r7,r8,29
    stw     r20,64(r9)
    add     r3,r7,r3
    slwi    r3,r3,2
    addi    r7,r1,60
    add     r7,r7,r3
    stw     r20,0(r7)
    mulli   r0,r0,24
    stw     r20,32(r7)
    clrlwi  r3,r6,29
    add     r0,r3,r0
    stw     r20,64(r7)
    slwi    r0,r0,2
    addi    r3,r1,60
    add     r3,r3,r0
    stw     r20,0(r3)
    addi    r5,r5,24
    addi    r4,r4,8
    stw     r20,32(r3)
    stw     r20,64(r3)
    bdnz+	.L_8036F0EC
    addi    r3,r10,0
    addi    r4,r1,60
    addi    r7,r1,348
    li      r5,0
    li      r6,6
    bl	OSGetFontTexel
    addi    r10,r3,0
    addi    r0,r20,0
.L_8036F270:
    srwi    r3,r20,3
    mulli   r5,r3,24
    li      r4,12
    mr      r3,r0
    mtctr   r4
    clrlwi  r6,r20,29
    addi    r4,r31,0
    add     r5,r6,r5
    slwi    r7,r0,1
    li      r6,0
.L_8036F298:
    clrrwi  r8,r6,3
    add     r8,r5,r8
    slwi    r9,r8,2
    clrlwi  r8,r6,29
    lwzx    r9,r23,r9
    subfic  r8,r8,7
    slwi    r8,r8,2
    srw     r8,r9,r8
    clrlwi. r8,r8,28
    beq-	.L_8036F330
    mulli   r8,r8,239
    lbz     r9,0(r27)
    mullw   r8,r9,r8
    mulhw   r9,r25,r8
    add     r8,r9,r8
    srawi   r8,r8,7
    srwi    r9,r8,31
    add     r8,r8,r9
    mulhw   r9,r24,r8
    add     r8,r9,r8
    srawi   r8,r8,3
    srwi    r9,r8,31
    add     r9,r8,r9
    addi    r9,r9,16
    clrlwi. r8,r4,31
    stbx    r9,r19,r7
    beq-	.L_8036F31C
    lbz     r8,1(r27)
    add     r9,r19,r7
    stb     r8,-1(r9)
    lbz     r8,2(r27)
    stb     r8,1(r9)
    b	.L_8036F330
.L_8036F31C:
    lbz     r8,2(r27)
    add     r9,r19,r7
    stb     r8,-1(r9)
    lbz     r8,1(r27)
    stb     r8,1(r9)
.L_8036F330:
    addi    r6,r6,1
    clrrwi  r8,r6,3
    add     r8,r5,r8
    slwi    r9,r8,2
    clrlwi  r8,r6,29
    lwzx    r9,r23,r9
    subfic  r8,r8,7
    slwi    r8,r8,2
    srw     r8,r9,r8
    clrlwi. r8,r8,28
    addi    r7,r7,2
    addi    r4,r4,1
    beq-	.L_8036F3D4
    mulli   r8,r8,239
    lbz     r9,0(r27)
    mullw   r8,r9,r8
    mulhw   r9,r25,r8
    add     r8,r9,r8
    srawi   r8,r8,7
    srwi    r9,r8,31
    add     r8,r8,r9
    mulhw   r9,r24,r8
    add     r8,r9,r8
    srawi   r8,r8,3
    srwi    r9,r8,31
    add     r9,r8,r9
    addi    r9,r9,16
    clrlwi. r8,r4,31
    stbx    r9,r19,r7
    beq-	.L_8036F3C0
    lbz     r8,1(r27)
    add     r9,r19,r7
    stb     r8,-1(r9)
    lbz     r8,2(r27)
    stb     r8,1(r9)
    b	.L_8036F3D4
.L_8036F3C0:
    lbz     r8,2(r27)
    add     r9,r19,r7
    stb     r8,-1(r9)
    lbz     r8,1(r27)
    stb     r8,1(r9)
.L_8036F3D4:
    addi    r3,r3,1
    addi    r7,r7,2
    addi    r4,r4,1
    addi    r6,r6,1
    bdnz+	.L_8036F298
    addi    r20,r20,1
    cmplwi  r20,24
    add     r0,r0,r21
    blt+	.L_8036F270
    lwz     r3,348(r1)
    slwi    r0,r3,1
    add     r19,r19,r0
    add     r31,r31,r3
.L_8036F408:
    lbz     r3,0(r10)
    extsb.  r0,r3
    bne+	.L_8036F0B4
.L_8036F414:
    lmw     r16,352(r1)
    lwz     r0,420(r1)
    addi    r1,r1,416
    mtlr    r0
    blr
.size ScreenReport, . - ScreenReport

.global RGB2YUV
.balign 4
RGB2YUV:
/* 0x8036F524 | size=0x1DC (476 bytes) */
    stwu    r1,-88(r1)
    lis     r0,17200
    lbz     r5,0(r3)
    lbz     r4,1(r3)
    stw     r5,76(r1)
    lbz     r3,2(r3)
    stw     r4,68(r1)
    lfd     f0,-18016(r13)
    stw     r0,72(r1)
    lfs     f4,-18060(r13)
    stw     r0,64(r1)
    lfd     f2,72(r1)
    stw     r3,84(r1)
    fsubs   f3,f2,f0
    lfd     f1,64(r1)
    stw     r0,80(r1)
    fsubs   f1,f1,f0
    lfs     f2,-18056(r13)
    fmuls   f3,f4,f3
    stw     r5,52(r1)
    fmuls   f1,f2,f1
    lfd     f5,80(r1)
    stw     r4,44(r1)
    fsubs   f2,f5,f0
    lfs     f4,-18064(r13)
    fadds   f1,f3,f1
    stw     r5,36(r1)
    lfs     f8,-18044(r13)
    fmuls   f3,f4,f2
    stw     r4,28(r1)
    lfs     f9,-18048(r13)
    stw     r0,48(r1)
    fadds   f10,f3,f1
    stw     r0,40(r1)
    lfd     f2,48(r1)
    lfd     f1,40(r1)
    stw     r3,60(r1)
    fsubs   f7,f2,f0
    fsubs   f5,f1,f0
    lfs     f6,-18040(r13)
    stw     r0,32(r1)
    lfs     f3,-18036(r13)
    stw     r0,24(r1)
    lfd     f2,32(r1)
    fmuls   f7,f8,f7
    stw     r3,20(r1)
    fmuls   f5,f6,f5
    fsubs   f4,f2,f0
    lfd     f1,24(r1)
    stw     r0,56(r1)
    fsubs   f5,f7,f5
    fsubs   f2,f1,f0
    stw     r0,16(r1)
    fmuls   f4,f9,f4
    lfd     f8,56(r1)
    fmuls   f3,f3,f2
    fsubs   f6,f8,f0
    lfd     f1,16(r1)
    lfs     f12,-18068(r13)
    fsubs   f0,f1,f0
    lfs     f2,-18032(r13)
    fadds   f1,f12,f10
    lfs     f11,-18072(r13)
    fmuls   f6,f9,f6
    fmuls   f0,f2,f0
    lfs     f8,-18052(r13)
    fadds   f9,f11,f1
    lfs     f7,-18028(r13)
    fsubs   f1,f4,f3
    fadds   f2,f6,f5
    fcmpo   cr0,f9,f7
    fsubs   f0,f1,f0
    fadds   f1,f8,f2
    fmr     f2,f9
    fadds   f0,f8,f0
    fadds   f3,f11,f1
    fadds   f4,f11,f0
    ble-	.L_8036F660
    b	.L_8036F674
.L_8036F660:
    fcmpo   cr0,f2,f12
    bge-	.L_8036F66C
    b	.L_8036F670
.L_8036F66C:
    fmr     f12,f2
.L_8036F670:
    fmr     f7,f12
.L_8036F674:
    fctiwz  f0,f7
    lfs     f1,-18024(r13)
    fcmpo   cr0,f3,f1
    stfd    f0,16(r1)
    lwz     r0,20(r1)
    stb     r0,12(r1)
    ble-	.L_8036F694
    b	.L_8036F6A8
.L_8036F694:
    lfs     f1,-18068(r13)
    fcmpo   cr0,f3,f1
    bge-	.L_8036F6A4
    b	.L_8036F6A8
.L_8036F6A4:
    fmr     f1,f3
.L_8036F6A8:
    fctiwz  f0,f1
    lfs     f1,-18024(r13)
    fcmpo   cr0,f4,f1
    stfd    f0,16(r1)
    lwz     r0,20(r1)
    stb     r0,13(r1)
    ble-	.L_8036F6C8
    b	.L_8036F6DC
.L_8036F6C8:
    lfs     f1,-18068(r13)
    fcmpo   cr0,f4,f1
    bge-	.L_8036F6D8
    b	.L_8036F6DC
.L_8036F6D8:
    fmr     f1,f4
.L_8036F6DC:
    fctiwz  f0,f1
    li      r0,0
    stfd    f0,16(r1)
    lwz     r3,20(r1)
    stb     r3,14(r1)
    stb     r0,15(r1)
    lwz     r3,12(r1)
    addi    r1,r1,88
    blr
.size RGB2YUV, . - RGB2YUV

.global OSFatal
.balign 4
OSFatal:
/* 0x8036F700 | size=0x1D8 (472 bytes) */
    mflr    r0
    lis     r6,-32690
    stw     r0,4(r1)
    stwu    r1,-64(r1)
    stmw    r23,28(r1)
    addi    r27,r3,0
    addi    r28,r4,0
    addi    r29,r5,0
    addi    r31,r6,-3960
    lis     r30,-32768
    bl	OSDisableInterrupts
    bl	OSDisableScheduler
    addi    r3,r31,16
    bl	OSClearContext
    addi    r3,r31,16
    bl	OSSetCurrentContext
    bl	__OSStopAudioSystem
    li      r3,0
    bl	AISetStreamVolLeft
    li      r3,0
    bl	AISetStreamVolRight
    bl	VIInit
    li      r3,128
    bl	__OSUnmaskInterrupts
    li      r3,1
    bl	VISetBlack
    bl	VIFlush
    li      r3,0
    bl	VISetPreRetraceCallback
    li      r3,0
    bl	VISetPostRetraceCallback
    bl	OSEnableInterrupts
    bl	VIGetRetraceCount
    mr      r23,r3
.L_8036F788:
    bl	VIGetRetraceCount
    subf    r0,r23,r3
    cmpwi   r0,1
    blt+	.L_8036F788
    bl	OSGetTime
    lis     r5,-32768
    lwz     r0,248(r5)
    lis     r5,4194
    addi    r5,r5,19923
    srwi    r0,r0,2
    mulhwu  r0,r5,r0
    srwi    r0,r0,6
    mulli   r25,r0,1000
    addi    r23,r4,0
    addi    r24,r3,0
    li      r26,0
.L_8036F7C8:
    li      r3,0
    bl	__OSCallResetFunctions
    cmpwi   r3,0
    bne-	.L_8036F800
    bl	OSGetTime
    subfc   r5,r23,r4
    subfe   r0,r24,r3
    xoris   r4,r0,32768
    xoris   r3,r26,32768
    subfc   r0,r25,r5
    subfe   r3,r3,r4
    subfe   r3,r4,r4
    neg.    r3,r3
    bne+	.L_8036F7C8
.L_8036F800:
    bl	OSDisableInterrupts
    li      r3,1
    bl	__OSCallResetFunctions
    li      r3,0
    li      r4,0
    bl	EXISetExiCallback
    li      r3,2
    li      r4,0
    bl	EXISetExiCallback
    b	.L_8036F840
.L_8036F828:
    li      r3,0
    bl	EXISync
    li      r3,0
    bl	EXIDeselect
    li      r3,0
    bl	EXIUnlock
.L_8036F840:
    li      r3,0
    li      r4,1
    li      r5,0
    bl	EXILock
    cmpwi   r3,0
    beq+	.L_8036F828
    li      r3,0
    bl	EXIUnlock
    lis     r3,-13312
    addi    r3,r3,26624
.L_8036F868:
    lwz     r0,12(r3)
    clrlwi  r0,r0,31
    cmplwi  r0,1
    beq+	.L_8036F868
    lis     r3,-32731
    addi    r4,r3,-17508
    li      r3,8
    bl	__OSDBJUMPEND
    bl	GXAbortFrame
    lis     r3,-32448
    bl	OSSetArenaLo
    lwz     r3,56(r30)
    bl	OSSetArenaHi
    lwz     r0,0(r27)
    stw     r0,0(r31)
    lwz     r0,0(r28)
    stw     r0,4(r31)
    stw     r29,8(r31)
    bl	OSGetArenaHi
    lis     r5,-32713
    addi    r4,r3,0
    addi    r3,r5,-1832
    bl	OSSwitchFiber
    lmw     r23,28(r1)
    lwz     r0,68(r1)
    addi    r1,r1,64
    mtlr    r0
    blr
.size OSFatal, . - OSFatal

#
# === OSFont.o (os.a) ===
#

.global GetFontCode
.balign 4
GetFontCode:
/* 0x8036FF50 | size=0x174 (372 bytes) */
    clrlwi  r0,r3,16
    cmplwi  r0,1
    bne-	.L_803700A0
    clrlwi  r0,r4,16
    cmplwi  r0,32
    blt-	.L_8036FF88
    cmplwi  r0,223
    bgt-	.L_8036FF88
    lis     r3,-32700
    addi    r3,r3,11920
    slwi    r0,r0,1
    add     r3,r3,r0
    lhz     r3,-64(r3)
    blr
.L_8036FF88:
    clrlwi  r0,r4,16
    cmplwi  r0,34974
    ble-	.L_8037000C
    cmplwi  r0,39026
    bgt-	.L_8037000C
    srawi   r3,r0,8
    clrlwi  r4,r0,24
    addi    r0,r3,-136
    cmplwi  r4,64
    mulli   r5,r0,188
    li      r3,0
    addi    r0,r3,0
    blt-	.L_8036FFC8
    cmplwi  r4,252
    bgt-	.L_8036FFC8
    li      r0,1
.L_8036FFC8:
    cmpwi   r0,0
    beq-	.L_8036FFE0
    clrlwi  r0,r4,24
    cmplwi  r0,127
    beq-	.L_8036FFE0
    li      r3,1
.L_8036FFE0:
    cmpwi   r3,0
    bne-	.L_8036FFF0
    li      r3,0
    blr
.L_8036FFF0:
    addi    r3,r4,-64
    cmpwi   r3,64
    blt-	.L_80370000
    addi    r3,r3,-1
.L_80370000:
    addi    r3,r3,702
    add     r3,r5,r3
    blr
.L_8037000C:
    clrlwi  r0,r4,16
    cmplwi  r0,33088
    blt-	.L_803700BC
    cmplwi  r0,34718
    bge-	.L_803700BC
    srawi   r3,r0,8
    clrlwi  r4,r0,24
    addi    r0,r3,-129
    cmplwi  r4,64
    mulli   r5,r0,188
    li      r3,0
    addi    r0,r3,0
    blt-	.L_8037004C
    cmplwi  r4,252
    bgt-	.L_8037004C
    li      r0,1
.L_8037004C:
    cmpwi   r0,0
    beq-	.L_80370064
    clrlwi  r0,r4,24
    cmplwi  r0,127
    beq-	.L_80370064
    li      r3,1
.L_80370064:
    cmpwi   r3,0
    bne-	.L_80370074
    li      r3,0
    blr
.L_80370074:
    addi    r3,r4,-64
    cmpwi   r3,64
    blt-	.L_80370084
    addi    r3,r3,-1
.L_80370084:
    add     r0,r5,r3
    lis     r3,-32700
    slwi    r4,r0,1
    addi    r0,r3,12304
    add     r3,r0,r4
    lhz     r3,0(r3)
    blr
.L_803700A0:
    clrlwi  r3,r4,16
    cmplwi  r3,32
    ble-	.L_803700BC
    cmplwi  r3,255
    bgt-	.L_803700BC
    addi    r3,r3,-32
    blr
.L_803700BC:
    li      r3,0
    blr
.size GetFontCode, . - GetFontCode

.global Decode
.balign 4
Decode:
/* 0x803700C4 | size=0x174 (372 bytes) */
    stwu    r1,-32(r1)
    addi    r6,r3,16
    li      r10,0
    stw     r31,28(r1)
    stw     r30,24(r1)
    li      r30,0
    stw     r29,20(r1)
    lwz     r31,4(r3)
    lwz     r11,8(r3)
    lwz     r12,12(r3)
.L_803700EC:
    cmplwi  r30,0
    bne-	.L_80370100
    lwz     r29,0(r6)
    li      r30,32
    addi    r6,r6,4
.L_80370100:
    clrrwi. r0,r29,31
    beq-	.L_80370124
    mr      r0,r12
    lbzx    r5,r3,r0
    mr      r0,r10
    addi    r10,r10,1
    stbx    r5,r4,r0
    addi    r12,r12,1
    b	.L_80370214
.L_80370124:
    add     r7,r3,r11
    lbz     r5,0(r7)
    addi    r11,r11,2
    lbz     r0,1(r7)
    rlwimi  r0,r5,8,16,23
    srawi.  r5,r0,12
    clrlwi  r0,r0,20
    subf    r9,r0,r10
    bne-	.L_8037015C
    mr      r0,r12
    lbzx    r5,r3,r0
    addi    r12,r12,1
    addi    r0,r5,18
    b	.L_80370160
.L_8037015C:
    addi    r0,r5,2
.L_80370160:
    cmpwi   r0,0
    mr      r5,r0
    add     r7,r4,r10
    ble-	.L_80370214
    srwi.   r0,r5,3
    mtctr   r0
    beq-	.L_803701F4
.L_8037017C:
    addi    r8,r9,-1
    lbzx    r0,r4,r8
    addi    r8,r9,0
    addi    r10,r10,8
    stb     r0,0(r7)
    lbzx    r0,r4,r8
    addi    r8,r9,1
    stb     r0,1(r7)
    lbzx    r0,r4,r8
    addi    r8,r9,2
    stb     r0,2(r7)
    lbzx    r0,r4,r8
    addi    r8,r9,3
    stb     r0,3(r7)
    lbzx    r0,r4,r8
    addi    r8,r9,4
    stb     r0,4(r7)
    lbzx    r0,r4,r8
    addi    r8,r9,5
    stb     r0,5(r7)
    lbzx    r0,r4,r8
    addi    r8,r9,6
    addi    r9,r9,8
    stb     r0,6(r7)
    lbzx    r0,r4,r8
    stb     r0,7(r7)
    addi    r7,r7,8
    bdnz+	.L_8037017C
    andi.   r5,r5,7
    beq-	.L_80370214
.L_803701F4:
    mtctr   r5
.L_803701F8:
    addi    r8,r9,-1
    lbzx    r0,r4,r8
    addi    r10,r10,1
    addi    r9,r9,1
    stb     r0,0(r7)
    addi    r7,r7,1
    bdnz+	.L_803701F8
.L_80370214:
    cmpw    r10,r31
    slwi    r29,r29,1
    addi    r30,r30,-1
    blt+	.L_803700EC
    lwz     r31,28(r1)
    lwz     r30,24(r1)
    lwz     r29,20(r1)
    addi    r1,r1,32
    blr
.size Decode, . - Decode

.global ReadFont
.balign 4
ReadFont:
/* 0x803703F4 | size=0x324 (804 bytes) */
    mflr    r0
    stw     r0,4(r1)
    clrlwi  r0,r4,16
    cmplwi  r0,1
    stwu    r1,-88(r1)
    stmw    r25,60(r1)
    addi    r29,r4,0
    addi    r28,r3,0
    addi    r30,r5,0
    bne-	.L_80370478
    lis     r4,27
    lis     r3,5
    addi    r31,r28,0
    addi    r26,r4,-256
    addi    r27,r3,-12288
    b	.L_8037046C
.L_80370434:
    cmpwi   r27,256
    bgt-	.L_80370444
    mr      r25,r27
    b	.L_80370448
.L_80370444:
    li      r25,256
.L_80370448:
    subf    r27,r25,r27
.L_8037044C:
    addi    r3,r31,0
    addi    r4,r25,0
    addi    r5,r26,0
    bl	__OSReadROM
    cmpwi   r3,0
    beq+	.L_8037044C
    add     r26,r26,r25
    add     r31,r31,r25
.L_8037046C:
    cmpwi   r27,0
    bgt+	.L_80370434
    b	.L_803704CC
.L_80370478:
    lis     r3,32
    addi    r26,r28,0
    addi    r31,r3,-12544
    li      r27,12288
    b	.L_803704C4
.L_8037048C:
    cmpwi   r27,256
    bgt-	.L_8037049C
    mr      r25,r27
    b	.L_803704A0
.L_8037049C:
    li      r25,256
.L_803704A0:
    subf    r27,r25,r27
.L_803704A4:
    addi    r3,r26,0
    addi    r4,r25,0
    addi    r5,r31,0
    bl	__OSReadROM
    cmpwi   r3,0
    beq+	.L_803704A4
    add     r31,r31,r25
    add     r26,r26,r25
.L_803704C4:
    cmpwi   r27,0
    bgt+	.L_8037048C
.L_803704CC:
    lbz     r0,0(r28)
    cmplwi  r0,89
    bne-	.L_803704F8
    lbz     r0,1(r28)
    cmplwi  r0,97
    bne-	.L_803704F8
    lbz     r0,2(r28)
    cmplwi  r0,121
    bne-	.L_803704F8
    lwz     r31,4(r28)
    b	.L_803704FC
.L_803704F8:
    li      r31,0
.L_803704FC:
    cmplwi  r31,0
    bne-	.L_8037050C
    li      r3,0
    b	.L_80370704
.L_8037050C:
    addi    r3,r28,0
    addi    r4,r30,0
    bl	Decode
    clrlwi  r0,r29,16
    cmplwi  r0,1
    bne-	.L_80370700
    lwz     r5,-18008(r13)
    mr      r3,r29
    lwz     r0,-18004(r13)
    li      r4,84
    stw     r5,28(r1)
    stw     r0,32(r1)
    bl	GetFontCode
    lhz     r9,26(r30)
    lhz     r4,28(r30)
    lhz     r0,30(r30)
    mullw   r8,r9,r4
    lwz     r11,36(r30)
    lhz     r5,18(r30)
    lhz     r7,16(r30)
    lwz     r4,20(r30)
    divw    r10,r3,r8
    lhz     r6,28(r1)
    mullw   r8,r10,r8
    subf    r12,r8,r3
    divw    r8,r12,r9
    mullw   r3,r8,r9
    mullw   r5,r8,r5
    srawi   r0,r0,3
    subf    r3,r3,r12
    addze   r0,r0
    slwi    r0,r0,5
    srawi   r9,r0,1
    mullw   r10,r10,r4
    mullw   r3,r3,r7
    addze   r9,r9
    addi    r0,r5,4
    srawi   r4,r0,3
    addze   r4,r4
    srawi   r8,r3,3
    addze   r8,r8
    srawi   r7,r0,3
    addze   r7,r7
    slwi    r7,r7,3
    subfc   r7,r7,r0
    srawi   r0,r3,3
    addze   r0,r0
    slwi    r0,r0,3
    subfc   r0,r0,r3
    srawi   r3,r0,2
    mullw   r0,r9,r4
    add     r4,r30,r11
    srwi    r9,r10,1
    add     r4,r4,r9
    add     r9,r4,r0
    slwi    r0,r8,4
    add     r9,r9,r0
    slwi    r7,r7,1
    add     r9,r9,r7
    addze   r3,r3
    add     r9,r9,r3
    sth     r6,0(r9)
    addi    r10,r5,5
    addi    r9,r5,6
    lhz     r7,30(r30)
    addi    r6,r5,7
    lhz     r5,30(r1)
    srawi   r7,r7,3
    addze   r7,r7
    slwi    r7,r7,5
    srawi   r8,r7,1
    addze   r8,r8
    srawi   r7,r10,3
    addze   r7,r7
    mullw   r8,r8,r7
    srawi   r7,r10,3
    addze   r7,r7
    slwi    r7,r7,3
    add     r8,r4,r8
    subfc   r7,r7,r10
    add     r8,r8,r0
    slwi    r7,r7,1
    add     r8,r8,r7
    add     r8,r8,r3
    sth     r5,0(r8)
    lhz     r7,30(r30)
    lhz     r5,32(r1)
    srawi   r7,r7,3
    addze   r7,r7
    slwi    r7,r7,5
    srawi   r8,r7,1
    addze   r8,r8
    srawi   r7,r9,3
    addze   r7,r7
    mullw   r8,r8,r7
    srawi   r7,r9,3
    addze   r7,r7
    slwi    r7,r7,3
    add     r8,r4,r8
    subfc   r7,r7,r9
    add     r8,r8,r0
    slwi    r7,r7,1
    add     r8,r8,r7
    add     r8,r8,r3
    sth     r5,0(r8)
    lhz     r5,30(r30)
    srawi   r5,r5,3
    addze   r5,r5
    slwi    r5,r5,5
    srawi   r7,r5,1
    addze   r7,r7
    srawi   r5,r6,3
    addze   r5,r5
    mullw   r5,r7,r5
    add     r7,r4,r5
    srawi   r5,r6,3
    lhz     r4,34(r1)
    addze   r5,r5
    slwi    r5,r5,3
    subfc   r5,r5,r6
    add     r7,r7,r0
    slwi    r0,r5,1
    add     r7,r7,r0
    add     r7,r7,r3
    sth     r4,0(r7)
.L_80370700:
    mr      r3,r31
.L_80370704:
    lmw     r25,60(r1)
    lwz     r0,92(r1)
    addi    r1,r1,88
    mtlr    r0
    blr
.size ReadFont, . - ReadFont

.global OSLoadFont
.balign 4
OSLoadFont:
/* 0x80370718 | size=0x140 (320 bytes) */
    mflr    r0
    stw     r0,4(r1)
    stwu    r1,-32(r1)
    stw     r31,28(r1)
    stw     r30,24(r1)
    addi    r30,r4,0
    lhz     r5,-25400(r13)
    cmplwi  r5,65535
    beq-	.L_80370740
    b	.L_80370794
.L_80370740:
    lis     r4,-32768
    lwz     r0,204(r4)
    cmpwi   r0,0
    beq-	.L_80370758
    blt-	.L_8037077C
    b	.L_8037077C
.L_80370758:
    lis     r4,-13312
    lhz     r0,8302(r4)
    rlwinm. r0,r0,0,30,30
    beq-	.L_80370770
    li      r0,1
    b	.L_80370774
.L_80370770:
    li      r0,0
.L_80370774:
    sth     r0,-25400(r13)
    b	.L_80370784
.L_8037077C:
    li      r0,0
    sth     r0,-25400(r13)
.L_80370784:
    lis     r4,-32713
    lhz     r5,-25400(r13)
    addi    r0,r4,2136
    stw     r0,-22372(r13)
.L_80370794:
    clrlwi  r0,r5,16
    cmpwi   r0,2
    beq-	.L_80370838
    bge-	.L_803707B4
    cmpwi   r0,0
    beq-	.L_803707C0
    bge-	.L_803707DC
    b	.L_80370838
.L_803707B4:
    cmpwi   r0,6
    bge-	.L_80370838
    b	.L_803707F8
.L_803707C0:
    stw     r3,-22384(r13)
    addi    r3,r30,0
    li      r4,0
    lwz     r5,-22384(r13)
    bl	ReadFont
    mr      r31,r3
    b	.L_8037083C
.L_803707DC:
    stw     r3,-22380(r13)
    addi    r3,r30,0
    li      r4,1
    lwz     r5,-22380(r13)
    bl	ReadFont
    mr      r31,r3
    b	.L_8037083C
.L_803707F8:
    stw     r3,-22384(r13)
    addi    r3,r30,0
    li      r4,0
    lwz     r5,-22384(r13)
    bl	ReadFont
    mr.     r31,r3
    beq-	.L_8037083C
    lwz     r0,-22384(r13)
    addi    r3,r30,0
    li      r4,1
    add     r0,r0,r31
    stw     r0,-22380(r13)
    lwz     r5,-22380(r13)
    bl	ReadFont
    add     r31,r31,r3
    b	.L_8037083C
.L_80370838:
    li      r31,0
.L_8037083C:
    mr      r3,r31
    lwz     r0,36(r1)
    lwz     r31,28(r1)
    lwz     r30,24(r1)
    addi    r1,r1,32
    mtlr    r0
    blr
.size OSLoadFont, . - OSLoadFont

.global ParseStringS
.balign 4
ParseStringS:
/* 0x80370858 | size=0x13C (316 bytes) */
    mflr    r0
    stw     r0,4(r1)
    clrlwi  r0,r3,16
    cmpwi   r0,1
    stwu    r1,-32(r1)
    stw     r31,28(r1)
    addi    r31,r6,0
    stw     r30,24(r1)
    addi    r30,r4,0
    li      r4,0
    beq-	.L_803708B0
    bge-	.L_8037096C
    cmpwi   r0,0
    bge-	.L_80370894
    b	.L_8037096C
.L_80370894:
    lbz     r0,0(r30)
    lwz     r8,-22384(r13)
    cmplwi  r0,0
    mr      r4,r0
    beq-	.L_8037096C
    addi    r30,r30,1
    b	.L_8037096C
.L_803708B0:
    lbz     r0,0(r30)
    lwz     r8,-22380(r13)
    cmplwi  r0,0
    mr      r4,r0
    beq-	.L_8037096C
    clrlwi  r0,r4,24
    cmplwi  r0,129
    li      r6,1
    li      r7,0
    addi    r30,r30,1
    blt-	.L_803708E8
    cmplwi  r0,159
    bgt-	.L_803708E8
    mr      r7,r6
.L_803708E8:
    cmpwi   r7,0
    bne-	.L_80370918
    clrlwi  r0,r4,24
    cmplwi  r0,224
    li      r7,0
    blt-	.L_8037090C
    cmplwi  r0,252
    bgt-	.L_8037090C
    li      r7,1
.L_8037090C:
    cmpwi   r7,0
    bne-	.L_80370918
    li      r6,0
.L_80370918:
    cmpwi   r6,0
    beq-	.L_8037096C
    lbz     r7,0(r30)
    li      r0,0
    mr      r6,r0
    cmplwi  r7,64
    blt-	.L_80370940
    cmplwi  r7,252
    bgt-	.L_80370940
    li      r6,1
.L_80370940:
    cmpwi   r6,0
    beq-	.L_80370954
    cmplwi  r7,127
    beq-	.L_80370954
    li      r0,1
.L_80370954:
    cmpwi   r0,0
    beq-	.L_8037096C
    lbz     r0,0(r30)
    rlwinm  r4,r4,8,8,23
    addi    r30,r30,1
    or      r4,r4,r0
.L_8037096C:
    stw     r8,0(r5)
    bl	GetFontCode
    stw     r3,0(r31)
    mr      r3,r30
    lwz     r0,36(r1)
    lwz     r31,28(r1)
    lwz     r30,24(r1)
    addi    r1,r1,32
    mtlr    r0
    blr
.size ParseStringS, . - ParseStringS

.global ParseStringW
.balign 4
ParseStringW:
/* 0x80370994 | size=0x1FC (508 bytes) */
    mflr    r0
    li      r7,0
    stw     r0,4(r1)
    clrlwi  r0,r3,16
    cmpwi   r0,3
    stwu    r1,-56(r1)
    stmw    r26,32(r1)
    addi    r26,r3,0
    addi    r27,r4,0
    addi    r28,r5,0
    addi    r29,r6,0
    li      r30,0
    stw     r7,24(r1)
    beq-	.L_80370AD0
    bge-	.L_803709E8
    cmpwi   r0,1
    beq-	.L_80370A14
    bge-	.L_80370B10
    cmpwi   r0,0
    bge-	.L_803709F8
    b	.L_80370B10
.L_803709E8:
    cmpwi   r0,5
    beq-	.L_80370AF8
    bge-	.L_80370B10
    b	.L_80370AE4
.L_803709F8:
    lbz     r0,0(r27)
    lwz     r31,-22384(r13)
    cmplwi  r0,0
    mr      r30,r0
    beq-	.L_80370B10
    addi    r27,r27,1
    b	.L_80370B10
.L_80370A14:
    lbz     r0,0(r27)
    lwz     r31,-22380(r13)
    cmplwi  r0,0
    mr      r30,r0
    beq-	.L_80370B10
    clrlwi  r0,r30,24
    cmplwi  r0,129
    li      r3,1
    addi    r27,r27,1
    blt-	.L_80370A48
    cmplwi  r0,159
    bgt-	.L_80370A48
    mr      r7,r3
.L_80370A48:
    cmpwi   r7,0
    bne-	.L_80370A78
    clrlwi  r0,r30,24
    cmplwi  r0,224
    li      r4,0
    blt-	.L_80370A6C
    cmplwi  r0,252
    bgt-	.L_80370A6C
    li      r4,1
.L_80370A6C:
    cmpwi   r4,0
    bne-	.L_80370A78
    li      r3,0
.L_80370A78:
    cmpwi   r3,0
    beq-	.L_80370B10
    lbz     r4,0(r27)
    li      r0,0
    mr      r3,r0
    cmplwi  r4,64
    blt-	.L_80370AA0
    cmplwi  r4,252
    bgt-	.L_80370AA0
    li      r3,1
.L_80370AA0:
    cmpwi   r3,0
    beq-	.L_80370AB4
    cmplwi  r4,127
    beq-	.L_80370AB4
    li      r0,1
.L_80370AB4:
    cmpwi   r0,0
    beq-	.L_80370B10
    lbz     r0,0(r27)
    rlwinm  r3,r30,8,8,23
    addi    r27,r27,1
    or      r30,r3,r0
    b	.L_80370B10
.L_80370AD0:
    addi    r3,r27,0
    addi    r4,r1,24
    bl	OSUTF8to32
    mr      r27,r3
    b	.L_80370B10
.L_80370AE4:
    addi    r3,r27,0
    addi    r4,r1,24
    bl	OSUTF16to32
    mr      r27,r3
    b	.L_80370B10
.L_80370AF8:
    lwz     r0,0(r27)
    stw     r0,24(r1)
    lwz     r0,24(r1)
    cmplwi  r0,0
    beq-	.L_80370B10
    addi    r27,r27,4
.L_80370B10:
    lwz     r3,24(r1)
    cmplwi  r3,0
    beq-	.L_80370B64
    lwz     r31,-22384(r13)
    li      r26,0
    bl	OSUTF32toANSI
    clrlwi. r30,r3,24
    beq-	.L_80370B48
    lwz     r0,-22376(r13)
    cmpwi   r0,0
    beq-	.L_80370B64
    lwz     r0,24(r1)
    cmplwi  r0,127
    bgt-	.L_80370B64
.L_80370B48:
    lwz     r3,24(r1)
    bl	OSUTF32toSJIS
    clrlwi. r0,r3,16
    addi    r30,r3,0
    beq-	.L_80370B64
    li      r26,1
    lwz     r31,-22380(r13)
.L_80370B64:
    stw     r31,0(r28)
    addi    r3,r26,0
    addi    r4,r30,0
    bl	GetFontCode
    stw     r3,0(r29)
    mr      r3,r27
    lmw     r26,32(r1)
    lwz     r0,60(r1)
    addi    r1,r1,56
    mtlr    r0
    blr
.size ParseStringW, . - ParseStringW

.global OSGetFontTexel
.balign 4
OSGetFontTexel:
/* 0x80370B90 | size=0x2A0 (672 bytes) */
    mflr    r0
    stw     r0,4(r1)
    stwu    r1,-96(r1)
    stmw    r18,40(r1)
    addi    r25,r3,0
    addi    r29,r4,0
    addi    r30,r5,0
    addi    r26,r6,0
    addi    r31,r7,0
    lhz     r8,-25400(r13)
    cmplwi  r8,65535
    beq-	.L_80370BC4
    b	.L_80370C18
.L_80370BC4:
    lis     r3,-32768
    lwz     r0,204(r3)
    cmpwi   r0,0
    beq-	.L_80370BDC
    blt-	.L_80370C00
    b	.L_80370C00
.L_80370BDC:
    lis     r3,-13312
    lhz     r0,8302(r3)
    rlwinm. r0,r0,0,30,30
    beq-	.L_80370BF4
    li      r0,1
    b	.L_80370BF8
.L_80370BF4:
    li      r0,0
.L_80370BF8:
    sth     r0,-25400(r13)
    b	.L_80370C08
.L_80370C00:
    li      r0,0
    sth     r0,-25400(r13)
.L_80370C08:
    lis     r3,-32713
    lhz     r8,-25400(r13)
    addi    r0,r3,2136
    stw     r0,-22372(r13)
.L_80370C18:
    lwz     r12,-22372(r13)
    addi    r3,r8,0
    addi    r4,r25,0
    mtlr    r12
    addi    r5,r1,36
    addi    r6,r1,32
    blrl
    lwz     r11,36(r1)
    slwi    r0,r26,2
    srawi   r0,r0,3
    lwz     r9,32(r1)
    lhz     r10,26(r11)
    lhz     r4,28(r11)
    addze   r0,r0
    lwz     r5,36(r11)
    addi    r25,r3,0
    mullw   r8,r10,r4
    lwz     r4,20(r11)
    lhz     r7,18(r11)
    lhz     r6,16(r11)
    divw    r12,r9,r8
    mullw   r8,r12,r8
    subf    r18,r8,r9
    divw    r9,r18,r10
    mullw   r8,r9,r10
    mullw   r4,r12,r4
    subf    r10,r8,r18
    mullw   r10,r10,r6
    mullw   r9,r9,r7
    add     r26,r11,r5
    srwi    r4,r4,1
    addi    r27,r11,44
    add     r26,r26,r4
    slwi    r6,r0,5
    li      r12,0
    b	.L_80370DEC
.L_80370CA8:
    add     r3,r9,r12
    srawi   r0,r3,3
    addze   r0,r0
    srawi   r7,r3,3
    addze   r7,r7
    slwi    r7,r7,3
    subfc   r7,r7,r3
    srawi   r3,r12,3
    addze   r3,r3
    mullw   r4,r3,r6
    srawi   r5,r12,3
    addze   r5,r5
    slwi    r5,r5,3
    subfc   r5,r5,r12
    slwi    r3,r7,1
    add     r4,r29,r4
    slwi    r5,r5,2
    li      r11,0
    b	.L_80370DD8
.L_80370CF4:
    lhz     r8,30(r8)
    add     r22,r10,r11
    add     r7,r30,r11
    srawi   r8,r8,3
    addze   r8,r8
    slwi    r8,r8,5
    srawi   r19,r8,1
    addze   r19,r19
    srawi   r20,r22,3
    addze   r20,r20
    srawi   r8,r22,3
    addze   r8,r8
    slwi    r8,r8,3
    subfc   r8,r8,r22
    srawi   r21,r8,2
    addze   r21,r21
    srawi   r28,r22,2
    addze   r28,r28
    slwi    r28,r28,2
    subfc   r28,r28,r22
    srawi   r22,r7,3
    addze   r22,r22
    srawi   r8,r7,3
    addze   r8,r8
    slwi    r8,r8,3
    mullw   r19,r19,r0
    subfc   r8,r8,r7
    srawi   r23,r8,1
    addze   r23,r23
    srawi   r24,r7,1
    addze   r24,r24
    slwi    r8,r22,5
    slwi    r24,r24,1
    add     r8,r4,r8
    add     r8,r8,r5
    add     r18,r26,r19
    slwi    r22,r20,4
    add     r18,r18,r22
    add     r18,r18,r3
    subfc.  r24,r24,r7
    add     r18,r18,r21
    add     r8,r8,r23
    beq-	.L_80370DA8
    li      r19,15
    b	.L_80370DAC
.L_80370DA8:
    li      r19,240
.L_80370DAC:
    slwi    r7,r28,1
    lbz     r28,0(r18)
    subfic  r7,r7,6
    lbz     r24,0(r8)
    sraw    r7,r28,r7
    clrlwi  r7,r7,30
    lbzx    r7,r27,r7
    addi    r11,r11,1
    and     r7,r7,r19
    or      r7,r24,r7
    stb     r7,0(r8)
.L_80370DD8:
    lwz     r8,36(r1)
    lhz     r7,16(r8)
    cmpw    r11,r7
    blt+	.L_80370CF4
    addi    r12,r12,1
.L_80370DEC:
    lwz     r4,36(r1)
    lhz     r0,18(r4)
    cmpw    r12,r0
    blt+	.L_80370CA8
    cmplwi  r31,0
    beq-	.L_80370E18
    lhz     r0,34(r4)
    lwz     r3,32(r1)
    add     r0,r4,r0
    lbzx    r0,r3,r0
    stw     r0,0(r31)
.L_80370E18:
    mr      r3,r25
    lmw     r18,40(r1)
    lwz     r0,100(r1)
    addi    r1,r1,96
    mtlr    r0
    blr
.size OSGetFontTexel, . - OSGetFontTexel

.global ExpandFontSheet
.balign 4
ExpandFontSheet:
/* 0x80370E30 | size=0x3AC (940 bytes) */
    mflr    r0
    mr      r6,r3
    stw     r0,4(r1)
    stwu    r1,-8(r1)
    lhz     r0,24(r3)
    addi    r3,r6,44
    cmplwi  r0,0
    bne-	.L_80371008
    lwz     r0,40(r6)
    srawi   r7,r0,1
    addze   r7,r7
    addi    r0,r7,-1
    mr.     r11,r0
    slwi    r0,r0,1
    add     r9,r5,r0
    addi    r7,r11,1
    blt-	.L_803711C0
    srwi.   r0,r7,2
    mtctr   r0
    beq-	.L_80370FB0
.L_80370E80:
    add     r10,r4,r11
    lbz     r0,0(r10)
    addi    r11,r11,-1
    rlwinm  r8,r0,26,30,31
    rlwinm  r0,r0,28,30,31
    lbzx    r8,r3,r8
    lbzx    r0,r3,r0
    clrlwi  r0,r0,28
    rlwimi  r0,r8,0,24,27
    stb     r0,0(r9)
    lbz     r0,0(r10)
    add     r10,r4,r11
    addi    r11,r11,-1
    rlwinm  r8,r0,30,30,31
    clrlwi  r0,r0,30
    lbzx    r8,r3,r8
    lbzx    r0,r3,r0
    clrlwi  r0,r0,28
    rlwimi  r0,r8,0,24,27
    stb     r0,1(r9)
    lbz     r0,0(r10)
    rlwinm  r8,r0,26,30,31
    rlwinm  r0,r0,28,30,31
    lbzx    r8,r3,r8
    lbzx    r0,r3,r0
    clrlwi  r0,r0,28
    rlwimi  r0,r8,0,24,27
    stb     r0,-2(r9)
    lbz     r0,0(r10)
    add     r10,r4,r11
    addi    r11,r11,-1
    rlwinm  r8,r0,30,30,31
    clrlwi  r0,r0,30
    lbzx    r8,r3,r8
    lbzx    r0,r3,r0
    clrlwi  r0,r0,28
    rlwimi  r0,r8,0,24,27
    stb     r0,-1(r9)
    lbz     r0,0(r10)
    rlwinm  r8,r0,26,30,31
    rlwinm  r0,r0,28,30,31
    lbzx    r8,r3,r8
    lbzx    r0,r3,r0
    clrlwi  r0,r0,28
    rlwimi  r0,r8,0,24,27
    stb     r0,-4(r9)
    lbz     r0,0(r10)
    add     r10,r4,r11
    addi    r11,r11,-1
    rlwinm  r8,r0,30,30,31
    clrlwi  r0,r0,30
    lbzx    r8,r3,r8
    lbzx    r0,r3,r0
    clrlwi  r0,r0,28
    rlwimi  r0,r8,0,24,27
    stb     r0,-3(r9)
    lbz     r0,0(r10)
    rlwinm  r8,r0,26,30,31
    rlwinm  r0,r0,28,30,31
    lbzx    r8,r3,r8
    lbzx    r0,r3,r0
    clrlwi  r0,r0,28
    rlwimi  r0,r8,0,24,27
    stb     r0,-6(r9)
    lbz     r0,0(r10)
    rlwinm  r8,r0,30,30,31
    clrlwi  r0,r0,30
    lbzx    r8,r3,r8
    lbzx    r0,r3,r0
    clrlwi  r0,r0,28
    rlwimi  r0,r8,0,24,27
    stb     r0,-5(r9)
    addi    r9,r9,-8
    bdnz+	.L_80370E80
    andi.   r7,r7,3
    beq-	.L_803711C0
.L_80370FB0:
    mtctr   r7
.L_80370FB4:
    add     r10,r4,r11
    lbz     r0,0(r10)
    addi    r11,r11,-1
    rlwinm  r8,r0,26,30,31
    rlwinm  r0,r0,28,30,31
    lbzx    r8,r3,r8
    lbzx    r0,r3,r0
    clrlwi  r0,r0,28
    rlwimi  r0,r8,0,24,27
    stb     r0,0(r9)
    lbz     r0,0(r10)
    rlwinm  r8,r0,30,30,31
    clrlwi  r0,r0,30
    lbzx    r8,r3,r8
    lbzx    r0,r3,r0
    clrlwi  r0,r0,28
    rlwimi  r0,r8,0,24,27
    stb     r0,1(r9)
    addi    r9,r9,-2
    bdnz+	.L_80370FB4
    b	.L_803711C0
.L_80371008:
    cmplwi  r0,2
    bne-	.L_803711C0
    lwz     r0,40(r6)
    srawi   r7,r0,2
    addze   r7,r7
    addic.  r10,r7,-1
    slwi    r0,r10,2
    add     r8,r5,r0
    addi    r7,r10,1
    blt-	.L_803711C0
    srwi.   r0,r7,2
    mtctr   r0
    beq-	.L_8037116C
.L_8037103C:
    add     r9,r4,r10
    lbz     r0,0(r9)
    addi    r10,r10,-1
    rlwinm  r0,r0,26,30,31
    lbzx    r0,r3,r0
    stb     r0,0(r8)
    lbz     r0,0(r9)
    rlwinm  r0,r0,28,30,31
    lbzx    r0,r3,r0
    stb     r0,1(r8)
    lbz     r0,0(r9)
    rlwinm  r0,r0,30,30,31
    lbzx    r0,r3,r0
    stb     r0,2(r8)
    lbz     r0,0(r9)
    add     r9,r4,r10
    addi    r10,r10,-1
    clrlwi  r0,r0,30
    lbzx    r0,r3,r0
    stb     r0,3(r8)
    lbz     r0,0(r9)
    rlwinm  r0,r0,26,30,31
    lbzx    r0,r3,r0
    stb     r0,-4(r8)
    lbz     r0,0(r9)
    rlwinm  r0,r0,28,30,31
    lbzx    r0,r3,r0
    stb     r0,-3(r8)
    lbz     r0,0(r9)
    rlwinm  r0,r0,30,30,31
    lbzx    r0,r3,r0
    stb     r0,-2(r8)
    lbz     r0,0(r9)
    add     r9,r4,r10
    addi    r10,r10,-1
    clrlwi  r0,r0,30
    lbzx    r0,r3,r0
    stb     r0,-1(r8)
    lbz     r0,0(r9)
    rlwinm  r0,r0,26,30,31
    lbzx    r0,r3,r0
    stb     r0,-8(r8)
    lbz     r0,0(r9)
    rlwinm  r0,r0,28,30,31
    lbzx    r0,r3,r0
    stb     r0,-7(r8)
    lbz     r0,0(r9)
    rlwinm  r0,r0,30,30,31
    lbzx    r0,r3,r0
    stb     r0,-6(r8)
    lbz     r0,0(r9)
    add     r9,r4,r10
    addi    r10,r10,-1
    clrlwi  r0,r0,30
    lbzx    r0,r3,r0
    stb     r0,-5(r8)
    lbz     r0,0(r9)
    rlwinm  r0,r0,26,30,31
    lbzx    r0,r3,r0
    stb     r0,-12(r8)
    lbz     r0,0(r9)
    rlwinm  r0,r0,28,30,31
    lbzx    r0,r3,r0
    stb     r0,-11(r8)
    lbz     r0,0(r9)
    rlwinm  r0,r0,30,30,31
    lbzx    r0,r3,r0
    stb     r0,-10(r8)
    lbz     r0,0(r9)
    clrlwi  r0,r0,30
    lbzx    r0,r3,r0
    stb     r0,-9(r8)
    addi    r8,r8,-16
    bdnz+	.L_8037103C
    andi.   r7,r7,3
    beq-	.L_803711C0
.L_8037116C:
    mtctr   r7
.L_80371170:
    add     r9,r4,r10
    lbz     r0,0(r9)
    addi    r10,r10,-1
    rlwinm  r0,r0,26,30,31
    lbzx    r0,r3,r0
    stb     r0,0(r8)
    lbz     r0,0(r9)
    rlwinm  r0,r0,28,30,31
    lbzx    r0,r3,r0
    stb     r0,1(r8)
    lbz     r0,0(r9)
    rlwinm  r0,r0,30,30,31
    lbzx    r0,r3,r0
    stb     r0,2(r8)
    lbz     r0,0(r9)
    clrlwi  r0,r0,30
    lbzx    r0,r3,r0
    stb     r0,3(r8)
    addi    r8,r8,-4
    bdnz+	.L_80371170
.L_803711C0:
    mr      r3,r5
    lwz     r4,40(r6)
    bl	DCStoreRange
    lwz     r0,12(r1)
    addi    r1,r1,8
    mtlr    r0
    blr
.size ExpandFontSheet, . - ExpandFontSheet

.global OSInitFont
.balign 4
OSInitFont:
/* 0x803711DC | size=0x20C (524 bytes) */
    mflr    r0
    stw     r0,4(r1)
    stwu    r1,-24(r1)
    stw     r31,20(r1)
    lhz     r5,-25400(r13)
    cmplwi  r5,65535
    beq-	.L_803711FC
    b	.L_80371250
.L_803711FC:
    lis     r4,-32768
    lwz     r0,204(r4)
    cmpwi   r0,0
    beq-	.L_80371214
    blt-	.L_80371238
    b	.L_80371238
.L_80371214:
    lis     r4,-13312
    lhz     r0,8302(r4)
    rlwinm. r0,r0,0,30,30
    beq-	.L_8037122C
    li      r0,1
    b	.L_80371230
.L_8037122C:
    li      r0,0
.L_80371230:
    sth     r0,-25400(r13)
    b	.L_80371240
.L_80371238:
    li      r0,0
    sth     r0,-25400(r13)
.L_80371240:
    lis     r4,-32713
    lhz     r5,-25400(r13)
    addi    r0,r4,2136
    stw     r0,-22372(r13)
.L_80371250:
    clrlwi  r0,r5,16
    cmpwi   r0,2
    beq-	.L_803713D0
    bge-	.L_80371270
    cmpwi   r0,0
    beq-	.L_8037127C
    bge-	.L_803712D0
    b	.L_803713D0
.L_80371270:
    cmpwi   r0,6
    bge-	.L_803713D0
    b	.L_80371324
.L_8037127C:
    stw     r3,-22384(r13)
    addis   r3,r3,2
    addi    r3,r3,-12000
    lwz     r5,-22384(r13)
    li      r4,0
    bl	ReadFont
    cmplwi  r3,0
    bne-	.L_803712A4
    li      r3,0
    b	.L_803713D4
.L_803712A4:
    lwz     r3,-22384(r13)
    lwz     r4,36(r3)
    addi    r0,r4,31
    clrrwi  r0,r0,5
    stw     r0,36(r3)
    add     r4,r3,r4
    lwz     r3,-22384(r13)
    lwz     r0,36(r3)
    add     r5,r3,r0
    bl	ExpandFontSheet
    b	.L_803713D0
.L_803712D0:
    stw     r3,-22380(r13)
    addis   r3,r3,13
    addi    r3,r3,16128
    lwz     r5,-22380(r13)
    li      r4,1
    bl	ReadFont
    cmplwi  r3,0
    bne-	.L_803712F8
    li      r3,0
    b	.L_803713D4
.L_803712F8:
    lwz     r3,-22380(r13)
    lwz     r4,36(r3)
    addi    r0,r4,31
    clrrwi  r0,r0,5
    stw     r0,36(r3)
    add     r4,r3,r4
    lwz     r3,-22380(r13)
    lwz     r0,36(r3)
    add     r5,r3,r0
    bl	ExpandFontSheet
    b	.L_803713D0
.L_80371324:
    stw     r3,-22384(r13)
    addis   r31,r3,15
    addi    r31,r31,16416
    lwz     r5,-22384(r13)
    addi    r3,r31,0
    li      r4,0
    bl	ReadFont
    cmplwi  r3,0
    bne-	.L_80371350
    li      r3,0
    b	.L_803713D4
.L_80371350:
    lwz     r3,-22384(r13)
    lwz     r4,36(r3)
    addi    r0,r4,31
    clrrwi  r0,r0,5
    stw     r0,36(r3)
    add     r4,r3,r4
    lwz     r3,-22384(r13)
    lwz     r0,36(r3)
    add     r5,r3,r0
    bl	ExpandFontSheet
    lwz     r5,-22384(r13)
    addi    r3,r31,0
    li      r4,1
    addis   r5,r5,2
    addi    r0,r5,288
    stw     r0,-22380(r13)
    lwz     r5,-22380(r13)
    bl	ReadFont
    cmplwi  r3,0
    bne-	.L_803713A8
    li      r3,0
    b	.L_803713D4
.L_803713A8:
    lwz     r3,-22380(r13)
    lwz     r4,36(r3)
    addi    r0,r4,31
    clrrwi  r0,r0,5
    stw     r0,36(r3)
    add     r4,r3,r4
    lwz     r3,-22380(r13)
    lwz     r0,36(r3)
    add     r5,r3,r0
    bl	ExpandFontSheet
.L_803713D0:
    li      r3,1
.L_803713D4:
    lwz     r0,28(r1)
    lwz     r31,20(r1)
    addi    r1,r1,24
    mtlr    r0
    blr
.size OSInitFont, . - OSInitFont

.global OSGetFontTexture
.balign 4
OSGetFontTexture:
/* 0x803713E8 | size=0x170 (368 bytes) */
    mflr    r0
    stw     r0,4(r1)
    addi    r0,r3,0
    stwu    r1,-56(r1)
    stw     r31,52(r1)
    addi    r31,r7,0
    stw     r30,48(r1)
    addi    r30,r6,0
    stw     r29,44(r1)
    addi    r29,r5,0
    stw     r28,40(r1)
    addi    r28,r4,0
    lhz     r8,-25400(r13)
    cmplwi  r8,65535
    beq-	.L_80371428
    b	.L_80371480
.L_80371428:
    lis     r3,-32768
    lwz     r3,204(r3)
    cmpwi   r3,0
    beq-	.L_80371440
    blt-	.L_80371468
    b	.L_80371468
.L_80371440:
    lis     r3,-13312
    addi    r3,r3,8192
    lhz     r3,110(r3)
    rlwinm. r3,r3,0,30,30
    beq-	.L_8037145C
    li      r3,1
    b	.L_80371460
.L_8037145C:
    li      r3,0
.L_80371460:
    sth     r3,-25400(r13)
    b	.L_80371470
.L_80371468:
    li      r3,0
    sth     r3,-25400(r13)
.L_80371470:
    lis     r3,-32713
    lhz     r8,-25400(r13)
    addi    r3,r3,2136
    stw     r3,-22372(r13)
.L_80371480:
    lwz     r12,-22372(r13)
    addi    r3,r8,0
    mr      r4,r0
    mtlr    r12
    addi    r5,r1,36
    addi    r6,r1,32
    blrl
    lwz     r7,36(r1)
    mr      r0,r3
    lwz     r6,32(r1)
    cmplwi  r31,0
    lhz     r5,26(r7)
    lhz     r4,28(r7)
    lwz     r3,20(r7)
    mullw   r5,r5,r4
    lwz     r4,36(r7)
    divw    r8,r6,r5
    mullw   r3,r3,r8
    add     r3,r4,r3
    add     r3,r7,r3
    stw     r3,0(r28)
    lwz     r3,36(r1)
    lwz     r4,32(r1)
    lhz     r6,26(r3)
    lhz     r5,28(r3)
    lhz     r3,16(r3)
    mullw   r5,r6,r5
    mullw   r5,r8,r5
    subf    r5,r5,r4
    divw    r7,r5,r6
    mullw   r4,r7,r6
    subf    r4,r4,r5
    mullw   r3,r4,r3
    stw     r3,0(r29)
    lwz     r3,36(r1)
    lhz     r3,18(r3)
    mullw   r3,r7,r3
    stw     r3,0(r30)
    beq-	.L_80371534
    lwz     r5,36(r1)
    lwz     r4,32(r1)
    lhz     r3,34(r5)
    add     r3,r5,r3
    lbzx    r3,r4,r3
    stw     r3,0(r31)
.L_80371534:
    mr      r3,r0
    lwz     r0,60(r1)
    lwz     r31,52(r1)
    lwz     r30,48(r1)
    lwz     r29,44(r1)
    lwz     r28,40(r1)
    addi    r1,r1,56
    mtlr    r0
    blr
.size OSGetFontTexture, . - OSGetFontTexture

#
# === OSInterrupt.o (os.a) ===
#

.global SetInterruptMask
.balign 4
SetInterruptMask:
/* 0x8024F640 | size=0x2D8 (728 bytes) */
    cntlzw  r0,r3
    cmpwi   r0,12
    bge-	.L_8024F66C
    cmpwi   r0,8
    beq-	.L_8024F74C
    bge-	.L_8024F77C
    cmpwi   r0,5
    bge-	.L_8024F6F8
    cmpwi   r0,0
    bge-	.L_8024F68C
    b	.L_8024F914
.L_8024F66C:
    cmpwi   r0,17
    bge-	.L_8024F680
    cmpwi   r0,15
    bge-	.L_8024F820
    b	.L_8024F7CC
.L_8024F680:
    cmpwi   r0,27
    bge-	.L_8024F914
    b	.L_8024F860
.L_8024F68C:
    clrrwi  r0,r4,31
    cmplwi  r0,0
    li      r5,0
    bne-	.L_8024F6A0
    ori     r5,r5,1
.L_8024F6A0:
    rlwinm  r0,r4,0,1,1
    cmplwi  r0,0
    bne-	.L_8024F6B0
    ori     r5,r5,2
.L_8024F6B0:
    rlwinm  r0,r4,0,2,2
    cmplwi  r0,0
    bne-	.L_8024F6C0
    ori     r5,r5,4
.L_8024F6C0:
    rlwinm  r0,r4,0,3,3
    cmplwi  r0,0
    bne-	.L_8024F6D0
    ori     r5,r5,8
.L_8024F6D0:
    rlwinm  r0,r4,0,4,4
    cmplwi  r0,0
    bne-	.L_8024F6E0
    ori     r5,r5,16
.L_8024F6E0:
    lis     r4,-13312
    clrlwi  r0,r5,16
    addi    r4,r4,16384
    sth     r0,28(r4)
    clrlwi  r3,r3,5
    b	.L_8024F914
.L_8024F6F8:
    lis     r5,-13312
    addi    r5,r5,20480
    addi    r5,r5,10
    rlwinm  r0,r4,0,5,5
    lhz     r6,0(r5)
    cmplwi  r0,0
    rlwinm  r6,r6,0,29,22
    bne-	.L_8024F71C
    ori     r6,r6,16
.L_8024F71C:
    rlwinm  r0,r4,0,6,6
    cmplwi  r0,0
    bne-	.L_8024F72C
    ori     r6,r6,64
.L_8024F72C:
    rlwinm  r0,r4,0,7,7
    cmplwi  r0,0
    bne-	.L_8024F73C
    ori     r6,r6,256
.L_8024F73C:
    clrlwi  r0,r6,16
    sth     r0,0(r5)
    rlwinm  r3,r3,0,8,4
    b	.L_8024F914
.L_8024F74C:
    rlwinm  r0,r4,0,8,8
    lis     r4,-13312
    cmplwi  r0,0
    lwz     r5,27648(r4)
    li      r0,-45
    and     r5,r5,r0
    bne-	.L_8024F76C
    ori     r5,r5,4
.L_8024F76C:
    lis     r4,-13312
    stw     r5,27648(r4)
    rlwinm  r3,r3,0,9,7
    b	.L_8024F914
.L_8024F77C:
    rlwinm  r0,r4,0,9,9
    lis     r5,-13312
    cmplwi  r0,0
    lwz     r5,26624(r5)
    li      r0,-11280
    and     r5,r5,r0
    bne-	.L_8024F79C
    ori     r5,r5,1
.L_8024F79C:
    rlwinm  r0,r4,0,10,10
    cmplwi  r0,0
    bne-	.L_8024F7AC
    ori     r5,r5,4
.L_8024F7AC:
    rlwinm  r0,r4,0,11,11
    cmplwi  r0,0
    bne-	.L_8024F7BC
    ori     r5,r5,1024
.L_8024F7BC:
    lis     r4,-13312
    stw     r5,26624(r4)
    rlwinm  r3,r3,0,12,8
    b	.L_8024F914
.L_8024F7CC:
    lis     r5,-13312
    addi    r6,r5,26624
    addi    r6,r6,20
    rlwinm  r0,r4,0,12,12
    lwz     r7,0(r6)
    li      r5,-3088
    cmplwi  r0,0
    and     r7,r7,r5
    bne-	.L_8024F7F4
    ori     r7,r7,1
.L_8024F7F4:
    rlwinm  r0,r4,0,13,13
    cmplwi  r0,0
    bne-	.L_8024F804
    ori     r7,r7,4
.L_8024F804:
    rlwinm  r0,r4,0,14,14
    cmplwi  r0,0
    bne-	.L_8024F814
    ori     r7,r7,1024
.L_8024F814:
    stw     r7,0(r6)
    rlwinm  r3,r3,0,15,11
    b	.L_8024F914
.L_8024F820:
    lis     r5,-13312
    addi    r5,r5,26624
    addi    r5,r5,40
    rlwinm  r0,r4,0,15,15
    lwz     r6,0(r5)
    cmplwi  r0,0
    clrrwi  r6,r6,4
    bne-	.L_8024F844
    ori     r6,r6,1
.L_8024F844:
    rlwinm  r0,r4,0,16,16
    cmplwi  r0,0
    bne-	.L_8024F854
    ori     r6,r6,4
.L_8024F854:
    stw     r6,0(r5)
    rlwinm  r3,r3,0,17,14
    b	.L_8024F914
.L_8024F860:
    rlwinm  r0,r4,0,17,17
    cmplwi  r0,0
    li      r5,240
    bne-	.L_8024F874
    ori     r5,r5,2048
.L_8024F874:
    rlwinm  r0,r4,0,20,20
    cmplwi  r0,0
    bne-	.L_8024F884
    ori     r5,r5,8
.L_8024F884:
    rlwinm  r0,r4,0,21,21
    cmplwi  r0,0
    bne-	.L_8024F894
    ori     r5,r5,4
.L_8024F894:
    rlwinm  r0,r4,0,22,22
    cmplwi  r0,0
    bne-	.L_8024F8A4
    ori     r5,r5,2
.L_8024F8A4:
    rlwinm  r0,r4,0,23,23
    cmplwi  r0,0
    bne-	.L_8024F8B4
    ori     r5,r5,1
.L_8024F8B4:
    rlwinm  r0,r4,0,24,24
    cmplwi  r0,0
    bne-	.L_8024F8C4
    ori     r5,r5,256
.L_8024F8C4:
    rlwinm  r0,r4,0,25,25
    cmplwi  r0,0
    bne-	.L_8024F8D4
    ori     r5,r5,4096
.L_8024F8D4:
    rlwinm  r0,r4,0,18,18
    cmplwi  r0,0
    bne-	.L_8024F8E4
    ori     r5,r5,512
.L_8024F8E4:
    rlwinm  r0,r4,0,19,19
    cmplwi  r0,0
    bne-	.L_8024F8F4
    ori     r5,r5,1024
.L_8024F8F4:
    rlwinm  r0,r4,0,26,26
    cmplwi  r0,0
    bne-	.L_8024F904
    ori     r5,r5,8192
.L_8024F904:
    lis     r4,-13312
    addi    r4,r4,12288
    stw     r5,4(r4)
    rlwinm  r3,r3,0,27,16
.L_8024F914:
    blr
.size SetInterruptMask, . - SetInterruptMask

.global __OSDispatchInterrupt
.balign 4
__OSDispatchInterrupt:
/* 0x8024FAC4 | size=0x344 (836 bytes) */
    mflr    r0
    stw     r0,4(r1)
    stwu    r1,-40(r1)
    stw     r31,36(r1)
    stw     r30,32(r1)
    stw     r29,28(r1)
    mr      r30,r4
    lis     r3,-13312
    lwz     r31,12288(r3)
    rlwinm  r31,r31,0,16,14
    cmplwi  r31,0
    beq-	.L_8024FB08
    addi    r3,r3,12288
    lwz     r0,4(r3)
    and     r0,r31,r0
    cmplwi  r0,0
    bne-	.L_8024FB10
.L_8024FB08:
    mr      r3,r30
    bl	OSLoadContext
.L_8024FB10:
    rlwinm  r0,r31,0,24,24
    cmplwi  r0,0
    li      r0,0
    beq-	.L_8024FB7C
    lis     r3,-13312
    addi    r3,r3,16384
    lhz     r4,30(r3)
    clrlwi  r3,r4,31
    cmplwi  r3,0
    beq-	.L_8024FB3C
    oris    r0,r0,32768
.L_8024FB3C:
    rlwinm  r3,r4,0,30,30
    cmplwi  r3,0
    beq-	.L_8024FB4C
    oris    r0,r0,16384
.L_8024FB4C:
    rlwinm  r3,r4,0,29,29
    cmplwi  r3,0
    beq-	.L_8024FB5C
    oris    r0,r0,8192
.L_8024FB5C:
    rlwinm  r3,r4,0,28,28
    cmplwi  r3,0
    beq-	.L_8024FB6C
    oris    r0,r0,4096
.L_8024FB6C:
    rlwinm  r3,r4,0,27,27
    cmplwi  r3,0
    beq-	.L_8024FB7C
    oris    r0,r0,2048
.L_8024FB7C:
    rlwinm  r3,r31,0,25,25
    cmplwi  r3,0
    beq-	.L_8024FBC4
    lis     r3,-13312
    addi    r3,r3,20480
    lhz     r4,10(r3)
    rlwinm  r3,r4,0,28,28
    cmplwi  r3,0
    beq-	.L_8024FBA4
    oris    r0,r0,1024
.L_8024FBA4:
    rlwinm  r3,r4,0,26,26
    cmplwi  r3,0
    beq-	.L_8024FBB4
    oris    r0,r0,512
.L_8024FBB4:
    rlwinm  r3,r4,0,24,24
    cmplwi  r3,0
    beq-	.L_8024FBC4
    oris    r0,r0,256
.L_8024FBC4:
    rlwinm  r3,r31,0,26,26
    cmplwi  r3,0
    beq-	.L_8024FBE8
    lis     r3,-13312
    lwz     r3,27648(r3)
    rlwinm  r3,r3,0,28,28
    cmplwi  r3,0
    beq-	.L_8024FBE8
    oris    r0,r0,128
.L_8024FBE8:
    rlwinm  r3,r31,0,27,27
    cmplwi  r3,0
    beq-	.L_8024FC94
    lis     r3,-13312
    lwz     r4,26624(r3)
    rlwinm  r3,r4,0,30,30
    cmplwi  r3,0
    beq-	.L_8024FC0C
    oris    r0,r0,64
.L_8024FC0C:
    rlwinm  r3,r4,0,28,28
    cmplwi  r3,0
    beq-	.L_8024FC1C
    oris    r0,r0,32
.L_8024FC1C:
    rlwinm  r3,r4,0,20,20
    cmplwi  r3,0
    beq-	.L_8024FC2C
    oris    r0,r0,16
.L_8024FC2C:
    lis     r3,-13312
    addi    r3,r3,26624
    lwz     r4,20(r3)
    rlwinm  r3,r4,0,30,30
    cmplwi  r3,0
    beq-	.L_8024FC48
    oris    r0,r0,8
.L_8024FC48:
    rlwinm  r3,r4,0,28,28
    cmplwi  r3,0
    beq-	.L_8024FC58
    oris    r0,r0,4
.L_8024FC58:
    rlwinm  r3,r4,0,20,20
    cmplwi  r3,0
    beq-	.L_8024FC68
    oris    r0,r0,2
.L_8024FC68:
    lis     r3,-13312
    addi    r3,r3,26624
    lwz     r4,40(r3)
    rlwinm  r3,r4,0,30,30
    cmplwi  r3,0
    beq-	.L_8024FC84
    oris    r0,r0,1
.L_8024FC84:
    rlwinm  r3,r4,0,28,28
    cmplwi  r3,0
    beq-	.L_8024FC94
    ori     r0,r0,32768
.L_8024FC94:
    rlwinm  r3,r31,0,18,18
    cmplwi  r3,0
    beq-	.L_8024FCA4
    ori     r0,r0,32
.L_8024FCA4:
    rlwinm  r3,r31,0,19,19
    cmplwi  r3,0
    beq-	.L_8024FCB4
    ori     r0,r0,64
.L_8024FCB4:
    rlwinm  r3,r31,0,21,21
    cmplwi  r3,0
    beq-	.L_8024FCC4
    ori     r0,r0,4096
.L_8024FCC4:
    rlwinm  r3,r31,0,22,22
    cmplwi  r3,0
    beq-	.L_8024FCD4
    ori     r0,r0,8192
.L_8024FCD4:
    rlwinm  r3,r31,0,23,23
    cmplwi  r3,0
    beq-	.L_8024FCE4
    ori     r0,r0,128
.L_8024FCE4:
    rlwinm  r3,r31,0,28,28
    cmplwi  r3,0
    beq-	.L_8024FCF4
    ori     r0,r0,2048
.L_8024FCF4:
    rlwinm  r3,r31,0,29,29
    cmplwi  r3,0
    beq-	.L_8024FD04
    ori     r0,r0,1024
.L_8024FD04:
    rlwinm  r3,r31,0,30,30
    cmplwi  r3,0
    beq-	.L_8024FD14
    ori     r0,r0,512
.L_8024FD14:
    rlwinm  r3,r31,0,20,20
    cmplwi  r3,0
    beq-	.L_8024FD24
    ori     r0,r0,16384
.L_8024FD24:
    clrlwi  r3,r31,31
    cmplwi  r3,0
    beq-	.L_8024FD34
    ori     r0,r0,256
.L_8024FD34:
    lis     r3,-32768
    lwz     r4,196(r3)
    lwz     r3,200(r3)
    or      r3,r4,r3
    andc    r4,r0,r3
    cmplwi  r4,0
    beq-	.L_8024FDE4
    lis     r3,-32700
    addi    r0,r3,-18696
    mr      r3,r0
    b	.L_8024FD60
.L_8024FD60:
    b	.L_8024FD64
.L_8024FD64:
    lwz     r0,0(r3)
    and     r0,r4,r0
    cmplwi  r0,0
    beq-	.L_8024FD80
    cntlzw  r0,r0
    extsh   r29,r0
    b	.L_8024FD88
.L_8024FD80:
    addi    r3,r3,4
    b	.L_8024FD64
.L_8024FD88:
    lwz     r3,-23664(r13)
    slwi    r0,r29,2
    lwzx    r31,r3,r0
    cmplwi  r31,0
    beq-	.L_8024FDE4
    cmpwi   r29,4
    ble-	.L_8024FDBC
    sth     r29,-23656(r13)
    bl	OSGetTime
    stw     r4,-23644(r13)
    stw     r3,-23648(r13)
    lwz     r0,408(r30)
    stw     r0,-23660(r13)
.L_8024FDBC:
    bl	OSDisableScheduler
    mr      r3,r29
    mr      r4,r30
    mr      r12,r31
    mtlr    r12
    blrl
    bl	OSEnableScheduler
    bl	__OSReschedule
    mr      r3,r30
    bl	OSLoadContext
.L_8024FDE4:
    mr      r3,r30
    bl	OSLoadContext
    lwz     r0,44(r1)
    lwz     r31,36(r1)
    lwz     r30,32(r1)
    lwz     r29,28(r1)
    addi    r1,r1,40
    mtlr    r0
    blr
.size __OSDispatchInterrupt, . - __OSDispatchInterrupt

#
# === OSLink.o (os.a) ===
#

.global Relocate
.balign 4
Relocate:
/* 0x8024FE6C | size=0x2BC (700 bytes) */
    mflr    r0
    stw     r0,4(r1)
    stwu    r1,-64(r1)
    stmw    r23,28(r1)
    mr.     r26,r3
    addi    r27,r4,0
    beq-	.L_8024FE90
    lwz     r31,0(r26)
    b	.L_8024FE94
.L_8024FE90:
    li      r31,0
.L_8024FE94:
    lwz     r3,40(r27)
    lwz     r0,44(r27)
    addi    r4,r3,0
    add     r3,r3,r0
    addi    r0,r3,7
    subf    r0,r4,r0
    srwi    r0,r0,3
    cmplw   r4,r3
    mtctr   r0
    bge-	.L_8024FED0
.L_8024FEBC:
    lwz     r0,0(r4)
    cmplw   r0,r31
    beq-	.L_8024FED8
    addi    r4,r4,8
    bdnz+	.L_8024FEBC
.L_8024FED0:
    li      r3,0
    b	.L_80250114
.L_8024FED8:
    lis     r3,-32700
    lwz     r30,4(r4)
    addi    r25,r3,-18648
    li      r29,0
    b	.L_802500DC
.L_8024FEEC:
    lhz     r0,0(r30)
    cmplwi  r31,0
    add     r28,r28,r0
    beq-	.L_8024FF14
    lbz     r0,3(r30)
    lwz     r3,16(r26)
    slwi    r0,r0,3
    lwzx    r0,r3,r0
    clrrwi  r5,r0,1
    b	.L_8024FF18
.L_8024FF14:
    li      r5,0
.L_8024FF18:
    cmpwi   r4,6
    beq-	.L_8024FFE0
    bge-	.L_8024FF50
    cmpwi   r4,2
    beq-	.L_8024FF90
    bge-	.L_8024FF40
    cmpwi   r4,0
    beq-	.L_802500D8
    bge-	.L_8024FF80
    b	.L_802500CC
.L_8024FF40:
    cmpwi   r4,4
    beq-	.L_8024FFBC
    bge-	.L_8024FFCC
    b	.L_8024FFAC
.L_8024FF50:
    cmpwi   r4,201
    beq-	.L_802500D8
    bge-	.L_8024FF74
    cmpwi   r4,10
    beq-	.L_80250028
    blt-	.L_8025000C
    cmpwi   r4,14
    bge-	.L_802500CC
    b	.L_80250048
.L_8024FF74:
    cmpwi   r4,203
    bge-	.L_802500CC
    b	.L_80250068
.L_8024FF80:
    lwz     r0,4(r30)
    add     r0,r5,r0
    stw     r0,0(r28)
    b	.L_802500D8
.L_8024FF90:
    lwz     r0,4(r30)
    lwz     r3,0(r28)
    add     r0,r5,r0
    rlwinm  r3,r3,0,30,5
    rlwimi  r3,r0,0,6,29
    stw     r3,0(r28)
    b	.L_802500D8
.L_8024FFAC:
    lwz     r0,4(r30)
    add     r0,r5,r0
    sth     r0,0(r28)
    b	.L_802500D8
.L_8024FFBC:
    lwz     r0,4(r30)
    add     r0,r5,r0
    sth     r0,0(r28)
    b	.L_802500D8
.L_8024FFCC:
    lwz     r0,4(r30)
    add     r0,r5,r0
    srwi    r0,r0,16
    sth     r0,0(r28)
    b	.L_802500D8
.L_8024FFE0:
    lwz     r0,4(r30)
    add     r4,r5,r0
    rlwinm. r0,r4,0,16,16
    beq-	.L_8024FFF8
    li      r3,1
    b	.L_8024FFFC
.L_8024FFF8:
    li      r3,0
.L_8024FFFC:
    srwi    r0,r4,16
    add     r0,r0,r3
    sth     r0,0(r28)
    b	.L_802500D8
.L_8025000C:
    lwz     r0,4(r30)
    lwz     r3,0(r28)
    add     r0,r5,r0
    rlwinm  r3,r3,0,30,15
    rlwimi  r3,r0,0,16,29
    stw     r3,0(r28)
    b	.L_802500D8
.L_80250028:
    lwz     r0,4(r30)
    lwz     r3,0(r28)
    add     r0,r5,r0
    subf    r0,r28,r0
    rlwinm  r3,r3,0,30,5
    rlwimi  r3,r0,0,6,29
    stw     r3,0(r28)
    b	.L_802500D8
.L_80250048:
    lwz     r0,4(r30)
    lwz     r3,0(r28)
    add     r0,r5,r0
    subf    r0,r28,r0
    rlwinm  r3,r3,0,30,15
    rlwimi  r3,r0,0,16,29
    stw     r3,0(r28)
    b	.L_802500D8
.L_80250068:
    lbz     r0,3(r30)
    cmplwi  r29,0
    lwz     r3,16(r27)
    slwi    r0,r0,3
    add     r3,r3,r0
    lwz     r0,0(r3)
    addi    r23,r3,0
    clrrwi  r28,r0,1
    beq-	.L_802500AC
    lwz     r0,0(r29)
    lwz     r4,4(r29)
    clrrwi  r24,r0,1
    addi    r3,r24,0
    bl	DCFlushRange
    mr      r3,r24
    lwz     r4,4(r29)
    bl	ICInvalidateRange
.L_802500AC:
    lwz     r0,0(r23)
    clrlwi. r0,r0,31
    beq-	.L_802500C0
    mr      r0,r23
    b	.L_802500C4
.L_802500C0:
    li      r0,0
.L_802500C4:
    mr      r29,r0
    b	.L_802500D8
.L_802500CC:
    addi    r3,r25,0
    crclr   4*cr1+eq
    bl	OSReport
.L_802500D8:
    addi    r30,r30,8
.L_802500DC:
    lbz     r4,2(r30)
    cmplwi  r4,203
    bne+	.L_8024FEEC
    cmplwi  r29,0
    beq-	.L_80250110
    lwz     r0,0(r29)
    lwz     r4,4(r29)
    clrrwi  r25,r0,1
    addi    r3,r25,0
    bl	DCFlushRange
    mr      r3,r25
    lwz     r4,4(r29)
    bl	ICInvalidateRange
.L_80250110:
    li      r3,1
.L_80250114:
    lmw     r23,28(r1)
    lwz     r0,68(r1)
    addi    r1,r1,64
    mtlr    r0
    blr
.size Relocate, . - Relocate

.global Link
.balign 4
Link:
/* 0x80250128 | size=0x2E0 (736 bytes) */
    mflr    r0
    stw     r0,4(r1)
    li      r0,0
    stwu    r1,-40(r1)
    stw     r31,36(r1)
    addi    r31,r3,0
    stw     r30,32(r1)
    addi    r30,r5,0
    stw     r29,28(r1)
    addi    r29,r4,0
    stw     r28,24(r1)
    stb     r0,51(r3)
    lwz     r0,28(r3)
    cmplwi  r0,3
    bgt-	.L_802501A4
    cmplwi  r0,2
    blt-	.L_802501AC
    lwz     r3,64(r31)
    cmplwi  r3,0
    beq-	.L_80250188
    divwu   r0,r31,r3
    mullw   r0,r0,r3
    subf.   r0,r0,r31
    bne-	.L_802501A4
.L_80250188:
    lwz     r3,68(r31)
    cmplwi  r3,0
    beq-	.L_802501AC
    divwu   r0,r29,r3
    mullw   r0,r0,r3
    subf.   r0,r0,r29
    beq-	.L_802501AC
.L_802501A4:
    li      r3,0
    b	.L_802503E8
.L_802501AC:
    lis     r3,-32768
    addi    r4,r3,12488
    lwzu    r5,4(r4)
    cmplwi  r5,0
    bne-	.L_802501C8
    stw     r31,12488(r3)
    b	.L_802501CC
.L_802501C8:
    stw     r31,4(r5)
.L_802501CC:
    stw     r5,8(r31)
    li      r0,0
    stw     r0,4(r31)
    stw     r31,0(r4)
    lwz     r0,16(r31)
    add     r0,r0,r31
    stw     r0,16(r31)
    lwz     r0,36(r31)
    add     r0,r0,r31
    stw     r0,36(r31)
    lwz     r0,40(r31)
    add     r0,r0,r31
    stw     r0,40(r31)
    lwz     r0,28(r31)
    cmplwi  r0,3
    blt-	.L_80250218
    lwz     r0,72(r31)
    add     r0,r0,r31
    stw     r0,72(r31)
.L_80250218:
    li      r5,1
    li      r3,8
    b	.L_80250260
.L_80250224:
    lwz     r0,16(r31)
    add     r4,r0,r3
    lwz     r0,0(r4)
    cmplwi  r0,0
    beq-	.L_80250244
    add     r0,r0,r31
    stw     r0,0(r4)
    b	.L_80250258
.L_80250244:
    lwz     r0,4(r4)
    cmplwi  r0,0
    beq-	.L_80250258
    stb     r5,51(r31)
    stw     r29,0(r4)
.L_80250258:
    addi    r3,r3,8
    addi    r5,r5,1
.L_80250260:
    lwz     r0,12(r31)
    cmplw   r5,r0
    blt+	.L_80250224
    lwz     r4,40(r31)
    b	.L_80250284
.L_80250274:
    lwz     r0,4(r4)
    add     r0,r0,r31
    stw     r0,4(r4)
    addi    r4,r4,8
.L_80250284:
    lwz     r3,40(r31)
    lwz     r0,44(r31)
    add     r0,r3,r0
    cmplw   r4,r0
    blt+	.L_80250274
    lbz     r0,48(r31)
    cmplwi  r0,0
    beq-	.L_802502C0
    lwz     r3,16(r31)
    slwi    r0,r0,3
    lwz     r4,52(r31)
    lwzx    r0,r3,r0
    clrrwi  r0,r0,1
    add     r0,r4,r0
    stw     r0,52(r31)
.L_802502C0:
    lbz     r0,49(r31)
    cmplwi  r0,0
    beq-	.L_802502E8
    lwz     r3,16(r31)
    slwi    r0,r0,3
    lwz     r4,56(r31)
    lwzx    r0,r3,r0
    clrrwi  r0,r0,1
    add     r0,r4,r0
    stw     r0,56(r31)
.L_802502E8:
    lbz     r0,50(r31)
    cmplwi  r0,0
    beq-	.L_80250310
    lwz     r3,16(r31)
    slwi    r0,r0,3
    lwz     r4,60(r31)
    lwzx    r0,r3,r0
    clrrwi  r0,r0,1
    add     r0,r4,r0
    stw     r0,60(r31)
.L_80250310:
    lis     r3,-32768
    lwz     r3,12496(r3)
    cmplwi  r3,0
    beq-	.L_8025032C
    lwz     r0,20(r31)
    add     r0,r0,r3
    stw     r0,20(r31)
.L_8025032C:
    li      r3,0
    addi    r4,r31,0
    bl	Relocate
    lis     r3,-32768
    lwz     r28,12488(r3)
    b	.L_80250368
.L_80250344:
    addi    r3,r31,0
    addi    r4,r28,0
    bl	Relocate
    cmplw   r28,r31
    beq-	.L_80250364
    addi    r3,r28,0
    addi    r4,r31,0
    bl	Relocate
.L_80250364:
    lwz     r28,4(r28)
.L_80250368:
    cmplwi  r28,0
    bne+	.L_80250344
    cmpwi   r30,0
    beq-	.L_802503CC
    lwz     r4,40(r31)
    lwz     r0,44(r31)
    addi    r5,r4,0
    add     r3,r4,r0
    addi    r0,r3,7
    subf    r0,r5,r0
    srwi    r0,r0,3
    cmplw   r5,r3
    mtctr   r0
    bge-	.L_802503CC
.L_802503A0:
    lwz     r3,0(r5)
    cmplwi  r3,0
    beq-	.L_802503B8
    lwz     r0,0(r31)
    cmplw   r3,r0
    bne-	.L_802503C4
.L_802503B8:
    subf    r0,r4,r5
    stw     r0,44(r31)
    b	.L_802503CC
.L_802503C4:
    addi    r5,r5,8
    bdnz+	.L_802503A0
.L_802503CC:
    lwz     r5,32(r31)
    addi    r3,r29,0
    li      r4,0
    bl	memset
    mr      r3,r31
    bl	OSNotifyLink
    li      r3,1
.L_802503E8:
    lwz     r0,44(r1)
    lwz     r31,36(r1)
    lwz     r30,32(r1)
    lwz     r29,28(r1)
    lwz     r28,24(r1)
    addi    r1,r1,40
    mtlr    r0
    blr
.size Link, . - Link

.global Undo
.balign 4
Undo:
/* 0x80250468 | size=0x238 (568 bytes) */
    mflr    r0
    stw     r0,4(r1)
    stwu    r1,-56(r1)
    stmw    r25,28(r1)
    mr      r28,r4
    lwz     r4,0(r3)
    lwz     r3,40(r28)
    lwz     r0,44(r28)
    addi    r5,r3,0
    add     r3,r3,r0
    addi    r0,r3,7
    subf    r0,r5,r0
    srwi    r0,r0,3
    cmplw   r5,r3
    mtctr   r0
    bge-	.L_802504BC
.L_802504A8:
    lwz     r0,0(r5)
    cmplw   r0,r4
    beq-	.L_802504C4
    addi    r5,r5,8
    bdnz+	.L_802504A8
.L_802504BC:
    li      r3,0
    b	.L_8025068C
.L_802504C4:
    lis     r3,-32700
    lwz     r31,4(r5)
    addi    r27,r3,-18608
    li      r30,0
    b	.L_80250654
.L_802504D8:
    lhz     r0,0(r31)
    cmpwi   r4,6
    li      r3,0
    add     r29,r29,r0
    beq-	.L_8025058C
    bge-	.L_8025051C
    cmpwi   r4,2
    beq-	.L_80250558
    bge-	.L_8025050C
    cmpwi   r4,0
    beq-	.L_80250650
    bge-	.L_8025054C
    b	.L_80250644
.L_8025050C:
    cmpwi   r4,4
    beq-	.L_80250574
    bge-	.L_80250580
    b	.L_80250568
.L_8025051C:
    cmpwi   r4,201
    beq-	.L_80250650
    bge-	.L_80250540
    cmpwi   r4,10
    beq-	.L_802505A8
    blt-	.L_80250598
    cmpwi   r4,14
    bge-	.L_80250644
    b	.L_802505D0
.L_80250540:
    cmpwi   r4,203
    bge-	.L_80250644
    b	.L_802505E0
.L_8025054C:
    li      r0,0
    stw     r0,0(r29)
    b	.L_80250650
.L_80250558:
    lwz     r0,0(r29)
    rlwinm  r0,r0,0,30,5
    stw     r0,0(r29)
    b	.L_80250650
.L_80250568:
    li      r0,0
    sth     r0,0(r29)
    b	.L_80250650
.L_80250574:
    li      r0,0
    sth     r0,0(r29)
    b	.L_80250650
.L_80250580:
    li      r0,0
    sth     r0,0(r29)
    b	.L_80250650
.L_8025058C:
    li      r0,0
    sth     r0,0(r29)
    b	.L_80250650
.L_80250598:
    lwz     r0,0(r29)
    rlwinm  r0,r0,0,30,15
    stw     r0,0(r29)
    b	.L_80250650
.L_802505A8:
    lbz     r0,50(r28)
    cmplwi  r0,0
    beq-	.L_802505BC
    lwz     r0,60(r28)
    subf    r3,r29,r0
.L_802505BC:
    lwz     r0,0(r29)
    rlwinm  r0,r0,0,30,5
    rlwimi  r0,r3,0,6,29
    stw     r0,0(r29)
    b	.L_80250650
.L_802505D0:
    lwz     r0,0(r29)
    rlwinm  r0,r0,0,30,15
    stw     r0,0(r29)
    b	.L_80250650
.L_802505E0:
    lbz     r0,3(r31)
    cmplwi  r30,0
    lwz     r3,16(r28)
    slwi    r0,r0,3
    add     r3,r3,r0
    lwz     r0,0(r3)
    addi    r26,r3,0
    clrrwi  r29,r0,1
    beq-	.L_80250624
    lwz     r0,0(r30)
    lwz     r4,4(r30)
    clrrwi  r25,r0,1
    addi    r3,r25,0
    bl	DCFlushRange
    mr      r3,r25
    lwz     r4,4(r30)
    bl	ICInvalidateRange
.L_80250624:
    lwz     r0,0(r26)
    clrlwi. r0,r0,31
    beq-	.L_80250638
    mr      r0,r26
    b	.L_8025063C
.L_80250638:
    li      r0,0
.L_8025063C:
    mr      r30,r0
    b	.L_80250650
.L_80250644:
    addi    r3,r27,0
    crclr   4*cr1+eq
    bl	OSReport
.L_80250650:
    addi    r31,r31,8
.L_80250654:
    lbz     r4,2(r31)
    cmplwi  r4,203
    bne+	.L_802504D8
    cmplwi  r30,0
    beq-	.L_80250688
    lwz     r0,0(r30)
    lwz     r4,4(r30)
    clrrwi  r27,r0,1
    addi    r3,r27,0
    bl	DCFlushRange
    mr      r3,r27
    lwz     r4,4(r30)
    bl	ICInvalidateRange
.L_80250688:
    li      r3,1
.L_8025068C:
    lmw     r25,28(r1)
    lwz     r0,60(r1)
    addi    r1,r1,56
    mtlr    r0
    blr
.size Undo, . - Undo

.global OSUnlink
.balign 4
OSUnlink:
/* 0x802506A0 | size=0x1D4 (468 bytes) */
    mflr    r0
    stw     r0,4(r1)
    stwu    r1,-24(r1)
    stw     r31,20(r1)
    mr      r31,r3
    stw     r30,16(r1)
    lwz     r4,4(r3)
    lwz     r5,8(r3)
    cmplwi  r4,0
    bne-	.L_802506D4
    lis     r3,-32768
    stw     r5,12492(r3)
    b	.L_802506D8
.L_802506D4:
    stw     r5,8(r4)
.L_802506D8:
    cmplwi  r5,0
    bne-	.L_802506EC
    lis     r3,-32768
    stw     r4,12488(r3)
    b	.L_802506F0
.L_802506EC:
    stw     r4,4(r5)
.L_802506F0:
    lis     r3,-32768
    lwz     r30,12488(r3)
    b	.L_8025070C
.L_802506FC:
    addi    r3,r31,0
    addi    r4,r30,0
    bl	Undo
    lwz     r30,4(r30)
.L_8025070C:
    cmplwi  r30,0
    bne+	.L_802506FC
    mr      r3,r31
    bl	OSNotifyUnlink
    lis     r3,-32768
    lwz     r3,12496(r3)
    cmplwi  r3,0
    beq-	.L_80250738
    lwz     r0,20(r31)
    subf    r0,r3,r0
    stw     r0,20(r31)
.L_80250738:
    lbz     r0,48(r31)
    cmplwi  r0,0
    beq-	.L_80250760
    lwz     r4,16(r31)
    slwi    r3,r0,3
    lwz     r0,52(r31)
    lwzx    r3,r4,r3
    clrrwi  r3,r3,1
    subf    r0,r3,r0
    stw     r0,52(r31)
.L_80250760:
    lbz     r0,49(r31)
    cmplwi  r0,0
    beq-	.L_80250788
    lwz     r4,16(r31)
    slwi    r3,r0,3
    lwz     r0,56(r31)
    lwzx    r3,r4,r3
    clrrwi  r3,r3,1
    subf    r0,r3,r0
    stw     r0,56(r31)
.L_80250788:
    lbz     r0,50(r31)
    cmplwi  r0,0
    beq-	.L_802507B0
    lwz     r4,16(r31)
    slwi    r3,r0,3
    lwz     r0,60(r31)
    lwzx    r3,r4,r3
    clrrwi  r3,r3,1
    subf    r0,r3,r0
    stw     r0,60(r31)
.L_802507B0:
    lwz     r4,40(r31)
    b	.L_802507C8
.L_802507B8:
    lwz     r0,4(r4)
    subf    r0,r31,r0
    stw     r0,4(r4)
    addi    r4,r4,8
.L_802507C8:
    lwz     r3,40(r31)
    lwz     r0,44(r31)
    add     r0,r3,r0
    cmplw   r4,r0
    blt+	.L_802507B8
    li      r6,1
    li      r5,8
    li      r3,0
    b	.L_80250828
.L_802507EC:
    lbz     r0,51(r31)
    lwz     r4,16(r31)
    cmplw   r6,r0
    add     r4,r4,r5
    bne-	.L_8025080C
    stb     r3,51(r31)
    stw     r3,0(r4)
    b	.L_80250820
.L_8025080C:
    lwz     r0,0(r4)
    cmplwi  r0,0
    beq-	.L_80250820
    subf    r0,r31,r0
    stw     r0,0(r4)
.L_80250820:
    addi    r5,r5,8
    addi    r6,r6,1
.L_80250828:
    lwz     r0,12(r31)
    cmplw   r6,r0
    blt+	.L_802507EC
    lwz     r0,36(r31)
    li      r3,1
    subf    r0,r31,r0
    stw     r0,36(r31)
    lwz     r0,40(r31)
    subf    r0,r31,r0
    stw     r0,40(r31)
    lwz     r0,16(r31)
    subf    r0,r31,r0
    stw     r0,16(r31)
    lwz     r0,28(r1)
    lwz     r31,20(r1)
    lwz     r30,16(r1)
    addi    r1,r1,24
    mtlr    r0
    blr
.size OSUnlink, . - OSUnlink

#
# === OSMemory.o (os.a) ===
#

.global __OSInitMemoryProtection
.balign 4
__OSInitMemoryProtection:
/* 0x80250BC8 | size=0x118 (280 bytes) */
    mflr    r0
    stw     r0,4(r1)
    stwu    r1,-80(r1)
    stmw    r27,60(r1)
    lis     r27,-32768
    lwz     r31,240(r27)
    bl	OSDisableInterrupts
    lis     r4,-13312
    addi    r28,r4,16384
    li      r0,0
    sth     r0,32(r28)
    li      r0,255
    mr      r30,r3
    sth     r0,16(r28)
    lis     r3,-4096
    bl	__OSMaskInterrupts
    lis     r3,-32731
    addi    r29,r3,2432
    mr      r4,r29
    li      r3,0
    bl	__OSSetInterruptHandler
    mr      r4,r29
    li      r3,1
    bl	__OSSetInterruptHandler
    mr      r4,r29
    li      r3,2
    bl	__OSSetInterruptHandler
    mr      r4,r29
    li      r3,3
    bl	__OSSetInterruptHandler
    mr      r4,r29
    li      r3,4
    bl	__OSSetInterruptHandler
    lis     r3,-32700
    addi    r3,r3,-18568
    bl	OSRegisterResetFunction
    lwz     r3,240(r27)
    lwz     r0,40(r27)
    cmplw   r3,r0
    bge-	.L_80250C88
    addis   r0,r3,-384
    cmplwi  r0,0
    bne-	.L_80250C88
    lis     r3,-32384
    lis     r4,384
    bl	DCInvalidateRange
    li      r0,2
    sth     r0,40(r28)
.L_80250C88:
    lis     r0,384
    cmplw   r31,r0
    bgt-	.L_80250CA4
    lis     r3,-32731
    addi    r3,r3,2736
    bl	RealMode
    b	.L_80250CBC
.L_80250CA4:
    lis     r0,768
    cmplw   r31,r0
    bgt-	.L_80250CBC
    lis     r3,-32731
    addi    r3,r3,2864
    bl	RealMode
.L_80250CBC:
    lis     r3,2048
    bl	__OSUnmaskInterrupts
    mr      r3,r30
    bl	OSRestoreInterrupts
    lmw     r27,60(r1)
    lwz     r0,84(r1)
    addi    r1,r1,80
    mtlr    r0
    blr
.size __OSInitMemoryProtection, . - __OSInitMemoryProtection

#
# === OSReset.o (os.a) ===
#

.global __OSShutdownDevices
.balign 4
__OSShutdownDevices:
/* 0x80251010 | size=0x1B0 (432 bytes) */
    mflr    r0
    stw     r0,4(r1)
    stwu    r1,-40(r1)
    stw     r31,36(r1)
    stw     r30,32(r1)
    stw     r29,28(r1)
    stw     r28,24(r1)
    mr      r28,r3
    bl	__OSStopAudioSystem
    cmpwi   r28,0
    bne-	.L_80251048
    li      r3,1
    bl	__PADDisableRecalibration
    mr      r29,r3
.L_80251048:
    b	.L_8025104C
.L_8025104C:
    b	.L_80251050
.L_80251050:
    li      r3,0
    lwz     r30,-23632(r13)
    mr      r31,r3
    b	.L_80251060
.L_80251060:
    b	.L_80251064
.L_80251064:
    b	.L_802510A0
.L_80251068:
    cmpwi   r31,0
    beq-	.L_8025107C
    lwz     r0,4(r30)
    cmplw   r3,r0
    bne-	.L_802510A8
.L_8025107C:
    li      r3,0
    lwz     r12,0(r30)
    mtlr    r12
    blrl
    cntlzw  r0,r3
    lwz     r3,4(r30)
    srwi    r0,r0,5
    lwz     r30,8(r30)
    or      r31,r31,r0
.L_802510A0:
    cmplwi  r30,0
    bne+	.L_80251068
.L_802510A8:
    bl	__OSSyncSram
    cntlzw  r0,r3
    srwi    r0,r0,5
    or      r31,r31,r0
    cmpwi   r31,0
    beq-	.L_802510C8
    li      r0,0
    b	.L_802510CC
.L_802510C8:
    li      r0,1
.L_802510CC:
    cmpwi   r0,0
    beq+	.L_80251050
    b	.L_802510D8
.L_802510D8:
    b	.L_802510DC
.L_802510DC:
    bl	__OSSyncSram
    cmpwi   r3,0
    beq+	.L_802510DC
    bl	OSDisableInterrupts
    li      r3,0
    lwz     r31,-23632(r13)
    mr      r30,r3
    b	.L_802510FC
.L_802510FC:
    b	.L_80251100
.L_80251100:
    b	.L_8025113C
.L_80251104:
    cmpwi   r30,0
    beq-	.L_80251118
    lwz     r0,4(r31)
    cmplw   r3,r0
    bne-	.L_80251144
.L_80251118:
    li      r3,1
    lwz     r12,0(r31)
    mtlr    r12
    blrl
    cntlzw  r0,r3
    lwz     r3,4(r31)
    srwi    r0,r0,5
    lwz     r31,8(r31)
    or      r30,r30,r0
.L_8025113C:
    cmplwi  r31,0
    bne+	.L_80251104
.L_80251144:
    bl	__OSSyncSram
    bl	LCDisable
    cmpwi   r28,0
    bne-	.L_8025115C
    mr      r3,r29
    bl	__PADDisableRecalibration
.L_8025115C:
    lis     r3,-32768
    lwz     r3,220(r3)
    b	.L_80251168
.L_80251168:
    b	.L_8025116C
.L_8025116C:
    b	.L_80251198
.L_80251170:
    lhz     r0,712(r3)
    lwz     r30,764(r3)
    cmpwi   r0,4
    beq-	.L_80251190
    bge-	.L_80251194
    cmpwi   r0,1
    beq-	.L_80251190
    b	.L_80251194
.L_80251190:
    bl	OSCancelThread
.L_80251194:
    mr      r3,r30
.L_80251198:
    cmplwi  r3,0
    bne+	.L_80251170
    lwz     r0,44(r1)
    lwz     r31,36(r1)
    lwz     r30,32(r1)
    lwz     r29,28(r1)
    lwz     r28,24(r1)
    addi    r1,r1,40
    mtlr    r0
    blr
.size __OSShutdownDevices, . - __OSShutdownDevices

.global OSResetSystem
.balign 4
OSResetSystem:
/* 0x802511C0 | size=0x200 (512 bytes) */
    mflr    r0
    stw     r0,4(r1)
    stwu    r1,-48(r1)
    stw     r31,44(r1)
    stw     r30,40(r1)
    stw     r29,36(r1)
    stw     r28,32(r1)
    mr      r28,r3
    mr      r29,r4
    mr      r30,r5
    bl	OSDisableScheduler
    cmpwi   r28,1
    bne-	.L_80251218
    cmpwi   r30,0
    beq-	.L_80251218
    bl	__OSLockSram
    lbz     r0,19(r3)
    ori     r0,r0,64
    stb     r0,19(r3)
    li      r3,1
    bl	__OSUnlockSram
    li      r29,0
.L_80251218:
    cmpwi   r28,2
    beq-	.L_80251240
    cmpwi   r28,0
    bne-	.L_8025129C
    lwz     r0,-23624(r13)
    cmplwi  r0,0
    bne-	.L_80251240
    addis   r0,r29,16383
    cmplwi  r0,0
    bne-	.L_8025129C
.L_80251240:
    bl	__OSStopAudioSystem
    li      r3,1
    bl	__PADDisableRecalibration
    mr      r31,r3
    b	.L_80251254
.L_80251254:
    b	.L_80251258
.L_80251258:
    li      r3,0
    bl	__OSCallResetFunctions
    cmpwi   r3,0
    beq+	.L_80251258
    b	.L_8025126C
.L_8025126C:
    b	.L_80251270
.L_80251270:
    bl	__OSSyncSram
    cmpwi   r3,0
    beq+	.L_80251270
    bl	OSDisableInterrupts
    li      r3,1
    bl	__OSCallResetFunctions
    bl	LCDisable
    mr      r3,r31
    bl	__PADDisableRecalibration
    bl	KillThreads
    b	.L_802512E0
.L_8025129C:
    bl	__OSStopAudioSystem
    b	.L_802512A4
.L_802512A4:
    b	.L_802512A8
.L_802512A8:
    li      r3,0
    bl	__OSCallResetFunctions
    cmpwi   r3,0
    beq+	.L_802512A8
    b	.L_802512BC
.L_802512BC:
    b	.L_802512C0
.L_802512C0:
    bl	__OSSyncSram
    cmpwi   r3,0
    beq+	.L_802512C0
    bl	OSDisableInterrupts
    li      r3,1
    bl	__OSCallResetFunctions
    bl	LCDisable
    bl	KillThreads
.L_802512E0:
    cmpwi   r28,1
    bne-	.L_8025130C
    bl	OSDisableInterrupts
    lis     r3,-13312
    addi    r3,r3,8192
    li      r0,0
    sth     r0,2(r3)
    bl	ICFlashInvalidate
    slwi    r3,r29,3
    bl	Reset
    b	.L_8025133C
.L_8025130C:
    cmpwi   r28,0
    bne-	.L_8025133C
    cmpwi   r30,1
    bne-	.L_8025132C
    lis     r3,-32700
    crclr   4*cr1+eq
    addi    r3,r3,-18552
    bl	OSReport
.L_8025132C:
    bl	OSEnableScheduler
    mr      r3,r29
    lwz     r4,-23624(r13)
    bl	__OSReboot
.L_8025133C:
    lis     r31,-32768
    addi    r3,r31,64
    li      r4,0
    li      r5,140
    bl	memset
    addi    r3,r31,212
    li      r4,0
    li      r5,20
    bl	memset
    addi    r3,r31,244
    li      r4,0
    li      r5,4
    bl	memset
    addi    r3,r31,12288
    li      r4,0
    li      r5,192
    bl	memset
    addi    r3,r31,12488
    li      r4,0
    li      r5,12
    bl	memset
    addi    r3,r31,12514
    li      r4,0
    li      r5,1
    bl	memset
    lwz     r0,52(r1)
    lwz     r31,44(r1)
    lwz     r30,40(r1)
    lwz     r29,36(r1)
    lwz     r28,32(r1)
    addi    r1,r1,48
    mtlr    r0
    blr
.size OSResetSystem, . - OSResetSystem

#
# === OSResetSW.o (os.a) ===
#

.global OSGetResetButtonState
.balign 4
OSGetResetButtonState:
/* 0x80251570 | size=0x298 (664 bytes) */
    mflr    r0
    stw     r0,4(r1)
    stwu    r1,-24(r1)
    stw     r31,20(r1)
    stw     r30,16(r1)
    stw     r29,12(r1)
    bl	OSDisableInterrupts
    mr      r30,r3
    bl	__OSGetSystemTime
    lis     r5,-13312
    lwz     r0,12288(r5)
    rlwinm. r0,r0,0,15,15
    bne-	.L_8025167C
    lwz     r0,-23612(r13)
    cmpwi   r0,0
    bne-	.L_802515EC
    lwz     r0,-23600(r13)
    li      r6,0
    lwz     r5,-23596(r13)
    li      r7,1
    xor     r0,r0,r6
    xor     r5,r5,r6
    stw     r7,-23612(r13)
    or.     r0,r5,r0
    beq-	.L_802515D8
    b	.L_802515DC
.L_802515D8:
    mr      r7,r6
.L_802515DC:
    stw     r4,-23588(r13)
    mr      r29,r7
    stw     r3,-23592(r13)
    b	.L_80251730
.L_802515EC:
    lwz     r0,-23600(r13)
    li      r9,0
    lwz     r5,-23596(r13)
    li      r10,1
    xor     r0,r0,r9
    xor     r5,r5,r9
    or.     r0,r5,r0
    bne-	.L_80251660
    lis     r6,-32768
    lwz     r5,-23588(r13)
    lwz     r7,248(r6)
    lis     r6,17180
    addi    r8,r6,-8573
    lwz     r0,-23592(r13)
    srwi    r6,r7,2
    mulhwu  r6,r8,r6
    srwi    r6,r6,15
    mulli   r6,r6,100
    subfc   r7,r5,r4
    subfe   r0,r0,r3
    srwi    r8,r6,3
    xoris   r5,r0,32768
    xoris   r6,r9,32768
    subfc   r0,r7,r8
    subfe   r5,r5,r6
    subfe   r5,r6,r6
    neg.    r5,r5
    bne-	.L_80251660
    mr      r10,r9
.L_80251660:
    cmpwi   r10,0
    beq-	.L_80251670
    li      r0,1
    b	.L_80251674
.L_80251670:
    li      r0,0
.L_80251674:
    mr      r29,r0
    b	.L_80251730
.L_8025167C:
    lwz     r0,-23612(r13)
    cmpwi   r0,0
    beq-	.L_802516B8
    lwz     r5,-23608(r13)
    li      r0,0
    stw     r0,-23612(r13)
    cmpwi   r5,0
    addi    r29,r5,0
    beq-	.L_802516AC
    stw     r4,-23596(r13)
    stw     r3,-23600(r13)
    b	.L_80251730
.L_802516AC:
    stw     r0,-23596(r13)
    stw     r0,-23600(r13)
    b	.L_80251730
.L_802516B8:
    lwz     r6,-23600(r13)
    li      r8,0
    lwz     r7,-23596(r13)
    xor     r0,r6,r8
    xor     r5,r7,r8
    or.     r0,r5,r0
    beq-	.L_80251720
    lis     r5,-32768
    lwz     r0,248(r5)
    lis     r5,4194
    addi    r5,r5,19923
    srwi    r0,r0,2
    mulhwu  r0,r5,r0
    srwi    r0,r0,6
    mulli   r0,r0,40
    subfc   r7,r7,r4
    subfe   r5,r6,r3
    xoris   r6,r5,32768
    xoris   r5,r8,32768
    subfc   r0,r0,r7
    subfe   r5,r5,r6
    subfe   r5,r6,r6
    neg.    r5,r5
    beq-	.L_80251720
    li      r29,1
    b	.L_80251730
.L_80251720:
    li      r0,0
    stw     r0,-23596(r13)
    li      r29,0
    stw     r0,-23600(r13)
.L_80251730:
    lis     r5,-32768
    stw     r29,-23608(r13)
    lbz     r0,12515(r5)
    clrlwi. r0,r0,27
    beq-	.L_802517E0
    mulli   r10,r0,60
    lwz     r0,248(r5)
    lwz     r9,-23692(r13)
    lwz     r8,-23696(r13)
    srwi    r6,r0,2
    srawi   r0,r10,31
    mullw   r7,r0,r6
    mulhwu  r0,r10,r6
    mullw   r5,r10,r6
    addc    r9,r9,r5
    li      r31,0
    add     r7,r7,r0
    mullw   r0,r10,r31
    add     r0,r7,r0
    adde    r8,r8,r0
    xoris   r7,r8,32768
    xoris   r5,r3,32768
    subfc   r0,r4,r9
    subfe   r5,r5,r7
    subfe   r5,r7,r7
    neg.    r5,r5
    beq-	.L_802517E0
    subfc   r4,r9,r4
    subfe   r3,r8,r3
    li      r5,0
    bl	__div2i
    li      r5,0
    li      r6,2
    bl	__div2i
    li      r0,1
    and     r4,r4,r0
    and     r0,r3,r31
    xor     r3,r4,r31
    xor     r0,r0,r31
    or.     r0,r3,r0
    bne-	.L_802517DC
    li      r29,1
    b	.L_802517E0
.L_802517DC:
    li      r29,0
.L_802517E0:
    mr      r3,r30
    bl	OSRestoreInterrupts
    mr      r3,r29
    lwz     r0,28(r1)
    lwz     r31,20(r1)
    lwz     r30,16(r1)
    lwz     r29,12(r1)
    addi    r1,r1,24
    mtlr    r0
    blr
.size OSGetResetButtonState, . - OSGetResetButtonState

#
# === OSRtc.o (os.a) ===
#

.global GetRTC
.balign 4
GetRTC:
/* 0x80251884 | size=0x118 (280 bytes) */
    mflr    r0
    li      r4,1
    stw     r0,4(r1)
    li      r5,0
    stwu    r1,-24(r1)
    stw     r31,20(r1)
    stw     r30,16(r1)
    addi    r30,r3,0
    li      r3,0
    bl	EXILock
    cmpwi   r3,0
    bne-	.L_802518BC
    li      r3,0
    b	.L_80251984
.L_802518BC:
    li      r3,0
    li      r4,1
    li      r5,3
    bl	EXISelect
    cmpwi   r3,0
    bne-	.L_802518E4
    li      r3,0
    bl	EXIUnlock
    li      r3,0
    b	.L_80251984
.L_802518E4:
    lis     r0,8192
    stw     r0,12(r1)
    addi    r4,r1,12
    li      r3,0
    li      r5,4
    li      r6,1
    li      r7,0
    bl	EXIImm
    cntlzw  r0,r3
    srwi    r31,r0,5
    li      r3,0
    bl	EXISync
    cntlzw  r0,r3
    srwi    r0,r0,5
    or      r31,r31,r0
    addi    r4,r1,12
    li      r3,0
    li      r5,4
    li      r6,0
    li      r7,0
    bl	EXIImm
    cntlzw  r0,r3
    srwi    r0,r0,5
    or      r31,r31,r0
    li      r3,0
    bl	EXISync
    cntlzw  r0,r3
    srwi    r0,r0,5
    or      r31,r31,r0
    li      r3,0
    bl	EXIDeselect
    cntlzw  r0,r3
    srwi    r0,r0,5
    or      r31,r31,r0
    li      r3,0
    bl	EXIUnlock
    lwz     r4,12(r1)
    cntlzw  r0,r31
    srwi    r3,r0,5
    stw     r4,0(r30)
.L_80251984:
    lwz     r0,28(r1)
    lwz     r31,20(r1)
    lwz     r30,16(r1)
    addi    r1,r1,24
    mtlr    r0
    blr
.size GetRTC, . - GetRTC

.global __OSGetRTC
.balign 4
__OSGetRTC:
/* 0x8025199C | size=0x22C (556 bytes) */
    mflr    r0
    stw     r0,4(r1)
    stwu    r1,-48(r1)
    stmw    r26,24(r1)
    addi    r26,r3,0
    li      r27,0
    lis     r31,8192
.L_802519B8:
    li      r3,0
    li      r4,1
    li      r5,0
    bl	EXILock
    cmpwi   r3,0
    bne-	.L_802519D8
    li      r0,0
    b	.L_80251A98
.L_802519D8:
    li      r3,0
    li      r4,1
    li      r5,3
    bl	EXISelect
    cmpwi   r3,0
    bne-	.L_80251A00
    li      r3,0
    bl	EXIUnlock
    li      r0,0
    b	.L_80251A98
.L_80251A00:
    stw     r31,16(r1)
    addi    r4,r1,16
    li      r3,0
    li      r5,4
    li      r6,1
    li      r7,0
    bl	EXIImm
    cntlzw  r0,r3
    srwi    r29,r0,5
    li      r3,0
    bl	EXISync
    cntlzw  r0,r3
    srwi    r0,r0,5
    or      r29,r29,r0
    addi    r4,r1,16
    li      r3,0
    li      r5,4
    li      r6,0
    li      r7,0
    bl	EXIImm
    cntlzw  r0,r3
    srwi    r0,r0,5
    or      r29,r29,r0
    li      r3,0
    bl	EXISync
    cntlzw  r0,r3
    srwi    r0,r0,5
    or      r29,r29,r0
    li      r3,0
    bl	EXIDeselect
    cntlzw  r0,r3
    srwi    r0,r0,5
    or      r29,r29,r0
    li      r3,0
    bl	EXIUnlock
    cntlzw  r0,r29
    lwz     r29,16(r1)
    srwi    r0,r0,5
.L_80251A98:
    cntlzw  r0,r0
    srwi    r30,r0,5
    li      r3,0
    li      r4,1
    li      r5,0
    bl	EXILock
    cmpwi   r3,0
    bne-	.L_80251AC0
    li      r0,0
    b	.L_80251B80
.L_80251AC0:
    li      r3,0
    li      r4,1
    li      r5,3
    bl	EXISelect
    cmpwi   r3,0
    bne-	.L_80251AE8
    li      r3,0
    bl	EXIUnlock
    li      r0,0
    b	.L_80251B80
.L_80251AE8:
    stw     r31,12(r1)
    addi    r4,r1,12
    li      r3,0
    li      r5,4
    li      r6,1
    li      r7,0
    bl	EXIImm
    cntlzw  r0,r3
    srwi    r28,r0,5
    li      r3,0
    bl	EXISync
    cntlzw  r0,r3
    srwi    r0,r0,5
    or      r28,r28,r0
    addi    r4,r1,12
    li      r3,0
    li      r5,4
    li      r6,0
    li      r7,0
    bl	EXIImm
    cntlzw  r0,r3
    srwi    r0,r0,5
    or      r28,r28,r0
    li      r3,0
    bl	EXISync
    cntlzw  r0,r3
    srwi    r0,r0,5
    or      r28,r28,r0
    li      r3,0
    bl	EXIDeselect
    cntlzw  r0,r3
    srwi    r0,r0,5
    or      r28,r28,r0
    li      r3,0
    bl	EXIUnlock
    cntlzw  r0,r28
    lwz     r28,12(r1)
    srwi    r0,r0,5
.L_80251B80:
    cntlzw  r0,r0
    srwi    r0,r0,5
    or.     r0,r30,r0
    bne-	.L_80251BB0
    cmplw   r29,r28
    bne-	.L_80251BA4
    stw     r29,0(r26)
    li      r3,1
    b	.L_80251BB4
.L_80251BA4:
    addi    r27,r27,1
    cmpwi   r27,16
    blt+	.L_802519B8
.L_80251BB0:
    li      r3,0
.L_80251BB4:
    lmw     r26,24(r1)
    lwz     r0,52(r1)
    addi    r1,r1,48
    mtlr    r0
    blr
.size __OSGetRTC, . - __OSGetRTC

.global __OSSetRTC
.balign 4
__OSSetRTC:
/* 0x80251BC8 | size=0x108 (264 bytes) */
    mflr    r0
    li      r4,1
    stw     r0,4(r1)
    li      r5,0
    stwu    r1,-24(r1)
    stw     r31,20(r1)
    stw     r3,8(r1)
    li      r3,0
    bl	EXILock
    cmpwi   r3,0
    bne-	.L_80251BFC
    li      r3,0
    b	.L_80251CBC
.L_80251BFC:
    li      r3,0
    li      r4,1
    li      r5,3
    bl	EXISelect
    cmpwi   r3,0
    bne-	.L_80251C24
    li      r3,0
    bl	EXIUnlock
    li      r3,0
    b	.L_80251CBC
.L_80251C24:
    lis     r0,-24576
    stw     r0,12(r1)
    addi    r4,r1,12
    li      r3,0
    li      r5,4
    li      r6,1
    li      r7,0
    bl	EXIImm
    cntlzw  r0,r3
    srwi    r31,r0,5
    li      r3,0
    bl	EXISync
    cntlzw  r0,r3
    srwi    r0,r0,5
    or      r31,r31,r0
    addi    r4,r1,8
    li      r3,0
    li      r5,4
    li      r6,1
    li      r7,0
    bl	EXIImm
    cntlzw  r0,r3
    srwi    r0,r0,5
    or      r31,r31,r0
    li      r3,0
    bl	EXISync
    cntlzw  r0,r3
    srwi    r0,r0,5
    or      r31,r31,r0
    li      r3,0
    bl	EXIDeselect
    cntlzw  r0,r3
    srwi    r0,r0,5
    or      r31,r31,r0
    li      r3,0
    bl	EXIUnlock
    cntlzw  r0,r31
    srwi    r3,r0,5
.L_80251CBC:
    lwz     r0,28(r1)
    lwz     r31,20(r1)
    addi    r1,r1,24
    mtlr    r0
    blr
.size __OSSetRTC, . - __OSSetRTC

.global ReadSram
.balign 4
ReadSram:
/* 0x80251CD0 | size=0x11C (284 bytes) */
    mflr    r0
    li      r4,64
    stw     r0,4(r1)
    stwu    r1,-24(r1)
    stw     r31,20(r1)
    stw     r30,16(r1)
    addi    r30,r3,0
    bl	DCInvalidateRange
    li      r3,0
    li      r4,1
    li      r5,0
    bl	EXILock
    cmpwi   r3,0
    bne-	.L_80251D10
    li      r3,0
    b	.L_80251DD4
.L_80251D10:
    li      r3,0
    li      r4,1
    li      r5,3
    bl	EXISelect
    cmpwi   r3,0
    bne-	.L_80251D38
    li      r3,0
    bl	EXIUnlock
    li      r3,0
    b	.L_80251DD4
.L_80251D38:
    lis     r3,8192
    addi    r0,r3,256
    stw     r0,12(r1)
    addi    r4,r1,12
    li      r3,0
    li      r5,4
    li      r6,1
    li      r7,0
    bl	EXIImm
    cntlzw  r0,r3
    srwi    r31,r0,5
    li      r3,0
    bl	EXISync
    cntlzw  r0,r3
    srwi    r0,r0,5
    addi    r4,r30,0
    or      r31,r31,r0
    li      r3,0
    li      r5,64
    li      r6,0
    li      r7,0
    bl	EXIDma
    cntlzw  r0,r3
    srwi    r0,r0,5
    or      r31,r31,r0
    li      r3,0
    bl	EXISync
    cntlzw  r0,r3
    srwi    r0,r0,5
    or      r31,r31,r0
    li      r3,0
    bl	EXIDeselect
    cntlzw  r0,r3
    srwi    r0,r0,5
    or      r31,r31,r0
    li      r3,0
    bl	EXIUnlock
    cntlzw  r0,r31
    srwi    r3,r0,5
.L_80251DD4:
    lwz     r0,28(r1)
    lwz     r31,20(r1)
    lwz     r30,16(r1)
    addi    r1,r1,24
    mtlr    r0
    blr
.size ReadSram, . - ReadSram

.global WriteSram
.balign 4
WriteSram:
/* 0x80251E4C | size=0x118 (280 bytes) */
    mflr    r0
    lis     r6,-32731
    stw     r0,4(r1)
    addi    r0,r6,7660
    stwu    r1,-40(r1)
    stw     r31,36(r1)
    addi    r31,r4,0
    li      r4,1
    stw     r30,32(r1)
    addi    r30,r5,0
    mr      r5,r0
    stw     r29,28(r1)
    addi    r29,r3,0
    li      r3,0
    bl	EXILock
    cmpwi   r3,0
    bne-	.L_80251E98
    li      r3,0
    b	.L_80251F48
.L_80251E98:
    li      r3,0
    li      r4,1
    li      r5,3
    bl	EXISelect
    cmpwi   r3,0
    bne-	.L_80251EC0
    li      r3,0
    bl	EXIUnlock
    li      r3,0
    b	.L_80251F48
.L_80251EC0:
    slwi    r31,r31,6
    addi    r0,r31,256
    oris    r0,r0,40960
    stw     r0,20(r1)
    addi    r4,r1,20
    li      r3,0
    li      r5,4
    li      r6,1
    li      r7,0
    bl	EXIImm
    cntlzw  r0,r3
    srwi    r31,r0,5
    li      r3,0
    bl	EXISync
    cntlzw  r0,r3
    srwi    r0,r0,5
    addi    r4,r29,0
    addi    r5,r30,0
    or      r31,r31,r0
    li      r3,0
    li      r6,1
    bl	EXIImmEx
    cntlzw  r0,r3
    srwi    r0,r0,5
    or      r31,r31,r0
    li      r3,0
    bl	EXIDeselect
    cntlzw  r0,r3
    srwi    r0,r0,5
    or      r31,r31,r0
    li      r3,0
    bl	EXIUnlock
    cntlzw  r0,r31
    srwi    r3,r0,5
.L_80251F48:
    lwz     r0,44(r1)
    lwz     r31,36(r1)
    lwz     r30,32(r1)
    lwz     r29,28(r1)
    addi    r1,r1,40
    mtlr    r0
    blr
.size WriteSram, . - WriteSram

.global __OSInitSram
.balign 4
__OSInitSram:
/* 0x80251F64 | size=0x13C (316 bytes) */
    mflr    r0
    lis     r3,-32694
    stw     r0,4(r1)
    li      r4,64
    stwu    r1,-24(r1)
    stw     r31,20(r1)
    li      r31,0
    stw     r30,16(r1)
    addi    r30,r3,-24704
    addi    r3,r30,0
    stw     r31,68(r30)
    stw     r31,72(r30)
    bl	DCInvalidateRange
    li      r3,0
    li      r4,1
    li      r5,0
    bl	EXILock
    cmpwi   r3,0
    bne-	.L_80251FB4
    b	.L_80252074
.L_80251FB4:
    li      r3,0
    li      r4,1
    li      r5,3
    bl	EXISelect
    cmpwi   r3,0
    bne-	.L_80251FD8
    li      r3,0
    bl	EXIUnlock
    b	.L_80252074
.L_80251FD8:
    lis     r3,8192
    addi    r0,r3,256
    stw     r0,8(r1)
    addi    r4,r1,8
    li      r3,0
    li      r5,4
    li      r6,1
    li      r7,0
    bl	EXIImm
    cntlzw  r0,r3
    srwi    r31,r0,5
    li      r3,0
    bl	EXISync
    cntlzw  r0,r3
    srwi    r0,r0,5
    addi    r4,r30,0
    or      r31,r31,r0
    li      r3,0
    li      r5,64
    li      r6,0
    li      r7,0
    bl	EXIDma
    cntlzw  r0,r3
    srwi    r0,r0,5
    or      r31,r31,r0
    li      r3,0
    bl	EXISync
    cntlzw  r0,r3
    srwi    r0,r0,5
    or      r31,r31,r0
    li      r3,0
    bl	EXIDeselect
    cntlzw  r0,r3
    srwi    r0,r0,5
    or      r31,r31,r0
    li      r3,0
    bl	EXIUnlock
    cntlzw  r0,r31
    srwi    r31,r0,5
.L_80252074:
    stw     r31,76(r30)
    li      r0,64
    stw     r0,64(r30)
    bl	OSGetGbsMode
    bl	OSSetGbsMode
    lwz     r0,28(r1)
    lwz     r31,20(r1)
    lwz     r30,16(r1)
    addi    r1,r1,24
    mtlr    r0
    blr
.size __OSInitSram, . - __OSInitSram

.global UnlockSram
.balign 4
UnlockSram:
/* 0x802521C0 | size=0x33C (828 bytes) */
    mflr    r0
    cmpwi   r3,0
    stw     r0,4(r1)
    lis     r3,-32694
    stwu    r1,-48(r1)
    stmw    r27,28(r1)
    addi    r31,r3,-24704
    beq-	.L_802524D4
    cmplwi  r4,0
    bne-	.L_80252394
    lbz     r3,19(r31)
    clrlwi  r0,r3,30
    cmplwi  r0,2
    ble-	.L_80252200
    clrrwi  r0,r3,2
    stb     r0,19(r31)
.L_80252200:
    li      r0,0
    sth     r0,2(r31)
    addi    r5,r31,20
    addi    r6,r31,12
    addi    r3,r5,1
    sth     r0,0(r31)
    subf    r3,r6,r3
    cmplw   r6,r5
    srwi    r3,r3,1
    bge-	.L_80252394
    srwi.   r0,r3,3
    mtctr   r0
    beq-	.L_80252364
.L_80252234:
    lhz     r5,0(r31)
    lhz     r0,0(r6)
    add     r0,r5,r0
    sth     r0,0(r31)
    lhz     r0,0(r6)
    lhz     r5,2(r31)
    not     r0,r0
    add     r0,r5,r0
    sth     r0,2(r31)
    lhz     r5,0(r31)
    lhz     r0,2(r6)
    add     r0,r5,r0
    sth     r0,0(r31)
    lhz     r0,2(r6)
    lhz     r5,2(r31)
    not     r0,r0
    add     r0,r5,r0
    sth     r0,2(r31)
    lhz     r5,0(r31)
    lhz     r0,4(r6)
    add     r0,r5,r0
    sth     r0,0(r31)
    lhz     r0,4(r6)
    lhz     r5,2(r31)
    not     r0,r0
    add     r0,r5,r0
    sth     r0,2(r31)
    lhz     r5,0(r31)
    lhz     r0,6(r6)
    add     r0,r5,r0
    sth     r0,0(r31)
    lhz     r0,6(r6)
    lhz     r5,2(r31)
    not     r0,r0
    add     r0,r5,r0
    sth     r0,2(r31)
    lhz     r5,0(r31)
    lhz     r0,8(r6)
    add     r0,r5,r0
    sth     r0,0(r31)
    lhz     r0,8(r6)
    lhz     r5,2(r31)
    not     r0,r0
    add     r0,r5,r0
    sth     r0,2(r31)
    lhz     r5,0(r31)
    lhz     r0,10(r6)
    add     r0,r5,r0
    sth     r0,0(r31)
    lhz     r0,10(r6)
    lhz     r5,2(r31)
    not     r0,r0
    add     r0,r5,r0
    sth     r0,2(r31)
    lhz     r5,0(r31)
    lhz     r0,12(r6)
    add     r0,r5,r0
    sth     r0,0(r31)
    lhz     r0,12(r6)
    lhz     r5,2(r31)
    not     r0,r0
    add     r0,r5,r0
    sth     r0,2(r31)
    lhz     r5,0(r31)
    lhz     r0,14(r6)
    add     r0,r5,r0
    sth     r0,0(r31)
    lhz     r0,14(r6)
    addi    r6,r6,16
    lhz     r5,2(r31)
    not     r0,r0
    add     r0,r5,r0
    sth     r0,2(r31)
    bdnz+	.L_80252234
    andi.   r3,r3,7
    beq-	.L_80252394
.L_80252364:
    mtctr   r3
.L_80252368:
    lhz     r5,0(r31)
    lhz     r0,0(r6)
    add     r0,r5,r0
    sth     r0,0(r31)
    lhz     r0,0(r6)
    addi    r6,r6,2
    lhz     r5,2(r31)
    not     r0,r0
    add     r0,r5,r0
    sth     r0,2(r31)
    bdnz+	.L_80252368
.L_80252394:
    addi    r30,r31,64
    lwz     r0,64(r31)
    cmplw   r4,r0
    bge-	.L_802523A8
    stw     r4,0(r30)
.L_802523A8:
    lwz     r0,0(r30)
    cmplwi  r0,20
    bgt-	.L_802523DC
    addi    r4,r31,20
    lhz     r3,60(r31)
    rlwinm  r0,r3,0,17,21
    cmplwi  r0,20480
    beq-	.L_802523D4
    rlwinm  r0,r3,0,24,25
    cmplwi  r0,192
    bne-	.L_802523DC
.L_802523D4:
    li      r0,0
    sth     r0,40(r4)
.L_802523DC:
    lwz     r29,0(r30)
    lis     r3,-32731
    addi    r5,r3,7660
    subfic  r27,r29,64
    add     r28,r31,r29
    li      r3,0
    li      r4,1
    bl	EXILock
    cmpwi   r3,0
    bne-	.L_8025240C
    li      r0,0
    b	.L_802524BC
.L_8025240C:
    li      r3,0
    li      r4,1
    li      r5,3
    bl	EXISelect
    cmpwi   r3,0
    bne-	.L_80252434
    li      r3,0
    bl	EXIUnlock
    li      r0,0
    b	.L_802524BC
.L_80252434:
    slwi    r3,r29,6
    addi    r0,r3,256
    oris    r0,r0,40960
    stw     r0,16(r1)
    addi    r4,r1,16
    li      r3,0
    li      r5,4
    li      r6,1
    li      r7,0
    bl	EXIImm
    cntlzw  r0,r3
    srwi    r29,r0,5
    li      r3,0
    bl	EXISync
    cntlzw  r0,r3
    srwi    r0,r0,5
    addi    r4,r28,0
    addi    r5,r27,0
    or      r29,r29,r0
    li      r3,0
    li      r6,1
    bl	EXIImmEx
    cntlzw  r0,r3
    srwi    r0,r0,5
    or      r29,r29,r0
    li      r3,0
    bl	EXIDeselect
    cntlzw  r0,r3
    srwi    r0,r0,5
    or      r29,r29,r0
    li      r3,0
    bl	EXIUnlock
    cntlzw  r0,r29
    srwi    r0,r0,5
.L_802524BC:
    stw     r0,76(r31)
    lwz     r0,76(r31)
    cmpwi   r0,0
    beq-	.L_802524D4
    li      r0,64
    stw     r0,0(r30)
.L_802524D4:
    li      r0,0
    stw     r0,72(r31)
    lwz     r3,68(r31)
    bl	OSRestoreInterrupts
    lwz     r3,76(r31)
    lmw     r27,28(r1)
    lwz     r0,52(r1)
    addi    r1,r1,48
    mtlr    r0
    blr
.size UnlockSram, . - UnlockSram

.global __OSCheckSram
.balign 4
__OSCheckSram:
/* 0x80252554 | size=0x110 (272 bytes) */
    lis     r3,-32694
    addi    r5,r3,-24704
    addi    r4,r5,20
    addi    r6,r5,12
    addi    r3,r4,1
    subf    r3,r6,r3
    cmplw   r6,r4
    srwi    r3,r3,1
    li      r8,0
    li      r7,0
    bge-	.L_80252638
    srwi.   r0,r3,3
    mtctr   r0
    beq-	.L_8025261C
.L_8025258C:
    lhz     r4,0(r6)
    not     r0,r4
    add     r7,r7,r4
    lhz     r4,2(r6)
    add     r8,r8,r0
    not     r0,r4
    add     r7,r7,r4
    lhz     r4,4(r6)
    add     r8,r8,r0
    not     r0,r4
    add     r7,r7,r4
    lhz     r4,6(r6)
    add     r8,r8,r0
    not     r0,r4
    add     r7,r7,r4
    lhz     r4,8(r6)
    add     r8,r8,r0
    not     r0,r4
    add     r7,r7,r4
    lhz     r4,10(r6)
    add     r8,r8,r0
    not     r0,r4
    add     r7,r7,r4
    lhz     r4,12(r6)
    add     r8,r8,r0
    not     r0,r4
    add     r7,r7,r4
    lhz     r4,14(r6)
    add     r8,r8,r0
    not     r0,r4
    add     r7,r7,r4
    add     r8,r8,r0
    addi    r6,r6,16
    bdnz+	.L_8025258C
    andi.   r3,r3,7
    beq-	.L_80252638
.L_8025261C:
    mtctr   r3
.L_80252620:
    lhz     r4,0(r6)
    addi    r6,r6,2
    not     r0,r4
    add     r7,r7,r4
    add     r8,r8,r0
    bdnz+	.L_80252620
.L_80252638:
    lhz     r4,0(r5)
    clrlwi  r0,r7,16
    li      r3,0
    cmplw   r4,r0
    bnelr-
    lhz     r4,2(r5)
    clrlwi  r0,r8,16
    cmplw   r4,r0
    bnelr-
    li      r3,1
    blr
.size __OSCheckSram, . - __OSCheckSram

.global __OSReadROM
.balign 4
__OSReadROM:
/* 0x80252664 | size=0x124 (292 bytes) */
    mflr    r0
    stw     r0,4(r1)
    stwu    r1,-40(r1)
    stw     r31,36(r1)
    addi    r31,r5,0
    stw     r30,32(r1)
    addi    r30,r4,0
    stw     r29,28(r1)
    addi    r29,r3,0
    bl	DCInvalidateRange
    li      r3,0
    li      r4,1
    li      r5,0
    bl	EXILock
    cmpwi   r3,0
    bne-	.L_802526AC
    li      r3,0
    b	.L_8025276C
.L_802526AC:
    li      r3,0
    li      r4,1
    li      r5,3
    bl	EXISelect
    cmpwi   r3,0
    bne-	.L_802526D4
    li      r3,0
    bl	EXIUnlock
    li      r3,0
    b	.L_8025276C
.L_802526D4:
    slwi    r0,r31,6
    stw     r0,20(r1)
    addi    r4,r1,20
    li      r3,0
    li      r5,4
    li      r6,1
    li      r7,0
    bl	EXIImm
    cntlzw  r0,r3
    srwi    r31,r0,5
    li      r3,0
    bl	EXISync
    cntlzw  r0,r3
    srwi    r0,r0,5
    addi    r4,r29,0
    addi    r5,r30,0
    or      r31,r31,r0
    li      r3,0
    li      r6,0
    li      r7,0
    bl	EXIDma
    cntlzw  r0,r3
    srwi    r0,r0,5
    or      r31,r31,r0
    li      r3,0
    bl	EXISync
    cntlzw  r0,r3
    srwi    r0,r0,5
    or      r31,r31,r0
    li      r3,0
    bl	EXIDeselect
    cntlzw  r0,r3
    srwi    r0,r0,5
    or      r31,r31,r0
    li      r3,0
    bl	EXIUnlock
    cntlzw  r0,r31
    srwi    r3,r0,5
.L_8025276C:
    lwz     r0,44(r1)
    lwz     r31,36(r1)
    lwz     r30,32(r1)
    lwz     r29,28(r1)
    addi    r1,r1,40
    mtlr    r0
    blr
.size __OSReadROM, . - __OSReadROM

.global __OSReadROMAsync
.balign 4
__OSReadROMAsync:
/* 0x802527E4 | size=0x110 (272 bytes) */
    mflr    r0
    stw     r0,4(r1)
    stwu    r1,-48(r1)
    stw     r31,44(r1)
    addi    r31,r6,0
    stw     r30,40(r1)
    addi    r30,r5,0
    stw     r29,36(r1)
    addi    r29,r4,0
    stw     r28,32(r1)
    addi    r28,r3,0
    bl	DCInvalidateRange
    lis     r3,-32694
    addi    r3,r3,-24704
    stw     r31,80(r3)
    li      r3,0
    li      r4,1
    li      r5,0
    bl	EXILock
    cmpwi   r3,0
    bne-	.L_80252840
    li      r3,0
    b	.L_802528D4
.L_80252840:
    li      r3,0
    li      r4,1
    li      r5,3
    bl	EXISelect
    cmpwi   r3,0
    bne-	.L_80252868
    li      r3,0
    bl	EXIUnlock
    li      r3,0
    b	.L_802528D4
.L_80252868:
    slwi    r0,r30,6
    stw     r0,24(r1)
    addi    r4,r1,24
    li      r3,0
    li      r5,4
    li      r6,1
    li      r7,0
    bl	EXIImm
    cntlzw  r0,r3
    srwi    r31,r0,5
    li      r3,0
    bl	EXISync
    cntlzw  r0,r3
    lis     r3,-32731
    srwi    r0,r0,5
    addi    r7,r3,10120
    addi    r4,r28,0
    addi    r5,r29,0
    or      r31,r31,r0
    li      r3,0
    li      r6,0
    bl	EXIDma
    cntlzw  r0,r3
    srwi    r0,r0,5
    or      r31,r31,r0
    cntlzw  r0,r31
    srwi    r3,r0,5
.L_802528D4:
    lwz     r0,52(r1)
    lwz     r31,44(r1)
    lwz     r30,40(r1)
    lwz     r29,36(r1)
    lwz     r28,32(r1)
    addi    r1,r1,48
    mtlr    r0
    blr
.size __OSReadROMAsync, . - __OSReadROMAsync

#
# === OSThread.o (os.a) ===
#

.global __OSThreadInit
.balign 4
__OSThreadInit:
/* 0x802532D0 | size=0x158 (344 bytes) */
    mflr    r0
    lis     r3,-32694
    stw     r0,4(r1)
    li      r0,2
    li      r4,16
    stwu    r1,-24(r1)
    stw     r31,20(r1)
    stw     r30,16(r1)
    stw     r29,12(r1)
    li      r29,0
    stw     r28,8(r1)
    addi    r28,r3,-24616
    addi    r31,r28,1048
    sth     r0,1760(r28)
    li      r0,1
    addi    r3,r31,744
    sth     r0,1762(r28)
    li      r0,-1
    stw     r4,1772(r28)
    stw     r4,1768(r28)
    stw     r29,1764(r28)
    stw     r0,1776(r28)
    stw     r29,1800(r28)
    bl	OSInitThreadQueue
    stw     r29,1808(r28)
    lis     r30,-32768
    addi    r3,r31,0
    stw     r29,1804(r28)
    stw     r31,216(r30)
    bl	OSClearContext
    mr      r3,r31
    bl	OSSetCurrentContext
    lis     r3,-32687
    addi    r0,r3,5536
    lis     r3,-32688
    stw     r0,1820(r28)
    addi    r0,r3,5536
    stw     r0,1824(r28)
    lis     r3,-8530
    addi    r0,r3,-17730
    lwz     r3,1824(r28)
    mr      r4,r31
    stw     r0,0(r3)
    lwz     r12,-27896(r13)
    lwz     r3,228(r30)
    mtlr    r12
    blrl
    stw     r31,228(r30)
    li      r3,0
    bl	OSClearStack
    stw     r29,-23584(r13)
    li      r30,0
    slwi    r0,r30,3
    stw     r29,-23580(r13)
    add     r29,r28,r0
.L_802533AC:
    mr      r3,r29
    bl	OSInitThreadQueue
    addi    r30,r30,1
    cmpwi   r30,31
    addi    r29,r29,8
    ble+	.L_802533AC
    lis     r30,-32768
    addi    r3,r30,220
    bl	OSInitThreadQueue
    addi    r4,r30,220
    lwzu    r3,4(r4)
    cmplwi  r3,0
    bne-	.L_802533E8
    stw     r31,220(r30)
    b	.L_802533EC
.L_802533E8:
    stw     r31,764(r3)
.L_802533EC:
    stw     r3,768(r31)
    li      r30,0
    addi    r3,r28,1840
    stw     r30,764(r31)
    stw     r31,0(r4)
    bl	OSClearContext
    stw     r30,-23576(r13)
    lwz     r0,28(r1)
    lwz     r31,20(r1)
    lwz     r30,16(r1)
    lwz     r29,12(r1)
    lwz     r28,8(r1)
    addi    r1,r1,24
    mtlr    r0
    blr
.size __OSThreadInit, . - __OSThreadInit

.global SetEffectivePriority
.balign 4
SetEffectivePriority:
/* 0x802536C4 | size=0x1C0 (448 bytes) */
    mflr    r0
    stw     r0,4(r1)
    stwu    r1,-24(r1)
    stw     r31,20(r1)
    mr      r31,r3
    stw     r30,16(r1)
    addi    r30,r4,0
    lhz     r0,712(r3)
    cmpwi   r0,3
    beq-	.L_80253868
    bge-	.L_80253700
    cmpwi   r0,1
    beq-	.L_8025370C
    bge-	.L_8025385C
    b	.L_80253868
.L_80253700:
    cmpwi   r0,5
    bge-	.L_80253868
    b	.L_80253784
.L_8025370C:
    mr      r3,r31
    bl	UnsetRun
    stw     r30,720(r31)
    lis     r3,-32694
    addi    r0,r3,-24616
    lwz     r3,720(r31)
    slwi    r3,r3,3
    add     r0,r0,r3
    stw     r0,732(r31)
    lwz     r4,732(r31)
    lwz     r3,4(r4)
    cmplwi  r3,0
    bne-	.L_80253748
    stw     r31,0(r4)
    b	.L_8025374C
.L_80253748:
    stw     r31,736(r3)
.L_8025374C:
    stw     r3,740(r31)
    li      r0,0
    li      r3,1
    stw     r0,736(r31)
    lwz     r4,732(r31)
    stw     r31,4(r4)
    lwz     r0,720(r31)
    lwz     r4,-23584(r13)
    subfic  r0,r0,31
    slw     r0,r3,r0
    or      r0,r4,r0
    stw     r0,-23584(r13)
    stw     r3,-23580(r13)
    b	.L_80253868
.L_80253784:
    lwz     r4,736(r31)
    lwz     r5,740(r31)
    cmplwi  r4,0
    bne-	.L_802537A0
    lwz     r3,732(r31)
    stw     r5,4(r3)
    b	.L_802537A4
.L_802537A0:
    stw     r5,740(r4)
.L_802537A4:
    cmplwi  r5,0
    bne-	.L_802537B8
    lwz     r3,732(r31)
    stw     r4,0(r3)
    b	.L_802537BC
.L_802537B8:
    stw     r4,736(r5)
.L_802537BC:
    stw     r30,720(r31)
    lwz     r4,732(r31)
    lwz     r5,0(r4)
    b	.L_802537D0
.L_802537CC:
    lwz     r5,736(r5)
.L_802537D0:
    cmplwi  r5,0
    beq-	.L_802537E8
    lwz     r3,720(r5)
    lwz     r0,720(r31)
    cmpw    r3,r0
    ble+	.L_802537CC
.L_802537E8:
    cmplwi  r5,0
    bne-	.L_80253820
    lwz     r3,4(r4)
    cmplwi  r3,0
    bne-	.L_80253804
    stw     r31,0(r4)
    b	.L_80253808
.L_80253804:
    stw     r31,736(r3)
.L_80253808:
    stw     r3,740(r31)
    li      r0,0
    stw     r0,736(r31)
    lwz     r3,732(r31)
    stw     r31,4(r3)
    b	.L_80253848
.L_80253820:
    stw     r5,736(r31)
    lwz     r3,740(r5)
    stw     r31,740(r5)
    cmplwi  r3,0
    stw     r3,740(r31)
    bne-	.L_80253844
    lwz     r3,732(r31)
    stw     r31,0(r3)
    b	.L_80253848
.L_80253844:
    stw     r31,736(r3)
.L_80253848:
    lwz     r3,752(r31)
    cmplwi  r3,0
    beq-	.L_80253868
    lwz     r3,8(r3)
    b	.L_8025386C
.L_8025385C:
    li      r0,1
    stw     r0,-23580(r13)
    stw     r30,720(r31)
.L_80253868:
    li      r3,0
.L_8025386C:
    lwz     r0,28(r1)
    lwz     r31,20(r1)
    lwz     r30,16(r1)
    addi    r1,r1,24
    mtlr    r0
    blr
.size SetEffectivePriority, . - SetEffectivePriority

.global SelectThread
.balign 4
SelectThread:
/* 0x8025394C | size=0x228 (552 bytes) */
    mflr    r0
    lis     r4,-32694
    stw     r0,4(r1)
    stwu    r1,-24(r1)
    stw     r31,20(r1)
    addi    r31,r4,-24616
    stw     r30,16(r1)
    addi    r30,r3,0
    lwz     r0,-23576(r13)
    cmpwi   r0,0
    ble-	.L_80253980
    li      r3,0
    b	.L_80253B5C
.L_80253980:
    bl	OSGetCurrentContext
    lis     r4,-32768
    lwz     r6,228(r4)
    cmplw   r3,r6
    addi    r3,r6,0
    beq-	.L_802539A0
    li      r3,0
    b	.L_80253B5C
.L_802539A0:
    cmplwi  r6,0
    beq-	.L_80253A60
    lhz     r0,712(r6)
    cmplwi  r0,2
    bne-	.L_80253A40
    cmpwi   r30,0
    bne-	.L_802539D8
    lwz     r4,-23584(r13)
    lwz     r0,720(r6)
    cntlzw  r4,r4
    cmpw    r0,r4
    bgt-	.L_802539D8
    li      r3,0
    b	.L_80253B5C
.L_802539D8:
    li      r0,1
    sth     r0,712(r6)
    lwz     r0,720(r6)
    slwi    r0,r0,3
    add     r0,r31,r0
    stw     r0,732(r6)
    lwz     r5,732(r6)
    lwz     r4,4(r5)
    cmplwi  r4,0
    bne-	.L_80253A08
    stw     r6,0(r5)
    b	.L_80253A0C
.L_80253A08:
    stw     r6,736(r4)
.L_80253A0C:
    stw     r4,740(r6)
    li      r0,0
    li      r4,1
    stw     r0,736(r6)
    lwz     r5,732(r6)
    stw     r6,4(r5)
    lwz     r0,720(r6)
    lwz     r5,-23584(r13)
    subfic  r0,r0,31
    slw     r0,r4,r0
    or      r0,r5,r0
    stw     r0,-23584(r13)
    stw     r4,-23580(r13)
.L_80253A40:
    lhz     r0,418(r6)
    rlwinm. r0,r0,0,30,30
    bne-	.L_80253A60
    bl	OSSaveContext
    cmplwi  r3,0
    beq-	.L_80253A60
    li      r3,0
    b	.L_80253B5C
.L_80253A60:
    lwz     r0,-23584(r13)
    cmplwi  r0,0
    bne-	.L_80253ABC
    lwz     r12,-27896(r13)
    lis     r30,-32768
    lwz     r3,228(r30)
    li      r4,0
    mtlr    r12
    blrl
    li      r0,0
    stw     r0,228(r30)
    addi    r3,r31,1840
    bl	OSSetCurrentContext
.L_80253A94:
    bl	OSEnableInterrupts
.L_80253A98:
    lwz     r0,-23584(r13)
    cmplwi  r0,0
    beq+	.L_80253A98
    bl	OSDisableInterrupts
    lwz     r0,-23584(r13)
    cmplwi  r0,0
    beq+	.L_80253A94
    addi    r3,r31,1840
    bl	OSClearContext
.L_80253ABC:
    li      r3,0
    stw     r3,-23580(r13)
    lwz     r0,-23584(r13)
    cntlzw  r7,r0
    slwi    r0,r7,3
    add     r4,r31,r0
    lwz     r5,0(r4)
    lwz     r6,736(r5)
    addi    r30,r5,0
    cmplwi  r6,0
    bne-	.L_80253AF0
    stw     r3,4(r4)
    b	.L_80253AF4
.L_80253AF0:
    stw     r3,740(r6)
.L_80253AF4:
    stw     r6,0(r4)
    lwz     r0,0(r4)
    cmplwi  r0,0
    bne-	.L_80253B1C
    subfic  r0,r7,31
    lwz     r4,-23584(r13)
    li      r3,1
    slw     r0,r3,r0
    andc    r0,r4,r0
    stw     r0,-23584(r13)
.L_80253B1C:
    li      r0,0
    stw     r0,732(r30)
    li      r0,2
    lis     r31,-32768
    sth     r0,712(r30)
    mr      r4,r30
    lwz     r12,-27896(r13)
    lwz     r3,228(r31)
    mtlr    r12
    blrl
    stw     r30,228(r31)
    mr      r3,r30
    bl	OSSetCurrentContext
    mr      r3,r30
    bl	OSLoadContext
    mr      r3,r30
.L_80253B5C:
    lwz     r0,28(r1)
    lwz     r31,20(r1)
    lwz     r30,16(r1)
    addi    r1,r1,24
    mtlr    r0
    blr
.size SelectThread, . - SelectThread

.global OSCreateThread
.balign 4
OSCreateThread:
/* 0x80253BE0 | size=0x1E8 (488 bytes) */
    mflr    r0
    cmpwi   r8,0
    stw     r0,4(r1)
    stwu    r1,-80(r1)
    stmw    r27,60(r1)
    addi    r31,r3,0
    addi    r27,r5,0
    addi    r28,r6,0
    addi    r29,r7,0
    blt-	.L_80253C10
    cmpwi   r8,31
    ble-	.L_80253C18
.L_80253C10:
    li      r3,0
    b	.L_80253DB4
.L_80253C18:
    li      r6,1
    sth     r6,712(r31)
    clrlwi  r0,r9,31
    clrrwi  r7,r28,3
    sth     r0,714(r31)
    li      r0,-1
    li      r30,0
    stw     r8,724(r31)
    addi    r3,r31,0
    addi    r5,r7,-8
    stw     r8,720(r31)
    stw     r6,716(r31)
    stw     r0,728(r31)
    stw     r30,752(r31)
    stw     r30,748(r31)
    stw     r30,744(r31)
    stw     r30,760(r31)
    stw     r30,756(r31)
    stw     r30,-8(r7)
    stw     r30,-4(r7)
    bl	OSInitContext
    lis     r3,-32731
    addi    r0,r3,15816
    stw     r0,132(r31)
    lis     r3,-8530
    subf    r4,r29,r28
    stw     r27,12(r31)
    addi    r0,r3,-17730
    stw     r28,772(r31)
    stw     r4,776(r31)
    lwz     r3,776(r31)
    stw     r0,0(r3)
    stw     r30,780(r31)
    stw     r30,784(r31)
    stw     r30,788(r31)
    bl	OSDisableInterrupts
    lis     r4,-32694
    addi    r4,r4,-24784
    lwz     r0,64(r4)
    cmplwi  r0,0
    beq-	.L_80253D7C
    lwz     r4,412(r31)
    li      r0,4
    mtctr   r0
    addi    r5,r31,0
    ori     r0,r4,2304
    stw     r0,412(r31)
    lhz     r0,418(r31)
    ori     r0,r0,1
    sth     r0,418(r31)
    lwz     r0,-27912(r13)
    rlwinm  r0,r0,0,24,28
    ori     r0,r0,4
    stw     r0,404(r31)
.L_80253CF0:
    li      r0,-1
    stw     r0,148(r5)
    stw     r0,144(r5)
    stw     r0,460(r5)
    stw     r0,456(r5)
    stw     r0,156(r5)
    stw     r0,152(r5)
    stw     r0,468(r5)
    stw     r0,464(r5)
    stw     r0,164(r5)
    stw     r0,160(r5)
    stw     r0,476(r5)
    stw     r0,472(r5)
    stw     r0,172(r5)
    stw     r0,168(r5)
    stw     r0,484(r5)
    stw     r0,480(r5)
    stw     r0,180(r5)
    stw     r0,176(r5)
    stw     r0,492(r5)
    stw     r0,488(r5)
    stw     r0,188(r5)
    stw     r0,184(r5)
    stw     r0,500(r5)
    stw     r0,496(r5)
    stw     r0,196(r5)
    stw     r0,192(r5)
    stw     r0,508(r5)
    stw     r0,504(r5)
    stw     r0,204(r5)
    stw     r0,200(r5)
    stw     r0,516(r5)
    stw     r0,512(r5)
    addi    r5,r5,64
    bdnz+	.L_80253CF0
.L_80253D7C:
    lis     r4,-32768
    addi    r5,r4,220
    lwzu    r6,4(r5)
    cmplwi  r6,0
    bne-	.L_80253D98
    stw     r31,220(r4)
    b	.L_80253D9C
.L_80253D98:
    stw     r31,764(r6)
.L_80253D9C:
    stw     r6,768(r31)
    li      r0,0
    stw     r0,764(r31)
    stw     r31,0(r5)
    bl	OSRestoreInterrupts
    li      r3,1
.L_80253DB4:
    lmw     r27,60(r1)
    lwz     r0,84(r1)
    addi    r1,r1,80
    mtlr    r0
    blr
.size OSCreateThread, . - OSCreateThread

.global OSCancelThread
.balign 4
OSCancelThread:
/* 0x80253EAC | size=0x1BC (444 bytes) */
    mflr    r0
    stw     r0,4(r1)
    stwu    r1,-32(r1)
    stw     r31,28(r1)
    stw     r30,24(r1)
    mr      r30,r3
    stw     r29,20(r1)
    bl	OSDisableInterrupts
    lhz     r0,712(r30)
    addi    r31,r3,0
    cmpwi   r0,3
    beq-	.L_80253FB4
    bge-	.L_80253EF0
    cmpwi   r0,1
    beq-	.L_80253EFC
    bge-	.L_80253F14
    b	.L_80253FB4
.L_80253EF0:
    cmpwi   r0,5
    bge-	.L_80253FB4
    b	.L_80253F20
.L_80253EFC:
    lwz     r0,716(r30)
    cmpwi   r0,0
    bgt-	.L_80253FC0
    mr      r3,r30
    bl	UnsetRun
    b	.L_80253FC0
.L_80253F14:
    li      r0,1
    stw     r0,-23580(r13)
    b	.L_80253FC0
.L_80253F20:
    lwz     r4,736(r30)
    lwz     r5,740(r30)
    cmplwi  r4,0
    bne-	.L_80253F3C
    lwz     r3,732(r30)
    stw     r5,4(r3)
    b	.L_80253F40
.L_80253F3C:
    stw     r5,740(r4)
.L_80253F40:
    cmplwi  r5,0
    bne-	.L_80253F54
    lwz     r3,732(r30)
    stw     r4,0(r3)
    b	.L_80253F58
.L_80253F54:
    stw     r4,736(r5)
.L_80253F58:
    li      r0,0
    stw     r0,732(r30)
    lwz     r0,716(r30)
    cmpwi   r0,0
    bgt-	.L_80253FC0
    lwz     r3,752(r30)
    cmplwi  r3,0
    beq-	.L_80253FC0
    lwz     r29,8(r3)
.L_80253F7C:
    lwz     r0,716(r29)
    cmpwi   r0,0
    bgt-	.L_80253FC0
    mr      r3,r29
    bl	__OSGetEffectivePriority
    lwz     r0,720(r29)
    addi    r4,r3,0
    cmpw    r0,r4
    beq-	.L_80253FC0
    mr      r3,r29
    bl	SetEffectivePriority
    mr.     r29,r3
    bne+	.L_80253F7C
    b	.L_80253FC0
.L_80253FB4:
    mr      r3,r31
    bl	OSRestoreInterrupts
    b	.L_8025404C
.L_80253FC0:
    mr      r3,r30
    bl	OSClearContext
    lhz     r0,714(r30)
    clrlwi. r0,r0,31
    beq-	.L_80254018
    lwz     r4,764(r30)
    lwz     r5,768(r30)
    cmplwi  r4,0
    bne-	.L_80253FF0
    lis     r3,-32768
    stw     r5,224(r3)
    b	.L_80253FF4
.L_80253FF0:
    stw     r5,768(r4)
.L_80253FF4:
    cmplwi  r5,0
    bne-	.L_80254008
    lis     r3,-32768
    stw     r4,220(r3)
    b	.L_8025400C
.L_80254008:
    stw     r4,764(r5)
.L_8025400C:
    li      r0,0
    sth     r0,712(r30)
    b	.L_80254020
.L_80254018:
    li      r0,8
    sth     r0,712(r30)
.L_80254020:
    mr      r3,r30
    bl	__OSUnlockAllMutex
    addi    r3,r30,744
    bl	OSWakeupThread
    lwz     r0,-23580(r13)
    cmpwi   r0,0
    beq-	.L_80254044
    li      r3,0
    bl	SelectThread
.L_80254044:
    mr      r3,r31
    bl	OSRestoreInterrupts
.L_8025404C:
    lwz     r0,36(r1)
    lwz     r31,28(r1)
    lwz     r30,24(r1)
    lwz     r29,20(r1)
    addi    r1,r1,32
    mtlr    r0
    blr
.size OSCancelThread, . - OSCancelThread

.global OSJoinThread
.balign 4
OSJoinThread:
/* 0x80254068 | size=0x140 (320 bytes) */
    mflr    r0
    stw     r0,4(r1)
    stwu    r1,-32(r1)
    stw     r31,28(r1)
    addi    r31,r3,0
    stw     r30,24(r1)
    stw     r29,20(r1)
    addi    r29,r4,0
    bl	OSDisableInterrupts
    lhz     r0,714(r31)
    addi    r30,r3,0
    clrlwi. r0,r0,31
    bne-	.L_80254114
    lhz     r0,712(r31)
    cmplwi  r0,8
    beq-	.L_80254114
    lwz     r0,744(r31)
    cmplwi  r0,0
    bne-	.L_80254114
    addi    r3,r31,744
    bl	OSSleepThread
    lhz     r0,712(r31)
    cmplwi  r0,0
    bne-	.L_802540D0
    li      r0,0
    b	.L_802540FC
.L_802540D0:
    lis     r3,-32768
    lwz     r3,220(r3)
    b	.L_802540F0
.L_802540DC:
    cmplw   r31,r3
    bne-	.L_802540EC
    li      r0,1
    b	.L_802540FC
.L_802540EC:
    lwz     r3,764(r3)
.L_802540F0:
    cmplwi  r3,0
    bne+	.L_802540DC
    li      r0,0
.L_802540FC:
    cmpwi   r0,0
    bne-	.L_80254114
    mr      r3,r30
    bl	OSRestoreInterrupts
    li      r3,0
    b	.L_8025418C
.L_80254114:
    lhz     r0,712(r31)
    cmplwi  r0,8
    bne-	.L_80254180
    cmplwi  r29,0
    beq-	.L_80254130
    lwz     r0,728(r31)
    stw     r0,0(r29)
.L_80254130:
    lwz     r4,764(r31)
    lwz     r5,768(r31)
    cmplwi  r4,0
    bne-	.L_8025414C
    lis     r3,-32768
    stw     r5,224(r3)
    b	.L_80254150
.L_8025414C:
    stw     r5,768(r4)
.L_80254150:
    cmplwi  r5,0
    bne-	.L_80254164
    lis     r3,-32768
    stw     r4,220(r3)
    b	.L_80254168
.L_80254164:
    stw     r4,764(r5)
.L_80254168:
    li      r0,0
    sth     r0,712(r31)
    mr      r3,r30
    bl	OSRestoreInterrupts
    li      r3,1
    b	.L_8025418C
.L_80254180:
    mr      r3,r30
    bl	OSRestoreInterrupts
    li      r3,0
.L_8025418C:
    lwz     r0,36(r1)
    lwz     r31,28(r1)
    lwz     r30,24(r1)
    lwz     r29,20(r1)
    addi    r1,r1,32
    mtlr    r0
    blr
.size OSJoinThread, . - OSJoinThread

.global OSResumeThread
.balign 4
OSResumeThread:
/* 0x80254248 | size=0x288 (648 bytes) */
    mflr    r0
    stw     r0,4(r1)
    stwu    r1,-40(r1)
    stw     r31,36(r1)
    stw     r30,32(r1)
    stw     r29,28(r1)
    mr      r29,r3
    bl	OSDisableInterrupts
    lwz     r4,716(r29)
    addi    r31,r3,0
    addi    r0,r4,-1
    stw     r0,716(r29)
    mr      r30,r4
    lwz     r0,716(r29)
    cmpwi   r0,0
    bge-	.L_80254294
    li      r0,0
    stw     r0,716(r29)
    b	.L_802544A8
.L_80254294:
    bne-	.L_802544A8
    lhz     r0,712(r29)
    cmpwi   r0,4
    beq-	.L_80254358
    bge-	.L_80254494
    cmpwi   r0,1
    beq-	.L_802542B4
    b	.L_80254494
.L_802542B4:
    lwz     r0,724(r29)
    lwz     r3,756(r29)
    b	.L_802542E0
.L_802542C0:
    lwz     r4,0(r3)
    cmplwi  r4,0
    beq-	.L_802542DC
    lwz     r4,720(r4)
    cmpw    r4,r0
    bge-	.L_802542DC
    mr      r0,r4
.L_802542DC:
    lwz     r3,16(r3)
.L_802542E0:
    cmplwi  r3,0
    bne+	.L_802542C0
    stw     r0,720(r29)
    lis     r3,-32694
    addi    r0,r3,-24616
    lwz     r3,720(r29)
    slwi    r3,r3,3
    add     r0,r0,r3
    stw     r0,732(r29)
    lwz     r4,732(r29)
    lwz     r3,4(r4)
    cmplwi  r3,0
    bne-	.L_8025431C
    stw     r29,0(r4)
    b	.L_80254320
.L_8025431C:
    stw     r29,736(r3)
.L_80254320:
    stw     r3,740(r29)
    li      r0,0
    li      r3,1
    stw     r0,736(r29)
    lwz     r4,732(r29)
    stw     r29,4(r4)
    lwz     r0,720(r29)
    lwz     r4,-23584(r13)
    subfic  r0,r0,31
    slw     r0,r3,r0
    or      r0,r4,r0
    stw     r0,-23584(r13)
    stw     r3,-23580(r13)
    b	.L_80254494
.L_80254358:
    lwz     r4,736(r29)
    lwz     r5,740(r29)
    cmplwi  r4,0
    bne-	.L_80254374
    lwz     r3,732(r29)
    stw     r5,4(r3)
    b	.L_80254378
.L_80254374:
    stw     r5,740(r4)
.L_80254378:
    cmplwi  r5,0
    bne-	.L_8025438C
    lwz     r3,732(r29)
    stw     r4,0(r3)
    b	.L_80254390
.L_8025438C:
    stw     r4,736(r5)
.L_80254390:
    lwz     r0,724(r29)
    lwz     r3,756(r29)
    b	.L_802543BC
.L_8025439C:
    lwz     r4,0(r3)
    cmplwi  r4,0
    beq-	.L_802543B8
    lwz     r4,720(r4)
    cmpw    r4,r0
    bge-	.L_802543B8
    mr      r0,r4
.L_802543B8:
    lwz     r3,16(r3)
.L_802543BC:
    cmplwi  r3,0
    bne+	.L_8025439C
    stw     r0,720(r29)
    lwz     r4,732(r29)
    lwz     r5,0(r4)
    b	.L_802543D8
.L_802543D4:
    lwz     r5,736(r5)
.L_802543D8:
    cmplwi  r5,0
    beq-	.L_802543F0
    lwz     r3,720(r5)
    lwz     r0,720(r29)
    cmpw    r3,r0
    ble+	.L_802543D4
.L_802543F0:
    cmplwi  r5,0
    bne-	.L_80254428
    lwz     r3,4(r4)
    cmplwi  r3,0
    bne-	.L_8025440C
    stw     r29,0(r4)
    b	.L_80254410
.L_8025440C:
    stw     r29,736(r3)
.L_80254410:
    stw     r3,740(r29)
    li      r0,0
    stw     r0,736(r29)
    lwz     r3,732(r29)
    stw     r29,4(r3)
    b	.L_80254450
.L_80254428:
    stw     r5,736(r29)
    lwz     r3,740(r5)
    stw     r29,740(r5)
    cmplwi  r3,0
    stw     r3,740(r29)
    bne-	.L_8025444C
    lwz     r3,732(r29)
    stw     r29,0(r3)
    b	.L_80254450
.L_8025444C:
    stw     r29,736(r3)
.L_80254450:
    lwz     r3,752(r29)
    cmplwi  r3,0
    beq-	.L_80254494
    lwz     r29,8(r3)
.L_80254460:
    lwz     r0,716(r29)
    cmpwi   r0,0
    bgt-	.L_80254494
    mr      r3,r29
    bl	__OSGetEffectivePriority
    lwz     r0,720(r29)
    addi    r4,r3,0
    cmpw    r0,r4
    beq-	.L_80254494
    mr      r3,r29
    bl	SetEffectivePriority
    mr.     r29,r3
    bne+	.L_80254460
.L_80254494:
    lwz     r0,-23580(r13)
    cmpwi   r0,0
    beq-	.L_802544A8
    li      r3,0
    bl	SelectThread
.L_802544A8:
    mr      r3,r31
    bl	OSRestoreInterrupts
    mr      r3,r30
    lwz     r0,44(r1)
    lwz     r31,36(r1)
    lwz     r30,32(r1)
    lwz     r29,28(r1)
    addi    r1,r1,40
    mtlr    r0
    blr
.size OSResumeThread, . - OSResumeThread

.global OSSuspendThread
.balign 4
OSSuspendThread:
/* 0x802544D0 | size=0x170 (368 bytes) */
    mflr    r0
    stw     r0,4(r1)
    stwu    r1,-32(r1)
    stw     r31,28(r1)
    stw     r30,24(r1)
    stw     r29,20(r1)
    mr      r29,r3
    bl	OSDisableInterrupts
    lwz     r4,716(r29)
    addi    r31,r3,0
    addi    r0,r4,1
    mr.     r30,r4
    stw     r0,716(r29)
    bne-	.L_80254618
    lhz     r0,712(r29)
    cmpwi   r0,3
    beq-	.L_80254604
    bge-	.L_80254528
    cmpwi   r0,1
    beq-	.L_80254544
    bge-	.L_80254534
    b	.L_80254604
.L_80254528:
    cmpwi   r0,5
    bge-	.L_80254604
    b	.L_80254550
.L_80254534:
    li      r0,1
    stw     r0,-23580(r13)
    sth     r0,712(r29)
    b	.L_80254604
.L_80254544:
    mr      r3,r29
    bl	UnsetRun
    b	.L_80254604
.L_80254550:
    lwz     r4,736(r29)
    lwz     r5,740(r29)
    cmplwi  r4,0
    bne-	.L_8025456C
    lwz     r3,732(r29)
    stw     r5,4(r3)
    b	.L_80254570
.L_8025456C:
    stw     r5,740(r4)
.L_80254570:
    cmplwi  r5,0
    bne-	.L_80254584
    lwz     r3,732(r29)
    stw     r4,0(r3)
    b	.L_80254588
.L_80254584:
    stw     r4,736(r5)
.L_80254588:
    li      r0,32
    stw     r0,720(r29)
    lwz     r4,732(r29)
    lwz     r3,4(r4)
    cmplwi  r3,0
    bne-	.L_802545A8
    stw     r29,0(r4)
    b	.L_802545AC
.L_802545A8:
    stw     r29,736(r3)
.L_802545AC:
    stw     r3,740(r29)
    li      r0,0
    stw     r0,736(r29)
    lwz     r3,732(r29)
    stw     r29,4(r3)
    lwz     r3,752(r29)
    cmplwi  r3,0
    beq-	.L_80254604
    lwz     r29,8(r3)
.L_802545D0:
    lwz     r0,716(r29)
    cmpwi   r0,0
    bgt-	.L_80254604
    mr      r3,r29
    bl	__OSGetEffectivePriority
    lwz     r0,720(r29)
    addi    r4,r3,0
    cmpw    r0,r4
    beq-	.L_80254604
    mr      r3,r29
    bl	SetEffectivePriority
    mr.     r29,r3
    bne+	.L_802545D0
.L_80254604:
    lwz     r0,-23580(r13)
    cmpwi   r0,0
    beq-	.L_80254618
    li      r3,0
    bl	SelectThread
.L_80254618:
    mr      r3,r31
    bl	OSRestoreInterrupts
    mr      r3,r30
    lwz     r0,36(r1)
    lwz     r31,28(r1)
    lwz     r30,24(r1)
    lwz     r29,20(r1)
    addi    r1,r1,32
    mtlr    r0
    blr
.size OSSuspendThread, . - OSSuspendThread

.global OSWakeupThread
.balign 4
OSWakeupThread:
/* 0x8025472C | size=0x104 (260 bytes) */
    mflr    r0
    stw     r0,4(r1)
    stwu    r1,-24(r1)
    stw     r31,20(r1)
    stw     r30,16(r1)
    mr      r30,r3
    bl	OSDisableInterrupts
    lis     r4,-32694
    addi    r31,r3,0
    addi    r5,r4,-24616
    b	.L_802547F0
.L_80254758:
    lwz     r3,736(r6)
    cmplwi  r3,0
    bne-	.L_80254770
    li      r0,0
    stw     r0,4(r30)
    b	.L_80254778
.L_80254770:
    li      r0,0
    stw     r0,740(r3)
.L_80254778:
    stw     r3,0(r30)
    li      r0,1
    sth     r0,712(r6)
    lwz     r0,716(r6)
    cmpwi   r0,0
    bgt-	.L_802547F0
    lwz     r0,720(r6)
    slwi    r0,r0,3
    add     r0,r5,r0
    stw     r0,732(r6)
    lwz     r4,732(r6)
    lwz     r3,4(r4)
    cmplwi  r3,0
    bne-	.L_802547B8
    stw     r6,0(r4)
    b	.L_802547BC
.L_802547B8:
    stw     r6,736(r3)
.L_802547BC:
    stw     r3,740(r6)
    li      r0,0
    li      r3,1
    stw     r0,736(r6)
    lwz     r4,732(r6)
    stw     r6,4(r4)
    lwz     r0,720(r6)
    lwz     r4,-23584(r13)
    subfic  r0,r0,31
    slw     r0,r3,r0
    or      r0,r4,r0
    stw     r0,-23584(r13)
    stw     r3,-23580(r13)
.L_802547F0:
    lwz     r6,0(r30)
    cmplwi  r6,0
    bne+	.L_80254758
    lwz     r0,-23580(r13)
    cmpwi   r0,0
    beq-	.L_80254810
    li      r3,0
    bl	SelectThread
.L_80254810:
    mr      r3,r31
    bl	OSRestoreInterrupts
    lwz     r0,28(r1)
    lwz     r31,20(r1)
    lwz     r30,16(r1)
    addi    r1,r1,24
    mtlr    r0
    blr
.size OSWakeupThread, . - OSWakeupThread

#
# === OSTime.o (os.a) ===
#

.global GetDates
.balign 4
GetDates:
/* 0x802555CC | size=0x19C (412 bytes) */
    lis     r5,-28087
    addi    r0,r5,9363
    addi    r7,r3,6
    mulhw   r6,r0,r7
    lis     r5,-19571
    addi    r0,r5,-1615
    mulhw   r0,r0,r3
    add     r5,r6,r7
    srawi   r5,r5,2
    srwi    r6,r5,31
    add     r5,r5,r6
    add     r0,r0,r3
    mulli   r6,r5,7
    srawi   r0,r0,8
    srwi    r5,r0,31
    add     r5,r0,r5
    subf    r0,r6,r7
    mulli   r11,r5,365
    stw     r0,24(r4)
    b	.L_8025561C
.L_8025561C:
    lis     r6,20972
    addi    r10,r6,-31457
    b	.L_80255628
.L_80255628:
    b	.L_80255634
.L_8025562C:
    addi    r11,r11,-365
    addi    r5,r5,-1
.L_80255634:
    cmpwi   r5,1
    bge-	.L_80255644
    li      r0,0
    b	.L_80255678
.L_80255644:
    addi    r0,r5,-1
    mulhw   r0,r10,r0
    srawi   r8,r0,7
    srawi   r6,r0,5
    addi    r0,r5,3
    srwi    r7,r6,31
    srawi   r0,r0,2
    srwi    r9,r8,31
    add     r6,r6,r7
    addze   r0,r0
    add     r7,r8,r9
    subf    r0,r6,r0
    add     r0,r7,r0
.L_80255678:
    add     r0,r11,r0
    cmpw    r3,r0
    blt+	.L_8025562C
    srawi   r6,r5,2
    stw     r5,20(r4)
    addze   r6,r6
    slwi    r6,r6,2
    subfc   r6,r6,r5
    subf    r0,r0,r3
    cmpwi   r6,0
    stw     r0,28(r4)
    li      r7,1
    li      r8,0
    bne-	.L_802556DC
    lis     r3,20972
    addi    r3,r3,-31457
    mulhw   r3,r3,r5
    srawi   r3,r3,5
    srwi    r6,r3,31
    add     r3,r3,r6
    mulli   r3,r3,100
    subf    r3,r3,r5
    cmpwi   r3,0
    beq-	.L_802556DC
    mr      r8,r7
.L_802556DC:
    cmpwi   r8,0
    bne-	.L_80255710
    lis     r3,20972
    addi    r3,r3,-31457
    mulhw   r3,r3,r5
    srawi   r3,r3,7
    srwi    r6,r3,31
    add     r3,r3,r6
    mulli   r3,r3,400
    subf    r3,r3,r5
    cmpwi   r3,0
    beq-	.L_80255710
    li      r7,0
.L_80255710:
    cmpwi   r7,0
    beq-	.L_80255724
    lis     r3,-32700
    addi    r6,r3,-16360
    b	.L_8025572C
.L_80255724:
    lis     r3,-32700
    addi    r6,r3,-16408
.L_8025572C:
    li      r7,12
    li      r3,48
    b	.L_80255738
.L_80255738:
    b	.L_8025573C
.L_8025573C:
    addi    r3,r3,-4
    lwzx    r5,r6,r3
    addi    r7,r7,-1
    cmpw    r0,r5
    blt+	.L_8025573C
    stw     r7,16(r4)
    lwzx    r3,r6,r3
    subf    r3,r3,r0
    addi    r0,r3,1
    stw     r0,12(r4)
    blr
.size GetDates, . - GetDates

.global OSTicksToCalendarTime
.balign 4
OSTicksToCalendarTime:
/* 0x80255768 | size=0x204 (516 bytes) */
    mflr    r0
    stw     r0,4(r1)
    stwu    r1,-56(r1)
    stmw    r25,28(r1)
    mr      r29,r3
    mr      r30,r4
    mr      r31,r5
    lis     r27,-32768
    lwz     r0,248(r27)
    mr      r3,r29
    mr      r4,r30
    srwi    r6,r0,2
    li      r5,0
    bl	__mod2i
    mr      r26,r3
    li      r5,0
    mr      r25,r4
    xoris   r4,r26,32768
    xoris   r3,r5,32768
    subfc   r0,r5,r25
    subfe   r3,r3,r4
    subfe   r3,r4,r4
    neg     r3,r3
    cmpwi   r3,0
    beq-	.L_802557DC
    lwz     r0,248(r27)
    srwi    r0,r0,2
    addc    r25,r25,r0
    adde    r26,r26,r5
.L_802557DC:
    li      r4,8
    mullw   r3,r26,r4
    mulhwu  r0,r25,r4
    lis     r27,-32768
    lwz     r6,248(r27)
    lis     r5,17180
    addi    r5,r5,-8573
    srwi    r6,r6,2
    mulhwu  r5,r5,r6
    srwi    r6,r5,15
    li      r28,0
    add     r3,r3,r0
    mullw   r0,r25,r28
    mullw   r4,r25,r4
    add     r3,r3,r0
    li      r5,0
    bl	__div2i
    li      r5,0
    li      r6,1000
    bl	__mod2i
    stw     r4,36(r31)
    lis     r3,4194
    addi    r5,r3,19923
    lwz     r0,248(r27)
    mr      r3,r26
    mr      r4,r25
    srwi    r0,r0,2
    mulhwu  r0,r5,r0
    srwi    r6,r0,6
    li      r5,0
    bl	__div2i
    li      r5,0
    li      r6,1000
    bl	__mod2i
    stw     r4,32(r31)
    subfc   r30,r25,r30
    subfe   r29,r26,r29
    lwz     r0,248(r27)
    lis     r5,1
    addi    r25,r5,20864
    mr      r3,r29
    srwi    r6,r0,2
    mr      r4,r30
    li      r5,0
    bl	__div2i
    mr      r6,r25
    li      r5,0
    bl	__div2i
    lis     r5,11
    lwz     r0,248(r27)
    addi    r5,r5,9589
    addc    r26,r4,r5
    srwi    r6,r0,2
    adde    r0,r3,r28
    mr      r3,r29
    mr      r4,r30
    li      r5,0
    bl	__div2i
    mr      r6,r25
    li      r5,0
    bl	__mod2i
    mr      r27,r4
    cmpwi   r27,0
    bge-	.L_802558E8
    addis   r27,r27,1
    addi    r26,r26,-1
    addi    r27,r27,20864
.L_802558E8:
    mr      r3,r26
    mr      r4,r31
    bl	GetDates
    lis     r3,-30583
    addi    r5,r3,-30583
    mulhw   r0,r5,r27
    add     r4,r0,r27
    srawi   r0,r4,5
    srwi    r3,r0,31
    add     r7,r0,r3
    mulhw   r0,r5,r7
    add     r0,r0,r7
    srawi   r5,r0,5
    srawi   r0,r0,5
    srwi    r3,r0,31
    add     r3,r0,r3
    srawi   r0,r4,5
    srwi    r6,r5,31
    mulli   r4,r3,60
    srwi    r3,r0,31
    add     r5,r5,r6
    add     r0,r0,r3
    stw     r5,8(r31)
    mulli   r0,r0,60
    subf    r3,r4,r7
    stw     r3,4(r31)
    subf    r0,r0,r27
    stw     r0,0(r31)
    lmw     r25,28(r1)
    lwz     r0,60(r1)
    addi    r1,r1,56
    mtlr    r0
    blr
.size OSTicksToCalendarTime, . - OSTicksToCalendarTime

.global OSCalendarTimeToTicks
.balign 4
OSCalendarTimeToTicks:
/* 0x8025596C | size=0x2E0 (736 bytes) */
    mflr    r0
    stw     r0,4(r1)
    stwu    r1,-96(r1)
    stmw    r18,40(r1)
    mr      r22,r3
    lis     r3,10923
    lwz     r4,16(r22)
    addi    r0,r3,-21845
    mulhw   r0,r0,r4
    srawi   r0,r0,1
    srwi    r3,r0,31
    add     r3,r0,r3
    mulli   r0,r3,12
    subf    r0,r0,r4
    cmpwi   r0,0
    mr      r26,r0
    bge-	.L_802559B8
    addi    r26,r26,12
    addi    r3,r3,-1
.L_802559B8:
    lwz     r0,20(r22)
    add     r30,r0,r3
    cmpwi   r30,1
    bge-	.L_802559D0
    li      r24,0
    b	.L_80255A0C
.L_802559D0:
    lis     r3,20972
    addi    r0,r30,-1
    addi    r3,r3,-31457
    mulhw   r0,r3,r0
    srawi   r5,r0,7
    srawi   r3,r0,5
    addi    r0,r30,3
    srwi    r4,r3,31
    srawi   r0,r0,2
    srwi    r6,r5,31
    add     r3,r3,r4
    addze   r0,r0
    add     r4,r5,r6
    subf    r0,r3,r0
    add     r24,r4,r0
.L_80255A0C:
    srawi   r0,r30,2
    addze   r0,r0
    slwi    r0,r0,2
    subfc   r0,r0,r30
    cmpwi   r0,0
    li      r4,1
    li      r5,0
    bne-	.L_80255A58
    lis     r3,20972
    addi    r0,r3,-31457
    mulhw   r0,r0,r30
    srawi   r0,r0,5
    srwi    r3,r0,31
    add     r0,r0,r3
    mulli   r0,r0,100
    subf    r0,r0,r30
    cmpwi   r0,0
    beq-	.L_80255A58
    mr      r5,r4
.L_80255A58:
    cmpwi   r5,0
    bne-	.L_80255A8C
    lis     r3,20972
    addi    r0,r3,-31457
    mulhw   r0,r0,r30
    srawi   r0,r0,7
    srwi    r3,r0,31
    add     r0,r0,r3
    mulli   r0,r0,400
    subf    r0,r0,r30
    cmpwi   r0,0
    beq-	.L_80255A8C
    li      r4,0
.L_80255A8C:
    cmpwi   r4,0
    beq-	.L_80255AA0
    lis     r3,-32700
    addi    r23,r3,-16360
    b	.L_80255AA8
.L_80255AA0:
    lis     r3,-32700
    addi    r23,r3,-16408
.L_80255AA8:
    lis     r25,-32768
    lwz     r5,36(r22)
    lwz     r0,248(r25)
    lis     r3,17180
    addi    r3,r3,-8573
    srwi    r0,r0,2
    mulhwu  r0,r3,r0
    srwi    r4,r0,15
    srawi   r0,r5,31
    mullw   r3,r0,r4
    mulhwu  r0,r5,r4
    li      r31,0
    add     r3,r3,r0
    mullw   r0,r5,r31
    mullw   r4,r5,r4
    add     r3,r3,r0
    li      r5,0
    li      r6,8
    bl	__div2i
    slwi    r0,r26,2
    lwz     r26,0(r22)
    lwz     r28,4(r22)
    li      r29,60
    srawi   r27,r26,31
    lwz     r5,12(r22)
    lwzx    r0,r23,r0
    srawi   r11,r28,31
    lwz     r10,8(r22)
    add     r5,r0,r5
    lwz     r25,248(r25)
    srawi   r7,r10,31
    lwz     r23,32(r22)
    addi    r0,r5,-1
    li      r9,3600
    lis     r5,481
    addi    r6,r5,13184
    srawi   r12,r30,31
    add     r18,r24,r0
    lis     r5,1
    addi    r19,r5,20864
    srawi   r8,r18,31
    mullw   r5,r12,r6
    mulhwu  r0,r30,r6
    add     r5,r5,r0
    mullw   r0,r30,r31
    lis     r22,4194
    lis     r24,19998
    mullw   r20,r8,r19
    mulhwu  r21,r18,r19
    add     r20,r20,r21
    mullw   r21,r18,r31
    mullw   r8,r7,r9
    mulhwu  r7,r10,r9
    add     r8,r8,r7
    mullw   r7,r10,r31
    mullw   r12,r11,r29
    mulhwu  r11,r28,r29
    add     r12,r12,r11
    mullw   r11,r28,r31
    mullw   r30,r30,r6
    mullw   r6,r18,r19
    mullw   r10,r10,r9
    mullw   r18,r28,r29
    add     r9,r5,r0
    add     r5,r20,r21
    addc    r0,r30,r6
    adde    r5,r9,r5
    add     r6,r8,r7
    addc    r0,r10,r0
    adde    r5,r6,r5
    add     r6,r12,r11
    addc    r0,r18,r0
    adde    r6,r6,r5
    addc    r7,r26,r0
    srwi    r8,r25,2
    addi    r0,r22,19923
    mulhwu  r0,r0,r8
    srwi    r5,r0,6
    adde    r6,r27,r6
    addi    r0,r24,16512
    addc    r10,r7,r0
    li      r0,-15
    adde    r6,r6,r0
    srawi   r0,r23,31
    mullw   r9,r6,r8
    mulhwu  r7,r10,r8
    add     r9,r9,r7
    mullw   r7,r10,r31
    mullw   r6,r0,r5
    mulhwu  r0,r23,r5
    add     r6,r6,r0
    mullw   r0,r23,r31
    mullw   r8,r10,r8
    mullw   r5,r23,r5
    add     r7,r9,r7
    add     r0,r6,r0
    addc    r5,r8,r5
    adde    r0,r7,r0
    addc    r4,r4,r5
    adde    r3,r3,r0
    lmw     r18,40(r1)
    lwz     r0,100(r1)
    addi    r1,r1,96
    mtlr    r0
    blr
.size OSCalendarTimeToTicks, . - OSCalendarTimeToTicks

#
# === OSUtf.o (os.a) ===
#

.global OSUTF8to32
.balign 4
OSUTF8to32:
/* 0x80371A98 | size=0x114 (276 bytes) */
    lbz     r5,0(r3)
    cmplwi  r5,0
    beq-	.L_80371AA8
    addi    r3,r3,1
.L_80371AA8:
    rlwinm. r0,r5,0,24,24
    bne-	.L_80371ABC
    addi    r6,r5,0
    li      r7,0
    b	.L_80371B0C
.L_80371ABC:
    rlwinm  r0,r5,0,24,26
    cmplwi  r0,192
    bne-	.L_80371AD4
    clrlwi  r6,r5,27
    li      r7,1
    b	.L_80371B0C
.L_80371AD4:
    rlwinm  r0,r5,0,24,27
    cmplwi  r0,224
    bne-	.L_80371AEC
    clrlwi  r6,r5,28
    li      r7,2
    b	.L_80371B0C
.L_80371AEC:
    rlwinm  r0,r5,0,24,28
    cmplwi  r0,240
    bne-	.L_80371B04
    clrlwi  r6,r5,29
    li      r7,3
    b	.L_80371B0C
.L_80371B04:
    li      r3,0
    blr
.L_80371B0C:
    cmplwi  r7,0
    mtctr   r7
    ble-	.L_80371B44
.L_80371B18:
    lbz     r5,0(r3)
    slwi    r6,r6,6
    addi    r3,r3,1
    rlwinm  r0,r5,0,24,25
    cmplwi  r0,128
    beq-	.L_80371B38
    li      r3,0
    blr
.L_80371B38:
    clrlwi  r0,r5,26
    or      r6,r6,r0
    bdnz+	.L_80371B18
.L_80371B44:
    cmplwi  r6,127
    bgt-	.L_80371B5C
    cmplwi  r7,0
    beq-	.L_80371B8C
    li      r3,0
    blr
.L_80371B5C:
    cmplwi  r6,2047
    bgt-	.L_80371B74
    cmplwi  r7,1
    beq-	.L_80371B8C
    li      r3,0
    blr
.L_80371B74:
    cmplwi  r6,65535
    bgt-	.L_80371B8C
    cmplwi  r7,2
    beq-	.L_80371B8C
    li      r3,0
    blr
.L_80371B8C:
    cmplwi  r6,55296
    blt-	.L_80371BA4
    cmplwi  r6,57343
    bgt-	.L_80371BA4
    li      r3,0
    blr
.L_80371BA4:
    stw     r6,0(r4)
    blr
.size OSUTF8to32, . - OSUTF8to32

.global OSUTF32toANSI
.balign 4
OSUTF32toANSI:
/* 0x80371D6C | size=0x11C (284 bytes) */
    cmplwi  r3,255
    ble-	.L_80371D7C
    li      r3,0
    blr
.L_80371D7C:
    cmplwi  r3,128
    blt-	.L_80371D8C
    cmplwi  r3,159
    ble-	.L_80371D94
.L_80371D8C:
    clrlwi  r3,r3,24
    blr
.L_80371D94:
    cmplwi  r3,338
    blt-	.L_80371E80
    cmplwi  r3,8482
    bgt-	.L_80371E80
    li      r0,4
    lis     r4,-32700
    mtctr   r0
    addi    r4,r4,14752
    li      r5,0
.L_80371DB8:
    lhz     r0,0(r4)
    cmplw   r3,r0
    bne-	.L_80371DCC
    addi    r3,r5,128
    blr
.L_80371DCC:
    lhzu    r0,2(r4)
    addi    r5,r5,1
    cmplw   r3,r0
    bne-	.L_80371DE4
    addi    r3,r5,128
    blr
.L_80371DE4:
    lhzu    r0,2(r4)
    addi    r5,r5,1
    cmplw   r3,r0
    bne-	.L_80371DFC
    addi    r3,r5,128
    blr
.L_80371DFC:
    lhzu    r0,2(r4)
    addi    r5,r5,1
    cmplw   r3,r0
    bne-	.L_80371E14
    addi    r3,r5,128
    blr
.L_80371E14:
    lhzu    r0,2(r4)
    addi    r5,r5,1
    cmplw   r3,r0
    bne-	.L_80371E2C
    addi    r3,r5,128
    blr
.L_80371E2C:
    lhzu    r0,2(r4)
    addi    r5,r5,1
    cmplw   r3,r0
    bne-	.L_80371E44
    addi    r3,r5,128
    blr
.L_80371E44:
    lhzu    r0,2(r4)
    addi    r5,r5,1
    cmplw   r3,r0
    bne-	.L_80371E5C
    addi    r3,r5,128
    blr
.L_80371E5C:
    lhzu    r0,2(r4)
    addi    r5,r5,1
    cmplw   r3,r0
    bne-	.L_80371E74
    addi    r3,r5,128
    blr
.L_80371E74:
    addi    r4,r4,2
    addi    r5,r5,1
    bdnz+	.L_80371DB8
.L_80371E80:
    li      r3,0
    blr
.size OSUTF32toANSI, . - OSUTF32toANSI
