# DolphinSDK os.a - Medium functions (65-256 bytes)
# Auto-generated from ELF disassembly
# Functions in the 65-256 byte range

.section .text

#
# === OS.o ===
#

.global OSExceptionVector
.balign 4
OSExceptionVector:
/* 0x8024BB00 | size=0x9C (156 bytes) */
    mtsprg  0,r4
    lwz     r4,192(0)
    stw     r3,12(r4)
    mfsprg  r3,0
    stw     r3,16(r4)
    stw     r5,20(r4)
    lhz     r3,418(r4)
    ori     r3,r3,2
    sth     r3,418(r4)
    mfcr    r3
    stw     r3,128(r4)
    mflr    r3
    stw     r3,132(r4)
    mfctr   r3
    stw     r3,136(r4)
    mfxer   r3
    stw     r3,140(r4)
    mfsrr0  r3
    stw     r3,408(r4)
    mfsrr1  r3
    stw     r3,412(r4)
    mr      r5,r3
    nop
    mfmsr   r3
    ori     r3,r3,48
    mtsrr1  r3
    li      r3,0
    lwz     r4,212(0)
    rlwinm. r5,r5,0,30,30
    bne-    .L_8024BB88
    lis     r5,-32731
    addi    r5,r5,-17508
    mtsrr0  r5
    rfi
.L_8024BB88:
    rlwinm  r5,r3,2,22,29
    lwz     r5,12288(r5)
    mtsrr0  r5
    rfi
    nop
.size OSExceptionVector, . - OSExceptionVector

.global OSDefaultExceptionHandler
.balign 4
OSDefaultExceptionHandler:
/* 0x8024BB9C | size=0x58 (88 bytes) */
    stw     r0,0(r4)
    stw     r1,4(r4)
    stw     r2,8(r4)
    stmw    r6,24(r4)
    mfgqr   r0,1
    stw     r0,424(r4)
    mfgqr   r0,2
    stw     r0,428(r4)
    mfgqr   r0,3
    stw     r0,432(r4)
    mfgqr   r0,4
    stw     r0,436(r4)
    mfgqr   r0,5
    stw     r0,440(r4)
    mfgqr   r0,6
    stw     r0,444(r4)
    mfgqr   r0,7
    stw     r0,448(r4)
    mfdsisr r5
    mfdar   r6
    stwu    r1,-8(r1)
    b       __OSUnhandledException
.size OSDefaultExceptionHandler, . - OSDefaultExceptionHandler

.global __OSPSInit
.balign 4
__OSPSInit:
/* 0x8024BBF4 | size=0x54 (84 bytes) */
    mflr    r0
    stw     r0,4(r1)
    stwu    r1,-8(r1)
    bl      PPCMfhid2
    oris    r3,r3,40960
    bl      PPCMthid2
    bl      ICFlashInvalidate
    sync
    li      r3,0
    mtgqr   0,r3
    mtgqr   1,r3
    mtgqr   2,r3
    mtgqr   3,r3
    mtgqr   4,r3
    mtgqr   5,r3
    mtgqr   6,r3
    mtgqr   7,r3
    lwz     r0,12(r1)
    addi    r1,r1,8
    mtlr    r0
    blr
.size __OSPSInit, . - __OSPSInit

#
# === OSAlarm.o ===
#

.global SetTimer
.balign 4
SetTimer:
/* 0x8024BDC8 | size=0x98 (152 bytes) */
    mflr    r0
    stw     r0,4(r1)
    stwu    r1,-24(r1)
    stw     r31,20(r1)
    mr      r31,r3
    bl      __OSGetSystemTime
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
    beq-    .L_8024BE1C
    li      r3,0
    bl      PPCMtdec
    b       .L_8024BE4C
.L_8024BE1C:
    lis     r4,-32768
    xoris   r3,r7,32768
    subfc   r0,r4,r8
    subfe   r3,r3,r6
    subfe   r3,r6,r6
    neg.    r3,r3
    beq-    .L_8024BE44
    mr      r3,r8
    bl      PPCMtdec
    b       .L_8024BE4C
.L_8024BE44:
    addi    r3,r4,-1
    bl      PPCMtdec
.L_8024BE4C:
    lwz     r0,28(r1)
    lwz     r31,20(r1)
    addi    r1,r1,24
    mtlr    r0
    blr
.size SetTimer, . - SetTimer

.global OSInitAlarm
.balign 4
OSInitAlarm:
/* 0x8024BE60 | size=0x58 (88 bytes) */
    mflr    r0
    li      r3,8
    stw     r0,4(r1)
    stwu    r1,-8(r1)
    bl      __OSGetExceptionHandler
    lis     r4,-32731
    addi    r4,r4,-14920
    cmplw   r3,r4
    beq-    .L_8024BEA8
    li      r0,0
    addi    r3,r13,-23688
    stw     r0,4(r3)
    li      r3,8
    stw     r0,-23688(r13)
    bl      __OSSetExceptionHandler
    lis     r3,-32700
    addi    r3,r3,-21176
    bl      OSRegisterResetFunction
.L_8024BEA8:
    lwz     r0,12(r1)
    addi    r1,r1,8
    mtlr    r0
    blr
.size OSInitAlarm, . - OSInitAlarm

.global OSSetAlarm
.balign 4
OSSetAlarm:
/* 0x8024C118 | size=0x68 (104 bytes) */
    mflr    r0
    stw     r0,4(r1)
    stwu    r1,-56(r1)
    stmw    r27,36(r1)
    addi    r27,r3,0
    addi    r29,r5,0
    addi    r28,r6,0
    addi    r30,r7,0
    bl      OSDisableInterrupts
    li      r0,0
    stw     r0,28(r27)
    mr      r31,r3
    stw     r0,24(r27)
    bl      __OSGetSystemTime
    addc    r6,r28,r4
    adde    r5,r29,r3
    addi    r3,r27,0
    addi    r7,r30,0
    bl      InsertAlarm
    mr      r3,r31
    bl      OSRestoreInterrupts
    lmw     r27,36(r1)
    lwz     r0,60(r1)
    addi    r1,r1,56
    mtlr    r0
    blr
.size OSSetAlarm, . - OSSetAlarm

.global OSSetAbsAlarm
.balign 4
OSSetAbsAlarm:
/* 0x8024C180 | size=0x70 (112 bytes) */
    mflr    r0
    stw     r0,4(r1)
    stwu    r1,-56(r1)
    stmw    r27,36(r1)
    addi    r27,r3,0
    addi    r29,r5,0
    addi    r28,r6,0
    addi    r30,r7,0
    bl      OSDisableInterrupts
    li      r0,0
    stw     r0,28(r27)
    mr      r31,r3
    addi    r4,r28,0
    stw     r0,24(r27)
    addi    r3,r29,0
    bl      __OSTimeToSystemTime
    addi    r5,r3,0
    addi    r3,r27,0
    addi    r6,r4,0
    addi    r7,r30,0
    bl      InsertAlarm
    mr      r3,r31
    bl      OSRestoreInterrupts
    lmw     r27,36(r1)
    lwz     r0,60(r1)
    addi    r1,r1,56
    mtlr    r0
    blr
.size OSSetAbsAlarm, . - OSSetAbsAlarm

.global OSSetPeriodicAlarm
.balign 4
OSSetPeriodicAlarm:
/* 0x8024C1F0 | size=0x7C (124 bytes) */
    mflr    r0
    stw     r0,4(r1)
    stwu    r1,-64(r1)
    stmw    r26,40(r1)
    addi    r26,r3,0
    addi    r28,r5,0
    addi    r27,r6,0
    addi    r29,r7,0
    addi    r31,r8,0
    addi    r30,r9,0
    bl      OSDisableInterrupts
    stw     r31,28(r26)
    mr      r31,r3
    addi    r4,r27,0
    stw     r29,24(r26)
    addi    r3,r28,0
    bl      __OSTimeToSystemTime
    stw     r4,36(r26)
    addi    r7,r30,0
    li      r6,0
    stw     r3,32(r26)
    addi    r3,r26,0
    li      r5,0
    bl      InsertAlarm
    mr      r3,r31
    bl      OSRestoreInterrupts
    lmw     r26,40(r1)
    lwz     r0,68(r1)
    addi    r1,r1,64
    mtlr    r0
    blr
.size OSSetPeriodicAlarm, . - OSSetPeriodicAlarm

.global DecrementerExceptionHandler
.balign 4
DecrementerExceptionHandler:
/* 0x8024C5B8 | size=0x50 (80 bytes) */
    stw     r0,0(r4)
    stw     r1,4(r4)
    stw     r2,8(r4)
    stmw    r6,24(r4)
    mfgqr   r0,1
    stw     r0,424(r4)
    mfgqr   r0,2
    stw     r0,428(r4)
    mfgqr   r0,3
    stw     r0,432(r4)
    mfgqr   r0,4
    stw     r0,436(r4)
    mfgqr   r0,5
    stw     r0,440(r4)
    mfgqr   r0,6
    stw     r0,444(r4)
    mfgqr   r0,7
    stw     r0,448(r4)
    stwu    r1,-8(r1)
    b       DecrementerExceptionCallback
.size DecrementerExceptionHandler, . - DecrementerExceptionHandler

.global OSCancelAlarms
.balign 4
OSCancelAlarms:
/* 0x8024C610 | size=0xB0 (176 bytes) */
    mflr    r0
    stw     r0,4(r1)
    stwu    r1,-32(r1)
    stw     r31,28(r1)
    stw     r30,24(r1)
    stw     r29,20(r1)
    mr      r29,r3
    cmplwi  r29,0
    beq-    .L_8024C6A4
    bl      OSDisableInterrupts
    lwz     r0,-23688(r13)
    mr      r31,r3
    cmplwi  r0,0
    mr      r3,r0
    beq-    .L_8024C654
    lwz     r0,20(r3)
    b       .L_8024C658
.L_8024C654:
    li      r0,0
.L_8024C658:
    mr      r30,r0
    b       .L_8024C660
.L_8024C660:
    b       .L_8024C664
.L_8024C664:
    b       .L_8024C694
.L_8024C668:
    lwz     r0,4(r3)
    cmplw   r0,r29
    bne-    .L_8024C678
    bl      OSCancelAlarm
.L_8024C678:
    cmplwi  r30,0
    mr      r3,r30
    beq-    .L_8024C68C
    lwz     r0,20(r30)
    b       .L_8024C690
.L_8024C68C:
    li      r0,0
.L_8024C690:
    mr      r30,r0
.L_8024C694:
    cmplwi  r3,0
    bne+    .L_8024C668
    mr      r3,r31
    bl      OSRestoreInterrupts
.L_8024C6A4:
    lwz     r0,36(r1)
    lwz     r31,28(r1)
    lwz     r30,24(r1)
    lwz     r29,20(r1)
    addi    r1,r1,32
    mtlr    r0
    blr
.size OSCancelAlarms, . - OSCancelAlarms

.global OnReset
.balign 4
OnReset:
/* 0x8024C6C0 | size=0xA0 (160 bytes) */
    mflr    r0
    stw     r0,4(r1)
    stwu    r1,-24(r1)
    stw     r31,20(r1)
    stw     r30,16(r1)
    cmpwi   r3,0
    beq-    .L_8024C744
    lwz     r0,-23688(r13)
    cmplwi  r0,0
    mr      r31,r0
    beq-    .L_8024C6F4
    lwz     r0,20(r31)
    b       .L_8024C6F8
.L_8024C6F4:
    li      r0,0
.L_8024C6F8:
    mr      r30,r0
    b       .L_8024C700
.L_8024C700:
    b       .L_8024C704
.L_8024C704:
    b       .L_8024C73C
.L_8024C708:
    mr      r3,r31
    bl      __DVDTestAlarm
    cmpwi   r3,0
    bne-    .L_8024C720
    mr      r3,r31
    bl      OSCancelAlarm
.L_8024C720:
    cmplwi  r30,0
    mr      r31,r30
    beq-    .L_8024C734
    lwz     r0,20(r30)
    b       .L_8024C738
.L_8024C734:
    li      r0,0
.L_8024C738:
    mr      r30,r0
.L_8024C73C:
    cmplwi  r31,0
    bne+    .L_8024C708
.L_8024C744:
    li      r3,1
    lwz     r0,28(r1)
    lwz     r31,20(r1)
    lwz     r30,16(r1)
    addi    r1,r1,24
    mtlr    r0
    blr
.size OnReset, . - OnReset

#
# === OSAudioSystem.o ===
#

.global __OSStopAudioSystem
.balign 4
__OSStopAudioSystem:
/* 0x8024C988 | size=0xD8 (216 bytes) */
    mflr    r0
    lis     r3,-13312
    stw     r0,4(r1)
    li      r0,2052
    stwu    r1,-16(r1)
    stw     r31,12(r1)
    addi    r31,r3,20480
    addi    r3,r3,20480
    stw     r30,8(r1)
    sth     r0,10(r31)
    lhz     r0,54(r3)
    rlwinm  r0,r0,0,17,15
    sth     r0,54(r3)
    lhzu    r0,10(r31)
    b       .L_8024C9C8
.L_8024C9C4:
    lhz     r0,0(r31)
.L_8024C9C8:
    rlwinm. r0,r0,0,21,21
    bne+    .L_8024C9C4
    lhz     r0,0(r31)
    b       .L_8024C9DC
.L_8024C9D8:
    lhz     r0,0(r31)
.L_8024C9DC:
    rlwinm. r0,r0,0,22,22
    bne+    .L_8024C9D8
    li      r0,2220
    lis     r3,-13312
    sth     r0,0(r31)
    li      r0,0
    sth     r0,20480(r3)
    addi    r4,r3,20480
.L_8024C9FC:
    lhz     r3,4(r4)
    lhz     r0,6(r4)
    rlwimi  r0,r3,16,0,15
    clrrwi. r0,r0,31
    bne+    .L_8024C9FC
    bl      OSGetTick
    mr      r30,r3
.L_8024CA18:
    bl      OSGetTick
    subf    r0,r30,r3
    cmpwi   r0,44
    blt+    .L_8024CA18
    lhz     r0,0(r31)
    ori     r0,r0,1
    sth     r0,0(r31)
    lhz     r0,0(r31)
    b       .L_8024CA40
.L_8024CA3C:
    lhz     r0,0(r31)
.L_8024CA40:
    clrlwi. r0,r0,31
    bne+    .L_8024CA3C
    lwz     r0,20(r1)
    lwz     r31,12(r1)
    lwz     r30,8(r1)
    addi    r1,r1,16
    mtlr    r0
    blr
.size __OSStopAudioSystem, . - __OSStopAudioSystem

#
# === OSCache.o ===
#

.global __LCEnable
.balign 4
__LCEnable:
/* 0x8024CCC0 | size=0xCC (204 bytes) */
    mfmsr   r5
    ori     r5,r5,4096
    mtmsr   r5
    lis     r3,-32768
    li      r4,1024
    mtctr   r4
.L_8024CCD8:
    dcbt    0,r3
    dcbst   0,r3
    addi    r3,r3,32
    bdnz+   .L_8024CCD8
    mfhid2  r4
    oris    r4,r4,4111
    mthid2  r4
    nop
    nop
    nop
    nop
    nop
    nop
    nop
    nop
    nop
    nop
    nop
    nop
    lis     r3,-8192
    ori     r3,r3,2
    mtdbatl 3,r3
    ori     r3,r3,510
    mtdbatu 3,r3
    isync
    lis     r3,-8192
    li      r6,512
    mtctr   r6
    li      r6,0
.L_8024CD4C:
    dcbz_l  r6,r3
    addi    r3,r3,32
    bdnz+   .L_8024CD4C
    nop
    nop
    nop
    nop
    nop
    nop
    nop
    nop
    nop
    nop
    nop
    nop
    blr
.size __LCEnable, . - __LCEnable

.global LCAlloc
.balign 4
LCAlloc:
/* 0x8024CE88 | size=0x70 (112 bytes) */
    mflr    r0
    stw     r0,4(r1)
    stwu    r1,-32(r1)
    stw     r31,28(r1)
    stw     r30,24(r1)
    stw     r29,20(r1)
    mr      r29,r3
    srwi    r30,r4,5
    bl      PPCMfhid2
    rlwinm  r0,r3,0,3,3
    cmplwi  r0,0
    bne-    .L_8024CECC
    bl      OSDisableInterrupts
    mr      r31,r3
    bl      __LCEnable
    mr      r3,r31
    bl      OSRestoreInterrupts
.L_8024CECC:
    mr      r4,r29
    mr      r5,r30
    li      r3,1
    bl      LCAllocTags
    lwz     r0,36(r1)
    lwz     r31,28(r1)
    lwz     r30,24(r1)
    lwz     r29,20(r1)
    addi    r1,r1,32
    mtlr    r0
    blr
.size LCAlloc, . - LCAlloc

.global LCAllocNoInvalidate
.balign 4
LCAllocNoInvalidate:
/* 0x8024CEF8 | size=0x70 (112 bytes) */
    mflr    r0
    stw     r0,4(r1)
    stwu    r1,-32(r1)
    stw     r31,28(r1)
    stw     r30,24(r1)
    stw     r29,20(r1)
    mr      r29,r3
    srwi    r30,r4,5
    bl      PPCMfhid2
    rlwinm  r0,r3,0,3,3
    cmplwi  r0,0
    bne-    .L_8024CF3C
    bl      OSDisableInterrupts
    mr      r31,r3
    bl      __LCEnable
    mr      r3,r31
    bl      OSRestoreInterrupts
.L_8024CF3C:
    mr      r4,r29
    mr      r5,r30
    li      r3,0
    bl      LCAllocTags
    lwz     r0,36(r1)
    lwz     r31,28(r1)
    lwz     r30,24(r1)
    lwz     r29,20(r1)
    addi    r1,r1,32
    mtlr    r0
    blr
.size LCAllocNoInvalidate, . - LCAllocNoInvalidate

.global LCLoadData
.balign 4
LCLoadData:
/* 0x8024CF68 | size=0xAC (172 bytes) */
    mflr    r0
    stw     r0,4(r1)
    stwu    r1,-40(r1)
    stw     r31,36(r1)
    stw     r30,32(r1)
    stw     r29,28(r1)
    stw     r28,24(r1)
    mr      r28,r3
    mr      r29,r4
    addi    r0,r5,31
    srwi    r3,r0,5
    addi    r0,r3,127
    mr      r31,r3
    srwi    r30,r0,7
    b       .L_8024CFA4
.L_8024CFA4:
    b       .L_8024CFA8
.L_8024CFA8:
    b       .L_8024CFE8
.L_8024CFAC:
    cmplwi  r31,128
    bge-    .L_8024CFCC
    mr      r3,r28
    mr      r4,r29
    mr      r5,r31
    bl      LCLoadBlocks
    li      r31,0
    b       .L_8024CFE8
.L_8024CFCC:
    mr      r3,r28
    mr      r4,r29
    li      r5,0
    bl      LCLoadBlocks
    addi    r31,r31,-128
    addi    r28,r28,4096
    addi    r29,r29,4096
.L_8024CFE8:
    cmplwi  r31,0
    bne+    .L_8024CFAC
    mr      r3,r30
    lwz     r0,44(r1)
    lwz     r31,36(r1)
    lwz     r30,32(r1)
    lwz     r29,28(r1)
    lwz     r28,24(r1)
    addi    r1,r1,40
    mtlr    r0
    blr
.size LCLoadData, . - LCLoadData

.global LCStoreData
.balign 4
LCStoreData:
/* 0x8024D014 | size=0xAC (172 bytes) */
    mflr    r0
    stw     r0,4(r1)
    stwu    r1,-40(r1)
    stw     r31,36(r1)
    stw     r30,32(r1)
    stw     r29,28(r1)
    stw     r28,24(r1)
    mr      r28,r3
    mr      r29,r4
    addi    r0,r5,31
    srwi    r3,r0,5
    addi    r0,r3,127
    mr      r31,r3
    srwi    r30,r0,7
    b       .L_8024D050
.L_8024D050:
    b       .L_8024D054
.L_8024D054:
    b       .L_8024D094
.L_8024D058:
    cmplwi  r31,128
    bge-    .L_8024D078
    mr      r3,r28
    mr      r4,r29
    mr      r5,r31
    bl      LCStoreBlocks
    li      r31,0
    b       .L_8024D094
.L_8024D078:
    mr      r3,r28
    mr      r4,r29
    li      r5,0
    bl      LCStoreBlocks
    addi    r31,r31,-128
    addi    r28,r28,4096
    addi    r29,r29,4096
.L_8024D094:
    cmplwi  r31,0
    bne+    .L_8024D058
    mr      r3,r30
    lwz     r0,44(r1)
    lwz     r31,36(r1)
    lwz     r30,32(r1)
    lwz     r29,28(r1)
    lwz     r28,24(r1)
    addi    r1,r1,40
    mtlr    r0
    blr
.size LCStoreData, . - LCStoreData

.global LCFlushQueue
.balign 4
LCFlushQueue:
/* 0x8024D0E0 | size=0x48 (72 bytes) */
    mflr    r0
    stw     r0,4(r1)
    stwu    r1,-16(r1)
    li      r0,0
    stw     r0,8(r1)
    li      r4,1
    li      r3,0
    lbz     r0,11(r1)
    rlwimi  r0,r4,0,31,31
    stb     r0,11(r1)
    bl      PPCMtdmaU
    lwz     r3,8(r1)
    bl      PPCMtdmaL
    bl      PPCSync
    lwz     r0,20(r1)
    addi    r1,r1,16
    mtlr    r0
    blr
.size LCFlushQueue, . - LCFlushQueue

.global L2Init
.balign 4
L2Init:
/* 0x8024D128 | size=0x4C (76 bytes) */
    mflr    r0
    stw     r0,4(r1)
    stwu    r1,-16(r1)
    stw     r31,12(r1)
    bl      PPCMfmsr
    mr      r31,r3
    sync
    li      r3,48
    bl      PPCMtmsr
    sync
    bl      L2Disable
    bl      L2GlobalInvalidate
    mr      r3,r31
    bl      PPCMtmsr
    lwz     r0,20(r1)
    lwz     r31,12(r1)
    addi    r1,r1,16
    mtlr    r0
    blr
.size L2Init, . - L2Init

.global L2GlobalInvalidate
.balign 4
L2GlobalInvalidate:
/* 0x8024D1D0 | size=0x98 (152 bytes) */
    mflr    r0
    stw     r0,4(r1)
    stwu    r1,-16(r1)
    stw     r31,12(r1)
    sync
    bl      PPCMfl2cr
    clrlwi  r3,r3,1
    bl      PPCMtl2cr
    sync
    bl      PPCMfl2cr
    oris    r3,r3,32
    bl      PPCMtl2cr
    b       .L_8024D204
.L_8024D204:
    b       .L_8024D208
.L_8024D208:
    bl      PPCMfl2cr
    clrlwi  r0,r3,31
    cmplwi  r0,0
    bne+    .L_8024D208
    bl      PPCMfl2cr
    rlwinm  r3,r3,0,11,9
    bl      PPCMtl2cr
    b       .L_8024D228
.L_8024D228:
    lis     r3,-32700
    addi    r31,r3,-20544
    b       .L_8024D234
.L_8024D234:
    b       .L_8024D244
.L_8024D238:
    mr      r3,r31
    crclr   4*cr1+eq
    bl      DBPrintf
.L_8024D244:
    bl      PPCMfl2cr
    clrlwi  r0,r3,31
    cmplwi  r0,0
    bne+    .L_8024D238
    lwz     r0,20(r1)
    lwz     r31,12(r1)
    addi    r1,r1,16
    mtlr    r0
    blr
.size L2GlobalInvalidate, . - L2GlobalInvalidate

.global __OSCacheInit
.balign 4
__OSCacheInit:
/* 0x8024D448 | size=0xF4 (244 bytes) */
    mflr    r0
    stw     r0,4(r1)
    stwu    r1,-16(r1)
    stw     r31,12(r1)
    stw     r30,8(r1)
    lis     r3,-32700
    addi    r31,r3,-20544
    bl      PPCMfhid0
    rlwinm  r0,r3,0,16,16
    cmplwi  r0,0
    bne-    .L_8024D484
    bl      ICEnable
    addi    r3,r31,428
    crclr   4*cr1+eq
    bl      DBPrintf
.L_8024D484:
    bl      PPCMfhid0
    rlwinm  r0,r3,0,17,17
    cmplwi  r0,0
    bne-    .L_8024D4A4
    bl      DCEnable
    addi    r3,r31,456
    crclr   4*cr1+eq
    bl      DBPrintf
.L_8024D4A4:
    bl      PPCMfl2cr
    clrrwi  r0,r3,31
    cmplwi  r0,0
    bne-    .L_8024D508
    bl      PPCMfmsr
    mr      r30,r3
    sync
    li      r3,48
    bl      PPCMtmsr
    sync
    sync
    bl      PPCMfl2cr
    clrlwi  r3,r3,1
    bl      PPCMtl2cr
    sync
    bl      L2GlobalInvalidate
    mr      r3,r30
    bl      PPCMtmsr
    bl      PPCMfl2cr
    oris    r0,r3,32768
    rlwinm  r3,r0,0,11,9
    bl      PPCMtl2cr
    addi    r3,r31,484
    crclr   4*cr1+eq
    bl      DBPrintf
.L_8024D508:
    lis     r3,-32731
    addi    r4,r3,-11544
    li      r3,1
    bl      OSSetErrorHandler
    addi    r3,r31,508
    crclr   4*cr1+eq
    bl      DBPrintf
    lwz     r0,20(r1)
    lwz     r31,12(r1)
    lwz     r30,8(r1)
    addi    r1,r1,16
    mtlr    r0
    blr
.size __OSCacheInit, . - __OSCacheInit

#
# === OSContext.o ===
#

.global OSSetCurrentContext
.balign 4
OSSetCurrentContext:
/* 0x8024D798 | size=0x5C (92 bytes) */
    lis     r4,-32768
    stw     r3,212(r4)
    clrlwi  r5,r3,2
    stw     r5,192(r4)
    lwz     r5,216(r4)
    cmpw    r5,r3
    bne-    .L_8024D7D0
    lwz     r6,412(r3)
    ori     r6,r6,8192
    stw     r6,412(r3)
    mfmsr   r6
    ori     r6,r6,2
    mtmsr   r6
    blr
.L_8024D7D0:
    lwz     r6,412(r3)
    rlwinm  r6,r6,0,19,17
    stw     r6,412(r3)
    mfmsr   r6
    rlwinm  r6,r6,0,19,17
    ori     r6,r6,2
    mtmsr   r6
    isync
    blr
.size OSSetCurrentContext, . - OSSetCurrentContext

.global OSSaveContext
.balign 4
OSSaveContext:
/* 0x8024D800 | size=0x80 (128 bytes) */
    stmw    r13,52(r3)
    mfgqr   r0,1
    stw     r0,424(r3)
    mfgqr   r0,2
    stw     r0,428(r3)
    mfgqr   r0,3
    stw     r0,432(r3)
    mfgqr   r0,4
    stw     r0,436(r3)
    mfgqr   r0,5
    stw     r0,440(r3)
    mfgqr   r0,6
    stw     r0,444(r3)
    mfgqr   r0,7
    stw     r0,448(r3)
    mfcr    r0
    stw     r0,128(r3)
    mflr    r0
    stw     r0,132(r3)
    stw     r0,408(r3)
    mfmsr   r0
    stw     r0,412(r3)
    mfctr   r0
    stw     r0,136(r3)
    mfxer   r0
    stw     r0,140(r3)
    stw     r1,4(r3)
    stw     r2,8(r3)
    li      r0,1
    stw     r0,12(r3)
    li      r3,0
    blr
.size OSSaveContext, . - OSSaveContext

.global OSLoadContext
.balign 4
OSLoadContext:
/* 0x8024D880 | size=0xD8 (216 bytes) */
    lis     r4,-32731
    lwz     r6,408(r3)
    addi    r5,r4,-2736
    cmplw   r6,r5
    ble-    .L_8024D8A8
    lis     r4,-32731
    addi    r0,r4,-2724
    cmplw   r6,r0
    bge-    .L_8024D8A8
    stw     r5,408(r3)
.L_8024D8A8:
    lwz     r0,0(r3)
    lwz     r1,4(r3)
    lwz     r2,8(r3)
    lhz     r4,418(r3)
    rlwinm. r5,r4,0,30,30
    beq-    .L_8024D8D0
    rlwinm  r4,r4,0,31,29
    sth     r4,418(r3)
    lmw     r5,20(r3)
    b       .L_8024D8D4
.L_8024D8D0:
    lmw     r13,52(r3)
.L_8024D8D4:
    lwz     r4,424(r3)
    mtgqr   1,r4
    lwz     r4,428(r3)
    mtgqr   2,r4
    lwz     r4,432(r3)
    mtgqr   3,r4
    lwz     r4,436(r3)
    mtgqr   4,r4
    lwz     r4,440(r3)
    mtgqr   5,r4
    lwz     r4,444(r3)
    mtgqr   6,r4
    lwz     r4,448(r3)
    mtgqr   7,r4
    lwz     r4,128(r3)
    mtcr    r4
    lwz     r4,132(r3)
    mtlr    r4
    lwz     r4,136(r3)
    mtctr   r4
    lwz     r4,140(r3)
    mtxer   r4
    mfmsr   r4
    rlwinm  r4,r4,0,17,15
    rlwinm  r4,r4,0,31,29
    mtmsr   r4
    lwz     r4,408(r3)
    mtsrr0  r4
    lwz     r4,412(r3)
    mtsrr1  r4
    lwz     r4,16(r3)
    lwz     r3,12(r3)
    rfi
.size OSLoadContext, . - OSLoadContext

.global OSInitContext
.balign 4
OSInitContext:
/* 0x8024D9C4 | size=0xBC (188 bytes) */
    stw     r4,408(r3)
    stw     r5,4(r3)
    li      r11,0
    ori     r11,r11,36914
    stw     r11,412(r3)
    li      r0,0
    stw     r0,128(r3)
    stw     r0,140(r3)
    stw     r2,8(r3)
    stw     r13,52(r3)
    stw     r0,12(r3)
    stw     r0,16(r3)
    stw     r0,20(r3)
    stw     r0,24(r3)
    stw     r0,28(r3)
    stw     r0,32(r3)
    stw     r0,36(r3)
    stw     r0,40(r3)
    stw     r0,44(r3)
    stw     r0,48(r3)
    stw     r0,56(r3)
    stw     r0,60(r3)
    stw     r0,64(r3)
    stw     r0,68(r3)
    stw     r0,72(r3)
    stw     r0,76(r3)
    stw     r0,80(r3)
    stw     r0,84(r3)
    stw     r0,88(r3)
    stw     r0,92(r3)
    stw     r0,96(r3)
    stw     r0,100(r3)
    stw     r0,104(r3)
    stw     r0,108(r3)
    stw     r0,112(r3)
    stw     r0,116(r3)
    stw     r0,120(r3)
    stw     r0,124(r3)
    stw     r0,420(r3)
    stw     r0,424(r3)
    stw     r0,428(r3)
    stw     r0,432(r3)
    stw     r0,436(r3)
    stw     r0,440(r3)
    stw     r0,444(r3)
    stw     r0,448(r3)
    b       OSClearContext
.size OSInitContext, . - OSInitContext

.global OSSwitchFPUContext
.balign 4
OSSwitchFPUContext:
/* 0x8024DD28 | size=0x84 (132 bytes) */
    mfmsr   r5
    ori     r5,r5,8192
    mtmsr   r5
    isync
    lwz     r5,412(r4)
    ori     r5,r5,8192
    mtsrr1  r5
    lis     r3,-32768
    lwz     r5,216(r3)
    stw     r4,216(r3)
    cmpw    r5,r4
    beq-    .L_8024DD68
    cmpwi   r5,0
    beq-    .L_8024DD64
    bl      __OSSaveFPUContext
.L_8024DD64:
    bl      __OSLoadFPUContext
.L_8024DD68:
    lwz     r3,128(r4)
    mtcr    r3
    lwz     r3,132(r4)
    mtlr    r3
    lwz     r3,408(r4)
    mtsrr0  r3
    lwz     r3,136(r4)
    mtctr   r3
    lwz     r3,140(r4)
    mtxer   r3
    lhz     r3,418(r4)
    rlwinm  r3,r3,0,31,29
    sth     r3,418(r4)
    lwz     r5,20(r4)
    lwz     r3,12(r4)
    lwz     r4,16(r4)
    rfi
.size OSSwitchFPUContext, . - OSSwitchFPUContext

.global __OSContextInit
.balign 4
__OSContextInit:
/* 0x8024DDAC | size=0x48 (72 bytes) */
    mflr    r0
    stw     r0,4(r1)
    stwu    r1,-8(r1)
    lis     r3,-32731
    addi    r4,r3,-8920
    li      r3,7
    bl      __OSSetExceptionHandler
    li      r0,0
    crclr   4*cr1+eq
    lis     r4,-32768
    lis     r3,-32700
    stw     r0,216(r4)
    addi    r3,r3,-19548
    bl      DBPrintf
    lwz     r0,12(r1)
    addi    r1,r1,8
    mtlr    r0
    blr
.size __OSContextInit, . - __OSContextInit

#
# === OSError.o ===
#

.global OSReport
.balign 4
OSReport:
/* 0x8024DF20 | size=0x80 (128 bytes) */
    mflr    r0
    stw     r0,4(r1)
    stwu    r1,-120(r1)
    bne-    cr1,.L_8024DF50
    stfd    f1,40(r1)
    stfd    f2,48(r1)
    stfd    f3,56(r1)
    stfd    f4,64(r1)
    stfd    f5,72(r1)
    stfd    f6,80(r1)
    stfd    f7,88(r1)
    stfd    f8,96(r1)
.L_8024DF50:
    stw     r3,8(r1)
    lis     r0,256
    stw     r4,12(r1)
    addi    r4,r1,108
    stw     r5,16(r1)
    stw     r6,20(r1)
    stw     r7,24(r1)
    stw     r8,28(r1)
    stw     r9,32(r1)
    stw     r10,36(r1)
    stw     r0,108(r1)
    addi    r0,r1,128
    stw     r0,112(r1)
    addi    r0,r1,8
    stw     r0,116(r1)
    bl      vprintf
    lwz     r0,124(r1)
    addi    r1,r1,120
    mtlr    r0
    blr
.size OSReport, . - OSReport

#
# === OSExec.o ===
#

.global StartDol
.balign 4
StartDol:
/* 0x8024E7B0 | size=0x68 (104 bytes) */
    mflr    r0
    stw     r0,4(r1)
    stwu    r1,-24(r1)
    stw     r31,20(r1)
    stw     r30,16(r1)
    mr      r30,r3
    mr      r31,r4
    li      r3,28
    li      r4,1
    bl      OSAllocFromArenaLo
    mr      r4,r3
    mr      r3,r30
    bl      __OSSetExecParams
    lis     r3,-13312
    addi    r3,r3,12288
    li      r0,7
    stw     r0,36(r3)
    bl      OSDisableInterrupts
    mr      r3,r31
    bl      Run
    lwz     r0,28(r1)
    lwz     r31,20(r1)
    lwz     r30,16(r1)
    addi    r1,r1,24
    mtlr    r0
    blr
.size StartDol, . - StartDol

.global ReadDisc
.balign 4
ReadDisc:
/* 0x8024E818 | size=0x6C (108 bytes) */
    mflr    r0
    stw     r0,4(r1)
    stwu    r1,-72(r1)
    mr      r0,r4
    mr      r6,r5
    mr      r4,r3
    mr      r5,r0
    addi    r3,r1,20
    li      r7,0
    li      r8,0
    bl      DVDReadAbsAsyncPrio
    b       .L_8024E848
.L_8024E848:
    b       .L_8024E84C
.L_8024E84C:
    b       .L_8024E864
.L_8024E850:
    bl      DVDCheckDisk
    cmpwi   r3,0
    bne-    .L_8024E864
    li      r3,0
    bl      __OSDoHotReset
.L_8024E864:
    addi    r3,r1,20
    bl      DVDGetCommandBlockStatus
    cmpwi   r3,0
    bne+    .L_8024E850
    lwz     r0,76(r1)
    addi    r1,r1,72
    mtlr    r0
    blr
.size ReadDisc, . - ReadDisc

.global __OSSetExecParams
.balign 4
__OSSetExecParams:
/* 0x8024E908 | size=0x44 (68 bytes) */
    mflr    r0
    stw     r0,4(r1)
    stwu    r1,-24(r1)
    stw     r31,20(r1)
    mr      r0,r3
    mr      r31,r4
    mr      r3,r31
    mr      r4,r0
    li      r5,28
    bl      memcpy
    lis     r3,-32768
    stw     r31,12528(r3)
    lwz     r0,28(r1)
    lwz     r31,20(r1)
    addi    r1,r1,24
    mtlr    r0
    blr
.size __OSSetExecParams, . - __OSSetExecParams

.global StopStreaming
.balign 4
StopStreaming:
/* 0x8024E94C | size=0xA0 (160 bytes) */
    mflr    r0
    stw     r0,4(r1)
    stwu    r1,-56(r1)
    lwz     r0,-23732(r13)
    cmpwi   r0,0
    bne-    .L_8024E9DC
    bl      DVDGetCurrentDiskID
    lbz     r0,8(r3)
    cmplwi  r0,0
    beq-    .L_8024E97C
    li      r0,1
    b       .L_8024E980
.L_8024E97C:
    li      r0,0
.L_8024E980:
    cmpwi   r0,0
    beq-    .L_8024E9DC
    li      r3,0
    bl      AISetStreamVolLeft
    li      r3,0
    bl      AISetStreamVolRight
    addi    r3,r1,8
    li      r4,0
    bl      DVDCancelStreamAsync
    b       .L_8024E9A8
.L_8024E9A8:
    b       .L_8024E9AC
.L_8024E9AC:
    b       .L_8024E9C4
.L_8024E9B0:
    bl      DVDCheckDisk
    cmpwi   r3,0
    bne-    .L_8024E9C4
    li      r3,0
    bl      __OSDoHotReset
.L_8024E9C4:
    addi    r3,r1,8
    bl      DVDGetCommandBlockStatus
    cmpwi   r3,0
    bne+    .L_8024E9B0
    li      r3,0
    bl      AISetStreamPlayState
.L_8024E9DC:
    lwz     r0,60(r1)
    addi    r1,r1,56
    mtlr    r0
    blr
.size StopStreaming, . - StopStreaming

.global GetApploaderPosition
.balign 4
GetApploaderPosition:
/* 0x8024E9EC | size=0xC4 (196 bytes) */
    mflr    r0
    stw     r0,4(r1)
    stwu    r1,-72(r1)
    stw     r31,68(r1)
    lwz     r3,-23668(r13)
    cmpwi   r3,0
    beq-    .L_8024EA0C
    b       .L_8024EA9C
.L_8024EA0C:
    lis     r31,-32768
    lwz     r0,12532(r31)
    cmpwi   r0,0
    beq-    .L_8024EA90
    li      r3,64
    li      r4,32
    bl      OSAllocFromArenaLo
    lwz     r6,12532(r31)
    mr      r31,r3
    mr      r4,r31
    addi    r3,r1,8
    li      r5,64
    li      r7,0
    li      r8,0
    bl      DVDReadAbsAsyncPrio
    b       .L_8024EA4C
.L_8024EA4C:
    b       .L_8024EA50
.L_8024EA50:
    b       .L_8024EA68
.L_8024EA54:
    bl      DVDCheckDisk
    cmpwi   r3,0
    bne-    .L_8024EA68
    li      r3,0
    bl      __OSDoHotReset
.L_8024EA68:
    addi    r3,r1,8
    bl      DVDGetCommandBlockStatus
    cmpwi   r3,0
    bne+    .L_8024EA54
    lis     r3,-32768
    lwz     r0,56(r31)
    lwz     r3,12532(r3)
    add     r0,r3,r0
    stw     r0,-23668(r13)
    b       .L_8024EA98
.L_8024EA90:
    li      r0,9280
    stw     r0,-23668(r13)
.L_8024EA98:
    lwz     r3,-23668(r13)
.L_8024EA9C:
    lwz     r0,76(r1)
    lwz     r31,68(r1)
    addi    r1,r1,72
    mtlr    r0
    blr
.size GetApploaderPosition, . - GetApploaderPosition

.global LoadApploader
.balign 4
LoadApploader:
/* 0x8024EAB0 | size=0xF4 (244 bytes) */
    mflr    r0
    stw     r0,4(r1)
    stwu    r1,-112(r1)
    stw     r31,108(r1)
    li      r3,32
    li      r4,32
    bl      OSAllocFromArenaLo
    mr      r31,r3
    bl      GetApploaderPosition
    mr      r6,r3
    mr      r4,r31
    addi    r3,r1,56
    li      r5,32
    li      r7,0
    li      r8,0
    bl      DVDReadAbsAsyncPrio
    b       .L_8024EAF4
.L_8024EAF4:
    b       .L_8024EAF8
.L_8024EAF8:
    b       .L_8024EB10
.L_8024EAFC:
    bl      DVDCheckDisk
    cmpwi   r3,0
    bne-    .L_8024EB10
    li      r3,0
    bl      __OSDoHotReset
.L_8024EB10:
    addi    r3,r1,56
    bl      DVDGetCommandBlockStatus
    cmpwi   r3,0
    bne+    .L_8024EAFC
    bl      GetApploaderPosition
    lwz     r4,20(r31)
    addi    r6,r3,32
    addi    r3,r1,8
    addi    r0,r4,31
    clrrwi  r5,r0,5
    lis     r4,-32480
    li      r7,0
    li      r8,0
    bl      DVDReadAbsAsyncPrio
    b       .L_8024EB4C
.L_8024EB4C:
    b       .L_8024EB50
.L_8024EB50:
    b       .L_8024EB68
.L_8024EB54:
    bl      DVDCheckDisk
    cmpwi   r3,0
    bne-    .L_8024EB68
    li      r3,0
    bl      __OSDoHotReset
.L_8024EB68:
    addi    r3,r1,8
    bl      DVDGetCommandBlockStatus
    cmpwi   r3,0
    bne+    .L_8024EB54
    lwz     r4,20(r31)
    lis     r3,-32480
    addi    r0,r4,31
    clrrwi  r4,r0,5
    bl      ICInvalidateRange
    mr      r3,r31
    lwz     r0,116(r1)
    lwz     r31,108(r1)
    addi    r1,r1,112
    mtlr    r0
    blr
.size LoadApploader, . - LoadApploader

.global ExecCommon
.balign 4
ExecCommon:
/* 0x8024F314 | size=0x68 (104 bytes) */
    mflr    r0
    stw     r0,4(r1)
    stwu    r1,-88(r1)
    stw     r31,84(r1)
    mr      r31,r4
    lbz     r0,0(r3)
    extsb   r0,r0
    cmpwi   r0,0
    bne-    .L_8024F340
    li      r3,0
    b       .L_8024F35C
.L_8024F340:
    addi    r4,r1,16
    bl      DVDOpen
    cmpwi   r3,0
    beq-    .L_8024F358
    lwz     r3,64(r1)
    b       .L_8024F35C
.L_8024F358:
    b       .L_8024F368
.L_8024F35C:
    mr      r5,r31
    lis     r4,-16384
    bl      __OSBootDol
.L_8024F368:
    lwz     r0,92(r1)
    lwz     r31,84(r1)
    addi    r1,r1,88
    mtlr    r0
    blr
.size ExecCommon, . - ExecCommon

.global OSExecv
.balign 4
OSExecv:
/* 0x8024F37C | size=0x90 (144 bytes) */
    mflr    r0
    stw     r0,4(r1)
    stwu    r1,-88(r1)
    stw     r31,84(r1)
    stw     r30,80(r1)
    mr      r30,r3
    mr      r31,r4
    bl      OSDisableScheduler
    li      r3,0
    bl      __OSShutdownDevices
    bl      OSEnableScheduler
    lis     r3,-32472
    bl      OSSetArenaLo
    lis     r3,-32465
    bl      OSSetArenaHi
    lbz     r0,0(r30)
    extsb   r0,r0
    cmpwi   r0,0
    bne-    .L_8024F3D0
    li      r3,0
    b       .L_8024F3E8
.L_8024F3D0:
    mr      r3,r30
    addi    r4,r1,16
    bl      DVDOpen
    cmpwi   r3,0
    beq-    .L_8024F3F4
    lwz     r3,64(r1)
.L_8024F3E8:
    mr      r5,r31
    lis     r4,-16384
    bl      __OSBootDol
.L_8024F3F4:
    lwz     r0,92(r1)
    lwz     r31,84(r1)
    lwz     r30,80(r1)
    addi    r1,r1,88
    mtlr    r0
    blr
.size OSExecv, . - OSExecv

#
# === OSFatal.o ===
#

.global ScreenClear
.balign 4
ScreenClear:
/* 0x8036EF54 | size=0xF8 (248 bytes) */
    clrlwi  r7,r4,16
    clrlwi  r5,r5,16
    li      r8,0
    b       .L_8036F040
.L_8036EF64:
    cmpwi   r7,0
    addi    r4,r7,1
    srwi    r4,r4,1
    ble-    .L_8036F03C
    srwi.   r0,r4,2
    mtctr   r0
    beq-    .L_8036F010
.L_8036EF80:
    lbz     r0,0(r6)
    stb     r0,0(r3)
    lbz     r0,1(r6)
    stb     r0,1(r3)
    lbz     r0,0(r6)
    stb     r0,2(r3)
    lbz     r0,2(r6)
    stb     r0,3(r3)
    lbz     r0,0(r6)
    stb     r0,4(r3)
    lbz     r0,1(r6)
    stb     r0,5(r3)
    lbz     r0,0(r6)
    stb     r0,6(r3)
    lbz     r0,2(r6)
    stb     r0,7(r3)
    lbz     r0,0(r6)
    stb     r0,8(r3)
    lbz     r0,1(r6)
    stb     r0,9(r3)
    lbz     r0,0(r6)
    stb     r0,10(r3)
    lbz     r0,2(r6)
    stb     r0,11(r3)
    lbz     r0,0(r6)
    stb     r0,12(r3)
    lbz     r0,1(r6)
    stb     r0,13(r3)
    lbz     r0,0(r6)
    stb     r0,14(r3)
    lbz     r0,2(r6)
    stb     r0,15(r3)
    addi    r3,r3,16
    bdnz+   .L_8036EF80
    andi.   r4,r4,3
    beq-    .L_8036F03C
.L_8036F010:
    mtctr   r4
.L_8036F014:
    lbz     r0,0(r6)
    stb     r0,0(r3)
    lbz     r0,1(r6)
    stb     r0,1(r3)
    lbz     r0,0(r6)
    stb     r0,2(r3)
    lbz     r0,2(r6)
    stb     r0,3(r3)
    addi    r3,r3,4
    bdnz+   .L_8036F014
.L_8036F03C:
    addi    r8,r8,1
.L_8036F040:
    cmpw    r8,r5
    blt+    .L_8036EF64
    blr
.size ScreenClear, . - ScreenClear

.global ConfigureVideo
.balign 4
ConfigureVideo:
/* 0x8036F428 | size=0xFC (252 bytes) */
    mflr    r0
    stw     r0,4(r1)
    li      r0,480
    stwu    r1,-72(r1)
    sth     r3,16(r1)
    li      r3,40
    sth     r0,18(r1)
    li      r0,640
    sth     r4,20(r1)
    sth     r3,22(r1)
    sth     r0,26(r1)
    sth     r4,28(r1)
    bl      VIGetTvFormat
    cmpwi   r3,2
    beq-    .L_8036F484
    bge-    .L_8036F478
    cmpwi   r3,0
    beq-    .L_8036F484
    bge-    .L_8036F4E0
    b       .L_8036F4F8
.L_8036F478:
    cmpwi   r3,5
    beq-    .L_8036F4C4
    b       .L_8036F4F8
.L_8036F484:
    lis     r3,-13312
    lhz     r0,8300(r3)
    clrlwi. r0,r0,31
    beq-    .L_8036F4AC
    li      r0,2
    stw     r0,12(r1)
    li      r0,0
    sth     r0,24(r1)
    stw     r0,32(r1)
    b       .L_8036F4F8
.L_8036F4AC:
    li      r3,0
    stw     r3,12(r1)
    li      r0,1
    sth     r3,24(r1)
    stw     r0,32(r1)
    b       .L_8036F4F8
.L_8036F4C4:
    li      r0,20
    stw     r0,12(r1)
    li      r3,0
    li      r0,1
    sth     r3,24(r1)
    stw     r0,32(r1)
    b       .L_8036F4F8
.L_8036F4E0:
    li      r0,4
    stw     r0,12(r1)
    li      r3,47
    li      r0,1
    sth     r3,24(r1)
    stw     r0,32(r1)
.L_8036F4F8:
    addi    r3,r1,12
    bl      VIConfigure
    li      r3,0
    li      r4,0
    li      r5,640
    li      r6,480
    bl      VIConfigurePan
    lwz     r0,76(r1)
    addi    r1,r1,72
    mtlr    r0
    blr
.size ConfigureVideo, . - ConfigureVideo

#
# === OSFont.o ===
#

.global IsSjisLeadByte
.balign 4
IsSjisLeadByte:
/* 0x8036FEB8 | size=0x58 (88 bytes) */
    clrlwi  r0,r3,24
    cmplwi  r0,129
    li      r4,1
    li      r5,0
    blt-    .L_8036FED8
    cmplwi  r0,159
    bgt-    .L_8036FED8
    mr      r5,r4
.L_8036FED8:
    cmpwi   r5,0
    bne-    .L_8036FF08
    clrlwi  r0,r3,24
    cmplwi  r0,224
    li      r3,0
    blt-    .L_8036FEFC
    cmplwi  r0,252
    bgt-    .L_8036FEFC
    li      r3,1
.L_8036FEFC:
    cmpwi   r3,0
    bne-    .L_8036FF08
    li      r4,0
.L_8036FF08:
    mr      r3,r4
    blr
.size IsSjisLeadByte, . - IsSjisLeadByte

.global OSGetFontEncode
.balign 4
OSGetFontEncode:
/* 0x8037026C | size=0x64 (100 bytes) */
    lhz     r3,-25400(r13)
    cmplwi  r3,65535
    bnelr-
    lis     r3,-32768
    lwz     r0,204(r3)
    cmpwi   r0,0
    beq-    .L_80370290
    blt-    .L_803702B4
    b       .L_803702B4
.L_80370290:
    lis     r3,-13312
    lhz     r0,8302(r3)
    rlwinm. r0,r0,0,30,30
    beq-    .L_803702A8
    li      r0,1
    b       .L_803702AC
.L_803702A8:
    li      r0,0
.L_803702AC:
    sth     r0,-25400(r13)
    b       .L_803702BC
.L_803702B4:
    li      r0,0
    sth     r0,-25400(r13)
.L_803702BC:
    lis     r4,-32713
    lhz     r3,-25400(r13)
    addi    r0,r4,2136
    stw     r0,-22372(r13)
    blr
.size OSGetFontEncode, . - OSGetFontEncode

.global OSSetFontEncode
.balign 4
OSSetFontEncode:
/* 0x803702D0 | size=0x98 (152 bytes) */
    lhz     r5,-25400(r13)
    cmplwi  r5,65535
    beq-    .L_803702E0
    b       .L_80370334
.L_803702E0:
    lis     r4,-32768
    lwz     r0,204(r4)
    cmpwi   r0,0
    beq-    .L_803702F8
    blt-    .L_8037031C
    b       .L_8037031C
.L_803702F8:
    lis     r4,-13312
    lhz     r0,8302(r4)
    rlwinm. r0,r0,0,30,30
    beq-    .L_80370310
    li      r0,1
    b       .L_80370314
.L_80370310:
    li      r0,0
.L_80370314:
    sth     r0,-25400(r13)
    b       .L_80370324
.L_8037031C:
    li      r0,0
    sth     r0,-25400(r13)
.L_80370324:
    lis     r4,-32713
    lhz     r5,-25400(r13)
    addi    r0,r4,2136
    stw     r0,-22372(r13)
.L_80370334:
    clrlwi  r0,r3,16
    cmplwi  r0,5
    bgt-    .L_80370360
    cmplwi  r0,3
    sth     r3,-25400(r13)
    blt-    .L_80370360
    cmplwi  r0,5
    bgt-    .L_80370360
    lis     r3,-32713
    addi    r0,r3,2452
    stw     r0,-22372(r13)
.L_80370360:
    mr      r3,r5
    blr
.size OSSetFontEncode, . - OSSetFontEncode

.global ReadROM
.balign 4
ReadROM:
/* 0x80370368 | size=0x8C (140 bytes) */
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
    b       .L_803703CC
.L_80370394:
    cmpwi   r29,256
    bgt-    .L_803703A4
    mr      r31,r29
    b       .L_803703A8
.L_803703A4:
    li      r31,256
.L_803703A8:
    subf    r29,r31,r29
.L_803703AC:
    addi    r3,r28,0
    addi    r4,r31,0
    addi    r5,r30,0
    bl      __OSReadROM
    cmpwi   r3,0
    beq+    .L_803703AC
    add     r30,r30,r31
    add     r28,r28,r31
.L_803703CC:
    cmpwi   r29,0
    bgt+    .L_80370394
    lwz     r0,44(r1)
    lwz     r31,36(r1)
    lwz     r30,32(r1)
    lwz     r29,28(r1)
    lwz     r28,24(r1)
    addi    r1,r1,40
    mtlr    r0
    blr
.size ReadROM, . - ReadROM

.global OSGetFontWidth
.balign 4
OSGetFontWidth:
/* 0x80371558 | size=0xD4 (212 bytes) */
    mflr    r0
    addi    r6,r3,0
    stw     r0,4(r1)
    stwu    r1,-32(r1)
    stw     r31,28(r1)
    addi    r31,r4,0
    lhz     r5,-25400(r13)
    cmplwi  r5,65535
    beq-    .L_80371580
    b       .L_803715D4
.L_80371580:
    lis     r3,-32768
    lwz     r0,204(r3)
    cmpwi   r0,0
    beq-    .L_80371598
    blt-    .L_803715BC
    b       .L_803715BC
.L_80371598:
    lis     r3,-13312
    lhz     r0,8302(r3)
    rlwinm. r0,r0,0,30,30
    beq-    .L_803715B0
    li      r0,1
    b       .L_803715B4
.L_803715B0:
    li      r0,0
.L_803715B4:
    sth     r0,-25400(r13)
    b       .L_803715C4
.L_803715BC:
    li      r0,0
    sth     r0,-25400(r13)
.L_803715C4:
    lis     r3,-32713
    lhz     r5,-25400(r13)
    addi    r0,r3,2136
    stw     r0,-22372(r13)
.L_803715D4:
    lwz     r12,-22372(r13)
    addi    r3,r5,0
    addi    r4,r6,0
    mtlr    r12
    addi    r5,r1,20
    addi    r6,r1,16
    blrl
    cmplwi  r31,0
    addi    r6,r3,0
    beq-    .L_80371614
    lwz     r4,20(r1)
    lwz     r3,16(r1)
    lhz     r0,34(r4)
    add     r0,r4,r0
    lbzx    r0,r3,r0
    stw     r0,0(r31)
.L_80371614:
    lwz     r0,36(r1)
    mr      r3,r6
    lwz     r31,28(r1)
    addi    r1,r1,32
    mtlr    r0
    blr
.size OSGetFontWidth, . - OSGetFontWidth

#
# === OSInterrupt.o ===
#

.global __OSInterruptInit
.balign 4
__OSInterruptInit:
/* 0x8024F5CC | size=0x74 (116 bytes) */
    mflr    r0
    stw     r0,4(r1)
    stwu    r1,-16(r1)
    stw     r31,12(r1)
    lis     r31,-32768
    addi    r0,r31,12352
    stw     r0,-23664(r13)
    li      r4,0
    li      r5,128
    lwz     r3,-23664(r13)
    bl      memset
    li      r0,0
    stw     r0,196(r31)
    lis     r3,-13312
    addi    r4,r3,12288
    stw     r0,200(r31)
    li      r0,240
    li      r3,-32
    stw     r0,4(r4)
    bl      __OSMaskInterrupts
    lis     r3,-32731
    addi    r4,r3,-504
    li      r3,4
    bl      __OSSetExceptionHandler
    lwz     r0,20(r1)
    lwz     r31,12(r1)
    addi    r1,r1,16
    mtlr    r0
    blr
.size __OSInterruptInit, . - __OSInterruptInit

.global OSSetInterruptMask
.balign 4
OSSetInterruptMask:
/* 0x8024F924 | size=0x90 (144 bytes) */
    mflr    r0
    stw     r0,4(r1)
    stwu    r1,-32(r1)
    stw     r31,28(r1)
    stw     r30,24(r1)
    stw     r29,20(r1)
    stw     r28,16(r1)
    mr      r28,r3
    bl      OSDisableInterrupts
    lis     r4,-32768
    lwz     r0,196(r4)
    mr      r30,r3
    lwz     r5,200(r4)
    or      r31,r0,r28
    or      r0,r0,r5
    stw     r28,200(r4)
    mr      r29,r5
    xor     r3,r28,r0
    b       .L_8024F970
.L_8024F970:
    b       .L_8024F974
.L_8024F974:
    b       .L_8024F980
.L_8024F978:
    mr      r4,r31
    bl      SetInterruptMask
.L_8024F980:
    cmplwi  r3,0
    bne+    .L_8024F978
    mr      r3,r30
    bl      OSRestoreInterrupts
    mr      r3,r29
    lwz     r0,36(r1)
    lwz     r31,28(r1)
    lwz     r30,24(r1)
    lwz     r29,20(r1)
    lwz     r28,16(r1)
    addi    r1,r1,32
    mtlr    r0
    blr
.size OSSetInterruptMask, . - OSSetInterruptMask

.global __OSMaskInterrupts
.balign 4
__OSMaskInterrupts:
/* 0x8024F9B4 | size=0x88 (136 bytes) */
    mflr    r0
    stw     r0,4(r1)
    stwu    r1,-32(r1)
    stw     r31,28(r1)
    stw     r30,24(r1)
    stw     r29,20(r1)
    mr      r31,r3
    bl      OSDisableInterrupts
    lis     r4,-32768
    lwz     r29,196(r4)
    mr      r30,r3
    lwz     r5,200(r4)
    or      r0,r29,r5
    andc    r3,r31,r0
    or      r31,r31,r29
    stw     r31,196(r4)
    or      r31,r31,r5
    b       .L_8024F9FC
.L_8024F9FC:
    b       .L_8024FA00
.L_8024FA00:
    b       .L_8024FA0C
.L_8024FA04:
    mr      r4,r31
    bl      SetInterruptMask
.L_8024FA0C:
    cmplwi  r3,0
    bne+    .L_8024FA04
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
.size __OSMaskInterrupts, . - __OSMaskInterrupts

.global __OSUnmaskInterrupts
.balign 4
__OSUnmaskInterrupts:
/* 0x8024FA3C | size=0x88 (136 bytes) */
    mflr    r0
    stw     r0,4(r1)
    stwu    r1,-32(r1)
    stw     r31,28(r1)
    stw     r30,24(r1)
    stw     r29,20(r1)
    mr      r31,r3
    bl      OSDisableInterrupts
    lis     r4,-32768
    lwz     r29,196(r4)
    mr      r30,r3
    lwz     r5,200(r4)
    or      r0,r29,r5
    and     r3,r31,r0
    andc    r31,r29,r31
    stw     r31,196(r4)
    or      r31,r31,r5
    b       .L_8024FA84
.L_8024FA84:
    b       .L_8024FA88
.L_8024FA88:
    b       .L_8024FA94
.L_8024FA8C:
    mr      r4,r31
    bl      SetInterruptMask
.L_8024FA94:
    cmplwi  r3,0
    bne+    .L_8024FA8C
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
.size __OSUnmaskInterrupts, . - __OSUnmaskInterrupts

.global ExternalInterruptHandler
.balign 4
ExternalInterruptHandler:
/* 0x8024FE08 | size=0x50 (80 bytes) */
    stw     r0,0(r4)
    stw     r1,4(r4)
    stw     r2,8(r4)
    stmw    r6,24(r4)
    mfgqr   r0,1
    stw     r0,424(r4)
    mfgqr   r0,2
    stw     r0,428(r4)
    mfgqr   r0,3
    stw     r0,432(r4)
    mfgqr   r0,4
    stw     r0,436(r4)
    mfgqr   r0,5
    stw     r0,440(r4)
    mfgqr   r0,6
    stw     r0,444(r4)
    mfgqr   r0,7
    stw     r0,448(r4)
    stwu    r1,-8(r1)
    b       __OSDispatchInterrupt
.size ExternalInterruptHandler, . - ExternalInterruptHandler

#
# === OSLink.o ===
#

.global OSSearchModule
.balign 4
OSSearchModule:
/* 0x8025088C | size=0xA0 (160 bytes) */
    cmplwi  r3,0
    bne-    .L_8025089C
    li      r3,0
    blr
.L_8025089C:
    lis     r6,-32768
    lwz     r8,12488(r6)
    b       .L_8025091C
.L_802508A8:
    lwz     r0,12(r8)
    li      r10,0
    lwz     r9,16(r8)
    cmplwi  r0,0
    mtctr   r0
    ble-    .L_80250918
.L_802508C0:
    lwz     r7,4(r9)
    cmplwi  r7,0
    beq-    .L_8025090C
    lwz     r0,0(r9)
    clrrwi  r6,r0,1
    cmplw   r6,r3
    bgt-    .L_8025090C
    add     r0,r6,r7
    cmplw   r3,r0
    bge-    .L_8025090C
    cmplwi  r4,0
    beq-    .L_802508F4
    stw     r10,0(r4)
.L_802508F4:
    cmplwi  r5,0
    beq-    .L_80250904
    subf    r0,r6,r3
    stw     r0,0(r5)
.L_80250904:
    mr      r3,r8
    blr
.L_8025090C:
    addi    r9,r9,8
    addi    r10,r10,1
    bdnz+   .L_802508C0
.L_80250918:
    lwz     r8,4(r8)
.L_8025091C:
    cmplwi  r8,0
    bne+    .L_802508A8
    li      r3,0
    blr
.size OSSearchModule, . - OSSearchModule

#
# === OSMemory.o ===
#

.global MEMIntrruptHandler
.balign 4
MEMIntrruptHandler:
/* 0x80250980 | size=0x6C (108 bytes) */
    mflr    r0
    lis     r3,-13312
    stw     r0,4(r1)
    addi    r8,r3,16384
    li      r0,0
    stwu    r1,-8(r1)
    lhz     r7,16420(r3)
    lis     r3,-32694
    lhz     r6,34(r8)
    addi    r3,r3,-24784
    lhz     r5,30(r8)
    rlwimi  r6,r7,16,6,15
    sth     r0,32(r8)
    lwz     r12,60(r3)
    cmplwi  r12,0
    beq-    .L_802509D4
    mtlr    r12
    li      r3,15
    crclr   4*cr1+eq
    blrl
    b       .L_802509DC
.L_802509D4:
    li      r3,15
    bl      __OSUnhandledException
.L_802509DC:
    lwz     r0,12(r1)
    addi    r1,r1,8
    mtlr    r0
    blr
.size MEMIntrruptHandler, . - MEMIntrruptHandler

.global OSProtectRange
.balign 4
OSProtectRange:
/* 0x802509EC | size=0xC4 (196 bytes) */
    mflr    r0
    stw     r0,4(r1)
    stwu    r1,-48(r1)
    stmw    r26,24(r1)
    addi    r26,r3,0
    cmplwi  r26,4
    bge-    .L_80250A9C
    add     r3,r4,r5
    addi    r0,r3,1023
    clrrwi  r27,r4,10
    clrrwi  r29,r0,10
    addi    r3,r27,0
    clrlwi  r31,r6,30
    subf    r4,r27,r29
    bl      DCFlushRange
    bl      OSDisableInterrupts
    lis     r0,-32768
    srw     r30,r0,r26
    addi    r28,r3,0
    addi    r3,r30,0
    bl      __OSMaskInterrupts
    lis     r3,-13312
    addi    r5,r3,16384
    slwi    r3,r26,2
    rlwinm  r0,r27,22,16,31
    sthx    r0,r5,r3
    rlwinm  r4,r29,22,16,31
    add     r3,r5,r3
    sth     r4,2(r3)
    addi    r4,r5,16
    slwi    r6,r26,1
    li      r0,3
    lhz     r5,16(r5)
    slw     r3,r0,r6
    slw     r0,r31,r6
    andc    r5,r5,r3
    or      r5,r5,r0
    cmplwi  r31,3
    sth     r5,0(r4)
    beq-    .L_80250A94
    mr      r3,r30
    bl      __OSUnmaskInterrupts
.L_80250A94:
    mr      r3,r28
    bl      OSRestoreInterrupts
.L_80250A9C:
    lmw     r26,24(r1)
    lwz     r0,52(r1)
    addi    r1,r1,48
    mtlr    r0
    blr
.size OSProtectRange, . - OSProtectRange

.global Config24MB
.balign 4
Config24MB:
/* 0x80250AB0 | size=0x80 (128 bytes) */
    li      r7,0
    lis     r4,0
    addi    r4,r4,2
    lis     r3,-32768
    addi    r3,r3,511
    lis     r6,256
    addi    r6,r6,2
    lis     r5,-32512
    addi    r5,r5,255
    isync
    mtdbatu 0,r7
    mtdbatl 0,r4
    mtdbatu 0,r3
    isync
    mtibatu 0,r7
    mtibatl 0,r4
    mtibatu 0,r3
    isync
    mtdbatu 2,r7
    mtdbatl 2,r6
    mtdbatu 2,r5
    isync
    mtibatu 2,r7
    mtibatl 2,r6
    mtibatu 2,r5
    isync
    mfmsr   r3
    ori     r3,r3,48
    mtsrr1  r3
    mflr    r3
    mtsrr0  r3
    rfi
.size Config24MB, . - Config24MB

.global Config48MB
.balign 4
Config48MB:
/* 0x80250B30 | size=0x80 (128 bytes) */
    li      r7,0
    lis     r4,0
    addi    r4,r4,2
    lis     r3,-32768
    addi    r3,r3,1023
    lis     r6,512
    addi    r6,r6,2
    lis     r5,-32256
    addi    r5,r5,511
    isync
    mtdbatu 0,r7
    mtdbatl 0,r4
    mtdbatu 0,r3
    isync
    mtibatu 0,r7
    mtibatl 0,r4
    mtibatu 0,r3
    isync
    mtdbatu 2,r7
    mtdbatl 2,r6
    mtdbatu 2,r5
    isync
    mtibatu 2,r7
    mtibatl 2,r6
    mtibatu 2,r5
    isync
    mfmsr   r3
    ori     r3,r3,48
    mtsrr1  r3
    mflr    r3
    mtsrr0  r3
    rfi
.size Config48MB, . - Config48MB

#
# === OSMessage.o ===
#

.global OSInitMessageQueue
.balign 4
OSInitMessageQueue:
/* 0x8037163C | size=0x60 (96 bytes) */
    mflr    r0
    stw     r0,4(r1)
    stwu    r1,-40(r1)
    stw     r31,36(r1)
    addi    r31,r5,0
    stw     r30,32(r1)
    addi    r30,r4,0
    stw     r29,28(r1)
    addi    r29,r3,0
    bl      OSInitThreadQueue
    addi    r3,r29,8
    bl      OSInitThreadQueue
    stw     r30,16(r29)
    li      r0,0
    stw     r31,20(r29)
    stw     r0,24(r29)
    stw     r0,28(r29)
    lwz     r0,44(r1)
    lwz     r31,36(r1)
    lwz     r30,32(r1)
    lwz     r29,28(r1)
    addi    r1,r1,40
    mtlr    r0
    blr
.size OSInitMessageQueue, . - OSInitMessageQueue

.global OSSendMessage
.balign 4
OSSendMessage:
/* 0x8037169C | size=0xC8 (200 bytes) */
    mflr    r0
    stw     r0,4(r1)
    stwu    r1,-40(r1)
    stw     r31,36(r1)
    addi    r31,r5,0
    stw     r30,32(r1)
    stw     r29,28(r1)
    addi    r29,r4,0
    stw     r28,24(r1)
    addi    r28,r3,0
    bl      OSDisableInterrupts
    addi    r30,r3,0
    clrlwi  r31,r31,31
    b       .L_803716F4
.L_803716D4:
    cmpwi   r31,0
    bne-    .L_803716EC
    mr      r3,r30
    bl      OSRestoreInterrupts
    li      r3,0
    b       .L_80371744
.L_803716EC:
    mr      r3,r28
    bl      OSSleepThread
.L_803716F4:
    lwz     r6,20(r28)
    lwz     r4,28(r28)
    cmpw    r6,r4
    ble+    .L_803716D4
    lwz     r0,24(r28)
    addi    r3,r28,8
    lwz     r5,16(r28)
    add     r4,r0,r4
    divw    r0,r4,r6
    mullw   r0,r0,r6
    subf    r0,r0,r4
    slwi    r0,r0,2
    stwx    r29,r5,r0
    lwz     r4,28(r28)
    addi    r0,r4,1
    stw     r0,28(r28)
    bl      OSWakeupThread
    mr      r3,r30
    bl      OSRestoreInterrupts
    li      r3,1
.L_80371744:
    lwz     r0,44(r1)
    lwz     r31,36(r1)
    lwz     r30,32(r1)
    lwz     r29,28(r1)
    lwz     r28,24(r1)
    addi    r1,r1,40
    mtlr    r0
    blr
.size OSSendMessage, . - OSSendMessage

.global OSReceiveMessage
.balign 4
OSReceiveMessage:
/* 0x80371764 | size=0xDC (220 bytes) */
    mflr    r0
    stw     r0,4(r1)
    stwu    r1,-40(r1)
    stw     r31,36(r1)
    addi    r31,r3,0
    stw     r30,32(r1)
    addi    r30,r5,0
    stw     r29,28(r1)
    stw     r28,24(r1)
    addi    r28,r4,0
    bl      OSDisableInterrupts
    addi    r29,r3,0
    clrlwi  r30,r30,31
    b       .L_803717BC
.L_8037179C:
    cmpwi   r30,0
    bne-    .L_803717B4
    mr      r3,r29
    bl      OSRestoreInterrupts
    li      r3,0
    b       .L_80371820
.L_803717B4:
    addi    r3,r31,8
    bl      OSSleepThread
.L_803717BC:
    lwz     r0,28(r31)
    cmpwi   r0,0
    beq+    .L_8037179C
    cmplwi  r28,0
    beq-    .L_803717E4
    lwz     r0,24(r31)
    lwz     r3,16(r31)
    slwi    r0,r0,2
    lwzx    r0,r3,r0
    stw     r0,0(r28)
.L_803717E4:
    lwz     r5,24(r31)
    mr      r3,r31
    lwz     r4,20(r31)
    addi    r5,r5,1
    divw    r0,r5,r4
    mullw   r0,r0,r4
    subf    r0,r0,r5
    stw     r0,24(r31)
    lwz     r4,28(r31)
    addi    r0,r4,-1
    stw     r0,28(r31)
    bl      OSWakeupThread
    mr      r3,r29
    bl      OSRestoreInterrupts
    li      r3,1
.L_80371820:
    lwz     r0,44(r1)
    lwz     r31,36(r1)
    lwz     r30,32(r1)
    lwz     r29,28(r1)
    lwz     r28,24(r1)
    addi    r1,r1,40
    mtlr    r0
    blr
.size OSReceiveMessage, . - OSReceiveMessage

.global OSJamMessage
.balign 4
OSJamMessage:
/* 0x80371840 | size=0xD4 (212 bytes) */
    mflr    r0
    stw     r0,4(r1)
    stwu    r1,-40(r1)
    stw     r31,36(r1)
    addi    r31,r3,0
    stw     r30,32(r1)
    addi    r30,r5,0
    stw     r29,28(r1)
    stw     r28,24(r1)
    addi    r28,r4,0
    bl      OSDisableInterrupts
    addi    r29,r3,0
    clrlwi  r30,r30,31
    b       .L_80371898
.L_80371878:
    cmpwi   r30,0
    bne-    .L_80371890
    mr      r3,r29
    bl      OSRestoreInterrupts
    li      r3,0
    b       .L_803718F4
.L_80371890:
    mr      r3,r31
    bl      OSSleepThread
.L_80371898:
    lwz     r5,20(r31)
    lwz     r0,28(r31)
    cmpw    r5,r0
    ble+    .L_80371878
    lwz     r4,24(r31)
    addi    r0,r5,-1
    addi    r3,r31,8
    add     r4,r4,r0
    divw    r0,r4,r5
    mullw   r0,r0,r5
    subf    r0,r0,r4
    stw     r0,24(r31)
    lwz     r0,24(r31)
    lwz     r4,16(r31)
    slwi    r0,r0,2
    stwx    r28,r4,r0
    lwz     r4,28(r31)
    addi    r0,r4,1
    stw     r0,28(r31)
    bl      OSWakeupThread
    mr      r3,r29
    bl      OSRestoreInterrupts
    li      r3,1
.L_803718F4:
    lwz     r0,44(r1)
    lwz     r31,36(r1)
    lwz     r30,32(r1)
    lwz     r29,28(r1)
    lwz     r28,24(r1)
    addi    r1,r1,40
    mtlr    r0
    blr
.size OSJamMessage, . - OSJamMessage

#
# === OSMutex.o ===
#

.global OSLockMutex
.balign 4
OSLockMutex:
/* 0x80255DE0 | size=0xDC (220 bytes) */
    mflr    r0
    stw     r0,4(r1)
    stwu    r1,-32(r1)
    stw     r31,28(r1)
    stw     r30,24(r1)
    stw     r29,20(r1)
    stw     r28,16(r1)
    mr      r28,r3
    bl      OSDisableInterrupts
    mr      r29,r3
    bl      OSGetCurrentThread
    addi    r30,r3,0
    li      r31,0
.L_80255E14:
    lwz     r0,8(r28)
    cmplwi  r0,0
    bne-    .L_80255E5C
    stw     r30,8(r28)
    lwz     r3,12(r28)
    addi    r0,r3,1
    stw     r0,12(r28)
    lwz     r3,760(r30)
    cmplwi  r3,0
    bne-    .L_80255E44
    stw     r28,756(r30)
    b       .L_80255E48
.L_80255E44:
    stw     r28,16(r3)
.L_80255E48:
    stw     r3,20(r28)
    li      r0,0
    stw     r0,16(r28)
    stw     r28,760(r30)
    b       .L_80255E94
.L_80255E5C:
    cmplw   r0,r30
    bne-    .L_80255E74
    lwz     r3,12(r28)
    addi    r0,r3,1
    stw     r0,12(r28)
    b       .L_80255E94
.L_80255E74:
    stw     r28,752(r30)
    lwz     r3,8(r28)
    lwz     r4,720(r30)
    bl      __OSPromoteThread
    mr      r3,r28
    bl      OSSleepThread
    stw     r31,752(r30)
    b       .L_80255E14
.L_80255E94:
    mr      r3,r29
    bl      OSRestoreInterrupts
    lwz     r0,36(r1)
    lwz     r31,28(r1)
    lwz     r30,24(r1)
    lwz     r29,20(r1)
    lwz     r28,16(r1)
    addi    r1,r1,32
    mtlr    r0
    blr
.size OSLockMutex, . - OSLockMutex

.global OSUnlockMutex
.balign 4
OSUnlockMutex:
/* 0x80255EBC | size=0xC8 (200 bytes) */
    mflr    r0
    stw     r0,4(r1)
    stwu    r1,-32(r1)
    stw     r31,28(r1)
    stw     r30,24(r1)
    stw     r29,20(r1)
    mr      r29,r3
    bl      OSDisableInterrupts
    mr      r31,r3
    bl      OSGetCurrentThread
    lwz     r0,8(r29)
    addi    r30,r3,0
    cmplw   r0,r30
    bne-    .L_80255F60
    lwz     r3,12(r29)
    addic.  r0,r3,-1
    stw     r0,12(r29)
    bne-    .L_80255F60
    lwz     r3,16(r29)
    lwz     r4,20(r29)
    cmplwi  r3,0
    bne-    .L_80255F1C
    stw     r4,760(r30)
    b       .L_80255F20
.L_80255F1C:
    stw     r4,20(r3)
.L_80255F20:
    cmplwi  r4,0
    bne-    .L_80255F30
    stw     r3,756(r30)
    b       .L_80255F34
.L_80255F30:
    stw     r3,16(r4)
.L_80255F34:
    li      r0,0
    stw     r0,8(r29)
    lwz     r3,720(r30)
    lwz     r0,724(r30)
    cmpw    r3,r0
    bge-    .L_80255F58
    mr      r3,r30
    bl      __OSGetEffectivePriority
    stw     r3,720(r30)
.L_80255F58:
    mr      r3,r29
    bl      OSWakeupThread
.L_80255F60:
    mr      r3,r31
    bl      OSRestoreInterrupts
    lwz     r0,36(r1)
    lwz     r31,28(r1)
    lwz     r30,24(r1)
    lwz     r29,20(r1)
    addi    r1,r1,32
    mtlr    r0
    blr
.size OSUnlockMutex, . - OSUnlockMutex

.global __OSUnlockAllMutex
.balign 4
__OSUnlockAllMutex:
/* 0x80255F84 | size=0x70 (112 bytes) */
    mflr    r0
    stw     r0,4(r1)
    stwu    r1,-24(r1)
    stw     r31,20(r1)
    li      r31,0
    stw     r30,16(r1)
    addi    r30,r3,0
    b       .L_80255FD0
.L_80255FA4:
    lwz     r5,16(r4)
    addi    r3,r4,0
    cmplwi  r5,0
    bne-    .L_80255FBC
    stw     r31,760(r30)
    b       .L_80255FC0
.L_80255FBC:
    stw     r31,20(r5)
.L_80255FC0:
    stw     r5,756(r30)
    stw     r31,12(r4)
    stw     r31,8(r4)
    bl      OSWakeupThread
.L_80255FD0:
    lwz     r4,756(r30)
    cmplwi  r4,0
    bne+    .L_80255FA4
    lwz     r0,28(r1)
    lwz     r31,20(r1)
    lwz     r30,16(r1)
    addi    r1,r1,24
    mtlr    r0
    blr
.size __OSUnlockAllMutex, . - __OSUnlockAllMutex

.global OSTryLockMutex
.balign 4
OSTryLockMutex:
/* 0x80255FF4 | size=0xBC (188 bytes) */
    mflr    r0
    stw     r0,4(r1)
    stwu    r1,-32(r1)
    stw     r31,28(r1)
    stw     r30,24(r1)
    stw     r29,20(r1)
    mr      r29,r3
    bl      OSDisableInterrupts
    mr      r31,r3
    bl      OSGetCurrentThread
    lwz     r0,8(r29)
    cmplwi  r0,0
    bne-    .L_80256068
    stw     r3,8(r29)
    lwz     r4,12(r29)
    addi    r0,r4,1
    stw     r0,12(r29)
    lwz     r4,760(r3)
    cmplwi  r4,0
    bne-    .L_8025604C
    stw     r29,756(r3)
    b       .L_80256050
.L_8025604C:
    stw     r29,16(r4)
.L_80256050:
    stw     r4,20(r29)
    li      r0,0
    li      r30,1
    stw     r0,16(r29)
    stw     r29,760(r3)
    b       .L_80256088
.L_80256068:
    cmplw   r0,r3
    bne-    .L_80256084
    lwz     r3,12(r29)
    li      r30,1
    addi    r0,r3,1
    stw     r0,12(r29)
    b       .L_80256088
.L_80256084:
    li      r30,0
.L_80256088:
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
.size OSTryLockMutex, . - OSTryLockMutex

.global OSWaitCond
.balign 4
OSWaitCond:
/* 0x802560D0 | size=0xD4 (212 bytes) */
    mflr    r0
    stw     r0,4(r1)
    stwu    r1,-40(r1)
    stmw    r27,20(r1)
    addi    r27,r3,0
    addi    r28,r4,0
    bl      OSDisableInterrupts
    mr      r31,r3
    bl      OSGetCurrentThread
    lwz     r0,8(r28)
    addi    r30,r3,0
    cmplw   r0,r30
    bne-    .L_80256188
    lwz     r29,12(r28)
    li      r0,0
    stw     r0,12(r28)
    lwz     r3,16(r28)
    lwz     r4,20(r28)
    cmplwi  r3,0
    bne-    .L_80256128
    stw     r4,760(r30)
    b       .L_8025612C
.L_80256128:
    stw     r4,20(r3)
.L_8025612C:
    cmplwi  r4,0
    bne-    .L_8025613C
    stw     r3,756(r30)
    b       .L_80256140
.L_8025613C:
    stw     r3,16(r4)
.L_80256140:
    li      r0,0
    stw     r0,8(r28)
    lwz     r3,720(r30)
    lwz     r0,724(r30)
    cmpw    r3,r0
    bge-    .L_80256164
    mr      r3,r30
    bl      __OSGetEffectivePriority
    stw     r3,720(r30)
.L_80256164:
    bl      OSDisableScheduler
    mr      r3,r28
    bl      OSWakeupThread
    bl      OSEnableScheduler
    mr      r3,r27
    bl      OSSleepThread
    mr      r3,r28
    bl      OSLockMutex
    stw     r29,12(r28)
.L_80256188:
    mr      r3,r31
    bl      OSRestoreInterrupts
    lmw     r27,20(r1)
    lwz     r0,44(r1)
    addi    r1,r1,40
    mtlr    r0
    blr
.size OSWaitCond, . - OSWaitCond

.global __OSCheckMutex
.balign 4
__OSCheckMutex:
/* 0x802561F0 | size=0x100 (256 bytes) */
    lwz     r4,0(r3)
    li      r7,0
    cmplwi  r4,0
    beq-    .L_80256214
    lwz     r0,740(r4)
    cmplwi  r0,0
    beq-    .L_80256214
    li      r3,0
    blr
.L_80256214:
    lwz     r5,4(r3)
    cmplwi  r5,0
    beq-    .L_80256234
    lwz     r0,736(r5)
    cmplwi  r0,0
    beq-    .L_80256234
    li      r3,0
    blr
.L_80256234:
    mr      r6,r4
    b       .L_802562AC
.L_8025623C:
    lwz     r4,736(r6)
    cmplwi  r4,0
    beq-    .L_8025625C
    lwz     r0,740(r4)
    cmplw   r6,r0
    beq-    .L_8025625C
    li      r3,0
    blr
.L_8025625C:
    lwz     r5,740(r6)
    cmplwi  r5,0
    beq-    .L_8025627C
    lwz     r0,736(r5)
    cmplw   r6,r0
    beq-    .L_8025627C
    li      r3,0
    blr
.L_8025627C:
    lhz     r0,712(r6)
    cmplwi  r0,4
    beq-    .L_80256290
    li      r3,0
    blr
.L_80256290:
    lwz     r0,720(r6)
    cmpw    r0,r7
    bge-    .L_802562A4
    li      r3,0
    blr
.L_802562A4:
    mr      r7,r0
    addi    r6,r4,0
.L_802562AC:
    cmplwi  r6,0
    bne+    .L_8025623C
    lwz     r0,8(r3)
    cmplwi  r0,0
    beq-    .L_802562D4
    lwz     r0,12(r3)
    cmpwi   r0,0
    bgt-    .L_802562E8
    li      r3,0
    blr
.L_802562D4:
    lwz     r0,12(r3)
    cmpwi   r0,0
    beq-    .L_802562E8
    li      r3,0
    blr
.L_802562E8:
    li      r3,1
    blr
.size __OSCheckMutex, . - __OSCheckMutex

.global __OSCheckMutexes
.balign 4
__OSCheckMutexes:
/* 0x80256328 | size=0x74 (116 bytes) */
    mflr    r0
    stw     r0,4(r1)
    stwu    r1,-24(r1)
    stw     r31,20(r1)
    stw     r30,16(r1)
    mr      r30,r3
    lwz     r31,756(r3)
    b       .L_80256378
.L_80256348:
    lwz     r0,8(r31)
    cmplw   r0,r30
    beq-    .L_8025635C
    li      r3,0
    b       .L_80256384
.L_8025635C:
    mr      r3,r31
    bl      __OSCheckMutex
    cmpwi   r3,0
    bne-    .L_80256374
    li      r3,0
    b       .L_80256384
.L_80256374:
    lwz     r31,16(r31)
.L_80256378:
    cmplwi  r31,0
    bne+    .L_80256348
    li      r3,1
.L_80256384:
    lwz     r0,28(r1)
    lwz     r31,20(r1)
    lwz     r30,16(r1)
    addi    r1,r1,24
    mtlr    r0
    blr
.size __OSCheckMutexes, . - __OSCheckMutexes

#
# === OSReboot.o ===
#

.global __OSReboot
.balign 4
__OSReboot:
/* 0x80250CE0 | size=0x70 (112 bytes) */
    mflr    r0
    stw     r0,4(r1)
    stwu    r1,-744(r1)
    stw     r31,740(r1)
    addi    r31,r4,0
    stw     r30,736(r1)
    addi    r30,r3,0
    bl      OSDisableInterrupts
    lis     r3,-32472
    bl      OSSetArenaLo
    lis     r3,-32465
    bl      OSSetArenaHi
    addi    r3,r1,24
    bl      OSClearContext
    addi    r3,r1,24
    bl      OSSetCurrentContext
    li      r0,0
    stw     r0,16(r1)
    addi    r3,r31,0
    oris    r4,r30,32768
    addi    r5,r1,16
    bl      __OSBootDol
    lwz     r0,748(r1)
    lwz     r31,740(r1)
    lwz     r30,736(r1)
    addi    r1,r1,744
    mtlr    r0
    blr
.size __OSReboot, . - __OSReboot

#
# === OSReset.o ===
#

.global OSRegisterResetFunction
.balign 4
OSRegisterResetFunction:
/* 0x80250D8C | size=0x84 (132 bytes) */
    lwz     r5,-23632(r13)
    b       .L_80250D98
.L_80250D94:
    lwz     r5,8(r5)
.L_80250D98:
    cmplwi  r5,0
    beq-    .L_80250DB0
    lwz     r4,4(r5)
    lwz     r0,4(r3)
    cmplw   r4,r0
    ble+    .L_80250D94
.L_80250DB0:
    cmplwi  r5,0
    bne-    .L_80250DE8
    addi    r5,r13,-23632
    lwzu    r4,4(r5)
    cmplwi  r4,0
    bne-    .L_80250DD0
    stw     r3,-23632(r13)
    b       .L_80250DD4
.L_80250DD0:
    stw     r3,8(r4)
.L_80250DD4:
    stw     r4,12(r3)
    li      r0,0
    stw     r0,8(r3)
    stw     r3,0(r5)
    blr
.L_80250DE8:
    stw     r5,8(r3)
    lwz     r4,12(r5)
    stw     r3,12(r5)
    cmplwi  r4,0
    stw     r4,12(r3)
    bne-    .L_80250E08
    stw     r3,-23632(r13)
    blr
.L_80250E08:
    stw     r3,8(r4)
    blr
.size OSRegisterResetFunction, . - OSRegisterResetFunction

.global __OSCallResetFunctions
.balign 4
__OSCallResetFunctions:
/* 0x80250E48 | size=0xA8 (168 bytes) */
    mflr    r0
    stw     r0,4(r1)
    stwu    r1,-32(r1)
    stw     r31,28(r1)
    stw     r30,24(r1)
    li      r30,0
    stw     r29,20(r1)
    addi    r29,r3,0
    li      r3,0
    lwz     r31,-23632(r13)
    b       .L_80250EAC
.L_80250E74:
    cmpwi   r30,0
    beq-    .L_80250E88
    lwz     r0,4(r31)
    cmplw   r3,r0
    bne-    .L_80250EB4
.L_80250E88:
    lwz     r12,0(r31)
    addi    r3,r29,0
    mtlr    r12
    blrl
    cntlzw  r0,r3
    lwz     r3,4(r31)
    srwi    r0,r0,5
    lwz     r31,8(r31)
    or      r30,r30,r0
.L_80250EAC:
    cmplwi  r31,0
    bne+    .L_80250E74
.L_80250EB4:
    bl      __OSSyncSram
    cntlzw  r0,r3
    srwi    r0,r0,5
    or.     r30,r30,r0
    beq-    .L_80250ED0
    li      r3,0
    b       .L_80250ED4
.L_80250ED0:
    li      r3,1
.L_80250ED4:
    lwz     r0,36(r1)
    lwz     r31,28(r1)
    lwz     r30,24(r1)
    lwz     r29,20(r1)
    addi    r1,r1,32
    mtlr    r0
    blr
.size __OSCallResetFunctions, . - __OSCallResetFunctions

.global Reset
.balign 4
Reset:
/* 0x80250EF0 | size=0x70 (112 bytes) */
    b       .L_80250F10
.L_80250EF4:
    mfhid0  r8
    ori     r8,r8,8
    mthid0  r8
    isync
    sync
    nop
    b       .L_80250F14
.L_80250F10:
    b       .L_80250F30
.L_80250F14:
    mftb    r5
.L_80250F18:
    mftb    r6
    subf    r7,r5,r6
    cmplwi  r7,4388
    blt+    .L_80250F18
    nop
    b       .L_80250F34
.L_80250F30:
    b       .L_80250F50
.L_80250F34:
    lis     r8,-13312
    ori     r8,r8,12288
    li      r4,3
    stw     r4,36(r8)
    stw     r3,36(r8)
    nop
    b       .L_80250F54
.L_80250F50:
    b       .L_80250F5C
.L_80250F54:
    nop
    b       .L_80250F54
.L_80250F5C:
    b       .L_80250EF4
.size Reset, . - Reset

.global KillThreads
.balign 4
KillThreads:
/* 0x80250F60 | size=0x68 (104 bytes) */
    mflr    r0
    stw     r0,4(r1)
    stwu    r1,-16(r1)
    stw     r31,12(r1)
    lis     r3,-32768
    lwz     r3,220(r3)
    b       .L_80250F7C
.L_80250F7C:
    b       .L_80250F80
.L_80250F80:
    b       .L_80250FAC
.L_80250F84:
    lhz     r0,712(r3)
    lwz     r31,764(r3)
    cmpwi   r0,4
    beq-    .L_80250FA4
    bge-    .L_80250FA8
    cmpwi   r0,1
    beq-    .L_80250FA4
    b       .L_80250FA8
.L_80250FA4:
    bl      OSCancelThread
.L_80250FA8:
    mr      r3,r31
.L_80250FAC:
    cmplwi  r3,0
    bne+    .L_80250F84
    lwz     r0,20(r1)
    lwz     r31,12(r1)
    addi    r1,r1,16
    mtlr    r0
    blr
.size KillThreads, . - KillThreads

.global __OSDoHotReset
.balign 4
__OSDoHotReset:
/* 0x80250FC8 | size=0x48 (72 bytes) */
    mflr    r0
    stw     r0,4(r1)
    stwu    r1,-24(r1)
    stw     r31,20(r1)
    mr      r31,r3
    bl      OSDisableInterrupts
    lis     r3,-13312
    addi    r3,r3,8192
    li      r0,0
    sth     r0,2(r3)
    bl      ICFlashInvalidate
    slwi    r3,r31,3
    bl      Reset
    lwz     r0,28(r1)
    lwz     r31,20(r1)
    addi    r1,r1,24
    mtlr    r0
    blr
.size __OSDoHotReset, . - __OSDoHotReset

#
# === OSResetSW.o ===
#

.global __OSResetSWInterruptHandler
.balign 4
__OSResetSWInterruptHandler:
/* 0x80251408 | size=0xF4 (244 bytes) */
    mflr    r0
    stw     r0,4(r1)
    stwu    r1,-40(r1)
    stw     r31,36(r1)
    stw     r30,32(r1)
    stw     r29,28(r1)
    bl      __OSGetSystemTime
    lis     r5,-32768
    stw     r4,-23588(r13)
    lwz     r0,248(r5)
    lis     r4,17180
    addi    r4,r4,-8573
    stw     r3,-23592(r13)
    srwi    r0,r0,2
    mulhwu  r0,r4,r0
    srwi    r0,r0,15
    mulli   r0,r0,100
    srwi    r29,r0,3
    li      r30,0
    lis     r31,-13312
.L_80251458:
    bl      __OSGetSystemTime
    lwz     r6,-23588(r13)
    xoris   r5,r30,32768
    lwz     r0,-23592(r13)
    subfc   r4,r6,r4
    subfe   r0,r0,r3
    xoris   r3,r0,32768
    subfc   r0,r29,r4
    subfe   r5,r5,r3
    subfe   r5,r3,r3
    neg.    r5,r5
    beq-    .L_80251494
    lwz     r0,12288(r31)
    rlwinm. r0,r0,0,15,15
    beq+    .L_80251458
.L_80251494:
    lis     r3,-13312
    lwz     r0,12288(r3)
    rlwinm. r0,r0,0,15,15
    bne-    .L_802514D4
    li      r0,1
    stw     r0,-23612(r13)
    li      r3,512
    stw     r0,-23608(r13)
    bl      __OSMaskInterrupts
    lwz     r12,-23616(r13)
    cmplwi  r12,0
    beq-    .L_802514D4
    li      r0,0
    mtlr    r12
    stw     r0,-23616(r13)
    blrl
.L_802514D4:
    li      r0,2
    lis     r3,-13312
    stw     r0,12288(r3)
    lwz     r0,44(r1)
    lwz     r31,36(r1)
    lwz     r30,32(r1)
    lwz     r29,28(r1)
    addi    r1,r1,40
    mtlr    r0
    blr
.size __OSResetSWInterruptHandler, . - __OSResetSWInterruptHandler

.global OSSetResetCallback
.balign 4
OSSetResetCallback:
/* 0x802514FC | size=0x74 (116 bytes) */
    mflr    r0
    stw     r0,4(r1)
    stwu    r1,-24(r1)
    stw     r31,20(r1)
    mr      r31,r3
    stw     r30,16(r1)
    bl      OSDisableInterrupts
    lwz     r30,-23616(r13)
    cmplwi  r31,0
    stw     r31,-23616(r13)
    mr      r31,r3
    beq-    .L_80251544
    li      r0,2
    lis     r3,-13312
    stw     r0,12288(r3)
    li      r3,512
    bl      __OSUnmaskInterrupts
    b       .L_8025154C
.L_80251544:
    li      r3,512
    bl      __OSMaskInterrupts
.L_8025154C:
    mr      r3,r31
    bl      OSRestoreInterrupts
    mr      r3,r30
    lwz     r0,28(r1)
    lwz     r31,20(r1)
    lwz     r30,16(r1)
    addi    r1,r1,24
    mtlr    r0
    blr
.size OSSetResetCallback, . - OSSetResetCallback

.global __OSSetResetButtonTimer
.balign 4
__OSSetResetButtonTimer:
/* 0x80251828 | size=0x5C (92 bytes) */
    mflr    r0
    stw     r0,4(r1)
    stwu    r1,-24(r1)
    stw     r31,20(r1)
    mr      r31,r3
    bl      OSDisableInterrupts
    clrlwi  r0,r31,24
    cmplwi  r0,31
    ble-    .L_80251850
    li      r31,31
.L_80251850:
    lis     r4,-32768
    lbz     r0,12515(r4)
    clrrwi  r0,r0,5
    stb     r0,12515(r4)
    lbz     r0,12515(r4)
    or      r0,r0,r31
    stb     r0,12515(r4)
    bl      OSRestoreInterrupts
    lwz     r0,28(r1)
    lwz     r31,20(r1)
    addi    r1,r1,24
    mtlr    r0
    blr
.size __OSSetResetButtonTimer, . - __OSSetResetButtonTimer

#
# === OSRtc.o ===
#

.global WriteSramCallback
.balign 4
WriteSramCallback:
/* 0x80251DEC | size=0x60 (96 bytes) */
    mflr    r0
    lis     r3,-32694
    stw     r0,4(r1)
    stwu    r1,-24(r1)
    stw     r31,20(r1)
    addi    r31,r3,-24704
    stw     r30,16(r1)
    addi    r30,r31,64
    lwz     r4,64(r31)
    add     r3,r31,r4
    subfic  r5,r4,64
    bl      WriteSram
    stw     r3,76(r31)
    lwz     r0,76(r31)
    cmpwi   r0,0
    beq-    .L_80251E34
    li      r0,64
    stw     r0,0(r30)
.L_80251E34:
    lwz     r0,28(r1)
    lwz     r31,20(r1)
    lwz     r30,16(r1)
    addi    r1,r1,24
    mtlr    r0
    blr
.size WriteSramCallback, . - WriteSramCallback

.global LockSram
.balign 4
LockSram:
/* 0x802520A0 | size=0x68 (104 bytes) */
    mflr    r0
    lis     r4,-32694
    stw     r0,4(r1)
    stwu    r1,-24(r1)
    stw     r31,20(r1)
    addi    r31,r4,-24704
    stw     r30,16(r1)
    addi    r30,r3,0
    bl      OSDisableInterrupts
    lwz     r0,72(r31)
    addi    r4,r31,72
    cmpwi   r0,0
    beq-    .L_802520E0
    bl      OSRestoreInterrupts
    li      r3,0
    b       .L_802520F0
.L_802520E0:
    stw     r3,68(r31)
    li      r0,1
    add     r3,r31,r30
    stw     r0,0(r4)
.L_802520F0:
    lwz     r0,28(r1)
    lwz     r31,20(r1)
    lwz     r30,16(r1)
    addi    r1,r1,24
    mtlr    r0
    blr
.size LockSram, . - LockSram

.global __OSLockSram
.balign 4
__OSLockSram:
/* 0x80252108 | size=0x5C (92 bytes) */
    mflr    r0
    lis     r3,-32694
    stw     r0,4(r1)
    stwu    r1,-16(r1)
    stw     r31,12(r1)
    addi    r31,r3,-24704
    bl      OSDisableInterrupts
    lwz     r0,72(r31)
    addi    r4,r31,72
    cmpwi   r0,0
    beq-    .L_80252140
    bl      OSRestoreInterrupts
    li      r31,0
    b       .L_8025214C
.L_80252140:
    stw     r3,68(r31)
    li      r0,1
    stw     r0,0(r4)
.L_8025214C:
    mr      r3,r31
    lwz     r0,20(r1)
    lwz     r31,12(r1)
    addi    r1,r1,16
    mtlr    r0
    blr
.size __OSLockSram, . - __OSLockSram

.global __OSLockSramEx
.balign 4
__OSLockSramEx:
/* 0x80252164 | size=0x5C (92 bytes) */
    mflr    r0
    lis     r3,-32694
    stw     r0,4(r1)
    stwu    r1,-16(r1)
    stw     r31,12(r1)
    addi    r31,r3,-24704
    bl      OSDisableInterrupts
    lwz     r0,72(r31)
    addi    r4,r31,72
    cmpwi   r0,0
    beq-    .L_8025219C
    bl      OSRestoreInterrupts
    li      r3,0
    b       .L_802521AC
.L_8025219C:
    stw     r3,68(r31)
    li      r0,1
    addi    r3,r31,20
    stw     r0,0(r4)
.L_802521AC:
    lwz     r0,20(r1)
    lwz     r31,12(r1)
    addi    r1,r1,16
    mtlr    r0
    blr
.size __OSLockSramEx, . - __OSLockSramEx

.global __OSReadROMCallback
.balign 4
__OSReadROMCallback:
/* 0x80252788 | size=0x5C (92 bytes) */
    mflr    r0
    stw     r0,4(r1)
    stwu    r1,-24(r1)
    stw     r31,20(r1)
    mr      r31,r3
    bl      EXIDeselect
    mr      r3,r31
    bl      EXIUnlock
    lis     r3,-32694
    addi    r3,r3,-24704
    lwzu    r0,80(r3)
    cmplwi  r0,0
    mr      r12,r0
    beq-    .L_802527D0
    li      r0,0
    mtlr    r12
    stw     r0,0(r3)
    blrl
.L_802527D0:
    lwz     r0,28(r1)
    lwz     r31,20(r1)
    addi    r1,r1,24
    mtlr    r0
    blr
.size __OSReadROMCallback, . - __OSReadROMCallback

.global OSGetSoundMode
.balign 4
OSGetSoundMode:
/* 0x802528F4 | size=0x80 (128 bytes) */
    mflr    r0
    lis     r3,-32694
    stw     r0,4(r1)
    stwu    r1,-32(r1)
    stw     r31,28(r1)
    addi    r31,r3,-24704
    bl      OSDisableInterrupts
    lwz     r0,72(r31)
    addi    r4,r31,72
    cmpwi   r0,0
    beq-    .L_8025292C
    bl      OSRestoreInterrupts
    li      r31,0
    b       .L_80252938
.L_8025292C:
    stw     r3,68(r31)
    li      r0,1
    stw     r0,0(r4)
.L_80252938:
    lbz     r0,19(r31)
    rlwinm. r0,r0,0,29,29
    beq-    .L_8025294C
    li      r31,1
    b       .L_80252950
.L_8025294C:
    li      r31,0
.L_80252950:
    li      r3,0
    li      r4,0
    bl      UnlockSram
    mr      r3,r31
    lwz     r0,36(r1)
    lwz     r31,28(r1)
    addi    r1,r1,32
    mtlr    r0
    blr
.size OSGetSoundMode, . - OSGetSoundMode

.global OSSetSoundMode
.balign 4
OSSetSoundMode:
/* 0x80252974 | size=0xA4 (164 bytes) */
    mflr    r0
    lis     r4,-32694
    stw     r0,4(r1)
    stwu    r1,-32(r1)
    stw     r31,28(r1)
    addi    r31,r4,-24704
    stw     r30,24(r1)
    rlwinm  r30,r3,2,29,29
    bl      OSDisableInterrupts
    lwz     r0,72(r31)
    addi    r4,r31,72
    cmpwi   r0,0
    beq-    .L_802529B4
    bl      OSRestoreInterrupts
    li      r31,0
    b       .L_802529C0
.L_802529B4:
    stw     r3,68(r31)
    li      r0,1
    stw     r0,0(r4)
.L_802529C0:
    lbz     r3,19(r31)
    rlwinm  r0,r3,0,29,29
    cmplw   r30,r0
    bne-    .L_802529E0
    li      r3,0
    li      r4,0
    bl      UnlockSram
    b       .L_80252A00
.L_802529E0:
    rlwinm  r0,r3,0,30,28
    stb     r0,19(r31)
    li      r3,1
    li      r4,0
    lbz     r0,19(r31)
    or      r0,r0,r30
    stb     r0,19(r31)
    bl      UnlockSram
.L_80252A00:
    lwz     r0,36(r1)
    lwz     r31,28(r1)
    lwz     r30,24(r1)
    addi    r1,r1,32
    mtlr    r0
    blr
.size OSSetSoundMode, . - OSSetSoundMode

.global OSGetProgressiveMode
.balign 4
OSGetProgressiveMode:
/* 0x80252A18 | size=0x70 (112 bytes) */
    mflr    r0
    lis     r3,-32694
    stw     r0,4(r1)
    stwu    r1,-24(r1)
    stw     r31,20(r1)
    addi    r31,r3,-24704
    bl      OSDisableInterrupts
    lwz     r0,72(r31)
    addi    r4,r31,72
    cmpwi   r0,0
    beq-    .L_80252A50
    bl      OSRestoreInterrupts
    li      r31,0
    b       .L_80252A5C
.L_80252A50:
    stw     r3,68(r31)
    li      r0,1
    stw     r0,0(r4)
.L_80252A5C:
    lbz     r0,19(r31)
    li      r3,0
    li      r4,0
    rlwinm  r31,r0,25,31,31
    bl      UnlockSram
    mr      r3,r31
    lwz     r0,28(r1)
    lwz     r31,20(r1)
    addi    r1,r1,24
    mtlr    r0
    blr
.size OSGetProgressiveMode, . - OSGetProgressiveMode

.global OSSetProgressiveMode
.balign 4
OSSetProgressiveMode:
/* 0x80252A88 | size=0xA4 (164 bytes) */
    mflr    r0
    lis     r4,-32694
    stw     r0,4(r1)
    stwu    r1,-32(r1)
    stw     r31,28(r1)
    addi    r31,r4,-24704
    stw     r30,24(r1)
    rlwinm  r30,r3,7,24,24
    bl      OSDisableInterrupts
    lwz     r0,72(r31)
    addi    r4,r31,72
    cmpwi   r0,0
    beq-    .L_80252AC8
    bl      OSRestoreInterrupts
    li      r31,0
    b       .L_80252AD4
.L_80252AC8:
    stw     r3,68(r31)
    li      r0,1
    stw     r0,0(r4)
.L_80252AD4:
    lbz     r3,19(r31)
    rlwinm  r0,r3,0,24,24
    cmplw   r30,r0
    bne-    .L_80252AF4
    li      r3,0
    li      r4,0
    bl      UnlockSram
    b       .L_80252B14
.L_80252AF4:
    rlwinm  r0,r3,0,25,23
    stb     r0,19(r31)
    li      r3,1
    li      r4,0
    lbz     r0,19(r31)
    or      r0,r0,r30
    stb     r0,19(r31)
    bl      UnlockSram
.L_80252B14:
    lwz     r0,36(r1)
    lwz     r31,28(r1)
    lwz     r30,24(r1)
    addi    r1,r1,32
    mtlr    r0
    blr
.size OSSetProgressiveMode, . - OSSetProgressiveMode

.global OSGetVideoMode
.balign 4
OSGetVideoMode:
/* 0x80252B2C | size=0x7C (124 bytes) */
    mflr    r0
    lis     r3,-32694
    stw     r0,4(r1)
    stwu    r1,-24(r1)
    stw     r31,20(r1)
    addi    r31,r3,-24704
    bl      OSDisableInterrupts
    lwz     r0,72(r31)
    addi    r4,r31,72
    cmpwi   r0,0
    beq-    .L_80252B64
    bl      OSRestoreInterrupts
    li      r31,0
    b       .L_80252B70
.L_80252B64:
    stw     r3,68(r31)
    li      r0,1
    stw     r0,0(r4)
.L_80252B70:
    lbz     r0,19(r31)
    li      r3,0
    li      r4,0
    clrlwi  r31,r0,30
    bl      UnlockSram
    cmplwi  r31,2
    ble-    .L_80252B90
    li      r31,0
.L_80252B90:
    mr      r3,r31
    lwz     r0,28(r1)
    lwz     r31,20(r1)
    addi    r1,r1,24
    mtlr    r0
    blr
.size OSGetVideoMode, . - OSGetVideoMode

.global OSSetVideoMode
.balign 4
OSSetVideoMode:
/* 0x80252BA8 | size=0xB0 (176 bytes) */
    mflr    r0
    stw     r0,4(r1)
    stwu    r1,-32(r1)
    stw     r31,28(r1)
    stw     r30,24(r1)
    addi    r30,r3,0
    cmplwi  r30,2
    lis     r3,-32694
    addi    r31,r3,-24704
    ble-    .L_80252BD4
    li      r30,0
.L_80252BD4:
    bl      OSDisableInterrupts
    lwz     r0,72(r31)
    addi    r4,r31,72
    cmpwi   r0,0
    beq-    .L_80252BF4
    bl      OSRestoreInterrupts
    li      r31,0
    b       .L_80252C00
.L_80252BF4:
    stw     r3,68(r31)
    li      r0,1
    stw     r0,0(r4)
.L_80252C00:
    lbz     r3,19(r31)
    clrlwi  r0,r3,30
    cmplw   r30,r0
    bne-    .L_80252C20
    li      r3,0
    li      r4,0
    bl      UnlockSram
    b       .L_80252C40
.L_80252C20:
    clrrwi  r0,r3,2
    stb     r0,19(r31)
    li      r3,1
    li      r4,0
    lbz     r0,19(r31)
    or      r0,r0,r30
    stb     r0,19(r31)
    bl      UnlockSram
.L_80252C40:
    lwz     r0,36(r1)
    lwz     r31,28(r1)
    lwz     r30,24(r1)
    addi    r1,r1,32
    mtlr    r0
    blr
.size OSSetVideoMode, . - OSSetVideoMode

.global OSGetLanguage
.balign 4
OSGetLanguage:
/* 0x80252C58 | size=0x6C (108 bytes) */
    mflr    r0
    lis     r3,-32694
    stw     r0,4(r1)
    stwu    r1,-24(r1)
    stw     r31,20(r1)
    addi    r31,r3,-24704
    bl      OSDisableInterrupts
    lwz     r0,72(r31)
    addi    r4,r31,72
    cmpwi   r0,0
    beq-    .L_80252C90
    bl      OSRestoreInterrupts
    li      r31,0
    b       .L_80252C9C
.L_80252C90:
    stw     r3,68(r31)
    li      r0,1
    stw     r0,0(r4)
.L_80252C9C:
    lbz     r31,18(r31)
    li      r3,0
    li      r4,0
    bl      UnlockSram
    mr      r3,r31
    lwz     r0,28(r1)
    lwz     r31,20(r1)
    addi    r1,r1,24
    mtlr    r0
    blr
.size OSGetLanguage, . - OSGetLanguage

.global OSSetLanguage
.balign 4
OSSetLanguage:
/* 0x80252CC4 | size=0x94 (148 bytes) */
    mflr    r0
    lis     r4,-32694
    stw     r0,4(r1)
    stwu    r1,-32(r1)
    stw     r31,28(r1)
    addi    r31,r4,-24704
    stw     r30,24(r1)
    addi    r30,r3,0
    bl      OSDisableInterrupts
    lwz     r0,72(r31)
    addi    r4,r31,72
    cmpwi   r0,0
    beq-    .L_80252D04
    bl      OSRestoreInterrupts
    li      r31,0
    b       .L_80252D10
.L_80252D04:
    stw     r3,68(r31)
    li      r0,1
    stw     r0,0(r4)
.L_80252D10:
    lbz     r0,18(r31)
    clrlwi  r3,r30,24
    cmplw   r3,r0
    bne-    .L_80252D30
    li      r3,0
    li      r4,0
    bl      UnlockSram
    b       .L_80252D40
.L_80252D30:
    stb     r30,18(r31)
    li      r3,1
    li      r4,0
    bl      UnlockSram
.L_80252D40:
    lwz     r0,36(r1)
    lwz     r31,28(r1)
    lwz     r30,24(r1)
    addi    r1,r1,32
    mtlr    r0
    blr
.size OSSetLanguage, . - OSSetLanguage

.global __OSGetBootMode
.balign 4
__OSGetBootMode:
/* 0x80252D58 | size=0x6C (108 bytes) */
    mflr    r0
    lis     r3,-32694
    stw     r0,4(r1)
    stwu    r1,-24(r1)
    stw     r31,20(r1)
    addi    r31,r3,-24704
    bl      OSDisableInterrupts
    lwz     r0,72(r31)
    addi    r4,r31,72
    cmpwi   r0,0
    beq-    .L_80252D90
    bl      OSRestoreInterrupts
    li      r31,0
    b       .L_80252D9C
.L_80252D90:
    stw     r3,68(r31)
    li      r0,1
    stw     r0,0(r4)
.L_80252D9C:
    lbz     r31,17(r31)
    li      r3,0
    li      r4,0
    bl      UnlockSram
    rlwinm  r3,r31,0,24,24
    lwz     r0,28(r1)
    lwz     r31,20(r1)
    addi    r1,r1,24
    mtlr    r0
    blr
.size __OSGetBootMode, . - __OSGetBootMode

.global __OSSetBootMode
.balign 4
__OSSetBootMode:
/* 0x80252DC4 | size=0xA4 (164 bytes) */
    mflr    r0
    lis     r4,-32694
    stw     r0,4(r1)
    stwu    r1,-32(r1)
    stw     r31,28(r1)
    addi    r31,r4,-24704
    stw     r30,24(r1)
    rlwinm  r30,r3,0,24,24
    bl      OSDisableInterrupts
    lwz     r0,72(r31)
    addi    r4,r31,72
    cmpwi   r0,0
    beq-    .L_80252E04
    bl      OSRestoreInterrupts
    li      r31,0
    b       .L_80252E10
.L_80252E04:
    stw     r3,68(r31)
    li      r0,1
    stw     r0,0(r4)
.L_80252E10:
    lbz     r3,17(r31)
    rlwinm  r0,r3,0,24,24
    cmplw   r30,r0
    bne-    .L_80252E30
    li      r3,0
    li      r4,0
    bl      UnlockSram
    b       .L_80252E50
.L_80252E30:
    rlwinm  r0,r3,0,25,23
    stb     r0,17(r31)
    li      r3,1
    li      r4,0
    lbz     r0,17(r31)
    or      r0,r0,r30
    stb     r0,17(r31)
    bl      UnlockSram
.L_80252E50:
    lwz     r0,36(r1)
    lwz     r31,28(r1)
    lwz     r30,24(r1)
    addi    r1,r1,32
    mtlr    r0
    blr
.size __OSSetBootMode, . - __OSSetBootMode

.global OSGetEuRgb60Mode
.balign 4
OSGetEuRgb60Mode:
/* 0x80252E68 | size=0x70 (112 bytes) */
    mflr    r0
    lis     r3,-32694
    stw     r0,4(r1)
    stwu    r1,-24(r1)
    stw     r31,20(r1)
    addi    r31,r3,-24704
    bl      OSDisableInterrupts
    lwz     r0,72(r31)
    addi    r4,r31,72
    cmpwi   r0,0
    beq-    .L_80252EA0
    bl      OSRestoreInterrupts
    li      r31,0
    b       .L_80252EAC
.L_80252EA0:
    stw     r3,68(r31)
    li      r0,1
    stw     r0,0(r4)
.L_80252EAC:
    lbz     r0,17(r31)
    li      r3,0
    li      r4,0
    rlwinm  r31,r0,26,31,31
    bl      UnlockSram
    mr      r3,r31
    lwz     r0,28(r1)
    lwz     r31,20(r1)
    addi    r1,r1,24
    mtlr    r0
    blr
.size OSGetEuRgb60Mode, . - OSGetEuRgb60Mode

.global OSSetEuRgb60Mode
.balign 4
OSSetEuRgb60Mode:
/* 0x80252ED8 | size=0xA4 (164 bytes) */
    mflr    r0
    lis     r4,-32694
    stw     r0,4(r1)
    stwu    r1,-32(r1)
    stw     r31,28(r1)
    addi    r31,r4,-24704
    stw     r30,24(r1)
    rlwinm  r30,r3,6,25,25
    bl      OSDisableInterrupts
    lwz     r0,72(r31)
    addi    r4,r31,72
    cmpwi   r0,0
    beq-    .L_80252F18
    bl      OSRestoreInterrupts
    li      r31,0
    b       .L_80252F24
.L_80252F18:
    stw     r3,68(r31)
    li      r0,1
    stw     r0,0(r4)
.L_80252F24:
    lbz     r3,17(r31)
    rlwinm  r0,r3,0,25,25
    cmplw   r30,r0
    bne-    .L_80252F44
    li      r3,0
    li      r4,0
    bl      UnlockSram
    b       .L_80252F64
.L_80252F44:
    rlwinm  r0,r3,0,26,24
    stb     r0,17(r31)
    li      r3,1
    li      r4,0
    lbz     r0,17(r31)
    or      r0,r0,r30
    stb     r0,17(r31)
    bl      UnlockSram
.L_80252F64:
    lwz     r0,36(r1)
    lwz     r31,28(r1)
    lwz     r30,24(r1)
    addi    r1,r1,32
    mtlr    r0
    blr
.size OSSetEuRgb60Mode, . - OSSetEuRgb60Mode

.global OSGetWirelessID
.balign 4
OSGetWirelessID:
/* 0x80252F7C | size=0x84 (132 bytes) */
    mflr    r0
    lis     r4,-32694
    stw     r0,4(r1)
    stwu    r1,-32(r1)
    stw     r31,28(r1)
    addi    r31,r4,-24704
    stw     r30,24(r1)
    addi    r30,r3,0
    bl      OSDisableInterrupts
    lwz     r0,72(r31)
    addi    r4,r31,72
    cmpwi   r0,0
    beq-    .L_80252FBC
    bl      OSRestoreInterrupts
    li      r3,0
    b       .L_80252FCC
.L_80252FBC:
    stw     r3,68(r31)
    li      r0,1
    addi    r3,r31,20
    stw     r0,0(r4)
.L_80252FCC:
    slwi    r0,r30,1
    add     r3,r3,r0
    lhz     r31,28(r3)
    li      r3,0
    li      r4,20
    bl      UnlockSram
    mr      r3,r31
    lwz     r0,36(r1)
    lwz     r31,28(r1)
    lwz     r30,24(r1)
    addi    r1,r1,32
    mtlr    r0
    blr
.size OSGetWirelessID, . - OSGetWirelessID

.global OSSetWirelessID
.balign 4
OSSetWirelessID:
/* 0x80253000 | size=0xAC (172 bytes) */
    mflr    r0
    lis     r5,-32694
    stw     r0,4(r1)
    stwu    r1,-40(r1)
    stw     r31,36(r1)
    addi    r31,r5,-24704
    stw     r30,32(r1)
    addi    r30,r4,0
    stw     r29,28(r1)
    addi    r29,r3,0
    bl      OSDisableInterrupts
    lwz     r0,72(r31)
    addi    r4,r31,72
    cmpwi   r0,0
    beq-    .L_80253048
    bl      OSRestoreInterrupts
    li      r3,0
    b       .L_80253058
.L_80253048:
    stw     r3,68(r31)
    li      r0,1
    addi    r3,r31,20
    stw     r0,0(r4)
.L_80253058:
    slwi    r0,r29,1
    add     r4,r3,r0
    lhzu    r3,28(r4)
    clrlwi  r0,r30,16
    cmplw   r3,r0
    beq-    .L_80253084
    sth     r30,0(r4)
    li      r3,1
    li      r4,20
    bl      UnlockSram
    b       .L_80253090
.L_80253084:
    li      r3,0
    li      r4,20
    bl      UnlockSram
.L_80253090:
    lwz     r0,44(r1)
    lwz     r31,36(r1)
    lwz     r30,32(r1)
    lwz     r29,28(r1)
    addi    r1,r1,40
    mtlr    r0
    blr
.size OSSetWirelessID, . - OSSetWirelessID

.global OSGetGbsMode
.balign 4
OSGetGbsMode:
/* 0x802530AC | size=0x70 (112 bytes) */
    mflr    r0
    lis     r3,-32694
    stw     r0,4(r1)
    stwu    r1,-24(r1)
    stw     r31,20(r1)
    addi    r31,r3,-24704
    bl      OSDisableInterrupts
    lwz     r0,72(r31)
    addi    r4,r31,72
    cmpwi   r0,0
    beq-    .L_802530E4
    bl      OSRestoreInterrupts
    li      r3,0
    b       .L_802530F4
.L_802530E4:
    stw     r3,68(r31)
    li      r0,1
    addi    r3,r31,20
    stw     r0,0(r4)
.L_802530F4:
    lhz     r31,40(r3)
    li      r3,0
    li      r4,20
    bl      UnlockSram
    mr      r3,r31
    lwz     r0,28(r1)
    lwz     r31,20(r1)
    addi    r1,r1,24
    mtlr    r0
    blr
.size OSGetGbsMode, . - OSGetGbsMode

.global OSSetGbsMode
.balign 4
OSSetGbsMode:
/* 0x8025311C | size=0xB8 (184 bytes) */
    mflr    r0
    clrlwi  r4,r3,16
    stw     r0,4(r1)
    rlwinm  r0,r3,0,17,21
    cmplwi  r0,20480
    stwu    r1,-32(r1)
    stw     r31,28(r1)
    stw     r30,24(r1)
    addi    r30,r3,0
    lis     r3,-32694
    addi    r31,r3,-24704
    beq-    .L_80253158
    rlwinm  r0,r4,0,24,25
    cmplwi  r0,192
    bne-    .L_8025315C
.L_80253158:
    li      r30,0
.L_8025315C:
    bl      OSDisableInterrupts
    lwz     r0,72(r31)
    addi    r5,r31,72
    cmpwi   r0,0
    beq-    .L_8025317C
    bl      OSRestoreInterrupts
    li      r4,0
    b       .L_8025318C
.L_8025317C:
    stw     r3,68(r31)
    li      r0,1
    addi    r4,r31,20
    stw     r0,0(r5)
.L_8025318C:
    lhz     r0,40(r4)
    clrlwi  r3,r30,16
    cmplw   r3,r0
    bne-    .L_802531AC
    li      r3,0
    li      r4,20
    bl      UnlockSram
    b       .L_802531BC
.L_802531AC:
    sth     r30,40(r4)
    li      r3,1
    li      r4,20
    bl      UnlockSram
.L_802531BC:
    lwz     r0,36(r1)
    lwz     r31,28(r1)
    lwz     r30,24(r1)
    addi    r1,r1,32
    mtlr    r0
    blr
.size OSSetGbsMode, . - OSSetGbsMode

#
# === OSSemaphore.o ===
#

.global OSInitSemaphore
.balign 4
OSInitSemaphore:
/* 0x80371914 | size=0x58 (88 bytes) */
    mflr    r0
    stw     r0,4(r1)
    stwu    r1,-32(r1)
    stw     r31,28(r1)
    stw     r30,24(r1)
    addi    r30,r4,0
    stw     r29,20(r1)
    addi    r29,r3,0
    bl      OSDisableInterrupts
    addi    r31,r3,0
    addi    r3,r29,4
    bl      OSInitThreadQueue
    stw     r30,0(r29)
    mr      r3,r31
    bl      OSRestoreInterrupts
    lwz     r0,36(r1)
    lwz     r31,28(r1)
    lwz     r30,24(r1)
    lwz     r29,20(r1)
    addi    r1,r1,32
    mtlr    r0
    blr
.size OSInitSemaphore, . - OSInitSemaphore

.global OSWaitSemaphore
.balign 4
OSWaitSemaphore:
/* 0x8037196C | size=0x70 (112 bytes) */
    mflr    r0
    stw     r0,4(r1)
    stwu    r1,-32(r1)
    stw     r31,28(r1)
    stw     r30,24(r1)
    stw     r29,20(r1)
    mr      r29,r3
    bl      OSDisableInterrupts
    mr      r31,r3
    b       .L_8037199C
.L_80371994:
    addi    r3,r29,4
    bl      OSSleepThread
.L_8037199C:
    lwz     r30,0(r29)
    cmpwi   r30,0
    ble+    .L_80371994
    lwz     r4,0(r29)
    addi    r3,r31,0
    addi    r0,r4,-1
    stw     r0,0(r29)
    bl      OSRestoreInterrupts
    mr      r3,r30
    lwz     r0,36(r1)
    lwz     r31,28(r1)
    lwz     r30,24(r1)
    lwz     r29,20(r1)
    addi    r1,r1,32
    mtlr    r0
    blr
.size OSWaitSemaphore, . - OSWaitSemaphore

.global OSTryWaitSemaphore
.balign 4
OSTryWaitSemaphore:
/* 0x803719DC | size=0x54 (84 bytes) */
    mflr    r0
    stw     r0,4(r1)
    stwu    r1,-24(r1)
    stw     r31,20(r1)
    stw     r30,16(r1)
    mr      r30,r3
    bl      OSDisableInterrupts
    lwz     r4,0(r30)
    cmpwi   r4,0
    addi    r31,r4,0
    ble-    .L_80371A10
    addi    r0,r4,-1
    stw     r0,0(r30)
.L_80371A10:
    bl      OSRestoreInterrupts
    mr      r3,r31
    lwz     r0,28(r1)
    lwz     r31,20(r1)
    lwz     r30,16(r1)
    addi    r1,r1,24
    mtlr    r0
    blr
.size OSTryWaitSemaphore, . - OSTryWaitSemaphore

.global OSSignalSemaphore
.balign 4
OSSignalSemaphore:
/* 0x80371A30 | size=0x60 (96 bytes) */
    mflr    r0
    stw     r0,4(r1)
    stwu    r1,-32(r1)
    stw     r31,28(r1)
    stw     r30,24(r1)
    stw     r29,20(r1)
    mr      r29,r3
    bl      OSDisableInterrupts
    lwz     r30,0(r29)
    addi    r31,r3,0
    addi    r3,r29,4
    addi    r0,r30,1
    stw     r0,0(r29)
    bl      OSWakeupThread
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
.size OSSignalSemaphore, . - OSSignalSemaphore

#
# === OSSync.o ===
#

.global __OSInitSystemCall
.balign 4
__OSInitSystemCall:
/* 0x802531F4 | size=0x64 (100 bytes) */
    mflr    r0
    stw     r0,4(r1)
    stwu    r1,-16(r1)
    stw     r31,12(r1)
    lis     r5,-32768
    lis     r4,-32731
    lis     r3,-32731
    addi    r31,r5,3072
    addi    r0,r3,12784
    addi    r4,r4,12756
    mr      r3,r31
    subf    r5,r4,r0
    bl      memcpy
    mr      r3,r31
    li      r4,256
    bl      DCFlushRangeNoSync
    sync
    mr      r3,r31
    li      r4,256
    bl      ICInvalidateRange
    lwz     r0,20(r1)
    lwz     r31,12(r1)
    addi    r1,r1,16
    mtlr    r0
    blr
.size __OSInitSystemCall, . - __OSInitSystemCall

#
# === OSThread.o ===
#

.global OSSetSwitchThreadCallback
.balign 4
OSSetSwitchThreadCallback:
/* 0x8025325C | size=0x74 (116 bytes) */
    mflr    r0
    stw     r0,4(r1)
    stwu    r1,-24(r1)
    stw     r31,20(r1)
    stw     r30,16(r1)
    mr      r30,r3
    bl      OSDisableInterrupts
    cmplwi  r30,0
    lwz     r31,-27896(r13)
    beq-    .L_8025328C
    mr      r0,r30
    b       .L_80253294
.L_8025328C:
    lis     r4,-32731
    addi    r0,r4,12888
.L_80253294:
    stw     r0,-27896(r13)
    bl      OSRestoreInterrupts
    lis     r3,-32731
    addi    r0,r3,12888
    cmplw   r31,r0
    bne-    .L_802532B4
    li      r3,0
    b       .L_802532B8
.L_802532B4:
    mr      r3,r31
.L_802532B8:
    lwz     r0,28(r1)
    lwz     r31,20(r1)
    lwz     r30,16(r1)
    addi    r1,r1,24
    mtlr    r0
    blr
.size OSSetSwitchThreadCallback, . - OSSetSwitchThreadCallback

.global __OSSwitchThread
.balign 4
__OSSwitchThread:
/* 0x80253444 | size=0x5C (92 bytes) */
    mflr    r0
    stw     r0,4(r1)
    stwu    r1,-24(r1)
    stw     r31,20(r1)
    lis     r31,-32768
    stw     r30,16(r1)
    addi    r30,r3,0
    mr      r4,r30
    lwz     r12,-27896(r13)
    lwz     r3,228(r31)
    mtlr    r12
    blrl
    stw     r30,228(r31)
    mr      r3,r30
    bl      OSSetCurrentContext
    mr      r3,r30
    bl      OSLoadContext
    lwz     r0,28(r1)
    lwz     r31,20(r1)
    lwz     r30,16(r1)
    addi    r1,r1,24
    mtlr    r0
    blr
.size __OSSwitchThread, . - __OSSwitchThread

.global __OSIsThreadActive
.balign 4
__OSIsThreadActive:
/* 0x802534F0 | size=0x44 (68 bytes) */
    lhz     r0,712(r3)
    cmplwi  r0,0
    bne-    .L_80253504
    li      r3,0
    blr
.L_80253504:
    lis     r4,-32768
    lwz     r4,220(r4)
    b       .L_80253524
.L_80253510:
    cmplw   r3,r4
    bne-    .L_80253520
    li      r3,1
    blr
.L_80253520:
    lwz     r4,764(r4)
.L_80253524:
    cmplwi  r4,0
    bne+    .L_80253510
    li      r3,0
    blr
.size __OSIsThreadActive, . - __OSIsThreadActive

.global SetRun
.balign 4
SetRun:
/* 0x802535B4 | size=0x6C (108 bytes) */
    lwz     r5,720(r3)
    lis     r4,-32694
    addi    r0,r4,-24616
    slwi    r4,r5,3
    add     r0,r0,r4
    stw     r0,732(r3)
    lwz     r5,732(r3)
    lwz     r4,4(r5)
    cmplwi  r4,0
    bne-    .L_802535E4
    stw     r3,0(r5)
    b       .L_802535E8
.L_802535E4:
    stw     r3,736(r4)
.L_802535E8:
    stw     r4,740(r3)
    li      r0,0
    li      r4,1
    stw     r0,736(r3)
    lwz     r5,732(r3)
    stw     r3,4(r5)
    lwz     r0,720(r3)
    lwz     r3,-23584(r13)
    subfic  r0,r0,31
    slw     r0,r4,r0
    or      r0,r3,r0
    stw     r0,-23584(r13)
    stw     r4,-23580(r13)
    blr
.size SetRun, . - SetRun

.global UnsetRun
.balign 4
UnsetRun:
/* 0x80253620 | size=0x68 (104 bytes) */
    lwz     r4,736(r3)
    lwz     r5,732(r3)
    cmplwi  r4,0
    lwz     r6,740(r3)
    bne-    .L_8025363C
    stw     r6,4(r5)
    b       .L_80253640
.L_8025363C:
    stw     r6,740(r4)
.L_80253640:
    cmplwi  r6,0
    bne-    .L_80253650
    stw     r4,0(r5)
    b       .L_80253654
.L_80253650:
    stw     r4,736(r6)
.L_80253654:
    lwz     r0,0(r5)
    cmplwi  r0,0
    bne-    .L_8025367C
    lwz     r0,720(r3)
    li      r4,1
    lwz     r5,-23584(r13)
    subfic  r0,r0,31
    slw     r0,r4,r0
    andc    r0,r5,r0
    stw     r0,-23584(r13)
.L_8025367C:
    li      r0,0
    stw     r0,732(r3)
    blr
.size UnsetRun, . - UnsetRun

.global UpdatePriority
.balign 4
UpdatePriority:
/* 0x80253884 | size=0x78 (120 bytes) */
    mflr    r0
    stw     r0,4(r1)
    stwu    r1,-8(r1)
.L_80253890:
    lwz     r0,716(r3)
    cmpwi   r0,0
    bgt-    .L_802538EC
    lwz     r5,724(r3)
    lwz     r4,756(r3)
    b       .L_802538C8
.L_802538A8:
    lwz     r6,0(r4)
    cmplwi  r6,0
    beq-    .L_802538C4
    lwz     r0,720(r6)
    cmpw    r0,r5
    bge-    .L_802538C4
    mr      r5,r0
.L_802538C4:
    lwz     r4,16(r4)
.L_802538C8:
    cmplwi  r4,0
    bne+    .L_802538A8
    lwz     r0,720(r3)
    addi    r4,r5,0
    cmpw    r0,r5
    beq-    .L_802538EC
    bl      SetEffectivePriority
    cmplwi  r3,0
    bne+    .L_80253890
.L_802538EC:
    lwz     r0,12(r1)
    addi    r1,r1,8
    mtlr    r0
    blr
.size UpdatePriority, . - UpdatePriority

.global __OSPromoteThread
.balign 4
__OSPromoteThread:
/* 0x802538FC | size=0x50 (80 bytes) */
    mflr    r0
    stw     r0,4(r1)
    stwu    r1,-24(r1)
    stw     r31,20(r1)
    mr      r31,r4
.L_80253910:
    lwz     r0,716(r3)
    cmpwi   r0,0
    bgt-    .L_80253938
    lwz     r0,720(r3)
    cmpw    r0,r31
    ble-    .L_80253938
    mr      r4,r31
    bl      SetEffectivePriority
    cmplwi  r3,0
    bne+    .L_80253910
.L_80253938:
    lwz     r0,28(r1)
    lwz     r31,20(r1)
    addi    r1,r1,24
    mtlr    r0
    blr
.size __OSPromoteThread, . - __OSPromoteThread

.global OSExitThread
.balign 4
OSExitThread:
/* 0x80253DC8 | size=0xE4 (228 bytes) */
    mflr    r0
    stw     r0,4(r1)
    stwu    r1,-32(r1)
    stw     r31,28(r1)
    stw     r30,24(r1)
    stw     r29,20(r1)
    stw     r28,16(r1)
    mr      r28,r3
    bl      OSDisableInterrupts
    lis     r31,-32768
    lwz     r30,228(r31)
    addi    r29,r3,0
    addi    r3,r30,0
    bl      OSClearContext
    lhz     r0,714(r30)
    clrlwi. r0,r0,31
    beq-    .L_80253E4C
    lwz     r4,764(r30)
    lwz     r5,768(r30)
    cmplwi  r4,0
    bne-    .L_80253E24
    stw     r5,224(r31)
    b       .L_80253E28
.L_80253E24:
    stw     r5,768(r4)
.L_80253E28:
    cmplwi  r5,0
    bne-    .L_80253E3C
    lis     r3,-32768
    stw     r4,220(r3)
    b       .L_80253E40
.L_80253E3C:
    stw     r4,764(r5)
.L_80253E40:
    li      r0,0
    sth     r0,712(r30)
    b       .L_80253E58
.L_80253E4C:
    li      r0,8
    sth     r0,712(r30)
    stw     r28,728(r30)
.L_80253E58:
    mr      r3,r30
    bl      __OSUnlockAllMutex
    addi    r3,r30,744
    bl      OSWakeupThread
    li      r0,1
    stw     r0,-23580(r13)
    lwz     r0,-23580(r13)
    cmpwi   r0,0
    beq-    .L_80253E84
    li      r3,0
    bl      SelectThread
.L_80253E84:
    mr      r3,r29
    bl      OSRestoreInterrupts
    lwz     r0,36(r1)
    lwz     r31,28(r1)
    lwz     r30,24(r1)
    lwz     r29,20(r1)
    lwz     r28,16(r1)
    addi    r1,r1,32
    mtlr    r0
    blr
.size OSExitThread, . - OSExitThread

.global OSDetachThread
.balign 4
OSDetachThread:
/* 0x802541A8 | size=0xA0 (160 bytes) */
    mflr    r0
    stw     r0,4(r1)
    stwu    r1,-24(r1)
    stw     r31,20(r1)
    stw     r30,16(r1)
    mr      r30,r3
    bl      OSDisableInterrupts
    lhz     r0,714(r30)
    addi    r31,r3,0
    ori     r0,r0,1
    sth     r0,714(r30)
    lhz     r0,712(r30)
    cmplwi  r0,8
    bne-    .L_80254220
    lwz     r4,764(r30)
    lwz     r5,768(r30)
    cmplwi  r4,0
    bne-    .L_802541FC
    lis     r3,-32768
    stw     r5,224(r3)
    b       .L_80254200
.L_802541FC:
    stw     r5,768(r4)
.L_80254200:
    cmplwi  r5,0
    bne-    .L_80254214
    lis     r3,-32768
    stw     r4,220(r3)
    b       .L_80254218
.L_80254214:
    stw     r4,764(r5)
.L_80254218:
    li      r0,0
    sth     r0,712(r30)
.L_80254220:
    addi    r3,r30,744
    bl      OSWakeupThread
    mr      r3,r31
    bl      OSRestoreInterrupts
    lwz     r0,28(r1)
    lwz     r31,20(r1)
    lwz     r30,16(r1)
    addi    r1,r1,24
    mtlr    r0
    blr
.size OSDetachThread, . - OSDetachThread

.global OSSleepThread
.balign 4
OSSleepThread:
/* 0x80254640 | size=0xEC (236 bytes) */
    mflr    r0
    stw     r0,4(r1)
    stwu    r1,-24(r1)
    stw     r31,20(r1)
    stw     r30,16(r1)
    mr      r30,r3
    bl      OSDisableInterrupts
    lis     r4,-32768
    lwz     r4,228(r4)
    li      r0,4
    mr      r31,r3
    sth     r0,712(r4)
    stw     r30,732(r4)
    lwz     r5,0(r30)
    b       .L_80254680
.L_8025467C:
    lwz     r5,736(r5)
.L_80254680:
    cmplwi  r5,0
    beq-    .L_80254698
    lwz     r3,720(r5)
    lwz     r0,720(r4)
    cmpw    r3,r0
    ble+    .L_8025467C
.L_80254698:
    cmplwi  r5,0
    bne-    .L_802546CC
    lwz     r3,4(r30)
    cmplwi  r3,0
    bne-    .L_802546B4
    stw     r4,0(r30)
    b       .L_802546B8
.L_802546B4:
    stw     r4,736(r3)
.L_802546B8:
    stw     r3,740(r4)
    li      r0,0
    stw     r0,736(r4)
    stw     r4,4(r30)
    b       .L_802546F0
.L_802546CC:
    stw     r5,736(r4)
    lwz     r3,740(r5)
    stw     r4,740(r5)
    cmplwi  r3,0
    stw     r3,740(r4)
    bne-    .L_802546EC
    stw     r4,0(r30)
    b       .L_802546F0
.L_802546EC:
    stw     r4,736(r3)
.L_802546F0:
    li      r0,1
    stw     r0,-23580(r13)
    lwz     r0,-23580(r13)
    cmpwi   r0,0
    beq-    .L_8025470C
    li      r3,0
    bl      SelectThread
.L_8025470C:
    mr      r3,r31
    bl      OSRestoreInterrupts
    lwz     r0,28(r1)
    lwz     r31,20(r1)
    lwz     r30,16(r1)
    addi    r1,r1,24
    mtlr    r0
    blr
.size OSSleepThread, . - OSSleepThread

.global OSSetThreadPriority
.balign 4
OSSetThreadPriority:
/* 0x80254830 | size=0xC0 (192 bytes) */
    mflr    r0
    stw     r0,4(r1)
    stwu    r1,-32(r1)
    stw     r31,28(r1)
    mr.     r31,r4
    stw     r30,24(r1)
    stw     r29,20(r1)
    addi    r29,r3,0
    blt-    .L_8025485C
    cmpwi   r31,31
    ble-    .L_80254864
.L_8025485C:
    li      r3,0
    b       .L_802548D4
.L_80254864:
    bl      OSDisableInterrupts
    lwz     r0,724(r29)
    addi    r30,r3,0
    cmpw    r0,r31
    beq-    .L_802548C8
    stw     r31,724(r29)
    mr      r31,r29
.L_80254880:
    lwz     r0,716(r31)
    cmpwi   r0,0
    bgt-    .L_802548B4
    mr      r3,r31
    bl      __OSGetEffectivePriority
    lwz     r0,720(r31)
    addi    r4,r3,0
    cmpw    r0,r4
    beq-    .L_802548B4
    mr      r3,r31
    bl      SetEffectivePriority
    mr.     r31,r3
    bne+    .L_80254880
.L_802548B4:
    lwz     r0,-23580(r13)
    cmpwi   r0,0
    beq-    .L_802548C8
    li      r3,0
    bl      SelectThread
.L_802548C8:
    mr      r3,r30
    bl      OSRestoreInterrupts
    li      r3,1
.L_802548D4:
    lwz     r0,36(r1)
    lwz     r31,28(r1)
    lwz     r30,24(r1)
    lwz     r29,20(r1)
    addi    r1,r1,32
    mtlr    r0
    blr
.size OSSetThreadPriority, . - OSSetThreadPriority

.global OSSetIdleFunction
.balign 4
OSSetIdleFunction:
/* 0x802548F8 | size=0x90 (144 bytes) */
    mflr    r0
    cmplwi  r3,0
    stw     r0,4(r1)
    lis     r8,-32694
    addi    r10,r4,0
    stwu    r1,-32(r1)
    addi    r9,r5,0
    addi    r7,r6,0
    stw     r31,28(r1)
    addi    r31,r8,-24616
    beq-    .L_8025495C
    lhz     r0,968(r31)
    cmplwi  r0,0
    bne-    .L_80254970
    addi    r4,r3,0
    addi    r6,r9,0
    addi    r5,r10,0
    addi    r3,r31,256
    li      r8,31
    li      r9,1
    bl      OSCreateThread
    addi    r3,r31,256
    bl      OSResumeThread
    addi    r3,r31,256
    b       .L_80254974
.L_8025495C:
    lhz     r0,968(r31)
    cmplwi  r0,0
    beq-    .L_80254970
    addi    r3,r31,256
    bl      OSCancelThread
.L_80254970:
    li      r3,0
.L_80254974:
    lwz     r0,36(r1)
    lwz     r31,28(r1)
    addi    r1,r1,32
    mtlr    r0
    blr
.size OSSetIdleFunction, . - OSSetIdleFunction

.global CheckThreadQueue
.balign 4
CheckThreadQueue:
/* 0x802549A4 | size=0x9C (156 bytes) */
    lwz     r4,0(r3)
    cmplwi  r4,0
    beq-    .L_802549C4
    lwz     r0,740(r4)
    cmplwi  r0,0
    beq-    .L_802549C4
    li      r3,0
    blr
.L_802549C4:
    lwz     r3,4(r3)
    cmplwi  r3,0
    beq-    .L_802549E4
    lwz     r0,736(r3)
    cmplwi  r0,0
    beq-    .L_802549E4
    li      r3,0
    blr
.L_802549E4:
    mr      r5,r4
    b       .L_80254A30
.L_802549EC:
    lwz     r3,736(r5)
    cmplwi  r3,0
    beq-    .L_80254A0C
    lwz     r0,740(r3)
    cmplw   r5,r0
    beq-    .L_80254A0C
    li      r3,0
    blr
.L_80254A0C:
    lwz     r4,740(r5)
    cmplwi  r4,0
    beq-    .L_80254A2C
    lwz     r0,736(r4)
    cmplw   r5,r0
    beq-    .L_80254A2C
    li      r3,0
    blr
.L_80254A2C:
    mr      r5,r3
.L_80254A30:
    cmplwi  r5,0
    bne+    .L_802549EC
    li      r3,1
    blr
.size CheckThreadQueue, . - CheckThreadQueue

.global OSClearStack
.balign 4
OSClearStack:
/* 0x802551BC | size=0xAC (172 bytes) */
    mflr    r0
    stw     r0,4(r1)
    rlwinm  r0,r3,16,8,15
    rlwimi  r0,r3,24,0,7
    stwu    r1,-24(r1)
    rlwimi  r0,r3,8,16,23
    stw     r31,20(r1)
    mr      r31,r0
    rlwimi  r31,r3,0,24,31
    bl      OSGetStackPointer
    lis     r4,-32768
    lwz     r5,228(r4)
    addi    r4,r3,3
    lwz     r5,776(r5)
    addi    r5,r5,4
    cmplw   r5,r3
    subf    r4,r5,r4
    srwi    r4,r4,2
    bge-    .L_80255254
    srwi.   r0,r4,3
    mtctr   r0
    beq-    .L_80255244
.L_80255214:
    stw     r31,0(r5)
    stw     r31,4(r5)
    stw     r31,8(r5)
    stw     r31,12(r5)
    stw     r31,16(r5)
    stw     r31,20(r5)
    stw     r31,24(r5)
    stw     r31,28(r5)
    addi    r5,r5,32
    bdnz+   .L_80255214
    andi.   r4,r4,7
    beq-    .L_80255254
.L_80255244:
    mtctr   r4
.L_80255248:
    stw     r31,0(r5)
    addi    r5,r5,4
    bdnz+   .L_80255248
.L_80255254:
    lwz     r0,28(r1)
    lwz     r31,20(r1)
    addi    r1,r1,24
    mtlr    r0
    blr
.size OSClearStack, . - OSClearStack

#
# === OSTime.o ===
#

.global __OSSetTime
.balign 4
__OSSetTime:
/* 0x80255304 | size=0x84 (132 bytes) */
    mflr    r0
    stw     r0,4(r1)
    stwu    r1,-40(r1)
    stw     r31,36(r1)
    stw     r30,32(r1)
    stw     r29,28(r1)
    mr      r30,r3
    mr      r29,r4
    bl      OSDisableInterrupts
    mr      r31,r3
    bl      OSGetTime
    lis     r5,-32768
    subfc   r6,r29,r4
    lwz     r0,12508(r5)
    subfe   r4,r30,r3
    lwz     r3,12504(r5)
    addc    r0,r0,r6
    stw     r0,12508(r5)
    adde    r0,r3,r4
    mr      r4,r29
    stw     r0,12504(r5)
    mr      r3,r30
    bl      __SetTime
    bl      EXIProbeReset
    mr      r3,r31
    bl      OSRestoreInterrupts
    lwz     r0,44(r1)
    lwz     r31,36(r1)
    lwz     r30,32(r1)
    lwz     r29,28(r1)
    addi    r1,r1,40
    mtlr    r0
    blr
.size __OSSetTime, . - __OSSetTime

.global __OSGetSystemTime
.balign 4
__OSGetSystemTime:
/* 0x80255388 | size=0x64 (100 bytes) */
    mflr    r0
    stw     r0,4(r1)
    stwu    r1,-32(r1)
    stw     r31,28(r1)
    stw     r30,24(r1)
    stw     r29,20(r1)
    bl      OSDisableInterrupts
    mr      r31,r3
    bl      OSGetTime
    lis     r6,-32768
    lwz     r5,12508(r6)
    lwz     r0,12504(r6)
    addc    r29,r5,r4
    adde    r30,r0,r3
    mr      r3,r31
    bl      OSRestoreInterrupts
    mr      r4,r29
    mr      r3,r30
    lwz     r0,36(r1)
    lwz     r31,28(r1)
    lwz     r30,24(r1)
    lwz     r29,20(r1)
    addi    r1,r1,32
    mtlr    r0
    blr
.size __OSGetSystemTime, . - __OSGetSystemTime

.global __OSTimeToSystemTime
.balign 4
__OSTimeToSystemTime:
/* 0x802553EC | size=0x58 (88 bytes) */
    mflr    r0
    stw     r0,4(r1)
    stwu    r1,-32(r1)
    stw     r31,28(r1)
    stw     r30,24(r1)
    mr      r31,r3
    mr      r30,r4
    bl      OSDisableInterrupts
    lis     r5,-32768
    lwz     r4,12508(r5)
    lwz     r0,12504(r5)
    addc    r30,r4,r30
    adde    r31,r0,r31
    bl      OSRestoreInterrupts
    mr      r4,r30
    mr      r3,r31
    lwz     r0,36(r1)
    lwz     r31,28(r1)
    lwz     r30,24(r1)
    addi    r1,r1,32
    mtlr    r0
    blr
.size __OSTimeToSystemTime, . - __OSTimeToSystemTime

.global IsLeapYear
.balign 4
IsLeapYear:
/* 0x8025544C | size=0x88 (136 bytes) */
    srawi   r0,r3,2
    addze   r0,r0
    slwi    r0,r0,2
    subfc   r0,r0,r3
    cmpwi   r0,0
    li      r5,1
    li      r6,0
    bne-    .L_80255498
    lis     r4,20972
    addi    r0,r4,-31457
    mulhw   r0,r0,r3
    srawi   r0,r0,5
    srwi    r4,r0,31
    add     r0,r0,r4
    mulli   r0,r0,100
    subf    r0,r0,r3
    cmpwi   r0,0
    beq-    .L_80255498
    mr      r6,r5
.L_80255498:
    cmpwi   r6,0
    bne-    .L_802554CC
    lis     r4,20972
    addi    r0,r4,-31457
    mulhw   r0,r0,r3
    srawi   r0,r0,7
    srwi    r4,r0,31
    add     r0,r0,r4
    mulli   r0,r0,400
    subf    r0,r0,r3
    cmpwi   r0,0
    beq-    .L_802554CC
    li      r5,0
.L_802554CC:
    mr      r3,r5
    blr
.size IsLeapYear, . - IsLeapYear

.global GetYearDays
.balign 4
GetYearDays:
/* 0x802554D4 | size=0xA8 (168 bytes) */
    srawi   r0,r3,2
    addze   r0,r0
    slwi    r0,r0,2
    subfc   r0,r0,r3
    cmpwi   r0,0
    li      r6,1
    li      r7,0
    bne-    .L_80255520
    lis     r5,20972
    addi    r0,r5,-31457
    mulhw   r0,r0,r3
    srawi   r0,r0,5
    srwi    r5,r0,31
    add     r0,r0,r5
    mulli   r0,r0,100
    subf    r0,r0,r3
    cmpwi   r0,0
    beq-    .L_80255520
    mr      r7,r6
.L_80255520:
    cmpwi   r7,0
    bne-    .L_80255554
    lis     r5,20972
    addi    r0,r5,-31457
    mulhw   r0,r0,r3
    srawi   r0,r0,7
    srwi    r5,r0,31
    add     r0,r0,r5
    mulli   r0,r0,400
    subf    r0,r0,r3
    cmpwi   r0,0
    beq-    .L_80255554
    li      r6,0
.L_80255554:
    cmpwi   r6,0
    beq-    .L_80255568
    lis     r3,-32700
    addi    r3,r3,-16360
    b       .L_80255570
.L_80255568:
    lis     r3,-32700
    addi    r3,r3,-16408
.L_80255570:
    slwi    r0,r4,2
    lwzx    r3,r3,r0
    blr
.size GetYearDays, . - GetYearDays

.global GetLeapDays
.balign 4
GetLeapDays:
/* 0x8025557C | size=0x50 (80 bytes) */
    cmpwi   r3,1
    bge-    .L_8025558C
    li      r3,0
    b       .L_802555C8
.L_8025558C:
    lis     r4,20972
    addi    r0,r3,-1
    addi    r4,r4,-31457
    mulhw   r0,r4,r0
    srawi   r5,r0,7
    srawi   r4,r0,5
    addi    r0,r3,3
    srwi    r3,r4,31
    srawi   r0,r0,2
    srwi    r6,r5,31
    add     r3,r4,r3
    addze   r0,r0
    add     r4,r5,r6
    subf    r0,r3,r0
    add     r3,r4,r0
.L_802555C8:
    blr
.size GetLeapDays, . - GetLeapDays

#
# === OSUtf.o ===
#

.global OSUTF32to8
.balign 4
OSUTF32to8:
/* 0x80371BAC | size=0xD4 (212 bytes) */
    cmplwi  r3,55296
    blt-    .L_80371BC4
    cmplwi  r3,57343
    bgt-    .L_80371BC4
    li      r3,0
    blr
.L_80371BC4:
    cmplwi  r3,128
    bge-    .L_80371BDC
    extsb   r0,r3
    stb     r0,0(r4)
    addi    r6,r4,1
    b       .L_80371C4C
.L_80371BDC:
    cmplwi  r3,2048
    bge-    .L_80371BFC
    srwi    r0,r3,6
    ori     r0,r0,192
    stb     r0,0(r4)
    addi    r6,r4,1
    li      r5,1
    b       .L_80371C4C
.L_80371BFC:
    lis     r0,1
    cmplw   r3,r0
    bge-    .L_80371C20
    srwi    r0,r3,12
    ori     r0,r0,224
    stb     r0,0(r4)
    addi    r6,r4,1
    li      r5,2
    b       .L_80371C4C
.L_80371C20:
    lis     r0,17
    cmplw   r3,r0
    bge-    .L_80371C44
    srwi    r0,r3,18
    ori     r0,r0,240
    stb     r0,0(r4)
    addi    r6,r4,1
    li      r5,3
    b       .L_80371C4C
.L_80371C44:
    li      r3,0
    blr
.L_80371C4C:
    mulli   r4,r5,6
    b       .L_80371C68
.L_80371C54:
    srw     r0,r3,r4
    clrlwi  r0,r0,26
    ori     r0,r0,128
    stb     r0,0(r6)
    addi    r6,r6,1
.L_80371C68:
    cmpwi   r5,0
    addi    r4,r4,-6
    addi    r5,r5,-1
    bgt+    .L_80371C54
    mr      r3,r6
    blr
.size OSUTF32to8, . - OSUTF32to8

.global OSUTF16to32
.balign 4
OSUTF16to32:
/* 0x80371C80 | size=0x74 (116 bytes) */
    lhz     r5,0(r3)
    cmplwi  r5,0
    beq-    .L_80371C90
    addi    r3,r3,2
.L_80371C90:
    cmplwi  r5,55296
    blt-    .L_80371CA0
    cmplwi  r5,57343
    ble-    .L_80371CA8
.L_80371CA0:
    mr      r6,r5
    b       .L_80371CEC
.L_80371CA8:
    cmplwi  r5,56319
    bgt-    .L_80371CE4
    lhz     r0,0(r3)
    addi    r3,r3,2
    cmplwi  r0,56320
    blt-    .L_80371CDC
    cmplwi  r0,57343
    bgt-    .L_80371CDC
    clrlwi  r0,r0,22
    mr      r6,r0
    rlwimi  r6,r5,10,12,21
    addis   r6,r6,1
    b       .L_80371CEC
.L_80371CDC:
    li      r3,0
    blr
.L_80371CE4:
    li      r3,0
    blr
.L_80371CEC:
    stw     r6,0(r4)
    blr
.size OSUTF16to32, . - OSUTF16to32

.global OSUTF32to16
.balign 4
OSUTF32to16:
/* 0x80371CF4 | size=0x78 (120 bytes) */
    cmplwi  r3,55296
    blt-    .L_80371D0C
    cmplwi  r3,57343
    bgt-    .L_80371D0C
    li      r3,0
    blr
.L_80371D0C:
    lis     r6,1
    cmplw   r3,r6
    bge-    .L_80371D24
    sth     r3,0(r4)
    addi    r3,r4,2
    blr
.L_80371D24:
    lis     r5,17
    addi    r0,r5,-1
    cmplw   r3,r0
    bgt-    .L_80371D64
    addis   r3,r3,-1
    addi    r5,r6,-10240
    srwi    r0,r3,10
    or      r5,r5,r0
    sth     r5,0(r4)
    addi    r5,r6,-9216
    clrlwi  r0,r3,22
    or      r5,r5,r0
    addi    r3,r4,2
    sth     r5,2(r4)
    addi    r3,r3,2
    blr
.L_80371D64:
    li      r3,0
    blr
.size OSUTF32to16, . - OSUTF32to16

.global OSUTF32toSJIS
.balign 4
OSUTF32toSJIS:
/* 0x80371EBC | size=0x44 (68 bytes) */
    lis     r0,1
    cmplw   r0,r3
    bgt-    .L_80371ED0
    li      r3,0
    blr
.L_80371ED0:
    lis     r4,-32699
    rlwinm  r5,r3,26,22,29
    addi    r0,r4,-3104
    add     r4,r0,r5
    lwz     r4,0(r4)
    cmplwi  r4,0
    beq-    .L_80371EF8
    rlwinm  r0,r3,1,23,30
    lhzx    r3,r4,r0
    blr
.L_80371EF8:
    li      r3,0
    blr
.size OSUTF32toSJIS, . - OSUTF32toSJIS

#
# === __ppc_eabi_init.o ===
#

.global __init_cpp
.balign 4
__init_cpp:
/* 0x80255C6C | size=0x54 (84 bytes) */
    mflr    r0
    stw     r0,4(r1)
    stwu    r1,-16(r1)
    stw     r31,12(r1)
    lis     r3,-32700
    addi    r0,r3,11856
    mr      r31,r0
    b       .L_80255C8C
.L_80255C8C:
    b       .L_80255C90
.L_80255C90:
    b       .L_80255CA0
.L_80255C94:
    mtlr    r12
    blrl
    addi    r31,r31,4
.L_80255CA0:
    lwz     r12,0(r31)
    cmplwi  r12,0
    bne+    .L_80255C94
    lwz     r0,20(r1)
    lwz     r31,12(r1)
    addi    r1,r1,16
    mtlr    r0
    blr
.size __init_cpp, . - __init_cpp

.global __fini_cpp
.balign 4
__fini_cpp:
/* 0x80255CC0 | size=0x54 (84 bytes) */
    mflr    r0
    stw     r0,4(r1)
    stwu    r1,-16(r1)
    stw     r31,12(r1)
    lis     r3,-32700
    addi    r0,r3,11864
    mr      r31,r0
    b       .L_80255CE0
.L_80255CE0:
    b       .L_80255CE4
.L_80255CE4:
    b       .L_80255CF4
.L_80255CE8:
    mtlr    r12
    blrl
    addi    r31,r31,4
.L_80255CF4:
    lwz     r12,0(r31)
    cmplwi  r12,0
    bne+    .L_80255CE8
    lwz     r0,20(r1)
    lwz     r31,12(r1)
    addi    r1,r1,16
    mtlr    r0
    blr
.size __fini_cpp, . - __fini_cpp

.global exit
.balign 4
exit:
/* 0x80255D34 | size=0x54 (84 bytes) */
    mflr    r0
    stw     r0,4(r1)
    stwu    r1,-24(r1)
    stw     r31,20(r1)
    lis     r3,-32700
    addi    r31,r3,11864
    b       .L_80255D50
.L_80255D50:
    b       .L_80255D54
.L_80255D54:
    b       .L_80255D64
.L_80255D58:
    mtlr    r12
    blrl
    addi    r31,r31,4
.L_80255D64:
    lwz     r12,0(r31)
    cmplwi  r12,0
    bne+    .L_80255D58
    bl      _ExitProcess
    lwz     r0,28(r1)
    lwz     r31,20(r1)
    addi    r1,r1,24
    mtlr    r0
    blr
.size exit, . - exit
