 #include <iostream>
 #include <string>
 using namespace std;



class IntNode{
    public:
    IntNode(){}
    IntNode(int theData, IntNode* theLink):data(theData),link(theLink){}
            IntNode* getLink() {return link;}
            int getData() {return data;}
            void setData(int theData) {data=theData;}
            void setLink(IntNode* pointer) {link = pointer;}
            private:
            int data;
            IntNode *link;

};


int main(){
 
cout << "starting\n";
 typedef IntNode* IntNodePtr;
 IntNodePtr next3 = new IntNode(6,NULL);
IntNodePtr next2 = new IntNode(5,next3);
 IntNodePtr next1 = new IntNode(4,next2);
 IntNodePtr head = new IntNode(3,next1);
 IntNodePtr here = head;
IntNodePtr discard = new IntNode(0,NULL);
IntNodePtr before = new IntNode(0,NULL);

int target = 5;
while(here->getData() != target && here->getLink() != NULL) {
    if(here->getLink()->getData() == target) {
        discard = here->getLink();
        before = here;
        before->setLink(discard->getLink());
        before->setData(discard->getData());
        delete discard;
        cout << "removed "<< before->getData() << endl;
    }
    here = here->getLink();
    cout << "Loop"<<endl;
}

return 0;
}