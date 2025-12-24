class Node {
    public:
        string url;
        Node* next;
        Node* prev;

        Node() {
            url="";
            next=NULL;
            prev=NULL;
        }
        Node(string x){
            url=x;
            next=NULL;
            prev=NULL;
        }
};


class BrowserHistory {
    Node* curr;
public:
    BrowserHistory(string homepage) {
        curr=new Node(homepage);
    }
    
    void visit(string url) {
        Node* newNode = new Node(url);
        curr->next=newNode;
        newNode->prev=curr;
        curr=curr->next;
    }
    
    string back(int steps) {
        while(steps && curr->prev) {
            curr=curr->prev;
            steps--;
        }
        return curr->url;
    }
    
    string forward(int steps) {
        while(steps && curr->next) {
            curr=curr->next;
            steps--;
        }
        return curr->url;
    }
};

/**
 * Your BrowserHistory object will be instantiated and called as such:
 * BrowserHistory* obj = new BrowserHistory(homepage);
 * obj->visit(url);
 * string param_2 = obj->back(steps);
 * string param_3 = obj->forward(steps);
 */