struct cXObjectImpl {
    void InternalFuncExtra();
    void WrapperFuncExtra();
};

void cXObjectImpl::WrapperFuncExtra() {
    InternalFuncExtra();
}
