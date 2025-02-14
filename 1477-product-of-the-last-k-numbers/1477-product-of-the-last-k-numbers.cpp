class ProductOfNumbers {
public:
vector<int> stream;
    ProductOfNumbers() {
        
    }
    
    void add(int num) {
      stream.push_back(num);
    }
    
    int getProduct(int k) {
        int product =1;
        int n= stream.size();
        int j=n-1 , i=0;
        while(i<k)
        {
            product*=stream[j];
            i++;
            j--;
        }
        return product;
    }
};

/**
 * Your ProductOfNumbers object will be instantiated and called as such:
 * ProductOfNumbers* obj = new ProductOfNumbers();
 * obj->add(num);
 * int param_2 = obj->getProduct(k);
 */