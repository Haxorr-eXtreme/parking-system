# Car Parking Management System

A comprehensive C++ console application for managing a parking lot with 40 parking spots. This system provides complete parking management functionality including car registration, spot allocation, expense calculation, and administrative features.

## Features

###  Authentication
- Password-protected system access
- Default password: `Ahmad`
- Secure login verification

###  Car Parking Management
- **Park a Car**: Register new vehicles with driver details
- **View Car Details**: Retrieve information about parked vehicles
- **Remove Car**: Check out vehicles and free up parking spots
- **Change Parking Duration**: Modify parking time and recalculate expenses

###  Expense Management
- **Automatic Pricing**: 
  - 100 per hour for regular parking
  - 2000 flat rate for 24-hour parking
- **View Expenses**: Check parking costs for any vehicle
- **Real-time Calculation**: Expenses update automatically when duration changes

###  Administrative Features
- **Display All Cars**: View all parked vehicles sorted by parking duration
- **Parking Spots Visualization**: Visual representation of available/occupied spots
- **Spot Management**: 40 parking spots with real-time availability tracking

## System Architecture

### Classes

#### `Login` Class
- Handles user authentication
- Password verification system

#### `Car` Class
- Represents a parked vehicle
- Stores driver information, car details, and parking data
- Implements doubly-linked list structure for efficient management
- Automatic expense calculation based on parking duration

#### `ParkingManagement` Class
- Main system controller
- Manages parking spots and car records
- Implements insertion sort for organized data display
- Handles all parking operations

## Data Structure

- **Doubly-Linked List**: Efficient car record management
- **Array-based Spot Tracking**: 40 boolean flags for spot availability
- **Insertion Sort**: Sorts cars by parking duration for display

## Usage

### Prerequisites
- C++ compiler (g++, Visual Studio, etc.)
- Windows/Linux/macOS terminal

### Compilation
```bash
g++ -o parking_system main.cpp
```

### Running the Program
```bash
./parking_system
```

### System Flow
1. **Login**: Enter password to access the system
2. **Main Menu**: Choose from 8 available options
3. **Operations**: Perform parking management tasks
4. **Exit**: Safely terminate the program

## Menu Options

1. **Park Your Car** - Register a new vehicle
2. **View Your Car Details** - Get information about a specific car
3. **View Your Car Expenses** - Check parking costs
4. **Remove Your Car** - Check out and free parking spot
5. **Display All Parked Cars** - View all vehicles (sorted by duration)
6. **Display Parking Spots** - Visual spot availability
7. **Change Parking Duration** - Modify parking time
8. **Exit** - Close the application

## Input Requirements

### Car Registration
- **Driver Name**: Full name of the vehicle owner
- **Car Name**: Vehicle make/model
- **Car ID**: Unique integer identifier
- **Time Stay**: Hours (1-24)
- **Parking Spot**: Spot number (1-40)

### Validation
- Time stay must be between 1-24 hours
- Parking spots must be available and within range
- Car ID must be unique integer
- All fields are required

## Pricing Structure

| Duration | Rate | Total Cost |
|----------|------|------------|
| 1-23 hours | ₹100/hour | Duration × ₹100 |
| 24 hours | Flat rate | ₹2000 |

## Technical Details

### Memory Management
- Dynamic memory allocation for car objects
- Proper destructor implementation
- Automatic cleanup on program exit

### User Interface
- Console-based interface
- Clear screen operations for better UX
- Input validation and error handling
- Press Enter to continue prompts

### Data Persistence
- In-memory storage (data lost on program exit)
- Real-time spot availability tracking
- Automatic expense recalculation

## Error Handling

- Invalid time duration validation
- Occupied spot prevention
- Non-existent car ID handling
- Input buffer management
- Authentication failure handling

## System Limitations

- Data is not persisted between sessions
- Single user system (no multi-user support)
- No payment processing integration
- No time-based automatic checkout
- Fixed 40-spot capacity

## Future Enhancements

- Database integration for data persistence
- Multi-user support with role-based access
- Payment gateway integration
- Automatic time tracking and notifications
- Web-based interface
- Mobile app integration
- Advanced reporting and analytics

## License

This project is open source and available under the MIT License.

## Contributing

Contributions are welcome! Please feel free to submit pull requests or open issues for bugs and feature requests.

## Support

For support or questions, please open an issue in the project repository.
