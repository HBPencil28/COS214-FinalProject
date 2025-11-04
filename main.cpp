// // main.cpp
// #include <cassert>
// #include <iostream>
// #include <string>
// #include <vector>
// #include <memory>
// #include <limits>

// #include "CareFactory.h"
// #include "CareStaff.h"
// #include "WaterPlant.h"
// #include "FertilisePlant.h"
// #include "Zone.h"
// #include "Manager.h"
// #include "SeniorManager.h"
// #include "NormalStaff.h"
// #include "Plant.h"

// using namespace std;

// // Small helper to print header for each section
// static void header(const string &s) {
//     cout << "\n\n===== " << s << " =====\n";
// }

// // ------------------- Factory Edge Tests -------------------
// void testCareFactory_basic_and_stress() {
//     header("CareFactory - basic & stress");

//     CareFactory factory;

//     // Basic: create one staff
//     Staff* staff = nullptr;
//     try {
//         staff = factory.createStaff();
//         assert(staff != nullptr);
//     } catch (...) {
//         cerr << "CareFactory::createStaff threw an exception on basic call\n";
//         assert(false);
//     }
//     delete staff;

//     // Stress: create and delete many times
//     const int N = 200;
//     vector<Staff*> arr;
//     arr.reserve(N);
//     for (int i = 0; i < N; ++i) {
//         Staff* s = nullptr;
//         try {
//             s = factory.createStaff();
//             assert(s != nullptr);
//         } catch (...) {
//             cerr << "CareFactory::createStaff threw during stress at i=" << i << "\n";
//             assert(false);
//         }
//         arr.push_back(s);
//     }
//     for (Staff* s : arr) delete s;

//     // Repeated allocate / deallocate cycle
//     for (int k = 0; k < 10; ++k) {
//         Staff* s = factory.createStaff();
//         delete s;
//     }

//     cout << "CareFactory tests passed.\n";
// }

// // ------------------- Command Edge Tests -------------------
// void testCareCommand_various_zones_and_amounts() {
//     header("CareCommand - zones & amounts");

//     CareStaff staff; // receiver

//     // 1) Zone with no children
//     Zone emptyZone("Empty", "Category", &staff);
//     CareCommand* wc1 = new WaterPlant(&staff, 0);
//     CareCommand* fc1 = new FertilisePlant(&staff, 0);
//     // Should not throw, even with zero amount
//     try {
//         wc1->execute(&emptyZone);
//         fc1->execute(&emptyZone);
//     } catch (...) {
//         cerr << "Commands threw on empty zone\n";
//         assert(false);
//     }
//     delete wc1;
//     delete fc1;

//     // 2) Zone with one plant (create a minimal Plant)
//     Zone plantZone("TestZone", "Flowers", &staff);
//     Plant* p = new Plant("TestRose", "Flowers");
//     plantZone.add(p);

//     // normal positive amounts
//     CareCommand* wc2 = new WaterPlant(&staff, 5);
//     CareCommand* fc2 = new FertilisePlant(&staff, 3);

//     try {
//         wc2->execute(&plantZone);
//         fc2->execute(&plantZone);
//     } catch (...) {
//         cerr << "Commands threw on zone with plant\n";
//         assert(false);
//     }

//     // negative amount (edge case) - system should not crash
//     CareCommand* wcNeg = new WaterPlant(&staff, -10);
//     CareCommand* fcNeg = new FertilisePlant(&staff, -5);
//     try {
//         wcNeg->execute(&plantZone);
//         fcNeg->execute(&plantZone);
//     } catch (...) {
//         cerr << "Commands threw on negative amount\n";
//         assert(false);
//     }

//     // very large amount
//     CareCommand* wcLarge = new WaterPlant(&staff, numeric_limits<int>::max()/1000);
//     CareCommand* fcLarge = new FertilisePlant(&staff, numeric_limits<int>::max()/1000);
//     try {
//         wcLarge->execute(&plantZone);
//         fcLarge->execute(&plantZone);
//     } catch (...) {
//         cerr << "Commands threw on large amount\n";
//         assert(false);
//     }

//     // repeated execution (idempotence / multiple effects)
//     try {
//         for (int i = 0; i < 5; ++i) {
//             wc2->execute(&plantZone);
//             fc2->execute(&plantZone);
//         }
//     } catch (...) {
//         cerr << "Commands threw during repeated execution\n";
//         assert(false);
//     }

//     // Null zone pointer (some implementations may assert; wrap in try)
//     CareCommand* wcNull = new WaterPlant(&staff, 1);
//     CareCommand* fcNull = new FertilisePlant(&staff, 1);
//     try {
//         // If execute expects non-null this may crash; we catch to avoid terminating
//         wcNull->execute(nullptr);
//         fcNull->execute(nullptr);
//     } catch (...) {
//         // acceptable as long as program does not UB silently; fail if it crashes the test runner
//         cout << "Warning: execute(nullptr) threw an exception (check implementation) - acceptable for defensive test.\n";
//     }

//     // clean up
//     delete wc2;
//     delete fc2;
//     delete wcNeg;
//     delete fcNeg;
//     delete wcLarge;
//     delete fcLarge;
//     delete wcNull;
//     delete fcNull;

//     // remove plant
//     //delete p;
//     // ensure zone children cleared if applicable (no memory leaks in test environment)
//     cout << "CareCommand tests passed.\n";
// }

// // ------------------- Chain of Responsibility Edge Tests -------------------
// void testChainOfResponsibility_varied_requests() {
//     cout << "\n=== Testing Chain of Responsibility (edge cases) ===" << endl;

//     // Use stack allocation (no need for new/delete)
//     NormalStaff normal;
//     Manager manager;
//     SeniorManager senior;

//     // Set up the chain
//     normal.setNextHandler(&manager);
//     manager.setNextHandler(&senior);

//     // Test empty and whitespace requests
//     normal.handleRequest(std::string(""));
//     normal.handleRequest(std::string("   "));

//     // Test case sensitivity
//     normal.handleRequest(std::string("CARE REQUEST")); // depends on implementation
//     normal.handleRequest(std::string("inventory"));
//     normal.handleRequest(std::string("unknown request"));

//     // Test long string input
//     std::string longReq(1000, 'x');
//     normal.handleRequest(longReq);

//     // Disconnect the manager and test chain break
//     normal.setNextHandler(NULL);
//     normal.handleRequest("inventory"); // manager not reachable

//     // Reconnect the chain
//     normal.setNextHandler(&manager);
//     manager.setNextHandler(NULL);
//     normal.handleRequest("inventory"); // manager reachable, senior not

//     // Reconnect fully again
//     manager.setNextHandler(&senior);
//     normal.handleRequest("inventory");
//     normal.handleRequest("care request");
//     normal.handleRequest("something weird");

//     cout << "✅ Chain of Responsibility edge cases passed successfully." << endl;
// }


// // ------------------- Combined integration-ish tests -------------------
// void testIntegration_sequence() {
//     header("Integration - sequence");

//     // Use stack CareStaff to avoid ownership/lifetime issues
//     CareStaff care;           // stack-allocated receiver (no delete necessary)

//     // create a zone that references the care staff (stack lifetime is sufficient)
//     {
//         Zone z("IvyZone", "Herbs", &care);

//         // create a plant and add it to the zone — do NOT delete it manually after adding
//         Plant* p = new Plant("Basil", "Herbs");
//         z.add(p); // assume Zone takes ownership

//         CareCommand* w = new WaterPlant(&care, 2);
//         CareCommand* f = new FertilisePlant(&care, 1);

//         // execute a few times
//         for (int i = 0; i < 3; ++i) {
//             w->execute(&z);
//             f->execute(&z);
//         }

//         // cleanup commands (we allocated these)
//         delete w;
//         delete f;

//         // DO NOT delete p here — Zone likely owns it and will delete it in its destructor
//         // When 'z' goes out of scope below, it will clean up its children safely.
//     } // z is destroyed here (Zone destructor runs)

//     // Do NOT delete 'care' - it's stack-allocated and will be destroyed automatically
//     // Do NOT call delete on other handlers or successors created on the stack elsewhere.

//     cout << "Integration tests passed.\n";
// }

// // ------------------- Main -------------------
// int main() {
//     cout << "===== EXTENDED EDGE-CASE UNIT TESTING START =====\n";

//     testCareFactory_basic_and_stress();
//     testCareCommand_various_zones_and_amounts();
//     testChainOfResponsibility_varied_requests();
//     testIntegration_sequence();

//     cout << "\n===== ALL EXTENDED TESTS COMPLETED =====\n";
//     return 0;
// }
