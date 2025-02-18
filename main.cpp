#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

class Login {
private:
    string password = "Ahmad";

public:
    bool authenticate(string inputPassword) {
        return inputPassword == password;
    }
};

class Car {
private:
    string driverName;
    string carName;
    int carId;
    int timeStay;
    int expense;
    int parkingSpot;

    Car* next;
    Car* prev;

public:
    Car(const string& driver, const string& car, int id, int stay, int spot) {
        driverName = driver;
        carName = car;
        carId = id;
        timeStay = stay;
        if (stay == 24) {
            expense = 2000;
        }
        else {
            expense = stay * 100;
        }
        parkingSpot = spot;
        next = nullptr;
        prev = nullptr;
    }

    int getCarId() const {
        return carId;
    }

    string getDriverName() const {
        return driverName;
    }

    string getCarName() const {
        return carName;
    }

    int getTimeStay() const {
        return timeStay;
    }

    int getExpense() const {
        return expense;
    }

    int getParkingSpot() const {
        return parkingSpot;
    }

    Car* getNext() const {
        return next;
    }

    Car* getPrev() const {
        return prev;
    }

    void setDriverName(const string& name) {
        driverName = name;
    }

    void setCarName(const string& name) {
        carName = name;
    }

    void setCarId(int id) {
        carId = id;
    }

    void setTimeStay(int time) {
        timeStay = time;
        if (time == 24) {
            expense = 2000;
        }
        else {
            expense = time * 100;
        }
    }

    void setExpense(int exp) {
        expense = exp;
    }

    void setParkingSpot(int spot) {
        parkingSpot = spot;
    }

    void setNext(Car* n) {
        next = n;
    }

    void setPrev(Car* p) {
        prev = p;
    }
};

class ParkingManagement {
private:
    Car* head;
    Car* tail;
    static const int TOTAL_SPOTS = 40;
    bool parkingSpots[TOTAL_SPOTS];

public:
    ParkingManagement() {
        head = nullptr;
        tail = nullptr;
        fill_n(parkingSpots, TOTAL_SPOTS, false);
    }

    ~ParkingManagement();

    void park();
    void carDetail();
    void viewExpenses();
    void removeCar();
    void displayAllCarsSorted();
    void displayParkingSpots();
    void changeParkingDuration();

private:
    void insertionSort();
    void clearInputBuffer();
};

ParkingManagement::~ParkingManagement() {
    Car* current = head;
    while (current) {
        Car* next = current->getNext();
        delete current;
        current = next;
    }
}

void ParkingManagement::clearInputBuffer() {
    cin.ignore();
}

void ParkingManagement::displayParkingSpots() {
    system("CLS");
    cout << "-------------> Parking Spots <-------------" << endl << endl;
    cout << "Available spots are marked with [ ] and occupied with [X]" << endl << endl;

    const int spotsPerRow = 10;
    int spotNumber = 1;

    for (int i = 0; i < TOTAL_SPOTS; ++i) {
        if (i % spotsPerRow == 0 && i != 0) {
            cout << endl;
        }

        if (parkingSpots[i]) {
            cout << "[X]";
        }
        else {
            cout << "[" << (i + 1) << "]";
        }

        cout << "   ";

        if ((i + 1) % spotsPerRow == 0 || i == TOTAL_SPOTS - 1) {
            cout << endl;
        }
    }
    cout << endl;
    cout << "Press Enter Key To Return";
    clearInputBuffer();
    cin.get();
}

void ParkingManagement::park() {
    system("CLS");
    cout << "-------------> Car Parking System <-------------" << endl << endl;

    string driver, car;
    int carId, timeStay, spot;

    clearInputBuffer();
    cout << "Enter Your Name : ";
    getline(cin, driver);

    cout << "Enter Your Car Name : ";
    getline(cin, car);

    cout << "Enter Your Car ID (Integer Only) : ";
    cin >> carId;

    cout << "Enter Your Time Stay In Hours (Integer Only) : ";
    cin >> timeStay;

    if (timeStay < 1 || timeStay > 24) {
        cout << "\nInvalid Time Stay. It must be between 1 and 24 hours." << endl;
        cout << "Press Enter Key To Return";
        clearInputBuffer();
        cin.get();
        return;
    }

    displayParkingSpots();
    cout << "Enter Parking Spot Number (1-" << TOTAL_SPOTS << ") : ";
    cin >> spot;

    if (spot < 1 || spot > TOTAL_SPOTS || parkingSpots[spot - 1]) {
        cout << "\nInvalid or Occupied Spot. Try Again!" << endl;
        cout << "Press Enter Key To Return";
        clearInputBuffer();
        cin.get();
        return;
    }

    Car* newCar = new Car(driver, car, carId, timeStay, spot);
    parkingSpots[spot - 1] = true;

    if (head == nullptr) {
        head = tail = newCar;
    }
    else {
        tail->setNext(newCar);
        newCar->setPrev(tail);
        tail = newCar;
    }

    cout << "\nYour Car Is Parked Now!" << endl;
    cout << "Press Enter Key To Return";
    clearInputBuffer();
    cin.get();
}

void ParkingManagement::carDetail() {
    system("CLS");
    int carId;
    bool found = false;

    cout << "-------------> Your Car Details <-------------" << endl << endl;
    cout << "Enter Your Car ID : ";
    cin >> carId;

    Car* current = head;
    while (current) {
        if (current->getCarId() == carId) {
            found = true;
            cout << "\nCar Name: " << current->getCarName() << endl;
            cout << "Driver Name: " << current->getDriverName() << endl;
            cout << "Car Time Stay: " << current->getTimeStay() << " hours" << endl;
            cout << "Total Expense: " << current->getExpense() << " Rupees" << endl;
            cout << "Parking Spot: " << current->getParkingSpot() << endl << endl;
            break;
        }
        current = current->getNext();
    }

    if (!found) {
        cout << "Car With Car ID " << carId << " Not Found" << endl;
    }

    cout << "Press Enter Key To Return";
    clearInputBuffer();
    cin.get();
}

void ParkingManagement::viewExpenses() {
    system("CLS");
    int carId;
    bool found = false;

    cout << "-------------> Car Parking Expenses <-------------" << endl << endl;
    cout << "Enter Your Car ID : ";
    cin >> carId;

    Car* current = head;
    while (current) {
        if (current->getCarId() == carId) {
            found = true;
            cout << "\nCar Name: " << current->getCarName() << endl;
            cout << "Car ID: " << current->getCarId() << endl;
            cout << "Driver Name: " << current->getDriverName() << endl;
            cout << "Car Time Stay: " << current->getTimeStay() << " hours" << endl;
            cout << "Total Expense: " << current->getExpense() << " Rupees" << endl;
            cout << "Parking Spot: " << current->getParkingSpot() << endl << endl;
            break;
        }
        current = current->getNext();
    }

    if (!found) {
        cout << "Car With Car ID " << carId << " Not Found" << endl;
    }

    cout << "Press Enter Key To Return";
    clearInputBuffer();
    cin.get();
}

void ParkingManagement::removeCar() {
    system("CLS");
    int carId;
    bool found = false;

    cout << "-------------> Remove Car <-------------" << endl << endl;
    cout << "Enter Your Car ID : ";
    cin >> carId;

    Car* current = head;
    while (current) {
        if (current->getCarId() == carId) {
            found = true;
            parkingSpots[current->getParkingSpot() - 1] = false;

            if (current == head) {
                head = current->getNext();
                if (head) {
                    head->setPrev(nullptr);
                }
                else {
                    tail = nullptr;
                }
            }
            else if (current == tail) {
                tail = current->getPrev();
                if (tail) {
                    tail->setNext(nullptr);
                }
            }
            else {
                Car* prevCar = current->getPrev();
                Car* nextCar = current->getNext();
                prevCar->setNext(nextCar);
                nextCar->setPrev(prevCar);
            }
            delete current;
            cout << "\nCar Removed Successfully!" << endl;
            break;
        }
        current = current->getNext();
    }

    if (!found) {
        cout << "Car With Car ID " << carId << " Not Found" << endl;
    }

    cout << "Press Enter Key To Return";
    clearInputBuffer();
    cin.get();
}

void ParkingManagement::displayAllCarsSorted() {
    system("CLS");
    cout << "-------------> All Parked Cars (Sorted by Time Stay) <-------------" << endl << endl;

    insertionSort();

    Car* current = head;
    while (current) {
        cout << "Car Name: " << current->getCarName() << endl;
        cout << "Car ID: " << current->getCarId() << endl;
        cout << "Driver Name: " << current->getDriverName() << endl;
        cout << "Car Time Stay: " << current->getTimeStay() << " hours" << endl;
        cout << "Total Expense: " << current->getExpense() << " Rupees" << endl;
        cout << "Parking Spot: " << current->getParkingSpot() << endl << endl;
        current = current->getNext();
    }

    cout << "Press Enter Key To Return";
    clearInputBuffer();
    cin.get();
}

void ParkingManagement::insertionSort() {
    if (!head || !head->getNext()) {
        return;
    }

    Car* sorted = nullptr;

    Car* current = head;
    while (current) {
        Car* next = current->getNext();
        if (!sorted || sorted->getTimeStay() >= current->getTimeStay()) {
            current->setNext(sorted);
            if (sorted) {
                sorted->setPrev(current);
            }
            sorted = current;
            sorted->setPrev(nullptr);
        }
        else {
            Car* temp = sorted;
            while (temp->getNext() && temp->getNext()->getTimeStay() < current->getTimeStay()) {
                temp = temp->getNext();
            }
            current->setNext(temp->getNext());
            if (temp->getNext()) {
                temp->getNext()->setPrev(current);
            }
            temp->setNext(current);
            current->setPrev(temp);
        }
        current = next;
    }

    head = sorted;
    tail = sorted;
    while (tail->getNext()) {
        tail = tail->getNext();
    }
}

void ParkingManagement::changeParkingDuration() {
    system("CLS");
    int carId;
    bool found = false;

    cout << "-------------> Change Parking Duration <-------------" << endl << endl;
    cout << "Enter Your Car ID : ";
    cin >> carId;

    Car* current = head;
    while (current) {
        if (current->getCarId() == carId) {
            found = true;
            int newTimeStay;
            cout << "\nEnter New Time Stay In Hours (Integer Only) : ";
            cin >> newTimeStay;

            if (newTimeStay < 1 || newTimeStay > 24) {
                cout << "\nInvalid Time Stay. It must be between 1 and 24 hours." << endl;
                cout << "Press Enter Key To Return";
                clearInputBuffer();
                cin.get();
                return;
            }

            current->setTimeStay(newTimeStay);
            current->setExpense((newTimeStay == 24) ? 2000 : newTimeStay * 100);

            cout << "\nParking Duration Changed Successfully!" << endl;
            cout << "Press Enter Key To Return";
            clearInputBuffer();
            cin.get();
            return;
        }
        current = current->getNext();
    }

    if (!found) {
        cout << "Car With Car ID " << carId << " Not Found" << endl;
    }

    cout << "Press Enter Key To Return";
    clearInputBuffer();
    cin.get();
}

int main() {
    ParkingManagement pm;
    Login login;
    string password;

    cout << "Enter Password: ";
    cin >> password;

    if (login.authenticate(password)) {
        int choice;
        do {
            system("CLS");
            cout << "-------------> Car Parking Management System <-------------" << endl << endl;
            cout << "1. Park Your Car" << endl;
            cout << "2. View Your Car Details" << endl;
            cout << "3. View Your Car Expenses" << endl;
            cout << "4. Remove Your Car" << endl;
            cout << "5. Display All Parked Cars (Sorted by Time Stay)" << endl;
            cout << "6. Display Parking Spots" << endl;
            cout << "7. Change Parking Duration" << endl;
            cout << "8. Exit" << endl;
            cout << "Enter Your Choice (1-8): ";
            cin >> choice;

            switch (choice) {
            case 1:
                pm.park();
                break;
            case 2:
                pm.carDetail();
                break;
            case 3:
                pm.viewExpenses();
                break;
            case 4:
                pm.removeCar();
                break;
            case 5:
                pm.displayAllCarsSorted();
                break;
            case 6:
                pm.displayParkingSpots();
                break;
            case 7:
                pm.changeParkingDuration();
                break;
            case 8:
                cout << "\nExiting..." << endl;
                break;
            default:
                cout << "\nInvalid Choice. Try Again!" << endl;
            }
        } while (choice != 8);
    }
    else {
        cout << "Authentication Failed. Exiting..." << endl;
    }

    return 0;
}
