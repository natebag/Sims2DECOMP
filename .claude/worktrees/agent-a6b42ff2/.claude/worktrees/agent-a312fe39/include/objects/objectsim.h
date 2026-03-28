#ifndef OBJECTSIM_H
#define OBJECTSIM_H

#include "types.h"

// Forward declarations
class cXObjectImpl;
class StackElem;
class Behavior;
class BehaviorNode;
class ObjSelector;
struct XPrimParam;
struct AnimateNewParam;
struct PlaySoundParam;
struct KillSoundsParam;
struct ExpressionParam;
struct CompleteGoalParam;
struct InventoryCommandParam;
struct FindTreeNewParam;
struct DialogParam;
class BString2;
class StringBuffer2;

// ============================================================================
// cXObjectImpl - Object simulation implementation (primitives)
// Object file: objectsim.obj
// These are the small stub/simple functions from the object simulation system
// ============================================================================

// Forward declaration of the static init/destruct functions
void __static_initialization_and_destruction_0_objectsim(int action, int priority);

// overrideDialogReturnCode static at 0x804FDCCC
extern short cXObjectImpl_overrideDialogReturnCode;

// Job HUD name list at 0x804864C0
extern void* JobControlNameList;

// Job name list at 0x804864B0
extern void* JobNameList;

// GetJobHUDName - returns constant string table pointer
char* GetJobHUDName(short jobId);

#endif // OBJECTSIM_H
