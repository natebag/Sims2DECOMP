# DolphinSDK hardware libs (exi.a, si.a, vi.a, pad.a, ai.a, dvd.a) - Small functions
# Auto-generated from ELF disassembly
# Small functions (<= 64 bytes)

.section .text

#
# === exi.a(EXIBios.o) ===
#

.global EXIGetState
.balign 4
EXIGetState:
/* 0x80257D50 | size=0x18 (24 bytes) */
    slwi    r4,r3,6
    lis     r3,-32694
    addi    r0,r3,-22064
    add     r3,r0,r4
    lwz     r3,12(r3)
    blr
.size EXIGetState, . - EXIGetState

.global UnlockedHandler
.balign 4
UnlockedHandler:
/* 0x80257D68 | size=0x28 (40 bytes) */
    mflr    r0
    stw     r0,4(r1)
    stwu    r1,-24(r1)
    li      r4,0
    addi    r5,r1,16
    bl EXIGetID
    lwz     r0,28(r1)
    addi    r1,r1,24
    mtlr    r0
    blr
.size UnlockedHandler, . - UnlockedHandler

#
# === exi.a(EXIUart.o) ===
#

.global ReadUARTN
.balign 4
ReadUARTN:
/* 0x80258844 | size=0x08 (8 bytes) */
    li      r3,4
    blr
.size ReadUARTN, . - ReadUARTN

#
# === si.a(SIBios.o) ===
#

.global SIBusy
.balign 4
SIBusy:
/* 0x80258AE4 | size=0x20 (32 bytes) */
    lis     r3,-32700
    lwz     r0,-15972(r3)
    cmpwi   r0,-1
    beq- .L_80258AFC
    li      r3,1
    blr
.L_80258AFC:
    li      r3,0
    blr
.size SIBusy, . - SIBusy

.global SIIsChanBusy
.balign 4
SIIsChanBusy:
/* 0x80258B04 | size=0x3C (60 bytes) */
    lis     r4,-32694
    slwi    r5,r3,5
    addi    r0,r4,-21872
    add     r4,r0,r5
    lwz     r0,0(r4)
    li      r5,1
    cmpwi   r0,-1
    bne- .L_80258B38
    lis     r4,-32700
    lwz     r0,-15972(r4)
    cmpw    r0,r3
    beq- .L_80258B38
    li      r5,0
.L_80258B38:
    mr      r3,r5
    blr
.size SIIsChanBusy, . - SIIsChanBusy

.global SIClearTCInterrupt
.balign 4
SIClearTCInterrupt:
/* 0x80258B40 | size=0x1C (28 bytes) */
    lis     r3,-13312
    addi    r3,r3,25600
    lwz     r0,52(r3)
    oris    r0,r0,32768
    clrrwi  r0,r0,1
    stw     r0,52(r3)
    blr
.size SIClearTCInterrupt, . - SIClearTCInterrupt

.global SISetCommand
.balign 4
SISetCommand:
/* 0x80259928 | size=0x14 (20 bytes) */
    mulli   r0,r3,12
    lis     r3,-13312
    addi    r3,r3,25600
    stwx    r4,r3,r0
    blr
.size SISetCommand, . - SISetCommand

.global SIGetCommand
.balign 4
SIGetCommand:
/* 0x8025993C | size=0x14 (20 bytes) */
    mulli   r0,r3,12
    lis     r3,-13312
    addi    r3,r3,25600
    lwzx    r3,r3,r0
    blr
.size SIGetCommand, . - SIGetCommand

.global SITransferCommands
.balign 4
SITransferCommands:
/* 0x80259950 | size=0x10 (16 bytes) */
    lis     r3,-13312
    lis     r0,-32768
    stw     r0,25656(r3)
    blr
.size SITransferCommands, . - SITransferCommands

.global SIProbe
.balign 4
SIProbe:
/* 0x8025A5C0 | size=0x24 (36 bytes) */
    mflr    r0
    stw     r0,4(r1)
    stwu    r1,-8(r1)
    bl SIGetType
    bl SIDecodeType
    lwz     r0,12(r1)
    addi    r1,r1,8
    mtlr    r0
    blr
.size SIProbe, . - SIProbe

#
# === si.a(SISamplingRate.o) ===
#

.global SIRefreshSamplingRate
.balign 4
SIRefreshSamplingRate:
/* 0x8025A820 | size=0x24 (36 bytes) */
    mflr    r0
    stw     r0,4(r1)
    stwu    r1,-8(r1)
    lwz     r3,-23528(r13)
    bl SISetSamplingRate
    lwz     r0,12(r1)
    addi    r1,r1,8
    mtlr    r0
    blr
.size SIRefreshSamplingRate, . - SIRefreshSamplingRate

#
# === dvd.a(dvdfs.o) ===
#

.global __DVDFSInit
.balign 4
__DVDFSInit:
/* 0x8025B098 | size=0x38 (56 bytes) */
    lis     r3,-32768
    stw     r3,-23512(r13)
    lwz     r0,56(r3)
    stw     r0,-23508(r13)
    lwz     r3,-23508(r13)
    cmplwi  r3,0
    beqlr-
    lwz     r0,8(r3)
    stw     r0,-23500(r13)
    lwz     r0,-23500(r13)
    mulli   r0,r0,12
    add     r0,r3,r0
    stw     r0,-23504(r13)
    blr
.size __DVDFSInit, . - __DVDFSInit

.global DVDClose
.balign 4
DVDClose:
/* 0x8025B5A0 | size=0x24 (36 bytes) */
    mflr    r0
    stw     r0,4(r1)
    stwu    r1,-8(r1)
    bl DVDCancel
    li      r3,1
    lwz     r0,12(r1)
    addi    r1,r1,8
    mtlr    r0
    blr
.size DVDClose, . - DVDClose

.global myStrncpy
.balign 4
myStrncpy:
/* 0x8025B5C4 | size=0x38 (56 bytes) */
    mr      r6,r5
    b .L_8025B5E0
.L_8025B5CC:
    lbz     r0,0(r4)
    addi    r4,r4,1
    addi    r6,r6,-1
    stb     r0,0(r3)
    addi    r3,r3,1
.L_8025B5E0:
    cmplwi  r6,0
    beq- .L_8025B5F4
    lbz     r0,0(r4)
    extsb.  r0,r0
    bne+ .L_8025B5CC
.L_8025B5F4:
    subf    r3,r6,r5
    blr
.size myStrncpy, . - myStrncpy

.global cbForReadAsync
.balign 4
cbForReadAsync:
/* 0x8025BA94 | size=0x30 (48 bytes) */
    mflr    r0
    stw     r0,4(r1)
    stwu    r1,-8(r1)
    lwz     r12,56(r4)
    cmplwi  r12,0
    beq- .L_8025BAB4
    mtlr    r12
    blrl
.L_8025BAB4:
    lwz     r0,12(r1)
    addi    r1,r1,8
    mtlr    r0
    blr
.size cbForReadAsync, . - cbForReadAsync

.global cbForReadSync
.balign 4
cbForReadSync:
/* 0x8025BBDC | size=0x24 (36 bytes) */
    mflr    r0
    addi    r3,r13,-23488
    stw     r0,4(r1)
    stwu    r1,-8(r1)
    bl OSWakeupThread
    lwz     r0,12(r1)
    addi    r1,r1,8
    mtlr    r0
    blr
.size cbForReadSync, . - cbForReadSync

.global cbForSeekAsync
.balign 4
cbForSeekAsync:
/* 0x8025BC98 | size=0x30 (48 bytes) */
    mflr    r0
    stw     r0,4(r1)
    stwu    r1,-8(r1)
    lwz     r12,56(r4)
    cmplwi  r12,0
    beq- .L_8025BCB8
    mtlr    r12
    blrl
.L_8025BCB8:
    lwz     r0,12(r1)
    addi    r1,r1,8
    mtlr    r0
    blr
.size cbForSeekAsync, . - cbForSeekAsync

.global cbForSeekSync
.balign 4
cbForSeekSync:
/* 0x8025BD74 | size=0x24 (36 bytes) */
    mflr    r0
    addi    r3,r13,-23488
    stw     r0,4(r1)
    stwu    r1,-8(r1)
    bl OSWakeupThread
    lwz     r0,12(r1)
    addi    r1,r1,8
    mtlr    r0
    blr
.size cbForSeekSync, . - cbForSeekSync

.global DVDGetFileInfoStatus
.balign 4
DVDGetFileInfoStatus:
/* 0x8025BD98 | size=0x20 (32 bytes) */
    mflr    r0
    stw     r0,4(r1)
    stwu    r1,-8(r1)
    bl DVDGetCommandBlockStatus
    lwz     r0,12(r1)
    addi    r1,r1,8
    mtlr    r0
    blr
.size DVDGetFileInfoStatus, . - DVDGetFileInfoStatus

.global DVDCloseDir
.balign 4
DVDCloseDir:
/* 0x8025BF84 | size=0x08 (8 bytes) */
    li      r3,1
    blr
.size DVDCloseDir, . - DVDCloseDir

.global DVDRewindDir
.balign 4
DVDRewindDir:
/* 0x8025BF8C | size=0x10 (16 bytes) */
    lwz     r4,0(r3)
    addi    r0,r4,1
    stw     r0,4(r3)
    blr
.size DVDRewindDir, . - DVDRewindDir

.global DVDGetFSTLocation
.balign 4
DVDGetFSTLocation:
/* 0x8025BF9C | size=0x0C (12 bytes) */
    lwz     r3,-23512(r13)
    lwz     r3,56(r3)
    blr
.size DVDGetFSTLocation, . - DVDGetFSTLocation

.global cbForPrepareStreamAsync
.balign 4
cbForPrepareStreamAsync:
/* 0x8025C094 | size=0x30 (48 bytes) */
    mflr    r0
    stw     r0,4(r1)
    stwu    r1,-8(r1)
    lwz     r12,56(r4)
    cmplwi  r12,0
    beq- .L_8025C0B4
    mtlr    r12
    blrl
.L_8025C0B4:
    lwz     r0,12(r1)
    addi    r1,r1,8
    mtlr    r0
    blr
.size cbForPrepareStreamAsync, . - cbForPrepareStreamAsync

.global cbForPrepareStreamSync
.balign 4
cbForPrepareStreamSync:
/* 0x8025C208 | size=0x24 (36 bytes) */
    mflr    r0
    addi    r3,r13,-23488
    stw     r0,4(r1)
    stwu    r1,-8(r1)
    bl OSWakeupThread
    lwz     r0,12(r1)
    addi    r1,r1,8
    mtlr    r0
    blr
.size cbForPrepareStreamSync, . - cbForPrepareStreamSync

#
# === dvd.a(dvd.o) ===
#

.global defaultOptionalCommandChecker
.balign 4
defaultOptionalCommandChecker:
/* 0x8025C298 | size=0x04 (4 bytes) */
    blr
.size defaultOptionalCommandChecker, . - defaultOptionalCommandChecker

.global __DVDSetOptionalCommandChecker
.balign 4
__DVDSetOptionalCommandChecker:
/* 0x8025C29C | size=0x08 (8 bytes) */
    stw     r3,-27784(r13)
    blr
.size __DVDSetOptionalCommandChecker, . - __DVDSetOptionalCommandChecker

.global stateError
.balign 4
stateError:
/* 0x8025C53C | size=0x2C (44 bytes) */
    mflr    r0
    stw     r0,4(r1)
    stwu    r1,-8(r1)
    bl __DVDStoreErrorCode
    lis     r3,-32730
    addi    r3,r3,-15216
    bl DVDLowStopMotor
    lwz     r0,12(r1)
    addi    r1,r1,8
    mtlr    r0
    blr
.size stateError, . - stateError

.global stateTimeout
.balign 4
stateTimeout:
/* 0x8025C568 | size=0x34 (52 bytes) */
    mflr    r0
    lis     r3,291
    stw     r0,4(r1)
    addi    r3,r3,17768
    stwu    r1,-8(r1)
    bl __DVDStoreErrorCode
    bl DVDReset
    li      r3,0
    bl cbForStateError
    lwz     r0,12(r1)
    addi    r1,r1,8
    mtlr    r0
    blr
.size stateTimeout, . - stateTimeout

.global stateGettingError
.balign 4
stateGettingError:
/* 0x8025C59C | size=0x28 (40 bytes) */
    mflr    r0
    lis     r3,-32730
    stw     r0,4(r1)
    addi    r3,r3,-14572
    stwu    r1,-8(r1)
    bl DVDLowRequestError
    lwz     r0,12(r1)
    addi    r1,r1,8
    mtlr    r0
    blr
.size stateGettingError, . - stateGettingError

.global stateGoToRetry
.balign 4
stateGoToRetry:
/* 0x8025CA54 | size=0x28 (40 bytes) */
    mflr    r0
    lis     r3,-32730
    stw     r0,4(r1)
    addi    r3,r3,-13700
    stwu    r1,-8(r1)
    bl DVDLowStopMotor
    lwz     r0,12(r1)
    addi    r1,r1,8
    mtlr    r0
    blr
.size stateGoToRetry, . - stateGoToRetry

.global stateCheckID3
.balign 4
stateCheckID3:
/* 0x8025CC9C | size=0x34 (52 bytes) */
    mflr    r0
    lis     r3,-32730
    stw     r0,4(r1)
    addi    r5,r3,-12424
    stwu    r1,-8(r1)
    lwz     r4,-23476(r13)
    lbz     r3,8(r4)
    li      r4,10
    bl DVDLowAudioBufferConfig
    lwz     r0,12(r1)
    addi    r1,r1,8
    mtlr    r0
    blr
.size stateCheckID3, . - stateCheckID3

.global stateCheckID2a
.balign 4
stateCheckID2a:
/* 0x8025CCD0 | size=0x34 (52 bytes) */
    mflr    r0
    lis     r3,-32730
    stw     r0,4(r1)
    addi    r5,r3,-13052
    stwu    r1,-8(r1)
    lwz     r4,-23476(r13)
    lbz     r3,8(r4)
    li      r4,10
    bl DVDLowAudioBufferConfig
    lwz     r0,12(r1)
    addi    r1,r1,8
    mtlr    r0
    blr
.size stateCheckID2a, . - stateCheckID2a

.global stateCheckID2
.balign 4
stateCheckID2:
/* 0x8025CD6C | size=0x38 (56 bytes) */
    mflr    r0
    lis     r3,-32694
    stw     r0,4(r1)
    lis     r4,-32730
    addi    r6,r4,-12640
    stwu    r1,-8(r1)
    addi    r3,r3,-17248
    li      r4,32
    li      r5,1056
    bl DVDLowRead
    lwz     r0,12(r1)
    addi    r1,r1,8
    mtlr    r0
    blr
.size stateCheckID2, . - stateCheckID2

.global stateCoverClosed_CMD
.balign 4
stateCoverClosed_CMD:
/* 0x8025D180 | size=0x30 (48 bytes) */
    mflr    r0
    lis     r3,-32694
    stw     r0,4(r1)
    lis     r4,-32730
    addi    r3,r3,-17216
    stwu    r1,-8(r1)
    addi    r4,r4,-11856
    bl DVDLowReadDiskID
    lwz     r0,12(r1)
    addi    r1,r1,8
    mtlr    r0
    blr
.size stateCoverClosed_CMD, . - stateCoverClosed_CMD

.global stateMotorStopped
.balign 4
stateMotorStopped:
/* 0x8025D214 | size=0x28 (40 bytes) */
    mflr    r0
    lis     r3,-32730
    stw     r0,4(r1)
    addi    r3,r3,-11716
    stwu    r1,-8(r1)
    bl DVDLowWaitCoverClose
    lwz     r0,12(r1)
    addi    r1,r1,8
    mtlr    r0
    blr
.size stateMotorStopped, . - stateMotorStopped

.global __DVDSetImmCommand
.balign 4
__DVDSetImmCommand:
/* 0x8025D950 | size=0x24 (36 bytes) */
    lwz     r6,-23400(r13)
    lis     r4,-32700
    addi    r0,r4,-14372
    addi    r5,r6,1
    slwi    r4,r6,2
    stw     r5,-23400(r13)
    add     r4,r0,r4
    stw     r3,0(r4)
    blr
.size __DVDSetImmCommand, . - __DVDSetImmCommand

.global __DVDSetDmaCommand
.balign 4
__DVDSetDmaCommand:
/* 0x8025D974 | size=0x1C (28 bytes) */
    lwz     r5,-23396(r13)
    addi    r4,r13,-27772
    addi    r0,r5,1
    stw     r0,-23396(r13)
    slwi    r0,r5,2
    stwx    r3,r4,r0
    blr
.size __DVDSetDmaCommand, . - __DVDSetDmaCommand

.global IsDmaCommand
.balign 4
IsDmaCommand:
/* 0x8025D9EC | size=0x40 (64 bytes) */
    cmplwi  r3,1
    beq- .L_8025DA08
    addi    r0,r3,-4
    cmplwi  r0,1
    ble- .L_8025DA08
    cmplwi  r3,14
    bne- .L_8025DA10
.L_8025DA08:
    li      r3,1
    blr
.L_8025DA10:
    lwz     r0,-27772(r13)
    cmplw   r3,r0
    bne- .L_8025DA24
    li      r3,1
    blr
.L_8025DA24:
    li      r3,0
    blr
.size IsDmaCommand, . - IsDmaCommand

.global __DVDGetIssueCommandAddr
.balign 4
__DVDGetIssueCommandAddr:
/* 0x8025E084 | size=0x0C (12 bytes) */
    lis     r3,-32730
    addi    r3,r3,-8048
    blr
.size __DVDGetIssueCommandAddr, . - __DVDGetIssueCommandAddr

.global cbForCancelStreamSync
.balign 4
cbForCancelStreamSync:
/* 0x8025E6B8 | size=0x28 (40 bytes) */
    mflr    r0
    stw     r0,4(r1)
    stwu    r1,-8(r1)
    stw     r3,32(r4)
    addi    r3,r13,-23488
    bl OSWakeupThread
    lwz     r0,12(r1)
    addi    r1,r1,8
    mtlr    r0
    blr
.size cbForCancelStreamSync, . - cbForCancelStreamSync

.global cbForStopStreamAtEndSync
.balign 4
cbForStopStreamAtEndSync:
/* 0x8025E83C | size=0x28 (40 bytes) */
    mflr    r0
    stw     r0,4(r1)
    stwu    r1,-8(r1)
    stw     r3,32(r4)
    addi    r3,r13,-23488
    bl OSWakeupThread
    lwz     r0,12(r1)
    addi    r1,r1,8
    mtlr    r0
    blr
.size cbForStopStreamAtEndSync, . - cbForStopStreamAtEndSync

.global cbForGetStreamErrorStatusSync
.balign 4
cbForGetStreamErrorStatusSync:
/* 0x8025E9C0 | size=0x28 (40 bytes) */
    mflr    r0
    stw     r0,4(r1)
    stwu    r1,-8(r1)
    stw     r3,32(r4)
    addi    r3,r13,-23488
    bl OSWakeupThread
    lwz     r0,12(r1)
    addi    r1,r1,8
    mtlr    r0
    blr
.size cbForGetStreamErrorStatusSync, . - cbForGetStreamErrorStatusSync

.global cbForGetStreamPlayAddrSync
.balign 4
cbForGetStreamPlayAddrSync:
/* 0x8025EB44 | size=0x28 (40 bytes) */
    mflr    r0
    stw     r0,4(r1)
    stwu    r1,-8(r1)
    stw     r3,32(r4)
    addi    r3,r13,-23488
    bl OSWakeupThread
    lwz     r0,12(r1)
    addi    r1,r1,8
    mtlr    r0
    blr
.size cbForGetStreamPlayAddrSync, . - cbForGetStreamPlayAddrSync

.global cbForGetStreamStartAddrSync
.balign 4
cbForGetStreamStartAddrSync:
/* 0x8025ECC8 | size=0x28 (40 bytes) */
    mflr    r0
    stw     r0,4(r1)
    stwu    r1,-8(r1)
    stw     r3,32(r4)
    addi    r3,r13,-23488
    bl OSWakeupThread
    lwz     r0,12(r1)
    addi    r1,r1,8
    mtlr    r0
    blr
.size cbForGetStreamStartAddrSync, . - cbForGetStreamStartAddrSync

.global cbForGetStreamLengthSync
.balign 4
cbForGetStreamLengthSync:
/* 0x8025EE4C | size=0x28 (40 bytes) */
    mflr    r0
    stw     r0,4(r1)
    stwu    r1,-8(r1)
    stw     r3,32(r4)
    addi    r3,r13,-23488
    bl OSWakeupThread
    lwz     r0,12(r1)
    addi    r1,r1,8
    mtlr    r0
    blr
.size cbForGetStreamLengthSync, . - cbForGetStreamLengthSync

.global cbForChangeDiskSync
.balign 4
cbForChangeDiskSync:
/* 0x8025F200 | size=0x24 (36 bytes) */
    mflr    r0
    addi    r3,r13,-23488
    stw     r0,4(r1)
    stwu    r1,-8(r1)
    bl OSWakeupThread
    lwz     r0,12(r1)
    addi    r1,r1,8
    mtlr    r0
    blr
.size cbForChangeDiskSync, . - cbForChangeDiskSync

.global cbForStopMotorSync
.balign 4
cbForStopMotorSync:
/* 0x8025F394 | size=0x24 (36 bytes) */
    mflr    r0
    addi    r3,r13,-23488
    stw     r0,4(r1)
    stwu    r1,-8(r1)
    bl OSWakeupThread
    lwz     r0,12(r1)
    addi    r1,r1,8
    mtlr    r0
    blr
.size cbForStopMotorSync, . - cbForStopMotorSync

.global cbForInquirySync
.balign 4
cbForInquirySync:
/* 0x8025F550 | size=0x24 (36 bytes) */
    mflr    r0
    addi    r3,r13,-23488
    stw     r0,4(r1)
    stwu    r1,-8(r1)
    bl OSWakeupThread
    lwz     r0,12(r1)
    addi    r1,r1,8
    mtlr    r0
    blr
.size cbForInquirySync, . - cbForInquirySync

.global DVDResetRequired
.balign 4
DVDResetRequired:
/* 0x8025F5B8 | size=0x08 (8 bytes) */
    lwz     r3,-23424(r13)
    blr
.size DVDResetRequired, . - DVDResetRequired

.global DVDSetAutoInvalidation
.balign 4
DVDSetAutoInvalidation:
/* 0x8025F6B8 | size=0x10 (16 bytes) */
    lwz     r0,-27788(r13)
    stw     r3,-27788(r13)
    mr      r3,r0
    blr
.size DVDSetAutoInvalidation, . - DVDSetAutoInvalidation

.global DVDPause
.balign 4
DVDPause:
/* 0x8025F6C8 | size=0x3C (60 bytes) */
    mflr    r0
    stw     r0,4(r1)
    stwu    r1,-8(r1)
    bl OSDisableInterrupts
    lwz     r0,-23480(r13)
    li      r4,1
    stw     r4,-23468(r13)
    cmplwi  r0,0
    bne- .L_8025F6F0
    stw     r4,-23464(r13)
.L_8025F6F0:
    bl OSRestoreInterrupts
    lwz     r0,12(r1)
    addi    r1,r1,8
    mtlr    r0
    blr
.size DVDPause, . - DVDPause

.global cbForCancelSync
.balign 4
cbForCancelSync:
/* 0x8025FA7C | size=0x24 (36 bytes) */
    mflr    r0
    addi    r3,r13,-23488
    stw     r0,4(r1)
    stwu    r1,-8(r1)
    bl OSWakeupThread
    lwz     r0,12(r1)
    addi    r1,r1,8
    mtlr    r0
    blr
.size cbForCancelSync, . - cbForCancelSync

.global cbForCancelAllSync
.balign 4
cbForCancelAllSync:
/* 0x8025FCC4 | size=0x2C (44 bytes) */
    mflr    r0
    addi    r3,r13,-23488
    stw     r0,4(r1)
    li      r0,1
    stwu    r1,-8(r1)
    stw     r0,-23420(r13)
    bl OSWakeupThread
    lwz     r0,12(r1)
    addi    r1,r1,8
    mtlr    r0
    blr
.size cbForCancelAllSync, . - cbForCancelAllSync

.global DVDGetCurrentDiskID
.balign 4
DVDGetCurrentDiskID:
/* 0x8025FCF0 | size=0x08 (8 bytes) */
    lis     r3,-32768
    blr
.size DVDGetCurrentDiskID, . - DVDGetCurrentDiskID

.global __DVDTestAlarm
.balign 4
__DVDTestAlarm:
/* 0x8025FF0C | size=0x38 (56 bytes) */
    mflr    r0
    lis     r4,-32694
    stw     r0,4(r1)
    addi    r0,r4,-17136
    cmplw   r3,r0
    stwu    r1,-8(r1)
    bne- .L_8025FF30
    li      r3,1
    b .L_8025FF34
.L_8025FF30:
    bl __DVDLowTestAlarm
.L_8025FF34:
    lwz     r0,12(r1)
    addi    r1,r1,8
    mtlr    r0
    blr
.size __DVDTestAlarm, . - __DVDTestAlarm

#
# === dvd.a(dvdqueue.o) ===
#

.global __DVDClearWaitingQueue
.balign 4
__DVDClearWaitingQueue:
/* 0x8025FF44 | size=0x38 (56 bytes) */
    lis     r3,-32694
    addi    r3,r3,-17096
    stw     r3,0(r3)
    addi    r5,r3,8
    addi    r4,r3,16
    stw     r3,4(r3)
    addi    r3,r3,24
    stw     r5,0(r5)
    stw     r5,4(r5)
    stw     r4,0(r4)
    stw     r4,4(r4)
    stw     r3,0(r3)
    stw     r3,4(r3)
    blr
.size __DVDClearWaitingQueue, . - __DVDClearWaitingQueue

#
# === dvd.a(dvdidutils.o) ===
#

.global strnlen
.balign 4
strnlen:
/* 0x80260670 | size=0x38 (56 bytes) */
    cmplwi  r4,0
    mtctr   r4
    li      r5,0
    ble- .L_802606A0
.L_80260680:
    lbz     r0,0(r3)
    addi    r3,r3,1
    extsb.  r0,r0
    bne- .L_80260698
    mr      r3,r5
    blr
.L_80260698:
    addi    r5,r5,1
    bdnz+ .L_80260680
.L_802606A0:
    mr      r3,r4
    blr
.size strnlen, . - strnlen

#
# === dvd.a(dvdFatal.o) ===
#

.global __DVDPrintFatalMessage
.balign 4
__DVDPrintFatalMessage:
/* 0x8026091C | size=0x30 (48 bytes) */
    mflr    r0
    stw     r0,4(r1)
    stwu    r1,-8(r1)
    lwz     r12,-23384(r13)
    cmplwi  r12,0
    beq- .L_8026093C
    mtlr    r12
    blrl
.L_8026093C:
    lwz     r0,12(r1)
    addi    r1,r1,8
    mtlr    r0
    blr
.size __DVDPrintFatalMessage, . - __DVDPrintFatalMessage

#
# === dvd.a(dvdlow.o) ===
#

.global __DVDInitWA
.balign 4
__DVDInitWA:
/* 0x80260B8C | size=0x40 (64 bytes) */
    mflr    r0
    lis     r3,-32694
    stw     r0,4(r1)
    li      r0,0
    li      r4,0
    stwu    r1,-8(r1)
    stw     r0,-23292(r13)
    li      r0,-1
    stw     r0,-16952(r3)
    li      r3,0
    bl __DVDLowSetWAType
    bl OSInitAlarm
    lwz     r0,12(r1)
    addi    r1,r1,8
    mtlr    r0
    blr
.size __DVDInitWA, . - __DVDInitWA

.global AudioBufferOn
.balign 4
AudioBufferOn:
/* 0x802611A8 | size=0x38 (56 bytes) */
    mflr    r0
    stw     r0,4(r1)
    stwu    r1,-8(r1)
    bl DVDGetCurrentDiskID
    lbz     r0,8(r3)
    cmplwi  r0,0
    beq- .L_802611CC
    li      r3,1
    b .L_802611D0
.L_802611CC:
    li      r3,0
.L_802611D0:
    lwz     r0,12(r1)
    addi    r1,r1,8
    mtlr    r0
    blr
.size AudioBufferOn, . - AudioBufferOn

.global DoJustRead
.balign 4
DoJustRead:
/* 0x80261280 | size=0x34 (52 bytes) */
    mflr    r0
    lis     r7,-32694
    stw     r0,4(r1)
    li      r0,-1
    stwu    r1,-8(r1)
    stw     r0,-16952(r7)
    li      r0,0
    stw     r0,-23292(r13)
    bl Read
    lwz     r0,12(r1)
    addi    r1,r1,8
    mtlr    r0
    blr
.size DoJustRead, . - DoJustRead

.global DVDLowWaitCoverClose
.balign 4
DVDLowWaitCoverClose:
/* 0x802616EC | size=0x2C (44 bytes) */
    li      r0,1
    stw     r3,-23352(r13)
    lis     r3,-13312
    stw     r0,-23332(r13)
    li      r0,0
    addi    r4,r3,24576
    stw     r0,-23360(r13)
    li      r0,2
    li      r3,1
    stw     r0,4(r4)
    blr
.size DVDLowWaitCoverClose, . - DVDLowWaitCoverClose

.global DoBreak
.balign 4
DoBreak:
/* 0x80261C30 | size=0x1C (28 bytes) */
    lis     r3,-13312
    lwz     r4,24576(r3)
    li      r0,1
    ori     r4,r4,65
    stw     r4,24576(r3)
    stw     r0,-23328(r13)
    blr
.size DoBreak, . - DoBreak

.global DVDLowBreak
.balign 4
DVDLowBreak:
/* 0x80261D24 | size=0x14 (20 bytes) */
    li      r0,1
    stw     r0,-23360(r13)
    li      r3,1
    stw     r0,-23328(r13)
    blr
.size DVDLowBreak, . - DVDLowBreak

.global DVDLowClearCallback
.balign 4
DVDLowClearCallback:
/* 0x80261D38 | size=0x1C (28 bytes) */
    lis     r3,-13312
    li      r0,0
    stw     r0,24580(r3)
    lwz     r3,-23352(r13)
    stw     r0,-23332(r13)
    stw     r0,-23352(r13)
    blr
.size DVDLowClearCallback, . - DVDLowClearCallback

.global __DVDLowTestAlarm
.balign 4
__DVDLowTestAlarm:
/* 0x80261E2C | size=0x38 (56 bytes) */
    lis     r4,-32694
    addi    r0,r4,-16808
    cmplw   r3,r0
    bne- .L_80261E44
    li      r3,1
    blr
.L_80261E44:
    lis     r4,-32694
    addi    r0,r4,-16848
    cmplw   r3,r0
    bne- .L_80261E5C
    li      r3,1
    blr
.L_80261E5C:
    li      r3,0
    blr
.size __DVDLowTestAlarm, . - __DVDLowTestAlarm

#
# === vi.a(vi.o) ===
#

.global getEncoderType
.balign 4
getEncoderType:
/* 0x80261E64 | size=0x08 (8 bytes) */
    li      r3,1
    blr
.size getEncoderType, . - getEncoderType

.global __VISetExtraTiming
.balign 4
__VISetExtraTiming:
/* 0x802622E4 | size=0x10 (16 bytes) */
    lwz     r0,-23196(r13)
    stw     r3,-23196(r13)
    mr      r3,r0
    blr
.size __VISetExtraTiming, . - __VISetExtraTiming

.global ImportAdjustingValues
.balign 4
ImportAdjustingValues:
/* 0x80262700 | size=0x3C (60 bytes) */
    mflr    r0
    stw     r0,4(r1)
    stwu    r1,-8(r1)
    bl __OSLockSram
    lbz     r4,16(r3)
    li      r0,0
    li      r3,0
    extsb   r4,r4
    sth     r0,-23250(r13)
    sth     r4,-23252(r13)
    bl __OSUnlockSram
    lwz     r0,12(r1)
    addi    r1,r1,8
    mtlr    r0
    blr
.size ImportAdjustingValues, . - ImportAdjustingValues

.global VIGetNextFrameBuffer
.balign 4
VIGetNextFrameBuffer:
/* 0x80264238 | size=0x08 (8 bytes) */
    lwz     r3,-23208(r13)
    blr
.size VIGetNextFrameBuffer, . - VIGetNextFrameBuffer

.global VIGetCurrentFrameBuffer
.balign 4
VIGetCurrentFrameBuffer:
/* 0x80264240 | size=0x08 (8 bytes) */
    lwz     r3,-23204(r13)
    blr
.size VIGetCurrentFrameBuffer, . - VIGetCurrentFrameBuffer

.global VIGetRetraceCount
.balign 4
VIGetRetraceCount:
/* 0x80264430 | size=0x08 (8 bytes) */
    lwz     r3,-23284(r13)
    blr
.size VIGetRetraceCount, . - VIGetRetraceCount

.global GetCurrentDisplayPosition
.balign 4
GetCurrentDisplayPosition:
/* 0x80264438 | size=0x3C (60 bytes) */
    lis     r5,-13312
    addi    r7,r5,8192
    lhzu    r0,44(r7)
    addi    r6,r5,8192
    clrlwi  r9,r0,21
.L_8026444C:
    lhz     r0,0(r7)
    mr      r8,r9
    lhz     r5,46(r6)
    clrlwi  r9,r0,21
    cmplw   r8,r9
    clrlwi  r0,r5,21
    bne+ .L_8026444C
    stw     r0,0(r3)
    stw     r9,0(r4)
    blr
.size GetCurrentDisplayPosition, . - GetCurrentDisplayPosition

.global VIGetDTVStatus
.balign 4
VIGetDTVStatus:
/* 0x80264730 | size=0x3C (60 bytes) */
    mflr    r0
    stw     r0,4(r1)
    stwu    r1,-16(r1)
    stw     r31,12(r1)
    bl OSDisableInterrupts
    lis     r4,-13312
    lhz     r0,8302(r4)
    clrlwi  r31,r0,30
    bl OSRestoreInterrupts
    clrlwi  r3,r31,31
    lwz     r0,20(r1)
    lwz     r31,12(r1)
    addi    r1,r1,16
    mtlr    r0
    blr
.size VIGetDTVStatus, . - VIGetDTVStatus

.global __VISetLatchMode
.balign 4
__VISetLatchMode:
/* 0x80264EC8 | size=0x2C (44 bytes) */
    lis     r4,-13312
    lhz     r6,8194(r4)
    addi    r5,r4,8192
    slwi    r4,r3,4
    slwi    r0,r3,6
    rlwinm  r3,r6,0,28,25
    or      r3,r3,r4
    rlwinm  r3,r3,0,26,23
    or      r0,r3,r0
    sth     r0,2(r5)
    blr
.size __VISetLatchMode, . - __VISetLatchMode

.global __VIGetLatchPosition
.balign 4
__VIGetLatchPosition:
/* 0x80264FDC | size=0x40 (64 bytes) */
    mflr    r0
    cmplwi  r3,0
    stw     r0,4(r1)
    stwu    r1,-8(r1)
    bne- .L_80265000
    addi    r3,r4,0
    addi    r4,r5,0
    bl __VIGetLatch0Position
    b .L_8026500C
.L_80265000:
    addi    r3,r4,0
    addi    r4,r5,0
    bl __VIGetLatch1Position
.L_8026500C:
    lwz     r0,12(r1)
    addi    r1,r1,8
    mtlr    r0
    blr
.size __VIGetLatchPosition, . - __VIGetLatchPosition

#
# === pad.a(Pad.o) ===
#

.global PADSetSamplingRate
.balign 4
PADSetSamplingRate:
/* 0x8026607C | size=0x20 (32 bytes) */
    mflr    r0
    stw     r0,4(r1)
    stwu    r1,-8(r1)
    bl SISetSamplingRate
    lwz     r0,12(r1)
    addi    r1,r1,8
    mtlr    r0
    blr
.size PADSetSamplingRate, . - PADSetSamplingRate

.global PADGetSpec
.balign 4
PADGetSpec:
/* 0x80266280 | size=0x08 (8 bytes) */
    lwz     r3,-27640(r13)
    blr
.size PADGetSpec, . - PADGetSpec

.global ClampU8
.balign 4
ClampU8:
/* 0x802665C4 | size=0x1C (28 bytes) */
    clrlwi  r5,r3,24
    clrlwi  r0,r4,24
    cmplw   r5,r0
    bge- .L_802665D8
    mr      r3,r4
.L_802665D8:
    subf    r3,r4,r3
    blr
.size ClampU8, . - ClampU8

.global __PADDisableXPatch
.balign 4
__PADDisableXPatch:
/* 0x80266C58 | size=0x0C (12 bytes) */
    li      r0,0
    stw     r0,-27648(r13)
    blr
.size __PADDisableXPatch, . - __PADDisableXPatch

.global PADIsBarrel
.balign 4
PADIsBarrel:
/* 0x80266E10 | size=0x3C (60 bytes) */
    cmpwi   r3,0
    blt- .L_80266E20
    cmpwi   r3,4
    blt- .L_80266E28
.L_80266E20:
    li      r3,0
    blr
.L_80266E28:
    lis     r0,-32768
    lwz     r4,-23156(r13)
    srw     r0,r0,r3
    and.    r0,r4,r0
    beq- .L_80266E44
    li      r3,1
    blr
.L_80266E44:
    li      r3,0
    blr
.size PADIsBarrel, . - PADIsBarrel

#
# === ai.a(ai.o) ===
#

.global AIGetDMAEnableFlag
.balign 4
AIGetDMAEnableFlag:
/* 0x80266F18 | size=0x10 (16 bytes) */
    lis     r3,-13312
    lhz     r0,20534(r3)
    rlwinm  r3,r0,17,31,31
    blr
.size AIGetDMAEnableFlag, . - AIGetDMAEnableFlag

.global AIStartDMA
.balign 4
AIStartDMA:
/* 0x80266F28 | size=0x18 (24 bytes) */
    lis     r3,-13312
    addi    r3,r3,20480
    lhz     r0,54(r3)
    ori     r0,r0,32768
    sth     r0,54(r3)
    blr
.size AIStartDMA, . - AIStartDMA

.global AIStopDMA
.balign 4
AIStopDMA:
/* 0x80266F40 | size=0x18 (24 bytes) */
    lis     r3,-13312
    addi    r3,r3,20480
    lhz     r0,54(r3)
    rlwinm  r0,r0,0,17,15
    sth     r0,54(r3)
    blr
.size AIStopDMA, . - AIStopDMA

.global AIGetDMABytesLeft
.balign 4
AIGetDMABytesLeft:
/* 0x80266F58 | size=0x10 (16 bytes) */
    lis     r3,-13312
    lhz     r0,20538(r3)
    rlwinm  r3,r0,5,12,26
    blr
.size AIGetDMABytesLeft, . - AIGetDMABytesLeft

.global AIGetDMAStartAddr
.balign 4
AIGetDMAStartAddr:
/* 0x80266F68 | size=0x1C (28 bytes) */
    lis     r3,-13312
    addi    r3,r3,20480
    lhz     r4,48(r3)
    lhz     r0,50(r3)
    rlwinm  r3,r0,0,16,26
    rlwimi  r3,r4,16,6,15
    blr
.size AIGetDMAStartAddr, . - AIGetDMAStartAddr

.global AIGetDMALength
.balign 4
AIGetDMALength:
/* 0x80266F84 | size=0x10 (16 bytes) */
    lis     r3,-13312
    lhz     r0,20534(r3)
    rlwinm  r3,r0,5,12,26
    blr
.size AIGetDMALength, . - AIGetDMALength

.global AICheckInit
.balign 4
AICheckInit:
/* 0x80266F94 | size=0x08 (8 bytes) */
    lwz     r3,-23120(r13)
    blr
.size AICheckInit, . - AICheckInit

.global AIGetStreamSampleCount
.balign 4
AIGetStreamSampleCount:
/* 0x80266FE0 | size=0x10 (16 bytes) */
    lis     r3,-13312
    addi    r3,r3,27648
    lwz     r3,8(r3)
    blr
.size AIGetStreamSampleCount, . - AIGetStreamSampleCount

.global AIResetStreamSampleCount
.balign 4
AIResetStreamSampleCount:
/* 0x80266FF0 | size=0x18 (24 bytes) */
    lis     r3,-13312
    lwz     r0,27648(r3)
    rlwinm  r0,r0,0,27,25
    ori     r0,r0,32
    stw     r0,27648(r3)
    blr
.size AIResetStreamSampleCount, . - AIResetStreamSampleCount

.global AISetStreamTrigger
.balign 4
AISetStreamTrigger:
/* 0x80267008 | size=0x0C (12 bytes) */
    lis     r4,-13312
    stw     r3,27660(r4)
    blr
.size AISetStreamTrigger, . - AISetStreamTrigger

.global AIGetStreamTrigger
.balign 4
AIGetStreamTrigger:
/* 0x80267014 | size=0x10 (16 bytes) */
    lis     r3,-13312
    addi    r3,r3,27648
    lwz     r3,12(r3)
    blr
.size AIGetStreamTrigger, . - AIGetStreamTrigger

.global AIGetStreamPlayState
.balign 4
AIGetStreamPlayState:
/* 0x802670FC | size=0x10 (16 bytes) */
    lis     r3,-13312
    lwz     r0,27648(r3)
    clrlwi  r3,r0,31
    blr
.size AIGetStreamPlayState, . - AIGetStreamPlayState

.global AIGetDSPSampleRate
.balign 4
AIGetDSPSampleRate:
/* 0x802671EC | size=0x14 (20 bytes) */
    lis     r3,-13312
    lwz     r0,27648(r3)
    rlwinm  r0,r0,26,31,31
    xori    r3,r0,1
    blr
.size AIGetDSPSampleRate, . - AIGetDSPSampleRate

.global AISetStreamSampleRate
.balign 4
AISetStreamSampleRate:
/* 0x80267200 | size=0x28 (40 bytes) */
    mflr    r0
    cmplwi  r3,1
    stw     r0,4(r1)
    stwu    r1,-8(r1)
    bne- .L_80267218
    bl __AI_set_stream_sample_rate
.L_80267218:
    lwz     r0,12(r1)
    addi    r1,r1,8
    mtlr    r0
    blr
.size AISetStreamSampleRate, . - AISetStreamSampleRate

.global __AI_DEBUG_set_stream_sample_rate
.balign 4
__AI_DEBUG_set_stream_sample_rate:
/* 0x80267228 | size=0x20 (32 bytes) */
    mflr    r0
    stw     r0,4(r1)
    stwu    r1,-8(r1)
    bl __AI_set_stream_sample_rate
    lwz     r0,12(r1)
    addi    r1,r1,8
    mtlr    r0
    blr
.size __AI_DEBUG_set_stream_sample_rate, . - __AI_DEBUG_set_stream_sample_rate

.global AIGetStreamSampleRate
.balign 4
AIGetStreamSampleRate:
/* 0x8026731C | size=0x10 (16 bytes) */
    lis     r3,-13312
    lwz     r0,27648(r3)
    rlwinm  r3,r0,31,31,31
    blr
.size AIGetStreamSampleRate, . - AIGetStreamSampleRate

.global AISetStreamVolLeft
.balign 4
AISetStreamVolLeft:
/* 0x8026732C | size=0x1C (28 bytes) */
    lis     r4,-13312
    addi    r4,r4,27648
    lwz     r0,4(r4)
    clrrwi  r0,r0,8
    rlwimi  r0,r3,0,24,31
    stw     r0,4(r4)
    blr
.size AISetStreamVolLeft, . - AISetStreamVolLeft

.global AIGetStreamVolLeft
.balign 4
AIGetStreamVolLeft:
/* 0x80267348 | size=0x10 (16 bytes) */
    lis     r3,-13312
    lwz     r0,27652(r3)
    clrlwi  r3,r0,24
    blr
.size AIGetStreamVolLeft, . - AIGetStreamVolLeft

.global AISetStreamVolRight
.balign 4
AISetStreamVolRight:
/* 0x80267358 | size=0x1C (28 bytes) */
    lis     r4,-13312
    addi    r4,r4,27648
    lwz     r0,4(r4)
    rlwinm  r0,r0,0,24,15
    rlwimi  r0,r3,8,16,23
    stw     r0,4(r4)
    blr
.size AISetStreamVolRight, . - AISetStreamVolRight

.global AIGetStreamVolRight
.balign 4
AIGetStreamVolRight:
/* 0x80267374 | size=0x10 (16 bytes) */
    lis     r3,-13312
    lwz     r0,27652(r3)
    rlwinm  r3,r0,24,24,31
    blr
.size AIGetStreamVolRight, . - AIGetStreamVolRight

.global AIReset
.balign 4
AIReset:
/* 0x802674F0 | size=0x0C (12 bytes) */
    li      r0,0
    stw     r0,-23120(r13)
    blr
.size AIReset, . - AIReset

.global __ai_src_get_time
.balign 4
__ai_src_get_time:
/* 0x80267860 | size=0x08 (8 bytes) */
    li      r3,0
    blr
.size __ai_src_get_time, . - __ai_src_get_time
