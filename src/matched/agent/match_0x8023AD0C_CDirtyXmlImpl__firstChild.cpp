extern int CDirtyXmlNode_firstChild(void *self);

struct CDirtyXmlImpl {
    int firstChild();
};

int CDirtyXmlImpl::firstChild() {
    return CDirtyXmlNode_firstChild(this);
}
