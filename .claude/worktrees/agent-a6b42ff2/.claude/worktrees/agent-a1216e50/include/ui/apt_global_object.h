#ifndef APT_GLOBAL_OBJECT_H
#define APT_GLOBAL_OBJECT_H

#include "types.h"
#include "ui/apt_value.h"

// ============================================================================
// AptGlobal - APT global scope object
// Source: libaptz.a(AptGlobalObject.cpp.obj)
// Layout:
//   0x00-0x0B: AptValueGC base
//   0x0C: AptNativeHash (embedded hash table, accessed via this+12)
// ============================================================================
class AptGlobal : public AptValueGC {
public:
    // 0x0C: embedded AptNativeHash starts here (accessed via addi r3,r3,12)

    AptGlobal();
    ~AptGlobal();

    AptValue* objectMemberLookup(AptValue* obj, EAStringC* name) const;
    int objectMemberSet(AptValue* obj, EAStringC* name, AptValue* val);

    void Set(EAStringC* key, AptValue* val);
    AptValue* Lookup(EAStringC* key) const;
};

#endif // APT_GLOBAL_OBJECT_H
