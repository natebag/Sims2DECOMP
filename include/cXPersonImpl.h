/* cXPersonImpl struct layout — reverse-engineered from DOL field accesses
 *
 * Sources:
 *   - 50+ matched functions in src/matched/agent/
 *   - 96 functions in src/asm_decomp/cXPersonImpl.cpp
 *   - 102 unique field offsets identified
 */

#ifndef CXPERSONIMPL_H
#define CXPERSONIMPL_H

#include "types.h"

/* Forward declarations */
class cXObject;
class cXPerson;
class Interaction;
class StackElem;
class XPrimParam;
class ReconBuffer;
class RoutingSlot;
class XRoute;
class TileList;
class ObjSelector;
class ObjectModule;

/* ============================================================================
 * cXPersonImpl Inner Object — accessed via this->m_inner (offset 0x04)
 * ============================================================================ */
struct cXPersonImplInner {
    /* 0x00 */ void* m_vtable;
    /* 0x04 */ void* m_data;
    /* ... more fields ... */
};

/* ============================================================================
 * Main cXPersonImpl Class
 * 
 * Inherits from: cXObjectImpl (via cXObject)
 * ============================================================================ */
struct cXPersonImpl {
    /* ------------------------------------------------------------------------
     * BASE CLASS / cXObjectImpl fields (offsets 0x00-0x??)
     * ------------------------------------------------------------------------ */
    /* 0x000 */ void* m_vtable;           /* cXObjectImpl vtable */
    /* 0x004 */ cXPersonImplInner* m_inner; /* Primary inner object */
    
    /* 0x008 */ char _pad008[0x0C-0x08];
    /* 0x00C */ int m_field0C;            /* R/W: frequently accessed */
    
    /* 0x010 */ char _pad010[0x48-0x10];
    /* 0x048 */ short m_visitorStatus;    /* IsVisitor check */
    
    /* 0x04A */ char _pad04A[0x9C-0x4A];
    /* 0x09C */ unsigned short m_flags;   /* Bit flags: IsInvisible, IsGreen, etc. */
    
    /* ------------------------------------------------------------------------
     * MOTIVES ARRAY (offset 0xA8)
     * ------------------------------------------------------------------------ */
    /* 0x0A0 */ char _pad0A0[0xA8-0x0A0];
    /* 0x0A8 */ float m_motives[16];      /* Sim motives (hunger, energy, etc.) */
    
    /* ------------------------------------------------------------------------
     * ACTIONS & INTERACTIONS
     * ------------------------------------------------------------------------ */
    /* 0x0E8 */ char _pad0E8[0x3F4-0x0E8];
    /* 0x3F4 */ void* m_field3F4;          /* Frequently accessed */
    
    /* 0x3F8 */ char _pad3F8[0x534-0x3F8];
    /* 0x534 */ int m_field534;            /* R/W: Sim memory related */
    
    /* ------------------------------------------------------------------------
     * MEMBER FIELDS 0x530-0x550 range (frequently accessed)
     * ------------------------------------------------------------------------ */
    /* 0x530 */ char _pad530[0x534-0x530];
    /* 0x534 */ int m_member534;
    
    /* 0x538 */ char _pad538[0x53C-0x538];
    /* 0x53C */ int m_member53C;
    /* 0x540 */ int m_member540;
    
    /* 0x544 */ char _pad544[0x548-0x544];
    /* 0x548 */ int m_member548;
    /* 0x54C */ int m_member54C;
    /* 0x550 */ int m_member550;
    
    /* ------------------------------------------------------------------------
     * Extended data (offsets 0x554-0x604)
     * ------------------------------------------------------------------------ */
    /* 0x554 */ char _pad554[0x5C4-0x554];
    /* 0x5C4 */ int m_member5C4;
    /* 0x5C8 */ int m_member5C8;
    
    /* 0x5CC */ char _pad5CC[0x604-0x5CC];
    /* 0x604 */ int m_member604;
    
    /* Total known struct extent: 0x608+ bytes */
};

/* ============================================================================
 * Function Prototypes (matched functions)
 * ============================================================================ */

/* Motive accessors */
float cXPersonImpl_GetMotive(void* this, int index);     /* 0x801253A4 */
float* cXPersonImpl_GetMotiveRef(void* this, int index); /* 0x801253B4 */
float* cXPersonImpl_GetOldMotiveRef(void* this, int index); /* 0x801253C4 */
void cXPersonImpl_SetMotive(void* this, int index, float value); /* 0x801253D4 */

/* Action management */
void cXPersonImpl_SetCurrentAction(void* this, Interaction* action); /* 0x80129ECC */
Interaction* cXPersonImpl_GetPendingAction(void* this);    /* 0x8012C714 */
void cXPersonImpl_UpdateCurrentAction(void* this);         /* 0x80129F28 */
void cXPersonImpl_CompleteCurrentAction(void* this);       /* 0x80129FA8 */
void cXPersonImpl_DeleteTopAction(void* this);             /* 0x8012A028 */
void cXPersonImpl_CancelLastAction(void* this);            /* 0x8012A0A8 */
void cXPersonImpl_CancelAllActions(void* this);            /* 0x8012A128 */
void cXPersonImpl_CancelAllButLastActions(void* this);     /* 0x8012A1A8 */

/* State checks */
int cXPersonImpl_IsVisitor(void* this);                  /* 0x8012C8A8 */
int cXPersonImpl_IsInvisible(void* this);                /* 0x8012C8E0 */
int cXPersonImpl_IsGreen(void* this);                    /* 0x8012C8EC */
int cXPersonImpl_IsGhost(void* this);                    /* 0x8012C8F8 */
int cXPersonImpl_IsAlien(void* this);                    /* 0x8012C904 */
int cXPersonImpl_IsInMotiveFailure(void* this);          /* 0x8012C910 */
int cXPersonImpl_NeedsWantFearShuffle(void* this);       /* 0x8012C91C */
int cXPersonImpl_IsInSocialMode(void* this);             /* 0x8012CA2C */
int cXPersonImpl_IsIdle(void* this);                     /* 0x80125AD0 */

/* Data accessors */
int cXPersonImpl_GetPersonData(void* this);              /* 0x8012C758 */
void cXPersonImpl_SetPersonData(void* this, int data);   /* 0x8012C768 */
int cXPersonImpl_GetCurrentRoom(void* this);             /* 0x8012C7F4 */
void cXPersonImpl_SetNeighborID(void* this, short id);   /* 0x8012C838 */
int cXPersonImpl_GetSimDescription(void* this);          /* 0x8012C8C0 */
int cXPersonImpl_GetServiceNPC(void* this);              /* 0x8012C8D0 */

/* Member accessors (template pattern) */
int cXPersonImpl_GetMember1032(void* this);              /* 0x8012C988 */
int cXPersonImpl_GetMember1072(void* this);              /* 0x8012C990 */
int cXPersonImpl_GetMember1076(void* this);              /* 0x8012C998 */
void cXPersonImpl_SetMember1076(void* this, int val);    /* 0x8012C9A0 */
int cXPersonImpl_GetMember1080(void* this);              /* 0x8012C9A8 */
void cXPersonImpl_SetMember1080(void* this, int val);    /* 0x8012C9B0 */
int cXPersonImpl_GetMember1084(void* this);              /* 0x8012C9C0 */
int cXPersonImpl_GetMember1088(void* this);              /* 0x8012C9B8 */
int cXPersonImpl_GetMember1092(void* this);              /* 0x8012C9C8 */
int cXPersonImpl_GetMember1096(void* this);              /* 0x8012C9D0 */
int cXPersonImpl_GetMember1328(void* this);              /* 0x8012C9F8 */
void cXPersonImpl_SetMember1328(void* this, int val);    /* 0x8012C9F8 */
int cXPersonImpl_GetMember1336(void* this);              /* 0x8012CA00 */
void cXPersonImpl_SetMember1336(void* this, int val);    /* 0x8012CA08 */
int cXPersonImpl_GetMember1340(void* this);              /* 0x8012CA10 */
void cXPersonImpl_SetMember1340(void* this, int val);    /* 0x8012CA18 */
void cXPersonImpl_ClearMember1340(void* this);           /* 0x8012CA20 */
int cXPersonImpl_GetMember1348(void* this);              /* 0x8012CA4C */
void cXPersonImpl_SetMember1348(void* this, int val);    /* 0x8012B82C */
int cXPersonImpl_GetMember1352(void* this);              /* 0x8012CA44 */
int cXPersonImpl_GetMember1356(void* this);              /* 0x8012CA54 */
void cXPersonImpl_SetMember1356(void* this, int val);    /* 0x8012B8C4 */

/* Awareness */
void cXPersonImpl_SetAwareOfObject(void* this, cXObject* obj);      /* 0x8012CAA8 */
void cXPersonImpl_SetAwareOfObjectKilled(void* this, cXObject* obj); /* 0x8012CAE0 */
void cXPersonImpl_ClearAwareOfObject(void* this, cXObject* obj);  /* 0x8012CB18 */

/* Other */
int cXPersonImpl_GetFlags(void* this);                   /* 0x8012C978 */
short cXPersonImpl_GetShort8(void* this);                /* 0x8012C780 */
int cXPersonImpl_GetMember1012(void* this);              /* 0x8012C7EC */
void cXPersonImpl_SetMember3424(void* this, int val);    /* 0x8012D1CC */
int cXPersonImpl_GetMember3424(void* this);              /* 0x8012D1C4 */

/* Type checks - template family */
int cXPersonImpl_IsDog(void* this);                      /* 0x801... */
int cXPersonImpl_IsCat(void* this);                      /* 0x801... */
int cXPersonImpl_IsMonkey(void* this);                   /* 0x801... */
int cXPersonImpl_IsPet(void* this);                      /* 0x801... */
int cXPersonImpl_IsChild(void* this);                    /* 0x801... */
int cXPersonImpl_IsMale(void* this);                     /* 0x801... */

#endif /* CXPERSONIMPL_H */
