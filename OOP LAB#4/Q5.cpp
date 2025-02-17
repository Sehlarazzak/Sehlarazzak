#include <iostream>
#include <vector>
#include <string>

class MenuItem {
public:
    std::string name;
    std::string type;
    double price;

    MenuItem(std::string n, std::string t, double p) : name(n), type(t), price(p) {}
};

class CoffeeShop {
private:
    std::string name;
    std::vector<MenuItem> menu;
    std::vector<std::string> orders;

public:
    CoffeeShop(std::string shopName, std::vector<MenuItem> menuItems)
        : name(shopName), menu(menuItems) {}

    std::string addOrder(std::string itemName) {
        for (const auto &item : menu) {
            if (item.name == itemName) {
                orders.push_back(itemName);
                return "Order added: " + itemName;
            }
        }
        return "This item is currently unavailable";
    }

    std::string fulfillOrder() {
        if (!orders.empty()) {
            std::string item = orders.front();
            orders.erase(orders.begin());
            return "The " + item + " is ready";
        }
        return "All orders have been fulfilled";
    }

    std::vector<std::string> listOrders() {
        return orders;
    }

    double dueAmount() {
        double total = 0;
        for (const auto &order : orders) {
            for (const auto &item : menu) {
                if (item.name == order) {
                    total += item.price;
                    break;
                }
            }
        }
        return total;
    }

    std::string cheapestItem() {
        if (menu.empty()) return "Menu is empty";
        const MenuItem *cheapest = &menu[0];
        for (const auto &item : menu) 
		{
            if (item.price < cheapest->price) 
			{
                cheapest = &item;
            }
        }
        return cheapest->name;
    }

    std::vector<std::string> drinksOnly() {
        std::vector<std::string> drinks;
        for (const auto &item : menu) 
		{
            if (item.type == "drink") 
			{
                drinks.push_back(item.name);
            }
        }
        return drinks;
    }

    std::vector<std::string> foodOnly() {
        std::vector<std::string> foods;
        for (const auto &item : menu) 
		{
            if (item.type == "food") 
			{
                foods.push_back(item.name);
            }
        }
        return foods;
    }
};

int main() {
    std::vector<MenuItem> menu = {
        {"Coffee", "drink", 2.50},
        {"Tea", "drink", 1.80},
        {"Sandwich", "food", 5.00},
        {"Cake", "food", 3.50}
    };

    CoffeeShop shop("Java Beans", menu);
    
    std::cout << shop.addOrder("Coffee") << std::endl;
    std::cout << shop.addOrder("Pizza") << std::endl;
    std::cout << "Total Due: $" << shop.dueAmount() << std::endl;
    std::cout << shop.fulfillOrder() << std::endl;
    std::cout << shop.fulfillOrder() << std::endl;
    std::cout << "Cheapest item: " << shop.cheapestItem() << std::endl;
    
    return 0;
}

