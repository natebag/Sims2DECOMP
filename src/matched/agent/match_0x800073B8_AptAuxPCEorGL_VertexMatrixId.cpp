/* AptAuxPCEorGL_VertexMatrixId(void) at 0x800073B8 (40B) */

extern char g_vertexMatrixObj[];

void LoadVertexMatrixId(void*);

void AptAuxPCEorGL_VertexMatrixId(void) {
    LoadVertexMatrixId(g_vertexMatrixObj);
}
