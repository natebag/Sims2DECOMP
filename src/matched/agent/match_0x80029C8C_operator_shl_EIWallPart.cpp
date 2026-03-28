void* StreamOperator2(void* stream, void* obj);

void* operator_shl_EIWallPart(void* stream, void* obj) {
    return StreamOperator2(stream, obj);
}
