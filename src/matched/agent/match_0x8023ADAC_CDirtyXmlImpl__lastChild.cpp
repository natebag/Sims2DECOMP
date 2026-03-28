extern int CDirtyXmlNode_lastChild(void *self);

struct CDirtyXmlImpl {
    int lastChild();
};

int CDirtyXmlImpl::lastChild() {
    return CDirtyXmlNode_lastChild(this);
}
