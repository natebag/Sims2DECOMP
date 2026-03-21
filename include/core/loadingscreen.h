#ifndef LOADINGSCREEN_H
#define LOADINGSCREEN_H

#include "types.h"

// Forward declarations
class EAHeap;

// CLoadingScreen - Loading screen manager
// From: loadingscreen.obj
// Size: at least 0x358 bytes (mode at offset 0x354)
class CLoadingScreen {
public:
    enum eLoadingScreenMode {
        // values TBD
    };

    CLoadingScreen(eLoadingScreenMode mode);

    // Custom allocator - uses MainHeap + EAHeap::MallocAligned
    void* operator new(unsigned int size);
    // Custom deallocator - uses MainHeap + EAHeap::Free
    void operator delete(void* ptr);

    // Returns m_mode at offset 0x354
    eLoadingScreenMode GetMode(void) const;

private:
    char _pad[0x354];                    // unknown members
    eLoadingScreenMode m_mode;           // offset 0x354
};

#endif // LOADINGSCREEN_H
