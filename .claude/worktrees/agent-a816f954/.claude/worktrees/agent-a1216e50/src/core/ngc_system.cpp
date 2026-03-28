// ngc_system.cpp - NGC threading, semaphore, sleep, filesystem, file I/O,
//                   mutex, sync objects implementation
// From: base_ngc_release_dvd.lib(e_ngcthread.obj, e_ngcsemaphore.obj,
//       e_ngcsleep.obj, e_ngcfilesystem.obj, e_ngcsnfile.obj, e_ngcfile.obj,
//       e_mutex.obj, e_syncobject.obj, e_thread.obj)
// Small functions (<=64 bytes) decompiled from these objects

#include "core/ngc_system.h"

// DolphinSDK OS functions
extern "C" {
    void OSResumeThread(int threadId);
    void OSCancelThread(int threadId);
    int OSSetThreadPriority(int threadId, int priority);
    int OSGetThreadPriority(int threadId);
    int OSGetCurrentThread(void);
    int OSSemWait(int* sem);
    int OSSemPost(int* sem);
    void OSDisableInterrupts(void);
    void OSEnableInterrupts(void);
}

// External functions
extern "C" void __builtin_delete(void* ptr);

// For EFileSystem base constructor
extern void EFileSystem_Construct(EFileSystem* fs);

// For efclose/efread/efwrite - calls through vtable of file object
extern void EFileSystem_Close(void* fs, void** file);

// SN file write
extern "C" int SNWrite(int handle, void* buffer, unsigned int size);

// Thread list globals (SDA-relative)
EThread* _threadList = 0;       // head
EThread* _threadListTail = 0;   // tail

// ============================================================================
// ESyncObject - e_syncobject.obj
// ============================================================================

// ESyncObject::ESyncObject - 0x802d5850 (20 bytes)
// Sets vtable pointer
// NON_MATCHING - vtable address is linker-resolved
ESyncObject::ESyncObject(void) {
    // vtable set by compiler
}

// ESyncObject::~ESyncObject - 0x802d5864 (52 bytes)
// Sets vtable, conditionally calls operator delete
// NON_MATCHING - vtable store and conditional delete
ESyncObject::~ESyncObject(void) {
    // vtable reset and conditional delete handled by compiler
}

// ESyncObject::Release(unsigned int, unsigned int*) - 0x802d5898 (52 bytes)
// Virtual dispatch: loads vtable, adjusts this, calls through vtable[3]
// This dispatches to the derived class's Release implementation
// NON_MATCHING - vtable dispatch pattern
void ESyncObject::Release(unsigned int count, unsigned int* prevCount) {
    // Virtual dispatch through vtable at offset 0x18/0x1C
    // In the original: loads vtable ptr, gets offset and function ptr,
    // adjusts this pointer, and calls through the function pointer
}

// ============================================================================
// ESemaphore - e_ngcsemaphore.obj
// ============================================================================

// ESemaphore::Destroy - 0x802d78c8 (12 bytes)
// Sets m_created to 0
// li r0,0; stw r0,4(r3)
void ESemaphore::Destroy(void) {
    m_created = 0;
}

// ESemaphore::GetObject - 0x802d7854 (8 bytes)
// Always returns 0 (NGC doesn't have native semaphore handles)
// li r3,0
int ESemaphore::GetObject(int idx) {
    return 0;
}

// ESemaphore::IsCreated - 0x802d785c (24 bytes)
// Returns 1 if m_created != 0, else 0
int ESemaphore::IsCreated(void) {
    if (m_created != 0) {
        return 1;
    }
    return 0;
}

// ESemaphore::iAcquire - 0x802d798c (56 bytes)
// Virtual dispatch: loads vtable from offset 0x00, gets function at vtable[2],
// adjusts this by vtable offset, calls through function pointer with timeout=0
// NON_MATCHING - vtable dispatch pattern
int ESemaphore::iAcquire(void) {
    return Acquire(0);
}

// ESemaphore::iRelease - 0x802d79c4 (52 bytes)
// Checks if currentCount < maxCount, if so calls OSSemPost
// NON_MATCHING - conditional branch to OSSemPost
int ESemaphore::iRelease(void) {
    if (m_currentCount < m_maxCount) {
        OSSemPost(&m_currentCount);
    }
    return 0;
}

// ESemaphore::GetCurrentCount - 0x802d79f8 (8 bytes)
// Returns m_currentCount at offset 0x0C
// lwz r3,0x0C(r3)
int ESemaphore::GetCurrentCount(void) {
    return m_currentCount;
}

// ESemaphore::GetMaxCount - 0x802d7a00 (8 bytes)
// Returns m_maxCount at offset 0x08
// lwz r3,0x08(r3)
int ESemaphore::GetMaxCount(void) {
    return m_maxCount;
}

// ============================================================================
// EMutex - e_mutex.obj
// ============================================================================

// EMutex::Acquire(char*, int, unsigned int) - 0x802cb9bc (56 bytes)
// Debug version: dispatches through vtable with timeout parameter
// Loads vtable[0], gets offset+func, adjusts this, calls with r6 (timeout) as r4
// NON_MATCHING - vtable dispatch pattern
int EMutex::Acquire(char* file, int line, unsigned int timeout) {
    return iAcquire();
}

// EMutex::Acquire(unsigned int) - 0x802cb9f4 (36 bytes)
// Simple version: calls ESemaphore::Acquire on embedded semaphore at this+4
// addi r3,r3,4; bl ESemaphore::Acquire
int EMutex::Acquire(unsigned int timeout) {
    return m_semaphore.Acquire(timeout);
}

// EMutex::Release(void) - 0x802cba18 (36 bytes)
// Calls ESemaphore::Release on embedded semaphore at this+4
// addi r3,r3,4; bl ESemaphore::Release
void EMutex::Release(void) {
    m_semaphore.Release();
}

// EMutex::Release(char*, int) - 0x802cba3c (52 bytes)
// Debug version: dispatches through vtable[3]
// Loads vtable, gets offset/func at vtable+0x18/0x1C, adjusts this, calls
// NON_MATCHING - vtable dispatch pattern
int EMutex::Release(char* file, int line) {
    Release();
    return 0;
}

// EMutex::iAcquire - 0x802cbbd4 (36 bytes)
// Calls ESemaphore::iAcquire on embedded semaphore at this+4
// addi r3,r3,4; bl ESemaphore::iAcquire
int EMutex::iAcquire(void) {
    return m_semaphore.iAcquire();
}

// EMutex::iRelease - 0x802cbbf8 (36 bytes)
// Calls ESemaphore::iRelease on embedded semaphore at this+4
// addi r3,r3,4; bl ESemaphore::iRelease
int EMutex::iRelease(void) {
    return m_semaphore.iRelease();
}

// ============================================================================
// EThread - e_ngcthread.obj and e_thread.obj
// ============================================================================

// EThread::Main - 0x802d868c (4 bytes)
// Empty virtual method stub (just blr)
void EThread::Main(void) {
}

// EThread::SetThreadName - 0x802d867c (8 bytes)
// Stores name pointer at offset 0x32C
// stw r4,0x32C(r3)
void EThread::SetThreadName(char* name) {
    m_threadName = name;
}

// EThread::GetThreadName - 0x802d8684 (8 bytes)
// Returns name pointer from offset 0x32C
// lwz r3,0x32C(r3)
char* EThread::GetThreadName(void) {
    return m_threadName;
}

// EThread::GetStack - 0x802d858c (8 bytes)
// Returns stack pointer from offset 0x31C
// lwz r3,0x31C(r3)
void* EThread::GetStack(void) {
    return m_stack;
}

// EThread::GetStackSize - 0x802d8594 (8 bytes)
// Returns stack size from offset 0x320
// lwz r3,0x320(r3)
int EThread::GetStackSize(void) {
    return m_stackSize;
}

// EThread::ThreadEntryPoint - 0x802d82d8 (56 bytes)
// Static callback: loads vtable callback info from this+0x338,
// adjusts this pointer by vtable offset, calls through function pointer
// Then returns 0
// NON_MATCHING - vtable dispatch through callback table at 0x338
void* EThread::ThreadEntryPoint(void* param) {
    EThread* thread = (EThread*)param;
    // Load callback vtable from offset 0x338
    void** vtable = (void**)thread->m_callbackTable;
    short offset = *(short*)((char*)vtable + 0x10);
    void (*func)(void*) = (void (*)(void*))vtable[5]; // offset 0x14
    func((void*)((char*)thread + offset));
    return 0;
}

// EThread::Start - 0x802d8464 (36 bytes)
// Calls OSResumeThread with the thread ID from offset 0x318
// lwz r3,0x318(r3); bl OSResumeThread
void EThread::Start(void) {
    OSResumeThread(m_threadId);
}

// EThread::Stop - 0x802d8488 (44 bytes)
// Calls OSCancelThread if thread ID is non-zero
// lwz r3,0x318(r3); cmpwi r3,0; beq skip; bl OSCancelThread
void EThread::Stop(void) {
    if (m_threadId != 0) {
        OSCancelThread(m_threadId);
    }
}

// EThread::SetPriority - 0x802d84b4 (36 bytes)
// Calls OSSetThreadPriority with thread ID
// lwz r3,0x318(r3); bl OSSetThreadPriority
void EThread::SetPriority(int priority) {
    OSSetThreadPriority(m_threadId, priority);
}

// EThread::GetPriority - 0x802d84d8 (36 bytes)
// Calls OSGetThreadPriority with thread ID
// lwz r3,0x318(r3); bl OSGetThreadPriority
int EThread::GetPriority(void) {
    return OSGetThreadPriority(m_threadId);
}

// EThread::GetCurrentThreadId - 0x802d8690 (32 bytes)
// Static: calls OSGetCurrentThread
int EThread::GetCurrentThreadId(void) {
    return OSGetCurrentThread();
}

// EThread::IsCallingThread - 0x802d84fc (60 bytes)
// Compares this thread's ID with the current thread ID
// Returns 1 if same, 0 if different
int EThread::IsCallingThread(void) {
    int currentId = GetCurrentThreadId();
    return (m_threadId == currentId) ? 1 : 0;
}

// EThread::GetThreadObject - 0x802d8538 (48 bytes)
// Static: walks the thread list looking for one with matching thread ID
// Returns the EThread* or NULL
// NON_MATCHING - SDA-relative access to _threadList
EThread* EThread::GetThreadObject(int threadId) {
    EThread* thread = _threadList;
    EThread* result = 0;
    while (thread != 0) {
        if (thread->m_threadId == threadId) {
            result = thread;
            break;
        }
        thread = thread->m_nextThread;
    }
    return result;
}

// EThread::GetCallingThreadObject - 0x802d8568 (36 bytes)
// Gets current thread ID, then finds the thread object for it
EThread* EThread::GetCallingThreadObject(void) {
    int id = GetCurrentThreadId();
    return GetThreadObject(id);
}

// EThread::IsStackPtr - 0x802d859c (48 bytes)
// Checks if a pointer is within any thread's stack
// Calls GetThreadFromStackPtr, returns 1 if found, 0 if not
int EThread::IsStackPtr(void* ptr) {
    EThread* thread = GetThreadFromStackPtr(ptr);
    if (thread != 0) {
        return 1;
    }
    return 0;
}

// EThread::AttachToCallingThread - 0x802e1714 (56 bytes)
// From e_thread.obj: gets current thread ID and calls Attach
void EThread::AttachToCallingThread(void) {
    int id = GetCurrentThreadId();
    Attach(id);
}

// EThread::ValidateStack - 0x802e17f0 (4 bytes)
// Empty stub (just blr) - release build
void EThread::ValidateStack(void) {
}

// EThread::ValidateAllStacks - 0x802e17f4 (4 bytes)
// Empty stub (just blr) - release build
void EThread::ValidateAllStacks(void) {
}

// EThread::GetStackUsage - 0x802e17f8 (8 bytes)
// Returns 0 - stub in release build
// li r3,0
int EThread::GetStackUsage(void) {
    return 0;
}

// EThread::PrintAllThreads - 0x802e1800 (4 bytes)
// Empty stub (just blr) - release build
void EThread::PrintAllThreads(void) {
}

// __static_initialization_and_destruction_0 - 0x802e1804 (44 bytes)
// Compiler-generated static init: checks __initialize_p and __priority
// If __priority == 0xFFFF and __initialize_p == 1, zeros the thread list globals
// NON_MATCHING - compiler-generated static initialization
static void __static_initialization_and_destruction_0(int __initialize_p, int __priority) {
    if (__priority == 0x0000FFFF && __initialize_p != 0) {
        _threadList = 0;
        _threadListTail = 0;
    }
}

// global constructors keyed to EThread::AttachToCallingThread - 0x802e1830 (44 bytes)
// Compiler-generated: calls __static_initialization_and_destruction_0(1, 0xFFFF)
// NON_MATCHING - compiler-generated global constructor
// This is automatically generated by the compiler and registered via .ctors

// ============================================================================
// ESleep - e_ngcsleep.obj
// ============================================================================

// ESleep::_tCallback - 0x802d7b20 (36 bytes)
// OSAlarm callback: loads ESemaphore pointer from alarm+4, calls iRelease
// lwz r3,4(r3); bl ESemaphore::iRelease
void ESleep::_tCallback(OSAlarm* alarm, OSContext* context) {
    // alarm->userData (at offset 4) points to the ESemaphore to release
    ESemaphore* sem = *(ESemaphore**)((char*)alarm + 4);
    sem->iRelease();
}

// ============================================================================
// ENgcFileSystem - e_ngcfilesystem.obj
// ============================================================================

// ENgcFileSystem::ENgcFileSystem - 0x802d73c0 (60 bytes)
// Calls EFileSystem base constructor, then sets its own vtable
// NON_MATCHING - vtable address and base class constructor call
ENgcFileSystem::ENgcFileSystem(void) {
    // Base class EFileSystem constructor called first by compiler
    // Then vtable pointer is overwritten with ENgcFileSystem's vtable
}

// efclose - 0x802d7534 (52 bytes)
// Stores file handle on stack, calls EFileSystem::Close with address of stack var
// NON_MATCHING - stack layout for passing file handle by reference
int efclose(void* file) {
    // Original: stores file ptr on stack at sp+8, loads fs global address,
    // calls EFileSystem_Close(fs, &stackVar)
    // Returns 0 always
    return 0;
}

// efread - 0x802d7568 (60 bytes)
// Virtual dispatch: loads vtable from file+0x28, multiplies size*count,
// dispatches through Read virtual
// NON_MATCHING - vtable dispatch through file object
unsigned int efread(void* buffer, unsigned int size, unsigned int count, EFile* file) {
    unsigned int totalSize = size * count;
    // Virtual dispatch through file->vtable->Read(file+offset, buffer, totalSize)
    return 0;
}

// efwrite - 0x802d75a4 (60 bytes)
// Virtual dispatch: similar pattern to efread but through Write virtual
// Offset: vtable[2] at 0x20/0x24 instead of 0x18/0x1C
// NON_MATCHING - vtable dispatch through file object
unsigned int efwrite(const void* buffer, unsigned int size, unsigned int count, EFile* file) {
    unsigned int totalSize = size * count;
    // Virtual dispatch through file->vtable->Write(file+offset, buffer, totalSize)
    return 0;
}

// eftell - 0x802d7648 (52 bytes)
// Virtual dispatch through vtable at file+0x28, entries at 0x30/0x34
// NON_MATCHING - vtable dispatch
int eftell(EFile* file) {
    // Virtual dispatch through file->vtable->Tell(file+offset)
    return 0;
}

// efflush - 0x802d767c (52 bytes)
// Virtual dispatch through vtable at file+0x28, entries at 0x38/0x3C
// NON_MATCHING - vtable dispatch
int efflush(EFile* file) {
    // Virtual dispatch through file->vtable->Flush(file+offset)
    return 0;
}

// ============================================================================
// ENgcSNFile - e_ngcsnfile.obj
// ============================================================================

// ENgcSNFile::Write - 0x802d8018 (36 bytes)
// Loads SN file handle from this+0x2C, calls SNWrite
// lwz r3,0x2C(r3); bl SNWrite
// NON_MATCHING - SNWrite call linkage
int ENgcSNFile::Write(void* buffer, unsigned int size) {
    return SNWrite(*(int*)((char*)this + 0x2C), buffer, size);
}

// ENgcSNFile::Tell - 0x802d8080 (8 bytes)
// Returns position from offset 0x30
// lwz r3,0x30(r3)
int ENgcSNFile::Tell(void) const {
    return *(int*)((char*)this + 0x30);
}

// ENgcSNFile::Flush - 0x802d8088 (8 bytes)
// Always returns 1 (success)
// li r3,1
int ENgcSNFile::Flush(void) {
    return 1;
}

// ENgcSNFile::GetLastError - 0x802d8090 (8 bytes)
// Always returns 0 (no error)
// li r3,0
int ENgcSNFile::GetLastError(void) const {
    return 0;
}

// ENgcSNFile::GetSystemHandle - 0x802d8098 (8 bytes)
// Returns handle from offset 0x2C
// lwz r3,0x2C(r3)
int ENgcSNFile::GetSystemHandle(void) const {
    return *(int*)((char*)this + 0x2C);
}

// ============================================================================
// ENgcFile - e_ngcfile.obj
// ============================================================================

// ENgcFile::Write - 0x802e1b78 (8 bytes)
// Always returns 0 (not supported on DVD)
// li r3,0
int ENgcFile::Write(void* buffer, unsigned int size) {
    return 0;
}

// ENgcFile::Tell - 0x802e1bdc (8 bytes)
// Returns position from offset 0x68
// lwz r3,0x68(r3)
int ENgcFile::Tell(void) const {
    return *(int*)((char*)this + 0x68);
}

// ENgcFile::Flush - 0x802e1be4 (8 bytes)
// Always returns 1 (success)
// li r3,1
int ENgcFile::Flush(void) {
    return 1;
}

// ENgcFile::GetLastError - 0x802e1bec (8 bytes)
// Always returns 0 (no error)
// li r3,0
int ENgcFile::GetLastError(void) const {
    return 0;
}

// ENgcFile::GetSystemHandle - 0x802e1bf4 (8 bytes)
// Returns pointer to DVDFileInfo at this+0x2C
// addi r3,r3,0x2C
void* ENgcFile::GetSystemHandle(void) const {
    return (void*)((char*)this + 0x2C);
}
