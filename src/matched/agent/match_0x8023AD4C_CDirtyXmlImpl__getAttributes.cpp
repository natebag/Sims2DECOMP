extern int CDirtyXmlNode_getAttributes(void *self);

struct CDirtyXmlImpl {
    int getAttributes();
};

int CDirtyXmlImpl::getAttributes() {
    return CDirtyXmlNode_getAttributes(this);
}
