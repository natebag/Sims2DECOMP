struct cXObjectImpl {
    void InternalFunc1();
    void WrapperFunc1();
};

void cXObjectImpl::WrapperFunc1() {
    InternalFunc1();
}
