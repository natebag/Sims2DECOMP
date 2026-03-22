// eastringc_stubs.cpp - Stub implementations for Eastringc
// Auto-generated from symbols.json - 46 functions
// These are stub implementations to register progress.
// Each function needs proper decompilation to match the original binary.

#include "types.h"

// 0x803EB1F8 | 104 bytes
EAStringC::~EAStringC(void) { }

// 0x803EB260 | 116 bytes
void EAStringC::operator=(EAStringC &) { }

// 0x8042DB10 | 108 bytes
void EAStringC::Clear(void) { }

// 0x804338A0 | 12 bytes
void EAStringC::operator char *(void) const { }

// 0x80435094 | 48 bytes
void EAStringC::Equal(char *) const { }

// 0x8043B478 | 216 bytes
void EAStringC::operator+=(EAStringC &) { }

// 0x8043B87C | 128 bytes
void EAStringC::Duplicate(EAStringC &) { }

// 0x8043B8FC | 64 bytes
void EAStringC::ReserveSize(unsigned int) { }

// 0x8043B93C | 24 bytes
void EAStringC::IsEnoughSize(unsigned int) const { }

// 0x8043B954 | 176 bytes
void EAStringC::Append(char *, unsigned int) { }

// 0x8043BA04 | 292 bytes
void EAStringC::AppendFormat(char *,...) { }

// 0x8043BB28 | 148 bytes
void EAStringC::Format(char *,...) { }

// 0x8043BBBC | 160 bytes
void EAStringC::vsFormat(char *, __va_list_tag *) { }

// 0x8043BC5C | 108 bytes
void EAStringC::Find(char *, int) const { }

// 0x8043BD34 | 8 bytes
void EAStringC::FindOneOf(char *) const { }

// 0x8043BD3C | 8 bytes
void EAStringC::ReverseFind(char) const { }

// 0x8043BD44 | 336 bytes
void EAStringC::Delete(int, int) { }

// 0x8043BE94 | 72 bytes
void EAStringC::Remove(char) { }

// 0x8043BEDC | 8 bytes
void EAStringC::Insert(int, char *) { }

// 0x8043BEEC | 464 bytes
void EAStringC::Replace(char *, char *) { }

// 0x8043C110 | 224 bytes
void EAStringC::Left(int) const { }

// 0x8043C1F0 | 220 bytes
void EAStringC::Right(int) const { }

// 0x8043C2CC | 220 bytes
void EAStringC::Mid(int) const { }

// 0x8043C48C | 140 bytes
void EAStringC::MakeLower(void) { }

// 0x8043C518 | 140 bytes
void EAStringC::MakeUpper(void) { }

// 0x8043C5A4 | 160 bytes
void EAStringC::MakeReverse(void) { }

// 0x8043C644 | 368 bytes
void EAStringC::TrimLeft(char *) { }

// 0x8043C7B4 | 372 bytes
void EAStringC::TrimRight(char *) { }

// 0x8043C928 | 60 bytes
void EAStringC::Trim(char *) { }

// 0x8043C964 | 100 bytes
void EAStringC::StartWith(char *) const { }

// 0x8043C9C8 | 116 bytes
void EAStringC::EndWith(char *) const { }

// 0x8043CA3C | 232 bytes
void EAStringC::StartWithRemove(char *) { }

// 0x8043CB24 | 248 bytes
void EAStringC::EndWithRemove(char *) { }

// 0x8043CC1C | 100 bytes
void EAStringC::UTF8_GetBuffer(int) { }

// 0x8043CC80 | 256 bytes
void EAStringC::UTF8_CharAt(int) const { }

// 0x8043CD80 | 84 bytes
void EAStringC::UTF8_Size(void) const { }

// 0x8043CDD4 | 176 bytes
void EAStringC::UTF8_Mid(int) const { }

// 0x8043CFA8 | 260 bytes
void EAStringC::UTF8_Append(char *, int) { }

// 0x8043D0AC | 260 bytes
void EAStringC::UTF8_Find(char *, int) const { }

// 0x8043D1B0 | 448 bytes
void EAStringC::UTF8_MakeLower(void) { }

// 0x8043D370 | 448 bytes
void EAStringC::UTF8_MakeUpper(void) { }

// 0x8043D530 | 448 bytes
void EAStringC::UTF8_Initialize(int) { }

// 0x8043D6F0 | 356 bytes
void EAStringC::ChangeBuffer(unsigned int, unsigned int, unsigned int, EAStringC::CBPushZero, unsigned int) { }

// 0x8043D854 | 184 bytes
void EAStringC::InitFromBuffer(char *) { }

// 0x8043D90C | 112 bytes
void EAStringC::CalculateHashValue(void) const { }

// 0x8043D97C | 164 bytes
void EAStringC::UTF8_ReadCharacter(char *, int *) { }
