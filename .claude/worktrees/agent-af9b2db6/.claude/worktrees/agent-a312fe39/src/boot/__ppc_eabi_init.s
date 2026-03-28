# =============================================================================
# DolphinSDK __ppc_eabi_init.s — Hardware initialization
# Source: os.a(__ppc_eabi_init.o) from DolphinSDK 1.0 HW2
# Address range: 0x80003468 — 0x800034BF
# =============================================================================

    .section .init, "ax"
    .align 2

# =============================================================================
# __init_hardware (0x80003468, size 0x24)
# Enables FPU in MSR, then initializes PS registers, FPR registers, and caches
# =============================================================================
    .global __init_hardware
__init_hardware:
    mfmsr   r0
    ori     r0, r0, 0x2000             # Set MSR[FP] — floating point available
    mtmsr   r0

    mflr    r31                         # Save return address
    bl      __OSPSInit                  # Initialize paired singles
    bl      __OSFPRInit                 # Initialize floating point registers
    bl      __OSCacheInit               # Initialize instruction and data caches
    mtlr    r31                         # Restore return address
    blr

# =============================================================================
# __flush_cache (0x8000348C, size 0x34)
# Flushes data cache and invalidates instruction cache for a memory range
# Args: r3 = address, r4 = size
# =============================================================================
    .global __flush_cache
__flush_cache:
    lis     r5, -1                      # r5 = 0xFFFF0000
    ori     r5, r5, 0xFFF1             # r5 = 0xFFFFFFF1 (mask: clear bits 1-3)
    and     r5, r5, r3                  # r5 = aligned start address
    subf    r3, r5, r3                  # r3 = bytes skipped by alignment
    add     r4, r4, r3                  # r4 = adjusted size

.L_flush_loop:
    dcbst   0, r5                       # Flush data cache block to memory
    sync                                # Ensure store completed
    icbi    0, r5                       # Invalidate instruction cache block
    addic   r5, r5, 8                   # Advance by 8 bytes
    addic.  r4, r4, -8                  # Decrement remaining size
    bge+    .L_flush_loop               # Continue if size >= 0

    isync                               # Sync instruction stream
    blr
