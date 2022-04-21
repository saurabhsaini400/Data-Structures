class MyHashSet {
public:
    struct ListNode{
        pair<int,int>val;        
        struct ListNode *next;
    };
    
    struct ListNode *head=nullptr;
   struct ListNode *newNode(int a)
    {
       struct ListNode *tmp=new ListNode();
        tmp->val.first=a;
       tmp->val.second=1;
        tmp->next=nullptr;
       return tmp;
    }
    MyHashSet() {
        
    }
    
    void add(int key) {
        if(!head)
        {
            head=newNode(key);
            return;
        }
struct ListNode *cur=head,*prev;
        while(cur){
            if(cur->val.first==key){
                cur->val.second++;
                return;
            }
            prev=cur;
            cur=cur->next;
        }
        prev->next=newNode(key);
        
    }
    
    void remove(int key) {
        if(!head)
            return;
        if(head->val.first==key)
        {
            head=head->next;
            return;
        }
       struct  ListNode *cur=head,*prev;
        while(cur){
            if(cur->val.first==key){
                prev->next=cur->next;
                return;
            }
            prev=cur;
            cur=cur->next;
        }        
    }
    
    bool contains(int key) {
         if(!head)
            return false;
         struct  ListNode *cur=head;
        while(cur){
            if(cur->val.first==key)
                return true;
          cur=cur->next;
        }
        return false;
    }
};