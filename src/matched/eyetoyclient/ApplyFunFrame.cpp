// 0x80038E50 EyeToyClient::ApplyFunFrame (20B)
// DOL:
//   lwz r0, -32564(r13)   ; load g
//   cmpw r3, r0
//   beqlr                 ; return if equal
//   stw r3, -32564(r13)   ; store new value
//   blr

// Two distinct externs to defeat CSE on the SDA address
extern char gFunFrameLoad[4];
extern char gFunFrameStore[4];

void ApplyFunFrame_int(int frame) {
    if (frame == *(int*)gFunFrameLoad) return;
    *(int*)gFunFrameStore = frame;
}
