// 0x80240258 PCgetLastError (20B)
//
// SDA-exchange-global pattern (non-SDA variant, from SonnetWorker2 catalog).
// Reads `__pcLastError` global into r3 (return value), then zeros it.
//
// asm:
//   lis r9, -32694           ; r9 = 0x80490000
//   li r0, 0
//   lwz r3, -26472(r9)        ; r3 = *(0x80489898) — old value
//   stw r0, -26472(r9)        ; *(0x80489898) = 0
//   blr

extern char __pcLastError[16];

extern "C" int PCgetLastError() {
    int prev = *(int*)__pcLastError;
    *(int*)__pcLastError = 0;
    return prev;
}
