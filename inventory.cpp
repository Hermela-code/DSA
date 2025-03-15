#include <iostream>
#include <string>
using namespace std;

#define TAX_RATE 0.15  // Preprocessor tax constant

struct Product {
    string name;
    int category;
    float price;
    int initialInventory;
    int itemsSold = 0;  // Direct initialization
    int newInventory;
    string inventoryStatus;
};

int main() {
    // Introductory message
    cout << "\n\n\033[1;33mSelam! This program helps manage your store inventory and sales.\033[0m\n";
    cout << "\n\n\033[1;33mC++ is a powerful compiled language.\033[0m\n";
    cout << "----------------------------------\n";

    // Different initialization methods
    string storeName = "Enqlf Store";  // Assignment
    const int MAX_PROD{5};             // List initialization
    float dailyTarget(5000.0);         // Direct initialization

    Product products[MAX_PROD];
    int productCount = 0;
    const string CURRENCY = "Birr";
    const float VAT_RATE = 0.15;  // const keyword

    // Add products phase
    cout << "\n=== Add Products (Max 5) ===\n";
    while(productCount < MAX_PROD) {
        Product p;
        
        cout << "\nProduct " << productCount+1 << ":\n";
        cout << "Enter product name (single word): ";
        cin >> p.name;

        cout << "Enter product category (1 to 5): 1-Electronics  2-Groceries  3-Clothing  4-Stationery  5-Miscellaneous: ";
        cin >> p.category;
        if(p.category < 1 || p.category > 5) {
            cout << "Invalid! Set to Miscellaneous(5)\n";
            p.category = 5;
        }

        cout << "Enter product price per unit: (" << CURRENCY << "): ";
        cin >> p.price;

        cout << "Enter initial inventory quantity: ";
        cin >> p.initialInventory;

        products[productCount++] = p;

        if(productCount < MAX_PROD) {
            cout << "Add more? (1=Yes/0=No): ";
            int choice;
            cin >> choice;
            if(!choice) break;
        }
    }

    // Sales phase
    cout << "\n=== Sales Section ===\n";
    float totalSalesAll = 0;  // Total across all products
    
    while(true) {
        cout << "\nAvailable Products:\n";
        for(int i = 0; i < productCount; i++) {
            products[i].newInventory = products[i].initialInventory - products[i].itemsSold;
            products[i].inventoryStatus = (products[i].newInventory < 10) ? "Low" : "Sufficient";
            cout << i+1 << ". " << products[i].name 
                 << " (" << products[i].newInventory << " left, Status: " << products[i].inventoryStatus << ") - "
                 << products[i].price << " " << CURRENCY << endl;
        }

        cout << "\nChoose product (1-" << productCount << ") or 0 to finish: ";
        int choice;
        cin >> choice;
        
        if(choice == 0) break;
        if(choice < 1 || choice > productCount) {
            cout << "Invalid choice!\n";
            continue;
        }

        Product &p = products[choice-1];
        
        cout << "Quantity to sell: ";
        int qty;
        cin >> qty;

        // Check stock
        if(qty > (p.initialInventory - p.itemsSold)) {
            cout << "Not enough stock!\n";
            continue;
        }

        // Update sales and inventory
        p.itemsSold += qty;
        p.newInventory = p.initialInventory - p.itemsSold;  // Compound assignment
        
        // Type deduction helpers
        auto salesCopy = p.itemsSold * p.price;
        decltype(p.initialInventory) stockHelper = 50;

        // Generate receipt
        cout << "\n----- " << storeName << " Receipt -----\n";
        for(int i = 0; i < qty; i++) {  
            cout << "Item #" << i+1 << ": " << p.price << " " << CURRENCY << endl;
        }
        
        float tax = salesCopy * TAX_RATE;
        cout << "Subtotal: " << salesCopy << " " << CURRENCY << endl;
        cout << "VAT (" << TAX_RATE*100 << "%): " << tax << endl;
        cout << "Total: " << salesCopy + tax << " " << CURRENCY << endl;
        cout << "------------------------------\n";

        totalSalesAll += salesCopy;
    }

    // Final report
    cout << "\n======= Daily Summary =======\n";
    cout << "Tax Rates: " << TAX_RATE*100 << "% (preprocessor), "
         << VAT_RATE*100 << "% (const)\n";
    
    for(int i = 0; i < productCount; i++) {
        Product &p = products[i];
        auto totalSales = p.itemsSold * p.price;  // auto helper
        
        cout << "\nProduct: " << p.name << endl;
        cout << "Category: ";
        switch(p.category) {  // Switch statement
            case 1: cout << "Electronics"; break;
            case 2: cout << "Groceries"; break;
            case 3: cout << "Clothing"; break;
            case 4: cout << "Stationery"; break;
            case 5: cout << "Miscellaneous"; break;
        }
        cout << "\nInitial Stock: " << p.initialInventory << endl;
        cout << "Price: " << p.price << " " << CURRENCY << endl;
        cout << "Sold: " << p.itemsSold << endl;
        cout << "Remaining: " << p.newInventory << endl;
        cout << "Sales Total: " << totalSales << " " << CURRENCY << endl;
    }

    decltype(totalSalesAll) dailyHelper = 10000.0;  // decltype helper
    cout << "\nDaily Target: " << dailyTarget << " " << CURRENCY;
    cout << "\nActual Sales: " << totalSalesAll << " " << CURRENCY;
    cout << "\nTarget Helper: " << dailyHelper << " " << CURRENCY;

     cout << "\n\n\033[1;33mAmasegenallo! Thank you for using our system!\033[0m\n";
    cout << "\n\n\033[1;33mAddis Ababa, Ethiopia\033[0m\n   ";
    return 0;
}

