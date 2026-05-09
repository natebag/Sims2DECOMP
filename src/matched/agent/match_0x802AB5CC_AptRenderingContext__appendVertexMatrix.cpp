// AptRenderingContext::appendVertexMatrix(AptMatrix*) @ 0x802AB5CC (72B)
// Pattern: static AptRenderingContext::multMatrix + indirect call via gAptFuncs[30]
class AptMatrix;

class AptRenderingContext {
public:
    void appendVertexMatrix(AptMatrix* matrix);
    static void multMatrix(AptMatrix*, AptMatrix*, AptMatrix*);
};

typedef void (*AptFunc)();
extern AptFunc gAptFuncs[];

void AptRenderingContext::appendVertexMatrix(AptMatrix* matrix) {
    AptMatrix* slot = (AptMatrix*)((char*)this + 0x20);
    multMatrix(slot, matrix, slot);
    ((void(*)(AptMatrix*))gAptFuncs[30])(slot);
}
