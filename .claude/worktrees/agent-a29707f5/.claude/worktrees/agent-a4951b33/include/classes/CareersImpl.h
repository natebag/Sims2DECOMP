#ifndef CAREERSIMPL_H
#define CAREERSIMPL_H

#include "types.h"

// CareersImpl - struct layout extracted from assembly analysis
// Estimated minimum size: 0x20 (32 bytes)
// 8 known fields (3 named), 32 methods

class CareersImpl {
public:
    // Constructors / Destructors
    CareersImpl(void)  // 0x80227D94
    ~CareersImpl(void);  // 0x80227DE0

    // Methods
    void Load(void);  // 0x80226EAC (872B)
    void TearDown(void);  // 0x80227214 (100B)
    /* ? */ GetCareerByID(int);  // 0x80227278 (168B)
    /* ? */ GetNumCareers(void);  // 0x80227320 (48B)
    /* ? */ GetCareerByIndex(int);  // 0x80227350 (184B)
    /* ? */ GetIndexByCareer(Career *);  // 0x80227408 (204B)
    /* ? */ GetJobPerformance(int);  // 0x802274D4 (400B)
    /* ? */ GetJobGrade(int);  // 0x80227664 (112B)
    /* ? */ GetOfferDialogText(unsigned wchar_t *, Career &, int, bool);  // 0x802276D4 (492B)
    /* ? */ GetBehCareerData(Career &, int, int, short *);  // 0x802278C0 (620B)
    /* ? */ GetJobName(Job &, bool);  // 0x80227B2C (148B)
    /* ? */ GetShortName(Job &, bool);  // 0x80227BC0 (148B)
    /* ? */ GetCarpoolHour(Job &);  // 0x80227C54 (96B)
    /* ? */ GetSuit(Job &, bool);  // 0x80227CB4 (64B)

    // ---- Field Layout (from assembly analysis) ----
    void** _vtable;  // 0x000 [R/W] - vtable pointer (GetBehCareerData, Load, ~CareersImpl)
    u32 m_field_004;  // 0x004 [R/W] (Load, TearDown)
    u32 m_careerByID;  // 0x008 [R/W] (GetCareerByID, Load, TearDown)
    u32 m_field_00C;  // 0x00C [W] (Load, TearDown)
    u32 m_jobPerformance;  // 0x010 [R/W] (GetJobPerformance, Load, TearDown)
    u16 m_field_014;  // 0x014 [W] (Load)
    u8 _pad_016[2];  // 0x016
    u32 m_field_018;  // 0x018 [W] (Load)
    u32 m_field_01C;  // 0x01C [W] (Load)
};

#endif // CAREERSIMPL_H
