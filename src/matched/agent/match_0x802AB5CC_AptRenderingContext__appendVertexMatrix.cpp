// 0x802AB5CC (72 bytes)
/* AptRenderingContext::appendVertexMatrix(AptMatrix *) */

// Forward declarations
extern void AptRenderingContext_addToList(void* list, void* item);  /* 0x802AB4D0 */

struct AptRenderingContext_appendVertex {
    char _pad[0x20];
    void* m_vertexMatrixList;  /* 0x20 */
    
    void appendVertexMatrix(void* matrix);
};

void AptRenderingContext_appendVertex::appendVertexMatrix(void* matrix) {
    AptRenderingContext_addToList(&m_vertexMatrixList, matrix);
    // vtable dispatch via global
}
