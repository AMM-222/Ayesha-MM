#include <iostream>
#include <cstring>
#include <windows.h>  

using namespace std;

struct Material {
    char name[50];
    char color[20];
    int stock;
    int sold;
};


const int MAX_CAPACITY = 100;  
Material inventory[MAX_CAPACITY] = {
    {"Cotton", "White", 400, 0},
    {"Linen", "Beige", 500, 0},
    {"Velvet", "Red", 350, 0},
    {"Silk", "Black", 600, 0}
};  
int totalMaterials = 4;  


void setTextColor(int color) {
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(hConsole, color);
}


void showWelcomeMessage() {
    setTextColor(2);  
    cout << "*********************************************\n";
    cout << "*       WELCOME TO INVENTORY MANAGEMENT     *\n";
    cout << "*********************************************\n";
    setTextColor(7);
}


void showAllMaterials() {
    cout << "\nMaterials in Inventory:\n";
    for (int i = 0; i < totalMaterials; i++) {
        cout << "Name: " << inventory[i].name
             << ", Color: " << inventory[i].color
             << ", Stock: " << inventory[i].stock
             << ", Sold: " << inventory[i].sold << endl;

        
        if (inventory[i].stock < 10) {
            setTextColor(14);  
            cout << "  *** Low stock alert! ***\n";
            setTextColor(7);  
        }
    }
}


void addMaterial() {
    if (totalMaterials == MAX_CAPACITY) {
	 setTextColor(4);
        cout << "Inventory is full. Cannot add more materials.\n";
        return;
        setTextColor(7);
    }

    Material newMaterial;
    cout << "Enter material name (e.g., Fabric, Leather): ";
    cin.ignore();
    cin.getline(newMaterial.name, 50);
    cout << "Enter material color (e.g., Red, Blue, Black): ";
    cin.getline(newMaterial.color, 20);

    cout << "Enter initial stock amount: ";
    cin >> newMaterial.stock;
    newMaterial.sold = 0;

    inventory[totalMaterials++] = newMaterial;  
    cout << "Material added successfully!\n";
}


void updateStock() {
    char materialName[50];
    cout << "Enter the name of material to update stock: ";
    cin.ignore();
    cin.getline(materialName, 50);

    for (int i = 0; i < totalMaterials; i++) {
        if (strcmp(inventory[i].name, materialName) == 0) {
            int newStock;
            cout << "Enter new stock amount: ";
            cin >> newStock;
            inventory[i].stock = newStock;
            cout << "Stock updated successfully!\n";
            return;
        }
    }

    setTextColor(14); 
    cout << "Material not found!\n";
    setTextColor(7);  
}


void sellMaterial() {
    char materialName[50];
    cout << "Enter the name of material to sell: ";
    cin.ignore();
    cin.getline(materialName, 50);

    for (int i = 0; i < totalMaterials; i++) {
        if (strcmp(inventory[i].name, materialName) == 0) {
            int quantity;
            cout << "Enter quantity to sell: ";
            cin >> quantity;

            if (quantity > inventory[i].stock) {
                cout << "Not enough stock available to sell!\n";
            } else {
                inventory[i].stock -= quantity;
                inventory[i].sold += quantity;
                cout << "Material sold successfully!\n";
            }
            return;
        }
    }

    setTextColor(14);  
    cout << "Material not found!\n";
    setTextColor(7);  
}


void deleteMaterial() {
    char materialName[50];
    cout << "Enter the name of material to delete: ";
    cin.ignore();
    cin.getline(materialName, 50);

    for (int i = 0; i < totalMaterials; i++) {
        if (strcmp(inventory[i].name, materialName) == 0) {
            
            for (int j = i; j < totalMaterials - 1; j++) {
                inventory[j] = inventory[j + 1];
            }
            totalMaterials--;
            cout << "Material deleted successfully.\n";
            return;
        }
    }

    setTextColor(14);  
    cout << "Material not found!\n";
    setTextColor(7);  
}


void showMenu() {
    setTextColor(14);  
    cout << "\nInventory Management Menu:\n";
    cout << "1. Show All Materials\n";
    cout << "2. Add New Material\n";
    cout << "3. Update Material Stock\n";
    cout << "4. Sell Material\n";
    cout << "5. Delete Material\n";
    cout << "6. Exit\n";
    setTextColor(7);  
}

int main() {
    showWelcomeMessage();

    int choice;
    do {
        showMenu();  
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                showAllMaterials();
                break;
            case 2:
                addMaterial();
                break;
            case 3:
                updateStock();
                break;
            case 4:
                sellMaterial();
                break;
            case 5:
                deleteMaterial();
                break;
            case 6:
                cout << "Exiting the system...\n";
                break;
            default:
                setTextColor(4);  
                cout << "Invalid choice! Try again.\n";
                setTextColor(7);  
        }
    } while (choice != 6);

    return 0;
}

