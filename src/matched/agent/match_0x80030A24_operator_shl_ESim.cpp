void* StreamOperator3(void* stream, void* obj);

void* operator_shl_ESim(void* stream, void* obj) {
    return StreamOperator3(stream, obj);
}
