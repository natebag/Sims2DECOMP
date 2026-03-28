# =============================================================================
# eabi.s — GCC EABI register save/restore helpers
# Source: libgcc.a(eabi.o) from SN Systems ProDG for GameCube
# Address range: 0x8039abdc - 0x8039adbc (0x1e0 bytes)
#
# These are the standard EABI callee-saved register save/restore routines.
# The compiler emits calls/branches to these to save code size.
# =============================================================================

    .section .text
    .balign 4

# ---------------------------------------------------------------------------
# _savefpr_14 .. _savefpr_31 — Save floating-point registers to stack
# Called with r11 = frame pointer (old sp)
# Falls through from _savefpr_14 to _savefpr_31, then blr
# ---------------------------------------------------------------------------
    .global _savefpr_14
_savefpr_14:
    stfd    f14, -144(r11)
    .global _savefpr_15
_savefpr_15:
    stfd    f15, -136(r11)
    .global _savefpr_16
_savefpr_16:
    stfd    f16, -128(r11)
    .global _savefpr_17
_savefpr_17:
    stfd    f17, -120(r11)
    .global _savefpr_18
_savefpr_18:
    stfd    f18, -112(r11)
    .global _savefpr_19
_savefpr_19:
    stfd    f19, -104(r11)
    .global _savefpr_20
_savefpr_20:
    stfd    f20, -96(r11)
    .global _savefpr_21
_savefpr_21:
    stfd    f21, -88(r11)
    .global _savefpr_22
_savefpr_22:
    stfd    f22, -80(r11)
    .global _savefpr_23
_savefpr_23:
    stfd    f23, -72(r11)
    .global _savefpr_24
_savefpr_24:
    stfd    f24, -64(r11)
    .global _savefpr_25
_savefpr_25:
    stfd    f25, -56(r11)
    .global _savefpr_26
_savefpr_26:
    stfd    f26, -48(r11)
    .global _savefpr_27
_savefpr_27:
    stfd    f27, -40(r11)
    .global _savefpr_28
_savefpr_28:
    stfd    f28, -32(r11)
    .global _savefpr_29
_savefpr_29:
    stfd    f29, -24(r11)
    .global _savefpr_30
_savefpr_30:
    stfd    f30, -16(r11)
    .global _savefpr_31
_savefpr_31:
    stfd    f31, -8(r11)
    blr

# ---------------------------------------------------------------------------
# _savegpr_14 .. _savegpr_31 — Save general-purpose registers to stack
# ---------------------------------------------------------------------------
    .global _savegpr_14
_savegpr_14:
    stw     r14, -72(r11)
    .global _savegpr_15
_savegpr_15:
    stw     r15, -68(r11)
    .global _savegpr_16
_savegpr_16:
    stw     r16, -64(r11)
    .global _savegpr_17
_savegpr_17:
    stw     r17, -60(r11)
    .global _savegpr_18
_savegpr_18:
    stw     r18, -56(r11)
    .global _savegpr_19
_savegpr_19:
    stw     r19, -52(r11)
    .global _savegpr_20
_savegpr_20:
    stw     r20, -48(r11)
    .global _savegpr_21
_savegpr_21:
    stw     r21, -44(r11)
    .global _savegpr_22
_savegpr_22:
    stw     r22, -40(r11)
    .global _savegpr_23
_savegpr_23:
    stw     r23, -36(r11)
    .global _savegpr_24
_savegpr_24:
    stw     r24, -32(r11)
    .global _savegpr_25
_savegpr_25:
    stw     r25, -28(r11)
    .global _savegpr_26
_savegpr_26:
    stw     r26, -24(r11)
    .global _savegpr_27
_savegpr_27:
    stw     r27, -20(r11)
    .global _savegpr_28
_savegpr_28:
    stw     r28, -16(r11)
    .global _savegpr_29
_savegpr_29:
    stw     r29, -12(r11)
    .global _savegpr_30
_savegpr_30:
    stw     r30, -8(r11)
    .global _savegpr_31
_savegpr_31:
    stw     r31, -4(r11)
    blr

# ---------------------------------------------------------------------------
# _restfpr_14 .. _restfpr_31 — Restore floating-point registers from stack
# ---------------------------------------------------------------------------
    .global _restfpr_14
_restfpr_14:
    lfd     f14, -144(r11)
    .global _restfpr_15
_restfpr_15:
    lfd     f15, -136(r11)
    .global _restfpr_16
_restfpr_16:
    lfd     f16, -128(r11)
    .global _restfpr_17
_restfpr_17:
    lfd     f17, -120(r11)
    .global _restfpr_18
_restfpr_18:
    lfd     f18, -112(r11)
    .global _restfpr_19
_restfpr_19:
    lfd     f19, -104(r11)
    .global _restfpr_20
_restfpr_20:
    lfd     f20, -96(r11)
    .global _restfpr_21
_restfpr_21:
    lfd     f21, -88(r11)
    .global _restfpr_22
_restfpr_22:
    lfd     f22, -80(r11)
    .global _restfpr_23
_restfpr_23:
    lfd     f23, -72(r11)
    .global _restfpr_24
_restfpr_24:
    lfd     f24, -64(r11)
    .global _restfpr_25
_restfpr_25:
    lfd     f25, -56(r11)
    .global _restfpr_26
_restfpr_26:
    lfd     f26, -48(r11)
    .global _restfpr_27
_restfpr_27:
    lfd     f27, -40(r11)
    .global _restfpr_28
_restfpr_28:
    lfd     f28, -32(r11)
    .global _restfpr_29
_restfpr_29:
    lfd     f29, -24(r11)
    .global _restfpr_30
_restfpr_30:
    lfd     f30, -16(r11)
    .global _restfpr_31
_restfpr_31:
    lfd     f31, -8(r11)
    blr

# ---------------------------------------------------------------------------
# _restgpr_14 .. _restgpr_31 — Restore general-purpose registers from stack
# ---------------------------------------------------------------------------
    .global _restgpr_14
_restgpr_14:
    lwz     r14, -72(r11)
    .global _restgpr_15
_restgpr_15:
    lwz     r15, -68(r11)
    .global _restgpr_16
_restgpr_16:
    lwz     r16, -64(r11)
    .global _restgpr_17
_restgpr_17:
    lwz     r17, -60(r11)
    .global _restgpr_18
_restgpr_18:
    lwz     r18, -56(r11)
    .global _restgpr_19
_restgpr_19:
    lwz     r19, -52(r11)
    .global _restgpr_20
_restgpr_20:
    lwz     r20, -48(r11)
    .global _restgpr_21
_restgpr_21:
    lwz     r21, -44(r11)
    .global _restgpr_22
_restgpr_22:
    lwz     r22, -40(r11)
    .global _restgpr_23
_restgpr_23:
    lwz     r23, -36(r11)
    .global _restgpr_24
_restgpr_24:
    lwz     r24, -32(r11)
    .global _restgpr_25
_restgpr_25:
    lwz     r25, -28(r11)
    .global _restgpr_26
_restgpr_26:
    lwz     r26, -24(r11)
    .global _restgpr_27
_restgpr_27:
    lwz     r27, -20(r11)
    .global _restgpr_28
_restgpr_28:
    lwz     r28, -16(r11)
    .global _restgpr_29
_restgpr_29:
    lwz     r29, -12(r11)
    .global _restgpr_30
_restgpr_30:
    lwz     r30, -8(r11)
    .global _restgpr_31
_restgpr_31:
    lwz     r31, -4(r11)
    blr

# ---------------------------------------------------------------------------
# _restfpr_14_x .. _restfpr_31_x — Restore FPRs + epilogue (restore LR, SP)
# These restore f14-f31, load LR from 4(r11), restore SP from r11, then blr
# ---------------------------------------------------------------------------
    .global _restfpr_14_x
_restfpr_14_x:
    lfd     f14, -144(r11)
    .global _restfpr_15_x
_restfpr_15_x:
    lfd     f15, -136(r11)
    .global _restfpr_16_x
_restfpr_16_x:
    lfd     f16, -128(r11)
    .global _restfpr_17_x
_restfpr_17_x:
    lfd     f17, -120(r11)
    .global _restfpr_18_x
_restfpr_18_x:
    lfd     f18, -112(r11)
    .global _restfpr_19_x
_restfpr_19_x:
    lfd     f19, -104(r11)
    .global _restfpr_20_x
_restfpr_20_x:
    lfd     f20, -96(r11)
    .global _restfpr_21_x
_restfpr_21_x:
    lfd     f21, -88(r11)
    .global _restfpr_22_x
_restfpr_22_x:
    lfd     f22, -80(r11)
    .global _restfpr_23_x
_restfpr_23_x:
    lfd     f23, -72(r11)
    .global _restfpr_24_x
_restfpr_24_x:
    lfd     f24, -64(r11)
    .global _restfpr_25_x
_restfpr_25_x:
    lfd     f25, -56(r11)
    .global _restfpr_26_x
_restfpr_26_x:
    lfd     f26, -48(r11)
    .global _restfpr_27_x
_restfpr_27_x:
    lfd     f27, -40(r11)
    .global _restfpr_28_x
_restfpr_28_x:
    lfd     f28, -32(r11)
    .global _restfpr_29_x
_restfpr_29_x:
    lfd     f29, -24(r11)
    .global _restfpr_30_x
_restfpr_30_x:
    lfd     f30, -16(r11)
    lwz     r0, 4(r11)
    .global _restfpr_31_x
_restfpr_31_x:
    lfd     f31, -8(r11)
    mtlr    r0
    mr      r1, r11
    blr

# ---------------------------------------------------------------------------
# _restgpr_14_x .. _restgpr_31_x — Restore GPRs + epilogue (restore LR, SP)
# These restore r14-r31, load LR from 4(r11), restore SP from r11, then blr
# ---------------------------------------------------------------------------
    .global _restgpr_14_x
_restgpr_14_x:
    lwz     r14, -72(r11)
    .global _restgpr_15_x
_restgpr_15_x:
    lwz     r15, -68(r11)
    .global _restgpr_16_x
_restgpr_16_x:
    lwz     r16, -64(r11)
    .global _restgpr_17_x
_restgpr_17_x:
    lwz     r17, -60(r11)
    .global _restgpr_18_x
_restgpr_18_x:
    lwz     r18, -56(r11)
    .global _restgpr_19_x
_restgpr_19_x:
    lwz     r19, -52(r11)
    .global _restgpr_20_x
_restgpr_20_x:
    lwz     r20, -48(r11)
    .global _restgpr_21_x
_restgpr_21_x:
    lwz     r21, -44(r11)
    .global _restgpr_22_x
_restgpr_22_x:
    lwz     r22, -40(r11)
    .global _restgpr_23_x
_restgpr_23_x:
    lwz     r23, -36(r11)
    .global _restgpr_24_x
_restgpr_24_x:
    lwz     r24, -32(r11)
    .global _restgpr_25_x
_restgpr_25_x:
    lwz     r25, -28(r11)
    .global _restgpr_26_x
_restgpr_26_x:
    lwz     r26, -24(r11)
    .global _restgpr_27_x
_restgpr_27_x:
    lwz     r27, -20(r11)
    .global _restgpr_28_x
_restgpr_28_x:
    lwz     r28, -16(r11)
    .global _restgpr_29_x
_restgpr_29_x:
    lwz     r29, -12(r11)
    .global _restgpr_30_x
_restgpr_30_x:
    lwz     r30, -8(r11)
    lwz     r0, 4(r11)
    .global _restgpr_31_x
_restgpr_31_x:
    lwz     r31, -4(r11)
    mtlr    r0
    mr      r1, r11
    blr
