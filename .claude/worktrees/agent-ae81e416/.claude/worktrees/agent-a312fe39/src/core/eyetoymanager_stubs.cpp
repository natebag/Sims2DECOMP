// eyetoymanager_stubs.cpp - Stub implementations for Eyetoymanager
// Auto-generated from symbols.json - 23 functions
// These are stub implementations to register progress.
// Each function needs proper decompilation to match the original binary.

#include "types.h"
#include "stub_classes.h"

// 0x8050160C | 72 bytes
void EyeToyManager::Open(int, int, bool) { }

// 0x80501654 | 132 bytes
void EyeToyManager::Close(void) { }

// 0x805016D8 | 8 bytes
void EyeToyManager::IsPhysicallyConnected(int) { }

// 0x805016E0 | 8 bytes
void EyeToyManager::GetPhysicalConnectionCount(void) { }

// 0x805016E8 | 24 bytes
void EyeToyManager::OpenInstance(int, void (*)(char *, int), int, bool, void (*)(int)) { }

// 0x80501700 | 56 bytes
void EyeToyManager::CloseInstance(int) { }

// 0x80501738 | 44 bytes
void EyeToyManager::UpdateAllInstances(float) { }

// 0x80501764 | 52 bytes
void EyeToyManager::UpdateInstance(int, float) { }

// 0x80501798 | 40 bytes
void EyeToyManager::LockOutputBuffer(int) { }

// 0x805017C0 | 40 bytes
void EyeToyManager::ReleaseOutputBuffer(int) { }

// 0x805017E8 | 56 bytes
void EyeToyManager::StartStream(int) { }

// 0x80501820 | 56 bytes
void EyeToyManager::StopStream(int) { }

// 0x80501858 | 40 bytes
void EyeToyManager::ResetStream(int, int) { }

// 0x80501880 | 20 bytes
void EyeToyManager::PauseStreams(void) { }

// 0x80501894 | 16 bytes
void EyeToyManager::ResumeStreams(void) { }

// 0x805018A4 | 68 bytes
void EyeToyManager::GetDimensions(int, int *, int *) { }

// 0x805018E8 | 40 bytes
void EyeToyManager::SetAttributes(int, int, int *) { }

// 0x80501910 | 56 bytes
void EyeToyManager::GetAttributes(int) { }

// 0x80501948 | 12 bytes
void EyeToyManager::ConvertHandleToInstancePtr(int) { }

// 0x80501954 | 4 bytes
void EyeToyManager::ConvertInstanceIndexToHandle(int) { }

// 0x80501958 | 4 bytes
void EyeToyManager::NormalizeTexture(int *) { }

// 0x8050195C | 4 bytes
void EyeToyManager::CleanUpBufferBetaHack(void) { }

// 0x80501960 | 36 bytes
void EyeToyManager::IsInstanceDisconnected(int) { }
