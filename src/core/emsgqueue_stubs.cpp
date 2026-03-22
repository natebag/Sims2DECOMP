// emsgqueue_stubs.cpp - Stub implementations for Emsgqueue
// Auto-generated from symbols.json - 11 functions
// These are stub implementations to register progress.
// Each function needs proper decompilation to match the original binary.

#include "types.h"

// 0x80538190 | 76 bytes
EMsgQueue::EMsgQueue(void) { }

// 0x80538234 | 100 bytes
EMsgQueue::~EMsgQueue(void) { }

// 0x80538298 | 236 bytes
void EMsgQueue::Create(int) { }

// 0x80538384 | 88 bytes
void EMsgQueue::Destroy(void) { }

// 0x805383DC | 192 bytes
void EMsgQueue::Send(unsigned int, bool) { }

// 0x8053849C | 160 bytes
void EMsgQueue::Receive(unsigned int *, bool) { }

// 0x8053853C | 120 bytes
void EMsgQueue::iSend(unsigned int) { }

// 0x805385B4 | 136 bytes
void EMsgQueue::iReceive(unsigned int *) { }

// 0x8053863C | 36 bytes
void EMsgQueue::GetCount(void) { }

// 0x80538660 | 88 bytes
void EMsgQueue::GetStats(int &, int &, int &, int &) { }

// 0x805386B8 | 64 bytes
void EMsgQueue::Empty(void) { }
