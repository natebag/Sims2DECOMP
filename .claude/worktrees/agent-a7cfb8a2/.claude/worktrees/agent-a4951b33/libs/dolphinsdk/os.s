# DolphinSDK os.a - Small functions
# Auto-generated from ELF disassembly
# Small functions (<= 64 bytes)

.section .text

#
# === __ppc_eabi_init.o ===
#

.global __init_hardware
.balign 4
__init_hardware:
/* 0x80003468 | size=0x24 (36 bytes) */
    mfmsr   r0
    ori     r0,r0,8192
    mtmsr   r0
    mflr    r31
    bl __OSPSInit
    bl __OSFPRInit
    bl __OSCacheInit
    mtlr    r31
    blr
.size __init_hardware, . - __init_hardware

.global __flush_cache
.balign 4
__flush_cache:
/* 0x8000348C | size=0x34 (52 bytes) */
    lis     r5,-1
    ori     r5,r5,65521
    and     r5,r5,r3
    subf    r3,r5,r3
    add     r4,r4,r3
.L_800034A0:
    dcbst   0,r5
    sync
    icbi    0,r5
    addic   r5,r5,8
    addic.  r4,r4,-8
    bge+ .L_800034A0
    isync
    blr
.size __flush_cache, . - __flush_cache

.global __init_user
.balign 4
__init_user:
/* 0x80255C4C | size=0x20 (32 bytes) */
    mflr    r0
    stw     r0,4(r1)
    stwu    r1,-8(r1)
    bl __init_cpp
    lwz     r0,12(r1)
    addi    r1,r1,8
    mtlr    r0
    blr
.size __init_user, . - __init_user

.global abort
.balign 4
abort:
/* 0x80255D14 | size=0x20 (32 bytes) */
    mflr    r0
    stw     r0,4(r1)
    stwu    r1,-8(r1)
    bl _ExitProcess
    lwz     r0,12(r1)
    addi    r1,r1,8
    mtlr    r0
    blr
.size abort, . - abort

.global _ExitProcess
.balign 4
_ExitProcess:
/* 0x80255D88 | size=0x20 (32 bytes) */
    mflr    r0
    stw     r0,4(r1)
    stwu    r1,-8(r1)
    bl PPCHalt
    lwz     r0,12(r1)
    addi    r1,r1,8
    mtlr    r0
    blr
.size _ExitProcess, . - _ExitProcess

#
# === OS.o ===
#

.global __OSIsDebuggerPresent
.balign 4
__OSIsDebuggerPresent:
/* 0x8024B050 | size=0x0C (12 bytes) */
    lis     r3,-32768
    lwz     r3,64(r3)
    blr
.size __OSIsDebuggerPresent, . - __OSIsDebuggerPresent

.global DisableWriteGatherPipe
.balign 4
DisableWriteGatherPipe:
/* 0x8024B184 | size=0x28 (40 bytes) */
    mflr    r0
    stw     r0,4(r1)
    stwu    r1,-8(r1)
    bl PPCMfhid2
    rlwinm  r3,r3,0,2,0
    bl PPCMthid2
    lwz     r0,12(r1)
    addi    r1,r1,8
    mtlr    r0
    blr
.size DisableWriteGatherPipe, . - DisableWriteGatherPipe

.global OSGetConsoleType
.balign 4
OSGetConsoleType:
/* 0x8024B1AC | size=0x28 (40 bytes) */
    lwz     r3,-23744(r13)
    cmplwi  r3,0
    beq- .L_8024B1C4
    lwz     r3,44(r3)
    cmplwi  r3,0
    bne- .L_8024B1D0
.L_8024B1C4:
    lis     r3,4096
    addi    r3,r3,2
    b .L_8024B1D0
.L_8024B1D0:
    blr
.size OSGetConsoleType, . - OSGetConsoleType

.global InquiryCallback
.balign 4
InquiryCallback:
/* 0x8024B30C | size=0x3C (60 bytes) */
    lwz     r0,12(r4)
    cmpwi   r0,0
    beq- .L_8024B31C
    b .L_8024B338
.L_8024B31C:
    lis     r3,-32694
    addi    r3,r3,-24896
    lhz     r0,2(r3)
    lis     r3,-32768
    ori     r0,r0,32768
    sth     r0,12518(r3)
    b .L_8024B344
.L_8024B338:
    li      r0,1
    lis     r3,-32768
    sth     r0,12518(r3)
.L_8024B344:
    blr
.size InquiryCallback, . - InquiryCallback

.global __OSDBIntegrator
.balign 4
__OSDBIntegrator:
/* 0x8024BAA8 | size=0x24 (36 bytes) */
    li      r5,64
    mflr    r3
    stw     r3,12(r5)
    lwz     r3,8(r5)
    oris    r3,r3,32768
    mtlr    r3
    li      r3,48
    mtmsr   r3
    blr
.size __OSDBIntegrator, . - __OSDBIntegrator

.global __OSDBJump
.balign 4
__OSDBJump:
/* 0x8024BACC | size=0x04 (4 bytes) */
    .4byte 0x48000063  /* bla     0x60 */
.size __OSDBJump, . - __OSDBJump

.global __OSSetExceptionHandler
.balign 4
__OSSetExceptionHandler:
/* 0x8024BAD0 | size=0x1C (28 bytes) */
    clrlwi  r0,r3,24
    lwz     r3,-23708(r13)
    slwi    r0,r0,2
    add     r5,r3,r0
    lwz     r3,0(r5)
    stw     r4,0(r5)
    blr
.size __OSSetExceptionHandler, . - __OSSetExceptionHandler

.global __OSGetExceptionHandler
.balign 4
__OSGetExceptionHandler:
/* 0x8024BAEC | size=0x14 (20 bytes) */
    clrlwi  r0,r3,24
    lwz     r3,-23708(r13)
    slwi    r0,r0,2
    lwzx    r3,r3,r0
    blr
.size __OSGetExceptionHandler, . - __OSGetExceptionHandler

.global __OSGetDIConfig
.balign 4
__OSGetDIConfig:
/* 0x8024BC48 | size=0x14 (20 bytes) */
    lis     r3,-13312
    addi    r3,r3,24576
    lwz     r0,36(r3)
    clrlwi  r3,r0,24
    blr
.size __OSGetDIConfig, . - __OSGetDIConfig

.global OSRegisterVersion
.balign 4
OSRegisterVersion:
/* 0x8024BC5C | size=0x2C (44 bytes) */
    mflr    r0
    stw     r0,4(r1)
    stwu    r1,-8(r1)
    mr      r4,r3
    crclr   4*cr1+eq
    addi    r3,r13,-27924
    bl OSReport
    lwz     r0,12(r1)
    addi    r1,r1,8
    mtlr    r0
    blr
.size OSRegisterVersion, . - OSRegisterVersion

#
# === OSAlarm.o ===
#

.global OSCreateAlarm
.balign 4
OSCreateAlarm:
/* 0x8024BEB8 | size=0x10 (16 bytes) */
    li      r0,0
    stw     r0,0(r3)
    stw     r0,4(r3)
    blr
.size OSCreateAlarm, . - OSCreateAlarm

.global OSSetAlarmTag
.balign 4
OSSetAlarmTag:
/* 0x8024C608 | size=0x08 (8 bytes) */
    stw     r4,4(r3)
    blr
.size OSSetAlarmTag, . - OSSetAlarmTag

#
# === OSArena.o ===
#

.global OSGetArenaHi
.balign 4
OSGetArenaHi:
/* 0x8024C760 | size=0x08 (8 bytes) */
    lwz     r3,-23680(r13)
    blr
.size OSGetArenaHi, . - OSGetArenaHi

.global OSGetArenaLo
.balign 4
OSGetArenaLo:
/* 0x8024C768 | size=0x08 (8 bytes) */
    lwz     r3,-27920(r13)
    blr
.size OSGetArenaLo, . - OSGetArenaLo

.global OSSetArenaHi
.balign 4
OSSetArenaHi:
/* 0x8024C770 | size=0x08 (8 bytes) */
    stw     r3,-23680(r13)
    blr
.size OSSetArenaHi, . - OSSetArenaHi

.global OSSetArenaLo
.balign 4
OSSetArenaLo:
/* 0x8024C778 | size=0x08 (8 bytes) */
    stw     r3,-27920(r13)
    blr
.size OSSetArenaLo, . - OSSetArenaLo

.global OSAllocFromArenaLo
.balign 4
OSAllocFromArenaLo:
/* 0x8024C780 | size=0x2C (44 bytes) */
    lwz     r0,-27920(r13)
    addi    r4,r4,-1
    not     r5,r4
    add     r0,r0,r4
    and     r6,r5,r0
    add     r0,r6,r3
    add     r0,r0,r4
    and     r0,r5,r0
    stw     r0,-27920(r13)
    mr      r3,r6
    blr
.size OSAllocFromArenaLo, . - OSAllocFromArenaLo

.global OSAllocFromArenaHi
.balign 4
OSAllocFromArenaHi:
/* 0x8024C7AC | size=0x20 (32 bytes) */
    addi    r0,r4,-1
    lwz     r4,-23680(r13)
    not     r0,r0
    and     r4,r4,r0
    subf    r4,r3,r4
    and     r3,r4,r0
    stw     r3,-23680(r13)
    blr
.size OSAllocFromArenaHi, . - OSAllocFromArenaHi

#
# === OSCache.o ===
#

.global DCFlashInvalidate
.balign 4
DCFlashInvalidate:
/* 0x8024CA60 | size=0x10 (16 bytes) */
    mfhid0  r3
    ori     r3,r3,1024
    mthid0  r3
    blr
.size DCFlashInvalidate, . - DCFlashInvalidate

.global DCEnable
.balign 4
DCEnable:
/* 0x8024CA70 | size=0x14 (20 bytes) */
    sync
    mfhid0  r3
    ori     r3,r3,16384
    mthid0  r3
    blr
.size DCEnable, . - DCEnable

.global DCDisable
.balign 4
DCDisable:
/* 0x8024CA84 | size=0x14 (20 bytes) */
    sync
    mfhid0  r3
    rlwinm  r3,r3,0,18,16
    mthid0  r3
    blr
.size DCDisable, . - DCDisable

.global DCFreeze
.balign 4
DCFreeze:
/* 0x8024CA98 | size=0x14 (20 bytes) */
    sync
    mfhid0  r3
    ori     r3,r3,4096
    mthid0  r3
    blr
.size DCFreeze, . - DCFreeze

.global DCUnfreeze
.balign 4
DCUnfreeze:
/* 0x8024CAAC | size=0x10 (16 bytes) */
    mfhid0  r3
    rlwinm  r3,r3,0,20,18
    mthid0  r3
    blr
.size DCUnfreeze, . - DCUnfreeze

.global DCTouchLoad
.balign 4
DCTouchLoad:
/* 0x8024CABC | size=0x08 (8 bytes) */
    dcbt    0,r3
    blr
.size DCTouchLoad, . - DCTouchLoad

.global DCBlockZero
.balign 4
DCBlockZero:
/* 0x8024CAC4 | size=0x08 (8 bytes) */
    dcbz    0,r3
    blr
.size DCBlockZero, . - DCBlockZero

.global DCBlockStore
.balign 4
DCBlockStore:
/* 0x8024CACC | size=0x08 (8 bytes) */
    dcbst   0,r3
    blr
.size DCBlockStore, . - DCBlockStore

.global DCBlockFlush
.balign 4
DCBlockFlush:
/* 0x8024CAD4 | size=0x08 (8 bytes) */
    dcbf    0,r3
    blr
.size DCBlockFlush, . - DCBlockFlush

.global DCBlockInvalidate
.balign 4
DCBlockInvalidate:
/* 0x8024CADC | size=0x08 (8 bytes) */
    dcbi    0,r3
    blr
.size DCBlockInvalidate, . - DCBlockInvalidate

.global DCInvalidateRange
.balign 4
DCInvalidateRange:
/* 0x8024CAE4 | size=0x2C (44 bytes) */
    cmplwi  r4,0
    blelr-
    clrlwi  r5,r3,27
    add     r4,r4,r5
    addi    r4,r4,31
    srwi    r4,r4,5
    mtctr   r4
.L_8024CB00:
    dcbi    0,r3
    addi    r3,r3,32
    bdnz+ .L_8024CB00
    blr
.size DCInvalidateRange, . - DCInvalidateRange

.global DCFlushRange
.balign 4
DCFlushRange:
/* 0x8024CB10 | size=0x30 (48 bytes) */
    cmplwi  r4,0
    blelr-
    clrlwi  r5,r3,27
    add     r4,r4,r5
    addi    r4,r4,31
    srwi    r4,r4,5
    mtctr   r4
.L_8024CB2C:
    dcbf    0,r3
    addi    r3,r3,32
    bdnz+ .L_8024CB2C
    sc
    blr
.size DCFlushRange, . - DCFlushRange

.global DCStoreRange
.balign 4
DCStoreRange:
/* 0x8024CB40 | size=0x30 (48 bytes) */
    cmplwi  r4,0
    blelr-
    clrlwi  r5,r3,27
    add     r4,r4,r5
    addi    r4,r4,31
    srwi    r4,r4,5
    mtctr   r4
.L_8024CB5C:
    dcbst   0,r3
    addi    r3,r3,32
    bdnz+ .L_8024CB5C
    sc
    blr
.size DCStoreRange, . - DCStoreRange

.global DCFlushRangeNoSync
.balign 4
DCFlushRangeNoSync:
/* 0x8024CB70 | size=0x2C (44 bytes) */
    cmplwi  r4,0
    blelr-
    clrlwi  r5,r3,27
    add     r4,r4,r5
    addi    r4,r4,31
    srwi    r4,r4,5
    mtctr   r4
.L_8024CB8C:
    dcbf    0,r3
    addi    r3,r3,32
    bdnz+ .L_8024CB8C
    blr
.size DCFlushRangeNoSync, . - DCFlushRangeNoSync

.global DCStoreRangeNoSync
.balign 4
DCStoreRangeNoSync:
/* 0x8024CB9C | size=0x2C (44 bytes) */
    cmplwi  r4,0
    blelr-
    clrlwi  r5,r3,27
    add     r4,r4,r5
    addi    r4,r4,31
    srwi    r4,r4,5
    mtctr   r4
.L_8024CBB8:
    dcbst   0,r3
    addi    r3,r3,32
    bdnz+ .L_8024CBB8
    blr
.size DCStoreRangeNoSync, . - DCStoreRangeNoSync

.global DCZeroRange
.balign 4
DCZeroRange:
/* 0x8024CBC8 | size=0x2C (44 bytes) */
    cmplwi  r4,0
    blelr-
    clrlwi  r5,r3,27
    add     r4,r4,r5
    addi    r4,r4,31
    srwi    r4,r4,5
    mtctr   r4
.L_8024CBE4:
    dcbz    0,r3
    addi    r3,r3,32
    bdnz+ .L_8024CBE4
    blr
.size DCZeroRange, . - DCZeroRange

.global DCTouchRange
.balign 4
DCTouchRange:
/* 0x8024CBF4 | size=0x2C (44 bytes) */
    cmplwi  r4,0
    blelr-
    clrlwi  r5,r3,27
    add     r4,r4,r5
    addi    r4,r4,31
    srwi    r4,r4,5
    mtctr   r4
.L_8024CC10:
    dcbt    0,r3
    addi    r3,r3,32
    bdnz+ .L_8024CC10
    blr
.size DCTouchRange, . - DCTouchRange

.global ICInvalidateRange
.balign 4
ICInvalidateRange:
/* 0x8024CC20 | size=0x34 (52 bytes) */
    cmplwi  r4,0
    blelr-
    clrlwi  r5,r3,27
    add     r4,r4,r5
    addi    r4,r4,31
    srwi    r4,r4,5
    mtctr   r4
.L_8024CC3C:
    icbi    0,r3
    addi    r3,r3,32
    bdnz+ .L_8024CC3C
    sync
    isync
    blr
.size ICInvalidateRange, . - ICInvalidateRange

.global ICFlashInvalidate
.balign 4
ICFlashInvalidate:
/* 0x8024CC54 | size=0x10 (16 bytes) */
    mfhid0  r3
    ori     r3,r3,2048
    mthid0  r3
    blr
.size ICFlashInvalidate, . - ICFlashInvalidate

.global ICEnable
.balign 4
ICEnable:
/* 0x8024CC64 | size=0x14 (20 bytes) */
    isync
    mfhid0  r3
    ori     r3,r3,32768
    mthid0  r3
    blr
.size ICEnable, . - ICEnable

.global ICDisable
.balign 4
ICDisable:
/* 0x8024CC78 | size=0x14 (20 bytes) */
    isync
    mfhid0  r3
    rlwinm  r3,r3,0,17,15
    mthid0  r3
    blr
.size ICDisable, . - ICDisable

.global ICFreeze
.balign 4
ICFreeze:
/* 0x8024CC8C | size=0x14 (20 bytes) */
    isync
    mfhid0  r3
    ori     r3,r3,8192
    mthid0  r3
    blr
.size ICFreeze, . - ICFreeze

.global ICUnfreeze
.balign 4
ICUnfreeze:
/* 0x8024CCA0 | size=0x10 (16 bytes) */
    mfhid0  r3
    rlwinm  r3,r3,0,19,17
    mthid0  r3
    blr
.size ICUnfreeze, . - ICUnfreeze

.global ICBlockInvalidate
.balign 4
ICBlockInvalidate:
/* 0x8024CCB0 | size=0x08 (8 bytes) */
    icbi    0,r3
    blr
.size ICBlockInvalidate, . - ICBlockInvalidate

.global ICSync
.balign 4
ICSync:
/* 0x8024CCB8 | size=0x08 (8 bytes) */
    isync
    blr
.size ICSync, . - ICSync

.global LCEnable
.balign 4
LCEnable:
/* 0x8024CD8C | size=0x38 (56 bytes) */
    mflr    r0
    stw     r0,4(r1)
    stwu    r1,-16(r1)
    stw     r31,12(r1)
    bl OSDisableInterrupts
    mr      r31,r3
    bl __LCEnable
    mr      r3,r31
    bl OSRestoreInterrupts
    lwz     r0,20(r1)
    lwz     r31,12(r1)
    addi    r1,r1,16
    mtlr    r0
    blr
.size LCEnable, . - LCEnable

.global LCDisable
.balign 4
LCDisable:
/* 0x8024CDC4 | size=0x28 (40 bytes) */
    lis     r3,-8192
    li      r4,512
    mtctr   r4
.L_8024CDD0:
    dcbi    0,r3
    addi    r3,r3,32
    bdnz+ .L_8024CDD0
    mfhid2  r4
    rlwinm  r4,r4,0,4,2
    mthid2  r4
    blr
.size LCDisable, . - LCDisable

.global LCAllocOneTag
.balign 4
LCAllocOneTag:
/* 0x8024CDEC | size=0x14 (20 bytes) */
    cmpwi   r3,0
    beq- .L_8024CDF8
    dcbi    0,r4
.L_8024CDF8:
    dcbz_l  r0,r4
    blr
.size LCAllocOneTag, . - LCAllocOneTag

.global LCAllocTags
.balign 4
LCAllocTags:
/* 0x8024CE00 | size=0x40 (64 bytes) */
    mflr    r6
    cmplwi  r5,0
    ble- .L_8024CE38
    mtctr   r5
    cmpwi   r3,0
    beq- .L_8024CE2C
.L_8024CE18:
    dcbi    0,r4
    dcbz_l  r0,r4
    addi    r4,r4,32
    bdnz+ .L_8024CE18
    b .L_8024CE38
.L_8024CE2C:
    dcbz_l  r0,r4
    addi    r4,r4,32
    bdnz+ .L_8024CE2C
.L_8024CE38:
    mtlr    r6
    blr
.size LCAllocTags, . - LCAllocTags

.global LCLoadBlocks
.balign 4
LCLoadBlocks:
/* 0x8024CE40 | size=0x24 (36 bytes) */
    rlwinm  r6,r5,30,27,31
    clrlwi  r4,r4,4
    or      r6,r6,r4
    mtdmau  r6
    rlwinm  r6,r5,2,28,29
    or      r6,r6,r3
    ori     r6,r6,18
    mtdmal  r6
    blr
.size LCLoadBlocks, . - LCLoadBlocks

.global LCStoreBlocks
.balign 4
LCStoreBlocks:
/* 0x8024CE64 | size=0x24 (36 bytes) */
    rlwinm  r6,r5,30,27,31
    clrlwi  r3,r3,4
    or      r6,r6,r3
    mtdmau  r6
    rlwinm  r6,r5,2,28,29
    or      r6,r6,r4
    ori     r6,r6,2
    mtdmal  r6
    blr
.size LCStoreBlocks, . - LCStoreBlocks

.global LCQueueLength
.balign 4
LCQueueLength:
/* 0x8024D0C0 | size=0x0C (12 bytes) */
    mfhid2  r4
    rlwinm  r3,r4,8,28,31
    blr
.size LCQueueLength, . - LCQueueLength

.global LCQueueWait
.balign 4
LCQueueWait:
/* 0x8024D0CC | size=0x14 (20 bytes) */
.L_8024D0CC:
    mfhid2  r4
    rlwinm  r4,r4,8,28,31
    cmpw    r4,r3
    bgt+ .L_8024D0CC
    blr
.size LCQueueWait, . - LCQueueWait

.global L2Enable
.balign 4
L2Enable:
/* 0x8024D174 | size=0x2C (44 bytes) */
    mflr    r0
    stw     r0,4(r1)
    stwu    r1,-8(r1)
    bl PPCMfl2cr
    oris    r0,r3,32768
    rlwinm  r3,r0,0,11,9
    bl PPCMtl2cr
    lwz     r0,12(r1)
    addi    r1,r1,8
    mtlr    r0
    blr
.size L2Enable, . - L2Enable

.global L2Disable
.balign 4
L2Disable:
/* 0x8024D1A0 | size=0x30 (48 bytes) */
    mflr    r0
    stw     r0,4(r1)
    stwu    r1,-8(r1)
    sync
    bl PPCMfl2cr
    clrlwi  r3,r3,1
    bl PPCMtl2cr
    sync
    lwz     r0,12(r1)
    addi    r1,r1,8
    mtlr    r0
    blr
.size L2Disable, . - L2Disable

.global L2SetDataOnly
.balign 4
L2SetDataOnly:
/* 0x8024D268 | size=0x40 (64 bytes) */
    mflr    r0
    stw     r0,4(r1)
    stwu    r1,-8(r1)
    cmpwi   r3,0
    beq- .L_8024D28C
    bl PPCMfl2cr
    oris    r3,r3,64
    bl PPCMtl2cr
    b .L_8024D298
.L_8024D28C:
    bl PPCMfl2cr
    rlwinm  r3,r3,0,10,8
    bl PPCMtl2cr
.L_8024D298:
    lwz     r0,12(r1)
    addi    r1,r1,8
    mtlr    r0
    blr
.size L2SetDataOnly, . - L2SetDataOnly

.global L2SetWriteThrough
.balign 4
L2SetWriteThrough:
/* 0x8024D2A8 | size=0x40 (64 bytes) */
    mflr    r0
    stw     r0,4(r1)
    stwu    r1,-8(r1)
    cmpwi   r3,0
    beq- .L_8024D2CC
    bl PPCMfl2cr
    oris    r3,r3,8
    bl PPCMtl2cr
    b .L_8024D2D8
.L_8024D2CC:
    bl PPCMfl2cr
    rlwinm  r3,r3,0,13,11
    bl PPCMtl2cr
.L_8024D2D8:
    lwz     r0,12(r1)
    addi    r1,r1,8
    mtlr    r0
    blr
.size L2SetWriteThrough, . - L2SetWriteThrough

#
# === OSContext.o ===
#

.global OSLoadFPUContext
.balign 4
OSLoadFPUContext:
/* 0x8024D788 | size=0x08 (8 bytes) */
    addi    r4,r3,0
    b __OSLoadFPUContext
.size OSLoadFPUContext, . - OSLoadFPUContext

.global OSSaveFPUContext
.balign 4
OSSaveFPUContext:
/* 0x8024D790 | size=0x08 (8 bytes) */
    addi    r5,r3,0
    b __OSSaveFPUContext
.size OSSaveFPUContext, . - OSSaveFPUContext

.global OSGetCurrentContext
.balign 4
OSGetCurrentContext:
/* 0x8024D7F4 | size=0x0C (12 bytes) */
    lis     r3,-32768
    lwz     r3,212(r3)
    blr
.size OSGetCurrentContext, . - OSGetCurrentContext

.global OSGetStackPointer
.balign 4
OSGetStackPointer:
/* 0x8024D958 | size=0x08 (8 bytes) */
    mr      r3,r1
    blr
.size OSGetStackPointer, . - OSGetStackPointer

.global OSSwitchStack
.balign 4
OSSwitchStack:
/* 0x8024D960 | size=0x10 (16 bytes) */
    mr      r5,r1
    mr      r1,r3
    mr      r3,r5
    blr
.size OSSwitchStack, . - OSSwitchStack

.global OSSwitchFiber
.balign 4
OSSwitchFiber:
/* 0x8024D970 | size=0x30 (48 bytes) */
    mflr    r0
    mr      r5,r1
    stwu    r5,-8(r4)
    mr      r1,r4
    stw     r0,4(r5)
    mtlr    r3
    blrl
    lwz     r5,0(r1)
    lwz     r0,4(r5)
    mtlr    r0
    mr      r1,r5
    blr
.size OSSwitchFiber, . - OSSwitchFiber

.global OSClearContext
.balign 4
OSClearContext:
/* 0x8024D9A0 | size=0x24 (36 bytes) */
    li      r5,0
    sth     r5,416(r3)
    lis     r4,-32768
    sth     r5,418(r3)
    lwz     r0,216(r4)
    cmplw   r3,r0
    bne- .L_8024D9C0
    stw     r5,216(r4)
.L_8024D9C0:
    blr
.size OSClearContext, . - OSClearContext

#
# === OSError.o ===
#

.global OSVReport
.balign 4
OSVReport:
/* 0x8024DFA0 | size=0x20 (32 bytes) */
    mflr    r0
    stw     r0,4(r1)
    stwu    r1,-8(r1)
    bl vprintf
    lwz     r0,12(r1)
    addi    r1,r1,8
    mtlr    r0
    blr
.size OSVReport, . - OSVReport

#
# === OSExec.o ===
#

.global Run
.balign 4
Run:
/* 0x8024E774 | size=0x3C (60 bytes) */
    mflr    r0
    stw     r0,4(r1)
    stwu    r1,-24(r1)
    stw     r31,20(r1)
    mr      r31,r3
    bl ICFlashInvalidate
    sync
    isync
    mtlr    r31
    blr
    lwz     r0,28(r1)
    lwz     r31,20(r1)
    addi    r1,r1,24
    mtlr    r0
    blr
.size Run, . - Run

.global Callback
.balign 4
Callback:
/* 0x8024E884 | size=0x0C (12 bytes) */
    li      r0,1
    stw     r0,-23672(r13)
    blr
.size Callback, . - Callback

.global IsStreamEnabled
.balign 4
IsStreamEnabled:
/* 0x8024E890 | size=0x38 (56 bytes) */
    mflr    r0
    stw     r0,4(r1)
    stwu    r1,-8(r1)
    bl DVDGetCurrentDiskID
    lbz     r0,8(r3)
    cmplwi  r0,0
    beq- .L_8024E8B4
    li      r3,1
    b .L_8024E8B8
.L_8024E8B4:
    li      r3,0
.L_8024E8B8:
    lwz     r0,12(r1)
    addi    r1,r1,8
    mtlr    r0
    blr
.size IsStreamEnabled, . - IsStreamEnabled

.global __OSGetExecParams
.balign 4
__OSGetExecParams:
/* 0x8024E8C8 | size=0x40 (64 bytes) */
    mflr    r0
    stw     r0,4(r1)
    stwu    r1,-8(r1)
    lis     r5,-32768
    lwz     r4,12528(r5)
    cmplw   r5,r4
    bgt- .L_8024E8F0
    li      r5,28
    bl memcpy
    b .L_8024E8F8
.L_8024E8F0:
    li      r0,0
    stw     r0,0(r3)
.L_8024E8F8:
    lwz     r0,12(r1)
    addi    r1,r1,8
    mtlr    r0
    blr
.size __OSGetExecParams, . - __OSGetExecParams

.global IsNewApploader
.balign 4
IsNewApploader:
/* 0x8024ECB4 | size=0x40 (64 bytes) */
    mflr    r0
    stw     r0,4(r1)
    stwu    r1,-8(r1)
    lis     r4,-32700
    addi    r4,r4,-18712
    li      r5,10
    bl strncmp
    cmpwi   r3,0
    ble- .L_8024ECE0
    li      r3,1
    b .L_8024ECE4
.L_8024ECE0:
    li      r3,0
.L_8024ECE4:
    lwz     r0,12(r1)
    addi    r1,r1,8
    mtlr    r0
    blr
.size IsNewApploader, . - IsNewApploader

#
# === OSInterrupt.o ===
#

.global OSDisableInterrupts
.balign 4
OSDisableInterrupts:
/* 0x8024F550 | size=0x14 (20 bytes) */
    mfmsr   r3
    rlwinm  r4,r3,0,17,15
    mtmsr   r4
    rlwinm  r3,r3,17,31,31
    blr
.size OSDisableInterrupts, . - OSDisableInterrupts

.global OSEnableInterrupts
.balign 4
OSEnableInterrupts:
/* 0x8024F564 | size=0x14 (20 bytes) */
    mfmsr   r3
    ori     r4,r3,32768
    mtmsr   r4
    rlwinm  r3,r3,17,31,31
    blr
.size OSEnableInterrupts, . - OSEnableInterrupts

.global OSRestoreInterrupts
.balign 4
OSRestoreInterrupts:
/* 0x8024F578 | size=0x24 (36 bytes) */
    cmpwi   r3,0
    mfmsr   r4
    beq- .L_8024F58C
    ori     r5,r4,32768
    b .L_8024F590
.L_8024F58C:
    rlwinm  r5,r4,0,17,15
.L_8024F590:
    mtmsr   r5
    rlwinm  r3,r4,17,31,31
    blr
.size OSRestoreInterrupts, . - OSRestoreInterrupts

.global __OSSetInterruptHandler
.balign 4
__OSSetInterruptHandler:
/* 0x8024F59C | size=0x1C (28 bytes) */
    extsh   r0,r3
    lwz     r3,-23664(r13)
    slwi    r0,r0,2
    add     r5,r3,r0
    lwz     r3,0(r5)
    stw     r4,0(r5)
    blr
.size __OSSetInterruptHandler, . - __OSSetInterruptHandler

.global __OSGetInterruptHandler
.balign 4
__OSGetInterruptHandler:
/* 0x8024F5B8 | size=0x14 (20 bytes) */
    extsh   r0,r3
    lwz     r3,-23664(r13)
    slwi    r0,r0,2
    lwzx    r3,r3,r0
    blr
.size __OSGetInterruptHandler, . - __OSGetInterruptHandler

.global OSGetInterruptMask
.balign 4
OSGetInterruptMask:
/* 0x8024F918 | size=0x0C (12 bytes) */
    lis     r3,-32768
    lwz     r3,200(r3)
    blr
.size OSGetInterruptMask, . - OSGetInterruptMask

#
# === OSLink.o ===
#

.global OSNotifyLink
.balign 4
OSNotifyLink:
/* 0x8024FE58 | size=0x04 (4 bytes) */
    blr
.size OSNotifyLink, . - OSNotifyLink

.global OSNotifyUnlink
.balign 4
OSNotifyUnlink:
/* 0x8024FE5C | size=0x04 (4 bytes) */
    blr
.size OSNotifyUnlink, . - OSNotifyUnlink

.global OSSetStringTable
.balign 4
OSSetStringTable:
/* 0x8024FE60 | size=0x0C (12 bytes) */
    lis     r4,-32768
    stw     r3,12496(r4)
    blr
.size OSSetStringTable, . - OSSetStringTable

.global OSLink
.balign 4
OSLink:
/* 0x80250408 | size=0x24 (36 bytes) */
    mflr    r0
    li      r5,0
    stw     r0,4(r1)
    stwu    r1,-8(r1)
    bl Link
    lwz     r0,12(r1)
    addi    r1,r1,8
    mtlr    r0
    blr
.size OSLink, . - OSLink

.global OSLinkFixed
.balign 4
OSLinkFixed:
/* 0x8025042C | size=0x3C (60 bytes) */
    mflr    r0
    stw     r0,4(r1)
    stwu    r1,-8(r1)
    lwz     r0,28(r3)
    cmplwi  r0,3
    bgt- .L_80250448
    bge- .L_80250450
.L_80250448:
    li      r3,0
    b .L_80250458
.L_80250450:
    li      r5,1
    bl Link
.L_80250458:
    lwz     r0,12(r1)
    addi    r1,r1,8
    mtlr    r0
    blr
.size OSLinkFixed, . - OSLinkFixed

.global __OSModuleInit
.balign 4
__OSModuleInit:
/* 0x80250874 | size=0x18 (24 bytes) */
    lis     r4,-32768
    li      r0,0
    stw     r0,12492(r4)
    stw     r0,12488(r4)
    stw     r0,12496(r4)
    blr
.size __OSModuleInit, . - __OSModuleInit

#
# === OSMemory.o ===
#

.global OSGetPhysicalMemSize
.balign 4
OSGetPhysicalMemSize:
/* 0x8025092C | size=0x0C (12 bytes) */
    lis     r3,-32768
    lwz     r3,40(r3)
    blr
.size OSGetPhysicalMemSize, . - OSGetPhysicalMemSize

.global OSGetConsoleSimulatedMemSize
.balign 4
OSGetConsoleSimulatedMemSize:
/* 0x80250938 | size=0x0C (12 bytes) */
    lis     r3,-32768
    lwz     r3,240(r3)
    blr
.size OSGetConsoleSimulatedMemSize, . - OSGetConsoleSimulatedMemSize

.global OnReset
.balign 4
OnReset:
/* 0x80250944 | size=0x3C (60 bytes) */
    mflr    r0
    cmpwi   r3,0
    stw     r0,4(r1)
    stwu    r1,-8(r1)
    beq- .L_8025096C
    lis     r3,-13312
    li      r0,255
    sth     r0,16400(r3)
    lis     r3,-4096
    bl __OSMaskInterrupts
.L_8025096C:
    li      r3,1
    lwz     r0,12(r1)
    addi    r1,r1,8
    mtlr    r0
    blr
.size OnReset, . - OnReset

.global RealMode
.balign 4
RealMode:
/* 0x80250BB0 | size=0x18 (24 bytes) */
    clrlwi  r3,r3,2
    mtsrr0  r3
    mfmsr   r3
    rlwinm  r3,r3,0,28,25
    mtsrr1  r3
    rfi
.size RealMode, . - RealMode

#
# === OSReboot.o ===
#

.global OSSetSaveRegion
.balign 4
OSSetSaveRegion:
/* 0x80250D50 | size=0x0C (12 bytes) */
    stw     r3,-23640(r13)
    stw     r4,-23636(r13)
    blr
.size OSSetSaveRegion, . - OSSetSaveRegion

.global OSGetSaveRegion
.balign 4
OSGetSaveRegion:
/* 0x80250D5C | size=0x14 (20 bytes) */
    lwz     r0,-23640(r13)
    stw     r0,0(r3)
    lwz     r0,-23636(r13)
    stw     r0,0(r4)
    blr
.size OSGetSaveRegion, . - OSGetSaveRegion

.global OSGetSavedRegion
.balign 4
OSGetSavedRegion:
/* 0x80250D70 | size=0x1C (28 bytes) */
    lis     r5,-32694
    addi    r5,r5,-24816
    lwz     r0,12(r5)
    stw     r0,0(r3)
    lwz     r0,16(r5)
    stw     r0,0(r4)
    blr
.size OSGetSavedRegion, . - OSGetSavedRegion

#
# === OSReset.o ===
#

.global OSUnregisterResetFunction
.balign 4
OSUnregisterResetFunction:
/* 0x80250E10 | size=0x38 (56 bytes) */
    lwz     r4,8(r3)
    lwz     r5,12(r3)
    cmplwi  r4,0
    bne- .L_80250E2C
    addi    r3,r13,-23632
    stw     r5,4(r3)
    b .L_80250E30
.L_80250E2C:
    stw     r5,12(r4)
.L_80250E30:
    cmplwi  r5,0
    bne- .L_80250E40
    stw     r4,-23632(r13)
    blr
.L_80250E40:
    stw     r4,8(r5)
    blr
.size OSUnregisterResetFunction, . - OSUnregisterResetFunction

.global OSGetResetCode
.balign 4
OSGetResetCode:
/* 0x802513C0 | size=0x38 (56 bytes) */
    lis     r3,-32694
    addi    r3,r3,-24816
    lwz     r0,0(r3)
    cmpwi   r0,0
    beq- .L_802513E0
    lwz     r0,4(r3)
    oris    r3,r0,32768
    b .L_802513F4
.L_802513E0:
    lis     r3,-13312
    addi    r3,r3,12288
    lwz     r0,36(r3)
    clrrwi  r0,r0,3
    srwi    r3,r0,3
.L_802513F4:
    blr
.size OSGetResetCode, . - OSGetResetCode

.global OSSetBootDol
.balign 4
OSSetBootDol:
/* 0x802513F8 | size=0x10 (16 bytes) */
    lwz     r0,-23624(r13)
    stw     r3,-23624(r13)
    mr      r3,r0
    blr
.size OSSetBootDol, . - OSSetBootDol

#
# === OSResetSW.o ===
#

.global OSGetResetSwitchState
.balign 4
OSGetResetSwitchState:
/* 0x80251808 | size=0x20 (32 bytes) */
    mflr    r0
    stw     r0,4(r1)
    stwu    r1,-8(r1)
    bl OSGetResetButtonState
    lwz     r0,12(r1)
    addi    r1,r1,8
    mtlr    r0
    blr
.size OSGetResetSwitchState, . - OSGetResetSwitchState

#
# === OSRtc.o ===
#

.global __OSUnlockSram
.balign 4
__OSUnlockSram:
/* 0x802524FC | size=0x24 (36 bytes) */
    mflr    r0
    li      r4,0
    stw     r0,4(r1)
    stwu    r1,-8(r1)
    bl UnlockSram
    lwz     r0,12(r1)
    addi    r1,r1,8
    mtlr    r0
    blr
.size __OSUnlockSram, . - __OSUnlockSram

.global __OSUnlockSramEx
.balign 4
__OSUnlockSramEx:
/* 0x80252520 | size=0x24 (36 bytes) */
    mflr    r0
    li      r4,20
    stw     r0,4(r1)
    stwu    r1,-8(r1)
    bl UnlockSram
    lwz     r0,12(r1)
    addi    r1,r1,8
    mtlr    r0
    blr
.size __OSUnlockSramEx, . - __OSUnlockSramEx

.global __OSSyncSram
.balign 4
__OSSyncSram:
/* 0x80252544 | size=0x10 (16 bytes) */
    lis     r3,-32694
    addi    r3,r3,-24704
    lwz     r3,76(r3)
    blr
.size __OSSyncSram, . - __OSSyncSram

#
# === OSSync.o ===
#

.global SystemCallVector
.balign 4
SystemCallVector:
/* 0x802531D4 | size=0x20 (32 bytes) */
    mfhid0  r9
    ori     r10,r9,8
    mthid0  r10
    isync
    sync
    mthid0  r9
    rfi
    nop
.size SystemCallVector, . - SystemCallVector

#
# === OSThread.o ===
#

.global DefaultSwitchThreadCallback
.balign 4
DefaultSwitchThreadCallback:
/* 0x80253258 | size=0x04 (4 bytes) */
    blr
.size DefaultSwitchThreadCallback, . - DefaultSwitchThreadCallback

.global OSInitThreadQueue
.balign 4
OSInitThreadQueue:
/* 0x80253428 | size=0x10 (16 bytes) */
    li      r0,0
    stw     r0,4(r3)
    stw     r0,0(r3)
    blr
.size OSInitThreadQueue, . - OSInitThreadQueue

.global OSGetCurrentThread
.balign 4
OSGetCurrentThread:
/* 0x80253438 | size=0x0C (12 bytes) */
    lis     r3,-32768
    lwz     r3,228(r3)
    blr
.size OSGetCurrentThread, . - OSGetCurrentThread

.global OSIsThreadSuspended
.balign 4
OSIsThreadSuspended:
/* 0x802534A0 | size=0x1C (28 bytes) */
    lwz     r0,716(r3)
    cmpwi   r0,0
    ble- .L_802534B4
    li      r3,1
    blr
.L_802534B4:
    li      r3,0
    blr
.size OSIsThreadSuspended, . - OSIsThreadSuspended

.global OSIsThreadTerminated
.balign 4
OSIsThreadTerminated:
/* 0x802534BC | size=0x34 (52 bytes) */
    lhz     r3,712(r3)
    li      r0,1
    cmplwi  r3,8
    beq- .L_802534D8
    cmplwi  r3,0
    beq- .L_802534D8
    li      r0,0
.L_802534D8:
    cmpwi   r0,0
    beq- .L_802534E8
    li      r3,1
    blr
.L_802534E8:
    li      r3,0
    blr
.size OSIsThreadTerminated, . - OSIsThreadTerminated

.global OSDisableScheduler
.balign 4
OSDisableScheduler:
/* 0x80253534 | size=0x40 (64 bytes) */
    mflr    r0
    stw     r0,4(r1)
    stwu    r1,-16(r1)
    stw     r31,12(r1)
    bl OSDisableInterrupts
    lwz     r4,-23576(r13)
    addi    r0,r4,1
    stw     r0,-23576(r13)
    mr      r31,r4
    bl OSRestoreInterrupts
    mr      r3,r31
    lwz     r0,20(r1)
    lwz     r31,12(r1)
    addi    r1,r1,16
    mtlr    r0
    blr
.size OSDisableScheduler, . - OSDisableScheduler

.global OSEnableScheduler
.balign 4
OSEnableScheduler:
/* 0x80253574 | size=0x40 (64 bytes) */
    mflr    r0
    stw     r0,4(r1)
    stwu    r1,-16(r1)
    stw     r31,12(r1)
    bl OSDisableInterrupts
    lwz     r4,-23576(r13)
    addi    r0,r4,-1
    stw     r0,-23576(r13)
    mr      r31,r4
    bl OSRestoreInterrupts
    mr      r3,r31
    lwz     r0,20(r1)
    lwz     r31,12(r1)
    addi    r1,r1,16
    mtlr    r0
    blr
.size OSEnableScheduler, . - OSEnableScheduler

.global __OSGetEffectivePriority
.balign 4
__OSGetEffectivePriority:
/* 0x80253688 | size=0x3C (60 bytes) */
    lwz     r4,724(r3)
    lwz     r5,756(r3)
    b .L_802536B4
.L_80253694:
    lwz     r3,0(r5)
    cmplwi  r3,0
    beq- .L_802536B0
    lwz     r0,720(r3)
    cmpw    r0,r4
    bge- .L_802536B0
    mr      r4,r0
.L_802536B0:
    lwz     r5,16(r5)
.L_802536B4:
    cmplwi  r5,0
    bne+ .L_80253694
    mr      r3,r4
    blr
.size __OSGetEffectivePriority, . - __OSGetEffectivePriority

.global __OSReschedule
.balign 4
__OSReschedule:
/* 0x80253B74 | size=0x30 (48 bytes) */
    mflr    r0
    stw     r0,4(r1)
    stwu    r1,-8(r1)
    lwz     r0,-23580(r13)
    cmpwi   r0,0
    beq- .L_80253B94
    li      r3,0
    bl SelectThread
.L_80253B94:
    lwz     r0,12(r1)
    addi    r1,r1,8
    mtlr    r0
    blr
.size __OSReschedule, . - __OSReschedule

.global OSYieldThread
.balign 4
OSYieldThread:
/* 0x80253BA4 | size=0x3C (60 bytes) */
    mflr    r0
    stw     r0,4(r1)
    stwu    r1,-16(r1)
    stw     r31,12(r1)
    bl OSDisableInterrupts
    addi    r31,r3,0
    li      r3,1
    bl SelectThread
    mr      r3,r31
    bl OSRestoreInterrupts
    lwz     r0,20(r1)
    lwz     r31,12(r1)
    addi    r1,r1,16
    mtlr    r0
    blr
.size OSYieldThread, . - OSYieldThread

.global OSGetThreadPriority
.balign 4
OSGetThreadPriority:
/* 0x802548F0 | size=0x08 (8 bytes) */
    lwz     r3,724(r3)
    blr
.size OSGetThreadPriority, . - OSGetThreadPriority

.global OSGetIdleFunction
.balign 4
OSGetIdleFunction:
/* 0x80254988 | size=0x1C (28 bytes) */
    lis     r3,-32694
    addi    r3,r3,-24360
    lhz     r0,712(r3)
    cmplwi  r0,0
    bnelr-
    li      r3,0
    blr
.size OSGetIdleFunction, . - OSGetIdleFunction

.global IsMember__OSThread
.balign 4
IsMember__OSThread:
/* 0x80254A40 | size=0x2C (44 bytes) | original: IsMember */
    lwz     r3,0(r3)
    b .L_80254A5C
.L_80254A48:
    cmplw   r4,r3
    bne- .L_80254A58
    li      r3,1
    blr
.L_80254A58:
    lwz     r3,736(r3)
.L_80254A5C:
    cmplwi  r3,0
    bne+ .L_80254A48
    li      r3,0
    blr
.size IsMember__OSThread, . - IsMember__OSThread

.global OSSetThreadSpecific
.balign 4
OSSetThreadSpecific:
/* 0x80255268 | size=0x30 (48 bytes) */
    lis     r5,-32768
    lwz     r5,228(r5)
    cmplwi  r5,0
    beqlr-
    cmpwi   r3,0
    bltlr-
    cmpwi   r3,2
    bgelr-
    slwi    r0,r3,2
    add     r3,r5,r0
    stw     r4,784(r3)
    blr
.size OSSetThreadSpecific, . - OSSetThreadSpecific

.global OSGetThreadSpecific
.balign 4
OSGetThreadSpecific:
/* 0x80255298 | size=0x38 (56 bytes) */
    lis     r4,-32768
    lwz     r4,228(r4)
    cmplwi  r4,0
    beq- .L_802552C8
    cmpwi   r3,0
    blt- .L_802552C8
    cmpwi   r3,2
    bge- .L_802552C8
    slwi    r0,r3,2
    add     r3,r4,r0
    lwz     r3,784(r3)
    blr
.L_802552C8:
    li      r3,0
    blr
.size OSGetThreadSpecific, . - OSGetThreadSpecific

#
# === OSTime.o ===
#

.global OSGetTime
.balign 4
OSGetTime:
/* 0x802552D0 | size=0x18 (24 bytes) */
.L_802552D0:
    mftbu   r3
    mftb    r4
    mftbu   r5
    cmpw    r3,r5
    bne+ .L_802552D0
    blr
.size OSGetTime, . - OSGetTime

.global OSGetTick
.balign 4
OSGetTick:
/* 0x802552E8 | size=0x08 (8 bytes) */
    mftb    r3
    blr
.size OSGetTick, . - OSGetTick

.global __SetTime
.balign 4
__SetTime:
/* 0x802552F0 | size=0x14 (20 bytes) */
    li      r5,0
    mttbl   r5
    mttbu   r3
    mttbl   r4
    blr
.size __SetTime, . - __SetTime

.global __OSSetTick
.balign 4
__OSSetTick:
/* 0x80255444 | size=0x08 (8 bytes) */
    mttbl   r3
    blr
.size __OSSetTick, . - __OSSetTick

#
# === OSMutex.o ===
#

.global OSInitMutex
.balign 4
OSInitMutex:
/* 0x80255DA8 | size=0x38 (56 bytes) */
    mflr    r0
    stw     r0,4(r1)
    stwu    r1,-24(r1)
    stw     r31,20(r1)
    mr      r31,r3
    bl OSInitThreadQueue
    li      r0,0
    stw     r0,8(r31)
    stw     r0,12(r31)
    lwz     r0,28(r1)
    lwz     r31,20(r1)
    addi    r1,r1,24
    mtlr    r0
    blr
.size OSInitMutex, . - OSInitMutex

.global OSInitCond
.balign 4
OSInitCond:
/* 0x802560B0 | size=0x20 (32 bytes) */
    mflr    r0
    stw     r0,4(r1)
    stwu    r1,-8(r1)
    bl OSInitThreadQueue
    lwz     r0,12(r1)
    addi    r1,r1,8
    mtlr    r0
    blr
.size OSInitCond, . - OSInitCond

.global OSSignalCond
.balign 4
OSSignalCond:
/* 0x802561A4 | size=0x20 (32 bytes) */
    mflr    r0
    stw     r0,4(r1)
    stwu    r1,-8(r1)
    bl OSWakeupThread
    lwz     r0,12(r1)
    addi    r1,r1,8
    mtlr    r0
    blr
.size OSSignalCond, . - OSSignalCond

.global IsMember__OSMutex
.balign 4
IsMember__OSMutex:
/* 0x802561C4 | size=0x2C (44 bytes) | original: IsMember */
    lwz     r3,0(r3)
    b .L_802561E0
.L_802561CC:
    cmplw   r4,r3
    bne- .L_802561DC
    li      r3,1
    blr
.L_802561DC:
    lwz     r3,16(r3)
.L_802561E0:
    cmplwi  r3,0
    bne+ .L_802561CC
    li      r3,0
    blr
.size IsMember__OSMutex, . - IsMember__OSMutex

.global __OSCheckDeadLock
.balign 4
__OSCheckDeadLock:
/* 0x802562F0 | size=0x38 (56 bytes) */
    lwz     r4,752(r3)
    b .L_8025630C
.L_802562F8:
    cmplw   r4,r3
    bne- .L_80256308
    li      r3,1
    blr
.L_80256308:
    lwz     r4,752(r4)
.L_8025630C:
    cmplwi  r4,0
    beq- .L_80256320
    lwz     r4,8(r4)
    cmplwi  r4,0
    bne+ .L_802562F8
.L_80256320:
    li      r3,0
    blr
.size __OSCheckDeadLock, . - __OSCheckDeadLock

#
# === OSFont.o ===
#

.global IsSjisTrailByte
.balign 4
IsSjisTrailByte:
/* 0x8036FF10 | size=0x40 (64 bytes) */
    clrlwi  r0,r3,24
    cmplwi  r0,64
    li      r4,0
    addi    r5,r4,0
    blt- .L_8036FF30
    cmplwi  r0,252
    bgt- .L_8036FF30
    li      r5,1
.L_8036FF30:
    cmpwi   r5,0
    beq- .L_8036FF48
    clrlwi  r0,r3,24
    cmplwi  r0,127
    beq- .L_8036FF48
    li      r4,1
.L_8036FF48:
    mr      r3,r4
    blr
.size IsSjisTrailByte, . - IsSjisTrailByte

.global GetFontSize
.balign 4
GetFontSize:
/* 0x80370238 | size=0x34 (52 bytes) */
    lbz     r0,0(r3)
    cmplwi  r0,89
    bne- .L_80370264
    lbz     r0,1(r3)
    cmplwi  r0,97
    bne- .L_80370264
    lbz     r0,2(r3)
    cmplwi  r0,121
    bne- .L_80370264
    lwz     r3,4(r3)
    blr
.L_80370264:
    li      r3,0
    blr
.size GetFontSize, . - GetFontSize

.global OSSetFontWidth
.balign 4
OSSetFontWidth:
/* 0x8037162C | size=0x10 (16 bytes) */
    lwz     r0,-22376(r13)
    stw     r3,-22376(r13)
    mr      r3,r0
    blr
.size OSSetFontWidth, . - OSSetFontWidth

#
# === OSSemaphore.o ===
#

.global OSGetSemaphoreCount
.balign 4
OSGetSemaphoreCount:
/* 0x80371A90 | size=0x08 (8 bytes) */
    lwz     r3,0(r3)
    blr
.size OSGetSemaphoreCount, . - OSGetSemaphoreCount

#
# === OSUtf.o ===
#

.global OSANSItoUTF32
.balign 4
OSANSItoUTF32:
/* 0x80371E88 | size=0x34 (52 bytes) */
    clrlwi  r0,r3,24
    cmplwi  r0,128
    blt- .L_80371EB4
    cmplwi  r0,159
    bgt- .L_80371EB4
    lis     r3,-32700
    addi    r3,r3,14752
    slwi    r0,r0,1
    add     r3,r3,r0
    lhz     r3,-256(r3)
    blr
.L_80371EB4:
    clrlwi  r3,r3,24
    blr
.size OSANSItoUTF32, . - OSANSItoUTF32

.global OSSJIStoUTF32
.balign 4
OSSJIStoUTF32:
/* 0x80371F00 | size=0x34 (52 bytes) */
    lis     r4,-32699
    clrlwi  r5,r3,16
    rlwinm  r3,r3,26,22,29
    addi    r0,r4,18400
    add     r3,r0,r3
    lwz     r3,0(r3)
    cmplwi  r3,0
    beq- .L_80371F2C
    rlwinm  r0,r5,1,23,30
    lhzx    r3,r3,r0
    blr
.L_80371F2C:
    li      r3,0
    blr
.size OSSJIStoUTF32, . - OSSJIStoUTF32
