// aptactioninterpreter_stubs.cpp - Stub implementations for Aptactioninterpreter
// Auto-generated from symbols.json - 108 functions
// These are stub implementations to register progress.
// Each function needs proper decompilation to match the original binary.

#include "types.h"
#include "stub_classes.h"

// 0x803EB38C | 172 bytes
void AptActionInterpreter::initialize(AptInitParmsT &) { }

// 0x803EB438 | 220 bytes
void AptActionInterpreter::shutdown(void) { }

// 0x803EB514 | 2504 bytes
void AptActionInterpreter::_parseStream(unsigned char *, unsigned char *, AptConstFile *, int *) { }

// 0x803EC190 | 316 bytes
void AptActionInterpreter::getObject(AptValue *, AptValue *, EAStringC *) { }

// 0x803EC2CC | 348 bytes
void AptActionInterpreter::getContext(AptValue *, AptValue *, EAStringC *, AptValue **, EAStringC &) { }

// 0x803EC630 | 1256 bytes
void AptActionInterpreter::setVariable(AptValue *, AptValue *, EAStringC *, AptValue *, int, int, int) { }

// 0x803ECB18 | 924 bytes
void AptActionInterpreter::cbCallMethod_setInterval(AptValue *, int) { }

// 0x803ECEB4 | 308 bytes
void AptActionInterpreter::cbCallMethod_clearInterval(AptValue *, int) { }

// 0x803ECFE8 | 388 bytes
void AptActionInterpreter::cbCallMethod_hitTest(AptCIH *, int) { }

// 0x803ED16C | 1196 bytes
void AptActionInterpreter::cbCallMethod_isNaN(AptValue *, int) { }

// 0x803ED618 | 416 bytes
void AptActionInterpreter::cbCallMethod_unescape(AptValue *, int) { }

// 0x803ED7B8 | 372 bytes
void AptActionInterpreter::cbCallMethod_escape(AptValue *, int) { }

// 0x803ED92C | 1628 bytes
void AptActionInterpreter::cbCallMethod_boolean(AptValue *, int) { }

// 0x803EE1AC | 328 bytes
void AptActionInterpreter::getName2(AptCIH *, EAStringC &) { }

// 0x803EE2F4 | 184 bytes
void AptActionInterpreter::getName(AptCIH *, EAStringC &) { }

// 0x803EE3AC | 628 bytes
void AptActionInterpreter::_doCloneSprite(AptCIH *, AptValue *, AptValue *, AptValue *, int, AptValue *) { }

// 0x803EE620 | 1092 bytes
void AptActionInterpreter::getVariable(AptValue *, AptValue *, EAStringC *, int, int, int) { }

// 0x803EEA64 | 220 bytes
void AptActionInterpreter::valueToObject(AptValue *, AptValue *, AptValue *, AptValue **) { }

// 0x803EEB40 | 1752 bytes
void AptActionInterpreter::callFunction(AptValue *, AptValue *, int) { }

// 0x803EF258 | 212 bytes
void AptActionInterpreter::CleanupAfterExecution(char *, void *) { }

// 0x803EF400 | 4744 bytes
void AptActionInterpreter::_createObject(AptValue *, AptValue *, EAStringC *, int, bool) { }

// 0x803F0688 | 760 bytes
void AptActionInterpreter::_doEnumerate(AptValue *, AptValue *) { }

// 0x803F0BA0 | 1008 bytes
void AptActionInterpreter::runStream(unsigned char *, AptCIH *, int, AptCharacterInst *) { }

// 0x803F12C4 | 324 bytes
void AptActionInterpreter::urlDecode(char *, EAStringC &, EAStringC &) { }

// 0x803F1408 | 76 bytes
void AptActionInterpreter::isFSCommand(char *) { }

// 0x803F1454 | 80 bytes
void AptActionInterpreter::doFSCommand(char *, char *) { }

// 0x803F1694 | 688 bytes
void AptActionInterpreter::_FunctionAptActionAdd(AptActionInterpreter *, int *) { }

// 0x803F1944 | 688 bytes
void AptActionInterpreter::_FunctionAptActionSubtract(AptActionInterpreter *, int *) { }

// 0x803F1BF4 | 688 bytes
void AptActionInterpreter::_FunctionAptActionMultiply(AptActionInterpreter *, int *) { }

// 0x803F1EA4 | 496 bytes
void AptActionInterpreter::_FunctionAptActionDivide(AptActionInterpreter *, int *) { }

// 0x803F2094 | 636 bytes
void AptActionInterpreter::_FunctionAptActionEquals(AptActionInterpreter *, int *) { }

// 0x803F2310 | 620 bytes
void AptActionInterpreter::_FunctionAptActionLessThan(AptActionInterpreter *, int *) { }

// 0x803F257C | 660 bytes
void AptActionInterpreter::_FunctionAptActionAnd(AptActionInterpreter *, int *) { }

// 0x803F2810 | 656 bytes
void AptActionInterpreter::_FunctionAptActionOr(AptActionInterpreter *, int *) { }

// 0x803F2AA0 | 360 bytes
void AptActionInterpreter::_FunctionAptActionNot(AptActionInterpreter *, int *) { }

// 0x803F2C08 | 860 bytes
void AptActionInterpreter::_FunctionAptActionStringEquals(AptActionInterpreter *, int *) { }

// 0x803F2F64 | 456 bytes
void AptActionInterpreter::_FunctionAptActionStringLength(AptActionInterpreter *, int *) { }

// 0x803F312C | 864 bytes
void AptActionInterpreter::_FunctionAptActionSubString(AptActionInterpreter *, int *) { }

// 0x803F3530 | 404 bytes
void AptActionInterpreter::_FunctionAptActionToInteger(AptActionInterpreter *, int *) { }

// 0x803F36C4 | 344 bytes
void AptActionInterpreter::_FunctionAptActionGetVariable(AptActionInterpreter *, int *) { }

// 0x803F381C | 332 bytes
void AptActionInterpreter::_FunctionAptActionSetVariable(AptActionInterpreter *, int *) { }

// 0x803F3968 | 380 bytes
void AptActionInterpreter::_FunctionAptActionSetTarget2(AptActionInterpreter *, int *) { }

// 0x803F3AE4 | 508 bytes
void AptActionInterpreter::_FunctionAptActionStringAdd(AptActionInterpreter *, int *) { }

// 0x803F3CE0 | 532 bytes
void AptActionInterpreter::_FunctionAptActionGetProperty(AptActionInterpreter *, int *) { }

// 0x803F3EF4 | 296 bytes
void AptActionInterpreter::_FunctionAptActionSetProperty(AptActionInterpreter *, int *) { }

// 0x803F41F8 | 592 bytes
void AptActionInterpreter::_FunctionAptActionTrace(AptActionInterpreter *, int *) { }

// 0x803F4448 | 832 bytes
void AptActionInterpreter::_FunctionAptActionStartDragMovie(AptActionInterpreter *, int *) { }

// 0x803F47F0 | 400 bytes
void AptActionInterpreter::_FunctionAptActionRandom(AptActionInterpreter *, int *) { }

// 0x803F4988 | 640 bytes
void AptActionInterpreter::_FunctionAptActionAsciiToChar(AptActionInterpreter *, int *) { }

// 0x803F4D10 | 548 bytes
void AptActionInterpreter::_FunctionAptActionDelete(AptActionInterpreter *, int *) { }

// 0x803F4F34 | 476 bytes
void AptActionInterpreter::_FunctionAptActionDelete2(AptActionInterpreter *, int *) { }

// 0x803F5110 | 316 bytes
void AptActionInterpreter::_FunctionAptActionDefineLocal(AptActionInterpreter *, int *) { }

// 0x803F524C | 576 bytes
void AptActionInterpreter::_FunctionAptActionCallFunction(AptActionInterpreter *, int *) { }

// 0x803F5498 | 504 bytes
void AptActionInterpreter::_FunctionAptActionModulo(AptActionInterpreter *, int *) { }

// 0x803F5690 | 496 bytes
void AptActionInterpreter::_FunctionAptActionNewObject(AptActionInterpreter *, int *) { }

// 0x803F5880 | 372 bytes
void AptActionInterpreter::_FunctionAptActionDefineLocal2(AptActionInterpreter *, int *) { }

// 0x803F59F4 | 428 bytes
void AptActionInterpreter::_FunctionAptActionInitArray(AptActionInterpreter *, int *) { }

// 0x803F5BA0 | 788 bytes
void AptActionInterpreter::_FunctionAptActionInitObject(AptActionInterpreter *, int *) { }

// 0x803F5EB4 | 1016 bytes
void AptActionInterpreter::_FunctionAptActionTypeOf(AptActionInterpreter *, int *) { }

// 0x803F62AC | 856 bytes
void AptActionInterpreter::_FunctionAptActionTargetPath(AptActionInterpreter *, int *) { }

// 0x803F662C | 1972 bytes
void AptActionInterpreter::_FunctionAptActionAdd2(AptActionInterpreter *, int *) { }

// 0x803F6DE0 | 2868 bytes
void AptActionInterpreter::_FunctionAptActionLessThan2(AptActionInterpreter *, int *) { }

// 0x803F7914 | 4572 bytes
void AptActionInterpreter::_FunctionAptActionEquals2(AptActionInterpreter *, int *) { }

// 0x803F8AF0 | 1816 bytes
void AptActionInterpreter::_FunctionAptActionToNumber(AptActionInterpreter *, int *) { }

// 0x803F9208 | 924 bytes
void AptActionInterpreter::_FunctionAptActionToString(AptActionInterpreter *, int *) { }

// 0x803F967C | 1060 bytes
void AptActionInterpreter::_FunctionAptActionGetMember(AptActionInterpreter *, int *) { }

// 0x803F9AA0 | 872 bytes
void AptActionInterpreter::_FunctionAptActionSetMember(AptActionInterpreter *, int *) { }

// 0x803F9E08 | 604 bytes
void AptActionInterpreter::_FunctionAptActionIncrement(AptActionInterpreter *, int *) { }

// 0x803FA064 | 604 bytes
void AptActionInterpreter::_FunctionAptActionDecrement(AptActionInterpreter *, int *) { }

// 0x803FA2C0 | 2868 bytes
void AptActionInterpreter::_FunctionAptActionCallMethod(AptActionInterpreter *, int *) { }

// 0x803FADF4 | 620 bytes
void AptActionInterpreter::_FunctionAptActionNewMethod(AptActionInterpreter *, int *) { }

// 0x803FB088 | 460 bytes
void AptActionInterpreter::_FunctionAptActionBitAnd(AptActionInterpreter *, int *) { }

// 0x803FB254 | 460 bytes
void AptActionInterpreter::_FunctionAptActionBitOr(AptActionInterpreter *, int *) { }

// 0x803FB420 | 460 bytes
void AptActionInterpreter::_FunctionAptActionBitXor(AptActionInterpreter *, int *) { }

// 0x803FB5EC | 460 bytes
void AptActionInterpreter::_FunctionAptActionBitLShift(AptActionInterpreter *, int *) { }

// 0x803FB7B8 | 460 bytes
void AptActionInterpreter::_FunctionAptActionBitRShift(AptActionInterpreter *, int *) { }

// 0x803FB988 | 1412 bytes
void AptActionInterpreter::_FunctionAptActionStrictEquals(AptActionInterpreter *, int *) { }

// 0x803FBF0C | 924 bytes
void AptActionInterpreter::_FunctionAptActionGreater(AptActionInterpreter *, int *) { }

// 0x803FC390 | 416 bytes
void AptActionInterpreter::_FunctionAptActionGetUrl(AptActionInterpreter *, int *) { }

// 0x803FC5A8 | 372 bytes
void AptActionInterpreter::_FunctionAptActionSetTarget(AptActionInterpreter *, int *) { }

// 0x803FC800 | 276 bytes
void AptActionInterpreter::_FunctionAptActionWith(AptActionInterpreter *, int *) { }

// 0x803FC914 | 264 bytes
void AptActionInterpreter::_FunctionAptActionPush(AptActionInterpreter *, int *) { }

// 0x803FCA1C | 1160 bytes
void AptActionInterpreter::_FunctionAptActionGetUrl2(AptActionInterpreter *, int *) { }

// 0x803FCEA4 | 428 bytes
void AptActionInterpreter::_FunctionAptActionDefineFunction(AptActionInterpreter *, int *) { }

// 0x803FD050 | 308 bytes
void AptActionInterpreter::_FunctionAptActionDefineFunction2(AptActionInterpreter *, int *) { }

// 0x803FD268 | 424 bytes
void AptActionInterpreter::_FunctionAptActionCallFrame(AptActionInterpreter *, int *) { }

// 0x803FD410 | 708 bytes
void AptActionInterpreter::_FunctionAptActionGotoFrame2(AptActionInterpreter *, int *) { }

// 0x803FD734 | 324 bytes
void AptActionInterpreter::_FunctionAptActionPushThis(AptActionInterpreter *, int *) { }

// 0x803FD878 | 324 bytes
void AptActionInterpreter::_FunctionAptActionPushGlobal(AptActionInterpreter *, int *) { }

// 0x803FE160 | 268 bytes
void AptActionInterpreter::_FunctionAptActionPushZeroSetVar(AptActionInterpreter *, int *) { }

// 0x803FE26C | 392 bytes
void AptActionInterpreter::_FunctionAptActionPushString(AptActionInterpreter *, int *) { }

// 0x803FE500 | 284 bytes
void AptActionInterpreter::_FunctionAptActionPushStringGetVar(AptActionInterpreter *, int *) { }

// 0x803FE61C | 408 bytes
void AptActionInterpreter::_FunctionAptActionPushStringGetMember(AptActionInterpreter *, int *) { }

// 0x803FE7B4 | 408 bytes
void AptActionInterpreter::_FunctionAptActionPushStringSetVar(AptActionInterpreter *, int *) { }

// 0x803FE94C | 408 bytes
void AptActionInterpreter::_FunctionAptActionPushStringSetMember(AptActionInterpreter *, int *) { }

// 0x803FEC3C | 264 bytes
void AptActionInterpreter::_FunctionAptActionDictCallFuncPop(AptActionInterpreter *, int *) { }

// 0x803FEE08 | 264 bytes
void AptActionInterpreter::_FunctionAptActionDictCallMethodPop(AptActionInterpreter *, int *) { }

// 0x803FEFD4 | 296 bytes
void AptActionInterpreter::_FunctionAptActionPushFloat(AptActionInterpreter *, int *) { }

// 0x803FF0FC | 268 bytes
void AptActionInterpreter::_FunctionAptActionPushByte(AptActionInterpreter *, int *) { }

// 0x803FF208 | 280 bytes
void AptActionInterpreter::_FunctionAptActionPushWord(AptActionInterpreter *, int *) { }

// 0x803FF320 | 296 bytes
void AptActionInterpreter::_FunctionAptActionPushDWord(AptActionInterpreter *, int *) { }

// 0x803FF52C | 1004 bytes
void AptActionInterpreter::_FunctionAptActionExtends(AptActionInterpreter *, int *) { }

// 0x803FF918 | 372 bytes
void AptActionInterpreter::isObjectOfType(AptValue *, AptValue *) { }

// 0x803FFA8C | 560 bytes
void AptActionInterpreter::_FunctionAptActionInstanceOf(AptActionInterpreter *, int *) { }

// 0x803FFCBC | 568 bytes
void AptActionInterpreter::_FunctionAptActionCastOp(AptActionInterpreter *, int *) { }

// 0x803FFEF4 | 932 bytes
void AptActionInterpreter::_FunctionAptActionImplementsOp(AptActionInterpreter *, int *) { }

// 0x80400298 | 844 bytes
void AptActionInterpreter::_FunctionAptActionTry(AptActionInterpreter *, int *) { }

// 0x804006A4 | 184 bytes
AptActionInterpreter::~AptActionInterpreter(void) { }
