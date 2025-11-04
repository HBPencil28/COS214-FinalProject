# COS214 Final Project - Plant Nursery Management System

## Project Description
The Plant Nursery Management System is a comprehensive C++ application designed to simulate and manage the daily operations of a plant nursery.  
It models real-world entities such as plants, staff, zones, deliveries, and customers, while demonstrating a deep understanding of object-oriented programming and software design principles.

The project was developed as part of the COS 214 Software Modelling module at the University of Pretoria and implements twelve classic design patterns (creational, structural, and behavioral).  
It emphasizes modularity, scalability, and flexibility, ensuring that new features can be easily added without modifying existing code.

---

## Design Patterns Implemented

### Creational Patterns
- **Builder Pattern** – Constructs complex plant configurations via `PlantBuilder`, `PotPlantBuilder`, and `WrapPlantBuilder`.
- **Factory Method Pattern** – Creates staff and customer objects using `StaffFactory` and `CustomerFactory`.
- **Prototype Pattern** – Supports cloning of existing plants for efficient duplication.
- **Abstract Factory Pattern** – (Optional extension) Produces related families of plant and wrapping combinations.

### Structural Patterns
- **Decorator Pattern** – Dynamically adds wrapping or decoration features to plants (`PlantDecorator`, `PlantWrap`, `Bow`, `Ribbon`).
- **Composite Pattern** – Manages plant hierarchies and groupings using `PlantComponent`.
- **Adapter Pattern** – (If used) Provides compatibility between differing interfaces.

### Behavioral Patterns
- **State Pattern** – Manages plant lifecycle transitions (`Seedling`, `Growing`, `Mature`, `Withered`).
- **Status Pattern** – Tracks logistical states (`InStorage`, `Sold`, `OutForDelivery`).
- **Strategy Pattern** – Switches between plant care strategies (`LowCare`, `MediumCare`, `HighCare`).
- **Command Pattern** – Encapsulates and executes actions (`CareCommand`, `CustomerCommand`).
- **Iterator Pattern** – Provides sequential traversal of plant collections (`PlantIterator`).
- **Observer Pattern** – Updates dependent systems automatically when plant states change (`PlantObserver`).
- **Mediator Pattern** – Coordinates communication between staff, care commands, and delivery modules.

---

## Configuration Instructions
**Requirements**
- C++11 or later
- GNU Make 4.3 or newer
- SFML library (`libsfml-dev`)
- doctest (included in `/lib`)
- Linux or WSL environment recommended
- Optional: Valgrind for memory checking

**Setup**
## How to set up SFML 
- To download SFML library sudo apt install libsfml-dev
