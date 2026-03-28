extern int CDirtyXmlNode_removeChild(void *self);

struct CDirtyXmlImpl {
    int removeChild();
};

int CDirtyXmlImpl::removeChild() {
    return CDirtyXmlNode_removeChild(this);
}
