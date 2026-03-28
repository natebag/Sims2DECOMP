#ifndef OBJECTSAVETYPETABLE_H
#define OBJECTSAVETYPETABLE_H

#include "types.h"

// ObjectSaveTypeTable - struct layout extracted from assembly analysis
// Estimated minimum size: 0xC (12 bytes)
// 3 known fields (0 named), 3 methods

class ObjectSaveTypeTable {
public:
    // Constructors / Destructors
    ObjectSaveTypeTable(ObjectFolderImpl *)  // 0x802D07DC

    // Methods
    void DoStream(ReconBuffer *, int);  // 0x802C36CC (1456B)

    // ---- Field Layout (from assembly analysis) ----
    u32 m_field_000;  // 0x000 [R] (DoStream)
    u32 m_field_004;  // 0x004 [R/W] (DoStream)
    u32 m_field_008;  // 0x008 [R/W] (DoStream)
};

#endif // OBJECTSAVETYPETABLE_H
