#ifndef MEMORYMETERWIN_H
#define MEMORYMETERWIN_H

#include "types.h"

// ============================================================================
// Panelstateman - Panel state machine base class
// From: memorymeterwin.obj
// Contains a vtable pointer at offset 0x04
// ============================================================================
class Panelstateman {
public:
    // Panel state enum
    enum Panelstate {
        // values TBD
    };

    // Panel event enum
    enum PanelEvent {
        // values TBD
    };

    virtual ~Panelstateman(void);
    virtual void SetState(Panelstate state);
    virtual void SetEvent(PanelEvent event, unsigned int param);

    void PollMemoryLevels(void);

protected:
    void* m_vtable;  // 0x00 - some base class pointer
    void* m_panel;   // 0x04 - vtable for Panelstateman
};

// ============================================================================
// EMemoryMeterWin - Debug memory meter window
// From: memorymeterwin.obj
// Inherits from Panelstateman
// ============================================================================
class EMemoryMeterWin : public Panelstateman {
public:
    void Init(void);
    void Reset(void);

    virtual void SetState(Panelstate state);
    virtual void SetEvent(PanelEvent event, unsigned int param);
};

#endif // MEMORYMETERWIN_H
