#include <iostream>
#include <string>
#include <vector>
#include <stdexcept>

class LibraryItem {
protected:
    std::string title;
    int item_id;
    bool checked_out;

public:
    LibraryItem(const std::string& _title, int _item_id)
        : title(_title), item_id(_item_id), checked_out(false) {}

    void check_out(int user_id) {
        if (checked_out) {
            throw std::runtime_error("Item is already checked out.");
        }
        checked_out = true;
        std::cout << "Item '" << title << "' checked out by User #" << user_id << std::endl;
    }

    void return_item() {
        checked_out = false;
        std::cout << "Item '" << title << "' returned." << std::endl;
    }

    bool is_checked_out() const {
        return checked_out;
    }

    virtual void display_info() const {
        std::cout << "Title: " << title << std::endl;
    }
};

class Book : public LibraryItem {
private:
    std::string author;

public:
    Book(const std::string& _title, int _item_id, const std::string& _author)
        : LibraryItem(_title, _item_id), author(_author) {}

    void display_info() const override {
        std::cout << "Book Information:" << std::endl;
        LibraryItem::display_info();
        std::cout << "Author: " << author << std::endl;
    }
};

class DVD : public LibraryItem {
private:
    std::string director;

public:
    DVD(const std::string& _title, int _item_id, const std::string& _director)
        : LibraryItem(_title, _item_id), director(_director) {}

    void display_info() const override {
        std::cout << "DVD Information:" << std::endl;
        LibraryItem::display_info();
        std::cout << "Director: " << director << std::endl;
    }
};

class User {
private:
    int user_id;
    std::string name;
    std::vector<LibraryItem*> checked_out_items;

public:
    User(int _user_id, const std::string& _name)
        : user_id(_user_id), name(_name) {}

    void check_out_item(LibraryItem* item) {
        if (item->is_checked_out()) {
            throw std::runtime_error("Item is already checked out.");
        }
        item->check_out(user_id);
        checked_out_items.push_back(item);
    }

    void return_item(LibraryItem* item) {
        if (std::find(checked_out_items.begin(), checked_out_items.end(), item) == checked_out_items.end()) {
            throw std::runtime_error("Item is not checked out by this user.");
        }
        item->return_item();
        checked_out_items.erase(std::remove(checked_out_items.begin(), checked_out_items.end(), item), checked_out_items.end());
    }

    void display_checked_out_items() const {
        std::cout << "User #" << user_id << " (" << name << ") has checked out the following items:" << std::endl;
        for (const LibraryItem* item : checked_out_items) {
            item->display_info();
            std::cout << std::endl;
        }
    }
};

int main() {
    // Create library items
    Book book1("The Great Gatsby", 1, "F. Scott Fitzgerald");
    Book book2("To Kill a Mockingbird", 2, "Harper Lee");
    DVD dvd1("The Shawshank Redemption", 3, "Frank Darabont");
    DVD dvd2("Inception", 4, "Christopher Nolan");

    // Create users
    User user1(101, "Alice");
    User user2(102, "Bob");

    // Demonstrate check out and return operations
    try {
        user1.check_out_item(&book1);
        user2.check_out_item(&dvd1);
        user1.display_checked_out_items();

        user1.check_out_item(&book2); // This will throw an exception
    } catch (const std::runtime_error& e) {
        std::cerr << "Error: " << e.what() << std::endl;
    }

    user2.return_item(&dvd1);
    user1.display_checked_out_items();

    return 0;
}
