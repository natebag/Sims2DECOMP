// ngc_system.h - NGC threading, semaphore, sleep, filesystem, file I/O, mutex, sync declarations
// From: base_ngc_release_dvd.lib(e_ngcthread.obj, e_ngcsemaphore.obj, e_ngcsleep.obj,
//       e_ngcfilesystem.obj, e_ngcsnfile.obj, e_ngcfile.obj, e_mutex.obj,
//       e_syncobject.obj, e_thread.obj)

#ifndef NGC_SYSTEM_H
#define NGC_SYSTEM_H

// Forward declarations for DolphinSDK types
typedef void OSAlarm;
typedef void OSContext;
typedef int OSThread;

// ============================================================================
// ESyncObject - base synchronization object
// From: e_syncobject.obj
// ============================================================================
class ESyncObject {
public:
    // vtable at offset 0x00
    // vtable layout (from disassembly):
    //   [0]: destructor thunk
    //   [1]: Acquire(unsigned int)
    //   [2]: iAcquire
    //   [3]: Release (2 overloads via thunks)

    ESyncObject(void);
    virtual ~ESyncObject(void);

    // Virtual methods via vtable dispatching
    virtual int Acquire(unsigned int timeout) = 0;
    virtual int iAcquire(void) = 0;
    virtual void Release(void) = 0;
    virtual void Release(unsigned int count, unsigned int* prevCount) = 0;
};

// ============================================================================
// ESemaphore - semaphore synchronization
// From: e_ngcsemaphore.obj
// Layout (from disassembly):
//   0x00: vtable pointer
//   0x04: m_created (int / flag)
//   0x08: m_maxCount (int)
//   0x0C: m_currentCount (int)
// ============================================================================
class ESemaphore {
public:
    // vtable at 0x00 (not ESyncObject-derived based on layout)
    int m_created;          // 0x04 - non-zero if created
    int m_maxCount;         // 0x08
    int m_currentCount;     // 0x0C

    ESemaphore(void);
    ESemaphore(int initialCount, int maxCount);
    ~ESemaphore(void);

    void Create(int initialCount, int maxCount);
    void Destroy(void);
    int GetObject(int idx);
    int IsCreated(void);
    int Acquire(unsigned int timeout);
    int Release(void);
    int iAcquire(void);
    int iRelease(void);
    int GetCurrentCount(void);
    int GetMaxCount(void);

    // operator overloads exist but are >64 bytes
};

// ============================================================================
// EMutex - mutex synchronization
// From: e_mutex.obj
// Layout (from disassembly):
//   0x00: vtable pointer (ESyncObject vtable)
//   0x04: ESemaphore m_semaphore
// ============================================================================
class EMutex : public ESyncObject {
public:
    ESemaphore m_semaphore; // 0x04 (embedded semaphore)

    EMutex(void);
    virtual ~EMutex(void);

    // Debug versions with file/line
    int Acquire(char* file, int line, unsigned int timeout);
    int Release(char* file, int line);

    // Simple versions
    int Acquire(unsigned int timeout);
    void Release(void);

    // Internal virtuals
    int iAcquire(void);
    int iRelease(void);
};

// ============================================================================
// EThreadMutex - thread-aware mutex
// From: e_mutex.obj (separate vtable)
// ============================================================================
class EThreadMutex : public EMutex {
public:
    EThreadMutex(void);
    virtual ~EThreadMutex(void);

    int Acquire(unsigned int timeout);
    void Release(void);
};

// ============================================================================
// EThread - thread management
// From: e_ngcthread.obj, e_thread.obj
// Layout (from constructor at 0x802d80a0 and Attach at 0x802d8310):
//   0x000-0x317: base data (zeroed in ctor, 792 bytes)
//   0x318: m_threadId (int) - OS thread handle
//   0x31C: m_stack (void*)
//   0x320: m_stackSize (int)
//   0x324: m_stackAllocated (int) - flag
//   0x328: m_stackFilled (int) - flag
//   0x32C: m_threadName (char*)
//   0x330: m_prevThread (EThread*) - linked list
//   0x334: m_nextThread (EThread*) - linked list
//   0x338: vtable2 / callback table pointer
// ============================================================================
class EThread {
public:
    char _base[0x318];          // 0x000: base data
    int m_threadId;             // 0x318: OS thread handle
    void* m_stack;              // 0x31C
    int m_stackSize;            // 0x320
    int m_stackAllocated;       // 0x324
    int m_stackFilled;          // 0x328
    char* m_threadName;         // 0x32C
    EThread* m_prevThread;      // 0x330
    EThread* m_nextThread;      // 0x334
    void* m_callbackTable;      // 0x338: pointer to callback vtable

    EThread(void);
    EThread(int priority, int stackSize, void* stack);
    virtual ~EThread(void);

    void Create(int priority, int stackSize, void* stack);
    void Destroy(void);
    void DeallocateStack(void);

    static void* ThreadEntryPoint(void* param);
    void Attach(int threadId);
    void AttachToCallingThread(void);
    void SetupStack(int stackSize, void* stack);

    void Start(void);
    void Stop(void);
    void SetPriority(int priority);
    int GetPriority(void);
    int IsCallingThread(void);

    void* GetStack(void);
    int GetStackSize(void);
    int IsStackPtr(void* ptr);

    static int GetCurrentThreadId(void);
    static EThread* GetThreadObject(int threadId);
    static EThread* GetCallingThreadObject(void);
    static EThread* GetThreadFromStackPtr(void* ptr);
    static int IsValidMemoryBlock(void* ptr, int size);

    virtual void Main(void);
    void SetThreadName(char* name);
    char* GetThreadName(void);

    void ValidateStack(void);
    static void ValidateAllStacks(void);
    int GetStackUsage(void);
    static void PrintAllThreads(void);
};

// Thread list globals (SDA)
extern EThread* _threadList;     // head of thread linked list
extern EThread* _threadListTail; // tail of thread linked list

// ============================================================================
// ESleep - sleep/alarm functionality
// From: e_ngcsleep.obj
// Layout (from _tCallback at 0x802d7b20):
//   OSAlarm has embedded pointer at offset 0x04 to ESemaphore to release
// ============================================================================
class ESleep {
public:
    static void _tCallback(OSAlarm* alarm, OSContext* context);
};

// ============================================================================
// EFileSystem / ENgcFileSystem - filesystem abstraction
// From: e_ngcfilesystem.obj
// ============================================================================
class EFileSystem {
public:
    // vtable at 0x00
    // constructor calls base at 0x802c6964
    EFileSystem(void);
    virtual ~EFileSystem(void);
};

class EFile;

class ENgcFileSystem : public EFileSystem {
public:
    ENgcFileSystem(void);
    virtual ~ENgcFileSystem(void);
};

// C-style file operation wrappers
extern "C" {
    int efclose(void* file);
    unsigned int efread(void* buffer, unsigned int size, unsigned int count, EFile* file);
    unsigned int efwrite(const void* buffer, unsigned int size, unsigned int count, EFile* file);
    int eftell(EFile* file);
    int efflush(EFile* file);
}

// ============================================================================
// ENgcSNFile - SN Systems file I/O
// From: e_ngcsnfile.obj
// Layout:
//   0x2C: m_handle (int - SN file handle)
//   0x30: m_position (int - current file position)
// ============================================================================
class ENgcSNFile {
public:
    // Fields before 0x2C are inherited/unknown
    // 0x2C: m_handle
    // 0x30: m_position

    int Write(void* buffer, unsigned int size);
    int Tell(void) const;
    int Flush(void);
    int GetLastError(void) const;
    int GetSystemHandle(void) const;
};

// ============================================================================
// ENgcFile - NGC DVD file I/O
// From: e_ngcfile.obj
// Layout:
//   0x28: vtable for file ops (via EFile base)
//   0x2C-0x67: file handle data (DVDFileInfo struct)
//   0x68: m_position (int - current file position)
// ============================================================================
class ENgcFile {
public:
    // Fields defined by EFile base class

    int Write(void* buffer, unsigned int size);
    int Tell(void) const;
    int Flush(void);
    int GetLastError(void) const;
    void* GetSystemHandle(void) const;
};

#endif // NGC_SYSTEM_H
