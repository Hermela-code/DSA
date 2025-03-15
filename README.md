# Enqlf Inventory System

Enqlf Inventory System is a simple C++ program designed to help Ethiopian store owners manage product sales and inventory efficiently. The system allows users to add products, track inventory, generate receipts, and view sales reports, all while maintaining an Ethiopian touch in the user interface.

## Features
- Add up to 5 products with categories
- Track inventory in real-time
- Generate sales receipts
- Apply Ethiopian VAT (15%)
- Provide inventory status notifications
- Daily sales summary

## Installation

### Linux (Ubuntu/Debian)
1. Update package lists and install g++:
     
     sudo apt update && sudo apt install g++ -y
   
2. Clone the repository:
     
git clone https://github.com/lamerhel/enqlf-inventory.git
  
3. Navigate to the project folder:
   
cd enqlf-inventory
   
4. Compile the program:
   
g++ inventory.cpp -o inventory
   
5. Run the program:
   
./inventory
   

### Windows (Using MinGW)
1. Download and install MinGW from [MinGW-w64](https://www.mingw-w64.org/).
2. Add MinGW to system PATH:
   - Go to **Control Panel** → **System** → **Advanced system settings**
   - Click **Environment Variables**
   - Under **System variables**, find **Path** and click **Edit**
   - Add the MinGW \bin directory (e.g., C:\MinGW\bin)
3. Open Command Prompt and verify installation:
   
g++ --version
   
4. Clone the repository:
   
git clone https://github.com/lamerhel/enqlf-inventory.git
   
5. Navigate to the project folder:
   
cd enqlf-inventory
    
6. Compile the program:
   
g++ inventory.cpp -o inventory.exe
   
7. Run the program:
   
inventory.exe
   

## Usage
1. Start the program and enter product details.
2. Choose a product and enter the quantity sold.
3. View receipts and inventory updates.
4. Check the daily sales summary at the end.


---
**Amasegenallo! Thank you for using Enqlf Inventory System!**
