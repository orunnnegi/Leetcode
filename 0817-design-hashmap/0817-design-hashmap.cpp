class MyHashMap {
public:
    int arr[1000001];
    MyHashMap() {
        memset(arr, -1, sizeof(arr));
    }
    
    void put(int key, int value) {
        arr[key]= value;
        return;
    }
    
    int get(int key) {
        if(arr[key]==-1) return -1;
        return arr[key];
    }
    
    void remove(int key) {
        arr[key]= -1;
        return;
    }
};

/**
 * Your MyHashMap object will be instantiated and called as such:
 * MyHashMap* obj = new MyHashMap();
 * obj->put(key,value);
 * int param_2 = obj->get(key);
 * obj->remove(key);
 */