
#include <iostream>

#include "Earth_Soldier_Queue.h" // Assuming you have defined Earth_SoldierQueue class
#include "Alien_Soldier_Queue.h"
#include"ET_stack.h"
#include "Alien_Drones_Queues.h"
#include "Earth_Gunnery_PQueue.h"
#include "Monster_Array.h"
#include"Game.h"
#include <cstdlib>
#include <ctime>
int main() {
    // Create some Earth_Soldier objects
    //Earth_Soldier* soldier1 = new Earth_Soldier(100, 50, 1, 10, 5);
    //Earth_Soldier* soldier2 = new Earth_Soldier(150, 60, 2, 12, 6);
    //Earth_Soldier* soldier3 = new Earth_Soldier(120, 55, 3, 11, 7);

    //// Create an Earth_SoldierQueue object
    //Earth_SoldierQueue soldierQueue;

    //// Enqueue the soldiers into the queue
    //soldierQueue.enqueue(soldier1);
    //soldierQueue.enqueue(soldier2);
    //soldierQueue.enqueue(soldier3);
    //soldierQueue.print();

    //// Display the front soldier in the queue
    //Earth_Soldier* frontSoldier = soldierQueue.peek();
    //if (frontSoldier != nullptr) {
    //    std::cout << "Front Soldier: ID = " << frontSoldier->getID() << std::endl;
    //}
    //else {
    //    std::cout << "Queue is empty!" << std::endl;
    //}

    //// Dequeue and display all soldiers from the queue
    //while (!soldierQueue.isEmpty()) {
    //    Earth_Soldier* dequeuedSoldier = soldierQueue.dequeue();
    //    std::cout << "Dequeued Soldier: ID = " << dequeuedSoldier->getID() << std::endl;
    //    delete dequeuedSoldier; // Deallocate memory
    //}
    //// Create some Earth_Soldier objects
    //Alien_Soldier* soldier11 = new Alien_Soldier(100, 50, 1, 10, 5);
    //Alien_Soldier* soldier22 = new Alien_Soldier(150, 60, 2, 12, 6);
    //Alien_Soldier* soldier33 = new Alien_Soldier(120, 55, 3, 11, 7);

    ////// Create an Alien_SoldierQueue object
    //Alien_SoldierQueue AsoldierQueue;

    //// Enqueue the soldiers into the queue
    //AsoldierQueue.enqueue(soldier11);
    //AsoldierQueue.enqueue(soldier22);
    //AsoldierQueue.enqueue(soldier33);
    //AsoldierQueue.print();
    //// Display the front soldier in the queue
    //Alien_Soldier* AfrontSoldier = AsoldierQueue.peek();
    //if (AfrontSoldier != nullptr) {
    //    std::cout << "Front Soldier: ID = " << AfrontSoldier->getID() << std::endl;
    //}
    //else {
    //    std::cout << "Queue is empty!" << std::endl;
    //}

    //// Dequeue and display all soldiers from the queue
    //while (!AsoldierQueue.isEmpty()) {
    //    Alien_Soldier* AdequeuedSoldier = AsoldierQueue.dequeue();
    //    std::cout << "Dequeued Soldier: ID = " << AdequeuedSoldier->getID() << std::endl;
    //    delete AdequeuedSoldier; // Deallocate memory
    //}

    // Create some Earth_Soldier objects
//    ETank* Tank1 = new ETank(100, 50, 1, 10, 5);
//    ETank* Tank2 = new ETank(150, 60, 2, 12, 6);
//    ETank* Tank3 = new ETank(120, 55, 3, 11, 7);
//
////     Create an ETankQueue object
//    ET_stack ATankstack;
//
//  //   push the Tanks into the queue
//    ATankstack.push(Tank1);
//    ATankstack.push(Tank2);
//    ATankstack.push(Tank3);
//    ATankstack.print();
    //// Display the front Tank in the stack
    //ETank* ATopTank = ATankstack.peek();
    //if (ATopTank != nullptr) {
    //    std::cout << "Top Tank: ID = " << ATopTank->getID() << std::endl;
    //}
    //else {
    //    std::cout << "stack is empty!" << std::endl;
    //}

    //// Destack and display all Tanks from the stack
    //while (!ATankstack.isEmpty()) {
    //    ETank* poppedstackdTank = ATankstack.pop();
    //    std::cout << "popped Tank: ID = " << poppedstackdTank->getID() << std::endl;
    //    delete poppedstackdTank; // Deallocate memory
    //}
    //////////////////////////////////////////////////////////****************************************///////////////////////////////////////////
    //Alien_Drone* Drone1 = new Alien_Drone(100, 50, 1, 10, 5);
    //Alien_Drone* Drone2 = new Alien_Drone(150, 60, 2, 12, 6);
    //Alien_Drone* Drone3 = new Alien_Drone(120, 55, 3, 11, 7);

    //// Create an Alien_DroneQueue object
    //Alien_DroneQueue DroneQueue;

    //// Enqueue the Drones into the queue
    //DroneQueue.enqueue(Drone1);
    //DroneQueue.enqueue(Drone2);
    //DroneQueue.enqueue(Drone3);
    //DroneQueue.print();

    //// Display the front Drone in the queue
    //Alien_Drone* frontDrone = DroneQueue.peek();
    //if (frontDrone != nullptr) {
    //    std::cout << "Front Drone: ID = " << frontDrone->getID() << std::endl;
    //}
    //else {
    //    std::cout << "Queue is empty!" << std::endl;
    //}

    //// Dequeue and display all Drones from the queue
    //while (!DroneQueue.isEmpty()) {
    //    Alien_Drone* dequeuedDrone = DroneQueue.dequeue();
    //    std::cout << "Dequeued Drone: ID = " << dequeuedDrone->getID() << std::endl;
    //    delete dequeuedDrone; // Deallocate memory
    //}
    //Earth_Gunnery_PQueue gunneryQueue;

    //// Example usage: adding Earth_Gunnery objects to the queue
    //Earth_Gunnery* gunnery1 = new Earth_Gunnery(100, 50, 1, 10, 20);
    //Earth_Gunnery* gunnery2 = new Earth_Gunnery(150, 30, 2, 15, 25);
    //Earth_Gunnery* gunnery3 = new Earth_Gunnery(80, 70, 3, 20, 15);

    // //Calculate priority for each Earth_Gunnery object (sum of power and health)
    //int priority1 = gunnery1->gethealth() + gunnery1->getpower();
    //int priority2 = gunnery2->gethealth() + gunnery2->getpower();
    //int priority3 = gunnery3->gethealth() + gunnery3->getpower();

    // //Enqueue Earth_Gunnery objects based on priority
    //gunneryQueue.enqueue(gunnery1, priority1);
    //gunneryQueue.enqueue(gunnery2, priority2);
    //gunneryQueue.enqueue(gunnery3, priority3);
    //gunneryQueue.print();

    //// Display the front Earth_Gunnery in the queue if it exists
    //Earth_Gunnery* frontGunnery;
    //int frontPriority;
    //if (gunneryQueue.peek(frontGunnery, frontPriority)) {
    //    cout << "Front Earth_Gunnery ID in the queue: " << frontGunnery->getID() << endl;
    //}
    //else {
    //    cout << "The queue is empty." << endl;
    //}

    //// Dequeue and display all Earth_Gunnery IDs from the queue
    //cout << "Dequeued and displayed Earth_Gunnery IDs:\n";
    //while (!gunneryQueue.isEmpty()) {
    //    Earth_Gunnery* dequeuedGunnery;
    //    int dequeuedPriority;
    //    gunneryQueue.dequeue(dequeuedGunnery, dequeuedPriority);

    //    cout << "ID: " << dequeuedGunnery->getID() << endl;

    //    delete dequeuedGunnery; // Deallocate memory
    //}
    //// Create a MonsterArray object
    //Monster_Array monsterArray;

    ////// Create and add 5 different monsters to the array
    //Alien_Monster* monster1 = new Alien_Monster(100, 50, 1, 10, 20);
    //Alien_Monster* monster2 = new Alien_Monster(150, 70, 2, 15, 25);
    //Alien_Monster* monster3 = new Alien_Monster(80, 40, 3, 20, 30);
    //Alien_Monster* monster4 = new Alien_Monster(120, 60, 4, 25, 15);
    //Alien_Monster* monster5 = new Alien_Monster(200, 90, 5, 30, 40);

    //monsterArray.addMonster(monster1);
    //monsterArray.addMonster(monster2);
    //monsterArray.addMonster(monster3);
    //monsterArray.addMonster(monster4);
    //monsterArray.addMonster(monster5);
    //monsterArray.print();
    //// Display the count of monsters in the array
    //cout << "Number of monsters: " << monsterArray.getCount() << endl;

    //// Display the IDs of all monsters in the array
    //cout << "Monster IDs in the array:" << endl;
    //for (int i = 0; i < monsterArray.getCount(); ++i) {
    //    cout << "ID: " << monsterArray.getMonster(i)->getID() << endl;
    //}

    //// Delete a monster by ID
    //int idToDelete = 3;
    //cout << "Deleting monster with ID " << idToDelete << endl;
    //monsterArray.removeMonster();

    //// Display the count of monsters after deletion
    //cout << "Number of monsters after deletion: " << monsterArray.getCount() << endl;

    //// Display the IDs of all monsters in the array after deletion
    //cout << "Monster IDs in the array after deletion:" << endl;
    //for (int i = 0; i < monsterArray.getCount(); ++i) {
    //    cout << "ID: " << monsterArray.getMonster(i)->getID() << endl;
    //}



Game game("test.txt");
srand(time(0));
game.go();

//string filename;
//cout << "Enter the filename (no more than 20 characters): ";
//cin >> filename;
//game.inputFunc( filename);
// is this correct
//game.getRG()->setN(7);
//game.getRG()->setProb(30);
//game.getRG()->setES(70);
//game.getRG()->setET(20);
//game.getRG()->setEG(10);
//game.getRG()->setAS(80);
//game.getRG()->setAM(12);
//game.getRG()->setAD(8);
//srand(time(0));
//
//while (game.getRG()->gettimestep() <= 50)
//{
//    game.getRG()->RandFunc();
//    int New_st = game.getRG()->gettimestep() + 1;
//    game.getRG()->settimestep(New_st);
//}
//game.getEA()->print();
//game.getAA()->print();


}