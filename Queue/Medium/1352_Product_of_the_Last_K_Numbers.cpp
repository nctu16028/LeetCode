#include <iostream>
#include <vector>
using namespace std;

class ProductOfNumbers {
public:
    vector<int> prefixProduct;

    ProductOfNumbers() {
        
    }
    
    void add(int num) {
        if (num == 0)
            prefixProduct.clear();
        else if (prefixProduct.empty())
            prefixProduct.push_back(num);
        else
            prefixProduct.push_back(prefixProduct.back() * num);
    }
    
    int getProduct(int k) {
        if (k > prefixProduct.size())
            return 0;
        else if (k == prefixProduct.size())
            return prefixProduct.back();
        else
            return prefixProduct.back() / prefixProduct[prefixProduct.size() - 1 - k];
    }
};

int main()
{
    ProductOfNumbers* productOfNumbers = new ProductOfNumbers();
    productOfNumbers->add(3);
    productOfNumbers->add(0);
    productOfNumbers->add(2);
    productOfNumbers->add(5);
    productOfNumbers->add(4);
    cout << productOfNumbers->getProduct(2) << endl;
    cout << productOfNumbers->getProduct(3) << endl;
    cout << productOfNumbers->getProduct(4) << endl;
    productOfNumbers->add(8);
    cout << productOfNumbers->getProduct(2) << endl;
    delete productOfNumbers;

    return 0;
}
