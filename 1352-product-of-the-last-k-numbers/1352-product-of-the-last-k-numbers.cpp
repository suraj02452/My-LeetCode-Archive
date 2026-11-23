#include <vector>

class ProductOfNumbers {
private:
    std::vector<int> prefix;

public:
    ProductOfNumbers() {
        // Initialize with 1 as the multiplicative identity
        prefix = {1};
    }
    
    void add(int num) {
        if (num == 0) {
            // Reset the prefix vector whenever 0 is added
            prefix = {1};
        } else {
            prefix.push_back(prefix.back() * num);
        }
    }
    
    int getProduct(int k) {
        int n = prefix.size();
        // If k >= n, a 0 was encountered within the last k elements
        if (k >= n) {
            return 0;
        }
        return prefix.back() / prefix[n - 1 - k];
    }
};
