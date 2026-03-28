#ifndef APT_VALUE_FACTORY_H
#define APT_VALUE_FACTORY_H

#include "types.h"
#include "ui/apt_value.h"

// ============================================================================
// AptValueFactory - factory for creating APT value objects
// Source: libaptz.a(AptValueFactory.cpp.obj)
// ============================================================================
class AptValueFactory {
public:
    static AptValue* CreateString(char* str);
    static AptValue* CreateUndefined();
};

#endif // APT_VALUE_FACTORY_H
