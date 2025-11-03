#ifndef GUI_H
#define GUI_H
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <cmath>
#include <iostream>
#include <string>
#include "Inventory.h"
#include "PlantIterator.h"
#include "Plant.h"
#include <algorithm>
#include <fstream>
#include <map>
#include <vector>
#include <random>

using namespace std;
using namespace sf;

// Customer structure to track individual customers
struct Customer {
    Sprite sprite;
    Sprite speechBubble;
    Vector2f targetPos;
    Vector2f currentPos;
    float alpha;
    bool isMoving;
    bool hasArrived;
    Clock animationClock;
    int customerType; // Which customer image (1-N)
    
    Customer() : alpha(0.f), isMoving(true), hasArrived(false), customerType(1) {}
};

class gui : public RenderWindow{
    private: 
    int width, height;
    Font font;
    Inventory* inventory;
    std::map<std::string, Texture> textureCache;
    float scrollOffset;
    
    // Customer management
    std::vector<Customer> activeCustomers;
    Clock customerSpawnClock;
    float customerSpawnInterval;
    int maxCustomers;
    vector<Zone*>* ExistingZones;
    std::mt19937 rng;

        // zones.push_back(new Zone("Flower Bed", "Flower", careGiver));
    // zones.push_back(new Zone("Desert","Cactus&Succulent",careGiver));
    // zones.push_back(new Zone("Herbs and Aromatics","Herb&Aromatic",careGiver));
    // zones.push_back(new Zone("Trees and Shrubs","Tree&ShrubGarden",careGiver));

    //Flowers mgmt
    Sprite* FlowerBed = nullptr;
    //Cactuses&Succulents
    Sprite* Desert = nullptr;
    //herbsAndAromatics
    Sprite* HerbsAndAromatics = nullptr;
    // TreeAndShrub
    Sprite* TreeAndShrub = nullptr; 

    //
    Vector2f greenhousePosition;



    public:
    gui(VideoMode mode, const string& title, Uint32 style = Style::Default, Inventory* inv = nullptr,vector<Zone*>* zones = nullptr) 
        : RenderWindow(mode, title, style), inventory(inv), scrollOffset(0.f),ExistingZones(zones), 
          customerSpawnInterval(5.f), maxCustomers(3), rng(std::random_device{}()){
        width = mode.width;
        height = mode.height;
        this->setFramerateLimit(60);
        this->setSize(Vector2u(mode.width, mode.height));
        this->setPosition(Vector2i((VideoMode::getDesktopMode().width - width) / 2, 
                                   (VideoMode::getDesktopMode().height - height) / 2));

        if (!font.loadFromFile("ARIAL.TTF")) {
            cout << "Failed to load font ARIAL.TTF" << endl;
        } else {
            cout << "Font loaded successfully!" << endl;
        }

        if (!this->isOpen()) {
            cout << "Failed to create window!" << endl;
        } else {
            cout << "Window created successfully!" << endl;
        }
    }
   
    ~gui() {
        if (this->isOpen()) this->close();
        cout << "Window closed." << endl;
    }

    void displayWindow() {
        const float scrollStep = 30.f;
        
        while (this->isOpen()) {
            Event event;
            while (this->pollEvent(event)) {
                if (event.type == Event::Closed) {
                    this->close();
                }
                else if (event.type == Event::MouseWheelScrolled) {
                    if (event.mouseWheelScroll.wheel == Mouse::VerticalWheel) {
                        scrollOffset -= event.mouseWheelScroll.delta * scrollStep;
                        if (scrollOffset < 0.f) scrollOffset = 0.f;
                    }
                }
            }
            
            // Auto-spawn customers
            // if (customerSpawnClock.getElapsedTime().asSeconds() >= customerSpawnInterval) {
            //     if (activeCustomers.size() < maxCustomers) {
            //         spawnCustomer();
            //     }
            //     customerSpawnClock.restart();
            // }
            
            this->clear(Color::White);
            this->displayStore();
            // this->displayCustomers(); // Draw customers
            this->displayInventory();
            this->displaySeedsinZone();
            this->display();
        }
    }

    Texture* loadTexture(const string& filepath) {
        auto it = textureCache.find(filepath);
        if (it != textureCache.end()) {
            return &(it->second);
        }
        
        Texture& texture = textureCache[filepath];
        if (!texture.loadFromFile(filepath)) {
            cout << "Failed to load texture from " << filepath << endl;
            textureCache.erase(filepath);
            return nullptr;
        }
        
        return &texture;
    }

void displaySeedsinZone(){
    if(!this->ExistingZones){
        std::cout << "No ExistingZones pointer" << std::endl;
        return;
    }

    if(ExistingZones->empty()){
        std::cout << "ExistingZones is empty" << std::endl;
        return;
    }


    std::cout << "Checking " << ExistingZones->size() << " zones for seeds..." << std::endl;

    // Check what categories exist - DON'T loop, check each zone individually
    for(auto z : *ExistingZones){
        if(!z) {
            std::cout << "Null zone found" << std::endl;
            continue;
        }
        
        std::cout << "Zone: " << z->getZoneName() << " Type: " << z->getType() << std::endl;
        
        // Check if zone has plants
        bool hasPlants = (z->getChildren().size() > 0);
        std::cout << "  Has plants: " << (hasPlants ? "YES" : "NO") << std::endl;
        
        if(z->getType() == "Flower" && FlowerBed == nullptr){
            std::string texPath = hasPlants ? "Seeds/Flower.png" : "Seeds/warn.png";
            std::cout << "  Attempting to load: " << texPath << std::endl;
            Texture* tex = loadTexture(texPath);
            if(tex) {
                FlowerBed = new Sprite(*tex);
                std::cout << "  ✓ Created FlowerBed sprite" << std::endl;
            } else {
                std::cout << "  ✗ FAILED to load FlowerBed texture from: " << texPath << std::endl;
            }
        }
        else if(z->getType() == "Cactus&Succulent" && Desert == nullptr){
            std::string texPath = hasPlants ? "Seeds/Cactus&Succulents.png" : "Seeds/warn.png";
            std::cout << "  Attempting to load: " << texPath << std::endl;
            Texture* tex = loadTexture(texPath);
            if(tex) {
                Desert = new Sprite(*tex);
                std::cout << "  ✓ Created Desert sprite" << std::endl;
            } else {
                std::cout << "  ✗ FAILED to load Desert texture from: " << texPath << std::endl;
            }
        }
        else if(z->getType() == "Tree&Shrub" && TreeAndShrub == nullptr){
            std::string texPath = hasPlants ? "Seeds/Trees&Shrubs.png" : "Seeds/warn.png";
            std::cout << "  Attempting to load: " << texPath << std::endl;
            Texture* tex = loadTexture(texPath);
            if(tex) {
                TreeAndShrub = new Sprite(*tex);
                std::cout << "  ✓ Created TreeAndShrub sprite" << std::endl;
            } else {
                std::cout << "  ✗ FAILED to load TreeAndShrub texture from: " << texPath << std::endl;
            }
        }
        else if(z->getType() == "Herb&Aromatic" && HerbsAndAromatics == nullptr){
            std::string texPath = hasPlants ? "Seeds/Herb&Aromatic.png" : "Seeds/warn.png";
            std::cout << "  Attempting to load: " << texPath << std::endl;
            Texture* tex = loadTexture(texPath);
            if(tex) {
                HerbsAndAromatics = new Sprite(*tex);
                std::cout << "  ✓ Created HerbsAndAromatics sprite" << std::endl;
            } else {
                std::cout << "  ✗ FAILED to load HerbsAndAromatics texture from: " << texPath << std::endl;
            }
        }
    }

    // Position and draw sprites in a grid layout on/around the greenhouse
    float ghX = greenhousePosition.x;
    float ghY = greenhousePosition.y;
    
    std::cout << "Greenhouse position: (" << ghX << ", " << ghY << ")" << std::endl;
    
    // Define spacing for seed icons (2x2 grid layout)
    const float seedSize = 60.f;  // Size of each seed icon
    const float spacing = 10.f;   // Space between icons
    
    int seedCount = 0;
    
    // Draw in a 2x2 grid pattern
    if(FlowerBed){
        // Top-left
        Vector2u texSize = FlowerBed->getTexture()->getSize();
        float scale = seedSize / std::max(texSize.x, texSize.y);
        FlowerBed->setScale(scale, scale);
        FlowerBed->setPosition(ghX + 10.f, ghY + 10.f);
        this->draw(*FlowerBed);
        std::cout << "Drew FlowerBed at (" << ghX + 10.f << ", " << ghY + 10.f << ")" << std::endl;
        seedCount++;
    }
    
    if(Desert){
        // Top-right
        Vector2u texSize = Desert->getTexture()->getSize();
        float scale = seedSize / std::max(texSize.x, texSize.y);
        Desert->setScale(scale, scale);
        Desert->setPosition(ghX + seedSize + spacing + 10.f, ghY + 10.f);
        this->draw(*Desert);
        std::cout << "Drew Desert at (" << ghX + seedSize + spacing + 10.f << ", " << ghY + 10.f << ")" << std::endl;
        seedCount++;
    }
    
    if(HerbsAndAromatics){
        // Bottom-left
        Vector2u texSize = HerbsAndAromatics->getTexture()->getSize();
        float scale = seedSize / std::max(texSize.x, texSize.y);
        HerbsAndAromatics->setScale(scale, scale);
        HerbsAndAromatics->setPosition(ghX + 10.f, ghY + seedSize + spacing + 10.f);
        this->draw(*HerbsAndAromatics);
        std::cout << "Drew HerbsAndAromatics at (" << ghX + 10.f << ", " << ghY + seedSize + spacing + 10.f << ")" << std::endl;
        seedCount++;
    }
    
    if(TreeAndShrub){
        // Bottom-right
        Vector2u texSize = TreeAndShrub->getTexture()->getSize();
        float scale = seedSize / std::max(texSize.x, texSize.y);
        TreeAndShrub->setScale(scale, scale);
        TreeAndShrub->setPosition(ghX + seedSize + spacing + 10.f, ghY + seedSize + spacing + 10.f);
        this->draw(*TreeAndShrub);
        std::cout << "Drew TreeAndShrub at (" << ghX + seedSize + spacing + 10.f << ", " << ghY + seedSize + spacing + 10.f << ")" << std::endl;
        seedCount++;
    }
    
    if(seedCount == 0){
        std::cout << "WARNING: No seed sprites were drawn!" << std::endl;
    }
}
void displayInventory() {
        if (!inventory) {
            std::cout << "Missing inventory" << std::endl;
            return;
        }

        // --- Layout constants ---
        const float boxWidth = 240.f;
        const float boxHeight = 450.f;
        const float margin = 15.f;
        const float padding = 10.f;
        
        const float cellWidth = (boxWidth - 2 * padding - 5.f) / 2.f;
        const float cellHeight = 70.f;
        const float iconSize = 35.f;

        const float boxX = this->getSize().x - boxWidth - margin;
        const float boxY = margin;

        // --- Draw box ---
        RectangleShape box(Vector2f(boxWidth, boxHeight));
        box.setFillColor(Color(245, 245, 245, 240));
        box.setOutlineColor(Color::Black);
        box.setOutlineThickness(2.f);
        box.setPosition(boxX, boxY);
        this->draw(box);

        // --- Inventory Icon ---
        Texture* inventoryLogo = loadTexture("Inventory/warehouse.png");
        if (inventoryLogo) {
            Sprite sprite(*inventoryLogo);
            Vector2u texSize = inventoryLogo->getSize();

            float desiredSize = 35.f;
            float scale = desiredSize / std::max(texSize.x, texSize.y);
            sprite.setScale(scale, scale);

            float iconX = boxX - desiredSize - 10.f;
            float iconY = boxY + 10.f;
            sprite.setPosition(iconX, iconY);

            this->draw(sprite);
        }

        // --- Plant data ---
        const std::vector<std::string> plantsAvailable = {
            "Roses", "Daisies", "Tulips", "Succulents", "Cactuses",
            "Basils", "Mints", "Parsleys", "Corianders", "Lavenders",
            "Rosemary", "LemonBalms", "Hibiscus", "Hydrangea",
            "Boxwood", "Oak", "Baobab", "Seeds"
        };

        std::map<std::string, int> plantCounts;
        int totalPlants = 0;
        for (const auto& plantType : plantsAvailable) {
            PlantIterator* it = inventory->createIterator(plantType);
            if (it) {
                int count = it->count();
                totalPlants += count;
                if (count > 0) plantCounts[plantType] = count;
                delete it;
            }
        }

        // --- Calculate grid ---
        const int columns = 2;
        const int totalRows = (plantCounts.size() + columns - 1) / columns;
        const float contentHeight = totalRows * cellHeight;
        const float viewableHeight = boxHeight - 70.f;
        const float maxScroll = std::max(0.f, contentHeight - viewableHeight);
        if (scrollOffset > maxScroll) scrollOffset = maxScroll;

        // --- Draw grid items ---
        float startX = boxX + padding;
        float startY = boxY + 45.f - scrollOffset;
        int index = 0;

        for (const auto& [plantName, count] : plantCounts) {
            int col = index % columns;
            int row = index / columns;

            float cellX = startX + col * cellWidth;
            float cellY = startY + row * cellHeight;

            if (cellY + cellHeight < boxY + 40.f || cellY > boxY + 40.f + viewableHeight) {
                index++;
                continue;
            }

            std::string imagePath = "Plants/" + plantName + ".png";
            Texture* texture = loadTexture(imagePath);
            if (texture) {
                Sprite sprite(*texture);
                Vector2u texSize = texture->getSize();
                float scale = iconSize / std::max(texSize.x, texSize.y);
                sprite.setScale(scale, scale);
                sprite.setPosition(cellX + 3.f, cellY + 5.f);
                this->draw(sprite);
            }

            string displayName = plantName;
            if (displayName.length() > 10) {
                displayName = displayName.substr(0, 8) + "..";
            }
            
            Text nameText(displayName, font, 11);
            nameText.setFillColor(Color::Black);
            nameText.setPosition(cellX + 43.f, cellY + 10.f);
            this->draw(nameText);

            Text qtyText("x" + std::to_string(count), font, 11);
            qtyText.setFillColor(Color(80, 80, 80));
            qtyText.setPosition(cellX + 43.f, cellY + 28.f);
            this->draw(qtyText);

            index++;
        }

        // --- Total at bottom ---
        RectangleShape bottomBar(Vector2f(boxWidth, 35.f));
        bottomBar.setFillColor(Color(235, 235, 235));
        bottomBar.setPosition(boxX, boxY + boxHeight - 35.f);
        this->draw(bottomBar);

        Text totalText("Total: " + std::to_string(totalPlants), font, 16);
        totalText.setFillColor(Color::Black);
        totalText.setStyle(Text::Bold);
        totalText.setPosition(boxX + 10.f, boxY + boxHeight - 28.f);
        this->draw(totalText);
    }

    void displayShelves(){
        Texture* shelf = loadTexture("Store/Shelf.png");
        if (shelf) {
            const int rows = 3;
            const int cols = 3;
            const float shelfWidth = 250.f;
            const float shelfHeight = 100.f;
            const float startX = 30.f;
            const float startY = 20.f;
            const float xSpacing = 1.f;
            const float yOverlap = 25.f;

            for (int row = 0; row < rows; row++) {
                for (int col = 0; col < cols; col++) {
                    Sprite sprite(*shelf);
                    Vector2u texSize = shelf->getSize();

                    float scale = (shelfHeight / texSize.y)*1.7;
                    sprite.setScale(scale, scale);

                    float xPos = startX + (col * (shelfWidth - xSpacing*150));
                    float yPos = startY + (row * (shelfHeight - yOverlap));
                    sprite.setPosition(xPos, yPos);

                    this->draw(sprite);
                }
            }

            Texture* greenhouseTex = loadTexture("Store/Greenhouse.png");
            if (greenhouseTex) {
                Sprite ghSprite(*greenhouseTex);
                Vector2u gsize = greenhouseTex->getSize();

                const float maxW = 340.f;
                const float maxH = 240.f;
                float scaleX = maxW / static_cast<float>(gsize.x)*1.7;
                float scaleY = maxH / static_cast<float>(gsize.y)*1.7;
                float ghScale = std::min(scaleX, scaleY);
                ghSprite.setScale(ghScale, ghScale);

                float gridRight = startX + cols * (shelfWidth - xSpacing*150);
                float gx = gridRight + 18.f;
                float gy = startY;

                float availRight = static_cast<float>(this->getSize().x) - (maxW + 20.f);
                if (gx > availRight) gx = availRight;
                if (gx < startX) gx = startX + 10.f;

                ghSprite.setPosition(gx, gy);
                this->greenhousePosition = {gx,gy};
                this->draw(ghSprite);
            }
        }
    }

    void displayStore() {
        this->displayShelves();
        this->displayCustomerStaff();
        this->displayCareStaff();
    }  

    void displayCustomerStaff(){
        Texture* customerStaffIMG = loadTexture("Staff/customerStaff_table.png");
        if (customerStaffIMG) {
            Sprite sprite(*customerStaffIMG);
            Vector2u texSize = customerStaffIMG->getSize();

            float desiredSize = 250.f; 
            float scale = (desiredSize / texSize.y);
            sprite.setScale(scale, scale);

            float iconX = 10.f;  
            float iconY = this->getSize().y - desiredSize - 10.f;  
            sprite.setPosition(iconX, iconY);

            this->draw(sprite);
        }
    }

    void displayCareStaff() {
        if(!inventory){
            std::cout << "Missing inventory or care staff" << std::endl;
            return;
        }

        const float staffSize = 200.f;
        const float margin = 20.f;
        
        Texture* staffTexture = loadTexture("Staff/careStaff.png");
        if (!staffTexture) {
            staffTexture = loadTexture("assets/Staff/caretaker.png");
        }
        
        if (staffTexture) {
            Sprite staffSprite(*staffTexture);
            Vector2u texSize = staffTexture->getSize();

            float scale = staffSize / std::max(texSize.x, texSize.y);
            //change scale
            scale *= 0.7;
            staffSprite.setScale(scale, scale);

            float staffX = sf::Window::getPosition().x;
            float staffY =sf::Window::getPosition().y + 15.f;
            staffSprite.setPosition(staffX, staffY);

            this->draw(staffSprite);
        }
    }

    void moveCareStaffFromGreenhouseToInventory(){

    }

    void moveCustomerStaffFromTabletoInventory(){

    }

    // void spawnCustomer(){
    //     // Don't spawn if at max capacity
    //     if (activeCustomers.size() >= maxCustomers) {
    //         return;
    //     }

    //     Customer newCustomer;
        
    //     // Randomly select customer type (1-10, adjust based on available images)
    //     std::uniform_int_distribution<int> dist(2, 9);
    //     newCustomer.customerType = dist(rng);
        
    //     // Load customer texture
    //     std::string customerPath = "Customers/customer" + std::to_string(newCustomer.customerType) + ".png";
    //     Texture* customerTex = loadTexture(customerPath);
        
    //     if (!customerTex) {
    //         std::cout << "Failed to load customer texture: " << customerPath << std::endl;
    //         return;
    //     }
        
    //     // Setup customer sprite
    //     newCustomer.sprite.setTexture(*customerTex);
    //     Vector2u texSize = customerTex->getSize();
    //     float customerScale = 120.f / std::max(texSize.x, texSize.y); // Customer size
    //     newCustomer.sprite.setScale(customerScale, customerScale);
        
    //     // Starting position (outside window, right side)
    //     float startX = static_cast<float>(this->getSize().x) + 50.f;
    //     float startY = this->getSize().y - 200.f; // Near bottom
    //     newCustomer.currentPos = Vector2f(startX, startY);
    //     newCustomer.sprite.setPosition(newCustomer.currentPos);
        
    //     // Target position (in front of customer staff table)
    //     newCustomer.targetPos = Vector2f(280.f, this->getSize().y - 220.f);
        
    //     // Load speech bubble
    //     Texture* bubbleTex = loadTexture("Customers/s_bubble.png");
    //     if (bubbleTex) {
    //         newCustomer.speechBubble.setTexture(*bubbleTex);
    //         Vector2u bubbleSize = bubbleTex->getSize();
    //         float bubbleScale = 80.f / std::max(bubbleSize.x, bubbleSize.y);
    //         newCustomer.speechBubble.setScale(bubbleScale, bubbleScale);
    //     }
        
    //     // Initialize animation state
    //     newCustomer.alpha = 0.f;
    //     newCustomer.isMoving = true;
    //     newCustomer.hasArrived = false;
    //     newCustomer.animationClock.restart();
        
    //     activeCustomers.push_back(newCustomer);
        
    //     std::cout << "Customer " << newCustomer.customerType << " spawned!" << std::endl;
    // }

    // void displayCustomers() {
    //     const float fadeSpeed = 100.f; // Alpha per second
    //     const float moveSpeed = 150.f; // Pixels per second
        
    //     for (auto it = activeCustomers.begin(); it != activeCustomers.end();) {
    //         Customer& customer = *it;
    //         float dt = customer.animationClock.restart().asSeconds();
            
    //         // Fade in
    //         if (customer.alpha < 255.f) {
    //             customer.alpha += fadeSpeed * dt;
    //             if (customer.alpha > 255.f) customer.alpha = 255.f;
    //         }
            
    //         // Move towards target
    //         if (customer.isMoving) {
    //             Vector2f direction = customer.targetPos - customer.currentPos;
    //             float distance = std::sqrt(direction.x * direction.x + direction.y * direction.y);
                
    //             if (distance > 2.f) {
    //                 // Normalize and move
    //                 direction.x /= distance;
    //                 direction.y /= distance;
                    
    //                 customer.currentPos.x += direction.x * moveSpeed * dt;
    //                 customer.currentPos.y += direction.y * moveSpeed * dt;
    //                 customer.sprite.setPosition(customer.currentPos);
    //             } else {
    //                 // Arrived at target
    //                 customer.isMoving = false;
    //                 customer.hasArrived = true;
    //                 customer.sprite.setPosition(customer.targetPos);
    //             }
    //         }
            
    //         // Set transparency
    //         Color col = customer.sprite.getColor();
    //         col.a = static_cast<sf::Uint8>(customer.alpha);
    //         customer.sprite.setColor(col);
            
    //         // Draw customer
    //         this->draw(customer.sprite);
            
    //         // Draw speech bubble if customer has arrived
    //         if (customer.hasArrived && customer.speechBubble.getTexture()) {
    //             // Position bubble above customer's head
    //             FloatRect bounds = customer.sprite.getGlobalBounds();
    //             float bubbleX = customer.currentPos.x + bounds.width / 2.f - 40.f;
    //             float bubbleY = customer.currentPos.y - 60.f;
    //             customer.speechBubble.setPosition(bubbleX, bubbleY);
                
    //             Color bubbleCol = customer.speechBubble.getColor();
    //             bubbleCol.a = static_cast<sf::Uint8>(customer.alpha);
    //             customer.speechBubble.setColor(bubbleCol);
                
    //             this->draw(customer.speechBubble);
    //         }
            
    //         ++it;
    //     }
    // }
    
    // Helper function to remove a customer (call this when customer is served)
    void removeCustomer(int index) {
        if (index >= 0 && index < activeCustomers.size()) {
            activeCustomers.erase(activeCustomers.begin() + index);
        }
    }
};
#endif