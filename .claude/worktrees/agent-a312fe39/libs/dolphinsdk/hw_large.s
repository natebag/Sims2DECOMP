# DolphinSDK hardware libraries - Large functions (257-1024 bytes)
# Auto-generated from ELF disassembly
# Functions in the 257-1024 byte range

.section .text

#
# === ai.o (ai.a) ===
#

.global AIInit
.balign 4
AIInit:
/* 0x80267384 | size=0x16C (364 bytes) */
    mflr    r0
    stw     r0,4(r1)
    stwu    r1,-24(r1)
    stw     r31,20(r1)
    stw     r30,16(r1)
    addi    r30,r3,0
    lwz     r0,-23120(r13)
    cmpwi   r0,1
    beq-	.L_802674D8
    lwz     r3,-27624(r13)
    bl	OSRegisterVersion
    lis     r3,-32768
    lwz     r0,248(r3)
    lis     r3,17180
    lis     r4,1
    srwi    r0,r0,2
    addi    r3,r3,-8573
    mulhwu  r0,r3,r0
    srwi    r9,r0,15
    addi    r5,r4,-23512
    addi    r3,r4,-23536
    addi    r0,r4,-2536
    lis     r4,4194
    mullw   r7,r9,r5
    addi    r10,r4,19923
    mullw   r5,r9,r3
    mullw   r4,r9,r0
    mulli   r8,r9,31524
    mulli   r3,r9,3000
    mulhwu  r8,r10,r8
    mulhwu  r7,r10,r7
    mulhwu  r5,r10,r5
    mulhwu  r4,r10,r4
    mulhwu  r3,r10,r3
    srwi    r8,r8,9
    srwi    r7,r7,9
    stw     r8,-23108(r13)
    srwi    r5,r5,9
    srwi    r4,r4,9
    stw     r7,-23100(r13)
    li      r31,0
    srwi    r3,r3,9
    stw     r5,-23092(r13)
    lis     r6,-13312
    stw     r3,-23076(r13)
    li      r3,1
    lwz     r0,27648(r6)
    stw     r4,-23084(r13)
    rlwinm  r0,r0,0,27,25
    ori     r0,r0,32
    stw     r31,-23112(r13)
    stw     r31,-23104(r13)
    stw     r31,-23096(r13)
    stw     r31,-23088(r13)
    stw     r31,-23080(r13)
    lwz     r5,27652(r6)
    stw     r0,27648(r6)
    rlwinm  r0,r5,0,24,15
    nop
    stw     r0,27652(r6)
    lwz     r0,27652(r6)
    clrrwi  r0,r0,8
    nop
    stw     r0,27652(r6)
    stw     r31,27660(r6)
    bl	__AI_set_stream_sample_rate
    li      r3,0
    bl	AISetDSPSampleRate
    lis     r3,-32730
    stw     r31,-23136(r13)
    addi    r4,r3,30072
    stw     r31,-23132(r13)
    li      r3,5
    stw     r30,-23128(r13)
    bl	__OSSetInterruptHandler
    lis     r3,1024
    bl	__OSUnmaskInterrupts
    lis     r3,-32730
    addi    r4,r3,29948
    li      r3,8
    bl	__OSSetInterruptHandler
    lis     r3,128
    bl	__OSUnmaskInterrupts
    li      r0,1
    stw     r0,-23120(r13)
.L_802674D8:
    lwz     r0,28(r1)
    lwz     r31,20(r1)
    lwz     r30,16(r1)
    addi    r1,r1,24
    mtlr    r0
    blr
.size AIInit, . - AIInit

.global __AI_SRC_INIT
.balign 4
__AI_SRC_INIT:
/* 0x8026767C | size=0x1E4 (484 bytes) */
    mflr    r0
    stw     r0,4(r1)
    stwu    r1,-48(r1)
    stmw    r26,24(r1)
    li      r4,0
    li      r3,0
    li      r0,0
    li      r28,0
    li      r29,0
    b	.L_802676A4
.L_802676A4:
    lis     r31,-13312
    b	.L_802676AC
.L_802676AC:
    b	.L_80267810
.L_802676B0:
    lwz     r0,27648(r31)
    addi    r30,r31,27648
    addi    r30,r30,8
    rlwinm  r0,r0,0,27,25
    ori     r0,r0,32
    stw     r0,27648(r31)
    lwz     r0,27648(r31)
    rlwinm  r0,r0,0,31,29
    stw     r0,27648(r31)
    lwz     r0,27648(r31)
    clrrwi  r0,r0,1
    ori     r0,r0,1
    stw     r0,27648(r31)
    lwz     r3,0(r30)
    b	.L_802676EC
.L_802676EC:
    b	.L_802676F0
.L_802676F0:
    lwz     r0,0(r30)
    cmplw   r3,r0
    beq+	.L_802676F0
    bl	OSGetTime
    lwz     r0,27648(r31)
    mr      r26,r4
    mr      r27,r3
    rlwinm  r0,r0,0,31,29
    ori     r0,r0,2
    stw     r0,27648(r31)
    lwz     r0,27648(r31)
    clrrwi  r0,r0,1
    ori     r0,r0,1
    stw     r0,27648(r31)
    lwz     r3,0(r30)
    b	.L_80267730
.L_80267730:
    b	.L_80267734
.L_80267734:
    lwz     r0,0(r30)
    cmplw   r3,r0
    beq+	.L_80267734
    bl	OSGetTime
    subfc   r8,r26,r4
    lwz     r12,-23108(r13)
    lwz     r5,27648(r31)
    subfe   r7,r27,r3
    lwz     r10,-23076(r13)
    xoris   r7,r7,32768
    rlwinm  r5,r5,0,31,29
    lwz     r11,-23112(r13)
    subfc   r6,r10,r12
    lwz     r9,-23080(r13)
    stw     r5,27648(r31)
    subfe   r0,r9,r11
    xoris   r5,r0,32768
    subfc   r0,r6,r8
    lwz     r0,27648(r31)
    subfe   r5,r5,r7
    subfe   r5,r7,r7
    neg     r5,r5
    clrrwi  r0,r0,1
    cmpwi   r5,0
    stw     r0,27648(r31)
    beq-	.L_802677AC
    lwz     r29,-23096(r13)
    li      r0,1
    lwz     r28,-23092(r13)
    b	.L_80267810
.L_802677AC:
    addc    r6,r12,r10
    adde    r0,r11,r9
    xoris   r5,r0,32768
    subfc   r0,r6,r8
    subfe   r5,r5,r7
    subfe   r5,r7,r7
    neg     r5,r5
    cmpwi   r5,0
    bne-	.L_8026780C
    lwz     r5,-23100(r13)
    lwz     r0,-23104(r13)
    subfc   r6,r10,r5
    subfe   r0,r9,r0
    xoris   r5,r0,32768
    subfc   r0,r6,r8
    subfe   r5,r5,r7
    subfe   r5,r7,r7
    neg     r5,r5
    cmpwi   r5,0
    beq-	.L_8026780C
    lwz     r29,-23088(r13)
    li      r0,1
    lwz     r28,-23084(r13)
    b	.L_80267810
.L_8026780C:
    li      r0,0
.L_80267810:
    cmplwi  r0,0
    beq+	.L_802676B0
    addc    r27,r4,r28
    adde    r26,r3,r29
    b	.L_80267824
.L_80267824:
    b	.L_80267828
.L_80267828:
    bl	OSGetTime
    xoris   r5,r3,32768
    xoris   r3,r26,32768
    subfc   r0,r27,r4
    subfe   r3,r3,r5
    subfe   r3,r5,r5
    neg     r3,r3
    cmpwi   r3,0
    bne+	.L_80267828
    lmw     r26,24(r1)
    lwz     r0,52(r1)
    addi    r1,r1,48
    mtlr    r0
    blr
.size __AI_SRC_INIT, . - __AI_SRC_INIT

#
# === dvd.o (dvd.a) ===
#

.global cbForStateGettingError
.balign 4
cbForStateGettingError:
/* 0x8025C714 | size=0x264 (612 bytes) */
    mflr    r0
    cmplwi  r3,16
    stw     r0,4(r1)
    stwu    r1,-32(r1)
    stw     r31,28(r1)
    stw     r30,24(r1)
    stw     r29,20(r1)
    stw     r28,16(r1)
    bne-	.L_8025C754
    lis     r3,291
    addi    r3,r3,17768
    bl	__DVDStoreErrorCode
    bl	DVDReset
    li      r3,0
    bl	cbForStateError
    b	.L_8025C958
.L_8025C754:
    rlwinm. r0,r3,0,30,30
    beq-	.L_8025C778
    lis     r3,291
    addi    r3,r3,17767
    bl	__DVDStoreErrorCode
    lis     r3,-32730
    addi    r3,r3,-15216
    bl	DVDLowStopMotor
    b	.L_8025C958
.L_8025C778:
    lis     r3,-13312
    lwz     r29,24608(r3)
    addi    r3,r29,0
    clrrwi  r28,r29,24
    bl	CategorizeError
    addi    r31,r3,0
    cmplwi  r31,1
    bne-	.L_8025C7B0
    mr      r3,r29
    bl	__DVDStoreErrorCode
    lis     r3,-32730
    addi    r3,r3,-15216
    bl	DVDLowStopMotor
    b	.L_8025C958
.L_8025C7B0:
    addi    r0,r31,-2
    cmplwi  r0,1
    bgt-	.L_8025C7C4
    li      r4,0
    b	.L_8025C804
.L_8025C7C4:
    addis   r0,r28,-256
    cmplwi  r0,0
    bne-	.L_8025C7D8
    li      r4,4
    b	.L_8025C804
.L_8025C7D8:
    addis   r0,r28,-512
    cmplwi  r0,0
    bne-	.L_8025C7EC
    li      r4,6
    b	.L_8025C804
.L_8025C7EC:
    addis   r0,r28,-768
    cmplwi  r0,0
    bne-	.L_8025C800
    li      r4,3
    b	.L_8025C804
.L_8025C800:
    li      r4,5
.L_8025C804:
    lwz     r0,-23448(r13)
    cmplwi  r0,0
    beq-	.L_8025C878
    lis     r3,-32694
    stw     r4,-23440(r13)
    li      r0,0
    lwz     r30,-23480(r13)
    addi    r3,r3,-17184
    stw     r0,-23448(r13)
    li      r0,10
    stw     r3,-23480(r13)
    stw     r0,12(r30)
    lwz     r12,40(r30)
    cmplwi  r12,0
    beq-	.L_8025C850
    mtlr    r12
    addi    r4,r30,0
    li      r3,-3
    blrl
.L_8025C850:
    lwz     r12,-23444(r13)
    cmplwi  r12,0
    beq-	.L_8025C86C
    mtlr    r12
    addi    r4,r30,0
    li      r3,0
    blrl
.L_8025C86C:
    bl	stateReady
    li      r0,1
    b	.L_8025C87C
.L_8025C878:
    li      r0,0
.L_8025C87C:
    cmpwi   r0,0
    bne-	.L_8025C958
    cmplwi  r31,2
    bne-	.L_8025C89C
    mr      r3,r29
    bl	__DVDStoreErrorCode
    bl	stateGoToRetry
    b	.L_8025C958
.L_8025C89C:
    cmplwi  r31,3
    bne-	.L_8025C8E0
    clrlwi  r3,r29,8
    addis   r0,r3,-3
    cmplwi  r0,4352
    bne-	.L_8025C8CC
    lwz     r5,-23480(r13)
    lis     r3,-32730
    addi    r4,r3,-13960
    lwz     r3,16(r5)
    bl	DVDLowSeek
    b	.L_8025C958
.L_8025C8CC:
    lwz     r12,-23392(r13)
    lwz     r3,-23480(r13)
    mtlr    r12
    blrl
    b	.L_8025C958
.L_8025C8E0:
    addis   r0,r28,-256
    cmplwi  r0,0
    bne-	.L_8025C900
    lwz     r3,-23480(r13)
    li      r0,5
    stw     r0,12(r3)
    bl	stateMotorStopped
    b	.L_8025C958
.L_8025C900:
    addis   r0,r28,-512
    cmplwi  r0,0
    bne-	.L_8025C920
    lwz     r3,-23480(r13)
    li      r0,3
    stw     r0,12(r3)
    bl	stateCoverClosed
    b	.L_8025C958
.L_8025C920:
    addis   r0,r28,-768
    cmplwi  r0,0
    bne-	.L_8025C940
    lwz     r3,-23480(r13)
    li      r0,4
    stw     r0,12(r3)
    bl	stateMotorStopped
    b	.L_8025C958
.L_8025C940:
    lis     r3,291
    addi    r3,r3,17767
    bl	__DVDStoreErrorCode
    lis     r3,-32730
    addi    r3,r3,-15216
    bl	DVDLowStopMotor
.L_8025C958:
    lwz     r0,36(r1)
    lwz     r31,28(r1)
    lwz     r30,24(r1)
    lwz     r29,20(r1)
    lwz     r28,16(r1)
    addi    r1,r1,32
    mtlr    r0
    blr
.size cbForStateGettingError, . - cbForStateGettingError

.global cbForStateGoToRetry
.balign 4
cbForStateGoToRetry:
/* 0x8025CA7C | size=0x140 (320 bytes) */
    mflr    r0
    cmplwi  r3,16
    stw     r0,4(r1)
    stwu    r1,-24(r1)
    stw     r31,20(r1)
    bne-	.L_8025CAB0
    lis     r3,291
    addi    r3,r3,17768
    bl	__DVDStoreErrorCode
    bl	DVDReset
    li      r3,0
    bl	cbForStateError
    b	.L_8025CBA8
.L_8025CAB0:
    rlwinm. r0,r3,0,30,30
    beq-	.L_8025CAD4
    lis     r3,291
    addi    r3,r3,17767
    bl	__DVDStoreErrorCode
    lis     r3,-32730
    addi    r3,r3,-15216
    bl	DVDLowStopMotor
    b	.L_8025CBA8
.L_8025CAD4:
    li      r0,0
    stw     r0,-23428(r13)
    lwz     r0,-23452(r13)
    cmplwi  r0,4
    beq-	.L_8025CB0C
    lwz     r0,-23452(r13)
    cmplwi  r0,5
    beq-	.L_8025CB0C
    lwz     r0,-23452(r13)
    cmplwi  r0,13
    beq-	.L_8025CB0C
    lwz     r0,-23452(r13)
    cmplwi  r0,15
    bne-	.L_8025CB14
.L_8025CB0C:
    li      r0,1
    stw     r0,-23424(r13)
.L_8025CB14:
    lwz     r0,-23448(r13)
    cmplwi  r0,0
    beq-	.L_8025CB8C
    li      r0,2
    lwz     r31,-23480(r13)
    lis     r3,-32694
    stw     r0,-23440(r13)
    addi    r0,r3,-17184
    li      r3,0
    stw     r0,-23480(r13)
    li      r0,10
    stw     r3,-23448(r13)
    stw     r0,12(r31)
    lwz     r12,40(r31)
    cmplwi  r12,0
    beq-	.L_8025CB64
    mtlr    r12
    addi    r4,r31,0
    li      r3,-3
    blrl
.L_8025CB64:
    lwz     r12,-23444(r13)
    cmplwi  r12,0
    beq-	.L_8025CB80
    mtlr    r12
    addi    r4,r31,0
    li      r3,0
    blrl
.L_8025CB80:
    bl	stateReady
    li      r0,1
    b	.L_8025CB90
.L_8025CB8C:
    li      r0,0
.L_8025CB90:
    cmpwi   r0,0
    bne-	.L_8025CBA8
    lwz     r3,-23480(r13)
    li      r0,11
    stw     r0,12(r3)
    bl	stateMotorStopped
.L_8025CBA8:
    lwz     r0,28(r1)
    lwz     r31,20(r1)
    addi    r1,r1,24
    mtlr    r0
    blr
.size cbForStateGoToRetry, . - cbForStateGoToRetry

.global stateReady
.balign 4
stateReady:
/* 0x8025D328 | size=0x2E8 (744 bytes) */
.L_8025D328:
    mflr    r0
    lis     r3,-32694
    stw     r0,4(r1)
    stwu    r1,-16(r1)
    stw     r31,12(r1)
    addi    r31,r3,-17248
    bl	__DVDCheckWaitingQueue
    cmpwi   r3,0
    bne-	.L_8025D358
    li      r0,0
    stw     r0,-23480(r13)
    b	.L_8025D5FC
.L_8025D358:
    lwz     r0,-23468(r13)
    cmpwi   r0,0
    beq-	.L_8025D378
    li      r3,1
    li      r0,0
    stw     r3,-23464(r13)
    stw     r0,-23480(r13)
    b	.L_8025D5FC
.L_8025D378:
    bl	__DVDPopWaitingQueue
    lwz     r0,-23456(r13)
    stw     r3,-23480(r13)
    cmpwi   r0,0
    beq-	.L_8025D3C4
    lwz     r3,-23480(r13)
    li      r4,-1
    addi    r0,r31,64
    stw     r4,12(r3)
    lwz     r4,-23480(r13)
    stw     r0,-23480(r13)
    lwz     r12,40(r4)
    cmplwi  r12,0
    beq-	.L_8025D3BC
    mtlr    r12
    li      r3,-1
    blrl
.L_8025D3BC:
    bl	.L_8025D328
    b	.L_8025D5FC
.L_8025D3C4:
    lwz     r4,-23480(r13)
    lwz     r0,8(r4)
    stw     r0,-23452(r13)
    lwz     r0,-23440(r13)
    cmplwi  r0,0
    beq-	.L_8025D534
    lwz     r0,-23440(r13)
    cmpwi   r0,4
    beq-	.L_8025D448
    bge-	.L_8025D404
    cmpwi   r0,2
    beq-	.L_8025D418
    bge-	.L_8025D430
    cmpwi   r0,1
    bge-	.L_8025D460
    b	.L_8025D528
.L_8025D404:
    cmpwi   r0,8
    bge-	.L_8025D528
    cmpwi   r0,6
    bge-	.L_8025D460
    b	.L_8025D514
.L_8025D418:
    li      r0,11
    lis     r3,-32730
    stw     r0,12(r4)
    addi    r3,r3,-11716
    bl	DVDLowWaitCoverClose
    b	.L_8025D528
.L_8025D430:
    li      r0,4
    lis     r3,-32730
    stw     r0,12(r4)
    addi    r3,r3,-11716
    bl	DVDLowWaitCoverClose
    b	.L_8025D528
.L_8025D448:
    li      r0,5
    lis     r3,-32730
    stw     r0,12(r4)
    addi    r3,r3,-11716
    bl	DVDLowWaitCoverClose
    b	.L_8025D528
.L_8025D460:
    li      r0,3
    stw     r0,12(r4)
    lwz     r0,-23452(r13)
    cmpwi   r0,13
    beq-	.L_8025D498
    bge-	.L_8025D48C
    cmpwi   r0,6
    bge-	.L_8025D4C8
    cmpwi   r0,4
    bge-	.L_8025D498
    b	.L_8025D4C8
.L_8025D48C:
    cmpwi   r0,15
    beq-	.L_8025D498
    b	.L_8025D4C8
.L_8025D498:
    bl	__DVDClearWaitingQueue
    lwz     r4,-23480(r13)
    addi    r0,r31,64
    stw     r0,-23480(r13)
    lwz     r12,40(r4)
    cmplwi  r12,0
    beq-	.L_8025D4C0
    mtlr    r12
    li      r3,-4
    blrl
.L_8025D4C0:
    bl	.L_8025D328
    b	.L_8025D528
.L_8025D4C8:
    li      r0,0
    stw     r0,-23408(r13)
    bl	DVDReset
    addi    r3,r31,112
    bl	OSCreateAlarm
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
    bl	OSSetAlarm
    b	.L_8025D528
.L_8025D514:
    lwz     r3,-23436(r13)
    bl	__DVDStoreErrorCode
    lis     r3,-32730
    addi    r3,r3,-15216
    bl	DVDLowStopMotor
.L_8025D528:
    li      r0,0
    stw     r0,-23440(r13)
    b	.L_8025D5FC
.L_8025D534:
    lwz     r0,-23408(r13)
    cmplwi  r0,0
    bne-	.L_8025D554
    li      r0,1
    stw     r0,12(r4)
    lwz     r3,-23480(r13)
    bl	stateBusy
    b	.L_8025D5FC
.L_8025D554:
    lwz     r0,-23452(r13)
    cmpwi   r0,13
    beq-	.L_8025D584
    bge-	.L_8025D578
    cmpwi   r0,6
    bge-	.L_8025D5B4
    cmpwi   r0,4
    bge-	.L_8025D584
    b	.L_8025D5B4
.L_8025D578:
    cmpwi   r0,15
    beq-	.L_8025D584
    b	.L_8025D5B4
.L_8025D584:
    bl	__DVDClearWaitingQueue
    lwz     r4,-23480(r13)
    addi    r0,r31,64
    stw     r0,-23480(r13)
    lwz     r12,40(r4)
    cmplwi  r12,0
    beq-	.L_8025D5AC
    mtlr    r12
    li      r3,-4
    blrl
.L_8025D5AC:
    bl	.L_8025D328
    b	.L_8025D5FC
.L_8025D5B4:
    li      r0,0
    stw     r0,-23408(r13)
    bl	DVDReset
    addi    r3,r31,112
    bl	OSCreateAlarm
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
    bl	OSSetAlarm
.L_8025D5FC:
    lwz     r0,20(r1)
    lwz     r31,12(r1)
    addi    r1,r1,16
    mtlr    r0
    blr
.size stateReady, . - stateReady

.global stateBusy
.balign 4
stateBusy:
/* 0x8025D610 | size=0x340 (832 bytes) */
    mflr    r0
    lis     r4,-32730
    stw     r0,4(r1)
    addi    r0,r4,-10736
    mr      r7,r3
    stwu    r1,-8(r1)
    stw     r0,-23392(r13)
    lwz     r0,8(r3)
    cmplwi  r0,16
    bgt-	.L_8025D928
    lis     r3,-32700
    addi    r3,r3,-14440
    slwi    r0,r0,2
    lwzx    r0,r3,r0
    mtctr   r0
    bctr
    lis     r3,-13312
    lwz     r0,24580(r3)
    addi    r5,r3,24576
    lis     r3,-32730
    stw     r0,4(r5)
    li      r0,32
    addi    r4,r3,-9684
    stw     r0,28(r7)
    lwz     r3,24(r7)
    bl	DVDLowReadDiskID
    b	.L_8025D940
    lwz     r0,20(r7)
    cmplwi  r0,0
    bne-	.L_8025D6C0
    lis     r3,-32694
    lwz     r4,-23480(r13)
    addi    r0,r3,-17184
    stw     r0,-23480(r13)
    li      r0,0
    stw     r0,12(r4)
    lwz     r12,40(r4)
    cmplwi  r12,0
    beq-	.L_8025D6B8
    mtlr    r12
    li      r3,0
    blrl
.L_8025D6B8:
    bl	stateReady
    b	.L_8025D940
.L_8025D6C0:
    lis     r3,-13312
    addi    r3,r3,24576
    lwz     r0,4(r3)
    lis     r4,8
    stw     r0,4(r3)
    lwz     r3,32(r7)
    lwz     r0,20(r7)
    subf    r0,r3,r0
    cmplw   r0,r4
    ble-	.L_8025D6EC
    b	.L_8025D6F0
.L_8025D6EC:
    mr      r4,r0
.L_8025D6F0:
    stw     r4,28(r7)
    lis     r3,-32730
    addi    r6,r3,-9684
    lwz     r5,32(r7)
    lwz     r3,24(r7)
    lwz     r0,16(r7)
    add     r3,r3,r5
    lwz     r4,28(r7)
    add     r5,r0,r5
    bl	DVDLowRead
    b	.L_8025D940
    lis     r3,-13312
    lwz     r0,24580(r3)
    addi    r5,r3,24576
    lis     r3,-32730
    stw     r0,4(r5)
    addi    r4,r3,-9684
    lwz     r3,16(r7)
    bl	DVDLowSeek
    b	.L_8025D940
    lis     r3,-32730
    addi    r3,r3,-9684
    bl	DVDLowStopMotor
    b	.L_8025D940
    lis     r3,-32730
    addi    r3,r3,-9684
    bl	DVDLowStopMotor
    b	.L_8025D940
    lis     r3,-13312
    addi    r3,r3,24576
    lwz     r0,4(r3)
    stw     r0,4(r3)
    lwz     r0,-23460(r13)
    cmpwi   r0,0
    beq-	.L_8025D79C
    lwz     r5,-23480(r13)
    li      r0,0
    lis     r3,-32730
    stw     r0,28(r5)
    addi    r4,r3,-9684
    li      r3,0
    bl	DVDLowRequestAudioStatus
    b	.L_8025D940
.L_8025D79C:
    lwz     r4,-23480(r13)
    li      r0,1
    lis     r3,-32730
    stw     r0,28(r4)
    addi    r6,r3,-9684
    li      r3,0
    lwz     r4,20(r7)
    lwz     r5,16(r7)
    bl	DVDLowAudioStream
    b	.L_8025D940
    lis     r3,-13312
    lwz     r0,24580(r3)
    addi    r4,r3,24576
    lis     r3,-32730
    stw     r0,4(r4)
    addi    r6,r3,-9684
    lis     r3,1
    li      r4,0
    li      r5,0
    bl	DVDLowAudioStream
    b	.L_8025D940
    lis     r3,-13312
    lwz     r0,24580(r3)
    addi    r4,r3,24576
    lis     r3,-32730
    stw     r0,4(r4)
    li      r0,1
    addi    r6,r3,-9684
    stw     r0,-23460(r13)
    li      r3,0
    li      r4,0
    li      r5,0
    bl	DVDLowAudioStream
    b	.L_8025D940
    lis     r3,-13312
    lwz     r0,24580(r3)
    addi    r5,r3,24576
    lis     r3,-32730
    stw     r0,4(r5)
    addi    r4,r3,-9684
    li      r3,0
    bl	DVDLowRequestAudioStatus
    b	.L_8025D940
    lis     r3,-13312
    lwz     r0,24580(r3)
    addi    r5,r3,24576
    lis     r3,-32730
    stw     r0,4(r5)
    addi    r4,r3,-9684
    lis     r3,1
    bl	DVDLowRequestAudioStatus
    b	.L_8025D940
    lis     r3,-13312
    lwz     r0,24580(r3)
    addi    r5,r3,24576
    lis     r3,-32730
    stw     r0,4(r5)
    addi    r4,r3,-9684
    lis     r3,2
    bl	DVDLowRequestAudioStatus
    b	.L_8025D940
    lis     r3,-13312
    lwz     r0,24580(r3)
    addi    r5,r3,24576
    lis     r3,-32730
    stw     r0,4(r5)
    addi    r4,r3,-9684
    lis     r3,3
    bl	DVDLowRequestAudioStatus
    b	.L_8025D940
    lis     r3,-13312
    lwz     r0,24580(r3)
    addi    r4,r3,24576
    lis     r3,-32730
    stw     r0,4(r4)
    addi    r5,r3,-9684
    lwz     r3,16(r7)
    lwz     r4,20(r7)
    bl	DVDLowAudioBufferConfig
    b	.L_8025D940
    lis     r3,-13312
    lwz     r0,24580(r3)
    addi    r5,r3,24576
    lis     r3,-32730
    stw     r0,4(r5)
    li      r0,32
    addi    r4,r3,-9684
    stw     r0,28(r7)
    lwz     r3,24(r7)
    bl	DVDLowInquiry
    b	.L_8025D940
    lis     r3,-13312
    lwz     r0,24580(r3)
    addi    r4,r3,24576
    lis     r3,-32730
    stw     r0,4(r4)
    addi    r3,r3,-9684
    bl	DVDLowStopMotor
    b	.L_8025D940
.L_8025D928:
    lwz     r12,-27784(r13)
    lis     r3,-32730
    addi    r4,r3,-9684
    mtlr    r12
    addi    r3,r7,0
    blrl
.L_8025D940:
    lwz     r0,12(r1)
    addi    r1,r1,8
    mtlr    r0
    blr
.size stateBusy, . - stateBusy

.global DVDChangeDiskAsync
.balign 4
DVDChangeDiskAsync:
/* 0x8025EFEC | size=0x110 (272 bytes) */
    mflr    r0
    stw     r0,4(r1)
    stwu    r1,-48(r1)
    stw     r31,44(r1)
    mr      r31,r4
    stw     r30,40(r1)
    addi    r30,r5,0
    stw     r29,36(r1)
    addi    r29,r3,0
    lbz     r0,4(r4)
    extsb.  r0,r0
    bne-	.L_8025F040
    lis     r3,-32700
    crclr   4*cr1+eq
    addi    r3,r3,-14360
    bl	OSReport
    crclr   4*cr1+eq
    addi    r3,r13,-27780
    li      r4,2902
    addi    r5,r13,-27768
    bl	OSPanic
.L_8025F040:
    li      r0,3
    stw     r0,8(r29)
    stw     r31,36(r29)
    stw     r30,40(r29)
    lwz     r4,-23472(r13)
    lwz     r3,56(r4)
    lwz     r4,60(r4)
    bl	DCInvalidateRange
    lwz     r0,-27788(r13)
    cmpwi   r0,0
    beq-	.L_8025F098
    lwz     r3,8(r29)
    cmplwi  r3,1
    beq-	.L_8025F08C
    addi    r0,r3,-4
    cmplwi  r0,1
    ble-	.L_8025F08C
    cmplwi  r3,14
    bne-	.L_8025F098
.L_8025F08C:
    lwz     r3,24(r29)
    lwz     r4,20(r29)
    bl	DCInvalidateRange
.L_8025F098:
    bl	OSDisableInterrupts
    li      r0,2
    stw     r0,12(r29)
    addi    r30,r3,0
    addi    r4,r29,0
    li      r3,2
    bl	__DVDPushWaitingQueue
    lwz     r0,-23480(r13)
    addi    r31,r3,0
    cmplwi  r0,0
    bne-	.L_8025F0D4
    lwz     r0,-23468(r13)
    cmpwi   r0,0
    bne-	.L_8025F0D4
    bl	stateReady
.L_8025F0D4:
    mr      r3,r30
    bl	OSRestoreInterrupts
    mr      r3,r31
    lwz     r0,52(r1)
    lwz     r31,44(r1)
    lwz     r30,40(r1)
    lwz     r29,36(r1)
    addi    r1,r1,48
    mtlr    r0
    blr
.size DVDChangeDiskAsync, . - DVDChangeDiskAsync

.global DVDChangeDisk
.balign 4
DVDChangeDisk:
/* 0x8025F0FC | size=0x104 (260 bytes) */
    mflr    r0
    stw     r0,4(r1)
    stwu    r1,-40(r1)
    stw     r31,36(r1)
    stw     r30,32(r1)
    mr      r30,r4
    stw     r29,28(r1)
    addi    r29,r3,0
    lbz     r0,4(r4)
    extsb.  r0,r0
    bne-	.L_8025F14C
    lis     r3,-32700
    crclr   4*cr1+eq
    addi    r3,r3,-14360
    bl	OSReport
    crclr   4*cr1+eq
    addi    r3,r13,-27780
    li      r4,2902
    addi    r5,r13,-27768
    bl	OSPanic
.L_8025F14C:
    li      r0,3
    stw     r0,8(r29)
    lis     r3,-32730
    addi    r0,r3,-3584
    stw     r30,36(r29)
    stw     r0,40(r29)
    lwz     r4,-23472(r13)
    lwz     r3,56(r4)
    lwz     r4,60(r4)
    bl	DCInvalidateRange
    li      r3,2
    addi    r4,r29,0
    bl	issueCommand
    cmpwi   r3,0
    bne-	.L_8025F190
    li      r3,-1
    b	.L_8025F1E4
.L_8025F190:
    bl	OSDisableInterrupts
    mr      r31,r3
.L_8025F198:
    lwz     r0,12(r29)
    cmpwi   r0,0
    bne-	.L_8025F1AC
    li      r30,0
    b	.L_8025F1D8
.L_8025F1AC:
    cmpwi   r0,-1
    bne-	.L_8025F1BC
    li      r30,-1
    b	.L_8025F1D8
.L_8025F1BC:
    cmpwi   r0,10
    bne-	.L_8025F1CC
    li      r30,-3
    b	.L_8025F1D8
.L_8025F1CC:
    addi    r3,r13,-23488
    bl	OSSleepThread
    b	.L_8025F198
.L_8025F1D8:
    mr      r3,r31
    bl	OSRestoreInterrupts
    mr      r3,r30
.L_8025F1E4:
    lwz     r0,44(r1)
    lwz     r31,36(r1)
    lwz     r30,32(r1)
    lwz     r29,28(r1)
    addi    r1,r1,40
    mtlr    r0
    blr
.size DVDChangeDisk, . - DVDChangeDisk

.global DVDCancelAsync
.balign 4
DVDCancelAsync:
/* 0x8025F754 | size=0x27C (636 bytes) */
    mflr    r0
    stw     r0,4(r1)
    stwu    r1,-40(r1)
    stw     r31,36(r1)
    stw     r30,32(r1)
    addi    r30,r4,0
    stw     r29,28(r1)
    addi    r29,r3,0
    bl	OSDisableInterrupts
    lwz     r4,12(r29)
    addi    r31,r3,0
    addi    r0,r4,1
    cmplwi  r0,12
    bgt-	.L_8025F9A8
    lis     r3,-32700
    addi    r3,r3,-14292
    slwi    r0,r0,2
    lwzx    r0,r3,r0
    mtctr   r0
    bctr
    cmplwi  r30,0
    beq-	.L_8025F9A8
    addi    r12,r30,0
    mtlr    r12
    addi    r4,r29,0
    li      r3,0
    blrl
    b	.L_8025F9A8
    lwz     r0,-23448(r13)
    cmplwi  r0,0
    beq-	.L_8025F7E0
    mr      r3,r31
    bl	OSRestoreInterrupts
    li      r3,0
    b	.L_8025F9B4
.L_8025F7E0:
    li      r0,1
    stw     r30,-23444(r13)
    stw     r0,-23448(r13)
    lwz     r0,8(r29)
    cmplwi  r0,4
    beq-	.L_8025F800
    cmplwi  r0,1
    bne-	.L_8025F9A8
.L_8025F800:
    bl	DVDLowBreak
    b	.L_8025F9A8
    mr      r3,r29
    bl	__DVDDequeueWaitingQueue
    li      r0,10
    stw     r0,12(r29)
    lwz     r12,40(r29)
    cmplwi  r12,0
    beq-	.L_8025F834
    mtlr    r12
    addi    r4,r29,0
    li      r3,-3
    blrl
.L_8025F834:
    cmplwi  r30,0
    beq-	.L_8025F9A8
    addi    r12,r30,0
    mtlr    r12
    addi    r4,r29,0
    li      r3,0
    blrl
    b	.L_8025F9A8
    lwz     r0,8(r29)
    cmpwi   r0,13
    beq-	.L_8025F884
    bge-	.L_8025F878
    cmpwi   r0,6
    bge-	.L_8025F8A4
    cmpwi   r0,4
    bge-	.L_8025F884
    b	.L_8025F8A4
.L_8025F878:
    cmpwi   r0,15
    beq-	.L_8025F884
    b	.L_8025F8A4
.L_8025F884:
    cmplwi  r30,0
    beq-	.L_8025F9A8
    addi    r12,r30,0
    mtlr    r12
    addi    r4,r29,0
    li      r3,0
    blrl
    b	.L_8025F9A8
.L_8025F8A4:
    lwz     r0,-23448(r13)
    cmplwi  r0,0
    beq-	.L_8025F8C0
    mr      r3,r31
    bl	OSRestoreInterrupts
    li      r3,0
    b	.L_8025F9B4
.L_8025F8C0:
    li      r0,1
    stw     r30,-23444(r13)
    stw     r0,-23448(r13)
    b	.L_8025F9A8
    bl	DVDLowClearCallback
    lis     r4,-32730
    addi    r0,r4,-11716
    cmplw   r3,r0
    beq-	.L_8025F8F4
    mr      r3,r31
    bl	OSRestoreInterrupts
    li      r3,0
    b	.L_8025F9B4
.L_8025F8F4:
    lwz     r0,12(r29)
    cmpwi   r0,4
    bne-	.L_8025F908
    li      r0,3
    stw     r0,-23440(r13)
.L_8025F908:
    lwz     r0,12(r29)
    cmpwi   r0,5
    bne-	.L_8025F91C
    li      r0,4
    stw     r0,-23440(r13)
.L_8025F91C:
    lwz     r0,12(r29)
    cmpwi   r0,6
    bne-	.L_8025F930
    li      r0,1
    stw     r0,-23440(r13)
.L_8025F930:
    lwz     r0,12(r29)
    cmpwi   r0,11
    bne-	.L_8025F944
    li      r0,2
    stw     r0,-23440(r13)
.L_8025F944:
    lwz     r0,12(r29)
    cmpwi   r0,7
    bne-	.L_8025F958
    li      r0,7
    stw     r0,-23440(r13)
.L_8025F958:
    lis     r3,-32694
    addi    r0,r3,-17184
    stw     r0,-23480(r13)
    li      r0,10
    stw     r0,12(r29)
    lwz     r12,40(r29)
    cmplwi  r12,0
    beq-	.L_8025F988
    mtlr    r12
    addi    r4,r29,0
    li      r3,-3
    blrl
.L_8025F988:
    cmplwi  r30,0
    beq-	.L_8025F9A4
    addi    r12,r30,0
    mtlr    r12
    addi    r4,r29,0
    li      r3,0
    blrl
.L_8025F9A4:
    bl	stateReady
.L_8025F9A8:
    mr      r3,r31
    bl	OSRestoreInterrupts
    li      r3,1
.L_8025F9B4:
    lwz     r0,44(r1)
    lwz     r31,36(r1)
    lwz     r30,32(r1)
    lwz     r29,28(r1)
    addi    r1,r1,40
    mtlr    r0
    blr
.size DVDCancelAsync, . - DVDCancelAsync

.global DVDCancelAll
.balign 4
DVDCancelAll:
/* 0x8025FB8C | size=0x138 (312 bytes) */
    mflr    r0
    stw     r0,4(r1)
    stwu    r1,-32(r1)
    stw     r31,28(r1)
    stw     r30,24(r1)
    stw     r29,20(r1)
    stw     r28,16(r1)
    bl	OSDisableInterrupts
    li      r0,0
    stw     r0,-23420(r13)
    mr      r31,r3
    bl	OSDisableInterrupts
    mr      r29,r3
    bl	OSDisableInterrupts
    lwz     r0,-23480(r13)
    li      r4,1
    stw     r4,-23468(r13)
    cmplwi  r0,0
    bne-	.L_8025FBDC
    stw     r4,-23464(r13)
.L_8025FBDC:
    bl	OSRestoreInterrupts
    b	.L_8025FBEC
.L_8025FBE4:
    li      r4,0
    bl	DVDCancelAsync
.L_8025FBEC:
    bl	__DVDPopWaitingQueue
    cmplwi  r3,0
    bne+	.L_8025FBE4
    lwz     r3,-23480(r13)
    cmplwi  r3,0
    beq-	.L_8025FC18
    lis     r4,-32730
    addi    r4,r4,-828
    bl	DVDCancelAsync
    mr      r30,r3
    b	.L_8025FC34
.L_8025FC18:
    lis     r3,-32730
    addic.  r0,r3,-828
    li      r30,1
    beq-	.L_8025FC34
    li      r3,0
    li      r4,0
    bl	cbForCancelAllSync
.L_8025FC34:
    bl	OSDisableInterrupts
    li      r4,0
    stw     r4,-23468(r13)
    mr      r28,r3
    lwz     r0,-23464(r13)
    cmpwi   r0,0
    beq-	.L_8025FC58
    stw     r4,-23464(r13)
    bl	stateReady
.L_8025FC58:
    mr      r3,r28
    bl	OSRestoreInterrupts
    mr      r3,r29
    bl	OSRestoreInterrupts
    cmpwi   r30,0
    bne-	.L_8025FC80
    mr      r3,r31
    bl	OSRestoreInterrupts
    li      r3,-1
    b	.L_8025FCA4
.L_8025FC80:
    lwz     r0,-23420(r13)
    cmpwi   r0,0
    bne-	.L_8025FC98
    addi    r3,r13,-23488
    bl	OSSleepThread
    b	.L_8025FC80
.L_8025FC98:
    mr      r3,r31
    bl	OSRestoreInterrupts
    li      r3,0
.L_8025FCA4:
    lwz     r0,36(r1)
    lwz     r31,28(r1)
    lwz     r30,24(r1)
    lwz     r29,20(r1)
    lwz     r28,16(r1)
    addi    r1,r1,32
    mtlr    r0
    blr
.size DVDCancelAll, . - DVDCancelAll

.global __DVDPrepareResetAsync
.balign 4
__DVDPrepareResetAsync:
/* 0x8025FDF0 | size=0x11C (284 bytes) */
    mflr    r0
    stw     r0,4(r1)
    stwu    r1,-32(r1)
    stw     r31,28(r1)
    stw     r30,24(r1)
    mr      r30,r3
    stw     r29,20(r1)
    bl	OSDisableInterrupts
    mr      r29,r3
    bl	__DVDClearWaitingQueue
    lwz     r0,-23448(r13)
    cmplwi  r0,0
    beq-	.L_8025FE2C
    stw     r30,-23444(r13)
    b	.L_8025FEE8
.L_8025FE2C:
    lwz     r3,-23480(r13)
    cmplwi  r3,0
    beq-	.L_8025FE40
    li      r0,0
    stw     r0,40(r3)
.L_8025FE40:
    bl	OSDisableInterrupts
    mr      r31,r3
    bl	OSDisableInterrupts
    lwz     r0,-23480(r13)
    li      r4,1
    stw     r4,-23468(r13)
    cmplwi  r0,0
    bne-	.L_8025FE64
    stw     r4,-23464(r13)
.L_8025FE64:
    bl	OSRestoreInterrupts
    b	.L_8025FE74
.L_8025FE6C:
    li      r4,0
    bl	DVDCancelAsync
.L_8025FE74:
    bl	__DVDPopWaitingQueue
    cmplwi  r3,0
    bne+	.L_8025FE6C
    lwz     r3,-23480(r13)
    cmplwi  r3,0
    beq-	.L_8025FE98
    mr      r4,r30
    bl	DVDCancelAsync
    b	.L_8025FEB4
.L_8025FE98:
    cmplwi  r30,0
    beq-	.L_8025FEB4
    addi    r12,r30,0
    mtlr    r12
    li      r3,0
    li      r4,0
    blrl
.L_8025FEB4:
    bl	OSDisableInterrupts
    li      r4,0
    stw     r4,-23468(r13)
    mr      r30,r3
    lwz     r0,-23464(r13)
    cmpwi   r0,0
    beq-	.L_8025FED8
    stw     r4,-23464(r13)
    bl	stateReady
.L_8025FED8:
    mr      r3,r30
    bl	OSRestoreInterrupts
    mr      r3,r31
    bl	OSRestoreInterrupts
.L_8025FEE8:
    mr      r3,r29
    bl	OSRestoreInterrupts
    lwz     r0,36(r1)
    lwz     r31,28(r1)
    lwz     r30,24(r1)
    lwz     r29,20(r1)
    addi    r1,r1,32
    mtlr    r0
    blr
.size __DVDPrepareResetAsync, . - __DVDPrepareResetAsync

#
# === dvderror.o (dvd.a) ===
#

.global ErrorCode2Num
.balign 4
ErrorCode2Num:
/* 0x80260378 | size=0x11C (284 bytes) */
    li      r0,2
    lis     r4,-32700
    mtctr   r0
    addi    r4,r4,-13824
    li      r5,0
.L_8026038C:
    lwz     r0,0(r4)
    cmplw   r3,r0
    bne-	.L_802603A0
    clrlwi  r3,r5,24
    blr
.L_802603A0:
    lwzu    r0,4(r4)
    addi    r5,r5,1
    cmplw   r3,r0
    bne-	.L_802603B8
    clrlwi  r3,r5,24
    blr
.L_802603B8:
    lwzu    r0,4(r4)
    addi    r5,r5,1
    cmplw   r3,r0
    bne-	.L_802603D0
    clrlwi  r3,r5,24
    blr
.L_802603D0:
    lwzu    r0,4(r4)
    addi    r5,r5,1
    cmplw   r3,r0
    bne-	.L_802603E8
    clrlwi  r3,r5,24
    blr
.L_802603E8:
    lwzu    r0,4(r4)
    addi    r5,r5,1
    cmplw   r3,r0
    bne-	.L_80260400
    clrlwi  r3,r5,24
    blr
.L_80260400:
    lwzu    r0,4(r4)
    addi    r5,r5,1
    cmplw   r3,r0
    bne-	.L_80260418
    clrlwi  r3,r5,24
    blr
.L_80260418:
    lwzu    r0,4(r4)
    addi    r5,r5,1
    cmplw   r3,r0
    bne-	.L_80260430
    clrlwi  r3,r5,24
    blr
.L_80260430:
    lwzu    r0,4(r4)
    addi    r5,r5,1
    cmplw   r3,r0
    bne-	.L_80260448
    clrlwi  r3,r5,24
    blr
.L_80260448:
    lwzu    r0,4(r4)
    addi    r5,r5,1
    cmplw   r3,r0
    bne-	.L_80260460
    clrlwi  r3,r5,24
    blr
.L_80260460:
    addi    r4,r4,4
    addi    r5,r5,1
    bdnz+	.L_8026038C
    lis     r4,16
    cmplw   r3,r4
    blt-	.L_8026048C
    addi    r0,r4,8
    cmplw   r3,r0
    bgt-	.L_8026048C
    li      r3,17
    blr
.L_8026048C:
    li      r3,29
    blr
.size ErrorCode2Num, . - ErrorCode2Num

.global Convert
.balign 4
Convert:
/* 0x80260494 | size=0x160 (352 bytes) */
    addis   r0,r3,-291
    cmplwi  r0,17767
    bne-	.L_802604A8
    li      r3,255
    blr
.L_802604A8:
    cmplwi  r0,17768
    bne-	.L_802604B8
    li      r3,254
    blr
.L_802604B8:
    li      r0,2
    lis     r4,-32700
    mtctr   r0
    addi    r4,r4,-13824
    srwi    r5,r3,24
    clrlwi  r6,r3,8
    li      r3,0
.L_802604D4:
    lwz     r0,0(r4)
    cmplw   r6,r0
    bne-	.L_802604E8
    clrlwi  r3,r3,24
    b	.L_802605D8
.L_802604E8:
    lwzu    r0,4(r4)
    addi    r3,r3,1
    cmplw   r6,r0
    bne-	.L_80260500
    clrlwi  r3,r3,24
    b	.L_802605D8
.L_80260500:
    lwzu    r0,4(r4)
    addi    r3,r3,1
    cmplw   r6,r0
    bne-	.L_80260518
    clrlwi  r3,r3,24
    b	.L_802605D8
.L_80260518:
    lwzu    r0,4(r4)
    addi    r3,r3,1
    cmplw   r6,r0
    bne-	.L_80260530
    clrlwi  r3,r3,24
    b	.L_802605D8
.L_80260530:
    lwzu    r0,4(r4)
    addi    r3,r3,1
    cmplw   r6,r0
    bne-	.L_80260548
    clrlwi  r3,r3,24
    b	.L_802605D8
.L_80260548:
    lwzu    r0,4(r4)
    addi    r3,r3,1
    cmplw   r6,r0
    bne-	.L_80260560
    clrlwi  r3,r3,24
    b	.L_802605D8
.L_80260560:
    lwzu    r0,4(r4)
    addi    r3,r3,1
    cmplw   r6,r0
    bne-	.L_80260578
    clrlwi  r3,r3,24
    b	.L_802605D8
.L_80260578:
    lwzu    r0,4(r4)
    addi    r3,r3,1
    cmplw   r6,r0
    bne-	.L_80260590
    clrlwi  r3,r3,24
    b	.L_802605D8
.L_80260590:
    lwzu    r0,4(r4)
    addi    r3,r3,1
    cmplw   r6,r0
    bne-	.L_802605A8
    clrlwi  r3,r3,24
    b	.L_802605D8
.L_802605A8:
    addi    r4,r4,4
    addi    r3,r3,1
    bdnz+	.L_802604D4
    lis     r3,16
    cmplw   r6,r3
    blt-	.L_802605D4
    addi    r0,r3,8
    cmplw   r6,r0
    bgt-	.L_802605D4
    li      r3,17
    b	.L_802605D8
.L_802605D4:
    li      r3,29
.L_802605D8:
    cmplwi  r5,6
    blt-	.L_802605E4
    li      r5,6
.L_802605E4:
    mulli   r0,r5,30
    clrlwi  r3,r3,24
    add     r3,r3,r0
    blr
.size Convert, . - Convert

#
# === dvdfs.o (dvd.a) ===
#

.global DVDConvertPathToEntrynum
.balign 4
DVDConvertPathToEntrynum:
/* 0x8025B170 | size=0x2F4 (756 bytes) */
    mflr    r0
    stw     r0,4(r1)
    stwu    r1,-72(r1)
    stmw    r20,24(r1)
    mr      r23,r3
    lis     r3,-32700
    addi    r25,r23,0
    addi    r31,r3,-15584
    lwz     r26,-23496(r13)
.L_8025B194:
    lbz     r3,0(r23)
    extsb.  r0,r3
    bne-	.L_8025B1A8
    mr      r3,r26
    b	.L_8025B450
.L_8025B1A8:
    extsb   r0,r3
    cmpwi   r0,47
    bne-	.L_8025B1C0
    li      r26,0
    addi    r23,r23,1
    b	.L_8025B194
.L_8025B1C0:
    cmpwi   r0,46
    bne-	.L_8025B238
    lbz     r3,1(r23)
    extsb   r0,r3
    cmpwi   r0,46
    bne-	.L_8025B218
    lbz     r3,2(r23)
    cmpwi   r3,47
    bne-	.L_8025B1FC
    mulli   r3,r26,12
    lwz     r4,-23508(r13)
    addi    r0,r3,4
    lwzx    r26,r4,r0
    addi    r23,r23,3
    b	.L_8025B194
.L_8025B1FC:
    extsb.  r0,r3
    bne-	.L_8025B238
    mulli   r0,r26,12
    lwz     r3,-23508(r13)
    add     r3,r3,r0
    lwz     r3,4(r3)
    b	.L_8025B450
.L_8025B218:
    cmpwi   r0,47
    bne-	.L_8025B228
    addi    r23,r23,2
    b	.L_8025B194
.L_8025B228:
    extsb.  r0,r3
    bne-	.L_8025B238
    mr      r3,r26
    b	.L_8025B450
.L_8025B238:
    lwz     r0,-23492(r13)
    cmplwi  r0,0
    bne-	.L_8025B2EC
    addi    r28,r23,0
    li      r5,0
    li      r4,0
    b	.L_8025B298
.L_8025B254:
    extsb   r0,r3
    cmpwi   r0,46
    bne-	.L_8025B288
    subf    r0,r23,r28
    cmpwi   r0,8
    bgt-	.L_8025B274
    cmpwi   r5,1
    bne-	.L_8025B27C
.L_8025B274:
    li      r4,1
    b	.L_8025B2B0
.L_8025B27C:
    addi    r24,r28,1
    li      r5,1
    b	.L_8025B294
.L_8025B288:
    cmpwi   r0,32
    bne-	.L_8025B294
    li      r4,1
.L_8025B294:
    addi    r28,r28,1
.L_8025B298:
    lbz     r3,0(r28)
    extsb.  r0,r3
    beq-	.L_8025B2B0
    extsb   r0,r3
    cmpwi   r0,47
    bne+	.L_8025B254
.L_8025B2B0:
    cmpwi   r5,1
    bne-	.L_8025B2C8
    subf    r0,r24,r28
    cmpwi   r0,3
    ble-	.L_8025B2C8
    li      r4,1
.L_8025B2C8:
    cmpwi   r4,0
    beq-	.L_8025B310
    addi    r5,r31,0
    crclr   4*cr1+eq
    addi    r6,r25,0
    addi    r3,r13,-27800
    li      r4,387
    bl	OSPanic
    b	.L_8025B310
.L_8025B2EC:
    mr      r28,r23
    b	.L_8025B2F8
.L_8025B2F4:
    addi    r28,r28,1
.L_8025B2F8:
    lbz     r3,0(r28)
    extsb.  r0,r3
    beq-	.L_8025B310
    extsb   r0,r3
    cmpwi   r0,47
    bne+	.L_8025B2F4
.L_8025B310:
    lbz     r0,0(r28)
    extsb.  r0,r0
    bne-	.L_8025B324
    li      r30,0
    b	.L_8025B328
.L_8025B324:
    li      r30,1
.L_8025B328:
    mulli   r29,r26,12
    subf    r27,r23,r28
    addi    r26,r26,1
    b	.L_8025B418
.L_8025B338:
    mulli   r28,r26,12
    lwzx    r4,r3,r28
    clrrwi. r0,r4,24
    bne-	.L_8025B350
    li      r0,0
    b	.L_8025B354
.L_8025B350:
    li      r0,1
.L_8025B354:
    cmpwi   r0,0
    bne-	.L_8025B364
    cmpwi   r30,1
    beq-	.L_8025B3E0
.L_8025B364:
    lwz     r3,-23504(r13)
    clrlwi  r0,r4,8
    addi    r21,r23,0
    add     r20,r3,r0
    b	.L_8025B3AC
.L_8025B378:
    lbz     r0,0(r20)
    addi    r20,r20,1
    extsb   r3,r0
    bl	tolower
    lbz     r0,0(r21)
    addi    r22,r3,0
    addi    r21,r21,1
    extsb   r3,r0
    bl	tolower
    cmpw    r3,r22
    beq-	.L_8025B3AC
    li      r0,0
    b	.L_8025B3D8
.L_8025B3AC:
    lbz     r0,0(r20)
    extsb.  r0,r0
    bne+	.L_8025B378
    lbz     r3,0(r21)
    cmpwi   r3,47
    beq-	.L_8025B3CC
    extsb.  r0,r3
    bne-	.L_8025B3D4
.L_8025B3CC:
    li      r0,1
    b	.L_8025B3D8
.L_8025B3D4:
    li      r0,0
.L_8025B3D8:
    cmpwi   r0,1
    beq-	.L_8025B434
.L_8025B3E0:
    lwz     r0,-23508(r13)
    add     r3,r0,r28
    lwz     r0,0(r3)
    clrrwi. r0,r0,24
    bne-	.L_8025B3FC
    li      r0,0
    b	.L_8025B400
.L_8025B3FC:
    li      r0,1
.L_8025B400:
    cmpwi   r0,0
    beq-	.L_8025B410
    lwz     r0,8(r3)
    b	.L_8025B414
.L_8025B410:
    addi    r0,r26,1
.L_8025B414:
    mr      r26,r0
.L_8025B418:
    lwz     r3,-23508(r13)
    addi    r0,r3,8
    lwzx    r0,r29,r0
    cmplw   r26,r0
    blt+	.L_8025B338
    li      r3,-1
    b	.L_8025B450
.L_8025B434:
    cmpwi   r30,0
    bne-	.L_8025B444
    mr      r3,r26
    b	.L_8025B450
.L_8025B444:
    add     r23,r27,r23
    addi    r23,r23,1
    b	.L_8025B194
.L_8025B450:
    lmw     r20,24(r1)
    lwz     r0,76(r1)
    addi    r1,r1,72
    mtlr    r0
    blr
.size DVDConvertPathToEntrynum, . - DVDConvertPathToEntrynum

.global entryToPath
.balign 4
entryToPath:
/* 0x8025B5FC | size=0x160 (352 bytes) */
.L_8025B5FC:
    mflr    r0
    cmplwi  r3,0
    stw     r0,4(r1)
    stwu    r1,-48(r1)
    stw     r31,44(r1)
    stw     r30,40(r1)
    addi    r30,r5,0
    stw     r29,36(r1)
    addi    r29,r4,0
    stw     r28,32(r1)
    bne-	.L_8025B630
    li      r3,0
    b	.L_8025B73C
.L_8025B630:
    lwz     r4,-23508(r13)
    mulli   r3,r3,12
    lwz     r6,-23504(r13)
    addi    r5,r4,4
    lwzx    r0,r4,r3
    lwzx    r3,r5,r3
    clrlwi  r0,r0,8
    cmplwi  r3,0
    add     r31,r6,r0
    bne-	.L_8025B660
    li      r3,0
    b	.L_8025B6DC
.L_8025B660:
    mulli   r3,r3,12
    lwzx    r0,r4,r3
    mr      r4,r29
    lwzx    r3,r5,r3
    addi    r5,r30,0
    clrlwi  r0,r0,8
    add     r28,r6,r0
    bl	.L_8025B5FC
    cmplw   r3,r30
    bne-	.L_8025B68C
    b	.L_8025B6DC
.L_8025B68C:
    addi    r0,r3,0
    addi    r3,r3,1
    li      r4,47
    subf    r6,r3,r30
    stbx    r4,r29,r0
    addi    r4,r6,0
    add     r5,r29,r3
    b	.L_8025B6C0
.L_8025B6AC:
    lbz     r0,0(r28)
    addi    r28,r28,1
    addi    r4,r4,-1
    stb     r0,0(r5)
    addi    r5,r5,1
.L_8025B6C0:
    cmplwi  r4,0
    beq-	.L_8025B6D4
    lbz     r0,0(r28)
    extsb.  r0,r0
    bne+	.L_8025B6AC
.L_8025B6D4:
    subf    r0,r4,r6
    add     r3,r3,r0
.L_8025B6DC:
    cmplw   r3,r30
    bne-	.L_8025B6E8
    b	.L_8025B73C
.L_8025B6E8:
    addi    r0,r3,0
    addi    r3,r3,1
    li      r4,47
    subf    r7,r3,r30
    stbx    r4,r29,r0
    addi    r6,r31,0
    addi    r4,r7,0
    add     r5,r29,r3
    b	.L_8025B720
.L_8025B70C:
    lbz     r0,0(r6)
    addi    r6,r6,1
    addi    r4,r4,-1
    stb     r0,0(r5)
    addi    r5,r5,1
.L_8025B720:
    cmplwi  r4,0
    beq-	.L_8025B734
    lbz     r0,0(r6)
    extsb.  r0,r0
    bne+	.L_8025B70C
.L_8025B734:
    subf    r0,r4,r7
    add     r3,r3,r0
.L_8025B73C:
    lwz     r0,52(r1)
    lwz     r31,44(r1)
    lwz     r30,40(r1)
    lwz     r29,36(r1)
    lwz     r28,32(r1)
    addi    r1,r1,48
    mtlr    r0
    blr
.size entryToPath, . - entryToPath

.global DVDConvertEntrynumToPath
.balign 4
DVDConvertEntrynumToPath:
/* 0x8025B75C | size=0x154 (340 bytes) */
    mflr    r0
    stw     r0,4(r1)
    stwu    r1,-40(r1)
    stw     r31,36(r1)
    addi    r31,r5,0
    stw     r30,32(r1)
    addi    r30,r4,0
    stw     r29,28(r1)
    mr.     r29,r3
    stw     r28,24(r1)
    bne-	.L_8025B790
    li      r3,0
    b	.L_8025B818
.L_8025B790:
    mulli   r3,r29,12
    lwz     r4,-23508(r13)
    lwz     r6,-23504(r13)
    lwzx    r0,r4,r3
    add     r3,r4,r3
    lwz     r3,4(r3)
    addi    r4,r30,0
    clrlwi  r0,r0,8
    addi    r5,r31,0
    add     r28,r6,r0
    bl	entryToPath
    cmplw   r3,r31
    bne-	.L_8025B7C8
    b	.L_8025B818
.L_8025B7C8:
    addi    r0,r3,0
    addi    r3,r3,1
    li      r4,47
    subf    r6,r3,r31
    stbx    r4,r30,r0
    addi    r4,r6,0
    add     r5,r30,r3
    b	.L_8025B7FC
.L_8025B7E8:
    lbz     r0,0(r28)
    addi    r28,r28,1
    addi    r4,r4,-1
    stb     r0,0(r5)
    addi    r5,r5,1
.L_8025B7FC:
    cmplwi  r4,0
    beq-	.L_8025B810
    lbz     r0,0(r28)
    extsb.  r0,r0
    bne+	.L_8025B7E8
.L_8025B810:
    subf    r0,r4,r6
    add     r3,r3,r0
.L_8025B818:
    cmplw   r3,r31
    bne-	.L_8025B834
    add     r3,r30,r31
    li      r0,0
    stb     r0,-1(r3)
    li      r3,0
    b	.L_8025B890
.L_8025B834:
    mulli   r0,r29,12
    lwz     r4,-23508(r13)
    lwzx    r0,r4,r0
    clrrwi. r0,r0,24
    bne-	.L_8025B850
    li      r0,0
    b	.L_8025B854
.L_8025B850:
    li      r0,1
.L_8025B854:
    cmpwi   r0,0
    beq-	.L_8025B884
    addi    r0,r31,-1
    cmplw   r3,r0
    bne-	.L_8025B878
    li      r0,0
    stbx    r0,r30,r3
    li      r3,0
    b	.L_8025B890
.L_8025B878:
    li      r0,47
    stbx    r0,r30,r3
    addi    r3,r3,1
.L_8025B884:
    li      r0,0
    stbx    r0,r30,r3
    li      r3,1
.L_8025B890:
    lwz     r0,44(r1)
    lwz     r31,36(r1)
    lwz     r30,32(r1)
    lwz     r29,28(r1)
    lwz     r28,24(r1)
    addi    r1,r1,40
    mtlr    r0
    blr
.size DVDConvertEntrynumToPath, . - DVDConvertEntrynumToPath

.global DVDReadPrio
.balign 4
DVDReadPrio:
/* 0x8025BAC4 | size=0x118 (280 bytes) */
    mflr    r0
    stw     r0,4(r1)
    stwu    r1,-56(r1)
    stmw    r27,36(r1)
    mr.     r29,r6
    addi    r31,r3,0
    addi    r27,r4,0
    addi    r28,r5,0
    addi    r30,r7,0
    blt-	.L_8025BAF8
    lwz     r0,52(r31)
    cmplw   r29,r0
    ble-	.L_8025BB10
.L_8025BAF8:
    lis     r3,-32700
    crclr   4*cr1+eq
    addi    r5,r3,-15276
    addi    r3,r13,-27800
    li      r4,820
    bl	OSPanic
.L_8025BB10:
    add.    r4,r29,r28
    blt-	.L_8025BB28
    lwz     r3,52(r31)
    addi    r0,r3,32
    cmplw   r4,r0
    blt-	.L_8025BB40
.L_8025BB28:
    lis     r3,-32700
    crclr   4*cr1+eq
    addi    r5,r3,-15276
    addi    r3,r13,-27800
    li      r4,826
    bl	OSPanic
.L_8025BB40:
    lwz     r0,48(r31)
    lis     r4,-32730
    addi    r7,r4,-17444
    addi    r3,r31,0
    addi    r4,r27,0
    addi    r5,r28,0
    addi    r8,r30,0
    add     r6,r0,r29
    bl	DVDReadAbsAsyncPrio
    cmpwi   r3,0
    bne-	.L_8025BB74
    li      r3,-1
    b	.L_8025BBC8
.L_8025BB74:
    bl	OSDisableInterrupts
    mr      r30,r3
.L_8025BB7C:
    lwz     r0,12(r31)
    cmpwi   r0,0
    bne-	.L_8025BB90
    lwz     r31,32(r31)
    b	.L_8025BBBC
.L_8025BB90:
    cmpwi   r0,-1
    bne-	.L_8025BBA0
    li      r31,-1
    b	.L_8025BBBC
.L_8025BBA0:
    cmpwi   r0,10
    bne-	.L_8025BBB0
    li      r31,-3
    b	.L_8025BBBC
.L_8025BBB0:
    addi    r3,r13,-23488
    bl	OSSleepThread
    b	.L_8025BB7C
.L_8025BBBC:
    mr      r3,r30
    bl	OSRestoreInterrupts
    mr      r3,r31
.L_8025BBC8:
    lmw     r27,36(r1)
    lwz     r0,60(r1)
    addi    r1,r1,56
    mtlr    r0
    blr
.size DVDReadPrio, . - DVDReadPrio

.global DVDPrepareStream
.balign 4
DVDPrepareStream:
/* 0x8025C0C4 | size=0x144 (324 bytes) */
    mflr    r0
    stw     r0,4(r1)
    stwu    r1,-48(r1)
    stmw    r27,28(r1)
    addi    r29,r5,0
    mr      r27,r3
    addi    r28,r4,0
    lwz     r6,48(r3)
    lis     r3,-32700
    addi    r31,r3,-15584
    add     r5,r6,r29
    clrlwi. r0,r5,17
    addi    r30,r5,0
    beq-	.L_8025C114
    crclr   4*cr1+eq
    addi    r7,r29,0
    addi    r5,r31,740
    addi    r3,r13,-27800
    li      r4,1288
    bl	OSPanic
.L_8025C114:
    cmplwi  r28,0
    bne-	.L_8025C124
    lwz     r0,52(r27)
    subf    r28,r29,r0
.L_8025C124:
    clrlwi. r0,r28,17
    beq-	.L_8025C144
    addi    r6,r28,0
    crclr   4*cr1+eq
    addi    r5,r31,840
    addi    r3,r13,-27800
    li      r4,1298
    bl	OSPanic
.L_8025C144:
    lwz     r3,52(r27)
    cmplw   r29,r3
    bgt-	.L_8025C15C
    add     r0,r29,r28
    cmplw   r0,r3
    ble-	.L_8025C178
.L_8025C15C:
    addi    r6,r29,0
    crclr   4*cr1+eq
    addi    r7,r28,0
    addi    r5,r31,920
    addi    r3,r13,-27800
    li      r4,1306
    bl	OSPanic
.L_8025C178:
    lis     r4,-32730
    addi    r6,r4,-15864
    addi    r3,r27,0
    addi    r4,r28,0
    addi    r5,r30,0
    bl	DVDPrepareStreamAbsAsync
    cmpwi   r3,0
    bne-	.L_8025C1A0
    li      r3,-1
    b	.L_8025C1F4
.L_8025C1A0:
    bl	OSDisableInterrupts
    mr      r31,r3
.L_8025C1A8:
    lwz     r0,12(r27)
    cmpwi   r0,0
    bne-	.L_8025C1BC
    li      r30,0
    b	.L_8025C1E8
.L_8025C1BC:
    cmpwi   r0,-1
    bne-	.L_8025C1CC
    li      r30,-1
    b	.L_8025C1E8
.L_8025C1CC:
    cmpwi   r0,10
    bne-	.L_8025C1DC
    li      r30,-3
    b	.L_8025C1E8
.L_8025C1DC:
    addi    r3,r13,-23488
    bl	OSSleepThread
    b	.L_8025C1A8
.L_8025C1E8:
    mr      r3,r31
    bl	OSRestoreInterrupts
    mr      r3,r30
.L_8025C1F4:
    lmw     r27,28(r1)
    lwz     r0,52(r1)
    addi    r1,r1,48
    mtlr    r0
    blr
.size DVDPrepareStream, . - DVDPrepareStream

#
# === dvdlow.o (dvd.a) ===
#

.global __DVDInterruptHandler
.balign 4
__DVDInterruptHandler:
/* 0x80260C60 | size=0x2E0 (736 bytes) */
    mflr    r0
    lis     r3,-32694
    stw     r0,4(r1)
    stwu    r1,-752(r1)
    stmw    r27,732(r1)
    addi    r28,r4,0
    addi    r30,r3,-16952
    li      r29,0
    lwz     r0,-23296(r13)
    cmpwi   r0,0
    beq-	.L_80260CC8
    bl	__OSGetSystemTime
    stw     r4,-23308(r13)
    li      r0,0
    stw     r3,-23312(r13)
    stw     r0,-27680(r13)
    lwz     r0,196(r30)
    stw     r0,184(r30)
    lwz     r0,200(r30)
    stw     r0,188(r30)
    lwz     r0,204(r30)
    stw     r0,192(r30)
    lwz     r0,-23360(r13)
    cmpwi   r0,1
    bne-	.L_80260CC8
    ori     r29,r29,8
.L_80260CC8:
    li      r0,0
    stw     r0,-23296(r13)
    lis     r3,-13312
    stw     r0,-23360(r13)
    lwz     r0,24576(r3)
    andi.   r31,r0,42
    andi.   r3,r0,84
    slwi    r0,r31,1
    and     r27,r3,r0
    rlwinm. r0,r27,0,25,25
    beq-	.L_80260CF8
    ori     r29,r29,8
.L_80260CF8:
    rlwinm. r0,r27,0,27,27
    beq-	.L_80260D04
    ori     r29,r29,1
.L_80260D04:
    rlwinm. r0,r27,0,29,29
    beq-	.L_80260D10
    ori     r29,r29,2
.L_80260D10:
    cmplwi  r29,0
    beq-	.L_80260D28
    li      r0,0
    stw     r0,-23336(r13)
    addi    r3,r30,104
    bl	OSCancelAlarm
.L_80260D28:
    or      r0,r27,r31
    lis     r31,-13312
    stw     r0,24576(r31)
    lwz     r0,-23336(r13)
    cmplwi  r0,0
    beq-	.L_80260DDC
    bl	__OSGetSystemTime
    lis     r5,-32768
    lwz     r7,-23344(r13)
    lwz     r6,248(r5)
    lis     r5,4194
    addi    r5,r5,19923
    lwz     r8,-23340(r13)
    srwi    r6,r6,2
    mulhwu  r5,r5,r6
    srwi    r5,r5,6
    mulli   r5,r5,200
    subfc   r6,r8,r4
    subfe   r3,r7,r3
    li      r0,0
    xoris   r4,r3,32768
    xoris   r3,r0,32768
    subfc   r0,r5,r6
    subfe   r3,r3,r4
    subfe   r3,r4,r4
    neg.    r3,r3
    beq-	.L_80260DDC
    addi    r27,r31,24576
    lwzu    r0,4(r27)
    rlwinm  r3,r0,0,29,29
    rlwinm  r0,r0,1,29,29
    and     r0,r3,r0
    rlwinm. r0,r0,0,29,29
    beq-	.L_80260DD0
    lwz     r12,-23348(r13)
    cmplwi  r12,0
    beq-	.L_80260DC8
    mtlr    r12
    li      r3,4
    blrl
.L_80260DC8:
    li      r0,0
    stw     r0,-23348(r13)
.L_80260DD0:
    lwz     r0,0(r27)
    stw     r0,0(r27)
    b	.L_80260E30
.L_80260DDC:
    lwz     r0,-23332(r13)
    cmpwi   r0,0
    beq-	.L_80260E24
    lis     r3,-13312
    addi    r5,r3,24576
    lwzu    r0,4(r5)
    rlwinm  r4,r0,0,30,30
    rlwinm  r3,r0,0,29,29
    rlwinm  r0,r0,1,29,29
    and     r3,r3,r0
    rlwinm. r0,r3,0,29,29
    beq-	.L_80260E10
    ori     r29,r29,4
.L_80260E10:
    or      r0,r3,r4
    stw     r0,0(r5)
    li      r0,0
    stw     r0,-23332(r13)
    b	.L_80260E30
.L_80260E24:
    lis     r3,-13312
    li      r0,0
    stw     r0,24580(r3)
.L_80260E30:
    rlwinm. r0,r29,0,28,28
    beq-	.L_80260E48
    lwz     r0,-23328(r13)
    cmpwi   r0,0
    bne-	.L_80260E48
    rlwinm  r29,r29,0,29,27
.L_80260E48:
    clrlwi. r0,r29,31
    beq-	.L_80260ECC
    lwz     r0,-23292(r13)
    mulli   r0,r0,20
    lwzx    r3,r30,r0
    cmpwi   r3,1
    bne-	.L_80260E90
    lwz     r3,-23292(r13)
    add     r6,r30,r0
    addi    r0,r3,1
    stw     r0,-23292(r13)
    lwz     r3,4(r6)
    lwz     r4,8(r6)
    lwz     r5,12(r6)
    lwz     r6,16(r6)
    bl	Read
    li      r0,1
    b	.L_80260EC0
.L_80260E90:
    cmpwi   r3,2
    bne-	.L_80260EBC
    lwz     r3,-23292(r13)
    add     r4,r30,r0
    addi    r0,r3,1
    stw     r0,-23292(r13)
    lwz     r3,12(r4)
    lwz     r4,16(r4)
    bl	DVDLowSeek
    li      r0,1
    b	.L_80260EC0
.L_80260EBC:
    li      r0,0
.L_80260EC0:
    cmpwi   r0,0
    beq-	.L_80260EDC
    b	.L_80260F2C
.L_80260ECC:
    li      r0,-1
    stw     r0,0(r30)
    li      r0,0
    stw     r0,-23292(r13)
.L_80260EDC:
    addi    r3,r1,16
    bl	OSClearContext
    addi    r3,r1,16
    bl	OSSetCurrentContext
    cmplwi  r29,0
    beq-	.L_80260F1C
    lwz     r12,-23352(r13)
    li      r0,0
    cmplwi  r12,0
    stw     r0,-23352(r13)
    beq-	.L_80260F14
    mtlr    r12
    addi    r3,r29,0
    blrl
.L_80260F14:
    li      r0,0
    stw     r0,-23328(r13)
.L_80260F1C:
    addi    r3,r1,16
    bl	OSClearContext
    mr      r3,r28
    bl	OSSetCurrentContext
.L_80260F2C:
    lmw     r27,732(r1)
    lwz     r0,756(r1)
    addi    r1,r1,752
    mtlr    r0
    blr
.size __DVDInterruptHandler, . - __DVDInterruptHandler

.global Read
.balign 4
Read:
/* 0x80261098 | size=0x110 (272 bytes) */
    mflr    r0
    stw     r0,4(r1)
    li      r0,0
    stwu    r1,-40(r1)
    stw     r31,36(r1)
    stw     r30,32(r1)
    addi    r30,r5,0
    stw     r29,28(r1)
    addi    r29,r4,0
    stw     r28,24(r1)
    addi    r28,r3,0
    stw     r0,-23360(r13)
    li      r0,1
    stw     r6,-23352(r13)
    lis     r6,-32694
    addi    r31,r6,-16952
    stw     r0,-23296(r13)
    bl	__OSGetSystemTime
    stw     r4,-23300(r13)
    lis     r4,-13312
    lis     r0,160
    stw     r3,-23304(r13)
    addi    r4,r4,24576
    lis     r3,-22528
    stw     r3,8(r4)
    srwi    r3,r30,2
    cmplw   r29,r0
    stw     r3,12(r4)
    li      r0,3
    stw     r29,16(r4)
    stw     r28,20(r4)
    stw     r29,24(r4)
    stw     r29,-23356(r13)
    stw     r0,28(r4)
    ble-	.L_80261158
    lis     r3,-32768
    lwz     r0,248(r3)
    addi    r3,r31,104
    srwi    r0,r0,2
    mulli   r30,r0,20
    bl	OSCreateAlarm
    lis     r3,-32730
    addi    r7,r3,4036
    addi    r6,r30,0
    addi    r3,r31,104
    li      r5,0
    bl	OSSetAlarm
    b	.L_80261188
.L_80261158:
    lis     r3,-32768
    lwz     r0,248(r3)
    addi    r3,r31,104
    srwi    r0,r0,2
    mulli   r30,r0,10
    bl	OSCreateAlarm
    lis     r3,-32730
    addi    r7,r3,4036
    addi    r6,r30,0
    addi    r3,r31,104
    li      r5,0
    bl	OSSetAlarm
.L_80261188:
    lwz     r0,44(r1)
    lwz     r31,36(r1)
    lwz     r30,32(r1)
    lwz     r29,28(r1)
    lwz     r28,24(r1)
    addi    r1,r1,40
    mtlr    r0
    blr
.size Read, . - Read

.global DVDLowRead
.balign 4
DVDLowRead:
/* 0x802613C0 | size=0x298 (664 bytes) */
    mflr    r0
    lis     r7,-13312
    stw     r0,4(r1)
    stwu    r1,-64(r1)
    stmw    r22,24(r1)
    addi    r25,r4,0
    addi    r4,r7,24576
    lis     r7,-32694
    addi    r31,r7,-16952
    addi    r24,r3,0
    addi    r26,r5,0
    addi    r30,r31,204
    mr      r27,r6
    stw     r25,24(r4)
    stw     r24,196(r31)
    stw     r25,200(r31)
    stw     r26,204(r31)
    lwz     r0,-23324(r13)
    cmplwi  r0,0
    bne-	.L_80261438
    li      r0,-1
    stw     r0,0(r31)
    li      r0,0
    addi    r3,r24,0
    stw     r0,-23292(r13)
    addi    r4,r25,0
    addi    r5,r26,0
    addi    r6,r27,0
    bl	Read
    b	.L_80261640
.L_80261438:
    lwz     r0,-23324(r13)
    cmplwi  r0,1
    bne-	.L_80261640
    lwz     r0,-27680(r13)
    cmpwi   r0,0
    beq-	.L_80261468
    addi    r3,r24,0
    addi    r4,r25,0
    addi    r5,r26,0
    addi    r6,r27,0
    bl	SeekTwiceBeforeRead
    b	.L_80261640
.L_80261468:
    addi    r29,r31,188
    lwz     r0,0(r30)
    addi    r28,r31,192
    lwz     r3,188(r31)
    lwz     r4,192(r31)
    srwi    r23,r0,15
    addi    r0,r3,-1
    add     r0,r4,r0
    srwi    r22,r0,15
    bl	DVDGetCurrentDiskID
    lbz     r0,8(r3)
    cmplwi  r0,0
    beq-	.L_802614A4
    li      r0,1
    b	.L_802614A8
.L_802614A4:
    li      r0,0
.L_802614A8:
    cmpwi   r0,0
    beq-	.L_802614B8
    li      r3,5
    b	.L_802614BC
.L_802614B8:
    li      r3,15
.L_802614BC:
    addi    r0,r22,-2
    cmplw   r23,r0
    bgt-	.L_802614D8
    addi    r0,r3,3
    add     r0,r22,r0
    cmplw   r23,r0
    bge-	.L_802614E0
.L_802614D8:
    li      r0,1
    b	.L_802614E4
.L_802614E0:
    li      r0,0
.L_802614E4:
    cmpwi   r0,0
    bne-	.L_80261514
    li      r0,-1
    stw     r0,0(r31)
    li      r0,0
    addi    r3,r24,0
    stw     r0,-23292(r13)
    addi    r4,r25,0
    addi    r5,r26,0
    addi    r6,r27,0
    bl	Read
    b	.L_80261640
.L_80261514:
    lwz     r3,0(r29)
    lwz     r4,0(r28)
    addi    r3,r3,-1
    lwz     r0,0(r30)
    add     r3,r4,r3
    srwi    r3,r3,15
    srwi    r4,r0,15
    cmplw   r3,r4
    beq-	.L_80261544
    addi    r0,r3,1
    cmplw   r0,r4
    bne-	.L_8026162C
.L_80261544:
    bl	__OSGetSystemTime
    lis     r5,-32768
    lwz     r8,-23312(r13)
    lwz     r0,248(r5)
    lis     r5,4194
    lwz     r9,-23308(r13)
    li      r6,0
    srwi    r7,r0,2
    addi    r0,r5,19923
    mulhwu  r0,r0,r7
    srwi    r0,r0,6
    subfc   r9,r9,r4
    subfe   r8,r8,r3
    mulli   r5,r0,5
    xoris   r4,r6,32768
    xoris   r3,r8,32768
    subfc   r0,r9,r5
    subfe   r3,r3,r4
    subfe   r3,r4,r4
    neg.    r3,r3
    beq-	.L_802615BC
    li      r0,-1
    stw     r0,0(r31)
    addi    r3,r24,0
    addi    r4,r25,0
    stw     r6,-23292(r13)
    addi    r5,r26,0
    addi    r6,r27,0
    bl	Read
    b	.L_80261640
.L_802615BC:
    li      r0,1
    stw     r0,0(r31)
    lis     r3,17180
    addi    r0,r3,-8573
    stw     r24,4(r31)
    mulhwu  r0,r0,r7
    stw     r25,8(r31)
    stw     r26,12(r31)
    srwi    r0,r0,15
    mulli   r3,r0,500
    stw     r27,16(r31)
    li      r0,-1
    stw     r0,20(r31)
    subfc   r5,r9,r5
    subfe   r4,r8,r6
    srwi    r0,r3,3
    stw     r6,-23292(r13)
    addc    r23,r5,r0
    adde    r22,r4,r6
    addi    r3,r31,64
    bl	OSCreateAlarm
    lis     r3,-32730
    addi    r7,r3,3904
    addi    r6,r23,0
    addi    r5,r22,0
    addi    r3,r31,64
    bl	OSSetAlarm
    b	.L_80261640
.L_8026162C:
    addi    r3,r24,0
    addi    r4,r25,0
    addi    r5,r26,0
    addi    r6,r27,0
    bl	SeekTwiceBeforeRead
.L_80261640:
    lmw     r22,24(r1)
    li      r3,1
    lwz     r0,68(r1)
    addi    r1,r1,64
    mtlr    r0
    blr
.size DVDLowRead, . - DVDLowRead

#
# === dvdqueue.o (dvd.a) ===
#

.global DVDDumpWaitingQueue
.balign 4
DVDDumpWaitingQueue:
/* 0x8026026C | size=0x10C (268 bytes) */
    mflr    r0
    lis     r3,-32700
    stw     r0,4(r1)
    crclr   4*cr1+eq
    stwu    r1,-24(r1)
    stw     r31,20(r1)
    addi    r31,r3,-14184
    addi    r3,r31,236
    stw     r30,16(r1)
    stw     r29,12(r1)
    stw     r28,8(r1)
    bl	OSReport
    lis     r3,-32694
    addi    r30,r3,-17096
    li      r29,0
.L_802602A8:
    addi    r4,r29,0
    crclr   4*cr1+eq
    addi    r3,r31,272
    bl	OSReport
    lwz     r0,0(r30)
    cmplw   r0,r30
    bne-	.L_802602D4
    addi    r3,r13,-27716
    crclr   4*cr1+eq
    bl	OSReport
    b	.L_80260348
.L_802602D4:
    addi    r3,r13,-27708
    crclr   4*cr1+eq
    bl	OSReport
    lwz     r28,0(r30)
    b	.L_80260340
.L_802602E8:
    lwz     r0,8(r28)
    addi    r4,r28,0
    addi    r3,r31,288
    crclr   4*cr1+eq
    slwi    r0,r0,2
    add     r5,r31,r0
    lwz     r5,172(r5)
    bl	OSReport
    lwz     r0,8(r28)
    cmplwi  r0,1
    bne-	.L_80260330
    lwz     r4,16(r28)
    addi    r3,r31,312
    lwz     r5,20(r28)
    crclr   4*cr1+eq
    lwz     r6,24(r28)
    bl	OSReport
    b	.L_8026033C
.L_80260330:
    addi    r3,r13,-27708
    crclr   4*cr1+eq
    bl	OSReport
.L_8026033C:
    lwz     r28,0(r28)
.L_80260340:
    cmplw   r28,r30
    bne+	.L_802602E8
.L_80260348:
    addi    r29,r29,1
    cmplwi  r29,4
    addi    r30,r30,8
    blt+	.L_802602A8
    lwz     r0,28(r1)
    lwz     r31,20(r1)
    lwz     r30,16(r1)
    lwz     r29,12(r1)
    lwz     r28,8(r1)
    addi    r1,r1,24
    mtlr    r0
    blr
.size DVDDumpWaitingQueue, . - DVDDumpWaitingQueue

#
# === fstload.o (dvd.a) ===
#

.global __fstLoad
.balign 4
__fstLoad:
/* 0x80260A24 | size=0x168 (360 bytes) */
    mflr    r0
    lis     r3,-32700
    stw     r0,4(r1)
    stwu    r1,-96(r1)
    stw     r31,92(r1)
    addi    r31,r3,-12808
    stw     r30,88(r1)
    stw     r29,84(r1)
    bl	OSGetArenaHi
    lis     r3,-32694
    addi    r3,r3,-17064
    addi    r4,r1,43
    addi    r0,r3,31
    clrrwi  r3,r4,5
    clrrwi  r0,r0,5
    stw     r3,-23368(r13)
    stw     r0,-23372(r13)
    bl	DVDReset
    lis     r3,-32694
    lwz     r4,-23368(r13)
    lis     r5,-32730
    addi    r3,r3,-17000
    addi    r5,r5,2380
    bl	DVDReadDiskID
.L_80260A84:
    bl	DVDGetDriveStatus
    cmpwi   r3,0
    bne+	.L_80260A84
    lwz     r3,-23372(r13)
    lis     r29,-32768
    lis     r30,-32768
    lwz     r0,16(r3)
    addi    r3,r29,0
    li      r5,32
    stw     r0,56(r30)
    lwz     r4,-23372(r13)
    lwz     r0,12(r4)
    stw     r0,60(r30)
    lwz     r4,-23368(r13)
    bl	memcpy
    addi    r3,r13,-27696
    crclr   4*cr1+eq
    bl	OSReport
    lbz     r4,0(r29)
    mr      r3,r31
    lbz     r5,1(r29)
    crclr   4*cr1+eq
    lbz     r6,2(r29)
    lbz     r7,3(r29)
    extsb   r4,r4
    extsb   r5,r5
    extsb   r6,r6
    extsb   r7,r7
    bl	OSReport
    lbz     r4,4(r29)
    addi    r3,r31,28
    lbz     r5,5(r29)
    crclr   4*cr1+eq
    extsb   r4,r4
    extsb   r5,r5
    bl	OSReport
    lbz     r4,6(r29)
    addi    r3,r31,52
    crclr   4*cr1+eq
    bl	OSReport
    lbz     r4,7(r29)
    addi    r3,r31,72
    crclr   4*cr1+eq
    bl	OSReport
    lbz     r0,8(r30)
    cmplwi  r0,0
    bne-	.L_80260B48
    addi    r4,r13,-27692
    b	.L_80260B4C
.L_80260B48:
    addi    r4,r13,-27688
.L_80260B4C:
    crclr   4*cr1+eq
    addi    r3,r31,92
    bl	OSReport
    addi    r3,r13,-27696
    crclr   4*cr1+eq
    bl	OSReport
    lwz     r3,-23372(r13)
    lwz     r3,16(r3)
    bl	OSSetArenaHi
    lwz     r0,100(r1)
    lwz     r31,92(r1)
    lwz     r30,88(r1)
    lwz     r29,84(r1)
    addi    r1,r1,96
    mtlr    r0
    blr
.size __fstLoad, . - __fstLoad

#
# === EXIBios.o (exi.a) ===
#

# Original symbol: CompleteTransfer
.global EXIBios_CompleteTransfer
.balign 4
EXIBios_CompleteTransfer:
/* 0x80256490 | size=0x154 (340 bytes) */
    slwi    r5,r3,6
    lis     r4,-32694
    addi    r0,r4,-22064
    add     r4,r0,r5
    lwz     r0,12(r4)
    clrlwi. r0,r0,30
    beqlr-
    lwz     r0,12(r4)
    rlwinm. r0,r0,0,30,30
    beq-	.L_802565D4
    lwz     r6,16(r4)
    cmpwi   r6,0
    beq-	.L_802565D4
    lwz     r5,20(r4)
    lis     r7,-13312
    addi    r7,r7,26624
    mulli   r0,r3,20
    add     r3,r7,r0
    lwz     r0,16(r3)
    li      r3,0
    ble-	.L_802565D4
    addi    r8,r6,-8
    cmpwi   r6,8
    ble-	.L_802565A8
    addi    r7,r8,7
    srwi    r7,r7,3
    mtctr   r7
    cmpwi   r8,0
    ble-	.L_802565A8
.L_80256504:
    subfic  r7,r3,3
    slwi    r7,r7,3
    srw     r7,r0,r7
    stb     r7,0(r5)
    addi    r7,r3,1
    subfic  r7,r7,3
    slwi    r7,r7,3
    srw     r7,r0,r7
    stb     r7,1(r5)
    addi    r7,r3,2
    subfic  r7,r7,3
    slwi    r7,r7,3
    srw     r7,r0,r7
    stb     r7,2(r5)
    neg     r7,r3
    slwi    r7,r7,3
    srw     r7,r0,r7
    stb     r7,3(r5)
    addi    r7,r3,4
    subfic  r7,r7,3
    slwi    r7,r7,3
    srw     r7,r0,r7
    stb     r7,4(r5)
    addi    r7,r3,5
    subfic  r7,r7,3
    slwi    r7,r7,3
    srw     r7,r0,r7
    stb     r7,5(r5)
    addi    r7,r3,6
    subfic  r7,r7,3
    slwi    r7,r7,3
    srw     r7,r0,r7
    stb     r7,6(r5)
    addi    r7,r3,7
    subfic  r7,r7,3
    slwi    r7,r7,3
    srw     r7,r0,r7
    stb     r7,7(r5)
    addi    r5,r5,8
    addi    r3,r3,8
    bdnz+	.L_80256504
.L_802565A8:
    subf    r7,r3,r6
    mtctr   r7
    cmpw    r3,r6
    bge-	.L_802565D4
.L_802565B8:
    subfic  r6,r3,3
    slwi    r6,r6,3
    srw     r6,r0,r6
    stb     r6,0(r5)
    addi    r5,r5,1
    addi    r3,r3,1
    bdnz+	.L_802565B8
.L_802565D4:
    lwz     r0,12(r4)
    clrrwi  r0,r0,2
    stw     r0,12(r4)
    blr
.size EXIBios_CompleteTransfer, . - EXIBios_CompleteTransfer

.global EXIImm
.balign 4
EXIImm:
/* 0x802565E4 | size=0x25C (604 bytes) */
    mflr    r0
    stw     r0,4(r1)
    stwu    r1,-64(r1)
    stmw    r25,36(r1)
    addi    r26,r3,0
    addi    r27,r4,0
    addi    r28,r5,0
    addi    r29,r6,0
    addi    r25,r7,0
    slwi    r4,r3,6
    lis     r3,-32694
    addi    r0,r3,-22064
    add     r31,r0,r4
    bl	OSDisableInterrupts
    mr      r30,r3
    lwz     r0,12(r31)
    clrlwi. r0,r0,30
    bne-	.L_80256638
    lwz     r0,12(r31)
    rlwinm. r0,r0,0,29,29
    bne-	.L_80256648
.L_80256638:
    mr      r3,r30
    bl	OSRestoreInterrupts
    li      r3,0
    b	.L_8025682C
.L_80256648:
    stw     r25,4(r31)
    lwz     r0,4(r31)
    cmplwi  r0,0
    beq-	.L_8025667C
    addi    r3,r26,0
    li      r4,0
    li      r5,1
    li      r6,0
    bl	EXIClearInterrupts
    lis     r3,32
    mulli   r0,r26,3
    srw     r3,r3,r0
    bl	__OSUnmaskInterrupts
.L_8025667C:
    lwz     r0,12(r31)
    ori     r0,r0,2
    stw     r0,12(r31)
    cmplwi  r29,0
    beq-	.L_802567D0
    li      r0,0
    li      r4,0
    cmpw    r4,r28
    bge-	.L_802567BC
    addi    r6,r28,-8
    cmpwi   r28,8
    ble-	.L_80256824
    addi    r3,r27,0
    addi    r5,r6,7
    srwi    r5,r5,3
    mtctr   r5
    cmpwi   r6,0
    ble-	.L_80256824
.L_802566C4:
    lbz     r6,0(r3)
    subfic  r5,r4,3
    slwi    r5,r5,3
    slw     r5,r6,r5
    or      r0,r0,r5
    lbz     r6,1(r3)
    addi    r5,r4,1
    subfic  r5,r5,3
    slwi    r5,r5,3
    slw     r5,r6,r5
    or      r0,r0,r5
    lbz     r6,2(r3)
    addi    r5,r4,2
    subfic  r5,r5,3
    slwi    r5,r5,3
    slw     r5,r6,r5
    or      r0,r0,r5
    lbz     r6,3(r3)
    neg     r5,r4
    slwi    r5,r5,3
    slw     r5,r6,r5
    or      r0,r0,r5
    lbz     r6,4(r3)
    addi    r5,r4,4
    subfic  r5,r5,3
    slwi    r5,r5,3
    slw     r5,r6,r5
    or      r0,r0,r5
    lbz     r6,5(r3)
    addi    r5,r4,5
    subfic  r5,r5,3
    slwi    r5,r5,3
    slw     r5,r6,r5
    or      r0,r0,r5
    lbz     r6,6(r3)
    addi    r5,r4,6
    subfic  r5,r5,3
    slwi    r5,r5,3
    slw     r5,r6,r5
    or      r0,r0,r5
    lbz     r6,7(r3)
    addi    r5,r4,7
    subfic  r5,r5,3
    slwi    r5,r5,3
    slw     r5,r6,r5
    or      r0,r0,r5
    addi    r3,r3,8
    addi    r4,r4,8
    bdnz+	.L_802566C4
    b	.L_80256824
.L_8025678C:
    subf    r3,r4,r28
    mtctr   r3
    cmpw    r4,r28
    bge-	.L_802567BC
.L_8025679C:
    lbz     r5,0(r6)
    subfic  r3,r4,3
    slwi    r3,r3,3
    slw     r3,r5,r3
    or      r0,r0,r3
    addi    r6,r6,1
    addi    r4,r4,1
    bdnz+	.L_8025679C
.L_802567BC:
    lis     r3,-13312
    addi    r4,r3,26624
    mulli   r3,r26,20
    add     r3,r4,r3
    stw     r0,16(r3)
.L_802567D0:
    stw     r27,20(r31)
    cmplwi  r29,1
    beq-	.L_802567E4
    mr      r0,r28
    b	.L_802567E8
.L_802567E4:
    li      r0,0
.L_802567E8:
    stw     r0,16(r31)
    slwi    r0,r29,2
    ori     r3,r0,1
    addi    r0,r28,-1
    slwi    r0,r0,4
    or      r4,r3,r0
    lis     r3,-13312
    addi    r3,r3,26624
    mulli   r0,r26,20
    add     r3,r3,r0
    stw     r4,12(r3)
    mr      r3,r30
    bl	OSRestoreInterrupts
    li      r3,1
    b	.L_8025682C
.L_80256824:
    add     r6,r27,r4
    b	.L_8025678C
.L_8025682C:
    lwz     r0,68(r1)
    lmw     r25,36(r1)
    addi    r1,r1,64
    mtlr    r0
    blr
.size EXIImm, . - EXIImm

.global EXISync
.balign 4
EXISync:
/* 0x802569CC | size=0x24C (588 bytes) */
    mflr    r0
    stw     r0,4(r1)
    stwu    r1,-48(r1)
    stmw    r27,28(r1)
    slwi    r5,r3,6
    lis     r4,-32694
    addi    r0,r4,-22064
    add     r31,r0,r5
    li      r28,0
    mulli   r30,r3,20
    lis     r3,-13312
    addi    r29,r3,26624
    add     r29,r29,r30
    b	.L_80256BF4
.L_80256A04:
    lwz     r0,12(r29)
    clrlwi. r0,r0,31
    bne-	.L_80256BF4
    bl	OSDisableInterrupts
    mr      r27,r3
    lwz     r0,12(r31)
    rlwinm. r0,r0,0,29,29
    beq-	.L_80256BE8
    lwz     r0,12(r31)
    clrlwi. r0,r0,30
    beq-	.L_80256B60
    lwz     r0,12(r31)
    rlwinm. r0,r0,0,30,30
    beq-	.L_80256B54
    lwz     r3,16(r31)
    cmpwi   r3,0
    beq-	.L_80256B54
    lwz     r5,20(r31)
    lis     r4,-13312
    addi    r0,r4,26624
    add     r4,r0,r30
    lwz     r0,16(r4)
    li      r4,0
    ble-	.L_80256B54
    addi    r7,r3,-8
    cmpwi   r3,8
    ble-	.L_80256B28
    addi    r6,r7,7
    srwi    r6,r6,3
    mtctr   r6
    cmpwi   r7,0
    ble-	.L_80256B28
.L_80256A84:
    subfic  r6,r4,3
    slwi    r6,r6,3
    srw     r6,r0,r6
    stb     r6,0(r5)
    addi    r6,r4,1
    subfic  r6,r6,3
    slwi    r6,r6,3
    srw     r6,r0,r6
    stb     r6,1(r5)
    addi    r6,r4,2
    subfic  r6,r6,3
    slwi    r6,r6,3
    srw     r6,r0,r6
    stb     r6,2(r5)
    neg     r6,r4
    slwi    r6,r6,3
    srw     r6,r0,r6
    stb     r6,3(r5)
    addi    r6,r4,4
    subfic  r6,r6,3
    slwi    r6,r6,3
    srw     r6,r0,r6
    stb     r6,4(r5)
    addi    r6,r4,5
    subfic  r6,r6,3
    slwi    r6,r6,3
    srw     r6,r0,r6
    stb     r6,5(r5)
    addi    r6,r4,6
    subfic  r6,r6,3
    slwi    r6,r6,3
    srw     r6,r0,r6
    stb     r6,6(r5)
    addi    r6,r4,7
    subfic  r6,r6,3
    slwi    r6,r6,3
    srw     r6,r0,r6
    stb     r6,7(r5)
    addi    r5,r5,8
    addi    r4,r4,8
    bdnz+	.L_80256A84
.L_80256B28:
    subf    r6,r4,r3
    mtctr   r6
    cmpw    r4,r3
    bge-	.L_80256B54
.L_80256B38:
    subfic  r3,r4,3
    slwi    r3,r3,3
    srw     r3,r0,r3
    stb     r3,0(r5)
    addi    r5,r5,1
    addi    r4,r4,1
    bdnz+	.L_80256B38
.L_80256B54:
    lwz     r0,12(r31)
    clrrwi  r0,r0,2
    stw     r0,12(r31)
.L_80256B60:
    bl	__OSGetDIConfig
    cmplwi  r3,255
    bne-	.L_80256BE4
    bl	OSGetConsoleType
    clrrwi  r3,r3,28
    addis   r0,r3,-8192
    cmplwi  r0,0
    beq-	.L_80256BE4
    lwz     r0,16(r31)
    cmpwi   r0,4
    bne-	.L_80256BE4
    lwz     r0,0(r29)
    rlwinm. r0,r0,0,25,27
    bne-	.L_80256BE4
    lis     r3,-13312
    addi    r0,r3,26624
    add     r4,r0,r30
    lwzu    r3,16(r4)
    addis   r0,r3,-257
    cmplwi  r0,0
    beq-	.L_80256BD4
    lwz     r3,0(r4)
    addis   r0,r3,-1287
    cmplwi  r0,0
    beq-	.L_80256BD4
    lwz     r3,0(r4)
    addis   r0,r3,-1058
    cmplwi  r0,1
    bne-	.L_80256BE4
.L_80256BD4:
    lis     r3,-32768
    lhz     r0,12518(r3)
    cmplwi  r0,33280
    bne-	.L_80256BE8
.L_80256BE4:
    li      r28,1
.L_80256BE8:
    mr      r3,r27
    bl	OSRestoreInterrupts
    b	.L_80256C00
.L_80256BF4:
    lwz     r0,12(r31)
    rlwinm. r0,r0,0,29,29
    bne+	.L_80256A04
.L_80256C00:
    mr      r3,r28
    lwz     r0,52(r1)
    lmw     r27,28(r1)
    addi    r1,r1,48
    mtlr    r0
    blr
.size EXISync, . - EXISync

.global __EXIProbe
.balign 4
__EXIProbe:
/* 0x80256D28 | size=0x174 (372 bytes) */
    mflr    r0
    stw     r0,4(r1)
    stwu    r1,-40(r1)
    stmw    r27,20(r1)
    addi    r28,r3,0
    slwi    r4,r3,6
    lis     r3,-32694
    addi    r0,r3,-22064
    add     r31,r0,r4
    cmpwi   r28,2
    bne-	.L_80256D5C
    li      r3,1
    b	.L_80256E88
.L_80256D5C:
    li      r29,1
    bl	OSDisableInterrupts
    addi    r30,r3,0
    mulli   r0,r28,20
    lis     r3,-13312
    addi    r3,r3,26624
    add     r3,r3,r0
    lwz     r5,0(r3)
    lwz     r0,12(r31)
    rlwinm. r0,r0,0,28,28
    bne-	.L_80256E50
    rlwinm. r0,r5,0,20,20
    beq-	.L_80256DB8
    lwz     r0,0(r3)
    andi.   r0,r0,2037
    ori     r0,r0,2048
    stw     r0,0(r3)
    li      r4,0
    stw     r4,32(r31)
    slwi    r0,r28,2
    lis     r3,-32768
    addi    r3,r3,12480
    stwx    r4,r3,r0
.L_80256DB8:
    rlwinm. r0,r5,0,19,19
    beq-	.L_80256E30
    lis     r31,-32768
    lwz     r0,248(r31)
    srwi    r0,r0,2
    lis     r3,4194
    addi    r3,r3,19923
    mulhwu  r0,r3,r0
    srwi    r27,r0,6
    bl	OSGetTime
    li      r5,0
    addi    r6,r27,0
    bl	__div2i
    li      r5,0
    li      r6,100
    bl	__div2i
    addi    r4,r4,1
    slwi    r0,r28,2
    addi    r3,r31,12480
    add     r3,r3,r0
    lwz     r0,0(r3)
    cmpwi   r0,0
    bne-	.L_80256E18
    stw     r4,0(r3)
.L_80256E18:
    lwz     r0,0(r3)
    subf    r0,r0,r4
    cmpwi   r0,3
    bge-	.L_80256E7C
    li      r29,0
    b	.L_80256E7C
.L_80256E30:
    li      r4,0
    stw     r4,32(r31)
    slwi    r0,r28,2
    lis     r3,-32768
    addi    r3,r3,12480
    stwx    r4,r3,r0
    li      r29,0
    b	.L_80256E7C
.L_80256E50:
    rlwinm. r0,r5,0,19,19
    beq-	.L_80256E60
    rlwinm. r0,r5,0,20,20
    beq-	.L_80256E7C
.L_80256E60:
    li      r4,0
    stw     r4,32(r31)
    slwi    r0,r28,2
    lis     r3,-32768
    addi    r3,r3,12480
    stwx    r4,r3,r0
    li      r29,0
.L_80256E7C:
    mr      r3,r30
    bl	OSRestoreInterrupts
    mr      r3,r29
.L_80256E88:
    lwz     r0,44(r1)
    lmw     r27,20(r1)
    addi    r1,r1,40
    mtlr    r0
    blr
.size __EXIProbe, . - __EXIProbe

.global EXIAttach
.balign 4
EXIAttach:
/* 0x802570A4 | size=0x10C (268 bytes) */
    mflr    r0
    stw     r0,4(r1)
    stwu    r1,-64(r1)
    stmw    r27,44(r1)
    addi    r27,r3,0
    addi    r28,r4,0
    slwi    r4,r3,6
    lis     r3,-32694
    addi    r0,r3,-22064
    add     r30,r0,r4
    addi    r3,r27,0
    bl	__EXIProbe
    cmpwi   r3,0
    beq-	.L_802570F8
    lwz     r0,32(r30)
    cmpwi   r0,0
    bne-	.L_802570F8
    addi    r3,r27,0
    li      r4,0
    addi    r5,r1,28
    bl	EXIGetID
.L_802570F8:
    bl	OSDisableInterrupts
    mr      r29,r3
    lwz     r0,32(r30)
    cmpwi   r0,0
    bne-	.L_8025711C
    mr      r3,r29
    bl	OSRestoreInterrupts
    li      r3,0
    b	.L_8025719C
.L_8025711C:
    bl	OSDisableInterrupts
    mr      r31,r3
    lwz     r0,12(r30)
    rlwinm. r0,r0,0,28,28
    bne-	.L_80257140
    mr      r3,r27
    bl	__EXIProbe
    cmpwi   r3,0
    bne-	.L_80257150
.L_80257140:
    mr      r3,r31
    bl	OSRestoreInterrupts
    li      r31,0
    b	.L_80257190
.L_80257150:
    addi    r3,r27,0
    li      r4,1
    li      r5,0
    li      r6,0
    bl	EXIClearInterrupts
    stw     r28,8(r30)
    lis     r3,16
    mulli   r0,r27,3
    srw     r3,r3,r0
    bl	__OSUnmaskInterrupts
    lwz     r0,12(r30)
    ori     r0,r0,8
    stw     r0,12(r30)
    mr      r3,r31
    bl	OSRestoreInterrupts
    li      r31,1
.L_80257190:
    mr      r3,r29
    bl	OSRestoreInterrupts
    mr      r3,r31
.L_8025719C:
    lwz     r0,68(r1)
    lmw     r27,44(r1)
    addi    r1,r1,64
    mtlr    r0
    blr
.size EXIAttach, . - EXIAttach

.global EXISelectSD
.balign 4
EXISelectSD:
/* 0x8025726C | size=0x154 (340 bytes) */
    mflr    r0
    stw     r0,4(r1)
    stwu    r1,-56(r1)
    stmw    r27,36(r1)
    addi    r27,r3,0
    addi    r28,r4,0
    addi    r29,r5,0
    slwi    r4,r3,6
    lis     r3,-32694
    addi    r0,r3,-22064
    add     r31,r0,r4
    bl	OSDisableInterrupts
    mr      r30,r3
    lwz     r0,12(r31)
    rlwinm. r0,r0,0,29,29
    bne-	.L_80257328
    cmpwi   r27,2
    beq-	.L_80257338
    cmplwi  r28,0
    bne-	.L_80257310
    lwz     r0,12(r31)
    rlwinm. r0,r0,0,28,28
    bne-	.L_80257310
    mr      r3,r27
    bl	__EXIProbe
    cmpwi   r3,0
    beq-	.L_80257308
    lwz     r0,32(r31)
    cmpwi   r0,0
    bne-	.L_80257308
    addi    r3,r27,0
    li      r4,0
    addi    r5,r1,24
    bl	EXIGetID
    cmpwi   r3,0
    beq-	.L_80257304
    li      r3,1
    b	.L_80257308
.L_80257304:
    li      r3,0
.L_80257308:
    cmpwi   r3,0
    beq-	.L_80257328
.L_80257310:
    lwz     r0,12(r31)
    rlwinm. r0,r0,0,27,27
    beq-	.L_80257328
    lwz     r0,24(r31)
    cmplw   r0,r28
    beq-	.L_80257338
.L_80257328:
    mr      r3,r30
    bl	OSRestoreInterrupts
    li      r3,0
    b	.L_802573AC
.L_80257338:
    lwz     r0,12(r31)
    ori     r0,r0,4
    stw     r0,12(r31)
    mulli   r0,r27,20
    lis     r3,-13312
    addi    r3,r3,26624
    add     r3,r3,r0
    lwz     r4,0(r3)
    andi.   r4,r4,1029
    slwi    r0,r29,4
    or      r4,r4,r0
    stw     r4,0(r3)
    lwz     r0,12(r31)
    rlwinm. r0,r0,0,28,28
    beq-	.L_802573A0
    cmpwi   r27,1
    beq-	.L_80257398
    bge-	.L_802573A0
    cmpwi   r27,0
    bge-	.L_8025738C
    b	.L_802573A0
.L_8025738C:
    lis     r3,16
    bl	__OSMaskInterrupts
    b	.L_802573A0
.L_80257398:
    lis     r3,2
    bl	__OSMaskInterrupts
.L_802573A0:
    mr      r3,r30
    bl	OSRestoreInterrupts
    li      r3,1
.L_802573AC:
    lwz     r0,60(r1)
    lmw     r27,36(r1)
    addi    r1,r1,56
    mtlr    r0
    blr
.size EXISelectSD, . - EXISelectSD

.global EXISelect
.balign 4
EXISelect:
/* 0x802573C0 | size=0x12C (300 bytes) */
    mflr    r0
    stw     r0,4(r1)
    stwu    r1,-48(r1)
    stmw    r27,28(r1)
    addi    r27,r3,0
    addi    r28,r4,0
    addi    r29,r5,0
    slwi    r4,r3,6
    lis     r3,-32694
    addi    r0,r3,-22064
    add     r31,r0,r4
    bl	OSDisableInterrupts
    mr      r30,r3
    lwz     r0,12(r31)
    rlwinm. r0,r0,0,29,29
    bne-	.L_80257444
    cmpwi   r27,2
    beq-	.L_80257454
    cmplwi  r28,0
    bne-	.L_8025742C
    lwz     r0,12(r31)
    rlwinm. r0,r0,0,28,28
    bne-	.L_8025742C
    mr      r3,r27
    bl	__EXIProbe
    cmpwi   r3,0
    beq-	.L_80257444
.L_8025742C:
    lwz     r0,12(r31)
    rlwinm. r0,r0,0,27,27
    beq-	.L_80257444
    lwz     r0,24(r31)
    cmplw   r0,r28
    beq-	.L_80257454
.L_80257444:
    mr      r3,r30
    bl	OSRestoreInterrupts
    li      r3,0
    b	.L_802574D8
.L_80257454:
    lwz     r0,12(r31)
    ori     r0,r0,4
    stw     r0,12(r31)
    mulli   r0,r27,20
    lis     r3,-13312
    addi    r4,r3,26624
    add     r4,r4,r0
    lwz     r5,0(r4)
    andi.   r5,r5,1029
    li      r0,1
    slw     r0,r0,r28
    slwi    r3,r0,7
    slwi    r0,r29,4
    or      r0,r3,r0
    or      r5,r5,r0
    stw     r5,0(r4)
    lwz     r0,12(r31)
    rlwinm. r0,r0,0,28,28
    beq-	.L_802574CC
    cmpwi   r27,1
    beq-	.L_802574C4
    bge-	.L_802574CC
    cmpwi   r27,0
    bge-	.L_802574B8
    b	.L_802574CC
.L_802574B8:
    lis     r3,16
    bl	__OSMaskInterrupts
    b	.L_802574CC
.L_802574C4:
    lis     r3,2
    bl	__OSMaskInterrupts
.L_802574CC:
    mr      r3,r30
    bl	OSRestoreInterrupts
    li      r3,1
.L_802574D8:
    lwz     r0,52(r1)
    lmw     r27,28(r1)
    addi    r1,r1,48
    mtlr    r0
    blr
.size EXISelect, . - EXISelect

.global EXIDeselect
.balign 4
EXIDeselect:
/* 0x802574EC | size=0x110 (272 bytes) */
    mflr    r0
    stw     r0,4(r1)
    stwu    r1,-32(r1)
    stw     r31,28(r1)
    stw     r30,24(r1)
    stw     r29,20(r1)
    stw     r28,16(r1)
    addi    r31,r3,0
    slwi    r4,r3,6
    lis     r3,-32694
    addi    r0,r3,-22064
    add     r30,r0,r4
    bl	OSDisableInterrupts
    mr      r28,r3
    lwz     r0,12(r30)
    rlwinm. r0,r0,0,29,29
    bne-	.L_80257540
    mr      r3,r28
    bl	OSRestoreInterrupts
    li      r3,0
    b	.L_802575DC
.L_80257540:
    lwz     r0,12(r30)
    rlwinm  r0,r0,0,30,28
    stw     r0,12(r30)
    mulli   r0,r31,20
    lis     r3,-13312
    addi    r3,r3,26624
    add     r3,r3,r0
    lwz     r29,0(r3)
    andi.   r0,r29,1029
    stw     r0,0(r3)
    lwz     r0,12(r30)
    rlwinm. r0,r0,0,28,28
    beq-	.L_802575A0
    cmpwi   r31,1
    beq-	.L_80257598
    bge-	.L_802575A0
    cmpwi   r31,0
    bge-	.L_8025758C
    b	.L_802575A0
.L_8025758C:
    lis     r3,16
    bl	__OSUnmaskInterrupts
    b	.L_802575A0
.L_80257598:
    lis     r3,2
    bl	__OSUnmaskInterrupts
.L_802575A0:
    mr      r3,r28
    bl	OSRestoreInterrupts
    cmpwi   r31,2
    beq-	.L_802575D8
    rlwinm. r0,r29,0,24,24
    beq-	.L_802575D8
    mr      r3,r31
    bl	__EXIProbe
    cmpwi   r3,0
    beq-	.L_802575D0
    li      r3,1
    b	.L_802575DC
.L_802575D0:
    li      r3,0
    b	.L_802575DC
.L_802575D8:
    li      r3,1
.L_802575DC:
    lwz     r0,36(r1)
    lwz     r31,28(r1)
    lwz     r30,24(r1)
    lwz     r29,20(r1)
    lwz     r28,16(r1)
    addi    r1,r1,32
    mtlr    r0
    blr
.size EXIDeselect, . - EXIDeselect

.global TCIntrruptHandler
.balign 4
TCIntrruptHandler:
/* 0x802576C4 | size=0x218 (536 bytes) */
    mflr    r0
    stw     r0,4(r1)
    stwu    r1,-760(r1)
    stw     r31,756(r1)
    stw     r30,752(r1)
    stw     r29,748(r1)
    stw     r28,744(r1)
    addi    r28,r4,0
    extsh   r5,r3
    addi    r0,r5,-10
    lis     r3,21845
    addi    r3,r3,21846
    mulhw   r3,r3,r0
    srwi    r0,r3,31
    add     r30,r3,r0
    slwi    r4,r30,6
    lis     r3,-32694
    addi    r0,r3,-22064
    add     r31,r0,r4
    lis     r0,-32768
    srw     r3,r0,r5
    bl	__OSMaskInterrupts
    mulli   r7,r30,20
    lis     r6,-13312
    addi    r3,r6,26624
    add     r3,r3,r7
    lwz     r0,0(r3)
    andi.   r0,r0,2037
    ori     r0,r0,8
    stw     r0,0(r3)
    lwz     r0,4(r31)
    mr      r29,r0
    cmplwi  r0,0
    beq-	.L_802578BC
    li      r4,0
    stw     r4,4(r31)
    lwz     r0,12(r31)
    clrlwi. r0,r0,30
    beq-	.L_80257888
    lwz     r0,12(r31)
    rlwinm. r0,r0,0,30,30
    beq-	.L_8025787C
    lwz     r3,16(r31)
    cmpwi   r3,0
    beq-	.L_8025787C
    lwz     r5,20(r31)
    addi    r0,r6,26624
    add     r6,r0,r7
    lwz     r0,16(r6)
    ble-	.L_8025787C
    addi    r7,r3,-8
    cmpwi   r3,8
    ble-	.L_80257850
    addi    r6,r7,7
    srwi    r6,r6,3
    mtctr   r6
    cmpwi   r7,0
    ble-	.L_80257850
.L_802577AC:
    subfic  r6,r4,3
    slwi    r6,r6,3
    srw     r6,r0,r6
    stb     r6,0(r5)
    addi    r6,r4,1
    subfic  r6,r6,3
    slwi    r6,r6,3
    srw     r6,r0,r6
    stb     r6,1(r5)
    addi    r6,r4,2
    subfic  r6,r6,3
    slwi    r6,r6,3
    srw     r6,r0,r6
    stb     r6,2(r5)
    neg     r6,r4
    slwi    r6,r6,3
    srw     r6,r0,r6
    stb     r6,3(r5)
    addi    r6,r4,4
    subfic  r6,r6,3
    slwi    r6,r6,3
    srw     r6,r0,r6
    stb     r6,4(r5)
    addi    r6,r4,5
    subfic  r6,r6,3
    slwi    r6,r6,3
    srw     r6,r0,r6
    stb     r6,5(r5)
    addi    r6,r4,6
    subfic  r6,r6,3
    slwi    r6,r6,3
    srw     r6,r0,r6
    stb     r6,6(r5)
    addi    r6,r4,7
    subfic  r6,r6,3
    slwi    r6,r6,3
    srw     r6,r0,r6
    stb     r6,7(r5)
    addi    r5,r5,8
    addi    r4,r4,8
    bdnz+	.L_802577AC
.L_80257850:
    subf    r6,r4,r3
    mtctr   r6
    cmpw    r4,r3
    bge-	.L_8025787C
.L_80257860:
    subfic  r3,r4,3
    slwi    r3,r3,3
    srw     r3,r0,r3
    stb     r3,0(r5)
    addi    r5,r5,1
    addi    r4,r4,1
    bdnz+	.L_80257860
.L_8025787C:
    lwz     r0,12(r31)
    clrrwi  r0,r0,2
    stw     r0,12(r31)
.L_80257888:
    addi    r3,r1,32
    bl	OSClearContext
    addi    r3,r1,32
    bl	OSSetCurrentContext
    addi    r3,r30,0
    addi    r4,r28,0
    addi    r12,r29,0
    mtlr    r12
    blrl
    addi    r3,r1,32
    bl	OSClearContext
    mr      r3,r28
    bl	OSSetCurrentContext
.L_802578BC:
    lwz     r0,764(r1)
    lwz     r31,756(r1)
    lwz     r30,752(r1)
    lwz     r29,748(r1)
    lwz     r28,744(r1)
    addi    r1,r1,760
    mtlr    r0
    blr
.size TCIntrruptHandler, . - TCIntrruptHandler

.global EXIInit
.balign 4
EXIInit:
/* 0x802579AC | size=0x1D4 (468 bytes) */
    mflr    r0
    stw     r0,4(r1)
    stwu    r1,-32(r1)
    stw     r31,28(r1)
    stw     r30,24(r1)
    stw     r29,20(r1)
    stw     r28,16(r1)
    lis     r3,-13312
    addi    r3,r3,26624
.L_802579D0:
    lwz     r0,12(r3)
    clrlwi  r0,r0,31
    cmplwi  r0,1
    beq+	.L_802579D0
    lwz     r0,32(r3)
    clrlwi  r0,r0,31
    cmplwi  r0,1
    beq+	.L_802579D0
    lwz     r0,52(r3)
    clrlwi  r0,r0,31
    cmplwi  r0,1
    beq+	.L_802579D0
    lis     r3,128
    addi    r3,r3,-32768
    bl	__OSMaskInterrupts
    li      r31,0
    lis     r4,-13312
    stw     r31,26624(r4)
    stw     r31,26644(r4)
    stw     r31,26664(r4)
    li      r0,8192
    stw     r0,26624(r4)
    li      r3,9
    lis     r4,-32731
    addi    r28,r4,30204
    addi    r4,r28,0
    bl	__OSSetInterruptHandler
    li      r3,10
    lis     r4,-32731
    addi    r29,r4,30404
    addi    r4,r29,0
    bl	__OSSetInterruptHandler
    li      r3,11
    lis     r4,-32731
    addi    r30,r4,30940
    addi    r4,r30,0
    bl	__OSSetInterruptHandler
    li      r3,12
    addi    r4,r28,0
    bl	__OSSetInterruptHandler
    li      r3,13
    addi    r4,r29,0
    bl	__OSSetInterruptHandler
    li      r3,14
    addi    r4,r30,0
    bl	__OSSetInterruptHandler
    li      r3,15
    addi    r4,r28,0
    bl	__OSSetInterruptHandler
    li      r3,16
    addi    r4,r29,0
    bl	__OSSetInterruptHandler
    li      r3,0
    li      r4,2
    addi    r5,r13,-23568
    bl	EXIGetID
    lwz     r0,-23704(r13)
    cmpwi   r0,0
    beq-	.L_80257AEC
    lis     r4,-32768
    stw     r31,12484(r4)
    stw     r31,12480(r4)
    lis     r3,-32694
    addi    r3,r3,-22064
    stw     r31,96(r3)
    stw     r31,32(r3)
    li      r3,0
    bl	__EXIProbe
    li      r3,1
    bl	__EXIProbe
    b	.L_80257B58
.L_80257AEC:
    li      r3,0
    li      r4,0
    addi    r5,r1,8
    bl	EXIGetID
    cmpwi   r3,0
    beq-	.L_80257B24
    lwz     r3,8(r1)
    addis   r0,r3,-1793
    cmplwi  r0,0
    bne-	.L_80257B24
    li      r3,1
    li      r4,0
    bl	__OSEnableBarnacle
    b	.L_80257B58
.L_80257B24:
    li      r3,1
    li      r4,0
    addi    r5,r1,8
    bl	EXIGetID
    cmpwi   r3,0
    beq-	.L_80257B58
    lwz     r3,8(r1)
    addis   r0,r3,-1793
    cmplwi  r0,0
    bne-	.L_80257B58
    li      r3,0
    li      r4,2
    bl	__OSEnableBarnacle
.L_80257B58:
    lwz     r3,-27888(r13)
    bl	OSRegisterVersion
    lwz     r0,36(r1)
    lwz     r31,28(r1)
    lwz     r30,24(r1)
    lwz     r29,20(r1)
    lwz     r28,16(r1)
    addi    r1,r1,32
    mtlr    r0
    blr
.size EXIInit, . - EXIInit

.global EXIGetID
.balign 4
EXIGetID:
/* 0x80257D90 | size=0x3B0 (944 bytes) */
    mflr    r0
    stw     r0,4(r1)
    stwu    r1,-72(r1)
    stmw    r23,36(r1)
    mr.     r25,r3
    addi    r26,r4,0
    addi    r27,r5,0
    slwi    r4,r3,6
    lis     r3,-32694
    addi    r0,r3,-22064
    add     r31,r0,r4
    bne-	.L_80257DE0
    cmplwi  r26,2
    bne-	.L_80257DE0
    lwz     r0,-23568(r13)
    cmplwi  r0,0
    beq-	.L_80257DE0
    stw     r0,0(r27)
    li      r3,1
    b	.L_8025812C
.L_80257DE0:
    cmpwi   r25,2
    bge-	.L_80257EC4
    cmplwi  r26,0
    bne-	.L_80257EC4
    mr      r3,r25
    bl	__EXIProbe
    cmpwi   r3,0
    bne-	.L_80257E08
    li      r3,0
    b	.L_8025812C
.L_80257E08:
    lwz     r4,32(r31)
    slwi    r0,r25,2
    lis     r3,-32768
    addi    r30,r3,12480
    add     r30,r30,r0
    lwz     r0,0(r30)
    cmpw    r4,r0
    bne-	.L_80257E38
    lwz     r0,28(r31)
    stw     r0,0(r27)
    lwz     r3,32(r31)
    b	.L_8025812C
.L_80257E38:
    bl	OSDisableInterrupts
    mr      r28,r3
    lwz     r0,12(r31)
    rlwinm. r0,r0,0,28,28
    bne-	.L_80257E5C
    mr      r3,r25
    bl	__EXIProbe
    cmpwi   r3,0
    bne-	.L_80257E6C
.L_80257E5C:
    mr      r3,r28
    bl	OSRestoreInterrupts
    li      r0,0
    b	.L_80257EB0
.L_80257E6C:
    addi    r3,r25,0
    li      r4,1
    li      r5,0
    li      r6,0
    bl	EXIClearInterrupts
    li      r0,0
    stw     r0,8(r31)
    lis     r3,16
    mulli   r0,r25,3
    srw     r3,r3,r0
    bl	__OSUnmaskInterrupts
    lwz     r0,12(r31)
    ori     r0,r0,8
    stw     r0,12(r31)
    mr      r3,r28
    bl	OSRestoreInterrupts
    li      r0,1
.L_80257EB0:
    cmpwi   r0,0
    bne-	.L_80257EC0
    li      r3,0
    b	.L_8025812C
.L_80257EC0:
    lwz     r29,0(r30)
.L_80257EC4:
    bl	OSDisableInterrupts
    addi    r28,r3,0
    li      r0,0
    cmpwi   r25,2
    bge-	.L_80257EE4
    cmplwi  r26,0
    bne-	.L_80257EE4
    li      r0,1
.L_80257EE4:
    cmpwi   r0,0
    beq-	.L_80257EF8
    lis     r3,-32731
    addi    r5,r3,32104
    b	.L_80257EFC
.L_80257EF8:
    li      r5,0
.L_80257EFC:
    addi    r3,r25,0
    addi    r4,r26,0
    bl	EXILock
    cntlzw  r0,r3
    srwi    r0,r0,5
    mr.     r30,r0
    bne-	.L_80258048
    addi    r3,r25,0
    addi    r4,r26,0
    li      r5,0
    bl	EXISelect
    cntlzw  r0,r3
    srwi    r0,r0,5
    mr.     r30,r0
    bne-	.L_80257FC4
    li      r0,0
    stw     r0,28(r1)
    addi    r3,r25,0
    addi    r4,r1,28
    li      r5,2
    li      r6,1
    li      r7,0
    bl	EXIImm
    cntlzw  r0,r3
    srwi    r0,r0,5
    or      r30,r30,r0
    addi    r3,r25,0
    bl	EXISync
    cntlzw  r0,r3
    srwi    r0,r0,5
    or      r30,r30,r0
    addi    r3,r25,0
    addi    r4,r27,0
    li      r5,4
    li      r6,0
    li      r7,0
    bl	EXIImm
    cntlzw  r0,r3
    srwi    r0,r0,5
    or      r30,r30,r0
    addi    r3,r25,0
    bl	EXISync
    cntlzw  r0,r3
    srwi    r0,r0,5
    or      r30,r30,r0
    addi    r3,r25,0
    bl	EXIDeselect
    cntlzw  r0,r3
    srwi    r0,r0,5
    or      r30,r30,r0
.L_80257FC4:
    bl	OSDisableInterrupts
    mr      r23,r3
    lwz     r0,12(r31)
    rlwinm. r0,r0,0,27,27
    bne-	.L_80257FE4
    mr      r3,r23
    bl	OSRestoreInterrupts
    b	.L_80258048
.L_80257FE4:
    lwz     r0,12(r31)
    rlwinm  r0,r0,0,28,26
    stw     r0,12(r31)
    addi    r3,r25,0
    addi    r4,r31,0
    bl	SetExiInterruptMask
    lwz     r3,36(r31)
    cmpwi   r3,0
    ble-	.L_80258040
    lwz     r24,44(r31)
    addic.  r0,r3,-1
    stw     r0,36(r31)
    ble-	.L_8025802C
    addi    r3,r31,40
    addi    r4,r31,48
    lwz     r0,36(r31)
    slwi    r5,r0,3
    bl	memmove
.L_8025802C:
    addi    r3,r25,0
    li      r4,0
    addi    r12,r24,0
    mtlr    r12
    blrl
.L_80258040:
    mr      r3,r23
    bl	OSRestoreInterrupts
.L_80258048:
    mr      r3,r28
    bl	OSRestoreInterrupts
    cmpwi   r25,2
    bge-	.L_80258118
    cmplwi  r26,0
    bne-	.L_80258118
    bl	OSDisableInterrupts
    mr      r23,r3
    lwz     r0,12(r31)
    rlwinm. r0,r0,0,28,28
    bne-	.L_80258080
    mr      r3,r23
    bl	OSRestoreInterrupts
    b	.L_802580C8
.L_80258080:
    lwz     r0,12(r31)
    rlwinm. r0,r0,0,27,27
    beq-	.L_802580A4
    lwz     r0,24(r31)
    cmplwi  r0,0
    bne-	.L_802580A4
    mr      r3,r23
    bl	OSRestoreInterrupts
    b	.L_802580C8
.L_802580A4:
    lwz     r0,12(r31)
    rlwinm  r0,r0,0,29,27
    stw     r0,12(r31)
    lis     r3,80
    mulli   r0,r25,3
    srw     r3,r3,r0
    bl	__OSMaskInterrupts
    mr      r3,r23
    bl	OSRestoreInterrupts
.L_802580C8:
    bl	OSDisableInterrupts
    slwi    r0,r25,2
    lis     r4,-32768
    addi    r4,r4,12480
    lwzx    r0,r4,r0
    subf    r4,r29,r0
    addic   r0,r4,-1
    subfe   r0,r0,r4
    or.     r30,r30,r0
    bne-	.L_802580FC
    lwz     r0,0(r27)
    stw     r0,28(r31)
    stw     r29,32(r31)
.L_802580FC:
    bl	OSRestoreInterrupts
    cmpwi   r30,0
    beq-	.L_80258110
    li      r3,0
    b	.L_8025812C
.L_80258110:
    lwz     r3,32(r31)
    b	.L_8025812C
.L_80258118:
    cmpwi   r30,0
    beq-	.L_80258128
    li      r3,0
    b	.L_8025812C
.L_80258128:
    li      r3,1
.L_8025812C:
    lwz     r0,76(r1)
    lmw     r23,36(r1)
    addi    r1,r1,72
    mtlr    r0
    blr
.size EXIGetID, . - EXIGetID

.global EXIGetType
.balign 4
EXIGetType:
/* 0x80258140 | size=0x118 (280 bytes) */
    mflr    r0
    stw     r0,4(r1)
    stwu    r1,-32(r1)
    stw     r31,28(r1)
    addi    r31,r5,0
    addi    r5,r1,20
    bl	EXIGetID
    cmpwi   r3,0
    bne-	.L_80258168
    b	.L_80258244
.L_80258168:
    lwz     r6,20(r1)
    clrrwi  r5,r6,8
    lis     r4,1026
    addi    r0,r4,768
    cmpw    r5,r0
    beq-	.L_802581B4
    bge-	.L_802581A4
    addi    r0,r4,512
    cmpw    r5,r0
    beq-	.L_802581B4
    bge-	.L_802581BC
    addi    r0,r4,256
    cmpw    r5,r0
    beq-	.L_802581B4
    b	.L_802581BC
.L_802581A4:
    lis     r0,1030
    cmpw    r5,r0
    beq-	.L_802581B4
    b	.L_802581BC
.L_802581B4:
    stw     r5,0(r31)
    b	.L_80258244
.L_802581BC:
    clrrwi  r4,r6,16
    lis     r0,1287
    cmpw    r4,r0
    beq-	.L_80258238
    bge-	.L_80258240
    cmpwi   r4,0
    beq-	.L_802581DC
    b	.L_80258240
.L_802581DC:
    andi.   r0,r6,14339
    bne-	.L_80258240
    rlwinm  r0,r6,0,24,29
    cmpwi   r0,32
    beq-	.L_80258230
    bge-	.L_80258218
    cmpwi   r0,8
    beq-	.L_80258230
    bge-	.L_8025820C
    cmpwi   r0,4
    beq-	.L_80258230
    b	.L_80258240
.L_8025820C:
    cmpwi   r0,16
    beq-	.L_80258230
    b	.L_80258240
.L_80258218:
    cmpwi   r0,128
    beq-	.L_80258230
    bge-	.L_80258240
    cmpwi   r0,64
    beq-	.L_80258230
    b	.L_80258240
.L_80258230:
    stw     r0,0(r31)
    b	.L_80258244
.L_80258238:
    stw     r0,0(r31)
    b	.L_80258244
.L_80258240:
    stw     r6,0(r31)
.L_80258244:
    lwz     r0,36(r1)
    lwz     r31,28(r1)
    addi    r1,r1,32
    mtlr    r0
    blr
.size EXIGetType, . - EXIGetType

.global EXIGetTypeString
.balign 4
EXIGetTypeString:
/* 0x80258258 | size=0x234 (564 bytes) */
    lis     r4,-32700
    addi    r5,r4,-16312
    lis     r0,257
    cmpw    r3,r0
    beq-	.L_80258424
    bge-	.L_8025831C
    cmpwi   r3,4
    beq-	.L_802583F4
    bge-	.L_802582E0
    lis     r4,-32768
    addi    r0,r4,32
    cmpw    r3,r0
    beq-	.L_80258454
    bge-	.L_802582C0
    addi    r0,r4,8
    cmpw    r3,r0
    beq-	.L_80258454
    bge-	.L_802582B0
    addi    r0,r4,4
    cmpw    r3,r0
    beq-	.L_80258454
    b	.L_80258484
.L_802582B0:
    addi    r0,r4,16
    cmpw    r3,r0
    beq-	.L_80258454
    b	.L_80258484
.L_802582C0:
    addi    r0,r4,128
    cmpw    r3,r0
    beq-	.L_80258454
    bge-	.L_80258484
    addi    r0,r4,64
    cmpw    r3,r0
    beq-	.L_80258454
    b	.L_80258484
.L_802582E0:
    cmpwi   r3,32
    beq-	.L_8025840C
    bge-	.L_80258304
    cmpwi   r3,16
    beq-	.L_80258404
    bge-	.L_80258484
    cmpwi   r3,8
    beq-	.L_802583FC
    b	.L_80258484
.L_80258304:
    cmpwi   r3,128
    beq-	.L_8025841C
    bge-	.L_80258484
    cmpwi   r3,64
    beq-	.L_80258414
    b	.L_80258484
.L_8025831C:
    lis     r4,1028
    addi    r0,r4,1028
    cmpw    r3,r0
    beq-	.L_8025844C
    bge-	.L_80258394
    lis     r4,1026
    addi    r0,r4,256
    cmpw    r3,r0
    beq-	.L_80258464
    bge-	.L_80258374
    lis     r0,514
    cmpw    r3,r0
    beq-	.L_80258434
    bge-	.L_80258364
    lis     r0,258
    cmpw    r3,r0
    beq-	.L_8025842C
    b	.L_80258484
.L_80258364:
    lis     r0,769
    cmpw    r3,r0
    beq-	.L_8025843C
    b	.L_80258484
.L_80258374:
    addi    r0,r4,768
    cmpw    r3,r0
    beq-	.L_80258464
    bge-	.L_80258484
    addi    r0,r4,512
    cmpw    r3,r0
    beq-	.L_80258464
    b	.L_80258484
.L_80258394:
    lis     r0,1043
    cmpw    r3,r0
    beq-	.L_80258474
    bge-	.L_802583C4
    lis     r0,1042
    cmpw    r3,r0
    beq-	.L_80258444
    bge-	.L_80258484
    lis     r0,1030
    cmpw    r3,r0
    beq-	.L_8025846C
    b	.L_80258484
.L_802583C4:
    lis     r4,1058
    addi    r0,r4,1
    cmpw    r3,r0
    beq-	.L_8025845C
    bge-	.L_802583E4
    cmpw    r3,r4
    bge-	.L_80258464
    b	.L_80258484
.L_802583E4:
    lis     r0,1287
    cmpw    r3,r0
    beq-	.L_8025847C
    b	.L_80258484
.L_802583F4:
    addi    r3,r5,72
    blr
.L_802583FC:
    addi    r3,r5,88
    blr
.L_80258404:
    addi    r3,r5,104
    blr
.L_8025840C:
    addi    r3,r5,120
    blr
.L_80258414:
    addi    r3,r5,136
    blr
.L_8025841C:
    addi    r3,r5,156
    blr
.L_80258424:
    addi    r3,r5,176
    blr
.L_8025842C:
    addi    r3,r13,-27884
    blr
.L_80258434:
    addi    r3,r13,-27876
    blr
.L_8025843C:
    addi    r3,r13,-27868
    blr
.L_80258444:
    addi    r3,r13,-27860
    blr
.L_8025844C:
    addi    r3,r13,-27852
    blr
.L_80258454:
    addi    r3,r5,188
    blr
.L_8025845C:
    addi    r3,r5,200
    blr
.L_80258464:
    addi    r3,r5,216
    blr
.L_8025846C:
    addi    r3,r13,-27844
    blr
.L_80258474:
    addi    r3,r5,236
    blr
.L_8025847C:
    addi    r3,r5,252
    blr
.L_80258484:
    addi    r3,r13,-27840
    blr
.size EXIGetTypeString, . - EXIGetTypeString

#
# === EXIUart.o (exi.a) ===
#

.global ProbeBarnacle
.balign 4
ProbeBarnacle:
/* 0x8025848C | size=0x18C (396 bytes) */
    mflr    r0
    stw     r0,4(r1)
    stwu    r1,-40(r1)
    stw     r31,36(r1)
    addi    r31,r5,0
    stw     r30,32(r1)
    addi    r30,r4,0
    stw     r29,28(r1)
    addi    r29,r3,0
    cmpwi   r29,2
    stw     r28,24(r1)
    beq-	.L_802584E0
    cmplwi  r30,0
    bne-	.L_802584E0
    addi    r3,r29,0
    li      r4,0
    bl	EXIAttach
    cmpwi   r3,0
    bne-	.L_802584E0
    li      r3,0
    b	.L_802585F8
.L_802584E0:
    addi    r3,r29,0
    addi    r4,r30,0
    li      r5,0
    bl	EXILock
    cntlzw  r0,r3
    srwi    r0,r0,5
    mr.     r28,r0
    bne-	.L_802585B4
    addi    r3,r29,0
    addi    r4,r30,0
    li      r5,0
    bl	EXISelect
    cntlzw  r0,r3
    srwi    r0,r0,5
    mr.     r28,r0
    bne-	.L_802585AC
    lis     r3,8193
    addi    r0,r3,4864
    stw     r0,20(r1)
    addi    r3,r29,0
    addi    r4,r1,20
    li      r5,4
    li      r6,1
    li      r7,0
    bl	EXIImm
    cntlzw  r0,r3
    addi    r3,r29,0
    srwi    r28,r0,5
    bl	EXISync
    cntlzw  r0,r3
    srwi    r0,r0,5
    addi    r3,r29,0
    addi    r4,r31,0
    or      r28,r28,r0
    li      r5,4
    li      r6,0
    li      r7,0
    bl	EXIImm
    cntlzw  r0,r3
    srwi    r0,r0,5
    addi    r3,r29,0
    or      r28,r28,r0
    bl	EXISync
    cntlzw  r0,r3
    srwi    r0,r0,5
    addi    r3,r29,0
    or      r28,r28,r0
    bl	EXIDeselect
    cntlzw  r0,r3
    srwi    r0,r0,5
    or      r28,r28,r0
.L_802585AC:
    mr      r3,r29
    bl	EXIUnlock
.L_802585B4:
    cmpwi   r29,2
    beq-	.L_802585CC
    cmplwi  r30,0
    bne-	.L_802585CC
    mr      r3,r29
    bl	EXIDetach
.L_802585CC:
    cmpwi   r28,0
    beq-	.L_802585DC
    li      r3,0
    b	.L_802585F8
.L_802585DC:
    lwz     r3,0(r31)
    addis   r0,r3,1
    cmplwi  r0,65535
    beq-	.L_802585F4
    li      r3,1
    b	.L_802585F8
.L_802585F4:
    li      r3,0
.L_802585F8:
    lwz     r0,44(r1)
    lwz     r31,36(r1)
    lwz     r30,32(r1)
    lwz     r29,28(r1)
    lwz     r28,24(r1)
    addi    r1,r1,40
    mtlr    r0
    blr
.size ProbeBarnacle, . - ProbeBarnacle

.global __OSEnableBarnacle
.balign 4
__OSEnableBarnacle:
/* 0x80258618 | size=0x1BC (444 bytes) */
    mflr    r0
    stw     r0,4(r1)
    stwu    r1,-32(r1)
    stw     r31,28(r1)
    addi    r31,r4,0
    addi    r5,r1,16
    stw     r30,24(r1)
    addi    r30,r3,0
    bl	EXIGetID
    cmpwi   r3,0
    beq-	.L_802587BC
    lwz     r4,16(r1)
    lis     r0,258
    cmpw    r4,r0
    beq-	.L_802587BC
    bge-	.L_802586E8
    cmpwi   r4,4
    beq-	.L_802587BC
    bge-	.L_802586B4
    lis     r3,-32768
    addi    r0,r3,16
    cmpw    r4,r0
    beq-	.L_802587BC
    bge-	.L_80258698
    addi    r0,r3,8
    cmpw    r4,r0
    beq-	.L_802587BC
    bge-	.L_8025878C
    addi    r0,r3,4
    cmpw    r4,r0
    beq-	.L_802587BC
    b	.L_8025878C
.L_80258698:
    cmpwi   r4,-1
    beq-	.L_802587BC
    bge-	.L_8025878C
    addi    r0,r3,32
    cmpw    r4,r0
    beq-	.L_802587BC
    b	.L_8025878C
.L_802586B4:
    cmpwi   r4,32
    beq-	.L_802587BC
    bge-	.L_802586D8
    cmpwi   r4,16
    beq-	.L_802587BC
    bge-	.L_8025878C
    cmpwi   r4,8
    beq-	.L_802587BC
    b	.L_8025878C
.L_802586D8:
    lis     r0,257
    cmpw    r4,r0
    beq-	.L_802587BC
    b	.L_8025878C
.L_802586E8:
    lis     r3,1028
    addi    r0,r3,1028
    cmpw    r4,r0
    beq-	.L_802587BC
    bge-	.L_80258750
    lis     r3,1026
    addi    r0,r3,256
    cmpw    r4,r0
    beq-	.L_802587BC
    bge-	.L_80258730
    lis     r0,769
    cmpw    r4,r0
    beq-	.L_802587BC
    bge-	.L_8025878C
    lis     r0,514
    cmpw    r4,r0
    beq-	.L_802587BC
    b	.L_8025878C
.L_80258730:
    addi    r0,r3,768
    cmpw    r4,r0
    beq-	.L_802587BC
    bge-	.L_8025878C
    addi    r0,r3,512
    cmpw    r4,r0
    beq-	.L_802587BC
    b	.L_8025878C
.L_80258750:
    lis     r0,1043
    cmpw    r4,r0
    beq-	.L_802587BC
    bge-	.L_80258780
    lis     r0,1042
    cmpw    r4,r0
    beq-	.L_802587BC
    bge-	.L_8025878C
    lis     r0,1030
    cmpw    r4,r0
    beq-	.L_802587BC
    b	.L_8025878C
.L_80258780:
    lis     r0,1058
    cmpw    r4,r0
    beq-	.L_802587BC
.L_8025878C:
    addi    r3,r30,0
    addi    r4,r31,0
    addi    r5,r1,16
    bl	ProbeBarnacle
    cmpwi   r3,0
    beq-	.L_802587BC
    lis     r3,-23041
    stw     r30,-23560(r13)
    addi    r0,r3,90
    stw     r31,-23556(r13)
    stw     r0,-23548(r13)
    stw     r0,-23552(r13)
.L_802587BC:
    lwz     r0,36(r1)
    lwz     r31,28(r1)
    lwz     r30,24(r1)
    addi    r1,r1,32
    mtlr    r0
    blr
.size __OSEnableBarnacle, . - __OSEnableBarnacle

.global WriteUARTN
.balign 4
WriteUARTN:
/* 0x802588E4 | size=0x200 (512 bytes) */
    mflr    r0
    stw     r0,4(r1)
    stwu    r1,-48(r1)
    stmw    r26,24(r1)
    addi    r30,r3,0
    addi    r31,r4,0
    lwz     r5,-23552(r13)
    addis   r0,r5,23041
    cmplwi  r0,90
    beq-	.L_80258914
    li      r3,2
    b	.L_80258AD0
.L_80258914:
    lwz     r3,-23560(r13)
    li      r5,0
    lwz     r4,-23556(r13)
    bl	EXILock
    cmpwi   r3,0
    bne-	.L_80258934
    li      r3,0
    b	.L_80258AD0
.L_80258934:
    addi    r4,r30,0
    li      r3,13
    b	.L_80258954
.L_80258940:
    lbz     r0,0(r4)
    cmpwi   r0,10
    bne-	.L_80258950
    stb     r3,0(r4)
.L_80258950:
    addi    r4,r4,1
.L_80258954:
    subf    r0,r30,r4
    cmplw   r0,r31
    blt+	.L_80258940
    lis     r0,-24575
    stw     r0,20(r1)
    li      r26,0
    lis     r29,8193
    b	.L_80258ABC
.L_80258974:
    lwz     r3,-23560(r13)
    li      r5,3
    lwz     r4,-23556(r13)
    bl	EXISelect
    cmpwi   r3,0
    bne-	.L_80258994
    li      r0,-1
    b	.L_802589EC
.L_80258994:
    stw     r29,16(r1)
    addi    r4,r1,16
    lwz     r3,-23560(r13)
    li      r5,4
    li      r6,1
    li      r7,0
    bl	EXIImm
    lwz     r3,-23560(r13)
    bl	EXISync
    lwz     r3,-23560(r13)
    addi    r4,r1,16
    li      r5,1
    li      r6,0
    li      r7,0
    bl	EXIImm
    lwz     r3,-23560(r13)
    bl	EXISync
    lwz     r3,-23560(r13)
    bl	EXIDeselect
    lwz     r0,16(r1)
    srwi    r0,r0,24
    subfic  r0,r0,16
.L_802589EC:
    cmpwi   r0,0
    mr      r27,r0
    bge-	.L_80258A00
    li      r26,3
    b	.L_80258AC4
.L_80258A00:
    cmpwi   r0,12
    bge-	.L_80258A10
    cmplw   r0,r31
    blt-	.L_80258ABC
.L_80258A10:
    lwz     r3,-23560(r13)
    li      r5,3
    lwz     r4,-23556(r13)
    bl	EXISelect
    cmpwi   r3,0
    bne-	.L_80258A30
    li      r26,3
    b	.L_80258AC4
.L_80258A30:
    lwz     r3,-23560(r13)
    addi    r4,r1,20
    li      r5,4
    li      r6,1
    li      r7,0
    bl	EXIImm
    lwz     r3,-23560(r13)
    bl	EXISync
    b	.L_80258AA4
.L_80258A54:
    cmpwi   r27,4
    bge-	.L_80258A64
    cmplw   r27,r31
    blt-	.L_80258AB4
.L_80258A64:
    cmplwi  r31,4
    bge-	.L_80258A74
    mr      r28,r31
    b	.L_80258A78
.L_80258A74:
    li      r28,4
.L_80258A78:
    lwz     r3,-23560(r13)
    mr      r5,r28
    addi    r4,r30,0
    li      r6,1
    li      r7,0
    bl	EXIImm
    lwz     r3,-23560(r13)
    add     r30,r30,r28
    subf    r31,r28,r31
    subf    r27,r28,r27
    bl	EXISync
.L_80258AA4:
    cmpwi   r27,0
    beq-	.L_80258AB4
    cmplwi  r31,0
    bne+	.L_80258A54
.L_80258AB4:
    lwz     r3,-23560(r13)
    bl	EXIDeselect
.L_80258ABC:
    cmplwi  r31,0
    bne+	.L_80258974
.L_80258AC4:
    lwz     r3,-23560(r13)
    bl	EXIUnlock
    mr      r3,r26
.L_80258AD0:
    lmw     r26,24(r1)
    lwz     r0,52(r1)
    addi    r1,r1,48
    mtlr    r0
    blr
.size WriteUARTN, . - WriteUARTN

#
# === GXAttr.o (gx.a) ===
#

.global GXSetVtxDesc
.balign 4
GXSetVtxDesc:
/* 0x803894B4 | size=0x26C (620 bytes) */
    cmplwi  r3,25
    bgt-	.L_803896C8
    lis     r5,-32698
    addi    r5,r5,-26464
    slwi    r0,r3,2
    lwzx    r0,r5,r0
    mtctr   r0
    bctr
    lwz     r3,-17720(r13)
    lwz     r0,20(r3)
    rlwimi  r0,r4,0,31,31
    stw     r0,20(r3)
    b	.L_803896C8
    lwz     r3,-17720(r13)
    lwz     r0,20(r3)
    rlwimi  r0,r4,1,30,30
    stw     r0,20(r3)
    b	.L_803896C8
    lwz     r3,-17720(r13)
    lwz     r0,20(r3)
    rlwimi  r0,r4,2,29,29
    stw     r0,20(r3)
    b	.L_803896C8
    lwz     r3,-17720(r13)
    lwz     r0,20(r3)
    rlwimi  r0,r4,3,28,28
    stw     r0,20(r3)
    b	.L_803896C8
    lwz     r3,-17720(r13)
    lwz     r0,20(r3)
    rlwimi  r0,r4,4,27,27
    stw     r0,20(r3)
    b	.L_803896C8
    lwz     r3,-17720(r13)
    lwz     r0,20(r3)
    rlwimi  r0,r4,5,26,26
    stw     r0,20(r3)
    b	.L_803896C8
    lwz     r3,-17720(r13)
    lwz     r0,20(r3)
    rlwimi  r0,r4,6,25,25
    stw     r0,20(r3)
    b	.L_803896C8
    lwz     r3,-17720(r13)
    lwz     r0,20(r3)
    rlwimi  r0,r4,7,24,24
    stw     r0,20(r3)
    b	.L_803896C8
    lwz     r3,-17720(r13)
    lwz     r0,20(r3)
    rlwimi  r0,r4,8,23,23
    stw     r0,20(r3)
    b	.L_803896C8
    lwz     r3,-17720(r13)
    lwz     r0,20(r3)
    rlwimi  r0,r4,9,21,22
    stw     r0,20(r3)
    b	.L_803896C8
    cmpwi   r4,0
    beq-	.L_803895C0
    lwz     r3,-17720(r13)
    li      r5,1
    li      r0,0
    stb     r5,1236(r3)
    stb     r0,1237(r3)
    stw     r4,1232(r3)
    b	.L_803896C8
.L_803895C0:
    lwz     r3,-17720(r13)
    li      r0,0
    stb     r0,1236(r3)
    b	.L_803896C8
    cmpwi   r4,0
    beq-	.L_803895F4
    lwz     r3,-17720(r13)
    li      r5,1
    li      r0,0
    stb     r5,1237(r3)
    stb     r0,1236(r3)
    stw     r4,1232(r3)
    b	.L_803896C8
.L_803895F4:
    lwz     r3,-17720(r13)
    li      r0,0
    stb     r0,1237(r3)
    b	.L_803896C8
    lwz     r3,-17720(r13)
    lwz     r0,20(r3)
    rlwimi  r0,r4,13,17,18
    stw     r0,20(r3)
    b	.L_803896C8
    lwz     r3,-17720(r13)
    lwz     r0,20(r3)
    rlwimi  r0,r4,15,15,16
    stw     r0,20(r3)
    b	.L_803896C8
    lwz     r3,-17720(r13)
    lwz     r0,24(r3)
    rlwimi  r0,r4,0,30,31
    stw     r0,24(r3)
    b	.L_803896C8
    lwz     r3,-17720(r13)
    lwz     r0,24(r3)
    rlwimi  r0,r4,2,28,29
    stw     r0,24(r3)
    b	.L_803896C8
    lwz     r3,-17720(r13)
    lwz     r0,24(r3)
    rlwimi  r0,r4,4,26,27
    stw     r0,24(r3)
    b	.L_803896C8
    lwz     r3,-17720(r13)
    lwz     r0,24(r3)
    rlwimi  r0,r4,6,24,25
    stw     r0,24(r3)
    b	.L_803896C8
    lwz     r3,-17720(r13)
    lwz     r0,24(r3)
    rlwimi  r0,r4,8,22,23
    stw     r0,24(r3)
    b	.L_803896C8
    lwz     r3,-17720(r13)
    lwz     r0,24(r3)
    rlwimi  r0,r4,10,20,21
    stw     r0,24(r3)
    b	.L_803896C8
    lwz     r3,-17720(r13)
    lwz     r0,24(r3)
    rlwimi  r0,r4,12,18,19
    stw     r0,24(r3)
    b	.L_803896C8
    lwz     r3,-17720(r13)
    lwz     r0,24(r3)
    rlwimi  r0,r4,14,16,17
    stw     r0,24(r3)
.L_803896C8:
    lwz     r4,-17720(r13)
    lbz     r0,1236(r4)
    cmplwi  r0,0
    bne-	.L_803896E4
    lbz     r0,1237(r4)
    cmplwi  r0,0
    beq-	.L_803896FC
.L_803896E4:
    lwz     r0,1232(r4)
    lwz     r4,20(r4)
    lwz     r3,-17720(r13)
    rlwimi  r4,r0,11,19,20
    stw     r4,20(r3)
    b	.L_8038970C
.L_803896FC:
    lwz     r3,20(r4)
    li      r0,0
    rlwimi  r3,r0,11,19,20
    stw     r3,20(r4)
.L_8038970C:
    lwz     r3,-17720(r13)
    lwz     r0,1452(r3)
    ori     r0,r0,8
    stw     r0,1452(r3)
    blr
.size GXSetVtxDesc, . - GXSetVtxDesc

.global GXSetVtxDescv
.balign 4
GXSetVtxDescv:
/* 0x80389720 | size=0x288 (648 bytes) */
    lis     r4,-32698
    addi    r4,r4,-26360
    b	.L_80389944
.L_8038972C:
    lwz     r5,0(r3)
    lwz     r0,4(r3)
    cmplwi  r5,25
    bgt-	.L_80389940
    slwi    r5,r5,2
    lwzx    r5,r4,r5
    mtctr   r5
    bctr
    lwz     r6,-17720(r13)
    lwz     r5,20(r6)
    rlwimi  r5,r0,0,31,31
    stw     r5,20(r6)
    b	.L_80389940
    lwz     r6,-17720(r13)
    lwz     r5,20(r6)
    rlwimi  r5,r0,1,30,30
    stw     r5,20(r6)
    b	.L_80389940
    lwz     r6,-17720(r13)
    lwz     r5,20(r6)
    rlwimi  r5,r0,2,29,29
    stw     r5,20(r6)
    b	.L_80389940
    lwz     r6,-17720(r13)
    lwz     r5,20(r6)
    rlwimi  r5,r0,3,28,28
    stw     r5,20(r6)
    b	.L_80389940
    lwz     r6,-17720(r13)
    lwz     r5,20(r6)
    rlwimi  r5,r0,4,27,27
    stw     r5,20(r6)
    b	.L_80389940
    lwz     r6,-17720(r13)
    lwz     r5,20(r6)
    rlwimi  r5,r0,5,26,26
    stw     r5,20(r6)
    b	.L_80389940
    lwz     r6,-17720(r13)
    lwz     r5,20(r6)
    rlwimi  r5,r0,6,25,25
    stw     r5,20(r6)
    b	.L_80389940
    lwz     r6,-17720(r13)
    lwz     r5,20(r6)
    rlwimi  r5,r0,7,24,24
    stw     r5,20(r6)
    b	.L_80389940
    lwz     r6,-17720(r13)
    lwz     r5,20(r6)
    rlwimi  r5,r0,8,23,23
    stw     r5,20(r6)
    b	.L_80389940
    lwz     r6,-17720(r13)
    lwz     r5,20(r6)
    rlwimi  r5,r0,9,21,22
    stw     r5,20(r6)
    b	.L_80389940
    cmpwi   r0,0
    beq-	.L_80389838
    lwz     r6,-17720(r13)
    li      r7,1
    li      r5,0
    stb     r7,1236(r6)
    stb     r5,1237(r6)
    stw     r0,1232(r6)
    b	.L_80389940
.L_80389838:
    lwz     r5,-17720(r13)
    li      r0,0
    stb     r0,1236(r5)
    b	.L_80389940
    cmpwi   r0,0
    beq-	.L_8038986C
    lwz     r6,-17720(r13)
    li      r7,1
    li      r5,0
    stb     r7,1237(r6)
    stb     r5,1236(r6)
    stw     r0,1232(r6)
    b	.L_80389940
.L_8038986C:
    lwz     r5,-17720(r13)
    li      r0,0
    stb     r0,1237(r5)
    b	.L_80389940
    lwz     r6,-17720(r13)
    lwz     r5,20(r6)
    rlwimi  r5,r0,13,17,18
    stw     r5,20(r6)
    b	.L_80389940
    lwz     r6,-17720(r13)
    lwz     r5,20(r6)
    rlwimi  r5,r0,15,15,16
    stw     r5,20(r6)
    b	.L_80389940
    lwz     r6,-17720(r13)
    lwz     r5,24(r6)
    rlwimi  r5,r0,0,30,31
    stw     r5,24(r6)
    b	.L_80389940
    lwz     r6,-17720(r13)
    lwz     r5,24(r6)
    rlwimi  r5,r0,2,28,29
    stw     r5,24(r6)
    b	.L_80389940
    lwz     r6,-17720(r13)
    lwz     r5,24(r6)
    rlwimi  r5,r0,4,26,27
    stw     r5,24(r6)
    b	.L_80389940
    lwz     r6,-17720(r13)
    lwz     r5,24(r6)
    rlwimi  r5,r0,6,24,25
    stw     r5,24(r6)
    b	.L_80389940
    lwz     r6,-17720(r13)
    lwz     r5,24(r6)
    rlwimi  r5,r0,8,22,23
    stw     r5,24(r6)
    b	.L_80389940
    lwz     r6,-17720(r13)
    lwz     r5,24(r6)
    rlwimi  r5,r0,10,20,21
    stw     r5,24(r6)
    b	.L_80389940
    lwz     r6,-17720(r13)
    lwz     r5,24(r6)
    rlwimi  r5,r0,12,18,19
    stw     r5,24(r6)
    b	.L_80389940
    lwz     r6,-17720(r13)
    lwz     r5,24(r6)
    rlwimi  r5,r0,14,16,17
    stw     r5,24(r6)
.L_80389940:
    addi    r3,r3,8
.L_80389944:
    lwz     r0,0(r3)
    cmpwi   r0,255
    bne+	.L_8038972C
    lwz     r4,-17720(r13)
    lbz     r0,1236(r4)
    cmplwi  r0,0
    bne-	.L_8038996C
    lbz     r0,1237(r4)
    cmplwi  r0,0
    beq-	.L_80389984
.L_8038996C:
    lwz     r0,1232(r4)
    lwz     r4,20(r4)
    lwz     r3,-17720(r13)
    rlwimi  r4,r0,11,19,20
    stw     r4,20(r3)
    b	.L_80389994
.L_80389984:
    lwz     r3,20(r4)
    li      r0,0
    rlwimi  r3,r0,11,19,20
    stw     r3,20(r4)
.L_80389994:
    lwz     r3,-17720(r13)
    lwz     r0,1452(r3)
    ori     r0,r0,8
    stw     r0,1452(r3)
    blr
.size GXSetVtxDescv, . - GXSetVtxDescv

.global __GXCalculateVLim
.balign 4
__GXCalculateVLim:
/* 0x80389A64 | size=0x124 (292 bytes) */
    lwz     r3,-17720(r13)
    lhz     r0,4(r3)
    cmplwi  r0,0
    beqlr-
    lwz     r9,20(r3)
    addi    r5,r13,-25304
    lwz     r8,28(r3)
    clrlwi  r0,r9,31
    lwz     r4,24(r3)
    rlwinm  r6,r9,31,31,31
    add     r0,r0,r6
    rlwinm  r6,r9,30,31,31
    add     r0,r0,r6
    rlwinm  r7,r9,29,31,31
    rlwinm  r6,r9,23,30,31
    lbzx    r5,r5,r6
    rlwinm  r8,r8,23,31,31
    add     r0,r0,r7
    rlwinm  r6,r9,28,31,31
    add     r0,r0,r6
    rlwinm  r6,r9,27,31,31
    add     r0,r0,r6
    rlwinm  r6,r9,26,31,31
    add     r0,r0,r6
    rlwinm  r6,r9,25,31,31
    add     r0,r0,r6
    rlwinm  r6,r9,24,31,31
    add     r0,r0,r6
    cmpwi   r8,1
    add     r0,r0,r5
    bne-	.L_80389AE8
    li      r8,3
    b	.L_80389AEC
.L_80389AE8:
    li      r8,1
.L_80389AEC:
    rlwinm  r6,r9,21,30,31
    addi    r5,r13,-25304
    lbzx    r6,r5,r6
    rlwinm  r5,r9,19,30,31
    addi    r7,r13,-25312
    mullw   r8,r6,r8
    lbzx    r6,r7,r5
    add     r0,r0,r8
    rlwinm  r5,r9,17,30,31
    lbzx    r9,r7,r5
    add     r0,r0,r6
    clrlwi  r6,r4,30
    addi    r8,r13,-25308
    rlwinm  r5,r4,30,30,31
    lbzx    r7,r8,r6
    add     r0,r0,r9
    lbzx    r6,r8,r5
    add     r0,r0,r7
    rlwinm  r5,r4,28,30,31
    lbzx    r7,r8,r5
    add     r0,r0,r6
    rlwinm  r5,r4,26,30,31
    lbzx    r6,r8,r5
    add     r0,r0,r7
    rlwinm  r5,r4,24,30,31
    lbzx    r7,r8,r5
    add     r0,r0,r6
    rlwinm  r5,r4,22,30,31
    lbzx    r6,r8,r5
    rlwinm  r5,r4,20,30,31
    add     r0,r0,r7
    lbzx    r5,r8,r5
    rlwinm  r4,r4,18,30,31
    add     r0,r0,r6
    lbzx    r4,r8,r4
    add     r0,r0,r5
    add     r0,r0,r4
    sth     r0,6(r3)
    blr
.size __GXCalculateVLim, . - __GXCalculateVLim

.global GXGetVtxDesc
.balign 4
GXGetVtxDesc:
/* 0x80389B88 | size=0x1B4 (436 bytes) */
    cmplwi  r3,25
    bgt-	.L_80389D30
    lis     r5,-32698
    addi    r5,r5,-26256
    slwi    r0,r3,2
    lwzx    r0,r5,r0
    mtctr   r0
    bctr
    lwz     r3,-17720(r13)
    lwz     r0,20(r3)
    clrlwi  r0,r0,31
    b	.L_80389D34
    lwz     r3,-17720(r13)
    lwz     r0,20(r3)
    rlwinm  r0,r0,31,31,31
    b	.L_80389D34
    lwz     r3,-17720(r13)
    lwz     r0,20(r3)
    rlwinm  r0,r0,30,31,31
    b	.L_80389D34
    lwz     r3,-17720(r13)
    lwz     r0,20(r3)
    rlwinm  r0,r0,29,31,31
    b	.L_80389D34
    lwz     r3,-17720(r13)
    lwz     r0,20(r3)
    rlwinm  r0,r0,28,31,31
    b	.L_80389D34
    lwz     r3,-17720(r13)
    lwz     r0,20(r3)
    rlwinm  r0,r0,27,31,31
    b	.L_80389D34
    lwz     r3,-17720(r13)
    lwz     r0,20(r3)
    rlwinm  r0,r0,26,31,31
    b	.L_80389D34
    lwz     r3,-17720(r13)
    lwz     r0,20(r3)
    rlwinm  r0,r0,25,31,31
    b	.L_80389D34
    lwz     r3,-17720(r13)
    lwz     r0,20(r3)
    rlwinm  r0,r0,24,31,31
    b	.L_80389D34
    lwz     r3,-17720(r13)
    lwz     r0,20(r3)
    rlwinm  r0,r0,23,30,31
    b	.L_80389D34
    lwz     r3,-17720(r13)
    lbz     r0,1236(r3)
    cmplwi  r0,0
    beq-	.L_80389C64
    lwz     r0,20(r3)
    rlwinm  r0,r0,21,30,31
    b	.L_80389D34
.L_80389C64:
    li      r0,0
    b	.L_80389D34
    lwz     r3,-17720(r13)
    lbz     r0,1237(r3)
    cmplwi  r0,0
    beq-	.L_80389C88
    lwz     r0,20(r3)
    rlwinm  r0,r0,21,30,31
    b	.L_80389D34
.L_80389C88:
    li      r0,0
    b	.L_80389D34
    lwz     r3,-17720(r13)
    lwz     r0,20(r3)
    rlwinm  r0,r0,19,30,31
    b	.L_80389D34
    lwz     r3,-17720(r13)
    lwz     r0,20(r3)
    rlwinm  r0,r0,17,30,31
    b	.L_80389D34
    lwz     r3,-17720(r13)
    lwz     r0,24(r3)
    clrlwi  r0,r0,30
    b	.L_80389D34
    lwz     r3,-17720(r13)
    lwz     r0,24(r3)
    rlwinm  r0,r0,30,30,31
    b	.L_80389D34
    lwz     r3,-17720(r13)
    lwz     r0,24(r3)
    rlwinm  r0,r0,28,30,31
    b	.L_80389D34
    lwz     r3,-17720(r13)
    lwz     r0,24(r3)
    rlwinm  r0,r0,26,30,31
    b	.L_80389D34
    lwz     r3,-17720(r13)
    lwz     r0,24(r3)
    rlwinm  r0,r0,24,30,31
    b	.L_80389D34
    lwz     r3,-17720(r13)
    lwz     r0,24(r3)
    rlwinm  r0,r0,22,30,31
    b	.L_80389D34
    lwz     r3,-17720(r13)
    lwz     r0,24(r3)
    rlwinm  r0,r0,20,30,31
    b	.L_80389D34
    lwz     r3,-17720(r13)
    lwz     r0,24(r3)
    rlwinm  r0,r0,18,30,31
    b	.L_80389D34
.L_80389D30:
    li      r0,0
.L_80389D34:
    stw     r0,0(r4)
    blr
.size GXGetVtxDesc, . - GXGetVtxDesc

.global GXSetVtxAttrFmt
.balign 4
GXSetVtxAttrFmt:
/* 0x80389E04 | size=0x25C (604 bytes) */
    addi    r0,r4,-9
    lwz     r8,-17720(r13)
    slwi    r4,r3,2
    add     r8,r8,r4
    cmplwi  r0,16
    addi    r4,r8,28
    addi    r9,r8,60
    addi    r10,r8,92
    bgt-	.L_8038A030
    lis     r8,-32698
    addi    r8,r8,-26152
    slwi    r0,r0,2
    lwzx    r0,r8,r0
    mtctr   r0
    bctr
    lwz     r8,0(r4)
    rlwimi  r8,r5,0,31,31
    stw     r8,0(r4)
    lwz     r5,0(r4)
    rlwimi  r5,r6,1,28,30
    stw     r5,0(r4)
    lwz     r5,0(r4)
    rlwimi  r5,r7,4,23,27
    stw     r5,0(r4)
    b	.L_8038A030
    lwz     r0,0(r4)
    rlwimi  r0,r6,10,19,21
    cmpwi   r5,2
    stw     r0,0(r4)
    bne-	.L_80389E9C
    lwz     r0,0(r4)
    li      r5,1
    rlwimi  r0,r5,9,22,22
    stw     r0,0(r4)
    lwz     r0,0(r4)
    rlwimi  r0,r5,31,0,0
    stw     r0,0(r4)
    b	.L_8038A030
.L_80389E9C:
    lwz     r6,0(r4)
    rlwimi  r6,r5,9,22,22
    li      r0,0
    stw     r6,0(r4)
    lwz     r5,0(r4)
    rlwimi  r5,r0,31,0,0
    stw     r5,0(r4)
    b	.L_8038A030
    lwz     r0,0(r4)
    rlwimi  r0,r5,13,18,18
    stw     r0,0(r4)
    lwz     r0,0(r4)
    rlwimi  r0,r6,14,15,17
    stw     r0,0(r4)
    b	.L_8038A030
    lwz     r0,0(r4)
    rlwimi  r0,r5,17,14,14
    stw     r0,0(r4)
    lwz     r0,0(r4)
    rlwimi  r0,r6,18,11,13
    stw     r0,0(r4)
    b	.L_8038A030
    lwz     r8,0(r4)
    rlwimi  r8,r5,21,10,10
    stw     r8,0(r4)
    lwz     r5,0(r4)
    rlwimi  r5,r6,22,7,9
    stw     r5,0(r4)
    lwz     r5,0(r4)
    rlwimi  r5,r7,25,2,6
    stw     r5,0(r4)
    b	.L_8038A030
    lwz     r4,0(r9)
    rlwimi  r4,r5,0,31,31
    stw     r4,0(r9)
    lwz     r4,0(r9)
    rlwimi  r4,r6,1,28,30
    stw     r4,0(r9)
    lwz     r4,0(r9)
    rlwimi  r4,r7,4,23,27
    stw     r4,0(r9)
    b	.L_8038A030
    lwz     r4,0(r9)
    rlwimi  r4,r5,9,22,22
    stw     r4,0(r9)
    lwz     r4,0(r9)
    rlwimi  r4,r6,10,19,21
    stw     r4,0(r9)
    lwz     r4,0(r9)
    rlwimi  r4,r7,13,14,18
    stw     r4,0(r9)
    b	.L_8038A030
    lwz     r4,0(r9)
    rlwimi  r4,r5,18,13,13
    stw     r4,0(r9)
    lwz     r4,0(r9)
    rlwimi  r4,r6,19,10,12
    stw     r4,0(r9)
    lwz     r4,0(r9)
    rlwimi  r4,r7,22,5,9
    stw     r4,0(r9)
    b	.L_8038A030
    lwz     r4,0(r9)
    rlwimi  r4,r5,27,4,4
    stw     r4,0(r9)
    lwz     r4,0(r9)
    rlwimi  r4,r6,28,1,3
    stw     r4,0(r9)
    lwz     r4,0(r10)
    rlwimi  r4,r7,0,27,31
    stw     r4,0(r10)
    b	.L_8038A030
    lwz     r4,0(r10)
    rlwimi  r4,r5,5,26,26
    stw     r4,0(r10)
    lwz     r4,0(r10)
    rlwimi  r4,r6,6,23,25
    stw     r4,0(r10)
    lwz     r4,0(r10)
    rlwimi  r4,r7,9,18,22
    stw     r4,0(r10)
    b	.L_8038A030
    lwz     r4,0(r10)
    rlwimi  r4,r5,14,17,17
    stw     r4,0(r10)
    lwz     r4,0(r10)
    rlwimi  r4,r6,15,14,16
    stw     r4,0(r10)
    lwz     r4,0(r10)
    rlwimi  r4,r7,18,9,13
    stw     r4,0(r10)
    b	.L_8038A030
    lwz     r4,0(r10)
    rlwimi  r4,r5,23,8,8
    stw     r4,0(r10)
    lwz     r4,0(r10)
    rlwimi  r4,r6,24,5,7
    stw     r4,0(r10)
    lwz     r4,0(r10)
    rlwimi  r4,r7,27,0,4
    stw     r4,0(r10)
.L_8038A030:
    lwz     r5,-17720(r13)
    clrlwi  r0,r3,24
    li      r3,1
    lwz     r4,1452(r5)
    slw     r0,r3,r0
    clrlwi  r0,r0,24
    ori     r3,r4,16
    stw     r3,1452(r5)
    lbz     r3,1451(r5)
    or      r0,r3,r0
    stb     r0,1451(r5)
    blr
.size GXSetVtxAttrFmt, . - GXSetVtxAttrFmt

.global GXSetVtxAttrFmtv
.balign 4
GXSetVtxAttrFmtv:
/* 0x8038A060 | size=0x280 (640 bytes) */
    lwz     r6,-17720(r13)
    slwi    r0,r3,2
    lis     r5,-32698
    add     r6,r6,r0
    addi    r7,r6,28
    addi    r8,r6,60
    addi    r9,r6,92
    addi    r5,r5,-26084
    b	.L_8038A2A4
.L_8038A084:
    lwz     r10,0(r4)
    lbz     r6,12(r4)
    addi    r10,r10,-9
    lwz     r0,8(r4)
    cmplwi  r10,16
    lwz     r11,4(r4)
    bgt-	.L_8038A2A0
    slwi    r10,r10,2
    lwzx    r10,r5,r10
    mtctr   r10
    bctr
    lwz     r10,0(r7)
    rlwimi  r10,r11,0,31,31
    stw     r10,0(r7)
    lwz     r10,0(r7)
    rlwimi  r10,r0,1,28,30
    stw     r10,0(r7)
    lwz     r0,0(r7)
    rlwimi  r0,r6,4,23,27
    stw     r0,0(r7)
    b	.L_8038A2A0
    lwz     r6,0(r7)
    rlwimi  r6,r0,10,19,21
    cmpwi   r11,2
    stw     r6,0(r7)
    bne-	.L_8038A10C
    lwz     r0,0(r7)
    li      r6,1
    rlwimi  r0,r6,9,22,22
    stw     r0,0(r7)
    lwz     r0,0(r7)
    rlwimi  r0,r6,31,0,0
    stw     r0,0(r7)
    b	.L_8038A2A0
.L_8038A10C:
    lwz     r6,0(r7)
    rlwimi  r6,r11,9,22,22
    li      r0,0
    stw     r6,0(r7)
    lwz     r6,0(r7)
    rlwimi  r6,r0,31,0,0
    stw     r6,0(r7)
    b	.L_8038A2A0
    lwz     r6,0(r7)
    rlwimi  r6,r11,13,18,18
    stw     r6,0(r7)
    lwz     r6,0(r7)
    rlwimi  r6,r0,14,15,17
    stw     r6,0(r7)
    b	.L_8038A2A0
    lwz     r6,0(r7)
    rlwimi  r6,r11,17,14,14
    stw     r6,0(r7)
    lwz     r6,0(r7)
    rlwimi  r6,r0,18,11,13
    stw     r6,0(r7)
    b	.L_8038A2A0
    lwz     r10,0(r7)
    rlwimi  r10,r11,21,10,10
    stw     r10,0(r7)
    lwz     r10,0(r7)
    rlwimi  r10,r0,22,7,9
    stw     r10,0(r7)
    lwz     r0,0(r7)
    rlwimi  r0,r6,25,2,6
    stw     r0,0(r7)
    b	.L_8038A2A0
    lwz     r10,0(r8)
    rlwimi  r10,r11,0,31,31
    stw     r10,0(r8)
    lwz     r10,0(r8)
    rlwimi  r10,r0,1,28,30
    stw     r10,0(r8)
    lwz     r0,0(r8)
    rlwimi  r0,r6,4,23,27
    stw     r0,0(r8)
    b	.L_8038A2A0
    lwz     r10,0(r8)
    rlwimi  r10,r11,9,22,22
    stw     r10,0(r8)
    lwz     r10,0(r8)
    rlwimi  r10,r0,10,19,21
    stw     r10,0(r8)
    lwz     r0,0(r8)
    rlwimi  r0,r6,13,14,18
    stw     r0,0(r8)
    b	.L_8038A2A0
    lwz     r10,0(r8)
    rlwimi  r10,r11,18,13,13
    stw     r10,0(r8)
    lwz     r10,0(r8)
    rlwimi  r10,r0,19,10,12
    stw     r10,0(r8)
    lwz     r0,0(r8)
    rlwimi  r0,r6,22,5,9
    stw     r0,0(r8)
    b	.L_8038A2A0
    lwz     r10,0(r8)
    rlwimi  r10,r11,27,4,4
    stw     r10,0(r8)
    lwz     r10,0(r8)
    rlwimi  r10,r0,28,1,3
    stw     r10,0(r8)
    lwz     r0,0(r9)
    rlwimi  r0,r6,0,27,31
    stw     r0,0(r9)
    b	.L_8038A2A0
    lwz     r10,0(r9)
    rlwimi  r10,r11,5,26,26
    stw     r10,0(r9)
    lwz     r10,0(r9)
    rlwimi  r10,r0,6,23,25
    stw     r10,0(r9)
    lwz     r0,0(r9)
    rlwimi  r0,r6,9,18,22
    stw     r0,0(r9)
    b	.L_8038A2A0
    lwz     r10,0(r9)
    rlwimi  r10,r11,14,17,17
    stw     r10,0(r9)
    lwz     r10,0(r9)
    rlwimi  r10,r0,15,14,16
    stw     r10,0(r9)
    lwz     r0,0(r9)
    rlwimi  r0,r6,18,9,13
    stw     r0,0(r9)
    b	.L_8038A2A0
    lwz     r10,0(r9)
    rlwimi  r10,r11,23,8,8
    stw     r10,0(r9)
    lwz     r10,0(r9)
    rlwimi  r10,r0,24,5,7
    stw     r10,0(r9)
    lwz     r0,0(r9)
    rlwimi  r0,r6,27,0,4
    stw     r0,0(r9)
.L_8038A2A0:
    addi    r4,r4,16
.L_8038A2A4:
    lwz     r0,0(r4)
    cmpwi   r0,255
    bne+	.L_8038A084
    lwz     r5,-17720(r13)
    clrlwi  r0,r3,24
    li      r3,1
    lwz     r4,1452(r5)
    slw     r0,r3,r0
    clrlwi  r0,r0,24
    ori     r3,r4,16
    stw     r3,1452(r5)
    lbz     r3,1451(r5)
    or      r0,r3,r0
    stb     r0,1451(r5)
    blr
.size GXSetVtxAttrFmtv, . - GXSetVtxAttrFmtv

.global GXGetVtxAttrFmt
.balign 4
GXGetVtxAttrFmt:
/* 0x8038A368 | size=0x280 (640 bytes) */
    addi    r0,r4,-9
    lwz     r4,-17720(r13)
    slwi    r3,r3,2
    add     r4,r4,r3
    cmplwi  r0,16
    addi    r3,r4,28
    addi    r8,r4,60
    addi    r9,r4,92
    bgt-	.L_8038A5D0
    lis     r4,-32698
    addi    r4,r4,-26016
    slwi    r0,r0,2
    lwzx    r0,r4,r0
    mtctr   r0
    bctr
    lwz     r0,0(r3)
    clrlwi  r0,r0,31
    stw     r0,0(r5)
    lwz     r0,0(r3)
    rlwinm  r0,r0,31,29,31
    stw     r0,0(r6)
    lwz     r0,0(r3)
    rlwinm  r0,r0,28,27,31
    stb     r0,0(r7)
    blr
    lwz     r0,0(r3)
    rlwinm  r0,r0,23,31,31
    stw     r0,0(r5)
    lwz     r0,0(r5)
    cmpwi   r0,1
    bne-	.L_8038A3F8
    lwz     r0,0(r3)
    srwi.   r0,r0,31
    beq-	.L_8038A3F8
    li      r0,2
    stw     r0,0(r5)
.L_8038A3F8:
    lwz     r0,0(r3)
    rlwinm  r0,r0,22,29,31
    stw     r0,0(r6)
    lwz     r0,0(r6)
    cmpwi   r0,2
    beq-	.L_8038A43C
    bge-	.L_8038A420
    cmpwi   r0,1
    bge-	.L_8038A42C
    b	.L_8038A43C
.L_8038A420:
    cmpwi   r0,4
    bge-	.L_8038A43C
    b	.L_8038A434
.L_8038A42C:
    li      r0,6
    b	.L_8038A440
.L_8038A434:
    li      r0,14
    b	.L_8038A440
.L_8038A43C:
    li      r0,0
.L_8038A440:
    stb     r0,0(r7)
    blr
    lwz     r4,0(r3)
    li      r0,0
    rlwinm  r4,r4,19,31,31
    stw     r4,0(r5)
    lwz     r3,0(r3)
    rlwinm  r3,r3,18,29,31
    stw     r3,0(r6)
    stb     r0,0(r7)
    blr
    lwz     r4,0(r3)
    li      r0,0
    rlwinm  r4,r4,15,31,31
    stw     r4,0(r5)
    lwz     r3,0(r3)
    rlwinm  r3,r3,14,29,31
    stw     r3,0(r6)
    stb     r0,0(r7)
    blr
    lwz     r0,0(r3)
    rlwinm  r0,r0,11,31,31
    stw     r0,0(r5)
    lwz     r0,0(r3)
    rlwinm  r0,r0,10,29,31
    stw     r0,0(r6)
    lwz     r0,0(r3)
    rlwinm  r0,r0,7,27,31
    stb     r0,0(r7)
    blr
    lwz     r0,0(r8)
    clrlwi  r0,r0,31
    stw     r0,0(r5)
    lwz     r0,0(r8)
    rlwinm  r0,r0,31,29,31
    stw     r0,0(r6)
    lwz     r0,0(r8)
    rlwinm  r0,r0,28,27,31
    stb     r0,0(r7)
    blr
    lwz     r0,0(r8)
    rlwinm  r0,r0,23,31,31
    stw     r0,0(r5)
    lwz     r0,0(r8)
    rlwinm  r0,r0,22,29,31
    stw     r0,0(r6)
    lwz     r0,0(r8)
    rlwinm  r0,r0,19,27,31
    stb     r0,0(r7)
    blr
    lwz     r0,0(r8)
    rlwinm  r0,r0,14,31,31
    stw     r0,0(r5)
    lwz     r0,0(r8)
    rlwinm  r0,r0,13,29,31
    stw     r0,0(r6)
    lwz     r0,0(r8)
    rlwinm  r0,r0,10,27,31
    stb     r0,0(r7)
    blr
    lwz     r0,0(r8)
    rlwinm  r0,r0,5,31,31
    stw     r0,0(r5)
    lwz     r0,0(r8)
    rlwinm  r0,r0,4,29,31
    stw     r0,0(r6)
    lwz     r0,0(r9)
    clrlwi  r0,r0,27
    stb     r0,0(r7)
    blr
    lwz     r0,0(r9)
    rlwinm  r0,r0,27,31,31
    stw     r0,0(r5)
    lwz     r0,0(r9)
    rlwinm  r0,r0,26,29,31
    stw     r0,0(r6)
    lwz     r0,0(r9)
    rlwinm  r0,r0,23,27,31
    stb     r0,0(r7)
    blr
    lwz     r0,0(r9)
    rlwinm  r0,r0,18,31,31
    stw     r0,0(r5)
    lwz     r0,0(r9)
    rlwinm  r0,r0,17,29,31
    stw     r0,0(r6)
    lwz     r0,0(r9)
    rlwinm  r0,r0,14,27,31
    stb     r0,0(r7)
    blr
    lwz     r0,0(r9)
    rlwinm  r0,r0,9,31,31
    stw     r0,0(r5)
    lwz     r0,0(r9)
    rlwinm  r0,r0,8,29,31
    stw     r0,0(r6)
    lwz     r0,0(r9)
    srwi    r0,r0,27
    stb     r0,0(r7)
    blr
.L_8038A5D0:
    li      r0,1
    stw     r0,0(r5)
    li      r0,0
    stw     r0,0(r6)
    stb     r0,0(r7)
    blr
.size GXGetVtxAttrFmt, . - GXGetVtxAttrFmt

.global GXSetTexCoordGen2
.balign 4
GXSetTexCoordGen2:
/* 0x8038A6B0 | size=0x280 (640 bytes) */
    mflr    r0
    cmplwi  r5,20
    stw     r0,4(r1)
    li      r10,0
    li      r12,0
    stwu    r1,-8(r1)
    li      r11,5
    bgt-	.L_8038A764
    lis     r9,-32698
    addi    r9,r9,-25920
    slwi    r0,r5,2
    lwzx    r0,r9,r0
    mtctr   r0
    bctr
    li      r11,0
    li      r12,1
    b	.L_8038A764
    li      r11,1
    li      r12,1
    b	.L_8038A764
    li      r11,3
    li      r12,1
    b	.L_8038A764
    li      r11,4
    li      r12,1
    b	.L_8038A764
    li      r11,2
    b	.L_8038A764
    li      r11,2
    b	.L_8038A764
    li      r11,5
    b	.L_8038A764
    li      r11,6
    b	.L_8038A764
    li      r11,7
    b	.L_8038A764
    li      r11,8
    b	.L_8038A764
    li      r11,9
    b	.L_8038A764
    li      r11,10
    b	.L_8038A764
    li      r11,11
    b	.L_8038A764
    li      r11,12
.L_8038A764:
    cmpwi   r4,1
    beq-	.L_8038A78C
    bge-	.L_8038A77C
    cmpwi   r4,0
    bge-	.L_8038A7AC
    b	.L_8038A824
.L_8038A77C:
    cmpwi   r4,10
    beq-	.L_8038A7F4
    bge-	.L_8038A824
    b	.L_8038A7C8
.L_8038A78C:
    li      r0,0
    rlwimi  r10,r0,1,30,30
    addi    r4,r10,0
    rlwimi  r4,r12,2,29,29
    addi    r10,r4,0
    rlwimi  r10,r0,4,25,27
    rlwimi  r10,r11,7,20,24
    b	.L_8038A824
.L_8038A7AC:
    li      r0,1
    rlwimi  r10,r0,1,30,30
    li      r0,0
    rlwimi  r10,r12,2,29,29
    rlwimi  r10,r0,4,25,27
    rlwimi  r10,r11,7,20,24
    b	.L_8038A824
.L_8038A7C8:
    li      r0,0
    rlwimi  r10,r0,1,30,30
    li      r0,1
    rlwimi  r10,r12,2,29,29
    rlwimi  r10,r0,4,25,27
    addi    r0,r5,-12
    rlwimi  r10,r11,7,20,24
    rlwimi  r10,r0,12,17,19
    addi    r0,r4,-2
    rlwimi  r10,r0,15,14,16
    b	.L_8038A824
.L_8038A7F4:
    cmpwi   r5,19
    li      r0,0
    rlwimi  r10,r0,1,30,30
    rlwimi  r10,r12,2,29,29
    bne-	.L_8038A814
    li      r0,2
    rlwimi  r10,r0,4,25,27
    b	.L_8038A81C
.L_8038A814:
    li      r0,3
    rlwimi  r10,r0,4,25,27
.L_8038A81C:
    li      r0,2
    rlwimi  r10,r0,7,20,24
.L_8038A824:
    li      r9,16
    lis     r5,-13311
    stb     r9,-32768(r5)
    addi    r4,r3,4160
    addi    r0,r8,-64
    stw     r4,-32768(r5)
    li      r8,0
    rlwimi  r8,r0,0,26,31
    stw     r10,-32768(r5)
    addi    r0,r3,4176
    cmplwi  r3,6
    stb     r9,-32768(r5)
    rlwimi  r8,r7,8,23,23
    stw     r0,-32768(r5)
    stw     r8,-32768(r5)
    bgt-	.L_8038A908
    lis     r4,-32698
    addi    r4,r4,-25948
    slwi    r0,r3,2
    lwzx    r0,r4,r0
    mtctr   r0
    bctr
    lwz     r4,-17720(r13)
    lwz     r0,128(r4)
    rlwimi  r0,r6,6,20,25
    stw     r0,128(r4)
    b	.L_8038A918
    lwz     r4,-17720(r13)
    lwz     r0,128(r4)
    rlwimi  r0,r6,12,14,19
    stw     r0,128(r4)
    b	.L_8038A918
    lwz     r4,-17720(r13)
    lwz     r0,128(r4)
    rlwimi  r0,r6,18,8,13
    stw     r0,128(r4)
    b	.L_8038A918
    lwz     r4,-17720(r13)
    lwz     r0,128(r4)
    rlwimi  r0,r6,24,2,7
    stw     r0,128(r4)
    b	.L_8038A918
    lwz     r4,-17720(r13)
    lwz     r0,132(r4)
    rlwimi  r0,r6,0,26,31
    stw     r0,132(r4)
    b	.L_8038A918
    lwz     r4,-17720(r13)
    lwz     r0,132(r4)
    rlwimi  r0,r6,6,20,25
    stw     r0,132(r4)
    b	.L_8038A918
    lwz     r4,-17720(r13)
    lwz     r0,132(r4)
    rlwimi  r0,r6,12,14,19
    stw     r0,132(r4)
    b	.L_8038A918
.L_8038A908:
    lwz     r4,-17720(r13)
    lwz     r0,132(r4)
    rlwimi  r0,r6,18,8,13
    stw     r0,132(r4)
.L_8038A918:
    addi    r3,r3,1
    bl	__GXSetMatrixIndex
    lwz     r0,12(r1)
    addi    r1,r1,8
    mtlr    r0
    blr
.size GXSetTexCoordGen2, . - GXSetTexCoordGen2

#
# === GXBump.o (gx.a) ===
#

.global GXSetIndTexMtx
.balign 4
GXSetIndTexMtx:
/* 0x8038ECC4 | size=0x178 (376 bytes) */
    stwu    r1,-112(r1)
    cmpwi   r3,8
    stw     r31,108(r1)
    stw     r30,104(r1)
    stw     r29,100(r1)
    beq-	.L_8038ED1C
    bge-	.L_8038ECF8
    cmpwi   r3,4
    beq-	.L_8038ED1C
    bge-	.L_8038ED0C
    cmpwi   r3,1
    bge-	.L_8038ED04
    b	.L_8038ED1C
.L_8038ECF8:
    cmpwi   r3,12
    bge-	.L_8038ED1C
    b	.L_8038ED14
.L_8038ED04:
    addi    r0,r3,-1
    b	.L_8038ED20
.L_8038ED0C:
    addi    r0,r3,-5
    b	.L_8038ED20
.L_8038ED14:
    addi    r0,r3,-9
    b	.L_8038ED20
.L_8038ED1C:
    li      r0,0
.L_8038ED20:
    lfs     f2,-17504(r13)
    mulli   r31,r0,3
    lfs     f1,0(r4)
    lfs     f0,12(r4)
    fmuls   f1,f2,f1
    addi    r10,r5,17
    fmuls   f0,f2,f0
    extsb   r10,r10
    li      r12,97
    fctiwz  f1,f1
    lis     r11,-13311
    fctiwz  f0,f0
    li      r30,0
    addi    r0,r31,6
    stfd    f1,88(r1)
    rlwinm  r8,r10,30,30,31
    addi    r7,r31,7
    lwz     r3,-17720(r13)
    stfd    f0,80(r1)
    lwz     r9,92(r1)
    li      r29,0
    lwz     r6,84(r1)
    addi    r5,r31,8
    rlwimi  r30,r9,0,21,31
    addi    r9,r30,0
    stb     r12,-32768(r11)
    rlwimi  r9,r6,11,10,20
    rlwimi  r9,r10,22,8,9
    rlwimi  r9,r0,24,0,7
    stw     r9,-32768(r11)
    rlwinm  r6,r10,28,30,31
    li      r30,0
    lfs     f1,4(r4)
    li      r0,0
    lfs     f0,16(r4)
    fmuls   f1,f2,f1
    fmuls   f0,f2,f0
    stb     r12,-32768(r11)
    fctiwz  f1,f1
    fctiwz  f0,f0
    stfd    f1,72(r1)
    stfd    f0,64(r1)
    lwz     r10,76(r1)
    lwz     r9,68(r1)
    rlwimi  r29,r10,0,21,31
    rlwimi  r29,r9,11,10,20
    rlwimi  r29,r8,22,8,9
    rlwimi  r29,r7,24,0,7
    stw     r29,-32768(r11)
    lfs     f1,8(r4)
    lfs     f0,20(r4)
    fmuls   f1,f2,f1
    fmuls   f0,f2,f0
    stb     r12,-32768(r11)
    fctiwz  f1,f1
    fctiwz  f0,f0
    stfd    f1,56(r1)
    stfd    f0,48(r1)
    lwz     r7,60(r1)
    lwz     r4,52(r1)
    rlwimi  r30,r7,0,21,31
    rlwimi  r30,r4,11,10,20
    rlwimi  r30,r6,22,8,9
    rlwimi  r30,r5,24,0,7
    stw     r30,-32768(r11)
    sth     r0,2(r3)
    lwz     r31,108(r1)
    lwz     r30,104(r1)
    lwz     r29,100(r1)
    addi    r1,r1,112
    blr
.size GXSetIndTexMtx, . - GXSetIndTexMtx

.global GXSetIndTexCoordScale
.balign 4
GXSetIndTexCoordScale:
/* 0x8038EE3C | size=0x144 (324 bytes) */
    cmpwi   r3,2
    beq-	.L_8038EEEC
    bge-	.L_8038EE58
    cmpwi   r3,0
    beq-	.L_8038EE64
    bge-	.L_8038EEA8
    b	.L_8038EF70
.L_8038EE58:
    cmpwi   r3,4
    bge-	.L_8038EF70
    b	.L_8038EF30
.L_8038EE64:
    lwz     r8,-17720(r13)
    li      r6,37
    li      r0,97
    lwz     r7,296(r8)
    rlwimi  r7,r4,0,28,31
    lis     r3,-13311
    stw     r7,296(r8)
    lwz     r4,296(r8)
    rlwimi  r4,r5,4,24,27
    stw     r4,296(r8)
    lwz     r4,296(r8)
    rlwimi  r4,r6,24,0,7
    stw     r4,296(r8)
    stb     r0,-32768(r3)
    lwz     r0,296(r8)
    stw     r0,-32768(r3)
    b	.L_8038EF70
.L_8038EEA8:
    lwz     r8,-17720(r13)
    li      r6,37
    li      r0,97
    lwz     r7,296(r8)
    rlwimi  r7,r4,8,20,23
    lis     r3,-13311
    stw     r7,296(r8)
    lwz     r4,296(r8)
    rlwimi  r4,r5,12,16,19
    stw     r4,296(r8)
    lwz     r4,296(r8)
    rlwimi  r4,r6,24,0,7
    stw     r4,296(r8)
    stb     r0,-32768(r3)
    lwz     r0,296(r8)
    stw     r0,-32768(r3)
    b	.L_8038EF70
.L_8038EEEC:
    lwz     r8,-17720(r13)
    li      r6,38
    li      r0,97
    lwz     r7,300(r8)
    rlwimi  r7,r4,0,28,31
    lis     r3,-13311
    stw     r7,300(r8)
    lwz     r4,300(r8)
    rlwimi  r4,r5,4,24,27
    stw     r4,300(r8)
    lwz     r4,300(r8)
    rlwimi  r4,r6,24,0,7
    stw     r4,300(r8)
    stb     r0,-32768(r3)
    lwz     r0,300(r8)
    stw     r0,-32768(r3)
    b	.L_8038EF70
.L_8038EF30:
    lwz     r8,-17720(r13)
    li      r6,38
    li      r0,97
    lwz     r7,300(r8)
    rlwimi  r7,r4,8,20,23
    lis     r3,-13311
    stw     r7,300(r8)
    lwz     r4,300(r8)
    rlwimi  r4,r5,12,16,19
    stw     r4,300(r8)
    lwz     r4,300(r8)
    rlwimi  r4,r6,24,0,7
    stw     r4,300(r8)
    stb     r0,-32768(r3)
    lwz     r0,300(r8)
    stw     r0,-32768(r3)
.L_8038EF70:
    lwz     r3,-17720(r13)
    li      r0,0
    sth     r0,2(r3)
    blr
.size GXSetIndTexCoordScale, . - GXSetIndTexCoordScale

.global GXSetTevIndTile
.balign 4
GXSetTevIndTile:
/* 0x8038F13C | size=0x1AC (428 bytes) */
    mflr    r0
    stw     r0,4(r1)
    clrlwi  r0,r5,16
    cmpwi   r0,64
    stwu    r1,-112(r1)
    stmw    r24,80(r1)
    addi    r24,r3,0
    lwz     r28,120(r1)
    addi    r25,r4,0
    lwz     r29,124(r1)
    addi    r26,r9,0
    addi    r27,r10,0
    beq-	.L_8038F1B4
    bge-	.L_8038F18C
    cmpwi   r0,32
    beq-	.L_8038F1BC
    bge-	.L_8038F1CC
    cmpwi   r0,16
    beq-	.L_8038F1C4
    b	.L_8038F1CC
.L_8038F18C:
    cmpwi   r0,256
    beq-	.L_8038F1A4
    bge-	.L_8038F1CC
    cmpwi   r0,128
    beq-	.L_8038F1AC
    b	.L_8038F1CC
.L_8038F1A4:
    li      r31,1
    b	.L_8038F1D0
.L_8038F1AC:
    li      r31,2
    b	.L_8038F1D0
.L_8038F1B4:
    li      r31,3
    b	.L_8038F1D0
.L_8038F1BC:
    li      r31,4
    b	.L_8038F1D0
.L_8038F1C4:
    li      r31,5
    b	.L_8038F1D0
.L_8038F1CC:
    li      r31,0
.L_8038F1D0:
    clrlwi  r0,r6,16
    cmpwi   r0,64
    beq-	.L_8038F220
    bge-	.L_8038F1F8
    cmpwi   r0,32
    beq-	.L_8038F228
    bge-	.L_8038F238
    cmpwi   r0,16
    beq-	.L_8038F230
    b	.L_8038F238
.L_8038F1F8:
    cmpwi   r0,256
    beq-	.L_8038F210
    bge-	.L_8038F238
    cmpwi   r0,128
    beq-	.L_8038F218
    b	.L_8038F238
.L_8038F210:
    li      r30,1
    b	.L_8038F23C
.L_8038F218:
    li      r30,2
    b	.L_8038F23C
.L_8038F220:
    li      r30,3
    b	.L_8038F23C
.L_8038F228:
    li      r30,4
    b	.L_8038F23C
.L_8038F230:
    li      r30,5
    b	.L_8038F23C
.L_8038F238:
    li      r30,0
.L_8038F23C:
    clrlwi  r0,r7,16
    lfd     f4,-17488(r13)
    stw     r0,76(r1)
    lis     r6,17200
    clrlwi  r0,r8,16
    lfs     f3,-17500(r13)
    stw     r6,72(r1)
    lfs     f1,-17496(r13)
    mr      r3,r27
    lfd     f0,72(r1)
    addi    r4,r1,40
    stw     r0,68(r1)
    fsubs   f0,f0,f4
    li      r5,10
    stw     r6,64(r1)
    fmuls   f2,f0,f3
    lfd     f0,64(r1)
    fsubs   f0,f0,f4
    stfs    f2,40(r1)
    stfs    f1,48(r1)
    fmuls   f0,f0,f3
    stfs    f1,44(r1)
    stfs    f0,56(r1)
    stfs    f1,60(r1)
    stfs    f1,52(r1)
    bl	GXSetIndTexMtx
    li      r0,1
    stw     r0,8(r1)
    addi    r3,r24,0
    addi    r4,r25,0
    stw     r29,12(r1)
    addi    r5,r26,0
    addi    r6,r28,0
    addi    r7,r27,0
    addi    r8,r31,0
    addi    r9,r30,0
    li      r10,0
    bl	GXSetTevIndirect
    lmw     r24,80(r1)
    lwz     r0,116(r1)
    addi    r1,r1,112
    mtlr    r0
    blr
.size GXSetTevIndTile, . - GXSetTevIndTile

.global GXSetTevIndBumpST
.balign 4
GXSetTevIndBumpST:
/* 0x8038F2E8 | size=0x10C (268 bytes) */
    mflr    r0
    cmpwi   r5,2
    stw     r0,4(r1)
    stwu    r1,-48(r1)
    stw     r31,44(r1)
    stw     r30,40(r1)
    stw     r29,36(r1)
    addi    r29,r4,0
    stw     r28,32(r1)
    addi    r28,r3,0
    beq-	.L_8038F33C
    bge-	.L_8038F324
    cmpwi   r5,1
    bge-	.L_8038F330
    b	.L_8038F350
.L_8038F324:
    cmpwi   r5,4
    bge-	.L_8038F350
    b	.L_8038F348
.L_8038F330:
    li      r7,5
    li      r30,9
    b	.L_8038F350
.L_8038F33C:
    li      r7,6
    li      r30,10
    b	.L_8038F350
.L_8038F348:
    li      r7,7
    li      r30,11
.L_8038F350:
    li      r31,0
    stw     r31,8(r1)
    addi    r3,r28,0
    addi    r4,r29,0
    stw     r31,12(r1)
    li      r5,0
    li      r6,3
    li      r8,6
    li      r9,6
    li      r10,0
    bl	GXSetTevIndirect
    stw     r31,8(r1)
    addi    r4,r29,0
    addi    r7,r30,0
    stw     r31,12(r1)
    addi    r3,r28,1
    li      r5,0
    li      r6,3
    li      r8,6
    li      r9,6
    li      r10,1
    bl	GXSetTevIndirect
    stw     r31,8(r1)
    addi    r4,r29,0
    addi    r3,r28,2
    stw     r31,12(r1)
    li      r5,0
    li      r6,0
    li      r7,0
    li      r8,0
    li      r9,0
    li      r10,1
    bl	GXSetTevIndirect
    lwz     r0,52(r1)
    lwz     r31,44(r1)
    lwz     r30,40(r1)
    lwz     r29,36(r1)
    lwz     r28,32(r1)
    addi    r1,r1,48
    mtlr    r0
    blr
.size GXSetTevIndBumpST, . - GXSetTevIndBumpST

#
# === GXFifo.o (gx.a) ===
#

.global GXCPInterruptHandler
.balign 4
GXCPInterruptHandler:
/* 0x80388580 | size=0x134 (308 bytes) */
    mflr    r0
    stw     r0,4(r1)
    stwu    r1,-736(r1)
    stw     r31,732(r1)
    mr      r31,r4
    lwz     r5,-21996(r13)
    lwz     r3,-17720(r13)
    lhz     r0,0(r5)
    stw     r0,12(r3)
    lwz     r0,8(r3)
    rlwinm. r0,r0,29,31,31
    beq-	.L_803885E4
    lwz     r0,12(r3)
    rlwinm. r0,r0,31,31,31
    beq-	.L_803885E4
    lwz     r3,-21952(r13)
    bl	OSResumeThread
    li      r0,0
    stw     r0,-21944(r13)
    li      r3,1
    li      r4,1
    bl	__GXWriteFifoIntReset
    li      r3,1
    li      r4,0
    bl	__GXWriteFifoIntEnable
.L_803885E4:
    lwz     r3,-17720(r13)
    lwz     r0,8(r3)
    rlwinm. r0,r0,30,31,31
    beq-	.L_80388634
    lwz     r0,12(r3)
    clrlwi. r0,r0,31
    beq-	.L_80388634
    lwz     r5,-21936(r13)
    li      r3,0
    li      r4,1
    addi    r0,r5,1
    stw     r0,-21936(r13)
    bl	__GXWriteFifoIntEnable
    li      r3,1
    li      r4,0
    bl	__GXWriteFifoIntReset
    li      r0,1
    lwz     r3,-21952(r13)
    stw     r0,-21944(r13)
    bl	OSSuspendThread
.L_80388634:
    lwz     r3,-17720(r13)
    lwz     r4,8(r3)
    rlwinm. r0,r4,27,31,31
    beq-	.L_803886A0
    lwz     r0,12(r3)
    rlwinm. r0,r0,28,31,31
    beq-	.L_803886A0
    li      r0,0
    rlwimi  r4,r0,5,26,26
    stw     r4,8(r3)
    lwz     r0,8(r3)
    lwz     r3,-21996(r13)
    sth     r0,2(r3)
    lwz     r0,-21940(r13)
    cmplwi  r0,0
    beq-	.L_803886A0
    addi    r3,r1,16
    bl	OSClearContext
    addi    r3,r1,16
    bl	OSSetCurrentContext
    lwz     r12,-21940(r13)
    mtlr    r12
    blrl
    addi    r3,r1,16
    bl	OSClearContext
    mr      r3,r31
    bl	OSSetCurrentContext
.L_803886A0:
    lwz     r0,740(r1)
    lwz     r31,732(r1)
    addi    r1,r1,736
    mtlr    r0
    blr
.size GXCPInterruptHandler, . - GXCPInterruptHandler

.global GXSetCPUFifo
.balign 4
GXSetCPUFifo:
/* 0x8038879C | size=0x128 (296 bytes) */
    mflr    r0
    stw     r0,4(r1)
    stwu    r1,-24(r1)
    stw     r31,20(r1)
    stw     r30,16(r1)
    mr      r30,r3
    bl	OSDisableInterrupts
    lwz     r0,-21956(r13)
    addi    r31,r3,0
    stw     r30,-21960(r13)
    cmplw   r30,r0
    bne-	.L_80388838
    lwz     r0,0(r30)
    li      r8,0
    lwz     r3,-22000(r13)
    li      r6,0
    clrlwi  r0,r0,2
    stw     r0,12(r3)
    li      r0,1
    li      r3,1
    lwz     r7,4(r30)
    li      r4,1
    lwz     r5,-22000(r13)
    clrlwi  r7,r7,2
    stw     r7,16(r5)
    lwz     r7,24(r30)
    lwz     r5,-22000(r13)
    rlwimi  r8,r7,0,6,26
    addi    r7,r8,0
    rlwimi  r7,r6,26,5,5
    stw     r7,20(r5)
    stb     r0,-21948(r13)
    bl	__GXWriteFifoIntReset
    li      r3,1
    li      r4,0
    bl	__GXWriteFifoIntEnable
    li      r3,1
    bl	__GXFifoLink
    b	.L_803888A0
.L_80388838:
    lbz     r0,-21948(r13)
    cmplwi  r0,0
    beq-	.L_80388854
    li      r3,0
    bl	__GXFifoLink
    li      r0,0
    stb     r0,-21948(r13)
.L_80388854:
    li      r3,0
    li      r4,0
    bl	__GXWriteFifoIntEnable
    lwz     r4,0(r30)
    li      r5,0
    lwz     r3,-22000(r13)
    li      r0,0
    clrlwi  r4,r4,2
    stw     r4,12(r3)
    lwz     r4,4(r30)
    lwz     r3,-22000(r13)
    clrlwi  r4,r4,2
    stw     r4,16(r3)
    lwz     r4,24(r30)
    lwz     r3,-22000(r13)
    rlwimi  r5,r4,0,6,26
    addi    r4,r5,0
    rlwimi  r4,r0,26,5,5
    stw     r4,20(r3)
.L_803888A0:
    bl	PPCSync
    mr      r3,r31
    bl	OSRestoreInterrupts
    lwz     r0,28(r1)
    lwz     r31,20(r1)
    lwz     r30,16(r1)
    addi    r1,r1,24
    mtlr    r0
    blr
.size GXSetCPUFifo, . - GXSetCPUFifo

.global GXSetGPFifo
.balign 4
GXSetGPFifo:
/* 0x803888C4 | size=0x178 (376 bytes) */
    mflr    r0
    stw     r0,4(r1)
    stwu    r1,-24(r1)
    stw     r31,20(r1)
    stw     r30,16(r1)
    mr      r30,r3
    bl	OSDisableInterrupts
    mr      r31,r3
    bl	__GXFifoReadDisable
    li      r3,0
    li      r4,0
    bl	__GXWriteFifoIntEnable
    stw     r30,-21956(r13)
    lwz     r3,-21996(r13)
    lwz     r0,0(r30)
    sth     r0,32(r3)
    lwz     r0,4(r30)
    lwz     r3,-21996(r13)
    sth     r0,36(r3)
    lwz     r0,28(r30)
    lwz     r3,-21996(r13)
    sth     r0,48(r3)
    lwz     r0,24(r30)
    lwz     r3,-21996(r13)
    sth     r0,52(r3)
    lwz     r0,20(r30)
    lwz     r3,-21996(r13)
    sth     r0,56(r3)
    lwz     r0,12(r30)
    lwz     r3,-21996(r13)
    sth     r0,40(r3)
    lwz     r0,16(r30)
    lwz     r3,-21996(r13)
    sth     r0,44(r3)
    lwz     r0,0(r30)
    lwz     r3,-21996(r13)
    rlwinm  r0,r0,16,18,31
    sth     r0,34(r3)
    lwz     r0,4(r30)
    lwz     r3,-21996(r13)
    rlwinm  r0,r0,16,18,31
    sth     r0,38(r3)
    lwz     r0,28(r30)
    lwz     r3,-21996(r13)
    srawi   r0,r0,16
    sth     r0,50(r3)
    lwz     r0,24(r30)
    lwz     r3,-21996(r13)
    rlwinm  r0,r0,16,18,31
    sth     r0,54(r3)
    lwz     r0,20(r30)
    lwz     r3,-21996(r13)
    rlwinm  r0,r0,16,18,31
    sth     r0,58(r3)
    lwz     r0,12(r30)
    lwz     r3,-21996(r13)
    srwi    r0,r0,16
    sth     r0,42(r3)
    lwz     r0,16(r30)
    lwz     r3,-21996(r13)
    srwi    r0,r0,16
    sth     r0,46(r3)
    bl	PPCSync
    lwz     r3,-21960(r13)
    lwz     r0,-21956(r13)
    cmplw   r3,r0
    bne-	.L_803889F0
    li      r0,1
    stb     r0,-21948(r13)
    li      r3,1
    li      r4,0
    bl	__GXWriteFifoIntEnable
    li      r3,1
    bl	__GXFifoLink
    b	.L_80388A0C
.L_803889F0:
    li      r0,0
    stb     r0,-21948(r13)
    li      r3,0
    li      r4,0
    bl	__GXWriteFifoIntEnable
    li      r3,0
    bl	__GXFifoLink
.L_80388A0C:
    li      r3,1
    li      r4,1
    bl	__GXWriteFifoIntReset
    bl	__GXFifoReadEnable
    mr      r3,r31
    bl	OSRestoreInterrupts
    lwz     r0,28(r1)
    lwz     r31,20(r1)
    lwz     r30,16(r1)
    addi    r1,r1,24
    mtlr    r0
    blr
.size GXSetGPFifo, . - GXSetGPFifo

.global GXGetFifoStatus
.balign 4
GXGetFifoStatus:
/* 0x80388BB8 | size=0x114 (276 bytes) */
    mflr    r0
    stw     r0,4(r1)
    li      r0,0
    stwu    r1,-80(r1)
    stmw    r23,44(r1)
    addi    r26,r5,0
    mr      r25,r4
    addi    r27,r6,0
    addi    r30,r9,0
    addi    r28,r7,0
    addi    r29,r8,0
    mr      r31,r3
    stb     r0,0(r5)
    stb     r0,0(r4)
    stw     r0,0(r6)
    stb     r0,0(r9)
    lwz     r0,-21956(r13)
    cmplw   r3,r0
    bne-	.L_80388C30
    lwz     r4,-21996(r13)
    lhz     r3,58(r4)
    lhz     r4,56(r4)
    rlwimi  r4,r3,16,0,15
    addis   r0,r4,-32768
    stw     r0,20(r31)
    lwz     r4,-21996(r13)
    lhz     r3,50(r4)
    lhz     r0,48(r4)
    rlwimi  r0,r3,16,0,15
    stw     r0,28(r31)
.L_80388C30:
    lwz     r0,-21960(r13)
    cmplw   r31,r0
    bne-	.L_80388C58
    bl	GXFlush
    mr      r3,r31
    bl	__GXSaveCPUFifoAux
    lwz     r3,-22000(r13)
    lwz     r0,20(r3)
    rlwinm  r0,r0,6,31,31
    stb     r0,0(r30)
.L_80388C58:
    lwz     r3,28(r31)
    lwz     r0,12(r31)
    subfc   r0,r3,r0
    subfe   r23,r23,r23
    neg     r0,r23
    stb     r0,0(r25)
    lwz     r3,28(r31)
    lwz     r0,16(r31)
    subfc   r0,r0,r3
    subfe   r24,r24,r24
    neg     r0,r24
    stb     r0,0(r26)
    lwz     r0,28(r31)
    stw     r0,0(r27)
    lwz     r0,-21960(r13)
    subf    r0,r0,r31
    cntlzw  r0,r0
    rlwinm  r0,r0,27,24,31
    stb     r0,0(r28)
    lwz     r0,-21956(r13)
    subf    r0,r0,r31
    cntlzw  r0,r0
    rlwinm  r0,r0,27,24,31
    stb     r0,0(r29)
    lmw     r23,44(r1)
    lwz     r0,84(r1)
    addi    r1,r1,80
    mtlr    r0
    blr
.size GXGetFifoStatus, . - GXGetFifoStatus

.global GXRedirectWriteGatherPipe
.balign 4
GXRedirectWriteGatherPipe:
/* 0x80389180 | size=0x108 (264 bytes) */
    mflr    r0
    stw     r0,4(r1)
    stwu    r1,-32(r1)
    stw     r31,28(r1)
    li      r31,0
    stw     r30,24(r1)
    stw     r29,20(r1)
    addi    r29,r3,0
    bl	OSDisableInterrupts
    mr      r30,r3
    bl	GXFlush
.L_803891AC:
    bl	PPCMfwpar
    clrlwi. r0,r3,31
    bne+	.L_803891AC
    lis     r3,3073
    addi    r3,r3,-32768
    bl	PPCMtwpar
    lbz     r0,-21948(r13)
    cmplwi  r0,0
    beq-	.L_80389214
    lwz     r5,-17720(r13)
    li      r4,0
    lwz     r0,8(r5)
    rlwimi  r0,r4,4,27,27
    stw     r0,8(r5)
    lwz     r0,8(r5)
    lwz     r3,-21996(r13)
    sth     r0,2(r3)
    lwz     r0,8(r5)
    rlwimi  r0,r4,2,29,29
    stw     r0,8(r5)
    lwz     r0,8(r5)
    rlwimi  r0,r4,3,28,28
    stw     r0,8(r5)
    lwz     r0,8(r5)
    lwz     r3,-21996(r13)
    sth     r0,2(r3)
.L_80389214:
    lwz     r4,-22000(r13)
    rlwimi  r31,r29,0,6,26
    lwz     r3,-21960(r13)
    addi    r5,r31,0
    lwz     r4,20(r4)
    rlwinm  r4,r4,0,6,4
    addis   r0,r4,-32768
    stw     r0,24(r3)
    li      r4,0
    lis     r0,1024
    lwz     r3,-22000(r13)
    rlwimi  r5,r4,26,5,5
    stw     r4,12(r3)
    lwz     r3,-22000(r13)
    stw     r0,16(r3)
    lwz     r3,-22000(r13)
    stw     r5,20(r3)
    bl	PPCSync
    mr      r3,r30
    bl	OSRestoreInterrupts
    lis     r3,-13311
    lwz     r0,36(r1)
    lwz     r31,28(r1)
    addi    r3,r3,-32768
    lwz     r30,24(r1)
    lwz     r29,20(r1)
    addi    r1,r1,32
    mtlr    r0
    blr
.size GXRedirectWriteGatherPipe, . - GXRedirectWriteGatherPipe

.global GXRestoreWriteGatherPipe
.balign 4
GXRestoreWriteGatherPipe:
/* 0x80389288 | size=0x1A0 (416 bytes) */
    mflr    r0
    stw     r0,4(r1)
    stwu    r1,-24(r1)
    stw     r31,20(r1)
    li      r31,0
    stw     r30,16(r1)
    bl	OSDisableInterrupts
    lis     r5,-13311
    li      r4,0
    stb     r4,-32768(r5)
    li      r6,24
    subfic  r0,r6,31
    stb     r4,-32768(r5)
    cmplwi  r6,31
    mtctr   r0
    mr      r30,r3
    stb     r4,-32768(r5)
    stb     r4,-32768(r5)
    stb     r4,-32768(r5)
    stb     r4,-32768(r5)
    stb     r4,-32768(r5)
    stb     r4,-32768(r5)
    stb     r4,-32768(r5)
    stb     r4,-32768(r5)
    stb     r4,-32768(r5)
    stb     r4,-32768(r5)
    stb     r4,-32768(r5)
    stb     r4,-32768(r5)
    stb     r4,-32768(r5)
    stb     r4,-32768(r5)
    stb     r4,-32768(r5)
    stb     r4,-32768(r5)
    stb     r4,-32768(r5)
    stb     r4,-32768(r5)
    stb     r4,-32768(r5)
    stb     r4,-32768(r5)
    stb     r4,-32768(r5)
    stb     r4,-32768(r5)
    bge-	.L_8038932C
.L_80389324:
    stb     r4,-32768(r5)
    bdnz+	.L_80389324
.L_8038932C:
    bl	PPCSync
.L_80389330:
    bl	PPCMfwpar
    clrlwi. r0,r3,31
    bne+	.L_80389330
    lis     r3,3073
    addi    r3,r3,-32768
    bl	PPCMtwpar
    lwz     r4,-21960(r13)
    li      r6,0
    lwz     r3,-22000(r13)
    lwz     r0,0(r4)
    clrlwi  r0,r0,2
    stw     r0,12(r3)
    lwz     r4,-21960(r13)
    lwz     r3,-22000(r13)
    lwz     r0,4(r4)
    clrlwi  r0,r0,2
    stw     r0,16(r3)
    lwz     r4,-21960(r13)
    lwz     r3,-22000(r13)
    lwz     r0,24(r4)
    rlwimi  r31,r0,0,6,26
    addi    r0,r31,0
    rlwimi  r0,r6,26,5,5
    stw     r0,20(r3)
    lbz     r0,-21948(r13)
    cmplwi  r0,0
    beq-	.L_80389404
    lwz     r5,-17720(r13)
    li      r4,1
    lwz     r0,16(r5)
    rlwimi  r0,r4,0,31,31
    stw     r0,16(r5)
    lwz     r0,16(r5)
    rlwimi  r0,r4,1,30,30
    stw     r0,16(r5)
    lwz     r0,16(r5)
    lwz     r3,-21996(r13)
    sth     r0,4(r3)
    lwz     r0,8(r5)
    rlwimi  r0,r4,2,29,29
    stw     r0,8(r5)
    lwz     r0,8(r5)
    rlwimi  r0,r6,3,28,28
    stw     r0,8(r5)
    lwz     r0,8(r5)
    lwz     r3,-21996(r13)
    sth     r0,2(r3)
    lwz     r0,8(r5)
    rlwimi  r0,r4,4,27,27
    stw     r0,8(r5)
    lwz     r0,8(r5)
    lwz     r3,-21996(r13)
    sth     r0,2(r3)
.L_80389404:
    bl	PPCSync
    mr      r3,r30
    bl	OSRestoreInterrupts
    lwz     r0,28(r1)
    lwz     r31,20(r1)
    lwz     r30,16(r1)
    addi    r1,r1,24
    mtlr    r0
    blr
.size GXRestoreWriteGatherPipe, . - GXRestoreWriteGatherPipe

#
# === GXFrameBuf.o (gx.a) ===
#

.global GXAdjustForOverscan
.balign 4
GXAdjustForOverscan:
/* 0x8038BAE8 | size=0x144 (324 bytes) */
    cmplw   r3,r4
    clrlwi  r0,r5,16
    clrlwi  r7,r6,16
    rlwinm  r5,r5,1,16,30
    rlwinm  r6,r6,1,16,30
    beq-	.L_8038BB78
    lwz     r9,0(r3)
    lwz     r8,4(r3)
    stw     r9,0(r4)
    stw     r8,4(r4)
    lwz     r9,8(r3)
    lwz     r8,12(r3)
    stw     r9,8(r4)
    stw     r8,12(r4)
    lwz     r9,16(r3)
    lwz     r8,20(r3)
    stw     r9,16(r4)
    stw     r8,20(r4)
    lwz     r9,24(r3)
    lwz     r8,28(r3)
    stw     r9,24(r4)
    stw     r8,28(r4)
    lwz     r9,32(r3)
    lwz     r8,36(r3)
    stw     r9,32(r4)
    stw     r8,36(r4)
    lwz     r9,40(r3)
    lwz     r8,44(r3)
    stw     r9,40(r4)
    stw     r8,44(r4)
    lwz     r9,48(r3)
    lwz     r8,52(r3)
    stw     r9,48(r4)
    stw     r8,52(r4)
    lwz     r8,56(r3)
    stw     r8,56(r4)
.L_8038BB78:
    lhz     r8,4(r3)
    lwz     r9,0(r3)
    subf    r8,r5,r8
    sth     r8,4(r4)
    clrlwi  r11,r9,30
    lhz     r10,6(r3)
    lhz     r8,8(r3)
    mullw   r9,r6,r10
    divwu   r8,r9,r8
    subf    r8,r8,r10
    sth     r8,6(r4)
    lwz     r8,20(r3)
    cmpwi   r8,0
    bne-	.L_8038BBD0
    cmplwi  r11,0
    bne-	.L_8038BBD0
    srawi   r9,r6,1
    lhz     r8,8(r3)
    addze   r9,r9
    subf    r8,r9,r8
    sth     r8,8(r4)
    b	.L_8038BBDC
.L_8038BBD0:
    lhz     r8,8(r3)
    subf    r8,r6,r8
    sth     r8,8(r4)
.L_8038BBDC:
    lhz     r8,14(r3)
    cmplwi  r11,1
    subf    r5,r5,r8
    sth     r5,14(r4)
    bne-	.L_8038BC04
    lhz     r5,16(r3)
    slwi    r6,r6,1
    subf    r5,r6,r5
    sth     r5,16(r4)
    b	.L_8038BC10
.L_8038BC04:
    lhz     r5,16(r3)
    subf    r5,r6,r5
    sth     r5,16(r4)
.L_8038BC10:
    lhz     r5,10(r3)
    add     r0,r5,r0
    sth     r0,10(r4)
    lhz     r0,12(r3)
    add     r0,r0,r7
    sth     r0,12(r4)
    blr
.size GXAdjustForOverscan, . - GXAdjustForOverscan

.global GXSetTexCopyDst
.balign 4
GXSetTexCopyDst:
/* 0x8038BD58 | size=0x130 (304 bytes) */
    mflr    r0
    cmpwi   r5,19
    stw     r0,4(r1)
    li      r0,0
    addi    r8,r3,0
    stwu    r1,-40(r1)
    stw     r31,36(r1)
    clrlwi  r31,r5,28
    stw     r30,32(r1)
    addi    r30,r6,0
    lwz     r7,-17720(r13)
    stb     r0,512(r7)
    addi    r7,r4,0
    bne-	.L_8038BD94
    li      r31,11
.L_8038BD94:
    cmpwi   r5,38
    beq-	.L_8038BDB4
    bge-	.L_8038BDCC
    cmpwi   r5,4
    bge-	.L_8038BDCC
    cmpwi   r5,0
    bge-	.L_8038BDB4
    b	.L_8038BDCC
.L_8038BDB4:
    lwz     r4,-17720(r13)
    li      r0,3
    lwz     r3,508(r4)
    rlwimi  r3,r0,15,15,16
    stw     r3,508(r4)
    b	.L_8038BDE0
.L_8038BDCC:
    lwz     r4,-17720(r13)
    li      r0,2
    lwz     r3,508(r4)
    rlwimi  r3,r0,15,15,16
    stw     r3,508(r4)
.L_8038BDE0:
    rlwinm  r3,r5,0,27,27
    lwz     r4,-17720(r13)
    addi    r0,r3,-16
    cntlzw  r0,r0
    rlwinm  r0,r0,27,24,31
    stb     r0,512(r4)
    addi    r3,r5,0
    addi    r5,r7,0
    lwz     r0,508(r4)
    rlwimi  r0,r31,0,28,28
    clrlwi  r31,r31,29
    stw     r0,508(r4)
    addi    r4,r8,0
    addi    r6,r1,28
    addi    r7,r1,24
    addi    r8,r1,20
    bl	__GetImageTileCount
    lwz     r7,-17720(r13)
    li      r0,0
    li      r3,77
    stw     r0,504(r7)
    lwz     r5,28(r1)
    lwz     r4,20(r1)
    lwz     r6,504(r7)
    mullw   r4,r5,r4
    rlwimi  r6,r4,0,22,31
    stw     r6,504(r7)
    lwz     r4,504(r7)
    rlwimi  r4,r3,24,0,7
    stw     r4,504(r7)
    lwz     r3,508(r7)
    rlwimi  r3,r30,9,22,22
    stw     r3,508(r7)
    lwz     r0,508(r7)
    rlwimi  r0,r31,4,25,27
    stw     r0,508(r7)
    lwz     r0,44(r1)
    lwz     r31,36(r1)
    lwz     r30,32(r1)
    addi    r1,r1,40
    mtlr    r0
    blr
.size GXSetTexCopyDst, . - GXSetTexCopyDst

.global GXGetYScaleFactor
.balign 4
GXGetYScaleFactor:
/* 0x8038BFEC | size=0x238 (568 bytes) */
    mflr    r0
    stw     r0,4(r1)
    lis     r0,17200
    stwu    r1,-120(r1)
    stfd    f31,112(r1)
    stfd    f30,104(r1)
    stfd    f29,96(r1)
    stfd    f28,88(r1)
    stmw    r25,60(r1)
    clrlwi  r28,r4,16
    clrlwi  r31,r3,16
    stw     r28,52(r1)
    mr      r27,r3
    mr      r25,r4
    stw     r31,44(r1)
    stw     r0,48(r1)
    stw     r0,40(r1)
    lfd     f3,-17672(r13)
    lfd     f2,48(r1)
    lfd     f1,40(r1)
    fsubs   f2,f2,f3
    lfs     f0,-17680(r13)
    fsubs   f1,f1,f3
    fdivs   f2,f2,f1
    fdivs   f1,f0,f2
    fmr     f28,f2
    bl	__cvt_fp2unsigned
    addi    r0,r31,-1
    clrlwi  r4,r3,23
    slwi    r30,r0,8
    divwu   r3,r30,r4
    cmplwi  r4,128
    addi    r3,r3,1
    ble-	.L_8038C0A0
    cmplwi  r4,256
    bge-	.L_8038C0A0
    b	.L_8038C084
.L_8038C080:
    srwi    r4,r4,1
.L_8038C084:
    clrlwi. r0,r4,31
    beq+	.L_8038C080
    divwu   r0,r31,r4
    mullw   r0,r0,r4
    subf.   r0,r0,r31
    bne-	.L_8038C0A0
    addi    r3,r3,1
.L_8038C0A0:
    cmplwi  r3,1024
    ble-	.L_8038C0AC
    li      r3,1024
.L_8038C0AC:
    lfd     f31,-17672(r13)
    mr      r0,r3
    lfs     f30,-17680(r13)
    clrlwi  r29,r25,16
    clrlwi  r26,r27,16
    lis     r25,17200
    b	.L_8038C14C
.L_8038C0C8:
    addi    r28,r28,-1
    stw     r26,52(r1)
    stw     r28,44(r1)
    stw     r25,40(r1)
    stw     r25,48(r1)
    lfd     f1,40(r1)
    lfd     f0,48(r1)
    fsubs   f1,f1,f31
    fsubs   f0,f0,f31
    fdivs   f0,f1,f0
    fdivs   f1,f30,f0
    fmr     f28,f0
    bl	__cvt_fp2unsigned
    clrlwi  r4,r3,23
    divwu   r3,r30,r4
    cmplwi  r4,128
    addi    r3,r3,1
    ble-	.L_8038C13C
    cmplwi  r4,256
    bge-	.L_8038C13C
    b	.L_8038C120
.L_8038C11C:
    srwi    r4,r4,1
.L_8038C120:
    clrlwi. r0,r4,31
    beq+	.L_8038C11C
    divwu   r0,r31,r4
    mullw   r0,r0,r4
    subf.   r0,r0,r31
    bne-	.L_8038C13C
    addi    r3,r3,1
.L_8038C13C:
    cmplwi  r3,1024
    ble-	.L_8038C148
    li      r3,1024
.L_8038C148:
    mr      r0,r3
.L_8038C14C:
    cmplw   r0,r29
    bgt+	.L_8038C0C8
    fmr     f29,f28
    lfd     f30,-17672(r13)
    lfs     f31,-17680(r13)
    clrlwi  r27,r27,16
    lis     r26,17200
    b	.L_8038C1F4
.L_8038C16C:
    addi    r28,r28,1
    stw     r27,52(r1)
    fmr     f29,f28
    stw     r28,44(r1)
    stw     r26,40(r1)
    stw     r26,48(r1)
    lfd     f1,40(r1)
    lfd     f0,48(r1)
    fsubs   f1,f1,f30
    fsubs   f0,f0,f30
    fdivs   f0,f1,f0
    fdivs   f1,f31,f0
    fmr     f28,f0
    bl	__cvt_fp2unsigned
    clrlwi  r4,r3,23
    divwu   r3,r30,r4
    cmplwi  r4,128
    addi    r3,r3,1
    ble-	.L_8038C1E4
    cmplwi  r4,256
    bge-	.L_8038C1E4
    b	.L_8038C1C8
.L_8038C1C4:
    srwi    r4,r4,1
.L_8038C1C8:
    clrlwi. r0,r4,31
    beq+	.L_8038C1C4
    divwu   r0,r31,r4
    mullw   r0,r0,r4
    subf.   r0,r0,r31
    bne-	.L_8038C1E4
    addi    r3,r3,1
.L_8038C1E4:
    cmplwi  r3,1024
    ble-	.L_8038C1F0
    li      r3,1024
.L_8038C1F0:
    mr      r0,r3
.L_8038C1F4:
    cmplw   r0,r29
    blt+	.L_8038C16C
    lmw     r25,60(r1)
    fmr     f1,f29
    lwz     r0,124(r1)
    lfd     f31,112(r1)
    lfd     f30,104(r1)
    lfd     f29,96(r1)
    lfd     f28,88(r1)
    addi    r1,r1,120
    mtlr    r0
    blr
.size GXGetYScaleFactor, . - GXGetYScaleFactor

.global GXSetCopyFilter
.balign 4
GXSetCopyFilter:
/* 0x8038C368 | size=0x208 (520 bytes) */
    stwu    r1,-72(r1)
    clrlwi. r0,r3,24
    stmw    r24,40(r1)
    beq-	.L_8038C46C
    lbz     r0,6(r4)
    li      r7,0
    lbz     r8,0(r4)
    li      r3,0
    rlwimi  r7,r0,0,28,31
    lbz     r9,12(r4)
    rlwimi  r3,r8,0,28,31
    li      r8,0
    lbz     r0,18(r4)
    rlwimi  r8,r9,0,28,31
    li      r9,0
    lbz     r10,1(r4)
    rlwimi  r9,r0,0,28,31
    lbz     r0,19(r4)
    lbz     r11,13(r4)
    rlwimi  r3,r10,4,24,27
    lbz     r27,2(r4)
    rlwimi  r9,r0,4,24,27
    lbz     r25,7(r4)
    lbz     r10,20(r4)
    rlwimi  r8,r11,4,24,27
    lbz     r12,14(r4)
    rlwimi  r3,r27,8,20,23
    lbz     r28,3(r4)
    rlwimi  r8,r12,8,20,23
    lbz     r29,4(r4)
    rlwimi  r3,r28,12,16,19
    lbz     r0,5(r4)
    rlwimi  r3,r29,16,12,15
    lbz     r24,8(r4)
    rlwimi  r7,r25,4,24,27
    lbz     r25,15(r4)
    rlwimi  r3,r0,20,8,11
    lbz     r30,9(r4)
    li      r0,1
    lbz     r31,10(r4)
    rlwimi  r9,r10,8,20,23
    lbz     r26,21(r4)
    rlwimi  r3,r0,24,0,7
    lbz     r12,11(r4)
    rlwimi  r7,r24,8,20,23
    lbz     r11,16(r4)
    rlwimi  r7,r30,12,16,19
    lbz     r10,17(r4)
    lbz     r27,22(r4)
    rlwimi  r7,r31,16,12,15
    rlwimi  r8,r25,12,16,19
    lbz     r4,23(r4)
    rlwimi  r8,r11,16,12,15
    rlwimi  r9,r26,12,16,19
    rlwimi  r9,r27,16,12,15
    li      r0,2
    rlwimi  r7,r12,20,8,11
    rlwimi  r7,r0,24,0,7
    li      r0,3
    rlwimi  r8,r10,20,8,11
    rlwimi  r8,r0,24,0,7
    li      r0,4
    rlwimi  r9,r4,20,8,11
    rlwimi  r9,r0,24,0,7
    b	.L_8038C48C
.L_8038C46C:
    lis     r3,358
    lis     r7,614
    lis     r8,870
    lis     r4,1126
    addi    r3,r3,26214
    addi    r7,r7,26214
    addi    r8,r8,26214
    addi    r9,r4,26214
.L_8038C48C:
    li      r10,97
    lis     r4,-13311
    stb     r10,-32768(r4)
    clrlwi. r0,r5,24
    li      r0,83
    stw     r3,-32768(r4)
    li      r3,0
    rlwimi  r3,r0,24,0,7
    stb     r10,-32768(r4)
    li      r0,84
    li      r5,0
    stw     r7,-32768(r4)
    rlwimi  r5,r0,24,0,7
    addi    r11,r3,0
    stb     r10,-32768(r4)
    addi    r0,r5,0
    stw     r8,-32768(r4)
    stb     r10,-32768(r4)
    stw     r9,-32768(r4)
    beq-	.L_8038C518
    lbz     r4,0(r6)
    lbz     r3,4(r6)
    rlwimi  r11,r4,0,26,31
    lbz     r4,1(r6)
    rlwimi  r0,r3,0,26,31
    lbz     r7,2(r6)
    rlwimi  r11,r4,6,20,25
    lbz     r4,5(r6)
    lbz     r5,3(r6)
    rlwimi  r11,r7,12,14,19
    lbz     r3,6(r6)
    rlwimi  r0,r4,6,20,25
    rlwimi  r11,r5,18,8,13
    rlwimi  r0,r3,12,14,19
    b	.L_8038C540
.L_8038C518:
    li      r4,0
    li      r3,21
    rlwimi  r11,r4,0,26,31
    rlwimi  r11,r4,6,20,25
    rlwimi  r0,r3,0,26,31
    rlwimi  r11,r3,12,14,19
    li      r3,22
    rlwimi  r0,r4,6,20,25
    rlwimi  r0,r4,12,14,19
    rlwimi  r11,r3,18,8,13
.L_8038C540:
    li      r6,97
    lwz     r3,-17720(r13)
    lis     r5,-13311
    stb     r6,-32768(r5)
    li      r4,0
    stw     r11,-32768(r5)
    stb     r6,-32768(r5)
    stw     r0,-32768(r5)
    sth     r4,2(r3)
    lmw     r24,40(r1)
    addi    r1,r1,72
    blr
.size GXSetCopyFilter, . - GXSetCopyFilter

.global GXCopyDisp
.balign 4
GXCopyDisp:
/* 0x8038C584 | size=0x168 (360 bytes) */
    clrlwi. r0,r4,24
    beq-	.L_8038C5CC
    lwz     r7,-17720(r13)
    li      r0,1
    li      r6,97
    lwz     r8,472(r7)
    lis     r5,-13311
    rlwimi  r8,r0,0,31,31
    li      r0,7
    stb     r6,-32768(r5)
    rlwimi  r8,r0,1,28,30
    stw     r8,-32768(r5)
    li      r0,0
    lwz     r7,464(r7)
    rlwimi  r7,r0,0,31,31
    rlwimi  r7,r0,1,30,30
    stb     r6,-32768(r5)
    stw     r7,-32768(r5)
.L_8038C5CC:
    clrlwi. r0,r4,24
    li      r10,0
    bne-	.L_8038C5EC
    lwz     r5,-17720(r13)
    lwz     r0,476(r5)
    clrlwi  r0,r0,29
    cmplwi  r0,3
    bne-	.L_8038C61C
.L_8038C5EC:
    lwz     r5,-17720(r13)
    lwz     r6,476(r5)
    rlwinm  r0,r6,26,31,31
    cmplwi  r0,1
    bne-	.L_8038C61C
    li      r0,97
    lis     r5,-13311
    stb     r0,-32768(r5)
    li      r0,0
    rlwimi  r6,r0,6,25,25
    stw     r6,-32768(r5)
    li      r10,1
.L_8038C61C:
    li      r8,97
    lwz     r6,-17720(r13)
    lis     r7,-13311
    stb     r8,-32768(r7)
    li      r9,0
    rlwimi  r9,r3,27,11,31
    lwz     r5,480(r6)
    li      r0,75
    rlwimi  r9,r0,24,0,7
    stw     r5,-32768(r7)
    clrlwi. r4,r4,24
    li      r3,1
    stb     r8,-32768(r7)
    li      r0,82
    lwz     r5,484(r6)
    stw     r5,-32768(r7)
    stb     r8,-32768(r7)
    lwz     r5,488(r6)
    stw     r5,-32768(r7)
    stb     r8,-32768(r7)
    stw     r9,-32768(r7)
    lwz     r5,492(r6)
    rlwimi  r5,r4,11,20,20
    stw     r5,492(r6)
    lwz     r4,492(r6)
    rlwimi  r4,r3,14,17,17
    stw     r4,492(r6)
    lwz     r3,492(r6)
    rlwimi  r3,r0,24,0,7
    stw     r3,492(r6)
    stb     r8,-32768(r7)
    lwz     r0,492(r6)
    stw     r0,-32768(r7)
    beq-	.L_8038C6BC
    stb     r8,-32768(r7)
    lwz     r0,472(r6)
    stw     r0,-32768(r7)
    stb     r8,-32768(r7)
    lwz     r0,464(r6)
    stw     r0,-32768(r7)
.L_8038C6BC:
    clrlwi. r0,r10,24
    beq-	.L_8038C6DC
    li      r0,97
    lwz     r3,-17720(r13)
    lis     r4,-13311
    stb     r0,-32768(r4)
    lwz     r0,476(r3)
    stw     r0,-32768(r4)
.L_8038C6DC:
    lwz     r3,-17720(r13)
    li      r0,0
    sth     r0,2(r3)
    blr
.size GXCopyDisp, . - GXCopyDisp

.global GXCopyTex
.balign 4
GXCopyTex:
/* 0x8038C6EC | size=0x18C (396 bytes) */
    clrlwi. r0,r4,24
    beq-	.L_8038C734
    lwz     r7,-17720(r13)
    li      r0,1
    li      r6,97
    lwz     r8,472(r7)
    lis     r5,-13311
    rlwimi  r8,r0,0,31,31
    li      r0,7
    stb     r6,-32768(r5)
    rlwimi  r8,r0,1,28,30
    stw     r8,-32768(r5)
    li      r0,0
    lwz     r7,464(r7)
    rlwimi  r7,r0,0,31,31
    rlwimi  r7,r0,1,30,30
    stb     r6,-32768(r5)
    stw     r7,-32768(r5)
.L_8038C734:
    lwz     r6,-17720(r13)
    li      r0,0
    lbz     r5,512(r6)
    lwz     r7,476(r6)
    cmplwi  r5,0
    beq-	.L_8038C764
    clrlwi  r5,r7,29
    cmplwi  r5,3
    beq-	.L_8038C764
    li      r0,3
    rlwimi  r7,r0,0,29,31
    li      r0,1
.L_8038C764:
    clrlwi. r5,r4,24
    bne-	.L_8038C778
    clrlwi  r5,r7,29
    cmplwi  r5,3
    bne-	.L_8038C790
.L_8038C778:
    rlwinm  r5,r7,26,31,31
    cmplwi  r5,1
    bne-	.L_8038C790
    li      r0,0
    rlwimi  r7,r0,6,25,25
    li      r0,1
.L_8038C790:
    clrlwi. r5,r0,24
    beq-	.L_8038C7A8
    li      r6,97
    lis     r5,-13311
    stb     r6,-32768(r5)
    stw     r7,-32768(r5)
.L_8038C7A8:
    li      r9,97
    lwz     r7,-17720(r13)
    lis     r8,-13311
    stb     r9,-32768(r8)
    clrlwi. r5,r4,24
    li      r10,0
    lwz     r4,496(r7)
    rlwimi  r10,r3,27,11,31
    li      r3,75
    stw     r4,-32768(r8)
    rlwimi  r10,r3,24,0,7
    li      r4,0
    stb     r9,-32768(r8)
    li      r3,82
    lwz     r6,500(r7)
    stw     r6,-32768(r8)
    stb     r9,-32768(r8)
    lwz     r6,504(r7)
    stw     r6,-32768(r8)
    stb     r9,-32768(r8)
    stw     r10,-32768(r8)
    lwz     r6,508(r7)
    rlwimi  r6,r5,11,20,20
    stw     r6,508(r7)
    lwz     r5,508(r7)
    rlwimi  r5,r4,14,17,17
    stw     r5,508(r7)
    lwz     r4,508(r7)
    rlwimi  r4,r3,24,0,7
    stw     r4,508(r7)
    stb     r9,-32768(r8)
    lwz     r3,508(r7)
    stw     r3,-32768(r8)
    beq-	.L_8038C848
    stb     r9,-32768(r8)
    lwz     r3,472(r7)
    stw     r3,-32768(r8)
    stb     r9,-32768(r8)
    lwz     r3,464(r7)
    stw     r3,-32768(r8)
.L_8038C848:
    clrlwi. r0,r0,24
    beq-	.L_8038C868
    li      r0,97
    lwz     r3,-17720(r13)
    lis     r4,-13311
    stb     r0,-32768(r4)
    lwz     r0,476(r3)
    stw     r0,-32768(r4)
.L_8038C868:
    lwz     r3,-17720(r13)
    li      r0,0
    sth     r0,2(r3)
    blr
.size GXCopyTex, . - GXCopyTex

#
# === GXInit.o (gx.a) ===
#

.global __GXShutdown
.balign 4
__GXShutdown:
/* 0x80387200 | size=0x190 (400 bytes) */
    mflr    r0
    stw     r0,4(r1)
    stwu    r1,-32(r1)
    stw     r31,28(r1)
    cmpwi   r3,0
    bne-	.L_80387310
    lwz     r0,-21968(r13)
    cmplwi  r0,0
    bne-	.L_80387278
    lwz     r3,-21988(r13)
    addi    r6,r3,78
    lhz     r4,0(r6)
    addi    r5,r3,80
    b	.L_80387238
.L_80387238:
    b	.L_8038723C
.L_8038723C:
    mr      r0,r4
    lhz     r4,0(r6)
    lhz     r3,0(r5)
    cmplw   r4,r0
    bne+	.L_8038723C
    slwi    r0,r4,16
    or      r0,r0,r3
    stw     r0,-21984(r13)
    bl	OSGetTime
    stw     r4,-21972(r13)
    li      r0,1
    stw     r3,-21976(r13)
    li      r3,0
    stw     r0,-21968(r13)
    b	.L_8038737C
.L_80387278:
    bl	OSGetTime
    lwz     r5,-21988(r13)
    addi    r6,r5,78
    lhz     r7,0(r6)
    addi    r5,r5,80
    b	.L_80387290
.L_80387290:
    b	.L_80387294
.L_80387294:
    mr      r0,r7
    lhz     r7,0(r6)
    lhz     r10,0(r5)
    cmplw   r7,r0
    bne+	.L_80387294
    lwz     r6,-21972(r13)
    li      r0,0
    lwz     r5,-21976(r13)
    slwi    r9,r7,16
    subfc   r8,r6,r4
    subfe   r5,r5,r3
    li      r7,10
    xoris   r6,r5,32768
    xoris   r5,r0,32768
    subfc   r0,r7,r8
    subfe   r5,r5,r6
    subfe   r5,r6,r6
    neg     r5,r5
    cmpwi   r5,0
    or      r5,r9,r10
    beq-	.L_803872F0
    li      r3,0
    b	.L_8038737C
.L_803872F0:
    lwz     r0,-21984(r13)
    cmplw   r5,r0
    beq-	.L_80387378
    stw     r4,-21972(r13)
    stw     r3,-21976(r13)
    li      r3,0
    stw     r5,-21984(r13)
    b	.L_8038737C
.L_80387310:
    li      r3,0
    bl	GXSetBreakPtCallback
    li      r3,0
    bl	GXSetDrawSyncCallback
    li      r3,0
    bl	GXSetDrawDoneCallback
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
    bl	PPCSync
    lwz     r3,-21996(r13)
    li      r4,3
    li      r0,1
    sth     r31,2(r3)
    lwz     r3,-21996(r13)
    sth     r4,4(r3)
    lwz     r3,-17720(r13)
    stb     r0,1450(r3)
    bl	__GXAbort
.L_80387378:
    li      r3,1
.L_8038737C:
    lwz     r0,36(r1)
    lwz     r31,28(r1)
    addi    r1,r1,32
    mtlr    r0
    blr
.size __GXShutdown, . - __GXShutdown

.global __GXInitRevisionBits
.balign 4
__GXInitRevisionBits:
/* 0x80387390 | size=0x1A4 (420 bytes) */
    li      r11,0
    slwi    r10,r11,2
    b	.L_8038739C
.L_8038739C:
    li      r0,2
    mtctr   r0
    li      r7,1
    li      r5,8
    lis     r4,-13311
    b	.L_803873B4
.L_803873B4:
    b	.L_803873B8
.L_803873B8:
    lwz     r9,-17720(r13)
    addi    r8,r10,28
    addi    r6,r10,60
    lwzx    r0,r9,r8
    rlwimi  r0,r7,30,1,1
    ori     r3,r11,128
    stwx    r0,r9,r8
    addi    r10,r10,4
    addi    r8,r10,28
    lwzx    r0,r9,r6
    rlwimi  r0,r7,31,0,0
    addi    r11,r11,1
    stwx    r0,r9,r6
    stb     r5,-32768(r4)
    stb     r3,-32768(r4)
    ori     r3,r11,128
    addi    r11,r11,1
    lwzx    r0,r9,r6
    addi    r6,r10,60
    addi    r10,r10,4
    stw     r0,-32768(r4)
    lwzx    r0,r9,r8
    rlwimi  r0,r7,30,1,1
    stwx    r0,r9,r8
    addi    r8,r10,28
    lwzx    r0,r9,r6
    rlwimi  r0,r7,31,0,0
    stwx    r0,r9,r6
    stb     r5,-32768(r4)
    stb     r3,-32768(r4)
    ori     r3,r11,128
    addi    r11,r11,1
    lwzx    r0,r9,r6
    addi    r6,r10,60
    addi    r10,r10,4
    stw     r0,-32768(r4)
    lwzx    r0,r9,r8
    rlwimi  r0,r7,30,1,1
    stwx    r0,r9,r8
    addi    r8,r10,28
    lwzx    r0,r9,r6
    rlwimi  r0,r7,31,0,0
    stwx    r0,r9,r6
    stb     r5,-32768(r4)
    stb     r3,-32768(r4)
    ori     r3,r11,128
    addi    r11,r11,1
    lwzx    r0,r9,r6
    addi    r6,r10,60
    addi    r10,r10,4
    stw     r0,-32768(r4)
    lwzx    r0,r9,r8
    rlwimi  r0,r7,30,1,1
    stwx    r0,r9,r8
    lwzx    r0,r9,r6
    rlwimi  r0,r7,31,0,0
    stwx    r0,r9,r6
    stb     r5,-32768(r4)
    stb     r3,-32768(r4)
    lwzx    r0,r9,r6
    stw     r0,-32768(r4)
    bdnz+	.L_803873B8
    li      r3,1
    li      r0,0
    rlwimi  r0,r3,0,31,31
    mr      r7,r0
    li      r0,0
    rlwimi  r0,r3,0,31,31
    mr      r8,r0
    rlwimi  r7,r3,1,30,30
    rlwimi  r7,r3,2,29,29
    rlwimi  r7,r3,3,28,28
    rlwimi  r7,r3,4,27,27
    li      r9,0
    li      r6,16
    lis     r5,-13311
    rlwimi  r8,r3,1,30,30
    stb     r6,-32768(r5)
    li      r0,4096
    stw     r0,-32768(r5)
    rlwimi  r7,r3,5,26,26
    rlwimi  r8,r3,2,29,29
    stw     r7,-32768(r5)
    li      r4,4114
    rlwimi  r9,r3,0,31,31
    stb     r6,-32768(r5)
    rlwimi  r8,r3,3,28,28
    li      r3,88
    stw     r4,-32768(r5)
    li      r0,97
    rlwimi  r8,r3,24,0,7
    stw     r9,-32768(r5)
    stb     r0,-32768(r5)
    stw     r8,-32768(r5)
    blr
.size __GXInitRevisionBits, . - __GXInitRevisionBits

#
# === GXLight.o (gx.a) ===
#

.global GXInitLightSpot
.balign 4
GXInitLightSpot:
/* 0x8038C958 | size=0x190 (400 bytes) */
    mflr    r0
    stw     r0,4(r1)
    stwu    r1,-32(r1)
    stw     r31,28(r1)
    addi    r31,r4,0
    stw     r30,24(r1)
    addi    r30,r3,0
    lfs     f0,-17632(r13)
    fcmpo   cr0,f1,f0
    cror    eq,lt,eq
    beq-	.L_8038C990
    lfs     f0,-17628(r13)
    fcmpo   cr0,f1,f0
    ble-	.L_8038C994
.L_8038C990:
    li      r31,0
.L_8038C994:
    lfs     f2,-17624(r13)
    lfs     f0,-17620(r13)
    fmuls   f1,f2,f1
    fdivs   f1,f1,f0
    bl	cosf
    cmplwi  r31,6
    bgt-	.L_8038CAB8
    lis     r3,-32698
    addi    r3,r3,-23824
    slwi    r0,r31,2
    lwzx    r0,r3,r0
    mtctr   r0
    bctr
    lfs     f0,-17616(r13)
    lfs     f4,-17612(r13)
    fmuls   f3,f0,f1
    lfs     f6,-17632(r13)
    b	.L_8038CAC4
    lfs     f2,-17608(r13)
    fneg    f0,f1
    lfs     f6,-17632(r13)
    fsubs   f1,f2,f1
    fdivs   f1,f2,f1
    fmr     f4,f1
    fmuls   f3,f0,f1
    b	.L_8038CAC4
    lfs     f2,-17608(r13)
    fneg    f0,f1
    lfs     f3,-17632(r13)
    fsubs   f1,f2,f1
    fdivs   f1,f2,f1
    fmr     f6,f1
    fmuls   f4,f0,f1
    b	.L_8038CAC4
    lfs     f4,-17608(r13)
    lfs     f2,-17604(r13)
    fsubs   f3,f4,f1
    fsubs   f0,f1,f2
    fmuls   f3,f3,f3
    fmuls   f0,f1,f0
    fdivs   f1,f4,f3
    fmuls   f3,f1,f0
    fmuls   f4,f2,f1
    fneg    f6,f1
    b	.L_8038CAC4
    lfs     f5,-17608(r13)
    lfs     f3,-17600(r13)
    fsubs   f4,f5,f1
    lfs     f2,-17596(r13)
    fadds   f0,f5,f1
    fmuls   f4,f4,f4
    fmuls   f0,f2,f0
    fdivs   f4,f5,f4
    fmuls   f2,f3,f4
    fmuls   f4,f0,f4
    fmr     f6,f2
    fmuls   f3,f2,f1
    b	.L_8038CAC4
    lfs     f5,-17608(r13)
    lfs     f0,-17604(r13)
    fsubs   f4,f5,f1
    lfs     f2,-17596(r13)
    fmuls   f3,f0,f1
    lfs     f0,-17592(r13)
    fmuls   f2,f2,f1
    fmuls   f4,f4,f4
    fmuls   f1,f3,f1
    fdivs   f3,f5,f4
    fmuls   f1,f3,f1
    fmuls   f4,f2,f3
    fmuls   f6,f0,f3
    fsubs   f3,f5,f1
    b	.L_8038CAC4
.L_8038CAB8:
    lfs     f4,-17632(r13)
    lfs     f3,-17608(r13)
    fmr     f6,f4
.L_8038CAC4:
    stfs    f3,16(r30)
    stfs    f4,20(r30)
    stfs    f6,24(r30)
    lwz     r0,36(r1)
    lwz     r31,28(r1)
    lwz     r30,24(r1)
    addi    r1,r1,32
    mtlr    r0
    blr
.size GXInitLightSpot, . - GXInitLightSpot

#
# === GXMisc.o (gx.a) ===
#

.global __GXAbort
.balign 4
__GXAbort:
/* 0x8038ABD0 | size=0x16C (364 bytes) */
    mflr    r0
    stw     r0,4(r1)
    stwu    r1,-40(r1)
    stmw    r27,20(r1)
    lwz     r3,-17720(r13)
    lbz     r0,1450(r3)
    cmplwi  r0,0
    beq-	.L_8038AC9C
    bl	GXGetGPFifo
    cmplwi  r3,0
    beq-	.L_8038AC9C
    lwz     r3,-21988(r13)
    addi    r6,r3,78
    lhz     r4,78(r3)
    addi    r5,r3,80
.L_8038AC0C:
    mr      r0,r4
    lhz     r4,0(r6)
    lhz     r3,0(r5)
    cmplw   r4,r0
    bne+	.L_8038AC0C
    slwi    r0,r4,16
    or      r27,r0,r3
.L_8038AC28:
    bl	OSGetTime
    li      r0,0
    addi    r31,r4,0
    addi    r30,r3,0
    xoris   r28,r0,32768
    li      r29,8
.L_8038AC40:
    bl	OSGetTime
    subfc   r4,r31,r4
    subfe   r0,r30,r3
    xoris   r3,r0,32768
    subfc   r0,r4,r29
    subfe   r3,r3,r28
    subfe   r3,r28,r28
    neg.    r3,r3
    beq+	.L_8038AC40
    lwz     r3,-21988(r13)
    addi    r6,r3,78
    lhz     r4,78(r3)
    addi    r5,r3,80
.L_8038AC74:
    mr      r0,r4
    lhz     r4,0(r6)
    lhz     r3,0(r5)
    cmplw   r4,r0
    bne+	.L_8038AC74
    slwi    r0,r4,16
    or      r0,r0,r3
    cmplw   r0,r27
    mr      r27,r0
    bne+	.L_8038AC28
.L_8038AC9C:
    lis     r3,-13312
    li      r0,1
    addi    r27,r3,12288
    stwu    r0,24(r27)
    bl	OSGetTime
    li      r0,0
    addi    r31,r4,0
    addi    r30,r3,0
    xoris   r28,r0,32768
    li      r29,50
.L_8038ACC4:
    bl	OSGetTime
    subfc   r4,r31,r4
    subfe   r0,r30,r3
    xoris   r3,r0,32768
    subfc   r0,r4,r29
    subfe   r3,r3,r28
    subfe   r3,r28,r28
    neg.    r3,r3
    beq+	.L_8038ACC4
    li      r30,0
    stw     r30,0(r27)
    bl	OSGetTime
    addi    r28,r4,0
    addi    r29,r3,0
    xoris   r31,r30,32768
    li      r30,5
.L_8038AD04:
    bl	OSGetTime
    subfc   r4,r28,r4
    subfe   r0,r29,r3
    xoris   r3,r0,32768
    subfc   r0,r4,r30
    subfe   r3,r3,r31
    subfe   r3,r31,r31
    neg.    r3,r3
    beq+	.L_8038AD04
    lmw     r27,20(r1)
    lwz     r0,44(r1)
    addi    r1,r1,40
    mtlr    r0
    blr
.size __GXAbort, . - __GXAbort

.global GXAbortFrame
.balign 4
GXAbortFrame:
/* 0x8038AD3C | size=0x1C8 (456 bytes) */
    mflr    r0
    stw     r0,4(r1)
    stwu    r1,-40(r1)
    stmw    r27,20(r1)
    lwz     r3,-17720(r13)
    lbz     r0,1450(r3)
    cmplwi  r0,0
    beq-	.L_8038AE08
    bl	GXGetGPFifo
    cmplwi  r3,0
    beq-	.L_8038AE08
    lwz     r3,-21988(r13)
    addi    r6,r3,78
    lhz     r4,78(r3)
    addi    r5,r3,80
.L_8038AD78:
    mr      r0,r4
    lhz     r4,0(r6)
    lhz     r3,0(r5)
    cmplw   r4,r0
    bne+	.L_8038AD78
    slwi    r0,r4,16
    or      r27,r0,r3
.L_8038AD94:
    bl	OSGetTime
    li      r0,0
    addi    r31,r4,0
    addi    r30,r3,0
    xoris   r28,r0,32768
    li      r29,8
.L_8038ADAC:
    bl	OSGetTime
    subfc   r4,r31,r4
    subfe   r0,r30,r3
    xoris   r3,r0,32768
    subfc   r0,r4,r29
    subfe   r3,r3,r28
    subfe   r3,r28,r28
    neg.    r3,r3
    beq+	.L_8038ADAC
    lwz     r3,-21988(r13)
    addi    r6,r3,78
    lhz     r4,78(r3)
    addi    r5,r3,80
.L_8038ADE0:
    mr      r0,r4
    lhz     r4,0(r6)
    lhz     r3,0(r5)
    cmplw   r4,r0
    bne+	.L_8038ADE0
    slwi    r0,r4,16
    or      r0,r0,r3
    cmplw   r0,r27
    mr      r27,r0
    bne+	.L_8038AD94
.L_8038AE08:
    lis     r3,-13312
    li      r0,1
    addi    r27,r3,12288
    stwu    r0,24(r27)
    bl	OSGetTime
    li      r0,0
    addi    r31,r4,0
    addi    r30,r3,0
    xoris   r28,r0,32768
    li      r29,50
.L_8038AE30:
    bl	OSGetTime
    subfc   r4,r31,r4
    subfe   r0,r30,r3
    xoris   r3,r0,32768
    subfc   r0,r4,r29
    subfe   r3,r3,r28
    subfe   r3,r28,r28
    neg.    r3,r3
    beq+	.L_8038AE30
    li      r30,0
    stw     r30,0(r27)
    bl	OSGetTime
    addi    r28,r4,0
    addi    r29,r3,0
    xoris   r31,r30,32768
    li      r30,5
.L_8038AE70:
    bl	OSGetTime
    subfc   r4,r28,r4
    subfe   r0,r29,r3
    xoris   r3,r0,32768
    subfc   r0,r4,r30
    subfe   r3,r3,r31
    subfe   r3,r31,r31
    neg.    r3,r3
    beq+	.L_8038AE70
    bl	GXGetGPFifo
    cmplwi  r3,0
    beq-	.L_8038AEF0
    bl	__GXCleanGPFifo
    bl	__GXInitRevisionBits
    lwz     r3,-17720(r13)
    li      r0,0
    stw     r0,1452(r3)
    lwz     r0,1452(r3)
    cmplwi  r0,0
    beq-	.L_8038AEC4
    bl	__GXSetDirtyState
.L_8038AEC4:
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
    bl	PPCSync
.L_8038AEF0:
    lmw     r27,20(r1)
    lwz     r0,44(r1)
    addi    r1,r1,40
    mtlr    r0
    blr
.size GXAbortFrame, . - GXAbortFrame

.global GXCompressZ16
.balign 4
GXCompressZ16:
/* 0x8038B520 | size=0x134 (308 bytes) */
    mflr    r0
    cmpwi   r4,2
    stw     r0,4(r1)
    slwi    r0,r3,8
    not     r0,r0
    stwu    r1,-32(r1)
    cntlzw  r0,r0
    stw     r31,28(r1)
    beq-	.L_8038B5A8
    bge-	.L_8038B558
    cmpwi   r4,0
    beq-	.L_8038B564
    bge-	.L_8038B56C
    b	.L_8038B620
.L_8038B558:
    cmpwi   r4,4
    bge-	.L_8038B620
    b	.L_8038B5E4
.L_8038B564:
    rlwinm  r31,r3,24,16,31
    b	.L_8038B63C
.L_8038B56C:
    cmpwi   r0,3
    ble-	.L_8038B57C
    li      r4,3
    b	.L_8038B580
.L_8038B57C:
    mr      r4,r0
.L_8038B580:
    cmpwi   r4,3
    bne-	.L_8038B590
    li      r0,7
    b	.L_8038B594
.L_8038B590:
    subfic  r0,r4,9
.L_8038B594:
    srw     r0,r3,r0
    clrlwi  r0,r0,18
    mr      r31,r0
    rlwimi  r31,r4,14,0,17
    b	.L_8038B63C
.L_8038B5A8:
    cmpwi   r0,7
    ble-	.L_8038B5B8
    li      r4,7
    b	.L_8038B5BC
.L_8038B5B8:
    mr      r4,r0
.L_8038B5BC:
    cmpwi   r4,7
    bne-	.L_8038B5CC
    li      r0,4
    b	.L_8038B5D0
.L_8038B5CC:
    subfic  r0,r4,10
.L_8038B5D0:
    srw     r0,r3,r0
    clrlwi  r0,r0,19
    mr      r31,r0
    rlwimi  r31,r4,13,0,18
    b	.L_8038B63C
.L_8038B5E4:
    cmpwi   r0,12
    ble-	.L_8038B5F4
    li      r4,12
    b	.L_8038B5F8
.L_8038B5F4:
    mr      r4,r0
.L_8038B5F8:
    cmpwi   r4,12
    bne-	.L_8038B608
    li      r0,0
    b	.L_8038B60C
.L_8038B608:
    subfic  r0,r4,11
.L_8038B60C:
    srw     r0,r3,r0
    clrlwi  r0,r0,20
    mr      r31,r0
    rlwimi  r31,r4,12,0,19
    b	.L_8038B63C
.L_8038B620:
    lis     r3,-32698
    crclr   4*cr1+eq
    lis     r4,-32698
    addi    r5,r4,-25820
    addi    r3,r3,-25832
    li      r4,1004
    bl	OSPanic
.L_8038B63C:
    mr      r3,r31
    lwz     r0,36(r1)
    lwz     r31,28(r1)
    addi    r1,r1,32
    mtlr    r0
    blr
.size GXCompressZ16, . - GXCompressZ16

.global GXDecompressZ16
.balign 4
GXDecompressZ16:
/* 0x8038B654 | size=0x11C (284 bytes) */
    mflr    r0
    cmpwi   r4,2
    stw     r0,4(r1)
    stwu    r1,-32(r1)
    stw     r31,28(r1)
    beq-	.L_8038B6CC
    bge-	.L_8038B680
    cmpwi   r4,0
    beq-	.L_8038B68C
    bge-	.L_8038B694
    b	.L_8038B73C
.L_8038B680:
    cmpwi   r4,4
    bge-	.L_8038B73C
    b	.L_8038B704
.L_8038B68C:
    rlwinm  r31,r3,8,8,23
    b	.L_8038B758
.L_8038B694:
    rlwinm  r4,r3,18,30,31
    cmpwi   r4,3
    bne-	.L_8038B6A8
    li      r5,7
    b	.L_8038B6AC
.L_8038B6A8:
    subfic  r5,r4,9
.L_8038B6AC:
    clrlwi  r0,r3,18
    subfic  r3,r4,24
    li      r4,-1
    slw     r3,r4,r3
    slw     r0,r0,r5
    or      r0,r3,r0
    clrlwi  r31,r0,8
    b	.L_8038B758
.L_8038B6CC:
    rlwinm  r4,r3,19,29,31
    cmpwi   r4,7
    bne-	.L_8038B6E0
    li      r5,4
    b	.L_8038B6E4
.L_8038B6E0:
    subfic  r5,r4,10
.L_8038B6E4:
    clrlwi  r0,r3,19
    subfic  r3,r4,24
    li      r4,-1
    slw     r3,r4,r3
    slw     r0,r0,r5
    or      r0,r3,r0
    clrlwi  r31,r0,8
    b	.L_8038B758
.L_8038B704:
    rlwinm  r4,r3,20,28,31
    cmpwi   r4,12
    bne-	.L_8038B718
    li      r5,0
    b	.L_8038B71C
.L_8038B718:
    subfic  r5,r4,11
.L_8038B71C:
    clrlwi  r0,r3,20
    subfic  r3,r4,24
    li      r4,-1
    slw     r3,r4,r3
    slw     r0,r0,r5
    or      r0,r3,r0
    clrlwi  r31,r0,8
    b	.L_8038B758
.L_8038B73C:
    lis     r3,-32698
    crclr   4*cr1+eq
    lis     r4,-32698
    addi    r5,r4,-25784
    addi    r3,r3,-25832
    li      r4,1054
    bl	OSPanic
.L_8038B758:
    mr      r3,r31
    lwz     r0,36(r1)
    lwz     r31,28(r1)
    addi    r1,r1,32
    mtlr    r0
    blr
.size GXDecompressZ16, . - GXDecompressZ16

#
# === GXPerf.o (gx.a) ===
#

.global GXReadGPMetric
.balign 4
GXReadGPMetric:
/* 0x80391878 | size=0x1A8 (424 bytes) */
    lwz     r10,-21996(r13)
    addi    r8,r10,66
    lhz     r6,66(r10)
    addi    r7,r10,64
.L_80391888:
    mr      r0,r6
    lhz     r5,0(r7)
    lhz     r6,0(r8)
    cmplw   r6,r0
    bne+	.L_80391888
    slwi    r0,r6,16
    or      r6,r0,r5
    addi    r9,r10,70
    lhz     r7,70(r10)
    addi    r8,r10,68
.L_803918B0:
    mr      r0,r7
    lhz     r5,0(r8)
    lhz     r7,0(r9)
    cmplw   r7,r0
    bne+	.L_803918B0
    slwi    r0,r7,16
    or      r7,r0,r5
    addi    r11,r10,74
    lhz     r8,74(r10)
    addi    r9,r10,72
.L_803918D8:
    mr      r0,r8
    lhz     r5,0(r9)
    lhz     r8,0(r11)
    cmplw   r8,r0
    bne+	.L_803918D8
    slwi    r0,r8,16
    or      r8,r0,r5
    addi    r11,r10,78
    lhz     r9,78(r10)
    addi    r10,r10,76
.L_80391900:
    mr      r0,r9
    lhz     r5,0(r10)
    lhz     r9,0(r11)
    cmplw   r9,r0
    bne+	.L_80391900
    slwi    r0,r9,16
    or      r9,r0,r5
    lwz     r5,-17720(r13)
    lwz     r0,1436(r5)
    cmpwi   r0,10
    beq-	.L_8039194C
    bge-	.L_8039193C
    cmpwi   r0,0
    bge-	.L_8039195C
    b	.L_80391970
.L_8039193C:
    cmpwi   r0,35
    beq-	.L_80391964
    bge-	.L_80391970
    b	.L_8039195C
.L_8039194C:
    mulli   r0,r7,1000
    divwu   r0,r0,r6
    stw     r0,0(r3)
    b	.L_80391978
.L_8039195C:
    stw     r6,0(r3)
    b	.L_80391978
.L_80391964:
    li      r0,0
    stw     r0,0(r3)
    b	.L_80391978
.L_80391970:
    li      r0,0
    stw     r0,0(r3)
.L_80391978:
    lwz     r3,-17720(r13)
    lwz     r0,1440(r3)
    cmplwi  r0,22
    bgt-	.L_80391A14
    lis     r3,-32698
    addi    r3,r3,-22612
    slwi    r0,r0,2
    lwzx    r0,r3,r0
    mtctr   r0
    bctr
    slwi    r0,r9,2
    stw     r0,0(r4)
    blr
    slwi    r0,r9,1
    add     r0,r8,r0
    stw     r0,0(r4)
    blr
    mulli   r3,r8,3
    slwi    r0,r9,2
    add     r0,r3,r0
    stw     r0,0(r4)
    blr
    mulli   r3,r8,5
    mulli   r0,r9,6
    add     r0,r3,r0
    stw     r0,0(r4)
    blr
    mulli   r3,r8,7
    slwi    r0,r9,3
    add     r0,r3,r0
    stw     r0,0(r4)
    blr
    stw     r9,0(r4)
    blr
    stw     r8,0(r4)
    blr
    li      r0,0
    stw     r0,0(r4)
    blr
.L_80391A14:
    li      r0,0
    stw     r0,0(r4)
    blr
.size GXReadGPMetric, . - GXReadGPMetric

.global GXReadMemMetric
.balign 4
GXReadMemMetric:
/* 0x80391A88 | size=0x214 (532 bytes) */
    stwu    r1,-96(r1)
    stw     r31,92(r1)
    stw     r30,88(r1)
    stw     r29,84(r1)
    stw     r28,80(r1)
    lwz     r12,104(r1)
    lwz     r11,108(r1)
    lwz     r29,-21988(r13)
    addi    r28,r29,50
    lhz     r30,50(r29)
    addi    r29,r29,52
.L_80391AB4:
    mr      r0,r30
    lhz     r31,0(r29)
    lhz     r30,0(r28)
    cmplw   r30,r0
    bne+	.L_80391AB4
    slwi    r0,r30,16
    or      r0,r0,r31
    stw     r0,0(r3)
    lwz     r3,-21988(r13)
    addi    r28,r3,54
    lhz     r30,54(r3)
    addi    r29,r3,56
.L_80391AE4:
    mr      r0,r30
    lhz     r3,0(r29)
    lhz     r30,0(r28)
    cmplw   r30,r0
    bne+	.L_80391AE4
    slwi    r0,r30,16
    or      r0,r0,r3
    stw     r0,0(r4)
    lwz     r3,-21988(r13)
    addi    r28,r3,58
    lhz     r4,58(r3)
    addi    r29,r3,60
.L_80391B14:
    mr      r0,r4
    lhz     r3,0(r29)
    lhz     r4,0(r28)
    cmplw   r4,r0
    bne+	.L_80391B14
    slwi    r0,r4,16
    or      r0,r0,r3
    stw     r0,0(r5)
    lwz     r3,-21988(r13)
    addi    r28,r3,62
    lhz     r4,62(r3)
    addi    r5,r3,64
.L_80391B44:
    mr      r0,r4
    lhz     r3,0(r5)
    lhz     r4,0(r28)
    cmplw   r4,r0
    bne+	.L_80391B44
    slwi    r0,r4,16
    or      r0,r0,r3
    stw     r0,0(r6)
    lwz     r3,-21988(r13)
    addi    r6,r3,66
    lhz     r4,66(r3)
    addi    r5,r3,68
.L_80391B74:
    mr      r0,r4
    lhz     r3,0(r5)
    lhz     r4,0(r6)
    cmplw   r4,r0
    bne+	.L_80391B74
    slwi    r0,r4,16
    or      r0,r0,r3
    stw     r0,0(r7)
    lwz     r3,-21988(r13)
    addi    r6,r3,70
    lhz     r4,70(r3)
    addi    r5,r3,72
.L_80391BA4:
    mr      r0,r4
    lhz     r3,0(r5)
    lhz     r4,0(r6)
    cmplw   r4,r0
    bne+	.L_80391BA4
    slwi    r0,r4,16
    or      r0,r0,r3
    stw     r0,0(r8)
    lwz     r3,-21988(r13)
    addi    r6,r3,74
    lhz     r4,74(r3)
    addi    r5,r3,76
.L_80391BD4:
    mr      r0,r4
    lhz     r3,0(r5)
    lhz     r4,0(r6)
    cmplw   r4,r0
    bne+	.L_80391BD4
    slwi    r0,r4,16
    or      r0,r0,r3
    stw     r0,0(r9)
    lwz     r3,-21988(r13)
    addi    r6,r3,78
    lhz     r4,78(r3)
    addi    r5,r3,80
.L_80391C04:
    mr      r0,r4
    lhz     r3,0(r5)
    lhz     r4,0(r6)
    cmplw   r4,r0
    bne+	.L_80391C04
    slwi    r0,r4,16
    or      r0,r0,r3
    stw     r0,0(r10)
    lwz     r3,-21988(r13)
    addi    r6,r3,82
    lhz     r4,82(r3)
    addi    r5,r3,84
.L_80391C34:
    mr      r0,r4
    lhz     r3,0(r5)
    lhz     r4,0(r6)
    cmplw   r4,r0
    bne+	.L_80391C34
    slwi    r0,r4,16
    or      r0,r0,r3
    stw     r0,0(r12)
    lwz     r3,-21988(r13)
    addi    r6,r3,86
    lhz     r4,86(r3)
    addi    r5,r3,88
.L_80391C64:
    mr      r0,r4
    lhz     r3,0(r5)
    lhz     r4,0(r6)
    cmplw   r4,r0
    bne+	.L_80391C64
    slwi    r0,r4,16
    or      r0,r0,r3
    stw     r0,0(r11)
    lwz     r31,92(r1)
    lwz     r30,88(r1)
    lwz     r29,84(r1)
    lwz     r28,80(r1)
    addi    r1,r1,96
    blr
.size GXReadMemMetric, . - GXReadMemMetric

.global GXReadPixMetric
.balign 4
GXReadPixMetric:
/* 0x80391D44 | size=0x138 (312 bytes) */
    lwz     r9,-21992(r13)
    addi    r12,r9,26
    lhz     r10,26(r9)
    addi    r11,r9,24
.L_80391D54:
    mr      r0,r10
    lhz     r9,0(r11)
    lhz     r10,0(r12)
    cmplw   r10,r0
    bne+	.L_80391D54
    slwi    r0,r10,16
    or      r0,r0,r9
    slwi    r0,r0,2
    stw     r0,0(r3)
    lwz     r3,-21992(r13)
    addi    r11,r3,30
    lhz     r9,30(r3)
    addi    r10,r3,28
.L_80391D88:
    mr      r0,r9
    lhz     r3,0(r10)
    lhz     r9,0(r11)
    cmplw   r9,r0
    bne+	.L_80391D88
    slwi    r0,r9,16
    or      r0,r0,r3
    slwi    r0,r0,2
    stw     r0,0(r4)
    lwz     r3,-21992(r13)
    addi    r10,r3,34
    lhz     r4,34(r3)
    addi    r9,r3,32
.L_80391DBC:
    mr      r0,r4
    lhz     r3,0(r9)
    lhz     r4,0(r10)
    cmplw   r4,r0
    bne+	.L_80391DBC
    slwi    r0,r4,16
    or      r0,r0,r3
    slwi    r0,r0,2
    stw     r0,0(r5)
    lwz     r3,-21992(r13)
    addi    r9,r3,38
    lhz     r4,38(r3)
    addi    r5,r3,36
.L_80391DF0:
    mr      r0,r4
    lhz     r3,0(r5)
    lhz     r4,0(r9)
    cmplw   r4,r0
    bne+	.L_80391DF0
    slwi    r0,r4,16
    or      r0,r0,r3
    slwi    r0,r0,2
    stw     r0,0(r6)
    lwz     r3,-21992(r13)
    addi    r6,r3,42
    lhz     r4,42(r3)
    addi    r5,r3,40
.L_80391E24:
    mr      r0,r4
    lhz     r3,0(r5)
    lhz     r4,0(r6)
    cmplw   r4,r0
    bne+	.L_80391E24
    slwi    r0,r4,16
    or      r0,r0,r3
    slwi    r0,r0,2
    stw     r0,0(r7)
    lwz     r3,-21992(r13)
    addi    r6,r3,46
    lhz     r4,46(r3)
    addi    r5,r3,44
.L_80391E58:
    mr      r0,r4
    lhz     r3,0(r5)
    lhz     r4,0(r6)
    cmplw   r4,r0
    bne+	.L_80391E58
    slwi    r0,r4,16
    or      r0,r0,r3
    stw     r0,0(r8)
    blr
.size GXReadPixMetric, . - GXReadPixMetric

#
# === GXPixel.o (gx.a) ===
#

.global GXSetFog
.balign 4
GXSetFog:
/* 0x8038FBFC | size=0x214 (532 bytes) */
    mflr    r0
    stw     r0,4(r1)
    stwu    r1,-96(r1)
    stfd    f31,88(r1)
    stmw    r23,52(r1)
    li      r30,0
    rlwinm. r31,r3,29,31,31
    addi    r24,r4,0
    addi    r29,r30,0
    clrlwi  r25,r3,29
    li      r28,0
    li      r27,0
    li      r26,0
    beq-	.L_8038FC7C
    fcmpu   cr0,f4,f3
    beq-	.L_8038FC44
    fcmpu   cr0,f2,f1
    bne-	.L_8038FC54
.L_8038FC44:
    lfs     f0,-17448(r13)
    stfs    f0,36(r1)
    stfs    f0,32(r1)
    b	.L_8038FD68
.L_8038FC54:
    fsubs   f5,f2,f1
    lfs     f6,-17444(r13)
    fsubs   f2,f4,f3
    fsubs   f0,f1,f3
    fdivs   f3,f6,f5
    fmuls   f1,f3,f2
    fmuls   f0,f3,f0
    stfs    f1,36(r1)
    stfs    f0,32(r1)
    b	.L_8038FD68
.L_8038FC7C:
    fcmpu   cr0,f4,f3
    beq-	.L_8038FC8C
    fcmpu   cr0,f2,f1
    bne-	.L_8038FC9C
.L_8038FC8C:
    lfs     f3,-17448(r13)
    lfs     f4,-17440(r13)
    fmr     f31,f3
    b	.L_8038FCB8
.L_8038FC9C:
    fsubs   f0,f4,f3
    fsubs   f5,f2,f1
    fmuls   f2,f4,f3
    fdivs   f4,f4,f0
    fmuls   f0,f0,f5
    fdivs   f31,f1,f5
    fdivs   f3,f2,f0
.L_8038FCB8:
    lfs     f1,-17440(r13)
    li      r3,0
    lfd     f0,-17432(r13)
    b	.L_8038FCD0
.L_8038FCC8:
    fmuls   f4,f4,f1
    addi    r3,r3,1
.L_8038FCD0:
    fcmpo   cr0,f4,f0
    bgt+	.L_8038FCC8
    lfd     f0,-17416(r13)
    lfs     f2,-17424(r13)
    lfs     f1,-17448(r13)
    b	.L_8038FCF0
.L_8038FCE8:
    fmuls   f4,f4,f2
    addi    r3,r3,-1
.L_8038FCF0:
    fcmpo   cr0,f4,f1
    ble-	.L_8038FD00
    fcmpo   cr0,f4,f0
    blt+	.L_8038FCE8
.L_8038FD00:
    addi    r23,r3,1
    lfs     f0,-17408(r13)
    li      r0,1
    lfd     f2,-17400(r13)
    slw     r0,r0,r23
    fmuls   f1,f0,f4
    xoris   r0,r0,32768
    stw     r0,44(r1)
    lis     r0,17200
    stw     r0,40(r1)
    lfd     f0,40(r1)
    fsubs   f0,f0,f2
    fdivs   f0,f3,f0
    stfs    f0,36(r1)
    bl	__cvt_fp2unsigned
    rlwimi  r30,r3,0,8,31
    stfs    f31,32(r1)
    rlwimi  r29,r23,0,27,31
    li      r0,239
    addi    r3,r30,0
    rlwimi  r3,r0,24,0,7
    li      r0,240
    addi    r4,r29,0
    rlwimi  r4,r0,24,0,7
    addi    r30,r3,0
    addi    r29,r4,0
.L_8038FD68:
    lwz     r7,36(r1)
    li      r0,97
    lwz     r9,0(r24)
    lis     r4,-13311
    rlwimi  r27,r7,20,21,31
    addi    r6,r27,0
    stb     r0,-32768(r4)
    rlwimi  r6,r7,20,13,20
    lwz     r8,32(r1)
    li      r5,238
    lwz     r3,-17720(r13)
    rlwimi  r6,r7,20,12,12
    rlwimi  r6,r5,24,0,7
    stw     r6,-32768(r4)
    rlwimi  r26,r8,20,21,31
    mr      r6,r26
    stb     r0,-32768(r4)
    rlwimi  r6,r8,20,13,20
    rlwimi  r6,r8,20,12,12
    stw     r30,-32768(r4)
    rlwimi  r6,r31,20,11,11
    li      r5,241
    stb     r0,-32768(r4)
    rlwimi  r6,r25,21,8,10
    rlwimi  r6,r5,24,0,7
    stw     r29,-32768(r4)
    rlwimi  r28,r9,24,8,31
    li      r5,242
    stb     r0,-32768(r4)
    stw     r6,-32768(r4)
    addi    r6,r28,0
    rlwimi  r6,r5,24,0,7
    stb     r0,-32768(r4)
    li      r0,0
    stw     r6,-32768(r4)
    sth     r0,2(r3)
    lmw     r23,52(r1)
    lwz     r0,100(r1)
    lfd     f31,88(r1)
    addi    r1,r1,96
    mtlr    r0
    blr
.size GXSetFog, . - GXSetFog

.global GXInitFogAdjTable
.balign 4
GXInitFogAdjTable:
/* 0x8038FE40 | size=0x1B0 (432 bytes) */
    mflr    r0
    stw     r0,4(r1)
    stwu    r1,-128(r1)
    stfd    f31,120(r1)
    stfd    f30,112(r1)
    stfd    f29,104(r1)
    stfd    f28,96(r1)
    stfd    f27,88(r1)
    stfd    f26,80(r1)
    stfd    f25,72(r1)
    stfd    f24,64(r1)
    stfd    f23,56(r1)
    stw     r31,52(r1)
    stw     r30,48(r1)
    stw     r29,44(r1)
    lfd     f1,-17392(r13)
    lfs     f0,60(r5)
    fcmpu   cr0,f1,f0
    bne-	.L_8038FEB0
    lfs     f1,40(r5)
    lfs     f0,-17444(r13)
    lfs     f2,44(r5)
    fsubs   f1,f1,f0
    lfs     f0,0(r5)
    fdivs   f1,f2,f1
    fdivs   f24,f1,f0
    fmr     f0,f1
    b	.L_8038FEC8
.L_8038FEB0:
    lfs     f2,-17444(r13)
    lfs     f1,0(r5)
    lfs     f0,-17384(r13)
    fdivs   f1,f2,f1
    fmr     f24,f1
    fmuls   f0,f0,f1
.L_8038FEC8:
    clrlwi  r0,r4,16
    lfd     f27,-17360(r13)
    stw     r0,36(r1)
    lis     r31,17200
    lfs     f1,-17424(r13)
    fmuls   f26,f0,f0
    stw     r31,32(r1)
    lfs     f28,-17444(r13)
    mr      r30,r3
    lfd     f0,32(r1)
    lfs     f29,-17448(r13)
    li      r29,0
    fsubs   f0,f0,f27
    lfd     f30,-17416(r13)
    lfd     f31,-17376(r13)
    lfs     f23,-17368(r13)
    fdivs   f25,f1,f0
.L_8038FF0C:
    addi    r0,r29,1
    slwi    r0,r0,5
    stw     r0,36(r1)
    stw     r31,32(r1)
    lfd     f0,32(r1)
    fsubs   f0,f0,f27
    fmuls   f0,f0,f25
    fmuls   f0,f0,f24
    fmuls   f0,f0,f0
    fdivs   f0,f0,f26
    fadds   f2,f28,f0
    fcmpo   cr0,f2,f29
    ble-	.L_8038FF90
    frsqrte f1,f2
    fmul    f0,f1,f1
    fmul    f1,f30,f1
    fmul    f0,f2,f0
    fsub    f0,f31,f0
    fmul    f1,f1,f0
    fmul    f0,f1,f1
    fmul    f1,f30,f1
    fmul    f0,f2,f0
    fsub    f0,f31,f0
    fmul    f1,f1,f0
    fmul    f0,f1,f1
    fmul    f1,f30,f1
    fmul    f0,f2,f0
    fsub    f0,f31,f0
    fmul    f0,f1,f0
    fmul    f0,f2,f0
    frsp    f0,f0
    stfs    f0,20(r1)
    lfs     f2,20(r1)
.L_8038FF90:
    fmuls   f1,f23,f2
    bl	__cvt_fp2unsigned
    addi    r29,r29,1
    clrlwi  r0,r3,20
    sth     r0,0(r30)
    cmplwi  r29,10
    addi    r30,r30,2
    blt+	.L_8038FF0C
    lwz     r0,132(r1)
    lfd     f31,120(r1)
    lfd     f30,112(r1)
    lfd     f29,104(r1)
    lfd     f28,96(r1)
    lfd     f27,88(r1)
    lfd     f26,80(r1)
    lfd     f25,72(r1)
    lfd     f24,64(r1)
    lfd     f23,56(r1)
    lwz     r31,52(r1)
    lwz     r30,48(r1)
    lwz     r29,44(r1)
    addi    r1,r1,128
    mtlr    r0
    blr
.size GXInitFogAdjTable, . - GXInitFogAdjTable

.global GXSetFogRangeAdj
.balign 4
GXSetFogRangeAdj:
/* 0x8038FFF0 | size=0x124 (292 bytes) */
    clrlwi. r0,r3,24
    beq-	.L_803900D8
    li      r6,0
    slwi    r0,r6,1
    add     r9,r5,r0
    lhz     r8,0(r9)
    srwi    r10,r6,1
    lhz     r7,2(r9)
    li      r0,97
    lis     r5,-13311
    li      r11,0
    stb     r0,-32768(r5)
    rlwimi  r11,r8,0,20,31
    addi    r8,r11,0
    addi    r6,r10,233
    rlwimi  r8,r7,12,8,19
    rlwimi  r8,r6,24,0,7
    stw     r8,-32768(r5)
    addi    r6,r10,234
    li      r11,0
    lhz     r8,4(r9)
    lhz     r7,6(r9)
    rlwimi  r11,r8,0,20,31
    addi    r8,r11,0
    stb     r0,-32768(r5)
    rlwimi  r8,r7,12,8,19
    rlwimi  r8,r6,24,0,7
    stw     r8,-32768(r5)
    addi    r6,r10,235
    li      r11,0
    lhz     r8,8(r9)
    lhz     r7,10(r9)
    rlwimi  r11,r8,0,20,31
    addi    r8,r11,0
    stb     r0,-32768(r5)
    rlwimi  r8,r7,12,8,19
    rlwimi  r8,r6,24,0,7
    stw     r8,-32768(r5)
    addi    r6,r10,236
    li      r11,0
    lhz     r8,12(r9)
    lhz     r7,14(r9)
    rlwimi  r11,r8,0,20,31
    addi    r8,r11,0
    stb     r0,-32768(r5)
    rlwimi  r8,r7,12,8,19
    rlwimi  r8,r6,24,0,7
    stw     r8,-32768(r5)
    addi    r6,r10,237
    li      r11,0
    lhz     r8,16(r9)
    lhz     r7,18(r9)
    rlwimi  r11,r8,0,20,31
    addi    r8,r11,0
    stb     r0,-32768(r5)
    rlwimi  r8,r7,12,8,19
    rlwimi  r8,r6,24,0,7
    stw     r8,-32768(r5)
.L_803900D8:
    clrlwi  r5,r4,16
    lwz     r4,-17720(r13)
    addi    r0,r5,342
    li      r5,0
    rlwimi  r5,r0,0,22,31
    rlwimi  r5,r3,10,21,21
    li      r0,97
    lis     r3,-13311
    stb     r0,-32768(r3)
    li      r0,232
    rlwimi  r5,r0,24,0,7
    stw     r5,-32768(r3)
    li      r0,0
    sth     r0,2(r4)
    blr
.size GXSetFogRangeAdj, . - GXSetFogRangeAdj

#
# === GXTev.o (gx.a) ===
#

.global GXSetTevOrder
.balign 4
GXSetTevOrder:
/* 0x8038FA38 | size=0x19C (412 bytes) */
    srawi   r7,r3,1
    lwz     r9,-17720(r13)
    rlwinm  r10,r5,0,24,22
    addze   r7,r7
    slwi    r0,r3,2
    add     r8,r9,r0
    slwi    r7,r7,2
    stw     r5,1364(r8)
    addi    r7,r7,256
    cmplwi  r10,8
    addi    r0,r10,0
    add     r7,r9,r7
    blt-	.L_8038FA74
    li      r9,0
    b	.L_8038FA78
.L_8038FA74:
    mr      r9,r0
.L_8038FA78:
    cmpwi   r4,8
    blt-	.L_8038FAA4
    lwz     r4,-17720(r13)
    li      r0,1
    slw     r0,r0,r3
    lwz     r8,1432(r4)
    addi    r10,r4,1432
    li      r4,0
    andc    r0,r8,r0
    stw     r0,0(r10)
    b	.L_8038FAC0
.L_8038FAA4:
    lwz     r8,-17720(r13)
    li      r0,1
    slw     r0,r0,r3
    addi    r10,r8,1432
    lwz     r8,1432(r8)
    or      r0,r8,r0
    stw     r0,0(r10)
.L_8038FAC0:
    clrlwi. r0,r3,31
    beq-	.L_8038FB38
    lwz     r0,0(r7)
    rlwimi  r0,r9,12,17,19
    cmpwi   r6,255
    stw     r0,0(r7)
    lwz     r0,0(r7)
    rlwimi  r0,r4,15,14,16
    stw     r0,0(r7)
    bne-	.L_8038FAF0
    li      r3,7
    b	.L_8038FB04
.L_8038FAF0:
    lis     r3,-32698
    slwi    r4,r6,2
    addi    r0,r3,-22920
    add     r3,r0,r4
    lwz     r3,0(r3)
.L_8038FB04:
    lwz     r0,0(r7)
    rlwimi  r0,r3,19,10,12
    cmpwi   r5,255
    stw     r0,0(r7)
    li      r3,0
    beq-	.L_8038FB28
    rlwinm. r0,r5,0,23,23
    bne-	.L_8038FB28
    li      r3,1
.L_8038FB28:
    lwz     r0,0(r7)
    rlwimi  r0,r3,18,13,13
    stw     r0,0(r7)
    b	.L_8038FBA4
.L_8038FB38:
    lwz     r0,0(r7)
    rlwimi  r0,r9,0,29,31
    cmpwi   r6,255
    stw     r0,0(r7)
    lwz     r0,0(r7)
    rlwimi  r0,r4,3,26,28
    stw     r0,0(r7)
    bne-	.L_8038FB60
    li      r3,7
    b	.L_8038FB74
.L_8038FB60:
    lis     r3,-32698
    slwi    r4,r6,2
    addi    r0,r3,-22920
    add     r3,r0,r4
    lwz     r3,0(r3)
.L_8038FB74:
    lwz     r0,0(r7)
    rlwimi  r0,r3,7,22,24
    cmpwi   r5,255
    stw     r0,0(r7)
    li      r3,0
    beq-	.L_8038FB98
    rlwinm. r0,r5,0,23,23
    bne-	.L_8038FB98
    li      r3,1
.L_8038FB98:
    lwz     r0,0(r7)
    rlwimi  r0,r3,6,25,25
    stw     r0,0(r7)
.L_8038FBA4:
    li      r0,97
    lwz     r3,-17720(r13)
    lis     r5,-13311
    stb     r0,-32768(r5)
    li      r0,0
    lwz     r4,0(r7)
    stw     r4,-32768(r5)
    sth     r0,2(r3)
    lwz     r0,1452(r3)
    ori     r0,r0,1
    stw     r0,1452(r3)
    blr
.size GXSetTevOrder, . - GXSetTevOrder

#
# === GXTexture.o (gx.a) ===
#

.global GXGetTexBufferSize
.balign 4
GXGetTexBufferSize:
/* 0x8038D134 | size=0x15C (348 bytes) */
    stwu    r1,-40(r1)
    cmplwi  r5,60
    stw     r31,36(r1)
    bgt-	.L_8038D180
    lis     r8,-32698
    addi    r8,r8,-23548
    slwi    r0,r5,2
    lwzx    r0,r8,r0
    mtctr   r0
    bctr
    li      r0,3
    li      r8,3
    b	.L_8038D188
    li      r0,3
    li      r8,2
    b	.L_8038D188
    li      r0,2
    li      r8,2
    b	.L_8038D188
.L_8038D180:
    li      r8,0
    li      r0,0
.L_8038D188:
    cmplwi  r5,6
    beq-	.L_8038D198
    cmplwi  r5,22
    bne-	.L_8038D1A0
.L_8038D198:
    li      r5,64
    b	.L_8038D1A4
.L_8038D1A0:
    li      r5,32
.L_8038D1A4:
    clrlwi  r6,r6,24
    cmplwi  r6,1
    bne-	.L_8038D24C
    clrlwi  r9,r7,24
    li      r6,1
    mtctr   r9
    slw     r7,r6,r8
    slw     r6,r6,r0
    cmplwi  r9,0
    addi    r10,r6,-1
    addi    r7,r7,-1
    li      r31,0
    ble-	.L_8038D280
.L_8038D1D8:
    clrlwi  r11,r3,16
    add     r6,r11,r10
    clrlwi  r12,r4,16
    sraw    r9,r6,r0
    add     r6,r12,r7
    sraw    r6,r6,r8
    mullw   r6,r9,r6
    mullw   r6,r5,r6
    cmplwi  r11,1
    add     r31,r31,r6
    bne-	.L_8038D20C
    cmplwi  r12,1
    beq-	.L_8038D280
.L_8038D20C:
    clrlwi  r3,r3,16
    cmplwi  r3,1
    ble-	.L_8038D220
    srawi   r6,r11,1
    b	.L_8038D224
.L_8038D220:
    li      r6,1
.L_8038D224:
    clrlwi  r3,r4,16
    cmplwi  r3,1
    clrlwi  r3,r6,16
    ble-	.L_8038D23C
    srawi   r4,r12,1
    b	.L_8038D240
.L_8038D23C:
    li      r4,1
.L_8038D240:
    clrlwi  r4,r4,16
    bdnz+	.L_8038D1D8
    b	.L_8038D280
.L_8038D24C:
    li      r6,1
    slw     r7,r6,r0
    slw     r6,r6,r8
    clrlwi  r9,r3,16
    addi    r3,r7,-1
    add     r7,r9,r3
    clrlwi  r4,r4,16
    addi    r3,r6,-1
    sraw    r6,r7,r0
    add     r0,r4,r3
    sraw    r0,r0,r8
    mullw   r0,r6,r0
    mullw   r31,r5,r0
.L_8038D280:
    mr      r3,r31
    lwz     r31,36(r1)
    addi    r1,r1,40
    blr
.size GXGetTexBufferSize, . - GXGetTexBufferSize

.global GXInitTexObj
.balign 4
GXInitTexObj:
/* 0x8038D358 | size=0x24C (588 bytes) */
    mflr    r0
    stw     r0,4(r1)
    stwu    r1,-96(r1)
    stmw    r24,64(r1)
    addi    r27,r4,0
    addi    r28,r5,0
    addi    r31,r3,0
    addi    r29,r6,0
    addi    r30,r7,0
    addi    r24,r8,0
    addi    r25,r9,0
    addi    r26,r10,0
    li      r4,0
    li      r5,32
    bl	memset
    lwz     r3,0(r31)
    rlwimi  r3,r24,0,30,31
    clrlwi. r0,r26,24
    stw     r3,0(r31)
    li      r3,1
    lwz     r0,0(r31)
    rlwimi  r0,r25,2,28,29
    stw     r0,0(r31)
    lwz     r0,0(r31)
    rlwimi  r0,r3,4,27,27
    stw     r0,0(r31)
    beq-	.L_8038D460
    lbz     r3,31(r31)
    addi    r0,r30,-8
    cmplwi  r0,2
    ori     r0,r3,1
    stb     r0,31(r31)
    bgt-	.L_8038D3F0
    lwz     r3,0(r31)
    li      r0,5
    rlwimi  r3,r0,5,24,26
    stw     r3,0(r31)
    b	.L_8038D400
.L_8038D3F0:
    lwz     r3,0(r31)
    li      r0,6
    rlwimi  r3,r0,5,24,26
    stw     r3,0(r31)
.L_8038D400:
    clrlwi  r3,r28,16
    clrlwi  r0,r29,16
    cmplw   r3,r0
    ble-	.L_8038D41C
    cntlzw  r0,r3
    subfic  r0,r0,31
    b	.L_8038D424
.L_8038D41C:
    cntlzw  r0,r0
    subfic  r0,r0,31
.L_8038D424:
    stw     r0,60(r1)
    lis     r0,17200
    lfd     f1,-17552(r13)
    stw     r0,56(r1)
    lfs     f2,-17560(r13)
    lfd     f0,56(r1)
    lwz     r3,4(r31)
    fsubs   f0,f0,f1
    fmuls   f0,f2,f0
    fctiwz  f0,f0
    stfd    f0,48(r1)
    lwz     r0,52(r1)
    rlwimi  r3,r0,8,16,23
    stw     r3,4(r31)
    b	.L_8038D470
.L_8038D460:
    lwz     r3,0(r31)
    li      r0,4
    rlwimi  r3,r0,5,24,26
    stw     r3,0(r31)
.L_8038D470:
    stw     r30,20(r31)
    clrlwi  r7,r28,16
    clrlwi  r4,r30,28
    addi    r0,r7,-1
    lwz     r3,8(r31)
    rlwimi  r3,r0,0,22,31
    stw     r3,8(r31)
    clrlwi  r5,r29,16
    addi    r0,r5,-1
    lwz     r3,8(r31)
    rlwimi  r3,r0,10,12,21
    cmplwi  r4,14
    stw     r3,8(r31)
    lwz     r0,8(r31)
    rlwimi  r0,r30,20,8,11
    stw     r0,8(r31)
    lwz     r0,12(r31)
    rlwimi  r0,r27,27,11,31
    stw     r0,12(r31)
    bgt-	.L_8038D53C
    lis     r3,-32698
    addi    r3,r3,-23060
    slwi    r0,r4,2
    lwzx    r0,r3,r0
    mtctr   r0
    bctr
    li      r0,1
    stb     r0,30(r31)
    li      r0,3
    li      r6,3
    b	.L_8038D54C
    li      r0,2
    stb     r0,30(r31)
    li      r0,3
    li      r6,2
    b	.L_8038D54C
    li      r0,2
    stb     r0,30(r31)
    li      r0,2
    li      r6,2
    b	.L_8038D54C
    li      r0,3
    stb     r0,30(r31)
    li      r0,2
    li      r6,2
    b	.L_8038D54C
    li      r0,0
    stb     r0,30(r31)
    li      r0,3
    li      r6,3
    b	.L_8038D54C
.L_8038D53C:
    li      r0,2
    stb     r0,30(r31)
    li      r0,2
    li      r6,2
.L_8038D54C:
    clrlwi  r8,r0,16
    li      r4,1
    slw     r3,r4,r8
    clrlwi  r6,r6,16
    addi    r0,r3,-1
    slw     r3,r4,r6
    add     r4,r7,r0
    addi    r0,r3,-1
    sraw    r3,r4,r8
    add     r0,r5,r0
    sraw    r0,r0,r6
    mullw   r0,r3,r0
    clrlwi  r0,r0,17
    sth     r0,28(r31)
    lbz     r0,31(r31)
    ori     r0,r0,2
    stb     r0,31(r31)
    lwz     r0,100(r1)
    lmw     r24,64(r1)
    addi    r1,r1,96
    mtlr    r0
    blr
.size GXInitTexObj, . - GXInitTexObj

.global GXInitTexObjLOD
.balign 4
GXInitTexObjLOD:
/* 0x8038D5EC | size=0x164 (356 bytes) */
    stwu    r1,-48(r1)
    lfs     f0,-17544(r13)
    fcmpo   cr0,f3,f0
    bge-	.L_8038D604
    fmr     f3,f0
    b	.L_8038D618
.L_8038D604:
    lfs     f0,-17540(r13)
    fcmpo   cr0,f3,f0
    cror    eq,gt,eq
    bne-	.L_8038D618
    lfs     f3,-17536(r13)
.L_8038D618:
    lfs     f0,-17532(r13)
    cmpwi   r5,1
    lwz     r5,0(r3)
    fmuls   f0,f0,f3
    fctiwz  f0,f0
    stfd    f0,40(r1)
    lwz     r0,44(r1)
    rlwimi  r5,r0,9,15,22
    stw     r5,0(r3)
    bne-	.L_8038D648
    li      r0,1
    b	.L_8038D64C
.L_8038D648:
    li      r0,0
.L_8038D64C:
    lwz     r5,0(r3)
    rlwimi  r5,r0,4,27,27
    clrlwi. r0,r7,24
    stw     r5,0(r3)
    addi    r5,r13,-25240
    lbzx    r0,r5,r4
    lwz     r4,0(r3)
    rlwimi  r4,r0,5,24,26
    stw     r4,0(r3)
    beq-	.L_8038D67C
    li      r4,0
    b	.L_8038D680
.L_8038D67C:
    li      r4,1
.L_8038D680:
    lwz     r0,0(r3)
    rlwimi  r0,r4,8,23,23
    li      r5,0
    stw     r0,0(r3)
    lwz     r4,0(r3)
    rlwimi  r4,r5,17,14,14
    stw     r4,0(r3)
    lwz     r4,0(r3)
    rlwimi  r4,r5,18,13,13
    stw     r4,0(r3)
    lwz     r4,0(r3)
    rlwimi  r4,r8,19,11,12
    stw     r4,0(r3)
    lwz     r4,0(r3)
    rlwimi  r4,r6,21,10,10
    stw     r4,0(r3)
    lfs     f0,-17528(r13)
    fcmpo   cr0,f1,f0
    bge-	.L_8038D6D4
    fmr     f1,f0
    b	.L_8038D6E4
.L_8038D6D4:
    lfs     f0,-17524(r13)
    fcmpo   cr0,f1,f0
    ble-	.L_8038D6E4
    fmr     f1,f0
.L_8038D6E4:
    lfs     f3,-17560(r13)
    lfs     f0,-17528(r13)
    fmuls   f1,f3,f1
    fcmpo   cr0,f2,f0
    fctiwz  f1,f1
    stfd    f1,40(r1)
    lwz     r0,44(r1)
    bge-	.L_8038D70C
    fmr     f2,f0
    b	.L_8038D71C
.L_8038D70C:
    lfs     f0,-17524(r13)
    fcmpo   cr0,f2,f0
    ble-	.L_8038D71C
    fmr     f2,f0
.L_8038D71C:
    lfs     f0,-17560(r13)
    lwz     r4,4(r3)
    rlwimi  r4,r0,0,24,31
    fmuls   f0,f0,f2
    stw     r4,4(r3)
    fctiwz  f0,f0
    lwz     r4,4(r3)
    stfd    f0,40(r1)
    lwz     r0,44(r1)
    rlwimi  r4,r0,8,16,23
    stw     r4,4(r3)
    addi    r1,r1,48
    blr
.size GXInitTexObjLOD, . - GXInitTexObjLOD

.global GXLoadTexObjPreLoaded
.balign 4
GXLoadTexObjPreLoaded:
/* 0x8038DBB4 | size=0x17C (380 bytes) */
    mflr    r0
    addi    r7,r13,-25280
    stw     r0,4(r1)
    addi    r6,r13,-25272
    stwu    r1,-64(r1)
    stw     r31,60(r1)
    addi    r31,r5,0
    addi    r5,r13,-25296
    stw     r30,56(r1)
    addi    r30,r3,0
    stw     r29,52(r1)
    lis     r29,-13311
    stw     r28,48(r1)
    li      r28,97
    lbzx    r0,r5,r31
    lwz     r5,0(r3)
    addi    r3,r13,-25288
    rlwimi  r5,r0,24,0,7
    stw     r5,0(r30)
    addi    r5,r13,-25264
    lbzx    r0,r3,r31
    addi    r3,r13,-25256
    lwz     r8,4(r30)
    rlwimi  r8,r0,24,0,7
    stw     r8,4(r30)
    lbzx    r0,r7,r31
    lwz     r7,8(r30)
    rlwimi  r7,r0,24,0,7
    stw     r7,8(r30)
    lbzx    r0,r6,r31
    lwz     r6,0(r4)
    rlwimi  r6,r0,24,0,7
    stw     r6,0(r4)
    lbzx    r0,r5,r31
    lwz     r5,4(r4)
    rlwimi  r5,r0,24,0,7
    stw     r5,4(r4)
    lbzx    r0,r3,r31
    lwz     r3,12(r30)
    rlwimi  r3,r0,24,0,7
    stw     r3,12(r30)
    stb     r28,-32768(r29)
    lwz     r0,0(r30)
    stw     r0,-32768(r29)
    stb     r28,-32768(r29)
    lwz     r0,4(r30)
    stw     r0,-32768(r29)
    stb     r28,-32768(r29)
    lwz     r0,8(r30)
    stw     r0,-32768(r29)
    stb     r28,-32768(r29)
    lwz     r0,0(r4)
    stw     r0,-32768(r29)
    stb     r28,-32768(r29)
    lwz     r0,4(r4)
    stw     r0,-32768(r29)
    stb     r28,-32768(r29)
    lwz     r0,12(r30)
    stw     r0,-32768(r29)
    lbz     r0,31(r30)
    rlwinm. r0,r0,0,30,30
    bne-	.L_8038DCE0
    lwz     r4,-17720(r13)
    lwz     r3,24(r30)
    lwz     r12,1228(r4)
    mtlr    r12
    blrl
    addi    r4,r13,-25248
    lwz     r5,4(r3)
    lbzx    r0,r4,r31
    rlwimi  r5,r0,24,0,7
    stw     r5,4(r3)
    stb     r28,-32768(r29)
    lwz     r0,4(r3)
    stw     r0,-32768(r29)
.L_8038DCE0:
    lwz     r5,-17720(r13)
    slwi    r4,r31,2
    lwz     r3,8(r30)
    li      r0,0
    add     r4,r5,r4
    stw     r3,1300(r4)
    lwz     r3,0(r30)
    stw     r3,1332(r4)
    lwz     r3,1452(r5)
    ori     r3,r3,1
    stw     r3,1452(r5)
    sth     r0,2(r5)
    lwz     r0,68(r1)
    lwz     r31,60(r1)
    lwz     r30,56(r1)
    lwz     r29,52(r1)
    lwz     r28,48(r1)
    addi    r1,r1,64
    mtlr    r0
    blr
.size GXLoadTexObjPreLoaded, . - GXLoadTexObjPreLoaded

.global GXGetTexRegionAll
.balign 4
GXGetTexRegionAll:
/* 0x8038E010 | size=0x10C (268 bytes) */
    lwz     r0,0(r3)
    rlwinm  r0,r0,5,12,26
    stw     r0,0(r6)
    lwz     r0,4(r3)
    rlwinm  r0,r0,5,12,26
    stw     r0,0(r8)
    lbz     r0,13(r3)
    cmplwi  r0,0
    beq-	.L_8038E0F0
    lwz     r0,0(r3)
    rlwinm  r0,r0,17,29,31
    cmpwi   r0,4
    beq-	.L_8038E070
    bge-	.L_8038E054
    cmpwi   r0,3
    bge-	.L_8038E060
    b	.L_8038E088
.L_8038E054:
    cmpwi   r0,6
    bge-	.L_8038E088
    b	.L_8038E07C
.L_8038E060:
    lis     r6,1
    addi    r0,r6,-32768
    stw     r0,0(r7)
    b	.L_8038E090
.L_8038E070:
    lis     r0,2
    stw     r0,0(r7)
    b	.L_8038E090
.L_8038E07C:
    lis     r0,8
    stw     r0,0(r7)
    b	.L_8038E090
.L_8038E088:
    li      r0,0
    stw     r0,0(r7)
.L_8038E090:
    lwz     r0,4(r3)
    rlwinm  r0,r0,17,29,31
    cmpwi   r0,4
    beq-	.L_8038E0CC
    bge-	.L_8038E0B0
    cmpwi   r0,3
    bge-	.L_8038E0BC
    b	.L_8038E0E4
.L_8038E0B0:
    cmpwi   r0,6
    bge-	.L_8038E0E4
    b	.L_8038E0D8
.L_8038E0BC:
    lis     r6,1
    addi    r0,r6,-32768
    stw     r0,0(r9)
    b	.L_8038E108
.L_8038E0CC:
    lis     r0,2
    stw     r0,0(r9)
    b	.L_8038E108
.L_8038E0D8:
    lis     r0,8
    stw     r0,0(r9)
    b	.L_8038E108
.L_8038E0E4:
    li      r0,0
    stw     r0,0(r9)
    b	.L_8038E108
.L_8038E0F0:
    lhz     r0,8(r3)
    slwi    r0,r0,5
    stw     r0,0(r7)
    lhz     r0,10(r3)
    slwi    r0,r0,5
    stw     r0,0(r9)
.L_8038E108:
    lbz     r0,12(r3)
    stb     r0,0(r5)
    lbz     r0,13(r3)
    stb     r0,0(r4)
    blr
.size GXGetTexRegionAll, . - GXGetTexRegionAll

.global GXInvalidateTexRegion
.balign 4
GXInvalidateTexRegion:
/* 0x8038E174 | size=0x12C (300 bytes) */
    mflr    r0
    stw     r0,4(r1)
    stwu    r1,-32(r1)
    stw     r31,28(r1)
    stw     r30,24(r1)
    stw     r29,20(r1)
    lwz     r7,0(r3)
    lwz     r0,4(r3)
    rlwinm  r4,r7,17,29,31
    addic.  r8,r4,-1
    rlwinm  r6,r7,14,29,31
    rlwinm  r5,r0,17,29,31
    rlwinm  r4,r0,14,29,31
    addi    r31,r5,-1
    addi    r6,r6,-1
    addi    r5,r4,-1
    bge-	.L_8038E1BC
    li      r8,0
.L_8038E1BC:
    cmpwi   r6,0
    bge-	.L_8038E1C8
    li      r6,0
.L_8038E1C8:
    cmpwi   r31,0
    bge-	.L_8038E1D4
    li      r31,0
.L_8038E1D4:
    cmpwi   r5,0
    bge-	.L_8038E1E0
    li      r5,0
.L_8038E1E0:
    lbz     r0,12(r3)
    add     r4,r8,r6
    addi    r6,r4,0
    cmplwi  r0,0
    beq-	.L_8038E200
    addi    r0,r5,-2
    add     r6,r0,r6
    add     r6,r31,r6
.L_8038E200:
    rlwinm  r0,r7,26,23,31
    li      r7,0
    rlwimi  r7,r0,0,23,31
    addi    r29,r7,0
    cmpwi   r31,0
    li      r0,102
    rlwimi  r29,r6,9,19,22
    rlwimi  r29,r0,24,0,7
    beq-	.L_8038E25C
    lbz     r0,12(r3)
    add     r5,r31,r5
    cmplwi  r0,0
    beq-	.L_8038E23C
    add     r5,r4,r5
    addi    r5,r5,-2
.L_8038E23C:
    lwz     r3,4(r3)
    li      r30,0
    li      r0,102
    rlwimi  r30,r3,26,23,31
    addi    r3,r30,0
    rlwimi  r3,r5,9,19,22
    rlwimi  r3,r0,24,0,7
    addi    r30,r3,0
.L_8038E25C:
    bl	__GXFlushTextureState
    li      r0,97
    lis     r3,-13311
    stb     r0,-32768(r3)
    cmpwi   r31,0
    stw     r29,-32768(r3)
    beq-	.L_8038E280
    stb     r0,-32768(r3)
    stw     r30,-32768(r3)
.L_8038E280:
    bl	__GXFlushTextureState
    lwz     r0,36(r1)
    lwz     r31,28(r1)
    lwz     r30,24(r1)
    lwz     r29,20(r1)
    addi    r1,r1,32
    mtlr    r0
    blr
.size GXInvalidateTexRegion, . - GXInvalidateTexRegion

.global GXPreLoadEntireTexture
.balign 4
GXPreLoadEntireTexture:
/* 0x8038E310 | size=0x264 (612 bytes) */
    mflr    r0
    li      r5,99
    stw     r0,4(r1)
    li      r11,0
    rlwimi  r11,r5,24,0,7
    stwu    r1,-112(r1)
    li      r12,0
    stmw    r14,40(r1)
    mr      r18,r3
    addi    r19,r11,0
    li      r11,0
    li      r17,0
    lbz     r3,31(r3)
    lwz     r0,8(r18)
    clrlwi  r3,r3,31
    lwz     r7,0(r4)
    addi    r3,r3,-1
    lwz     r6,4(r4)
    cntlzw  r10,r3
    lhz     r4,28(r18)
    rlwinm  r9,r0,12,28,31
    lbz     r3,30(r18)
    subfic  r9,r9,6
    lwz     r8,12(r18)
    cntlzw  r5,r9
    rlwimi  r19,r4,0,17,31
    rlwimi  r19,r3,15,15,16
    li      r3,96
    li      r9,0
    rlwimi  r9,r3,24,0,7
    li      r3,97
    rlwimi  r11,r3,24,0,7
    li      r3,98
    rlwimi  r12,r3,24,0,7
    addi    r22,r9,0
    addi    r21,r11,0
    addi    r20,r12,0
    rlwinm. r10,r10,27,24,31
    clrlwi  r31,r8,11
    rlwimi  r22,r8,0,11,31
    clrlwi  r24,r7,17
    rlwimi  r21,r7,0,17,31
    clrlwi  r25,r6,17
    rlwimi  r20,r6,0,17,31
    addi    r23,r4,0
    rlwinm  r14,r5,27,24,31
    beq-	.L_8038E408
    clrlwi  r4,r0,22
    rlwinm  r3,r0,22,22,31
    addi    r4,r4,1
    addi    r0,r3,1
    cmplw   r4,r0
    addi    r15,r4,0
    mr      r16,r0
    ble-	.L_8038E3FC
    cntlzw  r0,r15
    subfic  r0,r0,31
    clrlwi  r17,r0,16
    b	.L_8038E408
.L_8038E3FC:
    cntlzw  r0,r16
    subfic  r0,r0,31
    clrlwi  r17,r0,16
.L_8038E408:
    bl	__GXFlushTextureState
    li      r0,97
    lis     r27,-13311
    stb     r0,-32768(r27)
    cmplwi  r17,0
    stw     r22,-32768(r27)
    stb     r0,-32768(r27)
    stw     r21,-32768(r27)
    stb     r0,-32768(r27)
    stw     r20,-32768(r27)
    stb     r0,-32768(r27)
    stw     r19,-32768(r27)
    beq-	.L_8038E55C
    addi    r30,r24,0
    addi    r29,r25,0
    li      r28,0
    b	.L_8038E554
.L_8038E44C:
    cmplwi  r14,0
    beq-	.L_8038E468
    slwi    r0,r23,1
    add     r31,r31,r0
    add     r30,r30,r23
    add     r29,r29,r23
    b	.L_8038E480
.L_8038E468:
    clrlwi. r0,r28,31
    add     r31,r31,r23
    beq-	.L_8038E47C
    add     r29,r29,r23
    b	.L_8038E480
.L_8038E47C:
    add     r30,r30,r23
.L_8038E480:
    clrlwi. r0,r28,31
    beq-	.L_8038E490
    mr      r24,r30
    b	.L_8038E494
.L_8038E490:
    mr      r24,r29
.L_8038E494:
    cmplwi  r0,0
    beq-	.L_8038E4A4
    mr      r23,r29
    b	.L_8038E4A8
.L_8038E4A4:
    mr      r23,r30
.L_8038E4A8:
    addi    r4,r28,1
    lwz     r3,20(r18)
    srw     r0,r16,r4
    srw     r4,r15,r4
    clrlwi  r26,r4,16
    clrlwi  r25,r0,16
    addi    r4,r1,24
    addi    r5,r1,28
    bl	__GXGetTexTileShift
    cmplwi  r26,0
    bne-	.L_8038E4D8
    li      r26,1
.L_8038E4D8:
    cmplwi  r25,0
    bne-	.L_8038E4E4
    li      r25,1
.L_8038E4E4:
    li      r4,97
    lwz     r0,24(r1)
    stb     r4,-32768(r27)
    rlwimi  r22,r31,0,11,31
    li      r5,1
    lwz     r3,28(r1)
    stw     r22,-32768(r27)
    slw     r6,r5,r0
    slw     r5,r5,r3
    stb     r4,-32768(r27)
    rlwimi  r21,r24,0,17,31
    stw     r21,-32768(r27)
    clrlwi  r7,r26,16
    addi    r6,r6,-1
    add     r7,r7,r6
    stb     r4,-32768(r27)
    rlwimi  r20,r23,0,17,31
    stw     r20,-32768(r27)
    clrlwi  r6,r25,16
    addi    r5,r5,-1
    sraw    r7,r7,r0
    stb     r4,-32768(r27)
    add     r0,r6,r5
    sraw    r0,r0,r3
    mullw   r23,r7,r0
    rlwimi  r19,r23,0,17,31
    stw     r19,-32768(r27)
    addi    r28,r28,1
.L_8038E554:
    cmplw   r28,r17
    blt+	.L_8038E44C
.L_8038E55C:
    bl	__GXFlushTextureState
    lmw     r14,40(r1)
    lwz     r0,116(r1)
    addi    r1,r1,112
    mtlr    r0
    blr
.size GXPreLoadEntireTexture, . - GXPreLoadEntireTexture

.global __GXSetSUTexRegs
.balign 4
__GXSetSUTexRegs:
/* 0x8038E758 | size=0x17C (380 bytes) */
    mflr    r0
    stw     r0,4(r1)
    stwu    r1,-40(r1)
    stmw    r27,20(r1)
    lwz     r3,-17720(r13)
    lwz     r0,1428(r3)
    cmplwi  r0,255
    beq-	.L_8038E8C0
    lwz     r0,516(r3)
    li      r31,0
    rlwinm  r3,r0,22,28,31
    addi    r30,r3,1
    rlwinm  r27,r0,16,29,31
    b	.L_8038E82C
.L_8038E790:
    cmpwi   r31,2
    beq-	.L_8038E7E0
    bge-	.L_8038E7AC
    cmpwi   r31,0
    beq-	.L_8038E7B8
    bge-	.L_8038E7CC
    b	.L_8038E804
.L_8038E7AC:
    cmpwi   r31,4
    bge-	.L_8038E804
    b	.L_8038E7F4
.L_8038E7B8:
    lwz     r3,-17720(r13)
    lwz     r0,288(r3)
    clrlwi  r29,r0,29
    rlwinm  r28,r0,29,29,31
    b	.L_8038E804
.L_8038E7CC:
    lwz     r3,-17720(r13)
    lwz     r0,288(r3)
    rlwinm  r29,r0,26,29,31
    rlwinm  r28,r0,23,29,31
    b	.L_8038E804
.L_8038E7E0:
    lwz     r3,-17720(r13)
    lwz     r0,288(r3)
    rlwinm  r29,r0,20,29,31
    rlwinm  r28,r0,17,29,31
    b	.L_8038E804
.L_8038E7F4:
    lwz     r3,-17720(r13)
    lwz     r0,288(r3)
    rlwinm  r29,r0,14,29,31
    rlwinm  r28,r0,11,29,31
.L_8038E804:
    lwz     r3,-17720(r13)
    li      r0,1
    slw     r0,r0,r28
    lwz     r3,1428(r3)
    and.    r0,r3,r0
    bne-	.L_8038E828
    addi    r3,r29,0
    addi    r4,r28,0
    bl	__SetSURegs
.L_8038E828:
    addi    r31,r31,1
.L_8038E82C:
    cmplw   r31,r27
    blt+	.L_8038E790
    li      r31,0
    addi    r27,r31,0
    b	.L_8038E8B8
.L_8038E840:
    lwz     r5,-17720(r13)
    addi    r3,r27,1364
    rlwinm  r4,r31,1,0,29
    lwzx    r3,r5,r3
    clrlwi. r0,r31,31
    addi    r4,r4,256
    add     r4,r5,r4
    rlwinm  r29,r3,0,24,22
    beq-	.L_8038E870
    lwz     r0,0(r4)
    rlwinm  r28,r0,17,29,31
    b	.L_8038E878
.L_8038E870:
    lwz     r0,0(r4)
    rlwinm  r28,r0,29,29,31
.L_8038E878:
    cmplwi  r29,255
    beq-	.L_8038E8B0
    li      r4,1
    lwz     r3,1428(r5)
    slw     r0,r4,r28
    and.    r0,r3,r0
    bne-	.L_8038E8B0
    lwz     r3,1432(r5)
    slw     r0,r4,r31
    and.    r0,r3,r0
    beq-	.L_8038E8B0
    addi    r3,r29,0
    addi    r4,r28,0
    bl	__SetSURegs
.L_8038E8B0:
    addi    r27,r27,4
    addi    r31,r31,1
.L_8038E8B8:
    cmplw   r31,r30
    blt+	.L_8038E840
.L_8038E8C0:
    lmw     r27,20(r1)
    lwz     r0,44(r1)
    addi    r1,r1,40
    mtlr    r0
    blr
.size __GXSetSUTexRegs, . - __GXSetSUTexRegs

.global __GXSetTmemConfig
.balign 4
__GXSetTmemConfig:
/* 0x8038E904 | size=0x354 (852 bytes) */
    stwu    r1,-24(r1)
    cmpwi   r3,1
    stw     r31,20(r1)
    stw     r30,16(r1)
    beq-	.L_8038EA34
    bge-	.L_8038E920
    b	.L_8038EB40
.L_8038E920:
    cmpwi   r3,3
    bge-	.L_8038EB40
    li      r0,97
    lis     r3,-13311
    lis     r4,-29682
    stb     r0,-32768(r3)
    addi    r4,r4,-32768
    stw     r4,-32768(r3)
    lis     r4,-28658
    lis     r7,-29426
    stb     r0,-32768(r3)
    addi    r4,r4,-16384
    lis     r6,-28402
    stw     r4,-32768(r3)
    lis     r5,-29170
    lis     r4,-28146
    stb     r0,-32768(r3)
    addi    r7,r7,-30720
    lis     r30,-28914
    stw     r7,-32768(r3)
    lis     r12,-27890
    lis     r11,-21490
    stb     r0,-32768(r3)
    addi    r6,r6,-14336
    lis     r10,-20466
    stw     r6,-32768(r3)
    lis     r9,-21234
    lis     r8,-20210
    stb     r0,-32768(r3)
    addi    r5,r5,-28672
    lis     r7,-20978
    stw     r5,-32768(r3)
    lis     r6,-19954
    lis     r5,-20722
    stb     r0,-32768(r3)
    addi    r31,r4,-12288
    lis     r4,-19698
    stw     r31,-32768(r3)
    addi    r30,r30,-26624
    addi    r12,r12,-10240
    stb     r0,-32768(r3)
    addi    r11,r11,-24576
    addi    r10,r10,-15360
    stw     r30,-32768(r3)
    addi    r9,r9,-22528
    addi    r8,r8,-13312
    stb     r0,-32768(r3)
    addi    r7,r7,-20480
    addi    r6,r6,-11264
    stw     r12,-32768(r3)
    addi    r5,r5,-18432
    addi    r4,r4,-9216
    stb     r0,-32768(r3)
    stw     r11,-32768(r3)
    stb     r0,-32768(r3)
    stw     r10,-32768(r3)
    stb     r0,-32768(r3)
    stw     r9,-32768(r3)
    stb     r0,-32768(r3)
    stw     r8,-32768(r3)
    stb     r0,-32768(r3)
    stw     r7,-32768(r3)
    stb     r0,-32768(r3)
    stw     r6,-32768(r3)
    stb     r0,-32768(r3)
    stw     r5,-32768(r3)
    stb     r0,-32768(r3)
    stw     r4,-32768(r3)
    b	.L_8038EC48
.L_8038EA34:
    li      r0,97
    lis     r3,-13311
    lis     r4,-29682
    stb     r0,-32768(r3)
    addi    r4,r4,-32768
    stw     r4,-32768(r3)
    lis     r4,-28658
    lis     r7,-29426
    stb     r0,-32768(r3)
    addi    r4,r4,-16384
    lis     r6,-28402
    stw     r4,-32768(r3)
    lis     r5,-29170
    lis     r4,-28146
    stb     r0,-32768(r3)
    addi    r7,r7,-30720
    lis     r30,-28914
    stw     r7,-32768(r3)
    lis     r12,-27890
    lis     r11,-21490
    stb     r0,-32768(r3)
    addi    r6,r6,-14336
    lis     r10,-20466
    stw     r6,-32768(r3)
    lis     r9,-21234
    lis     r8,-20210
    stb     r0,-32768(r3)
    addi    r5,r5,-28672
    lis     r7,-20978
    stw     r5,-32768(r3)
    lis     r6,-19954
    lis     r5,-20722
    stb     r0,-32768(r3)
    addi    r31,r4,-12288
    lis     r4,-19698
    stw     r31,-32768(r3)
    addi    r30,r30,-26624
    addi    r12,r12,-10240
    stb     r0,-32768(r3)
    addi    r11,r11,-24576
    addi    r10,r10,-8192
    stw     r30,-32768(r3)
    addi    r9,r9,-22528
    addi    r8,r8,-6144
    stb     r0,-32768(r3)
    addi    r7,r7,-20480
    addi    r6,r6,-4096
    stw     r12,-32768(r3)
    addi    r5,r5,-18432
    addi    r4,r4,-2048
    stb     r0,-32768(r3)
    stw     r11,-32768(r3)
    stb     r0,-32768(r3)
    stw     r10,-32768(r3)
    stb     r0,-32768(r3)
    stw     r9,-32768(r3)
    stb     r0,-32768(r3)
    stw     r8,-32768(r3)
    stb     r0,-32768(r3)
    stw     r7,-32768(r3)
    stb     r0,-32768(r3)
    stw     r6,-32768(r3)
    stb     r0,-32768(r3)
    stw     r5,-32768(r3)
    stb     r0,-32768(r3)
    stw     r4,-32768(r3)
    b	.L_8038EC48
.L_8038EB40:
    li      r0,97
    lis     r3,-13311
    lis     r4,-29682
    stb     r0,-32768(r3)
    addi    r4,r4,-32768
    stw     r4,-32768(r3)
    lis     r4,-28658
    lis     r7,-29426
    stb     r0,-32768(r3)
    addi    r4,r4,-16384
    lis     r6,-28402
    stw     r4,-32768(r3)
    lis     r5,-29170
    lis     r4,-28146
    stb     r0,-32768(r3)
    addi    r7,r7,-31744
    lis     r31,-28914
    stw     r7,-32768(r3)
    lis     r12,-27890
    lis     r11,-21490
    stb     r0,-32768(r3)
    addi    r6,r6,-15360
    lis     r10,-20466
    stw     r6,-32768(r3)
    lis     r9,-21234
    lis     r8,-20210
    stb     r0,-32768(r3)
    addi    r5,r5,-30720
    lis     r7,-20978
    stw     r5,-32768(r3)
    lis     r6,-19954
    lis     r5,-20722
    stb     r0,-32768(r3)
    addi    r30,r4,-14336
    lis     r4,-19698
    stw     r30,-32768(r3)
    addi    r31,r31,-29696
    addi    r12,r12,-13312
    stb     r0,-32768(r3)
    addi    r11,r11,-28672
    addi    r10,r10,-12288
    stw     r31,-32768(r3)
    addi    r9,r9,-27648
    addi    r8,r8,-11264
    stb     r0,-32768(r3)
    addi    r7,r7,-26624
    addi    r6,r6,-10240
    stw     r12,-32768(r3)
    addi    r5,r5,-25600
    addi    r4,r4,-9216
    stb     r0,-32768(r3)
    stw     r11,-32768(r3)
    stb     r0,-32768(r3)
    stw     r10,-32768(r3)
    stb     r0,-32768(r3)
    stw     r9,-32768(r3)
    stb     r0,-32768(r3)
    stw     r8,-32768(r3)
    stb     r0,-32768(r3)
    stw     r7,-32768(r3)
    stb     r0,-32768(r3)
    stw     r6,-32768(r3)
    stb     r0,-32768(r3)
    stw     r5,-32768(r3)
    stb     r0,-32768(r3)
    stw     r4,-32768(r3)
.L_8038EC48:
    lwz     r31,20(r1)
    lwz     r30,16(r1)
    addi    r1,r1,24
    blr
.size __GXSetTmemConfig, . - __GXSetTmemConfig

#
# === GXTransform.o (gx.a) ===
#

.global GXProject
.balign 4
GXProject:
/* 0x80390614 | size=0x174 (372 bytes) */
    lfs     f4,0(r3)
    lfs     f0,4(r3)
    lfs     f6,16(r3)
    fmuls   f10,f4,f1
    lfs     f5,20(r3)
    fmuls   f9,f0,f2
    lfs     f4,32(r3)
    lfs     f0,36(r3)
    lfs     f11,8(r3)
    fmuls   f7,f6,f1
    fmuls   f6,f5,f2
    lfs     f8,24(r3)
    lfs     f5,40(r3)
    fmuls   f4,f4,f1
    fmuls   f2,f0,f2
    fmuls   f11,f11,f3
    lfs     f1,-17352(r13)
    fadds   f9,f10,f9
    lfs     f0,0(r4)
    fmuls   f8,f8,f3
    fadds   f6,f7,f6
    lfs     f10,12(r3)
    fadds   f9,f11,f9
    lfs     f7,28(r3)
    fadds   f6,f8,f6
    fmuls   f3,f5,f3
    lfs     f5,44(r3)
    fadds   f2,f4,f2
    fcmpu   cr0,f1,f0
    fadds   f8,f10,f9
    fadds   f0,f3,f2
    fadds   f7,f7,f6
    fadds   f9,f5,f0
    bne-	.L_803906E4
    fneg    f0,f9
    lfs     f1,-17348(r13)
    lfs     f6,4(r4)
    lfs     f5,8(r4)
    fdivs   f0,f1,f0
    lfs     f4,12(r4)
    lfs     f3,16(r4)
    lfs     f1,20(r4)
    lfs     f2,24(r4)
    fmuls   f1,f9,f1
    fmuls   f6,f8,f6
    fmuls   f5,f9,f5
    fmuls   f4,f7,f4
    fmuls   f3,f9,f3
    fadds   f6,f6,f5
    fadds   f7,f2,f1
    fadds   f3,f4,f3
    b	.L_80390718
.L_803906E4:
    lfs     f2,4(r4)
    lfs     f1,12(r4)
    lfs     f0,20(r4)
    fmuls   f5,f8,f2
    lfs     f6,8(r4)
    fmuls   f3,f7,f1
    lfs     f4,16(r4)
    fmuls   f1,f9,f0
    lfs     f2,24(r4)
    fadds   f6,f6,f5
    fadds   f3,f4,f3
    lfs     f0,-17348(r13)
    fadds   f7,f2,f1
.L_80390718:
    lfs     f4,8(r5)
    fneg    f1,f3
    lfs     f5,-17344(r13)
    fmuls   f2,f6,f4
    lfs     f3,0(r5)
    fmuls   f4,f4,f5
    fmuls   f2,f2,f5
    fmuls   f2,f0,f2
    fadds   f2,f3,f2
    fadds   f2,f4,f2
    stfs    f2,0(r6)
    lfs     f3,12(r5)
    lfs     f2,4(r5)
    fmuls   f1,f1,f3
    fmuls   f3,f3,f5
    fmuls   f1,f1,f5
    fmuls   f1,f0,f1
    fadds   f1,f2,f1
    fadds   f1,f3,f1
    stfs    f1,0(r7)
    lfs     f2,20(r5)
    lfs     f1,16(r5)
    fsubs   f1,f2,f1
    fmuls   f1,f7,f1
    fmuls   f0,f0,f1
    fadds   f0,f2,f0
    stfs    f0,0(r8)
    blr
.size GXProject, . - GXProject

#
# === mtx.o (mtx.a) ===
#

.global C_MTXConcat
.balign 4
C_MTXConcat:
/* 0x8037203C | size=0x2A8 (680 bytes) */
    mflr    r0
    stw     r0,4(r1)
    stwu    r1,-72(r1)
    cmplw   r5,r3
    beq-	.L_80372058
    cmplw   r5,r4
    bne-	.L_80372060
.L_80372058:
    addi    r6,r1,20
    b	.L_80372064
.L_80372060:
    mr      r6,r5
.L_80372064:
    lfs     f3,0(r3)
    lfs     f2,0(r4)
    lfs     f1,4(r3)
    lfs     f0,16(r4)
    fmuls   f2,f3,f2
    lfs     f3,8(r3)
    fmuls   f0,f1,f0
    lfs     f1,32(r4)
    fmuls   f1,f3,f1
    fadds   f0,f2,f0
    fadds   f0,f1,f0
    stfs    f0,0(r6)
    lfs     f3,0(r3)
    lfs     f2,4(r4)
    lfs     f1,4(r3)
    lfs     f0,20(r4)
    fmuls   f2,f3,f2
    lfs     f3,8(r3)
    fmuls   f0,f1,f0
    lfs     f1,36(r4)
    fmuls   f1,f3,f1
    fadds   f0,f2,f0
    fadds   f0,f1,f0
    stfs    f0,4(r6)
    lfs     f3,0(r3)
    lfs     f2,8(r4)
    lfs     f1,4(r3)
    lfs     f0,24(r4)
    fmuls   f2,f3,f2
    lfs     f3,8(r3)
    fmuls   f0,f1,f0
    lfs     f1,40(r4)
    fmuls   f1,f3,f1
    fadds   f0,f2,f0
    fadds   f0,f1,f0
    stfs    f0,8(r6)
    lfs     f3,0(r3)
    lfs     f2,12(r4)
    lfs     f1,4(r3)
    lfs     f0,28(r4)
    fmuls   f2,f3,f2
    lfs     f3,8(r3)
    fmuls   f0,f1,f0
    lfs     f1,44(r4)
    lfs     f4,12(r3)
    fmuls   f1,f3,f1
    fadds   f0,f2,f0
    fadds   f0,f1,f0
    fadds   f0,f4,f0
    stfs    f0,12(r6)
    lfs     f3,16(r3)
    lfs     f2,0(r4)
    lfs     f1,20(r3)
    lfs     f0,16(r4)
    fmuls   f2,f3,f2
    lfs     f3,24(r3)
    fmuls   f0,f1,f0
    lfs     f1,32(r4)
    fmuls   f1,f3,f1
    fadds   f0,f2,f0
    fadds   f0,f1,f0
    stfs    f0,16(r6)
    lfs     f3,16(r3)
    lfs     f2,4(r4)
    lfs     f1,20(r3)
    lfs     f0,20(r4)
    fmuls   f2,f3,f2
    lfs     f3,24(r3)
    fmuls   f0,f1,f0
    lfs     f1,36(r4)
    fmuls   f1,f3,f1
    fadds   f0,f2,f0
    fadds   f0,f1,f0
    stfs    f0,20(r6)
    lfs     f3,16(r3)
    lfs     f2,8(r4)
    lfs     f1,20(r3)
    lfs     f0,24(r4)
    fmuls   f2,f3,f2
    lfs     f3,24(r3)
    fmuls   f0,f1,f0
    lfs     f1,40(r4)
    fmuls   f1,f3,f1
    fadds   f0,f2,f0
    fadds   f0,f1,f0
    stfs    f0,24(r6)
    lfs     f3,16(r3)
    lfs     f2,12(r4)
    lfs     f1,20(r3)
    lfs     f0,28(r4)
    fmuls   f2,f3,f2
    lfs     f3,24(r3)
    fmuls   f0,f1,f0
    lfs     f1,44(r4)
    lfs     f4,28(r3)
    fmuls   f1,f3,f1
    fadds   f0,f2,f0
    fadds   f0,f1,f0
    fadds   f0,f4,f0
    stfs    f0,28(r6)
    lfs     f3,32(r3)
    lfs     f2,0(r4)
    lfs     f1,36(r3)
    lfs     f0,16(r4)
    fmuls   f2,f3,f2
    lfs     f3,40(r3)
    fmuls   f0,f1,f0
    lfs     f1,32(r4)
    fmuls   f1,f3,f1
    fadds   f0,f2,f0
    fadds   f0,f1,f0
    stfs    f0,32(r6)
    lfs     f3,32(r3)
    addi    r0,r1,20
    lfs     f2,4(r4)
    cmplw   r6,r0
    lfs     f1,36(r3)
    lfs     f0,20(r4)
    fmuls   f2,f3,f2
    lfs     f3,40(r3)
    fmuls   f0,f1,f0
    lfs     f1,36(r4)
    fmuls   f1,f3,f1
    fadds   f0,f2,f0
    fadds   f0,f1,f0
    stfs    f0,36(r6)
    lfs     f3,32(r3)
    lfs     f2,8(r4)
    lfs     f1,36(r3)
    lfs     f0,24(r4)
    fmuls   f2,f3,f2
    lfs     f3,40(r3)
    fmuls   f0,f1,f0
    lfs     f1,40(r4)
    fmuls   f1,f3,f1
    fadds   f0,f2,f0
    fadds   f0,f1,f0
    stfs    f0,40(r6)
    lfs     f3,32(r3)
    lfs     f2,12(r4)
    lfs     f1,36(r3)
    lfs     f0,28(r4)
    fmuls   f2,f3,f2
    lfs     f3,40(r3)
    fmuls   f0,f1,f0
    lfs     f1,44(r4)
    lfs     f4,44(r3)
    fmuls   f1,f3,f1
    fadds   f0,f2,f0
    fadds   f0,f1,f0
    fadds   f0,f4,f0
    stfs    f0,44(r6)
    bne-	.L_803722D4
    mr      r3,r0
    mr      r4,r5
    bl	C_MTXCopy
.L_803722D4:
    lwz     r0,76(r1)
    addi    r1,r1,72
    mtlr    r0
    blr
.size C_MTXConcat, . - C_MTXConcat

.global PSMTXConcatArray
.balign 4
PSMTXConcatArray:
/* 0x80372418 | size=0x158 (344 bytes) */
    stwu    r1,-32(r1)
    stfd    f31,24(r1)
    addi    r7,r13,-25392
    psq_l   f0,0(r3),0,0
    psq_l   f1,8(r3),0,0
    psq_l   f2,16(r3),0,0
    psq_l   f3,24(r3),0,0
    addi    r0,r6,-1
    psq_l   f4,32(r3),0,0
    psq_l   f5,40(r3),0,0
    mtctr   r0
    psq_l   f31,0(r7),0,0
    psq_l   f6,0(r4),0,0
    psq_l   f7,16(r4),0,0
    ps_muls0 f9,f6,f0
    ps_muls0 f10,f6,f2
    ps_muls0 f12,f6,f4
    psq_l   f8,32(r4),0,0
    ps_madds1 f9,f7,f0,f9
    ps_madds1 f10,f7,f2,f10
    ps_madds1 f12,f7,f4,f12
    psq_l   f6,8(r4),0,0
    ps_madds0 f9,f8,f1,f9
    ps_madds0 f10,f8,f3,f10
    ps_madds0 f12,f8,f5,f12
    psq_l   f7,24(r4),0,0
    psq_st  f9,0(r5),0,0
    ps_muls0 f8,f6,f0
    ps_muls0 f11,f6,f2
    ps_muls0 f13,f6,f4
    psq_l   f6,40(r4),0,0
    psq_st  f10,16(r5),0,0
    ps_madds1 f8,f7,f0,f8
    ps_madds1 f11,f7,f2,f11
    ps_madds1 f13,f7,f4,f13
    b	.L_803724A8
.L_803724A8:
    b	.L_803724AC
.L_803724AC:
    addi    r4,r4,48
    ps_madds0 f8,f6,f1,f8
    ps_madds0 f11,f6,f3,f11
    ps_madds0 f13,f6,f5,f13
    psq_l   f6,0(r4),0,0
    psq_st  f12,32(r5),0,0
    ps_madd f8,f31,f1,f8
    ps_madd f11,f31,f3,f11
    ps_madd f13,f31,f5,f13
    psq_l   f7,16(r4),0,0
    psq_st  f8,8(r5),0,0
    ps_muls0 f9,f6,f0
    ps_muls0 f10,f6,f2
    ps_muls0 f12,f6,f4
    psq_l   f8,32(r4),0,0
    psq_st  f11,24(r5),0,0
    ps_madds1 f9,f7,f0,f9
    ps_madds1 f10,f7,f2,f10
    ps_madds1 f12,f7,f4,f12
    psq_l   f6,8(r4),0,0
    psq_st  f13,40(r5),0,0
    addi    r5,r5,48
    ps_madds0 f9,f8,f1,f9
    ps_madds0 f10,f8,f3,f10
    ps_madds0 f12,f8,f5,f12
    psq_l   f7,24(r4),0,0
    psq_st  f9,0(r5),0,0
    ps_muls0 f8,f6,f0
    ps_muls0 f11,f6,f2
    ps_muls0 f13,f6,f4
    psq_l   f6,40(r4),0,0
    psq_st  f10,16(r5),0,0
    ps_madds1 f8,f7,f0,f8
    ps_madds1 f11,f7,f2,f11
    ps_madds1 f13,f7,f4,f13
    bdnz+	.L_803724AC
    psq_st  f12,32(r5),0,0
    ps_madds0 f8,f6,f1,f8
    ps_madds0 f11,f6,f3,f11
    ps_madds0 f13,f6,f5,f13
    ps_madd f8,f31,f1,f8
    ps_madd f11,f31,f3,f11
    ps_madd f13,f31,f5,f13
    psq_st  f8,8(r5),0,0
    psq_st  f11,24(r5),0,0
    psq_st  f13,40(r5),0,0
    lfd     f31,24(r1)
    addi    r1,r1,32
    blr
.size PSMTXConcatArray, . - PSMTXConcatArray

.global C_MTXInverse
.balign 4
C_MTXInverse:
/* 0x8037265C | size=0x2AC (684 bytes) */
    mflr    r0
    stw     r0,4(r1)
    stwu    r1,-64(r1)
    cmplw   r3,r4
    bne-	.L_80372678
    addi    r5,r1,16
    b	.L_8037267C
.L_80372678:
    mr      r5,r4
.L_8037267C:
    lfs     f11,0(r3)
    lfs     f6,20(r3)
    lfs     f12,24(r3)
    lfs     f5,4(r3)
    fmuls   f1,f11,f6
    lfs     f8,16(r3)
    lfs     f9,40(r3)
    fmuls   f0,f5,f12
    lfs     f2,32(r3)
    lfs     f7,8(r3)
    fmuls   f4,f9,f1
    fmuls   f1,f2,f0
    lfs     f10,36(r3)
    fmuls   f0,f7,f8
    fmuls   f3,f2,f6
    fmuls   f2,f8,f5
    fmuls   f5,f10,f0
    lfs     f0,-17964(r13)
    fadds   f4,f4,f1
    fmuls   f1,f11,f10
    fmuls   f3,f7,f3
    fadds   f4,f5,f4
    fmuls   f2,f9,f2
    fmuls   f1,f12,f1
    fsubs   f3,f4,f3
    fsubs   f2,f3,f2
    fsubs   f3,f2,f1
    fcmpu   cr0,f0,f3
    bne-	.L_803726F8
    li      r3,0
    b	.L_803728F8
.L_803726F8:
    lfs     f0,-17968(r13)
    fmuls   f2,f6,f9
    fmuls   f1,f10,f12
    fdivs   f0,f0,f3
    fsubs   f1,f2,f1
    fmuls   f1,f0,f1
    stfs    f1,0(r5)
    lfs     f4,4(r3)
    lfs     f3,40(r3)
    lfs     f2,36(r3)
    lfs     f1,8(r3)
    fmuls   f3,f4,f3
    fmuls   f1,f2,f1
    fsubs   f1,f3,f1
    fneg    f1,f1
    fmuls   f1,f0,f1
    stfs    f1,4(r5)
    lfs     f4,4(r3)
    lfs     f3,24(r3)
    lfs     f2,20(r3)
    lfs     f1,8(r3)
    fmuls   f3,f4,f3
    fmuls   f1,f2,f1
    fsubs   f1,f3,f1
    fmuls   f1,f0,f1
    stfs    f1,8(r5)
    lfs     f4,16(r3)
    lfs     f3,40(r3)
    lfs     f2,32(r3)
    lfs     f1,24(r3)
    fmuls   f3,f4,f3
    fmuls   f1,f2,f1
    fsubs   f1,f3,f1
    fneg    f1,f1
    fmuls   f1,f0,f1
    stfs    f1,16(r5)
    lfs     f4,0(r3)
    lfs     f3,40(r3)
    lfs     f2,32(r3)
    lfs     f1,8(r3)
    fmuls   f3,f4,f3
    fmuls   f1,f2,f1
    fsubs   f1,f3,f1
    fmuls   f1,f0,f1
    stfs    f1,20(r5)
    lfs     f4,0(r3)
    lfs     f3,24(r3)
    lfs     f2,16(r3)
    lfs     f1,8(r3)
    fmuls   f3,f4,f3
    fmuls   f1,f2,f1
    fsubs   f1,f3,f1
    fneg    f1,f1
    fmuls   f1,f0,f1
    stfs    f1,24(r5)
    lfs     f4,16(r3)
    lfs     f3,36(r3)
    lfs     f2,32(r3)
    lfs     f1,20(r3)
    fmuls   f3,f4,f3
    fmuls   f1,f2,f1
    fsubs   f1,f3,f1
    fmuls   f1,f0,f1
    stfs    f1,32(r5)
    lfs     f4,0(r3)
    lfs     f3,36(r3)
    lfs     f2,32(r3)
    lfs     f1,4(r3)
    fmuls   f3,f4,f3
    fmuls   f1,f2,f1
    fsubs   f1,f3,f1
    fneg    f1,f1
    fmuls   f1,f0,f1
    stfs    f1,36(r5)
    lfs     f4,0(r3)
    lfs     f3,20(r3)
    lfs     f2,16(r3)
    lfs     f1,4(r3)
    fmuls   f3,f4,f3
    fmuls   f1,f2,f1
    fsubs   f1,f3,f1
    fmuls   f0,f0,f1
    stfs    f0,40(r5)
    lfs     f0,0(r5)
    lfs     f4,12(r3)
    fneg    f5,f0
    lfs     f3,4(r5)
    lfs     f2,28(r3)
    lfs     f1,8(r5)
    lfs     f0,44(r3)
    fmuls   f4,f5,f4
    fmuls   f2,f3,f2
    fmuls   f0,f1,f0
    fsubs   f1,f4,f2
    fsubs   f0,f1,f0
    stfs    f0,12(r5)
    lfs     f0,16(r5)
    lfs     f4,12(r3)
    fneg    f5,f0
    lfs     f3,20(r5)
    lfs     f2,28(r3)
    lfs     f1,24(r5)
    lfs     f0,44(r3)
    fmuls   f4,f5,f4
    fmuls   f2,f3,f2
    fmuls   f0,f1,f0
    fsubs   f1,f4,f2
    fsubs   f0,f1,f0
    stfs    f0,28(r5)
    lfs     f0,32(r5)
    addi    r0,r1,16
    lfs     f1,12(r3)
    cmplw   r5,r0
    fneg    f3,f0
    lfs     f2,36(r5)
    lfs     f0,28(r3)
    fmuls   f3,f3,f1
    lfs     f1,40(r5)
    fmuls   f2,f2,f0
    lfs     f0,44(r3)
    fmuls   f0,f1,f0
    fsubs   f1,f3,f2
    fsubs   f0,f1,f0
    stfs    f0,44(r5)
    bne-	.L_803728F4
    mr      r3,r0
    bl	C_MTXCopy
.L_803728F4:
    li      r3,1
.L_803728F8:
    lwz     r0,68(r1)
    addi    r1,r1,64
    mtlr    r0
    blr
.size C_MTXInverse, . - C_MTXInverse

.global C_MTXInvXpose
.balign 4
C_MTXInvXpose:
/* 0x80372A00 | size=0x21C (540 bytes) */
    mflr    r0
    stw     r0,4(r1)
    stwu    r1,-64(r1)
    cmplw   r3,r4
    bne-	.L_80372A1C
    addi    r5,r1,16
    b	.L_80372A20
.L_80372A1C:
    mr      r5,r4
.L_80372A20:
    lfs     f11,0(r3)
    lfs     f6,20(r3)
    lfs     f12,24(r3)
    lfs     f5,4(r3)
    fmuls   f1,f11,f6
    lfs     f8,16(r3)
    lfs     f9,40(r3)
    fmuls   f0,f5,f12
    lfs     f2,32(r3)
    lfs     f7,8(r3)
    fmuls   f4,f9,f1
    fmuls   f1,f2,f0
    lfs     f10,36(r3)
    fmuls   f0,f7,f8
    fmuls   f3,f2,f6
    fmuls   f2,f8,f5
    fmuls   f5,f10,f0
    lfs     f0,-17964(r13)
    fadds   f4,f4,f1
    fmuls   f1,f11,f10
    fmuls   f3,f7,f3
    fadds   f4,f5,f4
    fmuls   f2,f9,f2
    fmuls   f1,f12,f1
    fsubs   f3,f4,f3
    fsubs   f2,f3,f2
    fsubs   f2,f2,f1
    fcmpu   cr0,f0,f2
    bne-	.L_80372A9C
    li      r3,0
    b	.L_80372C0C
.L_80372A9C:
    lfs     f1,-17968(r13)
    addi    r0,r1,16
    fmuls   f3,f6,f9
    cmplw   r5,r0
    fdivs   f1,f1,f2
    fmuls   f2,f10,f12
    fsubs   f2,f3,f2
    fmuls   f2,f1,f2
    stfs    f2,0(r5)
    lfs     f5,16(r3)
    lfs     f4,40(r3)
    lfs     f3,32(r3)
    lfs     f2,24(r3)
    fmuls   f4,f5,f4
    fmuls   f2,f3,f2
    fsubs   f2,f4,f2
    fneg    f2,f2
    fmuls   f2,f1,f2
    stfs    f2,4(r5)
    lfs     f5,16(r3)
    lfs     f4,36(r3)
    lfs     f3,32(r3)
    lfs     f2,20(r3)
    fmuls   f4,f5,f4
    fmuls   f2,f3,f2
    fsubs   f2,f4,f2
    fmuls   f2,f1,f2
    stfs    f2,8(r5)
    lfs     f5,4(r3)
    lfs     f4,40(r3)
    lfs     f3,36(r3)
    lfs     f2,8(r3)
    fmuls   f4,f5,f4
    fmuls   f2,f3,f2
    fsubs   f2,f4,f2
    fneg    f2,f2
    fmuls   f2,f1,f2
    stfs    f2,16(r5)
    lfs     f5,0(r3)
    lfs     f4,40(r3)
    lfs     f3,32(r3)
    lfs     f2,8(r3)
    fmuls   f4,f5,f4
    fmuls   f2,f3,f2
    fsubs   f2,f4,f2
    fmuls   f2,f1,f2
    stfs    f2,20(r5)
    lfs     f5,0(r3)
    lfs     f4,36(r3)
    lfs     f3,32(r3)
    lfs     f2,4(r3)
    fmuls   f4,f5,f4
    fmuls   f2,f3,f2
    fsubs   f2,f4,f2
    fneg    f2,f2
    fmuls   f2,f1,f2
    stfs    f2,24(r5)
    lfs     f5,4(r3)
    lfs     f4,24(r3)
    lfs     f3,20(r3)
    lfs     f2,8(r3)
    fmuls   f4,f5,f4
    fmuls   f2,f3,f2
    fsubs   f2,f4,f2
    fmuls   f2,f1,f2
    stfs    f2,32(r5)
    lfs     f5,0(r3)
    lfs     f4,24(r3)
    lfs     f3,16(r3)
    lfs     f2,8(r3)
    fmuls   f4,f5,f4
    fmuls   f2,f3,f2
    fsubs   f2,f4,f2
    fneg    f2,f2
    fmuls   f2,f1,f2
    stfs    f2,36(r5)
    lfs     f5,0(r3)
    lfs     f4,20(r3)
    lfs     f3,16(r3)
    lfs     f2,4(r3)
    fmuls   f4,f5,f4
    fmuls   f2,f3,f2
    fsubs   f2,f4,f2
    fmuls   f1,f1,f2
    stfs    f1,40(r5)
    stfs    f0,12(r5)
    stfs    f0,28(r5)
    stfs    f0,44(r5)
    bne-	.L_80372C08
    mr      r3,r0
    bl	C_MTXCopy
.L_80372C08:
    li      r3,1
.L_80372C0C:
    lwz     r0,68(r1)
    addi    r1,r1,64
    mtlr    r0
    blr
.size C_MTXInvXpose, . - C_MTXInvXpose

.global C_MTXRotTrig
.balign 4
C_MTXRotTrig:
/* 0x80372DC4 | size=0x104 (260 bytes) */
    extsb   r0,r4
    cmpwi   r0,120
    beq-	.L_80372E08
    bge-	.L_80372DF8
    cmpwi   r0,89
    beq-	.L_80372E48
    bge-	.L_80372DEC
    cmpwi   r0,88
    bge-	.L_80372E08
    b	.L_80372EC4
.L_80372DEC:
    cmpwi   r0,91
    bge-	.L_80372EC4
    b	.L_80372E88
.L_80372DF8:
    cmpwi   r0,122
    beq-	.L_80372E88
    bge-	.L_80372EC4
    b	.L_80372E48
.L_80372E08:
    lfs     f3,-17968(r13)
    fneg    f0,f1
    stfs    f3,0(r3)
    lfs     f3,-17964(r13)
    stfs    f3,4(r3)
    stfs    f3,8(r3)
    stfs    f3,12(r3)
    stfs    f3,16(r3)
    stfs    f2,20(r3)
    stfs    f0,24(r3)
    stfs    f3,28(r3)
    stfs    f3,32(r3)
    stfs    f1,36(r3)
    stfs    f2,40(r3)
    stfs    f3,44(r3)
    b	.L_80372EC4
.L_80372E48:
    stfs    f2,0(r3)
    fneg    f0,f1
    lfs     f3,-17964(r13)
    stfs    f3,4(r3)
    stfs    f1,8(r3)
    stfs    f3,12(r3)
    stfs    f3,16(r3)
    lfs     f1,-17968(r13)
    stfs    f1,20(r3)
    stfs    f3,24(r3)
    stfs    f3,28(r3)
    stfs    f0,32(r3)
    stfs    f3,36(r3)
    stfs    f2,40(r3)
    stfs    f3,44(r3)
    b	.L_80372EC4
.L_80372E88:
    fneg    f0,f1
    stfs    f2,0(r3)
    stfs    f0,4(r3)
    lfs     f3,-17964(r13)
    stfs    f3,8(r3)
    stfs    f3,12(r3)
    stfs    f1,16(r3)
    stfs    f2,20(r3)
    stfs    f3,24(r3)
    stfs    f3,28(r3)
    stfs    f3,32(r3)
    stfs    f3,36(r3)
    lfs     f0,-17968(r13)
    stfs    f0,40(r3)
    stfs    f3,44(r3)
.L_80372EC4:
    blr
.size C_MTXRotTrig, . - C_MTXRotTrig

.global C_MTXRotAxisRad
.balign 4
C_MTXRotAxisRad:
/* 0x80372F78 | size=0x118 (280 bytes) */
    mflr    r0
    stw     r0,4(r1)
    stwu    r1,-80(r1)
    stfd    f31,72(r1)
    stfd    f30,64(r1)
    stfd    f29,56(r1)
    stw     r31,52(r1)
    stw     r30,48(r1)
    fmr     f30,f1
    mr      r30,r3
    mr      r31,r4
    fmr     f1,f30
    bl	sinf
    fmr     f29,f1
    fmr     f1,f30
    bl	cosf
    fmr     f31,f1
    lfs     f0,-17968(r13)
    mr      r3,r31
    addi    r4,r1,32
    fsubs   f30,f0,f31
    bl	C_VECNormalize
    lfs     f6,32(r1)
    lfs     f4,36(r1)
    fmuls   f1,f6,f6
    lfs     f10,40(r1)
    fmuls   f3,f30,f6
    fmuls   f0,f4,f4
    fmuls   f2,f30,f1
    fmuls   f1,f30,f4
    fmuls   f7,f4,f3
    fmuls   f5,f29,f10
    fadds   f2,f31,f2
    fmuls   f9,f10,f3
    fmuls   f8,f29,f4
    fsubs   f4,f7,f5
    stfs    f2,0(r30)
    fmuls   f2,f30,f0
    fadds   f3,f9,f8
    stfs    f4,4(r30)
    fmuls   f0,f10,f10
    stfs    f3,8(r30)
    fadds   f5,f7,f5
    fmuls   f7,f10,f1
    fmuls   f1,f29,f6
    lfs     f6,-17964(r13)
    fadds   f4,f31,f2
    fmuls   f0,f30,f0
    stfs    f6,12(r30)
    fsubs   f3,f7,f1
    stfs    f5,16(r30)
    fsubs   f2,f9,f8
    fadds   f1,f7,f1
    stfs    f4,20(r30)
    fadds   f0,f31,f0
    stfs    f3,24(r30)
    stfs    f6,28(r30)
    stfs    f2,32(r30)
    stfs    f1,36(r30)
    stfs    f0,40(r30)
    stfs    f6,44(r30)
    lwz     r0,84(r1)
    lfd     f31,72(r1)
    lfd     f30,64(r1)
    lfd     f29,56(r1)
    lwz     r31,52(r1)
    lwz     r30,48(r1)
    addi    r1,r1,80
    mtlr    r0
    blr
.size C_MTXRotAxisRad, . - C_MTXRotAxisRad

.global C_MTXLookAt
.balign 4
C_MTXLookAt:
/* 0x80373734 | size=0x18C (396 bytes) */
    mflr    r0
    stw     r0,4(r1)
    stwu    r1,-80(r1)
    stw     r31,76(r1)
    stw     r30,72(r1)
    stw     r29,68(r1)
    mr      r29,r3
    mr      r30,r4
    mr      r31,r5
    lfs     f1,0(r30)
    addi    r3,r1,48
    lfs     f0,0(r6)
    mr      r4,r3
    fsubs   f0,f1,f0
    stfs    f0,48(r1)
    lfs     f1,4(r30)
    lfs     f0,4(r6)
    fsubs   f0,f1,f0
    stfs    f0,52(r1)
    lfs     f1,8(r30)
    lfs     f0,8(r6)
    fsubs   f0,f1,f0
    stfs    f0,56(r1)
    bl	PSVECNormalize
    mr      r3,r31
    addi    r4,r1,48
    addi    r5,r1,36
    bl	PSVECCrossProduct
    addi    r3,r1,36
    mr      r4,r3
    bl	PSVECNormalize
    addi    r3,r1,48
    addi    r4,r1,36
    addi    r5,r1,24
    bl	PSVECCrossProduct
    lfs     f0,36(r1)
    stfs    f0,0(r29)
    lfs     f0,40(r1)
    stfs    f0,4(r29)
    lfs     f0,44(r1)
    stfs    f0,8(r29)
    lfs     f3,0(r30)
    lfs     f2,36(r1)
    lfs     f1,4(r30)
    lfs     f0,40(r1)
    fmuls   f2,f3,f2
    lfs     f3,8(r30)
    fmuls   f0,f1,f0
    lfs     f1,44(r1)
    fmuls   f1,f3,f1
    fadds   f0,f2,f0
    fadds   f0,f1,f0
    fneg    f0,f0
    stfs    f0,12(r29)
    lfs     f0,24(r1)
    stfs    f0,16(r29)
    lfs     f0,28(r1)
    stfs    f0,20(r29)
    lfs     f0,32(r1)
    stfs    f0,24(r29)
    lfs     f3,0(r30)
    lfs     f2,24(r1)
    lfs     f1,4(r30)
    lfs     f0,28(r1)
    fmuls   f2,f3,f2
    lfs     f3,8(r30)
    fmuls   f0,f1,f0
    lfs     f1,32(r1)
    fmuls   f1,f3,f1
    fadds   f0,f2,f0
    fadds   f0,f1,f0
    fneg    f0,f0
    stfs    f0,28(r29)
    lfs     f0,48(r1)
    stfs    f0,32(r29)
    lfs     f0,52(r1)
    stfs    f0,36(r29)
    lfs     f0,56(r1)
    stfs    f0,40(r29)
    lfs     f3,0(r30)
    lfs     f2,48(r1)
    lfs     f1,4(r30)
    lfs     f0,52(r1)
    fmuls   f2,f3,f2
    lfs     f3,8(r30)
    fmuls   f0,f1,f0
    lfs     f1,56(r1)
    fmuls   f1,f3,f1
    fadds   f0,f2,f0
    fadds   f0,f1,f0
    fneg    f0,f0
    stfs    f0,44(r29)
    lwz     r0,84(r1)
    lwz     r31,76(r1)
    lwz     r30,72(r1)
    lwz     r29,68(r1)
    addi    r1,r1,80
    mtlr    r0
    blr
.size C_MTXLookAt, . - C_MTXLookAt

#
# === mtx44.o (mtx.a) ===
#

.global PSMTX44Concat
.balign 4
PSMTX44Concat:
/* 0x803748D8 | size=0x104 (260 bytes) */
    psq_l   f0,0(r3),0,0
    psq_l   f2,0(r4),0,0
    ps_muls0 f6,f2,f0
    psq_l   f3,16(r4),0,0
    psq_l   f4,32(r4),0,0
    ps_madds1 f6,f3,f0,f6
    psq_l   f1,8(r3),0,0
    psq_l   f5,48(r4),0,0
    ps_madds0 f6,f4,f1,f6
    psq_l   f0,16(r3),0,0
    ps_madds1 f6,f5,f1,f6
    psq_l   f1,24(r3),0,0
    ps_muls0 f8,f2,f0
    ps_madds1 f8,f3,f0,f8
    psq_l   f0,32(r3),0,0
    ps_madds0 f8,f4,f1,f8
    ps_madds1 f8,f5,f1,f8
    psq_l   f1,40(r3),0,0
    ps_muls0 f10,f2,f0
    ps_madds1 f10,f3,f0,f10
    psq_l   f0,48(r3),0,0
    ps_madds0 f10,f4,f1,f10
    ps_madds1 f10,f5,f1,f10
    psq_l   f1,56(r3),0,0
    ps_muls0 f12,f2,f0
    psq_l   f2,8(r4),0,0
    ps_madds1 f12,f3,f0,f12
    psq_l   f0,0(r3),0,0
    ps_madds0 f12,f4,f1,f12
    psq_l   f3,24(r4),0,0
    ps_madds1 f12,f5,f1,f12
    psq_l   f1,8(r3),0,0
    ps_muls0 f7,f2,f0
    psq_l   f4,40(r4),0,0
    ps_madds1 f7,f3,f0,f7
    psq_l   f5,56(r4),0,0
    ps_madds0 f7,f4,f1,f7
    psq_l   f0,16(r3),0,0
    ps_madds1 f7,f5,f1,f7
    psq_l   f1,24(r3),0,0
    ps_muls0 f9,f2,f0
    psq_st  f6,0(r5),0,0
    ps_madds1 f9,f3,f0,f9
    psq_l   f0,32(r3),0,0
    ps_madds0 f9,f4,f1,f9
    psq_st  f8,16(r5),0,0
    ps_madds1 f9,f5,f1,f9
    psq_l   f1,40(r3),0,0
    ps_muls0 f11,f2,f0
    psq_st  f10,32(r5),0,0
    ps_madds1 f11,f3,f0,f11
    psq_l   f0,48(r3),0,0
    ps_madds0 f11,f4,f1,f11
    psq_st  f12,48(r5),0,0
    ps_madds1 f11,f5,f1,f11
    psq_l   f1,56(r3),0,0
    ps_muls0 f13,f2,f0
    psq_st  f7,8(r5),0,0
    ps_madds1 f13,f3,f0,f13
    psq_st  f9,24(r5),0,0
    ps_madds0 f13,f4,f1,f13
    psq_st  f11,40(r5),0,0
    ps_madds1 f13,f5,f1,f13
    psq_st  f13,56(r5),0,0
    blr
.size PSMTX44Concat, . - PSMTX44Concat

.global C_MTX44Inverse
.balign 4
C_MTX44Inverse:
/* 0x80374B04 | size=0x3F0 (1008 bytes) */
    mflr    r0
    stw     r0,4(r1)
    stwu    r1,-88(r1)
    stw     r31,84(r1)
    mr      r31,r4
    addi    r4,r1,16
    bl	PSMTX44Copy
    lfs     f3,-17872(r13)
    lfs     f2,-17864(r13)
    stfs    f3,0(r31)
    psq_st  f2,4(r31),0,0
    psq_st  f2,12(r31),0,0
    stfs    f3,20(r31)
    psq_st  f2,24(r31),0,0
    psq_st  f2,32(r31),0,0
    stfs    f3,40(r31)
    psq_st  f2,44(r31),0,0
    psq_st  f2,52(r31),0,0
    stfs    f3,60(r31)
    li      r8,0
    li      r3,0
    li      r4,0
    b	.L_80374B60
.L_80374B60:
    addi    r7,r1,16
    b	.L_80374B68
.L_80374B68:
    b	.L_80374B6C
.L_80374B6C:
    lfs     f1,-17864(r13)
    mr      r6,r8
    mr      r9,r8
    b	.L_80374B7C
.L_80374B7C:
    subfic  r0,r9,4
    cmpwi   r9,4
    mtctr   r0
    slwi    r5,r9,4
    bge-	.L_80374BBC
    b	.L_80374B94
.L_80374B94:
    add     r0,r5,r4
    lfsx    f0,r7,r0
    fabs    f0,f0
    fcmpo   cr0,f0,f1
    ble-	.L_80374BB0
    fmr     f1,f0
    mr      r6,r9
.L_80374BB0:
    addi    r9,r9,1
    addi    r5,r5,16
    bdnz+	.L_80374B94
.L_80374BBC:
    fcmpu   cr0,f2,f1
    bne-	.L_80374BCC
    li      r3,0
    b	.L_80374EE0
.L_80374BCC:
    cmpw    r6,r8
    beq-	.L_80374C78
    b	.L_80374BD8
.L_80374BD8:
    slwi    r5,r6,4
    b	.L_80374BE0
.L_80374BE0:
    lfsx    f1,r7,r3
    addi    r6,r3,4
    lfsx    f0,r7,r5
    addi    r0,r5,4
    stfsx   f0,r7,r3
    stfsx   f1,r7,r5
    lfsx    f1,r31,r3
    lfsx    f0,r31,r5
    stfsx   f0,r31,r3
    stfsx   f1,r31,r5
    lfsx    f1,r7,r6
    lfsx    f0,r7,r0
    stfsx   f0,r7,r6
    stfsx   f1,r7,r0
    lfsx    f1,r31,r6
    lfsx    f0,r31,r0
    stfsx   f0,r31,r6
    addi    r6,r3,8
    stfsx   f1,r31,r0
    addi    r0,r5,8
    lfsx    f1,r7,r6
    lfsx    f0,r7,r0
    stfsx   f0,r7,r6
    stfsx   f1,r7,r0
    lfsx    f1,r31,r6
    lfsx    f0,r31,r0
    stfsx   f0,r31,r6
    addi    r6,r3,12
    stfsx   f1,r31,r0
    addi    r0,r5,12
    lfsx    f1,r7,r6
    lfsx    f0,r7,r0
    stfsx   f0,r7,r6
    stfsx   f1,r7,r0
    lfsx    f1,r31,r6
    lfsx    f0,r31,r0
    stfsx   f0,r31,r6
    stfsx   f1,r31,r0
.L_80374C78:
    add     r0,r3,r4
    lfsx    f0,r7,r0
    fdivs   f4,f3,f0
    b	.L_80374C88
.L_80374C88:
    b	.L_80374C8C
.L_80374C8C:
    lfsx    f0,r7,r3
    addi    r0,r3,4
    fmuls   f0,f0,f4
    stfsx   f0,r7,r3
    lfsx    f0,r31,r3
    fmuls   f0,f0,f4
    stfsx   f0,r31,r3
    lfsx    f0,r7,r0
    fmuls   f0,f0,f4
    stfsx   f0,r7,r0
    lfsx    f0,r31,r0
    fmuls   f0,f0,f4
    stfsx   f0,r31,r0
    addi    r0,r3,8
    lfsx    f0,r7,r0
    fmuls   f0,f0,f4
    stfsx   f0,r7,r0
    lfsx    f0,r31,r0
    fmuls   f0,f0,f4
    stfsx   f0,r31,r0
    addi    r0,r3,12
    lfsx    f0,r7,r0
    fmuls   f0,f0,f4
    stfsx   f0,r7,r0
    lfsx    f0,r31,r0
    fmuls   f0,f0,f4
    stfsx   f0,r31,r0
    li      r9,0
    li      r5,0
    b	.L_80374D04
.L_80374D04:
    li      r0,2
    mtctr   r0
    b	.L_80374D10
.L_80374D10:
    b	.L_80374D14
.L_80374D14:
    cmpw    r9,r8
    beq-	.L_80374DE4
    add     r0,r5,r4
    lfsx    f4,r7,r0
    b	.L_80374D28
.L_80374D28:
    b	.L_80374D2C
.L_80374D2C:
    lfsx    f0,r7,r3
    addi    r0,r3,4
    lfsx    f1,r7,r5
    addi    r6,r5,4
    fmuls   f0,f4,f0
    fsubs   f0,f1,f0
    stfsx   f0,r7,r5
    lfsx    f0,r31,r3
    lfsx    f1,r31,r5
    fmuls   f0,f4,f0
    fsubs   f0,f1,f0
    stfsx   f0,r31,r5
    lfsx    f0,r7,r0
    lfsx    f1,r7,r6
    fmuls   f0,f4,f0
    fsubs   f0,f1,f0
    stfsx   f0,r7,r6
    lfsx    f0,r31,r0
    addi    r0,r3,8
    lfsx    f1,r31,r6
    fmuls   f0,f4,f0
    fsubs   f0,f1,f0
    stfsx   f0,r31,r6
    addi    r6,r5,8
    lfsx    f0,r7,r0
    lfsx    f1,r7,r6
    fmuls   f0,f4,f0
    fsubs   f0,f1,f0
    stfsx   f0,r7,r6
    lfsx    f0,r31,r0
    addi    r0,r3,12
    lfsx    f1,r31,r6
    fmuls   f0,f4,f0
    fsubs   f0,f1,f0
    stfsx   f0,r31,r6
    addi    r6,r5,12
    lfsx    f0,r7,r0
    lfsx    f1,r7,r6
    fmuls   f0,f4,f0
    fsubs   f0,f1,f0
    stfsx   f0,r7,r6
    lfsx    f0,r31,r0
    lfsx    f1,r31,r6
    fmuls   f0,f4,f0
    fsubs   f0,f1,f0
    stfsx   f0,r31,r6
.L_80374DE4:
    addi    r9,r9,1
    addi    r5,r5,16
    cmpw    r9,r8
    beq-	.L_80374EBC
    add     r0,r5,r4
    lfsx    f4,r7,r0
    b	.L_80374E00
.L_80374E00:
    b	.L_80374E04
.L_80374E04:
    lfsx    f0,r7,r3
    addi    r0,r3,4
    lfsx    f1,r7,r5
    addi    r6,r5,4
    fmuls   f0,f4,f0
    fsubs   f0,f1,f0
    stfsx   f0,r7,r5
    lfsx    f0,r31,r3
    lfsx    f1,r31,r5
    fmuls   f0,f4,f0
    fsubs   f0,f1,f0
    stfsx   f0,r31,r5
    lfsx    f0,r7,r0
    lfsx    f1,r7,r6
    fmuls   f0,f4,f0
    fsubs   f0,f1,f0
    stfsx   f0,r7,r6
    lfsx    f0,r31,r0
    addi    r0,r3,8
    lfsx    f1,r31,r6
    fmuls   f0,f4,f0
    fsubs   f0,f1,f0
    stfsx   f0,r31,r6
    addi    r6,r5,8
    lfsx    f0,r7,r0
    lfsx    f1,r7,r6
    fmuls   f0,f4,f0
    fsubs   f0,f1,f0
    stfsx   f0,r7,r6
    lfsx    f0,r31,r0
    addi    r0,r3,12
    lfsx    f1,r31,r6
    fmuls   f0,f4,f0
    fsubs   f0,f1,f0
    stfsx   f0,r31,r6
    addi    r6,r5,12
    lfsx    f0,r7,r0
    lfsx    f1,r7,r6
    fmuls   f0,f4,f0
    fsubs   f0,f1,f0
    stfsx   f0,r7,r6
    lfsx    f0,r31,r0
    lfsx    f1,r31,r6
    fmuls   f0,f4,f0
    fsubs   f0,f1,f0
    stfsx   f0,r31,r6
.L_80374EBC:
    addi    r9,r9,1
    addi    r5,r5,16
    bdnz+	.L_80374D14
    addi    r8,r8,1
    addi    r3,r3,16
    addi    r4,r4,4
    cmpwi   r8,4
    blt+	.L_80374B6C
    li      r3,1
.L_80374EE0:
    lwz     r0,92(r1)
    lwz     r31,84(r1)
    addi    r1,r1,88
    mtlr    r0
    blr
.size C_MTX44Inverse, . - C_MTX44Inverse

.global C_MTX44RotTrig
.balign 4
C_MTX44RotTrig:
/* 0x803752EC | size=0x11C (284 bytes) */
    ori     r0,r4,32
    extsb   r0,r0
    cmpwi   r0,121
    beq-	.L_80375368
    bge-	.L_8037530C
    cmpwi   r0,120
    bge-	.L_80375318
    b	.L_80375404
.L_8037530C:
    cmpwi   r0,123
    bge-	.L_80375404
    b	.L_803753B8
.L_80375318:
    lfs     f4,-17872(r13)
    fneg    f0,f1
    stfs    f4,0(r3)
    lfs     f3,-17864(r13)
    stfs    f3,4(r3)
    stfs    f3,8(r3)
    stfs    f3,12(r3)
    stfs    f3,16(r3)
    stfs    f2,20(r3)
    stfs    f0,24(r3)
    stfs    f3,28(r3)
    stfs    f3,32(r3)
    stfs    f1,36(r3)
    stfs    f2,40(r3)
    stfs    f3,44(r3)
    stfs    f3,48(r3)
    stfs    f3,52(r3)
    stfs    f3,56(r3)
    stfs    f4,60(r3)
    b	.L_80375404
.L_80375368:
    stfs    f2,0(r3)
    fneg    f0,f1
    lfs     f3,-17864(r13)
    stfs    f3,4(r3)
    stfs    f1,8(r3)
    stfs    f3,12(r3)
    stfs    f3,16(r3)
    lfs     f1,-17872(r13)
    stfs    f1,20(r3)
    stfs    f3,24(r3)
    stfs    f3,28(r3)
    stfs    f0,32(r3)
    stfs    f3,36(r3)
    stfs    f2,40(r3)
    stfs    f3,44(r3)
    stfs    f3,48(r3)
    stfs    f3,52(r3)
    stfs    f3,56(r3)
    stfs    f1,60(r3)
    b	.L_80375404
.L_803753B8:
    fneg    f0,f1
    stfs    f2,0(r3)
    stfs    f0,4(r3)
    lfs     f3,-17864(r13)
    stfs    f3,8(r3)
    stfs    f3,12(r3)
    stfs    f1,16(r3)
    stfs    f2,20(r3)
    stfs    f3,24(r3)
    stfs    f3,28(r3)
    stfs    f3,32(r3)
    stfs    f3,36(r3)
    lfs     f0,-17872(r13)
    stfs    f0,40(r3)
    stfs    f3,44(r3)
    stfs    f3,48(r3)
    stfs    f3,52(r3)
    stfs    f3,56(r3)
    stfs    f0,60(r3)
.L_80375404:
    blr
.size C_MTX44RotTrig, . - C_MTX44RotTrig

.global C_MTX44RotAxisRad
.balign 4
C_MTX44RotAxisRad:
/* 0x803754DC | size=0x12C (300 bytes) */
    mflr    r0
    stw     r0,4(r1)
    stwu    r1,-80(r1)
    stfd    f31,72(r1)
    stfd    f30,64(r1)
    stfd    f29,56(r1)
    stw     r31,52(r1)
    stw     r30,48(r1)
    fmr     f30,f1
    mr      r30,r3
    mr      r31,r4
    fmr     f1,f30
    bl	sinf
    fmr     f29,f1
    fmr     f1,f30
    bl	cosf
    fmr     f31,f1
    lfs     f0,-17872(r13)
    mr      r3,r31
    addi    r4,r1,32
    fsubs   f30,f0,f31
    bl	C_VECNormalize
    lfs     f6,32(r1)
    lfs     f4,36(r1)
    fmuls   f1,f6,f6
    lfs     f10,40(r1)
    fmuls   f3,f30,f6
    fmuls   f0,f4,f4
    fmuls   f2,f30,f1
    fmuls   f1,f30,f4
    fmuls   f7,f4,f3
    fmuls   f5,f29,f10
    fadds   f2,f31,f2
    fmuls   f9,f10,f3
    fmuls   f8,f29,f4
    fsubs   f4,f7,f5
    stfs    f2,0(r30)
    fmuls   f2,f30,f0
    fadds   f3,f9,f8
    stfs    f4,4(r30)
    fmuls   f0,f10,f10
    stfs    f3,8(r30)
    fadds   f5,f7,f5
    fmuls   f7,f10,f1
    fmuls   f1,f29,f6
    lfs     f6,-17864(r13)
    fadds   f4,f31,f2
    fmuls   f0,f30,f0
    stfs    f6,12(r30)
    fsubs   f3,f7,f1
    stfs    f5,16(r30)
    fsubs   f2,f9,f8
    fadds   f1,f7,f1
    stfs    f4,20(r30)
    fadds   f0,f31,f0
    stfs    f3,24(r30)
    stfs    f6,28(r30)
    stfs    f2,32(r30)
    stfs    f1,36(r30)
    stfs    f0,40(r30)
    stfs    f6,44(r30)
    stfs    f6,48(r30)
    stfs    f6,52(r30)
    stfs    f6,56(r30)
    lfs     f0,-17872(r13)
    stfs    f0,60(r30)
    lwz     r0,84(r1)
    lfd     f31,72(r1)
    lfd     f30,64(r1)
    lfd     f29,56(r1)
    lwz     r31,52(r1)
    lwz     r30,48(r1)
    addi    r1,r1,80
    mtlr    r0
    blr
.size C_MTX44RotAxisRad, . - C_MTX44RotAxisRad

#
# === mtxvec.o (mtx.a) ===
#

.global C_MTXMultVecArray
.balign 4
C_MTXMultVecArray:
/* 0x80373B90 | size=0x204 (516 bytes) */
    b	.L_80373B94
.L_80373B94:
    cmplwi  r6,0
    ble-	.L_80373D90
    srwi    r0,r6,1
    cmplwi  r0,0
    mtctr   r0
    beq-	.L_80373CEC
    b	.L_80373BB0
.L_80373BB0:
    lfs     f10,0(r4)
    lfs     f0,0(r3)
    lfs     f2,16(r3)
    lfs     f9,4(r4)
    fmuls   f1,f0,f10
    lfs     f0,4(r3)
    fmuls   f8,f2,f10
    lfs     f3,20(r3)
    fmuls   f0,f0,f9
    lfs     f11,8(r4)
    fmuls   f7,f3,f9
    lfs     f2,8(r3)
    addi    r4,r4,12
    lfs     f4,32(r3)
    fmuls   f2,f2,f11
    lfs     f3,36(r3)
    fadds   f0,f1,f0
    lfs     f6,24(r3)
    lfs     f5,40(r3)
    fmuls   f4,f4,f10
    lfs     f1,12(r3)
    fmuls   f3,f3,f9
    lfs     f10,28(r3)
    fadds   f0,f2,f0
    fmuls   f9,f6,f11
    lfs     f6,44(r3)
    fadds   f7,f8,f7
    fadds   f0,f1,f0
    fmuls   f5,f5,f11
    fadds   f2,f4,f3
    fadds   f3,f9,f7
    stfs    f0,0(r5)
    fadds   f1,f5,f2
    fadds   f2,f10,f3
    fadds   f0,f6,f1
    stfs    f2,4(r5)
    stfs    f0,8(r5)
    addi    r5,r5,12
    lfs     f10,0(r4)
    lfs     f0,0(r3)
    lfs     f2,16(r3)
    lfs     f4,32(r3)
    fmuls   f1,f0,f10
    lfs     f9,4(r4)
    fmuls   f8,f2,f10
    lfs     f0,4(r3)
    lfs     f3,20(r3)
    fmuls   f0,f0,f9
    lfs     f11,8(r4)
    lfs     f2,8(r3)
    fmuls   f7,f3,f9
    lfs     f3,36(r3)
    lfs     f6,24(r3)
    fmuls   f2,f2,f11
    fadds   f0,f1,f0
    lfs     f5,40(r3)
    fmuls   f4,f4,f10
    fmuls   f3,f3,f9
    fmuls   f9,f6,f11
    fadds   f7,f8,f7
    lfs     f1,12(r3)
    fadds   f0,f2,f0
    fmuls   f5,f5,f11
    fadds   f2,f4,f3
    fadds   f3,f9,f7
    lfs     f10,28(r3)
    fadds   f0,f1,f0
    lfs     f6,44(r3)
    fadds   f1,f5,f2
    fadds   f2,f10,f3
    stfs    f0,0(r5)
    addi    r4,r4,12
    fadds   f0,f6,f1
    stfs    f2,4(r5)
    stfs    f0,8(r5)
    addi    r5,r5,12
    bdnz+	.L_80373BB0
    andi.   r6,r6,1
    beq-	.L_80373D90
.L_80373CEC:
    mtctr   r6
    b	.L_80373CF4
.L_80373CF4:
    lfs     f10,0(r4)
    lfs     f0,0(r3)
    lfs     f2,16(r3)
    lfs     f9,4(r4)
    fmuls   f1,f0,f10
    lfs     f0,4(r3)
    fmuls   f8,f2,f10
    lfs     f3,20(r3)
    fmuls   f0,f0,f9
    lfs     f11,8(r4)
    fmuls   f7,f3,f9
    lfs     f2,8(r3)
    addi    r4,r4,12
    lfs     f4,32(r3)
    fmuls   f2,f2,f11
    lfs     f3,36(r3)
    fadds   f0,f1,f0
    lfs     f6,24(r3)
    lfs     f5,40(r3)
    fmuls   f4,f4,f10
    lfs     f1,12(r3)
    fmuls   f3,f3,f9
    lfs     f10,28(r3)
    fadds   f0,f2,f0
    fmuls   f9,f6,f11
    lfs     f6,44(r3)
    fadds   f7,f8,f7
    fadds   f0,f1,f0
    fmuls   f5,f5,f11
    fadds   f2,f4,f3
    fadds   f3,f9,f7
    stfs    f0,0(r5)
    fadds   f1,f5,f2
    fadds   f2,f10,f3
    fadds   f0,f6,f1
    stfs    f2,4(r5)
    stfs    f0,8(r5)
    addi    r5,r5,12
    bdnz+	.L_80373CF4
.L_80373D90:
    blr
.size C_MTXMultVecArray, . - C_MTXMultVecArray

.global C_MTXMultVecArraySR
.balign 4
C_MTXMultVecArraySR:
/* 0x80373EF0 | size=0x1BC (444 bytes) */
    b	.L_80373EF4
.L_80373EF4:
    cmplwi  r6,0
    ble-	.L_803740A8
    srwi    r0,r6,1
    cmplwi  r0,0
    mtctr   r0
    beq-	.L_8037401C
    b	.L_80373F10
.L_80373F10:
    lfs     f10,0(r4)
    lfs     f0,0(r3)
    lfs     f2,16(r3)
    lfs     f9,4(r4)
    fmuls   f1,f0,f10
    lfs     f0,4(r3)
    fmuls   f7,f2,f10
    lfs     f3,20(r3)
    fmuls   f0,f0,f9
    lfs     f11,8(r4)
    fmuls   f6,f3,f9
    lfs     f2,8(r3)
    addi    r4,r4,12
    lfs     f4,32(r3)
    fmuls   f2,f2,f11
    lfs     f3,36(r3)
    fadds   f0,f1,f0
    lfs     f8,24(r3)
    lfs     f5,40(r3)
    fadds   f0,f2,f0
    fmuls   f4,f4,f10
    fmuls   f1,f3,f9
    fmuls   f8,f8,f11
    stfs    f0,0(r5)
    fadds   f3,f7,f6
    fmuls   f2,f5,f11
    fadds   f1,f4,f1
    fadds   f3,f8,f3
    fadds   f0,f2,f1
    stfs    f3,4(r5)
    stfs    f0,8(r5)
    addi    r5,r5,12
    lfs     f10,0(r4)
    lfs     f0,0(r3)
    lfs     f2,16(r3)
    lfs     f4,32(r3)
    fmuls   f1,f0,f10
    lfs     f9,4(r4)
    fmuls   f7,f2,f10
    lfs     f0,4(r3)
    lfs     f3,20(r3)
    fmuls   f0,f0,f9
    lfs     f11,8(r4)
    lfs     f2,8(r3)
    fmuls   f6,f3,f9
    lfs     f3,36(r3)
    lfs     f8,24(r3)
    fmuls   f2,f2,f11
    fadds   f0,f1,f0
    lfs     f5,40(r3)
    fmuls   f4,f4,f10
    fmuls   f1,f3,f9
    fadds   f0,f2,f0
    fmuls   f8,f8,f11
    addi    r4,r4,12
    fadds   f3,f7,f6
    fmuls   f2,f5,f11
    fadds   f1,f4,f1
    fadds   f3,f8,f3
    stfs    f0,0(r5)
    fadds   f0,f2,f1
    stfs    f3,4(r5)
    stfs    f0,8(r5)
    addi    r5,r5,12
    bdnz+	.L_80373F10
    andi.   r6,r6,1
    beq-	.L_803740A8
.L_8037401C:
    mtctr   r6
    b	.L_80374024
.L_80374024:
    lfs     f10,0(r4)
    lfs     f0,0(r3)
    lfs     f2,16(r3)
    lfs     f9,4(r4)
    fmuls   f1,f0,f10
    lfs     f0,4(r3)
    fmuls   f7,f2,f10
    lfs     f3,20(r3)
    fmuls   f0,f0,f9
    lfs     f11,8(r4)
    fmuls   f6,f3,f9
    lfs     f2,8(r3)
    addi    r4,r4,12
    lfs     f4,32(r3)
    fmuls   f2,f2,f11
    lfs     f3,36(r3)
    fadds   f0,f1,f0
    lfs     f8,24(r3)
    lfs     f5,40(r3)
    fadds   f0,f2,f0
    fmuls   f4,f4,f10
    fmuls   f1,f3,f9
    fmuls   f8,f8,f11
    stfs    f0,0(r5)
    fadds   f3,f7,f6
    fmuls   f2,f5,f11
    fadds   f1,f4,f1
    fadds   f3,f8,f3
    fadds   f0,f2,f1
    stfs    f3,4(r5)
    stfs    f0,8(r5)
    addi    r5,r5,12
    bdnz+	.L_80374024
.L_803740A8:
    blr
.size C_MTXMultVecArraySR, . - C_MTXMultVecArraySR

#
# === Pad.o (pad.a) ===
#

.global UpdateOrigin
.balign 4
UpdateOrigin:
/* 0x80265190 | size=0x1A4 (420 bytes) */
    mflr    r0
    lis     r5,-32694
    stw     r0,4(r1)
    mulli   r6,r3,12
    stwu    r1,-24(r1)
    addi    r5,r5,-16400
    stw     r31,20(r1)
    add     r31,r5,r6
    lwz     r0,-27644(r13)
    rlwinm  r4,r0,0,21,23
    cmpwi   r4,1024
    lis     r0,-32768
    srw     r0,r0,r3
    beq-	.L_802652B8
    bge-	.L_802651FC
    cmpwi   r4,512
    beq-	.L_80265288
    bge-	.L_802651F0
    cmpwi   r4,256
    beq-	.L_80265254
    bge-	.L_802652B8
    cmpwi   r4,0
    beq-	.L_80265220
    b	.L_802652B8
.L_802651F0:
    cmpwi   r4,768
    beq-	.L_802652B8
    b	.L_802652B8
.L_802651FC:
    cmpwi   r4,1536
    beq-	.L_80265220
    bge-	.L_80265214
    cmpwi   r4,1280
    beq-	.L_80265220
    b	.L_802652B8
.L_80265214:
    cmpwi   r4,1792
    beq-	.L_80265220
    b	.L_802652B8
.L_80265220:
    lbz     r4,6(r31)
    clrrwi  r4,r4,4
    stb     r4,6(r31)
    lbz     r4,7(r31)
    clrrwi  r4,r4,4
    stb     r4,7(r31)
    lbz     r4,8(r31)
    clrrwi  r4,r4,4
    stb     r4,8(r31)
    lbz     r4,9(r31)
    clrrwi  r4,r4,4
    stb     r4,9(r31)
    b	.L_802652B8
.L_80265254:
    lbz     r4,4(r31)
    clrrwi  r4,r4,4
    stb     r4,4(r31)
    lbz     r4,5(r31)
    clrrwi  r4,r4,4
    stb     r4,5(r31)
    lbz     r4,8(r31)
    clrrwi  r4,r4,4
    stb     r4,8(r31)
    lbz     r4,9(r31)
    clrrwi  r4,r4,4
    stb     r4,9(r31)
    b	.L_802652B8
.L_80265288:
    lbz     r4,4(r31)
    clrrwi  r4,r4,4
    stb     r4,4(r31)
    lbz     r4,5(r31)
    clrrwi  r4,r4,4
    stb     r4,5(r31)
    lbz     r4,6(r31)
    clrrwi  r4,r4,4
    stb     r4,6(r31)
    lbz     r4,7(r31)
    clrrwi  r4,r4,4
    stb     r4,7(r31)
.L_802652B8:
    lbz     r4,2(r31)
    addi    r4,r4,-128
    stb     r4,2(r31)
    lbz     r4,3(r31)
    addi    r4,r4,-128
    stb     r4,3(r31)
    lbz     r4,4(r31)
    addi    r4,r4,-128
    stb     r4,4(r31)
    lbz     r4,5(r31)
    addi    r4,r4,-128
    stb     r4,5(r31)
    lwz     r4,-27648(r13)
    and.    r0,r4,r0
    beq-	.L_80265320
    lbz     r0,2(r31)
    extsb   r0,r0
    cmpwi   r0,64
    ble-	.L_80265320
    bl	SIGetType
    clrrwi  r3,r3,16
    addis   r0,r3,-2304
    cmplwi  r0,0
    bne-	.L_80265320
    li      r0,0
    stb     r0,2(r31)
.L_80265320:
    lwz     r0,28(r1)
    lwz     r31,20(r1)
    addi    r1,r1,24
    mtlr    r0
    blr
.size UpdateOrigin, . - UpdateOrigin

.global PADTypeAndStatusCallback
.balign 4
PADTypeAndStatusCallback:
/* 0x8026559C | size=0x32C (812 bytes) */
    mflr    r0
    lis     r6,-32694
    stw     r0,4(r1)
    clrlwi. r0,r4,28
    stwu    r1,-64(r1)
    stw     r31,60(r1)
    lis     r31,-32768
    stw     r30,56(r1)
    addi    r30,r6,-16416
    stw     r29,52(r1)
    stw     r28,48(r1)
    lwz     r29,-27652(r13)
    lwz     r5,-23172(r13)
    srw     r28,r31,r29
    andc    r3,r5,r28
    stw     r3,-23172(r13)
    and     r5,r5,r28
    li      r3,1
    beq-	.L_80265638
    lwz     r4,-23176(r13)
    cntlzw  r0,r4
    stw     r0,-27652(r13)
    lwz     r3,-27652(r13)
    cmpwi   r3,32
    beq-	.L_802658A8
    mulli   r0,r3,12
    srw     r3,r31,r3
    andc    r4,r4,r3
    add     r3,r30,r0
    stw     r4,-23176(r13)
    li      r4,0
    li      r5,12
    addi    r3,r3,16
    bl	memset
    lis     r4,-32730
    lwz     r3,-27652(r13)
    addi    r4,r4,21916
    bl	SIGetTypeAsync
    b	.L_802658A8
.L_80265638:
    clrrwi  r6,r4,8
    rlwinm  r4,r4,0,3,4
    addis   r0,r4,-2048
    slwi    r4,r29,2
    cmplwi  r0,0
    stwx    r6,r30,r4
    bne-	.L_8026565C
    rlwinm. r0,r6,0,7,7
    bne-	.L_802656B0
.L_8026565C:
    lwz     r5,-23176(r13)
    cntlzw  r0,r5
    stw     r0,-27652(r13)
    lwz     r4,-27652(r13)
    cmpwi   r4,32
    beq-	.L_802658A8
    lis     r3,-32768
    mulli   r0,r4,12
    srw     r3,r3,r4
    andc    r4,r5,r3
    add     r3,r30,r0
    stw     r4,-23176(r13)
    li      r4,0
    li      r5,12
    addi    r3,r3,16
    bl	memset
    lis     r4,-32730
    lwz     r3,-27652(r13)
    addi    r4,r4,21916
    bl	SIGetTypeAsync
    b	.L_802658A8
.L_802656B0:
    lwz     r0,-27640(r13)
    cmplwi  r0,2
    bge-	.L_8026573C
    lwz     r0,-23180(r13)
    addi    r3,r29,0
    addi    r4,r1,28
    or      r0,r0,r28
    stw     r0,-23180(r13)
    bl	SIGetResponse
    lwz     r0,-27644(r13)
    addi    r3,r29,0
    oris    r4,r0,64
    bl	SISetCommand
    lwz     r3,-23180(r13)
    bl	SIEnablePolling
    lwz     r4,-23176(r13)
    cntlzw  r0,r4
    stw     r0,-27652(r13)
    lwz     r3,-27652(r13)
    cmpwi   r3,32
    beq-	.L_802658A8
    mulli   r0,r3,12
    srw     r3,r31,r3
    andc    r4,r4,r3
    add     r3,r30,r0
    stw     r4,-23176(r13)
    li      r4,0
    li      r5,12
    addi    r3,r3,16
    bl	memset
    lis     r4,-32730
    lwz     r3,-27652(r13)
    addi    r4,r4,21916
    bl	SIGetTypeAsync
    b	.L_802658A8
.L_8026573C:
    clrrwi. r0,r6,31
    beq-	.L_8026574C
    rlwinm. r0,r6,0,5,5
    beq-	.L_802657BC
.L_8026574C:
    cmplwi  r5,0
    beq-	.L_80265788
    mulli   r0,r29,12
    lis     r3,-32730
    add     r6,r30,r0
    addi    r8,r3,21300
    addi    r3,r29,0
    addi    r4,r13,-27628
    li      r5,3
    li      r7,10
    li      r10,0
    li      r9,0
    addi    r6,r6,16
    bl	SITransfer
    b	.L_80265844
.L_80265788:
    mulli   r0,r29,12
    lis     r3,-32730
    add     r6,r30,r0
    addi    r8,r3,21300
    addi    r3,r29,0
    addi    r4,r13,-27632
    li      r5,1
    li      r7,10
    li      r10,0
    li      r9,0
    addi    r6,r6,16
    bl	SITransfer
    b	.L_80265844
.L_802657BC:
    rlwinm. r0,r6,0,11,11
    beq-	.L_80265844
    rlwinm. r0,r6,0,12,12
    bne-	.L_80265844
    rlwinm. r0,r6,0,13,13
    bne-	.L_80265844
    rlwinm. r0,r6,0,1,1
    beq-	.L_80265810
    mulli   r0,r29,12
    lis     r3,-32730
    add     r6,r30,r0
    addi    r8,r3,21300
    addi    r3,r29,0
    addi    r4,r13,-27632
    li      r5,1
    li      r7,10
    li      r10,0
    li      r9,0
    addi    r6,r6,16
    bl	SITransfer
    b	.L_80265844
.L_80265810:
    mulli   r0,r29,12
    lis     r3,-32730
    add     r4,r30,r4
    add     r6,r30,r0
    addi    r8,r3,21700
    addi    r3,r29,0
    li      r5,3
    li      r7,8
    li      r10,0
    li      r9,0
    addi    r4,r4,64
    addi    r6,r6,16
    bl	SITransfer
.L_80265844:
    cmpwi   r3,0
    bne-	.L_802658A8
    lwz     r5,-23176(r13)
    lwz     r3,-23160(r13)
    cntlzw  r0,r5
    stw     r0,-27652(r13)
    or      r0,r3,r28
    lwz     r4,-27652(r13)
    stw     r0,-23160(r13)
    cmpwi   r4,32
    beq-	.L_802658A8
    lis     r3,-32768
    mulli   r0,r4,12
    srw     r3,r3,r4
    andc    r4,r5,r3
    add     r3,r30,r0
    stw     r4,-23176(r13)
    li      r4,0
    li      r5,12
    addi    r3,r3,16
    bl	memset
    lis     r4,-32730
    lwz     r3,-27652(r13)
    addi    r4,r4,21916
    bl	SIGetTypeAsync
.L_802658A8:
    lwz     r0,68(r1)
    lwz     r31,60(r1)
    lwz     r30,56(r1)
    lwz     r29,52(r1)
    lwz     r28,48(r1)
    addi    r1,r1,64
    mtlr    r0
    blr
.size PADTypeAndStatusCallback, . - PADTypeAndStatusCallback

.global PADReceiveCheckCallback
.balign 4
PADReceiveCheckCallback:
/* 0x802658C8 | size=0x140 (320 bytes) */
    mflr    r0
    stw     r0,4(r1)
    stwu    r1,-32(r1)
    stw     r31,28(r1)
    mr      r31,r3
    lis     r3,-32768
    stw     r30,24(r1)
    stw     r29,20(r1)
    srw     r29,r3,r31
    lwz     r0,-23180(r13)
    and.    r0,r0,r29
    beq-	.L_802659EC
    lwz     r5,-23168(r13)
    not     r6,r29
    lwz     r3,-23164(r13)
    clrlwi. r0,r4,28
    and     r5,r5,r6
    and     r3,r3,r6
    stw     r5,-23168(r13)
    stw     r3,-23164(r13)
    clrrwi  r3,r4,8
    bne-	.L_80265988
    clrrwi. r0,r3,31
    beq-	.L_80265988
    rlwinm. r0,r3,0,11,11
    beq-	.L_80265988
    rlwinm. r0,r3,0,1,1
    beq-	.L_80265988
    rlwinm. r0,r3,0,5,5
    bne-	.L_80265988
    rlwinm. r0,r3,0,12,12
    bne-	.L_80265988
    rlwinm. r0,r3,0,13,13
    bne-	.L_80265988
    mulli   r4,r31,12
    lis     r3,-32694
    addi    r0,r3,-16400
    lis     r3,-32730
    add     r6,r0,r4
    addi    r8,r3,21496
    addi    r3,r31,0
    addi    r4,r13,-27632
    li      r5,1
    li      r7,10
    li      r10,0
    li      r9,0
    bl	SITransfer
    b	.L_802659EC
.L_80265988:
    bl	OSDisableInterrupts
    addi    r30,r3,0
    addi    r3,r29,0
    bl	SIDisablePolling
    lwz     r0,-23180(r13)
    not     r9,r29
    lwz     r6,-23168(r13)
    mr      r3,r31
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
    bl	OSSetWirelessID
    mr      r3,r30
    bl	OSRestoreInterrupts
.L_802659EC:
    lwz     r0,36(r1)
    lwz     r31,28(r1)
    lwz     r30,24(r1)
    lwz     r29,20(r1)
    addi    r1,r1,32
    mtlr    r0
    blr
.size PADReceiveCheckCallback, . - PADReceiveCheckCallback

.global PADReset
.balign 4
PADReset:
/* 0x80265A08 | size=0x110 (272 bytes) */
    mflr    r0
    stw     r0,4(r1)
    stwu    r1,-24(r1)
    stw     r31,20(r1)
    stw     r30,16(r1)
    mr      r30,r3
    bl	OSDisableInterrupts
    lwz     r4,-23160(r13)
    li      r8,0
    lwz     r5,-23168(r13)
    mr      r31,r3
    lwz     r0,-23164(r13)
    or      r30,r30,r4
    lwz     r4,-23176(r13)
    or      r5,r5,r0
    lwz     r0,-27640(r13)
    andc    r30,r30,r5
    lwz     r6,-23180(r13)
    or      r5,r4,r30
    lwz     r4,-23156(r13)
    not     r7,r30
    stw     r5,-23176(r13)
    and     r5,r6,r7
    and     r4,r4,r7
    lwz     r7,-23176(r13)
    cmplwi  r0,4
    stw     r8,-23160(r13)
    and     r3,r7,r6
    stw     r5,-23180(r13)
    stw     r4,-23156(r13)
    bne-	.L_80265A90
    lwz     r0,-23172(r13)
    or      r0,r0,r30
    stw     r0,-23172(r13)
.L_80265A90:
    bl	SIDisablePolling
    lwz     r0,-27652(r13)
    cmpwi   r0,32
    bne-	.L_80265AF4
    lwz     r5,-23176(r13)
    cntlzw  r0,r5
    stw     r0,-27652(r13)
    lwz     r4,-27652(r13)
    cmpwi   r4,32
    beq-	.L_80265AF4
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
    bl	memset
    lis     r4,-32730
    lwz     r3,-27652(r13)
    addi    r4,r4,21916
    bl	SIGetTypeAsync
.L_80265AF4:
    mr      r3,r31
    bl	OSRestoreInterrupts
    lwz     r0,28(r1)
    li      r3,1
    lwz     r31,20(r1)
    lwz     r30,16(r1)
    addi    r1,r1,24
    mtlr    r0
    blr
.size PADReset, . - PADReset

.global PADRecalibrate
.balign 4
PADRecalibrate:
/* 0x80265B18 | size=0x114 (276 bytes) */
    mflr    r0
    stw     r0,4(r1)
    stwu    r1,-24(r1)
    stw     r31,20(r1)
    stw     r30,16(r1)
    mr      r30,r3
    bl	OSDisableInterrupts
    lwz     r5,-23160(r13)
    li      r8,0
    lwz     r6,-23168(r13)
    lis     r4,-32768
    lwz     r0,-23164(r13)
    or      r30,r30,r5
    lwz     r5,-23176(r13)
    or      r6,r6,r0
    lbz     r0,12515(r4)
    andc    r30,r30,r6
    lwz     r6,-23180(r13)
    or      r5,r5,r30
    lwz     r4,-23156(r13)
    stw     r5,-23176(r13)
    not     r9,r30
    and     r5,r6,r9
    and     r4,r4,r9
    lwz     r7,-23176(r13)
    mr      r31,r3
    stw     r8,-23160(r13)
    rlwinm. r0,r0,0,25,25
    stw     r5,-23180(r13)
    and     r3,r7,r6
    stw     r4,-23156(r13)
    bne-	.L_80265BA4
    lwz     r0,-23172(r13)
    or      r0,r0,r30
    stw     r0,-23172(r13)
.L_80265BA4:
    bl	SIDisablePolling
    lwz     r0,-27652(r13)
    cmpwi   r0,32
    bne-	.L_80265C08
    lwz     r5,-23176(r13)
    cntlzw  r0,r5
    stw     r0,-27652(r13)
    lwz     r4,-27652(r13)
    cmpwi   r4,32
    beq-	.L_80265C08
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
    bl	memset
    lis     r4,-32730
    lwz     r3,-27652(r13)
    addi    r4,r4,21916
    bl	SIGetTypeAsync
.L_80265C08:
    mr      r3,r31
    bl	OSRestoreInterrupts
    lwz     r0,28(r1)
    li      r3,1
    lwz     r31,20(r1)
    lwz     r30,16(r1)
    addi    r1,r1,24
    mtlr    r0
    blr
.size PADRecalibrate, . - PADRecalibrate

.global PADInit
.balign 4
PADInit:
/* 0x80265C2C | size=0x150 (336 bytes) */
    mflr    r0
    lis     r3,-32694
    stw     r0,4(r1)
    stwu    r1,-56(r1)
    stmw    r25,28(r1)
    addi    r31,r3,-16416
    lwz     r0,-23184(r13)
    cmpwi   r0,0
    beq-	.L_80265C58
    li      r3,1
    b	.L_80265D68
.L_80265C58:
    lwz     r3,-27656(r13)
    bl	OSRegisterVersion
    lwz     r3,-23140(r13)
    cmplwi  r3,0
    beq-	.L_80265C70
    bl	PADSetSpec
.L_80265C70:
    lwz     r0,-23536(r13)
    li      r3,1
    stw     r3,-23184(r13)
    cmplwi  r0,0
    beq-	.L_80265D0C
    bl	OSGetTime
    addi    r25,r4,0
    addi    r26,r3,0
    li      r5,16
    bl	__shr2i
    lis     r5,1
    addi    r27,r5,-1
    li      r28,0
    and     r6,r4,r27
    and     r4,r25,r27
    and     r5,r3,r28
    and     r0,r26,r28
    addc    r29,r4,r6
    addi    r3,r26,0
    addi    r4,r25,0
    adde    r30,r0,r5
    li      r5,32
    bl	__shr2i
    and     r4,r4,r27
    and     r0,r3,r28
    addc    r29,r4,r29
    addi    r3,r26,0
    addi    r4,r25,0
    adde    r30,r0,r30
    li      r5,48
    bl	__shr2i
    and     r0,r4,r27
    addc    r5,r0,r29
    lis     r0,-4096
    li      r4,16383
    stw     r0,-23172(r13)
    and     r0,r5,r4
    lis     r3,-32768
    sth     r0,12512(r3)
.L_80265D0C:
    lis     r3,-32768
    lhz     r0,12512(r3)
    rlwinm  r0,r0,8,10,23
    oris    r0,r0,19712
    stw     r0,64(r31)
    lhz     r0,12512(r3)
    rlwinm  r0,r0,8,10,23
    oris    r0,r0,19776
    stw     r0,68(r31)
    lhz     r0,12512(r3)
    rlwinm  r0,r0,8,10,23
    oris    r0,r0,19840
    stw     r0,72(r31)
    lhz     r0,12512(r3)
    rlwinm  r0,r0,8,10,23
    oris    r0,r0,19904
    stw     r0,76(r31)
    bl	SIRefreshSamplingRate
    lis     r3,-32700
    addi    r3,r3,-11624
    bl	OSRegisterResetFunction
    lis     r3,-4096
    bl	PADReset
.L_80265D68:
    lmw     r25,28(r1)
    lwz     r0,60(r1)
    addi    r1,r1,56
    mtlr    r0
    blr
.size PADInit, . - PADInit

.global PADRead
.balign 4
PADRead:
/* 0x80265D7C | size=0x300 (768 bytes) */
    mflr    r0
    stw     r0,4(r1)
    stwu    r1,-64(r1)
    stmw    r22,24(r1)
    mr      r23,r3
    bl	OSDisableInterrupts
    li      r25,0
    mulli   r5,r25,12
    lis     r4,-32694
    addi    r0,r4,-16400
    add     r28,r0,r5
    lis     r4,-32730
    lis     r5,-32730
    addi    r26,r3,0
    addi    r22,r4,21496
    addi    r31,r5,22728
    li      r24,0
    lis     r30,-32768
.L_80265DC4:
    lwz     r0,-23160(r13)
    srw     r27,r30,r25
    and.    r0,r0,r27
    beq-	.L_80265DF8
    li      r3,0
    bl	PADReset
    li      r0,-2
    stb     r0,10(r23)
    addi    r3,r23,0
    li      r4,0
    li      r5,10
    bl	memset
    b	.L_80266048
.L_80265DF8:
    lwz     r0,-23176(r13)
    and.    r0,r0,r27
    bne-	.L_80265E10
    lwz     r0,-27652(r13)
    cmpw    r0,r25
    bne-	.L_80265E2C
.L_80265E10:
    li      r0,-2
    stb     r0,10(r23)
    addi    r3,r23,0
    li      r4,0
    li      r5,10
    bl	memset
    b	.L_80266048
.L_80265E2C:
    lwz     r0,-23180(r13)
    and.    r0,r0,r27
    bne-	.L_80265E54
    li      r0,-1
    stb     r0,10(r23)
    addi    r3,r23,0
    li      r4,0
    li      r5,10
    bl	memset
    b	.L_80266048
.L_80265E54:
    mr      r3,r25
    bl	SIIsChanBusy
    cmpwi   r3,0
    beq-	.L_80265E80
    li      r0,-3
    stb     r0,10(r23)
    addi    r3,r23,0
    li      r4,0
    li      r5,10
    bl	memset
    b	.L_80266048
.L_80265E80:
    mr      r3,r25
    bl	SIGetStatus
    rlwinm. r0,r3,0,28,28
    beq-	.L_80265F64
    addi    r3,r25,0
    addi    r4,r1,16
    bl	SIGetResponse
    lwz     r0,-23168(r13)
    and.    r0,r0,r27
    beq-	.L_80265EE4
    li      r0,0
    stb     r0,10(r23)
    addi    r3,r23,0
    li      r4,0
    li      r5,10
    bl	memset
    lwz     r3,-23164(r13)
    and.    r0,r3,r27
    bne-	.L_80266048
    or      r0,r3,r27
    stw     r0,-23164(r13)
    addi    r3,r25,0
    addi    r4,r31,0
    bl	SIGetTypeAsync
    b	.L_80266048
.L_80265EE4:
    bl	OSDisableInterrupts
    addi    r29,r3,0
    addi    r3,r27,0
    bl	SIDisablePolling
    lwz     r0,-23180(r13)
    not     r9,r27
    lwz     r6,-23168(r13)
    mr      r3,r25
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
    bl	OSSetWirelessID
    mr      r3,r29
    bl	OSRestoreInterrupts
    li      r0,-1
    stb     r0,10(r23)
    addi    r3,r23,0
    li      r4,0
    li      r5,10
    bl	memset
    b	.L_80266048
.L_80265F64:
    mr      r3,r25
    bl	SIGetType
    rlwinm. r0,r3,0,2,2
    bne-	.L_80265F78
    or      r24,r24,r27
.L_80265F78:
    addi    r3,r25,0
    addi    r4,r1,16
    bl	SIGetResponse
    cmpwi   r3,0
    bne-	.L_80265FA8
    li      r0,-3
    stb     r0,10(r23)
    addi    r3,r23,0
    li      r4,0
    li      r5,10
    bl	memset
    b	.L_80266048
.L_80265FA8:
    lwz     r0,16(r1)
    clrrwi. r0,r0,31
    beq-	.L_80265FD0
    li      r0,-3
    stb     r0,10(r23)
    addi    r3,r23,0
    li      r4,0
    li      r5,10
    bl	memset
    b	.L_80266048
.L_80265FD0:
    lwz     r12,-27636(r13)
    addi    r3,r25,0
    addi    r4,r23,0
    mtlr    r12
    addi    r5,r1,16
    blrl
    lhz     r0,0(r23)
    rlwinm. r0,r0,0,18,18
    beq-	.L_80266034
    li      r0,-3
    stb     r0,10(r23)
    addi    r3,r23,0
    li      r4,0
    li      r5,10
    bl	memset
    addi    r3,r25,0
    addi    r6,r28,0
    addi    r8,r22,0
    addi    r4,r13,-27632
    li      r5,1
    li      r7,10
    li      r10,0
    li      r9,0
    bl	SITransfer
    b	.L_80266048
.L_80266034:
    li      r0,0
    stb     r0,10(r23)
    lhz     r0,0(r23)
    rlwinm  r0,r0,0,25,23
    sth     r0,0(r23)
.L_80266048:
    addi    r25,r25,1
    cmpwi   r25,4
    addi    r28,r28,12
    addi    r23,r23,12
    blt+	.L_80265DC4
    mr      r3,r26
    bl	OSRestoreInterrupts
    mr      r3,r24
    lmw     r22,24(r1)
    lwz     r0,68(r1)
    addi    r1,r1,64
    mtlr    r0
    blr
.size PADRead, . - PADRead

.global SPEC0_MakeStatus
.balign 4
SPEC0_MakeStatus:
/* 0x80266288 | size=0x174 (372 bytes) */
    li      r3,0
    sth     r3,0(r4)
    lwz     r0,0(r5)
    rlwinm. r0,r0,16,28,28
    beq-	.L_802662A0
    li      r3,256
.L_802662A0:
    lhz     r0,0(r4)
    or      r0,r0,r3
    sth     r0,0(r4)
    lwz     r0,0(r5)
    rlwinm. r0,r0,16,26,26
    beq-	.L_802662C0
    li      r3,512
    b	.L_802662C4
.L_802662C0:
    li      r3,0
.L_802662C4:
    lhz     r0,0(r4)
    or      r0,r0,r3
    sth     r0,0(r4)
    lwz     r0,0(r5)
    rlwinm. r0,r0,16,23,23
    beq-	.L_802662E4
    li      r3,1024
    b	.L_802662E8
.L_802662E4:
    li      r3,0
.L_802662E8:
    lhz     r0,0(r4)
    or      r0,r0,r3
    sth     r0,0(r4)
    lwz     r0,0(r5)
    rlwinm. r0,r0,16,31,31
    beq-	.L_80266308
    li      r3,2048
    b	.L_8026630C
.L_80266308:
    li      r3,0
.L_8026630C:
    lhz     r0,0(r4)
    or      r0,r0,r3
    sth     r0,0(r4)
    lwz     r0,0(r5)
    rlwinm. r0,r0,16,27,27
    beq-	.L_8026632C
    li      r6,4096
    b	.L_80266330
.L_8026632C:
    li      r6,0
.L_80266330:
    lhz     r3,0(r4)
    li      r0,0
    or      r3,r3,r6
    sth     r3,0(r4)
    lwz     r3,4(r5)
    srwi    r3,r3,16
    extsb   r3,r3
    stb     r3,2(r4)
    lwz     r3,4(r5)
    srwi    r3,r3,24
    extsb   r3,r3
    stb     r3,3(r4)
    lwz     r3,4(r5)
    extsb   r3,r3
    stb     r3,4(r4)
    lwz     r3,4(r5)
    srwi    r3,r3,8
    extsb   r3,r3
    stb     r3,5(r4)
    lwz     r3,0(r5)
    rlwinm  r3,r3,24,24,31
    stb     r3,6(r4)
    lwz     r3,0(r5)
    stb     r3,7(r4)
    stb     r0,8(r4)
    stb     r0,9(r4)
    lbz     r0,6(r4)
    cmplwi  r0,170
    blt-	.L_802663B0
    lhz     r0,0(r4)
    ori     r0,r0,64
    sth     r0,0(r4)
.L_802663B0:
    lbz     r0,7(r4)
    cmplwi  r0,170
    blt-	.L_802663C8
    lhz     r0,0(r4)
    ori     r0,r0,32
    sth     r0,0(r4)
.L_802663C8:
    lbz     r3,2(r4)
    addi    r0,r3,-128
    stb     r0,2(r4)
    lbz     r3,3(r4)
    addi    r0,r3,-128
    stb     r0,3(r4)
    lbz     r3,4(r4)
    addi    r0,r3,-128
    stb     r0,4(r4)
    lbz     r3,5(r4)
    addi    r0,r3,-128
    stb     r0,5(r4)
    blr
.size SPEC0_MakeStatus, . - SPEC0_MakeStatus

.global SPEC1_MakeStatus
.balign 4
SPEC1_MakeStatus:
/* 0x802663FC | size=0x174 (372 bytes) */
    li      r3,0
    sth     r3,0(r4)
    lwz     r0,0(r5)
    rlwinm. r0,r0,16,24,24
    beq-	.L_80266414
    li      r3,256
.L_80266414:
    lhz     r0,0(r4)
    or      r0,r0,r3
    sth     r0,0(r4)
    lwz     r0,0(r5)
    rlwinm. r0,r0,16,23,23
    beq-	.L_80266434
    li      r3,512
    b	.L_80266438
.L_80266434:
    li      r3,0
.L_80266438:
    lhz     r0,0(r4)
    or      r0,r0,r3
    sth     r0,0(r4)
    lwz     r0,0(r5)
    rlwinm. r0,r0,16,26,26
    beq-	.L_80266458
    li      r3,1024
    b	.L_8026645C
.L_80266458:
    li      r3,0
.L_8026645C:
    lhz     r0,0(r4)
    or      r0,r0,r3
    sth     r0,0(r4)
    lwz     r0,0(r5)
    rlwinm. r0,r0,16,27,27
    beq-	.L_8026647C
    li      r3,2048
    b	.L_80266480
.L_8026647C:
    li      r3,0
.L_80266480:
    lhz     r0,0(r4)
    or      r0,r0,r3
    sth     r0,0(r4)
    lwz     r0,0(r5)
    rlwinm. r0,r0,16,22,22
    beq-	.L_802664A0
    li      r6,4096
    b	.L_802664A4
.L_802664A0:
    li      r6,0
.L_802664A4:
    lhz     r3,0(r4)
    li      r0,0
    or      r3,r3,r6
    sth     r3,0(r4)
    lwz     r3,4(r5)
    srwi    r3,r3,16
    extsb   r3,r3
    stb     r3,2(r4)
    lwz     r3,4(r5)
    srwi    r3,r3,24
    extsb   r3,r3
    stb     r3,3(r4)
    lwz     r3,4(r5)
    extsb   r3,r3
    stb     r3,4(r4)
    lwz     r3,4(r5)
    srwi    r3,r3,8
    extsb   r3,r3
    stb     r3,5(r4)
    lwz     r3,0(r5)
    rlwinm  r3,r3,24,24,31
    stb     r3,6(r4)
    lwz     r3,0(r5)
    stb     r3,7(r4)
    stb     r0,8(r4)
    stb     r0,9(r4)
    lbz     r0,6(r4)
    cmplwi  r0,170
    blt-	.L_80266524
    lhz     r0,0(r4)
    ori     r0,r0,64
    sth     r0,0(r4)
.L_80266524:
    lbz     r0,7(r4)
    cmplwi  r0,170
    blt-	.L_8026653C
    lhz     r0,0(r4)
    ori     r0,r0,32
    sth     r0,0(r4)
.L_8026653C:
    lbz     r3,2(r4)
    addi    r0,r3,-128
    stb     r0,2(r4)
    lbz     r3,3(r4)
    addi    r0,r3,-128
    stb     r0,3(r4)
    lbz     r3,4(r4)
    addi    r0,r3,-128
    stb     r0,4(r4)
    lbz     r3,5(r4)
    addi    r0,r3,-128
    stb     r0,5(r4)
    blr
.size SPEC1_MakeStatus, . - SPEC1_MakeStatus

#
# === SIBios.o (si.a) ===
#

# Original symbol: CompleteTransfer
.global SIBios_CompleteTransfer
.balign 4
SIBios_CompleteTransfer:
/* 0x80258B5C | size=0x2FC (764 bytes) */
    mflr    r0
    lis     r3,-13312
    stw     r0,4(r1)
    stwu    r1,-32(r1)
    stw     r31,28(r1)
    stw     r30,24(r1)
    addi    r30,r3,25600
    stw     r29,20(r1)
    addi    r29,r30,52
    stw     r28,16(r1)
    lwz     r0,25652(r3)
    lwz     r28,25656(r3)
    lis     r3,-32700
    oris    r0,r0,32768
    clrrwi  r0,r0,1
    stw     r0,52(r30)
    addi    r31,r3,-16040
    lwz     r0,68(r31)
    cmpwi   r0,-1
    beq-	.L_80258E1C
    bl	__OSGetSystemTime
    lwz     r6,68(r31)
    lis     r5,-32694
    addi    r0,r5,-21552
    slwi    r5,r6,3
    add     r5,r0,r5
    stw     r4,4(r5)
    addi    r6,r31,76
    li      r4,0
    stw     r3,0(r5)
    lwz     r0,76(r31)
    lwz     r5,80(r31)
    srwi    r7,r0,2
    cmplwi  r7,0
    ble-	.L_80258C84
    cmplwi  r7,8
    addi    r3,r7,-8
    ble-	.L_80258E24
    addi    r0,r3,7
    srwi    r0,r0,3
    cmplwi  r3,0
    mtctr   r0
    ble-	.L_80258E24
.L_80258C08:
    lwz     r0,128(r30)
    addi    r4,r4,8
    stw     r0,0(r5)
    lwz     r0,132(r30)
    stw     r0,4(r5)
    lwz     r0,136(r30)
    stw     r0,8(r5)
    lwz     r0,140(r30)
    stw     r0,12(r5)
    lwz     r0,144(r30)
    stw     r0,16(r5)
    lwz     r0,148(r30)
    stw     r0,20(r5)
    lwz     r0,152(r30)
    stw     r0,24(r5)
    lwz     r0,156(r30)
    addi    r30,r30,32
    stw     r0,28(r5)
    addi    r5,r5,32
    bdnz+	.L_80258C08
    b	.L_80258E24
.L_80258C5C:
    subf    r0,r4,r7
    cmplw   r4,r7
    mtctr   r0
    bge-	.L_80258C84
.L_80258C6C:
    lwz     r0,128(r3)
    addi    r3,r3,4
    addi    r4,r4,1
    stw     r0,0(r5)
    addi    r5,r5,4
    bdnz+	.L_80258C6C
.L_80258C84:
    lwz     r0,0(r6)
    clrlwi. r3,r0,30
    beq-	.L_80258D9C
    lis     r6,-13312
    addi    r6,r6,25600
    slwi    r0,r4,2
    add     r4,r6,r0
    lwz     r6,128(r4)
    li      r4,0
    ble-	.L_80258D9C
    cmplwi  r3,8
    addi    r7,r3,-8
    ble-	.L_80258D70
    addi    r0,r7,7
    srwi    r0,r0,3
    cmplwi  r7,0
    mtctr   r0
    ble-	.L_80258D70
.L_80258CCC:
    subfic  r0,r4,3
    slwi    r7,r0,3
    addi    r0,r4,1
    srw     r7,r6,r7
    subfic  r0,r0,3
    stb     r7,0(r5)
    slwi    r0,r0,3
    addi    r7,r4,2
    srw     r0,r6,r0
    subfic  r7,r7,3
    stb     r0,1(r5)
    slwi    r7,r7,3
    srw     r12,r6,r7
    neg     r7,r4
    stb     r12,2(r5)
    slwi    r8,r7,3
    addi    r7,r4,4
    srw     r11,r6,r8
    subfic  r7,r7,3
    stb     r11,3(r5)
    slwi    r8,r7,3
    addi    r7,r4,5
    srw     r10,r6,r8
    subfic  r7,r7,3
    stb     r10,4(r5)
    slwi    r8,r7,3
    srw     r9,r6,r8
    addi    r7,r4,6
    stb     r9,5(r5)
    subfic  r8,r7,3
    addi    r7,r4,7
    slwi    r8,r8,3
    srw     r8,r6,r8
    subfic  r7,r7,3
    stb     r8,6(r5)
    slwi    r7,r7,3
    srw     r7,r6,r7
    stb     r7,7(r5)
    addi    r5,r5,8
    addi    r4,r4,8
    bdnz+	.L_80258CCC
.L_80258D70:
    subf    r0,r4,r3
    cmplw   r4,r3
    mtctr   r0
    bge-	.L_80258D9C
.L_80258D80:
    subfic  r0,r4,3
    slwi    r0,r0,3
    srw     r0,r6,r0
    stb     r0,0(r5)
    addi    r5,r5,1
    addi    r4,r4,1
    bdnz+	.L_80258D80
.L_80258D9C:
    lwz     r0,0(r29)
    rlwinm. r0,r0,0,2,2
    beq-	.L_80258DF0
    lwz     r3,68(r31)
    subfic  r0,r3,3
    slwi    r0,r0,3
    srw     r28,r28,r0
    clrlwi  r28,r28,28
    rlwinm. r0,r28,0,28,28
    beq-	.L_80258DE0
    slwi    r0,r3,2
    add     r3,r31,r0
    lwzu    r0,88(r3)
    rlwinm. r0,r0,0,24,24
    bne-	.L_80258DE0
    li      r0,8
    stw     r0,0(r3)
.L_80258DE0:
    cmplwi  r28,0
    bne-	.L_80258E14
    li      r28,4
    b	.L_80258E14
.L_80258DF0:
    bl	__OSGetSystemTime
    lwz     r6,68(r31)
    lis     r5,-32694
    addi    r0,r5,-21584
    slwi    r5,r6,3
    add     r5,r0,r5
    stw     r4,4(r5)
    li      r28,0
    stw     r3,0(r5)
.L_80258E14:
    li      r0,-1
    stw     r0,68(r31)
.L_80258E1C:
    mr      r3,r28
    b	.L_80258E38
.L_80258E24:
    lis     r3,-13312
    slwi    r0,r4,2
    addi    r3,r3,25600
    add     r3,r3,r0
    b	.L_80258C5C
.L_80258E38:
    lwz     r0,36(r1)
    lwz     r31,28(r1)
    lwz     r30,24(r1)
    lwz     r29,20(r1)
    lwz     r28,16(r1)
    addi    r1,r1,32
    mtlr    r0
    blr
.size SIBios_CompleteTransfer, . - SIBios_CompleteTransfer

.global SIInterruptHandler
.balign 4
SIInterruptHandler:
/* 0x80258F48 | size=0x344 (836 bytes) */
    mflr    r0
    lis     r5,-13312
    stw     r0,4(r1)
    lis     r7,-32694
    lis     r6,-32700
    stwu    r1,-72(r1)
    stmw    r21,28(r1)
    addi    r30,r3,0
    addi    r31,r4,0
    addi    r28,r7,-21872
    addi    r29,r6,-16040
    lwz     r24,25652(r5)
    clrrwi  r5,r24,30
    addis   r0,r5,16384
    cmplwi  r0,0
    bne-	.L_80259108
    lwz     r23,68(r29)
    bl	CompleteTransfer
    lwz     r21,84(r29)
    li      r27,0
    addi    r22,r3,0
    stw     r27,84(r29)
    addi    r26,r23,0
.L_80258FA4:
    addi    r26,r26,1
    srawi   r0,r26,2
    addze   r0,r0
    slwi    r0,r0,2
    subfc   r0,r0,r26
    mr      r26,r0
    slwi    r0,r0,5
    add     r25,r28,r0
    lwz     r0,0(r25)
    cmpwi   r0,-1
    beq-	.L_80259038
    bl	__OSGetSystemTime
    lwz     r0,24(r25)
    xoris   r5,r3,32768
    lwz     r6,28(r25)
    xoris   r3,r0,32768
    subfc   r0,r6,r4
    subfe   r3,r3,r5
    subfe   r3,r5,r5
    neg.    r3,r3
    bne-	.L_80259038
    lwz     r3,0(r25)
    lwz     r4,4(r25)
    lwz     r5,8(r25)
    lwz     r6,12(r25)
    lwz     r7,16(r25)
    lwz     r8,20(r25)
    bl	__SITransfer
    cmpwi   r3,0
    beq-	.L_80259044
    mulli   r0,r26,40
    add     r3,r28,r0
    addi    r3,r3,128
    bl	OSCancelAlarm
    li      r0,-1
    stw     r0,0(r25)
    b	.L_80259044
.L_80259038:
    addi    r27,r27,1
    cmpwi   r27,4
    blt+	.L_80258FA4
.L_80259044:
    cmplwi  r21,0
    beq-	.L_80259064
    addi    r12,r21,0
    mtlr    r12
    addi    r3,r23,0
    addi    r4,r22,0
    addi    r5,r31,0
    blrl
.L_80259064:
    lis     r3,-13312
    addi    r4,r3,25600
    lwz     r5,25656(r3)
    slwi    r0,r23,3
    lis     r3,3840
    sraw    r0,r3,r0
    and     r5,r5,r0
    slwi    r0,r23,2
    stw     r5,56(r4)
    add     r6,r29,r0
    lwzu    r0,88(r6)
    cmplwi  r0,128
    bne-	.L_80259108
    slwi    r0,r23,5
    lwzx    r0,r28,r0
    li      r3,1
    cmpwi   r0,-1
    bne-	.L_802590BC
    lwz     r0,68(r29)
    cmpw    r0,r23
    beq-	.L_802590BC
    li      r3,0
.L_802590BC:
    cmpwi   r3,0
    bne-	.L_80259108
    lis     r3,-32768
    lwz     r0,248(r3)
    lis     r3,17180
    lis     r4,-32730
    srwi    r0,r0,2
    addi    r3,r3,-8573
    mulhwu  r0,r3,r0
    srwi    r0,r0,15
    mulli   r0,r0,65
    addi    r8,r4,-24868
    srwi    r10,r0,3
    addi    r3,r23,0
    addi    r4,r13,-23544
    li      r5,1
    li      r7,3
    li      r9,0
    bl	SITransfer
.L_80259108:
    rlwinm  r3,r24,0,3,4
    addis   r0,r3,-6144
    cmplwi  r0,0
    bne-	.L_80259278
    bl	VIGetCurrentLine
    lwz     r0,72(r29)
    addi    r23,r28,480
    addi    r24,r29,72
    addi    r22,r23,0
    addi    r21,r3,1
    rlwinm  r26,r0,16,22,31
    li      r25,0
.L_80259138:
    mr      r3,r25
    bl	SIGetResponseRaw
    cmpwi   r3,0
    beq-	.L_8025914C
    stw     r21,0(r22)
.L_8025914C:
    addi    r25,r25,1
    cmpwi   r25,4
    addi    r22,r22,4
    blt+	.L_80259138
    lwz     r5,0(r24)
    lis     r3,-32768
    li      r0,24
    srw     r0,r3,r0
    and.    r0,r5,r0
    srwi    r6,r26,1
    beq-	.L_80259198
    lwz     r0,0(r23)
    cmplwi  r0,0
    beq-	.L_80259278
    lwz     r0,0(r23)
    add     r0,r6,r0
    cmplw   r0,r21
    bge-	.L_80259198
    b	.L_80259278
.L_80259198:
    li      r0,25
    srw     r0,r3,r0
    and.    r0,r5,r0
    addi    r4,r23,4
    beq-	.L_802591CC
    lwz     r0,0(r4)
    cmplwi  r0,0
    beq-	.L_80259278
    lwz     r0,0(r4)
    add     r0,r6,r0
    cmplw   r0,r21
    bge-	.L_802591CC
    b	.L_80259278
.L_802591CC:
    li      r0,26
    srw     r0,r3,r0
    and.    r0,r5,r0
    addi    r4,r4,4
    beq-	.L_80259200
    lwz     r0,0(r4)
    cmplwi  r0,0
    beq-	.L_80259278
    lwz     r0,0(r4)
    add     r0,r6,r0
    cmplw   r0,r21
    bge-	.L_80259200
    b	.L_80259278
.L_80259200:
    li      r0,27
    srw     r0,r3,r0
    and.    r0,r5,r0
    addi    r4,r4,4
    beq-	.L_80259234
    lwz     r0,0(r4)
    cmplwi  r0,0
    beq-	.L_80259278
    lwz     r0,0(r4)
    add     r0,r6,r0
    cmplw   r0,r21
    bge-	.L_80259234
    b	.L_80259278
.L_80259234:
    li      r22,0
    stw     r22,0(r23)
    addi    r21,r28,416
    stw     r22,484(r28)
    stw     r22,488(r28)
    stw     r22,492(r28)
.L_8025924C:
    lwz     r12,0(r21)
    cmplwi  r12,0
    beq-	.L_80259268
    mtlr    r12
    addi    r3,r30,0
    addi    r4,r31,0
    blrl
.L_80259268:
    addi    r22,r22,1
    cmpwi   r22,4
    addi    r21,r21,4
    blt+	.L_8025924C
.L_80259278:
    lmw     r21,28(r1)
    lwz     r0,76(r1)
    addi    r1,r1,72
    mtlr    r0
    blr
.size SIInterruptHandler, . - SIInterruptHandler

.global __SITransfer
.balign 4
__SITransfer:
/* 0x80259598 | size=0x20C (524 bytes) */
    mflr    r0
    lis     r9,-32700
    stw     r0,4(r1)
    stwu    r1,-72(r1)
    stmw    r25,44(r1)
    addi    r26,r3,0
    addi    r27,r4,0
    addi    r28,r5,0
    addi    r29,r6,0
    addi    r30,r7,0
    addi    r31,r8,0
    addi    r25,r9,-16040
    bl	OSDisableInterrupts
    lwz     r0,68(r25)
    cmpwi   r0,-1
    beq-	.L_802595E4
    bl	OSRestoreInterrupts
    li      r3,0
    b	.L_80259790
.L_802595E4:
    lis     r6,-13312
    slwi    r0,r26,3
    lwz     r7,25656(r6)
    lis     r4,3840
    sraw    r0,r4,r0
    and     r7,r7,r0
    stw     r7,25656(r6)
    addi    r0,r28,3
    srwi    r4,r0,2
    stw     r26,68(r25)
    cmplwi  r4,0
    li      r5,0
    stw     r31,84(r25)
    stw     r30,76(r25)
    stw     r29,80(r25)
    ble-	.L_802596C4
    cmplwi  r4,8
    addi    r7,r4,-8
    ble-	.L_80259778
    addi    r0,r7,7
    srwi    r0,r0,3
    cmplwi  r7,0
    mtctr   r0
    addi    r7,r27,0
    addi    r6,r6,25600
    ble-	.L_80259778
.L_8025964C:
    lwz     r0,0(r7)
    addi    r5,r5,8
    stw     r0,128(r6)
    lwz     r0,4(r7)
    stw     r0,132(r6)
    lwz     r0,8(r7)
    stw     r0,136(r6)
    lwz     r0,12(r7)
    stw     r0,140(r6)
    lwz     r0,16(r7)
    stw     r0,144(r6)
    lwz     r0,20(r7)
    stw     r0,148(r6)
    lwz     r0,24(r7)
    stw     r0,152(r6)
    lwz     r0,28(r7)
    addi    r7,r7,32
    stw     r0,156(r6)
    addi    r6,r6,32
    bdnz+	.L_8025964C
    b	.L_80259778
.L_802596A0:
    subf    r0,r5,r4
    cmplw   r5,r4
    mtctr   r0
    bge-	.L_802596C4
.L_802596B0:
    lwz     r0,0(r6)
    addi    r6,r6,4
    stw     r0,128(r7)
    addi    r7,r7,4
    bdnz+	.L_802596B0
.L_802596C4:
    lis     r4,-13312
    addi    r6,r4,25600
    lwzu    r0,52(r6)
    li      r4,1
    stw     r0,36(r1)
    cmplwi  r31,0
    lbz     r0,36(r1)
    rlwimi  r0,r4,7,24,24
    stb     r0,36(r1)
    beq-	.L_802596F0
    b	.L_802596F4
.L_802596F0:
    li      r4,0
.L_802596F4:
    lbz     r0,36(r1)
    rlwimi  r0,r4,6,25,25
    cmplwi  r28,128
    stb     r0,36(r1)
    bne-	.L_80259710
    li      r0,0
    b	.L_80259714
.L_80259710:
    mr      r0,r28
.L_80259714:
    clrlwi  r4,r0,24
    lbz     r0,37(r1)
    rlwimi  r0,r4,0,25,31
    cmplwi  r30,128
    stb     r0,37(r1)
    bne-	.L_80259734
    li      r0,0
    b	.L_80259738
.L_80259734:
    mr      r0,r30
.L_80259738:
    clrlwi  r4,r0,24
    lbz     r0,38(r1)
    rlwimi  r0,r4,0,25,31
    stb     r0,38(r1)
    li      r4,1
    lbz     r0,39(r1)
    rlwimi  r0,r26,1,29,30
    stb     r0,39(r1)
    lbz     r0,39(r1)
    rlwimi  r0,r4,0,31,31
    stb     r0,39(r1)
    lwz     r0,36(r1)
    stw     r0,0(r6)
    bl	OSRestoreInterrupts
    li      r3,1
    b	.L_80259790
.L_80259778:
    lis     r6,-13312
    slwi    r0,r5,2
    addi    r7,r6,25600
    add     r6,r27,r0
    add     r7,r7,r0
    b	.L_802596A0
.L_80259790:
    lmw     r25,44(r1)
    lwz     r0,76(r1)
    addi    r1,r1,72
    mtlr    r0
    blr
.size __SITransfer, . - __SITransfer

.global SISync
.balign 4
SISync:
/* 0x802597A4 | size=0x108 (264 bytes) */
    mflr    r0
    lis     r3,-13312
    stw     r0,4(r1)
    addi    r3,r3,25600
    stwu    r1,-32(r1)
    stmw    r26,8(r1)
.L_802597BC:
    lwz     r0,52(r3)
    clrlwi. r0,r0,31
    bne+	.L_802597BC
    bl	OSDisableInterrupts
    mr      r31,r3
    bl	CompleteTransfer
    lis     r4,-32694
    addi    r30,r3,0
    addi    r29,r4,-21872
    li      r27,4
    li      r28,0
.L_802597E8:
    addi    r27,r27,1
    srawi   r0,r27,2
    addze   r0,r0
    slwi    r0,r0,2
    subfc   r0,r0,r27
    mr      r27,r0
    slwi    r0,r0,5
    add     r26,r29,r0
    lwz     r0,0(r26)
    cmpwi   r0,-1
    beq-	.L_80259880
    bl	__OSGetSystemTime
    lwz     r0,24(r26)
    xoris   r5,r3,32768
    lwz     r6,28(r26)
    xoris   r3,r0,32768
    subfc   r0,r6,r4
    subfe   r3,r3,r5
    subfe   r3,r5,r5
    neg.    r3,r3
    bne-	.L_80259880
    lwz     r3,0(r26)
    lwz     r4,4(r26)
    lwz     r5,8(r26)
    lwz     r6,12(r26)
    lwz     r7,16(r26)
    lwz     r8,20(r26)
    bl	__SITransfer
    cmpwi   r3,0
    beq-	.L_8025988C
    mulli   r4,r27,40
    lis     r3,-32694
    addi    r0,r3,-21744
    add     r3,r0,r4
    bl	OSCancelAlarm
    li      r0,-1
    stw     r0,0(r26)
    b	.L_8025988C
.L_80259880:
    addi    r28,r28,1
    cmpwi   r28,4
    blt+	.L_802597E8
.L_8025988C:
    mr      r3,r31
    bl	OSRestoreInterrupts
    mr      r3,r30
    lmw     r26,8(r1)
    lwz     r0,36(r1)
    addi    r1,r1,32
    mtlr    r0
    blr
.size SISync, . - SISync

.global SITransfer
.balign 4
SITransfer:
/* 0x80259CF8 | size=0x16C (364 bytes) */
    mflr    r0
    stw     r0,4(r1)
    stwu    r1,-96(r1)
    stmw    r19,44(r1)
    addi    r24,r3,0
    lis     r3,-32694
    addi    r23,r3,-21872
    slwi    r0,r24,5
    addi    r25,r4,0
    addi    r26,r5,0
    addi    r27,r6,0
    addi    r28,r7,0
    addi    r29,r8,0
    addi    r31,r9,0
    addi    r30,r10,0
    add     r22,r23,r0
    bl	OSDisableInterrupts
    lwz     r0,0(r22)
    addi    r21,r3,0
    cmpwi   r0,-1
    bne-	.L_80259D5C
    lis     r3,-32700
    lwz     r0,-15972(r3)
    cmpw    r0,r24
    bne-	.L_80259D6C
.L_80259D5C:
    mr      r3,r21
    bl	OSRestoreInterrupts
    li      r3,0
    b	.L_80259E50
.L_80259D6C:
    bl	__OSGetSystemTime
    li      r0,0
    xor     r5,r30,r0
    xor     r0,r31,r0
    or.     r0,r5,r0
    bne-	.L_80259D90
    addi    r19,r4,0
    addi    r20,r3,0
    b	.L_80259DA8
.L_80259D90:
    slwi    r0,r24,3
    add     r6,r23,r0
    lwz     r5,324(r6)
    lwz     r0,320(r6)
    addc    r19,r30,r5
    adde    r20,r31,r0
.L_80259DA8:
    xoris   r6,r3,32768
    xoris   r5,r20,32768
    subfc   r0,r19,r4
    subfe   r5,r5,r6
    subfe   r5,r6,r6
    neg.    r5,r5
    beq-	.L_80259DF0
    mulli   r0,r24,40
    subfc   r30,r4,r19
    subfe   r31,r3,r20
    lis     r4,-32730
    add     r3,r23,r0
    addi    r7,r4,-25492
    addi    r6,r30,0
    addi    r5,r31,0
    addi    r3,r3,128
    bl	OSSetAlarm
    b	.L_80259E24
.L_80259DF0:
    addi    r3,r24,0
    addi    r4,r25,0
    addi    r5,r26,0
    addi    r6,r27,0
    addi    r7,r28,0
    addi    r8,r29,0
    bl	__SITransfer
    cmpwi   r3,0
    beq-	.L_80259E24
    mr      r3,r21
    bl	OSRestoreInterrupts
    li      r3,1
    b	.L_80259E50
.L_80259E24:
    stw     r24,0(r22)
    mr      r3,r21
    stw     r25,4(r22)
    stw     r26,8(r22)
    stw     r27,12(r22)
    stw     r28,16(r22)
    stw     r29,20(r22)
    stw     r19,28(r22)
    stw     r20,24(r22)
    bl	OSRestoreInterrupts
    li      r3,1
.L_80259E50:
    lmw     r19,44(r1)
    lwz     r0,100(r1)
    addi    r1,r1,96
    mtlr    r0
    blr
.size SITransfer, . - SITransfer

.global GetTypeCallback
.balign 4
GetTypeCallback:
/* 0x80259EDC | size=0x298 (664 bytes) */
    mflr    r0
    stw     r0,4(r1)
    stwu    r1,-48(r1)
    stmw    r26,24(r1)
    addi    r27,r3,0
    lis     r3,-32700
    addi    r0,r3,-15952
    slwi    r29,r27,2
    add     r30,r0,r29
    lis     r3,-32694
    addi    r26,r4,0
    addi    r31,r3,-21872
    lwz     r0,0(r30)
    rlwinm  r0,r0,0,25,23
    stw     r0,0(r30)
    lwz     r0,0(r30)
    or      r0,r0,r26
    stw     r0,0(r30)
    bl	__OSGetSystemTime
    slwi    r0,r27,3
    add     r5,r31,r0
    stw     r4,292(r5)
    lis     r4,-32768
    clrlwi. r0,r26,28
    stw     r3,288(r5)
    srw     r4,r4,r27
    lwz     r3,-23536(r13)
    lwz     r28,0(r30)
    andc    r0,r3,r4
    stw     r0,-23536(r13)
    and     r26,r3,r4
    bne-	.L_80259F7C
    rlwinm  r3,r28,0,3,4
    addis   r0,r3,-2048
    cmplwi  r0,0
    bne-	.L_80259F7C
    clrrwi. r0,r28,31
    beq-	.L_80259F7C
    rlwinm. r0,r28,0,5,5
    beq-	.L_80259FD4
.L_80259F7C:
    addi    r3,r27,0
    li      r4,0
    bl	OSSetWirelessID
    slwi    r0,r27,4
    lwz     r30,0(r30)
    add     r31,r31,r0
    li      r29,0
    addi    r28,r29,0
    addi    r31,r31,352
.L_80259FA0:
    lwz     r12,0(r31)
    cmplwi  r12,0
    beq-	.L_80259FC0
    stw     r28,0(r31)
    mtlr    r12
    addi    r3,r27,0
    addi    r4,r30,0
    blrl
.L_80259FC0:
    addi    r29,r29,1
    cmpwi   r29,4
    addi    r31,r31,4
    blt+	.L_80259FA0
    b	.L_8025A160
.L_80259FD4:
    mr      r3,r27
    bl	OSGetWirelessID
    cmpwi   r26,0
    rlwinm  r26,r3,8,8,23
    beq-	.L_8025A038
    rlwinm. r0,r26,0,11,11
    beq-	.L_8025A038
    lis     r3,208
    addi    r0,r3,-256
    and     r0,r26,r0
    oris    r0,r0,19984
    add     r4,r31,r29
    stwu    r0,496(r4)
    li      r0,128
    lis     r3,-32730
    stw     r0,0(r30)
    addi    r8,r3,-24868
    addi    r3,r27,0
    addi    r6,r30,0
    li      r5,3
    li      r7,3
    li      r10,0
    li      r9,0
    bl	SITransfer
    b	.L_8025A160
.L_8025A038:
    rlwinm. r0,r28,0,11,11
    beq-	.L_8025A0AC
    lis     r3,208
    addi    r3,r3,-256
    and     r0,r26,r3
    and     r3,r28,r3
    cmplw   r0,r3
    beq-	.L_8025A118
    rlwinm. r0,r26,0,11,11
    bne-	.L_8025A070
    oris    r26,r3,16
    addi    r3,r27,0
    rlwinm  r4,r26,24,16,31
    bl	OSSetWirelessID
.L_8025A070:
    oris    r0,r26,19968
    add     r4,r31,r29
    stwu    r0,496(r4)
    li      r0,128
    lis     r3,-32730
    stw     r0,0(r30)
    addi    r8,r3,-24868
    addi    r3,r27,0
    addi    r6,r30,0
    li      r5,3
    li      r7,3
    li      r10,0
    li      r9,0
    bl	SITransfer
    b	.L_8025A160
.L_8025A0AC:
    rlwinm. r0,r28,0,1,1
    beq-	.L_8025A10C
    lis     r3,208
    addi    r0,r3,-256
    and     r28,r28,r0
    oris    r28,r28,16
    addi    r3,r27,0
    rlwinm  r4,r28,24,16,31
    bl	OSSetWirelessID
    oris    r0,r28,19968
    add     r4,r31,r29
    stwu    r0,496(r4)
    li      r0,128
    lis     r3,-32730
    stw     r0,0(r30)
    addi    r8,r3,-24868
    addi    r3,r27,0
    addi    r6,r30,0
    li      r5,3
    li      r7,3
    li      r10,0
    li      r9,0
    bl	SITransfer
    b	.L_8025A160
.L_8025A10C:
    addi    r3,r27,0
    li      r4,0
    bl	OSSetWirelessID
.L_8025A118:
    slwi    r0,r27,4
    lwz     r30,0(r30)
    add     r31,r31,r0
    li      r29,0
    addi    r28,r29,0
    addi    r31,r31,352
.L_8025A130:
    lwz     r12,0(r31)
    cmplwi  r12,0
    beq-	.L_8025A150
    stw     r28,0(r31)
    mtlr    r12
    addi    r3,r27,0
    addi    r4,r30,0
    blrl
.L_8025A150:
    addi    r29,r29,1
    cmpwi   r29,4
    addi    r31,r31,4
    blt+	.L_8025A130
.L_8025A160:
    lmw     r26,24(r1)
    lwz     r0,52(r1)
    addi    r1,r1,48
    mtlr    r0
    blr
.size GetTypeCallback, . - GetTypeCallback

.global SIGetType
.balign 4
SIGetType:
/* 0x8025A174 | size=0x1C4 (452 bytes) */
    mflr    r0
    stw     r0,4(r1)
    stwu    r1,-40(r1)
    stmw    r27,20(r1)
    mr      r27,r3
    bl	OSDisableInterrupts
    lis     r4,-32700
    slwi    r5,r27,2
    addi    r0,r4,-15952
    add     r30,r0,r5
    lwz     r28,0(r30)
    mr      r29,r3
    bl	__OSGetSystemTime
    lis     r5,-32694
    slwi    r6,r27,3
    addi    r0,r5,-21584
    add     r31,r0,r6
    lwz     r6,4(r31)
    lis     r5,-32700
    addi    r5,r5,-15972
    lwz     r0,0(r31)
    subfc   r4,r6,r4
    subfe   r0,r0,r3
    lwz     r6,4(r5)
    li      r5,128
    sraw    r3,r5,r27
    and.    r3,r6,r3
    beq-	.L_8025A214
    cmplwi  r28,8
    beq-	.L_8025A208
    bl	__OSGetSystemTime
    stw     r4,4(r31)
    stw     r3,0(r31)
    mr      r3,r29
    bl	OSRestoreInterrupts
    mr      r3,r28
    b	.L_8025A324
.L_8025A208:
    stw     r5,0(r30)
    li      r28,128
    b	.L_8025A2C4
.L_8025A214:
    lis     r3,-32768
    lwz     r6,248(r3)
    lis     r5,4194
    addi    r5,r5,19923
    srwi    r6,r6,2
    mulhwu  r5,r5,r6
    srwi    r5,r5,6
    mulli   r7,r5,50
    li      r3,0
    xoris   r6,r3,32768
    xoris   r5,r0,32768
    subfc   r3,r4,r7
    subfe   r5,r5,r6
    subfe   r5,r6,r6
    neg.    r5,r5
    bne-	.L_8025A26C
    cmplwi  r28,8
    beq-	.L_8025A26C
    mr      r3,r29
    bl	OSRestoreInterrupts
    mr      r3,r28
    b	.L_8025A324
.L_8025A26C:
    lis     r3,-32768
    lwz     r6,248(r3)
    lis     r5,4194
    addi    r5,r5,19923
    srwi    r6,r6,2
    mulhwu  r5,r5,r6
    srwi    r5,r5,6
    mulli   r6,r5,75
    li      r3,0
    xoris   r5,r3,32768
    xoris   r3,r0,32768
    subfc   r0,r4,r6
    subfe   r3,r3,r5
    subfe   r3,r5,r5
    neg.    r3,r3
    bne-	.L_8025A2B8
    li      r0,128
    stw     r0,0(r30)
    b	.L_8025A2C4
.L_8025A2B8:
    li      r0,128
    stw     r0,0(r30)
    li      r28,128
.L_8025A2C4:
    bl	__OSGetSystemTime
    stw     r4,4(r31)
    lis     r4,17180
    lis     r5,-32730
    stw     r3,0(r31)
    lis     r3,-32768
    addi    r8,r5,-24868
    lwz     r0,248(r3)
    addi    r4,r4,-8573
    addi    r3,r27,0
    srwi    r0,r0,2
    mulhwu  r0,r4,r0
    srwi    r0,r0,15
    mulli   r0,r0,65
    srwi    r10,r0,3
    addi    r6,r30,0
    addi    r4,r13,-23540
    li      r5,1
    li      r7,3
    li      r9,0
    bl	SITransfer
    mr      r3,r29
    bl	OSRestoreInterrupts
    mr      r3,r28
.L_8025A324:
    lmw     r27,20(r1)
    lwz     r0,44(r1)
    addi    r1,r1,40
    mtlr    r0
    blr
.size SIGetType, . - SIGetType

.global SIGetTypeAsync
.balign 4
SIGetTypeAsync:
/* 0x8025A338 | size=0x13C (316 bytes) */
    mflr    r0
    stw     r0,4(r1)
    stwu    r1,-32(r1)
    stw     r31,28(r1)
    addi    r31,r4,0
    stw     r30,24(r1)
    stw     r29,20(r1)
    stw     r28,16(r1)
    addi    r28,r3,0
    bl	OSDisableInterrupts
    addi    r30,r3,0
    addi    r3,r28,0
    bl	SIGetType
    lis     r4,-32700
    slwi    r5,r28,2
    addi    r0,r4,-15952
    add     r4,r0,r5
    lwz     r0,0(r4)
    addi    r29,r3,0
    rlwinm. r0,r0,0,24,24
    beq-	.L_8025A434
    lis     r3,-32694
    slwi    r4,r28,4
    addi    r0,r3,-21520
    add     r4,r0,r4
    lwz     r0,0(r4)
    li      r5,0
    cmplw   r0,r31
    beq-	.L_8025A448
    cmplwi  r0,0
    bne-	.L_8025A3C0
    slwi    r0,r5,2
    stwx    r31,r4,r0
    b	.L_8025A448
.L_8025A3C0:
    addi    r3,r4,4
    lwz     r0,4(r4)
    li      r5,1
    cmplw   r0,r31
    beq-	.L_8025A448
    cmplwi  r0,0
    bne-	.L_8025A3E8
    slwi    r0,r5,2
    stwx    r31,r4,r0
    b	.L_8025A448
.L_8025A3E8:
    lwzu    r0,4(r3)
    li      r5,2
    cmplw   r0,r31
    beq-	.L_8025A448
    cmplwi  r0,0
    bne-	.L_8025A40C
    slwi    r0,r5,2
    stwx    r31,r4,r0
    b	.L_8025A448
.L_8025A40C:
    lwz     r0,4(r3)
    li      r5,3
    cmplw   r0,r31
    beq-	.L_8025A448
    cmplwi  r0,0
    bne-	.L_8025A448
    slwi    r0,r5,2
    stwx    r31,r4,r0
    b	.L_8025A448
    b	.L_8025A448
.L_8025A434:
    addi    r12,r31,0
    mtlr    r12
    addi    r3,r28,0
    addi    r4,r29,0
    blrl
.L_8025A448:
    mr      r3,r30
    bl	OSRestoreInterrupts
    mr      r3,r29
    lwz     r0,36(r1)
    lwz     r31,28(r1)
    lwz     r30,24(r1)
    lwz     r29,20(r1)
    lwz     r28,16(r1)
    addi    r1,r1,32
    mtlr    r0
    blr
.size SIGetTypeAsync, . - SIGetTypeAsync

.global SIDecodeType
.balign 4
SIDecodeType:
/* 0x8025A474 | size=0x14C (332 bytes) */
    rlwinm. r0,r3,0,28,28
    clrlwi  r4,r3,24
    clrrwi  r5,r3,8
    beq-	.L_8025A48C
    li      r3,8
    blr
.L_8025A48C:
    andi.   r0,r4,71
    beq-	.L_8025A49C
    li      r3,64
    blr
.L_8025A49C:
    cmplwi  r4,0
    beq-	.L_8025A4AC
    li      r3,128
    blr
.L_8025A4AC:
    rlwinm. r3,r5,0,3,4
    bne-	.L_8025A514
    clrrwi  r3,r5,16
    lis     r0,4
    cmpw    r3,r0
    beqlr-
    bge-	.L_8025A4E8
    lis     r0,2
    cmpw    r3,r0
    beqlr-
    bge-	.L_8025A50C
    lis     r0,1
    cmpw    r3,r0
    beqlr-
    b	.L_8025A50C
.L_8025A4E8:
    lis     r0,1280
    cmpw    r3,r0
    beqlr-
    bge-	.L_8025A50C
    lis     r0,512
    cmpw    r3,r0
    beqlr-
    b	.L_8025A50C
    blr
.L_8025A50C:
    li      r3,64
    blr
.L_8025A514:
    addis   r0,r3,-2048
    cmplwi  r0,0
    beq-	.L_8025A528
    li      r3,64
    blr
.L_8025A528:
    clrrwi  r3,r5,16
    lis     r0,2304
    cmpw    r3,r0
    beqlr-
    bge-	.L_8025A550
    lis     r0,2048
    cmpw    r3,r0
    beqlr-
    b	.L_8025A550
    blr
.L_8025A550:
    clrrwi  r3,r5,21
    addis   r0,r3,-2080
    cmplwi  r0,0
    bne-	.L_8025A568
    lis     r3,2080
    blr
.L_8025A568:
    clrrwi. r0,r5,31
    beq-	.L_8025A5A0
    rlwinm. r0,r5,0,5,5
    bne-	.L_8025A5A0
    andis.  r3,r5,35600
    addis   r0,r3,29936
    cmplwi  r0,0
    bne-	.L_8025A590
    lis     r3,-29936
    blr
.L_8025A590:
    rlwinm. r0,r5,0,6,6
    bne-	.L_8025A5A0
    lis     r3,-30720
    blr
.L_8025A5A0:
    andis.  r3,r5,2304
    addis   r0,r3,-2304
    cmplwi  r0,0
    bne-	.L_8025A5B8
    lis     r3,2304
    blr
.L_8025A5B8:
    li      r3,64
    blr
.size SIDecodeType, . - SIDecodeType

.global SIGetTypeString
.balign 4
SIGetTypeString:
/* 0x8025A5E4 | size=0x158 (344 bytes) */
    mflr    r0
    lis     r4,-32700
    stw     r0,4(r1)
    stwu    r1,-24(r1)
    stw     r31,20(r1)
    addi    r31,r4,-16040
    bl	SIDecodeType
    lis     r0,2
    cmpw    r3,r0
    beq-	.L_8025A6E4
    bge-	.L_8025A664
    cmpwi   r3,64
    beq-	.L_8025A724
    bge-	.L_8025A648
    lis     r0,-29936
    cmpw    r3,r0
    beq-	.L_8025A70C
    bge-	.L_8025A63C
    lis     r0,-30720
    cmpw    r3,r0
    beq-	.L_8025A704
    b	.L_8025A724
.L_8025A63C:
    cmpwi   r3,8
    beq-	.L_8025A6C4
    b	.L_8025A724
.L_8025A648:
    lis     r0,1
    cmpw    r3,r0
    beq-	.L_8025A6DC
    bge-	.L_8025A724
    cmpwi   r3,128
    beq-	.L_8025A6CC
    b	.L_8025A724
.L_8025A664:
    lis     r0,2048
    cmpw    r3,r0
    beq-	.L_8025A71C
    bge-	.L_8025A6A4
    lis     r0,512
    cmpw    r3,r0
    beq-	.L_8025A6EC
    bge-	.L_8025A694
    lis     r0,4
    cmpw    r3,r0
    beq-	.L_8025A6F4
    b	.L_8025A724
.L_8025A694:
    lis     r0,1280
    cmpw    r3,r0
    beq-	.L_8025A6D4
    b	.L_8025A724
.L_8025A6A4:
    lis     r0,2304
    cmpw    r3,r0
    beq-	.L_8025A6FC
    bge-	.L_8025A724
    lis     r0,2080
    cmpw    r3,r0
    beq-	.L_8025A714
    b	.L_8025A724
.L_8025A6C4:
    addi    r3,r31,104
    b	.L_8025A728
.L_8025A6CC:
    addi    r3,r13,-27828
    b	.L_8025A728
.L_8025A6D4:
    addi    r3,r31,116
    b	.L_8025A728
.L_8025A6DC:
    addi    r3,r31,132
    b	.L_8025A728
.L_8025A6E4:
    addi    r3,r31,148
    b	.L_8025A728
.L_8025A6EC:
    addi    r3,r31,164
    b	.L_8025A728
.L_8025A6F4:
    addi    r3,r31,176
    b	.L_8025A728
.L_8025A6FC:
    addi    r3,r31,192
    b	.L_8025A728
.L_8025A704:
    addi    r3,r31,212
    b	.L_8025A728
.L_8025A70C:
    addi    r3,r31,232
    b	.L_8025A728
.L_8025A714:
    addi    r3,r31,252
    b	.L_8025A728
.L_8025A71C:
    addi    r3,r31,264
    b	.L_8025A728
.L_8025A724:
    addi    r3,r13,-27820
.L_8025A728:
    lwz     r0,28(r1)
    lwz     r31,20(r1)
    addi    r1,r1,24
    mtlr    r0
    blr
.size SIGetTypeString, . - SIGetTypeString

#
# === vi.o (vi.a) ===
#

.global VISetRegs
.balign 4
VISetRegs:
/* 0x80261EC8 | size=0x120 (288 bytes) */
    mflr    r0
    lis     r3,-32694
    stw     r0,4(r1)
    stwu    r1,-32(r1)
    stw     r31,28(r1)
    addi    r31,r3,-16744
    stw     r30,24(r1)
    stw     r29,20(r1)
    stw     r28,16(r1)
    lwz     r0,-23232(r13)
    cmplwi  r0,1
    bne-	.L_80261F04
    bl	getCurrentFieldEvenOdd
    cmplwi  r3,0
    beq-	.L_80261FC4
.L_80261F04:
    lis     r3,-13312
    addi    r30,r3,8192
    b	.L_80261F84
.L_80261F10:
    lwz     r3,-23224(r13)
    li      r5,32
    lwz     r28,-23220(r13)
    addi    r4,r28,0
    bl	__shr2u
    cntlzw  r4,r4
    cmpwi   r4,32
    li      r0,-1
    and     r0,r28,r0
    bge-	.L_80261F3C
    b	.L_80261F44
.L_80261F3C:
    cntlzw  r3,r0
    addi    r4,r3,32
.L_80261F44:
    slwi    r6,r4,1
    add     r3,r31,r6
    lhz     r0,120(r3)
    subfic  r5,r4,63
    li      r3,0
    sthx    r0,r30,r6
    li      r4,1
    bl	__shl2i
    lwz     r0,-23224(r13)
    not     r5,r3
    not     r4,r4
    lwz     r3,-23220(r13)
    and     r0,r0,r5
    and     r3,r3,r4
    stw     r3,-23220(r13)
    stw     r0,-23224(r13)
.L_80261F84:
    lwz     r0,-23224(r13)
    li      r4,0
    lwz     r3,-23220(r13)
    xor     r0,r0,r4
    xor     r3,r3,r4
    or.     r0,r3,r0
    bne+	.L_80261F10
    stw     r4,-23232(r13)
    li      r3,1
    lwz     r0,-23208(r13)
    lwz     r4,324(r31)
    stw     r4,-23216(r13)
    lwz     r4,280(r31)
    stw     r4,-23212(r13)
    stw     r0,-23204(r13)
    b	.L_80261FC8
.L_80261FC4:
    li      r3,0
.L_80261FC8:
    lwz     r0,36(r1)
    lwz     r31,28(r1)
    lwz     r30,24(r1)
    lwz     r29,20(r1)
    lwz     r28,16(r1)
    addi    r1,r1,32
    mtlr    r0
    blr
.size VISetRegs, . - VISetRegs

.global __VIRetraceHandler
.balign 4
__VIRetraceHandler:
/* 0x80261FE8 | size=0x274 (628 bytes) */
    mflr    r0
    lis     r3,-13312
    stw     r0,4(r1)
    addi    r5,r3,8192
    lis     r3,-32694
    stwu    r1,-760(r1)
    li      r7,0
    stmw    r27,740(r1)
    addi    r30,r4,0
    addi    r31,r3,-16744
    lhzu    r6,48(r5)
    rlwinm. r0,r6,0,16,16
    beq-	.L_80262028
    rlwinm  r0,r6,0,17,15
    sth     r0,0(r5)
    ori     r7,r7,1
.L_80262028:
    lis     r3,-13312
    lhzu    r4,8244(r3)
    rlwinm. r0,r4,0,16,16
    beq-	.L_80262044
    rlwinm  r0,r4,0,17,15
    sth     r0,0(r3)
    ori     r7,r7,2
.L_80262044:
    lis     r3,-13312
    lhzu    r4,8248(r3)
    rlwinm. r0,r4,0,16,16
    beq-	.L_80262060
    rlwinm  r0,r4,0,17,15
    sth     r0,0(r3)
    ori     r7,r7,4
.L_80262060:
    lis     r3,-13312
    lhzu    r4,8252(r3)
    rlwinm. r0,r4,0,16,16
    beq-	.L_8026207C
    rlwinm  r0,r4,0,17,15
    sth     r0,0(r3)
    ori     r7,r7,8
.L_8026207C:
    rlwinm. r0,r7,0,29,29
    bne-	.L_8026208C
    rlwinm. r0,r7,0,28,28
    beq-	.L_802620DC
.L_8026208C:
    addi    r3,r1,24
    bl	OSClearContext
    addi    r3,r1,24
    bl	OSSetCurrentContext
    lwz     r0,-23260(r13)
    cmplwi  r0,0
    beq-	.L_802620C8
    addi    r3,r1,22
    addi    r4,r1,20
    bl	__VIGetCurrentPosition
    lwz     r12,-23260(r13)
    lha     r3,22(r1)
    mtlr    r12
    lha     r4,20(r1)
    blrl
.L_802620C8:
    addi    r3,r1,24
    bl	OSClearContext
    mr      r3,r30
    bl	OSSetCurrentContext
    b	.L_80262248
.L_802620DC:
    lwz     r4,-23284(r13)
    addi    r3,r1,24
    addi    r0,r4,1
    stw     r0,-23284(r13)
    bl	OSClearContext
    addi    r3,r1,24
    bl	OSSetCurrentContext
    lwz     r12,-23268(r13)
    cmplwi  r12,0
    beq-	.L_80262110
    lwz     r3,-23284(r13)
    mtlr    r12
    blrl
.L_80262110:
    lwz     r0,-23280(r13)
    cmplwi  r0,0
    beq-	.L_8026220C
    lwz     r0,-23232(r13)
    cmplwi  r0,1
    bne-	.L_80262134
    bl	getCurrentFieldEvenOdd
    cmplwi  r3,0
    beq-	.L_802621F4
.L_80262134:
    lis     r3,-13312
    addi    r29,r3,8192
    b	.L_802621B4
.L_80262140:
    lwz     r3,-23224(r13)
    li      r5,32
    lwz     r27,-23220(r13)
    addi    r4,r27,0
    bl	__shr2u
    cntlzw  r4,r4
    cmpwi   r4,32
    li      r0,-1
    and     r0,r27,r0
    bge-	.L_8026216C
    b	.L_80262174
.L_8026216C:
    cntlzw  r3,r0
    addi    r4,r3,32
.L_80262174:
    slwi    r6,r4,1
    add     r3,r31,r6
    lhz     r0,120(r3)
    subfic  r5,r4,63
    li      r3,0
    sthx    r0,r29,r6
    li      r4,1
    bl	__shl2i
    lwz     r0,-23224(r13)
    not     r5,r3
    not     r4,r4
    lwz     r3,-23220(r13)
    and     r0,r0,r5
    and     r3,r3,r4
    stw     r3,-23220(r13)
    stw     r0,-23224(r13)
.L_802621B4:
    lwz     r0,-23224(r13)
    li      r4,0
    lwz     r3,-23220(r13)
    xor     r0,r0,r4
    xor     r3,r3,r4
    or.     r0,r3,r0
    bne+	.L_80262140
    stw     r4,-23232(r13)
    li      r4,1
    lwz     r0,-23208(r13)
    lwz     r3,324(r31)
    stw     r3,-23216(r13)
    lwz     r3,280(r31)
    stw     r3,-23212(r13)
    stw     r0,-23204(r13)
    b	.L_802621F8
.L_802621F4:
    li      r4,0
.L_802621F8:
    cmpwi   r4,0
    beq-	.L_8026220C
    li      r0,0
    stw     r0,-23280(r13)
    bl	SIRefreshSamplingRate
.L_8026220C:
    lwz     r0,-23264(r13)
    cmplwi  r0,0
    beq-	.L_80262230
    addi    r3,r1,24
    bl	OSClearContext
    lwz     r12,-23264(r13)
    lwz     r3,-23284(r13)
    mtlr    r12
    blrl
.L_80262230:
    addi    r3,r13,-23276
    bl	OSWakeupThread
    addi    r3,r1,24
    bl	OSClearContext
    mr      r3,r30
    bl	OSSetCurrentContext
.L_80262248:
    lmw     r27,740(r1)
    lwz     r0,764(r1)
    addi    r1,r1,760
    mtlr    r0
    blr
.size __VIRetraceHandler, . - __VIRetraceHandler

.global __VIInit
.balign 4
__VIInit:
/* 0x8026239C | size=0x204 (516 bytes) */
    mflr    r0
    lis     r4,-32768
    stw     r0,4(r1)
    srwi    r0,r3,2
    stwu    r1,-40(r1)
    stw     r31,36(r1)
    clrlwi  r31,r3,30
    stw     r30,32(r1)
    mr      r30,r0
    stw     r0,204(r4)
    bl	getTiming
    lis     r4,-13312
    li      r0,2
    addi    r5,r4,8192
    sthu    r0,2(r5)
    li      r0,0
    stw     r0,28(r1)
    lwz     r0,28(r1)
    cmplwi  r0,1000
    bge-	.L_80262408
    b	.L_802623FC
.L_802623F0:
    lwz     r4,28(r1)
    addi    r0,r4,8
    stw     r0,28(r1)
.L_802623FC:
    lwz     r0,28(r1)
    cmplwi  r0,1000
    blt+	.L_802623F0
.L_80262408:
    li      r0,0
    sth     r0,0(r5)
    lis     r11,-13312
    li      r7,10280
    lhz     r0,26(r3)
    li      r6,1
    cmpwi   r30,4
    sth     r0,8198(r11)
    li      r0,4097
    lbz     r8,29(r3)
    lbz     r9,30(r3)
    rlwimi  r9,r8,8,16,23
    sth     r9,8196(r11)
    lbz     r8,31(r3)
    lbz     r9,28(r3)
    slwi    r8,r8,7
    or      r8,r9,r8
    sth     r8,8202(r11)
    lhz     r8,32(r3)
    rlwinm  r8,r8,1,16,30
    sth     r8,8200(r11)
    lhz     r8,2(r3)
    lbz     r10,0(r3)
    slwi    r8,r8,1
    lhz     r9,4(r3)
    addi    r8,r8,-2
    sth     r10,8192(r11)
    add     r8,r9,r8
    sth     r8,8206(r11)
    lhz     r8,8(r3)
    addi    r8,r8,2
    sth     r8,8204(r11)
    lhz     r8,2(r3)
    lhz     r9,6(r3)
    slwi    r8,r8,1
    addi    r8,r8,-2
    add     r8,r9,r8
    sth     r8,8210(r11)
    lhz     r8,10(r3)
    addi    r8,r8,2
    sth     r8,8208(r11)
    lhz     r8,16(r3)
    lbz     r9,12(r3)
    slwi    r8,r8,5
    or      r8,r9,r8
    sth     r8,8214(r11)
    lhz     r8,20(r3)
    lbz     r9,14(r3)
    slwi    r8,r8,5
    or      r8,r9,r8
    sth     r8,8212(r11)
    lhz     r8,18(r3)
    lbz     r9,13(r3)
    slwi    r8,r8,5
    or      r8,r9,r8
    sth     r8,8218(r11)
    lhz     r8,22(r3)
    lbz     r9,15(r3)
    slwi    r8,r8,5
    or      r8,r9,r8
    sth     r8,8216(r11)
    sth     r7,8264(r11)
    sth     r6,8246(r11)
    sth     r0,8244(r11)
    lhz     r0,24(r3)
    lhz     r3,26(r3)
    srawi   r6,r0,1
    addi    r0,r3,1
    addze   r6,r6
    sth     r0,8242(r11)
    addi    r3,r6,1
    ori     r0,r3,4096
    sth     r0,8240(r11)
    bge-	.L_80262544
    cmpwi   r30,1
    bge-	.L_8026253C
    b	.L_80262544
.L_8026253C:
    mr      r3,r30
    b	.L_80262548
.L_80262544:
    li      r3,0
.L_80262548:
    cmplwi  r31,1
    bgt-	.L_80262570
    rlwinm  r0,r31,2,29,29
    ori     r0,r0,1
    rlwimi  r0,r3,8,0,23
    sth     r0,0(r5)
    lis     r3,-13312
    li      r0,0
    sth     r0,8300(r3)
    b	.L_80262588
.L_80262570:
    slwi    r0,r3,8
    ori     r0,r0,5
    sth     r0,0(r5)
    lis     r3,-13312
    li      r0,1
    sth     r0,8300(r3)
.L_80262588:
    lwz     r0,44(r1)
    lwz     r31,36(r1)
    lwz     r30,32(r1)
    addi    r1,r1,40
    mtlr    r0
    blr
.size __VIInit, . - __VIInit

.global AdjustPosition
.balign 4
AdjustPosition:
/* 0x802625A0 | size=0x160 (352 bytes) */
    lis     r4,-32694
    lha     r5,-23252(r13)
    addi    r4,r4,-16744
    lha     r6,240(r4)
    lhz     r0,244(r4)
    add     r5,r6,r5
    subfic  r0,r0,720
    cmpw    r5,r0
    ble-	.L_802625C8
    b	.L_802625D8
.L_802625C8:
    cmpwi   r5,0
    bge-	.L_802625D4
    li      r5,0
.L_802625D4:
    mr      r0,r5
.L_802625D8:
    sth     r0,248(r4)
    lwz     r0,272(r4)
    cmpwi   r0,0
    bne-	.L_802625F0
    li      r6,2
    b	.L_802625F4
.L_802625F0:
    li      r6,1
.L_802625F4:
    lhz     r0,242(r4)
    addi    r8,r4,242
    lha     r7,-23250(r13)
    extsh   r5,r0
    clrlwi  r0,r0,31
    add     r5,r5,r7
    cmpw    r5,r0
    ble-	.L_80262618
    b	.L_8026261C
.L_80262618:
    mr      r5,r0
.L_8026261C:
    sth     r5,250(r4)
    extsh   r3,r3
    slwi    r3,r3,1
    lhz     r11,246(r4)
    subf    r9,r0,r3
    lha     r10,0(r8)
    addi    r12,r4,246
    extsh   r3,r11
    add     r5,r3,r7
    add     r5,r10,r5
    subf.   r3,r9,r5
    ble-	.L_80262654
    subf    r5,r9,r5
    b	.L_80262658
.L_80262654:
    li      r5,0
.L_80262658:
    add     r10,r10,r7
    subf.   r3,r0,r10
    bge-	.L_8026266C
    subf    r3,r0,r10
    b	.L_80262670
.L_8026266C:
    li      r3,0
.L_80262670:
    add     r3,r11,r3
    subf    r3,r5,r3
    sth     r3,252(r4)
    lha     r3,0(r8)
    add     r5,r3,r7
    subf.   r3,r0,r5
    bge-	.L_80262694
    subf    r3,r0,r5
    b	.L_80262698
.L_80262694:
    li      r3,0
.L_80262698:
    divw    r5,r3,r6
    lhz     r3,264(r4)
    subf    r3,r5,r3
    sth     r3,254(r4)
    lha     r3,0(r12)
    lha     r8,0(r8)
    add     r5,r3,r7
    add     r5,r8,r5
    subf.   r3,r9,r5
    ble-	.L_802626C8
    subf    r5,r9,r5
    b	.L_802626CC
.L_802626C8:
    li      r5,0
.L_802626CC:
    add     r7,r8,r7
    subf.   r3,r0,r7
    bge-	.L_802626E0
    subf    r0,r0,r7
    b	.L_802626E4
.L_802626E0:
    li      r0,0
.L_802626E4:
    divw    r0,r0,r6
    lhz     r3,268(r4)
    divw    r5,r5,r6
    add     r0,r3,r0
    subf    r0,r5,r0
    sth     r0,256(r4)
    blr
.size AdjustPosition, . - AdjustPosition

.global setFbbRegs
.balign 4
setFbbRegs:
/* 0x80262F2C | size=0x2D4 (724 bytes) */
    stwu    r1,-72(r1)
    lis     r9,-32694
    addi    r9,r9,-16744
    stw     r31,68(r1)
    lbz     r8,44(r3)
    lhz     r0,14(r3)
    slwi    r31,r8,5
    lhz     r8,22(r3)
    mullw   r0,r31,r0
    lwz     r11,32(r3)
    lwz     r10,48(r3)
    lhz     r12,10(r3)
    rlwinm  r8,r8,1,0,26
    add     r0,r8,r0
    add     r0,r10,r0
    cmpwi   r11,0
    stw     r0,0(r4)
    bne-	.L_80262F7C
    lwz     r8,0(r4)
    b	.L_80262F84
.L_80262F7C:
    lwz     r0,0(r4)
    add     r8,r0,r31
.L_80262F84:
    srawi   r0,r12,1
    stw     r8,0(r5)
    addze   r0,r0
    slwi    r0,r0,1
    subfc   r0,r0,r12
    cmpwi   r0,1
    bne-	.L_80262FB0
    lwz     r8,0(r4)
    lwz     r0,0(r5)
    stw     r0,0(r4)
    stw     r8,0(r5)
.L_80262FB0:
    lwz     r0,0(r4)
    clrlwi  r0,r0,2
    stw     r0,0(r4)
    lwz     r0,0(r5)
    clrlwi  r0,r0,2
    stw     r0,0(r5)
    lwz     r0,68(r3)
    cmpwi   r0,0
    beq-	.L_80263060
    lbz     r8,44(r3)
    lhz     r0,14(r3)
    slwi    r31,r8,5
    lhz     r8,22(r3)
    mullw   r0,r31,r0
    lwz     r11,32(r3)
    lwz     r10,72(r3)
    lhz     r12,10(r3)
    rlwinm  r8,r8,1,0,26
    add     r0,r8,r0
    add     r0,r10,r0
    cmpwi   r11,0
    stw     r0,0(r6)
    bne-	.L_80263014
    lwz     r8,0(r6)
    b	.L_8026301C
.L_80263014:
    lwz     r0,0(r6)
    add     r8,r0,r31
.L_8026301C:
    srawi   r0,r12,1
    stw     r8,0(r7)
    addze   r0,r0
    slwi    r0,r0,1
    subfc   r0,r0,r12
    cmpwi   r0,1
    bne-	.L_80263048
    lwz     r8,0(r6)
    lwz     r0,0(r7)
    stw     r0,0(r6)
    stw     r8,0(r7)
.L_80263048:
    lwz     r0,0(r6)
    clrlwi  r0,r0,2
    stw     r0,0(r6)
    lwz     r0,0(r7)
    clrlwi  r0,r0,2
    stw     r0,0(r7)
.L_80263060:
    lwz     r0,0(r4)
    lis     r8,256
    cmplw   r0,r8
    bge-	.L_8026309C
    lwz     r0,0(r5)
    cmplw   r0,r8
    bge-	.L_8026309C
    lwz     r0,0(r6)
    cmplw   r0,r8
    bge-	.L_8026309C
    lwz     r0,0(r7)
    cmplw   r0,r8
    bge-	.L_8026309C
    li      r10,0
    b	.L_802630A0
.L_8026309C:
    li      r10,1
.L_802630A0:
    cmplwi  r10,0
    beq-	.L_802630D8
    lwz     r0,0(r4)
    srwi    r0,r0,5
    stw     r0,0(r4)
    lwz     r0,0(r5)
    srwi    r0,r0,5
    stw     r0,0(r5)
    lwz     r0,0(r6)
    srwi    r0,r0,5
    stw     r0,0(r6)
    lwz     r0,0(r7)
    srwi    r0,r0,5
    stw     r0,0(r7)
.L_802630D8:
    lwz     r0,0(r4)
    slwi    r11,r10,12
    lis     r8,1
    sth     r0,30(r9)
    lis     r0,2
    lwz     r10,-23240(r13)
    lwz     r12,-23236(r13)
    or      r10,r10,r8
    stw     r12,-23236(r13)
    stw     r10,-23240(r13)
    lwz     r10,0(r4)
    lbz     r4,60(r3)
    srwi    r10,r10,16
    slwi    r4,r4,8
    or      r4,r10,r4
    or      r4,r11,r4
    sth     r4,28(r9)
    lwz     r4,-23240(r13)
    lwz     r10,-23236(r13)
    or      r0,r4,r0
    stw     r10,-23236(r13)
    stw     r0,-23240(r13)
    lwz     r0,0(r5)
    sth     r0,38(r9)
    lwz     r0,-23240(r13)
    lwz     r4,-23236(r13)
    ori     r0,r0,4096
    stw     r4,-23236(r13)
    stw     r0,-23240(r13)
    lwz     r0,0(r5)
    srwi    r0,r0,16
    sth     r0,36(r9)
    lwz     r0,-23240(r13)
    lwz     r4,-23236(r13)
    ori     r0,r0,8192
    stw     r4,-23236(r13)
    stw     r0,-23240(r13)
    lwz     r0,68(r3)
    cmpwi   r0,0
    beq-	.L_802631F4
    lwz     r3,0(r6)
    addi    r0,r8,-32768
    sth     r3,34(r9)
    lwz     r3,-23240(r13)
    lwz     r4,-23236(r13)
    ori     r3,r3,16384
    stw     r4,-23236(r13)
    stw     r3,-23240(r13)
    lwz     r3,0(r6)
    srwi    r3,r3,16
    sth     r3,32(r9)
    lwz     r3,-23240(r13)
    lwz     r4,-23236(r13)
    or      r0,r3,r0
    stw     r4,-23236(r13)
    stw     r0,-23240(r13)
    lwz     r0,0(r7)
    sth     r0,42(r9)
    lwz     r0,-23240(r13)
    lwz     r3,-23236(r13)
    ori     r0,r0,1024
    stw     r3,-23236(r13)
    stw     r0,-23240(r13)
    lwz     r0,0(r7)
    srwi    r0,r0,16
    sth     r0,40(r9)
    lwz     r0,-23240(r13)
    lwz     r3,-23236(r13)
    ori     r0,r0,2048
    stw     r3,-23236(r13)
    stw     r0,-23240(r13)
.L_802631F4:
    lwz     r31,68(r1)
    addi    r1,r1,72
    blr
.size setFbbRegs, . - setFbbRegs

.global setVerticalRegs
.balign 4
setVerticalRegs:
/* 0x802632CC | size=0x1A0 (416 bytes) */
    stwu    r1,-40(r1)
    lis     r11,-32694
    addi    r11,r11,-16744
    stw     r31,36(r1)
    lwz     r31,48(r1)
    stw     r30,32(r1)
    stw     r29,28(r1)
    lhz     r0,108(r11)
    clrlwi. r0,r0,31
    beq-	.L_80263300
    li      r12,1
    li      r29,2
    b	.L_80263308
.L_80263300:
    li      r12,2
    li      r29,1
.L_80263308:
    clrlwi  r30,r3,16
    srawi   r0,r30,1
    addze   r0,r0
    slwi    r0,r0,1
    subfc.  r0,r0,r30
    bne-	.L_80263358
    clrlwi  r3,r12,16
    clrlwi  r0,r6,16
    mullw   r0,r3,r0
    clrlwi  r3,r4,16
    subf    r0,r3,r0
    clrlwi  r3,r29,16
    mullw   r29,r3,r30
    subf    r0,r30,r0
    mullw   r30,r3,r0
    add     r0,r7,r29
    add     r6,r9,r30
    add     r3,r8,r29
    add     r7,r10,r30
    b	.L_8026338C
.L_80263358:
    clrlwi  r3,r12,16
    clrlwi  r0,r6,16
    mullw   r0,r3,r0
    clrlwi  r3,r4,16
    subf    r0,r3,r0
    clrlwi  r3,r29,16
    mullw   r29,r3,r30
    subf    r0,r30,r0
    mullw   r30,r3,r0
    add     r0,r8,r29
    add     r6,r10,r30
    add     r3,r7,r29
    add     r7,r9,r30
.L_8026338C:
    clrlwi  r8,r4,16
    clrlwi  r4,r12,16
    divw    r4,r8,r4
    cmpwi   r31,0
    clrlwi  r4,r4,16
    beq-	.L_802633C0
    slwi    r4,r4,1
    addi    r4,r4,-2
    add     r0,r0,r4
    add     r3,r3,r4
    li      r4,0
    addi    r6,r6,2
    addi    r7,r7,2
.L_802633C0:
    clrlwi  r5,r5,24
    rlwinm  r4,r4,4,12,27
    or      r4,r5,r4
    sth     r4,0(r11)
    lis     r4,-32768
    lis     r9,256
    lwz     r5,-23240(r13)
    lis     r8,512
    lwz     r10,-23236(r13)
    or      r4,r5,r4
    lis     r5,64
    stw     r10,-23236(r13)
    stw     r4,-23240(r13)
    lis     r4,128
    sth     r0,14(r11)
    lwz     r0,-23240(r13)
    lwz     r10,-23236(r13)
    or      r0,r0,r9
    stw     r10,-23236(r13)
    stw     r0,-23240(r13)
    sth     r6,12(r11)
    lwz     r0,-23240(r13)
    lwz     r6,-23236(r13)
    or      r0,r0,r8
    stw     r6,-23236(r13)
    stw     r0,-23240(r13)
    sth     r3,18(r11)
    lwz     r0,-23240(r13)
    lwz     r3,-23236(r13)
    or      r0,r0,r5
    stw     r3,-23236(r13)
    stw     r0,-23240(r13)
    sth     r7,16(r11)
    lwz     r0,-23240(r13)
    lwz     r3,-23236(r13)
    or      r0,r0,r4
    stw     r3,-23236(r13)
    stw     r0,-23240(r13)
    lwz     r31,36(r1)
    lwz     r30,32(r1)
    lwz     r29,28(r1)
    addi    r1,r1,40
    blr
.size setVerticalRegs, . - setVerticalRegs

.global VIConfigurePan
.balign 4
VIConfigurePan:
/* 0x80263D08 | size=0x394 (916 bytes) */
    mflr    r0
    lis     r7,-32694
    stw     r0,4(r1)
    stwu    r1,-80(r1)
    stmw    r23,44(r1)
    addi    r26,r3,0
    addi    r25,r4,0
    addi    r24,r5,0
    addi    r23,r6,0
    addi    r29,r7,-16744
    bl	OSDisableInterrupts
    sth     r26,262(r29)
    addi    r11,r29,262
    addi    r8,r29,264
    sth     r25,264(r29)
    addi    r10,r29,266
    addi    r4,r29,268
    sth     r24,266(r29)
    mr      r30,r3
    sth     r23,268(r29)
    lwz     r0,276(r29)
    cmplwi  r0,2
    bne-	.L_80263D6C
    lhz     r0,0(r4)
    b	.L_80263D98
.L_80263D6C:
    cmplwi  r0,3
    bne-	.L_80263D7C
    lhz     r0,0(r4)
    b	.L_80263D98
.L_80263D7C:
    lwz     r0,272(r29)
    cmpwi   r0,0
    bne-	.L_80263D94
    lhz     r0,0(r4)
    rlwinm  r0,r0,1,16,30
    b	.L_80263D98
.L_80263D94:
    lhz     r0,0(r4)
.L_80263D98:
    addi    r27,r29,246
    sth     r0,246(r29)
    addi    r9,r29,244
    lhz     r0,244(r29)
    lha     r5,240(r29)
    lha     r3,-23252(r13)
    subfic  r0,r0,720
    lwz     r28,324(r29)
    add     r3,r5,r3
    cmpw    r3,r0
    lhz     r7,2(r28)
    ble-	.L_80263DCC
    b	.L_80263DDC
.L_80263DCC:
    cmpwi   r3,0
    bge-	.L_80263DD8
    li      r3,0
.L_80263DD8:
    mr      r0,r3
.L_80263DDC:
    sth     r0,248(r29)
    addi    r12,r29,272
    lwz     r0,272(r29)
    cmpwi   r0,0
    bne-	.L_80263DF8
    li      r0,2
    b	.L_80263DFC
.L_80263DF8:
    li      r0,1
.L_80263DFC:
    lhz     r3,242(r29)
    addi    r6,r29,242
    lha     r5,-23250(r13)
    extsh   r25,r3
    clrlwi  r3,r3,31
    add     r26,r25,r5
    cmpw    r26,r3
    ble-	.L_80263E20
    b	.L_80263E24
.L_80263E20:
    mr      r26,r3
.L_80263E24:
    sth     r26,250(r29)
    extsh   r7,r7
    slwi    r7,r7,1
    lhz     r23,0(r27)
    subf    r7,r3,r7
    lha     r24,0(r6)
    addi    r31,r29,250
    extsh   r26,r23
    add     r25,r26,r5
    add     r25,r24,r25
    subf.   r26,r7,r25
    ble-	.L_80263E5C
    subf    r25,r7,r25
    b	.L_80263E60
.L_80263E5C:
    li      r25,0
.L_80263E60:
    add     r24,r24,r5
    subf.   r26,r3,r24
    bge-	.L_80263E74
    subf    r26,r3,r24
    b	.L_80263E78
.L_80263E74:
    li      r26,0
.L_80263E78:
    add     r26,r23,r26
    subf    r26,r25,r26
    sth     r26,252(r29)
    lha     r26,0(r6)
    add     r23,r26,r5
    subf.   r26,r3,r23
    bge-	.L_80263E9C
    subf    r25,r3,r23
    b	.L_80263EA0
.L_80263E9C:
    li      r25,0
.L_80263EA0:
    divw    r26,r25,r0
    lhz     r8,0(r8)
    subf    r8,r26,r8
    sth     r8,254(r29)
    lha     r8,0(r27)
    lha     r23,0(r6)
    add     r8,r8,r5
    add     r8,r23,r8
    subf.   r6,r7,r8
    ble-	.L_80263ED0
    subf    r6,r7,r8
    b	.L_80263ED4
.L_80263ED0:
    li      r6,0
.L_80263ED4:
    add     r7,r23,r5
    subf.   r5,r3,r7
    bge-	.L_80263EE8
    subf    r3,r3,r7
    b	.L_80263EEC
.L_80263EE8:
    li      r3,0
.L_80263EEC:
    divw    r3,r3,r0
    lhz     r4,0(r4)
    divw    r5,r6,r0
    add     r0,r4,r3
    subf    r0,r5,r0
    sth     r0,256(r29)
    lwz     r0,308(r29)
    lhz     r5,0(r9)
    cmpwi   r0,0
    lhz     r3,0(r10)
    beq-	.L_80263F20
    slwi    r0,r3,1
    b	.L_80263F24
.L_80263F20:
    mr      r0,r3
.L_80263F24:
    clrlwi  r6,r0,16
    cmplw   r6,r5
    bge-	.L_80263F7C
    slwi    r4,r6,8
    addi    r0,r4,-1
    add     r0,r5,r0
    divwu   r0,r0,r5
    ori     r0,r0,4096
    sth     r0,74(r29)
    lis     r0,1024
    lwz     r4,-23240(r13)
    lwz     r5,-23236(r13)
    or      r0,r5,r0
    stw     r0,-23236(r13)
    stw     r4,-23240(r13)
    sth     r6,112(r29)
    lwz     r4,-23240(r13)
    lwz     r0,-23236(r13)
    ori     r0,r0,128
    stw     r0,-23236(r13)
    stw     r4,-23240(r13)
    b	.L_80263F9C
.L_80263F7C:
    li      r0,256
    sth     r0,74(r29)
    lis     r0,1024
    lwz     r4,-23240(r13)
    lwz     r5,-23236(r13)
    or      r0,r5,r0
    stw     r0,-23236(r13)
    stw     r4,-23240(r13)
.L_80263F9C:
    lhz     r4,258(r29)
    addi    r6,r29,284
    lwz     r5,0(r12)
    addi    r0,r4,15
    lhz     r4,0(r11)
    srawi   r0,r0,4
    addze   r0,r0
    cmpwi   r5,0
    stb     r0,284(r29)
    bne-	.L_80263FCC
    lbz     r5,0(r6)
    b	.L_80263FD4
.L_80263FCC:
    lbz     r0,0(r6)
    rlwinm  r5,r0,1,24,30
.L_80263FD4:
    srawi   r0,r4,4
    stb     r5,285(r29)
    addze   r0,r0
    slwi    r0,r0,4
    subfc   r0,r0,r4
    stb     r0,300(r29)
    addi    r4,r29,300
    addi    r0,r3,15
    lbz     r4,0(r4)
    lis     r3,2048
    add     r0,r4,r0
    srawi   r0,r0,4
    addze   r0,r0
    stb     r0,286(r29)
    lbz     r0,286(r29)
    lbz     r4,285(r29)
    rlwimi  r4,r0,8,16,23
    sth     r4,72(r29)
    lwz     r4,-23240(r13)
    lwz     r0,-23200(r13)
    lwz     r5,-23236(r13)
    cmplwi  r0,0
    or      r0,r5,r3
    stw     r0,-23236(r13)
    stw     r4,-23240(r13)
    beq-	.L_80264054
    addi    r3,r29,240
    addi    r4,r29,292
    addi    r5,r29,296
    addi    r6,r29,316
    addi    r7,r29,320
    bl	setFbbRegs
.L_80264054:
    lwz     r0,304(r29)
    stw     r0,8(r1)
    lhz     r3,0(r31)
    lhz     r4,0(r27)
    lbz     r5,0(r28)
    lhz     r6,2(r28)
    lhz     r7,4(r28)
    lhz     r8,6(r28)
    lhz     r9,8(r28)
    lhz     r10,10(r28)
    bl	setVerticalRegs
    mr      r3,r30
    bl	OSRestoreInterrupts
    lmw     r23,44(r1)
    lwz     r0,84(r1)
    addi    r1,r1,80
    mtlr    r0
    blr
.size VIConfigurePan, . - VIConfigurePan

.global VIFlush
.balign 4
VIFlush:
/* 0x8026409C | size=0x130 (304 bytes) */
    mflr    r0
    lis     r3,-32694
    stw     r0,4(r1)
    stwu    r1,-32(r1)
    stw     r31,28(r1)
    addi    r31,r3,-16744
    stw     r30,24(r1)
    stw     r29,20(r1)
    stw     r28,16(r1)
    bl	OSDisableInterrupts
    lwz     r5,-23232(r13)
    addi    r30,r3,0
    li      r0,0
    lwz     r4,-23248(r13)
    or      r3,r5,r4
    stw     r3,-23232(r13)
    stw     r0,-23248(r13)
    lwz     r4,-23224(r13)
    lwz     r5,-23220(r13)
    lwz     r0,-23240(r13)
    lwz     r3,-23236(r13)
    or      r0,r4,r0
    or      r3,r5,r3
    stw     r3,-23220(r13)
    stw     r0,-23224(r13)
    b	.L_80264178
.L_80264104:
    lwz     r3,-23240(r13)
    li      r5,32
    lwz     r28,-23236(r13)
    addi    r4,r28,0
    bl	__shr2u
    cntlzw  r4,r4
    cmpwi   r4,32
    li      r0,-1
    and     r0,r28,r0
    bge-	.L_80264130
    b	.L_80264138
.L_80264130:
    cntlzw  r3,r0
    addi    r4,r3,32
.L_80264138:
    slwi    r3,r4,1
    lhzx    r0,r31,r3
    add     r3,r31,r3
    subfic  r5,r4,63
    sth     r0,120(r3)
    li      r3,0
    li      r4,1
    bl	__shl2i
    lwz     r0,-23240(r13)
    not     r5,r3
    not     r4,r4
    lwz     r3,-23236(r13)
    and     r0,r0,r5
    and     r3,r3,r4
    stw     r3,-23236(r13)
    stw     r0,-23240(r13)
.L_80264178:
    lwz     r0,-23240(r13)
    li      r3,0
    lwz     r4,-23236(r13)
    xor     r0,r0,r3
    xor     r3,r4,r3
    or.     r0,r3,r0
    bne+	.L_80264104
    li      r0,1
    stw     r0,-23280(r13)
    mr      r3,r30
    lwz     r0,288(r31)
    stw     r0,-23208(r13)
    bl	OSRestoreInterrupts
    lwz     r0,36(r1)
    lwz     r31,28(r1)
    lwz     r30,24(r1)
    lwz     r29,20(r1)
    lwz     r28,16(r1)
    addi    r1,r1,32
    mtlr    r0
    blr
.size VIFlush, . - VIFlush

.global __VISetAdjustingValues
.balign 4
__VISetAdjustingValues:
/* 0x8026476C | size=0x2C8 (712 bytes) */
    mflr    r0
    lis     r5,-32694
    stw     r0,4(r1)
    stwu    r1,-56(r1)
    stmw    r27,36(r1)
    addi    r28,r3,0
    addi    r27,r4,0
    addi    r30,r5,-16744
    bl	OSDisableInterrupts
    sth     r28,-23252(r13)
    addi    r31,r3,0
    extsh   r4,r28
    sth     r27,-23250(r13)
    addi    r9,r30,244
    lha     r3,240(r30)
    lhz     r0,244(r30)
    lwz     r29,324(r30)
    add     r3,r3,r4
    subfic  r0,r0,720
    cmpw    r3,r0
    lhz     r6,2(r29)
    ble-	.L_802647C8
    b	.L_802647D8
.L_802647C8:
    cmpwi   r3,0
    bge-	.L_802647D4
    li      r3,0
.L_802647D4:
    mr      r0,r3
.L_802647D8:
    sth     r0,248(r30)
    addi    r8,r30,248
    lwz     r0,272(r30)
    cmpwi   r0,0
    bne-	.L_802647F4
    li      r0,2
    b	.L_802647F8
.L_802647F4:
    li      r0,1
.L_802647F8:
    lhz     r3,242(r30)
    extsh   r4,r27
    addi    r5,r30,242
    extsh   r7,r3
    clrlwi  r3,r3,31
    add     r7,r7,r4
    cmpw    r7,r3
    ble-	.L_8026481C
    b	.L_80264820
.L_8026481C:
    mr      r7,r3
.L_80264820:
    sth     r7,250(r30)
    extsh   r6,r6
    slwi    r6,r6,1
    lhz     r28,246(r30)
    subf    r6,r3,r6
    lha     r12,0(r5)
    addi    r27,r30,250
    extsh   r10,r28
    add     r11,r10,r4
    add     r11,r12,r11
    subf.   r10,r6,r11
    addi    r7,r30,246
    ble-	.L_8026485C
    subf    r11,r6,r11
    b	.L_80264860
.L_8026485C:
    li      r11,0
.L_80264860:
    add     r12,r12,r4
    subf.   r10,r3,r12
    bge-	.L_80264874
    subf    r10,r3,r12
    b	.L_80264878
.L_80264874:
    li      r10,0
.L_80264878:
    add     r10,r28,r10
    subf    r10,r11,r10
    addi    r28,r30,252
    sth     r10,252(r30)
    lha     r10,0(r5)
    add     r11,r10,r4
    subf.   r10,r3,r11
    bge-	.L_802648A0
    subf    r10,r3,r11
    b	.L_802648A4
.L_802648A0:
    li      r10,0
.L_802648A4:
    divw    r11,r10,r0
    lhz     r10,264(r30)
    subf    r10,r11,r10
    sth     r10,254(r30)
    lha     r7,0(r7)
    lha     r10,0(r5)
    add     r7,r7,r4
    add     r7,r10,r7
    subf.   r5,r6,r7
    ble-	.L_802648D4
    subf    r5,r6,r7
    b	.L_802648D8
.L_802648D4:
    li      r5,0
.L_802648D8:
    add     r6,r10,r4
    subf.   r4,r3,r6
    bge-	.L_802648EC
    subf    r3,r3,r6
    b	.L_802648F0
.L_802648EC:
    li      r3,0
.L_802648F0:
    divw    r3,r3,r0
    lhz     r4,268(r30)
    divw    r5,r5,r0
    add     r0,r4,r3
    subf    r0,r5,r0
    sth     r0,256(r30)
    lis     r5,4096
    lis     r4,8192
    lhz     r10,0(r8)
    lis     r0,1024
    lhz     r6,26(r29)
    lis     r3,2048
    sth     r6,6(r30)
    lwz     r6,-23240(r13)
    lwz     r7,-23236(r13)
    or      r5,r6,r5
    stw     r7,-23236(r13)
    stw     r5,-23240(r13)
    lbz     r5,29(r29)
    lbz     r6,30(r29)
    rlwimi  r6,r5,8,16,23
    sth     r6,4(r30)
    lwz     r5,-23240(r13)
    lwz     r6,-23236(r13)
    or      r4,r5,r4
    stw     r6,-23236(r13)
    stw     r4,-23240(r13)
    lbz     r4,31(r29)
    lbz     r5,28(r29)
    add     r8,r4,r10
    lhz     r7,0(r9)
    addi    r8,r8,-40
    lhz     r6,32(r29)
    rlwinm  r4,r8,7,16,24
    or      r4,r5,r4
    add     r5,r6,r10
    sth     r4,10(r30)
    subfic  r6,r7,720
    addi    r5,r5,40
    lwz     r4,-23240(r13)
    subf    r7,r6,r5
    or      r5,r4,r0
    lwz     r6,-23236(r13)
    srwi    r4,r8,9
    stw     r6,-23236(r13)
    slwi    r0,r7,1
    or      r0,r4,r0
    stw     r5,-23240(r13)
    sth     r0,8(r30)
    lwz     r4,-23240(r13)
    lwz     r0,-23200(r13)
    lwz     r5,-23236(r13)
    or      r3,r4,r3
    cmplwi  r0,0
    stw     r5,-23236(r13)
    stw     r3,-23240(r13)
    beq-	.L_802649EC
    addi    r3,r30,240
    addi    r4,r30,292
    addi    r5,r30,296
    addi    r6,r30,316
    addi    r7,r30,320
    bl	setFbbRegs
.L_802649EC:
    lwz     r0,304(r30)
    stw     r0,8(r1)
    lhz     r3,0(r27)
    lhz     r4,0(r28)
    lbz     r5,0(r29)
    lhz     r6,2(r29)
    lhz     r7,4(r29)
    lhz     r8,6(r29)
    lhz     r9,8(r29)
    lhz     r10,10(r29)
    bl	setVerticalRegs
    mr      r3,r31
    bl	OSRestoreInterrupts
    lmw     r27,36(r1)
    lwz     r0,60(r1)
    addi    r1,r1,56
    mtlr    r0
    blr
.size __VISetAdjustingValues, . - __VISetAdjustingValues

.global __VIEnableRawPositionInterrupt
.balign 4
__VIEnableRawPositionInterrupt:
/* 0x80264A80 | size=0x180 (384 bytes) */
    mflr    r0
    stw     r0,4(r1)
    stwu    r1,-40(r1)
    stw     r31,36(r1)
    addi    r31,r5,0
    stw     r30,32(r1)
    addi    r30,r4,0
    stw     r29,28(r1)
    addi    r29,r3,0
    bl	OSDisableInterrupts
    extsh   r4,r29
    addi    r0,r4,1
    lis     r4,-13312
    addi    r4,r4,8192
    sth     r0,58(r4)
    lis     r5,-32694
    addi    r5,r5,-16504
    sth     r0,62(r4)
    lwz     r0,36(r5)
    cmplwi  r0,0
    bne-	.L_80264B50
    extsh   r5,r30
    clrlwi. r0,r5,31
    beq-	.L_80264B1C
    lwz     r8,-23216(r13)
    srawi   r5,r5,1
    addze   r5,r5
    lbz     r6,0(r8)
    addi    r0,r5,1
    lhz     r7,6(r8)
    mulli   r5,r6,3
    lhz     r6,24(r8)
    add     r5,r5,r7
    add     r5,r6,r5
    srwi    r5,r5,1
    add     r0,r5,r0
    ori     r0,r0,4096
    sth     r0,60(r4)
    b	.L_80264BDC
.L_80264B1C:
    lwz     r7,-23216(r13)
    srawi   r5,r5,1
    addze   r5,r5
    lbz     r6,0(r7)
    addi    r0,r5,1
    lhz     r7,4(r7)
    mulli   r5,r6,3
    add     r5,r7,r5
    srwi    r5,r5,1
    add     r0,r5,r0
    ori     r0,r0,4096
    sth     r0,56(r4)
    b	.L_80264BDC
.L_80264B50:
    cmplwi  r0,1
    bne-	.L_80264BA4
    lwz     r5,-23216(r13)
    extsh   r6,r30
    lbz     r0,0(r5)
    lhz     r5,4(r5)
    mulli   r0,r0,3
    add     r6,r0,r6
    add     r6,r5,r6
    srwi    r5,r6,1
    addi    r0,r5,1
    ori     r0,r0,4096
    sth     r0,56(r4)
    lwz     r5,-23216(r13)
    lhz     r0,24(r5)
    add     r0,r6,r0
    srwi    r5,r0,1
    addi    r0,r5,1
    ori     r0,r0,4096
    sth     r0,60(r4)
    b	.L_80264BDC
.L_80264BA4:
    cmplwi  r0,2
    bne-	.L_80264BDC
    lwz     r6,-23216(r13)
    extsh   r7,r30
    li      r0,0
    lbz     r5,0(r6)
    lhz     r6,4(r6)
    mulli   r5,r5,3
    add     r5,r5,r7
    addi    r5,r5,1
    add     r5,r6,r5
    ori     r5,r5,4096
    sth     r5,56(r4)
    sth     r0,60(r4)
.L_80264BDC:
    stw     r31,-23260(r13)
    bl	OSRestoreInterrupts
    lwz     r0,44(r1)
    lwz     r31,36(r1)
    lwz     r30,32(r1)
    lwz     r29,28(r1)
    addi    r1,r1,40
    mtlr    r0
    blr
.size __VIEnableRawPositionInterrupt, . - __VIEnableRawPositionInterrupt

.global __VIDisplayPositionToXY
.balign 4
__VIDisplayPositionToXY:
/* 0x80264C4C | size=0x21C (540 bytes) */
    lwz     r9,-23216(r13)
    lis     r7,-32694
    addi    r7,r7,-16504
    lhz     r0,26(r9)
    addi    r8,r3,-1
    lwz     r7,36(r7)
    addi    r4,r4,-1
    divwu   r0,r8,r0
    slwi    r4,r4,1
    cmplwi  r7,0
    add     r0,r4,r0
    bne-	.L_80264D38
    lhz     r10,24(r9)
    cmplw   r0,r10
    bge-	.L_80264CDC
    lbz     r4,0(r9)
    lhz     r8,4(r9)
    mulli   r7,r4,3
    add     r4,r8,r7
    cmplw   r0,r4
    bge-	.L_80264CAC
    li      r0,-1
    sth     r0,0(r6)
    b	.L_80264E5C
.L_80264CAC:
    lhz     r4,8(r9)
    subf    r4,r4,r10
    cmplw   r0,r4
    blt-	.L_80264CC8
    li      r0,-1
    sth     r0,0(r6)
    b	.L_80264E5C
.L_80264CC8:
    subf    r0,r7,r0
    subf    r0,r8,r0
    clrrwi  r0,r0,1
    sth     r0,0(r6)
    b	.L_80264E5C
.L_80264CDC:
    lbz     r4,0(r9)
    subf    r0,r10,r0
    lhz     r8,6(r9)
    mulli   r7,r4,3
    add     r4,r8,r7
    cmplw   r0,r4
    bge-	.L_80264D04
    li      r0,-1
    sth     r0,0(r6)
    b	.L_80264E5C
.L_80264D04:
    lhz     r4,10(r9)
    subf    r4,r4,r10
    cmplw   r0,r4
    blt-	.L_80264D20
    li      r0,-1
    sth     r0,0(r6)
    b	.L_80264E5C
.L_80264D20:
    subf    r0,r7,r0
    subf    r0,r8,r0
    clrrwi  r4,r0,1
    addi    r0,r4,1
    sth     r0,0(r6)
    b	.L_80264E5C
.L_80264D38:
    cmplwi  r7,1
    bne-	.L_80264DA4
    lhz     r7,24(r9)
    cmplw   r0,r7
    blt-	.L_80264D50
    subf    r0,r7,r0
.L_80264D50:
    lbz     r4,0(r9)
    lhz     r10,4(r9)
    mulli   r8,r4,3
    add     r4,r10,r8
    cmplw   r0,r4
    bge-	.L_80264D74
    li      r0,-1
    sth     r0,0(r6)
    b	.L_80264E5C
.L_80264D74:
    lhz     r4,8(r9)
    subf    r4,r4,r7
    cmplw   r0,r4
    blt-	.L_80264D90
    li      r0,-1
    sth     r0,0(r6)
    b	.L_80264E5C
.L_80264D90:
    subf    r0,r8,r0
    subf    r0,r10,r0
    clrrwi  r0,r0,1
    sth     r0,0(r6)
    b	.L_80264E5C
.L_80264DA4:
    cmplwi  r7,2
    bne-	.L_80264E5C
    lhz     r10,24(r9)
    cmplw   r0,r10
    bge-	.L_80264E08
    lbz     r4,0(r9)
    lhz     r8,4(r9)
    mulli   r7,r4,3
    add     r4,r8,r7
    cmplw   r0,r4
    bge-	.L_80264DDC
    li      r0,-1
    sth     r0,0(r6)
    b	.L_80264E5C
.L_80264DDC:
    lhz     r4,8(r9)
    subf    r4,r4,r10
    cmplw   r0,r4
    blt-	.L_80264DF8
    li      r0,-1
    sth     r0,0(r6)
    b	.L_80264E5C
.L_80264DF8:
    subf    r0,r7,r0
    subf    r0,r8,r0
    sth     r0,0(r6)
    b	.L_80264E5C
.L_80264E08:
    lbz     r4,0(r9)
    subf    r0,r10,r0
    lhz     r8,6(r9)
    mulli   r7,r4,3
    add     r4,r8,r7
    cmplw   r0,r4
    bge-	.L_80264E30
    li      r0,-1
    sth     r0,0(r6)
    b	.L_80264E5C
.L_80264E30:
    lhz     r4,10(r9)
    subf    r4,r4,r10
    cmplw   r0,r4
    blt-	.L_80264E4C
    li      r0,-1
    sth     r0,0(r6)
    b	.L_80264E5C
.L_80264E4C:
    subf    r0,r7,r0
    subf    r0,r8,r0
    clrrwi  r0,r0,1
    sth     r0,0(r6)
.L_80264E5C:
    addi    r0,r3,-1
    sth     r0,0(r5)
    blr
.size __VIDisplayPositionToXY, . - __VIDisplayPositionToXY
