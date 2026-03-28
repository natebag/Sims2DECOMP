#ifndef UIDRAW_H
#define UIDRAW_H

#include "types.h"

// Forward declarations
class ERC;
template<typename P1> class CBFunctor1;

// ============================================================================
// UIDrawTable - singleton managing draw callbacks (pre/post flash)
// Maintains a linked list of draw callback records with priority ordering
// ============================================================================
class UIDrawTable {
public:
    enum DrawTablePriority {};

    struct DrawTableRecord {
        void* m_prev;           // 0x00 - linked list prev
        void* m_next;           // 0x04 - linked list next
        int m_priority;         // 0x08 - DrawTablePriority
        int m_functorThunk;     // 0x0C - functor thunk pointer (for matching)
        u8 _pad[0x10];          // 0x10 - remaining record data
    };

    DrawTableRecord* m_head;   // 0x00 - linked list head
    u8 _pad[0x0C];             // 0x04

    UIDrawTable();
    ~UIDrawTable();

    void AddRecord(DrawTablePriority priority, CBFunctor1<ERC*>& functor, char* name);
    void RemoveRecord(DrawTableRecord* record);
    void InstallEntry(DrawTablePriority priority, CBFunctor1<ERC*>& functor, char* name);
    void UnInstallEntry(CBFunctor1<ERC*>& functor);
    void UnInstallAllName(char* name);
    int ContainsEntry(CBFunctor1<ERC*>& functor);
    void ExecuteDrawsPreFlash(ERC* rc);
    void ExecuteDrawsPostFlash(ERC* rc);

    static UIDrawTable* Instance();
    static void Shutdown();

    static UIDrawTable* s_pInstance;
};

#endif // UIDRAW_H
