
# Test Cases – Campus Route Finder

## Test Case 1: Direct Route

Input:
- Source: 0 (Main Gate)
- Destination: 1 (Library)

Expected Output:
Main Gate -> Library
Total edges: 1

Result: Pass

## Test Case 2: Multi-Stop Shortest Route

Input:
- Source: 0 (Main Gate)
- Destination: 5 (Auditorium)

Expected Output:
A shortest route containing 3 edges.

Example:
Main Gate -> Block 1 -> Cafeteria -> Auditorium

Result: Pass

## Test Case 3: Unreachable Destination

Input:
- Source: 0 (Main Gate)
- Destination: 6 (Parking)

Expected Output:
No route exists between Main Gate and Parking.

Result: Pass

## Conclusion
All three test cases were executed successfully.
