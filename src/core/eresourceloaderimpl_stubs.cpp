// eresourceloaderimpl_stubs.cpp - Stub implementations for Eresourceloaderimpl
// Auto-generated from symbols.json - 41 functions
// These are stub implementations to register progress.
// Each function needs proper decompilation to match the original binary.

#include "types.h"
#include "stub_classes.h"

// 0x804D8534 | 36 bytes
void EResourceLoaderImpl::GetQueueStats(int &, int &, int &, int &) { }

// 0x804D8558 | 36 bytes
void EResourceLoaderImpl::GetQueuedCommandCount(void) { }

// 0x804D857C | 92 bytes
void EResourceLoaderImpl::IsBusy(void) { }

// 0x804D85D8 | 188 bytes
EResourceLoaderImpl::EResourceLoaderImpl(void) { }

// 0x804D8694 | 164 bytes
EResourceLoaderImpl::~EResourceLoaderImpl(void) { }

// 0x804D8738 | 148 bytes
void EResourceLoaderImpl::Shutdown(void) { }

// 0x804D87CC | 72 bytes
void EResourceLoaderImpl::TerminateThread(void) { }

// 0x804D8814 | 36 bytes
void EResourceLoaderImpl::IsCallingThread(void) { }

// 0x804D8838 | 124 bytes
void EResourceLoaderImpl::Init(void) { }

// 0x804D88B4 | 492 bytes
void EResourceLoaderImpl::RefreshResources(void) { }

// 0x804D8AA0 | 252 bytes
void EResourceLoaderImpl::LoadRecentlyBuiltFilesList(void) { }

// 0x804D8BD0 | 4 bytes
void EResourceLoaderImpl::Update(void) { }

// 0x804D8BD4 | 40 bytes
void EResourceLoaderImpl::sendCommand(EResLoadCmd *) { }

// 0x804D8BFC | 464 bytes
void EResourceLoaderImpl::FlushCommandQueue(char *, int) { }

// 0x804D8DCC | 204 bytes
void EResourceLoaderImpl::AddManager(EResourceManager *) { }

// 0x804D8E98 | 232 bytes
void EResourceLoaderImpl::RemoveManager(EResourceManager *) { }

// 0x804D8F80 | 36 bytes
void EResourceLoaderImpl::CollapseDelRef(EResourceManager *, unsigned int) { }

// 0x804D8FA4 | 36 bytes
void EResourceLoaderImpl::IsInQueue(EResourceManager *, unsigned int) { }

// 0x804D8FC8 | 384 bytes
void EResourceLoaderImpl::Load(EResourceManager *, unsigned int, EFile *, unsigned int, unsigned int, bool) { }

// 0x804D9148 | 172 bytes
void EResourceLoaderImpl::Unload(EResourceManager *, unsigned int) { }

// 0x804D91F4 | 328 bytes
void EResourceLoaderImpl::ReadData(EFile *, void *, unsigned int, unsigned int, bool, EResLoadCmdResult *) { }

// 0x804D9464 | 328 bytes
void EResourceLoaderImpl::WriteData(EFile *, void *, unsigned int, unsigned int, bool, EResLoadCmdResult *) { }

// 0x804D95AC | 128 bytes
void EResourceLoaderImpl::FindResourceManager(char *) { }

// 0x804D962C | 96 bytes
void EResourceLoaderImpl::FindResourceManagerInternal(char *) { }

// 0x804D968C | 172 bytes
void EResourceLoaderImpl::OpenFiles(void) { }

// 0x804D9738 | 244 bytes
void EResourceLoaderImpl::CloseArchiveFile(EResourceManager *) { }

// 0x804D982C | 168 bytes
void EResourceLoaderImpl::AddRefDelRefAllResources(void) { }

// 0x804D98D4 | 140 bytes
void EResourceLoaderImpl::PrintLoadedResources(void) { }

// 0x804D99E4 | 136 bytes
void EResourceLoaderImpl::PrintResourceSizes(void) { }

// 0x804D9AF0 | 104 bytes
void EResourceLoaderImpl::FreeUnreferencedResources(void) { }

// 0x804D9C08 | 80 bytes
void EResourceLoaderImpl::GetUnreferencedResourceCount(void) { }

// 0x804D9CE8 | 124 bytes
void EResourceLoaderImpl::deallocateGlobalIndex(void) { }

// 0x804D9D64 | 512 bytes
void EResourceLoaderImpl::allocateGlobalIndex(void) { }

// 0x804D9F64 | 188 bytes
void EResourceLoaderImpl::getIndexPointer(EString &) { }

// 0x804DA020 | 108 bytes
void EResourceLoaderImpl::Main(void) { }

// 0x804DA08C | 672 bytes
void EResourceLoaderImpl::ProcessMessage(unsigned int) { }

// 0x804DA32C | 664 bytes
void EResourceLoaderImpl::DoLoadResource(EResourceManager *, unsigned int, EFile *, unsigned int, unsigned int) { }

// 0x804DAFFC | 8 bytes
void EResourceLoaderImpl::EnableReloads(bool) { }

// 0x804DB004 | 12 bytes
void EResourceLoaderImpl::PauseLoads(void) { }

// 0x804DB010 | 44 bytes
void EResourceLoaderImpl::UnPauseLoads(void) { }

// 0x804DB03C | 8 bytes
void EResourceLoaderImpl::AreLoadsPaused(void) { }
