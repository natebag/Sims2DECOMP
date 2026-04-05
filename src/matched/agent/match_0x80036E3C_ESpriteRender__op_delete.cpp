void *OD_GetHeap(void);
void OD_Free(void *, void *);

void ESpriteRender_op_delete(void *ptr) {
    void *heap = OD_GetHeap();
    OD_Free(heap, ptr);
}
