#include "types.h"
#include "stub_classes.h"
#if 0
// Return type mismatch: stub_classes says void, auto_match says void*
void* CasSimState::GetSimDescription() { return (char*)this + 0x8; }
void* CasSimState::GetStoredSimDescription() { return (char*)this + 0x12C; }
#endif
