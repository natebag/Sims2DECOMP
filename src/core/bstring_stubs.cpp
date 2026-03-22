// bstring_stubs.cpp - Stub implementations for Bstring
// Auto-generated from symbols.json - 42 functions
// These are stub implementations to register progress.
// Each function needs proper decompilation to match the original binary.

#include "types.h"
#include "stub_classes.h"

// 0x8011BF04 | 96 bytes
void BString::delete_ref(void) { }

// 0x8011BF64 | 12 bytes
void BString::ref_count(void) const { }

// 0x8011BF70 | 68 bytes
void BString::data(void) const { }

// 0x8011BFB4 | 12 bytes
void BString::point(void) { }

// 0x8011BFC0 | 12 bytes
void BString::len(void) { }

// 0x8011BFCC | 76 bytes
void BString::get_at(unsigned int) const { }

// 0x8011C018 | 76 bytes
void* BString::operator[](unsigned int) const { }

// 0x8011CA28 | 8 bytes
void BString::eos(void) { }

// 0x8011CA30 | 216 bytes
void BString::assign_str(char *, unsigned int) { }

// 0x8011CB08 | 304 bytes
void BString::append_str(char *, unsigned int) { }

// 0x8011CC38 | 484 bytes
void BString::insert_str(unsigned int, char *, unsigned int) { }

// 0x8011CE1C | 612 bytes
void BString::replace_str(unsigned int, unsigned int, char *, unsigned int) { }

// 0x8011D080 | 184 bytes
void BString::compare_str(unsigned int, char *, unsigned int, unsigned int) const { }

// 0x8011D138 | 256 bytes
void BString::find_str(char *, unsigned int, unsigned int) const { }

// 0x8011D238 | 288 bytes
void BString::rfind_str(char *, unsigned int, unsigned int) const { }

// 0x8011D358 | 184 bytes
void BString::find_first_of_str(char *, unsigned int, unsigned int) const { }

// 0x8011D410 | 212 bytes
void BString::find_last_of_str(char *, unsigned int, unsigned int) const { }

// 0x8011D4E4 | 152 bytes
void BString::find_first_not_of_str(char *, unsigned int, unsigned int) const { }

// 0x8011D57C | 204 bytes
void BString::find_last_not_of_str(char *, unsigned int, unsigned int) const { }

// 0x8011D648 | 32 bytes
BString::BString(void) { }

// 0x8011D8E4 | 64 bytes
BString::~BString(void) { }

// 0x8011D924 | 152 bytes
void BString::operator=(BString &) { }

// 0x8011DABC | 84 bytes
void BString::operator+=(BString &) { }

// 0x8011DC80 | 140 bytes
void BString::append(BString &, unsigned int, unsigned int) { }

// 0x8011DED8 | 196 bytes
void BString::assign(BString &, unsigned int, unsigned int) { }

// 0x8011E104 | 140 bytes
void BString::insert(unsigned int, BString &, unsigned int, unsigned int) { }

// 0x8011E430 | 424 bytes
void BString::erase(unsigned int, unsigned int) { }

// 0x8011E5D8 | 196 bytes
void BString::replace(unsigned int, unsigned int, BString &, unsigned int, unsigned int) { }

// 0x8011EA98 | 256 bytes
void BString::put_at(unsigned int, char) { }

// 0x8011EC48 | 48 bytes
void BString::c_str(void) const { }

// 0x8011EDE8 | 152 bytes
void BString::reserve(unsigned int) { }

// 0x8011EE80 | 144 bytes
void BString::copy(char *, unsigned int, unsigned int) const { }

// 0x8011EF10 | 88 bytes
void BString::find(BString &, unsigned int) const { }

// 0x8011F068 | 88 bytes
void BString::rfind(BString &, unsigned int) const { }

// 0x8011F210 | 88 bytes
void BString::find_first_of(BString &, unsigned int) const { }

// 0x8011F300 | 88 bytes
void BString::find_last_of(BString &, unsigned int) const { }

// 0x8011F3F0 | 88 bytes
void BString::find_first_not_of(BString &, unsigned int) const { }

// 0x8011F538 | 88 bytes
void BString::find_last_not_of(BString &, unsigned int) const { }

// 0x8011F6C0 | 168 bytes
void BString::substr(unsigned int, unsigned int) const { }

// 0x8011F768 | 132 bytes
void BString::compare(BString &, unsigned int, unsigned int) const { }

// 0x8011FE9C | 12 bytes
void BString::length(void) const { }

// 0x8011FEB4 | 124 bytes
void BString::assignDebug(wchar_t *) { }
