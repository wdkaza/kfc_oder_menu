#include <iostream>
#include <fstream>
#include <string>

void pick_menu(float &totalCost);
void seeStock(int &ORG_left, int &SC_left, int &CT_left);
void updateStock(int ORG_left, int SC_left, int CT_left);

int main()
{


    float totalCost = 0;
    pick_menu(totalCost);
    return 0;
}
void seeStock(int &ORG_left, int &SC_left, int &CT_left){
    std::ifstream file("kfc_stock.txt"); // Open file for reading
    if (file.is_open()) {
        file >> ORG_left >> SC_left >> CT_left; // Read stock from file
        file.close();
    } else {
        std::cerr << "Failed to open the file!" << std::endl;
    }
    file.close();
}

void updateStock(int ORG_left, int SC_left, int CT_left) {
    std::ofstream file("kfc_stock.txt");
    if (file.is_open()) {
        file << ORG_left << std::endl;
        file << SC_left << std::endl;
        file << CT_left << std::endl;
        file.close();
    } else {
        std::cerr << "failed to open the file" << std::endl;
    }
}

void pick_menu(float &totalCost){
    int userChoice;
    int SC_left, CT_left, ORG_left;
    do {
        std::cout << "-----------------------------------" << "\n";
        std::cout << "Kentucky Fried Chicken menu" << "\n";
        std::cout << "-----------------------------------" << "\n";
        std::cout << "1. Original Recipe Chicken - $5.99 (" << ORG_left << " left)" << "\n";
        std::cout << "2. Spicy Chicken - $9.99 (" << SC_left << " left)" << "\n";
        std::cout << "3. Chicken Tenders - $6.99 (" << CT_left << " left)" << "\n";
        std::cout << "0. Quit" << "\n";
        std::cout << "999. Debug (see stocks)" << "\n";
        std::cin >> userChoice;

        if (userChoice == 1 && ORG_left > 0) {
            totalCost += 5.99;
            ORG_left--;
            std::cout << "Original Recipe Chicken + $5.99, total cost | $" << totalCost << "\n";
            std::cout << "Original Recipe Chicken left | " << ORG_left << "\n";
        } else if (userChoice == 2 && SC_left > 0) {
            totalCost += 9.99;
            SC_left--;
            std::cout << "Spicy Chicken + $9.99, total cost | $" << totalCost << "\n";
            std::cout << "Spicy Chicken left | " << SC_left << "\n";
        } else if (userChoice == 3 && CT_left > 0) {
            totalCost += 6.99;
            CT_left--;
            std::cout << "Chicken Tenders + $6.99, total cost | $" << totalCost << "\n";
            std::cout << "Chicken Tenders left | " << CT_left << "\n";
        } else if (userChoice == 999) {
            // See stocks
            std::cout << "Original Recipe Chicken: " << ORG_left << "\n";
            std::cout << "Spicy Chicken: " << SC_left << "\n";
            std::cout << "Chicken Tenders: " << CT_left << "\n";
        } else if (userChoice != 0 && userChoice != 999) {
            std::cout << "Invalid choice or out of stock!" << "\n";
        }

        updateStock(ORG_left, SC_left, CT_left);

    } while (userChoice != 0);
}
