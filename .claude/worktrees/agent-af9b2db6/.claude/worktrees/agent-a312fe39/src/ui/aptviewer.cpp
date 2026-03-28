#if 0 // SKIP
// aptviewer.cpp - AptViewer (APT UI viewer/controller)
// Part of the Sims 2 GC decompilation
// Original: u2_ngc_release_dvd(aptviewer.obj)
//
// Small functions (<=64 bytes) decompiled from the aptviewer object file.
// AptViewer manages the Flash/ActionScript-based UI system.

#include "types.h"
#include "stub_classes.h"

// Forward declarations
class UIObjectBase;

//=============================================================================
// AptViewer
//=============================================================================
class AptViewer {
public:
    u8 pad00[0x40];
    int m_readControllerActive;  // approximate offset
    int m_allowControllerReading;

    // _freeFontTable - empty stub
    // Address: 0x80010078, Size: 4
    static void _freeFontTable() {}

    // Update - empty stub
    // Address: 0x80010640, Size: 4
    void Update() {}

    // ReadController - returns immediately (size 8 = lwz + blr pattern)
    // Address: 0x80010D68, Size: 8
    int ReadController(int, bool, int, bool) { return 0; }

    // UIOn - returns 1
    // Address: 0x80011E14, Size: 8
    int UIOn() { return 1; }

    // AllowControllerReading
    // Address: 0x80011E1C, Size: 16
    void AllowControllerReading(bool allow) {
        m_allowControllerReading = allow ? 1 : 0;
    }

    // IsReadControllerActive
    // Address: 0x80011E58, Size: 8
    int IsReadControllerActive() {
        return m_readControllerActive;
    }

    // Shutdown
    // Address: 0x800105B4, Size: 36
    // NON_MATCHING - calls destroy functions
    void Shutdown();

    // CreateAptViewer
    // Address: 0x80010038, Size: 64
    // NON_MATCHING - heap alloc + constructor
    static AptViewer* CreateAptViewer();

    // closeFunc
    // Address: 0x8001007C, Size: 44
    // NON_MATCHING - shutdown callback
    static void closeFunc();

    // CallFunction
    // Address: 0x80010358, Size: 60
    // NON_MATCHING - varargs forwarding
    void CallFunction(char*, char*, char*, int, ...);

    // RepeatClear
    // Address: 0x80010D70, Size: 60
    // NON_MATCHING - controller state clear
    void RepeatClear(int, int);

    // NewSetMessageHandler
    // Address: 0x80011DCC, Size: 36
    // NON_MATCHING - handler registration
    void NewSetMessageHandler(UIObjectBase*);

    // NewRemoveMessageHandler
    // Address: 0x80011DF0, Size: 36
    // NON_MATCHING - handler removal
    void NewRemoveMessageHandler(UIObjectBase*);

    // IsWaitingForPlayerInput
    // Address: 0x80011E2C, Size: 44
    // NON_MATCHING - flag check
    bool IsWaitingForPlayerInput();
};
#endif
