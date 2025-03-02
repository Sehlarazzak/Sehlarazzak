#include <iostream>
#include <vector>
#include <string>

struct MenuItem {
    std::string name;
    double price;
    std::string type; // "drink" or "food"
};

class CoffeeShop {
private:
    std::string name;
    std::vector<MenuItem> menu;
    std::vector<std::string> orders;

public:
    CoffeeShop(std::string shopName, std::vector<MenuItem> menuItems) : name(shopName), menu(menuItems) {}

    std::string addOrder(std::string itemName) {
        for (const auto& item : menu) {
            if (item.name == itemName) {
                orders.push_back(itemName);
                return "Order added: " + itemName;
            }
        }
        return "This item is currently unavailable!";
    }

    std::string fulfillOrder() {
        if (!orders.empty()) {
            std::string fulfilledItem = orders.front();
            orders.erase(orders.begin());
            return "The " + fulfilledItem + " is ready!";
        }
        return "All orders have been fulfilled";
    }

    std::vector<std::string> listOrders() {
        return orders;
    }

    double dueAmount() {
        double total = 0.0;
        for (const auto& order : orders) {
            for (const auto& item : menu) {
                if (item.name == order) {
                    total += item.price;
                }
            }
        }
        return total;
    }

    std::string cheapestItem() {
        if (menu.empty()) return "No items available";
        
        const MenuItem* cheapest = &menu[0];
        for (const auto& item : menu) {
            if (item.price < cheapest->price) {
                cheapest = &item;
            }
        }
        return cheapest->name;
    }

    std::vector<std::string> drinksOnly() {
        std::vector<std::string> drinks;
        for (const auto& item : menu) {
            if (item.type == "drink") {
                drinks.push_back(item.name);
            }
        }
        return drinks;
    }

    std::vector<std::string> foodOnly() {
        std::vector<std::string> foods;
        for (const auto& item : menu) {
            if (item.type == "food") {
                foods.push_back(item.name);
            }
        }
        return foods;
    }
};

int main() {
    std::vector<MenuItem> menu = {
        {"Espresso", 2.50, "drink"},
        {"Latte", 3.50, "drink"},
        {"Croissant", 2.00, "food"},
        {"Sandwich", 5.00, "food"}
    };
    
    CoffeeShop myShop("Java Haven", menu);
    
    std::cout << myShop.addOrder("Espresso") << std::endl;
    std::cout << myShop.addOrder("Burger") << std::endl;
    std::cout << myShop.fulfillOrder() << std::endl;
    std::cout << "Due Amount: $" << myShop.dueAmount() << std::endl;
    std::cout << "Cheapest Item: " << myShop.cheapestItem() << std::endl;
    
    std::vector<std::string> drinks = myShop.drinksOnly();
    std::cout << "Drinks Available: ";
    for (const auto& drink : drinks) {
        std::cout << drink << " ";
    }
    std::cout << std::endl;
    
    std::vector<std::string> foods = myShop.foodOnly();
    std::cout << "Foods Available: ";
    for (const auto& food : foods) {
        std::cout << food << " ";
    }
    std::cout << std::endl;
    
    return 0;
}