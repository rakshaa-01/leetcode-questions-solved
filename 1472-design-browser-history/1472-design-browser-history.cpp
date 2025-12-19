class BrowserHistory {
public:
    string url;
    BrowserHistory* back1;
    BrowserHistory* forward1;
    BrowserHistory* temp;

    BrowserHistory(string homepage) {
        url=homepage;
        back1=nullptr;
        forward1=nullptr;
        temp=this;
    }
    
    void visit(string url1) {
        BrowserHistory* newNode=new BrowserHistory(url1);
        temp->forward1=nullptr;
        newNode->back1=temp;
        temp->forward1=newNode;
        temp=temp->forward1;
    }
    
    string back(int steps) {
        while(steps>0 && temp->back1) {
            temp=temp->back1;
            steps--;
        }
        return temp->url;
    }
    
    string forward(int steps) {
        while(steps>0 && temp->forward1) {
            temp=temp->forward1;
            steps--;
        }
        return temp->url;
    }
};

/**
 * Your BrowserHistory object will be instantiated and called as such:
 * BrowserHistory* obj = new BrowserHistory(homepage);
 * obj->visit(url);
 * string param_2 = obj->back(steps);
 * string param_3 = obj->forward(steps);
 */