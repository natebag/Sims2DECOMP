struct cXObjectImpl {
    void InternalFuncX();
    void WrapperFuncX();
};

void cXObjectImpl::WrapperFuncX() {
    InternalFuncX();
}
