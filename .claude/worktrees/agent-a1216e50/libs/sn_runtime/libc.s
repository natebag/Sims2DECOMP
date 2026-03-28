# =============================================================================
# libc.s — SN Systems libc small functions (<=64 bytes)
# Source: libc.a from SN Systems ProDG for GameCube
#
# All functions in this file are <=64 bytes and taken directly from the
# original ELF (u2_ngc_release_dvd.elf). Symbol names match the DVD map.
# =============================================================================

    .section .text
    .balign 4

# ---------------------------------------------------------------------------
# isdigit — Check if character is a digit
# Source: libc.a(isdigit.obj)
# Address: 0x80242690  Size: 0x14 (20 bytes)
# ---------------------------------------------------------------------------
    .global isdigit
isdigit:
    lis     r9, _ctype_+1@ha
    addi    r9, r9, _ctype_+1@l
    lbzx    r3, r3, r9
    rlwinm  r3, r3, 0, 29, 29       # isolate bit 2 (digit flag)
    blr

# ---------------------------------------------------------------------------
# puts — Write string to stdout
# Source: libc.a(puts.obj)
# Address: 0x802427c0  Size: 0x28 (40 bytes)
# ---------------------------------------------------------------------------
    .global puts
puts:
    stwu    r1, -8(r1)
    mflr    r0
    stw     r0, 12(r1)
    mr      r4, r3
    lwz     r3, _impure_ptr@sda21(r13)
    bl      _puts_r
    lwz     r0, 12(r1)
    mtlr    r0
    addi    r1, r1, 8
    blr

# ---------------------------------------------------------------------------
# abort — Terminate the process
# Source: libc.a(abort.obj)
# Address: 0x802427e8  Size: 0x18 (24 bytes)
# ---------------------------------------------------------------------------
    .global abort
abort:
    stwu    r1, -8(r1)
    mflr    r0
    stw     r0, 12(r1)
    li      r3, 1
    crclr   4*cr1+eq
    bl      _exit

# ---------------------------------------------------------------------------
# srand — Seed random number generator
# Source: libc.a(rand.obj)
# Address: 0x802432a4  Size: 0x0c (12 bytes)
# ---------------------------------------------------------------------------
    .global srand
srand:
    lwz     r9, _impure_ptr@sda21(r13)
    stw     r3, 88(r9)
    blr

# ---------------------------------------------------------------------------
# rand — Generate pseudo-random number
# Source: libc.a(rand.obj)
# Address: 0x802432b0  Size: 0x24 (36 bytes)
# ---------------------------------------------------------------------------
    .global rand
rand:
    lwz     r9, _impure_ptr@sda21(r13)
    lis     r0, 0x41C6
    ori     r0, r0, 0x4E6D
    lwz     r3, 88(r9)
    mullw   r3, r3, r0
    addi    r3, r3, 12345
    stw     r3, 88(r9)
    clrlwi  r3, r3, 1               # mask off sign bit
    blr

# ---------------------------------------------------------------------------
# malloc — Allocate memory (SN Systems wrapper)
# Source: libc.a(sn_malloc.obj)
# Address: 0x802432d4  Size: 0x3c (60 bytes)
# ---------------------------------------------------------------------------
    .global malloc
malloc:
    stwu    r1, -8(r1)
    mflr    r0
    stw     r0, 12(r1)
    mflr    r6
    lis     r5, sn_malloc_dispatch_table@ha
    addi    r6, r6, -4
    addi    r5, r5, sn_malloc_dispatch_table@l
    li      r3, 0
    li      r4, 0
    crclr   4*cr1+eq
    bl      OSPanic
    lwz     r0, 12(r1)
    mtlr    r0
    addi    r1, r1, 8
    blr

# ---------------------------------------------------------------------------
# free — Free memory (SN Systems wrapper)
# Source: libc.a(sn_malloc.obj)
# Address: 0x80243310  Size: 0x3c (60 bytes)
# ---------------------------------------------------------------------------
    .global free
free:
    stwu    r1, -8(r1)
    mflr    r0
    stw     r0, 12(r1)
    mflr    r6
    lis     r5, sn_free_dispatch_table@ha
    addi    r6, r6, -4
    addi    r5, r5, sn_free_dispatch_table@l
    li      r3, 0
    li      r4, 0
    crclr   4*cr1+eq
    bl      OSPanic
    lwz     r0, 12(r1)
    mtlr    r0
    addi    r1, r1, 8
    blr

# ---------------------------------------------------------------------------
# realloc — Reallocate memory (SN Systems wrapper)
# Source: libc.a(sn_malloc.obj)
# Address: 0x8024334c  Size: 0x3c (60 bytes)
# ---------------------------------------------------------------------------
    .global realloc
realloc:
    stwu    r1, -8(r1)
    mflr    r0
    stw     r0, 12(r1)
    mflr    r6
    lis     r5, sn_realloc_dispatch_table@ha
    addi    r6, r6, -4
    addi    r5, r5, sn_realloc_dispatch_table@l
    li      r3, 0
    li      r4, 0
    crclr   4*cr1+eq
    bl      OSPanic
    lwz     r0, 12(r1)
    mtlr    r0
    addi    r1, r1, 8
    blr

# ---------------------------------------------------------------------------
# calloc — Allocate and zero memory (SN Systems wrapper)
# Source: libc.a(sn_malloc.obj)
# Address: 0x80243388  Size: 0x3c (60 bytes)
# ---------------------------------------------------------------------------
    .global calloc
calloc:
    stwu    r1, -8(r1)
    mflr    r0
    stw     r0, 12(r1)
    mflr    r6
    lis     r5, sn_calloc_dispatch_table@ha
    addi    r6, r6, -4
    addi    r5, r5, sn_calloc_dispatch_table@l
    li      r3, 0
    li      r4, 0
    crclr   4*cr1+eq
    bl      OSPanic
    lwz     r0, 12(r1)
    mtlr    r0
    addi    r1, r1, 8
    blr

# ---------------------------------------------------------------------------
# _vfflush — Flush vfprintf buffer
# Source: libc.a(vfprintf.obj)
# Address: 0x802442f8  Size: 0x30 (48 bytes)
# ---------------------------------------------------------------------------
    .global _vfflush
_vfflush:
    stwu    r1, -8(r1)
    mflr    r0
    stw     r0, 12(r1)
    lha     r3, 14(r3)
    li      r4, 0
    li      r5, 0
    li      r6, 2
    bl      _vfwrite
    lwz     r0, 12(r1)
    mtlr    r0
    addi    r1, r1, 8
    blr

# ---------------------------------------------------------------------------
# vfiprintf — Integer-only variant of vfprintf
# Source: libc.a(vfiprintf.obj)
# Address: 0x802459ec  Size: 0x3c (60 bytes)
# ---------------------------------------------------------------------------
    .global vfiprintf
vfiprintf:
    stwu    r1, -8(r1)
    mflr    r0
    stw     r0, 12(r1)
    mr      r9, r3
    mr      r0, r4
    mr      r6, r5
    lwz     r3, 92(r9)
    mr      r4, r9
    mr      r5, r0
    crclr   4*cr1+eq
    bl      _vfiprintf_r
    lwz     r0, 12(r1)
    mtlr    r0
    addi    r1, r1, 8
    blr

# ---------------------------------------------------------------------------
# _localeconv_r — Reentrant localeconv
# Source: libc.a(locale.obj)
# Address: 0x80246ed0  Size: 0x0c (12 bytes)
# ---------------------------------------------------------------------------
    .global _localeconv_r
_localeconv_r:
    lis     r3, __lconv@ha
    addi    r3, r3, __lconv@l
    blr

# ---------------------------------------------------------------------------
# setlocale — Set program locale
# Source: libc.a(locale.obj)
# Address: 0x80246edc  Size: 0x30 (48 bytes)
# ---------------------------------------------------------------------------
    .global setlocale
setlocale:
    stwu    r1, -8(r1)
    mflr    r0
    stw     r0, 12(r1)
    mr      r0, r3
    mr      r5, r4
    lwz     r3, _impure_ptr@sda21(r13)
    mr      r4, r0
    bl      _setlocale_r
    lwz     r0, 12(r1)
    mtlr    r0
    addi    r1, r1, 8
    blr

# ---------------------------------------------------------------------------
# localeconv — Get locale formatting parameters
# Source: libc.a(locale.obj)
# Address: 0x80246f0c  Size: 0x24 (36 bytes)
# ---------------------------------------------------------------------------
    .global localeconv
localeconv:
    stwu    r1, -8(r1)
    mflr    r0
    stw     r0, 12(r1)
    lwz     r3, _impure_ptr@sda21(r13)
    bl      _localeconv_r
    lwz     r0, 12(r1)
    mtlr    r0
    addi    r1, r1, 8
    blr

# ---------------------------------------------------------------------------
# lflush — Local flush helper for refill
# Source: libc.a(refill.obj)
# Address: 0x80248a6c  Size: 0x20 (32 bytes)
# ---------------------------------------------------------------------------
    .global lflush
lflush:
    stwu    r1, -8(r1)
    mflr    r0
    stw     r0, 12(r1)
    bl      fflush
    lwz     r0, 12(r1)
    mtlr    r0
    addi    r1, r1, 8
    blr

# ---------------------------------------------------------------------------
# __sclose — Close file via FILE structure callback
# Source: libc.a(stdio.obj)
# Address: 0x80248d38  Size: 0x28 (40 bytes)
# ---------------------------------------------------------------------------
    .global __sclose
__sclose:
    stwu    r1, -8(r1)
    mflr    r0
    stw     r0, 12(r1)
    lha     r4, 14(r3)
    lwz     r3, 92(r3)
    bl      _close_r
    lwz     r0, 12(r1)
    mtlr    r0
    addi    r1, r1, 8
    blr

# ---------------------------------------------------------------------------
# fopen — Open file
# Source: libc.a(fopen.obj)
# Address: 0x802484b4  Size: 0x30 (48 bytes)
# ---------------------------------------------------------------------------
    .global fopen
fopen:
    stwu    r1, -8(r1)
    mflr    r0
    stw     r0, 12(r1)
    mr      r0, r3
    mr      r5, r4
    lwz     r3, _impure_ptr@sda21(r13)
    mr      r4, r0
    bl      _fopen_r
    lwz     r0, 12(r1)
    mtlr    r0
    addi    r1, r1, 8
    blr

# ---------------------------------------------------------------------------
# _cleanup_r — Reentrant cleanup (walks file list)
# Source: libc.a(fopen.obj)
# Address: 0x802484e4  Size: 0x28 (40 bytes)
# ---------------------------------------------------------------------------
    .global _cleanup_r
_cleanup_r:
    stwu    r1, -8(r1)
    mflr    r0
    stw     r0, 12(r1)
    lis     r4, fflush@ha
    addi    r4, r4, fflush@l
    bl      _fwalk
    lwz     r0, 12(r1)
    mtlr    r0
    addi    r1, r1, 8
    blr

# ---------------------------------------------------------------------------
# _cleanup — Non-reentrant cleanup wrapper
# Source: libc.a(fopen.obj)
# Address: 0x8024850c  Size: 0x24 (36 bytes)
# ---------------------------------------------------------------------------
    .global _cleanup
_cleanup:
    stwu    r1, -8(r1)
    mflr    r0
    stw     r0, 12(r1)
    lwz     r3, _impure_ptr@sda21(r13)
    bl      _cleanup_r
    lwz     r0, 12(r1)
    mtlr    r0
    addi    r1, r1, 8
    blr

# ---------------------------------------------------------------------------
# tolower — Convert character to lowercase
# Source: libc.a(tolower.obj)
# Address: 0x8036e220  Size: 0x1c (28 bytes)
# ---------------------------------------------------------------------------
    .global tolower
tolower:
    lis     r9, _ctype_+1@ha
    addi    r9, r9, _ctype_+1@l
    lbzx    r0, r3, r9
    andi.   r9, r0, 1                # test uppercase flag
    beqlr-
    addi    r3, r3, 32               # convert to lowercase
    blr

# ---------------------------------------------------------------------------
# vprintf — Formatted print to stdout
# Source: libc.a(vprintf.obj)
# Address: 0x8036e3e8  Size: 0x34 (52 bytes)
# ---------------------------------------------------------------------------
    .global vprintf
vprintf:
    stwu    r1, -8(r1)
    mflr    r0
    stw     r0, 12(r1)
    lwz     r9, _impure_ptr@sda21(r13)
    mr      r0, r3
    mr      r5, r4
    lwz     r3, 8(r9)               # stdout
    mr      r4, r0
    bl      vfprintf
    lwz     r0, 12(r1)
    mtlr    r0
    addi    r1, r1, 8
    blr

# ---------------------------------------------------------------------------
# atof — Convert string to double
# Source: libc.a(atof.obj)
# Address: 0x8036e4ec  Size: 0x24 (36 bytes)
# ---------------------------------------------------------------------------
    .global atof
atof:
    stwu    r1, -8(r1)
    mflr    r0
    stw     r0, 12(r1)
    li      r4, 0
    bl      strtod
    lwz     r0, 12(r1)
    mtlr    r0
    addi    r1, r1, 8
    blr

# ---------------------------------------------------------------------------
# atoi — Convert string to integer
# Source: libc.a(atoi.obj)
# Address: 0x8036e510  Size: 0x28 (40 bytes)
# ---------------------------------------------------------------------------
    .global atoi
atoi:
    stwu    r1, -8(r1)
    mflr    r0
    stw     r0, 12(r1)
    li      r4, 0
    li      r5, 10
    bl      strtol
    lwz     r0, 12(r1)
    mtlr    r0
    addi    r1, r1, 8
    blr

# ---------------------------------------------------------------------------
# strtodf — Convert string to float (via strtod)
# Source: libc.a(strtod2.obj)
# Address: 0x8036e900  Size: 0x20 (32 bytes)
# ---------------------------------------------------------------------------
    .global strtodf
strtodf:
    stwu    r1, -8(r1)
    mflr    r0
    stw     r0, 12(r1)
    bl      strtod
    lwz     r0, 12(r1)
    mtlr    r0
    addi    r1, r1, 8
    blr

# ---------------------------------------------------------------------------
# strtoul — Convert string to unsigned long
# Source: libc.a(strtoul.obj)
# Address: 0x8036eab8  Size: 0x38 (56 bytes)
# ---------------------------------------------------------------------------
    .global strtoul
strtoul:
    stwu    r1, -8(r1)
    mflr    r0
    stw     r0, 12(r1)
    mr      r0, r3
    mr      r9, r4
    mr      r6, r5
    lwz     r3, _impure_ptr@sda21(r13)
    mr      r4, r0
    mr      r5, r9
    bl      _strtoul_r
    lwz     r0, 12(r1)
    mtlr    r0
    addi    r1, r1, 8
    blr

# ---------------------------------------------------------------------------
# strtok — Tokenize string (non-reentrant wrapper)
# Source: libc.a(strtok.obj)
# Address: 0x8036eb34  Size: 0x28 (40 bytes)
# ---------------------------------------------------------------------------
    .global strtok
strtok:
    stwu    r1, -8(r1)
    mflr    r0
    stw     r0, 12(r1)
    lwz     r5, _impure_ptr@sda21(r13)
    addi    r5, r5, 92               # &_reent->_strtok_last
    bl      strtok_r
    lwz     r0, 12(r1)
    mtlr    r0
    addi    r1, r1, 8
    blr

# ---------------------------------------------------------------------------
# strtol — Convert string to long
# Source: libc.a(strtol.obj)
# Address: 0x8036edd4  Size: 0x38 (56 bytes)
# ---------------------------------------------------------------------------
    .global strtol
strtol:
    stwu    r1, -8(r1)
    mflr    r0
    stw     r0, 12(r1)
    mr      r0, r3
    mr      r9, r4
    mr      r6, r5
    lwz     r3, _impure_ptr@sda21(r13)
    mr      r4, r0
    mr      r5, r9
    bl      _strtol_r
    lwz     r0, 12(r1)
    mtlr    r0
    addi    r1, r1, 8
    blr

# ---------------------------------------------------------------------------
# isspace — Check if character is whitespace
# Source: libc.a(isspace.obj)
# Address: 0x8036ee0c  Size: 0x14 (20 bytes)
# ---------------------------------------------------------------------------
    .global isspace
isspace:
    lis     r9, _ctype_+1@ha
    addi    r9, r9, _ctype_+1@l
    lbzx    r3, r3, r9
    rlwinm  r3, r3, 0, 28, 28       # isolate bit 3 (space flag)
    blr

# ---------------------------------------------------------------------------
# __errno — Return pointer to errno
# Source: libc.a(errno.obj)
# Address: 0x8036ee20  Size: 0x08 (8 bytes)
# ---------------------------------------------------------------------------
    .global __errno
__errno:
    lwz     r3, _impure_ptr@sda21(r13)
    blr

# ---------------------------------------------------------------------------
# strlwr — Convert string to lowercase in-place
# Source: libc.a(strlwr.obj)
# Address: 0x8036eaf0  Size: 0x44 (68 bytes)
# NOTE: 68 bytes, slightly over 64 byte limit but included for completeness
# ---------------------------------------------------------------------------
    .global strlwr
strlwr:
    lbz     r0, 0(r3)
    mr      r10, r3
    cmpwi   r0, 0
    beqlr-
    lis     r9, _ctype_+1@ha
    addi    r8, r9, _ctype_+1@l
.L_strlwr_loop:
    lbz     r0, 0(r10)
    extsb   r11, r0
    lbzx    r9, r11, r8
    andi.   r0, r9, 1                # test uppercase flag
    beq-    .L_strlwr_skip
    addi    r0, r11, 32
    stb     r0, 0(r10)
.L_strlwr_skip:
    lbzu    r0, 1(r10)
    cmpwi   r0, 0
    bne+    .L_strlwr_loop
    blr
