# =============================================================================
# SN Systems ProDG crt0.s — GameCube startup code
# Source: C:\Program Files\SN Systems\ngc\lib\libsn.a(crt0.o)
# Address range: 0x80003100 — 0x80003467
#
# This is the GameCube entry point. The boot ROM jumps here after loading
# the DOL. It sets up the stack, small data areas, clears BSS, initializes
# hardware, FPRs, paired singles, and finally calls main().
# =============================================================================

    .section .init, "ax"
    .align 2

# =============================================================================
# __start — Entry point (0x80003100)
# =============================================================================
    .global __start
__start:
    # Set up stack pointer (r1), SDA2 base (r2), SDA base (r13)
    lis     r1, _stack_addr@h
    ori     r1, r1, _stack_addr@l
    lis     r2, _SDA2_BASE_@h
    ori     r2, r2, _SDA2_BASE_@l
    lis     r13, _SDA_BASE_@h
    ori     r13, r13, _SDA_BASE_@l

    # Initialize GQR registers (Gekko Quantize Registers for paired singles)
    bl      __init_gqr

    # Initialize FPR and PS registers
    bl      __init_fprs

    # Initialize hardware (DolphinSDK — enables FPU, calls PSInit, FPRInit, CacheInit)
    bl      __init_hardware

    # Set up the terminating stack frame
    li      r0, -1                      # 0xFFFFFFFF — invalid LR marker
    stwu    r1, -8(r1)                  # push stack frame
    stw     r0, 4(r1)                   # store invalid LR
    stw     r0, 0(r1)                   # store invalid back chain

    # Clear .bss section
    lis     r3, _bss_start@h
    ori     r3, r3, _bss_start@l
    li      r4, 0
    lis     r5, _bss_end@h
    ori     r5, r5, _bss_end@l
    subf    r5, r3, r5                  # r5 = bss size
    bl      memset

    # Clear .sbss section
    lis     r3, _sbss_start@h
    ori     r3, r3, _sbss_start@l
    li      r4, 0
    lis     r5, _sbss_end@h
    ori     r5, r5, _sbss_end@l
    subf    r5, r3, r5                  # r5 = sbss size
    bl      memset

    # Clear ArenaHi (0x80000044) — set to 0
    li      r4, 0
    lis     r5, 0x8000
    stw     r4, 0x0044(r5)

    # Check for DVD arguments (SN debug probe?)
    li      r29, 0
    lis     r6, 0x8000
    ori     r6, r6, 0x00F4
    lwz     r6, 0(r6)                   # r6 = *(0x800000F4) — BS2 DVD argument pointer
    cmpwi   r6, 0
    beq-    .L_no_dvd_arg

    lwz     r3, 12(r6)                  # r3 = dvd_arg->field_0C
    cmplwi  r3, 2
    blt-    .L_no_dvd_arg

    bl      SNDebugInit                 # Initialize SN Systems debug probe
    li      r29, 1                      # Flag: debug probe is active

.L_no_dvd_arg:
    bl      __init_args                 # Parse command-line arguments
    mr      r30, r3                     # r30 = argc
    mr      r31, r4                     # r31 = argv

    bl      DBInit                      # Initialize debug communication
    bl      OSInit                      # Initialize Dolphin OS

    # Check MEM1 arena (0x800030E6)
    lis     r4, 0x8000
    lhz     r3, 0x30E6(r4)             # r3 = *(u16*)0x800030E6
    andi.   r4, r3, 0x8000             # Test high bit
    beq-    .L_do_check_pad3

    andi.   r3, r3, 0x7FFF             # Mask off high bit
    cmplwi  r3, 1
    bne-    .L_skip_check_pad3

.L_do_check_pad3:
    bl      __check_pad3                # Check controller pad 3 for reset

.L_skip_check_pad3:
    bl      __premain                   # Call __premain (stub — just blr)

    # Call __init_user to run C++ static constructors
    mr      r3, r30                     # argc
    mr      r4, r31                     # argv
    bl      __premain                   # Second __premain call
    bl      __init_user                 # Run C++ static initializers

    # Check if debug probe is active
    cmpwi   r29, 0
    beq-    .L_normal_main

    # Debug probe path — report messages, then rfi to main
    lis     r3, __SN_Libsn_version_58@h
    ori     r3, r3, __SN_Libsn_version_58@l
    lis     r4, __SN_Libsn_version@h
    ori     r4, r4, __SN_Libsn_version@l
    lwz     r4, 0(r4)
    bl      OSReport                    # Report SN Systems version

    lis     r3, __SN_Libsn_version@h
    ori     r3, r3, __SN_Libsn_version@l
    bl      OSReport                    # Report version string

    # Transition to main via rfi (restore from interrupt)
    # This switches to the final MSR state with IR (instruction relocate) enabled
    mfmsr   r5
    ori     r4, r5, 0x8000             # Set MSR[EE] (external interrupt enable)
    xori    r4, r4, 0x8000             # Clear it — net: r4 = r5 with EE cleared
    mtmsr   r4                          # Disable interrupts
    sync
    ori     r5, r5, 0x0200             # Set MSR[RI] (recoverable interrupt)
    mtsrr1  r5                          # SRR1 = MSR for rfi
    lis     r4, 0x8000
    ori     r4, r4, 0x3244
    mtsrr0  r4                          # SRR0 = address to return to
    rfi                                 # "return" to .L_normal_main

.L_normal_main:
    # Normal entry to main
    mr      r3, r30                     # argc
    mr      r4, r31                     # argv
    bl      main
    b       exit                        # Never returns

# =============================================================================
# __init_args — Parse command-line arguments from BS2 area (0x80003254)
# Returns: r3 = argc, r4 = argv
# =============================================================================
__init_args:
    lis     r6, 0x8000
    ori     r6, r6, 0x00F4
    lwz     r5, 0(r6)                   # r5 = *(0x800000F4) — DVD arg block
    cmpwi   r5, 0
    bne-    .L_has_args
.L_no_args:
    li      r3, 0                       # argc = 0
    li      r4, 0                       # argv = NULL
    blr
.L_has_args:
    lwz     r6, 8(r5)                   # r6 = arg_block->offset_to_args
    cmpwi   r6, 0
    beq+    .L_no_args

    add     r6, r5, r6                  # r6 = arg_block + offset = args table
    lwz     r3, 0(r6)                   # r3 = argc
    cmpwi   r3, 0
    beq+    .L_no_args

    addi    r4, r6, 4                   # r4 = argv (right after argc)

    # Relocate argv pointers — convert offsets to absolute addresses
    mtctr   r3
.L_relocate_argv:
    addi    r6, r6, 4                   # advance to next argv entry
    lwz     r7, 0(r6)
    add     r7, r7, r5                  # argv[i] += arg_block base
    stw     r7, 0(r6)
    bdnz+   .L_relocate_argv

    # Store relocated argv base to ArenaLo (0x80000034)
    lis     r5, 0x8000
    ori     r5, r5, 0x0034
    clrrwi  r7, r4, 5                   # Align down to 32 bytes
    stw     r7, 0(r5)
    blr

# =============================================================================
# __check_pad3 — Check pad 3 for OS reset (0x800032C0)
# =============================================================================
__check_pad3:
    mflr    r0
    stw     r0, 4(r1)
    stwu    r1, -8(r1)

    lis     r3, 0x8000
    lhz     r0, 0x30E4(r3)             # Read PAD status word
    andi.   r0, r0, 0x0EEF             # Mask for specific button combo
    cmpwi   r0, 0x0EEF                 # All buttons held?
    bne-    .L_pad3_done

    # Reset the system
    li      r3, 0                       # HOT reset
    li      r4, 0
    li      r5, 0
    bl      OSResetSystem

.L_pad3_done:
    lwz     r0, 12(r1)
    addi    r1, r1, 8
    mtlr    r0
    blr

# =============================================================================
# __init_gqr — Initialize Gekko Quantize Registers (0x80003300)
# All GQR registers set to 0 (no quantization)
# =============================================================================
__init_gqr:
    li      r3, 0
    mtgqr   0, r3
    mtgqr   1, r3
    mtgqr   2, r3
    mtgqr   3, r3
    mtgqr   4, r3
    mtgqr   5, r3
    mtgqr   6, r3
    mtgqr   7, r3
    blr

# Embedded zero constants used by __init_fprs
    .align 3
fprs_double_zero:
    .double 0.0
fprs_ps_zero:
    .float  0.0

# =============================================================================
# __init_fprs — Initialize FPR and PS registers (0x80003334)
# Clears all 32 FPRs and all 32 paired-single registers, plus FPSCR
# =============================================================================
__init_fprs:
    mfmsr   r3
    ori     r3, r3, 0x2000             # Enable MSR[FP] — floating point available
    mtmsr   r3

    # Check if paired singles are available (HID2 bit 29)
    mfhid2  r3
    rlwinm. r3, r3, 3, 31, 31          # Extract HID2[LSQE] (paired singles enable)
    beq-    .L_no_ps

    # Initialize all 32 paired-single registers from zero constant
    lis     r3, fprs_ps_zero@h
    ori     r3, r3, fprs_ps_zero@l
    psq_l   f0, 0(r3), 0, 0
    ps_mr   f1, f0
    ps_mr   f2, f0
    ps_mr   f3, f0
    ps_mr   f4, f0
    ps_mr   f5, f0
    ps_mr   f6, f0
    ps_mr   f7, f0
    ps_mr   f8, f0
    ps_mr   f9, f0
    ps_mr   f10, f0
    ps_mr   f11, f0
    ps_mr   f12, f0
    ps_mr   f13, f0
    ps_mr   f14, f0
    ps_mr   f15, f0
    ps_mr   f16, f0
    ps_mr   f17, f0
    ps_mr   f18, f0
    ps_mr   f19, f0
    ps_mr   f20, f0
    ps_mr   f21, f0
    ps_mr   f22, f0
    ps_mr   f23, f0
    ps_mr   f24, f0
    ps_mr   f25, f0
    ps_mr   f26, f0
    ps_mr   f27, f0
    ps_mr   f28, f0
    ps_mr   f29, f0
    ps_mr   f30, f0
    ps_mr   f31, f0

.L_no_ps:
    # Initialize all 32 FPRs from double zero constant
    lis     r3, fprs_double_zero@h
    ori     r3, r3, fprs_double_zero@l
    lfd     f0, 0(r3)
    fmr     f1, f0
    fmr     f2, f0
    fmr     f3, f0
    fmr     f4, f0
    fmr     f5, f0
    fmr     f6, f0
    fmr     f7, f0
    fmr     f8, f0
    fmr     f9, f0
    fmr     f10, f0
    fmr     f11, f0
    fmr     f12, f0
    fmr     f13, f0
    fmr     f14, f0
    fmr     f15, f0
    fmr     f16, f0
    fmr     f17, f0
    fmr     f18, f0
    fmr     f19, f0
    fmr     f20, f0
    fmr     f21, f0
    fmr     f22, f0
    fmr     f23, f0
    fmr     f24, f0
    fmr     f25, f0
    fmr     f26, f0
    fmr     f27, f0
    fmr     f28, f0
    fmr     f29, f0
    fmr     f30, f0
    fmr     f31, f0

    # Clear FPSCR
    mtfsf   255, f0
    blr

# =============================================================================
# __init_vm / __premain — Stub (0x80003464)
# =============================================================================
    .global __init_vm
    .global __premain
__init_vm:
__premain:
    blr
