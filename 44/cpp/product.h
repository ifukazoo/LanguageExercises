#ifndef _PRODUCT_H_
#define _PRODUCT_H_

#include <istream>
#include <string>
#include <vector>

namespace product {

class Product {
   private:
    std::string name_;
    double price_;
    int quantity_;

   public:
    explicit Product(std::string name, double price, int quantity)
        : name_(name), price_(price), quantity_(quantity) {}

    std::string name() const { return name_; }
    double price() const { return price_; }
    int quantity() const { return quantity_; }
    void disp() const;
};
bool parse(std::istream&, std::vector<Product>&);
}
#endif
