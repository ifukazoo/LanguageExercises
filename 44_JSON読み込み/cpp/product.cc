#include <iostream>

#include <boost/foreach.hpp>
#include <boost/property_tree/json_parser.hpp>
#include <boost/property_tree/ptree.hpp>

#include "product.h"

namespace pt = boost::property_tree;

namespace product {

bool parse(std::istream& is, std::vector<Product>& products) {
    pt::ptree pt;
    try {
        pt::read_json(is, pt);
        BOOST_FOREACH (auto& child, pt.get_child("products")) {
            std::string name = child.second.get<std::string>("name");
            double price = child.second.get<double>("price");
            int quantity = child.second.get<int>("quantity");
            products.push_back(Product(name, price, quantity));
        }
    } catch (std::exception const& e) {
        std::cerr << e.what() << std::endl;
        return false;
    }
    return true;
}
void Product::disp() const {
    std::cout << "Name: " << name_ << std::endl;
    std::cout << std::fixed << std::setprecision(2) << "Price: $" << price_
              << std::endl;
    std::cout << "Quantity on hand: " << quantity_ << std::endl;
}
}
