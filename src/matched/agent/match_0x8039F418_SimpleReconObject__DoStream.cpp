// 0x8039F418 SimpleReconObject::DoStream (40b)

struct Inner { void* data; };
struct Outer { int pad; Inner* inner; };

extern void DoStreamImpl(void*);

void SimpleReconObject_DoStream(Outer* self, void*, int) {
    Inner* inner = self->inner;
    DoStreamImpl(inner->data);
}
