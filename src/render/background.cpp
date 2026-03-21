// background.cpp - Background/BackgroundImpl classes (background thread system)
// Part of the Sims 2 GC decompilation
// Original: engine_ngc_release_dvd.lib(background.obj)
//
// Medium functions (65-256 bytes) decompiled from the background object file.

#include "types.h"

// Forward declarations
extern void* operator_new(u32 size);
extern void operator_delete(void* ptr);

// External thread/queue/semaphore functions
extern void EThread_Init(void* thread);
extern void EThread_Start(void* thread, int priority, u32 stackSize, int unused);
extern void EThread_Resume(void* thread);
extern void EThread_Destroy(void* thread, int mode);
extern void EThread_TestStop(void* thread);
extern void EMsgQueue_Init(void* queue);
extern void EMsgQueue_Destroy(void* queue, int mode);
extern void EMsgQueue_Push(void* queue, void* msg, int flag);
extern int EMsgQueue_Pop(void* queue, void* out, int flag);
extern void ESemaphore_Init(void* sem);
extern void ESemaphore_Destroy(void* sem);
extern void ESemaphore_Wait(void* sem);
extern void ESemaphore_Post(void* sem);
extern void ESemaphore_Create(void* sem, int initial, int max);

// Background message types
enum BackgroundMsgType {
    BG_MSG_FLUSH = 1,       // Signal semaphore and continue
    BG_MSG_TERMINATE = 2,   // Exit thread loop
    BG_MSG_EXECUTE = 3,     // Execute function pointer
    BG_MSG_EXECUTE_ARG = 4  // Execute function pointer with argument
};

// Background message struct (16 bytes, allocated with new)
struct BackgroundMsg {
    u32 m_type;       // 0x00 - message type
    void* m_func;     // 0x04 - function pointer
    u32 m_pad08;      // 0x08
    void* m_arg;      // 0x0C - argument for type 4
};

// Background base class (20 bytes, vtable at offset 0x00)
// vtable at 0x8046A5D0

// BackgroundImpl class layout:
// 0x000: void* m_vtable (Background vtable = 0x8046A578)
// 0x004: padding
// 0x008: EThread (embedded, size ~0x334)
// 0x340: void* m_implVtable (BackgroundImpl vtable = 0x8046A558)
// 0x344: padding
// 0x348: u32 m_initialized
// 0x34C: EMsgQueue (embedded)
// 0x368: ESemaphore (embedded)

//=============================================================================
// BackgroundImpl::BackgroundImpl(void)
// Address: 0x802E1C44, Size: 108
// NON_MATCHING: vtable addresses, bl targets
//=============================================================================
// Calls Background base ctor (sets vtable 0x8046A5D0 -> 0x8046A578)
// Calls EThread_Init(this+0x08)
// Sets BackgroundImpl vtable at 0x340 = 0x8046A558
// Sets Background vtable at 0x00 = 0x8046A578
// Calls EMsgQueue_Init(this+0x34C)
// Calls ESemaphore_Init(this+0x368)
// Sets m_initialized(0x348) = 0
// Stores this to static instance (r13 - 22756)

//=============================================================================
// BackgroundImpl::~BackgroundImpl(void)
// Address: 0x802E1CB0, Size: 116
// NON_MATCHING: vtable addresses, bl targets
//=============================================================================
// Sets vtable pair (0x8046A558 and 0x8046A578)
// Calls ESemaphore_Destroy(this+0x368, 2)
// Calls EMsgQueue_Destroy(this+0x34C, 2)
// Calls EThread_Destroy(this+0x08, 0)
// Calls base ~Background destructor

//=============================================================================
// BackgroundImpl::Shutdown(void)
// Address: 0x802E1D24, Size: 116
// NON_MATCHING: vtable dispatch, bl targets
//=============================================================================
// Dispatches through vtable at 0x00 offset 0x3C to stop thread
// Then dispatches through vtable at 0x00 offset 0x20 to cleanup
// Calls EThread_TestStop(this+0x08)
// Calls ESemaphore_Destroy(this+0x368)
// Sets m_initialized(0x348) = 0
// Clears static instance pointer

//=============================================================================
// BackgroundImpl::TerminateThread(void)
// Address: 0x802E1D98, Size: 76
// NON_MATCHING: bl targets
//=============================================================================
// Allocates 16 bytes (BackgroundMsg)
// Sets msg->type = 2 (BG_MSG_TERMINATE)
// Sets msg->arg = 0
// Sends message via SendCommand(this)

//=============================================================================
// BackgroundImpl::Init(void)
// Address: 0x802E1DE4, Size: 108
// NON_MATCHING: bl targets, constants
//=============================================================================
// Initializes semaphore at this+0x368 with initial count 32
// Sets thread entry to Main function ptr at this+0x008+0x32C
// Starts thread with priority 25, stack 0x8000
// Resumes thread
// Sets m_initialized = 1

//=============================================================================
// BackgroundImpl::ExecuteRoutine(void (*)(void))
// Address: 0x802E1E54, Size: 84
// NON_MATCHING: bl targets
//=============================================================================
// Allocates 16 bytes (BackgroundMsg)
// Sets msg->type = 3 (BG_MSG_EXECUTE)
// Sets msg->func = fn parameter
// Sets msg->arg = 0
// Sends via SendCommand

//=============================================================================
// BackgroundImpl::ExecuteArgRoutine(void (*)(void*), void*)
// Address: 0x802E1EA8, Size: 88
// NON_MATCHING: bl targets
//=============================================================================
// Allocates 16 bytes (BackgroundMsg)
// Sets msg->type = 4 (BG_MSG_EXECUTE_ARG)
// Sets msg->func = fn parameter
// Sets msg->arg = arg parameter
// Sends via SendCommand

//=============================================================================
// BackgroundImpl::Flush(void)
// Address: 0x802E1F28, Size: 172
// NON_MATCHING: vtable dispatch, semaphore/queue ops
//=============================================================================
// Checks if calling from background thread via vtable dispatch
// If result is not null (calling from bg thread), returns immediately
// Otherwise:
//   Creates stack semaphore (ESemaphore on stack)
//   Inits semaphore with (0, 1)
//   Allocates msg with type = BG_MSG_FLUSH
//   Stores semaphore ptr in msg
//   Sends via SendCommand
//   Waits on semaphore (blocking)
//   Posts semaphore
//   Destroys semaphore

//=============================================================================
// BackgroundImpl::Main(void)
// Address: 0x802E1FD4, Size: 220
// NON_MATCHING: message dispatch switch, bl targets
//=============================================================================
// Main thread loop:
// while (true):
//   Pop message from queue (this+0x368), blocking
//   Read msg->type
//   switch (type):
//     case BG_MSG_TERMINATE (2):
//       Free message, exit loop (return)
//     case BG_MSG_FLUSH (1):
//       Get semaphore from msg->func
//       Post it (unblock Flush caller)
//       goto next_msg (loop restarting from pop):
//         call EThread_TestStop and goto pop
//     case BG_MSG_EXECUTE (3):
//       Get fn from msg->func
//       if (fn != 0) call fn()
//       Free message
//     case BG_MSG_EXECUTE_ARG (4):
//       Get fn from msg->func
//       Get arg from msg->arg
//       if (fn != 0) call fn(arg)
//       Free message
//   Resume thread, goto pop

//=============================================================================
// __static_initialization_and_destruction_0 (background.obj)
// Address: 0x802E20B0, Size: 84
// NON_MATCHING: SDA pattern, bl targets
//=============================================================================
// If constructing (arg1 == 1, arg2 == 0xFFFF):
//   If static instance is null:
//     Allocates BackgroundImpl, constructs it
//   Else:
//     Calls destructor on static instance with mode 2
