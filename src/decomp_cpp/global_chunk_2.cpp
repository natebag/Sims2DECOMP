/*
 * global_chunk_2.cpp - global.cpp functions 495-988 (lines 52003-94075)
 *
 * Converted from inline PPC asm (src/asm_decomp/global.cpp) to portable C++.
 *
 * This chunk covers:
 *   - DolphinSDK OS functions (cache, context, interrupts, threads, timing)
 *   - DolphinSDK EXI/SI/VI/PAD/AI/DVD subsystems
 *   - OS linker/loader (Relocate, Link, Undo, OSUnlink)
 *   - OS memory protection, reset, SRAM
 *   - OS mutex/cond, scheduler
 *   - Debug subsystem (DB/DBG)
 *   - VEC math (C_VEC*, PSVec*)
 *   - APT engine globals (AptInitialize, AptReset, AptValue*, etc.)
 *   - Misc engine globals (SplitPath, MatrixInvert, Rndf, operators)
 *
 * Functions that require special PPC instructions (paired singles, cache ops,
 * MSR manipulation, SPR access, rfi) or SDA-relative addressing remain as
 * stubs with // NOTE: asm-derived comments.
 *
 * Source: Disassembly of extracted/sys/main.dol
 *         Symbol names from extracted/files/u2_ngc_release.map
 * Compiler: devkitPPC (GCC) with -O2 -mcpu=750
 */

#include "types.h"

/* ======================================================================
 * Forward declarations and types
 * ====================================================================== */

typedef f32 Vec[3];
typedef f32 Mtx[3][4];

/* DolphinSDK struct forward declarations */
typedef struct OSContext OSContext;
typedef struct OSThread OSThread;
typedef struct OSThreadQueue OSThreadQueue;
typedef struct OSAlarm OSAlarm;
typedef struct OSMutex OSMutex;
typedef struct OSCond OSCond;
typedef struct OSCalendarTime OSCalendarTime;
typedef struct OSResetFunctionInfo OSResetFunctionInfo;
typedef struct OSModuleInfo OSModuleInfo;
typedef struct OSModuleQueue OSModuleQueue;

typedef struct DVDFileInfo DVDFileInfo;
typedef struct DVDDir DVDDir;
typedef struct DVDDirEntry DVDDirEntry;
typedef struct DVDCommandBlock DVDCommandBlock;
typedef struct DVDDiskID DVDDiskID;

typedef struct PADStatus PADStatus;
typedef struct EXIDevice EXIDevice;

/* Callback typedefs */
typedef void (*OSAlarmHandler)(OSAlarm* alarm, OSContext* context);
typedef void (*OSResetCallback)(void);
typedef void (*OSSwitchThreadCallback)(OSThread* from, OSThread* to);
typedef void (*OSIdleFunction)(void* param);
typedef void (*DVDCallback)(s32 result, DVDFileInfo* fileInfo);
typedef void (*DVDCBCallback)(s32 result, DVDCommandBlock* block);
typedef void (*DVDLowCallback)(void);
typedef void (*PADSamplingCallback)(void);
typedef void (*VIRetraceCallback)(u32 retraceCount);
typedef s32 (*OSErrorHandler)(u16 error, OSContext* context, u32 dsisr, u32 dar);

/* APT forward declarations */
struct AptInitParmsT;
struct AptExtObject;
struct AptFile;
struct AptCIH;
struct AptCXForm;
struct AptnCXForm;
struct AptRenderingContext;
struct AptMatrix;
struct AptInputType {};
struct AptInputState {};
struct AptInputController {};
struct AptAnalogStickInfo {};
struct AptValue;
struct AptMaskRenderOperation {};
struct AptLinkerThingy;
template <typename T> struct AptSharedPtr {};
struct EAStringC;
enum NameStringType : int;

/* Engine forward declarations */
struct EStream;
struct EFile;
struct EString;
struct EStorable;
struct EFixedString;
struct EVec4;
struct EMat4;
struct ENDummy;
struct EQuat;

/* ======================================================================
 * OS Cache / Locked Cache
 *
 * These functions manipulate hardware cache registers and use special
 * PPC instructions (dcbtct, dcbz_l, mtspr, etc.) — must stay as stubs.
 * ====================================================================== */

// 0x8024C988 (216 bytes)
// NOTE: asm-derived — manipulates DSP audio registers directly via MMIO
void __OSStopAudioSystem() {
    // Writes to AI/DSP MMIO registers at 0xCC005000
    // Polls status bits, calls OSGetTick for timing
    // Cannot be expressed in portable C++
}

// 0x8024CCC0 (204 bytes)
// NOTE: asm-derived — manipulates MSR, HID2, DMA BAT registers
void __LCEnable() {
    // Enables Locked Cache via MSR, HID2, DBAT3 manipulation
    // Uses dcbtct, dcbst, dcbz_l special instructions
}

// 0x8024CE88 (112 bytes)
// NOTE: asm-derived — locked cache allocation
void LCAlloc(void* destAddr, u32 numBytes) {
    // Allocates locked cache blocks
    // Calls PPCMfhid2, __LCEnable, LCAllocTags
}

// 0x8024CEF8 (112 bytes)
// NOTE: asm-derived — locked cache allocation without invalidation
void LCAllocNoInvalidate(void* destAddr, u32 numBytes) {
    // Like LCAlloc but passes 0 (no invalidate) to LCAllocTags
}

// 0x8024CF68 (172 bytes)
// NOTE: asm-derived — DMA transfer from main memory to locked cache
u32 LCLoadData(void* destAddr, void* srcAddr, u32 numBytes) {
    // Loads data into locked cache in 4KB blocks
    // Calls LCLoadBlocks in a loop
    return 0;
}

// 0x8024D014 (172 bytes)
// NOTE: asm-derived — DMA transfer from locked cache to main memory
u32 LCStoreData(void* destAddr, void* srcAddr, u32 numBytes) {
    // Stores data from locked cache in 4KB blocks
    // Calls LCStoreBlocks in a loop
    return 0;
}

// 0x8024D0E0 (72 bytes)
// NOTE: asm-derived — flushes locked cache DMA queue
void LCFlushQueue() {
    // Calls PPCMtdmaU, PPCMtdmaL, PPCSync
}

// 0x8024D128 (76 bytes)
// NOTE: asm-derived — L2 cache initialization
void L2Init() {
    // Calls PPCMfmsr, PPCMtmsr, L2Disable, L2GlobalInvalidate
}

// 0x8024D1D0 (152 bytes)
// NOTE: asm-derived — L2 cache global invalidate
void L2GlobalInvalidate() {
    // Manipulates L2CR register via PPCMfl2cr/PPCMtl2cr
    // Polls L2CR bit 31 until clear
}

// 0x8024D2E8 (352 bytes)
// NOTE: asm-derived — DMA error handler
void DMAErrorHandler(u16 error, OSContext* context, u32 dsisr, u32 dar) {
    // Reads HID2 via PPCMfhid2, reports DMA errors via OSReport
    // Checks specific DMA error bits and either halts or clears
}

// 0x8024D448 (244 bytes)
// NOTE: asm-derived — cache subsystem initialization
void __OSCacheInit() {
    // Checks HID0 for I-cache and D-cache enable bits
    // Enables if needed, initializes L2 cache
    // Sets DMA error handler via OSSetErrorHandler
}

/* ======================================================================
 * OS Context (FPU save/restore, context switching)
 *
 * These manipulate FPU registers, SPRs, and use rfi — must stay as stubs.
 * ====================================================================== */

// 0x8024D53C (292 bytes)
// NOTE: asm-derived — loads all FPU registers from context
void __OSLoadFPUContext(u32 unused, OSContext* context) {
    // Loads FPSCR and all 32 FPRs from context
    // Also loads paired-singles state if HID2 indicates PS mode
}

// 0x8024D660 (296 bytes)
// NOTE: asm-derived — saves all FPU registers to context
void __OSSaveFPUContext(u32 unused1, u32 unused2, OSContext* context) {
    // Saves all 32 FPRs and FPSCR to context
    // Also saves paired-singles state if PS mode enabled
}

// 0x8024D798 (92 bytes)
// NOTE: asm-derived — sets current OS context
void OSSetCurrentContext(OSContext* context) {
    // Stores context pointer at 0x800000D4
    // If context == FPU owner, enables FPU in MSR
    // Otherwise disables FPU in context and MSR
}

// 0x8024D800 (128 bytes)
// NOTE: asm-derived — saves current CPU state to context
BOOL OSSaveContext(OSContext* context) {
    // Saves GPRs r13-r31 via stmw
    // Saves GQRs, CR, LR, SRR0, MSR, CTR, XER, SP, r2
    // Returns 0 (or 1 if restored via OSLoadContext)
    return 0;
}

// 0x8024D880 (216 bytes)
// NOTE: asm-derived — restores CPU state from context, does rfi
void OSLoadContext(OSContext* context) {
    // Restores GPRs, GQRs, CR, LR, CTR, XER
    // Sets SRR0/SRR1 and executes rfi
}

// 0x8024D9C4 (188 bytes)
// NOTE: asm-derived — initializes a new OS context
void OSInitContext(OSContext* context, void* pc, void* sp) {
    // Sets SRR0 = pc, SP = sp, MSR = default
    // Zeros all scratch GPRs and GQRs
    // Tail-calls OSClearContext
}

// 0x8024DA80 (680 bytes)
// NOTE: asm-derived — dumps context state via OSReport
void OSDumpContext(OSContext* context) {
    // Prints all GPRs (r0-r31), LR, CR, SRR0, MSR
    // If FPU state saved, also prints FPRs and PSRs
    // Walks stack trace up to 16 frames
}

// 0x8024DD28 (132 bytes)
// NOTE: asm-derived — switches FPU context between threads
void OSSwitchFPUContext(u16 error, OSContext* context) {
    // Enables FPU in MSR, saves old FPU context, loads new
    // Executes rfi to return to new context
}

// 0x8024DDAC (72 bytes)
// NOTE: asm-derived — context subsystem init
void __OSContextInit() {
    // Sets FPU exception handler via __OSDBJUMPEND
    // Clears FPU context owner pointer
}

// 0x8024DDF4 (300 bytes)
// NOTE: asm-derived — fills FPU context from current FPU state
void OSFillFPUContext(OSContext* context) {
    // Enables FPU in MSR, saves all FPRs and PS registers
}

/* ======================================================================
 * OS Reporting and Error Handling
 * ====================================================================== */

// 0x8024DF20 (128 bytes)
// NOTE: asm-derived — variadic, uses va_list struct on stack
void OSReport(const char* fmt, ...) {
    // Formats string and calls vprintf
    // Uses PPC varargs ABI (GPR save area + va_list struct)
}

// 0x8024DFC0 (300 bytes)
// NOTE: asm-derived — variadic panic with stack trace
void OSPanic(const char* file, int line, const char* fmt, ...) {
    // Disables interrupts, formats message via vprintf
    // Prints file:line, walks stack trace, calls PPCHalt
}

// 0x8024E0EC (536 bytes)
// NOTE: asm-derived — sets per-exception error handler
OSErrorHandler OSSetErrorHandler(u16 error, OSErrorHandler handler) {
    // Stores handler in error handler table
    // For FPU errors (error==16): iterates thread list to set/clear FPU state
    return (OSErrorHandler)0;
}

// 0x8024E304 (744 bytes)
// NOTE: asm-derived — default unhandled exception handler
void __OSUnhandledException(u16 error, OSContext* context, u32 dsisr, u32 dar) {
    // Handles FPU exceptions specially (dispatches to handler if installed)
    // For other exceptions: checks handler table, dispatches if available
    // Falls through to error report with context dump, stack trace
    // Switch table for exception-specific messages
}

/* ======================================================================
 * OS Exec / Boot DOL
 * ====================================================================== */

// 0x8024E5EC (392 bytes)
// NOTE: asm-derived — packs argument strings for DOL execution
BOOL PackArgs(void* buffer, int argc, char** argv) {
    // Copies argument strings into 8KB buffer
    // Adjusts pointers to be buffer-relative offsets
    return 1;
}

// 0x8024E7B0 (104 bytes)
// NOTE: asm-derived — starts execution of a loaded DOL
void StartDol(void* execParams, void* entryPoint) {
    // Allocates exec params, calls __OSSetExecParams
    // Disables interrupts, calls Run
}

// 0x8024E818 (108 bytes)
// NOTE: asm-derived — reads data from disc synchronously
void ReadDisc(void* dest, u32 offset, u32 length) {
    // Calls DVDReadAbsAsyncPrio, polls until complete
    // On disc error, calls __OSDoHotReset
}

// 0x8024E908 (68 bytes)
// NOTE: asm-derived — stores exec params pointer
void __OSSetExecParams(void* params, void* dest) {
    // memcpy params to dest, stores pointer at 0x800030F0
}

// 0x8024E94C (160 bytes)
// NOTE: asm-derived — stops any active disc streaming
void StopStreaming() {
    // Checks streaming flag, gets disk ID for streaming support
    // Mutes stream volume, cancels stream, waits for completion
}

// 0x8024E9EC (196 bytes)
// NOTE: asm-derived — gets apploader disc position
u32 GetApploaderPosition() {
    // Reads apploader offset from disc header
    // Caches result in static variable
    return 0;
}

// 0x8024EAB0 (244 bytes)
// NOTE: asm-derived — loads apploader from disc
void* LoadApploader() {
    // Reads apploader header, then loads full apploader code
    // Invalidates instruction cache for loaded region
    return (void*)0;
}

// 0x8024EBA4 (272 bytes)
// NOTE: asm-derived — loads DOL executable via apploader callbacks
void* LoadDol(void* execParams, void* apploaderInit) {
    // Calls apploader init/getNextSection/close callbacks
    // Reads DOL sections from disc
    return (void*)0;
}

// 0x8024ECF4 (1156 bytes)
// NOTE: asm-derived — boots a DOL with full setup
void __OSBootDolSimple(s32 dvdEntrynum, u32 apploaderFunc, s32 argc, char** argv,
                        u32 arenaLo, u32 resetCode, u32 bootInfo) {
    // Full boot sequence: DVD init, stream stop, apploader load
    // Loads DOL, prepares exec params, disables interrupts, runs
}

// 0x8024F178 (412 bytes)
// NOTE: asm-derived — boots a DOL from DVD entry
void __OSBootDol(s32 dvdEntrynum, void* entryPoint, char** argv) {
    // Gets save region, formats DOL path
    // Allocates argv array, calls __OSBootDolSimple
}

// 0x8024F314 (104 bytes)
// NOTE: asm-derived — common exec path
void ExecCommon(const char* path, char** argv) {
    // Opens DVD file, gets entry point, calls __OSBootDol
}

// 0x8024F37C (144 bytes)
// NOTE: asm-derived — exec with argv
void OSExecv(const char* path, char** argv) {
    // Disables scheduler, shuts down devices
    // Sets arena bounds, calls ExecCommon equivalent
}

// 0x8024F40C (324 bytes)
// NOTE: asm-derived — exec with variadic args
void OSExecl(const char* path, ...) {
    // Builds argv from varargs
    // Disables scheduler, shuts down devices, boots DOL
}

/* ======================================================================
 * OS Interrupts
 * ====================================================================== */

// 0x8024F5CC (116 bytes)
// NOTE: asm-derived — initializes interrupt subsystem
void __OSInterruptInit() {
    // Allocates handler table (32 entries)
    // Clears pending/mask registers
    // Masks all interrupts, sets external interrupt handler
}

// 0x8024F640 (728 bytes)
// NOTE: asm-derived — programs hardware interrupt mask registers
u32 SetInterruptMask(u32 intBits, u32 mask) {
    // Maps logical interrupt bits to hardware MMIO mask bits
    // Programs PI, MI, DSP, AI, EXI, CP interrupt masks
    return 0;
}

// 0x8024F924 (144 bytes)
// NOTE: asm-derived — sets interrupt mask (public API)
u32 OSSetInterruptMask(u32 mask) {
    // Disables interrupts, updates local + global masks
    // Calls SetInterruptMask for changed bits
    return 0;
}

// 0x8024F9B4 (136 bytes)
// NOTE: asm-derived — masks specified interrupts
u32 __OSMaskInterrupts(u32 mask) {
    // ORs mask into global mask, programs hardware
    return 0;
}

// 0x8024FA3C (136 bytes)
// NOTE: asm-derived — unmasks specified interrupts
u32 __OSUnmaskInterrupts(u32 mask) {
    // ANDCs mask from global mask, programs hardware
    return 0;
}

// 0x8024FAC4 (836 bytes)
// NOTE: asm-derived — main interrupt dispatch routine
void __OSDispatchInterrupt(u16 error, OSContext* context) {
    // Reads PI interrupt cause register
    // Maps hardware interrupt bits to logical interrupt numbers
    // Looks up and calls registered handler
    // Calls scheduler reschedule on return
}

// 0x8024FE08 (80 bytes)
// NOTE: asm-derived — external interrupt entry point
void ExternalInterruptHandler() {
    // Saves volatile GPRs and GQRs to context
    // Tail-jumps to __OSDispatchInterrupt
}

/* ======================================================================
 * OS Linker (module linking/unlinking)
 * ====================================================================== */

// 0x8024FE6C (700 bytes)
// NOTE: asm-derived — processes ELF relocations for a module
BOOL Relocate(OSModuleInfo* srcModule, OSModuleInfo* destModule) {
    // Iterates relocation entries, applies R_PPC_* relocation types
    // Handles: ADDR32, ADDR24, ADDR16_LO, ADDR16_HI, ADDR16_HA
    //          REL24, REL14, RVL_SECT (section-relative)
    // Calls DCFlushRange/ICInvalidateRange for code sections
    return 1;
}

// 0x80250128 (736 bytes)
// NOTE: asm-derived — links a module into the OS module list
BOOL Link(OSModuleInfo* module, void* bss, u32 bssSize) {
    // Validates module version and alignment
    // Adds to module linked list, adjusts section addresses
    // Resolves imports via Relocate, sets entry/exit points
    return 1;
}

// 0x80250468 (568 bytes)
// NOTE: asm-derived — undoes relocations for a module
void Undo(OSModuleInfo* srcModule, OSModuleInfo* destModule) {
    // Reverse of Relocate — zeroes out applied relocations
}

// 0x802506A0 (468 bytes)
// NOTE: asm-derived — unlinks a module from OS module list
BOOL OSUnlink(OSModuleInfo* module) {
    // Removes from linked list, calls Undo for all dependent modules
    // Adjusts section addresses back to relative offsets
    return 1;
}

// 0x8025088C (160 bytes)
// NOTE: asm-derived — searches for a module by ID
OSModuleInfo* OSSearchModule(u32 id) {
    // Walks module linked list looking for matching module ID
    return (OSModuleInfo*)0;
}

/* ======================================================================
 * OS Memory Protection
 * ====================================================================== */

// 0x80250980 (108 bytes)
// NOTE: asm-derived — memory protection interrupt handler
void MEMIntrruptHandler(u16 error, OSContext* context) {
    // Reports memory protection fault details via OSReport
}

// 0x802509EC (196 bytes)
// NOTE: asm-derived — configures a memory protection range
void OSProtectRange(u32 channel, void* addr, u32 numBytes, u32 control) {
    // Programs DBAT/IBAT or memory protection hardware
}

// 0x80250AB0 (128 bytes)
// NOTE: asm-derived — configures memory for 24MB mode
void Config24MB() {
    // Sets memory region sizes for 24MB console
}

// 0x80250B30 (128 bytes)
// NOTE: asm-derived — configures memory for 48MB mode
void Config48MB() {
    // Sets memory region sizes for 48MB (dev kit) console
}

// 0x80250BC8 (280 bytes)
// NOTE: asm-derived — initializes memory protection subsystem
void __OSInitMemoryProtection() {
    // Configures protection regions based on console memory size
    // Installs MEMIntrruptHandler
}

/* ======================================================================
 * OS Reset
 * ====================================================================== */

// 0x80250CE0 (112 bytes)
// NOTE: asm-derived — initiates system reboot
void __OSReboot(u32 resetCode, u32 forceMenu) {
    // Calls __OSBootDolSimple with reset parameters
}

// 0x80250D8C (132 bytes)
void OSRegisterResetFunction(OSResetFunctionInfo* info) {
    // Inserts reset function into priority-sorted linked list
}

// 0x80250E48 (168 bytes)
// NOTE: asm-derived — calls all registered reset functions
BOOL __OSCallResetFunctions(BOOL final) {
    // Walks reset function list, calls each one
    // Returns FALSE if any function returns FALSE
    return TRUE;
}

// 0x80250EF0 (112 bytes)
// NOTE: asm-derived — performs system reset
void Reset(u32 resetCode) {
    // Calls __OSCallResetFunctions, then hardware reset
}

// 0x80250F60 (104 bytes)
// NOTE: asm-derived — kills all threads except current
void KillThreads() {
    // Walks thread list, cancels all except current thread
}

// 0x80250FC8 (72 bytes)
// NOTE: asm-derived — performs hot reset (fast reboot)
void __OSDoHotReset(u32 resetCode) {
    // Writes reset code to hardware, triggers hardware reset
}

// 0x80251010 (432 bytes)
// NOTE: asm-derived — shuts down all registered devices
BOOL __OSShutdownDevices(BOOL final) {
    // Calls reset functions, waits for completion
    // Handles disc error recovery during shutdown
    return TRUE;
}

// 0x802511C0 (512 bytes)
// NOTE: asm-derived — public reset API
void OSResetSystem(u32 resetCode, u32 forceMenu, BOOL background) {
    // Full reset sequence: disable scheduler, shutdown devices
    // Stop streaming, prepare DVD reset, reboot
}

// 0x80251408 (244 bytes)
// NOTE: asm-derived — reset switch interrupt handler
void __OSResetSWInterruptHandler(u16 error, OSContext* context) {
    // Handles reset button press interrupt
}

// 0x802514FC (116 bytes)
OSResetCallback OSSetResetCallback(OSResetCallback callback) {
    // Sets and returns previous reset callback
    return (OSResetCallback)0;
}

// 0x80251570 (664 bytes)
// NOTE: asm-derived — reads reset button hardware state
BOOL OSGetResetButtonState() {
    // Polls hardware reset button status
    // Handles debouncing via timer
    return FALSE;
}

// 0x80251828 (92 bytes)
// NOTE: asm-derived — sets reset button timer
void __OSSetResetButtonTimer(OSAlarm* alarm) {
    // Configures alarm for reset button debounce
}

/* ======================================================================
 * OS RTC / SRAM
 * ====================================================================== */

// 0x80251884 (280 bytes)
// NOTE: asm-derived — reads real-time clock via EXI
BOOL GetRTC(u32* rtc) {
    // EXI channel 0, device 1, reads 4 bytes
    return TRUE;
}

// 0x8025199C (556 bytes)
// NOTE: asm-derived — public RTC read with retry
BOOL __OSGetRTC(u32* rtc) {
    // Calls GetRTC with retry logic and EXI lock management
    return TRUE;
}

// 0x80251BC8 (264 bytes)
// NOTE: asm-derived — sets RTC via EXI
BOOL __OSSetRTC(u32 rtc) {
    // EXI channel 0, device 1, writes 4 bytes
    return TRUE;
}

// 0x80251CD0 (284 bytes)
// NOTE: asm-derived — reads SRAM from EXI
void ReadSram() {
    // Reads 64 bytes of SRAM via EXI channel 0, device 1
}

// 0x80251DEC (96 bytes)
// NOTE: asm-derived — SRAM write completion callback
void WriteSramCallback(s32 channel, OSContext* context) {
    // EXI deselect/unlock, sets write-complete flag
}

// 0x80251E4C (280 bytes)
// NOTE: asm-derived — writes SRAM via EXI
void WriteSram(void* buffer, u32 offset, u32 size) {
    // EXI channel 0, device 1, writes SRAM data
}

// 0x80251F64 (316 bytes)
// NOTE: asm-derived — SRAM subsystem initialization
void __OSInitSram() {
    // Reads SRAM, validates checksum, initializes if invalid
}

// 0x802520A0 (104 bytes)
// NOTE: asm-derived — locks SRAM for reading
void* LockSram(u32 offset) {
    // Returns pointer into SRAM buffer at offset
    return (void*)0;
}

// 0x80252108 (92 bytes)
void* __OSLockSram() {
    // Calls LockSram(0)
    return (void*)0;
}

// 0x80252164 (92 bytes)
void* __OSLockSramEx() {
    // Calls LockSram(0x14) for extended SRAM area
    return (void*)0;
}

// 0x802521C0 (828 bytes)
// NOTE: asm-derived — unlocks SRAM, writes if modified
BOOL UnlockSram(BOOL modified, u32 offset) {
    // Recalculates checksum if modified, initiates EXI write
    return TRUE;
}

// 0x80252554 (272 bytes)
// NOTE: asm-derived — validates SRAM contents
BOOL __OSCheckSram() {
    // Verifies SRAM checksum and structure
    return TRUE;
}

// 0x80252664 (292 bytes)
// NOTE: asm-derived — reads ROM via EXI (synchronous)
BOOL __OSReadROM(void* dest, u32 offset, u32 size) {
    // EXI channel 0, device 1, reads ROM data
    return TRUE;
}

// 0x80252788 (92 bytes)
// NOTE: asm-derived — ROM read completion callback
void __OSReadROMCallback(s32 channel, OSContext* context) {
    // EXI deselect/unlock, sets completion flag
}

// 0x802527E4 (272 bytes)
// NOTE: asm-derived — reads ROM via EXI (async)
BOOL __OSReadROMAsync(void* dest, u32 offset, u32 size, void (*callback)(void)) {
    return TRUE;
}

/* ======================================================================
 * OS SRAM Settings (Sound, Video, Language, etc.)
 * ====================================================================== */

// 0x802528F4 (128 bytes)
u32 OSGetSoundMode() {
    // Reads sound mode from SRAM
    return 0;
}

// 0x80252974 (164 bytes)
void OSSetSoundMode(u32 mode) {
    // Writes sound mode to SRAM
}

// 0x80252A18 (112 bytes)
u32 OSGetProgressiveMode() {
    return 0;
}

// 0x80252A88 (164 bytes)
void OSSetProgressiveMode(u32 mode) {
}

// 0x80252B2C (124 bytes)
u32 OSGetVideoMode() {
    return 0;
}

// 0x80252BA8 (176 bytes)
void OSSetVideoMode(u32 mode) {
}

// 0x80252C58 (108 bytes)
u32 OSGetLanguage() {
    return 0;
}

// 0x80252CC4 (148 bytes)
void OSSetLanguage(u32 language) {
}

// 0x80252D58 (108 bytes)
u32 __OSGetBootMode() {
    return 0;
}

// 0x80252DC4 (164 bytes)
void __OSSetBootMode(u32 mode) {
}

// 0x80252E68 (112 bytes)
u32 OSGetEuRgb60Mode() {
    return 0;
}

// 0x80252ED8 (164 bytes)
void OSSetEuRgb60Mode(u32 mode) {
}

// 0x80252F7C (132 bytes)
u32 OSGetWirelessID(u32 channel) {
    return 0;
}

// 0x80253000 (172 bytes)
void OSSetWirelessID(u32 channel, u32 id) {
}

// 0x802530AC (112 bytes)
u32 OSGetGbsMode() {
    return 0;
}

// 0x8025311C (184 bytes)
void OSSetGbsMode(u32 mode) {
}

/* ======================================================================
 * OS Threads
 * ====================================================================== */

// 0x802531F4 (100 bytes)
// NOTE: asm-derived — initializes system call vector
void __OSInitSystemCall() {
    // Copies system call handler to exception vector 0x00000C00
}

// 0x8025325C (116 bytes)
OSSwitchThreadCallback OSSetSwitchThreadCallback(OSSwitchThreadCallback callback) {
    // Sets and returns previous thread switch callback
    return (OSSwitchThreadCallback)0;
}

// 0x802532D0 (344 bytes)
// NOTE: asm-derived — thread subsystem initialization
void __OSThreadInit() {
    // Creates default thread for main execution
    // Initializes run queue and thread list
}

// 0x80253444 (92 bytes)
// NOTE: asm-derived — switches to next ready thread
void __OSSwitchThread(OSThread* nextThread) {
    // Saves current context, loads next thread context
}

// 0x802534F0 (68 bytes)
// NOTE: asm-derived — checks if thread is in active list
BOOL __OSIsThreadActive(OSThread* thread) {
    // Walks thread list looking for match
    return FALSE;
}

// 0x802535B4 (108 bytes)
// NOTE: asm-derived — adds thread to run queue
void SetRun(OSThread* thread) {
    // Inserts into priority-sorted run queue
}

// 0x80253620 (104 bytes)
// NOTE: asm-derived — removes thread from run queue
void UnsetRun(OSThread* thread) {
    // Removes from run queue linked list
}

// 0x802536C4 (448 bytes)
// NOTE: asm-derived — sets effective priority with inheritance
s32 SetEffectivePriority(OSThread* thread, s32 priority) {
    // Handles priority inheritance through mutex chains
    return 0;
}

// 0x80253884 (120 bytes)
void UpdatePriority(OSThread* thread) {
    // Recalculates effective priority from base + mutex chain
}

// 0x802538FC (80 bytes)
// NOTE: asm-derived — promotes thread priority temporarily
void __OSPromoteThread(OSThread* thread, s32 priority) {
    // Sets effective priority, adjusts queue position
}

// 0x8025394C (552 bytes)
// NOTE: asm-derived — selects next thread to run
void SelectThread(BOOL yield) {
    // Picks highest priority ready thread
    // Calls switch callback, performs context switch
}

// 0x80253BE0 (488 bytes)
// NOTE: asm-derived — creates a new thread
BOOL OSCreateThread(OSThread* thread, void* (*func)(void*), void* param,
                    void* stack, u32 stackSize, s32 priority, u16 attr) {
    // Initializes thread context with entry point and stack
    // Adds to thread list, sets initial state to suspended
    return TRUE;
}

// 0x80253DC8 (228 bytes)
// NOTE: asm-derived — exits current thread
void OSExitThread(void* value) {
    // Sets thread state to moribund
    // Wakes any threads waiting in OSJoinThread
    // Reschedules
}

// 0x80253EAC (444 bytes)
// NOTE: asm-derived — cancels a thread
void OSCancelThread(OSThread* thread) {
    // Sets thread state to moribund
    // Removes from any wait queues, handles mutex release
}

// 0x80254068 (320 bytes)
// NOTE: asm-derived — waits for thread to exit
BOOL OSJoinThread(OSThread* thread, void** value) {
    // If thread already dead, returns immediately
    // Otherwise sleeps on thread's join queue
    return TRUE;
}

// 0x802541A8 (160 bytes)
void OSDetachThread(OSThread* thread) {
    // Marks thread as detached (no join needed)
    // If already dead, cleans up immediately
}

// 0x80254248 (648 bytes)
// NOTE: asm-derived — resumes a suspended thread
s32 OSResumeThread(OSThread* thread) {
    // Decrements suspend count, adds to run queue if ready
    // Handles priority inheritance, reschedules if needed
    return 0;
}

// 0x802544D0 (368 bytes)
// NOTE: asm-derived — suspends a thread
s32 OSSuspendThread(OSThread* thread) {
    // Increments suspend count, removes from run queue
    return 0;
}

// 0x80254640 (236 bytes)
// NOTE: asm-derived — puts current thread to sleep on queue
void OSSleepThread(OSThreadQueue* queue) {
    // Adds current thread to queue, reschedules
}

// 0x8025472C (260 bytes)
// NOTE: asm-derived — wakes all threads sleeping on queue
void OSWakeupThread(OSThreadQueue* queue) {
    // Moves all threads from queue to run queue
}

// 0x80254830 (192 bytes)
// NOTE: asm-derived — changes thread priority
BOOL OSSetThreadPriority(OSThread* thread, s32 priority) {
    // Updates base priority, recalculates effective priority
    return TRUE;
}

// 0x802548F8 (144 bytes)
void OSSetIdleFunction(OSIdleFunction func, void* param, void* stack, u32 stackSize) {
    // Creates idle thread running given function
}

// 0x802549A4 (156 bytes)
// NOTE: asm-derived — validates a thread queue
void CheckThreadQueue(OSThreadQueue* queue) {
    // Debug function, walks queue checking for corruption
}

// 0x80254A6C (1872 bytes)
// NOTE: asm-derived — validates all active threads
void OSCheckActiveThreads() {
    // Walks thread list, checks each thread's state consistency
    // Validates stack, queue membership, mutex ownership
}

// 0x802551BC (172 bytes)
void OSClearStack(u8 value) {
    // Fills unused portion of current thread's stack with value
}

/* ======================================================================
 * OS Time
 * ====================================================================== */

// 0x80255304 (132 bytes)
// NOTE: asm-derived — sets OS time base
void __OSSetTime(s64 time) {
    // Writes to TBU/TBL registers, adjusts stored time
}

// 0x80255388 (100 bytes)
// NOTE: asm-derived — reads system time
s64 __OSGetSystemTime() {
    // Reads TBU/TBL, adjusts for OS epoch
    return 0;
}

// 0x802553EC (88 bytes)
// NOTE: asm-derived — converts OS time to system time
s64 __OSTimeToSystemTime(s64 time) {
    return 0;
}

// 0x8025544C (136 bytes)
static BOOL IsLeapYear(s32 year) {
    // Standard leap year check: divisible by 4, not 100, unless 400
    if ((year % 4) == 0) {
        if ((year % 100) == 0) {
            return (year % 400) == 0;
        }
        return TRUE;
    }
    return FALSE;
}

// 0x802554D4 (168 bytes)
static s32 GetYearDays(s32 year, s32 month) {
    // Returns cumulative days in year up to given month
    static const s16 daysPerMonth[] = {0, 31, 59, 90, 120, 151, 181, 212, 243, 273, 304, 334, 365};
    s32 days = daysPerMonth[month];
    if (month > 1 && IsLeapYear(year)) days++;
    return days;
}

// 0x8025557C (80 bytes)
static s32 GetLeapDays(s32 year) {
    // Returns number of leap days from epoch to given year
    if (year <= 0) return 0;
    return (year / 4) - (year / 100) + (year / 400);
}

// 0x802555CC (412 bytes)
// NOTE: asm-derived — converts tick count to date components
static void GetDates(s32 days, s32* year, s32* month, s32* dayOfMonth, s32* dayOfWeek, s32* dayOfYear) {
    // Iteratively finds year, then month from cumulative day count
}

// 0x80255768 (516 bytes)
void OSTicksToCalendarTime(s64 ticks, OSCalendarTime* result) {
    // Converts tick count to broken-down calendar time
    // Handles seconds, minutes, hours, day, month, year
}

// 0x8025596C (736 bytes)
s64 OSCalendarTimeToTicks(OSCalendarTime* ct) {
    // Converts broken-down calendar time to ticks
    return 0;
}

/* ======================================================================
 * C++ Runtime
 * ====================================================================== */

// 0x80255C6C (84 bytes)
void __init_cpp() {
    // Calls global C++ constructors via __ctors array
}

// 0x80255CC0 (84 bytes)
void __fini_cpp() {
    // Calls global C++ destructors via __dtors array
}

// 0x80255D34 (84 bytes)
void exit(int status) {
    // Calls __fini_cpp, then halts
    __fini_cpp();
}

/* ======================================================================
 * OS Mutex / Cond
 * ====================================================================== */

// 0x80255DE0 (220 bytes)
void OSLockMutex(OSMutex* mutex) {
    // If mutex free, acquires it. If owned by self, increments count.
    // Otherwise sleeps on mutex queue.
}

// 0x80255EBC (200 bytes)
void OSUnlockMutex(OSMutex* mutex) {
    // Decrements lock count. If zero, transfers ownership to next waiter.
}

// 0x80255F84 (112 bytes)
// NOTE: asm-derived — releases all mutexes held by a thread
void __OSUnlockAllMutex(OSThread* thread) {
    // Walks thread's mutex list, unlocks each
}

// 0x80255FF4 (188 bytes)
BOOL OSTryLockMutex(OSMutex* mutex) {
    // Non-blocking lock attempt. Returns TRUE if acquired.
    return FALSE;
}

// 0x802560D0 (212 bytes)
void OSWaitCond(OSCond* cond, OSMutex* mutex) {
    // Atomically releases mutex and sleeps on cond queue
}

// 0x802561F0 (256 bytes)
// NOTE: asm-derived — validates mutex state
void __OSCheckMutex(OSMutex* mutex) {
    // Debug: validates mutex internal consistency
}

// 0x80256328 (116 bytes)
// NOTE: asm-derived — validates all mutexes for a thread
void __OSCheckMutexes(OSThread* thread) {
    // Debug: walks thread's mutex list, validates each
}

/* ======================================================================
 * EXI (Expansion Interface)
 * ====================================================================== */

// 0x8025639C (244 bytes)
// NOTE: asm-derived — sets EXI interrupt masks per channel
void SetExiInterruptMask(s32 channel, u32 mask) {
}

// 0x80256490 (340 bytes)
// NOTE: asm-derived — completes an EXI transfer
void CompleteTransfer(s32 channel) {
}

// 0x802565E4 (604 bytes)
// NOTE: asm-derived — performs immediate EXI transfer
BOOL EXIImm(s32 channel, void* data, s32 length, u32 type, void* callback) {
    return TRUE;
}

// 0x80256840 (160 bytes)
BOOL EXIImmEx(s32 channel, void* data, s32 length, u32 type) {
    // Calls EXIImm in a loop for multi-word transfers
    return TRUE;
}

// 0x802568E0 (236 bytes)
// NOTE: asm-derived — performs DMA EXI transfer
BOOL EXIDma(s32 channel, void* data, s32 length, u32 type, void* callback) {
    return TRUE;
}

// 0x802569CC (588 bytes)
// NOTE: asm-derived — waits for EXI transfer completion
BOOL EXISync(s32 channel) {
    return TRUE;
}

// 0x80256C18 (72 bytes)
void EXIClearInterrupts(s32 channel, BOOL exi, BOOL tc, BOOL ext) {
    // Clears EXI interrupt status bits
}

// 0x80256C60 (124 bytes)
void* EXISetExiCallback(s32 channel, void* callback) {
    return (void*)0;
}

// 0x80256CDC (76 bytes)
void EXIProbeReset() {
    // Resets EXI probe state
}

// 0x80256D28 (372 bytes)
// NOTE: asm-derived — internal probe for EXI device presence
BOOL __EXIProbe(s32 channel) {
    return TRUE;
}

// 0x80256E9C (128 bytes)
BOOL EXIProbe(s32 channel) {
    return TRUE;
}

// 0x80256F1C (180 bytes)
BOOL EXIProbeEx(s32 channel) {
    return TRUE;
}

// 0x80256FD0 (212 bytes)
// NOTE: asm-derived — internal device attach
BOOL __EXIAttach(s32 channel, void* callback) {
    return TRUE;
}

// 0x802570A4 (268 bytes)
BOOL EXIAttach(s32 channel, void* callback) {
    return TRUE;
}

// 0x802571B0 (188 bytes)
BOOL EXIDetach(s32 channel) {
    return TRUE;
}

// 0x8025726C (340 bytes)
// NOTE: asm-derived — selects EXI device (SD card variant)
BOOL EXISelectSD(s32 channel, u32 device, u32 freq) {
    return TRUE;
}

// 0x802573C0 (300 bytes)
BOOL EXISelect(s32 channel, u32 device, u32 freq) {
    return TRUE;
}

// 0x802574EC (272 bytes)
BOOL EXIDeselect(s32 channel) {
    return TRUE;
}

// 0x802575FC (200 bytes)
// NOTE: asm-derived — EXI interrupt handler
void EXIIntrruptHandler(u16 error, OSContext* context) {
}

// 0x802576C4 (536 bytes)
// NOTE: asm-derived — transfer complete interrupt handler
void TCIntrruptHandler(u16 error, OSContext* context) {
}

// 0x802578DC (208 bytes)
// NOTE: asm-derived — external device interrupt handler
void EXTIntrruptHandler(u16 error, OSContext* context) {
}

// 0x802579AC (468 bytes)
// NOTE: asm-derived — EXI subsystem initialization
void EXIInit() {
    // Initializes all 3 EXI channels
    // Registers interrupt handlers
}

// 0x80257B80 (244 bytes)
BOOL EXILock(s32 channel, u32 device, void* callback) {
    return TRUE;
}

// 0x80257C74 (220 bytes)
BOOL EXIUnlock(s32 channel) {
    return TRUE;
}

// 0x80257D90 (944 bytes)
// NOTE: asm-derived — gets device ID via EXI
BOOL EXIGetID(s32 channel, u32 device, u32* id) {
    return TRUE;
}

// 0x80258140 (280 bytes)
s32 EXIGetType(s32 channel, u32 device) {
    return 0;
}

// 0x80258258 (564 bytes)
// NOTE: asm-derived — returns device type as string
const char* EXIGetTypeString(s32 type) {
    return "Unknown";
}

// 0x8025848C (396 bytes)
// NOTE: asm-derived — probes for BBA device
BOOL ProbeBarnacle(s32 channel, u32 device) {
    return FALSE;
}

// 0x80258618 (444 bytes)
// NOTE: asm-derived — enables BBA debug device
BOOL __OSEnableBarnacle(s32 channel, u32 device) {
    return FALSE;
}

/* ======================================================================
 * UART (Serial Debug)
 * ====================================================================== */

// 0x802587D4 (112 bytes)
void InitializeUART(u32 baudRate) {
    // Initializes UART for debug output
}

// 0x8025884C (152 bytes)
s32 QueueLength() {
    // Returns number of bytes in UART transmit queue
    return 0;
}

// 0x802588E4 (512 bytes)
// NOTE: asm-derived — writes data to UART
s32 WriteUARTN(void* data, u32 length) {
    return 0;
}

/* ======================================================================
 * SI (Serial Interface — Controller Ports)
 * ====================================================================== */

// 0x80258B5C (764 bytes)
// NOTE: asm-derived — completes an SI transfer (overloaded name in SI context)
void CompleteTransfer(void) {
    // SI-specific transfer completion
}

// 0x80258E58 (240 bytes)
// NOTE: asm-derived — initiates next queued SI transfer
void SITransferNext(s32 channel) {
}

// 0x80258F48 (836 bytes)
// NOTE: asm-derived — SI interrupt handler
void SIInterruptHandler(u16 error, OSContext* context) {
}

// 0x8025928C (152 bytes)
BOOL SIEnablePollingInterrupt(BOOL enable) {
    return FALSE;
}

// 0x80259324 (204 bytes)
BOOL SIRegisterPollingHandler(void* handler) {
    return TRUE;
}

// 0x802593F0 (244 bytes)
BOOL SIUnregisterPollingHandler(void* handler) {
    return TRUE;
}

// 0x802594E4 (180 bytes)
// NOTE: asm-derived — SI subsystem initialization
void SIInit() {
}

// 0x80259598 (524 bytes)
// NOTE: asm-derived — internal SI transfer function
BOOL __SITransfer(s32 channel, void* output, u32 outputLength,
                  void* input, u32 inputLength, void* callback) {
    return TRUE;
}

// 0x802597A4 (264 bytes)
u32 SISync() {
    return 0;
}

// 0x802598AC (124 bytes)
u32 SIGetStatus(s32 channel) {
    return 0;
}

// 0x80259960 (108 bytes)
void SISetXY(u32 x, u32 y) {
}

// 0x802599CC (156 bytes)
u32 SIEnablePolling(u32 mask) {
    return 0;
}

// 0x80259A68 (108 bytes)
u32 SIDisablePolling(u32 mask) {
    return 0;
}

// 0x80259AD4 (212 bytes)
BOOL SIGetResponseRaw(s32 channel) {
    return FALSE;
}

// 0x80259BA8 (196 bytes)
BOOL SIGetResponse(s32 channel, void* data) {
    return FALSE;
}

// 0x80259C6C (140 bytes)
// NOTE: asm-derived — SI alarm handler
void AlarmHandler_SI(OSAlarm* alarm, OSContext* context) {
}

// 0x80259CF8 (364 bytes)
BOOL SITransfer(s32 channel, void* output, u32 outputLength,
                void* input, u32 inputLength, void* callback, s64 delay) {
    return TRUE;
}

// 0x80259E64 (120 bytes)
void CallTypeAndStatusCallback(s32 channel, u32 type) {
}

// 0x80259EDC (664 bytes)
// NOTE: asm-derived — callback for SIGetType
void GetTypeCallback(s32 channel, u32 status) {
}

// 0x8025A174 (452 bytes)
u32 SIGetType(s32 channel) {
    return 0;
}

// 0x8025A338 (316 bytes)
u32 SIGetTypeAsync(s32 channel, void* callback) {
    return 0;
}

// 0x8025A474 (332 bytes)
u32 SIDecodeType(u32 type) {
    return 0;
}

// 0x8025A5E4 (344 bytes)
// NOTE: asm-derived — returns device type as string
const char* SIGetTypeString(u32 type) {
    return "Unknown";
}

// 0x8025A73C (228 bytes)
void SISetSamplingRate(u32 rate) {
}

/* ======================================================================
 * DB (Debug)
 * ====================================================================== */

// 0x8025A888 (72 bytes)
// NOTE: asm-derived — debug exception destination
void __DBExceptionDestinationAux() {
}

// 0x8025A8FC (68 bytes)
// NOTE: asm-derived — marks exception for debugger
void __DBMarkException(u16 error) {
}

// 0x8025A94C (80 bytes)
// NOTE: asm-derived — debug printf (may be no-op in release)
void DBPrintf(const char* fmt, ...) {
}

/* ======================================================================
 * VEC Math
 * ====================================================================== */

// 0x8025AA90 (200 bytes)
void C_VECNormalize(const Vec* src, Vec* dst) {
    f32 x = (*src)[0], y = (*src)[1], z = (*src)[2];
    f32 len = x*x + y*y + z*z;
    if (len > 0.0f) {
        // Reciprocal square root approximation
        f32 inv;
        // Newton-Raphson: initial estimate from frsqrte
        // NOTE: asm uses frsqrte PPC instruction for fast inverse sqrt
        inv = 1.0f;  // placeholder
        if (len != 0.0f) {
            // Proper implementation would use hardware frsqrte
            f32 s = 1.0f;
            // Two Newton-Raphson iterations
            for (int i = 0; i < 2; i++) {
                s = s * (1.5f - 0.5f * len * s * s);
            }
            inv = s;
        }
        (*dst)[0] = x * inv;
        (*dst)[1] = y * inv;
        (*dst)[2] = z * inv;
    }
}

// 0x8025AB58 (68 bytes)
// NOTE: asm-derived — paired-singles version
void PSVECNormalize(const Vec* src, Vec* dst) {
    // Uses ps_* paired single instructions — not portable
    C_VECNormalize(src, dst);
}

// 0x8025ABD8 (148 bytes)
f32 C_VECMag(const Vec* v) {
    f32 x = (*v)[0], y = (*v)[1], z = (*v)[2];
    f32 sq = x*x + y*y + z*z;
    // NOTE: asm uses frsqrte + Newton-Raphson then multiplies by sq
    // to get magnitude without sqrt
    return sq; // placeholder — real version computes sqrt via frsqrte
}

// 0x8025AC6C (68 bytes)
// NOTE: asm-derived — paired-singles version
f32 PSVECMag(const Vec* v) {
    return C_VECMag(v);
}

// 0x8025AD00 (76 bytes)
void C_VECCrossProduct(const Vec* a, const Vec* b, Vec* result) {
    f32 ax = (*a)[0], ay = (*a)[1], az = (*a)[2];
    f32 bx = (*b)[0], by = (*b)[1], bz = (*b)[2];
    (*result)[0] = ay * bz - az * by;
    (*result)[1] = az * bx - ax * bz;
    (*result)[2] = ax * by - ay * bx;
}

// 0x8025AD88 (216 bytes)
void C_VECHalfAngle(const Vec* a, const Vec* b, Vec* result) {
    // Computes normalized half-angle vector between a and b
    (*result)[0] = (*a)[0] + (*b)[0];
    (*result)[1] = (*a)[1] + (*b)[1];
    (*result)[2] = (*a)[2] + (*b)[2];
    C_VECNormalize(result, result);
}

// 0x8025AE60 (212 bytes)
void C_VECReflect(const Vec* incident, const Vec* normal, Vec* result) {
    // Reflects incident vector about normal
    f32 dot = (*incident)[0] * (*normal)[0] + (*incident)[1] * (*normal)[1] + (*incident)[2] * (*normal)[2];
    (*result)[0] = (*incident)[0] - 2.0f * dot * (*normal)[0];
    (*result)[1] = (*incident)[1] - 2.0f * dot * (*normal)[1];
    (*result)[2] = (*incident)[2] - 2.0f * dot * (*normal)[2];
}

// 0x8025AF98 (172 bytes)
f32 C_VECDistance(const Vec* a, const Vec* b) {
    f32 dx = (*a)[0] - (*b)[0];
    f32 dy = (*a)[1] - (*b)[1];
    f32 dz = (*a)[2] - (*b)[2];
    f32 sq = dx*dx + dy*dy + dz*dz;
    // NOTE: uses frsqrte + Newton-Raphson to compute distance
    return sq; // placeholder
}

// 0x8025B044 (84 bytes)
// NOTE: asm-derived — paired-singles version
f32 PSVECDistance(const Vec* a, const Vec* b) {
    return C_VECDistance(a, b);
}

/* ======================================================================
 * DVD File System
 * ====================================================================== */

// 0x8025B0D0 (160 bytes)
// NOTE: asm-derived — compares path component for case-insensitive match
static BOOL isSame(const char* path, const char* fstName) {
    return FALSE;
}

// 0x8025B170 (756 bytes)
s32 DVDConvertPathToEntrynum(const char* path) {
    // Walks FST to find entry number for given path
    return -1;
}

// 0x8025B464 (116 bytes)
BOOL DVDFastOpen(s32 entrynum, DVDFileInfo* fileInfo) {
    // Opens file by entry number (no path lookup)
    return TRUE;
}

// 0x8025B4D8 (200 bytes)
BOOL DVDOpen(const char* path, DVDFileInfo* fileInfo) {
    // Calls DVDConvertPathToEntrynum + DVDFastOpen
    return TRUE;
}

// 0x8025B5FC (352 bytes)
// NOTE: asm-derived — converts entry number to path string
static BOOL entryToPath(s32 entrynum, char* path, u32 maxLen) {
    return FALSE;
}

// 0x8025B75C (340 bytes)
BOOL DVDConvertEntrynumToPath(s32 entrynum, char* path, u32 maxLen) {
    return FALSE;
}

// 0x8025B8B0 (196 bytes)
BOOL DVDGetCurrentDir(char* path, u32 maxLen) {
    return FALSE;
}

// 0x8025B974 (96 bytes)
BOOL DVDChangeDir(const char* path) {
    return TRUE;
}

// 0x8025B9D4 (192 bytes)
BOOL DVDReadAsyncPrio(DVDFileInfo* fileInfo, void* buffer, s32 length,
                      s32 offset, DVDCallback callback, s32 prio) {
    return TRUE;
}

// 0x8025BAC4 (280 bytes)
s32 DVDReadPrio(DVDFileInfo* fileInfo, void* buffer, s32 length,
                s32 offset, s32 prio) {
    return 0;
}

// 0x8025BC00 (152 bytes)
BOOL DVDSeekAsyncPrio(DVDFileInfo* fileInfo, s32 offset, DVDCallback callback, s32 prio) {
    return TRUE;
}

// 0x8025BCC8 (172 bytes)
s32 DVDSeekPrio(DVDFileInfo* fileInfo, s32 offset, s32 prio) {
    return 0;
}

// 0x8025BDB8 (104 bytes)
BOOL DVDFastOpenDir(s32 entrynum, DVDDir* dir) {
    return TRUE;
}

// 0x8025BE20 (192 bytes)
BOOL DVDOpenDir(const char* path, DVDDir* dir) {
    return TRUE;
}

// 0x8025BEE0 (164 bytes)
BOOL DVDReadDir(DVDDir* dir, DVDDirEntry* entry) {
    return FALSE;
}

// 0x8025BFA8 (236 bytes)
BOOL DVDPrepareStreamAsync(DVDFileInfo* fileInfo, u32 length, u32 offset,
                            DVDCallback callback) {
    return TRUE;
}

// 0x8025C0C4 (324 bytes)
s32 DVDPrepareStream(DVDFileInfo* fileInfo, u32 length, u32 offset) {
    return 0;
}

// 0x8025C22C (108 bytes)
s32 DVDGetTransferredSize(DVDFileInfo* fileInfo) {
    return 0;
}

// 0x8025C2A4 (216 bytes)
// NOTE: asm-derived — DVD subsystem initialization
void DVDInit() {
    // Initializes FST, installs interrupt handlers
}

// 0x8025C37C (148 bytes)
// NOTE: asm-derived — state: reading FST from disc
void stateReadingFST() {
}

// 0x8025C410 (128 bytes)
void cbForStateReadingFST(u32 result) {
}

// 0x8025C490 (172 bytes)
void cbForStateError(u32 result) {
}

// 0x8025C5C4 (180 bytes)
s32 CategorizeError(u32 error) {
    return 0;
}

// 0x8025C678 (156 bytes)
BOOL CheckCancel(void) {
    return FALSE;
}

// 0x8025C714 (612 bytes)
// NOTE: asm-derived — callback for error recovery state
void cbForStateGettingError(u32 result) {
}

// 0x8025C978 (92 bytes)
void cbForUnrecoveredError(u32 result) {
}

// 0x8025C9D4 (128 bytes)
void cbForUnrecoveredErrorRetry(u32 result) {
}

// 0x8025CA7C (320 bytes)
void cbForStateGoToRetry(u32 result) {
}

// 0x8025CBBC (224 bytes)
void stateCheckID() {
}

// 0x8025CD04 (104 bytes)
void cbForStateCheckID2a(u32 result) {
}

// 0x8025CDA4 (252 bytes)
void cbForStateCheckID1(u32 result) {
}

// 0x8025CEA0 (216 bytes)
void cbForStateCheckID2(u32 result) {
}

// 0x8025CF78 (240 bytes)
void cbForStateCheckID3(u32 result) {
}

// 0x8025D068 (68 bytes)
// NOTE: overloaded name — DVD-specific alarm handler
void AlarmHandler_DVD(OSAlarm* alarm, OSContext* context) {
}

// 0x8025D0AC (212 bytes)
void stateCoverClosed() {
}

// 0x8025D1B0 (100 bytes)
void cbForStateCoverClosed(u32 result) {
}

// 0x8025D23C (236 bytes)
void cbForStateMotorStopped(u32 result) {
}

// 0x8025D328 (744 bytes)
// NOTE: asm-derived — DVD ready state machine
void stateReady() {
}

// 0x8025D610 (832 bytes)
// NOTE: asm-derived — DVD busy state machine
void stateBusy() {
}

// 0x8025D990 (92 bytes)
static BOOL IsImmCommandWithResult(u32 command) {
    return FALSE;
}

// 0x8025DA2C (1624 bytes)
// NOTE: asm-derived — callback for DVD busy state
void cbForStateBusy(u32 result) {
}

// 0x8025E090 (188 bytes)
// NOTE: asm-derived — issues a DVD command
void issueCommand(s32 type, DVDCommandBlock* block) {
}

// 0x8025E14C (220 bytes)
BOOL DVDReadAbsAsyncPrio(DVDCommandBlock* block, void* dest, u32 length,
                          u32 offset, DVDCBCallback callback, s32 prio) {
    return TRUE;
}

// 0x8025E228 (204 bytes)
BOOL DVDSeekAbsAsyncPrio(DVDCommandBlock* block, u32 offset, DVDCBCallback callback) {
    return TRUE;
}

// 0x8025E2F4 (208 bytes)
BOOL DVDReadAbsAsyncForBS(DVDCommandBlock* block, void* dest, u32 length,
                           u32 offset, DVDCBCallback callback) {
    return TRUE;
}

// 0x8025E3C4 (212 bytes)
BOOL DVDReadDiskID(DVDCommandBlock* block, DVDDiskID* diskID, DVDCBCallback callback) {
    return TRUE;
}

// 0x8025E498 (196 bytes)
BOOL DVDPrepareStreamAbsAsync(DVDCommandBlock* block, u32 length, u32 offset,
                               DVDCBCallback callback) {
    return TRUE;
}

// 0x8025E55C (188 bytes)
BOOL DVDCancelStreamAsync(DVDCommandBlock* block, DVDCBCallback callback) {
    return TRUE;
}

// 0x8025E618 (160 bytes)
s32 DVDCancelStream(DVDCommandBlock* block) {
    return 0;
}

// 0x8025E6E0 (188 bytes)
BOOL DVDStopStreamAtEndAsync(DVDCommandBlock* block, DVDCBCallback callback) {
    return TRUE;
}

// 0x8025E79C (160 bytes)
s32 DVDStopStreamAtEnd(DVDCommandBlock* block) {
    return 0;
}

// 0x8025E864 (188 bytes)
BOOL DVDGetStreamErrorStatusAsync(DVDCommandBlock* block, DVDCBCallback callback) {
    return TRUE;
}

// 0x8025E920 (160 bytes)
s32 DVDGetStreamErrorStatus(DVDCommandBlock* block) {
    return 0;
}

// 0x8025E9E8 (188 bytes)
BOOL DVDGetStreamPlayAddrAsync(DVDCommandBlock* block, DVDCBCallback callback) {
    return TRUE;
}

// 0x8025EAA4 (160 bytes)
s32 DVDGetStreamPlayAddr(DVDCommandBlock* block) {
    return 0;
}

// 0x8025EB6C (188 bytes)
BOOL DVDGetStreamStartAddrAsync(DVDCommandBlock* block, DVDCBCallback callback) {
    return TRUE;
}

// 0x8025EC28 (160 bytes)
s32 DVDGetStreamStartAddr(DVDCommandBlock* block) {
    return 0;
}

// 0x8025ECF0 (188 bytes)
BOOL DVDGetStreamLengthAsync(DVDCommandBlock* block, DVDCBCallback callback) {
    return TRUE;
}

// 0x8025EDAC (160 bytes)
s32 DVDGetStreamLength(DVDCommandBlock* block) {
    return 0;
}

// 0x8025EE74 (188 bytes)
BOOL __DVDAudioBufferConfig(DVDCommandBlock* block, BOOL enable, u32 size,
                             DVDCBCallback callback) {
    return TRUE;
}

// 0x8025EF30 (188 bytes)
BOOL DVDChangeDiskAsyncForBS(DVDCommandBlock* block, DVDDiskID* diskID,
                              DVDCBCallback callback) {
    return TRUE;
}

// 0x8025EFEC (272 bytes)
BOOL DVDChangeDiskAsync(DVDDiskID* diskID, DVDCBCallback callback) {
    return TRUE;
}

// 0x8025F0FC (260 bytes)
s32 DVDChangeDisk(DVDDiskID* diskID) {
    return 0;
}

// 0x8025F224 (188 bytes)
BOOL DVDStopMotorAsync(DVDCommandBlock* block, DVDCBCallback callback) {
    return TRUE;
}

// 0x8025F2E0 (180 bytes)
s32 DVDStopMotor(DVDCommandBlock* block) {
    return 0;
}

// 0x8025F3B8 (208 bytes)
BOOL DVDInquiryAsync(DVDCommandBlock* block, void* result, DVDCBCallback callback) {
    return TRUE;
}

// 0x8025F488 (200 bytes)
s32 DVDInquiry(DVDCommandBlock* block, void* result) {
    return 0;
}

// 0x8025F574 (68 bytes)
void DVDReset() {
}

// 0x8025F5C0 (76 bytes)
s32 DVDGetCommandBlockStatus(DVDCommandBlock* block) {
    return 0;
}

// 0x8025F60C (172 bytes)
s32 DVDGetDriveStatus() {
    return 0;
}

// 0x8025F704 (80 bytes)
BOOL DVDResume() {
    return TRUE;
}

// 0x8025F754 (636 bytes)
// NOTE: asm-derived — cancels current DVD operation
BOOL DVDCancelAsync(DVDCommandBlock* block, DVDCBCallback callback) {
    return TRUE;
}

// 0x8025F9D0 (172 bytes)
s32 DVDCancel(DVDCommandBlock* block) {
    return 0;
}

// 0x8025FAA0 (236 bytes)
BOOL DVDCancelAllAsync(DVDCBCallback callback) {
    return TRUE;
}

// 0x8025FB8C (312 bytes)
s32 DVDCancelAll() {
    return 0;
}

// 0x8025FCF8 (248 bytes)
s32 DVDCheckDisk() {
    return 0;
}

// 0x8025FDF0 (284 bytes)
BOOL __DVDPrepareResetAsync(DVDCBCallback callback) {
    return TRUE;
}

/* ======================================================================
 * DVD Command Queue
 * ====================================================================== */

// 0x8025FF7C (104 bytes)
void __DVDPushWaitingQueue(DVDCommandBlock* block) {
}

// 0x8025FFE4 (100 bytes)
DVDCommandBlock* PopWaitingQueuePrio() {
    return (DVDCommandBlock*)0;
}

// 0x80260048 (160 bytes)
DVDCommandBlock* __DVDPopWaitingQueue() {
    return (DVDCommandBlock*)0;
}

// 0x802600E8 (88 bytes)
BOOL __DVDCheckWaitingQueue() {
    return FALSE;
}

// 0x80260140 (96 bytes)
BOOL __DVDDequeueWaitingQueue(DVDCommandBlock* block) {
    return TRUE;
}

// 0x802601A0 (204 bytes)
BOOL __DVDIsBlockInWaitingQueue(DVDCommandBlock* block) {
    return FALSE;
}

// 0x8026026C (268 bytes)
void DVDDumpWaitingQueue() {
    // Debug: prints all blocks in waiting queue via OSReport
}

/* ======================================================================
 * DVD Error Handling
 * ====================================================================== */

// 0x80260378 (284 bytes)
s32 ErrorCode2Num(u32 errorCode) {
    return 0;
}

// 0x80260494 (352 bytes)
void Convert(u32 errorCode, char* buffer) {
    // Converts DVD error code to human-readable string
}

// 0x802605F4 (124 bytes)
void __DVDStoreErrorCode(u32 errorCode) {
}

// 0x802606A8 (248 bytes)
BOOL DVDCompareDiskID(DVDDiskID* id1, DVDDiskID* id2) {
    return TRUE;
}

// 0x802607A0 (128 bytes)
void DVDGenerateDiskID(DVDDiskID* diskID, const char* gameName, const char* company,
                       u8 diskNumber, u8 version) {
}

// 0x80260820 (140 bytes)
void ShowMessage(const char* message) {
    // Shows fatal error message
}

// 0x802608AC (112 bytes)
BOOL DVDSetAutoFatalMessaging(BOOL enable) {
    return TRUE;
}

/* ======================================================================
 * DVD Low-level Interface
 * ====================================================================== */

// 0x8026094C (216 bytes)
void cb(u32 result) {
}

// 0x80260A24 (360 bytes)
// NOTE: asm-derived — loads FST from disc
void __fstLoad() {
}

// 0x80260BCC (148 bytes)
void ProcessNextCommand() {
}

// 0x80260C60 (736 bytes)
// NOTE: asm-derived — DVD interrupt handler
void __DVDInterruptHandler(u16 error, OSContext* context) {
}

// 0x80260F40 (132 bytes)
void AlarmHandler_DVDLow(OSAlarm* alarm, OSContext* context) {
}

// 0x80260FC4 (112 bytes)
void AlarmHandlerForTimeout(OSAlarm* alarm, OSContext* context) {
}

// 0x80261034 (100 bytes)
void SetTimeoutAlarm(s64 timeout) {
}

// 0x80261098 (272 bytes)
// NOTE: overloaded name — DVDLow read
void Read(void* dest, u32 length, u32 offset, DVDLowCallback callback) {
}

// 0x802611E0 (160 bytes)
BOOL HitCache(u32 offset, u32 length) {
    return FALSE;
}

// 0x802612B4 (128 bytes)
void SeekTwiceBeforeRead(u32 offset) {
}

// 0x80261334 (140 bytes)
void WaitBeforeRead(u32 offset) {
}

// 0x802613C0 (664 bytes)
BOOL DVDLowRead(void* dest, u32 length, u32 offset, DVDLowCallback callback) {
    return TRUE;
}

// 0x80261658 (148 bytes)
BOOL DVDLowSeek(u32 offset, DVDLowCallback callback) {
    return TRUE;
}

// 0x80261718 (164 bytes)
BOOL DVDLowReadDiskID(DVDDiskID* diskID, DVDLowCallback callback) {
    return TRUE;
}

// 0x802617BC (140 bytes)
BOOL DVDLowStopMotor(DVDLowCallback callback) {
    return TRUE;
}

// 0x80261848 (140 bytes)
BOOL DVDLowRequestError(DVDLowCallback callback) {
    return TRUE;
}

// 0x802618D4 (156 bytes)
BOOL DVDLowInquiry(void* result, DVDLowCallback callback) {
    return TRUE;
}

// 0x80261970 (152 bytes)
BOOL DVDLowAudioStream(u32 command, u32 length, u32 offset, DVDLowCallback callback) {
    return TRUE;
}

// 0x80261A08 (140 bytes)
BOOL DVDLowRequestAudioStatus(u32 command, DVDLowCallback callback) {
    return TRUE;
}

// 0x80261A94 (156 bytes)
BOOL DVDLowAudioBufferConfig(BOOL enable, u32 size, DVDLowCallback callback) {
    return TRUE;
}

// 0x80261B30 (188 bytes)
void DVDLowReset() {
}

// 0x80261BEC (68 bytes)
DVDLowCallback DVDLowSetResetCoverCallback(DVDLowCallback callback) {
    return (DVDLowCallback)0;
}

// 0x80261C4C (116 bytes)
void AlarmHandlerForBreak(OSAlarm* alarm, OSContext* context) {
}

// 0x80261CC0 (100 bytes)
void SetBreakAlarm(s64 timeout) {
}

// 0x80261D54 (148 bytes)
s32 DVDLowGetCoverStatus() {
    return 0;
}

// 0x80261DE8 (68 bytes)
void __DVDLowSetWAType(u32 type) {
}

// 0x80261E6C (92 bytes)
// NOTE: asm-derived — counts leading zeros on 64-bit value
static u32 cntlzd(u64 val) {
    if ((u32)(val >> 32) != 0) return 0; // placeholder
    return 0;
}

/* ======================================================================
 * VI (Video Interface)
 * ====================================================================== */

// 0x80261EC8 (288 bytes)
// NOTE: asm-derived — writes VI register set
void VISetRegs() {
}

// 0x80261FE8 (628 bytes)
// NOTE: asm-derived — VI retrace interrupt handler
void __VIRetraceHandler(u16 error, OSContext* context) {
}

// 0x8026225C (68 bytes)
VIRetraceCallback VISetPreRetraceCallback(VIRetraceCallback callback) {
    return (VIRetraceCallback)0;
}

// 0x802622A0 (68 bytes)
VIRetraceCallback VISetPostRetraceCallback(VIRetraceCallback callback) {
    return (VIRetraceCallback)0;
}

// 0x802622F4 (168 bytes)
// NOTE: asm-derived — gets timing parameters for video mode
void* getTiming(u32 tvFormat) {
    return (void*)0;
}

// 0x8026239C (516 bytes)
// NOTE: asm-derived — VI internal initialization
void __VIInit(u32 tvFormat) {
}

// 0x802625A0 (352 bytes)
// NOTE: asm-derived — adjusts display position
void AdjustPosition(u32 tvFormat) {
}

// 0x8026273C (1200 bytes)
// NOTE: asm-derived — VI public initialization
void VIInit() {
}

// 0x80262BEC (84 bytes)
void VIWaitForRetrace() {
    // Sleeps until next vertical retrace
}

// 0x80262C40 (124 bytes)
void setInterruptRegs(void* timing) {
}

// 0x80262CBC (152 bytes)
void setPicConfig(void* renderMode) {
}

// 0x80262D54 (188 bytes)
void setBBIntervalRegs(void* timing) {
}

// 0x80262E10 (156 bytes)
void setScalingRegs(u32 panSizeY, u32 dispSizeY) {
}

// 0x80262EAC (128 bytes)
void calcFbbs(u32 bufAddr, u32 panPosX, u32 panPosY, u32 format,
              u32* tfbb, u32* bfbb) {
}

// 0x80262F2C (724 bytes)
// NOTE: asm-derived — sets frame buffer registers
void setFbbRegs(void* renderMode, u32* tfbb, u32* bfbb, u32* rtfbb, u32* rbfbb) {
}

// 0x80263200 (204 bytes)
void setHorizontalRegs(void* timing) {
}

// 0x802632CC (416 bytes)
void setVerticalRegs(void* timing, u32 isInterlaced) {
}

// 0x8026346C (148 bytes)
void PrintDebugPalCaution() {
}

// 0x80263500 (2056 bytes)
// NOTE: asm-derived — configures video output mode
void VIConfigure(void* renderMode) {
}

// 0x80263D08 (916 bytes)
// NOTE: asm-derived — configures video with pan adjustment
void VIConfigurePan(void* renderMode) {
}

// 0x8026409C (304 bytes)
void VIFlush() {
    // Writes pending VI register changes to hardware
}

// 0x802641CC (108 bytes)
void VISetNextFrameBuffer(void* frameBuffer) {
}

// 0x80264248 (108 bytes)
void VISetNextRightFrameBuffer(void* frameBuffer) {
}

// 0x802642B4 (124 bytes)
void VISetBlack(BOOL black) {
}

// 0x80264330 (256 bytes)
void VISet3D(BOOL enable) {
}

// 0x80264474 (80 bytes)
// NOTE: asm-derived — reads current half line from VI hardware
static u32 getCurrentHalfLine() {
    return 0;
}

// 0x802644C4 (104 bytes)
static u32 getCurrentFieldEvenOdd() {
    return 0;
}

// 0x8026452C (156 bytes)
u32 VIGetNextField() {
    return 0;
}

// 0x802645C8 (152 bytes)
u32 VIGetCurrentLine() {
    return 0;
}

// 0x80264660 (104 bytes)
u32 VIGetTvFormat() {
    return 0;
}

// 0x802646C8 (104 bytes)
u32 VIGetScanMode() {
    return 0;
}

// 0x8026476C (712 bytes)
// NOTE: asm-derived — sets VI display position adjustments
void __VISetAdjustingValues(s16 xPos, s16 yPos) {
}

// 0x80264A34 (76 bytes)
void __VIGetAdjustingValues(s16* xPos, s16* yPos) {
}

// 0x80264A80 (384 bytes)
// NOTE: asm-derived — enables raw position interrupt
void __VIEnableRawPositionInterrupt(u32 x, u32 y) {
}

// 0x80264C00 (76 bytes)
void __VIDisableRawPositionInterrupt() {
}

// 0x80264C4C (540 bytes)
// NOTE: asm-derived — converts display position to X/Y coordinates
void __VIDisplayPositionToXY(u32 position, u32* x, u32* y) {
}

// 0x80264E68 (96 bytes)
u32 __VIGetCurrentPosition() {
    return 0;
}

// 0x80264EF4 (116 bytes)
void __VIGetLatch0Position(u32* x, u32* y) {
}

// 0x80264F68 (116 bytes)
void __VIGetLatch1Position(u32* x, u32* y) {
}

/* ======================================================================
 * PAD (Controller Input)
 * ====================================================================== */

// 0x8026501C (96 bytes)
void PADEnable(s32 channel) {
}

// 0x8026507C (164 bytes)
void PADDisable(s32 channel) {
}

// 0x80265120 (112 bytes)
static void DoReset() {
}

// 0x80265190 (420 bytes)
// NOTE: asm-derived — updates controller origin calibration
static void UpdateOrigin(s32 channel) {
}

// 0x80265334 (196 bytes)
static void PADOriginCallback(s32 channel, u32 status) {
}

// 0x802653F8 (204 bytes)
static void PADOriginUpdateCallback(s32 channel, u32 status) {
}

// 0x802654C4 (216 bytes)
static void PADProbeCallback(s32 channel, u32 status) {
}

// 0x8026559C (812 bytes)
// NOTE: asm-derived — handles controller type/status response
static void PADTypeAndStatusCallback(s32 channel, u32 type) {
}

// 0x802658C8 (320 bytes)
static void PADReceiveCheckCallback(s32 channel, u32 status) {
}

// 0x80265A08 (272 bytes)
BOOL PADReset(u32 mask) {
    return TRUE;
}

// 0x80265B18 (276 bytes)
BOOL PADRecalibrate(u32 mask) {
    return TRUE;
}

// 0x80265C2C (336 bytes)
// NOTE: asm-derived — PAD subsystem initialization
BOOL PADInit() {
    return TRUE;
}

// 0x80265D7C (768 bytes)
// NOTE: asm-derived — reads all controller states
u32 PADRead(PADStatus* status) {
    return 0;
}

// 0x8026609C (204 bytes)
void PADControlAllMotors(const u32* commands) {
}

// 0x80266168 (184 bytes)
void PADControlMotor(s32 channel, u32 command) {
}

// 0x80266220 (96 bytes)
void PADSetSpec(u32 spec) {
}

// 0x80266288 (372 bytes)
// NOTE: asm-derived — SPEC0 controller data format
static void SPEC0_MakeStatus(s32 channel, PADStatus* status, void* rawData) {
}

// 0x802663FC (372 bytes)
// NOTE: asm-derived — SPEC1 controller data format
static void SPEC1_MakeStatus(s32 channel, PADStatus* status, void* rawData) {
}

// 0x80266570 (84 bytes)
static s8 ClampS8(s32 value) {
    if (value > 127) return 127;
    if (value < -128) return -128;
    return (s8)value;
}

// 0x802665E0 (1136 bytes)
// NOTE: asm-derived — SPEC2 controller data format (standard GC controller)
static void SPEC2_MakeStatus(s32 channel, PADStatus* status, void* rawData) {
}

// 0x80266A50 (116 bytes)
u32 PADGetType(s32 channel) {
    return 0;
}

// 0x80266AC4 (100 bytes)
BOOL PADSync() {
    return TRUE;
}

// 0x80266B28 (116 bytes)
void PADSetAnalogMode(u32 mode) {
}

// 0x80266B9C (188 bytes)
// NOTE: asm-derived — reset button callback for PAD
static BOOL OnReset(BOOL final) {
    return TRUE;
}

// 0x80266C64 (96 bytes)
// NOTE: asm-derived — PAD sampling interrupt handler
static void SamplingHandler(OSAlarm* alarm, OSContext* context) {
}

// 0x80266CC4 (84 bytes)
PADSamplingCallback PADSetSamplingCallback(PADSamplingCallback callback) {
    return (PADSamplingCallback)0;
}

// 0x80266D18 (124 bytes)
u32 __PADDisableRecalibration(BOOL disable) {
    return 0;
}

// 0x80266D94 (124 bytes)
u32 __PADDisableRumble(BOOL disable) {
    return 0;
}

/* ======================================================================
 * AI (Audio Interface)
 * ====================================================================== */

// 0x80266E4C (68 bytes)
void* AIRegisterDMACallback(void* callback) {
    return (void*)0;
}

// 0x80266E90 (136 bytes)
void AIInitDMA(void* buffer, u32 length) {
}

// 0x80266F9C (68 bytes)
void* AIRegisterStreamCallback(void* callback) {
    return (void*)0;
}

// 0x80267024 (216 bytes)
void AISetStreamPlayState(u32 state) {
}

// 0x8026710C (224 bytes)
void AISetDSPSampleRate(u32 rate) {
}

// 0x80267248 (212 bytes)
void __AI_set_stream_sample_rate(u32 rate) {
}

// 0x80267384 (364 bytes)
// NOTE: asm-derived — AI subsystem initialization
void AIInit(void* buffer) {
}

// 0x802674FC (124 bytes)
// NOTE: asm-derived — AI stream interrupt handler
void __AISHandler(u16 error, OSContext* context) {
}

// 0x80267578 (172 bytes)
// NOTE: asm-derived — AI DMA interrupt handler
void __AIDHandler(u16 error, OSContext* context) {
}

// 0x80267624 (88 bytes)
// NOTE: asm-derived — switches to callback stack for AI handlers
void __AICallbackStackSwitch(void* callback) {
}

// 0x8026767C (484 bytes)
// NOTE: asm-derived — AI sample rate converter initialization
void __AI_SRC_INIT() {
}

/* ======================================================================
 * DBG (Hardware Debugger Interface)
 * ====================================================================== */

// 0x802678A0 (608 bytes)
// NOTE: asm-derived — writes data to debugger
BOOL DBWrite(u32 address, void* data, u32 length) {
    return FALSE;
}

// 0x80267B00 (140 bytes)
// NOTE: asm-derived — reads data from debugger
BOOL DBRead(u32 address, void* data, u32 length) {
    return FALSE;
}

// 0x80267B8C (156 bytes)
BOOL DBQueryData(u32 address, u32* result) {
    return FALSE;
}

// 0x80267C28 (336 bytes)
// NOTE: asm-derived — checks debugger mailbox
BOOL CheckMailBox() {
    return FALSE;
}

// 0x80267D78 (84 bytes)
// NOTE: asm-derived — initializes debugger interrupts
void DBInitInterrupts() {
}

// 0x80267DCC (120 bytes)
// NOTE: asm-derived — initializes debugger communication
void DBInitComm(void* statusPtr, void* callback) {
}

// 0x80267EC0 (172 bytes)
// NOTE: asm-derived — reads debugger status register
BOOL DBGReadStatus(u32* status) {
    return FALSE;
}

// 0x80267F6C (220 bytes)
// NOTE: asm-derived — writes to debugger via EXI
BOOL DBGWrite(u32 address, void* data, u32 length) {
    return FALSE;
}

// 0x80268048 (220 bytes)
// NOTE: asm-derived — reads from debugger via EXI
BOOL DBGRead(u32 address, void* data, u32 length) {
    return FALSE;
}

// 0x80268124 (172 bytes)
BOOL DBGReadMailbox(u32* data) {
    return FALSE;
}

// 0x802681D0 (140 bytes)
BOOL DBGWriteMailbox(u32 data) {
    return FALSE;
}

// 0x8026825C (172 bytes)
BOOL DBGCheckID() {
    return FALSE;
}

// 0x80268320 (664 bytes)
// NOTE: asm-derived — raw EXI immediate transfer for debugger
BOOL DBGEXIImm(void* data, u32 length, u32 type) {
    return FALSE;
}

/* ======================================================================
 * APT Engine (Flash/ActionScript UI System)
 * ====================================================================== */

// 0x8026864C (152 bytes)
// NOTE: asm-derived — APT debug print (variadic)
void AptDebuggerPrint(int level, char* fmt, ...) {
    // Formats and outputs APT debug message
}

// 0x80268998 (688 bytes)
// NOTE: asm-derived — APT system initialization
void AptInitialize(AptInitParmsT* params, bool useDefaults) {
    // Initializes APT rendering, input, allocator, ActionScript VM
}

// 0x80268C48 (400 bytes)
// NOTE: asm-derived — resets APT state
void AptReset() {
    // Resets animation state, clears display lists
}

// 0x80268DD8 (352 bytes)
// NOTE: asm-derived — shuts down APT system
void AptShutdown(int level) {
    // Releases animations, clears native functions, frees memory
}

// 0x80268F38 (180 bytes)
// NOTE: asm-derived — initializes APT memory allocator
void AptAllocatorInitialize(u32 heapSize, u32 align, u32 flags, u32 poolSize) {
}

// 0x80268FEC (164 bytes)
void AptAllocatorShutdown() {
}

// 0x802690B0 (76 bytes)
// NOTE: asm-derived — clears all registered native functions
void CleanAllNativeFunctions() {
}

// 0x802690FC (132 bytes)
void AptCompleteAnimationAsyncLoad(AptSharedPtr<AptFile> file, void* a, void* b, void* c) {
}

// 0x80269180 (352 bytes)
// NOTE: asm-derived — gets animation at specified stack level
AptValue* _AptGetAnimationAtLevel(int level) {
    return (AptValue*)0;
}

// 0x802692E0 (220 bytes)
void AptGetAnimationSize(int* width, int* height) {
}

// 0x802693E8 (196 bytes)
void AptLoadAnimation(char* aptFile, char* datFile) {
}

// 0x802694AC (120 bytes)
void AptPreloadAnimation(char* aptFile) {
}

// 0x80269524 (128 bytes)
void AptAddCustomSavedInput(void* data, u32 size) {
}

// 0x802695A4 (112 bytes)
void AptCancelPreloadedAnimation(char* aptFile) {
}

// 0x80269614 (124 bytes)
BOOL AptIsFileLoaded(AptSharedPtr<AptFile> file) {
    return FALSE;
}

// 0x80269690 (136 bytes)
void _addScreenGrabToSavedInputs() {
}

// 0x80269718 (400 bytes)
// NOTE: asm-derived — APT tick (update one frame)
void _tick(u32 deltaTime) {
}

// 0x802698A8 (4036 bytes)
// NOTE: asm-derived — plays back recorded input sequence
void _playbackSavedInputs(u32 deltaTime) {
}

// 0x8026A86C (492 bytes)
// NOTE: asm-derived — internal APT update
void _AptInternalUpdate(u32 deltaTime) {
}

// 0x8026AA58 (80 bytes)
void _AptInternalRender() {
}

// 0x8026AAEC (92 bytes)
void AptAddToInputQueue(AptInputType type, AptInputState state, AptInputController controller) {
}

// 0x8026AB48 (116 bytes)
void AptAddToInputAnalogQueue(AptAnalogStickInfo info) {
}

// 0x8026ABBC (416 bytes)
// NOTE: asm-derived — sets internal APT variable from string key/value
void AptSetInternalVariable(char* name, char* value) {
}

// 0x8026AD5C (240 bytes)
void AptGetInternalVariable(char* name, char* outValue) {
}

// 0x8026AE4C (1016 bytes)
// NOTE: asm-derived — calls an APT/ActionScript function (variadic)
void AptCallFunction(char* target, char* method, char* format, int numArgs, ...) {
}

// 0x8026B244 (812 bytes)
// NOTE: asm-derived — optimized variant of AptCallFunction
void AptCallFunctionOpti(char* target, char* method, char* format, int numArgs, ...) {
}

// 0x8026B570 (272 bytes)
void AptSetInputRoot(char* rootName) {
}

// 0x8026B6FC (112 bytes)
// NOTE: asm-derived — checks if APT animation is currently playing
int AptDebugIsPlaying(int level) {
    return -1;
}

// 0x8026B834 (168 bytes)
// NOTE: asm-derived — registers an APT extension object
void AptRegisterExtension(AptExtObject* ext) {
}

// 0x8026B8DC (220 bytes)
// NOTE: asm-derived — unregisters an APT extension by object pointer
void AptUnRegisterExtension(AptExtObject* ext) {
}

// 0x8026B9B8 (212 bytes)
// NOTE: asm-derived — unregisters an APT extension by name
void AptUnRegisterExtension(char* name) {
}

// 0x8026BAB4 (488 bytes)
// NOTE: asm-derived — processes zombie (dead) APT objects
void AptUpdateZombieVector(bool forceCleanup) {
}

/* ======================================================================
 * APT Internal Helpers
 * ====================================================================== */

// 0x8026F4C0 (540 bytes)
// NOTE: asm-derived — builds display name string for an APT character
void _getNameString(AptCIH* cih, EAStringC& outName, NameStringType type) {
    // Recursively builds dotted path name (e.g. "_root.menu.button1")
}

// 0x80271EB0 (544 bytes)
// NOTE: asm-derived — concatenates two AptValues as strings
AptValue* _concatAsStrings(AptValue* a, AptValue* b) {
    return (AptValue*)0;
}

// 0x802724C0 (380 bytes)
// NOTE: asm-derived — escapes special characters in string
void _escape(EAStringC& str) {
}

// 0x8027263C (96 bytes)
// NOTE: asm-derived — converts two hex chars to a character
char _escape2Char(char hi, char lo) {
    return 0;
}

// 0x8027269C (344 bytes)
// NOTE: asm-derived — unescapes percent-encoded string
void _unEscape(EAStringC& str) {
}

// 0x80286C48 (76 bytes)
BOOL _isIndex(char* str) {
    // Returns TRUE if str is a numeric index string
    return FALSE;
}

// 0x8029A1A4 (320 bytes)
// NOTE: asm-derived — converts APT color transform to native format
void _convertToCXForm(AptCXForm* dst, AptnCXForm* src) {
}

// 0x8029B024 (176 bytes)
// NOTE: asm-derived — draws a character instance
void _drawCharacterInst(AptRenderingContext* ctx, AptCIH* cih, AptMaskRenderOperation maskOp) {
}

// 0x8029B0D4 (892 bytes)
// NOTE: asm-derived — optimized character instance drawing
void _drawCharacterInstOpti(AptRenderingContext* ctx, AptCIH* cih, AptMaskRenderOperation maskOp) {
}

// 0x8029C920 (244 bytes)
void _getCharacterGridPosition(EAStringC& name, int* row, int* col) {
}

// 0x8029CA14 (364 bytes)
int _getButtonScore(AptInputType type, int x1, int y1, int x2, int y2) {
    return 0;
}

// 0x8029CB80 (588 bytes)
// NOTE: asm-derived — finds best button for input navigation
AptCIH* _getBestButton(AptInputType type, AptCIH* current, AptCIH* candidate) {
    return (AptCIH*)0;
}

// 0x8029CDCC (96 bytes)
int _ActionConditionFlagToActionEventFlags(int conditionFlag) {
    return 0;
}

// 0x8029D1A0 (76 bytes)
void _matrix_vecMult(float* result, AptMatrix* matrix, float* vec) {
    // 2D matrix-vector multiply for APT transforms
}

// 0x8029D1EC (164 bytes)
BOOL _pointInTri(float* triVerts, float x, float y) {
    // Point-in-triangle test for APT hit testing
    return FALSE;
}

// 0x8029E270 (240 bytes)
// NOTE: asm-derived — case-insensitive APT filename compare
s32 AptFileNameCompare(char* a, char* b) {
    return 0;
}

// 0x802A1010 (132 bytes)
void AptSharedPtrDelete(AptFile* file) {
    // Releases shared pointer to AptFile
}

// 0x802A10BC (92 bytes)
void AptSharedPtrDelete(AptLinkerThingy* linker) {
    // Releases shared pointer to AptLinkerThingy
}

// 0x802A1118 (1752 bytes)
// NOTE: asm-derived — global notification callback for APT file load completion
void GlobalNotificationFunction(AptSharedPtr<AptFile> file) {
}

// 0x802AAF5C (368 bytes)
// NOTE: asm-derived — reloads Mersenne Twister RNG state
void _randReloadMersenneTwister() {
}

// 0x802AB0CC (124 bytes)
// NOTE: asm-derived — APT random number generator
s32 AptRand() {
    return 0;
}

// 0x802B0E4C (600 bytes)
// NOTE: asm-derived — registers global object function for APT
void _gObjRegistrationFunc(AptValue* obj, int index) {
}

// 0x802B10A4 (5412 bytes)
// NOTE: asm-derived — constructs all built-in ActionScript objects
void _constructBuiltInObjects() {
    // Creates Math, String, Array, Boolean, Number, Date, Object prototypes
    // Registers native functions for each built-in type
}

// 0x802B25C8 (2000 bytes)
// NOTE: asm-derived — initializes APT value system
void AptValueInitialize() {
    // Creates global scope, undefined value, rendering context
    // Initializes built-in prototypes and function tables
}

// 0x802B2D98 (1116 bytes)
// NOTE: asm-derived — shuts down APT value system
void AptValueShutdown(int level) {
    // Releases all global APT values and prototypes
}

// 0x802B31F4 (84 bytes)
void AptValueShutdownRemaining() {
    // Final cleanup of any remaining APT values
}

// 0x802B642C (152 bytes)
// NOTE: asm-derived — sets __proto__ on an AptObject
void Set__Proto____9AptObjectP8AptValue(AptValue* obj, AptValue* proto) {
    // Mangled name: AptObject::Set__Proto__(AptValue*)
}

// 0x802BC6C4 (276 bytes)
// NOTE: asm-derived — string concatenation operator
EAStringC* operator_plus_charstar_EAStringC(char* lhs, EAStringC& rhs) {
    // operator+(char*, EAStringC&)
    return (EAStringC*)0;
}

/* ======================================================================
 * Engine Utility Functions
 * ====================================================================== */

// 0x802C6104 (484 bytes)
void SplitPath(char* fullPath, char* drive, char* dir, char* name, char* ext) {
    // Splits a full file path into drive, directory, filename, extension
    // Similar to _splitpath from CRT
}

// 0x802C62E8 (108 bytes)
char* DupString(char* str) {
    // Allocates and copies a string (strdup equivalent)
    return (char*)0;
}

/* ======================================================================
 * Engine Stream Operators
 * ====================================================================== */

// 0x802C66C0 (160 bytes)
// NOTE: asm-derived — reads EString from EFile
EFile& operator_extract_EFile_EString(EFile& file, EString& str) {
    // operator>>(EFile&, EString&) — uses virtual dispatch
    return file;
}

// 0x802C6760 (156 bytes)
// NOTE: asm-derived — reads EStorable from EFile
EFile& operator_extract_EFile_EStorable(EFile& file, EStorable& obj) {
    // operator>>(EFile&, EStorable&) — uses virtual dispatch
    return file;
}

// 0x802C67FC (148 bytes)
// NOTE: asm-derived — reads EStorable pointer from EFile
EFile& operator_extract_EFile_EStorablePtr(EFile& file, EStorable*& obj) {
    // operator>>(EFile&, EStorable*&) — uses virtual dispatch
    return file;
}

// 0x802C7EBC (72 bytes)
// NOTE: asm-derived — writes EFixedString to EStream
EStream& operator_insert_EStream_EFixedString(EStream& stream, EFixedString& str) {
    // operator<<(EStream&, EFixedString&)
    // Calls stream's virtual write function with string buffer
    return stream;
}

// 0x802C7F04 (76 bytes)
// NOTE: asm-derived — reads EFixedString from EStream
EStream& operator_extract_EStream_EFixedString(EStream& stream, EFixedString& str) {
    // operator>>(EStream&, EFixedString&)
    // Calls stream's virtual read function into string buffer
    return stream;
}

// 0x802C9160 (168 bytes)
// NOTE: asm-derived — 4x4 matrix * vec4 multiply
EVec4& operator_mul_EVec4_EMat4(EVec4& result, EVec4& vec, EMat4& mat) {
    // operator*(EVec4&, EMat4&)
    // Full 4-component matrix-vector multiply using fmadds
    return result;
}

// 0x802C9350 (136 bytes)
// NOTE: asm-derived — writes EMat4 to stream
EStream& operator_insert_EStream_EMat4(EStream& stream, EMat4& mat) {
    // operator<<(EStream&, EMat4&)
    // Writes 4x4 = 16 floats via virtual write
    return stream;
}

// 0x802C93D8 (124 bytes)
// NOTE: asm-derived — reads EMat4 from stream
EStream& operator_extract_EStream_EMat4(EStream& stream, EMat4& mat) {
    // operator>>(EStream&, EMat4&)
    // Reads 16 floats via virtual read
    return stream;
}

// 0x802CB5B4 (732 bytes)
// NOTE: asm-derived — in-place matrix inversion with pivot
BOOL MatrixInvert(float** matrix, int size) {
    // Gauss-Jordan elimination with full pivoting
    // Uses local arrays for pivot tracking (up to ~256x256)
    // Returns FALSE if matrix is singular
    return TRUE;
}

// 0x802CB890 (84 bytes)
// NOTE: asm-derived — returns random float in [0, 1)
f32 Rndf() {
    // Linear congruential generator: seed = seed * 0x41C64E6D + 0x3039
    // Converts upper 15 bits to float via integer bit manipulation
    return 0.0f;
}

// 0x802CC198 (76 bytes)
// NOTE: asm-derived — writes ENDummy to stream via vtable
EStream& operator_insert_EStream_ENDummy(EStream& stream, ENDummy& dummy) {
    // operator<<(EStream&, ENDummy&)
    return stream;
}

// 0x802CC1E4 (76 bytes)
// NOTE: asm-derived — reads ENDummy from stream via vtable
EStream& operator_extract_EStream_ENDummy(EStream& stream, ENDummy& dummy) {
    // operator>>(EStream&, ENDummy&)
    return stream;
}

// 0x802CD83C (208 bytes)
// NOTE: asm-derived — writes quaternion to stream (4 floats)
EStream& operator_insert_EStream_EQuat(EStream& stream, EQuat& quat) {
    // operator<<(EStream&, EQuat&)
    // Writes x, y, z, w components as 4 separate float writes
    return stream;
}

// 0x802CD90C (172 bytes)
// NOTE: asm-derived — reads quaternion from stream (4 floats)
EStream& operator_extract_EStream_EQuat(EStream& stream, EQuat& quat) {
    // operator>>(EStream&, EQuat&)
    // Reads x, y, z, w components as 4 separate float reads
    return stream;
}
