// aptviewer_stubs.cpp - Stub implementations for Aptviewer
// Auto-generated from symbols.json - 31 functions
// These are stub implementations to register progress.
// Each function needs proper decompilation to match the original binary.

#include "types.h"
#include "stub_classes.h"

// 0x80015798 | 240 bytes
AptViewer::AptViewer(void) { }

// 0x80015888 | 120 bytes
AptViewer::~AptViewer(void) { }

// 0x80015900 | 60 bytes
void AptViewer::CallFunction(char *, char *, char *, int,...) { }

// 0x8001593C | 284 bytes
void AptViewer::NewCallFunction(char *, char *, char *, int,...) { }

// 0x80015A58 | 476 bytes
void AptViewer::NewCallFunction2(char *, char *, char *, int, char **) { }

// 0x80015C34 | 36 bytes
void AptViewer::Shutdown(void) { }

// 0x80015C58 | 104 bytes
void AptViewer::Init(UIObjectBase *) { }

// 0x80015CC0 | 4 bytes
void AptViewer::Update(void) { }

// 0x80015CC4 | 476 bytes
void AptViewer::UpdateAll(void) { }

// 0x80015EA0 | 1192 bytes
void AptViewer::Draw(ERC *) { }

// 0x80016348 | 148 bytes
void AptViewer::Load(char *, bool) { }

// 0x800163DC | 112 bytes
void AptViewer::LoadActionScript(char *, bool) { }

// 0x8001644C | 120 bytes
void AptViewer::UnLoad(void) { }

// 0x800164C4 | 104 bytes
void AptViewer::ReadController(int, bool, int, bool) { }

// 0x8001652C | 60 bytes
void AptViewer::RepeatClear(int, int) { }

// 0x80016568 | 208 bytes
void AptViewer::RepeatCheck(int, int) { }

// 0x80016638 | 196 bytes
void AptViewer::NewReadController(int, bool, int, bool) { }

// 0x800166FC | 2932 bytes
void AptViewer::OnePlayerReadController(int, int) { }

// 0x80017270 | 448 bytes
void AptViewer::PushAptButtonFilter(int, char *) { }

// 0x80017430 | 504 bytes
void AptViewer::PopAptButtonFilter(int, unsigned int) { }

// 0x80017628 | 320 bytes
void AptViewer::AddCmdToAptButtonFilter(int, unsigned int, ECTRL_CMD) { }

// 0x80017768 | 320 bytes
void AptViewer::RemoveCmdFromAptButtonFilter(int, unsigned int, ECTRL_CMD) { }

// 0x800178A8 | 120 bytes
void AptViewer::GetCurrentAptButtonFilter(int) { }

// 0x80017920 | 172 bytes
void AptViewer::GetPlayersController(int) { }

// 0x800179CC | 36 bytes
void AptViewer::NewSetMessageHandler(UIObjectBase *) { }

// 0x800179F0 | 36 bytes
void AptViewer::NewRemoveMessageHandler(UIObjectBase *) { }

// 0x80017A14 | 8 bytes
void AptViewer::UIOn(void) { }

// 0x80017A1C | 16 bytes
void AptViewer::AllowControllerReading(bool) { }

// 0x80017A2C | 44 bytes
void AptViewer::IsWaitingForPlayerInput(void) { }

// 0x80017A58 | 8 bytes
void AptViewer::IsReadControllerActive(void) { }

// 0x80017A60 | 164 bytes
void AptViewer::casButtonSequencer(void) { }
