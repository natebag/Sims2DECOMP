#ifndef OBJTESTSIM_H
#define OBJTESTSIM_H

#include "types.h"

// ObjTestSim - struct layout extracted from assembly analysis
// Estimated minimum size: 0xA2 (162 bytes)
// 8 known fields (2 named), 23 methods

class ObjTestSim {
public:
    // Constructors / Destructors
    ObjTestSim(cXPerson *, cXObject *)  // 0x80332BEC
    ObjTestSim(cXPerson *)  // 0x80332B2C
    ~ObjTestSim(void);  // 0x80332CBC

    // Methods
    /* ? */ GetCheckTreeAds(void);  // 0x8032998C (44B)
    void AppendInteractionsForMenu(InteractionList &, int);  // 0x80333980 (2016B)
    bool IsMenuInProgress(void);  // 0x80334238 (92B)
    void MakeNewMenuItem(unsigned wchar_t *, short *, StackElem *, short);  // 0x80334294 (328B)
    void SetStackObject(cXObject *);  // 0x80332DA4 (132B)
    void TestInteraction(Interaction *, bool, bool, bool, TTabScratchEntry **);  // 0x80332E28 (2780B)
    void SetupInteractionColors(Interaction *, short);  // 0x80333904 (124B)
    void RunMenuCheckTree(InteractionList &, Interaction &);  // 0x80334160 (216B)
    void AppendInteractionsForAuto(InteractionList &);  // 0x803343DC (1420B)

    // ---- Field Layout (from assembly analysis) ----
    void** _vtable;  // 0x000 [R/W] - vtable pointer (AppendInteractionsForAuto, AppendInteractionsForMenu, ObjTestSim, ...)
    u32 m_stackObject;  // 0x004 [R/W] (AppendInteractionsForAuto, AppendInteractionsForMenu, ObjTestSim, ...)
    u32 m_field_008;  // 0x008 [R] (AppendInteractionsForMenu)
    u32 m_field_00C;  // 0x00C [R] (AppendInteractionsForMenu)
    s16 m_field_010;  // 0x010 [R] (AppendInteractionsForAuto, AppendInteractionsForMenu)
    u8 _pad_012[6];  // 0x012
    u32 m_field_018;  // 0x018 [R/W] (ObjTestSim, TestInteraction, ~ObjTestSim)
    u8 _pad_01C[0x20];  // 0x01C
    u32 m_field_03C;  // 0x03C [R/W] (AppendInteractionsForMenu, MakeNewMenuItem)
    u8 _pad_040[0x60];  // 0x040
    s16 m_field_0A0;  // 0x0A0 [R] (TestInteraction)
};

#endif // OBJTESTSIM_H
