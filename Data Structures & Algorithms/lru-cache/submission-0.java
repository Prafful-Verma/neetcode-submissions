class LRUCache {
    static int totalcapacity;
    static int maxsize;
    Node head;
    Node tail;
    class Node
    {
        int key;
        int value;
        Node next;
        Node prev;
        
    }
    static HashMap<Integer,Node> m=new HashMap<>();

    public LRUCache(int capacity) {
        m.clear();
        this.maxsize=capacity;
        totalcapacity=0;
        head=new Node();
        tail=new Node();
        head.next=tail;
        tail.prev=head;
        
    }
    
    public int get(int key) {
        
        Node node=m.get(key);
        if(node==null)
        {
            return -1;
        }
        if(head.next!=node)
        {
            movetohead(node);
        }
        return node.value;
    }
    public void movetohead(Node node)
    {
        removeNodeFromList(node);
        addNodeToFront(node);
    }
    public void removeNodeFromList(Node node)
    {
        node.prev.next=node.next;
        node.next.prev=node.prev;
    }
    public void addNodeToFront(Node node)
    {
        Node front=head.next;
        head.next=node;
        node.prev=head;
        
        front.prev=node;
        node.next=front;
    }
    public void put(int key, int value) 
    {
        Node node=m.get(key);
        if(node==null)
        {
            Node newnode=new Node();
            newnode.value=value;
            newnode.key=key;
            m.put(key,newnode);
            totalcapacity++;
            addNodeToFront(newnode);
            if(totalcapacity>maxsize)
            {
                removeLFU();
            }
        }
        else
        {
            node.value=value;
            removeNodeFromList(node);
            movetohead(node);
        }
    }
    public void removeLFU()
    {
        Node lastnode=tail.prev;
        removeNodeFromList(lastnode);
        m.remove(lastnode.key);
        totalcapacity--;
    }
}

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache obj = new LRUCache(capacity);
 * int param_1 = obj.get(key);
 * obj.put(key,value);
 */