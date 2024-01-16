#include <iostream>

template <typename T>
class LinkedList {
private:
    struct Node {
        T data;
        Node* next;

        Node(const T& val) : data(val), next(nullptr) {}
    };

    Node* head;

public:
    LinkedList() : head(nullptr) {}

    // Конструктор копіювання
    LinkedList(const LinkedList& other) : head(nullptr) {
        Node* otherCurrent = other.head;
        Node* current = nullptr;

        while (otherCurrent != nullptr) {
            if (head == nullptr) {
                head = new Node(otherCurrent->data);
                current = head;
            }
            else {
                current->next = new Node(otherCurrent->data);
                current = current->next;
            }

            otherCurrent = otherCurrent->next;
        }
    }

    ~LinkedList() {
        while (head != nullptr) {
            Node* temp = head;
            head = head->next;
            delete temp;
        }
    }

    // Операція клонування списку
    LinkedList clone() const {
        return LinkedList(*this);
    }

    // Перевантаження оператора "+"
    LinkedList operator+(const LinkedList& other) const {
        LinkedList result(*this);

        Node* current = result.head;
        while (current->next != nullptr) {
            current = current->next;
        }

        Node* otherCurrent = other.head;
        while (otherCurrent != nullptr) {
            current->next = new Node(otherCurrent->data);
            current = current->next;
            otherCurrent = otherCurrent->next;
        }

        return result;
    }

    // Перевантаження оператора "*"
    LinkedList operator*(const LinkedList& other) const {
        LinkedList result;

        Node* current = head;
        while (current != nullptr) {
            Node* otherCurrent = other.head;
            while (otherCurrent != nullptr) {
                if (current->data == otherCurrent->data) {
                    result.pushBack(current->data);
                    break;
                }
                otherCurrent = otherCurrent->next;
            }
            current = current->next;
        }

        return result;
    }

    // Додавання елемента в кінець списку
    void pushBack(const T& value) {
        Node* newNode = new Node(value);
        if (head == nullptr) {
            head = newNode;
        }
        else {
            Node* current = head;
            while (current->next != nullptr) {
                current = current->next;
            }
            current->next = newNode;
        }
    }

    // Друк списку
    void print() const {
        Node* current = head;
        while (current != nullptr) {
            std::cout << current->data << " ";
            current = current->next;
        }
        std::cout << std::endl;
    }
};

int main() {
    LinkedList<int> list1;
    list1.pushBack(1);
    list1.pushBack(2);
    list1.pushBack(3);

    LinkedList<int> list2;
    list2.pushBack(2);
    list2.pushBack(3);
    list2.pushBack(4);

    std::cout << "List 1: ";
    list1.print();

    std::cout << "List 2: ";
    list2.print();

    LinkedList<int> clonedList = list1.clone();
    std::cout << "Cloned List: ";
    clonedList.print();

    LinkedList<int> combinedList = list1 + list2;
    std::cout << "Combined List: ";
    combinedList.print();

    LinkedList<int> commonElementsList = list1 * list2;
    std::cout << "Common Elements List: ";
    commonElementsList.print();

    return 0;
}
