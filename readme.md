# 🛒 Supermarket Billing System

A simple command-line-based Supermarket Billing System written in C++ for managing item inventory and generating customer bills. This project supports adding items to the inventory, handling purchases, and printing the final bill.

---

## 📋 Features

- Add new items with name, rate, and quantity
- Store item inventory in a text file (`Bill.txt`)
- Generate and display customer bills
- Deduct purchased quantities from inventory
- Simple text-based menu interface
- Windows-compatible (uses `windows.h`)

---

## 🛠️ Requirements

- C++ Compiler (e.g., g++, MSVC)
- Windows OS (due to `windows.h` and `Sleep()` usage)
- Text file path must exist:  
  `C:/Users/LENOVO/Desktop/OK tested/Bill.txt`

---

## 🚀 How to Run

1. **Clone the repository** (or copy the code):
   ```bash
   git clone https://github.com/your-username/supermarket-billing-system.git
   ```

2. **Open the project in your favorite C++ IDE or compile via terminal:**
   ```bash
   g++ -o billing main.cpp
   ```

3. **Run the executable:**
   ```bash
   ./billing
   ```

4. **Follow the menu prompts:**
   - `1` → Add Item
   - `2` → Print Bill
   - `3` → Exit

---

## 📂 File Structure

```
supermarket-billing-system/
├── main.cpp        # Source code for the billing system
├── Bill.txt        # Inventory file (created after adding items)
```

> Note: Make sure the directory `C:/Users/LENOVO/Desktop/OK tested/` exists before running.

---

## 🧱 Class Overview

### `Bill`
- **Attributes**: `Item`, `Rate`, `Quantity`
- **Methods**: Setters & Getters for each attribute

### Core Functions
- `addItem(Bill b)` – Adds a new item to the inventory
- `printBill()` – Handles customer purchases and displays total bill

---

## 📌 Future Improvements

- Input validation and error handling
- Cross-platform compatibility (replace `windows.h`)
- Use CSV or database instead of plain text
- GUI with frameworks like Qt or wxWidgets

---

## 📃 License

This project is open source and available under the [MIT License](LICENSE).

---

## 🙋‍♂️ Author

**Siddharth Pandey** 