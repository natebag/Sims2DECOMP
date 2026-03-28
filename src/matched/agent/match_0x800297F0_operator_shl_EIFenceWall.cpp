void* StreamOperator(void* stream, void* obj);

void* operator_shl_EIFenceWall(void* stream, void* obj) {
    return StreamOperator(stream, obj);
}
