// 0x800073B8 (40 bytes) AptAuxPCEorGL_VertexMatrixId(void)
// Loads the address of a static EMat4 and resets it to identity.
// Referencing the global by symbol (not an integer-literal cast) makes the
// compiler emit the lis@ha / addi@l relocation pair instead of lis / ori.
struct EMat4 {
    float m[4][4];
    void Id();
};

extern EMat4 s_vertexMatrix;

void AptAuxPCEorGL_VertexMatrixId() {
    s_vertexMatrix.Id();
}
