// 0x80038E50 EyeToyClient::ApplyFunFrame (20 bytes)
// DOL:
//   lwz r0, -32564(r13)   ; load g (SDA)
//   cmpw r3, r0
//   beqlr                 ; return if equal
//   stw r3, -32564(r13)   ; store new value
//   blr
// Anti-CSE technique: two distinct externs prevent the compiler from
// caching the SDA address into a scratch register and reusing it.

extern char gFunFrameLoad[4];
extern char gFunFrameStore[4];

void ApplyFunFrame_int(int frame) {
    if (frame == *(int*)gFunFrameLoad) return;
    *(int*)gFunFrameStore = frame;
}
