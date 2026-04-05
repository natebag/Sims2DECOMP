/* ESim struct layout — reverse-engineered from DOL field accesses
 *
 * Sources:
 *   - Matched functions in src/matched/agent/ (IsMale, DrawSim, DrawSimModel, etc.)
 *   - 39 functions in src/asm_decomp/ESim.cpp (DOL byte analysis)
 *   - 101 unique field offsets identified
 *
 * This header represents the EXACT memory layout required for matching code generation.
 * Field offsets are critical — do not change without verifying against DOL.
 */

#ifndef ESIM_H
#define ESIM_H

#include "types.h"

/* Forward declarations */
class cXPerson;
class ERC;
class EVec3;
class ELevelDrawData;
class EOrderTableData;
class EIStaticModel;
class EShader;
class EMat4;
class E3DWindow;

/* ============================================================================
 * ESim Inner Object — accessed via this->m_inner (offset 0x3D0)
 * Has vtable at offset 0x04 for virtual dispatch
 * ============================================================================ */
struct ESimInnerVtable {
    char pad[4];
    /* 0x04 */ void* m_func1;
    /* ... vtable entries ... */
    /* 0x200 */ short m_isMaleDelta;
    /* 0x202 */ char _pad1[2];
    /* 0x204 */ int (*m_isMaleFunc)(void*);
    /* ... more entries ... */
    /* 0x238 */ short m_drawSimDelta;
    /* 0x23A */ char _pad2[2];
    /* 0x23C */ int (*m_drawSimFunc)(void*);
    /* ... remaining entries ... */
};

struct ESimInner {
    /* 0x00 */ void* m_field00;
    /* 0x04 */ ESimInnerVtable* m_vtable;
    /* ... inner object fields ... */
};

/* ============================================================================
 * ESim Model Structure — accessed via this->m_model (offset 0x63C)
 * ============================================================================ */
struct ESimModel {
    char pad[0x68];
    /* 0x68 */ EIStaticModel* m_parts[4];
};

/* ============================================================================
 * Main ESim Class
 * 
 * Inherits from: ISimInstance (base class constructor called)
 * 
 * SN Systems ABI notes:
 * - Vtable pointer is at offset 0x320 (stored in constructor)
 * - Multiple sub-objects with their own data
 * - Field layout is critical for matching instruction offsets
 * ============================================================================ */
struct ESim {
    /* ------------------------------------------------------------------------
     * BASE CLASS / ISimInstance fields (offsets 0x00-0x??)
     * ------------------------------------------------------------------------ */
    /* 0x000 */ void* m_vtable;           /* ISimInstance vtable */
    /* 0x004 */ void* m_field04;          /* R/W: initModel, Update, etc. */
    /* 0x008 */ void* m_field08;          /* R/W: initModel, Update */
    
    /* 0x00C */ char _pad00C[0x14-0x0C];
    /* 0x014 */ short m_field14;          /* R/W: Update */
    /* 0x018 */ short m_field18;          /* R/W: Update */
    
    /* 0x01C */ char _pad01C[0x54-0x1C];
    /* 0x054 */ char m_field54;           /* W: constructor */
    
    /* 0x055 */ char _pad055[0x5C-0x55];
    /* 0x05C */ int m_field5C;            /* R/W: UpdateSkillMeter */
    
    /* 0x060 */ char _pad060[0x68-0x60];
    /* 0x068 */ char m_field68;           /* R/W: Update */
    
    /* 0x069 */ char _pad069[0x70-0x69];
    /* 0x070 */ int m_field70;            /* R: PropOrderTableCallback */
    
    /* 0x074 */ char _pad074[0x98-0x74];
    /* 0x098 */ void* m_field98;          /* R: Draw */
    
    /* 0x09C */ char _pad09C[0x120-0x9C];
    /* 0x120 */ void* m_field120;         /* R/W: Update, CreateThumbnail */
    
    /* 0x124 */ char _pad124[0x320-0x124];
    
    /* ------------------------------------------------------------------------
     * VTABLE POINTER (SN ABI: stored during construction)
     * ------------------------------------------------------------------------ */
    /* 0x320 */ void* m_esimVtable;       /* ESim's own vtable pointer */
    
    /* ------------------------------------------------------------------------
     * SUB-OBJECT: Skin/Model data (offsets 0x324-0x3CF)
     * ------------------------------------------------------------------------ */
    /* 0x324 */ char _pad324[0x3D0-0x324];
    
    /* ------------------------------------------------------------------------
     * INNER OBJECT POINTER — Primary vtable dispatch hub
     * Loaded at offset 0x3D0, used for most virtual calls
     * ------------------------------------------------------------------------ */
    /* 0x3D0 */ ESimInner* m_inner;       /* Primary inner object for dispatch */
    
    /* ------------------------------------------------------------------------
     * SIM STATE & FLAGS (offsets 0x3D4-0x427)
     * ------------------------------------------------------------------------ */
    /* 0x3D4 */ char _pad3D4[0x3D8-0x3D4];
    /* 0x3D8 */ int m_field3D8;           /* R/W: DrawPlumbBob */
    
    /* 0x3DC */ char _pad3DC[0x3E0-0x3DC];
    /* 0x3E0 */ void* m_field3E0;         /* R/W: Draw, Update */
    
    /* 0x3E4 */ char _pad3E4[0x3E8-0x3E4];
    /* 0x3E8 */ int m_field3E8;           /* R/W: Draw, Update, DoAnimation */
    /* 0x3EC */ int m_field3EC;           /* R/W: Draw, Update */
    
    /* 0x3F0 */ char _pad3F0[0x3F4-0x3F0];
    /* 0x3F4 */ int m_field3F4;           /* R/W: Update, DoAnimation */
    
    /* 0x3F8 */ char _pad3F8[0x408-0x3F8];
    /* 0x408 */ int m_field408;           /* R/W: Draw, Update */
    /* 0x40C */ int m_field40C;           /* R/W: Draw, Update */
    /* 0x410 */ int m_field410;           /* R/W: Draw, Update */
    
    /* 0x414 */ char _pad414[0x418-0x414];
    /* 0x418 */ int m_field418;           /* R/W: Draw, Update */
    /* 0x41C */ int m_field41C;           /* R/W: Draw, Update */
    /* 0x420 */ int m_field420;           /* R/W: Draw, Update */
    
    /* 0x424 */ char _pad424[0x428-0x424];
    /* 0x428 */ int m_drawSimState;       /* R/W: DrawSim result storage */
    
    /* 0x42C */ int m_field42C;           /* R/W: Draw, Update */
    /* 0x430 */ int m_field430;           /* R/W: Draw, Update */
    /* 0x434 */ int m_field434;           /* R/W: Update, DoAnimation */
    /* 0x438 */ int m_field438;           /* R/W: Update */
    
    /* 0x43C */ char _pad43C[0x440-0x43C];
    /* 0x440 */ void* m_field440;         /* W: constructor, Update */
    
    /* 0x444 */ char _pad444[0x478-0x444];
    /* 0x478 */ void* m_field478;         /* W: constructor */
    
    /* 0x47C */ char _pad47C[0x4B0-0x47C];
    /* 0x4B0 */ void* m_field4B0;         /* W: constructor, Update */
    
    /* 0x4B4 */ char _pad4B4[0x4E8-0x4B4];
    /* 0x4E8 */ void* m_field4E8;         /* W: constructor, Update */
    
    /* 0x4EC */ char _pad4EC[0x528-0x4EC];
    /* 0x528 */ int m_field528;           /* R/W: Update */
    /* 0x52C */ int m_field52C;           /* R/W: Update */
    
    /* 0x530 */ char _pad530[0x628-0x530];
    /* 0x628 */ int m_field628;           /* R/W: Update */
    
    /* 0x62C */ char _pad62C[0x630-0x62C];
    /* 0x630 */ void* m_field630;         /* R/W: Update, CreateThumbnail */
    
    /* ------------------------------------------------------------------------
     * MODEL POINTER — Sim model data (offset 0x63C)
     * ------------------------------------------------------------------------ */
    /* 0x634 */ char _pad634[0x63C-0x634];
    /* 0x63C */ ESimModel* m_model;       /* Sim model parts */
    
    /* 0x640 */ void* m_field640;         /* R/W: Draw */
    /* 0x644 */ int m_field644;           /* R/W: Update */
    
    /* 0x648 */ char _pad648[0x11BC-0x648];
    /* 0x11BC */ void* m_field11BC;       /* R: Draw */
    
    /* Total known struct extent: 0x11C0 bytes (4544+ bytes) */
};

/* ============================================================================
 * Function Prototypes (matched functions)
 * ============================================================================ */

/* Type checking */
int ESim_IsMale(void* this);            /* 0x80031790 */
int ESim_IsFemale(void* this);          /* 0x800317C8 */
int ESim_IsAdult(void* this);           /* 0x800317EC */
int ESim_IsChild(void* this);           /* 0x80031824 */
int ESim_IsDog(void* this);             /* 0x8003185C */
int ESim_IsCat(void* this);             /* 0x80031894 */
int ESim_IsMonkey(void* this);          /* 0x800318CC */
int ESim_IsPet(void* this);             /* 0x80031904 */

/* Drawing & Rendering */
void ESim_DrawSimModel(void* this, ERC* rc, EMat4* mat, unsigned int flags); /* 0x80032EF8 */
void ESim_DoAnimation(void* this);      /* 0x800334B4 */
void ESim_DoLightingCalculation(void* this); /* 0x800334F8 */
void ESim_SetAnim(void* this, char* anim); /* 0x800342CC */
void ESim_CreateSkinAsync(void* this);  /* 0x800345C4 */
void ESim_DrawSim(void* this, bool b);  /* 0x8003494C */

/* State & Queries */
int ESim_HasQueuedOperation(void* this); /* 0x8003489C */
void ESim_UpdateQueuedOperation(void* this); /* 0x800348B8 */
float ESim_GetScaler(void* this);       /* 0x80034908 */
int ESim_GetPlayerIndex(void* this);    /* 0x80034AB8 */
void ESim_UpdatePlumbBob(void* this);   /* 0x80034AF0 */
void ESim_ChangeCostume(void* this);    /* 0x80034DE4 */

/* Factory methods */
void* ESim_New(void* this);             /* 0x80035018 */
void ESim_Construct(void* this);        /* 0x8003506C */
void ESim_SafeDelete(void* this);       /* 0x800350B0 */

/* Type info */
void* ESim_GetTypeInfo(void* this);     /* 0x800350F0 */
const char* ESim_GetTypeName(void* this); /* 0x800350FC */
unsigned short ESim_GetTypeKey(void* this); /* 0x80035108 */
unsigned short ESim_GetTypeVersion(void* this); /* 0x80035114 */
void* ESim_GetTypeInfoStatic(void);     /* 0x80035120 */
short ESim_GetReadVersion(void* this);  /* 0x8003512C */
void* ESim_CreateCopy(void* this);      /* 0x8003518C */

/* Model access */
void* ESim_GetModelPart(void* this);    /* 0x8003531C */
void ESim_SetVanityDraw(void* this);    /* 0x80035340 */
bool ESim_UseVanityDraw(void* this);    /* 0x8003534C */
void ESim_SetXOb(void* this);           /* 0x80035308 */
void* ESim_GetShadow(void* this);       /* 0x8003530C */
cXPerson* ESim_GetPerson(void* this);   /* 0x80035314 */
void* ESim_GetSimHead(void* this);      /* 0x80035330 */
void* ESim_GetSimModel(void* this);     /* 0x80035338 */
unsigned int ESim_GetPlumbBobState(void* this); /* 0x8003535C */
bool ESim_GetIsModelLoaded(void* this); /* 0x8003536C */
bool ESim_GetIsChangingOutfit(void* this); /* 0x80035374 */
void ESim_RegisterType(unsigned short type); /* 0x80035138 */

#endif /* ESIM_H */
