#include "types.h"
#include "stub_classes.h"
#if 0
// r13 reference and operator char* issues - can't fix
void EString::SetToNull() { *(int*)((char*)this + 0x0) = 0; }
int EString::operator char *() const { return *(int*)((char*)this + 0x0); }
#endif
