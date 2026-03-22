#if 0 // SKIP
// ea_stubs.cpp - Stub implementations for Ea
// Auto-generated from symbols.json - 108 functions
// These are stub implementations to register progress.
// Each function needs proper decompilation to match the original binary.

#include "types.h"
#include "stub_classes.h"

// 0x803EAC38 | 1336 bytes
void EA::String::BasicString<StringAsVectorEncoding<AptFileSavedInputState>, StringAsVectorPolicy>::Insert<AptFileSavedInputState *>(AptFileSavedInputState * &, AptFileSavedInputState * &, int<StringAsVectorEncoding<AptFileSavedInputState>, StringAsVectorPolicy>::DbgIterator &) { }

// 0x804209D8 | 1644 bytes
void EA::String::BasicString<StringAsVectorEncoding<AptSharedPtr<AptFile> >, StringAsVectorPolicy>::Insert<AptSharedPtr<AptFile> *>(AptSharedPtr<AptFile> * &, AptSharedPtr<AptFile> * &, int<StringAsVectorEncoding<AptSharedPtr<AptFile> >, StringAsVectorPolicy>::DbgIterator &) { }

// 0x80473B44 | 52 bytes
void EA::UnitTest::Report(char *) { }

// 0x80473B78 | 236 bytes
void EA::UnitTest::ReportFormatted(void (*)(char *), char *,...) { }

// 0x80473C64 | 144 bytes
void EA::UnitTest::Verify(bool, char *, int *, void (*)(char *)) { }

// 0x80473CF4 | 96 bytes
EA::UnitTest::Test::Test(char *, int *, void (*)(char *)) { }

// 0x80473D54 | 112 bytes
EA::UnitTest::Test::~Test(void) { }

// 0x80473DC4 | 8 bytes
void EA::UnitTest::Test::Init(void) { }

// 0x80473DCC | 24 bytes
void EA::UnitTest::Test::Shutdown(void) { }

// 0x80473DE4 | 8 bytes
void EA::UnitTest::Test::GetParentSuite(void) const { }

// 0x80473DEC | 8 bytes
void EA::UnitTest::Test::SetParentSuite(int *) { }

// 0x80473DF4 | 48 bytes
void EA::UnitTest::Test::GetReportFunction(void) { }

// 0x80473E24 | 532 bytes
void EA::UnitTest::Test::GetName(basic_string<char, char_traits<char>, allocator<char> > &) { }

// 0x804740A0 | 4 bytes
void EA::UnitTest::Test::Abort(void) { }

// 0x804740A4 | 284 bytes
void EA::UnitTest::Test::Verify(bool, char *, void (*)(char *)) { }

// 0x804741C0 | 244 bytes
void EA::UnitTest::Test::VerifyFormatted(bool, char *,...) { }

// 0x804742B4 | 8 bytes
void EA::UnitTest::Test::SetErrorCount(unsigned int) { }

// 0x804742BC | 8 bytes
void EA::UnitTest::Test::ForceReport(void) const { }

// 0x804742C4 | 8 bytes
void EA::UnitTest::Test::SetForceReport(bool) { }

// 0x804742CC | 128 bytes
void EA::UnitTest::Test::TestResult(void) const { }

// 0x8047434C | 136 bytes
void EA::UnitTest::Test::WriteReport(void) { }

// 0x804743D4 | 76 bytes
EA::UnitTest::TestFunction::TestFunction(char *, int (*)(void)) { }

// 0x804744A0 | 116 bytes
EA::UnitTest::TestSuite::TestSuite(char *) { }

// 0x80474514 | 256 bytes
EA::UnitTest::TestSuite::~TestSuite(void) { }

// 0x80474614 | 132 bytes
void EA::UnitTest::TestSuite::Shutdown(void) { }

// 0x804747BC | 312 bytes
void EA::UnitTest::TestSuite::RunTest(char *) { }

// 0x804748F4 | 1116 bytes
void EA::UnitTest::TestSuite::AddTest(int *, bool) { }

// 0x80474DB4 | 460 bytes
void EA::UnitTest::TestSuite::RemoveTest(int *, bool) { }

// 0x804750C0 | 140 bytes
void EA::UnitTest::TestSuite::EnumerateTests(int **, unsigned int) { }

// 0x8047514C | 472 bytes
void EA::UnitTest::TestSuite::WriteReport(void) { }

// 0x80475774 | 32 bytes
EA::UnitTest::TestFunction::~TestFunction(void) { }

// 0x804758D0 | 128 bytes
void EA::Allocator::MemoryFillCheck(unsigned char *, unsigned int, unsigned char) { }

// 0x80475950 | 448 bytes
EA::Allocator::GeneralAllocator::GeneralAllocator(void *, unsigned int, bool, bool, unsigned int (*)(int *, void *, unsigned int, void *), void *) { }

// 0x80475B10 | 64 bytes
EA::Allocator::GeneralAllocator::~GeneralAllocator(void) { }

// 0x80475B50 | 424 bytes
void EA::Allocator::GeneralAllocator::Init(void *, unsigned int, bool, bool, unsigned int (*)(int *, void *, unsigned int, void *), void *) { }

// 0x80475CF8 | 216 bytes
void EA::Allocator::GeneralAllocator::Shutdown(void) { }

// 0x80475DD0 | 652 bytes
void EA::Allocator::GeneralAllocator::SetOption(int, int) { }

// 0x8047605C | 12 bytes
void EA::Allocator::GeneralAllocator::SetMallocFailureFunction(bool (*)(int *, unsigned int, unsigned int, void *), void *) { }

// 0x80476068 | 12 bytes
void EA::Allocator::GeneralAllocator::SetHookFuncton(void (*)(int *, void *), void *) { }

// 0x80476074 | 12 bytes
void EA::Allocator::GeneralAllocator::SetTraceFunction(void (*)(char *, void *), void *) { }

// 0x80476080 | 12 bytes
void EA::Allocator::GeneralAllocator::SetTraceFieldDelimiters(unsigned char, unsigned char) { }

// 0x8047608C | 8 bytes
void EA::Allocator::GeneralAllocator::GetPageSize(void) { }

// 0x80476094 | 128 bytes
void EA::Allocator::GeneralAllocator::FindPriorChunk(int *) const { }

// 0x80476114 | 104 bytes
void EA::Allocator::GeneralAllocator::GetLargeBinIndexFromChunkSize(unsigned int) { }

// 0x8047617C | 212 bytes
void EA::Allocator::GeneralAllocator::FindAndSetNewTopChunk(void) { }

// 0x80476250 | 92 bytes
void EA::Allocator::GeneralAllocator::GetChunkIsFenceChunk(int *) const { }

// 0x804762AC | 392 bytes
void EA::Allocator::GeneralAllocator::FindChunkBin(int *) const { }

// 0x80476434 | 4 bytes
void EA::Allocator::GeneralAllocator::AdjustHighFence(void) { }

// 0x80476438 | 60 bytes
void EA::Allocator::GeneralAllocator::SetNewTopChunk(int *, bool) { }

// 0x80476474 | 24 bytes
void EA::Allocator::GeneralAllocator::AdjustTopChunk(int *, unsigned int) { }

// 0x8047648C | 8 bytes
void EA::Allocator::GeneralAllocator::ChunkMatchesLowHigh(int, int *, unsigned int) const { }

// 0x80476494 | 72 bytes
void EA::Allocator::GeneralAllocator::ChunkMatchesBlockType(int *, int) { }

// 0x804764DC | 32 bytes
void EA::Allocator::GeneralAllocator::SetFencepostAfterChunk(int *, unsigned int) { }

// 0x804764FC | 68 bytes
void EA::Allocator::GeneralAllocator::AddDoubleFencepost(int *, int) { }

// 0x80476540 | 68 bytes
void EA::Allocator::GeneralAllocator::MakeChunkFromCore(void *, unsigned int, int) { }

// 0x80476584 | 36 bytes
void EA::Allocator::GeneralAllocator::GetBlockInfoForCoreBlock(int *, int *) const { }

// 0x804765A8 | 224 bytes
void EA::Allocator::GeneralAllocator::GetBlockInfoForChunk(int *, int *) const { }

// 0x80476688 | 548 bytes
void EA::Allocator::GeneralAllocator::CheckChunk(int *) { }

// 0x804768AC | 508 bytes
void EA::Allocator::GeneralAllocator::CheckFreeChunk(int *) { }

// 0x80476AA8 | 292 bytes
void EA::Allocator::GeneralAllocator::CheckUsedChunk(int *) { }

// 0x80476BCC | 232 bytes
void EA::Allocator::GeneralAllocator::CheckRemallocedChunk(int *, unsigned int) { }

// 0x80476CB4 | 208 bytes
void EA::Allocator::GeneralAllocator::CheckMallocedChunk(int *, unsigned int, bool, bool) { }

// 0x80476D84 | 240 bytes
void EA::Allocator::GeneralAllocator::CheckMMappedChunk(int *) { }

// 0x80476E74 | 1628 bytes
void EA::Allocator::GeneralAllocator::CheckState(int) { }

// 0x804774D0 | 304 bytes
void EA::Allocator::GeneralAllocator::GetDataPreview(void *, unsigned int, char *, wchar_t *, unsigned int) const { }

// 0x80477600 | 32 bytes
void EA::Allocator::GeneralAllocator::AssertionFailureFunctionDefault(char *, void *) { }

// 0x80477620 | 12 bytes
void EA::Allocator::GeneralAllocator::SetAssertionFailureFunction(void (*)(char *, void *), void *) { }

// 0x8047762C | 60 bytes
void EA::Allocator::GeneralAllocator::AssertionFailure(char *) const { }

// 0x80477668 | 48 bytes
void EA::Allocator::GeneralAllocator::TraceFunctionDefault(char *, void *) { }

// 0x80477698 | 352 bytes
void EA::Allocator::GeneralAllocator::DescribeChunk(int *, char *, unsigned int) { }

// 0x804777F8 | 36 bytes
void EA::Allocator::GeneralAllocator::DescribeData(void *, char *, unsigned int) { }

// 0x8047781C | 288 bytes
void EA::Allocator::GeneralAllocator::TraceAllocatedMemory(void (*)(char *, void *), void *, void *, unsigned int) { }

// 0x8047793C | 184 bytes
void EA::Allocator::GeneralAllocator::ReportHeap(bool (*)(int *, void *), void *, int, bool, void *, unsigned int) { }

// 0x804779F4 | 108 bytes
void EA::Allocator::GeneralAllocator::ReportBegin(void *, int, bool, void *, unsigned int) { }

// 0x80477A60 | 480 bytes
void EA::Allocator::GeneralAllocator::ReportNext(void *, int) { }

// 0x80477C40 | 80 bytes
void EA::Allocator::GeneralAllocator::ReportEnd(void *) { }

// 0x80477C90 | 120 bytes
EA::Allocator::GeneralAllocator::Snapshot::Snapshot(unsigned int, int) { }

// 0x80477D08 | 832 bytes
void EA::Allocator::GeneralAllocator::TakeSnapshot(int, bool, void *, unsigned int) { }

// 0x80478048 | 64 bytes
void EA::Allocator::GeneralAllocator::FreeSnapshot(void *) { }

// 0x80478088 | 284 bytes
void EA::Allocator::GeneralAllocator::ValidateAddress(void *, bool) { }

// 0x804781A4 | 84 bytes
void EA::Allocator::GeneralAllocator::ValidateHeap(int) { }

// 0x804781F8 | 36 bytes
void EA::Allocator::GeneralAllocator::SetAutoHeapValidation(int, unsigned int) { }

// 0x8047821C | 108 bytes
void EA::Allocator::GeneralAllocator::Malloc(unsigned int, int) { }

// 0x80478288 | 1420 bytes
void EA::Allocator::GeneralAllocator::MallocInternal(unsigned int, int) { }

// 0x80478814 | 92 bytes
void EA::Allocator::GeneralAllocator::Free(void *) { }

// 0x80478870 | 416 bytes
void EA::Allocator::GeneralAllocator::FreeInternal(void *) { }

// 0x80478A10 | 124 bytes
void EA::Allocator::GeneralAllocator::MallocAligned(unsigned int, unsigned int, unsigned int, int) { }

// 0x80478A8C | 632 bytes
void EA::Allocator::GeneralAllocator::MallocAlignedInternal(unsigned int, unsigned int, unsigned int, int) { }

// 0x80478D04 | 116 bytes
void EA::Allocator::GeneralAllocator::Realloc(void *, unsigned int, int) { }

// 0x80478D78 | 716 bytes
void EA::Allocator::GeneralAllocator::ReallocInternal(void *, unsigned int, int) { }

// 0x80479044 | 116 bytes
void EA::Allocator::GeneralAllocator::Calloc(unsigned int, unsigned int, int) { }

// 0x804790B8 | 272 bytes
void EA::Allocator::GeneralAllocator::CallocInternal(unsigned int, unsigned int, int) { }

// 0x804791C8 | 128 bytes
void EA::Allocator::GeneralAllocator::MallocMultiple(unsigned int, unsigned int, void **, int) { }

// 0x804792C8 | 416 bytes
void EA::Allocator::GeneralAllocator::MallocMultipleInternal(unsigned int, unsigned int, unsigned int *, void **, int) { }

// 0x80479468 | 392 bytes
void EA::Allocator::GeneralAllocator::ClearFastBins(void) { }

// 0x804795F0 | 64 bytes
void EA::Allocator::GeneralAllocator::GetUsableSize(void *) const { }

// 0x80479630 | 52 bytes
void EA::Allocator::GeneralAllocator::GetTotalCoreSize(void) const { }

// 0x80479664 | 12 bytes
void EA::Allocator::GeneralAllocator::GetBlockSize(void *) const { }

// 0x80479670 | 28 bytes
void EA::Allocator::GeneralAllocator::LinkCoreBlock(int *, int *) { }

// 0x8047968C | 28 bytes
void EA::Allocator::GeneralAllocator::UnlinkCoreBlock(int *) { }

// 0x804796A8 | 64 bytes
void EA::Allocator::GeneralAllocator::FindCoreBlockForAddress(void *) const { }

// 0x804796E8 | 364 bytes
void EA::Allocator::GeneralAllocator::AddCore(void *, unsigned int, bool, bool, unsigned int (*)(int *, void *, unsigned int, void *), void *) { }

// 0x80479854 | 200 bytes
void EA::Allocator::GeneralAllocator::ExtendCoreInternal(unsigned int) { }

// 0x8047991C | 272 bytes
void EA::Allocator::GeneralAllocator::AddCoreInternal(unsigned int) { }

// 0x80479A2C | 80 bytes
void EA::Allocator::GeneralAllocator::FreeCore(int *) { }

// 0x80479A7C | 316 bytes
void EA::Allocator::GeneralAllocator::TrimCore(unsigned int) { }

// 0x80479BB8 | 72 bytes
void EA::Allocator::GeneralAllocator::MMapAlloc(unsigned int, unsigned int *) { }

// 0x80479C00 | 36 bytes
void EA::Allocator::GeneralAllocator::MMapFree(void *, unsigned int) { }
#endif
