#include <iostream>

template <typename T>
class Stack {
private:
    struct Node {
        T data;
        Node* next;

        Node(const T& val) : data(val), next(nullptr) {}
    };

    Node* top;
    size_t size;

public:
    Stack() : top(nullptr), size(0) {}

    ~Stack() {
        while (!isEmpty()) {
            pop();
        }
    }

    bool isEmpty() const {
        return top == nullptr;
    }

    size_t getSize() const {
        return size;
    }

    void push(const T& value) {
        Node* newNode = new Node(value);
        newNode->next = top;
        top = newNode;
        size++;
    }

    void pop() {
        if (!isEmpty()) {
            Node* temp = top;
            top = top->next;
            delete temp;
            size--;
        }
    }

    T& getTop() const {
        if (!isEmpty()) {
            return top->data;
        }
        else {
            throw std::out_of_range("Stack is empty");
        }
    }
};

int main() {
    Stack<int> myStack;

    int choice;
    int value;

    do {
        std::cout << "1. Push\n";
        std::cout << "2. Pop\n";
        std::cout << "3. Get Top\n";
        std::cout << "4. Quit\n";
        std::cout << "Enter your choice: ";
        std::cin >> choice;

        switch (choice) {
        case 1:
            std::cout << "Enter value to push: ";
            std::cin >> value;
            myStack.push(value);
            break;
        case 2:
            try {
                myStack.pop();
                std::cout << "Pop operation successful.\n";
            }
            catch (const std::out_of_range& e) {
                std::cerr << e.what() << std::endl;
            }
            break;
        case 3:
            try {
                std::cout << "Top element: " << myStack.getTop() << std::endl;
            }
            catch (const std::out_of_range& e) {
                std::cerr << e.what() << std::endl;
            }
            break;
        case 4:
            std::cout << "Exiting program.\n";
            break;
        default:
            std::cout << "Invalid choice. Please try again.\n";
        }

    } while (choice != 4);

    return 0;
}
